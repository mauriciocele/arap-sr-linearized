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

namespace mv_analyze {

using namespace h3ga;


void mvAnalysis::analyze(h3ga::mv X, int intFlags/* = 0 */,  double epsilon/* = DEFAULT_EPSILON */, 
						 const h3ga::normalizedPoint &probe /*= h3ga::_normalizedPoint(h3ga::e0)*/) {
	// cleanup:
	m_flags = FLAG_VALID;
	m_epsilon = epsilon;
	for (int i = 0; i < NB_TYPE_LEVELS; i++)
		m_type[i] = INVALID_TYPE;

	// type is vector space
	m_type[0] = HOMOGENEOUS_MODEL;
	m_type[2] = NOT_USED; // later on in this function, if 'X' it is a blade, the m_type[2] will be set to either LOCALIZED_BLADE or INFINITE_BLADE

	// forced dual interpretation?
	if (intFlags & FLAG_DUAL) {
		m_flags ^= FLAG_DUAL;
		X = h3ga::dual(X); // should 'dual' be 'undual?'
	}

	// get basic mv type (BLADE, VERSOR, etc)
	m_mvType = h3ga::mvType(X, (h3ga::mv::Float)epsilon);
	m_type[1] = m_mvType.m_type;

	// zero blade? 
	if (m_mvType.m_zero) {
		m_type[3] = ZERO;
		m_sc[0] = 0;
		return;
	}

	// versor?
	else if (m_mvType.m_type == VERSOR) {
		if (m_mvType.m_parity) {
			// no info for odd versor, since we don't draw it
			m_type[3] = ODD_VERSOR;
		}
		else {
			if (_Float(norm_e(X - _rotor(X))) < epsilon) {
				// rotor
				m_type[3] = ROTOR;

				// test by applying it to e0?
				// or simply cast to rotor, subtract, get norm, must be (near-)zero

				// format for versor:
				// m_sc[0] = magnitude
				// m_sc[1] = angle
				// m_vc[0], m_vc[1] is basis for rotation plane
				// m_vc[2] is normal to rotation plane
				h3ga::vector factors[2];
				h3ga::factorizeBlade(_bivector(X), factors);
				m_vc[0] = e3ga::vector(e3ga::vector_e1_e2_e3, factors[0].getC(h3ga::vector_e1_e2_e3));
				m_vc[1] = e3ga::vector(e3ga::vector_e1_e2_e3, factors[1].getC(h3ga::vector_e1_e2_e3));
				m_vc[2] = _vector(e3ga::dual(m_vc[0] ^ m_vc[1]));

				m_sc[0] = h3ga::_Float(norm_e(X));
				m_sc[1] = (h3ga::mv::Float)(2.0 * atan2(h3ga::_Float(h3ga::norm_e(h3ga::_bivector(X))), h3ga::_Float(X)));
			}
			else {
				// no info for even versor, since we don't draw it
				m_type[3] = EVEN_VERSOR;
			}
		}
		return;
	}

	// blade
	else if (m_mvType.m_type == BLADE) {
		if (m_mvType.m_grade == 0) {
			m_type[2] =	LOCALIZED_BLADE;
			m_type[3] = SCALAR;

			// format for scalar:
			// m_sc[0] = size (unit_e())
			m_sc[0] = _Float(X);
			return;
		}
		else if (m_mvType.m_grade == 4) {
			m_type[2] =	 LOCALIZED_BLADE;
			m_type[3] = PSEUDOSCALAR;

			// format for scalar:
			// m_sc[0] = size
			m_sc[0] = X.e1e2e3e0();
			return;
		}
		else {
			h3ga::mv attitude = h3ga::e0i << X;
			h3ga::mv moment = h3ga::e0i << (h3ga::e0 ^ X);

			if (_Float(norm_e(attitude)) < epsilon) {
				m_type[2] =	 INFINITE_BLADE;
				// INFINITE blade
				// VECTOR, LINE, or PLANE

				// format for INFINITE blade:
				// m_sc[0] = size (norm_e())

				// for a VECTOR: 
				// m_vc[0] is the unit direction

				// for LINE:
				// m_vc[0], m_vc[1] is basis for plane

				// for PLANE:
				// m_vc[0], m_vc[1], m_vc[2] is basis for trivector

				m_sc[0] = _Float(norm_e(X));
				if (m_mvType.m_grade == 1) {
					m_type[3] = VECTOR;
					m_vc[0] = e3ga::vector(e3ga::vector_e1_e2_e3, h3ga::_vector(unit_e(X)).getC(h3ga::vector_e1_e2_e3));
				}
				else if (m_mvType.m_grade == 2) {
					m_type[3] = LINE;
					h3ga::vector factors[2];
					h3ga::factorizeBlade(_bivector(X), factors);
					m_vc[0] = e3ga::vector(e3ga::vector_e1_e2_e3, factors[0].getC(h3ga::vector_e1_e2_e3));
					m_vc[1] = e3ga::vector(e3ga::vector_e1_e2_e3, factors[1].getC(h3ga::vector_e1_e2_e3));
				}
				else if (m_mvType.m_grade == 3) {
					m_type[3] = PLANE;
					m_vc[0] = e3ga::e1;
					m_vc[1] = e3ga::e2;
					m_vc[2] = e3ga::e3;
				}
				return;
			}
			else {
				// translate blade such that probe == origin
				h3ga::vector T = _vector(probe);
				if (_Float(h3ga::norm_e2(T)) != 0.0f)
					X = X - (T ^ (h3ga::e0 << X));
			

				// recompute attitude & moment
				attitude = h3ga::e0i << X;
				moment = h3ga::e0i << (h3ga::e0 ^ X);

				m_type[2] =	 LOCALIZED_BLADE;

				h3ga::vector supportVector = h3ga::_vector(moment * inverse(attitude));
				h3ga::point supportPoint = h3ga::_point(X * inverse(attitude));

				// LOCALIZED blade
				// POINT, LINE, or PLANE

				// format for LOCALIZED blade:
				// m_sc[0] = size (norm_e())
				// m_pt[0] is support point

				// for a VECTOR: 
				// -

				// for LINE:
				// m_vc[0], is basis for moment
				// m_vc[2] basis for dual of moment

				// for PLANE:
				// m_vc[0], m_vc[1] is basis for moment
				// m_vc[2] dual of moment

				m_sc[0] = _Float(norm_e(X));
				m_pt[0] = e3ga::vector(e3ga::vector_e1_e2_e3, supportVector.getC(h3ga::vector_e1_e2_e3));

				if (m_mvType.m_grade == 1) {
					m_type[3] = VECTOR;
				}
				else if (m_mvType.m_grade == 2) {
					m_type[3] = LINE;
					m_vc[0] = e3ga::vector(e3ga::vector_e1_e2_e3, h3ga::_vector(unit_e(attitude)).getC(h3ga::vector_e1_e2_e3));
					// dual (in e3ga)
					e3ga::factorizeBlade(dual(m_vc[0]), m_vc + 1);
				}
				else if (m_mvType.m_grade == 3) {
					m_type[3] = PLANE;

					h3ga::vector factors[2];
					h3ga::factorizeBlade(_bivector(attitude), factors);
					m_vc[0] = e3ga::vector(e3ga::vector_e1_e2_e3, factors[0].getC(h3ga::vector_e1_e2_e3));
					m_vc[1] = e3ga::vector(e3ga::vector_e1_e2_e3, factors[1].getC(h3ga::vector_e1_e2_e3));
					m_vc[2] = _vector(e3ga::dual(m_vc[0] ^ m_vc[1]));
				}

				// translate support point to undo the probe translation, above:
				if (_Float(h3ga::norm_e2(T)) != 0.0)
					m_pt[0] = _vector(m_pt[0] + T.e1() * e3ga::e1 + T.e2() * e3ga::e2 + T.e3() * e3ga::e3);

				return;
			}
		}
	}
}

} /** end of namespace mv_analyze */
