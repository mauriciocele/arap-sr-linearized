//! Renders the paper's figures from real deformations computed by the solver, into
//! `../fast-linealized-rotation/figures/`. Opens a small window for the OpenGL context and closes it when done.
//!
//! `cargo run --release --bin render [all|teaser|pipeline|bar|cactus|colorbar|dance [name|all]]`

use std::fs::{self, File};
use std::io::BufWriter;
use std::path::{Path, PathBuf};

use arap::deformer::{ConstrainedRule, Deformer, LocalStep};
use arap::handle::Handle;
use arap::mesh::{Mesh, Vec3 as DVec3};
use arap::scenes::{arc, armadillo_handles, armadillo_pose, load, tube_length, tube_scene, twist};
use nalgebra::{UnitQuaternion, Vector3};
use three_d::*;

mod dance;

/// Output size in pixels, and the supersampling factor used for anti-aliasing.
const WIDTH: u32 = 1200;
const HEIGHT: u32 = 1200;
const SUPERSAMPLE: u32 = 3;

fn figures_dir() -> PathBuf {
    let dir = Path::new(env!("CARGO_MANIFEST_DIR")).join("../fast-linealized-rotation/figures");
    fs::create_dir_all(&dir).expect("figures directory");
    dir
}

/// What one image shows.
struct View {
    positions: Vec<DVec3>,
    normals: Vec<DVec3>,
    faces: Vec<[usize; 3]>,
    /// Per-vertex colours; the clay material is used when absent.
    colors: Option<Vec<Srgba>>,
    /// Handle spheres: centre and radius.
    handles: Vec<(DVec3, f64)>,
    handle_alpha: u8,
    /// A wireframe drawn over the surface, as (positions, faces).
    wire: Option<(Vec<DVec3>, Vec<[usize; 3]>)>,
    /// Rotation applied to the whole scene for display (some models are stored lying down).
    turn: UnitQuaternion<f64>,
    eye: Vec3,
    target: Vec3,
    fov: f32,
    width: u32,
    height: u32,
    /// Floor height; under the lowest point when absent.
    floor_y: Option<f64>,
}

impl View {
    fn surface(positions: Vec<DVec3>, normals: Vec<DVec3>, faces: Vec<[usize; 3]>) -> Self {
        View {
            positions,
            normals,
            faces,
            colors: None,
            handles: Vec::new(),
            handle_alpha: HANDLE.a,
            wire: None,
            turn: UnitQuaternion::identity(),
            eye: vec3(0.0, 0.0, -3.0),
            target: vec3(0.0, 0.0, 0.0),
            fov: 30.0,
            width: WIDTH,
            height: HEIGHT,
            floor_y: None,
        }
    }

    fn detail(d: &Deformer) -> Self {
        View::surface(d.high_positions.clone(), d.high_normals.clone(), d.high.faces.clone())
    }

    fn with_handles(mut self, d: &Deformer) -> Self {
        self.handles = d.handles.iter().map(|h| (h.center(), h.radius)).collect();
        self
    }

    fn looking(mut self, eye: [f32; 3], target: [f32; 3]) -> Self {
        self.eye = vec3(eye[0], eye[1], eye[2]);
        self.target = vec3(target[0], target[1], target[2]);
        self
    }

    fn turned(mut self, turn: UnitQuaternion<f64>) -> Self {
        self.turn = turn;
        self
    }

    /// Points the camera at the centre of the scene from direction `from` (towards the eye), backing off until the
    /// bounding sphere of the surface and handles fits the narrower field of view, with a small margin.
    fn framed(mut self, from: [f32; 3]) -> Self {
        let mut points: Vec<DVec3> = self.positions.iter().map(|p| self.turn * p).collect();
        for (c, r) in &self.handles {
            let c = self.turn * c;
            points.push(c + DVec3::repeat(*r));
            points.push(c - DVec3::repeat(*r));
        }
        let (min, max) = points.iter().fold((DVec3::repeat(f64::MAX), DVec3::repeat(f64::MIN)), |(a, b), p| (a.inf(p), b.sup(p)));
        let centre = (min + max) / 2.0;
        let radius = ((max - min).norm() / 2.0) as f32;
        let vertical = (self.fov / 2.0).to_radians();
        let horizontal = (vertical.tan() * self.width as f32 / self.height as f32).atan();
        let distance = 1.04 * radius / vertical.min(horizontal).sin();
        let dir = vec3(from[0], from[1], from[2]).normalize();
        self.target = f32v(&centre);
        self.eye = self.target + dir * distance;
        self
    }

