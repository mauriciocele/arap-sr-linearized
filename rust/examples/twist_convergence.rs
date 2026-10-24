//! Convergence of the 180-degree twist of the bar with the linearized (PCG) and the exact local step: the unit
//! SR-ARAP energy and the shape metrics as the local/global iterations go on.
//!
//! `cargo run --release --example twist_convergence [degrees]`
use arap::deformer::{Deformer, LocalStep};
use arap::scenes::{tube_scene, twist};

fn main() {
    let degrees: f64 = std::env::args().nth(1).map(|s| s.parse().unwrap()).unwrap_or(180.0);
    let checkpoints = [10, 30, 100, 300, 1000, 2000, 4000, 8000];
    for (name, step) in [("closed form (PCG)", LocalStep::Pcg), ("exact 3 sweeps", LocalStep::Exact { sweeps: 3 })] {
        let (mesh, handles) = tube_scene(81, 96);
        let mut d = Deformer::control_only(mesh, handles);
        twist(&mut d.handles[1], degrees);
        d.local_step = step;
        let mut done = 0;
        for &k in &checkpoints {
            while done < k {
                d.iterate();
                done += 1;
            }
            let (distortion, roughness) = d.shape_metrics();
            println!("{name:18} {k:5} iterations: energy {:.6e}, distortion {distortion:.4e}, roughness {roughness:.3} deg", d.unit_energy());
        }
    }
}
