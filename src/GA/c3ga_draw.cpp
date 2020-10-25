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

#ifdef WIN32
#include <windows.h>
#endif

#if defined (__APPLE__) || defined (OSX)
	#include <OpenGL/gl.h>
#else
	#include <GL/gl.h>
#endif

#include "c3ga_draw.h"
#include "e3ga_util.h"
#include "mv_analyze.h"

using namespace mv_analyze;

namespace mv_draw {

using namespace e3ga;


// test all done so far . . .
// 4 points, and sphere, line, plane, etc thorugh them . .. 
// 
void drawFlat(const mvAnalysis &A, int method = 0, Palet *o = NULL) {
	if (A.bladeSubclass() == mvAnalysis::POINT) {
		GLboolean l;
		glGetBooleanv(GL_LIGHTING, &l);
		glDisable(GL_LIGHTING);
		g_drawState.pushDrawModeOff(OD_ORIENTATION);
		e3ga::mv::Float scale = pow(g_drawState.m_pointSize, 3) * ((4.0f/3.0f) * (float)M_PI);
		drawTriVector(A.m_pt[0], scale, NULL, DRAW_TV_SPHERE, o);
		g_drawState.popDrawMode();
		if (l) glEnable(GL_LIGHTING);
	}
	else if (A.bladeSubclass() == mvAnalysis::LINE) {
		drawLine(A.m_pt[0], A.m_vc[0], A.m_sc[0], method, o);
	}
	else if (A.bladeSubclass() == mvAnalysis::PLANE) {
		drawPlane(A.m_pt[0], A.m_vc[0], A.m_vc[1], A.m_vc[2], A.m_sc[0], method, o);
	}
}

void drawRound(const mvAnalysis &A, int method = 0, Palet *o = NULL) {
	// todo test if all of these get drawn correctly!:
	if (A.bladeSubclass() == mvAnalysis::POINT_PAIR) {
		GLboolean l;
		glGetBooleanv(GL_LIGHTING, &l);
		glDisable(GL_LIGHTING);
		g_drawState.pushDrawModeOff(OD_ORIENTATION);
		e3ga::mv::Float scale = pow(g_drawState.m_pointSize, 3) * ((4.0f/3.0f) * (float)M_PI);
		drawTriVector(_vector(A.m_pt[0] + A.m_sc[0] * A.m_vc[0]), scale, NULL, DRAW_TV_SPHERE, o);
		drawTriVector(_vector(A.m_pt[0] - A.m_sc[0] * A.m_vc[0]), scale, NULL, DRAW_TV_SPHERE, o);
		g_drawState.popDrawMode();
		if (l) glEnable(GL_LIGHTING);
	}
	else if (A.bladeSubclass() == mvAnalysis::CIRCLE) {
//		glLineWidth(2.0f);
		int method = DRAW_BV_CIRCLE_OUTLINE;
		drawBivector(A.m_pt[0], A.m_vc[2], A.m_vc[0], A.m_vc[1], A.m_sc[0], method, o);
//		glLineWidth(1.0f);
	}
	else if (A.bladeSubclass() == mvAnalysis::SPHERE) {
//		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		e3ga::mv::Float scale = pow(A.m_sc[0], 3) * ((4.0f/3.0f) * (float)M_PI);
		drawTriVector(_vector(A.m_pt[0]), scale, NULL, DRAW_TV_SPHERE, o);
//		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}

void drawTangent(const mvAnalysis &A, int method = 0, Palet *o = NULL) {
	if (A.bladeSubclass() == mvAnalysis::SCALAR) {
		GLboolean l;
		glGetBooleanv(GL_LIGHTING, &l);
		glDisable(GL_LIGHTING);
		g_drawState.pushDrawModeOff(OD_ORIENTATION);
		e3ga::mv::Float scale = pow(g_drawState.m_pointSize, 3) * ((4.0f/3.0f) * (float)M_PI);
		drawTriVector(A.m_pt[0], scale, NULL, DRAW_TV_SPHERE, o);
		g_drawState.popDrawMode();
		if (l) glEnable(GL_LIGHTING);
	}
	
	else if (A.bladeSubclass() == mvAnalysis::VECTOR) {
		drawVector(A.m_pt[0], A.m_vc[0], A.m_sc[0]);
	}
	else if (A.bladeSubclass() == mvAnalysis::BIVECTOR) {
		e3ga::mv::Float scale = (e3ga::mv::Float)sqrt(A.m_sc[0] / M_PI);
		drawBivector(A.m_pt[0], A.m_vc[2], A.m_vc[0], A.m_vc[1], 
				 scale, method, o);
	}
	else if (A.bladeSubclass() == mvAnalysis::TRIVECTOR) {
		drawTriVector(A.m_pt[0],  A.m_sc[0], A.m_vc, method, o);
	}


}

namespace {
GLubyte s_polygonStipplePattern[] = {
	0X33, 0X33, 0X33, 0X33, 0X33, 0X33, 0X33, 0X33, 
	0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 
	0X33, 0X33, 0X33, 0X33, 0X33, 0X33, 0X33, 0X33, 
	0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 
	0X33, 0X33, 0X33, 0X33, 0X33, 0X33, 0X33, 0X33, 
	0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 
	0X33, 0X33, 0X33, 0X33, 0X33, 0X33, 0X33, 0X33, 
	0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 
	0X33, 0X33, 0X33, 0X33, 0X33, 0X33, 0X33, 0X33, 
	0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 
	0X33, 0X33, 0X33, 0X33, 0X33, 0X33, 0X33, 0X33, 
	0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 
	0X33, 0X33, 0X33, 0X33, 0X33, 0X33, 0X33, 0X33, 
	0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 
	0X33, 0X33, 0X33, 0X33, 0X33, 0X33, 0X33, 0X33, 
	0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 0XCC, 0XCC
};
}

void drawFree(const mvAnalysis &A, int method = 0, Palet *o = NULL) {
	glLineStipple(1, 0x0F0F);
	glPolygonStipple(s_polygonStipplePattern);

	glEnable(GL_POLYGON_STIPPLE);
	glEnable(GL_LINE_STIPPLE);

	if (A.bladeSubclass() == mvAnalysis::VECTOR) {
		drawVector(e3ga::vector(), A.m_vc[0], A.m_sc[0]);
	}
	else if (A.bladeSubclass() == mvAnalysis::BIVECTOR) {
		e3ga::mv::Float scale = (e3ga::mv::Float)sqrt(A.m_sc[0] / M_PI);
		drawBivector(e3ga::vector(), A.m_vc[2], A.m_vc[0], A.m_vc[1], scale, method, o);
	}
	else if (A.bladeSubclass() == mvAnalysis::TRIVECTOR) {
		drawTriVector(e3ga::vector(),  A.m_sc[0], A.m_vc, method, o);
	}

	glDisable(GL_LINE_STIPPLE);
	glDisable(GL_POLYGON_STIPPLE);
}



void drawC3GA(const mv_analyze::mvAnalysis &A, int method/*= 0*/, Palet *o/* = NULL*/) {
	if (A.model() != mvAnalysis::CONFORMAL_MODEL)
		return;

	switch(A.bladeClass()) {
	case mvAnalysis::PSEUDOSCALAR:
	case mvAnalysis::SCALAR:
	case mvAnalysis::ZERO:
		return;
	case mvAnalysis::FLAT:
		drawFlat(A, method, o);
		return;
	case mvAnalysis::ROUND:
		drawRound(A, method, o);
		return;
	case mvAnalysis::TANGENT:
		drawTangent(A, method, o);
		return;
	case mvAnalysis::FREE:
		drawFree(A, method, o);
		return;
	}

}

void draw(const c3ga::mv &X, int method/*= 0*/, Palet *o/* = NULL*/) {
	mv_analyze::mvAnalysis A(X);
	drawC3GA(A, method, o);
}

/// same as above, but with option to set analysis epsilon
void draw(const c3ga::mv &X, double epsilon, int method/*= 0*/, Palet *o/* = NULL*/) {
	const int intFlags = 0;
	mv_analyze::mvAnalysis A(X, intFlags, epsilon);
	drawC3GA(A, method, o);
}



/*
normalizedPoint labelPositionPoint(const mvAnalysis &A, unsigned int labelGenerator) {
	double r = POINT_SIZE + 2.0 * POINT_SIZE * (double)(labelGenerator % 5) / 4; // distance to center point
	double a1 = 2.0 * M_PI * (double)((labelGenerator / 5) % 11) / 10;
	double a2 = 2.0 * M_PI * (double)((labelGenerator / (5*11)) % 11) / 10;

	rotor R = _rotor(exp(a1 * (e1 ^ e2)) * exp(a2 * (e2 ^ e3)));
	freeVector t = _freeVector((r * _vectorE3GA(R * e3 * inverse(R))) ^ ni);
	translator T = _translator(1.0 - 0.5 * t);

	return _normalizedPoint(T * A.m_pt[0] * inverse(T));
}


normalizedPoint labelPositionFlat(const mvAnalysis &A, unsigned int labelGenerator) {
	if (A.bladeSubclass() == mvAnalysis::POINT) {
		return labelPositionPoint(A, labelGenerator);
	}
	else if (A.bladeSubclass() == mvAnalysis::LINE) {
		double a1 = -1.0 + 2.0 * (double)(labelGenerator % 31) / 30.0;

		freeVector t = _freeVector((m_lineLength * a1 * A.m_vc[0]) ^ ni);
		translator T = _translator(1.0 - 0.5 * t);
		return _normalizedPoint(T * A.m_pt[0] * inverse(T));
	}
	else if (A.bladeSubclass() == mvAnalysis::PLANE) {
		double a1 = -1.0 + 2.0 * (double)(labelGenerator % 31) / 30.0;
		double r1 =  2 * M_PI * (double)((labelGenerator / 31) % 4) / 4.0;

		

		freeVector t = _freeVector((0.5 * m_planeSize * A.m_vc[0] + a1 * 0.5 * m_planeSize * A.m_vc[1]) ^ ni);
		rotor R = _rotor(exp(0.5 * r1 * (A.m_vc[0] ^ A.m_vc[1])));
		t = _freeVector(R * t * inverse(R));
		translator T = _translator(1.0 - 0.5 * t);
		return _normalizedPoint(T * A.m_pt[0] * inverse(T));
	}

	throw -1;
}

normalizedPoint labelPositionRound(const mvAnalysis &A, unsigned int labelGenerator) {
	if (A.bladeSubclass() == mvAnalysis::POINT_PAIR) {
		translator T;
		double shift = -0.5 + (double)((labelGenerator / 51) % 11) / 10.0;
			
		if ((labelGenerator % 51) & 1)
			T = _translator(1.0 - (0.5 * A.m_sc[0] + shift * POINT_SIZE) * (A.m_vc[0] ^ ni));
		else T = _translator(1.0 + (0.5 * A.m_sc[0] + shift * POINT_SIZE) * (A.m_vc[0] ^ ni));

		return _normalizedPoint(T * A.m_pt[0] * inverse(T));
	}
	else if (A.bladeSubclass() == mvAnalysis::CIRCLE) {
		double alpha = (double)(labelGenerator % 31) / 30.0;
		freeVector t = _freeVector((A.m_sc[0] * (cos(alpha) * A.m_vc[0] + sin(alpha) * A.m_vc[1])) ^ ni);
		translator T = _translator(1.0 - 0.5 * t);

		return _normalizedPoint(T * A.m_pt[0] * inverse(T));
	}
	else if (A.bladeSubclass() == mvAnalysis::SPHERE) {
		double r = A.m_sc[0]; // distance to center point
		double a1 = 2.0 * M_PI * (double)((labelGenerator / 5) % 11) / 10;
		double a2 = 2.0 * M_PI * (double)((labelGenerator / (5*11)) % 11) / 10;

		rotor R = _rotor(exp(a1 * (e1 ^ e2)) * exp(a2 * (e2 ^ e3)));
		freeVector t = _freeVector((r * _vectorE3GA(R * e3 * inverse(R))) ^ ni);
		translator T = _translator(1.0 - 0.5 * t);

		return _normalizedPoint(T * A.m_pt[0] * inverse(T));
	}
	

	throw -1;
}

normalizedPoint labelPositionTangentOrFree(const mvAnalysis &A, unsigned int labelGenerator, const normalizedPoint &pt) {
	if (A.bladeSubclass() == mvAnalysis::SCALAR) {
		return labelPositionPoint(A, labelGenerator);
	}
	else if (A.bladeSubclass() == mvAnalysis::VECTOR) {
		double a1 = (double)(labelGenerator % 31) / 30.0;

		freeVector t = _freeVector((A.m_sc[0] * a1 * A.m_vc[0]) ^ ni);
		translator T = _translator(1.0 - 0.5 * t);
		return _normalizedPoint(T * pt * inverse(T));
	}
	else if (A.bladeSubclass() == mvAnalysis::BIVECTOR) {
		double alpha = (double)(labelGenerator % 31) / 30.0;
		double r2 = A.m_sc[0] / M_PI;
		double r = sqrt(r2);

		freeVector t = _freeVector((r * (cos(alpha) * A.m_vc[0] + sin(alpha) * A.m_vc[1])) ^ ni);
		translator T = _translator(1.0 - 0.5 * t);

		return _normalizedPoint(T *pt * inverse(T));
	}
	else if (A.bladeSubclass() == mvAnalysis::TRIVECTOR) {
		double r3 = A.m_sc[0] * 3 / (4 * M_PI);
		double r = 0.5 * pow(r3, 1.0/3.0); // distance to center point
		double a1 = 2.0 * M_PI * (double)((labelGenerator / 5) % 11) / 10;
		double a2 = 2.0 * M_PI * (double)((labelGenerator / (5*11)) % 11) / 10;

		rotor R = _rotor(exp(a1 * (e1 ^ e2)) * exp(a2 * (e2 ^ e3)));
		freeVector t = _freeVector((r * _vectorE3GA(R * e3 * inverse(R))) ^ ni);
		translator T = _translator(1.0 - 0.5 * t);

		return _normalizedPoint(T * pt * inverse(T));
	}

	throw -1;
}


normalizedPoint labelPositionTangent(const mvAnalysis &A, unsigned int labelGenerator) {
	return labelPositionTangentOrFree(A, labelGenerator, A.m_pt[0]);
}


normalizedPoint labelPositionFree(const mvAnalysis &A, int labelGenerator) {
	return labelPositionTangentOrFree(A, labelGenerator, _normalizedPoint(no));
}


normalizedPoint labelPosition(const mvAnalysis &A, int labelGenerator) {
	if (A.model() != mvAnalysis::CONFORMAL)
		throw -1;

	switch(A.bladeClass()) {
	case mvAnalysis::SCALAR:
	case mvAnalysis::ZERO:
		throw -1;
	case mvAnalysis::FLAT:
		return labelPositionFlat(A, labelGenerator);
	case mvAnalysis::ROUND:
		return labelPositionRound(A, labelGenerator);
	case mvAnalysis::TANGENT:
		return labelPositionTangent(A, labelGenerator);
	case mvAnalysis::FREE:
		return labelPositionFree(A, labelGenerator);
	}
	throw -1;
}
*/

} // end of namespace mv_draw

