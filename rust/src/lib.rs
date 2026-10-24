//! Smooth-rotation enhanced ARAP deformation with linearized rotations: the solver shared by the interactive
//! viewer (`src/main.rs`), the experiments (`src/bin/experiments.rs`) and the figure renderer (`src/bin/render.rs`).

pub mod deformer;
pub mod handle;
pub mod laplacian;
pub mod mesh;
pub mod scenes;
pub mod iterative;
pub mod exact;
