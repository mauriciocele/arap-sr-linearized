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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifdef WIN32
#include <windows.h>
#endif

#if defined (__APPLE__) || defined (OSX)
	#include <OpenGL/gl.h>
#else
	#include <GL/gl.h>
#endif

#include "draw.h"
#include "gl_util.h"
#include "e3ga_util.h"
#include "geosphere.h"

using namespace e3ga;

namespace mv_draw {

DrawState g_drawState;

void DrawState::setDrawMode(int mode) {
	m_drawMode[m_drawMode.size()-1] = mode;
}

void DrawState::pushDrawMode(int mode) {
	m_drawMode.push_back(mode);
}

void DrawState::pushDrawModeOff(int mode) {
	m_drawMode.push_back(getDrawMode()^(getDrawMode() & mode));
}

void DrawState::pushDrawModeOn(int mode) {
	m_drawMode.push_back(getDrawMode()|mode);
}

void DrawState::popDrawMode() {
	if (m_drawMode.size() > 1)
		m_drawMode.resize(m_drawMode.size()-1);
}


Palet::Palet() {
	memset(m_fgColor, 0, sizeof(float) * 4);
	memset(m_bgColor, 0, sizeof(float) * 4);
	memset(m_olColor, 0, sizeof(float) * 4);
	m_fgColor[0] = 1.0;
	m_bgColor[1] = 1.0;
	m_fgColor[3] = m_bgColor[3] = m_olColor[3] = 1.0;

}


void Palet::setFgColor() {
	GLfloat ambientColor[4] = {m_fgColor[0] * g_drawState.m_ambient, m_fgColor[1] * g_drawState.m_ambient, m_fgColor[2] * g_drawState.m_ambient, m_fgColor[3]};
	GLfloat diffuseColor[4] = {m_fgColor[0] * g_drawState.m_diffuse, m_fgColor[1] * g_drawState.m_diffuse, m_fgColor[2] * g_drawState.m_diffuse, m_fgColor[3]};
	glColor4f(m_fgColor[0], m_fgColor[1], m_fgColor[2], m_fgColor[3]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuseColor);
}

void Palet::setBgColor() {
	GLfloat ambientColor[4] = {m_bgColor[0] * g_drawState.m_ambient, m_bgColor[1] * g_drawState.m_ambient, m_bgColor[2] * g_drawState.m_ambient, m_bgColor[3]};
	GLfloat diffuseColor[4] = {m_bgColor[0] * g_drawState.m_diffuse, m_bgColor[1] * g_drawState.m_diffuse, m_bgColor[2] * g_drawState.m_diffuse, m_bgColor[3]};
	glColor4f(m_bgColor[0], m_bgColor[1], m_bgColor[2], m_bgColor[3]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuseColor);
}

void Palet::setOlColor() {
	
	GLfloat ambientColor[4] = {m_olColor[0] * g_drawState.m_ambient, m_olColor[1] * g_drawState.m_ambient, m_olColor[2] * g_drawState.m_ambient, m_olColor[3]};
	GLfloat diffuseColor[4] = {m_olColor[0] * g_drawState.m_diffuse, m_olColor[1] * g_drawState.m_diffuse, m_olColor[2] * g_drawState.m_diffuse, m_olColor[3]};
	glColor4f(m_olColor[0], m_olColor[1], m_olColor[2], m_olColor[3]);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuseColor);
}

void Palet::copyColors(const Palet *o) {
	memcpy(m_fgColor, o->m_fgColor, sizeof(float) * 3);
	memcpy(m_bgColor, o->m_bgColor, sizeof(float) * 3);
	memcpy(m_olColor, o->m_olColor, sizeof(float) * 3);
}

void Palet::setFgColor(const float c[4]) {
	memcpy(m_fgColor, c, sizeof(float) * 4);
}
void Palet::setBgColor(const float c[4]) {
	memcpy(m_bgColor, c, sizeof(float) * 4);
}
void Palet::setOlColor(const float c[4]) {
	memcpy(m_olColor, c, sizeof(float) * 4);
}

