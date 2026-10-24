//! The rotation `R` maximising `tr(R^T M)` for a 3x3 matrix `M` (orthogonal Procrustes), without an SVD.
//!
//! Two methods that solve the quartic of Davenport's 4x4 matrix with Newton's method, written once for any lane
//! type `T`: `f64` solves one problem, `f64x4` solves four independent problems at once in SIMD lanes.
//!
//! - [`rotor`]: the method of "Robust Quaternion Estimation with Geometric Algebra" (Algorithm 1): Newton from an
//!   upper bound of the largest eigenvalue, then the eigenrotor as the meet of three hyperplanes, the one with the
//!   largest component chosen with selects (no data-dependent branch). Returns a quaternion `(w, x, y, z)`.
//! - [`foam`]: Markley's FOAM, the same Newton iteration on its own quartic, then a closed formula for the
//!   rotation matrix.
//!
//! Both take, besides `M`, an upper bound `h` of the largest eigenvalue `s1 + s2 + s3` (the nuclear norm of `M`).
//! When `M = sum w_k t_k s_k^T`, `h = sum |w_k| (|s_k|^2 + |t_k|^2) / 2` is one, since `|w t s^T|_* = |w| |s| |t| <=
//! |w| (|s|^2 + |t|^2) / 2`; a rotation matrix `a R` (a > 0) adds `3 a`, its nuclear norm.
//!
//! Newton stops when a step is below `TOLERANCE * h` in every lane.

use std::ops::{Add, AddAssign, Div, Mul, Neg, Sub};

use nalgebra::Matrix3;
use wide::f64x4;

/// Relative stopping tolerance of Newton's method. Its convergence is quadratic, so the eigenvalue is then
/// accurate to about `TOLERANCE^2 h`.
pub const TOLERANCE: f64 = 1e-7;

/// What the methods need from a lane type: arithmetic, and comparisons that give masks.
pub trait Lane:
    Copy + Add<Output = Self> + Sub<Output = Self> + Mul<Output = Self> + Div<Output = Self> + Neg<Output = Self> + AddAssign
{
    type Mask: Copy;
    fn splat(x: f64) -> Self;
    fn abs(self) -> Self;
    fn sqrt(self) -> Self;
    fn gt(self, other: Self) -> Self::Mask;
    /// `a` where the mask is set, `b` elsewhere.
    fn select(m: Self::Mask, a: Self, b: Self) -> Self;
    fn any(m: Self::Mask) -> bool;
}

impl Lane for f64 {
    type Mask = bool;
    #[inline(always)]
    fn splat(x: f64) -> Self {
        x
    }
    #[inline(always)]
    fn abs(self) -> Self {
        f64::abs(self)
    }
    #[inline(always)]
    fn sqrt(self) -> Self {
        f64::sqrt(self)
    }
    #[inline(always)]
    fn gt(self, other: Self) -> bool {
        self > other
    }
    #[inline(always)]
    fn select(m: bool, a: Self, b: Self) -> Self {
        if m { a } else { b }
    }
    #[inline(always)]
    fn any(m: bool) -> bool {
        m
    }
}

impl Lane for f64x4 {
    type Mask = f64x4;
    #[inline(always)]
    fn splat(x: f64) -> Self {
        f64x4::splat(x)
    }
    #[inline(always)]
    fn abs(self) -> Self {
        f64x4::abs(self)
    }
    #[inline(always)]
    fn sqrt(self) -> Self {
        f64x4::sqrt(self)
    }
    #[inline(always)]
    fn gt(self, other: Self) -> f64x4 {
        self.simd_gt(other)
    }
    #[inline(always)]
    fn select(m: f64x4, a: Self, b: Self) -> Self {
        m.bitselect(a, b)
    }
    #[inline(always)]
    fn any(m: f64x4) -> bool {
        m.any()
    }
}

#[inline(always)]
fn det3<T: Lane>(m: &[[T; 3]; 3]) -> T {
    m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) - m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0])
        + m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0])
}

/// Bivector of the 4D algebra, coordinates on `e01, e02, e03, e12, e13, e23`.
#[derive(Clone, Copy)]
struct Bivector<T>([T; 6]);