    fn sized(mut self, width: u32, height: u32) -> Self {
        (self.width, self.height) = (width, height);
        self
    }
}

const CLAY: Srgba = Srgba { r: 196, g: 204, b: 222, a: 255 };
const HANDLE: Srgba = Srgba { r: 255, g: 140, b: 40, a: 90 };

fn f32v(p: &DVec3) -> Vec3 {
    vec3(p.x as f32, p.y as f32, p.z as f32)
}

/// Renders `view` offscreen with soft key-light shadows on a floor and saves it as a PNG in the figures directory.
fn render(context: &Context, view: &View, name: &str) {
    let path = figures_dir().join(format!("{name}.png"));
    render_to(context, view, &path, SUPERSAMPLE);
    println!("wrote {}", path.display());
}

fn render_to(context: &Context, view: &View, path: &Path, supersample: u32) {
    let turn = |p: &DVec3| view.turn * p;
    let positions: Vec<DVec3> = view.positions.iter().map(turn).collect();
    let normals: Vec<DVec3> = view.normals.iter().map(turn).collect();
    let (w, h) = (view.width * supersample, view.height * supersample);
    let camera = Camera::new_perspective(
        Viewport::new_at_origo(w, h),
        view.eye,
        view.target,
        vec3(0.0, 1.0, 0.0),
        degrees(view.fov),
        0.05,
        100.0,
    );

    let indices: Vec<u32> = view.faces.iter().flatten().map(|&i| i as u32).collect();
    let cpu = CpuMesh {
        positions: Positions::F32(positions.iter().map(f32v).collect()),
        normals: Some(normals.iter().map(f32v).collect()),
        colors: view.colors.clone(),
        indices: Indices::U32(indices),
        ..Default::default()
    };
    let albedo = if view.colors.is_some() { Srgba::WHITE } else { CLAY };
    let model = Gm::new(
        three_d::Mesh::new(context, &cpu),
        PhysicalMaterial::new_opaque(
            context,
            &CpuMaterial { albedo, roughness: 0.55, metallic: 0.0, ..Default::default() },
        ),
    );

    // A floor under the lowest point, large enough to catch the shadow.
    let floor_y = view.floor_y.unwrap_or_else(|| positions.iter().map(|p| p.y).fold(f64::MAX, f64::min)) as f32 - 0.002;
    let mut floor = Gm::new(
        three_d::Mesh::new(context, &CpuMesh::square()),
        PhysicalMaterial::new_opaque(
            context,
            &CpuMaterial { albedo: Srgba::new(250, 250, 250, 255), roughness: 0.9, metallic: 0.0, ..Default::default() },
        ),
    );
    floor.set_transformation(
        Mat4::from_translation(vec3(view.target.x, floor_y, view.target.z))
            * Mat4::from_scale(60.0)
            * Mat4::from_angle_x(degrees(-90.0)),
    );

    let sphere = CpuMesh::sphere(48);
    let handles: Vec<_> = view
        .handles
        .iter()
        .map(|(c, r)| {
            let mut s = Gm::new(
                three_d::Mesh::new(context, &sphere),
                PhysicalMaterial::new_transparent(
                    context,
                    &CpuMaterial {
                        albedo: Srgba { a: view.handle_alpha, ..HANDLE },
                        roughness: 0.25,
                        metallic: 0.0,
                        ..Default::default()
                    },
                ),
            );
            s.set_transformation(Mat4::from_translation(f32v(&turn(c))) * Mat4::from_scale(*r as f32));
            s
        })
        .collect();

    let wire = view.wire.as_ref().map(|(positions, faces)| {
        let soup: Vec<Vec3> = faces.iter().flatten().map(|&i| f32v(&turn(&positions[i]))).collect();
        Wireframe::new(context, &soup, 1.6 * supersample as f32, Srgba::new(40, 60, 110, 255))
    });

    // Key light from the upper left front casts the shadow; a weak fill from the right and an ambient term.
    let ambient = AmbientLight::new(context, 0.45, Srgba::WHITE);
    let mut key = DirectionalLight::new(context, 2.4, Srgba::WHITE, vec3(0.3, -1.0, 0.3));
    key.generate_shadow_map(4096, [&model.geometry]).expect("shadow map");
    let fill = DirectionalLight::new(context, 0.7, Srgba::new(225, 235, 255, 255), vec3(-0.7, -0.3, 0.8));

    let color = Texture2D::new_empty::<[u8; 4]>(
        context,
        w,
        h,
        Interpolation::Nearest,
        Interpolation::Nearest,
        None,
        Wrapping::ClampToEdge,
        Wrapping::ClampToEdge,
    );
    let depth = DepthTexture2D::new::<f32>(context, w, h, Wrapping::ClampToEdge, Wrapping::ClampToEdge);
    let target = RenderTarget::new(color.as_color_target(None), depth.as_depth_target());
    let lights: [&dyn Light; 3] = [&ambient, &key, &fill];
    // The background takes the colour of the lit floor (read from a floor-only pass at the bottom centre),
    // so the floor shows no horizon.
    target.clear(ClearState::color_and_depth(1.0, 1.0, 1.0, 1.0, 1.0));
    target.render(&camera, &floor, &lights);
    // Sample just below the far edge of the floor at the centre column (the first non-white row from the top).
    let floor_only = target.read_color::<[u8; 4]>();
    let column = w / 2;
    let horizon = (0..h).find(|&y| floor_only[(y * w + column) as usize][..3] != [255, 255, 255]).unwrap_or(h - 1);
    let floor_pixel = floor_only[((horizon + 8 * supersample).min(h - 1) * w + column) as usize];
    let [r, g, b, _] = floor_pixel.map(|c| c as f32 / 255.0);
    target.clear(ClearState::color_and_depth(r, g, b, 1.0, 1.0));
    target.render(&camera, floor.into_iter().chain(&model), &lights);
    if let Some(wire) = &wire {
        target.render(&camera, wire, &lights);
    }
    target.render(&camera, handles.iter().flat_map(|s| s.into_iter()), &lights);
    let pixels = target.read_color::<[u8; 4]>();
    save_png(path, &pixels, w, h, supersample);
}

