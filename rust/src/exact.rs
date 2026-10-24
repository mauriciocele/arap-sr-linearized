//! The exact cell problem of the SR-ARAP local step with unit quaternions:
//!
//! ```text
//! minimise  R^T M R - 2 h^T R   subject to  |R| = 1,
//! ```
//!
//! where `M` is the cell's symmetric positive semi-definite membrane matrix and `h = alpha A (sum_j w_ij R_j +
//! eps_i R_i^prev)` collects the neighbours' rotations (on the unit sphere the bending term `|R - R_j|^2 = 2 -
//! 2 R.R_j` is linear in `R`). Its stationarity condition is
//!
//! ```text
//! (M - lambda I) R = h,   |R| = 1,
//! ```
//!
//! with a Lagrange multiplier `lambda`. The linearized cell equation `(M + alpha A I) R = h` is the same equation
//! with the multiplier frozen at `lambda = -alpha A`; here it is solved for.
//!
//! The global minimiser has `lambda* < m1`, the smallest eigenvalue of `M` (`M - lambda I` positive definite), and
//! `lambda*` is the root of `psi(lambda) = 1 / |R(lambda)| = 1`, `R(lambda) = (M - lambda I)^-1 h`. `psi` is
//! concave and decreasing on `(-inf, m1)`, so Newton's method started in `[lambda*, m1)` decreases monotonically to
//! `lambda*`. Such a start comes from the cell's own ARAP rotation `v1`, the eigenvector of `m1`: since
//! `|R(lambda)| >= |h.v1| / (m1 - lambda)`, the start `m1 - |h.v1|` has `|R| >= 1`.
//!
//! `m1` is found as in "Robust Quaternion Estimation with Geometric Algebra": Newton's method on the
//! characteristic polynomial, started from the bound `0 <= m1` (`M` is positive semi-definite), increases
//! monotonically to `m1`; `v1` is the column of `adj(M - m1 I)` with the largest diagonal entry.

use nalgebra::{Matrix4, Vector4};

/// What [`exact_cell`] found.
#[derive(Clone, Copy, Debug)]
pub struct ExactCell {
    /// The unit quaternion `(w, x, y, z)`.
    pub rotation: Vector4<f64>,
    /// The Lagrange multiplier `lambda*`.
    pub multiplier: f64,
    /// The smallest eigenvalue `m1` of `M`.
    pub smallest_eigenvalue: f64,
    /// Newton steps for `m1` and for `lambda*`.
    pub eigen_steps: usize,
    pub secular_steps: usize,
}

const MAX_STEPS: usize = 60;

fn minor3(g: &Matrix4<f64>, row: usize, col: usize) -> f64 {
    const OTHERS: [[usize; 3]; 4] = [[1, 2, 3], [0, 2, 3], [0, 1, 3], [0, 1, 2]];
    let (r, c) = (OTHERS[row], OTHERS[col]);
    g[(r[0], c[0])] * (g[(r[1], c[1])] * g[(r[2], c[2])] - g[(r[1], c[2])] * g[(r[2], c[1])])
        - g[(r[0], c[1])] * (g[(r[1], c[0])] * g[(r[2], c[2])] - g[(r[1], c[2])] * g[(r[2], c[0])])
        + g[(r[0], c[2])] * (g[(r[1], c[0])] * g[(r[2], c[1])] - g[(r[1], c[1])] * g[(r[2], c[0])])
}

/// The null vector of a symmetric matrix `g` of rank 3: the column of `adj(g)` with the largest diagonal entry.
fn null_vector(g: &Matrix4<f64>) -> Vector4<f64> {
    let diagonal = [0, 1, 2, 3].map(|k| minor3(g, k, k));
    let k = (0..4).max_by(|&a, &b| diagonal[a].abs().total_cmp(&diagonal[b].abs())).unwrap();
    let sign = |i: usize| if (i + k) % 2 == 0 { 1.0 } else { -1.0 };
    Vector4::from_fn(|i, _| sign(i) * minor3(g, k, i))
}