#[inline(always)]
fn wedge2<T: Lane>(a: &[T; 4], b: &[T; 4]) -> Bivector<T> {
    Bivector([
        a[0] * b[1] - a[1] * b[0],
        a[0] * b[2] - a[2] * b[0],
        a[0] * b[3] - a[3] * b[0],
        a[1] * b[2] - a[2] * b[1],
        a[1] * b[3] - a[3] * b[1],
        a[2] * b[3] - a[3] * b[2],
    ])
}

/// `B ^ c`, coordinates on `e012, e013, e023, e123`.
#[inline(always)]
fn wedge3<T: Lane>(b: &Bivector<T>, c: &[T; 4]) -> [T; 4] {
    let b = &b.0;
    [
        b[0] * c[2] - b[1] * c[1] + b[3] * c[0],
        b[0] * c[3] - b[2] * c[1] + b[4] * c[0],
        b[1] * c[3] - b[2] * c[2] + b[5] * c[0],
        b[3] * c[3] - b[4] * c[2] + b[5] * c[1],
    ]
}

/// `A ^ C` for two bivectors: the coefficient of `e0123`.
#[inline(always)]
fn wedge4<T: Lane>(a: &Bivector<T>, c: &Bivector<T>) -> T {
    let (a, c) = (&a.0, &c.0);
    a[0] * c[5] - a[1] * c[4] + a[2] * c[3] + a[3] * c[2] - a[4] * c[1] + a[5] * c[0]
}

#[inline(always)]
fn normalized<T: Lane>(q: [T; 4]) -> [T; 4] {
    let s = T::splat(1.0) / (q[0] * q[0] + q[1] * q[1] + q[2] * q[2] + q[3] * q[3]).sqrt();
    [q[0] * s, q[1] * s, q[2] * s, q[3] * s]
}

/// The unit quaternion `(w, x, y, z)` of the rotation maximising `tr(R^T M)`, by the proposed method.
#[inline(always)]
pub fn rotor<T: Lane>(b: &[[T; 3]; 3], h: T) -> [T; 4] {
    // Davenport's matrix K = [[tr D, z^T], [z, D + D^T - tr D I]] in the order (w, x, y, z), one row per column
    let tr = b[0][0] + b[1][1] + b[2][2];
    let z = [b[2][1] - b[1][2], b[0][2] - b[2][0], b[1][0] - b[0][1]];
    let row = |i: usize| [z[i], b[i][0] + b[0][i], b[i][1] + b[1][i], b[i][2] + b[2][i]];
    let mut k = [[tr, z[0], z[1], z[2]], row(0), row(1), row(2)];
    for i in 1..4 {
        k[i][i] = k[i][i] - tr;
    }
    // characteristic polynomial mu^4 + a mu^2 + c1 mu + c0
    let mut sq = T::splat(0.0);
    for r in b {
        for &v in r {
            sq += v * v;
        }
    }
    let a = T::splat(-2.0) * sq;
    let c1 = T::splat(-8.0) * det3(b);
    let c0 = wedge4(&wedge2(&k[0], &k[1]), &wedge2(&k[2], &k[3]));
    let tolerance = T::splat(TOLERANCE) * h;
    let mut mu = h;
    loop {
        let mu2 = mu * mu;
        let step = ((mu2 + a) * mu2 + c1 * mu + c0) / ((T::splat(4.0) * mu2 + T::splat(2.0) * a) * mu + c1);
        mu = mu - step;
        if !T::any(step.abs().gt(tolerance)) {
            break;
        }
    }
    for (i, r) in k.iter_mut().enumerate() {
        r[i] = r[i] - mu;
    }
    let ab = wedge2(&k[0], &k[1]);
    let cb = wedge2(&k[2], &k[3]);
    let (a_, c_) = (&ab.0, &cb.0);
    // the component of each meet along its own axis, |r_k| times a common factor
    let own = [
        (c_[3] * k[1][3] - c_[4] * k[1][2] + c_[5] * k[1][1]).abs(),
        (c_[1] * k[0][3] - c_[2] * k[0][2] + c_[5] * k[0][0]).abs(),
        (a_[0] * k[3][3] - a_[2] * k[3][1] + a_[4] * k[3][0]).abs(),
        (a_[0] * k[2][2] - a_[1] * k[2][1] + a_[3] * k[2][0]).abs(),
    ];
    // choose the meet with the largest own component: its bivector and its vector, then one wedge
    let m1 = own[1].gt(own[0]);
    let mut best = T::select(m1, own[1], own[0]);
    let mut bs = cb;
    let mut v = [0, 1, 2, 3].map(|i| T::select(m1, k[0][i], k[1][i]));
    for (kk, vi) in [(2, 3), (3, 2)] {
        let m = own[kk].gt(best);
        best = T::select(m, own[kk], best);
        for i in 0..6 {
            bs.0[i] = T::select(m, ab.0[i], bs.0[i]);
        }
        for i in 0..4 {
            v[i] = T::select(m, k[vi][i], v[i]);
        }
    }
    let t = wedge3(&bs, &v);
    normalized([t[3], -t[2], t[1], -t[0]])
}

