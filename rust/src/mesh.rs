//! Triangle mesh with the adjacency the deformation needs.
//!
//! Port of `HalfEdge/Mesh.{h,cpp}`. The C++ half-edge structure is only ever used to walk the one-ring of a
//! vertex and to find the vertex opposite a directed edge, so this keeps exactly that: a sorted neighbour list per
//! vertex and a map from each directed edge to the third vertex of the face it bounds.

use std::collections::{BTreeSet, HashMap};
use std::fs;
use std::path::Path;

use nalgebra::Vector3;

pub type Vec3 = Vector3<f64>;

#[derive(Clone)]
pub struct Mesh {
    pub positions: Vec<Vec3>,
    pub normals: Vec<Vec3>,
    pub faces: Vec<[usize; 3]>,
    /// One-ring of each vertex, in increasing vertex order.
    pub neighbors: Vec<Vec<usize>>,
    /// Directed edge `(i, j)` to the third vertex `k` of the face `(i, j, k)` it belongs to.
    opposite: HashMap<(usize, usize), usize>,
}

impl Mesh {
    /// Reads an OBJ file: `v x y z` and `f a b c ...` lines; texture and normal indices (`a/b/c`) are ignored.
    /// Polygons are fanned into triangles.
    pub fn read_obj(path: &Path) -> Result<Self, String> {
        let text = fs::read_to_string(path).map_err(|e| format!("cannot read {}: {e}", path.display()))?;
        let mut positions = Vec::new();
        let mut faces = Vec::new();
        for (line_no, line) in text.lines().enumerate() {
            let mut tokens = line.split_whitespace();
            match tokens.next() {
                Some("v") => {
                    let mut c = [0.0; 3];
                    for value in &mut c {
                        *value = tokens
                            .next()
                            .and_then(|t| t.parse().ok())
                            .ok_or_else(|| format!("{}:{}: bad vertex", path.display(), line_no + 1))?;
                    }
                    positions.push(Vec3::new(c[0], c[1], c[2]));
                }
                Some("f") => {
                    let ids = tokens
                        .map(|t| {
                            let id: usize = t
                                .split('/')
                                .next()
                                .and_then(|s| s.parse().ok())
                                .filter(|&id| id >= 1)
                                .ok_or_else(|| format!("{}:{}: bad face", path.display(), line_no + 1))?;
                            Ok(id - 1)
                        })
                        .collect::<Result<Vec<usize>, String>>()?;
                    for k in 1..ids.len().saturating_sub(1) {
                        faces.push([ids[0], ids[k], ids[k + 1]]);
                    }
                }
                _ => {}
            }
        }
        if let Some(bad) = faces.iter().flatten().find(|&&id| id >= positions.len()) {
            return Err(format!("{}: face references vertex {} of {}", path.display(), bad + 1, positions.len()));
        }
        Ok(Self::from_raw(positions, faces, &path.display().to_string()))
    }

    /// Builds the adjacency, then centres, normalises and computes normals as `read_obj` does.
    pub fn from_raw(positions: Vec<Vec3>, faces: Vec<[usize; 3]>, name: &str) -> Self {
        let mut opposite = HashMap::with_capacity(faces.len() * 3);
        let mut rings = vec![BTreeSet::new(); positions.len()];
        for &[a, b, c] in &faces {
            for (i, j, k) in [(a, b, c), (b, c, a), (c, a, b)] {
                opposite.insert((i, j), k);
                rings[i].insert(j);
                rings[j].insert(i);
            }
        }
        let neighbors = rings.into_iter().map(|ring| ring.into_iter().collect()).collect();

        let mut mesh = Mesh { normals: vec![Vec3::zeros(); positions.len()], positions, faces, neighbors, opposite };
        println!("{name}: {} vertices, {} faces", mesh.positions.len(), mesh.faces.len());
        mesh.center_and_normalize();
        mesh.compute_normals();
        mesh
    }

