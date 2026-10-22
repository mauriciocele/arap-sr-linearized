//! The armadillo dancing: real deformations of the detailed armadillo, one per frame, driven by its handles.
//!
//! `cargo run --release --bin render dance [loveme|floss|gangnam|macarena|moonwalk|robot|whip|all]` writes the frames
//! to `ARAP_DANCE_DIR/<name>/` (default `/tmp/arap_dance`) and encodes them into `<name>.mp4` there with ffmpeg.
//!
//! Each dance is a pose function of time. A pose moves the six armadillo handles (hands, feet, head, hip) plus three
//! added for secondary motion (both ears and the tail). The hip carries the upper body, the head carries the ears,
//! and the whole dancer can turn and move. The hands, head, ears and tail then chase their targets through damped
//! springs, so they lag, overshoot and wobble: whip cracks, and floppy ears.

use std::f64::consts::{PI, TAU};
use std::fs;
use std::path::PathBuf;
use std::process::Command;
use std::time::Instant;

use arap::deformer::Deformer;
use arap::handle::Handle;
use arap::mesh::Vec3 as DVec3;
use arap::scenes::{armadillo_handles, load};
use nalgebra::{UnitQuaternion, Vector3};
use three_d::Context;

use super::{View, converge, render_to, rot};

const FPS: f64 = 30.0;
const ITERATIONS_PER_FRAME: usize = 14;

/// Rest centres of the hands (handles 0 and 2) and of the added handles. The armadillo faces -z with its left
/// side at -x.
const LEFT_HAND: [f64; 3] = [-0.5, 0.45, -0.3];
const RIGHT_HAND: [f64; 3] = [0.45, 0.45, -0.3];
const LEFT_EAR: [f64; 3] = [-0.16, 0.6, -0.24];
const RIGHT_EAR: [f64; 3] = [0.17, 0.6, -0.22];
const TAIL: [f64; 3] = [-0.04, -0.27, 0.45];

const EARS: Spring = Spring { frequency: 2.2, damping: 0.16, response: 0.0 };
const TAIL_SPRING: Spring = Spring { frequency: 2.8, damping: 0.12, response: 0.0 };
const HANDS: Spring = Spring { frequency: 3.2, damping: 0.55, response: 0.0 };
const HEAD: Spring = Spring { frequency: 4.0, damping: 0.6, response: 0.0 };

/// The armadillo with its six handles (hands 0 and 2, feet 1 at +x and 3 at -x, head 4, hip 5), the ears 6 (-x)
/// and 7 (+x) and the tail 8.
fn dancer() -> Deformer {
    let mut handles = armadillo_handles();
    for (centre, radius) in [(LEFT_EAR, 0.07), (RIGHT_EAR, 0.07), (TAIL, 0.07)] {
        handles.push(Handle::new(v(centre), radius));
    }
    Deformer::new(load("armadillo.obj"), load("armadillo1.obj"), handles)
}

fn v(a: [f64; 3]) -> DVec3 {
    DVec3::new(a[0], a[1], a[2])
}

/// 0 below `edge0`, 1 above `edge1`, smooth in between.
fn smoothstep(edge0: f64, edge1: f64, x: f64) -> f64 {
    let t = ((x - edge0) / (edge1 - edge0)).clamp(0.0, 1.0);
    t * t * (3.0 - 2.0 * t)
}

/// 1 between `a` and `b`, fading in and out over `fade` centred on each end.
fn window(t: f64, a: f64, b: f64, fade: f64) -> f64 {
    smoothstep(a - fade, a + fade, t) * (1.0 - smoothstep(b - fade, b + fade, t))
}

/// A bump `sin(pi x)` on `0 < x < 1`, zero elsewhere.
fn pulse(x: f64) -> f64 {
    if (0.0..1.0).contains(&x) { (PI * x).sin() } else { 0.0 }
}

fn lerp3(a: [f64; 3], b: [f64; 3], u: f64) -> [f64; 3] {
    std::array::from_fn(|k| a[k] + (b[k] - a[k]) * u)
}

/// A value moving through keyframes: from time `k.0` it eases towards `k.1` over `k.2` seconds, starting from
/// wherever the earlier keys have left it. The first key is the initial value.
fn track(t: f64, keys: &[(f64, [f64; 3], f64)]) -> [f64; 3] {
    let mut value = keys[0].1;
    for &(start, target, ease) in &keys[1..] {
        if t <= start {
            break;
        }
        value = lerp3(value, target, smoothstep(start, start + ease, t));
    }
    value
}

/// A handle's motion relative to its rest pose: a translation and a rotation vector (axis times angle).
#[derive(Clone, Copy, Default)]
struct Motion {
    t: DVec3,
    r: DVec3,
}

impl Motion {
    fn add(&mut self, weight: f64, t: [f64; 3], r_degrees: [f64; 3]) {
        self.t += weight * v(t);
        self.r += weight * v(r_degrees).map(f64::to_radians);
    }

    /// Moves a handle resting at `rest` towards `target`.
    fn to(&mut self, weight: f64, rest: [f64; 3], target: [f64; 3]) {
        self.t += weight * (v(target) - v(rest));
    }

    fn rotate(&mut self, weight: f64, r_degrees: [f64; 3]) {
        self.add(weight, [0.0; 3], r_degrees);
    }
}

