//! Interactive ARAP-SR mesh deformation with linearized rotations. Port of `Flatten.cpp` to Rust and three-d.
//!
//! Mouse:
//! - left-drag a sphere: move it (drag and drop, in the plane facing the camera)
//! - right-drag a sphere, or shift + left-drag: rotate it about its centre
//! - left-drag the background: arcball rotation (free tumble inside, roll near the edge); wheel or pinch: zoom
//! - click a sphere to select it; Up / Down change the selected sphere's radius
//!
//! Keys: W wireframe, H handles, X iterate (100 times, or until converged in convergence mode), C convergence mode,
//! A animate the first handle.

mod arcball;

use std::path::{Path, PathBuf};
use std::time::Instant;

use three_d::egui;
use three_d::*;

use arap::deformer::{Deformer, Fit, LocalStep};
use arap::handle::Handle;
use arap::mesh::{Mesh, Vec3 as DVec3};

use crate::arcball::Arcball;

const WINDOW_TITLE: &str = "Interactive 3D Shape Deformation using Conformal Geometric Algebra";
/// Radians of handle rotation per logical pixel of mouse motion (`2 * rotateVel` in the C++ code).
const ROTATE_SPEED: f64 = 0.01;
/// Translation per animation frame (`2 * translateVel` in the C++ code).
const ANIMATION_STEP: f64 = 0.01;
const RADIUS_STEP: f64 = 0.025;

struct Scene {
    high: PathBuf,
    low: PathBuf,
    handles: Vec<Handle>,
    /// `--srarap FIT`: use the SR-ARAP local step (3 Gauss-Seidel sweeps) with this per-cell fit.
    fit: Option<Fit>,
    /// `--arap FIT`: plain ARAP (no bending), each cell fitted on its own.
    plain: bool,
}

fn main() {
    let scene = match parse_args() {
        Ok(scene) => scene,
        Err(message) => {
            eprintln!("{message}\n\n{}", usage());
            std::process::exit(2);
        }
    };
    let high = Mesh::read_obj(&scene.high).unwrap_or_else(|e| fail(&e));
    let low = Mesh::read_obj(&scene.low).unwrap_or_else(|e| fail(&e));
    let mut deformer = Deformer::new(high, low, scene.handles);
    if let Some(fit) = scene.fit {
        deformer.local_step = if scene.plain { LocalStep::Arap } else { LocalStep::SrArap { sweeps: 3 } };
        deformer.fit = fit;
        println!("{} local step, fit {fit:?}", if scene.plain { "plain ARAP" } else { "SR-ARAP (3 Gauss-Seidel sweeps)" });
    }
    for (k, handle) in deformer.handles.iter().enumerate() {
        println!("handle {k}: {} control vertices", handle.constraints.len());
    }
    deformer.step();
    run(deformer);
}

fn fail(message: &str) -> ! {
    eprintln!("{message}");
    std::process::exit(1);
}

fn usage() -> String {
    "usage: arap [cactus|armadillo] [--data DIR] [--srarap FIT | --arap FIT]\n       \
     arap --high HIGH.obj --low LOW.obj --handle X,Y,Z,R [--handle X,Y,Z,R ...] [--srarap FIT]\n\n\
     --srarap FIT: the SR-ARAP local step of Levi and Gotsman, each cell fitted by FIT, one of svd, colored-svd,\n\
     rotor, rotor-simd, foam, foam-simd (rotor = the geometric-algebra rotor estimator).\n\
     --arap FIT: plain ARAP (no bending), each cell's rotation fitted on its own by FIT.\n\
     Handle centres are in the normalised frame: each mesh is centred and scaled to a bounding-box half-diagonal of 1."
        .to_string()
}

