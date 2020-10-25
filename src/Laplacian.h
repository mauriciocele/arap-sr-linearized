#if !defined(__LAPLACIAN__H__)
#define __LAPLACIAN__H__

#include <memory>
#include <cfloat>
#include "numerics.h"
#include "HalfEdge/Mesh.h"

const int Uniform = 0;
const int LaplaceBeltrami = 1;
const int MeanValue = 2;

std::shared_ptr<numerics::SparseMatrix> CreateLaplacianMatrix( Mesh *mesh, int type );

#endif