/// Box-filters `factor` x `factor` blocks (anti-aliasing) and writes an RGB PNG. `pixels` are in top-down rows,
/// as `RenderTarget::read_color` returns them.
fn save_png(path: &Path, pixels: &[[u8; 4]], w: u32, h: u32, factor: u32) {
    let (ow, oh) = (w / factor, h / factor);
    let mut out = Vec::with_capacity((ow * oh * 3) as usize);
    for y in 0..oh {
        for x in 0..ow {
            let mut sum = [0u32; 3];
            for dy in 0..factor {
                for dx in 0..factor {
                    let p = pixels[((y * factor + dy) * w + x * factor + dx) as usize];
                    for c in 0..3 {
                        sum[c] += p[c] as u32;
                    }
                }
            }
            let n = factor * factor;
            out.extend(sum.iter().map(|&s| ((s + n / 2) / n) as u8));
        }
    }
    let file = BufWriter::new(File::create(path).expect("create PNG"));
    let mut encoder = png::Encoder::new(file, ow, oh);
    encoder.set_color(png::ColorType::Rgb);
    encoder.set_depth(png::BitDepth::Eight);
    encoder.write_header().unwrap().write_image_data(&out).unwrap();
}

/// The viridis colour map, interpolated between 11 anchors.
fn viridis(t: f64) -> Srgba {
    const ANCHORS: [[u8; 3]; 11] = [
        [0x44, 0x01, 0x54],
        [0x48, 0x24, 0x75],
        [0x41, 0x44, 0x87],
        [0x35, 0x5f, 0x8d],
        [0x2a, 0x78, 0x8e],
        [0x21, 0x91, 0x8c],
        [0x22, 0xa8, 0x84],
        [0x44, 0xbf, 0x70],
        [0x7a, 0xd1, 0x51],
        [0xbd, 0xdf, 0x26],
        [0xfd, 0xe7, 0x25],
    ];
    let x = t.clamp(0.0, 1.0) * 10.0;
    let i = (x.floor() as usize).min(9);
    let f = x - i as f64;
    let mix = |a: u8, b: u8| (a as f64 + (b as f64 - a as f64) * f).round() as u8;
    let (a, b) = (ANCHORS[i], ANCHORS[i + 1]);
    Srgba::new(mix(a[0], b[0]), mix(a[1], b[1]), mix(a[2], b[2]), 255)
}

