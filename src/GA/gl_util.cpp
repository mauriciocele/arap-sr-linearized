// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

// Copyright 2007, Daniel Fontijne, University of Amsterdam -- fontijne@science.uva.nl


#include <string>

#include "gl_util.h"
#if defined (__APPLE__) || defined (OSX)
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

void doIntelWarning() {
	static bool warned = false;
	if (!warned) {
		warned = true;
		const GLubyte *vendor = glGetString(GL_VENDOR);
		const GLubyte *renderer = glGetString(GL_RENDERER);
		std::string ren((const char*)renderer);
		if (std::string((const char*)vendor).find("ntel") != std::string::npos) {
			printf("General warning: OpenGL picking seems to be broken on integrated Intel graphics chipset.\n");
			printf("At least on the 945 chipset which I tested (on Windows XP).\n");
			printf("This computer seems to have %s:%s\n", vendor, renderer);
			printf("This may affect dragging, creation and orbitting operations.\n");
		}
	}
}


void viewportCoordinates(const GLdouble ptWorld[3], GLdouble ptViewport[2], 
	const GLdouble *pjMatrix /* = NULL */, const GLdouble *mvMatrix/* = NULL */,
	const GLdouble *viewport /* = NULL */) {
	
	GLdouble _pjMatrix[16];
	GLdouble _mvMatrix[16];
	GLdouble _viewport[4];
	if (pjMatrix == NULL) {
		pjMatrix = _pjMatrix;
		glGetDoublev(GL_PROJECTION_MATRIX, _pjMatrix);
	}
	if (mvMatrix == NULL) {
		mvMatrix = _mvMatrix;
		glGetDoublev(GL_MODELVIEW_MATRIX, _mvMatrix);
	}
	if (viewport == NULL) {
		viewport = _viewport;
		glGetDoublev(GL_VIEWPORT, _viewport);
	}
		
	GLdouble pt1[4], pt2[4];
	pt1[0] = ptWorld[0]; pt1[1] = ptWorld[1]; pt1[2] = ptWorld[2]; pt1[3] = 1;
	GLmatrixVectorMul(mvMatrix, pt1, pt2);
	GLmatrixVectorMul(pjMatrix, pt2, pt1);
	ptViewport[0] = (pt1[0] / pt1[3] + 1.0) * viewport[2] / 2.0 + viewport[0];
	ptViewport[1] = (pt1[1] / pt1[3] + 1.0) * viewport[3] / 2.0 + viewport[1];	
}

void viewportCoordinates(const GLfloat ptWorld[3], GLfloat ptViewport[2], 
	const GLfloat *pjMatrix /* = NULL */, const GLfloat *mvMatrix/* = NULL */,
	const GLfloat *viewport /* = NULL */) {
	
	GLfloat _pjMatrix[16];
	GLfloat _mvMatrix[16];
	GLfloat _viewport[4];
	if (pjMatrix == NULL) {
		pjMatrix = _pjMatrix;
		glGetFloatv(GL_PROJECTION_MATRIX, _pjMatrix);
	}
	if (mvMatrix == NULL) {
		mvMatrix = _mvMatrix;
		glGetFloatv(GL_MODELVIEW_MATRIX, _mvMatrix);
	}
	if (viewport == NULL) {
		viewport = _viewport;
		glGetFloatv(GL_VIEWPORT, _viewport);
	}
		
	GLfloat pt1[4], pt2[4];
	pt1[0] = ptWorld[0]; pt1[1] = ptWorld[1]; pt1[2] = ptWorld[2]; pt1[3] = 1;
	GLmatrixVectorMul(mvMatrix, pt1, pt2);
	GLmatrixVectorMul(pjMatrix, pt2, pt1);
	ptViewport[0] = (pt1[0] / pt1[3] + 1.0) * viewport[2] / 2.0 + viewport[0];
	ptViewport[1] = (pt1[1] / pt1[3] + 1.0) * viewport[3] / 2.0 + viewport[1];

	
}

