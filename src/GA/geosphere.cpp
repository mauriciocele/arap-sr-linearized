/*
Some code for generating a geosphere, ported to use vector
instead of LA
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef WIN32
#include <windows.h>
#endif

#if defined (__APPLE__) || defined (OSX)
	#include <OpenGL/gl.h>
#else
	#include <GL/gl.h>
#endif


#include "geosphere.h"

using namespace e3ga;

int gsEnsureVertices(geosphere *sphere, int nb) {
	if (nb <= sphere->maxVertices) {
		return 0;
	}
	else {
		sphere->maxVertices = (sphere->maxVertices * 4 > nb) ? sphere->maxVertices * 4 : nb;
//		printf("->%d vertices\n", sphere->maxVertices);
		vector *oldVertex = sphere->vertex;
		int i;
		if ( (sphere->vertex = new vector[sphere->maxVertices]) == NULL) return -1;
		for (i = 0; i < sphere->nbVertices; i++)
			sphere->vertex[i] = oldVertex[i];
		if (oldVertex) delete[] oldVertex;

		return 0;
	}
}

int gsEnsureFaces(geosphere *sphere, int nb) {
	if (nb <= sphere->maxFaces) {
		return 0;
	}
	else {
		sphere->maxFaces = (sphere->maxFaces * 2 > nb) ? sphere->maxFaces * 2 : nb;
		if ( (sphere->face = (geosphereFace*)realloc(sphere->face, sizeof(geosphereFace) * sphere->maxFaces)) == NULL)
			return -1;
		return 0;
	}
}

int gsAddVertex(geosphere *sphere, vector &pos, int *v) {
	int i, res;
	vector temp;

	*v = -1;

	// first check if vertex already exists
	for (i = 0; i < sphere->nbVertices; i++) {
		temp = pos - sphere->vertex[i];
		if (_Float(norm_e2(temp)) < 1e-5 * 1e-5) {
			*v = i;
			return 0;
		}
	}

	// create new vertex
	if ( (res = gsEnsureVertices(sphere, sphere->nbVertices + 1)) != 0)
		return res;
	
	sphere->vertex[sphere->nbVertices] = pos;
	*v = sphere->nbVertices;
	sphere->nbVertices++;

	return 0;
}

int gsRefineFace(geosphere *sphere, int f, int depth) {
	e3ga::vector v1, v2;
	int v[3], res, i, n;
	geosphereFace *nf;

	if (depth == 0) return 0;

	n = sphere->nbFaces;

	// create 3 vertices
	for (i = 0; i < 3; i++) {
		v1 = unit_e(sphere->vertex[sphere->face[f].v[(i + 0) % 3]] + sphere->vertex[sphere->face[f].v[(i + 1) % 3]]);

		if ( (res = gsAddVertex(sphere, v1, v + i)) != 0)
			return res;
	}

	// allocate four new faces
	if ( (res = gsEnsureFaces(sphere, n + 4)) != 0)
		return res;

	// create four new faces
	nf = sphere->face + n + 0;
	nf->v[0] = sphere->face[f].v[0];
	nf->v[1] = v[0];
	nf->v[2] = v[2];
	nf->depth = sphere->face[f].depth + 1;
	memset(nf->child, -1, sizeof(int) * 4);

	nf = sphere->face + n + 1;
	nf->v[0] = v[0];
	nf->v[1] = sphere->face[f].v[1];
	nf->v[2] = v[1];
	nf->depth = sphere->face[f].depth + 1;
	memset(nf->child, -1, sizeof(int) * 4);

	nf = sphere->face + n + 2;
	nf->v[0] = v[0];
	nf->v[1] = v[1];
	nf->v[2] = v[2];
	nf->depth = sphere->face[f].depth + 1;
	memset(nf->child, -1, sizeof(int) * 4);

	nf = sphere->face + n + 3;
	nf->v[0] = v[1];
	nf->v[1] = sphere->face[f].v[2];
	nf->v[2] = v[2];
	nf->depth = sphere->face[f].depth + 1;
	memset(nf->child, -1, sizeof(int) * 4);

	sphere->nbFaces += 4;

	// set child pointers of face
	for (i = 0; i < 4; i++) sphere->face[f].child[i] = n + i;

	for (i = 0; i < 4; i++) 
		gsRefineFace(sphere, n + i, depth -1);


	return 0;
}

// quadratic timecomplexity algorithm....
void gsComputeNeighbours(geosphere *sphere) {
	int f, e, i, j, n;

	// reset all neighbourship relations
	for (f = 0; f < sphere->nbFaces; f++) {
		for (e = 0; e < 3; e++) {
			sphere->face[f].neighbour[e] = -1;
		}
	}

	// find all neighbourship relations
	for (f = 0; f < sphere->nbFaces; f++) {
		n = 0;
		for (e = 0; e < 3; e++) {
			if (sphere->face[f].neighbour[e] >= 0) {
				n++;
				continue;
			}

			for (i = f + 1; i < sphere->nbFaces; i++) {
				for (j = 0; j < 3; j++) {
					if (sphere->face[f].v[e] == sphere->face[i].v[j]) {
						if (sphere->face[f].v[(e+1)%3] == sphere->face[i].v[(j+1)%3]) {
							sphere->face[f].neighbour[e] = i;
							sphere->face[i].neighbour[j] = f;
							n++;
						}
						else if (sphere->face[f].v[(e+1)%3] == sphere->face[i].v[(j-1+3)%3]) {
							sphere->face[f].neighbour[e] = i;
							sphere->face[i].neighbour[(j-1+3)%3] = f;
							n++;
						}
					}
				}
			}
		}
		if (n != 3)
			fprintf(stderr, "gsComputeNeighbours(): Found only %d neighbours of face %d\n", n, f);
	}

}

int gsCompute(geosphere **sPtr, int depth) {
	int i, j, n;
	geosphere *sphere;
	const int inbFaces = 8;
	const int iF[inbFaces][3] = {
		{5, 0, 2},
		{3, 2, 0},
		{5, 4, 0},
		{4, 3, 0},
		{1, 5, 2},
		{1, 2, 3},
		{1, 3 ,4},
		{1, 4, 5}
	};

	const int inbVertices = 6;
	const mv::Float iV[inbVertices][3] = {
		{0.0f, -1.0f, 0.0f},
		{0.0f, 1.0f, 0.0f},
		{0.707f, 0.0f, 0.707f},
		{0.707f, 0.0f, -0.707f},
		{-0.707f, 0.0f, -0.707f},
		{-0.707f, 0.0f, 0.707f},
	};
	

	// allocate resources
	if ( (*sPtr = sphere = (geosphere *)calloc(1, sizeof(geosphere))) == NULL) {
		return -1;
	}
	gsEnsureFaces(sphere, inbFaces);
	gsEnsureVertices(sphere, inbVertices);

	// set initial geometry
	for (i = 0; i < inbFaces; i++) {
		for (j = 0;  j < 3; j++)
			sphere->face[i].v[j] = iF[i][j];
		for (j = 0;  j < 3; j++)
			sphere->face[i].child[j] = -1;
		sphere->face[i].depth = 0;
	}
	sphere->nbFaces = sphere->nbPrimitives = inbFaces;
	for (i = 0; i < inbVertices; i++) {
		sphere->vertex[i].set(vector_e1_e2_e3,  iV[i]);
//		sphere->vertex[i] *= 0.
	}
	sphere->nbVertices = inbVertices;
	
	// refine each face
	n = sphere->nbFaces;
	for (i = 0; i < n; i++) {
		gsRefineFace(sphere, i, depth);
	}

	sphere->depth = depth;

	gsComputeNeighbours(sphere);

	return 0;
}

int gsFree(geosphere **sPtr) {
	geosphere *sphere = *sPtr;
	*sPtr = NULL;
	if (sphere == NULL) return 0;

	free(sphere->face);
	delete[] sphere->vertex;

	free(sphere);
	return 0;
}


void gsDraw(geosphere * sphere, int f, mv::Float normal = 0.0) {
	int i;
	vector v1;

	if (sphere->face[f].child[0] >= 0) {
		for (i = 0; i < 4; i++)
			gsDraw(sphere, sphere->face[f].child[i], normal);
	}
	else {

		glBegin(GL_TRIANGLES);
		for (i = 0; i < 3; i++) {
			glNormal3fv(sphere->vertex[sphere->face[f].v[i]].getC(vector_e1_e2_e3));
			glVertex3fv((sphere->vertex[sphere->face[f].v[i]]).getC(vector_e1_e2_e3));
		}
		glEnd();

		if (normal != 0.0) {
			GLboolean l;
			glGetBooleanv(GL_LIGHTING, &l);
			glDisable(GL_LIGHTING);
			glBegin(GL_LINES);
			for (i = 0; i < 3; i++) {
				v1 = unit_e(sphere->vertex[sphere->face[f].v[i]]);
				glVertex3fv((sphere->vertex[sphere->face[f].v[i]]).getC(vector_e1_e2_e3));
				glVertex3fv(_vector(sphere->vertex[sphere->face[f].v[i]] + v1 * normal).getC(vector_e1_e2_e3));
			}
			glEnd();
			if (l) glEnable(GL_LIGHTING);
		}
	}
}


void gsDraw(geosphere * sphere, mv::Float normal /*= 0.0*/) {
	int i;
	for (i = 0; i < sphere->nbPrimitives; i++)
		gsDraw(sphere, i, normal);
}

