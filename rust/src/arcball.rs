//! Arcball camera rotation (Shoemake, with Bell's hyperbolic sheet outside the ball).
//!
//! Dragging inside the ball tumbles the scene freely; dragging near the window edge rolls it about the view axis,
//! like the C++ viewer. The scene stays put and the camera orbits the target the opposite way.

use three_d::*;

#[derive(Default)]
pub struct Arcball {
    /// Last point on the ball, in view coordinates (x right, y up, z towards the viewer).
    last: Option<Vec3>,
}

impl Arcball {
    pub fn begin(&mut self, camera: &Camera, pixel: PhysicalPoint) {
        self.last = Some(ball_point(camera, pixel));
    }

    pub fn end(&mut self) {
        self.last = None;
    }

    pub fn is_active(&self) -> bool {
        self.last.is_some()
    }

    /// Rotates the camera about `target` so the scene follows the cursor from the previous point to `pixel`.
    pub fn drag(&mut self, camera: &mut Camera, target: Vec3, pixel: PhysicalPoint) {
        let Some(from) = self.last else { return };
        let to = ball_point(camera, pixel);
        self.last = Some(to);

        let axis_view = from.cross(to);
        if axis_view.magnitude() < 1e-7 {
            return;
        }
        let angle = from.dot(to).clamp(-1.0, 1.0).acos();
        // View axes in world space.
        let right = camera.right_direction().normalize();
        let up = camera.up_orthogonal().normalize();
        let back = -camera.view_direction().normalize();
        let axis = (right * axis_view.x + up * axis_view.y + back * axis_view.z).normalize();
        // Turning the scene by `angle` about `axis` is turning the camera by `-angle`.
        let rotation = Mat3::from_axis_angle(axis, radians(-angle));
        let position = target + rotation * (camera.position() - target);
        let new_up = rotation * up;
        camera.set_view(position, target, new_up);
    }
}

/// Maps a pixel to a unit vector on the arcball, which fills 90% of the shorter window side.
fn ball_point(camera: &Camera, pixel: PhysicalPoint) -> Vec3 {
    let viewport = camera.viewport();
    let radius = 0.45 * viewport.width.min(viewport.height) as f32;
    let x = (pixel.x - (viewport.x as f32 + viewport.width as f32 / 2.0)) / radius;
    let y = (pixel.y - (viewport.y as f32 + viewport.height as f32 / 2.0)) / radius;
    let d2 = x * x + y * y;
    // Sphere near the centre, hyperbolic sheet outside so the mapping stays smooth up to the edges.
    let z = if d2 <= 0.5 { (1.0 - d2).sqrt() } else { 0.5 / d2.sqrt() };
    vec3(x, y, z).normalize()
}
