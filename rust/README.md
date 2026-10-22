# arap (Rust port)

Rust port of the interactive C++ demo in `../src` (`Flatten.cpp`): smooth-rotation enhanced ARAP deformation with
linearized rotations, solved on a coarse control mesh and transferred to the detailed mesh. The viewer uses
[three-d](https://github.com/asny/three-d); the linear algebra uses [faer](https://faer.veganb.tw) and
[nalgebra](https://nalgebra.org).

```bash
cargo run --release                 # cactus (cactus2.obj driven by cactus1.obj, two handles)
cargo run --release -- armadillo    # armadillo with six handles
cargo run --release -- --high H.obj --low L.obj --handle 0,0.04,0.7,0.15 --handle 0,0.04,-0.8,0.15
cargo test --release                # solver checks
```

Handle centres are in the normalised frame: each mesh is centred and scaled to a bounding-box half-diagonal of 1.

## Controls

| Input | Action |
|---|---|
| Left-drag a sphere | Move it with the cursor (in the plane facing the camera) |
| Right-drag a sphere, or Shift + left-drag | Rotate it about its centre |
| Left-drag the background | Arcball: tumble freely near the centre, roll near the window edge |
| Wheel / pinch | Zoom |
| Click a sphere, then Up / Down | Change its radius (re-selects the control vertices it drives) |
| W / H | Wireframe / handles |
| X | 100 iterations, or iterate until converged in convergence mode |
| C | Convergence mode (also applies the C++ benchmark displacement to the first handle) |
| A | Animate the first handle back and forth |

## Differences from the C++ version

- The conformal geometric algebra library (`../src/GA`, generated code) is replaced by a quaternion plus a
  translation per handle; the motor `T * (Tc R ~Tc)` becomes `x -> R (x - c) + c + t`.
- All three linear systems are solved with sparse Cholesky factorizations instead of the C++ sparse LUs. The Poisson
  systems are reduced to their free vertices; the rotation system's rows are scaled so it becomes symmetric. The
  solutions are the same (a test checks the rotation solve against the C++ LU system), but faster: a cactus frame
  takes ~5 ms and an armadillo frame ~31 ms.
- `ARAP_PROFILE=1 cargo run --release -- --animate` prints frame and solve times while the first handle animates.
- Handles move with the cursor instead of by a fixed amount per pixel, and changing a handle's radius updates the
  constrained vertices (the C++ code only changed the drawn sphere).
- OpenGL selection-buffer picking is replaced by ray–sphere intersection.
