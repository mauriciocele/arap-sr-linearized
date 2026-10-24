//! Own-fit constrained cells for the first iterations only, then the paper's smoothed rule: does the 180-degree
//! twist leave its stall and still reach the paper's fixed point?
//!
//! `cargo run --release --example ownfit_warmstart`
use arap::deformer::{ConstrainedRule, Deformer, LocalStep};
use arap::scenes::{tube_scene, twist};

fn main() {
    use arap::scenes::{arc, armadillo_handles, armadillo_pose, load, tube_length};
    for scene in ["twist180", "arc180_twist180", "arc90", "armadillo"] {
        for (name, rule) in [("smoothed", ConstrainedRule::Smoothed), ("adaptive 90", ConstrainedRule::Adaptive { threshold_deg: 90 })] {
            let mut d = match scene {
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
                        "arc90" => arc(&mut d.handles[1], length, 90.0),
                        "arc180_twist180" => {
                            arc(&mut d.handles[1], length, 180.0);
                            d.handles[1].rotation *= nalgebra::UnitQuaternion::from_axis_angle(&nalgebra::Vector3::y_axis(), std::f64::consts::PI);
                        }
                        _ => twist(&mut d.handles[1], 180.0),
                    }
                    d
                }
            };
            d.local_step = LocalStep::Pcg;
            d.constrained_rule = rule;
            let mut out = String::new();
            let mut done = 0;
            let checkpoints: &[usize] = if scene == "armadillo" { &[10, 30, 100, 300] } else { &[30, 100, 300, 1000, 2000, 3000] };
            for &k in checkpoints {
                while done < k { d.iterate(); done += 1; }
                let (distortion, roughness) = d.shape_metrics();
                out += &format!("  {k}: E {:.4} D {:.3e} r {:.2}", d.energy(), distortion, roughness);
            }
            println!("{scene:16} {name:12}{out}");
        }
    }
    return;
    for warm in [0usize, 10, 30, 100] {
        let (mesh, handles) = tube_scene(81, 96);
        let mut d = Deformer::control_only(mesh, handles);
        twist(&mut d.handles[1], 180.0);
        d.local_step = LocalStep::Pcg;
        let mut out = String::new();
        let mut done = 0;
        for k in [30usize, 100, 300, 1000, 2000] {
            while done < k {
                d.constrained_rule = if done < warm { ConstrainedRule::OwnFit } else { ConstrainedRule::Smoothed };
                d.iterate();
                done += 1;
            }
            let (distortion, roughness) = d.shape_metrics();
            out += &format!("  {k}: E {:.4} D {:.3e} r {:.2}", d.energy(), distortion, roughness);
        }
        println!("own fit for the first {warm:3} iterations:{out}");
    }
}
