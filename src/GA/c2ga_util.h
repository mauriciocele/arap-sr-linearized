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

#ifndef _C2GA_UTIL_H_
#define _C2GA_UTIL_H_

#include "c2ga.h"
#include "e3ga.h"
#include "common.h"

namespace c2ga {

inline normalizedPoint c2gaPoint(vectorE2GA l) {
	return _normalizedPoint(l + no + 0.5f * norm_e2(l) * ni);
}

inline normalizedPoint c2gaPoint(mv::Float x, mv::Float y) {
	return c2gaPoint(vectorE2GA(vectorE2GA_e1_e2, x, y));
}

inline e3ga::vector vectorToE3GA(const c2ga::vectorE2GA &v) {
	return e3ga::vector(e3ga::vector_e1_e2_e3, v.e1(), v.e2(), 0.0f);
}


} /* end of namespace c2ga */

#endif /* _C3GA_UTIL_H_ */
