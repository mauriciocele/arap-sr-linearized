//! Smooth-rotation enhanced ARAP with linearized rotations, solved on a coarse control mesh and transferred to the
//! detailed mesh. Port of the solver half of `Flatten.cpp`.
//!
//! ```text
//! E_i = sum_j w_ij |R_i q_ij ~R_i - p_ij|^2 + A sum_j c_ij |R_i - R_j|^2 + e_i |R_i - R_{i-1}|^2
//! ```
//!
//! Each iteration solves one sparse linear system for all control-mesh rotations at once (quaternion components,
//! `4n` unknowns), then one Poisson system for the positions. The detailed mesh gets its rotations by Laplacian
//! interpolation of the control rotations, and its positions from a Poisson solve with the control vertices as
//! constraints.

use std::time::Instant;

use faer::Mat;
use faer::prelude::Solve;
use faer::Side;
use faer::sparse::linalg::solvers::{Llt, Lu, SymbolicLlt, SymbolicLu};
use faer::sparse::{SparseColMat, Triplet};
use nalgebra::{Matrix3, Matrix4, Quaternion, Rotation3, UnitQuaternion, Vector4};

use crate::handle::Handle;
use crate::iterative::{Preconditioner, SymmetricMatrix, pcg};
use crate::laplacian::{Laplacian, PoissonSolver, Weights};
use crate::mesh::{Mesh, Vec3};

/// Smoothness weight of the rotation field, relative to the control-mesh area.
const ALPHA: f64 = 0.14;
/// Default weight `e` of the previous iteration's rotation (feedback term); see [`Deformer::feedback`].
pub const FEEDBACK: f64 = 0.2;
/// Smoothness weight used by [`Deformer::energy`]; the C++ code uses a different constant there.
const ENERGY_ALPHA: f64 = 0.28;
/// The C++ code gathers at most this many neighbours per vertex for the rotation fit.
const MAX_DEGREE: usize = 32;
/// Rotation + Poisson iterations per interactive frame.
pub const ITERATIONS_PER_FRAME: usize = 3;

type Quat = UnitQuaternion<f64>;

/// The reduced rotation system `K_FF x = b` of one local step. `x` stacks the quaternion coefficients
/// `(w, x, y, z)` of the free cells.
pub struct RotationSystem {
    pub size: usize,
    /// Lower triangle of `K_FF`, as (row, column, value).
    pub lower: Vec<(usize, usize, f64)>,
    pub rhs: Vec<f64>,
    /// The previous rotations of the free cells: the warm start of an iterative solver.
    pub previous: Vec<f64>,
    /// The 4x4 diagonal block of each free cell.
    pub blocks: Vec<Matrix4<f64>>,
    /// The position-independent part `s_i (alpha A + eps)` of each diagonal block (times the identity).
    pub constant_diagonal: Vec<f64>,
    /// Fitted rotations of the constrained cells (zero for free cells).
    pub fixed: Vec<Vector4<f64>>,
}

/// How the local (rotation) step is solved.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum LocalStep {
    /// One sparse Cholesky solve of the coupled rotation system (the paper's method).
    ClosedForm,
    /// The same system solved by preconditioned conjugate gradients, warm-started from the previous rotations.
    /// The preconditioner is a Cholesky factorization of the system's position-independent part, computed once
    /// per constraint set, so a local step costs a few back-substitutions instead of a numeric factorization.
    /// Stops at a relative residual of [`PCG_TOLERANCE`], which matches the closed form to about 1e-12 rad.
    Pcg,
    /// The baseline: block Gauss-Seidel sweeps over the per-cell equations, each cell solved with its neighbours'
    /// current rotations fixed. Converges to the closed-form solution (same linear system).
    Relaxation { sweeps: usize },
    /// The original SR-ARAP local step of Levi and Gotsman: rotation matrices, each cell fitted exactly by an SVD
    /// (orthogonal Procrustes) against its edges and its neighbours' current rotations, in Gauss-Seidel sweeps.
    /// Each cell update minimises the total SR-ARAP energy over that cell. No linearisation, no feedback.
    SrArap { sweeps: usize },
}

/// Bending weight of the SR-ARAP baseline. Its bending term `||R_i - R_j||_F^2` is about `2 theta^2` for two
/// rotations `theta` apart, while the quaternion term `||q_i - q_j||^2` is about `theta^2 / 4`; dividing the
/// paper's `alpha` by 8 gives both methods the same stiffness for small rotation differences.
pub const SR_ARAP_ALPHA: f64 = ENERGY_ALPHA / 8.0;

/// Relative residual at which the PCG local step stops.
pub const PCG_TOLERANCE: f64 = 1e-12;
/// Safety cap on PCG iterations; the factor-once preconditioner needs 5 to 20.
const PCG_MAX_ITERATIONS: usize = 500;

pub struct Deformer {
    pub low: Mesh,
    pub high: Mesh,
    low_laplacian: Laplacian,
    high_laplacian: Laplacian,
    /// Detailed-mesh vertex nearest to each control-mesh vertex.
    high_of_low: Vec<usize>,
    pub handles: Vec<Handle>,
    low_constrained: Vec<bool>,
    low_solver: PoissonSolver,
    /// None in control-only mode, where the control mesh is also the output mesh.
    high_solver: Option<PoissonSolver>,
    pub local_step: LocalStep,
    /// Feedback weight `e`. With `e > 0` the rotation system's smallest eigenvalue is at least `e`.
    pub feedback: f64,
    /// The rotation system keeps its sparsity pattern until the constraints change.
    rotation_symbolic: Option<SymbolicLu<usize>>,
    rotation_llt_symbolic: Option<SymbolicLlt<usize>>,
    /// Factor-once preconditioner of the PCG local step, with the feedback weight it was built for.
    pcg_preconditioner: Option<(f64, Preconditioner)>,
    /// PCG iterations of the last local step.
    pub last_pcg_iterations: usize,
    /// Index of each free control vertex in the reduced rotation system.
    rotation_free_index: Vec<Option<usize>>,
    rotation_free_count: usize,
    mesh_area: f64,

    low_positions: Vec<Vec3>,
    low_rotations: Vec<Quat>,
    low_differentials: Vec<Vec3>,
    pub high_positions: Vec<Vec3>,
    pub high_normals: Vec<Vec3>,
    high_rotations: Vec<Quat>,
    high_differentials: Vec<Vec3>,
    started: bool,
}

