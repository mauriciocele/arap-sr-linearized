/*
arg min Sum_i Ei(Ri)
  s.t. ~Ri Ri = 1

Ei = Sum_j wij |Ri qji ~Ri - pji|^2 + A Sum_j cij |Ri - Rj|^2 + ei |Ri - R_{i-1}|^2

where:  Sum_j wij = 1    and     ei + Sum_j cij = 1

Ei = Sum_j wij |Ri qji - pji Ri|^2 + A Sum_j cij |Ri - Rj|^2 + ei |Ri - R_{i-1}|^2

Since: Sum_j wij |Ri qji - pji Ri|^2 = Ri^T Hi Ri

Ei = Ri^T Hi Ri + A Sum_j cij |Ri - Rj|^2 + ei |Ri - R_{i-1}|^2

dEi/Ri = 2 Hi Ri + 2 A sum_j(cij Ri - Rj) + 2 ei (Ri - R_{i-1})
dEi/Ri = Hi Ri + A sum_j(cij Ri) - A sum_j(cij Rj) + ei Ri - ei R_{i-1}
dEi/Ri = Hi Ri + A Ri sum_j(cij) - A sum_j(cij Rj) + ei Ri - ei R_{i-1}
dEi/Ri = (Hi + A sum_j(cij) I + ei I) Ri - sum_j(A cij Rj) - ei R_{i-1}

Setting dEi/Ri = 0

(Hi + A sum_j(cij) I + ei I) Ri - sum_j(A cij Rj) - ei R_{i-1} = 0

Setting Mi = Hi + (A sum_j(cij) + ei) I

And imposing: sum_j(cij) + ei = 1

Mi = Hi + A I

Mi Ri = sum_j(A cij Rj) + ei R_{i-1}

M R = L R + ei R_prev

Where 
   M is stacking Mi at the diagonal
   L is laplacian matrix from sum_j(A cij Rj)
   R_prev is stacking feedback R_{i-1}

Solve (M - L) R = ei R_prev
s.t R = R_const,  at the constrained points.
*/
#ifdef WIN32
#define NOMINMAX
#include <windows.h>
#endif

#if defined (__APPLE__) || defined (OSX)
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

#include "GA/c3ga.h"
#include "GA/c3ga_util.h"
#include "GA/gl_util.h"

#include "primitivedraw.h"
#include "gahelper.h"
#include "Laplacian.h"

#include <memory>
#include <chrono>
#include <cstring>

#include <vector>
#include <queue>
#include <map>
#include "numerics.h"
#include "HalfEdge/Mesh.h"
#include "GARotorEstimator.h"

#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <Eigen/Geometry>

// #include <ppl.h>

#include "Benchs.h"

const char *WINDOW_TITLE = "Interactive 3D Shape Deformation using Conformal Geometric Algebra";

// GLUT state information
int g_viewportWidth = 800;
int g_viewportHeight = 600;

void display();
void reshape(GLint width, GLint height);
void MouseButton(int button, int state, int x, int y);
void MouseMotion(int x, int y);
void KeyboardUpFunc(unsigned char key, int x, int y);
void SpecialFunc(int key, int x, int y);
void SpecialUpFunc(int key, int x, int y);
void Idle();
void DestroyWindow();

//using namespace boost;
using namespace c3ga;
using namespace std;
using namespace numerics;

class Camera
{
public:
	float		pos[3];
	float		fw[3];
	float		up[3];
	float		translateVel;
	float		rotateVel;

	Camera()
	{
		float		_pos[] = { 0, 0, -2};
		float		_fw[] = { 0, 0, 1 };
		float		_up[] = { 0, 1, 0 };

		translateVel = 0.005;
		rotateVel = 0.005;
		memcpy(pos, _pos, sizeof(float)*3);
		memcpy(fw, _fw, sizeof(float)*3);
		memcpy(up, _up, sizeof(float)*3);
	}

	void glLookAt()
	{
		gluLookAt( pos[0], pos[1], pos[2], fw[0],  fw[1],  fw[2], up[0],  up[1],  up[2] );
	}
};

class VertexBuffer
{
public:
	std::vector<Eigen::Vector3d> deformedPositions; //deformed mesh positions
	std::map<int, Eigen::Vector3d> constrainedPositions; //positional constraints
	std::vector<Eigen::Vector3d> laplacianCoordinates; //laplacian Coordinates
	std::vector<Eigen::Vector3d> normals; //for rendering (lighting)
	std::vector<Eigen::Vector3d> normalsOrig; //original normals
	std::vector<Eigen::Quaterniond> rotors;
	int size;

	VertexBuffer() : size(0)
	{
	}

	void resize(int size)
	{
		this->size = size;
		deformedPositions.resize(size);
		laplacianCoordinates.resize(size);
		normals.resize(size);
		normalsOrig.resize(size);
		rotors.resize(size);
	}
	int get_size() { return size; }

};

class IndexBuffer {
public:
	std::vector<int> faces;
	int size;

	IndexBuffer() : size(0)
	{
	}

	void resize(int size)
	{
		this->size = size;
		faces.resize(size);
	}
	int get_size() { return size; }

};

class Handle
{
public:
	rotor R;
	translator T;
	translator Tcenter;
	dualSphere dS;
	std::set<int> constraints;

	Handle() {
		T = _rotor(1.0);
		R = _translator(1.0);
		Tcenter = _translator(1.0);
	}
	Handle(dualSphere dS)
	{
		normalizedPoint x = DualSphereCenter(dS);
		Tcenter = exp(-0.5 * _vectorE3GA(x) * ni);
		T = _translator(1.0);
		R = _rotor(1.0);
		this->dS = dS;
	}

	TRversor GetTRVersor()
	{
		return _TRversor(T * _TRversor(Tcenter * R * inverse(Tcenter)));
	}
};

Camera g_camera;
Mesh mesh, meshLow;
map<int, int> mapping;
vectorE3GA g_prevMousePos;
bool g_rotateModel = false;
bool g_rotateModelOutOfPlane = false;
rotor g_modelRotor = _rotor(1.0);
bool g_rotateKeyRotors = false;
bool g_translateKeyRotors = false;
bool g_computeBasis = false;
float g_dragDistance = -1.0f;
int g_dragObject;
std::shared_ptr<SparseMatrix> A;
std::shared_ptr<SparseMatrix> AHi;
Eigen::SparseLU<Eigen::SparseMatrix<double>, Eigen::COLAMDOrdering<int>> solverLow, solverHi;
Eigen::SparseLU<Eigen::SparseMatrix<double>, Eigen::COLAMDOrdering<int>> solverRotations;
Eigen::SparseMatrix<double> RotationMatrix;
vector<Eigen::Triplet<double>> triplets;
int systemType = LaplaceBeltrami; //MeanValue; //LaplaceBeltrami
bool g_showSpheres = true;
bool g_showWires = false;
bool g_iterateManyTimes = false;
Eigen::MatrixXd b3Low;
Eigen::MatrixXd xyzLow;
Eigen::MatrixXd b3Hi;
Eigen::MatrixXd xyzHi;
Eigen::VectorXd Rknown;
Eigen::MatrixXd RknownHi;
Eigen::MatrixXd RbestHi;

double g_meshArea = 0.0;

bool g_automaticAnimation = false;
bool g_convergence = false;
Benchmarks benchs;

VertexBuffer vertexDescriptors;
VertexBuffer vertexDescriptorsLow;
IndexBuffer trianglesHi;
std::vector<Handle> handles;
std::set<int> allconstraints;

/*
Constrained Poisson solve: L x = b with x_c prescribed at the constrained vertices.

PreFactor replaces each constrained row of L by an identity row, which makes the matrix non-symmetric and needs a
sparse LU. Moving the prescribed values to the right-hand side instead leaves the free block:

  L_ff x_f + L_fc x_c = b_f   =>   (-L_ff) x_f = -b_f + L_fc x_c

With cotangent weights (symmetric, clamped to >= 0, rows not rescaled) -L_ff is symmetric and diagonally dominant,
and positive definite as long as every connected component has a constrained vertex, so it is factored with a sparse
Cholesky (LDL^T). The solution is the same as the LU of the row-replaced matrix.
*/
class PoissonSolver
{
public:
	void factor(std::shared_ptr<SparseMatrix> L, const std::set<int>& constrained)
	{
		const int n = L->numRows();
		freeIndex.assign(n, -1);
		freeVertices.clear();
		coupling.clear();
		for (int i = 0; i < n; ++i) {
			if (constrained.find(i) == constrained.end()) {
				freeIndex[i] = (int)freeVertices.size();
				freeVertices.push_back(i);
			}
		}
		std::vector<Eigen::Triplet<double>> entries;
		for (int r = 0; r < (int)freeVertices.size(); ++r) {
			for (SparseMatrix::RowIterator it = L->iterator(freeVertices[r]); !it.end(); ++it) {
				const int j = it.columnIndex();
				if (freeIndex[j] >= 0)
					entries.emplace_back(r, freeIndex[j], -it.value()); // -L_ff, diagonal included
				else
					coupling.emplace_back(r, j, it.value()); // L_fc
			}
		}
		Eigen::SparseMatrix<double> M((int)freeVertices.size(), (int)freeVertices.size());
		M.setFromTriplets(entries.begin(), entries.end());
		ldlt.compute(M);
		if (ldlt.info() != Eigen::Success) {
			std::cerr << "PoissonSolver: the free Laplacian block is not positive definite" << std::endl;
		}
	}

