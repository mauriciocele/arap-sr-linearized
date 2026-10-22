# arap-sr-linearized
Exact Smooth-Rotation Estimation in Near-Linear Time for ARAP Surface Deformation.

ARAP deformation with smooth rotations (SR-ARAP), where the local step is solved exactly as one symmetric positive
definite system with linearized quaternion rotations, by conjugate gradients preconditioned with a factor-once
Cholesky factorization. The repository contains the reference C++ implementation (`src/`), a Rust port used for the
paper's measurements and figures (`rust/`), and the paper (`fast-linealized-rotation/`).

## Rust port

Requires a recent stable Rust toolchain (edition 2024). From `rust/`:

```sh
cargo build --release
cargo test --release
```

Interactive viewer (default binary):

```sh
cargo run --release                     # cactus
cargo run --release -- armadillo        # Armadillo with a 502-vertex control mesh
cargo run --release -- --data DIR cactus
cargo run --release -- --high HIGH.obj --low LOW.obj --handle X,Y,Z,R [--handle X,Y,Z,R ...]
cargo run --release -- --animate        # start with the first handle animated
```

`--data` is the folder with the models (default `../src`). With `--high`/`--low` the full-resolution and control
meshes are given explicitly, and each `--handle` is a sphere (centre and radius) in the normalised frame, where every
mesh is centred and scaled to a bounding-box half-diagonal of 1.

Controls:

- left-drag a sphere: move it; right-drag (or shift + left-drag): rotate it about its centre
- left-drag the background: arcball rotation; wheel or pinch: zoom
- click a sphere to select it; Up / Down change its radius
- `W` wireframe, `H` handles, `X` iterate (100 times, or until converged in convergence mode), `C` convergence mode,
  `A` animate the first handle

Paper data and figures:

```sh
cargo run --release --bin experiments [all|convergence|feedback|iterative|bias|energy|comparison|timing]
cargo run --release --bin render [all|teaser|pipeline|bar|arcs|cactus|colorbar|twist270]
```

`experiments` writes CSV files to `fast-linealized-rotation/data/`, and `render` writes images to
`fast-linealized-rotation/figures/` (it opens a small window for the OpenGL context).

## C++ implementation

Requires [Eigen 3.4](https://eigen.tuxfamily.org) and OpenGL/GLUT. On macOS, from `src/`:

```sh
clang++ -std=c++17 -stdlib=libc++ -O3 -march=native -ffast-math -I/path/to/eigen-3.4.0 \
    -framework OpenGL -framework GLUT GA/*.cpp HalfEdge/*.cpp *.cpp -o flatten.out
./flatten.out
```

`.vscode/tasks.json` contains the same build as a VS Code task, and `arap.sln` is the Visual Studio solution. Run it
from `src/` so that it finds the models. It loads the cactus (`cactus2.obj`, with the control mesh `cactus1.obj`);
the Armadillo setup is commented out in `main`. Options:

- `--direct`: refactor the rotation system with a sparse Cholesky every local step instead of solving it with PCG
- `--lu`: use the original LU solves for the Poisson systems
- `--check`: run the same frames with LU, direct Cholesky and PCG, and print their timings and differences

Keys: `W` wireframe, `H` handles, `X` iterate, `C` convergence mode, `A` animate.

## Paper

From `fast-linealized-rotation/`:

```sh
latexmk -pdf linealizedrotations.tex
```
