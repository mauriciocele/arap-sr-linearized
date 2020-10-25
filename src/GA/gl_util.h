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

#ifndef _GL_UTIL_H_
#define _GL_UTIL_H_

#ifdef WIN32
#include <windows.h>
#endif 

#if defined (__APPLE__) || defined (OSX)
	#include <OpenGL/gl.h>
#else
	#include <GL/gl.h>
#endif

#include "e3ga.h"
#include "h3ga.h"
#include "c3ga.h"


void doIntelWarning(); // warn for possible problems with pciking on Intel graphics chipsets

/**
Todo: use GLUproject() instead!
(didn't know it existed...)

Simulates OpenGL 3D -> 2D viewport transform
'ptWorld' is transformed to 'ptViewport'.

pjMatrix, mvMatrix and viewport should be obtained by
glGetDoublev(GL_VIEWPORT, ...), glGetDoublev(GL_PROJECTION_MATRIX, ...) and
glGetDoublev(GL_MODELVIEW_MATRIX, ...), or can be set to NULL.
When NULL, the function will use glGetDoublev(...) itself, which is inefficient
if you call this function a lot of times.
*/
void viewportCoordinates(const GLdouble ptWorld[3], GLdouble ptViewport[2], 
	const GLdouble *pjMatrix = NULL, const GLdouble *mvMatrix = NULL,
	const GLdouble *viewport = NULL);
void viewportCoordinates(const GLfloat ptWorld[3], GLfloat ptViewport[2], 
	const GLfloat *pjMatrix = NULL, const GLfloat *mvMatrix = NULL,
	const GLfloat *viewport = NULL);

void GLmatrixVectorMul(const GLdouble m[16], const GLdouble v[4], GLdouble r[4]);
void GLmatrixVectorMul(const GLfloat m[16], const GLfloat v[4], GLfloat r[4]);

/// Multiplies the current OpenGL matrix with rotor 'v'
void rotorGLMult(const e3ga::rotor &v);
void rotorGLMult(const h3ga::rotor &v);
void rotorGLMult(const c3ga::rotor &v);
//void rotorGLMult(const c3ga::rotor &v);

void versorGLMult(const c3ga::mv &v);

/// Loads color (also into GL 'material' colors, for lighting)
void glColor3fm(float r, float g, float b);
void glColor4fm(float r, float g, float b, float a);

/// Translates a viewport z-value to a world z-value, given _near and _far frustum values.
inline double viewportDepthToWorldCoordinates(double d, double _near, double _far) {
	return -_far*_near / (_far-_near) / (d - 0.5 * (_far+_near)/(_far-_near) - 0.5);
}

/// Translates a viewport z-value to a world z-value, given _near and _far frustum values.
inline double viewportDepthToWorldCoordinates(unsigned int d, double _near, double _far) {
	return viewportDepthToWorldCoordinates((double)d / (unsigned int)0xFFFFFFFF, _near, _far);
}

namespace GLpick {
/// set to 'true' during picking'
extern bool g_pickActive;
/// set to picking window (x, y, w, h) during picking
extern int g_OpenGL_pick[4];
/// must be set correctly by caller of pick() in order to get correct distances returned
extern double g_frustumNear;
/// must be set correctly by caller of pick() in order to get correct distances returned
extern double g_frustumFar;
/// not required for pick(), provided for completenes
extern double g_frustumWidth;
/// not required for pick(), provided for completenes
extern double g_frustumHeight;

/** window size used for the picking (the area searched for a hit)
Actual window size is 1 + 2 * g_pickWinSize.
Default is 4.
*/
extern int g_pickWinSize;

}

/// must be called by the 'drawFunc()' before setting up the projection matrix
void pickLoadMatrix();

/** returns the 'name' of the objects closest to the mouse at [x, y]
Coordinates are OpenGL viewport coordinates (so FLIP the y!)
Calls 'drawFunc()' to get the scene rendered.
(if 'distance' is not NULL, then the distance is returned, too) */
int pick(int x, int y, 
		 void (*drawFunc)(void),
		 float *distance = NULL);

#endif /* _GL_UTIL_H_ */
