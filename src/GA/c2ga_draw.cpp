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

#include "c2ga_draw.h"
#include "c3ga_draw.h"
#include "mv_analyze.h"

using namespace mv_analyze;

namespace mv_draw {

using namespace e3ga;

void drawC2GA(const mv_analyze::mvAnalysis &A, int method/*= 0*/, Palet *o/* = NULL*/) {
	return drawC3GA(A, method, o);
}

void draw(const c2ga::mv &X, int method/*= 0*/, Palet *o/* = NULL*/) {
	mv_analyze::mvAnalysis A(X);
	drawC3GA(A, method, o);
}


} // end of namespace mv_draw