/// Everything a dance sets at one instant. The hands, head and tail move in the frame of the hip (`body`); the
/// feet in the dancer's frame. The whole dancer then turns by `turn` degrees about the vertical through the hip and
/// moves by `shift`.
#[derive(Clone, Copy, Default)]
struct Pose {
    turn: f64,
    shift: DVec3,
    body: Motion,
    left: Motion,
    right: Motion,
    head: Motion,
    left_foot: Motion,
    right_foot: Motion,
    tail: Motion,
}

/// A rigid motion written as the handles write theirs, `x -> rotation (x - rest) + image`, where `image` is where
/// the rest centre goes.
#[derive(Clone, Copy)]
struct Motor {
    rotation: UnitQuaternion<f64>,
    rest: DVec3,
    image: DVec3,
}

impl Motor {
    fn of(rest: DVec3, m: &Motion) -> Self {
        Motor { rotation: UnitQuaternion::from_scaled_axis(m.r), rest, image: rest + m.t }
    }

    fn apply(&self, x: &DVec3) -> DVec3 {
        self.rotation * (x - self.rest) + self.image
    }

    /// `inner` followed by `self`, keeping `inner`'s rest centre.
    fn after(&self, inner: &Motor) -> Motor {
        Motor { rotation: self.rotation * inner.rotation, rest: inner.rest, image: self.apply(&inner.image) }
    }
}

/// Where each of the nine handles should be for `pose`.
fn targets(d: &Deformer, pose: &Pose) -> Vec<Motor> {
    let rest: Vec<DVec3> = d.handles.iter().map(|h| h.rest_center).collect();
    let own = |i: usize, m: &Motion| Motor::of(rest[i], m);
    let still = Motion::default();
    let body = own(5, &pose.body);
    let head = body.after(&own(4, &pose.head));
    let pivot = DVec3::new(0.0, 0.0, rest[5].z);
    let world = Motor { rotation: rot(Vector3::y(), pose.turn), rest: pivot, image: pivot + pose.shift };
    [
        body.after(&own(0, &pose.left)),
        own(1, &pose.right_foot),
        body.after(&own(2, &pose.right)),
        own(3, &pose.left_foot),
        head,
        body,
        head.after(&own(6, &still)),
        head.after(&own(7, &still)),
        body.after(&own(8, &pose.tail)),
    ]
    .iter()
    .map(|m| world.after(m))
    .collect()
}

/// Second-order dynamics that follow a moving target, as in t3ssel8r's "Giving Personality to Procedural
/// Animations": natural `frequency` in Hz, `damping` below 1 overshoots, `response` above 0 reacts at once and
/// below 0 anticipates.
#[derive(Clone, Copy)]
struct Spring {
    frequency: f64,
    damping: f64,
    response: f64,
}

struct Follower {
    k1: f64,
    k2: f64,
    k3: f64,
    position: DVec3,
    velocity: DVec3,
    previous_target: DVec3,
}

impl Follower {
    fn new(s: Spring, start: DVec3) -> Self {
        let w = TAU * s.frequency;
        Follower {
            k1: s.damping / (PI * s.frequency),
            k2: 1.0 / (w * w),
            k3: s.response * s.damping / w,
            position: start,
            velocity: DVec3::zeros(),
            previous_target: start,
        }
    }

    fn follow(&mut self, target: DVec3, dt: f64) -> DVec3 {
        let target_velocity = (target - self.previous_target) / dt;
        self.previous_target = target;
        const SUBSTEPS: usize = 16;
        let h = dt / SUBSTEPS as f64;
        for _ in 0..SUBSTEPS {
            self.position += h * self.velocity;
            self.velocity +=
                h * (target + self.k3 * target_velocity - self.position - self.k1 * self.velocity) / self.k2;
        }
        self.position
    }
}

struct Dance {
    name: &'static str,
    seconds: f64,
    pose: fn(f64) -> Pose,
    hands: Spring,
    head: Spring,
    eye: [f32; 3],
    target: [f32; 3],
}

const EYE: [f32; 3] = [0.95, 0.35, -3.45];
const TARGET: [f32; 3] = [0.0, 0.14, 0.0];

fn dances() -> Vec<Dance> {
    let dance = |name, seconds, pose| Dance { name, seconds, pose, hands: HANDS, head: HEAD, eye: EYE, target: TARGET };
    vec![
        dance("loveme", 18.0, loveme),
        dance("floss", 14.0, floss),
        dance("gangnam", 15.0, gangnam),
        dance("macarena", 20.0, macarena),
        Dance { eye: [0.0, 0.3, -4.4], target: [0.0, 0.1, 0.0], ..dance("moonwalk", 14.5, moonwalk) },
        Dance {
            hands: Spring { frequency: 5.5, damping: 0.28, response: 0.0 },
            head: Spring { frequency: 6.0, damping: 0.3, response: 0.0 },
            ..dance("robot", 18.4, robot)
        },
        Dance { hands: Spring { frequency: 4.0, damping: 0.35, response: 0.0 }, ..dance("whip", 16.4, whip) },
    ]
}