void Palet::setFgColor(const double c[4]) {
	for (int i = 0; i < 4; i++) m_fgColor[i] = (float)c[i];
}
void Palet::setBgColor(const double c[4]) {
	for (int i = 0; i < 4; i++) m_bgColor[i] = (float)c[i];
}
void Palet::setOlColor(const double c[4]) {
	for (int i = 0; i < 4; i++) m_olColor[i] = (float)c[i];
}

void Palet::setFgAlpha(float alpha) {
	m_fgColor[3] = alpha;
}
void Palet::setBgAlpha(float alpha) {
	m_bgColor[3] = alpha;
}
void Palet::setOlAlpha(float alpha) {
	m_olColor[3] = alpha;
}

// retrieve a component [0 .. 3] from a color
float Palet::fgColor(int idx) {
	return ((idx < 0) || (idx > 3)) ? 0.0f : (m_fgColor[idx]);
}
float Palet::bgColor(int idx) {
	return ((idx < 0) || (idx > 3)) ? 0.0f : (m_bgColor[idx]);
}
float Palet::olColor(int idx) {
	return ((idx < 0) || (idx > 3)) ? 0.0f : (m_olColor[idx]);
}

const float *Palet::fgColor() const {
	return m_fgColor;
}
const float *Palet::bgColor() const {
	return m_bgColor;
}
const float *Palet::olColor() const {
	return m_olColor;
}


void DrawState::drawSphere(e3ga::mv::Float normal) {
	if (m_sphere == NULL) {
		gsCompute(&m_sphere, 4);
		m_sphereGLlist = glGenLists(1);
		glNewList(m_sphereGLlist, GL_COMPILE);
		gsDraw(m_sphere, 0.0f);
		glEndList();
	}
	if (normal == 0.0f) {
		glCallList(m_sphereGLlist);
	}
	else gsDraw(m_sphere, normal);
}

void drawVector(const e3ga::vector &tail, const e3ga::vector &dir, mv::Float scale) {
	GLboolean l;
	const mv::Float rotStep = 2.0f * (mv::Float)M_PI / 32.0f;
	mv::Float z;
	rotor rt, rti;
	e3ga::vector n;

	if (scale == 0.0f) return;

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	if (_Float(norm_e2(tail))) glTranslated(tail.e1(), tail.e2(), tail.e3());
	glScalef(scale, scale, scale);

	// draw the stick of the vector
	glGetBooleanv(GL_LIGHTING, &l);
	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(0.98 * dir.e1(), 0.98 * dir.e2(), 0.98 * dir.e3());
	glEnd();
	if (l) glEnable(GL_LIGHTING);

	glPushMatrix();

	// translate to head of vector
	glTranslated(dir.e1(), dir.e2(), dir.e3());

	if (scale > 1.2f) {// 1.2 = arbitrary constant
		glScalef(1.2f / scale, 1.2f / scale, 1.2f / scale);
		glScalef(1.1f * sqrt(scale), 1.1f * sqrt(scale), 1.1f * sqrt(scale));
	}

	// rotate e3 to vector direction
	rt = rotorFromVectorToVector(_vector(e3), _vector(unit_e(dir)));
	rotorGLMult(rt);

	glEnable(GL_CULL_FACE);
	GLint cl;
	glGetIntegerv(GL_CULL_FACE_MODE, &cl);	
	glCullFace(GL_FRONT);

	rt = _rotor(exp(-0.5f * rotStep * (e1 ^ e2)));
	rti = _rotor(inverse(rt)); 
	n = _vector(e1);
	glBegin(GL_QUADS);
	for (z = 0; z < 2 * M_PI; z += rotStep) {
		glNormal3fv(n.getC(vector_e1_e2_e3));
		glVertex3f(0.1f * (float)cos(z), 0.1f * (float)sin(z), -0.25f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		n = _vector(rt * n * rti);
		glNormal3fv(n.getC(vector_e1_e2_e3));
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.1f * (float)cos(z + rotStep), 0.1f * (float)sin(z + rotStep), -0.25f);
	}
	glEnd();

	n = e1;
	glBegin(GL_TRIANGLE_FAN);
	glNormal3fv(_vector(-e3).getC(vector_e1_e2_e3));
	glVertex3f(0.0f, 0.0f, -0.25f);
	for (z = 0; z <= 2 * M_PI + 1e-3; z += rotStep) {
		glVertex3f(0.1f * (float)cos(z), 0.1f * (float)sin(z), -0.25f);
	}
	glEnd();

	glCullFace(cl);

	glPopMatrix();


	// draw the stick of the vector
/*	glGetBooleanv(GL_LIGHTING, &l);
	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(0.98 * dir[0], 0.98 * dir[1], 0.98 * dir[2]);
	glEnd();
	if (l) glEnable(GL_LIGHTING);*/

	glPopMatrix();
}