fn rotation_angles(rotations: &[UnitQuaternion<f64>]) -> Vec<f64> {
    rotations.iter().map(|q| q.angle()).collect()
}

fn colored(values: &[f64], max: f64) -> Vec<Srgba> {
    values.iter().map(|&v| viridis(v / max)).collect()
}

/// Converges the deformation with the closed-form local step and transfers it to the detailed mesh.
fn converge(d: &mut Deformer, iterations: usize) {
    for _ in 0..iterations {
        d.iterate();
    }
    d.update_high();
}

fn armadillo() -> Deformer {
    Deformer::new(load("armadillo.obj"), load("armadillo1.obj"), armadillo_handles())
}

fn rot(axis: Vector3<f64>, degrees: f64) -> UnitQuaternion<f64> {
    UnitQuaternion::from_axis_angle(&nalgebra::Unit::new_normalize(axis), degrees.to_radians())
}

fn teaser(context: &Context) {
    let mut d = armadillo();
    let eye = [1.2, 0.55, -3.6];
    let target = [0.0, 0.12, 0.0];
    let view = |d: &Deformer| {
        let mut v = View::detail(d).with_handles(d).looking(eye, target).sized(900, 1200);
        v.handle_alpha = 55;
        v
    };
    d.update_high();
    render(context, &view(&d), "teaser_rest");
    for k in 1..=3 {
        armadillo_pose(&mut d, k);
        converge(&mut d, 300);
        render(context, &view(&d), &format!("teaser_pose{k}"));
    }
}

fn pipeline(context: &Context) {
    let mut d = armadillo();
    armadillo_pose(&mut d, 2);
    converge(&mut d, 200);
    let eye = [1.2, 0.55, -3.6];
    let target = [0.0, 0.12, 0.0];
    // The control mesh's rest normals turned by its rotations, for shading.
    let low_normals: Vec<DVec3> = d.low.normals.iter().zip(d.low_rotations()).map(|(n, r)| r * n).collect();
    // (a) The deformed control mesh with its handles.
    let low = View {
        wire: Some((d.low_positions().to_vec(), d.low.faces.clone())),
        ..View::surface(d.low_positions().to_vec(), low_normals.clone(), d.low.faces.clone())
    };
    render(context, &low.with_handles(&d).looking(eye, target).sized(900, 1200), "pipeline_a_control");
    // (b) Its rotation field, as the rotation angle of each cell.
    let low_angles = rotation_angles(d.low_rotations());
    let max = low_angles.iter().cloned().fold(0.0, f64::max);
    println!("pipeline: largest control rotation {:.1} degrees", max.to_degrees());
    let mut b = View::surface(d.low_positions().to_vec(), low_normals, d.low.faces.clone());
    b.colors = Some(colored(&low_angles, max));
    render(context, &b.looking(eye, target).sized(900, 1200), "pipeline_b_rotations");
    // (c) The rotation field interpolated harmonically onto the detailed mesh.
    let mut c = View::detail(&d);
    c.colors = Some(colored(&rotation_angles(d.high_rotations()), max));
    render(context, &c.looking(eye, target).sized(900, 1200), "pipeline_c_transfer");
    // (d) The final detailed surface.
    render(context, &View::detail(&d).looking(eye, target).sized(900, 1200), "pipeline_d_result");
}

