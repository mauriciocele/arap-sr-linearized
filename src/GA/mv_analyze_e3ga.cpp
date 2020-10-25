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

namespace mv_analyze {

using namespace e3ga;

void mvAnalysis::analyze(e3ga::mv X, int intFlags/* = 0 */,  double epsilon/* = DEFAULT_EPSILON */) {
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
		X = e3ga::dual(X); // should 'dual' be 'undual?'
	}

	// get basic mv type (BLADE, VERSOR, etc)
	m_mvType = e3ga::mvType(X, (e3ga::mv::Float)epsilon);
	m_type[1] = m_mvType.m_type;

	// zero blade? 
	if (m_mvType.m_zero) {
		m_type[3] = ZERO;
		m_sc[0] = 0;
		return;
	}

	// versor?
	else if (m_mvType.m_type == VERSOR) {
		m_type[3] = (m_mvType.m_parity) ? ODD_VERSOR : ROTOR;		

		if (m_type[3] == ROTOR) {
			// format for rotor:
			// m_sc[0] = magnitude
			// m_sc[1] = angle
			// m_vc[0], m_vc[1] is basis for rotation plane
			// m_vc[2] is normal to rotation plane
			e3ga::factorizeBlade(_bivector(X), m_vc);
			m_vc[2] = _vector(e3ga::dual(m_vc[0] ^ m_vc[1]));

			m_sc[0] = e3ga::_Float(norm_e(X));
	//		printf("%f %f\n", e3ga::_Float(e3ga::norm_e(e3ga::_bivector(X))), e3ga::_Float(X));
			m_sc[1] = (e3ga::mv::Float)(2.0 * atan2(e3ga::_Float(e3ga::norm_e(e3ga::_bivector(X))), e3ga::_Float(X)));
		}
		else {
			// no info for odd versor, since we do not draw it?
		}

		return;
	}

	// blade
	else if (m_mvType.m_type == BLADE) {
		// format for blade:
		// m_sc[0] = size (unit_e())

		// for a vector: 
		// m_vc[0] is the unit direction

		// for bivector:
		// m_vc[0], m_vc[1] is basis for plane

		// for trivector:
		// m_vc[0], m_vc[1], m_vc[2]

		m_sc[0] = e3ga::_Float(e3ga::norm_e(X));
		if (m_mvType.m_grade == 1) {
			m_type[3] = VECTOR;
			m_vc[0] = e3ga::_vector(e3ga::unit_e(X));
		}
		else if (m_mvType.m_grade == 2) {
			m_type[3] = BIVECTOR;
			e3ga::factorizeBlade(_bivector(X), m_vc);
			m_vc[2] = _vector(e3ga::dual(m_vc[0] ^ m_vc[1]));
		}
		else if (m_mvType.m_grade == 3) {
			m_type[3] = TRIVECTOR;
			m_vc[0] = e3ga::_vector(e3ga::e1);
			m_vc[1] = e3ga::_vector(e3ga::e2);
			m_vc[2] = e3ga::_vector(e3ga::e3);
		}
		return;
	}
}

} /** end of namespace mv_analyze */
