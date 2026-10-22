//! Measurements for the paper's Results section. Writes CSV files (read by pgfplots) into
//! `../fast-linealized-rotation/data/`.
//!
//! `cargo run --release --bin experiments [all|convergence|energy|timing]`

use std::fmt::Write as _;
use std::fs;
use std::path::{Path, PathBuf};

use std::time::Instant;

use arap::deformer::{Deformer, LocalStep};
use arap::handle::Handle;
use arap::mesh::{Mesh, Vec3};
use arap::scenes::{arc, armadillo_handles, armadillo_pose, bend, load, models, raise_arms, tube_length, tube_scene};

fn data_dir() -> PathBuf {
    let dir = Path::new(env!("CARGO_MANIFEST_DIR")).join("../fast-linealized-rotation/data");
    fs::create_dir_all(&dir).expect("data directory");
    dir
}

fn write(name: &str, contents: &str) {
    let path = data_dir().join(name);
    fs::write(&path, contents).expect("write CSV");
    println!("wrote {}", path.display());
}

fn mean_ms(reps: usize, mut f: impl FnMut()) -> f64 {
    let start = Instant::now();
    for _ in 0..reps {
        f();
    }
    start.elapsed().as_secs_f64() * 1e3 / reps as f64
}

/// Relaxation sweeps against the closed-form local step, as the mesh grows. Two starting states:
/// - `cold`: the first local step right after the handle moves (rotations still at rest);
/// - `warm`: a local step in the middle of the solve, after five closed-form iterations.
fn convergence() {
    let mut summary = String::from(
        "scenario,n,closed_ms,sweep_ms,sweeps_1e-2,sweeps_1e-3,sweeps_1e-4,max_sweeps,error_1,error_3,final_error\n",
    );
    let mut curves = String::from("scenario,n,sweep,error\n");
    for (rings, segments) in [(21, 24), (41, 48), (81, 96), (161, 192), (321, 384)] {
        for scenario in ["cold", "warm"] {
            let (mesh, handles) = tube_scene(rings, segments);
            let length = tube_length(&mesh);
            let n = mesh.num_vertices();
            assert!(mesh.neighbors.iter().all(|r| r.len() <= 32), "valence above 32 takes the LU fallback");
            let mut d = Deformer::control_only(mesh, handles);
            bend(&mut d.handles[1], length);
            d.global();
            if scenario == "warm" {
                for _ in 0..5 {
                    d.iterate();
                }
            }
            let max_sweeps = if n > 50_000 { 6000 } else { 20000 };
            let start = Instant::now();
            let errors = d.relaxation_errors(max_sweeps);
            let sweep_ms = start.elapsed().as_secs_f64() * 1e3 / max_sweeps as f64;
            d.local_step = LocalStep::ClosedForm;
            let closed_ms = mean_ms(3, || d.local());
            let first_below = |tol: f64| {
                errors.iter().position(|&e| e < tol).map_or(String::from("nan"), |k| (k + 1).to_string())
            };
            writeln!(
                summary,
                "{scenario},{n},{closed_ms:.4},{sweep_ms:.4},{},{},{},{max_sweeps},{:.3e},{:.3e},{:.3e}",
                first_below(1e-2),
                first_below(1e-3),
                first_below(1e-4),
                errors[0],
                errors[2],
                errors.last().unwrap()
            )
            .unwrap();
            // Log-spaced samples keep the curve files small.
            let mut k = 1usize;
            while k <= errors.len() {
                writeln!(curves, "{scenario},{n},{k},{:.6e}", errors[k - 1].max(1e-16)).unwrap();
                k = ((k as f64) * 1.15).ceil().max(k as f64 + 1.0) as usize;
            }
            println!(
                "{scenario} n={n}: closed form {closed_ms:.2} ms, sweep {sweep_ms:.3} ms, error after 3 sweeps \
                 {:.2e}, below 1e-3 after {} sweeps",
                errors[2],
                first_below(1e-3)
            );
        }
    }
    write("convergence_summary.csv", &summary);
    write("convergence_curves.csv", &curves);
}