	// b holds the right-hand side in free rows and the prescribed values in constrained rows.
	Eigen::MatrixXd solve(const Eigen::MatrixXd& b) const
	{
		Eigen::MatrixXd rhs((int)freeVertices.size(), b.cols());
		for (int r = 0; r < (int)freeVertices.size(); ++r)
			rhs.row(r) = -b.row(freeVertices[r]);
		for (const Coupling& c : coupling)
			rhs.row(c.row) += c.weight * b.row(c.vertex);
		const Eigen::MatrixXd xf = ldlt.solve(rhs);
		Eigen::MatrixXd x = b;
		for (int r = 0; r < (int)freeVertices.size(); ++r)
			x.row(freeVertices[r]) = xf.row(r);
		return x;
	}

private:
	struct Coupling
	{
		int row;
		int vertex;
		double weight;
		Coupling(int row, int vertex, double weight) : row(row), vertex(vertex), weight(weight) {}
	};
	std::vector<int> freeIndex; // vertex -> reduced index, -1 when constrained
	std::vector<int> freeVertices;
	std::vector<Coupling> coupling;
	Eigen::SimplicialLDLT<Eigen::SparseMatrix<double>> ldlt;
};

// --lu (or a non-cotangent Laplacian) keeps the original row-replaced LU solves.
bool g_useLU = false;
// --direct refactors the rotation system with a sparse Cholesky every local step instead of solving it with PCG.
bool g_useDirect = false;
// PCG preconditioner of the rotation system: a Cholesky factorization of its position-independent part, which
// depends only on the mesh and the constraints, so it is computed once.
Eigen::SimplicialLDLT<Eigen::SparseMatrix<double>> rotationPreconditioner;
bool g_preconditionerReady = false;
int g_lastPcgIterations = 0;
const double PCG_TOLERANCE = 1e-12;
const int PCG_MAX_ITERATIONS = 500;
PoissonSolver poissonLow, poissonHi;
Eigen::SimplicialLDLT<Eigen::SparseMatrix<double>, Eigen::Lower> ldltRotations;
bool g_rotationsAnalyzed = false;
std::vector<int> rotationFreeIndex; // control vertex -> reduced block index, -1 when constrained
int rotationFreeCount = 0;
int g_maxDegreeLow = 0;
const int MAX_ROTATION_DEGREE = 32;

Eigen::Affine3d MotorToMatrix(const TRversor& R) {
	TRversor Ri = inverse(R);

	// compute images of basis vectors:
	c3ga::flatPoint imageOfE1NI = _flatPoint(R * c3ga::e1ni * Ri);
	c3ga::flatPoint imageOfE2NI = _flatPoint(R * c3ga::e2ni * Ri);
	c3ga::flatPoint imageOfE3NI = _flatPoint(R * c3ga::e3ni * Ri);
	c3ga::flatPoint imageOfNONI = _flatPoint(R * c3ga::noni * Ri);

	// create matrix representation:
	Eigen::Affine3d M;
	M(0, 0) = imageOfE1NI.m_c[0];
	M(1, 0) = imageOfE1NI.m_c[1];
	M(2, 0) = imageOfE1NI.m_c[2];
	M(3, 0) = imageOfE1NI.m_c[3];
	M(0, 1) = imageOfE2NI.m_c[0];
	M(1, 1) = imageOfE2NI.m_c[1];
	M(2, 1) = imageOfE2NI.m_c[2];
	M(3, 1) = imageOfE2NI.m_c[3];
	M(0, 2) = imageOfE3NI.m_c[0];
	M(1, 2) = imageOfE3NI.m_c[1];
	M(2, 2) = imageOfE3NI.m_c[2];
	M(3, 2) = imageOfE3NI.m_c[3];
	M(0, 3) = imageOfNONI.m_c[0];
	M(1, 3) = imageOfNONI.m_c[1];
	M(2, 3) = imageOfNONI.m_c[2];
	M(3, 3) = imageOfNONI.m_c[3];
	return M;
}

void ComputeLaplacianCoordinates(std::shared_ptr<SparseMatrix> A, Mesh* mesh, std::vector<Eigen::Vector3d>& laplacianCoordinates)
{
	std::fill(laplacianCoordinates.begin(), laplacianCoordinates.end(), Eigen::Vector3d(0, 0, 0));

	auto numRows = A->numRows();

	for (int i = 0; i < numRows; ++i)
	{
		SparseMatrix::RowIterator aIter = A->iterator(i);
		for (; !aIter.end(); ++aIter)
		{
			auto j = aIter.columnIndex();
			laplacianCoordinates[i] += mesh->vertexAt(j).p * aIter.value();
		}
	}
}

bool is_constrained(std::set<int>& constraints, int vertex)
{
	return constraints.find(vertex) != constraints.end();
}

void PreFactor(std::shared_ptr<SparseMatrix> A, std::set<int>& constraints, Eigen::SparseLU<Eigen::SparseMatrix<double>, Eigen::COLAMDOrdering<int>>& solver)
{

	Eigen::SparseMatrix<double> Lc = Eigen::SparseMatrix<double>(A->numRows(), A->numColumns());

	auto numRows = A->numRows();
	for (int i = 0; i < numRows; ++i)
	{
		if (!is_constrained(constraints, i))
		{
			SparseMatrix::RowIterator aIter = A->iterator(i);
			for (; !aIter.end(); ++aIter)
			{
				auto j = aIter.columnIndex();
				Lc.insert(i, j) = (*A)(i, j);
			}
		}
		else
		{
			Lc.insert(i, i) = 1.0;
		}
	}

	Lc.makeCompressed();
	solver.compute(Lc);
	if (solver.info() != Eigen::Success) {
		// TODO: error handling
	}

}

double meshArea(Mesh *mesh)
{
	double area = 0.0;
	for(Face& face :  mesh->getFaces())
	{
		Eigen::Vector3d	u = face.edge->next->vertex->p - face.edge->vertex->p;
		Eigen::Vector3d	v = face.edge->next->next->vertex->p - face.edge->vertex->p;
		area += 0.5 * u.cross(v).norm();
	}
	return area;
}

void meshMapping(Mesh *meshLow, Mesh *mesh, map<int, int>& mapping)
{
	for (Vertex& vertexLow : meshLow->getVertices())
	{
		double minDist = 1e38;
		int mappedPoint = -1;
		Eigen::Vector3d& pLow = vertexLow.p;
		for (Vertex& vertexHi : mesh->getVertices())
		{
			Eigen::Vector3d& p = vertexHi.p;
			double dist = (pLow - p).norm();
			if (dist < minDist) {
				minDist = dist;
				mappedPoint = vertexHi.ID;
			}
		}
		mapping[vertexLow.ID] = mappedPoint;
	}
}

void RunSolverCheck();

