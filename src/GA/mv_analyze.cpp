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
#include "h3ga_util.h"
#include "c3ga_util.h"
#include "c2gatoc3ga.h"

namespace mv_analyze {

// This is some weird inconsistency between gcc and MS compiler:
// With GCC, you have to define static const int members here, too!
#ifndef WIN32
const int mvAnalysis::NB_POINTS;
const int mvAnalysis::NB_VECTORS;
const int mvAnalysis::NB_SCALARS ;
const int mvAnalysis::NB_TYPE_LEVELS ;
const int mvAnalysis::FLAG_VALID ;
const int mvAnalysis::FLAG_DUAL;
const int mvAnalysis::VECTOR_SPACE_MODEL;
const int mvAnalysis::HOMOGENEOUS_MODEL;
const int mvAnalysis::CONFORMAL_MODEL;
const int mvAnalysis::INVALID_TYPE ;
const int mvAnalysis::MULTIVECTOR;
const int mvAnalysis::VERSOR;
const int mvAnalysis::BLADE;
const int mvAnalysis::SCALAR;
const int mvAnalysis::FLAT;
const int mvAnalysis::ROUND;
const int mvAnalysis::TANGENT ;
const int mvAnalysis::FREE ;
const int mvAnalysis::ZERO;

	
const int mvAnalysis::POINT;
const int mvAnalysis::LINE;
const int mvAnalysis::PLANE;
const int mvAnalysis::POINT_PAIR ;
const int mvAnalysis::CIRCLE ;
const int mvAnalysis::SPHERE;
const int mvAnalysis::VECTOR;
const int mvAnalysis::BIVECTOR;
const int mvAnalysis::TRIVECTOR;
const int mvAnalysis::NOT_USED ;
const int mvAnalysis::EVEN_VERSOR;
const int mvAnalysis::ODD_VERSOR;
const int mvAnalysis::ROTOR;

const int mvAnalysis::LOCALIZED_BLADE;
const int mvAnalysis::INFINITE_BLADE;


#endif

mvAnalysis::mvAnalysis() : m_flags(0), m_epsilon(0.0) {
	for (int i = 0; i < NB_SCALARS; i++)
		m_sc[i] = (e3ga::mv::Float)0.0;

	for (int i = 0; i < NB_TYPE_LEVELS; i++)
		m_type[i] = INVALID_TYPE;
}

mvAnalysis::mvAnalysis(const e2ga::mv &X, int intFlags/* = 0 */, double epsilon/* = DEFAULT_EPSILON */) {
	analyze(X, intFlags, epsilon);
}

mvAnalysis::mvAnalysis(const e3ga::mv &X, int intFlags/* = 0 */, double epsilon/* = DEFAULT_EPSILON */) {
	analyze(X, intFlags, epsilon);
}

mvAnalysis::mvAnalysis(const h3ga::mv &X, int intFlags/* = 0 */, double epsilon/* = DEFAULT_EPSILON */, 
					   const h3ga::normalizedPoint &probe /*= h3ga::_normalizedPoint(h3ga::e0)*/) {
	analyze(X, intFlags, epsilon, probe);
}

mvAnalysis::mvAnalysis(const c3ga::mv &X, int intFlags/* = 0 */, double epsilon/* = DEFAULT_EPSILON */, 
					   const c3ga::normalizedPoint &probe /*= c3ga::_normalizedPoint(c3ga::no)*/) {
	analyze(X, intFlags, epsilon, probe);
}

mvAnalysis::mvAnalysis(const c2ga::mv &X, int intFlags/* = 0 */, double epsilon/* = DEFAULT_EPSILON */, 
					   const c2ga::normalizedPoint &probe /*= c2ga::_normalizedPoint(c3ga::no)*/) {
	analyze(X, intFlags, epsilon, probe);
}


mvAnalysis::~mvAnalysis() {
}

mvAnalysis::mvAnalysis(const mvAnalysis &I) {
	operator=(I);
}


mvAnalysis &mvAnalysis::operator=(const mvAnalysis &I) {
	if (&I != this) {
		for (int i = 0; i < NB_POINTS; i++)
			m_pt[i] = I.m_pt[i];
		for (int i = 0; i < NB_VECTORS; i++)
			m_vc[i] = I.m_vc[i];
		for (int i = 0; i < NB_SCALARS; i++)
			m_sc[i] = I.m_sc[i];
		for (int i = 0; i < NB_TYPE_LEVELS; i++)
			m_type[i] = I.m_type[i];
		m_flags = I.m_flags;
		m_epsilon = I.m_epsilon;
		m_mvType = I.m_mvType;
	}
	return *this;
}

std::string mvAnalysis::toString() const {
	std::string result;
	if (!isValid()) result = "invalid analysis";

	else if (model() == VECTOR_SPACE_MODEL) {
		// model:
		result += "Vector space model";

		// flags / special stuff:
		if (isDual()) result += " dual";
		if (isZero()) result += " zero";

		// blade / versor / multivector?
		if (isBlade()) result += " blade";
		else if (isVersor()) result += " versor";
		else result += " multivector";

		if (isBlade()) {
			result += ":";
			switch(bladeSubclass()) {
				case SCALAR:
					result += " scalar";
					break;
				case VECTOR:
					result += " vector";
					break;
				case BIVECTOR:
					result += " bivector";
					break;
				case TRIVECTOR:
					result += " trivector";
					break;
			}
		}
		else if (isVersor()) {
			result += ":";
			switch(versorSubclass()) {
				case ODD_VERSOR:
					result += " odd versor";
					break;
				case EVEN_VERSOR:
					result += " even versor";
					break;
			}
		}
	}

	else if (model() == HOMOGENEOUS_MODEL) {
		// model:
		result += "Homogeneous";

		// flags / special stuff:
		if (isDual()) result += " dual";
		if (isZero()) result += " zero";

		// blade / versor / multivector?
		if (isBlade()) result += " blade";
		else if (isVersor()) result += " versor";
		else result += " multivector";

		if (!isZero()) {
			if (isBlade()) {
				result += ":";
				
				if (bladeClass() == SCALAR) {
					result += " scalar";
				}

				else if (bladeClass() == INFINITE_BLADE) {
					switch(bladeSubclass()) {
					case POINT:
						result += " vector";
						break;
					case LINE:
						result += " line at infinity";
						break;
					case PLANE:
						result += " plane at infinity";
						break;
					}
				}
				
				else if (bladeClass() == LOCALIZED_BLADE) {
					switch(bladeSubclass()) {
					case POINT:
						result += " point";
						break;
					case LINE:
						result += " line";
						break;
					case PLANE:
						result += " plane";
						break;
					}
				}
				
				else if (bladeClass() == PSEUDOSCALAR) {
					result += " pseudoscalar";
				}

			}
			else if (isVersor()) {
				result += ":";
				switch(versorSubclass()) {
					case ODD_VERSOR:
						result += " odd versor";
						break;
					case EVEN_VERSOR:
						result += " even versor";
						break;
					case ROTOR:
						result += " rotor";
						break;
				}
			}
		}
	}

	else if (model() == CONFORMAL_MODEL) {
		// model:
		result += "Conformal";

		// flags / special stuff:
		if (isDual()) result += " dual";
		if (isZero()) result += " zero";

		// blade / versor / multivector?
		if (isBlade()) result += " blade";
		else if (isVersor()) result += " versor";
		else result += " multivector";

		if (!isZero()) {
			if (isBlade()) {
				result += ":";
				switch (bladeClass()) {
				case SCALAR:
					result += " scalar";
					break;
				case FLAT:
					switch(bladeSubclass()) {
					case SCALAR:
						result += " scalar";
						break;
					case POINT:
						result += " flat point";
						break;
					case LINE:
						result += " line";
						break;
					case PLANE:
						result += " plane";
						break;
					}
					break;
				case ROUND:
					switch(bladeSubclass()) {
					case POINT_PAIR:
						result += " point pair";
						break;
					case CIRCLE:
						result += " circle";
						break;
					case SPHERE:
						result += " sphere";
						break;
					}
					break;
				case TANGENT:
				case FREE:
					result +=(bladeClass() == FREE) ? " free" : " tangent";
					switch(bladeSubclass()) {
					case SCALAR:
						result += " point";
						break;
					case VECTOR:
						result += " vector";
						break;
					case BIVECTOR:
						result += " bivector";
						break;
					case TRIVECTOR:
						result += " trivector";
						break;
					}
					break;
				case PSEUDOSCALAR:
					result += " pseudoscalar";
					break;
				default:
					result += "of unknown class";
					break;
				}
			}
		}

	}
	else {
		result += "multivector from unknown model";
	}
	return result;

}


} /** end of namespace mv_analyze */