/// The smallest eigenvalue of the symmetric positive semi-definite `m`, by Newton's method on
/// `det(m - lambda I)` from `0`, and the number of steps.
fn smallest_eigenvalue(m: &Matrix4<f64>) -> (f64, usize) {
    // det(m - lambda I) = lambda^4 - e1 lambda^3 + e2 lambda^2 - e3 lambda + e4, from the traces of the powers
    let m2 = m * m;
    let (t1, t2, t3) = (m.trace(), m2.trace(), (m2 * m).trace());
    let e1 = t1;
    let e2 = (t1 * t1 - t2) / 2.0;
    let e3 = (t1 * t1 * t1 - 3.0 * t1 * t2 + 2.0 * t3) / 6.0;
    let e4 = m.determinant();
    let tolerance = 1e-14 * t1.max(f64::MIN_POSITIVE);
    let mut lambda = 0.0;
    for step in 1..=MAX_STEPS {
        let p = (((lambda - e1) * lambda + e2) * lambda - e3) * lambda + e4;
        let dp = ((4.0 * lambda - 3.0 * e1) * lambda + 2.0 * e2) * lambda - e3;
        if dp == 0.0 {
            return (lambda, step);
        }
        let delta = p / dp;
        lambda -= delta;
        if delta.abs() <= tolerance {
            return (lambda, step);
        }
    }
    (lambda, MAX_STEPS)
}

/// The rotation that fits a cell's own edges best: the unit eigenvector of the smallest eigenvalue of `m`
/// (the cell problem without bending), up to sign.
pub fn cell_rotation(m: &Matrix4<f64>) -> Vector4<f64> {
    let (m1, _) = smallest_eigenvalue(m);
    null_vector(&(m - Matrix4::identity() * m1)).normalize()
}

/// Solves the exact cell problem (see the module documentation). `hint` (e.g. the cell's previous rotation)
/// only breaks the tie of the hard case, where two minimisers mirror each other.
pub fn exact_cell(m: &Matrix4<f64>, h: &Vector4<f64>, hint: &Vector4<f64>) -> ExactCell {
    let (m1, eigen_steps) = smallest_eigenvalue(m);
    let g1 = m - Matrix4::identity() * m1;
    let v = null_vector(&g1);
    let v1 = v / v.norm();
    let beta = h.dot(&v1).abs();
    let scale = m.trace().max(h.norm());
    if beta <= 1e-13 * scale {
        // The hard case: h has no component along v1. The part of the solution orthogonal to v1 is the solution y
        // of G1 y = h, y . v1 = 0, which (G1 + v1 v1^T) y = h gives; if it is shorter than 1, the minimiser is at
        // lambda = m1 and completes y to unit length along v1.
        let y = (g1 + v1 * v1.transpose()).cholesky().map(|c| c.solve(&(h - v1 * h.dot(&v1))));
        if let Some(y) = y.filter(|y| y.norm_squared() <= 1.0) {
            let tau = (1.0 - y.norm_squared()).sqrt();
            let side = if hint.dot(&v1) < 0.0 { -1.0 } else { 1.0 };
            let rotation = y + v1 * (side * tau);
            return ExactCell { rotation, multiplier: m1, smallest_eigenvalue: m1, eigen_steps, secular_steps: 0 };
        }
    }
    // Otherwise lambda* < m1: Newton from m1 - |h.v1|, where |R| >= 1
    let offset = beta.max(1e-12 * scale);
    let mut lambda = m1 - offset;
    let mut rotation = v1;
    let mut secular_steps = 0;
    for step in 1..=MAX_STEPS {
        secular_steps = step;
        let g = m - Matrix4::identity() * lambda;
        let Some(cholesky) = g.cholesky() else {
            // rounding pushed lambda to m1: step back towards the root
            lambda -= offset;
            continue;
        };
        let r = cholesky.solve(h);
        let z = cholesky.l().solve_lower_triangular(&r).expect("triangular");
        let norm = r.norm();
        rotation = r / norm;
        // Newton on 1 / |R(lambda)| = 1
        let delta = norm * norm * (1.0 - norm) / z.norm_squared();
        lambda += delta;
        // quadratic convergence: once a step is at rounding level, the rotation of this step is final
        if delta.abs() <= 1e-14 * scale || (1.0 - norm).abs() <= 1e-15 {
            break;
        }
    }
    ExactCell { rotation, multiplier: lambda, smallest_eigenvalue: m1, eigen_steps, secular_steps }
}

#[cfg(test)]
mod tests {
    use super::*;

    struct Lcg(u64);
    impl Lcg {
        fn next(&mut self) -> f64 {
            self.0 = self.0.wrapping_mul(6364136223846793005).wrapping_add(1442695040888963407);
            ((self.0 >> 11) as f64 / (1u64 << 53) as f64) * 2.0 - 1.0
        }
    }

    fn problem(seed: u64) -> (Matrix4<f64>, Vector4<f64>) {
        let mut g = Lcg(seed);
        let x = Matrix4::from_fn(|_, _| g.next());
        let m = x * x.transpose() * (0.01 + g.next().abs() * 3.0);
        let h = Vector4::from_fn(|_, _| g.next()) * (1e-3 + g.next().abs() * 5.0);
        (m, h)
    }