impl Deformer {
    pub fn new(high: Mesh, low: Mesh, handles: Vec<Handle>) -> Self {
        // With faer's default thread pool the sparse Cholesky solves of the detailed mesh take ~25x longer (558 ms
        // against 22 ms for 173k vertices); `PoissonSolver` parallelises over right-hand sides instead.
        faer::set_global_parallelism(faer::Par::Seq);
        let start = Instant::now();
        let high_of_low = nearest_vertices(&low, &high);

        let low_laplacian = Laplacian::new(&low, Weights::Cotangent);
        let high_laplacian = Laplacian::new(&high, Weights::Cotangent);
        let low_differentials = low_laplacian.apply(&low, &low.positions);
        let high_differentials = high_laplacian.apply(&high, &high.positions);

        let mut high_constrained = vec![false; high.num_vertices()];
        for &h in &high_of_low {
            high_constrained[h] = true;
        }
        let high_solver = Some(PoissonSolver::new(&high, &high_laplacian, &high_constrained, true));

        let mut handles = handles;
        let (low_constrained, low_solver) = constrain(&low, &low_laplacian, &mut handles);
        let n_low = low.num_vertices();
        let n_high = high.num_vertices();
        let mut deformer = Deformer {
            mesh_area: low.area(),
            low_positions: low.positions.clone(),
            low_rotations: vec![Quat::identity(); n_low],
            low_differentials,
            high_positions: high.positions.clone(),
            high_normals: high.normals.clone(),
            high_rotations: vec![Quat::identity(); n_high],
            high_differentials,
            low_constrained,
            low_solver,
            high_solver,
            local_step: LocalStep::Pcg,
            feedback: FEEDBACK,
            rotation_symbolic: None,
            rotation_llt_symbolic: None,
            pcg_preconditioner: None,
            last_pcg_iterations: 0,
            rotation_free_index: Vec::new(),
            rotation_free_count: 0,
            low_laplacian,
            high_laplacian,
            high_of_low,
            handles,
            low,
            high,
            started: false,
        };
        deformer.index_free_rotations();
        println!("set-up took {:.2?}", start.elapsed());
        deformer
    }

    /// Deforms `mesh` directly, with no multiresolution transfer: the control mesh is the output mesh. Used to
    /// measure the local step on large meshes.
    pub fn control_only(mesh: Mesh, handles: Vec<Handle>) -> Self {
        faer::set_global_parallelism(faer::Par::Seq);
        let laplacian = Laplacian::new(&mesh, Weights::Cotangent);
        let differentials = laplacian.apply(&mesh, &mesh.positions);
        let mut handles = handles;
        let (low_constrained, low_solver) = constrain(&mesh, &laplacian, &mut handles);
        let n = mesh.num_vertices();
        let mut deformer = Deformer {
            mesh_area: mesh.area(),
            low_positions: mesh.positions.clone(),
            low_rotations: vec![Quat::identity(); n],
            low_differentials: differentials.clone(),
            high_positions: mesh.positions.clone(),
            high_normals: mesh.normals.clone(),
            high_rotations: vec![Quat::identity(); n],
            high_differentials: differentials,
            low_constrained,
            low_solver,
            high_solver: None,
            local_step: LocalStep::Pcg,
            feedback: FEEDBACK,
            rotation_symbolic: None,
            rotation_llt_symbolic: None,
            pcg_preconditioner: None,
            last_pcg_iterations: 0,
            rotation_free_index: Vec::new(),
            rotation_free_count: 0,
            high_laplacian: laplacian.clone(),
            low_laplacian: laplacian,
            high_of_low: (0..n).collect(),
            handles,
            high: mesh.clone(),
            low: mesh,
            started: false,
        };
        deformer.index_free_rotations();
        deformer
    }

    pub fn low_positions(&self) -> &[Vec3] {
        &self.low_positions
    }

    pub fn low_rotations(&self) -> &[Quat] {
        &self.low_rotations
    }

    pub fn high_rotations(&self) -> &[Quat] {
        &self.high_rotations
    }

    pub fn is_constrained(&self, i: usize) -> bool {
        self.low_constrained[i]
    }

    /// Nearest detailed vertex of each control vertex.
    pub fn high_of_low(&self) -> &[usize] {
        &self.high_of_low
    }

    /// Re-selects the control vertices inside each handle's rest sphere and refactors the control-mesh system.
    /// Needed after a handle's radius changes.
    pub fn assign_constraints(&mut self) {
        (self.low_constrained, self.low_solver) = constrain(&self.low, &self.low_laplacian, &mut self.handles);
        self.rotation_symbolic = None;
        self.index_free_rotations();
    }

    fn index_free_rotations(&mut self) {
        let mut count = 0;
        self.rotation_free_index = self
            .low_constrained
            .iter()
            .map(|&constrained| {
                (!constrained).then(|| {
                    count += 1;
                    count - 1
                })
            })
            .collect();
        self.rotation_free_count = count;
        self.rotation_llt_symbolic = None;
        self.pcg_preconditioner = None;
    }

    /// Advances the deformation by one interactive frame (`display()` in the C++ code).
    pub fn step(&mut self) {
        if !self.started {
            self.solve_low_positions();
            self.started = true;
        }
        for _ in 0..ITERATIONS_PER_FRAME {
            self.solve_low_rotations();
            self.solve_low_positions();
        }
        self.update_high();
    }

    /// The `X` key: 100 iterations, or until the energy settles when `until_converged` is set.
    pub fn iterate_many(&mut self, until_converged: bool) {
        if !until_converged {
            for _ in 0..100 {
                self.solve_low_rotations();
                self.solve_low_positions();
            }
        } else {
            let mut energy = self.energy();
            let mut total = 0.0;
            let mut count = 0;
            while count < 2500 {
                let start = Instant::now();
                self.solve_low_rotations();
                self.solve_low_positions();
                total += start.elapsed().as_secs_f64();
                let new_energy = self.energy();
                if (energy - new_energy).abs() < 1e-4 {
                    println!("convergence after {} iterations", count + 1);
                    break;
                }
                energy = new_energy;
                count += 1;
            }
            println!("{}", self.energy());
            println!("Average iteration time (sec): {}", total / (count + 1) as f64);
            println!("Total accum time (sec): {total}");
        }
        self.update_high();
    }

