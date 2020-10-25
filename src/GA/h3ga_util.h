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

#ifndef _H3GA_UTIL_H_
#define _H3GA_UTIL_H_

#include "h3ga.h"
#include "common.h"

namespace h3ga {

mv exp(const mv &x, int order = 9);

/** special exp() for 3D bivectors */
h3ga::rotor exp(const h3ga::bivector &x);
/** special log() for 3D rotors */
h3ga::bivector log(const h3ga::rotor &R);

mv::Float factorizeBlade(const mv &X, vector factor[], int gradeOfX = -1);



/**
Computes meet and join of 'a' 'b'.
The meet is returned in 'm' .
The join is returned in 'j'.
Implementation of an algorithm by Ian Bell.

Todo / warning: not fully compatible with meet & join described in book.
-> in the way the meet is computed from the join, and vice versa.
Todo!
*/
void meetJoin(const h3ga::mv  &a, const h3ga::mv &b, h3ga::mv &m, mv &j, 
			  h3ga::mv::Float smallEpsilon = 1e-7f, h3ga::mv::Float largeEpsilon = 1e-4f);

/**
Returns the meet of 'a' and 'b'
*/
inline h3ga::mv meet(const h3ga::mv &a, const h3ga::mv &b, 
			  h3ga::mv::Float smallEpsilon = 1e-7f, h3ga::mv::Float largeEpsilon = 1e-4f) {
	mv m, j;
	meetJoin(a, b, m, j, smallEpsilon, largeEpsilon);
	return m;
}

/**
Returns the join of 'a' and 'b'
*/
inline h3ga::mv join(const h3ga::mv &a, const h3ga::mv &b, 
			  h3ga::mv::Float smallEpsilon = 1e-7f, h3ga::mv::Float largeEpsilon = 1e-4f) {
	mv m, j;
	meetJoin(a, b, m, j, smallEpsilon, largeEpsilon);
	return j;
}

h3ga::mv largestGradePart(const h3ga::mv &X, int *gradeIdx = NULL);
h3ga::mv highestGradePart(const h3ga::mv &X, float epsilon = 1e-7f, int *gradeIdx = NULL);
h3ga::mv deltaProduct(const h3ga::mv &X, const h3ga::mv &Y, float epsilon = 1e-7f, int *gradeIdx = NULL);
h3ga::mv takeGrade(const h3ga::mv &X, int gradeUsageBitmap);

/** 
Returns a random blade of 'grade' with a (Euclidean) size in range [0, 1.0].
'grade' counts from 0, 1, 2, 3, 4, etc (so it is not a bitwise or GRADE_0 | GRADE_1).
If 'grade' < 0, then a random grade is picked

Currently, rand() is used to generate the blade
Todo: use Mersenne twister or something similar (license issues?)
*/
h3ga::mv randomBlade(int grade = -1, float size = 1.0f);

/**
Returns a random multivector (so not necessarily a blade or versor)
Which grade parts to fill with random coordinates is determined by 'gradeParts
*/
h3ga::mv randomMultivector(int gradeParts = GRADE_0 | GRADE_1 | GRADE_2 | GRADE_3 | GRADE_4, float size = 1.0f);

} /* end of namespace h3ga */

#endif /* _H3GA_UTIL_H_ */