void drawBivector(const e3ga::vector &base, const e3ga::vector &normal, 
				 const e3ga::vector &ortho1, const e3ga::vector &ortho2, 
				 e3ga::mv::Float scale, int method /*= DRAW_BV_CIRCLE*/, Palet *o /*= NULL*/) {
	GLboolean l;
	const mv::Float rotStep = 2.0f * (mv::Float)M_PI / 64.0f;
	mv::Float x, y;
	rotor rt;
	e3ga::vector null;

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	if (_Float(norm_e2(base))) glTranslated(base.e1(), base.e2(), base.e3());

//	printf("method = %d %d\n", method, DRAW_BV_PARALLELOGRAM);
//	printf("scale = %f,\n", scale);
	// scale bivector

	if ((method != DRAW_BV_PARALLELOGRAM) &&
		(method != DRAW_BV_PARALLELOGRAM_NO_VECTORS)) {
		glScaled(scale, scale, scale);

		// rotate e3 to normal direction
		rt = rotorFromVectorToVector(_vector(e3), normal);
		rotorGLMult(rt);
	}
	else {
		const e3ga::vector &o1(ortho1);
		const e3ga::vector &o2(ortho2);
		// scale is based on _circle_, re-scale for square:
		double size = scale * scale * M_PI / _Float(norm_e(o1 ^ o2));
		double _scale = sqrt(size);
		glScaled(_scale, _scale, _scale);
	}

	switch(method) {
	case DRAW_BV_CIRCLE:
	case DRAW_BV_CIRCLE_OUTLINE:
		if ((method == DRAW_BV_CIRCLE) && ((o == NULL) || o->fgColor(3) > 0.0))  {
			
			// draw the filled-in circle (back)
			glNormal3d(0.0, 0.0, 1.0);
			glBegin(GL_TRIANGLE_FAN);
			glVertex3d(0.0, 0.0, 0.0);
			for (x = 0; x < M_PI * 2.0 + 0.001; x += rotStep)
				glVertex2d(cos(x), sin(x));
			glEnd();

			// draw the filled-in circle (front)
			glNormal3d(0.0, 0.0, -1.0);
			if (g_drawState.getDrawMode() & OD_ORIENTATION) glPolygonMode(GL_FRONT,  GL_LINE);
			glBegin(GL_TRIANGLE_FAN);
			glVertex3d(0.0, 0.0, 0.0);
			for (x = 0; x < M_PI * 2.0 + 0.001; x += rotStep)
				glVertex2d(-cos(x), sin(x));
			glEnd();
		}

		// draw the outline
		glGetBooleanv(GL_LIGHTING, &l);
		glDisable(GL_LIGHTING);
		if (o) o->setOlColor();
		glBegin(GL_LINE_LOOP);
		for (x = 0; x < M_PI * 2.0; x += rotStep)
			glVertex2d(cos(x), sin(x));
		glEnd();

		if (g_drawState.getDrawMode() & OD_ORIENTATION) {
			// draw 6 little 'hooks' along the edge of the circle
			for (x = 0; x < 6; x++) {
				glBegin(GL_LINES);
				glVertex2d(1.0, 0.0);
				glVertex2d(1.0, -0.5);
				glEnd();
				glRotated(360 / 6, 0.0, 0.0, 1.0);
			}

			// draw a normal vector
/*			glBegin(GL_LINES);
			glVertex3d(0.0, 0.0, 0.0);
			glVertex3d(0.0, 0.0, 1.0);
			glEnd();*/
		}

		if (l) glEnable(GL_LIGHTING);

		break;
	case DRAW_BV_PARALLELOGRAM:
	case DRAW_BV_PARALLELOGRAM_NO_VECTORS:
		// front
		glNormal3fv(normal.getC(vector_e1_e2_e3));
		glBegin(GL_QUADS);
		glVertex3fv(null.getC(vector_e1_e2_e3));
		glVertex3fv(ortho1.getC(vector_e1_e2_e3));
		glVertex3fv(_vector(ortho1 + ortho2).getC(vector_e1_e2_e3) );
		glVertex3fv(ortho2.getC(vector_e1_e2_e3));
		glEnd();

		// back
		/*if ((method != DRAW_BV_PARALLELOGRAM) && 
			(g_drawState.getDrawMode() & OD_ORIENTATION)) glPolygonMode(GL_FRONT,  GL_LINE);*/
		if (g_drawState.getDrawMode() & OD_ORIENTATION) glPolygonMode(GL_FRONT,  GL_LINE);
		glNormal3fv(_vector(-normal).getC(vector_e1_e2_e3));
		glBegin(GL_QUADS);
		glVertex3fv(ortho2.getC(vector_e1_e2_e3));
		glVertex3fv(_vector(ortho1 + ortho2).getC(vector_e1_e2_e3) );
		glVertex3fv(ortho1.getC(vector_e1_e2_e3));
		glVertex3fv(null.getC(vector_e1_e2_e3));
		glEnd();

		// vectors
		if (method != DRAW_BV_PARALLELOGRAM_NO_VECTORS) {
			glPolygonMode(GL_FRONT_AND_BACK, (g_drawState.getDrawMode() & OD_WIREFRAME) ? GL_LINE : GL_FILL);
			if (o) o->setBgColor();
			drawVector(null, ortho1, 1.0);
			if (g_drawState.getDrawMode() & OD_SHADE) glEnable(GL_LIGHTING); // has been turned off by drawVector()
			drawVector(ortho1, ortho2, 1.0);

			// outline 
			/*
			glDisable(GL_LIGHTING);
			if (o) o->setOlColor();
			glBegin(GL_LINE_LOOP);
			glVertex3d(0.0, 0.0, 0.0);
			glVertex3dv(ortho1);
			glVertex3d(ortho1[0] + ortho2[0], ortho1[1] + ortho2[1], ortho1[2] + ortho2[2]);
			glVertex3dv(ortho2);
			glEnd();*/

			// draw a normal vector
			if (g_drawState.getDrawMode() & OD_ORIENTATION) {
				glBegin(GL_LINES);
				glVertex3fv(null.getC(vector_e1_e2_e3));
				glVertex3fv(normal.getC(vector_e1_e2_e3));
				glEnd();
			}
		}

		break;
	case DRAW_BV_CROSS:
		glDisable(GL_LIGHTING);
		for (x = 0; x < 4; x++) {
			glBegin(GL_LINE_STRIP);
			glVertex2f(0.0f, 0.0f);
			glVertex2f(1.0f, 0.0f);
			glVertex2f(1.0f, 1.0f);
			glEnd();
			glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
		}
		break;
	case DRAW_BV_CURLYTAIL:
		glDisable(GL_LIGHTING);
		glBegin(GL_LINE_STRIP);
		for (y = 0; y <= (mv::Float)M_PI *2.0f + 0.001f; y += (mv::Float)M_PI * 2.0f / 64.0f)
			glVertex2d(-sqrt(y / (2 * M_PI)) * sin(y), sqrt(y / (2 * M_PI)) * cos(y));
		glEnd();
		break;
	case DRAW_BV_SWIRL:
		glDisable(GL_LIGHTING);
		for (x = 0; x < 4; x++) {
			glBegin(GL_LINE_STRIP);
			for (y = 0; y <= (mv::Float)M_PI / 2.0f + 0.001f; y += (mv::Float)M_PI / (2.0f * 16.0f)) {
				glVertex2d((1.0 - sin(y)), cos(y));
			}
			glEnd();
			glRotated(90, 0.0, 0.0, 1.0);
		}
		break;
	default:
		glPopMatrix();
		return;
	}

	glPopMatrix();
}

