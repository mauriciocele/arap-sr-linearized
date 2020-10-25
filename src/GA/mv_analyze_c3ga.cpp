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

#include "mv_analyze.h"
#include "e3ga_util.h"
#include "c3ga_util.h"

namespace mv_analyze {

using namespace c3ga;

void mvAnalysis::analyze(c3ga::mv X, int intFlags/* = 0 */,  double epsilon/* = DEFAULT_EPSILON */, 
						 const c3ga::normalizedPoint &probe /*= _normalizedPoint(no)*/) {
	// cleanup:
	m_flags = FLAG_VALID;
	m_epsilon = epsilon;
	for (int i = 0; i < NB_TYPE_LEVELS; i++)
		m_type[i] = INVALID_TYPE;

	// type is conformal
	m_type[0] = CONFORMAL_MODEL;

	// forced dual interpretation?
	if (intFlags & FLAG_DUAL) {
		m_flags ^= FLAG_DUAL;
		X = dual(X); // should 'dual' be 'undual?'
	}

	// get basic mv type (BLADE, VERSOR, etc)
	m_mvType = mvType(X, (mv::Float)epsilon);
	m_type[1] = m_mvType.m_type;

	// todo: check for VERSOR, MULTIVECTOR HERE!!!


	// zero blade? 
	if (m_mvType.m_zero) {
		m_type[2] = ZERO;
		m_sc[0] = 0;
		return;
	}

	// scalar
	if (m_mvType.m_gradeUsage == GRADE_0) {
		m_type[2] = SCALAR;
		m_type[3] = SCALAR;		
		m_sc[0] = _Float(X);
		return;
	}
	// pseudo scalar
	else if (m_mvType.m_gradeUsage == GRADE_5) {
		m_type[2] = PSEUDOSCALAR;
		m_type[3] = PSEUDOSCALAR;		
		m_sc[0] = X.noe1e2e3ni();
		return;
	}

	// init basic classifiers:
	c3ga::mv::Float _opNiX = _Float(norm_e(op(ni, X)));
	c3ga::mv::Float _ipNiX = _Float(norm_e(lcont(ni, X)));
	c3ga::mv::Float _X2 = _Float(norm_r2(X));

	// init basic classifiers (bool):
	bool opNiX = (fabs(_opNiX) >= epsilon);
	bool ipNiX = (fabs(_ipNiX) >= epsilon);
	bool X2 = (fabs(_X2) >= epsilon);

	// free?
	if ((!opNiX) && (!ipNiX))
		analyzeFree(X, intFlags,  epsilon);

	// flat?
	else if ((!opNiX) && (ipNiX)) {
		analyzeFlat(X, probe, intFlags,  epsilon);
	}

	// dual flat?
	else if ((opNiX) && (!ipNiX)) {
		m_flags ^= FLAG_DUAL;
		analyzeFlat(dual(X), probe, intFlags,  epsilon); // should 'dual' be 'undual'?
	}

	// tangent
	else if ((opNiX) && (ipNiX) && (!X2))
		analyzeTangent(X, intFlags,  epsilon);

	// round
	else if ((opNiX) && (ipNiX) && (X2))
		analyzeRound(X, intFlags,  epsilon);
}

void mvAnalysis::analyzeRound(mv X, int intFlags /* = 0 */, double epsilon /* = DEFAULT_EPSILON */) {

	m_type[2] = ROUND;
	int Agrade = m_mvType.m_grade;

	if (Agrade == 1) {
		X = dual(X);
		m_flags ^= FLAG_DUAL;
	}

	// make exception for scalars:
	if (Agrade == 0) {
		m_type[2] = SCALAR;
		m_type[3] = SCALAR;
		// ************* format of 'round' scalar***************
		// m_sc[0] = signed weight
		// ************* END format of round ***************
		m_sc[0] = _float(X);
		return;
	}


	// free N-vector
	mv attitude = negate(op(lcont(ni, X), ni)); 

	// _location is normalized dual sphere
	mv _location = gp(X, inverse(lcont(ni, X))); 
	_location = gp(_location, inverse(-scp(ni, _location)));
	// location:
	normalizedPoint location = c3gaPoint(_vectorE3GA(_location));

	mv::Float niX2 = _Float(scp(lcont(ni, X), lcont(ni, X)));

	// radius squared:
	mv::Float radius2 = _Float(gp(X, gradeInvolution(X)) * (1.0f / niX2)); // *-1 required?

	// weight:
	mv::Float weight = _Float(norm_r(lcont(no, attitude)));

	// ************* format of round ***************
	// m_pt[0] = location
	// m_sc[0] = signed radius
	// m_sc[1] = signed weight
	// m_vc[0] .. m_vc[2] = unit 3D vector basis for attitude
	// ************* END format of round ***************

	m_pt[0] = vectorToE3GA(_vectorE3GA(location));
	m_sc[0] = sqrt(fabs(radius2)) * ((radius2 < 0) ? -1.0f : 1.0f);
	m_sc[1] = weight;

	// factor attitude:
	if ((Agrade == 4) || (Agrade == 1)) { 
		// (dual) sphere (WHAT ABOUT DUAL POINTS WITH 0 RADIUS)? 
		m_vc[0] = e3ga::_vector(e3ga::e1);
		m_vc[1] = e3ga::_vector(e3ga::e2);
		m_vc[2] = e3ga::_vector(e3ga::e3);
	}
	else if (Agrade == 2) {
//		printf("att = %s,\n", attitude.c_str());
		// point pair
		m_vc[0] = vectorToE3GA(_vectorE3GA(unit_e(lcont(no, attitude))));
//		printf("vc = %s,\n", m_vc[0].c_str());
	}
	else if (Agrade == 3) {
		// circle
		// explicit factorization required:
		dualSphere factor[5];
		const int gradeOfBlade = 2;
		mv::Float scale = factorizeBlade(reverse(lcont(no, reverse(attitude))), factor, gradeOfBlade);
		m_vc[0] = vectorToE3GA(_vectorE3GA(factor[0]));
		m_vc[1] = vectorToE3GA(_vectorE3GA(factor[1]));
		m_vc[2] = _vector(dual(m_vc[0] ^ m_vc[1]));
	}

	switch (Agrade) {
		case 1:
			// dual sphere
            m_type[3] = SPHERE;
			m_flags ^= FLAG_DUAL;
			break;
		case 2:
            m_type[3] = POINT_PAIR;
			break;
		case 3:
            m_type[3] = CIRCLE;
			break;
		case 4:
            m_type[3] = SPHERE;
			break;
	}

}

void mvAnalysis::analyzeTangent(const mv &X, int intFlags /* = 0 */, double epsilon /* = DEFAULT_EPSILON */) {

	m_type[2] = TANGENT;


	int Agrade = m_mvType.m_grade;

	// free N-vector
	mv attitude = negate(op(lcont(ni, X), ni)); 

	// _location is normalized dual sphere
	mv _location = gp(X, inverse(lcont(ni, X))); 
	_location = gp(_location, inverse(-scp(ni, _location)));
	// location:
	normalizedPoint location = c3gaPoint(_vectorE3GA(_location));

	mv::Float weight = _Float(norm_e(ni << X));

	// ************* format of tangent ***************
	// m_pt[0] = location
	// m_vc[0] .. m_vc[2] = unit 3D vector basis for attitude
	// m_sc[0] = weight
	// ************* END format of tangent ***************
	m_pt[0] = vectorToE3GA(_vectorE3GA(location));
	m_sc[0] = weight;

	// factor attitude:
	if (Agrade == 4) { 
		// T trivector
		m_vc[0] = e3ga::e1;
		m_vc[1] = e3ga::e2;
		m_vc[2] = e3ga::e3;
	}
	else if (Agrade == 2) {
		// T vector
		m_vc[0] = vectorToE3GA(_vectorE3GA(unit_e(lcont(no, attitude))));
	}
	else if (Agrade == 3) {
		// T bivector
		// explicit factorization required:
		dualSphere factor[5];
		int gradeOfBlade = 2;
		mv::Float scale = factorizeBlade(reverse(lcont(no, reverse(attitude))), factor, gradeOfBlade);
		m_vc[0] = vectorToE3GA(_vectorE3GA(factor[0]));
		m_vc[1] = vectorToE3GA(_vectorE3GA(factor[1]));
		m_vc[2] = _vector(-dual(m_vc[0] ^ m_vc[1]));
	}

	switch (Agrade) {
		case 1:
			// point
            m_type[3] = SCALAR;
			break;
		case 2:
            m_type[3] = VECTOR;
			break;
		case 3:
            m_type[3] = BIVECTOR;
			break;
		case 4:
            m_type[3] = TRIVECTOR;
			break;
	}


}

void mvAnalysis::analyzeFlat(const mv &X, const normalizedPoint &probe, int intFlags /* = 0 */, double epsilon /* = DEFAULT_EPSILON */) {
	using namespace c3ga;

	m_type[2] = FLAT;
	int Agrade = m_mvType.m_grade;
	if (m_flags & FLAG_DUAL) Agrade = 5 - Agrade;

	// free N-vector
	mv attitude = negate(lcont(ni, X)); 
//	printf("att = %s,\n", attitude.c_str_e20());

	// _location is normalized dual sphere
	mv _location = lcont(lcont(probe, X), inverse(X)); 
	_location = gp(_location, inverse(-scp(ni, _location)));
	// location:
	normalizedPoint location = c3gaPoint(_vectorE3GA(_location));

//	printf("loc = %s,\n", location.c_str_e20());

	mv::Float weight = (Agrade == 1) ? -_Float(scp(X, no))  : fabs(_Float(norm_r(X)));


	// ************* format of flat ***************
	// m_pt[0] = location
	// m_vc[0] .. m_vc[1] = unit 3D vector basis for attitude
	// m_sc[0] = weight 
	// ************* END format of flat ***************
	m_pt[0] = vectorToE3GA(_vectorE3GA(location));
	m_sc[0] = weight;

	// factor attitude:
	if (Agrade == 4) { 
		// plane
		// explicit factorization required:
		dualSphere factor[5];
		const int gradeOfBlade = 2;
		double scale = factorizeBlade(reverse(lcont(no, reverse(attitude))), factor, gradeOfBlade);
		m_vc[0] = vectorToE3GA(_vectorE3GA(factor[0]));
		m_vc[1] = vectorToE3GA(_vectorE3GA(factor[1]));
		m_vc[2] = _vector(-dual(m_vc[0] ^ m_vc[1]));
//		printf("vc0 = %s,\n", (m_vc[0] ^ ni).c_str_e20());
//		printf("vc1 = %s,\n", (m_vc[1] ^ ni).c_str_e20());
	}
	else if (Agrade == 3) {
		// line
		m_vc[0] = vectorToE3GA(_vectorE3GA(unit_e(lcont(no, attitude))));
//		printf("vc0 = %s,\n", (m_vc[0] ^ ni).c_str_e20());
	}
	// flat point and flat scalar have no attitude


	switch (Agrade) {
		case 1:
            m_type[3] = SCALAR;
			break;
		case 2:
            m_type[3] = POINT;
			break;
		case 3:
            m_type[3] = LINE;
			break;
		case 4:
            m_type[3] = PLANE;
			break;
	}
}

void mvAnalysis::analyzeFree(const mv &X, int intFlags /* = 0 */, double epsilon /* = DEFAULT_EPSILON */) {
	using namespace c3ga;

	m_type[2] = FREE;
	int Agrade = m_mvType.m_grade;

	const mv &attitude = X;
	float weight = _Float(norm_e(X));

	// ************* format of free ***************
	// m_pt[0] = no (or probe?)
	// m_vc[0] .. m_vc[2] = unit 3D vector basis for attitude
	// m_sc[0] = weight 
	// ************* END format of free ***************

	m_pt[0] = e3ga::vector();
	m_sc[0] = weight;

	// factor attitude:
	if (Agrade == 4) { 
		// F trivector
		m_vc[0] = e3ga::e1;
		m_vc[1] = e3ga::e2;
		m_vc[2] = e3ga::e3;
	}
	else if (Agrade == 2) {
		// F vector
		m_vc[0] = vectorToE3GA(_vectorE3GA(unit_e(lcont(no, attitude))));
	}
	else if (Agrade == 3) {
		// F bivector
		// explicit factorization required:
		dualSphere factor[5];
		int gradeOfBlade = 2;
		double scale = factorizeBlade(reverse(lcont(no, reverse(attitude))), factor, gradeOfBlade);
		m_vc[0] = vectorToE3GA(_vectorE3GA(factor[0]));
		m_vc[1] = vectorToE3GA(_vectorE3GA(factor[1]));
		m_vc[2] = _vector(-dual(m_vc[0] ^ m_vc[1]));
	}

	switch (Agrade) {
		case 1:
            m_type[3] = SCALAR;
			break;
		case 2:
            m_type[3] = VECTOR;
			break;
		case 3:
            m_type[3] = BIVECTOR;
			break;
		case 4:
            m_type[3] = TRIVECTOR;
			break;
	}

}

} /** end of namespace mv_analyze */
