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

#ifndef _C3GA_UTIL_H_
#define _C3GA_UTIL_H_

#include "c3ga.h"
#include "e3ga.h"
#include "common.h"

namespace c3ga {

inline normalizedPoint c3gaPoint(const vectorE3GA &l) {
	return _normalizedPoint(l + no + 0.5f * norm_e2(l) * ni);
}

inline normalizedPoint c3gaPoint(mv::Float x, mv::Float y, mv::Float z) {
	return c3gaPoint(vectorE3GA(vectorE3GA_e1_e2_e3, x, y, z));
}

inline e3ga::vector vectorToE3GA(const c3ga::vectorE3GA &v) {
	return e3ga::vector(e3ga::vector_e1_e2_e3, v.getC(c3ga::vectorE3GA_e1_e2_e3));
}

mv exp(const mv &x, int order = 9);

/** special exp() for Euclidean bivectors (rotation) */
inline rotor exp(const bivectorE3GA &x) {
	// Since (x*x <= 0) for 3D bivector in Euclidean metric, we can optimize:
	mv::Float x2 = _Float(x << x);
	mv::Float ha = sqrt(-x2);
	if (ha == (mv::Float)0.0) return _rotor((mv::Float)1.0);
	return _rotor((mv::Float)cos(ha) + ((mv::Float)sin(ha) / ha) * x);
}


/** special exp() for general free vectors (translation) */
inline normalizedTranslator exp(const freeVector &x) {
	// Since (x*x <= 0) for 3D bivector in Euclidean metric, we can optimize:
	return _normalizedTranslator(1.0f + x);
}

/** special exp() for noni (scaling) */
inline scalor exp(const noni_t &x) {
	// Since (x*x >= 0) for 3D bivector in Euclidean metric, we can optimize:
	return _scalor((mv::Float)cosh(fabs(x.noni())) + 
		(mv::Float)sinh(x.noni()) * noni);
}


/** 
Converts `homogeneous 4x4 matrix' to translate-rotate-POSITIVE SCALING UNIFORM scaling versor 
transpose = true for OpenGL matrices
*/
TRSversor matrix4x4ToVersorPS(const mv::Float _M[4 * 4], bool transpose /*= false*/);

/** 
Converts `homogeneous 4x4 matrix' to translate-rotate-UNIFORM scale versor 
(negative scaling is allowed)
transpose = true for OpenGL matrices
*/
TRSversor matrix4x4ToVersor(const mv::Float M[16], bool transpose = false);

/** special exp() for bivectors */
// todo:
//evenVersor exp(const c3ga::pointPair &x);

/** special log() for rotors */
bivectorE3GA log(const c3ga::rotor &R);

/** special log() for TRversors */
//pointPair log(const c3ga::TRversor &V);
dualLine log(const TRversor &V);

/** special log() for TRSversors */
TRSversorLog log(const TRSversor &U);


mv::Float factorizeBlade(const mv &X, dualSphere factor[], int gradeOfX = -1);


/**
Computes the reciprocal frame 'RF' of input frame 'IF'
Throws std::string when vectors in 'IF' are not independent, 
or if one of the IF[i] is null.
*/
void reciprocalFrame(const dualSphere *IF, dualSphere *RF, int nbVectors);


/**
Computes meet and join of 'a' 'b'.
The meet is returned in 'm' .
The join is returned in 'j'.
Implementation of an algorithm by Ian Bell.

Todo / warning: not fully compatible with meet & join described in book.
-> in the way the meet is computed from the join, and vice versa.
Todo!
*/
void meetJoin(const mv  &a, const mv &b, mv &m, mv &j, 
			  mv::Float smallEpsilon = 1e-7f, mv::Float largeEpsilon = 1e-4f);

/**
Returns the meet of 'a' and 'b'
*/
inline mv meet(const mv &a, const mv &b, 
			  mv::Float smallEpsilon = 1e-7f, mv::Float largeEpsilon = 1e-4f) {
	mv m, j;
	meetJoin(a, b, m, j, smallEpsilon, largeEpsilon);
	return m;
}

/**
Returns the join of 'a' and 'b'
*/
inline mv join(const mv &a, const mv &b, 
			  mv::Float smallEpsilon = 1e-7f, mv::Float largeEpsilon = 1e-4f) {
	mv m, j;
	meetJoin(a, b, m, j, smallEpsilon, largeEpsilon);
	return j;
}


mv largestGradePart(const mv &X, int *gradeIdx = NULL);
mv highestGradePart(const mv &X, float epsilon = 1e-7f, int *gradeIdx = NULL);
mv deltaProduct(const mv &X, const mv &Y, float epsilon = 1e-7f, int *gradeIdx = NULL);
mv takeGrade(const mv &X, int gradeUsageBitmap);


/** 
Returns a random blade of 'grade' with a (Euclidean) size in range [0, 1.0].
'grade' counts from 0, 1, 2, 3, 4, etc (so it is not a bitwise or GRADE_0 | GRADE_1).
If 'grade' < 0, then a random grade is picked

Currently, rand() is used to generate the blade
Todo: use Mersenne twister or something similar (license issues?)
*/
mv randomBlade(int grade = -1, float size = 1.0f);

/**
Returns a random multivector (so not necessarily a blade or versor)
Which grade parts to fill with random coordinates is determined by 'gradeParts
*/
mv randomMultivector(int gradeParts = GRADE_0 | GRADE_1 | GRADE_2 | GRADE_3, float size = 1.0f);



} /* end of namespace c3ga */

#endif /* _C3GA_UTIL_H_ */