fn parse_args() -> Result<Scene, String> {
    let mut preset = None;
    let mut data = PathBuf::from(concat!(env!("CARGO_MANIFEST_DIR"), "/../src"));
    let mut high = None;
    let mut low = None;
    let mut handles = Vec::new();
    let mut fit = None;
    let mut plain = false;
    let mut args = std::env::args().skip(1);
    while let Some(arg) = args.next() {
        let mut value = |name: &str| args.next().ok_or_else(|| format!("{name} needs a value"));
        match arg.as_str() {
            "--data" => data = PathBuf::from(value("--data")?),
            "--high" => high = Some(PathBuf::from(value("--high")?)),
            "--low" => low = Some(PathBuf::from(value("--low")?)),
            "--handle" => {
                let spec = value("--handle")?;
                let v: Vec<f64> = spec
                    .split(',')
                    .map(|s| s.trim().parse().map_err(|_| format!("bad --handle {spec}")))
                    .collect::<Result<_, _>>()?;
                let [x, y, z, r] = v[..] else {
                    return Err(format!("--handle expects X,Y,Z,R, got {spec}"));
                };
                handles.push(Handle::new(DVec3::new(x, y, z), r));
            }
            "--arap" => {
                let name = value("--arap")?;
                fit = Some(Fit::parse(&name).ok_or_else(|| format!("unknown fit {name}"))?);
                plain = true;
            }
            "--srarap" => {
                let name = value("--srarap")?;
                fit = Some(Fit::parse(&name).ok_or_else(|| format!("unknown fit {name}"))?);
            }
            // Read in `run`.
            "--animate" => {}
            "-h" | "--help" => {
                println!("{}", usage());
                std::process::exit(0);
            }
            name if !name.starts_with('-') && preset.is_none() => preset = Some(name.to_string()),
            other => return Err(format!("unknown argument {other}")),
        }
    }
    match (high, low) {
        (Some(high), Some(low)) => {
            if handles.is_empty() {
                return Err("at least one --handle is required with --high/--low".into());
            }
            Ok(Scene { high, low, handles, fit, plain })
        }
        (None, None) => preset_scene(preset.as_deref().unwrap_or("cactus"), &data, handles).map(|s| Scene { fit, plain, ..s }),
        _ => Err("--high and --low must be given together".into()),
    }
}

/// The scenes hard-coded (or commented out) in `Flatten.cpp`.
fn preset_scene(name: &str, data: &Path, extra: Vec<Handle>) -> Result<Scene, String> {
    let sphere = |x, y, z| Handle::new(DVec3::new(x, y, z), 0.15);
    let (high, low, mut handles) = match name {
        "cactus" => ("cactus2.obj", "cactus1.obj", vec![sphere(0.0, 0.04, 0.7), sphere(0.0, 0.04, -0.8)]),
        "armadillo" => (
            "armadillo.obj",
            "armadillo1.obj",
            vec![
                sphere(-0.5, 0.45, -0.3), // hand
                sphere(0.2, -0.6, 0.1),   // foot
                sphere(0.45, 0.45, -0.3), // hand
                sphere(-0.3, -0.6, 0.1),  // foot
                sphere(0.0, 0.4, -0.2),   // head
                sphere(0.0, -0.05, 0.1),  // hip
            ],
        ),
        other => return Err(format!("unknown scene {other}; expected cactus or armadillo")),
    };
    handles.extend(extra);
    Ok(Scene { high: data.join(high), low: data.join(low), handles, fit: None, plain: false })
}

enum Drag {
    None,
    /// Moves the handle with the cursor in the plane through `anchor` facing the camera.
    Move { handle: usize, anchor: Vec3, normal: Vec3 },
    Rotate { handle: usize },
}