int main(int argc, char* argv[])
{
	bool check = false;
	for (int i = 1; i < argc; ++i) {
		if (strcmp(argv[i], "--lu") == 0) g_useLU = true;
		if (strcmp(argv[i], "--direct") == 0) g_useDirect = true;
		if (strcmp(argv[i], "--check") == 0) check = true;
	}
	// The Cholesky solves rely on the symmetric cotangent Laplacian (see PoissonSolver).
	if (systemType != LaplaceBeltrami) g_useLU = true;

	mesh.readOBJ("cactus2.obj"); //cactus2.obj  armadillo.obj
	mesh.CenterAndNormalize();
	mesh.computeNormals();

	meshLow.readOBJ("cactus1.obj"); //cactus1.obj armadillo1.obj
	meshLow.CenterAndNormalize();
	meshLow.computeNormals();

	meshMapping(&meshLow, &mesh, mapping);

	//cactus.obj
	handles.push_back(Handle(_dualSphere(c3gaPoint(.0, .04, 0.7) - 0.5*SQR(0.15)*ni)));
	handles.push_back(Handle(_dualSphere(c3gaPoint(.0, .04, -0.8) - 0.5*SQR(0.15)*ni)));

	////cylinder.obj
	//handles.push_back(Handle(_dualSphere(c3gaPoint(.0, 0.9, .0) - 0.5*SQR(0.25)*ni)));
	//handles.push_back(Handle(_dualSphere(c3gaPoint(.0, -0.9, .0) - 0.5*SQR(0.25)*ni)));

	// //Armadillo foot and hand
	// handles.push_back(Handle(_dualSphere(c3gaPoint(-.5, 0.45, -.3) - 0.5*SQR(0.15)*ni))); // hand
	// handles.push_back(Handle(_dualSphere(c3gaPoint(.2, -0.6, .1) - 0.5*SQR(0.15)*ni))); // foot
	// handles.push_back(Handle(_dualSphere(c3gaPoint(.45, 0.45, -.3) - 0.5*SQR(0.15)*ni))); // hand
	// handles.push_back(Handle(_dualSphere(c3gaPoint(-.3, -0.6, .1) - 0.5*SQR(0.15)*ni))); // foot
	// //Armadillo hip y head
	// handles.push_back(Handle(_dualSphere(c3gaPoint(.0, 0.4, -.2) - 0.5*SQR(0.15)*ni)));
	// handles.push_back(Handle(_dualSphere(c3gaPoint(.0, -0.05, .1) - 0.5*SQR(0.15)*ni)));

	vertexDescriptorsLow.resize(meshLow.numVertices());
	vertexDescriptors.resize(mesh.numVertices());
	trianglesHi.resize(mesh.numFaces() * 3);

	for( Vertex& vertexLow : meshLow.getVertices())
	{
		vertexDescriptorsLow.rotors[vertexLow.ID] = Eigen::Quaterniond::Identity();
		normalizedPoint position = c3gaPoint(vertexLow.p.x(), vertexLow.p.y(), vertexLow.p.z());

		for (Handle& handle : handles)
		{
			TRversor TR = handle.GetTRVersor();

			if (_double(position << (TR * handle.dS * inverse(TR))) > 0) //inside the sphere
			{
				handle.constraints.insert(vertexLow.ID);
				vertexDescriptorsLow.constrainedPositions[vertexLow.ID] = vertexLow.p;
			}
		}
	}

	A = CreateLaplacianMatrix( &meshLow, systemType );
	
	ComputeLaplacianCoordinates(A, &meshLow, vertexDescriptorsLow.laplacianCoordinates);

	b3Low = Eigen::MatrixXd(A->numRows(), 3);

	for (Handle& handle : handles) {
		allconstraints.insert(handle.constraints.begin(), handle.constraints.end());
	}
	if (g_useLU || check) PreFactor(A, allconstraints, solverLow);
	if (!g_useLU || check) poissonLow.factor(A, allconstraints);

	rotationFreeIndex.assign(meshLow.numVertices(), -1);
	rotationFreeCount = 0;
	for (Vertex& vertexLow : meshLow.getVertices()) {
		g_maxDegreeLow = std::max(g_maxDegreeLow, vertexLow.getValence());
		if (!is_constrained(allconstraints, vertexLow.ID)) rotationFreeIndex[vertexLow.ID] = rotationFreeCount++;
	}

	g_meshArea = meshArea(&meshLow);

	for (Vertex& vertexHi : mesh.getVertices()) {
		vertexDescriptors.normalsOrig[vertexHi.ID] = vertexHi.n;
		vertexDescriptors.rotors[vertexHi.ID] = Eigen::Quaterniond::Identity();
	}

	for (Face& face : mesh.getFaces()) {
		int i = face.ID;
		int	v1 = face.edge->vertex->ID;
		int	v2 = face.edge->next->vertex->ID;
		int	v3 = face.edge->next->next->vertex->ID;
		trianglesHi.faces[i * 3 + 0] = v1;
		trianglesHi.faces[i * 3 + 1] = v2;
		trianglesHi.faces[i * 3 + 2] = v3;
	}


	AHi = CreateLaplacianMatrix(&mesh, systemType);
	ComputeLaplacianCoordinates(AHi, &mesh, vertexDescriptors.laplacianCoordinates);
	std::set<int> constraintsHi;
	for (map<int, int>::iterator iter = mapping.begin(); iter != mapping.end(); iter++){
		constraintsHi.insert(iter->second);
	}
	b3Hi = Eigen::MatrixXd(AHi->numRows(), 3);
	if (g_useLU || check) PreFactor(AHi, constraintsHi, solverHi);
	if (!g_useLU || check) poissonHi.factor(AHi, constraintsHi);

  RotationMatrix = Eigen::SparseMatrix<double>(A->numRows()*4, A->numColumns()*4);
  triplets.resize(A->NonZeros()*16);
  Rknown = Eigen::VectorXd(A->numRows()*4);
  Rknown.setZero();
  RknownHi = Eigen::MatrixXd(AHi->numRows(), 4);
  RknownHi.setZero();

	if (check) {
		RunSolverCheck();
		return 0;
	}

	// GLUT Window Initialization:
	glutInit (&argc, argv);
	glutInitWindowSize(g_viewportWidth, g_viewportHeight);
	glutInitDisplayMode( GLUT_RGB | GLUT_ALPHA | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow(WINDOW_TITLE);

	// Register callbacks:
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(MouseButton);
	glutMotionFunc(MouseMotion);
	glutKeyboardUpFunc(KeyboardUpFunc);
	glutSpecialFunc(SpecialFunc);
	glutSpecialUpFunc(SpecialUpFunc);
	glutIdleFunc(Idle);
	atexit(DestroyWindow);

	InitializeDrawing();

	glutMainLoop();

	return 0;
}

void SolvePoissonEquation(VertexBuffer& vertexDescriptors)
{
	int n = vertexDescriptors.get_size();

	for (int i = 0; i < n; ++i) {
		b3Low.row(i) = vertexDescriptors.laplacianCoordinates[i];
	}

	for (Handle& handle : handles) {
		Eigen::Affine3d M = MotorToMatrix(handle.GetTRVersor());
		for (int i : handle.constraints) {
			b3Low.row(i) = M * vertexDescriptors.constrainedPositions[i];
		}
	}

	xyzLow = g_useLU ? Eigen::MatrixXd(solverLow.solve(b3Low)) : poissonLow.solve(b3Low);

	for( int i = 0 ; i < n ; ++i ) {
		vertexDescriptors.deformedPositions[i] = xyzLow.row(i);
	}
}

void SolvePoissonEquationHi(VertexBuffer& vertexDescriptors, VertexBuffer& vertexDescriptorsLow)
{
	int n = vertexDescriptors.get_size();

	for (int i = 0; i < n; ++i) {
		b3Hi.row(i) = vertexDescriptors.laplacianCoordinates[i];
	}

	for (auto&& pair : mapping){
		b3Hi.row(pair.second) = vertexDescriptorsLow.deformedPositions[pair.first];
	}

	xyzHi = g_useLU ? Eigen::MatrixXd(solverHi.solve(b3Hi)) : poissonHi.solve(b3Hi);

	for (int i = 0; i < n; ++i) {
		vertexDescriptors.deformedPositions[i] = xyzHi.row(i);
		vertexDescriptors.normals[i] = vertexDescriptors.rotors[i]._transformVector(vertexDescriptors.normalsOrig[i]);
	}
}

/*
Laplacian: L(Ri) => Ri = Sum_j wij Rj

Solve Sum_i wij (Ri - Rj) = 0
s.t Ri = R_const,  at the constrained points.

L Ri = 0
s.t Ri = R_const

Where L is discrete laplacian operator
*/
void LaplacianRotationsInterpolation(VertexBuffer& vertexDescriptors, VertexBuffer& vertexDescriptorsLow)
{
	int n = vertexDescriptors.get_size();

	for (auto&& pair : mapping){
		RknownHi.row(pair.second) = vertexDescriptorsLow.rotors[pair.first].coeffs();
	}

	RbestHi = g_useLU ? Eigen::MatrixXd(solverHi.solve(RknownHi)) : poissonHi.solve(RknownHi);

	for (int i = 0; i < n; ++i) {
		vertexDescriptors.rotors[i] = Eigen::Quaterniond((Eigen::Vector4d)RbestHi.row(i)).normalized();
	}
}

/*
Ei = sum_j |Ri qij ~Ri - pij|^2
Ei = sum_j |Ri qij - pij Ri|^2

Ri = w + B

(w + B) qij - pij (w + B)
w qij + B qij - pij w - pij B
w qij + B qij - pij w - pij B

pij B = pij . B + pij x B
B qij = B . qij + B x qij = qij . B - qij x B

w qij + (qij . B - qij x B) - pij w - (pij . B + pij x B)
w qij + qij . B - qij x B - pij w - pij . B - pij x B

(qij - pij) w + (qij - pij) . B - (qij + pij) x B

(qij - pij) w - (qij - pij)^T B - [qij + pij]_x B

|0            -(qij - pij)^T  | |w| = |-(qij - pij)^T B               |
|(qij - pij)   [qij + pij]^T_x| |B|   |(qij - pij) w - [qij + pij]_x B|

d = (qij - pij)
s = (qij + pij)
d w - s^T B - [s]_x B

|0    -d^T  | |w| = |-d^T B       |
|d   [s]^T_x| |B|   |d w - [s]_x B|

|0    -d^T  |^T |0    -d^T  | = 
|d   [s]^T_x|   |d   [s]^T_x|

|0    d^T  | |0    -d^T  | = |d^T d    d^T [s]^T_x              |
|-d   [s]_x| |d   [s]^T_x|   |[s]_x d  -d (-d^T) + [s]_x [s]^T_x|

|0    d^T  | |0    -d^T  | = |d^T d    d^T [s]^T_x    |
|-d   [s]_x| |d   [s]^T_x|   |[s]_x d  d d^T - [s]^2_x|

| ||d||^2   (s x d)^T      |
| s x d     d d^T - [s]^2_x|

| ||d||^2   (s x d)^T                |
| s x d     d d^T - s s^T + ||s||^2 I|

d = (qij - pij)
s = (qij + pij)

||d||^2 = - 2 pij^T qij + ||pij||^2 + ||qij||^2
||s||^2 = + 2 pij^T qij + ||pij||^2 + ||qij||^2
s x d = 2 pij x qij
d d^T = qij qij^T - pij qij^T - qij pij^T + pij pij^T 
s s^T = qij qij^T + pij qij^T + qij pij^T + pij pij^T
d d^T - s s^T = - 2 pij qij^T - 2 qij pij^T

| ||d||^2   (s x d)^T                |
| s x d     d d^T - s s^T + ||s||^2 I|

-2 | qij^T pij   (qij x pij)^T                      | + ||pij||^2 + ||qij||^2 I4x4
   | qij x pij   qij pij^T + pij qij^T - qij^T pij I|   

COORDINATES:

qij pij^T = | qx | |px py pz | = | qx px  qx py  qx pz |
            | qy |               | qy px  qy py  qy pz |
            | qz |               | qz px  qz py  qz pz |


Trace(qij pij^T) = qij^T pij
qij x pij = [(qy pz - qz py) e2e3, (qz px - qx pz) e3e1, (qx py - qy px) e1e2]
pij qij^T = (qij pij^T)^T
qij pij^T + pij qij^T = qij pij^T + (qij pij^T)^T =

| qx px  qx py  qx pz | | qx px  qy px  qz px |   | qx px+qx px  qx py+qy px  qx pz+qz px |
| qy px  qy py  qy pz | | qx py  qy py  qz py | = | qy px+qx py  qy py+qy py  qy pz+qz py |
| qz px  qz py  qz pz | | qx pz  qy pz  qz pz |   | qz px+qx pz  qz py+qy pz  qz pz+qz pz |

qij = a e1 + b e2 + c e3
pij = d e1 + e e2 + f e3
(b f - c e) e2e3 + (c d - a f) e3e1 + (a e - b d) e1e2
(qy pz - qz py) e2e3 + (qz px - qx pz) e3e1 + (qx py - qy px) e1e2
*/
void E3GA_Prep(const vector<Eigen::Vector3d>& P, const vector<Eigen::Vector3d>& Q, const vector<double>& w, const int N, Eigen::Matrix4d &JtJ)
{
	Eigen::Matrix3d Sx;
	double wj;
	Sx.setZero();
	double S = 0;
	for (size_t j = 0; j < N; ++j) {
		wj = w[j];
		const Eigen::Vector3d& Qj = Q[j];
		const Eigen::Vector3d& Pj = P[j];
		S += wj * Pj.dot(Pj);
		S += wj * Qj.dot(Qj);
		Sx.noalias() += (wj * Pj) * Qj.transpose();
	}

	wj = 0.5 * S;
 	JtJ(0,0) = wj - Sx.trace();
	wj = wj + Sx.trace();
	JtJ(0,1) = -(Sx(1, 2) - Sx(2, 1));
	JtJ(0,2) = -(Sx(2, 0) - Sx(0, 2));
	JtJ(0,3) = -(Sx(0, 1) - Sx(1, 0));
	JtJ(1,1) = -2.0 * Sx(0, 0) + wj;  
	JtJ(1,2) = -(Sx(0, 1) + Sx(1, 0)); 
	JtJ(1,3) = -(Sx(2, 0) + Sx(0, 2));
	JtJ(2,2) = -2.0 * Sx(1, 1) + wj;  
	JtJ(2,3) = -(Sx(1, 2) + Sx(2, 1));
	JtJ(3,3) = -2.0 * Sx(2, 2) + wj;
  JtJ.selfadjointView<Eigen::Upper>().evalTo(JtJ);
}

/*
Ei = sum_j cij |Ri qij ~Ri - pij|^2 + alphaA sum_j wij |Rj - Ri|^2
Ei = sum_j cij |Ri qij - pij Ri|^2 + alphaA sum_j wij |Rj - Ri|^2

Ei = Ri^T Mi Ri + alphaA sum_j wij (Rj^T Rj - Rj^T Ri + Ri^T Ri)
d/Ri Ei = Mi Ri + sum_j alphaA wij (-Rj + Ri)

Mi Ri + sum_j alphaA wij (-Rj + Ri) = 0
Mi Ri - sum_j alphaA wij (Rj) + sum_j alphaA wij (Ri) = 0

Since sum_j alphaA wij = alphaA

Mi Ri + alphaA Ri - sum_j alphaA wij (Rj) = 0
(Mi + alphaA I) Ri = sum_j alphaA wij Rj
*/
Eigen::Quaterniond E3GA_Fast4(const vector<Eigen::Vector3d>& P, const vector<Eigen::Vector3d>& Q, const vector<double>& w, double alphaA, const vector<Eigen::Quaterniond>& Rq, const int N)
{
	Eigen::Matrix4d JtJ;
	Eigen::Matrix3d Sx;
  Eigen::Vector4d b;

  b.setZero();
  for (int i = 0; i < N; ++i)
	{
		const Eigen::Quaterniond& Qi = Rq[i];
		b(0) += Qi.w(); // 1.0
		b(1) += Qi.x(); // e1 ^ e2
		b(2) += Qi.y(); // e1 ^ e3
		b(3) += Qi.z(); // e2 ^ e3
	}
  
  b *= alphaA / (double) N;

	double wj;
	Sx.setZero();
	double S = 0;
	for (size_t j = 0; j < N; ++j) {
		wj = w[j];
		const Eigen::Vector3d& Qj = Q[j];
		const Eigen::Vector3d& Pj = P[j];
		S += wj * Pj.dot(Pj);
		S += wj * Qj.dot(Qj);
		Sx.noalias() += (wj * Pj) * Qj.transpose();
	}

	wj = 0.5 * S;
 	JtJ(0,0) = wj - Sx.trace() + alphaA;
	wj = wj + Sx.trace() + alphaA;
	JtJ(0,1) = -(Sx(1, 2) - Sx(2, 1));
	JtJ(0,2) = -(Sx(2, 0) - Sx(0, 2));
	JtJ(0,3) = -(Sx(0, 1) - Sx(1, 0));
	JtJ(1,1) = -2.0 * Sx(0, 0) + wj;  
	JtJ(1,2) = -(Sx(0, 1) + Sx(1, 0)); 
	JtJ(1,3) = -(Sx(2, 0) + Sx(0, 2));
	JtJ(2,2) = -2.0 * Sx(1, 1) + wj;  
	JtJ(2,3) = -(Sx(1, 2) + Sx(2, 1));
	JtJ(3,3) = -2.0 * Sx(2, 2) + wj;
  JtJ.selfadjointView<Eigen::Upper>().evalTo(JtJ);

  Eigen::Vector4d x = JtJ.inverse().eval() * b;
  return Eigen::Quaterniond(x(0), x(1), x(2), x(3)).normalized();
}

// The rotation system as originally built: identity rows at the constrained vertices, solved with a sparse LU.
/*
	Rotation of a constrained (handle) cell. Normally the cell equation without feedback (E3GA_Fast4): the fit of the
	cell's edges, smoothed towards its neighbours' rotations. In the hard case, when the cell's own fit v1 (the
	eigenvector of the smallest eigenvalue of Mi) and the neighbours' pull h disagree by more than 90 degrees as
	rotations, 2 acos(|v1.h| / |h|) > 90 degrees, the smoothing would hold the handle back (a handle turned by 180
	degrees has a quaternion orthogonal to its resting neighbours'), so the cell takes its own fit instead, on the side
	of its handle's rotation. Once the rotations have spread the test fails again, so the fixed point is unchanged.
*/
Eigen::Quaterniond ConstrainedRotation(const vector<Eigen::Vector3d>& P, const vector<Eigen::Vector3d>& Q, const vector<double>& w, double alphaA, const vector<Eigen::Quaterniond>& Rq, const int N, const Eigen::Quaterniond& side)
{
	Eigen::Vector4d h = Eigen::Vector4d::Zero();
	for (int i = 0; i < N; ++i) h += Eigen::Vector4d(Rq[i].w(), Rq[i].x(), Rq[i].y(), Rq[i].z());
	Eigen::Matrix4d JtJ;
	E3GA_Prep(P, Q, w, N, JtJ);
	Eigen::SelfAdjointEigenSolver<Eigen::Matrix4d> eigen(JtJ);
	Eigen::Vector4d v1 = eigen.eigenvectors().col(0); // eigenvalues in increasing order
	const double pull = 2.0 * std::acos(std::min(1.0, std::abs(v1.dot(h)) / h.norm()));
	if (pull <= 0.5 * M_PI)
		return E3GA_Fast4(P, Q, w, alphaA, Rq, N);
	if (v1.dot(Eigen::Vector4d(side.w(), side.x(), side.y(), side.z())) < 0.0) v1 = -v1;
	return Eigen::Quaterniond(v1(0), v1(1), v1(2), v1(3)).normalized();
}

/* The rotation of the handle that drives a constrained vertex, kept on one branch from call to call. */
Eigen::Quaterniond HandleRotationOf(int vertex)
{
	static std::vector<Eigen::Quaterniond> last;
	if (last.size() != handles.size()) last.assign(handles.size(), Eigen::Quaterniond::Identity());
	for (size_t k = 0; k < handles.size(); ++k) {
		if (!handles[k].constraints.count(vertex)) continue;
		Eigen::Quaterniond q(MotorToMatrix(handles[k].GetTRVersor()).linear());
		if (q.coeffs().dot(last[k].coeffs()) < 0.0) q.coeffs() *= -1.0;
		last[k] = q;
		return q;
	}
	return Eigen::Quaterniond::Identity();
}

void SolveRotationsSystemLU(Mesh *mesh, std::shared_ptr<SparseMatrix> A, VertexBuffer& vertexDescriptors, std::set<int>& constraints, bool analyzeSystem)
{
	vector<Eigen::Vector3d> P;
	vector<Eigen::Vector3d> Q;
  vector<double> w;
  vector<int> neighbors;
  Eigen::VectorXd Rbest;
  Eigen::Matrix4d JtJ;
  vector<Eigen::Quaterniond> Rq;

	P.resize(32);
	Q.resize(32);
  neighbors.resize(32);
  triplets.reserve(A->NonZeros()*16);
  w.resize(32);
  Rq.resize(32);
	const double alpha = 0.14;
	const double ei = 0.2;
  const double cij = 1.0;
  const double alphaA = alpha * g_meshArea;
  int nnz = 0;
  
	for (Vertex& vertex : mesh->getVertices())
	{
		int i = vertex.ID;
    int ii = i*4;

		Eigen::Vector3d &pi = vertex.p;
		Eigen::Vector3d &tpi = vertexDescriptors.deformedPositions[i];

		int vertexDegree = 0;
		for (Vertex::EdgeAroundIterator edgeAroundIter = vertex.iterator(); vertexDegree < 32 && !edgeAroundIter.end(); edgeAroundIter++, vertexDegree++)
		{
			int j = edgeAroundIter.edge_out()->pair->vertex->ID;

			Eigen::Vector3d &tpj = vertexDescriptors.deformedPositions[j];
			Eigen::Vector3d &pj = mesh->vertexAt(j).p;
			P[vertexDegree] = pj - pi;
			Q[vertexDegree] = tpj - tpi;
      neighbors[vertexDegree] = j;
      w[vertexDegree] = (*A)(i, j);
		}
    if (!is_constrained(constraints, i)) {
  		double invVertexDegree = (alphaA * cij) / ((double)vertexDegree + ei); // Plus ei since we consider the feedback.
      for(int v = 0; v < vertexDegree; ++v) {
        int jj = neighbors[v]*4;
        triplets[nnz++] = Eigen::Triplet<double>(ii+0, jj+0, -invVertexDegree);
        triplets[nnz++] = Eigen::Triplet<double>(ii+1, jj+1, -invVertexDegree);
        triplets[nnz++] = Eigen::Triplet<double>(ii+2, jj+2, -invVertexDegree);
        triplets[nnz++] = Eigen::Triplet<double>(ii+3, jj+3, -invVertexDegree);
      }
      E3GA_Prep(P, Q, w, vertexDegree, JtJ);
      JtJ(0, 0) += alphaA + 1e-6;
      JtJ(1, 1) += alphaA + 1e-6;
      JtJ(2, 2) += alphaA + 1e-6;
      JtJ(3, 3) += alphaA + 1e-6;
      triplets[nnz++] = Eigen::Triplet<double>(ii+0, ii+0, JtJ(0, 0));
      triplets[nnz++] = Eigen::Triplet<double>(ii+0, ii+1, JtJ(0, 1));
      triplets[nnz++] = Eigen::Triplet<double>(ii+0, ii+2, JtJ(0, 2));
      triplets[nnz++] = Eigen::Triplet<double>(ii+0, ii+3, JtJ(0, 3));
      triplets[nnz++] = Eigen::Triplet<double>(ii+1, ii+0, JtJ(1, 0));
      triplets[nnz++] = Eigen::Triplet<double>(ii+1, ii+1, JtJ(1, 1));
      triplets[nnz++] = Eigen::Triplet<double>(ii+1, ii+2, JtJ(1, 2));
      triplets[nnz++] = Eigen::Triplet<double>(ii+1, ii+3, JtJ(1, 3));
      triplets[nnz++] = Eigen::Triplet<double>(ii+2, ii+0, JtJ(2, 0));
      triplets[nnz++] = Eigen::Triplet<double>(ii+2, ii+1, JtJ(2, 1));
      triplets[nnz++] = Eigen::Triplet<double>(ii+2, ii+2, JtJ(2, 2));
      triplets[nnz++] = Eigen::Triplet<double>(ii+2, ii+3, JtJ(2, 3));
      triplets[nnz++] = Eigen::Triplet<double>(ii+3, ii+0, JtJ(3, 0));
      triplets[nnz++] = Eigen::Triplet<double>(ii+3, ii+1, JtJ(3, 1));
      triplets[nnz++] = Eigen::Triplet<double>(ii+3, ii+2, JtJ(3, 2));
      triplets[nnz++] = Eigen::Triplet<double>(ii+3, ii+3, JtJ(3, 3));
      // Feedback added on the RHS.
      invVertexDegree *= ei;
      Rknown[ii+0] = invVertexDegree * vertexDescriptors.rotors[i].w();
      Rknown[ii+1] = invVertexDegree * vertexDescriptors.rotors[i].x();
      Rknown[ii+2] = invVertexDegree * vertexDescriptors.rotors[i].y();
      Rknown[ii+3] = invVertexDegree * vertexDescriptors.rotors[i].z();
    }
    else
    {
      for(int v = 0; v < vertexDegree; ++v) {
        Rq[v] = vertexDescriptors.rotors[neighbors[v]];
      }

      Eigen::Quaterniond M = ConstrainedRotation(P, Q, w, alphaA, Rq, vertexDegree, HandleRotationOf(i));
      Rknown[ii+0] = M.w();
      Rknown[ii+1] = M.x();
      Rknown[ii+2] = M.y();
      Rknown[ii+3] = M.z();
      triplets[nnz++] = Eigen::Triplet<double>(ii+0, ii+0, 1.0);
      triplets[nnz++] = Eigen::Triplet<double>(ii+1, ii+1, 1.0);
      triplets[nnz++] = Eigen::Triplet<double>(ii+2, ii+2, 1.0);
      triplets[nnz++] = Eigen::Triplet<double>(ii+3, ii+3, 1.0);     
    }
	}
  RotationMatrix.setFromTriplets(triplets.begin(), triplets.begin() + nnz);
  if(analyzeSystem) {
    solverRotations.analyzePattern(RotationMatrix);
  }
  solverRotations.factorize(RotationMatrix);
	if (solverRotations.info() != Eigen::Success) {
		// TODO: error handling
	}
	Rbest = solverRotations.solve(Rknown);

	for (int i = 0; i < vertexDescriptors.get_size(); ++i) {
    int ii = i*4;
    Eigen::Quaterniond M = Eigen::Quaterniond(Rbest(ii+0), Rbest(ii+1), Rbest(ii+2), Rbest(ii+3));
		vertexDescriptors.rotors[i] = M.normalized();
	}

  std::fill(vertexDescriptors.laplacianCoordinates.begin(), vertexDescriptors.laplacianCoordinates.end(), Eigen::Vector3d(0, 0, 0));

	//concurrency::parallel_for_each(mesh->getVertices().begin(), mesh->getVertices().end(), [&](Vertex& vertex)
	for (Vertex& vertex : mesh->getVertices())
	{
		int i = vertex.ID;
		for (Vertex::EdgeAroundIterator edgeAroundIter = vertex.iterator(); !edgeAroundIter.end(); edgeAroundIter++)
		{
			int j = edgeAroundIter.edge_out()->pair->vertex->ID;
			double wij = (*A)(i, j);
			Eigen::Quaterniond&Ri = vertexDescriptors.rotors[i];
			Eigen::Quaterniond&Rj = vertexDescriptors.rotors[j];
			Eigen::Vector3d V = mesh->vertexAt(j).p - mesh->vertexAt(i).p;
			vertexDescriptors.laplacianCoordinates[i] += 0.5 * wij * (Ri._transformVector(V) + Rj._transformVector(V));;
		}
	}
}

/*
Preconditioned conjugate gradients for the rotation system K x = b (lower triangle of K in M), warm-started from
the previous rotations.

K = C (x) I_4 + S M_blocks, where the block-diagonal S M_blocks (the membrane terms, which change with the positions)
is positive semi-definite and C, the diagonal s_i (alpha A + eps) minus the adjacency of the free cells, depends only
on the mesh and the constraints. C is therefore factored once and used as the preconditioner, applied to the four
quaternion components at once. The preconditioned system has condition number at most
1 + max_i s_i lambda_max(M_i) / e, which tends to 1 as the mesh is refined, so a local step costs a handful of
back-substitutions.
*/
Eigen::VectorXd SolveRotationsPCG(const Eigen::SparseMatrix<double>& M, const Eigen::VectorXd& b,
                                  const Eigen::VectorXd& x0, const std::vector<Eigen::Triplet<double>>& constantEntries,
                                  int cells)
{
	typedef Eigen::Matrix<double, Eigen::Dynamic, 4, Eigen::RowMajor> Components;
	if (!g_preconditionerReady) {
		Eigen::SparseMatrix<double> C(cells, cells);
		C.setFromTriplets(constantEntries.begin(), constantEntries.end());
		rotationPreconditioner.compute(C);
		g_preconditionerReady = true;
	}
	// x[4 r + k] is component k of cell r, so a row-major (cells x 4) view puts each component in a column.
	auto precondition = [&](const Eigen::VectorXd& r) {
		Eigen::MatrixXd z = rotationPreconditioner.solve(Eigen::Map<const Components>(r.data(), cells, 4));
		Eigen::VectorXd out(r.size());
		Eigen::Map<Components>(out.data(), cells, 4) = z;
		return out;
	};
	auto K = M.selfadjointView<Eigen::Lower>();
	Eigen::VectorXd x = x0;
	Eigen::VectorXd r = b - K * x;
	Eigen::VectorXd z = precondition(r);
	Eigen::VectorXd p = z;
	double rz = r.dot(z);
	const double threshold = PCG_TOLERANCE * b.norm();
	int k = 0;
	while (k < PCG_MAX_ITERATIONS && r.norm() > threshold && rz != 0.0) {
		Eigen::VectorXd q = K * p;
		const double alpha = rz / p.dot(q);
		x += alpha * p;
		r -= alpha * q;
		z = precondition(r);
		const double rzNext = r.dot(z);
		p = z + (rzNext / rz) * p;
		rz = rzNext;
		++k;
	}
	g_lastPcgIterations = k;
	return x;
}

/*
The same rotation system, made symmetric and solved with a sparse Cholesky.

The row block of a free vertex i with degree d_i is

  (H_i + (alphaA + eps) I) R_i - c_i sum_j R_j = c_i ei R_i^prev,    c_i = alphaA / (d_i + ei)

so block (i, j) is -c_i I while block (j, i) is -c_j I. Scaling the row block by 1 / c_i = (d_i + ei) / alphaA gives

  s_i (H_i + (alphaA + eps) I) R_i - sum_j R_j = ei R_i^prev,       s_i = (d_i + ei) / alphaA

whose off-diagonal blocks are -I both ways. The constrained rotations are known (the E3GA_Fast4 fit of the identity
rows), so they move to the right-hand side (+R_j for each constrained neighbour). H_i is positive semi-definite, so
the diagonal block has eigenvalues >= (d_i + ei)(1 + eps / alphaA) > d_i, which makes the free block strictly
diagonally dominant and positive definite. Same solution as SolveRotationsSystemLU.

Symmetry needs j in the ring of i exactly when i is in the ring of j, so this is used only when no ring is truncated
at MAX_ROTATION_DEGREE.
*/
void SolveRotationsSystemLDLT(Mesh *mesh, std::shared_ptr<SparseMatrix> A, VertexBuffer& vertexDescriptors, std::set<int>& constraints, bool analyzeSystem)
{
	vector<Eigen::Vector3d> P(MAX_ROTATION_DEGREE);
	vector<Eigen::Vector3d> Q(MAX_ROTATION_DEGREE);
	vector<double> w(MAX_ROTATION_DEGREE);
	vector<int> neighbors(MAX_ROTATION_DEGREE);
	vector<Eigen::Quaterniond> Rq(MAX_ROTATION_DEGREE);
	Eigen::Matrix4d JtJ;
	const double alpha = 0.14;
	const double ei = 0.2;
	const double alphaA = alpha * g_meshArea;
	const int n = vertexDescriptors.get_size();

	auto gather = [&](Vertex& vertex) {
		const int i = vertex.ID;
		const Eigen::Vector3d& pi = vertex.p;
		const Eigen::Vector3d& tpi = vertexDescriptors.deformedPositions[i];
		int degree = 0;
		for (Vertex::EdgeAroundIterator around = vertex.iterator(); !around.end(); around++, degree++) {
			const int j = around.edge_out()->pair->vertex->ID;
			P[degree] = mesh->vertexAt(j).p - pi;
			Q[degree] = vertexDescriptors.deformedPositions[j] - tpi;
			neighbors[degree] = j;
			w[degree] = (*A)(i, j);
		}
		return degree;
	};
	auto coefficients = [](const Eigen::Quaterniond& q) { return Eigen::Vector4d(q.w(), q.x(), q.y(), q.z()); };

	// Constrained vertices: the closed-form fit their identity rows would have returned.
	std::vector<Eigen::Vector4d> fixed(n, Eigen::Vector4d::Zero());
	for (Vertex& vertex : mesh->getVertices()) {
		if (!is_constrained(constraints, vertex.ID)) continue;
		const int degree = gather(vertex);
		for (int v = 0; v < degree; ++v) Rq[v] = vertexDescriptors.rotors[neighbors[v]];
		fixed[vertex.ID] = coefficients(ConstrainedRotation(P, Q, w, alphaA, Rq, degree, HandleRotationOf(vertex.ID)));
	}

	// Free vertices: scaled diagonal block, -I towards free neighbours (lower triangle only), constrained
	// neighbours on the right-hand side.
	const int m = 4 * rotationFreeCount;
	std::vector<Eigen::Triplet<double>> entries;
	entries.reserve(m * 12);
	Eigen::VectorXd rhs = Eigen::VectorXd::Zero(m);
	Eigen::VectorXd previous = Eigen::VectorXd::Zero(m);
	// The position-independent part C of the system, one scalar row per free cell (lower triangle): the PCG
	// preconditioner.
	std::vector<Eigen::Triplet<double>> constantEntries;
	for (Vertex& vertex : mesh->getVertices()) {
		const int i = vertex.ID;
		const int r = rotationFreeIndex[i];
		if (r < 0) continue;
		const int rr = 4 * r;
		const int degree = gather(vertex);
		const double scale = ((double)degree + ei) / alphaA;
		E3GA_Prep(P, Q, w, degree, JtJ);
		for (int k = 0; k < 4; ++k) JtJ(k, k) += alphaA + 1e-6;
		for (int a = 0; a < 4; ++a)
			for (int b = 0; b <= a; ++b)
				entries.emplace_back(rr + a, rr + b, scale * JtJ(a, b));
		constantEntries.emplace_back(r, r, scale * (alphaA + 1e-6));
		previous.segment<4>(rr) = coefficients(vertexDescriptors.rotors[i]);
		Eigen::Vector4d b = ei * coefficients(vertexDescriptors.rotors[i]);
		for (int v = 0; v < degree; ++v) {
			const int c = rotationFreeIndex[neighbors[v]];
			if (c < 0) {
				b += fixed[neighbors[v]];
			} else if (c < r) {
				for (int k = 0; k < 4; ++k) entries.emplace_back(rr + k, 4 * c + k, -1.0);
				constantEntries.emplace_back(r, c, -1.0);
			}
		}
		rhs.segment<4>(rr) = b;
	}

	Eigen::VectorXd solution;
	if (m > 0) {
		Eigen::SparseMatrix<double> M(m, m);
		M.setFromTriplets(entries.begin(), entries.end());
		if (g_useDirect) {
			// The pattern only depends on the mesh and the constraints, so the ordering is computed once.
			if (analyzeSystem || !g_rotationsAnalyzed) {
				ldltRotations.analyzePattern(M);
				g_rotationsAnalyzed = true;
			}
			ldltRotations.factorize(M);
			if (ldltRotations.info() != Eigen::Success) {
				std::cerr << "SolveRotationsSystemLDLT: the rotation system is not positive definite" << std::endl;
			}
			solution = ldltRotations.solve(rhs);
		} else {
			solution = SolveRotationsPCG(M, rhs, previous, constantEntries, rotationFreeCount);
		}
	}

	for (int i = 0; i < n; ++i) {
		const int r = rotationFreeIndex[i];
		const Eigen::Vector4d c = r < 0 ? fixed[i] : Eigen::Vector4d(solution.segment<4>(4 * r));
		vertexDescriptors.rotors[i] = Eigen::Quaterniond(c(0), c(1), c(2), c(3)).normalized();
	}

	std::fill(vertexDescriptors.laplacianCoordinates.begin(), vertexDescriptors.laplacianCoordinates.end(), Eigen::Vector3d(0, 0, 0));
	for (Vertex& vertex : mesh->getVertices())
	{
		int i = vertex.ID;
		for (Vertex::EdgeAroundIterator edgeAroundIter = vertex.iterator(); !edgeAroundIter.end(); edgeAroundIter++)
		{
			int j = edgeAroundIter.edge_out()->pair->vertex->ID;
			double wij = (*A)(i, j);
			Eigen::Quaterniond& Ri = vertexDescriptors.rotors[i];
			Eigen::Quaterniond& Rj = vertexDescriptors.rotors[j];
			Eigen::Vector3d V = mesh->vertexAt(j).p - mesh->vertexAt(i).p;
			vertexDescriptors.laplacianCoordinates[i] += 0.5 * wij * (Ri._transformVector(V) + Rj._transformVector(V));
		}
	}
}

void SolveRotationsSystem(Mesh *mesh, std::shared_ptr<SparseMatrix> A, VertexBuffer& vertexDescriptors, std::set<int>& constraints, bool analyzeSystem)
{
	if (g_useLU || g_maxDegreeLow > MAX_ROTATION_DEGREE)
		SolveRotationsSystemLU(mesh, A, vertexDescriptors, constraints, analyzeSystem);
	else
		SolveRotationsSystemLDLT(mesh, A, vertexDescriptors, constraints, analyzeSystem);
}

void transferRotations(Mesh *mesh, std::shared_ptr<SparseMatrix> A, VertexBuffer& vertexDescriptors, VertexBuffer& vertexDescriptorsLow)
{
  LaplacianRotationsInterpolation(vertexDescriptors, vertexDescriptorsLow);

	std::fill(vertexDescriptors.laplacianCoordinates.begin(), vertexDescriptors.laplacianCoordinates.end(), Eigen::Vector3d(0, 0, 0));

	//concurrency::parallel_for_each(mesh->getVertices().begin(), mesh->getVertices().end(), [&](Vertex& vertex)
	for (Vertex& vertex : mesh->getVertices())
	{
		int i = vertex.ID;
		for (Vertex::EdgeAroundIterator edgeAroundIter = vertex.iterator(); !edgeAroundIter.end(); edgeAroundIter++)
		{
			int j = edgeAroundIter.edge_out()->pair->vertex->ID;
			double wij = (*A)(i, j);
			Eigen::Quaterniond &Ri = vertexDescriptors.rotors[i];
			Eigen::Quaterniond &Rj = vertexDescriptors.rotors[j];
			Eigen::Vector3d V = mesh->vertexAt(j).p - mesh->vertexAt(i).p;
			vertexDescriptors.laplacianCoordinates[i] += 0.5 * wij * (Ri._transformVector(V) + Rj._transformVector(V));;
		}
	}
	//});
}

double ComputeEnergy(Mesh *mesh, std::shared_ptr<SparseMatrix> A, VertexBuffer& vertexDescriptors)
{
	double arapEnergy = 0.0;
	const double alpha = 0.28;
	//concurrency::parallel_for_each(mesh->vertices.begin(), mesh->vertices.end(), [&](Vertex * vertex)
	for (Vertex& vertex : mesh->getVertices())
	{
		int i = vertex.ID;

		Eigen::Vector3d& pi = vertex.p;
		Eigen::Vector3d &tpi = vertexDescriptors.deformedPositions[i];
		auto& Ri = vertexDescriptors.rotors[i];

		int vertexDegree = 0;
		for (Vertex::EdgeAroundIterator edgeAroundIter = vertex.iterator(); !edgeAroundIter.end(); edgeAroundIter++)
		{
			vertexDegree++;
		}

		double invVertexDegree = alpha * g_meshArea / (double)vertexDegree;

		for (Vertex::EdgeAroundIterator edgeAroundIter = vertex.iterator(); !edgeAroundIter.end(); edgeAroundIter++)
		{
			int j = edgeAroundIter.edge_out()->pair->vertex->ID;

			Eigen::Vector3d &tpj = vertexDescriptors.deformedPositions[j];
			Eigen::Vector3d &pj = mesh->vertexAt(j).p;

			Eigen::Vector3d eij = (pj - pi);
			auto q_ij = tpj - tpi;
			auto p_ij = eij;
			auto& Rj = vertexDescriptors.rotors[j];

			arapEnergy += (*A)(i, j) * (Ri._transformVector(p_ij) - q_ij).squaredNorm();
			arapEnergy += invVertexDegree * (Rj.coeffs() - Ri.coeffs()).squaredNorm();
		}
	}//);

	return arapEnergy;
}

void display()
{
	/*
	 *	matrices
	 */
	glViewport( 0, 0, g_viewportWidth, g_viewportHeight );
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	pickLoadMatrix();
	GLpick::g_frustumFar = 1000.0;
	GLpick::g_frustumNear = .1;
	gluPerspective( 60.0, (double)g_viewportWidth/(double)g_viewportHeight, GLpick::g_frustumNear, GLpick::g_frustumFar );
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glShadeModel(GL_SMOOTH);	//gouraud shading
	glClearDepth(1.0f);
	glClearColor( .75f, .75f, .75f, .0f );
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );

	/*
	 *	estados
	 */
	glEnable(GL_CULL_FACE);		//face culling
	glCullFace( GL_BACK );
	glFrontFace( GL_CCW );
	glEnable(GL_DEPTH_TEST);	//z-buffer
	glDepthFunc(GL_LEQUAL);

	/*
	 *	iluminacion
	 */
	float		ambient[] = { .3f, .3f, .3f, 1.f };
	float		diffuse[] = { .3f, .3f, .3f, 1.f };
	float		position[] = { .0f, 0.f, -150.f, 1.f };
	float		specular[] = { 1.f, 1.f, 1.f };

	glLightfv( GL_LIGHT0, GL_AMBIENT, ambient );
	glLightfv( GL_LIGHT0, GL_DIFFUSE, diffuse );
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.0125);
	glEnable(  GL_LIGHT0   );
	glEnable(  GL_LIGHTING );
	glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, specular );
	glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, 50.f );

	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glLoadIdentity();

	g_camera.glLookAt();

	glLightfv( GL_LIGHT0, /*GL_POSITION*/GL_SPOT_DIRECTION, position );

	glPushMatrix();

	rotorGLMult(g_modelRotor);

	benchs.Begin();

	if(!g_computeBasis)
	{
		static bool oneTime = true;
		if (oneTime || (g_rotateKeyRotors || g_translateKeyRotors || g_automaticAnimation))
		{
			if(oneTime == true)
			{
				SolvePoissonEquation(vertexDescriptorsLow);
			}

			for(int i = 0 ; i < 3 ; ++i)
			{
        SolveRotationsSystem(&meshLow, A, vertexDescriptorsLow, allconstraints, oneTime == true);
				SolvePoissonEquation(vertexDescriptorsLow);
			}
			transferRotations(&mesh, AHi, vertexDescriptors, vertexDescriptorsLow);
			SolvePoissonEquationHi(vertexDescriptors, vertexDescriptorsLow);

      oneTime = false;
		}
	}
	if(g_iterateManyTimes)
	{
		if (g_convergence)
		{
			clock_t begin;
			clock_t end;
			double avgTime = 0.0;

			auto arapEnergy = ComputeEnergy(&meshLow, A, vertexDescriptorsLow);
			int count = 0;
			for (; count < 2500; ++count)
			{
				begin = clock();

        SolveRotationsSystem(&meshLow, A, vertexDescriptorsLow, allconstraints, false);
				SolvePoissonEquation(vertexDescriptorsLow);

				end = clock();

				double secDeform = (double)(end - begin) / CLOCKS_PER_SEC;

				avgTime += secDeform;

				auto newArapEnergy = ComputeEnergy(&meshLow, A, vertexDescriptorsLow);
				if (fabs(arapEnergy - newArapEnergy) < 1e-4)
				{
					std::cout << "convergence after " << count + 1 << " iterations" << std::endl;
					break;
				}
				arapEnergy = newArapEnergy;
			}
			arapEnergy = ComputeEnergy(&meshLow, A, vertexDescriptorsLow);
			std::cout << arapEnergy << std::endl;
			std::cout << "Average iteration time (sec): " << avgTime / (double)(count + 1) << endl;
			std::cout << "Total accum time (sec): " << avgTime << endl;

			transferRotations(&mesh, AHi, vertexDescriptors, vertexDescriptorsLow);
			SolvePoissonEquationHi(vertexDescriptors, vertexDescriptorsLow);
		}
		else
		{
			for (int i = 0; i < 100; ++i)
			{
        SolveRotationsSystem(&meshLow, A, vertexDescriptorsLow, allconstraints, false);
				SolvePoissonEquation(vertexDescriptorsLow);
			}
			transferRotations(&mesh, AHi, vertexDescriptors, vertexDescriptorsLow);
			SolvePoissonEquationHi(vertexDescriptors, vertexDescriptorsLow);
		}
		g_iterateManyTimes = false;
	}

	benchs.End();

	if (GLpick::g_pickActive) glLoadName((GLuint)-1);

	double alpha = 1.0;

	//glEnable (GL_BLEND);
	//glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//alpha = 0.5;

	//Mesh-Faces Rendering
	glPolygonMode( GL_FRONT_AND_BACK, GL_FILL /*GL_LINE GL_FILL GL_POINT*/);
	glEnable (GL_POLYGON_OFFSET_FILL);
	glPolygonOffset (1., 1.);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable( GL_COLOR_MATERIAL );
	if (GLpick::g_pickActive) glLoadName((GLuint)10);

	glColor4d(1, 1, 1, alpha);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_DOUBLE, 0, &vertexDescriptors.deformedPositions[0]);
	glNormalPointer(GL_DOUBLE, 0, &vertexDescriptors.normals[0]);
	// draw the model
	glDrawElements(GL_TRIANGLES, trianglesHi.get_size(), GL_UNSIGNED_INT, &trianglesHi.faces[0]);
	// deactivate vertex arrays after drawing
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);

	if (g_showWires)
	{
		if (!GLpick::g_pickActive)
		{
			//Mesh-Edges Rendering (superimposed to faces)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE /*GL_LINE GL_FILL GL_POINT*/);
			glColor4d(.5, .5, .5, alpha);
			glDisable(GL_LIGHTING);
			glEnableClientState(GL_VERTEX_ARRAY);
			glVertexPointer(3, GL_DOUBLE, 0, &vertexDescriptors.deformedPositions[0]);
			// draw the model
			glDrawElements(GL_TRIANGLES, trianglesHi.get_size(), GL_UNSIGNED_INT, &trianglesHi.faces[0]);
			// deactivate vertex arrays after drawing
			glDisableClientState(GL_VERTEX_ARRAY);
			glEnable(GL_LIGHTING);
		}
	}

	//for (map<int, int>::iterator iter = mapping.begin(); iter != mapping.end(); iter++){
	//	DrawPoint(c3gaPoint(vertexDescriptors[iter->second]->deformedPosition));
	//}

	glDisable( GL_COLOR_MATERIAL );
	glDisable(GL_POLYGON_OFFSET_FILL);

	//glDisable (GL_BLEND);

	if(g_showSpheres)
	{
		//Handles rendering
		glPolygonMode( GL_FRONT_AND_BACK, GL_FILL /*GL_LINE GL_FILL GL_POINT*/);

		float	turcoise[] = { .0f, .5f, .5f, 0.3f };
		float	red[] = { .5f, .0f, .0f, 0.3f };

		for( int k = 0 ; k < handles.size() ; ++k)
		{
			if (GLpick::g_pickActive) glLoadName((GLuint)k);
			TRversor R = handles[k].GetTRVersor();
			DrawTransparentDualSphere( _dualSphere( R * handles[k].dS * inverse(R) ), turcoise );
		}		
	}

	glPopMatrix();

	glutSwapBuffers();
}