/// Stripes around the tube's axis, so that twisting is visible.
fn stripes(rest: &Mesh) -> Vec<Srgba> {
    rest.positions
        .iter()
        .map(|p| {
            let a = p.z.atan2(p.x);
            if ((a / std::f64::consts::TAU * 12.0).rem_euclid(1.0)) < 0.5 { Srgba::new(70, 110, 190, 255) } else { CLAY }
        })
        .collect()
}

fn bar(context: &Context) {
    // Twist alone, and twist combined with circular arcs of 90 and 180 degrees, converged with the closed form.
    // Large twists need many local/global iterations: at 600 the 180 degree twist is still bunched under the top
    // handle; at 2000 it is spread evenly along the bar.
    for (name, arc_degrees) in [("bar_twist", 0.0), ("bar_twist_arc90", 90.0), ("bar_twist_arc180", 180.0)] {
        let (mesh, handles) = tube_scene(81, 96);
        let length = tube_length(&mesh);
        let colors = stripes(&mesh);
        let mut d = Deformer::control_only(mesh, handles);
        if arc_degrees > 0.0 {
            arc(&mut d.handles[1], length, arc_degrees);
        }
        // Twist about the bar's own axis at the top, then follow the arc.
        d.handles[1].rotation *= rot(Vector3::y(), 180.0);
        converge(&mut d, 2000);
        let (width, height) = if arc_degrees > 0.0 { (1000, 1000) } else { (800, 1200) };
        let mut v = View::detail(&d).with_handles(&d).sized(width, height);
        v.colors = Some(colors);
        render(context, &v.framed([0.35, 0.3, -1.0]), name);
    }
}

/// Twist angles on the bar, converged for longer, to see where the closed form stops spreading the twist.
fn twist_sweep(context: &Context) {
    let eye = [0.9, 0.5, -5.2];
    let target = [-0.25, 0.0, 0.0];
    for degrees in [90.0, 135.0, 180.0] {
        let (mesh, handles) = tube_scene(81, 96);
        let colors = stripes(&mesh);
        let mut d = Deformer::control_only(mesh, handles);
        twist(&mut d.handles[1], degrees);
        converge(&mut d, 2000);
        // How much of the twist each height carries: the rotation angle of the free cells, by height.
        let mut bands = [(0.0f64, 0usize); 10];
        let (ymin, ymax) = d.low.positions.iter().fold((f64::MAX, f64::MIN), |(a, b), p| (a.min(p.y), b.max(p.y)));
        for (i, p) in d.low.positions.iter().enumerate() {
            let band = (((p.y - ymin) / (ymax - ymin) * 10.0) as usize).min(9);
            bands[band].0 += d.low_rotations()[i].angle().to_degrees();
            bands[band].1 += 1;
        }
        let profile: Vec<String> = bands.iter().map(|(s, c)| format!("{:.0}", s / *c as f64)).collect();
        println!("twist {degrees}: mean rotation by height (bottom to top): {}", profile.join(" "));
        let mut v = View::detail(&d).with_handles(&d).looking(eye, target).sized(800, 1200);
        v.colors = Some(colors);
        render(context, &v, &format!("twist_{degrees}"));
    }
}

/// The bar bent into circular arcs of 90 and 180 degrees, and the 180 degree arc with the original SR-ARAP local
/// step, coloured by its distance to the closed-form shape.
fn arcs(context: &Context) {
    let from = [0.35, 0.3, -1.0];
    let mut closed_180 = Vec::new();
    for degrees in [90.0, 180.0] {
        let (mesh, handles) = tube_scene(81, 96);
        let length = tube_length(&mesh);
        let colors = stripes(&mesh);
        let mut d = Deformer::control_only(mesh, handles);
        arc(&mut d.handles[1], length, degrees);
        converge(&mut d, 2000);
        if degrees == 180.0 {
            closed_180 = d.high_positions.clone();
        }
        let mut v = View::detail(&d).with_handles(&d).sized(1000, 1000);
        v.colors = Some(colors);
        render(context, &v.framed(from), &format!("arc_{degrees}"));
    }
    let (mesh, handles) = tube_scene(81, 96);
    let length = tube_length(&mesh);
    let mut d = Deformer::control_only(mesh, handles);
    d.local_step = LocalStep::SrArap { sweeps: 3 };
    arc(&mut d.handles[1], length, 180.0);
    converge(&mut d, 2000);
    let gap: Vec<f64> = d.high_positions.iter().zip(&closed_180).map(|(a, b)| (a - b).norm() / length).collect();
    let max = gap.iter().cloned().fold(0.0, f64::max);
    println!("arc 180: SR-ARAP is at most {:.2}% of the bar length from the closed-form shape", 100.0 * max);
    let mut v = View::detail(&d).with_handles(&d).sized(1000, 1000);
    v.colors = Some(colored(&gap, max));
    render(context, &v.framed(from), "arc_180_srarap");
}

