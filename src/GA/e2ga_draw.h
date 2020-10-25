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

#ifndef _E2GA_DRAW_H_
#define _E2GA_DRAW_H_

#include "e2ga.h"
#include "draw.h"

namespace mv_draw {

/* 
Method & flags are dependent on what 'X' represents.
They are forwarded to drawVector, drawBivector, drawTrivector.

Currently, 'method' is some integer in range [0, n), where each
integer indicates a different way of drawing the multivector.

The Palet can be used to specify foreground, background and outline color.

Uses g_drawState for some extra flags!
If this gets annoying, allow DrawState to be passed along
as argument (and also integrate 'Palet')
*/
void draw(const e2ga::mv &X, int method = 0,Palet *o = NULL);

} /* end of namespace mv_draw */

#endif /* _E2GA_DRAW_H_ */