void reshape(GLint width, GLint height)
{
	g_viewportWidth = width;
	g_viewportHeight = height;

	// redraw viewport
	glutPostRedisplay();
}

vectorE3GA mousePosToVector(int x, int y) {
	x -= g_viewportWidth / 2;
	y -= g_viewportHeight / 2;
	return _vectorE3GA((float)-x * e1 - (float)y * e2);
}

void MouseButton(int button, int state, int x, int y)
{
	g_rotateModel = false;
	g_rotateKeyRotors = false;
	g_translateKeyRotors = false;

	if (button == GLUT_LEFT_BUTTON)
	{
		g_prevMousePos = mousePosToVector(x, y);

		GLpick::g_pickWinSize = 1;
		g_dragObject = pick(x, g_viewportHeight - y, display, &g_dragDistance);

		if(g_dragObject == -1 || g_dragObject == 10 )
		{
			vectorE3GA mousePos = mousePosToVector(x, y);
			g_rotateModel = true;

			if ((_Float(norm_e(mousePos)) / _Float(norm_e(g_viewportWidth * e1 + g_viewportHeight * e2))) < 0.2)
				g_rotateModelOutOfPlane = true;
			else g_rotateModelOutOfPlane = false;
		}
		else if(g_dragObject >= 0 && g_dragObject < handles.size())
		{
			g_rotateKeyRotors = true;
		}
	}

	if (button == GLUT_RIGHT_BUTTON)
	{
		g_prevMousePos = mousePosToVector(x, y);

		GLpick::g_pickWinSize = 1;
		g_dragObject = pick(x, g_viewportHeight - y, display, &g_dragDistance);

		if(g_dragObject >= 0 && g_dragObject < handles.size())
			g_translateKeyRotors = true;
	}
}