    /// Transfers the control-mesh state to the detailed mesh.
    pub fn update_high(&mut self) {
        if self.high_solver.is_none() {
            self.high_positions = self.low_positions.clone();
            self.high_rotations = self.low_rotations.clone();
            for (i, normal) in self.high_normals.iter_mut().enumerate() {
                *normal = self.high_rotations[i] * self.high.normals[i];
            }
            return;
        }
        self.transfer_rotations();
        self.solve_high_positions();
    }

    /// One local/global iteration on the control mesh, with the configured local step.
    pub fn iterate(&mut self) {
        if !self.started {
            self.solve_low_positions();
            self.started = true;
        }
        self.local();
        self.solve_low_positions();
    }

    /// The local step alone, with the configured method.
    pub fn local(&mut self) {
        match self.local_step {
            LocalStep::ClosedForm => self.solve_low_rotations(),
            LocalStep::Pcg => self.solve_low_rotations_pcg(),
            LocalStep::Relaxation { sweeps } => self.solve_low_rotations_relaxation(sweeps),
            LocalStep::SrArap { sweeps } => self.solve_low_rotations_sr_arap(sweeps),
        }
    }

    /// The global step alone.
    pub fn global(&mut self) {
        self.solve_low_positions();
        self.started = true;
    }

    /// Runs the relaxation local step from the current state, one sweep at a time, and returns after each sweep
    /// the largest angle (radians) between a relaxed and the closed-form rotation. The state is left unchanged.
    pub fn relaxation_errors(&mut self, max_sweeps: usize) -> Vec<f64> {
        let saved = (self.low_rotations.clone(), self.low_differentials.clone());
        self.solve_low_rotations();
        let target = self.low_rotations.clone();
        (self.low_rotations, self.low_differentials) = saved;
        let mut errors = Vec::with_capacity(max_sweeps);
        self.relax(max_sweeps, |current| {
            let worst = current
                .iter()
                .zip(&target)
                .map(|(c, t)| Quat::new_normalize(Quaternion::new(c[0], c[1], c[2], c[3])).angle_to(t))
                .fold(0.0, f64::max);
            errors.push(worst);
        });
        errors
    }

    /// The reduced, symmetric rotation system of the closed-form local step (Section 5.6 of the paper), assembled
    /// from the current positions and rotations: the free cells' unknowns, its lower triangle, right-hand side,
    /// the constrained cells' fitted rotations, and the pieces an iterative solver needs.
    pub fn rotation_system(&self) -> RotationSystem {
        let n = self.low.num_vertices();
        let alpha_area = ALPHA * self.mesh_area;
        let free_index = &self.rotation_free_index;
        let m = 4 * self.rotation_free_count;

        // Constrained vertices: closed-form fit from the previous rotations, as the identity rows of the C++ code.
        let mut fixed = vec![Vector4::zeros(); n];
        let mut p = Vec::with_capacity(MAX_DEGREE);
        let mut q = Vec::with_capacity(MAX_DEGREE);
        let mut w = Vec::with_capacity(MAX_DEGREE);
        let gather = |i: usize, p: &mut Vec<Vec3>, q: &mut Vec<Vec3>, w: &mut Vec<f64>| {
            p.clear();
            q.clear();
            w.clear();
            for (&j, &wij) in self.low.neighbors[i].iter().zip(&self.low_laplacian.weights[i]) {
                p.push(self.low.positions[j] - self.low.positions[i]);
                q.push(self.low_positions[j] - self.low_positions[i]);
                w.push(wij);
            }
        };
        for i in (0..n).filter(|&i| self.low_constrained[i]) {
            gather(i, &mut p, &mut q, &mut w);
            let neighbors: Vec<Quat> = self.low.neighbors[i].iter().map(|&j| self.low_rotations[j]).collect();
            fixed[i] = coefficients(&fit_constrained(&p, &q, &w, alpha_area, &neighbors));
        }

        let mut triplets = Vec::with_capacity(m * 12);
        let mut rhs = vec![0.0; m];
        let mut previous = vec![0.0; m];
        let mut blocks = Vec::with_capacity(self.rotation_free_count);
        let mut constant_diagonal = Vec::with_capacity(self.rotation_free_count);
        for i in 0..n {
            let Some(r) = free_index[i] else { continue };
            let rr = 4 * r;
            gather(i, &mut p, &mut q, &mut w);
            let scale = (self.low.neighbors[i].len() as f64 + self.feedback) / alpha_area;
            let mut block = fit_matrix(&p, &q, &w);
            for c in 0..4 {
                block[(c, c)] += alpha_area + 1e-6;
            }
            for a in 0..4 {
                for b in 0..=a {
                    triplets.push((rr + a, rr + b, scale * block[(a, b)]));
                }
            }
            blocks.push(block * scale);
            // The part of the diagonal block that does not depend on the positions.
            constant_diagonal.push(scale * (alpha_area + 1e-6));
            let mut b = coefficients(&self.low_rotations[i]) * self.feedback;
            for &j in &self.low.neighbors[i] {
                match free_index[j] {
                    Some(c) if c < r => {
                        for k in 0..4 {
                            triplets.push((rr + k, 4 * c + k, -1.0));
                        }
                    }
                    Some(_) => {}
                    None => b += fixed[j],
                }
            }
            let current = coefficients(&self.low_rotations[i]);
            for k in 0..4 {
                rhs[rr + k] = b[k];
                previous[rr + k] = current[k];
            }
        }

        RotationSystem { size: m, lower: triplets, rhs, previous, blocks, constant_diagonal, fixed }
    }

    /// Normalised rotations of every control cell for a solution `x` of `system` (free cells from `x`, constrained
    /// cells from their fit).
    pub fn rotations_from(&self, system: &RotationSystem, x: &[f64]) -> Vec<Quat> {
        self.rotation_free_index
            .iter()
            .zip(&system.fixed)
            .map(|(index, fixed)| {
                let c = match *index {
                    Some(r) => Vector4::new(x[4 * r], x[4 * r + 1], x[4 * r + 2], x[4 * r + 3]),
                    None => *fixed,
                };
                Quat::new_normalize(Quaternion::new(c[0], c[1], c[2], c[3]))
            })
            .collect()
    }

