//! Diagnostics for the SR-ARAP cell fits on the bent bar: how tight the Newton start is, how many Newton steps the
//! cells need, and the time of the rotor fit one cell at a time and four at a time.
//!
//! `cargo run --release --example srarap_newton_steps`
use arap::deformer::{Deformer, Fit, LocalStep};
use arap::scenes::{tube_scene, tube_length, arc};
fn main() {
    let (mesh, handles) = tube_scene(161, 192);
    let length = tube_length(&mesh);
    let mut d = Deformer::control_only(mesh, handles);
    arc(&mut d.handles[1], length, 90.0);
    d.local_step = LocalStep::SrArap { sweeps: 3 };
    d.fit = Fit::ColoredSvd;
    for _ in 0..5 { d.iterate(); }
    let (ms, hs) = d.sr_arap_cell_problems();
    let mut hist = [0usize; 40];
    let mut ratio_sum = 0.0;
    for (m, &h) in ms.iter().zip(&hs) {
        let sv = m.svd(false, false).singular_values;
        let mut s = [sv[0], sv[1], sv[2]];
        if m.determinant() < 0.0 { s[2] = -s[2]; }
        let mu0 = s[0] + s[1] + s[2];
        ratio_sum += h / mu0;
        let b = m;
        let sq: f64 = b.iter().map(|v| v * v).sum();
        let a = -2.0 * sq; let c1 = -8.0 * b.determinant();
        // c0 = det K
        let tr = b.trace();
        let z = [b[(2,1)]-b[(1,2)], b[(0,2)]-b[(2,0)], b[(1,0)]-b[(0,1)]];
        let mut k = nalgebra::Matrix4::zeros();
        k[(0,0)] = tr; for i in 0..3 { k[(0,i+1)] = z[i]; k[(i+1,0)] = z[i]; for j in 0..3 { k[(i+1,j+1)] = b[(i,j)] + b[(j,i)] - if i==j {tr} else {0.0}; } }
        let c0 = k.determinant();
        let mut mu = h; let mut it = 0;
        loop { let mu2 = mu*mu; let st = ((mu2 + a)*mu2 + c1*mu + c0)/((4.0*mu2 + 2.0*a)*mu + c1); mu -= st; it += 1; if st.abs() <= 1e-7*h || it >= 39 { break; } }
        hist[it] += 1;
    }
    println!("mean h/mu0 = {:.4}", ratio_sum / ms.len() as f64);
    for (i, c) in hist.iter().enumerate() { if *c > 0 { println!("{i} steps: {c}"); } }
    use arap::procrustes::{rotor, matrix};
    use wide::f64x4;
    use std::time::Instant;
    let n = ms.len() / 4 * 4;
    let mut out = vec![nalgebra::Matrix3::<f64>::zeros(); n];
    for _ in 0..3 {
        let t = Instant::now();
        for _ in 0..50 { for i in 0..n {
            let b = [0, 1, 2].map(|r| [0, 1, 2].map(|k| ms[i][(r, k)]));
            let rm = matrix(&rotor(&b, hs[i]));
            out[i] = nalgebra::Matrix3::from_fn(|r, k| rm[r][k]);
        } std::hint::black_box(&mut out); }
        let g1 = t.elapsed().as_secs_f64()*1e9/(50.0*n as f64);
        let t = Instant::now();
        for _ in 0..50 { for c in (0..n).step_by(4) {
            let idx = [c, c+1, c+2, c+3];
            let b = [0, 1, 2].map(|r| [0, 1, 2].map(|k| f64x4::new(idx.map(|i| ms[i][(r, k)]))));
            let h = f64x4::new(idx.map(|i| hs[i]));
            let rm = matrix(&rotor(&b, h)).map(|row| row.map(|v| v.to_array()));
            for (l, &i) in idx.iter().enumerate() { out[i] = nalgebra::Matrix3::from_fn(|r, k| rm[r][k][l]); }
        } std::hint::black_box(&mut out); }
        let g4 = t.elapsed().as_secs_f64()*1e9/(50.0*n as f64);
        let t = Instant::now();
        for _ in 0..50 { for c in (0..n).step_by(4) {
            let r = arap::procrustes::rotor_matrix4([&ms[c], &ms[c+1], &ms[c+2], &ms[c+3]], [hs[c], hs[c+1], hs[c+2], hs[c+3]]);
            for l in 0..4 { out[c+l] = r[l]; }
        } std::hint::black_box(&mut out); }
        let l4 = t.elapsed().as_secs_f64()*1e9/(50.0*n as f64);
        let t = Instant::now();
        for _ in 0..50 { for i in 0..n { out[i] = arap::procrustes::rotor_matrix(&ms[i], hs[i]); } std::hint::black_box(&mut out); }
        let l1 = t.elapsed().as_secs_f64()*1e9/(50.0*n as f64);
        println!("ARAP problems: scalar {g1:.1} ns, x4 {g4:.1} ns; lib fns: scalar {l1:.1}, x4 {l4:.1}");
    }
}