fn run(mut deformer: Deformer) {
    let window = Window::new(WindowSettings {
        title: WINDOW_TITLE.to_string(),
        initial_size: Some((1024, 768)),
        ..Default::default()
    })
    .unwrap_or_else(|e| fail(&format!("cannot open window: {e}")));
    let context = window.gl();

    // Same view as the C++ camera: from (0, 0, -2) towards +z, y up, 60 degree vertical field of view.
    let mut camera = Camera::new_perspective(
        window.viewport(),
        vec3(0.0, 0.0, -2.0),
        vec3(0.0, 0.0, 0.0),
        vec3(0.0, 1.0, 0.0),
        degrees(60.0),
        0.1,
        1000.0,
    );
    let target = vec3(0.0, 0.0, 0.0);
    let mut arcball = Arcball::default();
    // Only zooms: the arcball consumes left-button drags before it sees them.
    let mut zoom = OrbitControl::new(target, 0.3, 50.0);

    let indices: Vec<u32> = deformer.high.faces.iter().flatten().map(|&i| i as u32).collect();
    let cpu_mesh = CpuMesh {
        positions: Positions::F32(to_f32(&deformer.high_positions)),
        normals: Some(to_f32(&deformer.high_normals)),
        indices: Indices::U32(indices),
        ..Default::default()
    };
    let mut model = Gm::new(
        three_d::Mesh::new(&context, &cpu_mesh),
        PhysicalMaterial::new_opaque(
            &context,
            &CpuMaterial { albedo: Srgba::new(235, 235, 235, 255), roughness: 0.5, metallic: 0.0, ..Default::default() },
        ),
    );
    let unit_sphere = CpuMesh::sphere(32);
    let sphere_material = |color: Srgba| {
        PhysicalMaterial::new_transparent(
            &context,
            &CpuMaterial { albedo: color, roughness: 0.3, metallic: 0.0, ..Default::default() },
        )
    };
    let turquoise = Srgba::new(0, 128, 128, 77);
    let red = Srgba::new(160, 0, 0, 90);
    let mut spheres: Vec<_> = deformer
        .handles
        .iter()
        .map(|_| Gm::new(three_d::Mesh::new(&context, &unit_sphere), sphere_material(turquoise)))
        .collect();
    let mut wireframe: Option<Wireframe> = None;

    let ambient = AmbientLight::new(&context, 0.35, Srgba::WHITE);
    let mut light = DirectionalLight::new(&context, 1.8, Srgba::WHITE, vec3(0.0, 0.0, 1.0));
    let mut gui = GUI::new(&context);

    let mut drag = Drag::None;
    let mut selected: Option<usize> = None;
    let mut show_wires = false;
    let mut show_handles = true;
    let mut convergence = false;
    let mut animate = std::env::args().any(|a| a == "--animate");
    // ARAP_PROFILE=1 prints frame and solve times every 120 frames.
    let profile = std::env::var_os("ARAP_PROFILE").is_some();
    let mut stats = (0u32, 0.0f64, 0.0f64, 0.0f64);
    let mut animation = (0i32, 1.0f64);
    let mut mesh_dirty = false;
    let mut solve_time = 0.0f64;

    window.render_loop(move |mut frame_input| {
        let frame_start = Instant::now();
        let mut solved = 0.0;
        camera.set_viewport(frame_input.viewport);

        let mut iterate = false;
        let mut toggle_convergence = false;
        let mut toggle_animation = false;
        let mut radius_delta = 0.0;
        gui.update(
            &mut frame_input.events,
            frame_input.accumulated_time,
            frame_input.viewport,
            frame_input.device_pixel_ratio,
            |ui| {
                egui::Window::new("ARAP-SR").default_width(230.0).show(ui.ctx(), |ui| {
                    ui.label("Left-drag sphere: move");
                    ui.label("Right / shift-drag sphere: rotate");
                    ui.label("Left-drag background: arcball, wheel: zoom");
                    ui.separator();
                    ui.checkbox(&mut show_wires, "Wireframe (W)");
                    ui.checkbox(&mut show_handles, "Handles (H)");
                    let (mut c, mut a) = (convergence, animate);
                    toggle_convergence = ui.checkbox(&mut c, "Convergence mode (C)").changed();
                    toggle_animation = ui.checkbox(&mut a, "Animate handle 0 (A)").changed();
                    iterate = ui.button("Iterate (X)").clicked();
                    if let Some(k) = selected {
                        ui.separator();
                        ui.label(format!("Handle {k}: radius {:.3}", deformer.handles[k].radius));
                        ui.horizontal(|ui| {
                            if ui.button("-").clicked() {
                                radius_delta = -RADIUS_STEP;
                            }
                            if ui.button("+").clicked() {
                                radius_delta = RADIUS_STEP;
                            }
                        });
                    }
                    ui.separator();
                    ui.label(format!("Solve: {:.1} ms/frame", solve_time * 1e3));
                });
            },
        );

        for event in frame_input.events.iter_mut() {
            match event {
                Event::MousePress { button, position, modifiers, handled } if !*handled => {
                    let origin = camera.position_at_pixel(*position);
                    let direction = camera.view_direction_at_pixel(*position).normalize();
                    let hit = if show_handles { pick(&deformer.handles, origin, direction) } else { None };
                    if let Some((k, t)) = hit {
                        selected = Some(k);
                        drag = if *button == MouseButton::Right || modifiers.shift {
                            Drag::Rotate { handle: k }
                        } else {
                            Drag::Move { handle: k, anchor: origin + direction * t as f32, normal: camera.view_direction() }
                        };
                        *handled = true;
                    } else if *button == MouseButton::Left {
                        arcball.begin(&camera, *position);
                        *handled = true;
                    }
                }
                Event::MouseMotion { delta, position, handled, .. } if !*handled => match drag {
                    Drag::Move { handle, ref mut anchor, normal } => {
                        let origin = camera.position_at_pixel(*position);
                        let direction = camera.view_direction_at_pixel(*position);
                        let denominator = direction.dot(normal);
                        if denominator.abs() > 1e-6 {
                            let point = origin + direction * ((*anchor - origin).dot(normal) / denominator);
                            deformer.handles[handle].translation += to_f64(point - *anchor);
                            *anchor = point;
                        }
                        *handled = true;
                    }
                    Drag::Rotate { handle } => {
                        // Turns the side facing the camera in the direction of the drag.
                        let motion = camera.right_direction() * delta.0 - camera.up_orthogonal() * delta.1;
                        let axis = (-camera.view_direction()).cross(motion);
                        if axis.magnitude() > 1e-6 {
                            let angle = ROTATE_SPEED * f64::from(delta.0.hypot(delta.1));
                            let rotation = nalgebra::UnitQuaternion::from_axis_angle(
                                &nalgebra::Unit::new_normalize(to_f64(axis)),
                                angle,
                            );
                            let h = &mut deformer.handles[handle];
                            h.rotation = rotation * h.rotation;
                        }
                        *handled = true;
                    }
                    Drag::None => {
                        if arcball.is_active() {
                            arcball.drag(&mut camera, target, *position);
                            *handled = true;
                        }
                    }
                },
                Event::MouseRelease { handled, .. } => {
                    arcball.end();
                    if !matches!(drag, Drag::None) {
                        drag = Drag::None;
                        *handled = true;
                    }
                }
                Event::KeyPress { kind, handled, .. } if !*handled => {
                    match kind {
                        Key::W => show_wires = !show_wires,
                        Key::H => show_handles = !show_handles,
                        Key::X => iterate = true,
                        Key::C => toggle_convergence = true,
                        Key::A => toggle_animation = true,
                        Key::ArrowUp => radius_delta = RADIUS_STEP,
                        Key::ArrowDown => radius_delta = -RADIUS_STEP,
                        _ => continue,
                    }
                    *handled = true;
                }
                _ => {}
            }
        }
        zoom.handle_events(&mut camera, &mut frame_input.events);

        if toggle_convergence {
            // As in the C++ code, toggling also applies the fixed benchmark displacement to the first handle.
            convergence = !convergence;
            if let Some(h) = deformer.handles.first_mut() {
                h.translation += DVec3::new(-0.7, -0.6, 0.0);
            }
            iterate_or_step(&mut deformer, &mut solve_time, None);
            solved += solve_time * 1e3;
            mesh_dirty = true;
        }
        if toggle_animation {
            animate = !animate;
        }
        if let (Some(k), true) = (selected, radius_delta != 0.0) {
            let h = &mut deformer.handles[k];
            h.radius = (h.radius + radius_delta).max(RADIUS_STEP);
            deformer.assign_constraints();
            let h = &deformer.handles[k];
            println!("handle {k}: radius {:.3}, {} control vertices", h.radius, h.constraints.len());
            iterate_or_step(&mut deformer, &mut solve_time, None);
            solved += solve_time * 1e3;
            mesh_dirty = true;
        }
        if animate && !deformer.handles.is_empty() {
            // Back and forth along x over 100 frames (`Idle` in the C++ code).
            let (count, direction) = &mut animation;
            if *count == 50 {
                *direction = -1.0;
            } else if *count == -50 {
                *direction = 1.0;
            }
            *count += *direction as i32;
            deformer.handles[0].translation.x += ANIMATION_STEP * *direction;
        }

        // The C++ code keeps iterating every frame while a handle is held, even without motion.
        if !matches!(drag, Drag::None) || animate {
            iterate_or_step(&mut deformer, &mut solve_time, None);
            solved += solve_time * 1e3;
            mesh_dirty = true;
        }
        if iterate {
            iterate_or_step(&mut deformer, &mut solve_time, Some(convergence));
            solved += solve_time * 1e3;
            mesh_dirty = true;
        }

        if mesh_dirty {
            // `set_positions` / `set_normals` compare against `Mesh::vertex_count()`, which three-d 0.19 reports as
            // the index count for indexed meshes; the partial updates write the same buffers without that check.
            model.geometry.set_positions_partially(0, &to_f32(&deformer.high_positions)).expect("vertex buffer");
            model.geometry.set_normals_partially(0, &to_f32(&deformer.high_normals)).expect("normal buffer");
            wireframe = None;
            mesh_dirty = false;
        }
        if show_wires && wireframe.is_none() {
            let soup: Vec<Vec3> = deformer
                .high
                .faces
                .iter()
                .flatten()
                .map(|&i| to_f32_vec(&deformer.high_positions[i]))
                .collect();
            wireframe = Some(Wireframe::new(&context, &soup, 1.0, Srgba::new(80, 80, 80, 255)));
        }
        for (k, (sphere, handle)) in spheres.iter_mut().zip(&deformer.handles).enumerate() {
            let c = to_f32_vec(&handle.center());
            sphere.set_transformation(Mat4::from_translation(c) * Mat4::from_scale(handle.radius as f32));
            let color = if Some(k) == selected { red } else { turquoise };
            sphere.material.albedo = color;
        }
        light.direction = camera.view_direction();

        let wires = wireframe.iter().filter(|_| show_wires).flat_map(|w| w.into_iter());
        let handles = spheres.iter().filter(|_| show_handles).flat_map(|s| s.into_iter());
        frame_input
            .screen()
            .clear(ClearState::color_and_depth(0.75, 0.75, 0.75, 1.0, 1.0))
            .render(&camera, model.into_iter().chain(wires).chain(handles), &[&ambient, &light])
            .write(|| gui.render())
            .unwrap();

        if profile {
            let (frames, interval, work, solve) = &mut stats;
            *frames += 1;
            *interval += frame_input.elapsed_time;
            *work += frame_start.elapsed().as_secs_f64() * 1e3;
            *solve += solved;
            if *frames == 120 {
                let f = f64::from(*frames);
                println!(
                    "frame interval {:.1} ms ({:.0} fps), frame work {:.1} ms, of which solve {:.1} ms",
                    *interval / f,
                    1e3 * f / *interval,
                    *work / f,
                    *solve / f
                );
                stats = (0, 0.0, 0.0, 0.0);
            }
        }
        FrameOutput::default()
    });
}