/// The rotation matrix maximising `tr(R^T M)`, by FOAM. The matrix is orthogonal to the precision of Newton's
/// method.
#[inline(always)]
pub fn foam<T: Lane>(b: &[[T; 3]; 3], h: T) -> [[T; 3]; 3] {
    let mut cof = [[T::splat(0.0); 3]; 3];
    for i in 0..3 {
        for k in 0..3 {
            let (i1, i2, k1, k2) = ((i + 1) % 3, (i + 2) % 3, (k + 1) % 3, (k + 2) % 3);
            cof[i][k] = b[i1][k1] * b[i2][k2] - b[i1][k2] * b[i2][k1];
        }
    }
    let (mut norm, mut adj) = (T::splat(0.0), T::splat(0.0));
    for i in 0..3 {
        for k in 0..3 {
            norm += b[i][k] * b[i][k];
            adj += cof[i][k] * cof[i][k];
        }
    }
    let adj = T::splat(4.0) * adj;
    let det = T::splat(8.0) * det3(b);
    let tolerance = T::splat(TOLERANCE) * h;
    let mut lambda = h;
    loop {
        let kappa = lambda * lambda - norm;
        let step = (kappa * kappa - lambda * det - adj) / (T::splat(4.0) * lambda * kappa - det);
        lambda = lambda - step;
        if !T::any(step.abs().gt(tolerance)) {
            break;
        }
    }
    let kappa = T::splat(0.5) * (lambda * lambda - norm);
    let mut bbt = [[T::splat(0.0); 3]; 3];
    for i in 0..3 {
        for k in 0..3 {
            bbt[i][k] = b[i][0] * b[k][0] + b[i][1] * b[k][1] + b[i][2] * b[k][2];
        }
    }
    let inv = T::splat(1.0) / (lambda * kappa - det * T::splat(0.125));
    let mut r = [[T::splat(0.0); 3]; 3];
    for i in 0..3 {
        for k in 0..3 {
            let bbtb = bbt[i][0] * b[0][k] + bbt[i][1] * b[1][k] + bbt[i][2] * b[2][k];
            r[i][k] = ((kappa + norm) * b[i][k] + lambda * cof[i][k] - bbtb) * inv;
        }
    }
    r
}

/// The rotation matrix of a unit quaternion `(w, x, y, z)`.
#[inline(always)]
pub fn matrix<T: Lane>(q: &[T; 4]) -> [[T; 3]; 3] {
    let [w, x, y, z] = *q;
    let two = T::splat(2.0);
    let one = T::splat(1.0);
    [
        [one - two * (y * y + z * z), two * (x * y - w * z), two * (x * z + w * y)],
        [two * (x * y + w * z), one - two * (x * x + z * z), two * (y * z - w * x)],
        [two * (x * z - w * y), two * (y * z + w * x), one - two * (x * x + y * y)],
    ]
}

/// The rotation matrix of [`rotor`], for one problem given as a nalgebra matrix.
pub fn rotor_matrix(m: &Matrix3<f64>, h: f64) -> Matrix3<f64> {
    let b = [0, 1, 2].map(|r| [0, 1, 2].map(|c| m[(r, c)]));
    let r = matrix(&rotor(&b, h));
    Matrix3::from_fn(|i, k| r[i][k])
}

/// [`foam`] for one problem given as a nalgebra matrix.
pub fn foam_matrix(m: &Matrix3<f64>, h: f64) -> Matrix3<f64> {
    let b = [0, 1, 2].map(|r| [0, 1, 2].map(|c| m[(r, c)]));
    let r = foam(&b, h);
    Matrix3::from_fn(|i, k| r[i][k])
}