/// Renders the frames of the dance `which` (or of all of them) and encodes each into an MP4.
pub fn dance(context: &Context, which: &str) {
    let base = PathBuf::from(std::env::var("ARAP_DANCE_DIR").unwrap_or_else(|_| "/tmp/arap_dance".to_string()));
    let selected: Vec<Dance> = dances().into_iter().filter(|d| which == "all" || which == d.name).collect();
    assert!(!selected.is_empty(), "unknown dance {which}");
    for dance in selected {
        let dir = base.join(dance.name);
        let _ = fs::remove_dir_all(&dir);
        fs::create_dir_all(&dir).expect("frames directory");
        let mut d = dancer();
        let floor_y = d.high.positions.iter().map(|p| p.y).fold(f64::MAX, f64::min);
        let springs = [
            Some(dance.hands),
            None,
            Some(dance.hands),
            None,
            Some(dance.head),
            None,
            Some(EARS),
            Some(EARS),
            Some(TAIL_SPRING),
        ];
        let first = targets(&d, &(dance.pose)(0.0));
        let mut followers: Vec<Option<Follower>> =
            springs.iter().zip(&first).map(|(s, m)| s.map(|s| Follower::new(s, m.image))).collect();
        let frames = (FPS * dance.seconds).round() as usize;
        let start = Instant::now();
        for frame in 0..frames {
            let t = frame as f64 / FPS;
            let motors = targets(&d, &(dance.pose)(t));
            for ((handle, m), follower) in d.handles.iter_mut().zip(&motors).zip(&mut followers) {
                let image = match follower {
                    Some(f) => f.follow(m.image, 1.0 / FPS),
                    None => m.image,
                };
                handle.rotation = m.rotation;
                handle.translation = image - m.rest;
            }
            converge(&mut d, if frame == 0 { 60 } else { ITERATIONS_PER_FRAME });
            let mut view = View::detail(&d).looking(dance.eye, dance.target).sized(1280, 720);
            view.floor_y = Some(floor_y);
            render_to(context, &view, &dir.join(format!("frame_{frame:04}.png")), 2);
        }
        let video = base.join(format!("{}.mp4", dance.name));
        let encoded = Command::new("ffmpeg")
            .args(["-y", "-loglevel", "error", "-framerate", "30", "-i"])
            .arg(dir.join("frame_%04d.png"))
            .args(["-c:v", "libx264", "-pix_fmt", "yuv420p", "-crf", "18", "-movflags", "+faststart"])
            .arg(&video)
            .status()
            .is_ok_and(|s| s.success());
        println!(
            "{}: {frames} frames in {:.0} s{}",
            dance.name,
            start.elapsed().as_secs_f64(),
            if encoded { format!(", wrote {}", video.display()) } else { ", ffmpeg failed".to_string() }
        );
    }
}

/// "Do You Love Me?": a hip groove with pumping arms, the twist, the running man, an arms-up shimmy and a final
/// pose.
fn loveme(t: f64) -> Pose {
    const BEAT: f64 = 0.5;
    let window = |a, b| window(t, a, b, 0.35);
    let beat = (TAU * t / BEAT).sin();
    let bar = (TAU * t / (2.0 * BEAT)).sin();
    let bounce = 0.5 * (1.0 - (TAU * t / BEAT).cos());
    let mut p = Pose::default();

    // Groove: hips sway side to side and bounce on every beat, arms pump in turn, head bobs.
    let w = window(0.6, 4.5);
    p.body.add(w, [0.06 * bar, -0.035 * bounce, 0.0], [0.0, 0.0, -6.0 * bar]);
    p.left.add(w, [0.0, 0.12 * bar, -0.04 * bar], [0.0; 3]);
    p.right.add(w, [0.0, -0.12 * bar, 0.04 * bar], [0.0; 3]);
    p.head.rotate(w, [-12.0 * beat, 0.0, 6.0 * bar]);

    // The twist: knees bent, hips turn one way while the feet pivot the other, arms swing across.
    let w = window(4.5, 8.5);
    p.body.add(w, [0.0, -0.06 - 0.02 * bounce, 0.0], [0.0, 28.0 * bar, 0.0]);
    p.left_foot.rotate(w, [0.0, -18.0 * bar, 0.0]);
    p.right_foot.rotate(w, [0.0, -18.0 * bar, 0.0]);
    p.left.add(w, [0.08 * bar, -0.1, -0.08 * bar], [0.0; 3]);
    p.right.add(w, [0.08 * bar, -0.1, 0.08 * bar], [0.0; 3]);
    p.head.rotate(w, [0.0, -20.0 * bar, 0.0]);

    // Running man: the feet take turns lifting, the hips bounce over the standing foot, arms pump like a sprinter.
    let w = window(8.5, 12.5);
    let (up_right, up_left) = (bar.max(0.0), (-bar).max(0.0));
    p.left_foot.add(w, [0.0, 0.14 * up_left, -0.08 * up_left], [-25.0 * up_left, 0.0, 0.0]);
    p.right_foot.add(w, [0.0, 0.14 * up_right, -0.08 * up_right], [-25.0 * up_right, 0.0, 0.0]);
    p.body.add(w, [-0.05 * bar, -0.05 * bounce, 0.0], [8.0 * bounce, 0.0, 5.0 * bar]);
    p.left.add(w, [0.05, -0.12, 0.18 * bar], [0.0; 3]);
    p.right.add(w, [-0.05, -0.12, -0.18 * bar], [0.0; 3]);
    p.head.rotate(w, [-10.0 * beat, 0.0, 0.0]);

    // Arms up: hands high over the head waving from side to side, hips shaking twice per beat, head tilting.
    let w = window(12.5, 16.2);
    let shake = (2.0 * TAU * t / BEAT).sin();
    p.left.add(w, [0.15 + 0.12 * bar, 0.3, 0.1], [0.0, 0.0, -30.0 - 15.0 * bar]);
    p.right.add(w, [-0.15 + 0.12 * bar, 0.3, 0.1], [0.0, 0.0, 30.0 - 15.0 * bar]);
    p.body.add(w, [0.03 * shake, -0.02 * bounce, 0.0], [0.0, 8.0 * shake, -5.0 * bar]);
    p.head.rotate(w, [-15.0, 0.0, 15.0 * bar]);

    // Final pose: one arm pointing up and out, the other on the hip, head turned to the camera.
    let w = window(16.2, 30.0);
    p.right.add(w, [0.2, 0.32, -0.15], [0.0, 0.0, 45.0]);
    p.left.add(w, [0.18, -0.3, 0.0], [0.0, 0.0, 40.0]);
    p.body.add(w, [0.03, -0.02, 0.0], [0.0, -12.0, 4.0]);
    p.head.rotate(w, [-10.0, 25.0, -8.0]);
    p.right_foot.rotate(w, [0.0, -20.0, 0.0]);
    p
}

