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

#include "e3ga_draw.h"
#include "e3ga_util.h"
#include "mv_analyze.h"

using namespace mv_analyze;

namespace mv_draw {

using namespace e3ga;

void draw(const e3ga::mv &X, int method /* = 0*/, Palet *o /*= NULL*/) {
	mvAnalysis A(X);

	if (A.isBlade()) {
		switch (A.bladeSubclass()) {
			case mvAnalysis::VECTOR:
				{
					drawVector(e3ga::vector(), A.m_vc[0], A.m_sc[0]);
				}
				break;
			case mvAnalysis::BIVECTOR:
				{
					e3ga::mv::Float scale = 
						(g_drawState.getDrawMode() & OD_MAGNITUDE) 
						? (e3ga::mv::Float)sqrt(fabs(A.m_sc[0]) / M_PI) 
						: 1.0f;

					drawBivector(e3ga::vector(), A.m_vc[2], A.m_vc[0], A.m_vc[1], scale, method, o);
				}
				break;
			case mvAnalysis::TRIVECTOR:
				{
					drawTriVector(e3ga::vector(), A.m_sc[0],  A.m_vc, method, o);
				}
				break;
		}
	}
	else if (A.isVersor()) {
		if (A.versorSubclass() == mvAnalysis::ROTOR) {
			// todo: share this code with other algebras!. . .  DO NOT DUPLICATE!
			if (A.m_sc[0] > 0.0001) {
				mv::Float scale = (g_drawState.getDrawMode() & OD_MAGNITUDE)
					? (mv::Float)sqrt(fabs(A.m_sc[0]) / M_PI) : 1.0f;
				
				// draw plane of rotation
				glPolygonMode(GL_FRONT_AND_BACK, (g_drawState.getDrawMode() & OD_WIREFRAME) ? GL_LINE : GL_FILL);
				g_drawState.pushDrawModeOff(OD_ORIENTATION);
				drawBivector(e3ga::vector(), A.m_vc[2], A.m_vc[0], A.m_vc[1], A.m_sc[0], DRAW_BV_CIRCLE, o);
				g_drawState.popDrawMode();

				// draw 'angle of rotation'
				if (o) o->setOlColor();
				else glColor3f(0.0, 0.0, 0.0);
				e3ga::vector v = A.m_vc[0]; // vector in rotation plane
				
				bivector b = _bivector(-dual(A.m_vc[2])); // rotation plane 
				v = _vector(unit_e(v) * (mv::Float)(0.8f * scale));
				
				int nbSteps, i;
				const mv::Float ainc = 0.05f * (mv::Float)M_PI;

				glBegin(GL_LINE_STRIP);
				glVertex3fv(v.getC(vector_e1_e2_e3));

				nbSteps = (int)(A.m_sc[1] / ainc) + 1;
				rotor R = _rotor(exp(((0.5f * A.m_sc[1]) / nbSteps) * b));
				rotor Ri = _rotor(inverse(R));
				for (i = 0; i < nbSteps; i++) {
					v = _vector(R * v * Ri);
					glVertex3fv(v.getC(vector_e1_e2_e3));
				}
				glEnd();

				// add arrowhead
				R = _rotor(exp(0.01f * b));
				v = _vector(R * v * Ri);
				glBegin(GL_LINE_STRIP);
				glVertex3fv(_vector(0.93f * v + 0.13f * (v << b)).getC(vector_e1_e2_e3));
				glVertex3fv(v.getC(vector_e1_e2_e3));
				glVertex3fv(_vector(1.05f * v + 0.15f * (v << b)).getC(vector_e1_e2_e3));
				glEnd();
			}
		}
	}


}


} /* end of namespace mv_draw */