void drawTriVector(const e3ga::vector &base, e3ga::mv::Float scale, const e3ga::vector vc[3], int method /*= DRAW_TV_SPHERE*/, Palet *o /*= NULL*/) {
	mv::Float scaleSign = (scale < 0.0f) ? -1.0f : 1.0f;

	if ((method == DRAW_TV_PARALLELEPIPED) ||
		(method == DRAW_TV_PARALLELEPIPED_NO_VECTORS)) {
		if (vc == NULL) drawTriVector(base, scale, NULL, DRAW_TV_SPHERE, o);

		// adjust scale for cube
		scale = (mv::Float)(scaleSign * pow((double)(scaleSign * scale), 1.0 / 3.0));
	}
	else {
		// adjust scale for sphere
		scale =  (mv::Float)(scaleSign * pow((double)(scaleSign * scale / ((4.0/3.0) * M_PI)), 1.0 / 3.0));
	}

//	printf("Draw scale: %f\n", scale);

	int i, j, vtxIdx;
	mv::Float z, s = (scale < 0.0f) ? -1.0f : 1.0f, f;
	const mv::Float zMax = (mv::Float)(4 * M_PI);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	if (_Float(norm_e2(base))) glTranslated(base.e1(), base.e2(), base.e3());
	glScaled(fabs(scale), fabs(scale), fabs(scale));

	switch(method) {
	case DRAW_TV_SPHERE:
		g_drawState.drawSphere(((g_drawState.getDrawMode() & OD_ORIENTATION) ? s * 0.1f : 0.0f));
		break;
	case DRAW_TV_CROSS:
		if (g_drawState.getDrawMode() & OD_ORIENTATION) glScaled(s, fabs(s), fabs(s));
		glDisable(GL_LIGHTING);
		for (i = 0; i < 3; i++) {
			glBegin(GL_LINE_STRIP);
			glVertex2d(0.5, -1.0);
			glVertex2d(0.0, -1.0);
			glVertex2d(0.0, 1.0);
			glVertex2d(-0.5, 1.0);
			glEnd();
			glRotated(90.0, 0.0, 0.0, 1.0);
			glRotated(-90.0, 1.0, 0.0, 0.0);
		}
		
		break;
	case DRAW_TV_CURLYTAIL:
		// mag & ori nog niet helemaal goed....
		if (g_drawState.getDrawMode() & OD_ORIENTATION) glScaled(s, fabs(s), fabs(s));
		glDisable(GL_LIGHTING);
		glBegin(GL_LINE_STRIP);
		for (z = -zMax; z <= zMax; z += 0.1f) {
			f = z / zMax;
			f = sqrt(1 - f * f);
			glVertex3d(/*s * */1.0 * f * cos(z), 1.0 * f * sin(z), 1.0 * z / zMax);
		}
		glEnd();
		break;

	case DRAW_TV_PARALLELEPIPED:
	case DRAW_TV_PARALLELEPIPED_NO_VECTORS:
		if (g_drawState.getDrawMode() & OD_ORIENTATION) glScaled(s, fabs(s), fabs(s));

		// maybe define vertices of the 'cube'
		{
			mv::Float vertex[8][3];
			int vertexVectors[8][3] = 
			{{-1, -1, -1}, // -
			{0, -1, -1},  // 0
			{0, 1, -1}, // 0 + 1
			{1, -1, -1}, // 1
			{2, -1, -1}, // 2
			{0, 2, -1},  // 0 + 2
			{0, 1, 2}, // 0 + 1 + 2
			{1, 2, -1}}; // 1 + 2
			
			int polygon[6][4] = 
			{{0, 1, 5, 4},
			{0, 4, 7, 3},
			{4, 5, 6, 7},
			{1, 2, 6, 5},
			{6, 2, 3, 7},
			{0, 3, 2, 1}};

			for (i = 0; i < 8; i++) {
				vertex[i][0] = vertex[i][1] = vertex[i][2] = 0.0;
				for (j = 0; j < 3; j++) {
					if ( (vtxIdx = vertexVectors[i][j]) < 0) continue;
					vertex[i][0] += vc[vtxIdx].e1();
					vertex[i][1] += vc[vtxIdx].e2();
					vertex[i][2] += vc[vtxIdx].e3();
				}
			}

			glBegin(GL_QUADS);
			for (i = 0; i < 6; i++) {
				e3ga::vector v1(e3ga::vector_e1_e2_e3, vertex[polygon[i][0]]);
				e3ga::vector v2(e3ga::vector_e1_e2_e3, vertex[polygon[i][1]]);
				e3ga::vector v3(e3ga::vector_e1_e2_e3, vertex[polygon[i][3]]);
				e3ga::vector normal(_vector(dual(scaleSign * ((v2 - v1) ^ (v3 - v1)))));
				glNormal3fv(normal.getC(e3ga::vector_e1_e2_e3));
				if (scale >= 0.0)
					for (j = 0; j < 4; j++) glVertex3fv(vertex[polygon[i][j]]);
				else for (j = 3; j >= 0; j--) glVertex3fv(vertex[polygon[i][j]]);
				
			}
			glEnd();

			if (method == DRAW_TV_PARALLELEPIPED) {
				// draw the vectors
				if (o) o->setBgColor();
				drawVector(e3ga::vector(e3ga::vector_e1_e2_e3, vertex[0]), vc[0], 1.0);
				if (g_drawState.getDrawMode() & OD_SHADE) glEnable(GL_LIGHTING); // has been turned off by drawVector()
				drawVector(e3ga::vector(e3ga::vector_e1_e2_e3, vertex[1]), vc[1], 1.0);
				if (g_drawState.getDrawMode() & OD_SHADE) glEnable(GL_LIGHTING); // has been turned off by drawVector()
				drawVector(e3ga::vector(e3ga::vector_e1_e2_e3, vertex[2]), vc[2], 1.0);
				if (g_drawState.getDrawMode() & OD_SHADE) glEnable(GL_LIGHTING); // has been turned off by drawVector()
			}
		}

		break;
	default:
		glPopMatrix();
	}

	glPopMatrix();

}