/// Four problems in the lanes of `f64x4`: gathers the matrices, solves, and scatters the rotations back.
#[inline(always)]
fn four(ms: [&Matrix3<f64>; 4], h: [f64; 4], solve: impl Fn(&[[f64x4; 3]; 3], f64x4) -> [[f64x4; 3]; 3]) -> [Matrix3<f64>; 4] {
    let b = [0, 1, 2].map(|r| [0, 1, 2].map(|c| f64x4::new(ms.map(|m| m[(r, c)]))));
    let r = solve(&b, f64x4::new(h)).map(|row| row.map(|v| v.to_array()));
    [0, 1, 2, 3].map(|l| Matrix3::from_fn(|i, k| r[i][k][l]))
}

/// [`rotor_matrix`] for four problems at once, in SIMD lanes.
pub fn rotor_matrix4(ms: [&Matrix3<f64>; 4], h: [f64; 4]) -> [Matrix3<f64>; 4] {
    four(ms, h, |b, h| matrix(&rotor(b, h)))
}

/// [`foam_matrix`] for four problems at once, in SIMD lanes.
pub fn foam_matrix4(ms: [&Matrix3<f64>; 4], h: [f64; 4]) -> [Matrix3<f64>; 4] {
    four(ms, h, |b, h| foam(b, h))
}

#[cfg(test)]
mod tests {
    use super::*;
    use nalgebra::{UnitQuaternion, Vector3};

    fn svd_rotation(m: &Matrix3<f64>) -> Matrix3<f64> {
        let svd = m.svd(true, true);
        let (u, v_t) = (svd.u.unwrap(), svd.v_t.unwrap());
        let mut d = Matrix3::identity();
        if (u * v_t).determinant() < 0.0 {
            d[(2, 2)] = -1.0;
        }
        u * d * v_t
    }

    fn random_problem(seed: u64) -> ([[f64; 3]; 3], f64, Matrix3<f64>) {
        // a deterministic generator, enough for tests
        let mut s = seed.wrapping_mul(6364136223846793005).wrapping_add(1442695040888963407);
        let mut next = || {
            s = s.wrapping_mul(6364136223846793005).wrapping_add(1442695040888963407);
            ((s >> 11) as f64 / (1u64 << 53) as f64) * 2.0 - 1.0
        };
        let rot = UnitQuaternion::from_scaled_axis(Vector3::new(next(), next(), next()) * 3.0);
        let mut m = Matrix3::zeros();
        let mut h = 0.0;
        for _ in 0..6 {
            let s = Vector3::new(next(), next(), next());
            let t = rot * s + Vector3::new(next(), next(), next()) * 0.1;
            let w = next();
            m += t * s.transpose() * w;
            h += w.abs() * (s.norm_squared() + t.norm_squared()) / 2.0;
        }
        let b = [0, 1, 2].map(|i| [0, 1, 2].map(|k| m[(i, k)]));
        (b, h, m)
    }

    #[test]
    fn rotor_and_foam_match_the_svd() {
        for seed in 0..2000 {
            let (b, h, m) = random_problem(seed);
            let reference = svd_rotation(&m);
            let r = matrix(&rotor(&b, h));
            let f = foam(&b, h);
            for i in 0..3 {
                for k in 0..3 {
                    assert!((r[i][k] - reference[(i, k)]).abs() < 1e-9, "rotor, seed {seed}");
                    assert!((f[i][k] - reference[(i, k)]).abs() < 1e-7, "foam, seed {seed}");
                }
            }
        }
    }

    #[test]
    fn four_lanes_match_one_lane() {
        for seed in (0..400).step_by(4) {
            let problems: Vec<_> = (0..4).map(|l| random_problem(seed + l)).collect();
            let b = [0, 1, 2].map(|i| [0, 1, 2].map(|k| f64x4::new([0, 1, 2, 3].map(|l| problems[l].0[i][k]))));
            let h = f64x4::new([0, 1, 2, 3].map(|l| problems[l].1));
            let q4 = rotor(&b, h);
            for (l, p) in problems.iter().enumerate() {
                let q1 = rotor(&p.0, p.1);
                for c in 0..4 {
                    // lanes may take more Newton steps than a single problem would
                    assert!((q4[c].to_array()[l] - q1[c]).abs() < 1e-10);
                }
            }
        }
    }
}