void GLmatrixVectorMul(const GLdouble m[16], const GLdouble v[4], GLdouble r[4]) {
/*	int i, j;
	for (i = 0; i < 4; i++) {
		r[i] = 0;
		for (j = 0; j < 4; j++)
			r[i] += m[j * 4 + i] * v[j];
	}*/
	r[0] = m[0 * 4 + 0] * v[0] + m[1 * 4 + 0] * v[1] + m[2 * 4 + 0] * v[2] + m[3 * 4 + 0] * v[3];
	r[1] = m[0 * 4 + 1] * v[0] + m[1 * 4 + 1] * v[1] + m[2 * 4 + 1] * v[2] + m[3 * 4 + 1] * v[3];
	r[2] = m[0 * 4 + 2] * v[0] + m[1 * 4 + 2] * v[1] + m[2 * 4 + 2] * v[2] + m[3 * 4 + 2] * v[3];
	r[3] = m[0 * 4 + 3] * v[0] + m[1 * 4 + 3] * v[1] + m[2 * 4 + 3] * v[2] + m[3 * 4 + 3] * v[3];
	
}

void GLmatrixVectorMul(const GLfloat m[16], const GLfloat v[4], GLfloat r[4]) {
/*	int i, j;
	for (i = 0; i < 4; i++) {
		r[i] = 0;
		for (j = 0; j < 4; j++)
			r[i] += m[j * 4 + i] * v[j];
	}*/
	r[0] = m[0 * 4 + 0] * v[0] + m[1 * 4 + 0] * v[1] + m[2 * 4 + 0] * v[2] + m[3 * 4 + 0] * v[3];
	r[1] = m[0 * 4 + 1] * v[0] + m[1 * 4 + 1] * v[1] + m[2 * 4 + 1] * v[2] + m[3 * 4 + 1] * v[3];
	r[2] = m[0 * 4 + 2] * v[0] + m[1 * 4 + 2] * v[1] + m[2 * 4 + 2] * v[2] + m[3 * 4 + 2] * v[3];
	r[3] = m[0 * 4 + 3] * v[0] + m[1 * 4 + 3] * v[1] + m[2 * 4 + 3] * v[2] + m[3 * 4 + 3] * v[3];
	
}

/// Multiplies the current OpenGL matrix with rotor 'v'
void rotorGLMult(const e3ga::rotor &v) {
	// compute the images of all OpenGL basis vectors
	e3ga::vector image[4] = {
			e3ga::_vector(v * e3ga::e1 * inverse(v)), // image of e1
			e3ga::_vector(v * e3ga::e2 * inverse(v)), // image of e2
			e3ga::_vector(v * e3ga::e3 * inverse(v)), // image of e3
			e3ga::vector() // 'image of origin'
	};

	// transfer the coordinates to the OpenGL matrix
	GLfloat GLmatrix[16];
	for (int i = 0; i < 4; i++) {
		const e3ga::vector &vc(image[i]);
		GLmatrix[i * 4 + 0] = vc.e1();
		GLmatrix[i * 4 + 1] = vc.e2();
		GLmatrix[i * 4 + 2] = vc.e3();
		GLmatrix[i * 4 + 3] = (i == 3) ? 1.0f : 0.0f;
	}

	/*printf("Knock knock. The matrix has you: \n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%f ", GLmatrix[j * 4 + i]);
		}
		printf("\n");
	}*/

	// multiply current OpenGL matrix:
	glMultMatrixf(GLmatrix);
}

void rotorGLMult(const h3ga::rotor &v) {
	rotorGLMult(e3ga::rotor(e3ga::rotor_scalar_e1e2_e2e3_e3e1, v.getC(h3ga::rotor_scalar_e1e2_e2e3_e3e1)));
}


void rotorGLMult(const c3ga::rotor &v) {
	rotorGLMult(e3ga::rotor(e3ga::rotor_scalar_e1e2_e2e3_e3e1, v.getC(c3ga::rotor_scalar_e1e2_e2e3_e3e1)));
}

void versorGLMult(const c3ga::mv &V) {
	c3ga::mv Vi(inverse(V));

	// compute images of basis vectors:
	c3ga::flatPoint imageOfE1NI = _flatPoint(V * c3ga::e1ni * Vi);
	c3ga::flatPoint imageOfE2NI = _flatPoint(V * c3ga::e2ni * Vi);
	c3ga::flatPoint imageOfE3NI = _flatPoint(V * c3ga::e3ni * Vi);
	c3ga::flatPoint imageOfNONI = _flatPoint(V * c3ga::noni * Vi);

	// create matrix representation:
	c3ga::omFlatPoint M(imageOfE1NI, imageOfE2NI, imageOfE3NI, imageOfNONI);

	// multiply current OpenGL matrix:
	glMultMatrixf(M.m_c);
}


