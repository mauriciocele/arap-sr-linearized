//! Discrete Laplacian. Port of `Laplacian.cpp` and the map-based `numerics::SparseMatrix`.
//!
//! Row `i` holds `L(i, j) = w_ij` for every neighbour `j` and `L(i, i) = -sum_j w_ij`, so
//! `(L x)_i = sum_j w_ij (x_j - x_i)`. With cotangent weights the per-vertex area scaling of the C++ code is 1 for
//! every non-isolated vertex, so it is applied only for the uniform and mean-value variants.

use faer::prelude::Solve;
use faer::sparse::linalg::solvers::{Llt, Lu};
use faer::sparse::{SparseColMat, Triplet};
use faer::{Mat, Side};

use crate::mesh::{Mesh, Vec3};

#[allow(dead_code)]
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Weights {
    Uniform,
    Cotangent,
    MeanValue,
}

#[derive(Clone)]
pub struct Laplacian {
    /// Off-diagonal weights of row `i`, aligned with `mesh.neighbors[i]`.
    pub weights: Vec<Vec<f64>>,
    pub diagonal: Vec<f64>,
}

impl Laplacian {
    pub fn new(mesh: &Mesh, kind: Weights) -> Self {
        let n = mesh.num_vertices();
        let mut weights: Vec<Vec<f64>> = (0..n)
            .map(|i| mesh.neighbors[i].iter().map(|&j| edge_weight(mesh, kind, i, j)).collect())
            .collect();
        let mut diagonal = vec![0.0; n];
        for i in 0..n {
            let w: f64 = weights[i].iter().sum();
            diagonal[i] = -w;
            if kind != Weights::Cotangent {
                let scale = if w.abs() > f64::from(f32::MIN_POSITIVE) { 1.0 / w } else { 0.0 };
                weights[i].iter_mut().for_each(|x| *x *= scale);
                diagonal[i] *= scale;
            }
        }
        Laplacian { weights, diagonal }
    }

    /// `L p`: the differential coordinates of the rest pose.
    pub fn apply(&self, mesh: &Mesh, x: &[Vec3]) -> Vec<Vec3> {
        (0..x.len())
            .map(|i| {
                let mut sum = x[i] * self.diagonal[i];
                for (&j, &w) in mesh.neighbors[i].iter().zip(&self.weights[i]) {
                    sum += x[j] * w;
                }
                sum
            })
            .collect()
    }
}

/// Solves `L x = b` with `x_i` prescribed at the constrained vertices: the system the C++ code builds by replacing
/// each constrained row with an identity row (`PreFactor`).
///
/// The prescribed values are moved to the right-hand side instead, which leaves the free block `-L_ff`. With
/// cotangent weights that block is symmetric positive definite, so it is factored with a sparse Cholesky, which is
/// several times faster to solve than the LU of the row-replaced matrix. The solution is the same.
pub struct PoissonSolver {
    free: Vec<usize>,
    /// `L(i, j)` for free `i` and constrained `j`, as (reduced row of `i`, `j`, weight).
    coupling: Vec<(usize, usize, f64)>,
    factor: Factor,
}

enum Factor {
    Cholesky(Llt<usize, f64>),
    /// Fallback for the non-symmetric weightings.
    Lu(Box<Lu<usize, f64>>),
}

