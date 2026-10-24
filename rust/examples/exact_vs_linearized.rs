//! The exact local step (unit norm enforced, multiplier solved for) against the linearized one (multiplier frozen
//! at -alpha A): per-cell statistics at a mid-solve state, local-step times, and the shapes after a full solve.
//!
//! `cargo run --release --example exact_vs_linearized`
use std::time::Instant;

use arap::deformer::{Deformer, LocalStep};
use arap::scenes::{arc, armadillo_handles, armadillo_pose, load, tube_length, tube_scene, twist};

fn percentile(v: &mut [f64], p: f64) -> f64 {
    v.sort_by(f64::total_cmp);
    v[((v.len() - 1) as f64 * p).round() as usize]
}

fn main() {
    for scene in ["armadillo", "bar_arc90", "bar_twist180"] {
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
                if scene == "bar_arc90" {
                    arc(&mut d.handles[1], length, 90.0);
                } else {
                    twist(&mut d.handles[1], 180.0);
                }
                d
            }
        };
        let iterations = if scene == "armadillo" { 300 } else { 1000 };
        // per-cell statistics at a mid-solve state
        let mut d = make();
        d.local_step = LocalStep::Pcg;
        for _ in 0..5 {
            d.iterate();
        }
        let stats = d.exact_cell_statistics(false);
        let alpha_area = -stats[0].1;
        let mut rel: Vec<f64> = stats.iter().map(|s| (s.0 - s.1).abs() / alpha_area).collect();
        let mut ang: Vec<f64> = stats.iter().map(|s| s.5).collect();
        let eig: f64 = stats.iter().map(|s| s.3 as f64).sum::<f64>() / stats.len() as f64;
        let sec: f64 = stats.iter().map(|s| s.4 as f64).sum::<f64>() / stats.len() as f64;
        let sec_max = stats.iter().map(|s| s.4).max().unwrap();
        println!("{scene} ({} cells), mid-solve state:", d.low.num_vertices());
        println!(
            "  |lambda* + alpha A| / alpha A: median {:.2e}, 99% {:.2e}, max {:.2e}",
            percentile(&mut rel, 0.5),
            percentile(&mut rel, 0.99),
            percentile(&mut rel, 1.0)
        );
        println!(
            "  angle exact vs linearized cell: median {:.2e} rad, 99% {:.2e}, max {:.2e}",
            percentile(&mut ang, 0.5),
            percentile(&mut ang, 0.99),
            percentile(&mut ang, 1.0)
        );
        println!("  Newton steps: eigenvalue {eig:.2} mean, secular {sec:.2} mean ({sec_max} max)");

        // full solves
        let mut reference: Option<Vec<arap::mesh::Vec3>> = None;
        for (name, step) in [
            ("closed form (PCG)", LocalStep::Pcg),
            ("relaxation 3 sweeps", LocalStep::Relaxation { sweeps: 3 }),
            ("exact 3 sweeps", LocalStep::Exact { sweeps: 3 }),
            ("exact 10 sweeps", LocalStep::Exact { sweeps: 10 }),
        ] {
            let mut d = make();
            d.local_step = step;
            for _ in 0..iterations {
                d.iterate();
            }
            let start = d.low_rotations().to_vec();
            let reps = if scene == "armadillo" { 200 } else { 20 };
            let mut best = f64::MAX;
            for _ in 0..3 {
                let mut total = 0.0;
                for _ in 0..reps {
                    d.set_low_rotations(&start);
                    let t = Instant::now();
                    d.local();
                    total += t.elapsed().as_secs_f64();
                }
                best = best.min(total * 1e3 / reps as f64);
            }
            d.set_low_rotations(&start);
            let (distortion, roughness) = d.shape_metrics();
            let energy = d.unit_energy();
            let gap = reference
                .as_ref()
                .map(|r| r.iter().zip(d.low_positions()).map(|(a, b)| (a - b).norm()).fold(0.0, f64::max))
                .unwrap_or(0.0);
            if reference.is_none() {
                reference = Some(d.low_positions().to_vec());
            }
            println!(
                "  {name:22} local {best:7.3} ms, energy {energy:.6e}, distortion {distortion:.4e}, roughness {roughness:.3} deg, \
                 max distance to closed form {gap:.2e}"
            );
        }
    }
}
