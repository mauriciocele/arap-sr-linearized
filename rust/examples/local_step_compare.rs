//! Local-step time of the paper's methods (closed form, PCG, linearized relaxation) against the SR-ARAP baseline with
//! the SVD and with the rotor estimator in SIMD lanes, from the same mid-solve state.
//!
//! `cargo run --release --example local_step_compare`
use std::time::Instant;
use arap::deformer::{Deformer, Fit, LocalStep};
use arap::scenes::{arc, armadillo_handles, armadillo_pose, load, tube_length, tube_scene};

fn main() {
    for scene in ["armadillo", "bar81", "bar161"] {
        let make = || match scene {
            "armadillo" => {
                let mut d = Deformer::new(load("armadillo.obj"), load("armadillo1.obj"), armadillo_handles());
                armadillo_pose(&mut d, 2);
                d
            }
            _ => {
                let (r, s) = if scene == "bar81" { (81, 96) } else { (161, 192) };
                let (mesh, handles) = tube_scene(r, s);
                let length = tube_length(&mesh);
                let mut d = Deformer::control_only(mesh, handles);
                arc(&mut d.handles[1], length, 90.0);
                d
            }
        };
        let mut d = make();
        d.local_step = LocalStep::Pcg;
        for _ in 0..5 {
            d.iterate();
        }
        let start = d.low_rotations().to_vec();
        let methods = [
            ("closed form", LocalStep::ClosedForm, Fit::Svd),
            ("PCG", LocalStep::Pcg, Fit::Svd),
            ("relaxation, 3 sweeps", LocalStep::Relaxation { sweeps: 3 }, Fit::Svd),
            ("SR-ARAP 3 sweeps, SVD", LocalStep::SrArap { sweeps: 3 }, Fit::Svd),
            ("SR-ARAP 3 sweeps, rotor SIMD", LocalStep::SrArap { sweeps: 3 }, Fit::RotorSimd),
        ];
        println!("{scene} ({} cells)", d.low.num_vertices());
        for (name, step, fit) in methods {
            d.local_step = step;
            d.fit = fit;
            d.set_low_rotations(&start);
            d.local(); // warm-up: symbolic factorizations, preconditioner, colouring
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
            println!("  {name:30} {best:8.3} ms");
        }
    }
}