    fn solve_low_rotations_pcg(&mut self) {
        if self.low.neighbors.iter().any(|ring| ring.len() > MAX_DEGREE) {
            return self.solve_low_rotations_lu();
        }
        let system = self.rotation_system();
        if system.size == 0 {
            return self.apply_rotation_solution(&system, &[]);
        }
        if self.pcg_preconditioner.as_ref().is_none_or(|(e, _)| *e != self.feedback) {
            self.pcg_preconditioner = Some((self.feedback, Preconditioner::constant_cholesky(&system)));
        }
        let preconditioner = &self.pcg_preconditioner.as_ref().unwrap().1;
        let matrix = SymmetricMatrix::from_lower(system.size, &system.lower);
        let mut x = system.previous.clone();
        self.last_pcg_iterations =
            pcg(&matrix, &system.rhs, &mut x, preconditioner, PCG_MAX_ITERATIONS, PCG_TOLERANCE, |_, _| true);
        self.apply_rotation_solution(&system, &x);
    }

    /// Takes the solution `x` of `system` as the new rotations.
    pub fn apply_rotation_solution(&mut self, system: &RotationSystem, x: &[f64]) {
        self.low_rotations = self.rotations_from(system, x);
        self.low_differentials = rotated_differentials(&self.low, &self.low_laplacian, &self.low_rotations);
    }

    /// Cross-covariance `sum_j c_ij p_ij q_ij^T` of each cell (deformed against rest edges).
    fn covariances(&self) -> Vec<Matrix3<f64>> {
        (0..self.low.num_vertices())
            .map(|i| {
                let mut m = Matrix3::zeros();
                for (&j, &c) in self.low.neighbors[i].iter().zip(&self.low_laplacian.weights[i]) {
                    let q = self.low.positions[j] - self.low.positions[i];
                    let p = self.low_positions[j] - self.low_positions[i];
                    m += (p * c) * q.transpose();
                }
                m
            })
            .collect()
    }

    fn solve_low_rotations_sr_arap(&mut self, sweeps: usize) {
        let n = self.low.num_vertices();
        let alpha_area = SR_ARAP_ALPHA * self.mesh_area;
        let covariances = self.covariances();
        let mut rotations: Vec<Matrix3<f64>> =
            self.low_rotations.iter().map(|q| *q.to_rotation_matrix().matrix()).collect();
        let degree: Vec<f64> = self.low.neighbors.iter().map(|r| r.len() as f64).collect();
        for _ in 0..sweeps {
            for i in 0..n {
                // Bending E = alpha A sum_i sum_j (1/d_i) ||R_i - R_j||^2: R_i appears in its own term and in each
                // neighbour's, hence the symmetrised weight 1/d_i + 1/d_j.
                let mut m = covariances[i];
                for &j in &self.low.neighbors[i] {
                    m += rotations[j] * (alpha_area * (1.0 / degree[i] + 1.0 / degree[j]));
                }
                rotations[i] = nearest_rotation(&m);
            }
        }
        self.low_rotations = rotations
            .iter()
            .map(|r| UnitQuaternion::from_rotation_matrix(&Rotation3::from_matrix_unchecked(*r)))
            .collect();
        self.low_differentials = rotated_differentials(&self.low, &self.low_laplacian, &self.low_rotations);
    }

    /// Shape quality of the deformed control mesh, independent of how its rotations were found: each cell's best
    /// rigid fit is computed from the positions alone (orthogonal Procrustes). Returns the ARAP distortion
    /// `sum c_ij ||R_i q_ij - p_ij||^2 / sum c_ij ||q_ij||^2` and the RMS angle (degrees) between the fitted
    /// rotations of adjacent cells.
    pub fn shape_metrics(&self) -> (f64, f64) {
        let fits: Vec<Matrix3<f64>> = self.covariances().iter().map(nearest_rotation).collect();
        let (mut distortion, mut scale) = (0.0, 0.0);
        let (mut angles, mut edges) = (0.0, 0usize);
        for i in 0..self.low.num_vertices() {
            for (&j, &c) in self.low.neighbors[i].iter().zip(&self.low_laplacian.weights[i]) {
                let q = self.low.positions[j] - self.low.positions[i];
                let p = self.low_positions[j] - self.low_positions[i];
                distortion += c * (fits[i] * q - p).norm_squared();
                scale += c * q.norm_squared();
                if i < j {
                    let relative = fits[i].transpose() * fits[j];
                    let cos = ((relative.trace() - 1.0) / 2.0).clamp(-1.0, 1.0);
                    angles += cos.acos().to_degrees().powi(2);
                    edges += 1;
                }
            }
        }
        (distortion / scale, (angles / edges as f64).sqrt())
    }

    fn solve_low_rotations_relaxation(&mut self, sweeps: usize) {
        let relaxed = self.relax(sweeps, |_| {});
        self.low_rotations =
            relaxed.iter().map(|c| Quat::new_normalize(Quaternion::new(c[0], c[1], c[2], c[3]))).collect();
        self.low_differentials = rotated_differentials(&self.low, &self.low_laplacian, &self.low_rotations);
    }