void drawLine(const e3ga::vector &pt, const e3ga::vector &dir, float weight, int method /*= 0 */, Palet *o /*= NULL*/) {
	mv::Float scaleConst = g_drawState.m_lineLength; // 4.0f * (mv::Float)sqrt(2.0);
	mv::Float stepSize = 0.1f;

	glDisable(GL_LIGHTING);
	glPushMatrix();
	// translate to point on line 
	glTranslatef(pt.e1(), pt.e2(), pt.e3());

	// rotate e3 to line direction
	rotor rt = rotorFromVectorToVector(_vector(e3), dir);
	rotorGLMult(rt);

	// draw line
	glBegin(GL_LINE_STRIP);
	for (mv::Float z = -scaleConst; z <= scaleConst; z += stepSize * scaleConst)
		glVertex3f(0.0, 0.0, z);
	glEnd();

	// draw 'orientation'
	if (g_drawState.getDrawMode() & OD_ORIENTATION) { 
		// option 3: little hooks 
		glTranslatef(0.0, 0.0, -scaleConst);
		for (mv::Float c = 0.0; c < 1.0; c += stepSize) {
			glPushMatrix();
			// if magnitude: scale
			if (g_drawState.getDrawMode() & OD_MAGNITUDE)
				glScaled(0.5 * fabs(weight), 0.5 * fabs(weight), 0.5 * fabs(weight));
			else glScalef(0.5f, 0.5f, 0.5f);

			glBegin(GL_LINE_STRIP);
			glVertex3f(-0.25f, 0.0f, -1.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.25f, 0.0f, -1.0f);
			glEnd();

			glPopMatrix();
			glRotated(90.0f, 0.0f, 0.0f, 1.0f);
			glTranslated(0.0f, 0.0f, 2.0f * stepSize * scaleConst);
		}
	}
	glPopMatrix();
}

