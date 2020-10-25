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

#include "c2gatoc3ga.h"

c3ga::mv c2gaTOc3ga(const c2ga::mv &X) {
	int gu = 0;
	c3ga::mv::Float C[32];
	int iC = 0;
	int iX = 0;
	
	if (X.gu() & c2ga::GRADE_0) {
		C[iC++] = X.m_c[iX++]; // scalar
	}
	if (X.gu() & c2ga::GRADE_1) {
		C[iC++] = X.m_c[iX++]; // no
		C[iC++] = X.m_c[iX++]; // e1
		C[iC++] = X.m_c[iX++]; // e2
		C[iC++] = 0.0;         // e3
		C[iC++] = X.m_c[iX++]; // ni
	}
	if (X.gu() & c2ga::GRADE_2) {
		C[iC++] = X.m_c[iX++]; // no^e1
		C[iC++] = X.m_c[iX++]; // no^e2
		C[iC++] = 0.0;         // no^e3
		C[iC++] = X.m_c[iX++]; // e1^e2
		C[iC++] = 0.0;         // e2^e3
		C[iC++] = 0.0;         // e3^e1
		C[iC++] = X.m_c[iX++]; // e1^ni
		C[iC++] = X.m_c[iX++]; // e2^ni
		C[iC++] = 0.0;         // e3^ni
		C[iC++] = X.m_c[iX++]; // no^ni
	}
	if (X.gu() & c2ga::GRADE_3) {
		C[iC++] = 0.0;         // e2^e3^ni
		C[iC++] = 0.0;         // e3^e1^ni
		C[iC++] = X.m_c[iX++]; // e1^e2^ni
		C[iC++] = 0.0;         // no^e3^ni
		C[iC++] = X.m_c[iX++]; // no^e1^ni
		C[iC++] = X.m_c[iX++]; // no^e2^ni
		C[iC++] = 0.0;         // no^e2^e3
		C[iC++] = 0.0;         // no^e1^e3
		C[iC++] = X.m_c[iX++]; // no^e1^e2
		C[iC++] = 0.0;         // e1^e2^e3
	}
	if (X.gu() & c2ga::GRADE_4) {
		C[iC++] = 0.0; // e1 ^ e2 ^ e3 ^ ni
		C[iC++] = 0.0; // no ^ e2 ^ e3 ^ ni
		C[iC++] = 0.0; // no ^ e1 ^ ni ^ e3
		C[iC++] = X.m_c[iX++]; // no ^ e1 ^ e2 ^ ni
		C[iC++] = 0.0; // no ^ e1 ^ e2 ^ e3
	}

	return c3ga::mv(X.gu(), C);
}