/// Sweeps relaxation needs to match the closed form (cold start), for decreasing feedback weights.
fn feedback() {
    let mut csv = String::from("feedback,n,closed_ms,sweep_ms,sweeps_1e-3,error_3,final_error\n");
    for e in [0.2, 0.02, 0.0] {
        for (rings, segments) in [(21, 24), (41, 48), (81, 96), (161, 192)] {
            let (mesh, handles) = tube_scene(rings, segments);
            let length = tube_length(&mesh);
            let n = mesh.num_vertices();
            let mut d = Deformer::control_only(mesh, handles);
            d.feedback = e;
            bend(&mut d.handles[1], length);
            d.global();
            let max_sweeps = 20000;
            let start = Instant::now();
            let errors = d.relaxation_errors(max_sweeps);
            let sweep_ms = start.elapsed().as_secs_f64() * 1e3 / max_sweeps as f64;
            d.local_step = LocalStep::ClosedForm;
            let closed_ms = mean_ms(3, || d.local());
            let below = errors.iter().position(|&x| x < 1e-3).map_or(String::from("nan"), |k| (k + 1).to_string());
            writeln!(csv, "{e},{n},{closed_ms:.4},{sweep_ms:.4},{below},{:.3e},{:.3e}", errors[2], errors.last().unwrap())
                .unwrap();
            println!("e={e} n={n}: below 1e-3 after {below} sweeps (error after {max_sweeps}: {:.2e})", errors.last().unwrap());
        }
    }
    write("feedback.csv", &csv);
}

/// How much the feedback weight changes the converged shape: the 90 degree arc converged with e = 0.2 and with
/// e = 0, and the largest distance between them.
fn feedback_bias() {
    let mut shapes = Vec::new();
    let mut csv = String::from("feedback,iterations,distortion,roughness_deg,gap_to_e0\n");
    for e in [0.0, 0.2] {
        let (mesh, handles) = tube_scene(81, 96);
        let length = tube_length(&mesh);
        let mut d = Deformer::control_only(mesh, handles);
        d.feedback = e;
        arc(&mut d.handles[1], length, 90.0);
        for _ in 0..3000 {
            d.iterate();
        }
        let (distortion, roughness) = d.shape_metrics();
        let gap = shapes
            .first()
            .map(|reference: &Vec<Vec3>| {
                reference.iter().zip(d.low_positions()).map(|(a, b)| (a - b).norm()).fold(0.0, f64::max) / length
            })
            .unwrap_or(0.0);
        println!("e={e}: distortion {distortion:.5e}, roughness {roughness:.4} deg, gap to e=0: {:.3}% of length", 100.0 * gap);
        writeln!(csv, "{e},3000,{distortion:.6e},{roughness:.5},{gap:.6}").unwrap();
        shapes.push(d.low_positions().to_vec());
    }
    write("feedback_bias.csv", &csv);
}