void drawPlane(const e3ga::vector &pt, const e3ga::vector &ortho1, const e3ga::vector &ortho2,
			   const e3ga::vector &normal, float weight, int method /*= 0 */, Palet *o /*= NULL*/) {
	mv::Float scaleConst = g_drawState.m_planeSize; // 4.0f * (mv::Float)sqrt(2.0);
	mv::Float stepSize = 0.1f;

	for (int s = 0; s < 2; s++) { // draw both front and back side individually
		if (s == 0) { // front
			glPolygonMode(GL_FRONT, (g_drawState.getDrawMode() & OD_WIREFRAME) ? GL_LINE : GL_FILL);
			glNormal3fv(normal.getC(vector_e1_e2_e3)); 
		}
		else { // back
			glPolygonMode(GL_FRONT, ((g_drawState.getDrawMode() & OD_WIREFRAME) || 
				(g_drawState.getDrawMode() & OD_ORIENTATION)) ? GL_LINE : GL_FILL);
			glNormal3fv(_vector(-normal).getC(vector_e1_e2_e3)); 
		}
		for (mv::Float y = -scaleConst; y < scaleConst - stepSize * scaleConst; y += stepSize * scaleConst) {
			glBegin(GL_QUAD_STRIP);
			for (mv::Float x = -scaleConst; x < scaleConst; x += stepSize * scaleConst) {
				glVertex3fv(_vector(pt + x * ortho1 + ((s == 1) ? (y + stepSize * scaleConst) : y) * ortho2).getC(vector_e1_e2_e3));
				glVertex3fv(_vector(pt + x * ortho1 + ((s == 0) ? (y + stepSize * scaleConst) : y) * ortho2).getC(vector_e1_e2_e3));
			}
			glEnd();
		}
		glPolygonMode(GL_FRONT, GL_FILL);
	}


	if (g_drawState.getDrawMode() & OD_MAGNITUDE) { // draw normals
		mv::Float scaleMag = weight;
		GLboolean l;
		glGetBooleanv(GL_LIGHTING, &l);
		glDisable(GL_LIGHTING);
		glBegin(GL_LINES);
		for (mv::Float y = -scaleConst; y < scaleConst; y += stepSize * scaleConst) {
			for (mv::Float x = -scaleConst; x < scaleConst; x += stepSize * scaleConst) {
				glVertex3fv(_vector(pt + x * ortho1 + y * ortho2).getC(vector_e1_e2_e3));
				glVertex3fv(_vector(pt + x * ortho1 + y * ortho2 - scaleMag * normal).getC(vector_e1_e2_e3));
			}
		}
		glEnd();
		if (l) glEnable(GL_LIGHTING);
	}

}



} /* end of namespace mv_draw */

