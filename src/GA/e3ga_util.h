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

#ifndef _E3GA_UTIL_H_
#define _E3GA_UTIL_H_

#include "e3ga.h"
#include "common.h"

namespace e3ga {

rotor rotorFromVectorToVector(const vector &v1, const vector &v2);
rotor rotorFromVectorToVector(const vector &v1, const vector &v2, const bivector &altPlane);
mv exp(const mv &x, int order = 9);

/** special exp() for 3D bivectors */
e3ga::rotor exp(const e3ga::bivector &x);
/** special log() for 3D rotors */
e3ga::bivector log(const e3ga::rotor &R);

void rotorToMatrix(const rotor &R, mv::Float M[9]);
rotor matrixToRotor(const mv::Float M[9]);


mv::Float factorizeBlade(const mv &X, vector factor[], int gradeOfX = -1);


/**
Computes the reciprocal frame 'RF' of input frame 'IF'
Throws std::string when vectors in 'IF' are not independent, 
or if one of the IF[i] is null.
*/
void reciprocalFrame(const e3ga::vector *IF, e3ga::vector *RF, int nbVectors);


/**
Computes meet and join of 'a' 'b'.
The meet is returned in 'm' .
The join is returned in 'j'.
Implementation of an algorithm by Ian Bell.

Todo / warning: not fully compatible with meet & join described in book.
-> in the way the meet is computed from the join, and vice versa.
Todo!
*/
void meetJoin(const e3ga::mv  &a, const e3ga::mv &b, e3ga::mv &m, mv &j, 
			  e3ga::mv::Float smallEpsilon = 1e-7f, e3ga::mv::Float largeEpsilon = 1e-4f);

/**
Returns the meet of 'a' and 'b'
*/
inline e3ga::mv meet(const e3ga::mv &a, const e3ga::mv &b, 
			  e3ga::mv::Float smallEpsilon = 1e-7f, e3ga::mv::Float largeEpsilon = 1e-4f) {
	mv m, j;
	meetJoin(a, b, m, j, smallEpsilon, largeEpsilon);
	return m;
}

/**
Returns the join of 'a' and 'b'
*/
inline e3ga::mv join(const e3ga::mv &a, const e3ga::mv &b, 
			  e3ga::mv::Float smallEpsilon = 1e-7f, e3ga::mv::Float largeEpsilon = 1e-4f) {
	mv m, j;
	meetJoin(a, b, m, j, smallEpsilon, largeEpsilon);
	return j;
}

e3ga::mv largestGradePart(const e3ga::mv &X, int *gradeIdx = NULL);
e3ga::mv highestGradePart(const e3ga::mv &X, float epsilon = 1e-7f, int *gradeIdx = NULL);
e3ga::mv deltaProduct(const e3ga::mv &X, const e3ga::mv &Y, float epsilon = 1e-7f, int *gradeIdx = NULL);
e3ga::mv takeGrade(const e3ga::mv &X, int gradeUsageBitmap);

/** 
Returns a random blade of 'grade' with a (Euclidean) size in range [0, 1.0].
'grade' counts from 0, 1, 2, 3, 4, etc (so it is not a bitwise or GRADE_0 | GRADE_1).
If 'grade' < 0, then a random grade is picked

Currently, rand() is used to generate the blade
Todo: use Mersenne twister or something similar (license issues?)
*/
e3ga::mv randomBlade(int grade = -1, float size = 1.0f);

/**
Returns a random multivector (so not necessarily a blade or versor)
Which grade parts to fill with random coordinates is determined by 'gradeParts
*/
e3ga::mv randomMultivector(int gradeParts = GRADE_0 | GRADE_1 | GRADE_2 | GRADE_3, float size = 1.0f);



} /* end of namespace e3ga */

#endif /* _E3GA_UTIL_H_ */