/// Loads color (also into GL 'material' colors, for lighting)
void glColor3fm(float r, float g, float b) {
	const float af = 0.3f;
	float amb[4] = {af * r, af*g, af*b, 1};
	const float df = 0.7f;
	float dif[4] = {df * r, df*g, df*b, 1};

	glColor3f(r, g, b);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, dif);
}

/// Loads color (also into GL 'material' colors, for lighting)
void glColor4fm(float r, float g, float b, float a) {
	const float af = 0.3f;
	float amb[4] = {af * r, af*g, af*b, a};
	const float df = 0.7f;
	float dif[4] = {df * r, df*g, df*b, a};

	glColor4f(r, g, b, a);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, dif);
}

namespace GLpick {
bool g_pickActive = false;
int g_OpenGL_pick[4] = {0, 0, 0, 0};
double g_frustumNear = 1.0;
double g_frustumFar = 100.0;
double g_frustumWidth = -1.0;
double g_frustumHeight = -1.0;

int g_pickWinSize = 4;
}

void pickLoadMatrix() {
	if (!GLpick::g_pickActive) return;

	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	gluPickMatrix(
		GLpick::g_OpenGL_pick[0], GLpick::g_OpenGL_pick[1], 
		GLpick::g_OpenGL_pick[2] * 2 + 1, GLpick::g_OpenGL_pick[3] * 2 + 1, 
		viewport);
}


/** returns the 'name' of the objects closest to the mouse at [x, y]
Coordinates are OpenGL viewport coordinates (so FLIP the y!)
Calls 'drawFunc()' to get the scene rendered.
(if 'distance' is not NULL, then the distance is returned, too) */
int pick(int x, int y, 
		 void (*drawFunc)(void),
		 float *distance /*= NULL*/) {
	GLpick::g_pickActive = true;
	// set pick location
	GLpick::g_OpenGL_pick[0] = x;
	GLpick::g_OpenGL_pick[1] = y;
	// set pick window size
	GLpick::g_OpenGL_pick[2] = GLpick::g_pickWinSize; // g_pickWinSize * 2 + 1 pixels
	GLpick::g_OpenGL_pick[3] = GLpick::g_pickWinSize;

	const int nb_of_objects = 10; 
	// allocate select buffer
	GLuint *sb = new GLuint[nb_of_objects * 4];
	//sb.resize(nb_of_objects * 4);

	// set select buffer, set render mode to select
	glSelectBuffer(nb_of_objects * 4, &(sb[0]));
	glRenderMode(GL_SELECT);

	// initialize OpenGL picking names 
	glInitNames();
	glPushName((GLuint)-1);

	drawFunc();

	// get the number of hit records by returning to normal 'render mode'
	int nbHits = glRenderMode(GL_RENDER);

	/*
	OpenGL hits records are:
	-number of names on the name stack (we make sure that we have only one name on the stack)
	-minimum z of hit
	-maximum z of hit
	-name of object 
	*/

	GLpick::g_pickActive = false;
	if (nbHits <= 0) {
		delete[] sb;
		return -1;
	}

	int closestObject = -1;
	float minD = (float)GLpick::g_frustumFar;
	for (int i = 0; i < nbHits; i++) {
		if ((int)sb[i * 4 + 3] < 0) continue;
		float d1 = viewportDepthToWorldCoordinates(sb[i * 4 + 1], GLpick::g_frustumNear, GLpick::g_frustumFar);
		float d2 = viewportDepthToWorldCoordinates(sb[i * 4 + 2], GLpick::g_frustumNear, GLpick::g_frustumFar);
		float d = 0.5 * (d1 + d2);
		if (d < minD) {
			minD = d;
			closestObject = (int)sb[i * 4 + 3];
		}
	}

	if (distance) *distance = minD;

	delete[] sb;

	return closestObject;
}