    /// Block Gauss-Seidel on the per-cell equations
    /// `(H_i + (A + eps) I) R_i = A / (d_i + e) (sum_j R_j + e R_i^prev)`, starting from the previous rotations.
    /// Constrained cells get the same closed-form fit as in the closed-form local step. `observe` sees the
    /// unnormalised iterate after every sweep.
    fn relax(&self, sweeps: usize, mut observe: impl FnMut(&[Vector4<f64>])) -> Vec<Vector4<f64>> {
        let n = self.low.num_vertices();
        let alpha_area = ALPHA * self.mesh_area;
        let previous: Vec<Vector4<f64>> = self.low_rotations.iter().map(coefficients).collect();
        let mut current = previous.clone();
        // Each cell's 4x4 system depends only on the positions, so it is inverted once per local step.
        let mut inverses = vec![Matrix4::zeros(); n];
        let (mut p, mut q, mut w) = (Vec::new(), Vec::new(), Vec::new());
        for i in 0..n {
            p.clear();
            q.clear();
            w.clear();
            for (&j, &wij) in self.low.neighbors[i].iter().zip(&self.low_laplacian.weights[i]) {
                p.push(self.low.positions[j] - self.low.positions[i]);
                q.push(self.low_positions[j] - self.low_positions[i]);
                w.push(wij);
            }
            if self.low_constrained[i] {
                let neighbors: Vec<Quat> = self.low.neighbors[i].iter().map(|&j| self.low_rotations[j]).collect();
                current[i] = coefficients(&fit_constrained(&p, &q, &w, alpha_area, &neighbors));
            } else {
                let mut m = fit_matrix(&p, &q, &w);
                for c in 0..4 {
                    m[(c, c)] += alpha_area + 1e-6;
                }
                inverses[i] = m.try_inverse().expect("cell matrix is positive definite");
            }
        }
        for _ in 0..sweeps {
            for i in (0..n).filter(|&i| !self.low_constrained[i]) {
                let ring = &self.low.neighbors[i];
                let mut b = previous[i] * self.feedback;
                for &j in ring {
                    b += current[j];
                }
                current[i] = inverses[i] * (b * (alpha_area / (ring.len() as f64 + self.feedback)));
            }
            observe(&current);
        }
        current
    }

    fn solve_low_positions(&mut self) {
        let mut rhs = vectors_to_mat(&self.low_differentials);
        for handle in &self.handles {
            for &i in &handle.constraints {
                let p = handle.transform(&self.low.positions[i]);
                set_row(&mut rhs, i, &p);
            }
        }
        self.low_solver.solve_in_place(&mut rhs);
        self.low_positions = mat_to_vectors(&rhs);
    }

    /// One linear solve for every control-mesh rotation.
    ///
    /// The C++ system has, per free vertex `i` with degree `d`, the rows
    /// `(H_i + (A + eps) I) R_i - A / (d + e) sum_j R_j = A e / (d + e) R_i^prev`, and identity rows at constrained
    /// vertices. Scaling each free row by `(d + e) / A` makes the off-diagonal blocks `-I`, so the matrix is
    /// symmetric; moving the constrained rotations to the right-hand side leaves a strictly diagonally dominant,
    /// hence positive definite, free block. That block is solved with a sparse Cholesky whose analysis is reused
    /// until the constraints change. The solution is the same as the C++ LU solve, which faer's sparse LU takes
    /// ~8 ms to factor here against well under 1 ms for this.
    fn solve_low_rotations(&mut self) {
        if self.low.neighbors.iter().any(|ring| ring.len() > MAX_DEGREE) {
            // The C++ code truncates rings at MAX_DEGREE, which breaks the symmetry; keep its exact system.
            return self.solve_low_rotations_lu();
        }
        let system = self.rotation_system();
        let m = system.size;
        let rhs = Mat::from_fn(m, 1, |i, _| system.rhs[i]);
        let triplets: Vec<Triplet<usize, usize, f64>> =
            system.lower.iter().map(|&(r, c, v)| Triplet::new(r, c, v)).collect();
        let solution = if m == 0 {
            rhs
        } else {
            let matrix = SparseColMat::<usize, f64>::try_new_from_triplets(m, m, &triplets)
                .expect("valid rotation-system triplets");
            let symbolic = match &self.rotation_llt_symbolic {
                Some(symbolic) => symbolic.clone(),
                None => {
                    let symbolic =
                        SymbolicLlt::try_new(matrix.symbolic(), Side::Lower).expect("rotation-system analysis failed");
                    self.rotation_llt_symbolic = Some(symbolic.clone());
                    symbolic
                }
            };
            let llt = Llt::try_new_with_symbolic(symbolic, matrix.as_ref(), Side::Lower)
                .expect("rotation system is not positive definite");
            llt.solve(&rhs)
        };
        let x: Vec<f64> = (0..m).map(|i| solution[(i, 0)]).collect();
        self.apply_rotation_solution(&system, &x);
    }

    /// The rotation system exactly as the C++ code builds and solves it (sparse LU of the full `4n` system).
    fn solve_low_rotations_lu(&mut self) {
        let n = self.low.num_vertices();
        let alpha_area = ALPHA * self.mesh_area;
        let mut triplets = Vec::with_capacity(n * (16 + 4 * 8));
        let mut rhs = Mat::<f64>::zeros(4 * n, 1);
        let mut p = Vec::with_capacity(MAX_DEGREE);
        let mut q = Vec::with_capacity(MAX_DEGREE);
        let mut w = Vec::with_capacity(MAX_DEGREE);

        for i in 0..n {
            let ii = 4 * i;
            let ring = &self.low.neighbors[i];
            let degree = ring.len().min(MAX_DEGREE);
            p.clear();
            q.clear();
            w.clear();
            for (&j, &wij) in ring[..degree].iter().zip(&self.low_laplacian.weights[i]) {
                p.push(self.low.positions[j] - self.low.positions[i]);
                q.push(self.low_positions[j] - self.low_positions[i]);
                w.push(wij);
            }

            if !self.low_constrained[i] {
                let off_diagonal = alpha_area / (degree as f64 + self.feedback);
                for &j in &ring[..degree] {
                    for c in 0..4 {
                        triplets.push(Triplet::new(ii + c, 4 * j + c, -off_diagonal));
                    }
                }
                let mut jtj = fit_matrix(&p, &q, &w);
                for c in 0..4 {
                    jtj[(c, c)] += alpha_area + 1e-6;
                }
                for r in 0..4 {
                    for c in 0..4 {
                        triplets.push(Triplet::new(ii + r, ii + c, jtj[(r, c)]));
                    }
                }
                let previous = coefficients(&self.low_rotations[i]) * (off_diagonal * self.feedback);
                for c in 0..4 {
                    rhs[(ii + c, 0)] = previous[c];
                }
            } else {
                let neighbors: Vec<Quat> = ring[..degree].iter().map(|&j| self.low_rotations[j]).collect();
                let fitted = coefficients(&fit_constrained(&p, &q, &w, alpha_area, &neighbors));
                for c in 0..4 {
                    rhs[(ii + c, 0)] = fitted[c];
                    triplets.push(Triplet::new(ii + c, ii + c, 1.0));
                }
            }
        }

        let matrix = SparseColMat::<usize, f64>::try_new_from_triplets(4 * n, 4 * n, &triplets)
            .expect("valid rotation-system triplets");
        let symbolic = match &self.rotation_symbolic {
            Some(symbolic) => symbolic.clone(),
            None => {
                let symbolic = SymbolicLu::try_new(matrix.symbolic()).expect("rotation-system analysis failed");
                self.rotation_symbolic = Some(symbolic.clone());
                symbolic
            }
        };
        let lu = Lu::try_new_with_symbolic(symbolic, matrix.as_ref()).expect("rotation system is singular");
        let solution = lu.solve(&rhs);
        for i in 0..n {
            let ii = 4 * i;
            self.low_rotations[i] = Quat::new_normalize(Quaternion::new(
                solution[(ii, 0)],
                solution[(ii + 1, 0)],
                solution[(ii + 2, 0)],
                solution[(ii + 3, 0)],
            ));
        }
        self.low_differentials = rotated_differentials(&self.low, &self.low_laplacian, &self.low_rotations);
    }

