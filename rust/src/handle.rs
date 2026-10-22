//! Deformation handles. Replaces the conformal geometric algebra `Handle` of `Flatten.cpp`.
//!
//! In the C++ code a handle is a dual sphere plus a motor `T * (Tc R ~Tc)`: rotate by `R` about the sphere's rest
//! centre, then translate by `T`. Here that motor is a quaternion and a translation vector.

use nalgebra::UnitQuaternion;

use crate::mesh::Vec3;

#[derive(Clone, Debug)]
pub struct Handle {
    /// Sphere centre in the rest pose.
    pub rest_center: Vec3,
    pub radius: f64,
    pub rotation: UnitQuaternion<f64>,
    pub translation: Vec3,
    /// Control-mesh vertices this handle drives.
    pub constraints: Vec<usize>,
}

impl Handle {
    pub fn new(center: Vec3, radius: f64) -> Self {
        Handle {
            rest_center: center,
            radius,
            rotation: UnitQuaternion::identity(),
            translation: Vec3::zeros(),
            constraints: Vec::new(),
        }
    }

    /// Image of a rest-pose point under the handle's motor.
    pub fn transform(&self, p: &Vec3) -> Vec3 {
        self.rotation * (p - self.rest_center) + self.rest_center + self.translation
    }

    /// Where the sphere is drawn and picked.
    pub fn center(&self) -> Vec3 {
        self.rest_center + self.translation
    }

    /// Strictly inside the rest-pose sphere, the C++ `x . S > 0` test.
    pub fn contains_rest(&self, p: &Vec3) -> bool {
        (p - self.rest_center).norm_squared() < self.radius * self.radius
    }

    /// Distance along the ray `origin + t * direction` (unit direction) to the sphere's surface, if it is hit.
    pub fn ray_hit(&self, origin: &Vec3, direction: &Vec3) -> Option<f64> {
        let oc = origin - self.center();
        let b = oc.dot(direction);
        let c = oc.norm_squared() - self.radius * self.radius;
        let disc = b * b - c;
        if disc < 0.0 {
            return None;
        }
        let sqrt = disc.sqrt();
        [-b - sqrt, -b + sqrt].into_iter().find(|&t| t >= 0.0)
    }
}