/// A 270 degree twist reached gradually (3 degrees per step, 20 iterations each, as when dragging), with and
/// without feedback, and set at once. The end handle at 270 degrees puts its vertices where -90 degrees would, so
/// only the history can tell the solver which way round the twist goes.
fn twist270(context: &Context) {
    let mut csv = String::from("run,band,height,twist_deg\n");
    for (name, feedback, gradual) in [
        ("twist270_gradual_feedback", 0.2, true),
        ("twist270_gradual_nofeedback", 0.0, true),
        ("twist270_at_once_feedback", 0.2, false),
    ] {
        let (mesh, handles) = tube_scene(81, 96);
        let colors = stripes(&mesh);
        let mut d = Deformer::control_only(mesh, handles);
        d.feedback = feedback;
        if gradual {
            for step in 1..=90 {
                twist(&mut d.handles[1], 3.0 * step as f64);
                for _ in 0..20 {
                    d.iterate();
                }
            }
        } else {
            twist(&mut d.handles[1], 270.0);
        }
        converge(&mut d, 1000);
        // Signed twist about the bar's axis, by height: 2 atan2(q_y, q_w) follows the quaternion's branch, so it
        // can exceed 180 degrees when the field winds that far.
        let (ymin, ymax) = d.low.positions.iter().fold((f64::MAX, f64::MIN), |(a, b), p| (a.min(p.y), b.max(p.y)));
        let mut bands = [(0.0f64, 0usize); 10];
        for (i, p) in d.low.positions.iter().enumerate() {
            let band = (((p.y - ymin) / (ymax - ymin) * 10.0) as usize).min(9);
            let q = d.low_rotations()[i];
            bands[band].0 += 2.0 * q.j.atan2(q.w).to_degrees();
            bands[band].1 += 1;
        }
        let profile: Vec<String> = bands.iter().map(|(s, c)| format!("{:.0}", s / *c as f64)).collect();
        println!("{name}: twist by height, bottom to top (degrees): {}", profile.join(" "));
        for (band, (sum, count)) in bands.iter().enumerate() {
            let height = (band as f64 + 0.5) / 10.0;
            csv.push_str(&format!("{name},{band},{height:.2},{:.1}\n", sum / *count as f64));
        }
        let mut v = View::detail(&d).with_handles(&d).sized(800, 1200);
        v.colors = Some(colors);
        render(context, &v.framed([0.35, 0.3, -1.0]), name);
    }
    let path = Path::new(env!("CARGO_MANIFEST_DIR")).join("../fast-linealized-rotation/data/twist270.csv");
    fs::write(&path, csv).expect("write twist270.csv");
    println!("wrote {}", path.display());
}