    /// Laplacian interpolation of the control rotations onto the detailed mesh (`transferRotations`).
    pub fn transfer_rotations(&mut self) {
        let mut rhs = Mat::<f64>::zeros(self.high.num_vertices(), 4);
        for (l, &h) in self.high_of_low.iter().enumerate() {
            let c = coefficients(&self.low_rotations[l]);
            for k in 0..4 {
                rhs[(h, k)] = c[k];
            }
        }
        self.high_solver.as_ref().expect("multiresolution mode").solve_in_place(&mut rhs);
        let solution = rhs;
        for (i, rotation) in self.high_rotations.iter_mut().enumerate() {
            *rotation = Quat::new_normalize(Quaternion::new(
                solution[(i, 0)],
                solution[(i, 1)],
                solution[(i, 2)],
                solution[(i, 3)],
            ));
        }
        self.high_differentials = rotated_differentials(&self.high, &self.high_laplacian, &self.high_rotations);
    }

    pub fn solve_high_positions(&mut self) {
        let mut rhs = vectors_to_mat(&self.high_differentials);
        for (l, &h) in self.high_of_low.iter().enumerate() {
            set_row(&mut rhs, h, &self.low_positions[l]);
        }
        self.high_solver.as_ref().expect("multiresolution mode").solve_in_place(&mut rhs);
        self.high_positions = mat_to_vectors(&rhs);
        for (i, normal) in self.high_normals.iter_mut().enumerate() {
            *normal = self.high_rotations[i] * self.high.normals[i];
        }
    }

    /// Control-mesh ARAP energy plus rotation smoothness (`ComputeEnergy`), used for the convergence test.
    pub fn energy(&self) -> f64 {
        let mut energy = 0.0;
        for i in 0..self.low.num_vertices() {
            let ring = &self.low.neighbors[i];
            let smooth = ENERGY_ALPHA * self.mesh_area / ring.len() as f64;
            let ri = &self.low_rotations[i];
            for (k, &j) in ring.iter().enumerate() {
                let p_ij = self.low.positions[j] - self.low.positions[i];
                let q_ij = self.low_positions[j] - self.low_positions[i];
                energy += self.low_laplacian.weights[i][k] * (ri * p_ij - q_ij).norm_squared();
                energy += smooth * (coefficients(&self.low_rotations[j]) - coefficients(ri)).norm_squared();
            }
        }
        energy
    }
}

/// Assigns each handle the control vertices inside its rest sphere and factors the constrained Laplacian.
fn constrain(low: &Mesh, laplacian: &Laplacian, handles: &mut [Handle]) -> (Vec<bool>, PoissonSolver) {
    let mut constrained = vec![false; low.num_vertices()];
    for handle in handles.iter_mut() {
        handle.constraints = (0..low.num_vertices()).filter(|&i| handle.contains_rest(&low.positions[i])).collect();
        for &i in &handle.constraints {
            constrained[i] = true;
        }
    }
    let solver = PoissonSolver::new(low, laplacian, &constrained, true);
    (constrained, solver)
}

/// The rotation maximising `tr(R^T m)` (orthogonal Procrustes), by SVD.
fn nearest_rotation(m: &Matrix3<f64>) -> Matrix3<f64> {
    let svd = m.svd(true, true);
    let (u, v_t) = (svd.u.expect("U"), svd.v_t.expect("V^T"));
    let mut d = Matrix3::identity();
    if (u * v_t).determinant() < 0.0 {
        d[(2, 2)] = -1.0;
    }
    u * d * v_t
}

/// `(w, x, y, z)`, the ordering of the unknowns in the rotation system.
fn coefficients(q: &Quat) -> Vector4<f64> {
    Vector4::new(q.w, q.i, q.j, q.k)
}

/// The 4x4 quadratic form `R^T H R` of the linearized fit `sum_j w_j |R q_j - p_j R|^2` (`E3GA_Prep`).
fn fit_matrix(p: &[Vec3], q: &[Vec3], w: &[f64]) -> Matrix4<f64> {
    let mut sx = Matrix3::zeros();
    let mut s = 0.0;
    for ((pj, qj), &wj) in p.iter().zip(q).zip(w) {
        s += wj * pj.dot(pj) + wj * qj.dot(qj);
        sx += (pj * wj) * qj.transpose();
    }
    let half = 0.5 * s;
    let trace = sx.trace();
    let diagonal = half + trace;
    let mut m = Matrix4::zeros();
    m[(0, 0)] = half - trace;
    m[(0, 1)] = -(sx[(1, 2)] - sx[(2, 1)]);
    m[(0, 2)] = -(sx[(2, 0)] - sx[(0, 2)]);
    m[(0, 3)] = -(sx[(0, 1)] - sx[(1, 0)]);
    m[(1, 1)] = -2.0 * sx[(0, 0)] + diagonal;
    m[(1, 2)] = -(sx[(0, 1)] + sx[(1, 0)]);
    m[(1, 3)] = -(sx[(2, 0)] + sx[(0, 2)]);
    m[(2, 2)] = -2.0 * sx[(1, 1)] + diagonal;
    m[(2, 3)] = -(sx[(1, 2)] + sx[(2, 1)]);
    m[(3, 3)] = -2.0 * sx[(2, 2)] + diagonal;
    for r in 0..4 {
        for c in 0..r {
            m[(r, c)] = m[(c, r)];
        }
    }
    m
}

