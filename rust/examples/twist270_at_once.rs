//! A 270-degree twist set at once, with the cell equation alone and with the adaptive rule at several thresholds:
//! the twist angle of the top tenth of the bar after 1,000 iterations, and the handle cells' pull angles at the
//! first local step.
//!
//! `cargo run --release --example twist270_at_once`
use arap::deformer::{ConstrainedRule, Deformer};
use arap::scenes::{tube_scene, twist};

fn main() {
    for (name, rule) in [
        ("cell equation", ConstrainedRule::Smoothed),
        ("adaptive 80", ConstrainedRule::Adaptive { threshold_deg: 80 }),
        ("adaptive 89", ConstrainedRule::Adaptive { threshold_deg: 89 }),
        ("adaptive 90", ConstrainedRule::Adaptive { threshold_deg: 90 }),
        ("adaptive 91", ConstrainedRule::Adaptive { threshold_deg: 91 }),
        ("adaptive 100", ConstrainedRule::Adaptive { threshold_deg: 100 }),
    ] {
        let (mesh, handles) = tube_scene(81, 96);
        let mut d = Deformer::control_only(mesh, handles);
        twist(&mut d.handles[1], 270.0);
        d.constrained_rule = rule;
        d.global();
        let pulls: Vec<f64> = d.handle_cell_statistics().iter().map(|s| s.0).collect();
        let (lo, hi) = pulls.iter().fold((f64::MAX, f64::MIN), |(a, b), &p| (a.min(p), b.max(p)));
        for _ in 0..1000 {
            d.iterate();
        }
        let (ymin, ymax) = d.low.positions.iter().fold((f64::MAX, f64::MIN), |(a, b), p| (a.min(p.y), b.max(p.y)));
        let (mut sum, mut count) = (0.0, 0.0);
        for (i, p) in d.low.positions.iter().enumerate() {
            if (p.y - ymin) / (ymax - ymin) >= 0.9 {
                let q = d.low_rotations()[i];
                sum += 2.0 * q.j.atan2(q.w).to_degrees();
                count += 1.0;
            }
        }
        println!("{name:14} first-step pull angles {lo:.2}..{hi:.2} deg; top-tenth twist after 1000 iterations {:.0} deg", sum / count);
    }
}