/// The floss: straight arms swing round the body from side to side, one in front and one behind, while the hips
/// swing the other way. Speeds up halfway, and ends with a ta-da.
fn floss(t: f64) -> Pose {
    let mut p = Pose::default();
    // Swings so far: 2.4 a second, speeding up to 3.4 around 7 s.
    let rate = |s: f64| 2.4 + 1.0 * smoothstep(6.5, 7.5, s);
    let steps = 400;
    let swings: f64 = (0..steps).map(|i| rate((i as f64 + 0.5) * t / steps as f64)).sum::<f64>() * t / steps as f64;
    // 0: hands at the right side, 1: at the left.
    let u = 0.5 - 0.5 * (PI * swings).cos();
    let side = 1.0 - 2.0 * u;
    let dip = (PI * swings).sin().powi(2);
    let w = window(t, 0.6, 12.4, 0.4);
    // The hands go round the body on an ellipse at hip height: angle 0 at the right side, -90 in front.
    let around = |degrees: f64| {
        let a = degrees.to_radians();
        [0.42 * a.cos(), -0.02, 0.1 + 0.34 * a.sin()]
    };
    p.left.to(w, LEFT_HAND, around(-45.0 - 175.0 * u));
    p.right.to(w, RIGHT_HAND, around(40.0 - 175.0 * u));
    p.body.add(w, [-0.09 * side, -0.03 * dip, 0.0], [0.0, -8.0 * side, -6.0 * side]);
    p.head.rotate(w, [-6.0 * dip, 0.0, 10.0 * side]);
    p.tail.add(w, [0.08 * side, 0.0, 0.0], [0.0; 3]);
    // Ta-da: arms up in a V, head up.
    let end = smoothstep(12.2, 12.8, t);
    p.left.to(end, LEFT_HAND, [-0.42, 0.82, -0.2]);
    p.right.to(end, RIGHT_HAND, [0.4, 0.82, -0.2]);
    p.head.rotate(end, [15.0, 0.0, 0.0]);
    p
}