    /// A closed tube along y (the classic bar benchmark of ARAP papers): `rings` rings of `segments` vertices,
    /// `length` long with radius `radius`. Each end is closed by concentric rings that halve in size towards the
    /// centre, so no vertex has more than a dozen neighbours (a single fan would give the centre `segments`).
    /// `segments` must be 12 times a power of two. Faces are counter-clockwise seen from outside.
    pub fn tube(rings: usize, segments: usize, length: f64, radius: f64) -> Self {
        assert!(segments >= 12 && segments.is_multiple_of(12) && (segments / 12).is_power_of_two());
        let mut positions = Vec::new();
        let ring = |positions: &mut Vec<Vec3>, count: usize, y: f64, r: f64| {
            let start = positions.len();
            for s in 0..count {
                let a = std::f64::consts::TAU * s as f64 / count as f64;
                positions.push(Vec3::new(r * a.cos(), y, r * a.sin()));
            }
            start
        };
        let side: Vec<usize> = (0..rings)
            .map(|r| ring(&mut positions, segments, -length / 2.0 + length * r as f64 / (rings - 1) as f64, radius))
            .collect();
        let mut faces: Vec<[usize; 3]> = Vec::new();
        for r in 0..rings - 1 {
            for s in 0..segments {
                let (a, b) = (side[r], side[r + 1]);
                let (s1, s2) = (s, (s + 1) % segments);
                faces.push([a + s1, b + s1, b + s2]);
                faces.push([a + s1, b + s2, a + s2]);
            }
        }
        // Caps: rings of segments, segments/2, ..., 12 on the end plane, then a fan of 12 around the centre.
        for (outer_start, y) in [(side[0], -length / 2.0), (side[rings - 1], length / 2.0)] {
            let mut cap_faces = Vec::new();
            let (mut outer, mut count) = (outer_start, segments);
            while count > 12 {
                let inner_count = count / 2;
                let inner = ring(&mut positions, inner_count, y, radius * inner_count as f64 / segments as f64);
                for k in 0..inner_count {
                    let o = |i: usize| outer + i % count;
                    let n = |i: usize| inner + i % inner_count;
                    cap_faces.push([o(2 * k), o(2 * k + 1), n(k)]);
                    cap_faces.push([o(2 * k + 1), o(2 * k + 2), n(k + 1)]);
                    cap_faces.push([o(2 * k + 1), n(k + 1), n(k)]);
                }
                (outer, count) = (inner, inner_count);
            }
            let centre = positions.len();
            positions.push(Vec3::new(0.0, y, 0.0));
            for k in 0..count {
                cap_faces.push([centre, outer + k, outer + (k + 1) % count]);
            }
            // Orient every cap triangle to face away from the tube.
            let outward = y.signum();
            for f in &mut cap_faces {
                let n = (positions[f[1]] - positions[f[0]]).cross(&(positions[f[2]] - positions[f[0]]));
                if n.y * outward < 0.0 {
                    f.swap(1, 2);
                }
            }
            faces.extend(cap_faces);
        }
        Self::from_raw(positions, faces, &format!("tube {rings}x{segments}"))
    }

    /// Third vertex of the face that contains the directed edge `i -> j`, if any.
    pub fn opposite(&self, i: usize, j: usize) -> Option<usize> {
        self.opposite.get(&(i, j)).copied()
    }

    /// Centres the bounding box at the origin and scales its half-diagonal to 1.
    fn center_and_normalize(&mut self) {
        let mut min = Vec3::repeat(f64::INFINITY);
        let mut max = Vec3::repeat(f64::NEG_INFINITY);
        for p in &self.positions {
            min = min.inf(p);
            max = max.sup(p);
        }
        let center = min + (max - min) * 0.5;
        let scale = 1.0 / ((max - min).norm() / 2.0);
        for p in &mut self.positions {
            *p = (*p - center) * scale;
        }
    }

    /// Vertex normal = normalised mean of the unit normals of the incident faces.
    fn compute_normals(&mut self) {
        let mut sums = vec![Vec3::zeros(); self.positions.len()];
        for &[a, b, c] in &self.faces {
            let p = &self.positions;
            let n = (p[b] - p[a]).cross(&(p[c] - p[a])).normalize();
            for v in [a, b, c] {
                sums[v] += n;
            }
        }
        for (normal, sum) in self.normals.iter_mut().zip(sums) {
            *normal = sum.try_normalize(0.0).unwrap_or_else(Vec3::z);
        }
    }

    pub fn area(&self) -> f64 {
        self.faces
            .iter()
            .map(|&[a, b, c]| {
                let p = &self.positions;
                0.5 * (p[b] - p[a]).cross(&(p[c] - p[a])).norm()
            })
            .sum()
    }

    pub fn num_vertices(&self) -> usize {
        self.positions.len()
    }
}
