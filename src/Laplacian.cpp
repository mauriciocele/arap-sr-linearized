#include "Laplacian.h"

using namespace std;
using namespace numerics;

double cotangent(const Eigen::Vector3d& a, const Eigen::Vector3d& b, const Eigen::Vector3d& c)
{
	//Vector3 ba = (a - b).norm();
	//Vector3 bc = (c - b).norm();
	//return  1.0 / tan( arc_cosine( ba.dot(bc) ) );

	Eigen::Vector3d ba = a - b;
	Eigen::Vector3d bc = c - b;
	return  (ba.dot(bc))/(ba.cross(bc)).norm();
}

double tanThetaOverTwo(const Eigen::Vector3d& a, const Eigen::Vector3d& b, const Eigen::Vector3d& c)
{
	//Vector3 ba = (b - a).norm();
	//Vector3 bc = (c - a).norm();
	//return  tan( 0.5 * arc_cosine( ba.dot(bc) ) );

	// Return tangent of half the angle between vectors b-a and c-a
	// without using trig functions.
	// Use fact that tan(alpha/2) = (1-cos(alpha)) / sin(alpha).
	// and use scalar and dot products to get cos(alpha) and sin(alpha).
	//  M.F. Apr. 2002.
	Eigen::Vector3d bb = b - a;
	Eigen::Vector3d cc = c - a;

	double cp = (bb.cross(cc)).norm();
		// length of cross product of bb and cc
	double dp = bb.dot(cc); // scalar product of bb and cc
	double bc = bb.norm() * cc.norm();
	return (bc - dp) / cp;
}

double faceArea(const Eigen::Vector3d& a, const Eigen::Vector3d& b, const Eigen::Vector3d& c)
{
    return 0.5 * ((b-a).cross(c-a)).norm();
}

Vertex* GetThirdVertexOnFace( Face *f, Vertex *v1, Vertex *v2)
{
	Vertex*	v[3];
	v[0] = f->edge->vertex;
	v[1] = f->edge->next->vertex;
	v[2] = f->edge->next->next->vertex;
	for( int i = 0 ; i < 3 ; ++i )
		if(v1->ID != v[i]->ID && v2->ID != v[i]->ID)
			return v[i];
	return NULL;
}

double CalcCotangentWeights(Edge* edge)
{
	Face *face1 = edge->face;
	Face *face2 = edge->pair->face;
	Vertex *vi = edge->vertex;
	Vertex *vj = edge->pair->vertex;

	double cotAlpha = 0.0, cotBeta = 0.0;

	if(face1 != NULL)
	{
		Vertex *vk = GetThirdVertexOnFace(face1, vi, vj);
		cotAlpha = cotangent(vi->p, vk->p, vj->p);
	}

	if(face2 != NULL)
	{
		Vertex *vk = GetThirdVertexOnFace(face2, vi, vj);
		cotBeta = cotangent(vi->p, vk->p, vj->p);
	}

	return std::max(0.0, (cotAlpha + cotBeta) / 2.0);
}

double CalcMeanValueWeights(Edge* edge)
{
	Face *face1 = edge->face;
	Face *face2 = edge->pair->face;
	Vertex *vi = edge->vertex;
	Vertex *vj = edge->pair->vertex;

	double tanAlpha = 0.0, tanBeta = 0.0;

	if(face1 != NULL)
	{
		Vertex *vk = GetThirdVertexOnFace(face1, vi, vj);
		tanAlpha = tanThetaOverTwo(vi->p, vk->p, vj->p);
	}

	if(face2 != NULL)
	{
		Vertex *vk = GetThirdVertexOnFace(face2, vi, vj);
		tanBeta = tanThetaOverTwo(vi->p, vk->p, vj->p);
	}

	return std::max(0.0, (tanAlpha + tanBeta) / (vi->p - vj->p).norm());
}

std::shared_ptr<SparseMatrix> CreateLaplacianMatrix(Mesh *mesh, int type)
{
	std::shared_ptr<SparseMatrix> L(new SparseMatrix(mesh->numVertices()));

	for( Edge* edge : mesh->getEdges())
	{
		int i = edge->vertex->ID;
		int j = edge->pair->vertex->ID;
		double wij;
		if(type == LaplaceBeltrami)
			wij = CalcCotangentWeights(edge);
		else if( type == MeanValue )
			wij = CalcMeanValueWeights(edge);
		else
			wij = 1.0; //uniform

		(*L)(i, j) = wij;
		(*L)(j, i) = wij;
	}

	vector<double> areas;
	for(Vertex& vertex : mesh->getVertices())
	{
		int i = vertex.ID;
		double w = 0.0;
		double area = 0.0;
		for(Vertex::EdgeAroundIterator edgeAroundIter = vertex.iterator() ; !edgeAroundIter.end() ; edgeAroundIter++)
		{
			int j = edgeAroundIter.edge_out()->pair->vertex->ID;
			w += (*L)(i, j);

			if(type == LaplaceBeltrami)
			{
				Face	*f = edgeAroundIter.edge_out()->face;
				if(f != NULL)
					area += faceArea(f->edge->vertex->p, f->edge->next->vertex->p, f->edge->next->next->vertex->p);
			}

		}
		(*L)(i, i) = -w;
		if(type == LaplaceBeltrami)
			areas.push_back((fabs(area)>FLT_MIN ? 1.0 : 0.0)); //used to be 1.0 / area
		else
			areas.push_back((fabs(w)>FLT_MIN ? 1.0 / w : 0.0));
	}

	for( int i = 0; i < L->numRows() ; ++i)
	{
		SparseMatrix::mapVect::iterator iter = L->matrix[i].begin();
		SparseMatrix::mapVect::iterator endIter = L->matrix[i].end();

		for( ; iter != endIter ; iter++ )
			iter->second *= areas[i];
	}

	return L;
}