void MouseMotion(int x, int y)
{
	if (g_rotateModel || g_rotateKeyRotors || g_translateKeyRotors )
	{
		// get mouse position, motion
		vectorE3GA mousePos = mousePosToVector(x, y);
		vectorE3GA motion = mousePos - g_prevMousePos;

		if (g_rotateModel)
		{
			// update rotor
			if (g_rotateModelOutOfPlane)
				g_modelRotor = exp(g_camera.rotateVel * (motion ^ e3) ) * g_modelRotor;
			else 
				g_modelRotor = exp(0.00001f * (motion ^ mousePos) ) * g_modelRotor;
		}
		if(g_rotateKeyRotors)
		{
			rotor R1 =  _rotor( inverse(g_modelRotor) * exp(-g_camera.rotateVel * (motion ^ e3) ) * g_modelRotor);
			//rotor R1 =  _rotor( exp(-g_camera.rotateVel * (motion ^ e3) ) );
			if(g_dragObject < handles.size())
			{
				rotor R = handles[g_dragObject].R;
				handles[g_dragObject].R = normalize(_TRversor( R1 * R  ) );
			}
		}

		if(g_translateKeyRotors)
		{
			normalizedTranslator T1 = _normalizedTranslator(inverse(g_modelRotor) * exp( _freeVector(-g_camera.translateVel*motion*ni) ) * g_modelRotor);
			if(g_dragObject < handles.size())
			{
				translator T = handles[g_dragObject].T;
				handles[g_dragObject].T = normalize(_TRversor( T1 * T ));
			}
		}

		// remember mouse pos for next motion:
		g_prevMousePos = mousePos;

		// redraw viewport
		glutPostRedisplay();
	}
}

