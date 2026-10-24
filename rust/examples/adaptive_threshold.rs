//! Sensitivity of the adaptive rule for constrained cells to its threshold: iterations until the energy stays
//! within 1% of its final value, and the final energy, on the twisted bar and the 90-degree arc.
//!
//! `cargo run --release --example adaptive_threshold`
use arap::deformer::{ConstrainedRule, Deformer, LocalStep};
use arap::scenes::{arc, tube_length, tube_scene, twist};

fn main() {
    for scene in ["twist180", "arc90"] {
        for threshold in [45u32, 60, 90, 120, 150] {
            let (mesh, handles) = tube_scene(81, 96);
            let length = tube_length(&mesh);
            let mut d = Deformer::control_only(mesh, handles);
            if scene == "arc90" { arc(&mut d.handles[1], length, 90.0) } else { twist(&mut d.handles[1], 180.0) }
            d.local_step = LocalStep::Pcg;
            d.constrained_rule = ConstrainedRule::Adaptive { threshold_deg: threshold };
            let energies: Vec<f64> = (0..1500).map(|_| { d.iterate(); d.energy() }).collect();
            let last = *energies.last().unwrap();
            let settled = (0..energies.len()).find(|&k| energies[k..].iter().all(|e| (e - last).abs() / last < 0.01)).unwrap() + 1;
            println!("{scene:9} threshold {threshold:3} deg: within 1% from iteration {settled:4}, final energy {last:.4}");
        }
    }
}