/// Closed-form rotation of a constrained vertex, smoothed towards its neighbours' rotations (`E3GA_Fast4`):
/// `(H + A I) R = A mean_j(R_j)`.
fn fit_constrained(p: &[Vec3], q: &[Vec3], w: &[f64], alpha_area: f64, neighbors: &[Quat]) -> Quat {
    let mut b = Vector4::zeros();
    for r in neighbors {
        b += coefficients(r);
    }
    b *= alpha_area / neighbors.len() as f64;
    let mut m = fit_matrix(p, q, w);
    for c in 0..4 {
        m[(c, c)] += alpha_area;
    }
    let x = m.try_inverse().map(|inv| inv * b).unwrap_or(b);
    Quat::new_normalize(Quaternion::new(x[0], x[1], x[2], x[3]))
}

/// `sum_j w_ij (R_i + R_j) / 2 (p_j - p_i)`: the rest differentials rotated by the current rotation field.
fn rotated_differentials(mesh: &Mesh, laplacian: &Laplacian, rotations: &[Quat]) -> Vec<Vec3> {
    parallel_map(mesh.num_vertices(), |i| {
        let mut sum = Vec3::zeros();
        for (&j, &w) in mesh.neighbors[i].iter().zip(&laplacian.weights[i]) {
            let v = mesh.positions[j] - mesh.positions[i];
            sum += (rotations[i] * v + rotations[j] * v) * (0.5 * w);
        }
        sum
    })
}

/// `(0..n).map(f).collect()`, split across the available cores for large `n`.
fn parallel_map<T: Send + Default + Clone>(n: usize, f: impl Fn(usize) -> T + Sync) -> Vec<T> {
    let threads = std::thread::available_parallelism().map_or(1, |t| t.get());
    if n < 20_000 || threads == 1 {
        return (0..n).map(f).collect();
    }
    let mut out = vec![T::default(); n];
    let chunk = n.div_ceil(threads);
    std::thread::scope(|scope| {
        for (k, part) in out.chunks_mut(chunk).enumerate() {
            let f = &f;
            scope.spawn(move || {
                for (offset, slot) in part.iter_mut().enumerate() {
                    *slot = f(k * chunk + offset);
                }
            });
        }
    });
    out
}

/// Brute-force nearest detailed vertex for every control vertex (`meshMapping`).
fn nearest_vertices(low: &Mesh, high: &Mesh) -> Vec<usize> {
    low.positions
        .iter()
        .map(|pl| {
            let mut best = (f64::INFINITY, 0);
            for (h, ph) in high.positions.iter().enumerate() {
                let d = (pl - ph).norm_squared();
                if d < best.0 {
                    best = (d, h);
                }
            }
            best.1
        })
        .collect()
}

fn vectors_to_mat(v: &[Vec3]) -> Mat<f64> {
    Mat::from_fn(v.len(), 3, |i, k| v[i][k])
}

fn mat_to_vectors(m: &Mat<f64>) -> Vec<Vec3> {
    (0..m.nrows()).map(|i| Vec3::new(m[(i, 0)], m[(i, 1)], m[(i, 2)])).collect()
}

fn set_row(m: &mut Mat<f64>, i: usize, p: &Vec3) {
    for k in 0..3 {
        m[(i, k)] = p[k];
    }
}

#[cfg(test)]
mod tests {
    use std::collections::HashMap;
    use std::path::Path;

    use super::*;

    fn cactus() -> Deformer {
        let data = Path::new(env!("CARGO_MANIFEST_DIR")).join("../src");
        let high = Mesh::read_obj(&data.join("cactus2.obj")).unwrap();
        let low = Mesh::read_obj(&data.join("cactus1.obj")).unwrap();
        let handles = vec![
            Handle::new(Vec3::new(0.0, 0.04, 0.7), 0.15),
            Handle::new(Vec3::new(0.0, 0.04, -0.8), 0.15),
        ];
        Deformer::new(high, low, handles)
    }

    fn max_distance(a: &[Vec3], b: &[Vec3]) -> f64 {
        a.iter().zip(b).map(|(x, y)| (x - y).norm()).fold(0.0, f64::max)
    }

    #[test]
    fn handles_capture_control_vertices() {
        let d = cactus();
        assert!(d.handles.iter().all(|h| !h.constraints.is_empty()));
    }

    #[test]
    fn rest_pose_is_a_fixed_point() {
        let mut d = cactus();
        d.step();
        assert!(max_distance(&d.low_positions, &d.low.positions) < 1e-9);
        // The detailed mesh is pinned to the control positions at its nearest vertices, which are up to ~1% of the
        // model size away, so it settles close to, not exactly at, its rest pose (as in the C++ code).
        assert!(max_distance(&d.high_positions, &d.high.positions) < 0.02);
    }

    #[test]
    fn moved_handle_converges_and_constraints_hold() {
        let mut d = cactus();
        d.step();
        // The benchmark displacement applied by the `C` key.
        d.handles[0].translation += Vec3::new(-0.7, -0.6, 0.0);
        let before = d.energy();
        d.step();
        let after_frame = d.energy();
        d.iterate_many(true);
        let converged = d.energy();
        println!("energy: first frame {after_frame:.6}, converged {converged:.6} (rest {before:.6})");
        assert!(converged <= after_frame + 1e-9);

        for h in &d.handles {
            for &i in &h.constraints {
                assert!((d.low_positions[i] - h.transform(&d.low.positions[i])).norm() < 1e-9);
            }
        }
        // The detailed mesh passes through the control vertices it is mapped to. When two control vertices share a
        // detailed vertex the later one wins, as with the C++ std::map.
        let mut last_writer = HashMap::new();
        for (l, &h) in d.high_of_low.iter().enumerate() {
            last_writer.insert(h, l);
        }
        for (&h, &l) in &last_writer {
            assert!((d.high_positions[h] - d.low_positions[l]).norm() < 1e-9);
        }
        // The far handle did not move.
        let far = &d.handles[1];
        for &i in &far.constraints {
            assert!((d.low_positions[i] - d.low.positions[i]).norm() < 1e-9);
        }
    }

