//! The handle cells at the first local step and at the fixed point: their pull angle and the stiffness ratios
//! that bound the lag of the cell equation behind their own fit (Proposition `prop:lag` of the paper).
//!
//! `cargo run --release --example handle_cells`
use arap::deformer::Deformer;
use arap::scenes::{arc, armadillo_handles, armadillo_pose, load, tube_length, tube_scene, twist};

fn main() {
    for scene in ["bar_twist180", "bar_arc180_twist180", "bar_arc90", "armadillo"] {
        let make = || match scene {
            "armadillo" => {
                let mut d = Deformer::new(load("armadillo.obj"), load("armadillo1.obj"), armadillo_handles());
                armadillo_pose(&mut d, 2);
                d
            }
            _ => {
                let (mesh, handles) = tube_scene(81, 96);
                let length = tube_length(&mesh);
                let mut d = Deformer::control_only(mesh, handles);
                match scene {
                    "bar_arc90" => arc(&mut d.handles[1], length, 90.0),
                    "bar_arc180_twist180" => {
                        arc(&mut d.handles[1], length, 180.0);
                        d.handles[1].rotation *=
                            nalgebra::UnitQuaternion::from_axis_angle(&nalgebra::Vector3::y_axis(), std::f64::consts::PI);
                    }
                    _ => twist(&mut d.handles[1], 180.0),
                }
                d
            }
        };
        let mut d = make();
        d.global();
        let report = |d: &Deformer, when: &str| {
            let s = d.handle_cell_statistics();
            let pull_max = s.iter().map(|x| x.0).fold(0.0, f64::max);
            let triggered = s.iter().filter(|x| x.0 > 90.0).count();
            let r2_max = s.iter().map(|x| x.1).fold(0.0, f64::max);
            let r4_min = s.iter().map(|x| x.2).fold(f64::MAX, f64::min);
            println!(
                "{scene:20} {when:12} {} handle cells: pull max {pull_max:6.2} deg, {triggered} above 90; \
                 (m1+aA)/(m2+aA) max {r2_max:.3}, (m1+aA)/(m4+aA) min {r4_min:.4}",
                s.len()
            );
        };
        report(&d, "first step");
        for _ in 0..if scene == "armadillo" { 300 } else { 3000 } {
            d.iterate();
        }
        report(&d, "fixed point");
    }
}