    /// The minimum over the sphere, by brute force on a fine grid refined locally.
    fn brute_force(m: &Matrix4<f64>, h: &Vector4<f64>) -> f64 {
        let f = |r: &Vector4<f64>| (r.transpose() * m * r)[0] - 2.0 * h.dot(r);
        let mut best = f64::MAX;
        let mut best_r = Vector4::zeros();
        let n = 24;
        for a in 0..=n {
            for b in 0..=n {
                for c in 0..=2 * n {
                    let (t1, t2, t3) = (
                        std::f64::consts::PI * a as f64 / n as f64,
                        std::f64::consts::PI * b as f64 / n as f64,
                        std::f64::consts::PI * c as f64 / n as f64,
                    );
                    let r = Vector4::new(
                        t1.cos(),
                        t1.sin() * t2.cos(),
                        t1.sin() * t2.sin() * t3.cos(),
                        t1.sin() * t2.sin() * t3.sin(),
                    );
                    let v = f(&r);
                    if v < best {
                        best = v;
                        best_r = r;
                    }
                }
            }
        }
        // local refinement by projected gradient
        let mut r = best_r;
        for _ in 0..20000 {
            let grad = (m * r - h) * 2.0;
            let tangent = grad - r * r.dot(&grad);
            r = (r - tangent * 1e-3 / (1.0 + m.trace())).normalize();
        }
        f(&r).min(best)
    }

    #[test]
    fn satisfies_the_stationarity_condition_on_the_sphere() {
        for seed in 0..3000 {
            let (m, h) = problem(seed);
            let c = exact_cell(&m, &h, &Vector4::zeros());
            let residual = (m - Matrix4::identity() * c.multiplier) * c.rotation - h;
            assert!((c.rotation.norm() - 1.0).abs() < 1e-12, "seed {seed}");
            assert!(residual.norm() < 1e-9 * (m.norm() + h.norm()), "seed {seed}: {}", residual.norm());
            assert!(c.multiplier < c.smallest_eigenvalue, "seed {seed}");
            let eigen = m.symmetric_eigen();
            let m1 = eigen.eigenvalues.min();
            assert!((c.smallest_eigenvalue - m1).abs() < 1e-10 * m.trace(), "seed {seed}");
            assert!(c.secular_steps < 40 && c.eigen_steps < 40, "seed {seed}: {c:?}");
        }
    }

    #[test]
    fn is_the_global_minimum() {
        for seed in 0..40 {
            let (m, h) = problem(seed);
            let c = exact_cell(&m, &h, &Vector4::zeros());
            let f = (c.rotation.transpose() * m * c.rotation)[0] - 2.0 * h.dot(&c.rotation);
            assert!(f <= brute_force(&m, &h) + 1e-9, "seed {seed}");
        }
    }

    #[test]
    fn hard_case_completes_the_orthogonal_part_along_the_cell_rotation() {
        for seed in 0..200 {
            let (m, h) = problem(seed);
            let e = m.symmetric_eigen();
            let v1 = e.eigenvectors.column(e.eigenvalues.imin()).into_owned();
            // a pull orthogonal to the cell's own rotation, weak and strong
            for s in [1e-3, 1e-1, 10.0] {
                let h = (h - v1 * h.dot(&v1)) * s;
                let c = exact_cell(&m, &h, &v1);
                let f = |r: &Vector4<f64>| (r.transpose() * m * r)[0] - 2.0 * h.dot(r);
                assert!((c.rotation.norm() - 1.0).abs() < 1e-12, "seed {seed}");
                assert!(f(&c.rotation) <= brute_force(&m, &h) + 1e-9 * (1.0 + m.norm()), "seed {seed}, s {s}");
            }
            if seed >= 20 {
                break;
            }
        }
    }

    #[test]
    fn small_bending_gives_the_cell_rotation_and_large_bending_the_neighbour_average() {
        let (m, h) = problem(7);
        let v1 = m.symmetric_eigen();
        let k = v1.eigenvalues.imin();
        let e = v1.eigenvectors.column(k).into_owned();
        let small = exact_cell(&m, &(h * 1e-9), &Vector4::zeros()).rotation;
        assert!((small.dot(&e).abs() - 1.0).abs() < 1e-8);
        let large = exact_cell(&m, &(h * 1e9), &Vector4::zeros()).rotation;
        assert!((large - h.normalize()).norm() < 1e-6);
    }
}
