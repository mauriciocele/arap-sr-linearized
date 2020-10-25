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

#ifndef _DRAW_FUNCTIONS_H_
#define _DRAW_FUNCTIONS_H_

#include "e3ga.h"
#include <vector>

struct geosphere_s;

namespace mv_draw {

#define OD_SHADE 1
#define OD_WIREFRAME 2
#define OD_MAGNITUDE 4
#define OD_ORIENTATION 8

class DrawState {
public:
	DrawState() : m_ambient(0.2f),  m_diffuse(1.0f), m_sphere(NULL), m_pointSize(0.01f),
		m_lineLength(6.0f), m_planeSize(6.0f) {
		m_drawMode.push_back(OD_MAGNITUDE | OD_ORIENTATION);
	}

	void drawSphere(e3ga::mv::Float normal);

	/// used for drawing spheres:
	struct geosphere_s *m_sphere;
	GLuint m_sphereGLlist;

	float m_ambient;
	float m_diffuse;
	float m_pointSize;
	float m_lineLength;
	float m_planeSize;


	inline int getDrawMode() const {
		return	m_drawMode[m_drawMode.size()-1];
	}
	
	void setDrawMode(int mode);
	void pushDrawMode(int mode);
	void pushDrawModeOff(int mode);
	void pushDrawModeOn(int mode);
	void popDrawMode();
	


protected:
	std::vector<int> m_drawMode;
	// line width, etc
	// point size, etc
	
};

extern DrawState g_drawState;


/** used to pass multiple colors to drawing routine */
class Palet {
public:
	Palet();

	void copyColors(const Palet *o);

	// set the color
	void setFgColor(const float c[4]);
	void setBgColor(const float c[4]);
	void setOlColor(const float c[4]);
	void setFgColor(const double c[4]);
	void setBgColor(const double c[4]);
	void setOlColor(const double c[4]);
	void setFgAlpha(float alpha);
	void setBgAlpha(float alpha);
	void setOlAlpha(float alpha);

	// set OpenGL color
	void setFgColor();
	void setBgColor();
	void setOlColor();

	// retrieve a component [0 .. 3] from a color
	float fgColor(int idx);
	float bgColor(int idx);
	float olColor(int idx);

	// retrieve pointer to color
	const float *fgColor() const;
	const float *bgColor() const;
	const float *olColor() const;



	float m_fgColor[4]; // foreground color rgba [0.0, 1.0]
	float m_bgColor[4]; // background color rgba [0.0, 1.0]
	float m_olColor[4];  // outline color rgba [0.0, 1.0]
};

// some drawing functions

/**
Draws a vector (a line with a 3D arrow at its head)

The tail of the vector will be at 'tail'. This argument
can be NULL if you simply want to draw at the origin.

The head of the vector will be at 'tail' + scale * 'dir'.

The arrow will scale with 'scale'
*/
void drawVector(const e3ga::vector &tail, const e3ga::vector &dir, e3ga::mv::Float scale);

#define DRAW_BV_CIRCLE 0
#define DRAW_BV_PARALLELOGRAM 1
#define DRAW_BV_PARALLELOGRAM_NO_VECTORS 2
#define DRAW_BV_CROSS 3
#define DRAW_BV_CURLYTAIL 4
#define DRAW_BV_SWIRL 5
#define DRAW_BV_CIRCLE_OUTLINE 6

/*
Draws a bivector at 'base'. 
'base' can be NULL if you want to draw at the origin.

The bivector is specified by its 'normal', 
and two factors ('factor1' and 'factor2').

The entire bivector will be scaled according to 'scale'

Several drawing methods can be selected using the 'method' argument,
which can have any 'DRAW_BV_XXX' value

If you specify an object 'o' this can be used to set
the appropriate colors (i.e. foreground, outline)

*/
void drawBivector(const e3ga::vector &base, const e3ga::vector &normal, 
				 const e3ga::vector &factor1, const e3ga::vector &factor2, 
				 e3ga::mv::Float scale, int method = DRAW_BV_CIRCLE, Palet *o = NULL);

#define DRAW_TV_SPHERE 0
#define DRAW_TV_CROSS 1
#define DRAW_TV_CURLYTAIL 2
#define DRAW_TV_PARALLELEPIPED 3
#define DRAW_TV_PARALLELEPIPED_NO_VECTORS 4
/*
Draws a trivector at 'base'. 
'base' can be NULL if you want to draw at the origin.

The entire trivector will be scaled according to 'scale'

Several drawing methods can be selected using the 'method' argument,
which can have any 'DRAW_TV_XXX' value

If you specify an object 'o' this can be used to set
the appropriate colors (i.e. foreground, outline)

*/
void drawTriVector(const e3ga::vector &base, e3ga::mv::Float scale, const e3ga::vector vector[3], int method = DRAW_TV_SPHERE, Palet *o = NULL);

/*
Draws a line at position 'pt' in direction 'dir'. 
*/
void drawLine(const e3ga::vector &pt, const e3ga::vector &dir, float weight, int method = 0, Palet *o = NULL);


/*
Draws a plane at position 'pt' in plane 'ortho1 ^ ortho2' with normal 'normal' .
*/
void drawPlane(const e3ga::vector &pt, const e3ga::vector &ortho1, const e3ga::vector &ortho2,
			   const e3ga::vector &normal, float weight, int method = 0, Palet *o = NULL);

} /* end of namespace mv_draw */

#endif /* _DRAW_FUNCTIONS_H_ */