void SpecialFunc(int key, int x, int y)
{
	switch(key) {
		case GLUT_KEY_F1 :
			{
				int mod = glutGetModifiers();
				if(mod == GLUT_ACTIVE_CTRL || mod == GLUT_ACTIVE_SHIFT )
				{
				}
			}
			break;
		case GLUT_KEY_UP:
			{
				if(g_rotateKeyRotors)
				{
					handles[g_dragObject].dS = ChangeDualSphereRadiusSize(handles[g_dragObject].dS, 0.025);

					// redraw viewport
					glutPostRedisplay();
				}
			}
			break;
		case GLUT_KEY_DOWN:
			{
				if(g_rotateKeyRotors)
				{
					handles[g_dragObject].dS = ChangeDualSphereRadiusSize(handles[g_dragObject].dS, -0.025);

					// redraw viewport
					glutPostRedisplay();
				}
			}
			break;
	}
}

void SpecialUpFunc(int key, int x, int y)
{
}

void KeyboardUpFunc(unsigned char key, int x, int y)
{
	if (key == 'c' || key == 'C')
	{
		g_convergence = !g_convergence;
		vectorE3GA motion = _vectorE3GA(-70.0, -60.0, 0);
		normalizedTranslator T1 = _normalizedTranslator(inverse(g_modelRotor) * exp(_freeVector(-g_camera.translateVel*motion*ni)) * g_modelRotor);
		translator T = handles[0].T;
		handles[0].T = normalize(_TRversor(T1 * T));

		glutPostRedisplay();
	}

	if (key == 'a' || key == 'A')
	{
		g_automaticAnimation = !g_automaticAnimation;
		if (g_automaticAnimation)
		{
			benchs.Start();
		}
		else
		{
			benchs.Stop();
		}

		glutPostRedisplay();
	}

	if(key == 'w' || key == 'W')
	{
		g_showWires = !g_showWires;
		glutPostRedisplay();
	}
	
	if( key == 'h' || key == 'H' )
	{
		g_showSpheres = !g_showSpheres;
		glutPostRedisplay();
	}

	if( key == 'x' || key == 'X' )
	{
		g_iterateManyTimes = true;
		glutPostRedisplay();
	}
}