    #[test]
    fn cholesky_rotation_solve_matches_the_cpp_lu_system() {
        let mut d = cactus();
        d.step();
        d.handles[0].translation += Vec3::new(-0.3, 0.2, 0.1);
        d.handles[1].rotation = Quat::from_axis_angle(&nalgebra::Vector3::x_axis(), 0.5);
        for _ in 0..5 {
            d.solve_low_positions();
            let (rotations, positions) = (d.low_rotations.clone(), d.low_positions.clone());
            d.solve_low_rotations_lu();
            let reference = d.low_rotations.clone();
            (d.low_rotations, d.low_positions) = (rotations, positions);
            d.solve_low_rotations();
            let worst = d.low_rotations.iter().zip(&reference).map(|(a, b)| a.angle_to(b)).fold(0.0, f64::max);
            assert!(worst < 1e-9, "largest rotation difference {worst}");
        }
    }

    #[test]
    fn pcg_local_step_matches_the_closed_form() {
        let mut d = cactus();
        d.step();
        d.handles[0].translation += Vec3::new(-0.3, 0.2, 0.1);
        d.handles[1].rotation = Quat::from_axis_angle(&nalgebra::Vector3::x_axis(), 0.6);
        for _ in 0..5 {
            d.global();
            let saved = (d.low_rotations.clone(), d.low_differentials.clone());
            d.local_step = LocalStep::ClosedForm;
            d.local();
            let reference = d.low_rotations.clone();
            (d.low_rotations, d.low_differentials) = saved;
            d.local_step = LocalStep::Pcg;
            d.local();
            let worst = d.low_rotations.iter().zip(&reference).map(|(a, b)| a.angle_to(b)).fold(0.0, f64::max);
            println!("PCG: {} iterations, largest difference to the closed form {worst:.1e} rad", d.last_pcg_iterations);
            assert!(worst < 1e-10, "PCG differs from the closed form by {worst}");
        }
    }

    #[test]
    fn relaxation_converges_to_the_closed_form_solution() {
        let mut d = cactus();
        d.step();
        d.handles[0].translation += Vec3::new(-0.3, 0.2, 0.1);
        d.handles[1].rotation = Quat::from_axis_angle(&nalgebra::Vector3::x_axis(), 0.6);
        d.global();
        let errors = d.relaxation_errors(3000);
        println!("relaxation error after 1, 10, 100, 3000 sweeps: {:.2e} {:.2e} {:.2e} {:.2e}",
                 errors[0], errors[9], errors[99], errors[2999]);
        assert!(errors[2999] < 1e-8, "relaxation did not reach the closed-form solution: {}", errors[2999]);
        assert!(errors[2999] < errors[0]);
    }

    #[test]
    fn rotated_handle_rotates_its_region() {
        let mut d = cactus();
        d.step();
        let axis = nalgebra::Vector3::y_axis();
        d.handles[0].rotation = Quat::from_axis_angle(&axis, 0.8);
        for _ in 0..20 {
            d.step();
        }
        let i = d.handles[0].constraints[0];
        let angle = d.low_rotations[i].angle_to(&d.handles[0].rotation);
        println!("rotation error at a handle vertex: {angle:.4} rad");
        assert!(angle < 0.2);
    }
}


#[cfg(test)]
mod timing {
    use super::*;

    /// `cargo test --release timing -- --ignored --nocapture`
    #[test]
    #[ignore]
    fn armadillo_frame_time() {
        frame_time("armadillo.obj", "armadillo1.obj", Vec3::new(-0.5, 0.45, -0.3), Vec3::new(0.2, -0.6, 0.1));
    }

    #[test]
    #[ignore]
    fn cactus_frame_time() {
        frame_time("cactus2.obj", "cactus1.obj", Vec3::new(0.0, 0.04, 0.7), Vec3::new(0.0, 0.04, -0.8));
    }

    fn frame_time(hi: &str, lo: &str, a: Vec3, b: Vec3) {
        let data = std::path::Path::new(env!("CARGO_MANIFEST_DIR")).join("../src");
        let high = Mesh::read_obj(&data.join(hi)).unwrap();
        let low = Mesh::read_obj(&data.join(lo)).unwrap();
        let handles = vec![Handle::new(a, 0.15), Handle::new(b, 0.15)];
        let mut d = Deformer::new(high, low, handles);
        d.step();
        d.handles[0].translation += Vec3::new(0.0, 0.2, 0.0);
        let start = Instant::now();
        for _ in 0..10 {
            d.step();
        }
        println!("{hi} frame: {:.1} ms", start.elapsed().as_secs_f64() * 100.0);
        let time = |name: &str, f: &mut dyn FnMut()| {
            let start = Instant::now();
            for _ in 0..10 {
                f();
            }
            println!("{name}: {:.2} ms", start.elapsed().as_secs_f64() * 100.0);
        };
        time("low rotations", &mut || d.solve_low_rotations());
        time("low positions", &mut || d.solve_low_positions());
        time("transfer rotations", &mut || d.transfer_rotations());
        time("high positions", &mut || d.solve_high_positions());
        time("high differentials", &mut || {
            rotated_differentials(&d.high, &d.high_laplacian, &d.high_rotations);
        });
    }
}


#[cfg(test)]
mod tube_tests {
    use std::collections::HashSet;

    use crate::mesh::Mesh;

    #[test]
    fn tube_is_a_closed_consistently_oriented_manifold_with_small_valence() {
        for (rings, segments) in [(21, 24), (41, 48), (81, 96)] {
            let mesh = Mesh::tube(rings, segments, 4.0, 0.25);
            let mut directed = HashSet::new();
            for &[a, b, c] in &mesh.faces {
                for edge in [(a, b), (b, c), (c, a)] {
                    assert!(directed.insert(edge), "directed edge {edge:?} used twice: inconsistent orientation");
                }
            }
            for &(a, b) in &directed {
                assert!(directed.contains(&(b, a)), "edge ({a}, {b}) is on a boundary");
            }
            let max_valence = mesh.neighbors.iter().map(Vec::len).max().unwrap();
            assert!(max_valence <= 12, "valence {max_valence}");
            // Euler characteristic of a sphere.
            let edges = directed.len() / 2;
            assert_eq!(mesh.num_vertices() as i64 - edges as i64 + mesh.faces.len() as i64, 2);
        }
    }
}
