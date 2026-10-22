//! Iterative solvers for the rotation system `K_FF x = b` of the closed-form local step, to compare against its
//! sparse Cholesky factorization.
//!
//! `K_FF` has 4x4 diagonal blocks `s_i (M_i + (alpha A + eps) I)`, which change with the positions, and `-I`
//! blocks between adjacent free cells, which do not. Three solvers:
//! - CG: conjugate gradients, no preconditioner;
//! - block Jacobi: preconditioned with the inverses of the diagonal blocks (linear work per iteration);
//! - constant Cholesky: preconditioned with a Cholesky factorization of the position-independent part
//!   `C = diag(s_i (alpha A + eps)) - adjacency`, the same for all four quaternion components. `C` depends only on
//!   the mesh and the constraints, so it is factored once and every iteration costs one back-substitution.

use faer::prelude::Solve;
use faer::sparse::linalg::solvers::Llt;
use faer::sparse::{SparseColMat, Triplet};
use faer::{Mat, Side};
use nalgebra::{Matrix4, Vector4};

use crate::deformer::RotationSystem;

/// `K_FF` in compressed rows, both triangles.
pub struct SymmetricMatrix {
    row_start: Vec<usize>,
    cols: Vec<usize>,
    vals: Vec<f64>,
}

impl SymmetricMatrix {
    pub fn from_lower(size: usize, lower: &[(usize, usize, f64)]) -> Self {
        let mut entries: Vec<(usize, usize, f64)> = Vec::with_capacity(2 * lower.len());
        for &(r, c, v) in lower {
            entries.push((r, c, v));
            if r != c {
                entries.push((c, r, v));
            }
        }
        entries.sort_unstable_by_key(|&(r, c, _)| (r, c));
        let mut row_start = vec![0; size + 1];
        for &(r, _, _) in &entries {
            row_start[r + 1] += 1;
        }
        for i in 0..size {
            row_start[i + 1] += row_start[i];
        }
        SymmetricMatrix {
            row_start,
            cols: entries.iter().map(|e| e.1).collect(),
            vals: entries.iter().map(|e| e.2).collect(),
        }
    }

    pub fn apply(&self, x: &[f64], y: &mut [f64]) {
        for (i, out) in y.iter_mut().enumerate() {
            let mut sum = 0.0;
            for k in self.row_start[i]..self.row_start[i + 1] {
                sum += self.vals[k] * x[self.cols[k]];
            }
            *out = sum;
        }
    }
}

pub enum Preconditioner {
    None,
    BlockJacobi(Vec<Matrix4<f64>>),
    /// Factorization of the scalar matrix `C` (one row per free cell), applied to each quaternion component.
    ConstantCholesky(Box<Llt<usize, f64>>),
}

impl Preconditioner {
    pub fn block_jacobi(system: &RotationSystem) -> Self {
        Preconditioner::BlockJacobi(
            system.blocks.iter().map(|b| b.try_inverse().expect("diagonal block is positive definite")).collect(),
        )
    }

    /// Factors `C`. It depends only on the mesh and the constraints, so in an interactive session this is done
    /// once, not every local step.
    pub fn constant_cholesky(system: &RotationSystem) -> Self {
        let cells = system.size / 4;
        let mut triplets: Vec<Triplet<usize, usize, f64>> =
            system.constant_diagonal.iter().enumerate().map(|(i, &d)| Triplet::new(i, i, d)).collect();
        // The coupling entries of K_FF are -1 between the same component of adjacent cells; take them once.
        for &(r, c, v) in &system.lower {
            if r / 4 != c / 4 && r % 4 == 0 {
                triplets.push(Triplet::new(r / 4, c / 4, v));
            }
        }
        let matrix = SparseColMat::<usize, f64>::try_new_from_triplets(cells, cells, &triplets).expect("valid C");
        Preconditioner::ConstantCholesky(Box::new(matrix.sp_cholesky(Side::Lower).expect("C is positive definite")))
    }

    fn apply(&self, r: &[f64], z: &mut [f64]) {
        match self {
            Preconditioner::None => z.copy_from_slice(r),
            Preconditioner::BlockJacobi(inverses) => {
                for (cell, inverse) in inverses.iter().enumerate() {
                    let v = Vector4::new(r[4 * cell], r[4 * cell + 1], r[4 * cell + 2], r[4 * cell + 3]);
                    let w = inverse * v;
                    z[4 * cell..4 * cell + 4].copy_from_slice(w.as_slice());
                }
            }
            Preconditioner::ConstantCholesky(llt) => {
                let cells = r.len() / 4;
                let mut rhs = Mat::from_fn(cells, 4, |i, k| r[4 * i + k]);
                llt.solve_in_place(&mut rhs);
                for i in 0..cells {
                    for k in 0..4 {
                        z[4 * i + k] = rhs[(i, k)];
                    }
                }
            }
        }
    }
}

fn dot(a: &[f64], b: &[f64]) -> f64 {
    a.iter().zip(b).map(|(x, y)| x * y).sum()
}

/// Preconditioned conjugate gradients from `x`, for at most `iterations` iterations, stopping once the residual
/// `|b - K x|` falls below `tolerance |b|` (pass 0 to run all iterations). `observe` sees the iterate after every
/// iteration and can stop the solve by returning false. Returns the number of iterations performed.
pub fn pcg(
    matrix: &SymmetricMatrix,
    b: &[f64],
    x: &mut [f64],
    preconditioner: &Preconditioner,
    iterations: usize,
    tolerance: f64,
    mut observe: impl FnMut(usize, &[f64]) -> bool,
) -> usize {
    let n = b.len();
    let mut r = vec![0.0; n];
    matrix.apply(x, &mut r);
    for i in 0..n {
        r[i] = b[i] - r[i];
    }
    let mut z = vec![0.0; n];
    preconditioner.apply(&r, &mut z);
    let mut p = z.clone();
    let mut rz = dot(&r, &z);
    let mut q = vec![0.0; n];
    let threshold = tolerance * dot(b, b).sqrt();
    let mut performed = 0;
    for k in 1..=iterations {
        if rz == 0.0 || dot(&r, &r).sqrt() <= threshold {
            break;
        }
        performed = k;
        matrix.apply(&p, &mut q);
        let alpha = rz / dot(&p, &q);
        for i in 0..n {
            x[i] += alpha * p[i];
            r[i] -= alpha * q[i];
        }
        if !observe(k, x) {
            break;
        }
        preconditioner.apply(&r, &mut z);
        let rz_next = dot(&r, &z);
        let beta = rz_next / rz;
        rz = rz_next;
        for i in 0..n {
            p[i] = z[i] + beta * p[i];
        }
    }
    performed
}