/// Gangnam Style: the horse-riding gallop with crossed wrists, the lasso overhead, arm pumps with hip thrusts and the
/// "Oppa" pose.
fn gangnam(t: f64) -> Pose {
    let mut p = Pose::default();
    let b = 60.0 / 132.0;
    let half = b / 2.0;
    // Gallop: two hops on the left foot (the right one up), then two on the right.
    let hop = (PI * (t / half).fract()).sin();
    let (right_up, left_up) = if ((t / half).floor() as i64).rem_euclid(4) < 2 { (hop, 0.0) } else { (0.0, hop) };
    // -1 while standing on the left foot, +1 on the right.
    let stance = -(PI * t / b).sin();
    let g = window(t, 0.7, 11.0, 0.3);
    p.body.add(g, [0.035 * stance, -0.07 + 0.03 * hop, -0.02], [-6.0, 6.0 * stance, 0.0]);
    p.right_foot.add(g, [0.04, 0.08 * right_up, -0.02 * right_up], [-15.0 * right_up, 0.0, 0.0]);
    p.left_foot.add(g, [-0.04, 0.08 * left_up, -0.02 * left_up], [-15.0 * left_up, 0.0, 0.0]);
    p.head.rotate(g, [-8.0 * hop, 0.0, 6.0 * stance]);
    p.tail.add(g, [0.06 * stance, 0.03 * hop, 0.0], [0.0; 3]);

    // Wrists crossed on the reins; from 6 s the right hand swings a lasso overhead while the dancer turns about.
    let reins_left = [0.07, 0.12 + 0.03 * hop, -0.4];
    let reins_right = [-0.05, 0.17 + 0.03 * hop, -0.42];
    let spin = TAU * t / b;
    let lasso = [0.12 + 0.17 * spin.cos(), 0.88, -0.1 + 0.17 * spin.sin()];
    let lw = window(t, 6.0, 11.0, 0.35);
    p.left.to(g, LEFT_HAND, reins_left);
    p.right.to(g, RIGHT_HAND, lerp3(reins_right, lasso, lw));
    p.turn = 25.0 * (TAU * t / (8.0 * b)).sin() * lw;

    // Arm pumps overhead, one per beat, with hip thrusts.
    let th = window(t, 11.0, 13.6, 0.3);
    let up_right = (PI * t / b).sin().max(0.0);
    let up_left = (-(PI * t / b).sin()).max(0.0);
    let thrust = (TAU * t / b).sin();
    p.right.to(th, RIGHT_HAND, lerp3([0.25, 0.3, -0.35], [0.25, 0.88, -0.2], up_right));
    p.left.to(th, LEFT_HAND, lerp3([-0.27, 0.3, -0.35], [-0.27, 0.88, -0.2], up_left));
    p.body.add(th, [0.0, -0.05, -0.05 * thrust], [10.0 * thrust, 0.0, 0.0]);
    p.head.rotate(th, [-12.0 * thrust, 0.0, 0.0]);

    // Oppa Gangnam Style: horse stance, one hand at the sunglasses, head cocked.
    let fin = smoothstep(13.4, 13.8, t);
    p.right.to(fin, RIGHT_HAND, [0.22, 0.5, -0.42]);
    p.left.to(fin, LEFT_HAND, [0.07, 0.12, -0.4]);
    p.body.add(fin, [0.0, -0.07, 0.0], [-6.0, 0.0, 0.0]);
    p.head.rotate(fin, [0.0, -15.0, 10.0]);
    p.right_foot.add(fin, [0.04, 0.0, 0.0], [0.0; 3]);
    p.left_foot.add(fin, [-0.04, 0.0, 0.0], [0.0; 3]);
    p
}

/// The Macarena, twice: hands out, palms up, to the shoulders, behind the head, to the hips and behind, three hip
/// circles and a jump with a quarter turn. Ends with a "Hey!".
fn macarena(t: f64) -> Pose {
    let mut p = Pose::default();
    let b = 60.0 / 103.0;
    let t0 = 0.4;
    let c = (t - t0) / b;
    let ease = 0.45 * b;
    let mut right = vec![(0.0, RIGHT_HAND, 0.0)];
    let mut left = vec![(0.0, LEFT_HAND, 0.0)];
    let mut right_palm = vec![(0.0, [0.0; 3], 0.0)];
    let mut left_palm = vec![(0.0, [0.0; 3], 0.0)];
    for cycle in 0..2 {
        let at = |count: f64| t0 + (16.0 * cycle as f64 + count) * b;
        right.push((at(0.0), [0.22, 0.22, -0.62], ease));
        left.push((at(1.0), [-0.24, 0.22, -0.62], ease));
        right_palm.push((at(2.0), [0.0, 0.0, 150.0], ease));
        left_palm.push((at(3.0), [0.0, 0.0, -150.0], ease));
        right.push((at(4.0), [-0.2, 0.3, -0.24], ease));
        right_palm.push((at(4.0), [0.0; 3], ease));
        left.push((at(5.0), [0.18, 0.33, -0.3], ease));
        left_palm.push((at(5.0), [0.0; 3], ease));
        // Behind the head, over the top rather than through it.
        right.push((at(6.0), [0.05, 0.8, -0.25], 0.5 * ease));
        right.push((at(6.0) + 0.5 * ease, [0.1, 0.7, -0.02], 0.5 * ease));
        left.push((at(7.0), [-0.08, 0.82, -0.28], 0.5 * ease));
        left.push((at(7.0) + 0.5 * ease, [-0.12, 0.7, -0.02], 0.5 * ease));
        right.push((at(8.0), [-0.18, -0.02, -0.18], ease));
        left.push((at(9.0), [0.16, 0.0, -0.22], ease));
        right.push((at(10.0), [0.24, -0.12, 0.36], ease));
        left.push((at(11.0), [-0.26, -0.12, 0.36], ease));
    }
    // Hey!
    right.push((t0 + 32.0 * b, [0.4, 0.85, -0.2], ease));
    left.push((t0 + 32.0 * b, [-0.42, 0.85, -0.2], ease));
    p.right.to(1.0, RIGHT_HAND, track(t, &right));
    p.left.to(1.0, LEFT_HAND, track(t, &left));
    p.right.rotate(1.0, track(t, &right_palm));
    p.left.rotate(1.0, track(t, &left_palm));

    // A little groove on every count.
    let dancing = window(c, 0.0, 32.0, 0.3);
    p.body.add(dancing, [0.02 * (PI * c).sin(), -0.02 * (PI * c).sin().powi(2), 0.0], [0.0, 0.0, -3.0 * (PI * c).sin()]);
    p.head.rotate(dancing, [-6.0 * (PI * c).sin().powi(2), 0.0, 4.0 * (PI * c).sin()]);
    p.tail.add(dancing, [0.05 * (PI * c).sin(), 0.0, 0.0], [0.0; 3]);
    for cycle in 0..2 {
        let k = c - 16.0 * cycle as f64;
        // Three hip circles on counts 12 to 15.
        if (12.0..15.0).contains(&k) {
            let a = TAU * (k - 12.0);
            p.body.add(1.0, [0.07 * a.sin(), 0.0, 0.06 * (1.0 - a.cos())], [6.0 * (1.0 - a.cos()), 0.0, -8.0 * a.sin()]);
            p.tail.add(1.0, [-0.1 * a.sin(), 0.0, 0.0], [0.0; 3]);
        }
        // Squat, jump with a quarter turn, land in a squat.
        let squat = pulse((k - 15.0) / 0.3) + pulse((k - 15.8) / 0.2);
        let air = pulse((k - 15.3) / 0.5);
        p.body.add(1.0, [0.0, -0.08 * squat, 0.0], [-8.0 * squat, 0.0, 0.0]);
        p.shift.y += 0.16 * air;
        p.left_foot.add(1.0, [0.0, 0.06 * air, 0.0], [-10.0 * air, 0.0, 0.0]);
        p.right_foot.add(1.0, [0.0, 0.06 * air, 0.0], [-10.0 * air, 0.0, 0.0]);
    }
    p.turn = 90.0 * (smoothstep(15.3, 15.8, c) - smoothstep(31.3, 31.8, c));
    p.head.rotate(smoothstep(31.8, 32.4, c), [15.0, 0.0, 0.0]);
    p
}

