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

#include <string>

#include "h3ga.h"
#include "h3ga_util.h"
#include "gabits.h"

namespace h3ga {

mv exp(const mv &x, int order /*= 9*/) {
	// First try special cases:
	// Check if (x * x == scalar) is scalar
	mv x2 = x * x;
	mv::Float s_x2 = _Float(x2);
	if ((_Float(norm_e2(x2) - s_x2 * s_x2)) < 1e-7f) {
		// OK (x * x == scalar), so use special cases:
		if (s_x2 < 0.0) {
			mv::Float a = sqrt(-s_x2);
			return (mv::Float)cos(a) + (mv::Float)sin(a) * x * (1.0f / a);
		}
		else if (s_x2 > 0.0) {
			mv::Float a = sqrt(s_x2);
			return (mv::Float)cosh(a) + (mv::Float)sinh(a) * x * (1.0f / a);
		}
		else {
			return 1 + x;
		}
	}


	// now do general series eval:


    int i;
    mv result;

    result = 1.0;
    if (order == 0) {
        return result;
    }

    // scale by power of 2 so that its norm is < 1
    unsigned long max = (unsigned long)x.largestCoordinate();
    unsigned long scale=1;
    if (max > 1) scale <<= 1;
    while (max)
    {
        max >>= 1;
        scale <<= 1;
    }

    mv scaled = x * scalar(1.0f / (mv::Float)scale);

    // taylor approximation
    mv tmp;

    tmp = 1.0;
    for (i = 1; i < order; i++) {
        tmp = tmp*scaled * scalar(1.0f / (mv::Float)i);
        result += tmp;
    }

    // undo scaling
    while (scale > 1)
    {
        result *= result;
        scale >>= 1;
    }
	return result;
}

bivector log(const rotor &R) {
	// get the bivector/2-blade part of R
	bivector B = _bivector(R);

	// compute the 'reverse norm' of the bivector part of R:
	mv::Float R2 = _Float(norm_r(B));

	// check to avoid divide-by-zero (and also below zero due to FP roundoff):
	if (R2 <= 0.0) {
		if (_Float(R) < 0)  // this means the user ask for log(-1):
			return _bivector((float)M_PI * (e1 ^ e2)); // we return 360 degree rotation in an arbitrary plane
		else 
			return bivector();  // return log(1) = 0
	}

	// return the log:
	return _bivector(B * ((float)atan2(R2, _Float(R)) / R2));
}

// special exp for 3D Euclidean bivectors:
rotor exp(const bivector &x) {
	// Since (x*x <= 0) for 3D bivector in Euclidean metric, we can optimize:
	mv::Float x2 = _Float(x << x);
	mv::Float ha = sqrt(-x2);
	return _rotor((mv::Float)cos(ha) + ((mv::Float)sin(ha) / ha) * x);
}




/// factors blade into vectors (euclidean unit length), returns  scale (or throws exception when non-blade is passed)
mv::Float factorizeBlade(const mv &X, vector factor[], int gradeOfX /* = -1 */) {
//	printf("X = %s;\n", X.c_str());
	// get scale of blade, grade of blade
	int k = gradeOfX;
	if (k < 0) {
		mvType T(X);
		k = T.m_grade;
	}
	mv::Float s = (k == 0) ? _Float(X): _Float(norm_e(X));
	
	// detect non-blades
	if (k < 0) throw -1;
	
	// set scale of output, no matter what:
	mv::Float scale = s;
	
	// detect null-blades, scalar-blades
	if ((s == 0.0) || (k == 0))
	    return scale;
	
	
	// get largest basis blade, basis vectors
	unsigned int E;
	int Eidx = 0;
	X.largestBasisBlade(E);
	
	// setup the 'current input blade'
	mv Bc = unit_e(X);
	
	mv::Float coords[4] = {0.0f, 0.0f, 0.0f, 0.0f};
	for (int i = 0; i < (k-1); i++) {
		// get next basisvector
		while (!(E&1)) {
			coords[Eidx] = 0.0;
			E >>= 1;	Eidx++;
		}
		coords[Eidx] = 1.0;
		E ^= 1;
		mv ei(GRADE_1, coords);

	    // project basis vector ei, normalize projection:
	    factor[i] = _vector(unit_e(lcont(lcont(ei, Bc), Bc))); // no inverse(Bc) required, since Bc is always unit
	    
	    // remove f[i] from Bc
	    Bc = lcont(factor[i], Bc);
	}
	
	// last factor = what is left of the input blade
	factor[k-1] = _vector(unit_e(Bc)); // already normalized, but renormalize to remove any FP round-off error
	
	return scale;
}

// todo: integrate into G2
mv largestGradePart(const mv &X, int *gradeIdx /* = NULL */) {
	int nbBits = bitCount16(X.gu()); // bitCount16 also goes into Gaigen 2
	if (nbBits == 1) {
		if (gradeIdx) *gradeIdx = highestOneBit16(X.gu());
		return X;
	}
	else if (nbBits == 0) {
		if (gradeIdx) *gradeIdx = 0;
		return mv(0.0f);
	}
	else {
		// loop over all grade
		// if grade is present: sum + square coordinates
		//								 if larger than current -> keep pointer
		mv::Float largestG = 0.0f;
		int largestGidx = -1;
		const mv::Float *largestC = NULL;
		const mv::Float *C = X.m_c;

		for (int i = 0; i <= 4; i++) {
			if ((X.gu() & (1 << i)) == 0) continue;
			else {
				// square, sum 
				mv::Float l = C[0] * C[0];
				int s = mv_gradeSize[i];
				for (int j = 1; j < s; j++) l = C[j] * C[j];

				// check if larger
				if (l > largestG) {
					largestC = C;
					largestG = l;
					largestGidx = i;
					if (gradeIdx) *gradeIdx = i;
				}

				C += mv_gradeSize[i];
			}
		}
		if (largestC)
			return mv((unsigned int)(1 << largestGidx), largestC);
		else {
			if (gradeIdx) *gradeIdx = 0;
			return mv(0.0f);
		}
	}
}

// todo: integrate into G2
/**
Returns grade usage of multivector.
The returned integer is a bitwise or of 
GRADE_0 = 1, 
GRADE_1 = 2, 
GRADE_N = 1 << (N) 
constants.
*/
mv grade(const mv &X, float epsilon /* = 1e-7 */);

// todo: integrate into G2
mv highestGradePart(const mv &X, float epsilon /* = 1e-7 */, int *gradeIdx /* = NULL*/) {
	int g = 4, gu = X.gu(), iX = mv_size[gu], size, i;
	const float *cptr = NULL;
	do {
		if (gu & (1 << g)) {
			size = mv_gradeSize[g];
			iX -= size;
			cptr = X.m_c + iX;
			for (i = 0; i < size; i++) 
				if ((cptr[i] > epsilon) || (-cptr[i] > epsilon)) {
					if (gradeIdx) *gradeIdx = g;
					return mv((unsigned int)(1 << g), cptr);
				}
		}
	} while ((--g)>= 0);

	if (gradeIdx) *gradeIdx = 0;
	return mv(0.0f);
}

// todo: integrate into G2
mv takeGrade(const mv &X, int gradeUsageBitmap) {
	int gua;

	// determine what the grage usage 'gu' of the result should be:
	if (gradeUsageBitmap = ((gua = X.gu()) & gradeUsageBitmap)) { // only execute if any grade will be present in the result
		mv::Float C[8]; 
		mv::Float *bc; 
		const mv::Float *ac; 

		bc = C; ac = X.m_c; // pointers to the coordinates of source (ac) and result (bc)
		for (int i = 1; i <= gradeUsageBitmap; i = i << 1) { // for each grade that is possibly in the result
			if (gua & i) { // determine if grade is present in source
				int s = mv_size[i]; // get the size of grade
				if (gradeUsageBitmap & i) { // determine if grade is present in result
					// copy coordinates
					for (int j = 0; j < s; j++) bc[j] = ac[j];
					bc += s; // increment pointer to result
				}
				ac += s; // increment pointer to source
			}
		}
		return mv(gradeUsageBitmap, C);
	}
	else return mv(0.0f);
}


// todo: integrate into G2
mv deltaProduct(const mv &X, const mv &Y, float epsilon /* = 1e-7 */, int *gradeIdx /* = NULL*/) {
	return highestGradePart(gp(X, Y), epsilon, gradeIdx);
}

inline mv randomVector() {
	float c[4] =
	{
		(float)(rand() - RAND_MAX / 2),
		(float)(rand() - RAND_MAX / 2),
		(float)(rand() - RAND_MAX / 2),
		(float)(rand() - RAND_MAX / 2)
	};
	return mv(GRADE_1, c);
}

/** 
Returns a random blade of 'grade' with a (Euclidean) size in range [0, 1.0].
If grade < 0, then a random grade is picked

Currently, rand() is used to generate the blade
Todo: use Mersenne twister or something (license issues?)
*/
mv randomBlade(int grade/* = -1*/, float size /*= 1.0f*/) {
	if (grade < 0) 
		grade = rand() % 5;
	

	if (grade == 0) {
		return mv(size * (-1.0f + 2.0f * (float)rand() / (float)RAND_MAX));
	}
	else if (grade == 4) {
		return mv(GRADE_4, size * (-1.0f + 2.0f * (float)rand() / (float)RAND_MAX));
	}
	else {
		mv result = randomVector();
		for (int g = 1; g < grade; g++) {
			result ^= randomVector();
		}
		result = (-1.0f + 2.0f * (float)rand() / (float)RAND_MAX) * size * unit_e(result); // todo: random factor
		return result;
	}
}

mv randomMultivector(int gradeParts /* = GRADE_0 | GRADE_1 | GRADE_2 | GRADE_3 | GRADE_4 */, float size /*= 1.0f*/) {
	mv::Float C[16];
	gradeParts &= GRADE_0 | GRADE_1 | GRADE_2 | GRADE_3 | GRADE_4; // to prevent weird input
	int s = mv_size[gradeParts];
	for (int i = 0; i < s; i++) {
		C[i] = -1.0f + 2.0f * (float)rand() * size / (float)RAND_MAX;
	}
	return mv(gradeParts, C);
}


void meetJoin(const mv  &a, const mv &b, mv &m, mv &j, mv::Float smallEpsilon, mv::Float largeEpsilon) {
	mv::Float la = a.largestCoordinate();
	mv::Float lb = b.largestCoordinate();

	// step one: check for near-zero input
	if ((la < smallEpsilon) || (lb < smallEpsilon)) {
		// set both meet and join to 0;
		m.set();
		j.set();
		return; // done
	}

	// determine grade of input
	int ga, gb;
	mv _ca = largestGradePart(a, &ga);
	mv _cb = largestGradePart(b, &gb);

	// normalize (approximatelly) and swap (optionally)
	mv ca, cb;
	if (ga <= gb) {
		ca = op(_ca, 1.0f / la);
		cb = op(_cb, 1.0f / lb);
	}
	else {
		ca = op(_cb, 1.0f / lb);
		cb = op(_ca, 1.0f / la);
		int tempg = ga;
		ga = gb;
		gb = tempg;
	}

	// compute delta product & 'normalize'
	mv d,_d;
	int gd;
	_d = deltaProduct(a, b, smallEpsilon, &gd);
	mv::Float ld = _d.largestCoordinate();
	d = op(_d, 1.0f / ld);

	// if delta product is scalar, we're done:
	if (gd == 0) {
		// a == b (up to scalar)
		m = ca;
		j  = ca;
		// todo: largest coordinate positive?
		return;
	}

	// if grade of delta product is equal to ga + gb, we're done, too
	if (gd == ga + gb) {
		// a and b entirely disjoint
		m.set(1.0f);
		j = unit_e(op(ca, cb));
		// todo: largest coordinate positive?
		return;
	}

	// init join
	j = I4;
	int Ej = 4 - ((ga + gb + gd) >> 1);

	// check join excessity
	if (Ej == 0) {
		m = lcont(d, j);
		// todo: largest coordinate positive?
		return;
	}

	// init meet 
	m = 1.0f;
	int Em = ((ga + gb - gd) >> 1);

	// init s, the dual of the delta product:
	mv s = lcont(d, I4i);

	// precompute inverse of ca
	mv cai = inverse(ca);

	mv e[4] = {
		mv(GRADE_1, 1.0f, 0.0f, 0.0f, 0.0f),
		mv(GRADE_1, 0.0f, 1.0f, 0.0f, 0.0f),
		mv(GRADE_1, 0.0f, 0.0f, 1.0f, 0.0f),
		mv(GRADE_1, 0.0f, 0.0f, 0.0f, 1.0f)
	};

	for (unsigned int i = 0; i < 4; i++) {
		// compute next factor 'c'
		mv c = lcont(lcont(e[i], s), s);		

		// check if 'c' is OK to use:
		if (c.largestCoordinate() < largeEpsilon)
			continue;

		// compute projection, rejection of 'c' wrt to 'ca'
		mv cp, cr; // c projected, c rejected
		mv tmpc = lcont(c, ca);
		cp = lcont(tmpc, cai); // use correct inverse because otherwise cr != c - cp
		cr = subtract(c, cp);

		// if 'c' has enough of it in 'ca', then add to meet
		if (cp.largestCoordinate() > largeEpsilon) {
			m = op(m, cp);
			Em--;	
			if (Em == 0) {
				j = op(d, m);
				m = unit_e(m);
				j = unit_e(j);

				// todo: largest coordinate positive?
				return;
			}
		}

		if (cr.largestCoordinate() > largeEpsilon) {
			j = lcont(cr, j);
			Ej--;	
			if (Ej == 0) {
				m = lcont(d, j);
				m = unit_e(m);
				j = unit_e(j);

				// todo: largest coordinate positive?
				return;
			}
		}

		// optionally remove 'c' from 's' (do that?)
	}

	throw std::string("Error while computing meet & join!");
}


} /* end of namespace h3ga */