impl PoissonSolver {
    pub fn new(mesh: &Mesh, laplacian: &Laplacian, constrained: &[bool], symmetric: bool) -> Self {
        let mut free_index = vec![None; mesh.num_vertices()];
        let free: Vec<usize> = (0..mesh.num_vertices()).filter(|&i| !constrained[i]).collect();
        for (r, &i) in free.iter().enumerate() {
            free_index[i] = Some(r);
        }
        let mut triplets = Vec::with_capacity(free.len() * 8);
        let mut coupling = Vec::new();
        for (r, &i) in free.iter().enumerate() {
            triplets.push(Triplet::new(r, r, -laplacian.diagonal[i]));
            for (&j, &w) in mesh.neighbors[i].iter().zip(&laplacian.weights[i]) {
                match free_index[j] {
                    Some(c) => triplets.push(Triplet::new(r, c, -w)),
                    None => coupling.push((r, j, w)),
                }
            }
        }
        let m = free.len();
        let matrix = SparseColMat::<usize, f64>::try_new_from_triplets(m, m, &triplets).expect("valid triplets");
        let factor = if symmetric {
            Factor::Cholesky(matrix.sp_cholesky(Side::Lower).expect("Laplacian block is not positive definite"))
        } else {
            Factor::Lu(Box::new(matrix.sp_lu().expect("Laplacian block is singular")))
        };
        PoissonSolver { free, coupling, factor }
    }

    /// `rhs` holds the differential coordinates in free rows and the prescribed values in constrained rows; it is
    /// overwritten with the solution.
    pub fn solve_in_place(&self, rhs: &mut Mat<f64>) {
        let k = rhs.ncols();
        // -L_ff x_f = -(b_f - L_fc x_c)
        let mut reduced = Mat::from_fn(self.free.len(), k, |r, c| -rhs[(self.free[r], c)]);
        for &(r, j, w) in &self.coupling {
            for c in 0..k {
                reduced[(r, c)] += w * rhs[(j, c)];
            }
        }
        // faer's own threading makes these triangular solves much slower (see `Deformer::new`), so the columns are
        // solved on separate threads instead.
        let mut columns: Vec<Mat<f64>> = (0..k).map(|c| reduced.col(c).as_mat().to_owned()).collect();
        std::thread::scope(|scope| {
            for column in &mut columns {
                scope.spawn(|| match &self.factor {
                    Factor::Cholesky(llt) => llt.solve_in_place(column),
                    Factor::Lu(lu) => lu.solve_in_place(column),
                });
            }
        });
        for (c, column) in columns.iter().enumerate() {
            reduced.col_mut(c).copy_from(column.col(0));
        }
        for (r, &i) in self.free.iter().enumerate() {
            for c in 0..k {
                rhs[(i, c)] = reduced[(r, c)];
            }
        }
    }
}

fn edge_weight(mesh: &Mesh, kind: Weights, i: usize, j: usize) -> f64 {
    let p = &mesh.positions;
    let (vi, vj) = (p[i], p[j]);
    // The faces on either side of the edge: (i, j, k1) and (j, i, k2).
    let sides = [mesh.opposite(i, j), mesh.opposite(j, i)];
    match kind {
        Weights::Uniform => 1.0,
        Weights::Cotangent => {
            let sum: f64 = sides.iter().flatten().map(|&k| cotangent(vi, p[k], vj)).sum();
            (sum / 2.0).max(0.0)
        }
        Weights::MeanValue => {
            // Not symmetric in (i, j); the C++ code keeps the value computed from the half-edge leaving the higher
            // vertex index for both L(i, j) and L(j, i).
            let (vi, vj) = if i > j { (vi, vj) } else { (vj, vi) };
            let sum: f64 = sides.iter().flatten().map(|&k| tan_half_angle(vi, p[k], vj)).sum();
            (sum / (vi - vj).norm()).max(0.0)
        }
    }
}

/// Cotangent of the angle at `b` in the triangle `(a, b, c)`.
fn cotangent(a: Vec3, b: Vec3, c: Vec3) -> f64 {
    let ba = a - b;
    let bc = c - b;
    ba.dot(&bc) / ba.cross(&bc).norm()
}

/// Tangent of half the angle at `a` between `b - a` and `c - a`, as in the C++ code.
fn tan_half_angle(a: Vec3, b: Vec3, c: Vec3) -> f64 {
    let bb = b - a;
    let cc = c - a;
    (bb.norm() * cc.norm() - bb.dot(&cc)) / bb.cross(&cc).norm()
}