void Idle()
{
	// redraw viewport
	if (g_automaticAnimation)
	{
		const int minCount = -50;
		const int maxCount = 50;
		static int mycount = 0;
		static int direction = 0;
		vectorE3GA motion = _vectorE3GA(1.0, 0, 0);
		if (mycount == maxCount)
		{
			direction = 1;
		}
		if (mycount == minCount)
		{
			direction = 0;
		}

		if (mycount < maxCount && direction == 0)
		{
			motion = _vectorE3GA(1.0, 0, 0);
			mycount++;
		}
		if (mycount > minCount && direction == 1)
		{
			motion = _vectorE3GA(-1.0, 0, 0);
			mycount--;
		}

		normalizedTranslator T1 = _normalizedTranslator(inverse(g_modelRotor) * exp(_freeVector(-g_camera.translateVel*motion*ni)) * g_modelRotor);
		translator T = handles[0].T;
		handles[0].T = normalize(_TRversor(T1 * T));

		if (!benchs.IsStarted())
		{
			benchs.Start();
		}

		glutPostRedisplay();
	}
}

void DestroyWindow()
{
	ReleaseDrawing();
}


/*
--check: runs the same interactive frames with the original LU solves, with the Cholesky solves refactored every
local step (--direct), and with the PCG local step (the default), from the same start state, after the
displacement the 'C' key applies. Reports how far apart the results are and how long a frame takes with each.
*/
void RunSolverCheck()
{
	vectorE3GA motion = _vectorE3GA(-70.0, -60.0, 0);
	normalizedTranslator T1 = _normalizedTranslator(inverse(g_modelRotor) * exp(_freeVector(-g_camera.translateVel*motion*ni)) * g_modelRotor);
	handles[0].T = normalize(_TRversor(T1 * handles[0].T));

	const int frames = 10;
	const VertexBuffer low0 = vertexDescriptorsLow;
	const VertexBuffer high0 = vertexDescriptors;

	// mode 0: LU (original), 1: Cholesky refactored per step, 2: PCG with the factor-once preconditioner.
	int pcgIterations = 0;
	auto run = [&](int mode) {
		g_useLU = mode == 0;
		g_useDirect = mode == 1;
		vertexDescriptorsLow = low0;
		vertexDescriptors = high0;
		SolvePoissonEquation(vertexDescriptorsLow);
		const auto start = std::chrono::steady_clock::now();
		for (int frame = 0; frame < frames; ++frame) {
			for (int i = 0; i < 3; ++i) {
				SolveRotationsSystem(&meshLow, A, vertexDescriptorsLow, allconstraints, frame == 0 && i == 0);
				SolvePoissonEquation(vertexDescriptorsLow);
				if (mode == 2) pcgIterations += g_lastPcgIterations;
			}
			transferRotations(&mesh, AHi, vertexDescriptors, vertexDescriptorsLow);
			SolvePoissonEquationHi(vertexDescriptors, vertexDescriptorsLow);
		}
		const std::chrono::duration<double, std::milli> elapsed = std::chrono::steady_clock::now() - start;
		return elapsed.count() / frames;
	};

	const double luMs = run(0);
	const VertexBuffer lowLU = vertexDescriptorsLow;
	const VertexBuffer highLU = vertexDescriptors;
	auto gaps = [&](double& rotationGap, double& lowGap, double& highGap) {
		rotationGap = lowGap = highGap = 0.0;
		for (int i = 0; i < vertexDescriptorsLow.get_size(); ++i) {
			rotationGap = std::max(rotationGap, vertexDescriptorsLow.rotors[i].angularDistance(lowLU.rotors[i]));
			lowGap = std::max(lowGap, (vertexDescriptorsLow.deformedPositions[i] - lowLU.deformedPositions[i]).norm());
		}
		for (int i = 0; i < vertexDescriptors.get_size(); ++i) {
			highGap = std::max(highGap, (vertexDescriptors.deformedPositions[i] - highLU.deformedPositions[i]).norm());
		}
	};
	double rd, ld, hd, rp, lp, hp;
	const double directMs = run(1);
	gaps(rd, ld, hd);
	const double pcgMs = run(2);
	gaps(rp, lp, hp);

	std::cout << "max degree of the control mesh: " << g_maxDegreeLow
	          << (g_maxDegreeLow > MAX_ROTATION_DEGREE ? " (rotation system falls back to LU)" : "") << std::endl;
	std::cout << "frame time: LU " << luMs << " ms, Cholesky per step " << directMs << " ms, PCG " << pcgMs
	          << " ms (" << (double)pcgIterations / (3 * frames) << " PCG iterations per local step)" << std::endl;
	std::cout << "largest difference to LU after " << frames << " frames:" << std::endl;
	std::cout << "  Cholesky: rotations " << rd << " rad, control positions " << ld << ", detailed positions " << hd << std::endl;
	std::cout << "  PCG:      rotations " << rp << " rad, control positions " << lp << ", detailed positions " << hp << std::endl;
}