/// Billie Jean: the hat pose, a moonwalk across the floor, a spin, up on the toes, "hee-hee", and a turn to the
/// camera.
fn moonwalk(t: f64) -> Pose {
    let mut p = Pose::default();
    let b = 60.0 / 117.0;
    let period = 2.0 * b;
    let (start, stop) = (2.0, 9.6);
    let heading: f64 = 80.0;
    let speed = 1.5 / (stop - start);
    // Facing the camera, then side on for the walk (front towards the right of the picture, walking backwards to
    // the left), a full spin, and back to the camera.
    p.turn = heading * smoothstep(1.6, 2.0, t) + 360.0 * smoothstep(9.6, 10.6, t) - heading * smoothstep(12.8, 13.4, t);
    let travel = speed * (t - start).clamp(0.0, stop - start);
    let back = DVec3::new(heading.to_radians().sin(), 0.0, heading.to_radians().cos());
    p.shift = DVec3::new(-0.75, 0.0, 0.0) + travel * back;

    let hat = [0.05, 0.62, -0.44];
    let right = [
        (0.0, RIGHT_HAND, 0.0),
        (0.2, hat, 0.5),
        (1.7, [0.3, 0.1, -0.2], 0.4),
        (9.6, [0.15, 0.28, -0.32], 0.3),
        (10.6, hat, 0.4),
    ];
    let left = [
        (0.0, LEFT_HAND, 0.0),
        (0.2, [-0.4, 0.02, -0.18], 0.5),
        (1.7, [-0.35, 0.1, -0.2], 0.4),
        (9.6, [-0.17, 0.28, -0.32], 0.3),
        (10.6, [-0.32, 0.0, 0.08], 0.4),
    ];
    let head = [
        (0.0, [0.0; 3], 0.0),
        (0.2, [-25.0, 0.0, 0.0], 0.4),
        (1.2, [10.0, 0.0, 0.0], 0.12),
        (1.7, [0.0; 3], 0.3),
        (10.6, [12.0, 0.0, 0.0], 0.3),
        (12.0, [28.0, 0.0, 0.0], 0.08),
        (12.3, [12.0, 0.0, 0.0], 0.3),
    ];
    p.right.to(1.0, RIGHT_HAND, track(t, &right));
    p.left.to(1.0, LEFT_HAND, track(t, &left));
    p.head.rotate(1.0, track(t, &head));

    // The walk: each foot in turn slides back flat while the other stands on its toes; the feet alternate between
    // a quarter step ahead of the body and a quarter step behind.
    let walk = window(t, start, stop, 0.25);
    let step = speed * period;
    let foot = |s: f64, lag: f64| {
        let k = s.floor();
        let f = s - k;
        let z = step * (k + smoothstep(0.0, 0.5, f)) - lag;
        let heel = smoothstep(0.5, 0.6, f) * (1.0 - smoothstep(0.92, 1.0, f));
        (z, heel)
    };
    let s = (t - start) / period;
    let body_z = speed * (t - start);
    let (z, heel) = foot(s, 0.25 * step);
    p.right_foot.add(walk, [0.0, 0.045 * heel, z - body_z], [-30.0 * heel, 0.0, 0.0]);
    let (z, heel) = foot(s + 0.5, 0.75 * step);
    p.left_foot.add(walk, [0.0, 0.045 * heel, z - body_z], [-30.0 * heel, 0.0, 0.0]);
    let beat = TAU * (t - start) / b;
    p.body.add(walk, [0.0, -0.025 + 0.012 * beat.cos(), 0.0], [-4.0, 0.0, 0.0]);
    p.right.add(walk, [0.0, 0.0, 0.06 * (beat / 2.0).sin()], [0.0; 3]);
    p.left.add(walk, [0.0, 0.0, -0.06 * (beat / 2.0).sin()], [0.0; 3]);
    p.head.rotate(walk, [-6.0 * (beat / 2.0).sin().powi(2), 0.0, 0.0]);

    // Up on the toes after the spin, with a hip thrust on the "hee-hee".
    let toes = window(t, 10.6, 30.0, 0.25);
    for f in [&mut p.left_foot, &mut p.right_foot] {
        f.add(toes, [0.0, 0.07, 0.0], [-35.0, 0.0, 0.0]);
    }
    let thrust = pulse((t - 12.0) / 0.3);
    p.body.add(toes, [0.0, 0.07, -0.06 * thrust], [10.0 * thrust, 0.0, 0.0]);
    p
}