/// Iterative solvers of the rotation system against its Cholesky factorization: iterations and time to match the
/// closed-form rotations to 1e-3, 1e-8 and 1e-12 rad, cold start on the bent tube.
fn iterative() {
    use arap::iterative::{pcg, Preconditioner, SymmetricMatrix};
    let mut summary = String::from(
        "n,method,assembly_ms,closed_ms,setup_ms,iteration_ms,iters_1e-3,iters_1e-8,iters_1e-12,time_1e-8_ms,time_1e-12_ms\n",
    );
    let mut curves = String::from("n,method,iteration,error\n");
    for (rings, segments) in [(21, 24), (41, 48), (81, 96), (161, 192), (321, 384)] {
        let (mesh, handles) = tube_scene(rings, segments);
        let length = tube_length(&mesh);
        let n = mesh.num_vertices();
        let mut d = Deformer::control_only(mesh, handles);
        bend(&mut d.handles[1], length);
        d.global();
        let assembly_ms = mean_ms(3, || {
            let _ = d.rotation_system();
        });
        let system = d.rotation_system();
        // The reference: the closed-form local step (assembly, numeric Cholesky, solve). The first call also does
        // the symbolic analysis, which is reused afterwards, so it is excluded from the timing.
        let before = d.low_rotations().to_vec();
        d.local_step = LocalStep::ClosedForm;
        d.local();
        let target = d.low_rotations().to_vec();
        let closed_ms = mean_ms(3, || d.local());
        let _ = before;
        let matrix = SymmetricMatrix::from_lower(system.size, &system.lower);
        let error = |x: &[f64]| {
            d.rotations_from(&system, x).iter().zip(&target).map(|(a, b)| a.angle_to(b)).fold(0.0, f64::max)
        };
        for (method, make) in [
            ("cg", 0usize),
            ("block_jacobi", 1),
            ("constant_cholesky", 2),
        ] {
            let start = std::time::Instant::now();
            let preconditioner = match make {
                0 => Preconditioner::None,
                1 => Preconditioner::block_jacobi(&system),
                _ => Preconditioner::constant_cholesky(&system),
            };
            let setup_ms = start.elapsed().as_secs_f64() * 1e3;
            let max_iterations = 2000;
            let mut first_below = [None; 3];
            let mut x = system.previous.clone();
            pcg(&matrix, &system.rhs, &mut x, &preconditioner, max_iterations, 0.0, |k, x| {
                let e = error(x);
                writeln!(curves, "{n},{method},{k},{:.6e}", e.max(1e-17)).unwrap();
                for (slot, tol) in first_below.iter_mut().zip([1e-3, 1e-8, 1e-12]) {
                    if slot.is_none() && e < tol {
                        *slot = Some(k);
                    }
                }
                first_below[2].is_none()
            });
            // Time the iterations alone, without the error bookkeeping.
            let k = first_below[2].unwrap_or(max_iterations);
            let start = std::time::Instant::now();
            let mut x = system.previous.clone();
            pcg(&matrix, &system.rhs, &mut x, &preconditioner, k, 0.0, |_, _| true);
            let iteration_ms = start.elapsed().as_secs_f64() * 1e3 / k as f64;
            let fmt = |v: Option<usize>| v.map_or(String::from("nan"), |k| k.to_string());
            // The block inverses are rebuilt every local step; the constant factorization only once per session.
            let per_step_setup = if make == 1 { setup_ms } else { 0.0 };
            let time = |v: Option<usize>| {
                v.map_or(String::from("nan"), |k| format!("{:.3}", assembly_ms + per_step_setup + k as f64 * iteration_ms))
            };
            writeln!(
                summary,
                "{n},{method},{assembly_ms:.3},{closed_ms:.3},{setup_ms:.3},{iteration_ms:.4},{},{},{},{},{}",
                fmt(first_below[0]),
                fmt(first_below[1]),
                fmt(first_below[2]),
                time(first_below[1]),
                time(first_below[2])
            )
            .unwrap();
            println!(
                "n={n} {method}: setup {setup_ms:.2} ms, {iteration_ms:.3} ms/iteration, iterations to 1e-3/1e-8/1e-12: \
                 {}/{}/{}, time to 1e-12 {} ms (closed form {closed_ms:.2} ms, assembly {assembly_ms:.2} ms)",
                fmt(first_below[0]),
                fmt(first_below[1]),
                fmt(first_below[2]),
                time(first_below[2])
            );
        }
    }
    write("iterative_summary.csv", &summary);
    write("iterative_curves.csv", &curves);
}