fn cactus(context: &Context) {
    let handles = vec![
        Handle::new(DVec3::new(0.0, 0.04, 0.7), 0.15),
        Handle::new(DVec3::new(0.0, 0.04, -0.8), 0.15),
    ];
    let mut d = Deformer::new(load("cactus2.obj"), load("cactus1.obj"), handles);
    // The cactus is stored lying along z with its arms towards +z; stand it up (z becomes y) and turn its arms
    // to the side.
    let upright = rot(Vector3::y(), 90.0) * rot(Vector3::x(), -90.0);
    let from = [0.17, 0.12, -1.0];
    d.update_high();
    render(context, &View::detail(&d).with_handles(&d).turned(upright).framed(from), "cactus_rest");
    // Keep the base (handle 1, at z = -0.8) and bend the trunk along a circular arc of 120 degrees: the top handle
    // (at z = 0.7) turns by the arc angle and moves to the end of the arc, keeping the trunk's length. In model
    // coordinates the trunk runs along +z and the arc bends towards +y.
    let (top, base) = (0.7, -0.8);
    let phi = 120f64.to_radians();
    let radius = (top - base) / phi;
    d.handles[0].rotation = rot(Vector3::x(), -120.0);
    d.handles[0].translation = DVec3::new(0.0, radius * (1.0 - phi.cos()), base + radius * phi.sin() - top);
    converge(&mut d, 1000);
    render(context, &View::detail(&d).with_handles(&d).turned(upright).framed(from), "cactus_bent");
    // The top handle moved far sideways and down without rotating it.
    d.handles[0].rotation = UnitQuaternion::identity();
    d.handles[0].translation = DVec3::new(0.0, 0.9, -0.45);
    converge(&mut d, 1000);
    render(context, &View::detail(&d).with_handles(&d).turned(upright).framed(from), "cactus_moved");
}

/// A horizontal viridis strip for the figure legends.
fn colorbar() {
    let (w, h) = (1024u32, 48u32);
    let mut pixels = Vec::with_capacity((w * h) as usize);
    for _ in 0..h {
        for x in 0..w {
            let c = viridis(x as f64 / (w - 1) as f64);
            pixels.push([c.r, c.g, c.b, 255]);
        }
    }
    let path = figures_dir().join("colorbar.png");
    save_png(&path, &pixels, w, h, 1);
    println!("wrote {}", path.display());
}

/// The 180-degree twist, and the twist following a 180-degree arc, after a few hundred iterations with the
/// paper's rule for the constrained cells and with the adaptive rule (own fit in the hard case).
fn adaptive(context: &Context) {
    for (scene, iterations) in [("twist180", 100), ("arc180_twist180", 300)] {
        for (name, rule) in [("smoothed", ConstrainedRule::Smoothed), ("adaptive", ConstrainedRule::Adaptive { threshold_deg: 90 })] {
            let (mesh, handles) = tube_scene(81, 96);
            let length = tube_length(&mesh);
            let colors = stripes(&mesh);
            let mut d = Deformer::control_only(mesh, handles);
            if scene == "arc180_twist180" {
                arc(&mut d.handles[1], length, 180.0);
            }
            d.handles[1].rotation *= rot(Vector3::y(), 180.0);
            d.local_step = LocalStep::Pcg;
            d.constrained_rule = rule;
            converge(&mut d, iterations);
            let (width, height) = if scene == "twist180" { (800, 1200) } else { (1000, 1000) };
            let mut v = View::detail(&d).with_handles(&d).sized(width, height);
            v.colors = Some(colors);
            render(context, &v.framed([0.35, 0.3, -1.0]), &format!("{scene}_{iterations}_{name}"));
        }
    }
}

fn main() {
    let which = std::env::args().nth(1).unwrap_or_else(|| "all".to_string());
    let window = Window::new(WindowSettings {
        title: "rendering figures".to_string(),
        initial_size: Some((320, 240)),
        ..Default::default()
    })
    .expect("window for the OpenGL context");
    let context = window.gl();
    let mut done = false;
    window.render_loop(move |_frame| {
        if done {
            return FrameOutput { exit: true, ..Default::default() };
        }
        done = true;
        if which == "all" || which == "colorbar" {
            colorbar();
        }
        if which == "all" || which == "teaser" {
            teaser(&context);
        }
        if which == "all" || which == "pipeline" {
            pipeline(&context);
        }
        if which == "all" || which == "bar" {
            bar(&context);
        }
        if which == "all" || which == "arcs" {
            arcs(&context);
        }
        if which == "twist270" {
            twist270(&context);
        }
        if which == "twist_sweep" {
            twist_sweep(&context);
        }
        if which == "adaptive" {
            adaptive(&context);
        }
        if which == "dance" {
            dance::dance(&context, std::env::args().nth(2).as_deref().unwrap_or("all"));
        }
        if which == "all" || which == "cactus" {
            cactus(&context);
        }
        FrameOutput { exit: true, ..Default::default() }
    });
}