/// The robot: hits on every beat that overshoot and settle, head snaps, a wave along the arms, a stiff march, a
/// head turning in ticks, the battery running out, a reboot and a salute.
fn robot(t: f64) -> Pose {
    let mut p = Pose::default();
    let b = 0.6;
    let t0 = 0.4;
    let at = |count: f64| t0 + count * b;
    const SNAP: f64 = 0.09;
    const DYING: f64 = 2.4;
    let (right_rest, left_rest) = ([0.28, 0.08, -0.45], [-0.3, 0.08, -0.45]);
    let (right_out, left_out) = ([0.65, 0.35, -0.1], [-0.68, 0.35, -0.1]);
    let right = [
        (0.0, RIGHT_HAND, 0.0),
        (at(0.0), right_rest, SNAP),
        (at(4.0), [0.3, 0.5, -0.3], SNAP),
        (at(6.0), right_rest, SNAP),
        (at(11.0), right_out, SNAP),
        (at(16.0), right_rest, SNAP),
        (at(22.0), [0.26, -0.12, -0.25], DYING),
        (at(26.0), right_rest, SNAP),
        (at(27.5), [0.2, 0.55, -0.42], 1.5 * SNAP),
    ];
    let left = [
        (0.0, LEFT_HAND, 0.0),
        (at(0.0), left_rest, SNAP),
        (at(5.0), [-0.32, 0.5, -0.3], SNAP),
        (at(7.0), left_rest, SNAP),
        (at(11.0), left_out, SNAP),
        (at(16.0), left_rest, SNAP),
        (at(22.0), [-0.28, -0.12, -0.25], DYING),
        (at(26.0), left_rest, SNAP),
    ];
    let head = [
        (0.0, [0.0; 3], 0.0),
        (at(1.0), [0.0, -60.0, 0.0], SNAP),
        (at(2.0), [0.0, 60.0, 0.0], SNAP),
        (at(3.0), [0.0; 3], SNAP),
        (at(20.0), [0.0, -20.0, 0.0], SNAP),
        (at(20.33), [0.0, -40.0, 0.0], SNAP),
        (at(20.67), [0.0, -60.0, 0.0], SNAP),
        (at(21.0), [0.0; 3], SNAP),
        (at(22.0), [-35.0, 0.0, 0.0], DYING),
        (at(26.0), [0.0; 3], SNAP),
        (at(27.5), [10.0, 0.0, 0.0], SNAP),
    ];
    let body_turn = [
        (0.0, [0.0; 3], 0.0),
        (at(8.0), [0.0, -35.0, 0.0], SNAP),
        (at(9.0), [0.0, 35.0, 0.0], SNAP),
        (at(10.0), [0.0; 3], SNAP),
        (at(22.0), [-15.0, 0.0, 0.0], DYING),
        (at(26.0), [0.0; 3], SNAP),
    ];
    let body_move = [(0.0, [0.0; 3], 0.0), (at(22.0), [0.0, -0.12, -0.03], DYING), (at(26.0), [0.0; 3], SNAP)];
    p.right.to(1.0, RIGHT_HAND, track(t, &right));
    p.left.to(1.0, LEFT_HAND, track(t, &left));
    p.head.rotate(1.0, track(t, &head));
    p.body.add(1.0, track(t, &body_move), track(t, &body_turn));

    // The wave: a bump runs from the left hand through the head to the right hand and back.
    let c = (t - t0) / b;
    let wave = window(t, at(12.0), at(16.0), 0.1);
    let s = -(PI * (c - 12.0) / 2.0).cos();
    let bump = |x: f64| (-((s - x) / 0.4).powi(2)).exp();
    p.left.add(wave, [0.0, 0.2 * bump(-1.0), 0.0], [0.0, 0.0, -30.0 * bump(-1.0)]);
    p.right.add(wave, [0.0, 0.2 * bump(1.0), 0.0], [0.0, 0.0, 30.0 * bump(1.0)]);
    p.head.add(wave, [0.0, 0.04 * bump(0.0), 0.0], [0.0, 0.0, 15.0 * bump(0.0) * s.signum()]);
    p.body.add(wave, [0.0, 0.03 * bump(0.0), 0.0], [0.0; 3]);

    // The march: a foot snaps up on each beat, the arms swing stiffly against the legs.
    let march = window(t, at(16.0), at(20.0), 0.1);
    let m = c - 16.0;
    let (k, f) = (m.floor(), m - m.floor());
    let lift = smoothstep(0.0, 0.15, f) * (1.0 - smoothstep(0.5, 0.65, f));
    let sign = if (k as i64).rem_euclid(2) == 0 { 1.0 } else { -1.0 };
    let arm = sign * (2.0 * smoothstep(0.0, 0.15, f) - 1.0);
    let (right_lift, left_lift) = if sign > 0.0 { (lift, 0.0) } else { (0.0, lift) };
    p.right_foot.add(march, [0.0, 0.1 * right_lift, 0.0], [0.0; 3]);
    p.left_foot.add(march, [0.0, 0.1 * left_lift, 0.0], [0.0; 3]);
    p.right.add(march, [0.0, 0.0, -0.12 * arm], [0.0; 3]);
    p.left.add(march, [0.0, 0.0, 0.12 * arm], [0.0; 3]);

    // Last twitches while the battery dies, and a head shake on reboot.
    let twitch = pulse((t - at(23.2)) / 0.15) + pulse((t - at(24.4)) / 0.15);
    p.head.rotate(1.0, [12.0 * twitch, 0.0, 0.0]);
    let shake = if (0.0..0.3).contains(&(t - at(26.0))) { (TAU * (t - at(26.0)) / 0.1).sin() } else { 0.0 };
    p.head.rotate(1.0, [0.0, 20.0 * shake, 0.0]);
    p
}