/// SR-ARAP energy per local/global iteration, closed form against relaxation with a fixed sweep budget.
fn energy() {
    let methods = [
        ("closed", LocalStep::ClosedForm),
        ("relax1", LocalStep::Relaxation { sweeps: 1 }),
        ("relax3", LocalStep::Relaxation { sweeps: 3 }),
        ("relax10", LocalStep::Relaxation { sweeps: 10 }),
    ];
    let iterations = 300;

    let mut csv = String::from("scene,method,iteration,energy\n");
    for (label, step) in methods {
        let (mesh, handles) = tube_scene(81, 96);
        let length = tube_length(&mesh);
        let mut d = Deformer::control_only(mesh, handles);
        d.local_step = step;
        bend(&mut d.handles[1], length);
        for k in 1..=iterations {
            d.iterate();
            writeln!(csv, "tube,{label},{k},{:.8e}", d.energy()).unwrap();
        }
        println!("tube {label}: energy after {iterations} iterations {:.6e}", d.energy());
    }
    for (label, step) in methods {
        let high = Mesh::read_obj(&models().join("armadillo.obj")).unwrap();
        let low = Mesh::read_obj(&models().join("armadillo1.obj")).unwrap();
        let mut d = Deformer::new(high, low, armadillo_handles());
        d.local_step = step;
        raise_arms(&mut d);
        for k in 1..=iterations {
            d.iterate();
            writeln!(csv, "armadillo,{label},{k},{:.8e}", d.energy()).unwrap();
        }
        println!("armadillo {label}: energy after {iterations} iterations {:.6e}", d.energy());
    }
    write("energy.csv", &csv);
}

/// The closed form against the original SR-ARAP local step (SVD per cell, Gauss-Seidel sweeps), on the same global
/// step. Shapes are compared by method-independent measures: ARAP distortion and rotation roughness of the best
/// rigid fit of every cell.
fn comparison() {
    let methods = [
        ("closed", LocalStep::ClosedForm),
        ("pcg", LocalStep::Pcg),
        ("relax3", LocalStep::Relaxation { sweeps: 3 }),
        ("srarap1", LocalStep::SrArap { sweeps: 1 }),
        ("srarap3", LocalStep::SrArap { sweeps: 3 }),
        ("srarap10", LocalStep::SrArap { sweeps: 10 }),
    ];
    let mut csv = String::from("scene,method,iteration,elapsed_ms,distortion,roughness_deg\n");
    let mut timing = String::from("scene,method,local_ms,distortion,roughness_deg,gap_to_closed\n");
    for scene in ["tube_arc90", "armadillo"] {
        let mut finals: Vec<(String, Vec<Vec3>)> = Vec::new();
        for (label, step) in methods {
            let mut d = match scene {
                "tube_arc90" => {
                    let (mesh, handles) = tube_scene(81, 96);
                    let length = tube_length(&mesh);
                    let mut d = Deformer::control_only(mesh, handles);
                    arc(&mut d.handles[1], length, 90.0);
                    d
                }
                _ => {
                    let mut d = Deformer::new(load("armadillo.obj"), load("armadillo1.obj"), armadillo_handles());
                    armadillo_pose(&mut d, 2);
                    d
                }
            };
            d.local_step = step;
            let iterations = if scene == "armadillo" { 300 } else { 1000 };
            let mut elapsed = 0.0;
            for k in 1..=iterations {
                // Only the local/global iteration is timed, not the quality measurement.
                let start = Instant::now();
                d.iterate();
                elapsed += start.elapsed().as_secs_f64() * 1e3;
                if k <= 20 || k % 10 == 0 {
                    let (distortion, roughness) = d.shape_metrics();
                    writeln!(csv, "{scene},{label},{k},{elapsed:.3},{distortion:.8e},{roughness:.6}").unwrap();
                }
            }
            let local_ms = mean_ms(10, || d.local());
            d.global();
            let (distortion, roughness) = d.shape_metrics();
            let gap = finals
                .first()
                .map(|(_, reference)| {
                    reference.iter().zip(d.low_positions()).map(|(a, b)| (a - b).norm()).fold(0.0, f64::max)
                })
                .unwrap_or(0.0);
            // Distances are relative to the bounding-box half-diagonal, which normalisation sets to 1.
            writeln!(timing, "{scene},{label},{local_ms:.4},{distortion:.6e},{roughness:.4},{gap:.5}").unwrap();
            println!(
                "{scene} {label}: local {local_ms:.3} ms, distortion {distortion:.4e}, roughness {roughness:.3} deg, \
                 max distance to the closed-form shape {gap:.4}"
            );
            finals.push((label.to_string(), d.low_positions().to_vec()));
        }
    }
    write("comparison.csv", &csv);
    write("comparison_summary.csv", &timing);
}

