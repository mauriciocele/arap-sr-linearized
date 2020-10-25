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
#include "e2ga_util.h"

namespace mv_analyze {

using namespace e2ga;

void mvAnalysis::analyze(e2ga::mv X, int intFlags/* = 0 */,  double epsilon/* = DEFAULT_EPSILON */) {
	// cleanup:
	m_flags = FLAG_VALID;
	m_epsilon = epsilon;
	for (int i = 0; i < NB_TYPE_LEVELS; i++)
		m_type[i] = INVALID_TYPE;

	// type is vector space
	m_type[0] = VECTOR_SPACE_MODEL;
	m_type[2] = NOT_USED; // no blade/versor classes

	// forced dual interpretation?
	if (intFlags & FLAG_DUAL) {
		m_flags ^= FLAG_DUAL;
		X = e2ga::dual(X); // should 'dual' be 'undual?'
	}

	// get basic mv type (BLADE, VERSOR, etc)
	m_mvType = e2ga::mvType(X, (e2ga::mv::Float)epsilon);
	m_type[1] = m_mvType.m_type;

	// zero blade? 
	if (m_mvType.m_zero) {
		m_type[3] = ZERO;
		m_sc[0] = 0;
		return;
	}

	// versor?
	else if (m_mvType.m_type == VERSOR) {
		m_type[3] = EVEN_VERSOR;		

		// format for versor:
		// m_sc[0] = magnitude
		// m_sc[1] = angle
		// m_vc[0], m_vc[1] is basis for rotation plane
		m_vc[0] = e3ga::_vector(e3ga::e1);
		m_vc[1] = (_bivector(X).e1e2() < 0.0) ? _vector(-e3ga::e2) : _vector(e3ga::e2);

		m_sc[0] = e2ga::_Float(norm_e(X));
		m_sc[1] = 2.0f * (e3ga::mv::Float)atan2(e2ga::_Float(e2ga::norm_e(e2ga::_bivector(X))), e2ga::_Float(X));
		return;
	}

	// blade
	else if (m_mvType.m_type == BLADE) {
		m_type[3] = VECTOR + m_mvType.m_grade - 1;

		// format for blade:
		// m_sc[0] = size (norm_e())

		// for a vector: 
		// m_vc[0] is the unit direction

		// for bivector:
		// m_vc[0], m_vc[1] is basis for plane

		m_sc[0] = e2ga::_Float(e2ga::norm_e(X));
		if (m_type[3] == VECTOR) {
			e2ga::vector Xn = e2ga::_vector(e2ga::unit_e(X));
			m_vc[0] = Xn.e1() * e3ga::e1 + Xn.e2() * e3ga::e2;
		}
		else if (m_type[3] == BIVECTOR) {
			m_vc[0] = e3ga::e1;
			m_vc[1] = (_bivector(X).e1e2() < 0.0) ? _vector(-e3ga::e2) : _vector(e3ga::e2);
		}
		return;
	}
}

} /** end of namespace mv_analyze */