/// Watch Me (Whip/Nae Nae): two whips, the nae nae with the right arm up, two whips to the left, the nae nae with
/// the left arm, and a dab.
fn whip(t: f64) -> Pose {
    let mut p = Pose::default();
    let b = 0.43;
    let t0 = 0.5;
    let at = |count: f64| t0 + count * b;
    let c = (t - t0) / b;
    const SNAP: f64 = 0.08;
    let ease = 0.6 * b;
    // The whipping hand is cocked across the chest, then snaps out to the side.
    let (right_cocked, right_whip, right_steer) = ([0.1, 0.2, -0.42], [0.62, 0.3, -0.45], [0.22, 0.25, -0.5]);
    let (left_cocked, left_whip, left_steer) = ([-0.12, 0.2, -0.42], [-0.64, 0.3, -0.45], [-0.25, 0.25, -0.5]);
    let (right_up, left_up) = ([0.22, 0.92, -0.12], [-0.24, 0.92, -0.12]);
    let (right_across, left_across) = ([0.13, 0.15, -0.42], [-0.15, 0.15, -0.42]);
    let right = [
        (0.0, RIGHT_HAND, 0.0),
        (at(0.5), right_cocked, ease),
        (at(2.0), right_whip, SNAP),
        (at(4.5), right_cocked, ease),
        (at(6.0), right_whip, SNAP),
        (at(7.3), right_up, ease),
        (at(16.3), right_steer, ease),
        (at(23.3), right_across, ease),
        (at(33.0), [0.62, 0.72, -0.12], SNAP),
    ];
    let left = [
        (0.0, LEFT_HAND, 0.0),
        (at(0.5), left_steer, ease),
        (at(7.3), left_across, ease),
        (at(16.5), left_cocked, ease),
        (at(18.0), left_whip, SNAP),
        (at(20.5), left_cocked, ease),
        (at(22.0), left_whip, SNAP),
        (at(23.3), left_up, ease),
        (at(33.0), [0.3, 0.55, -0.42], SNAP),
    ];
    p.right.to(1.0, RIGHT_HAND, track(t, &right));
    p.left.to(1.0, LEFT_HAND, track(t, &left));

    // Each whip: lean back on the back leg, front foot out, head snapping down with the hand.
    for (count, side) in [(2.0, 1.0), (6.0, 1.0), (18.0, -1.0), (22.0, -1.0)] {
        let w = window(c, count - 1.5, count + 1.5, 0.5);
        p.body.add(w, [-0.05 * side, -0.05, 0.0], [8.0, 0.0, 0.0]);
        let snap = smoothstep(count - 0.05, count + 0.1, c) * (1.0 - smoothstep(count + 1.0, count + 1.8, c));
        p.head.rotate(snap, [-15.0, 0.0, 0.0]);
        let foot = if side > 0.0 { &mut p.right_foot } else { &mut p.left_foot };
        foot.add(w, [0.03 * side, 0.0, -0.1], [0.0, -20.0 * side, 0.0]);
    }

    // Nae nae: rock from side to side with knees bent, the raised hand waving, the other arm swinging across.
    let rock = (PI * c).sin();
    for (from, to, side) in [(8.0, 16.0, 1.0), (24.0, 32.0, -1.0)] {
        let w = window(c, from, to, 0.6);
        let (up, across) = if side > 0.0 { (&mut p.right, &mut p.left) } else { (&mut p.left, &mut p.right) };
        up.add(w, [0.1 * rock, 0.0, 0.0], [0.0, 0.0, -20.0 * rock]);
        across.add(w, [0.06 * rock, 0.0, 0.0], [0.0; 3]);
        p.body.add(w, [0.06 * rock, -0.06 - 0.02 * rock.abs(), 0.0], [0.0, 0.0, -6.0 * rock]);
        p.head.rotate(w, [0.0, 0.0, 8.0 * rock]);
        p.tail.add(w, [-0.08 * rock, 0.0, 0.0], [0.0; 3]);
    }

    // Dab: head down into the bent left elbow, right arm out and up.
    let dab = smoothstep(at(33.0) - 0.02, at(33.0) + 0.12, t);
    p.head.rotate(dab, [-30.0, 0.0, 15.0]);
    p.body.add(dab, [-0.03, -0.03, 0.0], [0.0, 0.0, 6.0]);
    p
}