/// One interactive frame, or the `X` iteration when `many` is set (`Some(until_converged)`).
fn iterate_or_step(deformer: &mut Deformer, solve_time: &mut f64, many: Option<bool>) {
    let start = Instant::now();
    match many {
        None => deformer.step(),
        Some(until_converged) => deformer.iterate_many(until_converged),
    }
    *solve_time = start.elapsed().as_secs_f64();
}

/// Nearest handle sphere hit by the ray, with the distance along it.
fn pick(handles: &[Handle], origin: Vec3, direction: Vec3) -> Option<(usize, f64)> {
    let (o, d) = (to_f64(origin), to_f64(direction).normalize());
    handles
        .iter()
        .enumerate()
        .filter_map(|(k, h)| h.ray_hit(&o, &d).map(|t| (k, t)))
        .min_by(|a, b| a.1.total_cmp(&b.1))
}

fn to_f32(v: &[DVec3]) -> Vec<Vec3> {
    v.iter().map(to_f32_vec).collect()
}

fn to_f32_vec(p: &DVec3) -> Vec3 {
    vec3(p.x as f32, p.y as f32, p.z as f32)
}

fn to_f64(p: Vec3) -> DVec3 {
    DVec3::new(f64::from(p.x), f64::from(p.y), f64::from(p.z))
}