/// Per-stage cost of one interactive frame on the multiresolution scenes.
fn timing() {
    let mut csv = String::from(
        "scene,control_vertices,detail_vertices,local_closed_ms,local_pcg_ms,pcg_iterations,local_relax3_ms,global_ms,transfer_ms,detail_ms,frame_ms\n",
    );
    let scenes: [(&str, &str, &str, Vec<Handle>); 2] = [
        ("cactus", "cactus2.obj", "cactus1.obj", vec![
            Handle::new(Vec3::new(0.0, 0.04, 0.7), 0.15),
            Handle::new(Vec3::new(0.0, 0.04, -0.8), 0.15),
        ]),
        ("armadillo", "armadillo.obj", "armadillo1.obj", armadillo_handles()),
    ];
    for (name, high, low, handles) in scenes {
        let high = Mesh::read_obj(&models().join(high)).unwrap();
        let low = Mesh::read_obj(&models().join(low)).unwrap();
        let (nl, nh) = (low.num_vertices(), high.num_vertices());
        let mut d = Deformer::new(high, low, handles);
        d.handles[0].translation += Vec3::new(-0.1, 0.15, 0.0);
        for _ in 0..3 {
            d.iterate();
        }
        d.local_step = LocalStep::ClosedForm;
        let local_closed = mean_ms(30, || d.local());
        d.local_step = LocalStep::Pcg;
        let mut pcg_iterations = 0;
        let local_pcg = mean_ms(30, || {
            d.local();
            pcg_iterations += d.last_pcg_iterations;
        });
        d.local_step = LocalStep::Relaxation { sweeps: 3 };
        let local_relax = mean_ms(30, || d.local());
        d.local_step = LocalStep::Pcg;
        let global = mean_ms(30, || d.global());
        let transfer = mean_ms(10, || d.transfer_rotations());
        let detail = mean_ms(10, || d.solve_high_positions());
        let frame = mean_ms(10, || d.step());
        writeln!(
            csv,
            "{name},{nl},{nh},{local_closed:.3},{local_pcg:.3},{:.1},{local_relax:.3},{global:.3},{transfer:.3},{detail:.3},{frame:.3}",
            pcg_iterations as f64 / 30.0
        )
        .unwrap();
        println!(
            "{name}: local closed {local_closed:.2} ms, PCG {local_pcg:.2} ms ({:.1} iterations), relax3 {local_relax:.2} ms, \
             global {global:.3} ms, transfer {transfer:.2} ms, detail {detail:.2} ms, frame {frame:.2} ms",
            pcg_iterations as f64 / 30.0
        );
    }
    write("timing.csv", &csv);
}

fn main() {
    let which = std::env::args().nth(1).unwrap_or_else(|| "all".to_string());
    if which == "all" || which == "convergence" {
        convergence();
    }
    if which == "all" || which == "feedback" {
        feedback();
    }
    if which == "all" || which == "iterative" {
        iterative();
    }
    if which == "all" || which == "bias" {
        feedback_bias();
    }
    if which == "all" || which == "energy" {
        energy();
    }
    if which == "all" || which == "comparison" {
        comparison();
    }
    if which == "all" || which == "timing" {
        timing();
    }
}
