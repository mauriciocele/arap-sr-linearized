//! Scenes shared by the experiments and the figure renderer.

use std::path::{Path, PathBuf};

use nalgebra::{UnitQuaternion, Vector3};

use crate::deformer::Deformer;
use crate::handle::Handle;
use crate::mesh::{Mesh, Vec3};

/// The OBJ models shipped with the C++ project.
pub fn models() -> PathBuf {
    Path::new(env!("CARGO_MANIFEST_DIR")).join("../src")
}

pub fn load(name: &str) -> Mesh {
    Mesh::read_obj(&models().join(name)).unwrap_or_else(|e| panic!("{e}"))
}

/// The bar benchmark: a tube along y with a handle over each end.
pub fn tube_scene(rings: usize, segments: usize) -> (Mesh, Vec<Handle>) {
    let mesh = Mesh::tube(rings, segments, 4.0, 0.25);
    let (ymin, ymax) = y_range(&mesh);
    let radius = mesh.positions.iter().map(|p| p.x.hypot(p.z)).fold(0.0, f64::max);
    let reach = 1.05 * radius.hypot(0.1 * (ymax - ymin));
    let bottom = Handle::new(Vec3::new(0.0, ymin, 0.0), reach);
    let top = Handle::new(Vec3::new(0.0, ymax, 0.0), reach);
    (mesh, vec![bottom, top])
}

pub fn y_range(mesh: &Mesh) -> (f64, f64) {
    mesh.positions.iter().fold((f64::MAX, f64::MIN), |(a, b), p| (a.min(p.y), b.max(p.y)))
}

pub fn tube_length(mesh: &Mesh) -> f64 {
    let (ymin, ymax) = y_range(mesh);
    ymax - ymin
}

/// Bends the top of the tube by 60 degrees towards -x.
pub fn bend(top: &mut Handle, length: f64) {
    top.rotation = UnitQuaternion::from_axis_angle(&Vector3::z_axis(), 60f64.to_radians());
    top.translation = Vec3::new(-0.35 * length, -0.12 * length, 0.0);
}

/// Bends the tube into a circular arc that turns by `degrees` towards -x, keeping its length: the top handle is
/// rotated by the arc angle and moved to the end of the arc.
pub fn arc(top: &mut Handle, length: f64, degrees: f64) {
    let phi = degrees.to_radians();
    let radius = length / phi;
    top.rotation = UnitQuaternion::from_axis_angle(&Vector3::z_axis(), phi);
    top.translation = Vec3::new(-radius * (1.0 - phi.cos()), radius * phi.sin() - length, 0.0);
}

/// Twists the top of the tube by `degrees` about the tube axis.
pub fn twist(top: &mut Handle, degrees: f64) {
    top.rotation = UnitQuaternion::from_axis_angle(&Vector3::y_axis(), degrees.to_radians());
}

/// The six armadillo handles of the C++ project: hands 0 and 2, feet 1 and 3, head 4, hip 5.
pub fn armadillo_handles() -> Vec<Handle> {
    let sphere = |x, y, z| Handle::new(Vec3::new(x, y, z), 0.15);
    vec![
        sphere(-0.5, 0.45, -0.3),
        sphere(0.2, -0.6, 0.1),
        sphere(0.45, 0.45, -0.3),
        sphere(-0.3, -0.6, 0.1),
        sphere(0.0, 0.4, -0.2),
        sphere(0.0, -0.05, 0.1),
    ]
}

/// Both hands up and forward, the head turned.
pub fn raise_arms(d: &mut Deformer) {
    d.handles[0].translation = Vec3::new(-0.15, 0.3, -0.25);
    d.handles[2].translation = Vec3::new(0.15, 0.3, -0.25);
    d.handles[4].rotation = UnitQuaternion::from_axis_angle(&Vector3::y_axis(), 35f64.to_radians());
}

fn rot(axis: Vector3<f64>, degrees: f64) -> UnitQuaternion<f64> {
    UnitQuaternion::from_axis_angle(&nalgebra::Unit::new_normalize(axis), degrees.to_radians())
}

/// The armadillo poses of the figures, from the rest pose: 1 reaching, 2 victory, 3 kick.
pub fn armadillo_pose(d: &mut Deformer, which: usize) {
    for h in &mut d.handles {
        h.rotation = UnitQuaternion::identity();
        h.translation = Vec3::zeros();
    }
    if which == 1 {
        raise_arms(d);
        return;
    }
    let hs = &mut d.handles;
    match which {
        // Both hands high above the head, head up.
        2 => {
            hs[0].translation = Vec3::new(0.12, 0.42, 0.18);
            hs[0].rotation = rot(Vector3::z(), -35.0);
            hs[2].translation = Vec3::new(-0.12, 0.42, 0.18);
            hs[2].rotation = rot(Vector3::z(), 35.0);
            hs[4].rotation = rot(Vector3::x(), -25.0);
        }
        // One foot up and forward, arms swung back for balance, hip and head turned.
        3 => {
            hs[1].translation = Vec3::new(0.05, 0.38, -0.32);
            hs[1].rotation = rot(Vector3::x(), -55.0);
            hs[0].translation = Vec3::new(-0.05, -0.12, 0.3);
            hs[2].translation = Vec3::new(0.05, 0.1, 0.25);
            hs[5].rotation = rot(Vector3::y(), -15.0);
            hs[4].rotation = rot(Vector3::y(), 30.0);
        }
        _ => {}
    }
}
