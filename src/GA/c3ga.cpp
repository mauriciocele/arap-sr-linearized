
// Generated on 2007-08-08 10:16:05 by G2 0.1 from 'E:\gasandbox\ga_sandbox\libgasandbox\c3ga.gs2'

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





#include <string.h>
#include "c3ga.h"

	// pre_cpp_include


	namespace c3ga {

	// The dimension of the space:
	const int mv_spaceDim = 5;

	// Is the metric of the space Euclidean?
	const bool mv_metricEuclidean = false;


	// This array can be used to lookup the number of coordinates for a grade part of a general multivector
	const int mv_gradeSize[6] = {
		1, 5, 10, 10, 5, 1 
	};

	// This array can be used to lookup the number of coordinates based on a grade usage bitmap
	const int mv_size[64] = {
		0, 1, 5, 6, 10, 11, 15, 16, 10, 11, 15, 16, 20, 21, 25, 26, 5, 6, 10, 11, 15, 16, 20, 21, 15, 16, 20, 21, 25, 26, 30, 31, 1, 2, 6, 7, 11, 12, 16, 17, 11, 12, 16, 17, 21, 22, 26, 27, 6, 7, 11, 12, 16, 17, 21, 22, 16, 17, 21, 22, 26, 27, 31, 32 
	};

	// This array of ASCIIZ strings contains the names of the basis vectors
	const char *mv_basisVectorNames[5] = {
		"no", "e1", "e2", "e3", "ni" 
	};

	// This array of integers contains the order of basis elements in the general multivector
	const int mv_basisElements[32][6] = {
		{-1}
		, {0, -1}
		, {1, -1}
		, {2, -1}
		, {3, -1}
		, {4, -1}
		, {0, 1, -1}
		, {0, 2, -1}
		, {0, 3, -1}
		, {1, 2, -1}
		, {2, 3, -1}
		, {1, 3, -1}
		, {1, 4, -1}
		, {2, 4, -1}
		, {3, 4, -1}
		, {0, 4, -1}
		, {2, 3, 4, -1}
		, {1, 3, 4, -1}
		, {1, 2, 4, -1}
		, {0, 3, 4, -1}
		, {0, 1, 4, -1}
		, {0, 2, 4, -1}
		, {0, 2, 3, -1}
		, {0, 1, 3, -1}
		, {0, 1, 2, -1}
		, {1, 2, 3, -1}
		, {1, 2, 3, 4, -1}
		, {0, 2, 3, 4, -1}
		, {0, 1, 3, 4, -1}
		, {0, 1, 2, 4, -1}
		, {0, 1, 2, 3, -1}
		, {0, 1, 2, 3, 4, -1}
	};

	// This array of integers contains the 'sign' (even/odd permutation of the canonical order) of basis elements in the general multivector
	// Use it to answer 'what is the permutation of the coordinate at index [x]'?
	const double mv_basisElementSignByIndex[32] = {
		1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0, 1.0, 1.0, 1.0 
	};


	// This array of integers contains the 'sign' (even/odd permutation of canonical order) of basis elements in the general multivector
	// Use it to answer 'what is the permutation of the coordinate of bitmap [x]'?
	const double mv_basisElementSignByBitmap[32] = {
		1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0, -1.0, 1.0, 1.0, 1.0, 1.0 
	};


	// This array of integers contains the order of basis elements in the general multivector
	// Use it to answer: 'at what index do I find basis element [x] (x = basis vector bitmap)?
	const int mv_basisElementIndexByBitmap[32] = {
		0, 1, 2, 6, 3, 7, 9, 24, 4, 8, 11, 23, 10, 22, 25, 30, 5, 15, 12, 20, 13, 21, 18, 29, 14, 19, 17, 28, 16, 27, 26, 31 
	};

	// This array of integers contains the indices of basis elements in the general multivector
	// Use it to answer: 'what basis element do I find at index [x]'?
	const int mv_basisElementBitmapByIndex[32] = {
		0, 1, 2, 4, 8, 16, 3, 5, 9, 6, 12, 10, 18, 20, 24, 17, 28, 26, 22, 25, 19, 21, 13, 11, 7, 14, 30, 29, 27, 23, 15, 31 
	};


	// This array of grade of each basis elements in the general multivector
	// Use it to answer: 'what is the grade of basis element bitmap [x]'?
	extern const int mv_basisElementGradeByBitmap[32] = {
		0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5 
	};





	// These strings determine how the output of string() is formatted.
	// You can alter them at runtime using mv_setStringFormat().

	const char *mv_string_fp = "%2.2f"; 
	const char *mv_string_start = ""; 
	const char *mv_string_end = ""; 
	const char *mv_string_mul = "*"; 
	const char *mv_string_wedge = "^"; 
	const char *mv_string_plus = " + "; 
	const char *mv_string_minus = " - "; 

	void mv_setStringFormat(const char *what, const char *format) {

		if (!strcmp(what, "fp")) 
			mv_string_fp = (format) ? format : "%2.2f"; 
		else if (!strcmp(what, "start")) 
			mv_string_start = (format) ? format : ""; 
		else if (!strcmp(what, "end")) 
			mv_string_end = (format) ? format : ""; 
		else if (!strcmp(what, "mul")) 
			mv_string_mul = (format) ? format : "*"; 
		else if (!strcmp(what, "wedge")) 
			mv_string_wedge = (format) ? format : "^"; 
		else if (!strcmp(what, "plus")) 
			mv_string_plus = (format) ? format : " + "; 
		else if (!strcmp(what, "minus")) 
			mv_string_minus = (format) ? format : " - ";	else {
			char msg[1024];
			sprintf(msg, "invalid argument to mv_setStringFormat(): %s", what);
			mv_throw_exception(msg, MV_EXCEPTION_WARNING);
		}

	}



	namespace g2Profiling {
		// Just a bunch of dummy functions:
		// Profiling is disabled, but having these functions around
		// simplifies a lot.
		void profile(unsigned int funcIdx, unsigned short storageTypeIdx, unsigned short nbArg, unsigned short argType[]) {
		}
		void reset() {
		}
		void save(const char *filename /*= "E:\\gasandbox\\ga_sandbox\\libgasandbox\\c3ga.gp2"*/, bool append /*= false*/) {
		}
		void init(const char *filename /*= "E:\\gasandbox\\ga_sandbox\\libgasandbox\\c3ga.gp2"*/,
		const char *hostName /*= "localhost"*/, int port /*= 7693*/) {
		}
	} // end of namespace g2Profiling






	// todo: for all storage formats, generate constants






	// set to 0
	void mv::set() {
		// set grade usage
		gu(0);

	}

	// set to copy 
	void mv::set(const mv &arg1) {
		// copy grade usage
		gu(arg1.gu());
		// copy coordinates
		mv_memcpy(m_c, arg1.m_c, mv_size[gu()]);

	}

	// set to scalar
	void mv::set(Float scalarVal) {
		// set grade usage
		gu(1);
		// set type (if profile)
		// set coordinate
		m_c[0] = scalarVal;

	}


	// set to coordinates 
	void mv::set(unsigned int gradeUsage, const Float *coordinates) {
		// set grade usage
		gu(gradeUsage);
		// set coordinates
		mv_memcpy(m_c, coordinates, mv_size[gu()]);

	}


	// set to 1 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 1)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;

	}

	// set to 2 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 2)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;

	}

	// set to 3 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 3)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;

	}

	// set to 4 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2, Float c3	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 4)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;
		m_c[3] = c3;

	}

	// set to 5 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2, Float c3, Float c4	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 5)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;
		m_c[3] = c3;
		m_c[4] = c4;

	}

	// set to 6 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 6)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;
		m_c[3] = c3;
		m_c[4] = c4;
		m_c[5] = c5;

	}

	// set to 7 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 7)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;
		m_c[3] = c3;
		m_c[4] = c4;
		m_c[5] = c5;
		m_c[6] = c6;

	}

	// set to 8 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 8)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;
		m_c[3] = c3;
		m_c[4] = c4;
		m_c[5] = c5;
		m_c[6] = c6;
		m_c[7] = c7;

	}

	// set to 9 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 9)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;
		m_c[3] = c3;
		m_c[4] = c4;
		m_c[5] = c5;
		m_c[6] = c6;
		m_c[7] = c7;
		m_c[8] = c8;

	}

	// set to 10 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 10)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;
		m_c[3] = c3;
		m_c[4] = c4;
		m_c[5] = c5;
		m_c[6] = c6;
		m_c[7] = c7;
		m_c[8] = c8;
		m_c[9] = c9;

	}

	// set to 11 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 11)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;
		m_c[3] = c3;
		m_c[4] = c4;
		m_c[5] = c5;
		m_c[6] = c6;
		m_c[7] = c7;
		m_c[8] = c8;
		m_c[9] = c9;
		m_c[10] = c10;

	}

	// set to 12 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 12)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;
		m_c[3] = c3;
		m_c[4] = c4;
		m_c[5] = c5;
		m_c[6] = c6;
		m_c[7] = c7;
		m_c[8] = c8;
		m_c[9] = c9;
		m_c[10] = c10;
		m_c[11] = c11;

	}

	// set to 13 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 13)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;
		m_c[3] = c3;
		m_c[4] = c4;
		m_c[5] = c5;
		m_c[6] = c6;
		m_c[7] = c7;
		m_c[8] = c8;
		m_c[9] = c9;
		m_c[10] = c10;
		m_c[11] = c11;
		m_c[12] = c12;

	}

	// set to 14 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 14)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;
		m_c[3] = c3;
		m_c[4] = c4;
		m_c[5] = c5;
		m_c[6] = c6;
		m_c[7] = c7;
		m_c[8] = c8;
		m_c[9] = c9;
		m_c[10] = c10;
		m_c[11] = c11;
		m_c[12] = c12;
		m_c[13] = c13;

	}

	// set to 15 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13, Float c14	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 15)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;
		m_c[3] = c3;
		m_c[4] = c4;
		m_c[5] = c5;
		m_c[6] = c6;
		m_c[7] = c7;
		m_c[8] = c8;
		m_c[9] = c9;
		m_c[10] = c10;
		m_c[11] = c11;
		m_c[12] = c12;
		m_c[13] = c13;
		m_c[14] = c14;

	}

	// set to 16 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13, Float c14, Float c15	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 16)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;
		m_c[3] = c3;
		m_c[4] = c4;
		m_c[5] = c5;
		m_c[6] = c6;
		m_c[7] = c7;
		m_c[8] = c8;
		m_c[9] = c9;
		m_c[10] = c10;
		m_c[11] = c11;
		m_c[12] = c12;
		m_c[13] = c13;
		m_c[14] = c14;
		m_c[15] = c15;

	}

	// set to 17 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13, Float c14, Float c15, Float c16	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 17)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;
		m_c[3] = c3;
		m_c[4] = c4;
		m_c[5] = c5;
		m_c[6] = c6;
		m_c[7] = c7;
		m_c[8] = c8;
		m_c[9] = c9;
		m_c[10] = c10;
		m_c[11] = c11;
		m_c[12] = c12;
		m_c[13] = c13;
		m_c[14] = c14;
		m_c[15] = c15;
		m_c[16] = c16;

	}

	// set to 18 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13, Float c14, Float c15, Float c16, Float c17	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 18)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;
		m_c[3] = c3;
		m_c[4] = c4;
		m_c[5] = c5;
		m_c[6] = c6;
		m_c[7] = c7;
		m_c[8] = c8;
		m_c[9] = c9;
		m_c[10] = c10;
		m_c[11] = c11;
		m_c[12] = c12;
		m_c[13] = c13;
		m_c[14] = c14;
		m_c[15] = c15;
		m_c[16] = c16;
		m_c[17] = c17;

	}

	// set to 19 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13, Float c14, Float c15, Float c16, Float c17, Float c18	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 19)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;
		m_c[3] = c3;
		m_c[4] = c4;
		m_c[5] = c5;
		m_c[6] = c6;
		m_c[7] = c7;
		m_c[8] = c8;
		m_c[9] = c9;
		m_c[10] = c10;
		m_c[11] = c11;
		m_c[12] = c12;
		m_c[13] = c13;
		m_c[14] = c14;
		m_c[15] = c15;
		m_c[16] = c16;
		m_c[17] = c17;
		m_c[18] = c18;

	}

	// set to 20 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13, Float c14, Float c15, Float c16, Float c17, Float c18, Float c19	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 20)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;
		m_c[3] = c3;
		m_c[4] = c4;
		m_c[5] = c5;
		m_c[6] = c6;
		m_c[7] = c7;
		m_c[8] = c8;
		m_c[9] = c9;
		m_c[10] = c10;
		m_c[11] = c11;
		m_c[12] = c12;
		m_c[13] = c13;
		m_c[14] = c14;
		m_c[15] = c15;
		m_c[16] = c16;
		m_c[17] = c17;
		m_c[18] = c18;
		m_c[19] = c19;

	}

	// set to 21 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13, Float c14, Float c15, Float c16, Float c17, Float c18, Float c19, Float c20	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 21)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;
		m_c[3] = c3;
		m_c[4] = c4;
		m_c[5] = c5;
		m_c[6] = c6;
		m_c[7] = c7;
		m_c[8] = c8;
		m_c[9] = c9;
		m_c[10] = c10;
		m_c[11] = c11;
		m_c[12] = c12;
		m_c[13] = c13;
		m_c[14] = c14;
		m_c[15] = c15;
		m_c[16] = c16;
		m_c[17] = c17;
		m_c[18] = c18;
		m_c[19] = c19;
		m_c[20] = c20;

	}

	// set to 22 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13, Float c14, Float c15, Float c16, Float c17, Float c18, Float c19, Float c20, Float c21	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 22)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;
		m_c[3] = c3;
		m_c[4] = c4;
		m_c[5] = c5;
		m_c[6] = c6;
		m_c[7] = c7;
		m_c[8] = c8;
		m_c[9] = c9;
		m_c[10] = c10;
		m_c[11] = c11;
		m_c[12] = c12;
		m_c[13] = c13;
		m_c[14] = c14;
		m_c[15] = c15;
		m_c[16] = c16;
		m_c[17] = c17;
		m_c[18] = c18;
		m_c[19] = c19;
		m_c[20] = c20;
		m_c[21] = c21;

	}

	// set to 23 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13, Float c14, Float c15, Float c16, Float c17, Float c18, Float c19, Float c20, Float c21, Float c22	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 23)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;
		m_c[3] = c3;
		m_c[4] = c4;
		m_c[5] = c5;
		m_c[6] = c6;
		m_c[7] = c7;
		m_c[8] = c8;
		m_c[9] = c9;
		m_c[10] = c10;
		m_c[11] = c11;
		m_c[12] = c12;
		m_c[13] = c13;
		m_c[14] = c14;
		m_c[15] = c15;
		m_c[16] = c16;
		m_c[17] = c17;
		m_c[18] = c18;
		m_c[19] = c19;
		m_c[20] = c20;
		m_c[21] = c21;
		m_c[22] = c22;

	}

	// set to 24 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13, Float c14, Float c15, Float c16, Float c17, Float c18, Float c19, Float c20, Float c21, Float c22, Float c23	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 24)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;
		m_c[3] = c3;
		m_c[4] = c4;
		m_c[5] = c5;
		m_c[6] = c6;
		m_c[7] = c7;
		m_c[8] = c8;
		m_c[9] = c9;
		m_c[10] = c10;
		m_c[11] = c11;
		m_c[12] = c12;
		m_c[13] = c13;
		m_c[14] = c14;
		m_c[15] = c15;
		m_c[16] = c16;
		m_c[17] = c17;
		m_c[18] = c18;
		m_c[19] = c19;
		m_c[20] = c20;
		m_c[21] = c21;
		m_c[22] = c22;
		m_c[23] = c23;

	}

	// set to 25 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13, Float c14, Float c15, Float c16, Float c17, Float c18, Float c19, Float c20, Float c21, Float c22, Float c23, Float c24	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 25)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;
		m_c[3] = c3;
		m_c[4] = c4;
		m_c[5] = c5;
		m_c[6] = c6;
		m_c[7] = c7;
		m_c[8] = c8;
		m_c[9] = c9;
		m_c[10] = c10;
		m_c[11] = c11;
		m_c[12] = c12;
		m_c[13] = c13;
		m_c[14] = c14;
		m_c[15] = c15;
		m_c[16] = c16;
		m_c[17] = c17;
		m_c[18] = c18;
		m_c[19] = c19;
		m_c[20] = c20;
		m_c[21] = c21;
		m_c[22] = c22;
		m_c[23] = c23;
		m_c[24] = c24;

	}

	// set to 26 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13, Float c14, Float c15, Float c16, Float c17, Float c18, Float c19, Float c20, Float c21, Float c22, Float c23, Float c24, Float c25	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 26)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;
		m_c[3] = c3;
		m_c[4] = c4;
		m_c[5] = c5;
		m_c[6] = c6;
		m_c[7] = c7;
		m_c[8] = c8;
		m_c[9] = c9;
		m_c[10] = c10;
		m_c[11] = c11;
		m_c[12] = c12;
		m_c[13] = c13;
		m_c[14] = c14;
		m_c[15] = c15;
		m_c[16] = c16;
		m_c[17] = c17;
		m_c[18] = c18;
		m_c[19] = c19;
		m_c[20] = c20;
		m_c[21] = c21;
		m_c[22] = c22;
		m_c[23] = c23;
		m_c[24] = c24;
		m_c[25] = c25;

	}

	// set to 27 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13, Float c14, Float c15, Float c16, Float c17, Float c18, Float c19, Float c20, Float c21, Float c22, Float c23, Float c24, Float c25, Float c26	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 27)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;
		m_c[3] = c3;
		m_c[4] = c4;
		m_c[5] = c5;
		m_c[6] = c6;
		m_c[7] = c7;
		m_c[8] = c8;
		m_c[9] = c9;
		m_c[10] = c10;
		m_c[11] = c11;
		m_c[12] = c12;
		m_c[13] = c13;
		m_c[14] = c14;
		m_c[15] = c15;
		m_c[16] = c16;
		m_c[17] = c17;
		m_c[18] = c18;
		m_c[19] = c19;
		m_c[20] = c20;
		m_c[21] = c21;
		m_c[22] = c22;
		m_c[23] = c23;
		m_c[24] = c24;
		m_c[25] = c25;
		m_c[26] = c26;

	}

	// set to 28 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13, Float c14, Float c15, Float c16, Float c17, Float c18, Float c19, Float c20, Float c21, Float c22, Float c23, Float c24, Float c25, Float c26, Float c27	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 28)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;
		m_c[3] = c3;
		m_c[4] = c4;
		m_c[5] = c5;
		m_c[6] = c6;
		m_c[7] = c7;
		m_c[8] = c8;
		m_c[9] = c9;
		m_c[10] = c10;
		m_c[11] = c11;
		m_c[12] = c12;
		m_c[13] = c13;
		m_c[14] = c14;
		m_c[15] = c15;
		m_c[16] = c16;
		m_c[17] = c17;
		m_c[18] = c18;
		m_c[19] = c19;
		m_c[20] = c20;
		m_c[21] = c21;
		m_c[22] = c22;
		m_c[23] = c23;
		m_c[24] = c24;
		m_c[25] = c25;
		m_c[26] = c26;
		m_c[27] = c27;

	}

	// set to 29 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13, Float c14, Float c15, Float c16, Float c17, Float c18, Float c19, Float c20, Float c21, Float c22, Float c23, Float c24, Float c25, Float c26, Float c27, Float c28	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 29)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;
		m_c[3] = c3;
		m_c[4] = c4;
		m_c[5] = c5;
		m_c[6] = c6;
		m_c[7] = c7;
		m_c[8] = c8;
		m_c[9] = c9;
		m_c[10] = c10;
		m_c[11] = c11;
		m_c[12] = c12;
		m_c[13] = c13;
		m_c[14] = c14;
		m_c[15] = c15;
		m_c[16] = c16;
		m_c[17] = c17;
		m_c[18] = c18;
		m_c[19] = c19;
		m_c[20] = c20;
		m_c[21] = c21;
		m_c[22] = c22;
		m_c[23] = c23;
		m_c[24] = c24;
		m_c[25] = c25;
		m_c[26] = c26;
		m_c[27] = c27;
		m_c[28] = c28;

	}

	// set to 30 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13, Float c14, Float c15, Float c16, Float c17, Float c18, Float c19, Float c20, Float c21, Float c22, Float c23, Float c24, Float c25, Float c26, Float c27, Float c28, Float c29	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 30)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;
		m_c[3] = c3;
		m_c[4] = c4;
		m_c[5] = c5;
		m_c[6] = c6;
		m_c[7] = c7;
		m_c[8] = c8;
		m_c[9] = c9;
		m_c[10] = c10;
		m_c[11] = c11;
		m_c[12] = c12;
		m_c[13] = c13;
		m_c[14] = c14;
		m_c[15] = c15;
		m_c[16] = c16;
		m_c[17] = c17;
		m_c[18] = c18;
		m_c[19] = c19;
		m_c[20] = c20;
		m_c[21] = c21;
		m_c[22] = c22;
		m_c[23] = c23;
		m_c[24] = c24;
		m_c[25] = c25;
		m_c[26] = c26;
		m_c[27] = c27;
		m_c[28] = c28;
		m_c[29] = c29;

	}

	// set to 31 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13, Float c14, Float c15, Float c16, Float c17, Float c18, Float c19, Float c20, Float c21, Float c22, Float c23, Float c24, Float c25, Float c26, Float c27, Float c28, Float c29, Float c30	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 31)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;
		m_c[3] = c3;
		m_c[4] = c4;
		m_c[5] = c5;
		m_c[6] = c6;
		m_c[7] = c7;
		m_c[8] = c8;
		m_c[9] = c9;
		m_c[10] = c10;
		m_c[11] = c11;
		m_c[12] = c12;
		m_c[13] = c13;
		m_c[14] = c14;
		m_c[15] = c15;
		m_c[16] = c16;
		m_c[17] = c17;
		m_c[18] = c18;
		m_c[19] = c19;
		m_c[20] = c20;
		m_c[21] = c21;
		m_c[22] = c22;
		m_c[23] = c23;
		m_c[24] = c24;
		m_c[25] = c25;
		m_c[26] = c26;
		m_c[27] = c27;
		m_c[28] = c28;
		m_c[29] = c29;
		m_c[30] = c30;

	}

	// set to 32 coordinates 
	void mv::set(unsigned int gradeUsage, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13, Float c14, Float c15, Float c16, Float c17, Float c18, Float c19, Float c20, Float c21, Float c22, Float c23, Float c24, Float c25, Float c26, Float c27, Float c28, Float c29, Float c30, Float c31	) {
		// set grade usage
		gu(gradeUsage);
		// check the number of coordinates
		if (mv_size[gu()] != 32)
			throw (-1); // todo: more sensible exception
		// set coordinates
		m_c[0] = c0;
		m_c[1] = c1;
		m_c[2] = c2;
		m_c[3] = c3;
		m_c[4] = c4;
		m_c[5] = c5;
		m_c[6] = c6;
		m_c[7] = c7;
		m_c[8] = c8;
		m_c[9] = c9;
		m_c[10] = c10;
		m_c[11] = c11;
		m_c[12] = c12;
		m_c[13] = c13;
		m_c[14] = c14;
		m_c[15] = c15;
		m_c[16] = c16;
		m_c[17] = c17;
		m_c[18] = c18;
		m_c[19] = c19;
		m_c[20] = c20;
		m_c[21] = c21;
		m_c[22] = c22;
		m_c[23] = c23;
		m_c[24] = c24;
		m_c[25] = c25;
		m_c[26] = c26;
		m_c[27] = c27;
		m_c[28] = c28;
		m_c[29] = c29;
		m_c[30] = c30;
		m_c[31] = c31;

	}



	// set to no_t 
	void mv::set(const no_t & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;


	}
	// set to e1_t 
	void mv::set(const e1_t & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)0;
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;


	}
	// set to e2_t 
	void mv::set(const e2_t & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = arg1.m_c[0] ;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;


	}
	// set to e3_t 
	void mv::set(const e3_t & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[0] ;
		m_c[4] = (Float)0;


	}
	// set to ni_t 
	void mv::set(const ni_t & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = arg1.m_c[0] ;


	}
	// set to scalar 
	void mv::set(const scalar & arg1) {

		// set grade usage 
		gu(1);


		m_c[0] = arg1.m_c[0] ;


	}
	// set to noni_t 
	void mv::set(const noni_t & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = arg1.m_c[0] ;


	}
	// set to point 
	void mv::set(const point & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[3] ;
		m_c[4] = arg1.m_c[4] ;


	}
	// set to normalizedPoint 
	void mv::set(const normalizedPoint & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)1.0f; 
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = arg1.m_c[2] ;
		m_c[4] = arg1.m_c[3] ;


	}
	// set to flatPoint 
	void mv::set(const flatPoint & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = arg1.m_c[0] ;
		m_c[7] = arg1.m_c[1] ;
		m_c[8] = arg1.m_c[2] ;
		m_c[9] = arg1.m_c[3] ;


	}
	// set to normalizedFlatPoint 
	void mv::set(const normalizedFlatPoint & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = arg1.m_c[0] ;
		m_c[7] = arg1.m_c[1] ;
		m_c[8] = arg1.m_c[2] ;
		m_c[9] = (Float)1.0f; 


	}
	// set to pointPair 
	void mv::set(const pointPair & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[3] ;
		m_c[4] = arg1.m_c[4] ;
		m_c[5] = arg1.m_c[5] ;
		m_c[6] = arg1.m_c[6] ;
		m_c[7] = arg1.m_c[7] ;
		m_c[8] = arg1.m_c[8] ;
		m_c[9] = arg1.m_c[9] ;


	}
	// set to line 
	void mv::set(const line & arg1) {

		// set grade usage 
		gu(8);


		m_c[0] = arg1.m_c[2] ;
		m_c[1] = arg1.m_c[1] * (Float)-1.0;
		m_c[2] = arg1.m_c[0] ;
		m_c[3] = arg1.m_c[5] * (Float)-1.0;
		m_c[4] = arg1.m_c[3] * (Float)-1.0;
		m_c[5] = arg1.m_c[4] * (Float)-1.0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;


	}
	// set to dualLine 
	void mv::set(const dualLine & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[0] ;
		m_c[4] = arg1.m_c[2] ;
		m_c[5] = arg1.m_c[1] * (Float)-1.0;
		m_c[6] = arg1.m_c[3] ;
		m_c[7] = arg1.m_c[4] ;
		m_c[8] = arg1.m_c[5] ;
		m_c[9] = (Float)0;


	}
	// set to plane 
	void mv::set(const plane & arg1) {

		// set grade usage 
		gu(16);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[3] ;
		m_c[2] = arg1.m_c[2] * (Float)-1.0;
		m_c[3] = arg1.m_c[1] ;
		m_c[4] = (Float)0;


	}
	// set to dualPlane 
	void mv::set(const dualPlane & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)0;
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = arg1.m_c[2] ;
		m_c[4] = arg1.m_c[3] ;


	}
	// set to circle 
	void mv::set(const circle & arg1) {

		// set grade usage 
		gu(8);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[3] ;
		m_c[4] = arg1.m_c[4] ;
		m_c[5] = arg1.m_c[5] ;
		m_c[6] = arg1.m_c[6] ;
		m_c[7] = arg1.m_c[7] ;
		m_c[8] = arg1.m_c[8] ;
		m_c[9] = arg1.m_c[9] ;


	}
	// set to sphere 
	void mv::set(const sphere & arg1) {

		// set grade usage 
		gu(16);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[3] ;
		m_c[2] = arg1.m_c[2] * (Float)-1.0;
		m_c[3] = arg1.m_c[1] ;
		m_c[4] = arg1.m_c[4] * (Float)-1.0;


	}
	// set to dualSphere 
	void mv::set(const dualSphere & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[3] ;
		m_c[4] = arg1.m_c[4] ;


	}
	// set to normalizedSphere 
	void mv::set(const normalizedSphere & arg1) {

		// set grade usage 
		gu(16);


		m_c[0] = (Float)1.0f; 
		m_c[1] = arg1.m_c[2] ;
		m_c[2] = arg1.m_c[1] * (Float)-1.0;
		m_c[3] = arg1.m_c[0] ;
		m_c[4] = arg1.m_c[3] * (Float)-1.0;


	}
	// set to normalizedDualSphere 
	void mv::set(const normalizedDualSphere & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)1.0f; 
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = arg1.m_c[2] ;
		m_c[4] = arg1.m_c[3] ;


	}
	// set to freeVector 
	void mv::set(const freeVector & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = arg1.m_c[0] ;
		m_c[7] = arg1.m_c[1] ;
		m_c[8] = arg1.m_c[2] ;
		m_c[9] = (Float)0;


	}
	// set to freeBivector 
	void mv::set(const freeBivector & arg1) {

		// set grade usage 
		gu(8);


		m_c[0] = arg1.m_c[1] ;
		m_c[1] = arg1.m_c[2] ;
		m_c[2] = arg1.m_c[0] ;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;


	}
	// set to freeTrivector 
	void mv::set(const freeTrivector & arg1) {

		// set grade usage 
		gu(16);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;


	}
	// set to tangentVector 
	void mv::set(const tangentVector & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[3] ;
		m_c[4] = arg1.m_c[4] ;
		m_c[5] = arg1.m_c[5] ;
		m_c[6] = arg1.m_c[6] ;
		m_c[7] = arg1.m_c[7] ;
		m_c[8] = arg1.m_c[8] ;
		m_c[9] = arg1.m_c[9] ;


	}
	// set to tangentBivector 
	void mv::set(const tangentBivector & arg1) {

		// set grade usage 
		gu(8);


		m_c[0] = arg1.m_c[1] ;
		m_c[1] = arg1.m_c[2] ;
		m_c[2] = arg1.m_c[3] ;
		m_c[3] = arg1.m_c[4] ;
		m_c[4] = arg1.m_c[5] ;
		m_c[5] = arg1.m_c[6] ;
		m_c[6] = arg1.m_c[7] ;
		m_c[7] = arg1.m_c[8] ;
		m_c[8] = arg1.m_c[9] ;
		m_c[9] = arg1.m_c[0] ;


	}
	// set to vectorE2GA 
	void mv::set(const vectorE2GA & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)0;
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;


	}
	// set to vectorE3GA 
	void mv::set(const vectorE3GA & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)0;
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = arg1.m_c[2] ;
		m_c[4] = (Float)0;


	}
	// set to bivectorE3GA 
	void mv::set(const bivectorE3GA & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[0] ;
		m_c[4] = arg1.m_c[1] ;
		m_c[5] = arg1.m_c[2] ;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;


	}
	// set to TRversorLog 
	void mv::set(const TRversorLog & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[0] ;
		m_c[4] = arg1.m_c[1] ;
		m_c[5] = arg1.m_c[2] ;
		m_c[6] = arg1.m_c[3] ;
		m_c[7] = arg1.m_c[4] ;
		m_c[8] = arg1.m_c[5] ;
		m_c[9] = (Float)0;


	}
	// set to TRSversorLog 
	void mv::set(const TRSversorLog & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[0] ;
		m_c[4] = arg1.m_c[2] ;
		m_c[5] = arg1.m_c[1] * (Float)-1.0;
		m_c[6] = arg1.m_c[3] ;
		m_c[7] = arg1.m_c[4] ;
		m_c[8] = arg1.m_c[5] ;
		m_c[9] = arg1.m_c[6] ;


	}
	// set to TRversor 
	void mv::set(const TRversor & arg1) {

		// set grade usage 
		gu(21);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = arg1.m_c[1] ;
		m_c[5] = arg1.m_c[3] ;
		m_c[6] = arg1.m_c[2] * (Float)-1.0;
		m_c[7] = arg1.m_c[4] ;
		m_c[8] = arg1.m_c[5] ;
		m_c[9] = arg1.m_c[6] ;
		m_c[10] = (Float)0;
		m_c[11] = arg1.m_c[7] ;
		m_c[12] = (Float)0;
		m_c[13] = (Float)0;
		m_c[14] = (Float)0;
		m_c[15] = (Float)0;


	}
	// set to TRSversor 
	void mv::set(const TRSversor & arg1) {

		// set grade usage 
		gu(21);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = arg1.m_c[1] ;
		m_c[5] = arg1.m_c[3] ;
		m_c[6] = arg1.m_c[2] * (Float)-1.0;
		m_c[7] = arg1.m_c[4] ;
		m_c[8] = arg1.m_c[5] ;
		m_c[9] = arg1.m_c[6] ;
		m_c[10] = arg1.m_c[7] ;
		m_c[11] = arg1.m_c[11] ;
		m_c[12] = arg1.m_c[10] ;
		m_c[13] = arg1.m_c[9] * (Float)-1.0;
		m_c[14] = arg1.m_c[8] ;
		m_c[15] = (Float)0;


	}
	// set to evenVersor 
	void mv::set(const evenVersor & arg1) {

		// set grade usage 
		gu(21);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[3] ;
		m_c[4] = arg1.m_c[4] ;
		m_c[5] = arg1.m_c[5] ;
		m_c[6] = arg1.m_c[6] ;
		m_c[7] = arg1.m_c[7] ;
		m_c[8] = arg1.m_c[8] ;
		m_c[9] = arg1.m_c[9] ;
		m_c[10] = arg1.m_c[10] ;
		m_c[11] = arg1.m_c[11] ;
		m_c[12] = arg1.m_c[14] ;
		m_c[13] = arg1.m_c[13] * (Float)-1.0;
		m_c[14] = arg1.m_c[12] ;
		m_c[15] = arg1.m_c[15] * (Float)-1.0;


	}
	// set to translator 
	void mv::set(const translator & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = arg1.m_c[1] ;
		m_c[8] = arg1.m_c[2] ;
		m_c[9] = arg1.m_c[3] ;
		m_c[10] = (Float)0;


	}
	// set to normalizedTranslator 
	void mv::set(const normalizedTranslator & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = (Float)1.0f; 
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = arg1.m_c[0] ;
		m_c[8] = arg1.m_c[1] ;
		m_c[9] = arg1.m_c[2] ;
		m_c[10] = (Float)0;


	}
	// set to rotor 
	void mv::set(const rotor & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = arg1.m_c[1] ;
		m_c[5] = arg1.m_c[2] ;
		m_c[6] = arg1.m_c[3] ;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;
		m_c[10] = (Float)0;


	}
	// set to scalor 
	void mv::set(const scalor & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;
		m_c[10] = arg1.m_c[1] ;


	}
	// set to __no_ct__ 
	void mv::set(const __no_ct__ & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)1.0f; 
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;


	}
	// set to __e1_ct__ 
	void mv::set(const __e1_ct__ & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)0;
		m_c[1] = (Float)1.0f; 
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;


	}
	// set to __e2_ct__ 
	void mv::set(const __e2_ct__ & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)1.0f; 
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;


	}
	// set to __e3_ct__ 
	void mv::set(const __e3_ct__ & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)1.0f; 
		m_c[4] = (Float)0;


	}
	// set to __ni_ct__ 
	void mv::set(const __ni_ct__ & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)1.0f; 


	}
	// set to __noni_ct__ 
	void mv::set(const __noni_ct__ & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)1.0f; 


	}
	// set to __e3ni_ct__ 
	void mv::set(const __e3ni_ct__ & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)1.0f; 
		m_c[9] = (Float)0;


	}
	// set to __e2ni_ct__ 
	void mv::set(const __e2ni_ct__ & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)1.0f; 
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;


	}
	// set to __I3_ct__ 
	void mv::set(const __I3_ct__ & arg1) {

		// set grade usage 
		gu(8);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)1.0f; 


	}
	// set to __e1ni_ct__ 
	void mv::set(const __e1ni_ct__ & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)1.0f; 
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;


	}
	// set to __I5_ct__ 
	void mv::set(const __I5_ct__ & arg1) {

		// set grade usage 
		gu(32);


		m_c[0] = (Float)1.0f; 


	}
	// set to __I5i_ct__ 
	void mv::set(const __I5i_ct__ & arg1) {

		// set grade usage 
		gu(32);


		m_c[0] = (Float)-1.0f; 


	}
	// set to __syn_smv___e1_e2_e3_ni_nof_1_0 
	void mv::set(const __syn_smv___e1_e2_e3_ni_nof_1_0 & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)-1.0f; 
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = arg1.m_c[2] ;
		m_c[4] = arg1.m_c[3] ;


	}
	// set to __syn_smv___scalar_noe1_noe2_e1e2_noe3_e1e3_e2e3_noni_e1ni_e2ni_e3ni 
	void mv::set(const __syn_smv___scalar_noe1_noe2_e1e2_noe3_e1e3_e2e3_noni_e1ni_e2ni_e3ni & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[4] ;
		m_c[4] = arg1.m_c[3] ;
		m_c[5] = arg1.m_c[6] ;
		m_c[6] = arg1.m_c[5] * (Float)-1.0;
		m_c[7] = arg1.m_c[8] ;
		m_c[8] = arg1.m_c[9] ;
		m_c[9] = arg1.m_c[10] ;
		m_c[10] = arg1.m_c[7] ;


	}
	// set to __syn_smv___scalar_noe1_noe2_noe3_noni 
	void mv::set(const __syn_smv___scalar_noe1_noe2_noe3_noni & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[3] ;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;
		m_c[10] = arg1.m_c[4] ;


	}
	// set to __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_noe2e3_ni_noe1ni_noe2ni_noe3ni 
	void mv::set(const __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_noe2e3_ni_noe1ni_noe2ni_noe3ni & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[4] ;
		m_c[4] = arg1.m_c[7] ;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = arg1.m_c[10] ;
		m_c[9] = arg1.m_c[8] ;
		m_c[10] = arg1.m_c[9] ;
		m_c[11] = arg1.m_c[6] ;
		m_c[12] = arg1.m_c[5] ;
		m_c[13] = arg1.m_c[3] ;
		m_c[14] = (Float)0;


	}
	// set to __syn_smv___scalar_noe1_e1e2_e1e3_e1ni 
	void mv::set(const __syn_smv___scalar_noe1_e1e2_e1e3_e1ni & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = arg1.m_c[2] ;
		m_c[5] = (Float)0;
		m_c[6] = arg1.m_c[3] * (Float)-1.0;
		m_c[7] = arg1.m_c[4] ;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;
		m_c[10] = (Float)0;


	}
	// set to __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_e1e2e3_ni_noe1ni_e1e2ni_e1e3ni 
	void mv::set(const __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_e1e2e3_ni_noe1ni_e1e2ni_e1e3ni & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[4] ;
		m_c[4] = arg1.m_c[7] ;
		m_c[5] = (Float)0;
		m_c[6] = arg1.m_c[10] * (Float)-1.0;
		m_c[7] = arg1.m_c[9] ;
		m_c[8] = (Float)0;
		m_c[9] = arg1.m_c[8] ;
		m_c[10] = (Float)0;
		m_c[11] = (Float)0;
		m_c[12] = arg1.m_c[5] ;
		m_c[13] = arg1.m_c[3] ;
		m_c[14] = arg1.m_c[6] ;


	}
	// set to __syn_smv___scalar_noe2_e1e2_e2e3_e2ni 
	void mv::set(const __syn_smv___scalar_noe2_e1e2_e2e3_e2ni & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = (Float)0;
		m_c[4] = arg1.m_c[2] ;
		m_c[5] = arg1.m_c[3] ;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = arg1.m_c[4] ;
		m_c[9] = (Float)0;
		m_c[10] = (Float)0;


	}
	// set to __syn_smv___no_e1_e2_noe1e2_e3_noe2e3_e1e2e3_ni_noe2ni_e1e2ni_e2e3ni 
	void mv::set(const __syn_smv___no_e1_e2_noe1e2_e3_noe2e3_e1e2e3_ni_noe2ni_e1e2ni_e2e3ni & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[4] ;
		m_c[4] = arg1.m_c[7] ;
		m_c[5] = arg1.m_c[10] ;
		m_c[6] = (Float)0;
		m_c[7] = arg1.m_c[9] ;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;
		m_c[10] = arg1.m_c[8] ;
		m_c[11] = arg1.m_c[5] ;
		m_c[12] = (Float)0;
		m_c[13] = arg1.m_c[3] ;
		m_c[14] = arg1.m_c[6] ;


	}
	// set to __syn_smv___scalar_noe3_e1e3_e2e3_e3ni 
	void mv::set(const __syn_smv___scalar_noe3_e1e3_e2e3_e3ni & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[1] ;
		m_c[4] = (Float)0;
		m_c[5] = arg1.m_c[3] ;
		m_c[6] = arg1.m_c[2] * (Float)-1.0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = arg1.m_c[4] ;
		m_c[10] = (Float)0;


	}
	// set to __syn_smv___no_e1_e2_e3_noe1e3_noe2e3_e1e2e3_ni_noe3ni_e1e3ni_e2e3ni 
	void mv::set(const __syn_smv___no_e1_e2_e3_noe1e3_noe2e3_e1e2e3_ni_noe3ni_e1e3ni_e2e3ni & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[3] ;
		m_c[4] = arg1.m_c[7] ;
		m_c[5] = arg1.m_c[10] ;
		m_c[6] = arg1.m_c[9] * (Float)-1.0;
		m_c[7] = (Float)0;
		m_c[8] = arg1.m_c[8] ;
		m_c[9] = (Float)0;
		m_c[10] = (Float)0;
		m_c[11] = arg1.m_c[5] ;
		m_c[12] = arg1.m_c[4] ;
		m_c[13] = (Float)0;
		m_c[14] = arg1.m_c[6] ;


	}
	// set to __syn_smv___scalar_noni_e1ni_e2ni_e3ni 
	void mv::set(const __syn_smv___scalar_noni_e1ni_e2ni_e3ni & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = arg1.m_c[2] ;
		m_c[8] = arg1.m_c[3] ;
		m_c[9] = arg1.m_c[4] ;
		m_c[10] = arg1.m_c[1] ;


	}
	// set to __syn_smv___no_e1_e2_e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni 
	void mv::set(const __syn_smv___no_e1_e2_e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[3] ;
		m_c[4] = arg1.m_c[4] ;
		m_c[5] = arg1.m_c[10] ;
		m_c[6] = arg1.m_c[9] * (Float)-1.0;
		m_c[7] = arg1.m_c[7] ;
		m_c[8] = arg1.m_c[8] ;
		m_c[9] = arg1.m_c[5] ;
		m_c[10] = arg1.m_c[6] ;
		m_c[11] = (Float)0;
		m_c[12] = (Float)0;
		m_c[13] = (Float)0;
		m_c[14] = (Float)0;


	}
	// set to __syn_smv___e1ni_e2ni_e3ni_nonif_1_0 
	void mv::set(const __syn_smv___e1ni_e2ni_e3ni_nonif_1_0 & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = arg1.m_c[0] ;
		m_c[7] = arg1.m_c[1] ;
		m_c[8] = arg1.m_c[2] ;
		m_c[9] = (Float)-1.0f; 


	}
	// set to __syn_smv___scalarf_1_0 
	void mv::set(const __syn_smv___scalarf_1_0 & arg1) {

		// set grade usage 
		gu(1);


		m_c[0] = (Float)-1.0f; 


	}
	// set to __syn_smv___nif_1_0 
	void mv::set(const __syn_smv___nif_1_0 & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)-1.0f; 


	}
	// set to __syn_smv___nif1_0 
	void mv::set(const __syn_smv___nif1_0 & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)1.0f; 


	}
	// set to __syn_smv___noe1e2ni_noe1e3ni_noe2e3ni_e1e2e3ni_noe1e2e3f1_0 
	void mv::set(const __syn_smv___noe1e2ni_noe1e3ni_noe2e3ni_e1e2e3ni_noe1e2e3f1_0 & arg1) {

		// set grade usage 
		gu(16);


		m_c[0] = arg1.m_c[3] ;
		m_c[1] = arg1.m_c[2] ;
		m_c[2] = arg1.m_c[1] * (Float)-1.0;
		m_c[3] = arg1.m_c[0] ;
		m_c[4] = (Float)1.0f; 


	}
	// set to __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2ni_noe1e3ni_noe2e3ni 
	void mv::set(const __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2ni_noe1e3ni_noe2e3ni & arg1) {

		// set grade usage 
		gu(20);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[3] ;
		m_c[3] = arg1.m_c[2] ;
		m_c[4] = arg1.m_c[5] ;
		m_c[5] = arg1.m_c[4] * (Float)-1.0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;
		m_c[10] = (Float)0;
		m_c[11] = arg1.m_c[8] ;
		m_c[12] = arg1.m_c[7] * (Float)-1.0;
		m_c[13] = arg1.m_c[6] ;
		m_c[14] = (Float)0;


	}
	// set to __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_noe2e3_e1e2e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni_noe1e2e3ni 
	void mv::set(const __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_noe2e3_e1e2e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni_noe1e2e3ni & arg1) {

		// set grade usage 
		gu(42);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[4] ;
		m_c[4] = arg1.m_c[8] ;
		m_c[5] = arg1.m_c[14] ;
		m_c[6] = arg1.m_c[13] * (Float)-1.0;
		m_c[7] = arg1.m_c[11] ;
		m_c[8] = arg1.m_c[12] ;
		m_c[9] = arg1.m_c[9] ;
		m_c[10] = arg1.m_c[10] ;
		m_c[11] = arg1.m_c[6] ;
		m_c[12] = arg1.m_c[5] ;
		m_c[13] = arg1.m_c[3] ;
		m_c[14] = arg1.m_c[7] ;
		m_c[15] = arg1.m_c[15] ;


	}
	// set to __syn_smv___noni_e2ni_noe1e2ni_e3ni_noe1e3ni_e1e2e3ni 
	void mv::set(const __syn_smv___noni_e2ni_noe1e2ni_e3ni_noe1e3ni_e1e2e3ni & arg1) {

		// set grade usage 
		gu(20);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = arg1.m_c[1] ;
		m_c[8] = arg1.m_c[3] ;
		m_c[9] = arg1.m_c[0] ;
		m_c[10] = arg1.m_c[5] ;
		m_c[11] = (Float)0;
		m_c[12] = arg1.m_c[4] * (Float)-1.0;
		m_c[13] = arg1.m_c[2] ;
		m_c[14] = (Float)0;


	}
	// set to __syn_smv___e1_e2_e3_e1e2e3_ni_e1e2ni_e1e3ni_e2e3ni 
	void mv::set(const __syn_smv___e1_e2_e3_e1e2e3_ni_e1e2ni_e1e3ni_e2e3ni & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = (Float)0;
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = arg1.m_c[2] ;
		m_c[4] = arg1.m_c[4] ;
		m_c[5] = arg1.m_c[7] ;
		m_c[6] = arg1.m_c[6] * (Float)-1.0;
		m_c[7] = arg1.m_c[5] ;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;
		m_c[10] = (Float)0;
		m_c[11] = (Float)0;
		m_c[12] = (Float)0;
		m_c[13] = (Float)0;
		m_c[14] = arg1.m_c[3] ;


	}
	// set to __syn_smv___noni_e1ni_noe1e2ni_e3ni_noe2e3ni_e1e2e3ni 
	void mv::set(const __syn_smv___noni_e1ni_noe1e2ni_e3ni_noe2e3ni_e1e2e3ni & arg1) {

		// set grade usage 
		gu(20);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = arg1.m_c[1] ;
		m_c[7] = (Float)0;
		m_c[8] = arg1.m_c[3] ;
		m_c[9] = arg1.m_c[0] ;
		m_c[10] = arg1.m_c[5] ;
		m_c[11] = arg1.m_c[4] ;
		m_c[12] = (Float)0;
		m_c[13] = arg1.m_c[2] ;
		m_c[14] = (Float)0;


	}
	// set to __syn_smv___noni_e1ni_e2ni_noe1e3ni_noe2e3ni_e1e2e3ni 
	void mv::set(const __syn_smv___noni_e1ni_e2ni_noe1e3ni_noe2e3ni_e1e2e3ni & arg1) {

		// set grade usage 
		gu(20);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = arg1.m_c[1] ;
		m_c[7] = arg1.m_c[2] ;
		m_c[8] = (Float)0;
		m_c[9] = arg1.m_c[0] ;
		m_c[10] = arg1.m_c[5] ;
		m_c[11] = arg1.m_c[4] ;
		m_c[12] = arg1.m_c[3] * (Float)-1.0;
		m_c[13] = (Float)0;
		m_c[14] = (Float)0;


	}
	// set to __syn_smv___ni_e1e2ni_e1e3ni_e2e3ni 
	void mv::set(const __syn_smv___ni_e1e2ni_e1e3ni_e2e3ni & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = arg1.m_c[0] ;
		m_c[5] = arg1.m_c[3] ;
		m_c[6] = arg1.m_c[2] * (Float)-1.0;
		m_c[7] = arg1.m_c[1] ;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;
		m_c[10] = (Float)0;
		m_c[11] = (Float)0;
		m_c[12] = (Float)0;
		m_c[13] = (Float)0;
		m_c[14] = (Float)0;


	}
	// set to __syn_smv___scalarf0_0 
	void mv::set(const __syn_smv___scalarf0_0 & arg1) {

		// set grade usage 
		gu(1);


		m_c[0] = (Float)0.0f; 


	}
	// set to __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2e3_noe1e2ni_noe1e3ni_noe2e3ni 
	void mv::set(const __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2e3_noe1e2ni_noe1e3ni_noe2e3ni & arg1) {

		// set grade usage 
		gu(20);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[3] ;
		m_c[3] = arg1.m_c[2] ;
		m_c[4] = arg1.m_c[5] ;
		m_c[5] = arg1.m_c[4] * (Float)-1.0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;
		m_c[10] = (Float)0;
		m_c[11] = arg1.m_c[9] ;
		m_c[12] = arg1.m_c[8] * (Float)-1.0;
		m_c[13] = arg1.m_c[7] ;
		m_c[14] = arg1.m_c[6] ;


	}
	// set to __syn_smv___noe2_noe3_e2e3_noe1e2e3_noni_e2ni_noe1e2ni_e3ni_noe1e3ni_e1e2e3ni 
	void mv::set(const __syn_smv___noe2_noe3_e2e3_noe1e2e3_noni_e2ni_noe1e2ni_e3ni_noe1e3ni_e1e2e3ni & arg1) {

		// set grade usage 
		gu(20);


		m_c[0] = (Float)0;
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = (Float)0;
		m_c[4] = arg1.m_c[2] ;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = arg1.m_c[5] ;
		m_c[8] = arg1.m_c[7] ;
		m_c[9] = arg1.m_c[4] ;
		m_c[10] = arg1.m_c[9] ;
		m_c[11] = (Float)0;
		m_c[12] = arg1.m_c[8] * (Float)-1.0;
		m_c[13] = arg1.m_c[6] ;
		m_c[14] = arg1.m_c[3] ;


	}
	// set to __syn_smv___noe1_noe3_e1e3_noe1e2e3_noni_e1ni_noe1e2ni_e3ni_noe2e3ni_e1e2e3ni 
	void mv::set(const __syn_smv___noe1_noe3_e1e3_noe1e2e3_noni_e1ni_noe1e2ni_e3ni_noe2e3ni_e1e2e3ni & arg1) {

		// set grade usage 
		gu(20);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = arg1.m_c[2] * (Float)-1.0;
		m_c[6] = arg1.m_c[5] ;
		m_c[7] = (Float)0;
		m_c[8] = arg1.m_c[7] ;
		m_c[9] = arg1.m_c[4] ;
		m_c[10] = arg1.m_c[9] ;
		m_c[11] = arg1.m_c[8] ;
		m_c[12] = (Float)0;
		m_c[13] = arg1.m_c[6] ;
		m_c[14] = arg1.m_c[3] ;


	}
	// set to __syn_smv___noe1_noe2_e1e2_noe1e2e3_noni_e1ni_e2ni_noe1e3ni_noe2e3ni_e1e2e3ni 
	void mv::set(const __syn_smv___noe1_noe2_e1e2_noe1e2e3_noni_e1ni_e2ni_noe1e3ni_noe2e3ni_e1e2e3ni & arg1) {

		// set grade usage 
		gu(20);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[2] ;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = arg1.m_c[5] ;
		m_c[7] = arg1.m_c[6] ;
		m_c[8] = (Float)0;
		m_c[9] = arg1.m_c[4] ;
		m_c[10] = arg1.m_c[9] ;
		m_c[11] = arg1.m_c[8] ;
		m_c[12] = arg1.m_c[7] * (Float)-1.0;
		m_c[13] = (Float)0;
		m_c[14] = arg1.m_c[3] ;


	}
	// set to __syn_smv___e1e2_e1e3_e2e3_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni 
	void mv::set(const __syn_smv___e1e2_e1e3_e2e3_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni & arg1) {

		// set grade usage 
		gu(20);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[0] ;
		m_c[4] = arg1.m_c[2] ;
		m_c[5] = arg1.m_c[1] * (Float)-1.0;
		m_c[6] = arg1.m_c[3] ;
		m_c[7] = arg1.m_c[4] ;
		m_c[8] = arg1.m_c[6] ;
		m_c[9] = (Float)0;
		m_c[10] = arg1.m_c[9] ;
		m_c[11] = arg1.m_c[8] ;
		m_c[12] = arg1.m_c[7] * (Float)-1.0;
		m_c[13] = arg1.m_c[5] ;
		m_c[14] = (Float)0;


	}
	// set to __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni 
	void mv::set(const __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni & arg1) {

		// set grade usage 
		gu(20);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[3] ;
		m_c[3] = arg1.m_c[2] ;
		m_c[4] = arg1.m_c[5] ;
		m_c[5] = arg1.m_c[4] * (Float)-1.0;
		m_c[6] = arg1.m_c[7] ;
		m_c[7] = arg1.m_c[8] ;
		m_c[8] = arg1.m_c[10] ;
		m_c[9] = arg1.m_c[6] ;
		m_c[10] = arg1.m_c[13] ;
		m_c[11] = arg1.m_c[12] ;
		m_c[12] = arg1.m_c[11] * (Float)-1.0;
		m_c[13] = arg1.m_c[9] ;
		m_c[14] = (Float)0;


	}
	// set to __syn_smv___scalar_noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2e3_noni_noe1e2ni_noe1e3ni_noe2e3ni 
	void mv::set(const __syn_smv___scalar_noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2e3_noni_noe1e2ni_noe1e3ni_noe2e3ni & arg1) {

		// set grade usage 
		gu(21);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[4] ;
		m_c[4] = arg1.m_c[3] ;
		m_c[5] = arg1.m_c[6] ;
		m_c[6] = arg1.m_c[5] * (Float)-1.0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;
		m_c[10] = arg1.m_c[8] ;
		m_c[11] = (Float)0;
		m_c[12] = arg1.m_c[11] ;
		m_c[13] = arg1.m_c[10] * (Float)-1.0;
		m_c[14] = arg1.m_c[9] ;
		m_c[15] = arg1.m_c[7] ;


	}
	// set to __syn_smv___noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni 
	void mv::set(const __syn_smv___noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni & arg1) {

		// set grade usage 
		gu(20);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = arg1.m_c[1] ;
		m_c[7] = arg1.m_c[2] ;
		m_c[8] = arg1.m_c[4] ;
		m_c[9] = arg1.m_c[0] ;
		m_c[10] = arg1.m_c[7] ;
		m_c[11] = arg1.m_c[6] ;
		m_c[12] = arg1.m_c[5] * (Float)-1.0;
		m_c[13] = arg1.m_c[3] ;
		m_c[14] = (Float)0;


	}
	// set to __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni 
	void mv::set(const __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni & arg1) {

		// set grade usage 
		gu(20);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[3] ;
		m_c[3] = arg1.m_c[2] ;
		m_c[4] = arg1.m_c[5] ;
		m_c[5] = arg1.m_c[4] * (Float)-1.0;
		m_c[6] = arg1.m_c[8] ;
		m_c[7] = arg1.m_c[9] ;
		m_c[8] = arg1.m_c[11] ;
		m_c[9] = arg1.m_c[7] ;
		m_c[10] = arg1.m_c[14] ;
		m_c[11] = arg1.m_c[13] ;
		m_c[12] = arg1.m_c[12] * (Float)-1.0;
		m_c[13] = arg1.m_c[10] ;
		m_c[14] = arg1.m_c[6] ;


	}
	// set to __syn_smv___scalar_e1e2_e1e3_e2e3_e1ni_e2ni_e3ni 
	void mv::set(const __syn_smv___scalar_e1e2_e1e3_e2e3_e1ni_e2ni_e3ni & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = arg1.m_c[1] ;
		m_c[5] = arg1.m_c[3] ;
		m_c[6] = arg1.m_c[2] * (Float)-1.0;
		m_c[7] = arg1.m_c[4] ;
		m_c[8] = arg1.m_c[5] ;
		m_c[9] = arg1.m_c[6] ;
		m_c[10] = (Float)0;


	}
	// set to __syn_smv___nof_1_0 
	void mv::set(const __syn_smv___nof_1_0 & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)-1.0f; 
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;


	}
	// set to __syn_smv___e1_e2_e3_e1e2e3 
	void mv::set(const __syn_smv___e1_e2_e3_e1e2e3 & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = (Float)0;
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = arg1.m_c[2] ;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;
		m_c[10] = (Float)0;
		m_c[11] = (Float)0;
		m_c[12] = (Float)0;
		m_c[13] = (Float)0;
		m_c[14] = arg1.m_c[3] ;


	}
	// set to __syn_smv___e1ni_e2ni_e3ni_e1e2e3ni 
	void mv::set(const __syn_smv___e1ni_e2ni_e3ni_e1e2e3ni & arg1) {

		// set grade usage 
		gu(20);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = arg1.m_c[0] ;
		m_c[7] = arg1.m_c[1] ;
		m_c[8] = arg1.m_c[2] ;
		m_c[9] = (Float)0;
		m_c[10] = arg1.m_c[3] ;
		m_c[11] = (Float)0;
		m_c[12] = (Float)0;
		m_c[13] = (Float)0;
		m_c[14] = (Float)0;


	}
	// set to __syn_smv___e1e2_e1e3_e2e3_e1ni_e2ni_e3ni_e1e2e3ni 
	void mv::set(const __syn_smv___e1e2_e1e3_e2e3_e1ni_e2ni_e3ni_e1e2e3ni & arg1) {

		// set grade usage 
		gu(20);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[0] ;
		m_c[4] = arg1.m_c[2] ;
		m_c[5] = arg1.m_c[1] * (Float)-1.0;
		m_c[6] = arg1.m_c[3] ;
		m_c[7] = arg1.m_c[4] ;
		m_c[8] = arg1.m_c[5] ;
		m_c[9] = (Float)0;
		m_c[10] = arg1.m_c[6] ;
		m_c[11] = (Float)0;
		m_c[12] = (Float)0;
		m_c[13] = (Float)0;
		m_c[14] = (Float)0;


	}
	// set to __syn_smv___noe1e2_noe1e3_noe2e3_e1e2e3_noe1e2e3ni 
	void mv::set(const __syn_smv___noe1e2_noe1e3_noe2e3_e1e2e3_noe1e2e3ni & arg1) {

		// set grade usage 
		gu(40);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = arg1.m_c[2] ;
		m_c[7] = arg1.m_c[1] ;
		m_c[8] = arg1.m_c[0] ;
		m_c[9] = arg1.m_c[3] ;
		m_c[10] = arg1.m_c[4] ;


	}
	// set to __syn_smv___noe2e3_noe2ni_noe3ni_e2e3ni_noe1e2e3ni 
	void mv::set(const __syn_smv___noe2e3_noe2ni_noe3ni_e2e3ni_noe1e2e3ni & arg1) {

		// set grade usage 
		gu(40);


		m_c[0] = arg1.m_c[3] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[2] ;
		m_c[4] = (Float)0;
		m_c[5] = arg1.m_c[1] ;
		m_c[6] = arg1.m_c[0] ;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;
		m_c[10] = arg1.m_c[4] ;


	}
	// set to __syn_smv___noe1e3_noe1ni_noe3ni_e1e3ni_noe1e2e3ni 
	void mv::set(const __syn_smv___noe1e3_noe1ni_noe3ni_e1e3ni_noe1e2e3ni & arg1) {

		// set grade usage 
		gu(40);


		m_c[0] = (Float)0;
		m_c[1] = arg1.m_c[3] * (Float)-1.0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[2] ;
		m_c[4] = arg1.m_c[1] ;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = arg1.m_c[0] ;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;
		m_c[10] = arg1.m_c[4] ;


	}
	// set to __syn_smv___noe1e2_noe1ni_noe2ni_e1e2ni_noe1e2e3ni 
	void mv::set(const __syn_smv___noe1e2_noe1ni_noe2ni_e1e2ni_noe1e2e3ni & arg1) {

		// set grade usage 
		gu(40);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = arg1.m_c[3] ;
		m_c[3] = (Float)0;
		m_c[4] = arg1.m_c[1] ;
		m_c[5] = arg1.m_c[2] ;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = arg1.m_c[0] ;
		m_c[9] = (Float)0;
		m_c[10] = arg1.m_c[4] ;


	}
	// set to __syn_smv___e1e2e3_e1e2ni_e1e3ni_e2e3ni_noe1e2e3ni 
	void mv::set(const __syn_smv___e1e2e3_e1e2ni_e1e3ni_e2e3ni_noe1e2e3ni & arg1) {

		// set grade usage 
		gu(40);


		m_c[0] = arg1.m_c[3] ;
		m_c[1] = arg1.m_c[2] * (Float)-1.0;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = arg1.m_c[0] ;
		m_c[10] = arg1.m_c[4] ;


	}
	// set to __syn_smv___noe1e2e3ni 
	void mv::set(const __syn_smv___noe1e2e3ni & arg1) {

		// set grade usage 
		gu(32);


		m_c[0] = arg1.m_c[0] ;


	}
	// set to __syn_smv___e1e2e3_e1e2ni_e1e3ni_e2e3ni 
	void mv::set(const __syn_smv___e1e2e3_e1e2ni_e1e3ni_e2e3ni & arg1) {

		// set grade usage 
		gu(8);


		m_c[0] = arg1.m_c[3] ;
		m_c[1] = arg1.m_c[2] * (Float)-1.0;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = arg1.m_c[0] ;


	}
	// set to __syn_smv___e1e2e3 
	void mv::set(const __syn_smv___e1e2e3 & arg1) {

		// set grade usage 
		gu(8);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = arg1.m_c[0] ;


	}
	// set to __syn_smv___e1e3_e2e3 
	void mv::set(const __syn_smv___e1e3_e2e3 & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = arg1.m_c[1] ;
		m_c[5] = arg1.m_c[0] * (Float)-1.0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;


	}
	// set to __syn_smv___scalarf1_0 
	void mv::set(const __syn_smv___scalarf1_0 & arg1) {

		// set grade usage 
		gu(1);


		m_c[0] = (Float)1.0f; 


	}
	// set to __syn_smv___ni_nof1_0 
	void mv::set(const __syn_smv___ni_nof1_0 & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)1.0f; 
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = arg1.m_c[0] ;


	}
	// set to __syn_smv___e1_e2_e3_nof1_0 
	void mv::set(const __syn_smv___e1_e2_e3_nof1_0 & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)1.0f; 
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = arg1.m_c[2] ;
		m_c[4] = (Float)0;


	}
	// set to __syn_smv___e1_e2_e3_ni_nof2_0 
	void mv::set(const __syn_smv___e1_e2_e3_ni_nof2_0 & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)2.0f; 
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = arg1.m_c[2] ;
		m_c[4] = arg1.m_c[3] ;


	}
	// set to __syn_smv___e1_e2_e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni_nof1_0 
	void mv::set(const __syn_smv___e1_e2_e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni_nof1_0 & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = (Float)1.0f; 
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = arg1.m_c[2] ;
		m_c[4] = arg1.m_c[3] ;
		m_c[5] = arg1.m_c[9] ;
		m_c[6] = arg1.m_c[8] * (Float)-1.0;
		m_c[7] = arg1.m_c[6] ;
		m_c[8] = arg1.m_c[7] ;
		m_c[9] = arg1.m_c[4] ;
		m_c[10] = arg1.m_c[5] ;
		m_c[11] = (Float)0;
		m_c[12] = (Float)0;
		m_c[13] = (Float)0;
		m_c[14] = (Float)0;


	}
	// set to __syn_smv___scalar_e1e2 
	void mv::set(const __syn_smv___scalar_e1e2 & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = arg1.m_c[1] ;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;
		m_c[10] = (Float)0;


	}
	// set to __syn_smv___scalar_e1e3_e2e3 
	void mv::set(const __syn_smv___scalar_e1e3_e2e3 & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = arg1.m_c[2] ;
		m_c[6] = arg1.m_c[1] * (Float)-1.0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;
		m_c[10] = (Float)0;


	}
	// set to __syn_smv___e1e2f1_0 
	void mv::set(const __syn_smv___e1e2f1_0 & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)1.0f; 
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;


	}
	// set to __syn_smv___e1e2nif1_0 
	void mv::set(const __syn_smv___e1e2nif1_0 & arg1) {

		// set grade usage 
		gu(8);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)1.0f; 
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;


	}
	// set to __syn_smv___noe1e2f1_0 
	void mv::set(const __syn_smv___noe1e2f1_0 & arg1) {

		// set grade usage 
		gu(8);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)1.0f; 
		m_c[9] = (Float)0;


	}
	// set to __syn_smv___noe1e2f1_0_e1e2nif1_0 
	void mv::set(const __syn_smv___noe1e2f1_0_e1e2nif1_0 & arg1) {

		// set grade usage 
		gu(8);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)1.0f; 
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)1.0f; 
		m_c[9] = (Float)0;


	}
	// set to __syn_smv___e1e2_e1e3_e2e3_noe1e2e3_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni 
	void mv::set(const __syn_smv___e1e2_e1e3_e2e3_noe1e2e3_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni & arg1) {

		// set grade usage 
		gu(20);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[0] ;
		m_c[4] = arg1.m_c[2] ;
		m_c[5] = arg1.m_c[1] * (Float)-1.0;
		m_c[6] = arg1.m_c[4] ;
		m_c[7] = arg1.m_c[5] ;
		m_c[8] = arg1.m_c[7] ;
		m_c[9] = (Float)0;
		m_c[10] = (Float)0;
		m_c[11] = arg1.m_c[9] ;
		m_c[12] = arg1.m_c[8] * (Float)-1.0;
		m_c[13] = arg1.m_c[6] ;
		m_c[14] = arg1.m_c[3] ;


	}
	// set to __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2ni_noe1e3ni_noe2e3ni_e1e2e3ni 
	void mv::set(const __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2ni_noe1e3ni_noe2e3ni_e1e2e3ni & arg1) {

		// set grade usage 
		gu(20);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[3] ;
		m_c[3] = arg1.m_c[2] ;
		m_c[4] = arg1.m_c[5] ;
		m_c[5] = arg1.m_c[4] * (Float)-1.0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;
		m_c[10] = arg1.m_c[9] ;
		m_c[11] = arg1.m_c[8] ;
		m_c[12] = arg1.m_c[7] * (Float)-1.0;
		m_c[13] = arg1.m_c[6] ;
		m_c[14] = (Float)0;


	}
	// set to __syn_smv___nof1_0 
	void mv::set(const __syn_smv___nof1_0 & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)1.0f; 
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;


	}
	// set to __syn_smv___noe1 
	void mv::set(const __syn_smv___noe1 & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;


	}
	// set to __syn_smv___noe2 
	void mv::set(const __syn_smv___noe2 & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;


	}
	// set to __syn_smv___noe3 
	void mv::set(const __syn_smv___noe3 & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = arg1.m_c[0] ;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;


	}
	// set to __syn_smv___nonif_1_0 
	void mv::set(const __syn_smv___nonif_1_0 & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)-1.0f; 


	}
	// set to __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_noe2e3_e1e2e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni 
	void mv::set(const __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_noe2e3_e1e2e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[4] ;
		m_c[4] = arg1.m_c[8] ;
		m_c[5] = arg1.m_c[14] ;
		m_c[6] = arg1.m_c[13] * (Float)-1.0;
		m_c[7] = arg1.m_c[11] ;
		m_c[8] = arg1.m_c[12] ;
		m_c[9] = arg1.m_c[9] ;
		m_c[10] = arg1.m_c[10] ;
		m_c[11] = arg1.m_c[6] ;
		m_c[12] = arg1.m_c[5] ;
		m_c[13] = arg1.m_c[3] ;
		m_c[14] = arg1.m_c[7] ;


	}
	// set to __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_noe2e3_noe1ni_noe2ni_noe3ni 
	void mv::set(const __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_noe2e3_noe1ni_noe2ni_noe3ni & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[4] ;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = arg1.m_c[9] ;
		m_c[9] = arg1.m_c[7] ;
		m_c[10] = arg1.m_c[8] ;
		m_c[11] = arg1.m_c[6] ;
		m_c[12] = arg1.m_c[5] ;
		m_c[13] = arg1.m_c[3] ;
		m_c[14] = (Float)0;


	}
	// set to __syn_smv___no_e2_noe1e2_e3_noe1e3_e1e2e3_ni_noe1ni_e1e2ni_e1e3ni 
	void mv::set(const __syn_smv___no_e2_noe1e2_e3_noe1e3_e1e2e3_ni_noe1ni_e1e2ni_e1e3ni & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = arg1.m_c[3] ;
		m_c[4] = arg1.m_c[6] ;
		m_c[5] = (Float)0;
		m_c[6] = arg1.m_c[9] * (Float)-1.0;
		m_c[7] = arg1.m_c[8] ;
		m_c[8] = (Float)0;
		m_c[9] = arg1.m_c[7] ;
		m_c[10] = (Float)0;
		m_c[11] = (Float)0;
		m_c[12] = arg1.m_c[4] ;
		m_c[13] = arg1.m_c[2] ;
		m_c[14] = arg1.m_c[5] ;


	}
	// set to __syn_smv___no_e1_noe1e2_e3_noe2e3_e1e2e3_ni_noe2ni_e1e2ni_e2e3ni 
	void mv::set(const __syn_smv___no_e1_noe1e2_e3_noe2e3_e1e2e3_ni_noe2ni_e1e2ni_e2e3ni & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[3] ;
		m_c[4] = arg1.m_c[6] ;
		m_c[5] = arg1.m_c[9] ;
		m_c[6] = (Float)0;
		m_c[7] = arg1.m_c[8] ;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;
		m_c[10] = arg1.m_c[7] ;
		m_c[11] = arg1.m_c[4] ;
		m_c[12] = (Float)0;
		m_c[13] = arg1.m_c[2] ;
		m_c[14] = arg1.m_c[5] ;


	}
	// set to __syn_smv___no_e1_e2_noe1e3_noe2e3_e1e2e3_ni_noe3ni_e1e3ni_e2e3ni 
	void mv::set(const __syn_smv___no_e1_e2_noe1e3_noe2e3_e1e2e3_ni_noe3ni_e1e3ni_e2e3ni & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = (Float)0;
		m_c[4] = arg1.m_c[6] ;
		m_c[5] = arg1.m_c[9] ;
		m_c[6] = arg1.m_c[8] * (Float)-1.0;
		m_c[7] = (Float)0;
		m_c[8] = arg1.m_c[7] ;
		m_c[9] = (Float)0;
		m_c[10] = (Float)0;
		m_c[11] = arg1.m_c[4] ;
		m_c[12] = arg1.m_c[3] ;
		m_c[13] = (Float)0;
		m_c[14] = arg1.m_c[5] ;


	}
	// set to __syn_smv___e1_e2_e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni 
	void mv::set(const __syn_smv___e1_e2_e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = (Float)0;
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = arg1.m_c[2] ;
		m_c[4] = arg1.m_c[3] ;
		m_c[5] = arg1.m_c[9] ;
		m_c[6] = arg1.m_c[8] * (Float)-1.0;
		m_c[7] = arg1.m_c[6] ;
		m_c[8] = arg1.m_c[7] ;
		m_c[9] = arg1.m_c[4] ;
		m_c[10] = arg1.m_c[5] ;
		m_c[11] = (Float)0;
		m_c[12] = (Float)0;
		m_c[13] = (Float)0;
		m_c[14] = (Float)0;


	}
	// set to __syn_smv___e1_e2_noe1e2_e3_noe1e3_noe2e3_ni_noe1ni_noe2ni_noe3ni 
	void mv::set(const __syn_smv___e1_e2_noe1e2_e3_noe1e3_noe2e3_ni_noe1ni_noe2ni_noe3ni & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = (Float)0;
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = arg1.m_c[3] ;
		m_c[4] = arg1.m_c[6] ;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = arg1.m_c[9] ;
		m_c[9] = arg1.m_c[7] ;
		m_c[10] = arg1.m_c[8] ;
		m_c[11] = arg1.m_c[5] ;
		m_c[12] = arg1.m_c[4] ;
		m_c[13] = arg1.m_c[2] ;
		m_c[14] = (Float)0;


	}
	// set to __syn_smv___no_e1_e2_e3_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni 
	void mv::set(const __syn_smv___no_e1_e2_e3_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[3] ;
		m_c[4] = (Float)0;
		m_c[5] = arg1.m_c[9] ;
		m_c[6] = arg1.m_c[8] * (Float)-1.0;
		m_c[7] = arg1.m_c[6] ;
		m_c[8] = arg1.m_c[7] ;
		m_c[9] = arg1.m_c[4] ;
		m_c[10] = arg1.m_c[5] ;
		m_c[11] = (Float)0;
		m_c[12] = (Float)0;
		m_c[13] = (Float)0;
		m_c[14] = (Float)0;


	}
	// set to __syn_smv___scalar_noe1_noe2_noe3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni 
	void mv::set(const __syn_smv___scalar_noe1_noe2_noe3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni & arg1) {

		// set grade usage 
		gu(21);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[3] ;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = arg1.m_c[5] ;
		m_c[8] = arg1.m_c[6] ;
		m_c[9] = arg1.m_c[8] ;
		m_c[10] = arg1.m_c[4] ;
		m_c[11] = (Float)0;
		m_c[12] = arg1.m_c[10] ;
		m_c[13] = arg1.m_c[9] * (Float)-1.0;
		m_c[14] = arg1.m_c[7] ;
		m_c[15] = (Float)0;


	}
	// set to __syn_smv___scalar_noe1_e1e2_e1e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_e1e2e3ni 
	void mv::set(const __syn_smv___scalar_noe1_e1e2_e1e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_e1e2e3ni & arg1) {

		// set grade usage 
		gu(21);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = arg1.m_c[2] ;
		m_c[5] = (Float)0;
		m_c[6] = arg1.m_c[3] * (Float)-1.0;
		m_c[7] = arg1.m_c[5] ;
		m_c[8] = arg1.m_c[6] ;
		m_c[9] = arg1.m_c[8] ;
		m_c[10] = arg1.m_c[4] ;
		m_c[11] = arg1.m_c[10] ;
		m_c[12] = (Float)0;
		m_c[13] = arg1.m_c[9] * (Float)-1.0;
		m_c[14] = arg1.m_c[7] ;
		m_c[15] = (Float)0;


	}
	// set to __syn_smv___scalar_noe2_e1e2_e2e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe2e3ni_e1e2e3ni 
	void mv::set(const __syn_smv___scalar_noe2_e1e2_e2e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe2e3ni_e1e2e3ni & arg1) {

		// set grade usage 
		gu(21);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = (Float)0;
		m_c[4] = arg1.m_c[2] ;
		m_c[5] = arg1.m_c[3] ;
		m_c[6] = (Float)0;
		m_c[7] = arg1.m_c[5] ;
		m_c[8] = arg1.m_c[6] ;
		m_c[9] = arg1.m_c[8] ;
		m_c[10] = arg1.m_c[4] ;
		m_c[11] = arg1.m_c[10] ;
		m_c[12] = arg1.m_c[9] ;
		m_c[13] = (Float)0;
		m_c[14] = arg1.m_c[7] ;
		m_c[15] = (Float)0;


	}
	// set to __syn_smv___scalar_noe3_e1e3_e2e3_noni_e1ni_e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni 
	void mv::set(const __syn_smv___scalar_noe3_e1e3_e2e3_noni_e1ni_e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni & arg1) {

		// set grade usage 
		gu(21);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[1] ;
		m_c[4] = (Float)0;
		m_c[5] = arg1.m_c[3] ;
		m_c[6] = arg1.m_c[2] * (Float)-1.0;
		m_c[7] = arg1.m_c[5] ;
		m_c[8] = arg1.m_c[6] ;
		m_c[9] = arg1.m_c[7] ;
		m_c[10] = arg1.m_c[4] ;
		m_c[11] = arg1.m_c[10] ;
		m_c[12] = arg1.m_c[9] ;
		m_c[13] = arg1.m_c[8] * (Float)-1.0;
		m_c[14] = (Float)0;
		m_c[15] = (Float)0;


	}
	// set to __syn_smv___scalar_noe1_noe2_e1e2_noe3_e1e3_e2e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni 
	void mv::set(const __syn_smv___scalar_noe1_noe2_e1e2_noe3_e1e3_e2e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni & arg1) {

		// set grade usage 
		gu(21);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[4] ;
		m_c[4] = arg1.m_c[3] ;
		m_c[5] = arg1.m_c[6] ;
		m_c[6] = arg1.m_c[5] * (Float)-1.0;
		m_c[7] = arg1.m_c[8] ;
		m_c[8] = arg1.m_c[9] ;
		m_c[9] = arg1.m_c[11] ;
		m_c[10] = arg1.m_c[7] ;
		m_c[11] = arg1.m_c[14] ;
		m_c[12] = arg1.m_c[13] ;
		m_c[13] = arg1.m_c[12] * (Float)-1.0;
		m_c[14] = arg1.m_c[10] ;
		m_c[15] = (Float)0;


	}
	// set to __syn_smv___e1e2_e1e3_e2e3_noe1e2e3_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni 
	void mv::set(const __syn_smv___e1e2_e1e3_e2e3_noe1e2e3_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni & arg1) {

		// set grade usage 
		gu(20);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[0] ;
		m_c[4] = arg1.m_c[2] ;
		m_c[5] = arg1.m_c[1] * (Float)-1.0;
		m_c[6] = arg1.m_c[4] ;
		m_c[7] = arg1.m_c[5] ;
		m_c[8] = arg1.m_c[7] ;
		m_c[9] = (Float)0;
		m_c[10] = arg1.m_c[10] ;
		m_c[11] = arg1.m_c[9] ;
		m_c[12] = arg1.m_c[8] * (Float)-1.0;
		m_c[13] = arg1.m_c[6] ;
		m_c[14] = arg1.m_c[3] ;


	}
	// set to __syn_smv___e1e2 
	void mv::set(const __syn_smv___e1e2 & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[0] ;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;


	}
	// set to __syn_smv___noe2ni_noe3ni_e2e3ni_noe1e2e3ni 
	void mv::set(const __syn_smv___noe2ni_noe3ni_e2e3ni_noe1e2e3ni & arg1) {

		// set grade usage 
		gu(40);


		m_c[0] = arg1.m_c[2] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[1] ;
		m_c[4] = (Float)0;
		m_c[5] = arg1.m_c[0] ;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;
		m_c[10] = arg1.m_c[3] ;


	}
	// set to __syn_smv___e1_e2_e3_e1e2e3_ni_e1e2ni_e1e3ni 
	void mv::set(const __syn_smv___e1_e2_e3_e1e2e3_ni_e1e2ni_e1e3ni & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = (Float)0;
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = arg1.m_c[2] ;
		m_c[4] = arg1.m_c[4] ;
		m_c[5] = (Float)0;
		m_c[6] = arg1.m_c[6] * (Float)-1.0;
		m_c[7] = arg1.m_c[5] ;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;
		m_c[10] = (Float)0;
		m_c[11] = (Float)0;
		m_c[12] = (Float)0;
		m_c[13] = (Float)0;
		m_c[14] = arg1.m_c[3] ;


	}
	// set to __syn_smv___noe1ni_noe3ni_e1e3ni_noe1e2e3ni 
	void mv::set(const __syn_smv___noe1ni_noe3ni_e1e3ni_noe1e2e3ni & arg1) {

		// set grade usage 
		gu(40);


		m_c[0] = (Float)0;
		m_c[1] = arg1.m_c[2] * (Float)-1.0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[1] ;
		m_c[4] = arg1.m_c[0] ;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;
		m_c[10] = arg1.m_c[3] ;


	}
	// set to __syn_smv___e1_e2_e3_e1e2e3_ni_e1e2ni_e2e3ni 
	void mv::set(const __syn_smv___e1_e2_e3_e1e2e3_ni_e1e2ni_e2e3ni & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = (Float)0;
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = arg1.m_c[2] ;
		m_c[4] = arg1.m_c[4] ;
		m_c[5] = arg1.m_c[6] ;
		m_c[6] = (Float)0;
		m_c[7] = arg1.m_c[5] ;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;
		m_c[10] = (Float)0;
		m_c[11] = (Float)0;
		m_c[12] = (Float)0;
		m_c[13] = (Float)0;
		m_c[14] = arg1.m_c[3] ;


	}
	// set to __syn_smv___noe1ni_noe2ni_e1e2ni_noe1e2e3ni 
	void mv::set(const __syn_smv___noe1ni_noe2ni_e1e2ni_noe1e2e3ni & arg1) {

		// set grade usage 
		gu(40);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = (Float)0;
		m_c[4] = arg1.m_c[0] ;
		m_c[5] = arg1.m_c[1] ;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;
		m_c[10] = arg1.m_c[3] ;


	}
	// set to __syn_smv___e1_e2_e3_e1e2e3_ni_e1e3ni_e2e3ni 
	void mv::set(const __syn_smv___e1_e2_e3_e1e2e3_ni_e1e3ni_e2e3ni & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = (Float)0;
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = arg1.m_c[2] ;
		m_c[4] = arg1.m_c[4] ;
		m_c[5] = arg1.m_c[6] ;
		m_c[6] = arg1.m_c[5] * (Float)-1.0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;
		m_c[10] = (Float)0;
		m_c[11] = (Float)0;
		m_c[12] = (Float)0;
		m_c[13] = (Float)0;
		m_c[14] = arg1.m_c[3] ;


	}
	// set to __syn_smv___scalar_e1ni_e2ni_e3ni_e1e2e3ni 
	void mv::set(const __syn_smv___scalar_e1ni_e2ni_e3ni_e1e2e3ni & arg1) {

		// set grade usage 
		gu(21);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = arg1.m_c[1] ;
		m_c[8] = arg1.m_c[2] ;
		m_c[9] = arg1.m_c[3] ;
		m_c[10] = (Float)0;
		m_c[11] = arg1.m_c[4] ;
		m_c[12] = (Float)0;
		m_c[13] = (Float)0;
		m_c[14] = (Float)0;
		m_c[15] = (Float)0;


	}
	// set to __syn_smv___e1e2_e1e3_e2e3_noni 
	void mv::set(const __syn_smv___e1e2_e1e3_e2e3_noni & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[0] ;
		m_c[4] = arg1.m_c[2] ;
		m_c[5] = arg1.m_c[1] * (Float)-1.0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = arg1.m_c[3] ;


	}
	// set to __syn_smv___e1e2_e1e3_e2e3_noni_e1ni_e2ni_e3ni_e1e2e3ni 
	void mv::set(const __syn_smv___e1e2_e1e3_e2e3_noni_e1ni_e2ni_e3ni_e1e2e3ni & arg1) {

		// set grade usage 
		gu(20);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[0] ;
		m_c[4] = arg1.m_c[2] ;
		m_c[5] = arg1.m_c[1] * (Float)-1.0;
		m_c[6] = arg1.m_c[4] ;
		m_c[7] = arg1.m_c[5] ;
		m_c[8] = arg1.m_c[6] ;
		m_c[9] = arg1.m_c[3] ;
		m_c[10] = arg1.m_c[7] ;
		m_c[11] = (Float)0;
		m_c[12] = (Float)0;
		m_c[13] = (Float)0;
		m_c[14] = (Float)0;


	}
	// set to __syn_smv___scalar_e1e2_e1e3_e2e3_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni 
	void mv::set(const __syn_smv___scalar_e1e2_e1e3_e2e3_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni & arg1) {

		// set grade usage 
		gu(21);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = arg1.m_c[1] ;
		m_c[5] = arg1.m_c[3] ;
		m_c[6] = arg1.m_c[2] * (Float)-1.0;
		m_c[7] = arg1.m_c[4] ;
		m_c[8] = arg1.m_c[5] ;
		m_c[9] = arg1.m_c[7] ;
		m_c[10] = (Float)0;
		m_c[11] = arg1.m_c[10] ;
		m_c[12] = arg1.m_c[9] ;
		m_c[13] = arg1.m_c[8] * (Float)-1.0;
		m_c[14] = arg1.m_c[6] ;
		m_c[15] = (Float)0;


	}
	// set to __syn_smv___scalar_e1e2_e1e3_e2e3_noni_e1ni_e2ni_e3ni 
	void mv::set(const __syn_smv___scalar_e1e2_e1e3_e2e3_noni_e1ni_e2ni_e3ni & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = arg1.m_c[1] ;
		m_c[5] = arg1.m_c[3] ;
		m_c[6] = arg1.m_c[2] * (Float)-1.0;
		m_c[7] = arg1.m_c[5] ;
		m_c[8] = arg1.m_c[6] ;
		m_c[9] = arg1.m_c[7] ;
		m_c[10] = arg1.m_c[4] ;


	}
	// set to __syn_smv___nof1_0_e2f1_0 
	void mv::set(const __syn_smv___nof1_0_e2f1_0 & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)1.0f; 
		m_c[1] = (Float)0;
		m_c[2] = (Float)1.0f; 
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;


	}
	// set to __syn_smv___nonif1_0_e2nif1_0 
	void mv::set(const __syn_smv___nonif1_0_e2nif1_0 & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)1.0f; 
		m_c[8] = (Float)0;
		m_c[9] = (Float)1.0f; 


	}
	// set to __syn_smv___noe1f1_0_e1e2f_1_0 
	void mv::set(const __syn_smv___noe1f1_0_e1e2f_1_0 & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)1.0f; 
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)-1.0f; 
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;


	}
	// set to __syn_smv___noe2e3f1_0_noe3nif_1_0 
	void mv::set(const __syn_smv___noe2e3f1_0_noe3nif_1_0 & arg1) {

		// set grade usage 
		gu(8);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)-1.0f; 
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)1.0f; 
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;


	}
	// set to __syn_smv___e3ni 
	void mv::set(const __syn_smv___e3ni & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = arg1.m_c[0] ;
		m_c[9] = (Float)0;


	}
	// set to __syn_smv___e1_e2_noe1e2_e3_noe1e3_noe2e3_e1e2e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni_noe1e2e3ni 
	void mv::set(const __syn_smv___e1_e2_noe1e2_e3_noe1e3_noe2e3_e1e2e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni_noe1e2e3ni & arg1) {

		// set grade usage 
		gu(42);


		m_c[0] = (Float)0;
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = arg1.m_c[3] ;
		m_c[4] = arg1.m_c[7] ;
		m_c[5] = arg1.m_c[13] ;
		m_c[6] = arg1.m_c[12] * (Float)-1.0;
		m_c[7] = arg1.m_c[10] ;
		m_c[8] = arg1.m_c[11] ;
		m_c[9] = arg1.m_c[8] ;
		m_c[10] = arg1.m_c[9] ;
		m_c[11] = arg1.m_c[5] ;
		m_c[12] = arg1.m_c[4] ;
		m_c[13] = arg1.m_c[2] ;
		m_c[14] = arg1.m_c[6] ;
		m_c[15] = arg1.m_c[14] ;


	}
	// set to __syn_smv___e1e2e3ni_noe1e2e3f1_0 
	void mv::set(const __syn_smv___e1e2e3ni_noe1e2e3f1_0 & arg1) {

		// set grade usage 
		gu(16);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)1.0f; 


	}
	// set to __syn_smv___e2ni 
	void mv::set(const __syn_smv___e2ni & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = arg1.m_c[0] ;
		m_c[8] = (Float)0;
		m_c[9] = (Float)0;


	}
	// set to __syn_smv___e2ni_e3ni 
	void mv::set(const __syn_smv___e2ni_e3ni & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = arg1.m_c[0] ;
		m_c[8] = arg1.m_c[1] ;
		m_c[9] = (Float)0;


	}
	// set to __syn_smv___scalar_e3ni 
	void mv::set(const __syn_smv___scalar_e3ni & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;
		m_c[8] = (Float)0;
		m_c[9] = arg1.m_c[1] ;
		m_c[10] = (Float)0;


	}






	// assign copy
	mv& mv::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}


	// assign scalar
	mv& mv::operator=(Float s) {
		set(s);
		return *this;
	}

	// assign no_t 
	mv& mv::operator=(const no_t& arg1) {
		set(arg1);
		return *this;
	}
	// assign e1_t 
	mv& mv::operator=(const e1_t& arg1) {
		set(arg1);
		return *this;
	}
	// assign e2_t 
	mv& mv::operator=(const e2_t& arg1) {
		set(arg1);
		return *this;
	}
	// assign e3_t 
	mv& mv::operator=(const e3_t& arg1) {
		set(arg1);
		return *this;
	}
	// assign ni_t 
	mv& mv::operator=(const ni_t& arg1) {
		set(arg1);
		return *this;
	}
	// assign scalar 
	mv& mv::operator=(const scalar& arg1) {
		set(arg1);
		return *this;
	}
	// assign noni_t 
	mv& mv::operator=(const noni_t& arg1) {
		set(arg1);
		return *this;
	}
	// assign point 
	mv& mv::operator=(const point& arg1) {
		set(arg1);
		return *this;
	}
	// assign normalizedPoint 
	mv& mv::operator=(const normalizedPoint& arg1) {
		set(arg1);
		return *this;
	}
	// assign flatPoint 
	mv& mv::operator=(const flatPoint& arg1) {
		set(arg1);
		return *this;
	}
	// assign normalizedFlatPoint 
	mv& mv::operator=(const normalizedFlatPoint& arg1) {
		set(arg1);
		return *this;
	}
	// assign pointPair 
	mv& mv::operator=(const pointPair& arg1) {
		set(arg1);
		return *this;
	}
	// assign line 
	mv& mv::operator=(const line& arg1) {
		set(arg1);
		return *this;
	}
	// assign dualLine 
	mv& mv::operator=(const dualLine& arg1) {
		set(arg1);
		return *this;
	}
	// assign plane 
	mv& mv::operator=(const plane& arg1) {
		set(arg1);
		return *this;
	}
	// assign dualPlane 
	mv& mv::operator=(const dualPlane& arg1) {
		set(arg1);
		return *this;
	}
	// assign circle 
	mv& mv::operator=(const circle& arg1) {
		set(arg1);
		return *this;
	}
	// assign sphere 
	mv& mv::operator=(const sphere& arg1) {
		set(arg1);
		return *this;
	}
	// assign dualSphere 
	mv& mv::operator=(const dualSphere& arg1) {
		set(arg1);
		return *this;
	}
	// assign normalizedSphere 
	mv& mv::operator=(const normalizedSphere& arg1) {
		set(arg1);
		return *this;
	}
	// assign normalizedDualSphere 
	mv& mv::operator=(const normalizedDualSphere& arg1) {
		set(arg1);
		return *this;
	}
	// assign freeVector 
	mv& mv::operator=(const freeVector& arg1) {
		set(arg1);
		return *this;
	}
	// assign freeBivector 
	mv& mv::operator=(const freeBivector& arg1) {
		set(arg1);
		return *this;
	}
	// assign freeTrivector 
	mv& mv::operator=(const freeTrivector& arg1) {
		set(arg1);
		return *this;
	}
	// assign tangentVector 
	mv& mv::operator=(const tangentVector& arg1) {
		set(arg1);
		return *this;
	}
	// assign tangentBivector 
	mv& mv::operator=(const tangentBivector& arg1) {
		set(arg1);
		return *this;
	}
	// assign vectorE2GA 
	mv& mv::operator=(const vectorE2GA& arg1) {
		set(arg1);
		return *this;
	}
	// assign vectorE3GA 
	mv& mv::operator=(const vectorE3GA& arg1) {
		set(arg1);
		return *this;
	}
	// assign bivectorE3GA 
	mv& mv::operator=(const bivectorE3GA& arg1) {
		set(arg1);
		return *this;
	}
	// assign TRversorLog 
	mv& mv::operator=(const TRversorLog& arg1) {
		set(arg1);
		return *this;
	}
	// assign TRSversorLog 
	mv& mv::operator=(const TRSversorLog& arg1) {
		set(arg1);
		return *this;
	}
	// assign TRversor 
	mv& mv::operator=(const TRversor& arg1) {
		set(arg1);
		return *this;
	}
	// assign TRSversor 
	mv& mv::operator=(const TRSversor& arg1) {
		set(arg1);
		return *this;
	}
	// assign evenVersor 
	mv& mv::operator=(const evenVersor& arg1) {
		set(arg1);
		return *this;
	}
	// assign translator 
	mv& mv::operator=(const translator& arg1) {
		set(arg1);
		return *this;
	}
	// assign normalizedTranslator 
	mv& mv::operator=(const normalizedTranslator& arg1) {
		set(arg1);
		return *this;
	}
	// assign rotor 
	mv& mv::operator=(const rotor& arg1) {
		set(arg1);
		return *this;
	}
	// assign scalor 
	mv& mv::operator=(const scalor& arg1) {
		set(arg1);
		return *this;
	}
	// assign __no_ct__ 
	mv& mv::operator=(const __no_ct__& arg1) {
		set(arg1);
		return *this;
	}
	// assign __e1_ct__ 
	mv& mv::operator=(const __e1_ct__& arg1) {
		set(arg1);
		return *this;
	}
	// assign __e2_ct__ 
	mv& mv::operator=(const __e2_ct__& arg1) {
		set(arg1);
		return *this;
	}
	// assign __e3_ct__ 
	mv& mv::operator=(const __e3_ct__& arg1) {
		set(arg1);
		return *this;
	}
	// assign __ni_ct__ 
	mv& mv::operator=(const __ni_ct__& arg1) {
		set(arg1);
		return *this;
	}
	// assign __noni_ct__ 
	mv& mv::operator=(const __noni_ct__& arg1) {
		set(arg1);
		return *this;
	}
	// assign __e3ni_ct__ 
	mv& mv::operator=(const __e3ni_ct__& arg1) {
		set(arg1);
		return *this;
	}
	// assign __e2ni_ct__ 
	mv& mv::operator=(const __e2ni_ct__& arg1) {
		set(arg1);
		return *this;
	}
	// assign __I3_ct__ 
	mv& mv::operator=(const __I3_ct__& arg1) {
		set(arg1);
		return *this;
	}
	// assign __e1ni_ct__ 
	mv& mv::operator=(const __e1ni_ct__& arg1) {
		set(arg1);
		return *this;
	}
	// assign __I5_ct__ 
	mv& mv::operator=(const __I5_ct__& arg1) {
		set(arg1);
		return *this;
	}
	// assign __I5i_ct__ 
	mv& mv::operator=(const __I5i_ct__& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1_e2_e3_ni_nof_1_0 
	mv& mv::operator=(const __syn_smv___e1_e2_e3_ni_nof_1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_noe1_noe2_e1e2_noe3_e1e3_e2e3_noni_e1ni_e2ni_e3ni 
	mv& mv::operator=(const __syn_smv___scalar_noe1_noe2_e1e2_noe3_e1e3_e2e3_noni_e1ni_e2ni_e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_noe1_noe2_noe3_noni 
	mv& mv::operator=(const __syn_smv___scalar_noe1_noe2_noe3_noni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_noe2e3_ni_noe1ni_noe2ni_noe3ni 
	mv& mv::operator=(const __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_noe2e3_ni_noe1ni_noe2ni_noe3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_noe1_e1e2_e1e3_e1ni 
	mv& mv::operator=(const __syn_smv___scalar_noe1_e1e2_e1e3_e1ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_e1e2e3_ni_noe1ni_e1e2ni_e1e3ni 
	mv& mv::operator=(const __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_e1e2e3_ni_noe1ni_e1e2ni_e1e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_noe2_e1e2_e2e3_e2ni 
	mv& mv::operator=(const __syn_smv___scalar_noe2_e1e2_e2e3_e2ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___no_e1_e2_noe1e2_e3_noe2e3_e1e2e3_ni_noe2ni_e1e2ni_e2e3ni 
	mv& mv::operator=(const __syn_smv___no_e1_e2_noe1e2_e3_noe2e3_e1e2e3_ni_noe2ni_e1e2ni_e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_noe3_e1e3_e2e3_e3ni 
	mv& mv::operator=(const __syn_smv___scalar_noe3_e1e3_e2e3_e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___no_e1_e2_e3_noe1e3_noe2e3_e1e2e3_ni_noe3ni_e1e3ni_e2e3ni 
	mv& mv::operator=(const __syn_smv___no_e1_e2_e3_noe1e3_noe2e3_e1e2e3_ni_noe3ni_e1e3ni_e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_noni_e1ni_e2ni_e3ni 
	mv& mv::operator=(const __syn_smv___scalar_noni_e1ni_e2ni_e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___no_e1_e2_e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni 
	mv& mv::operator=(const __syn_smv___no_e1_e2_e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1ni_e2ni_e3ni_nonif_1_0 
	mv& mv::operator=(const __syn_smv___e1ni_e2ni_e3ni_nonif_1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalarf_1_0 
	mv& mv::operator=(const __syn_smv___scalarf_1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___nif_1_0 
	mv& mv::operator=(const __syn_smv___nif_1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___nif1_0 
	mv& mv::operator=(const __syn_smv___nif1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___noe1e2ni_noe1e3ni_noe2e3ni_e1e2e3ni_noe1e2e3f1_0 
	mv& mv::operator=(const __syn_smv___noe1e2ni_noe1e3ni_noe2e3ni_e1e2e3ni_noe1e2e3f1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2ni_noe1e3ni_noe2e3ni 
	mv& mv::operator=(const __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2ni_noe1e3ni_noe2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_noe2e3_e1e2e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni_noe1e2e3ni 
	mv& mv::operator=(const __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_noe2e3_e1e2e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni_noe1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___noni_e2ni_noe1e2ni_e3ni_noe1e3ni_e1e2e3ni 
	mv& mv::operator=(const __syn_smv___noni_e2ni_noe1e2ni_e3ni_noe1e3ni_e1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1_e2_e3_e1e2e3_ni_e1e2ni_e1e3ni_e2e3ni 
	mv& mv::operator=(const __syn_smv___e1_e2_e3_e1e2e3_ni_e1e2ni_e1e3ni_e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___noni_e1ni_noe1e2ni_e3ni_noe2e3ni_e1e2e3ni 
	mv& mv::operator=(const __syn_smv___noni_e1ni_noe1e2ni_e3ni_noe2e3ni_e1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___noni_e1ni_e2ni_noe1e3ni_noe2e3ni_e1e2e3ni 
	mv& mv::operator=(const __syn_smv___noni_e1ni_e2ni_noe1e3ni_noe2e3ni_e1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___ni_e1e2ni_e1e3ni_e2e3ni 
	mv& mv::operator=(const __syn_smv___ni_e1e2ni_e1e3ni_e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalarf0_0 
	mv& mv::operator=(const __syn_smv___scalarf0_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2e3_noe1e2ni_noe1e3ni_noe2e3ni 
	mv& mv::operator=(const __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2e3_noe1e2ni_noe1e3ni_noe2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___noe2_noe3_e2e3_noe1e2e3_noni_e2ni_noe1e2ni_e3ni_noe1e3ni_e1e2e3ni 
	mv& mv::operator=(const __syn_smv___noe2_noe3_e2e3_noe1e2e3_noni_e2ni_noe1e2ni_e3ni_noe1e3ni_e1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___noe1_noe3_e1e3_noe1e2e3_noni_e1ni_noe1e2ni_e3ni_noe2e3ni_e1e2e3ni 
	mv& mv::operator=(const __syn_smv___noe1_noe3_e1e3_noe1e2e3_noni_e1ni_noe1e2ni_e3ni_noe2e3ni_e1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___noe1_noe2_e1e2_noe1e2e3_noni_e1ni_e2ni_noe1e3ni_noe2e3ni_e1e2e3ni 
	mv& mv::operator=(const __syn_smv___noe1_noe2_e1e2_noe1e2e3_noni_e1ni_e2ni_noe1e3ni_noe2e3ni_e1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1e2_e1e3_e2e3_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni 
	mv& mv::operator=(const __syn_smv___e1e2_e1e3_e2e3_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni 
	mv& mv::operator=(const __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2e3_noni_noe1e2ni_noe1e3ni_noe2e3ni 
	mv& mv::operator=(const __syn_smv___scalar_noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2e3_noni_noe1e2ni_noe1e3ni_noe2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni 
	mv& mv::operator=(const __syn_smv___noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni 
	mv& mv::operator=(const __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_e1e2_e1e3_e2e3_e1ni_e2ni_e3ni 
	mv& mv::operator=(const __syn_smv___scalar_e1e2_e1e3_e2e3_e1ni_e2ni_e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___nof_1_0 
	mv& mv::operator=(const __syn_smv___nof_1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1_e2_e3_e1e2e3 
	mv& mv::operator=(const __syn_smv___e1_e2_e3_e1e2e3& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1ni_e2ni_e3ni_e1e2e3ni 
	mv& mv::operator=(const __syn_smv___e1ni_e2ni_e3ni_e1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1e2_e1e3_e2e3_e1ni_e2ni_e3ni_e1e2e3ni 
	mv& mv::operator=(const __syn_smv___e1e2_e1e3_e2e3_e1ni_e2ni_e3ni_e1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___noe1e2_noe1e3_noe2e3_e1e2e3_noe1e2e3ni 
	mv& mv::operator=(const __syn_smv___noe1e2_noe1e3_noe2e3_e1e2e3_noe1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___noe2e3_noe2ni_noe3ni_e2e3ni_noe1e2e3ni 
	mv& mv::operator=(const __syn_smv___noe2e3_noe2ni_noe3ni_e2e3ni_noe1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___noe1e3_noe1ni_noe3ni_e1e3ni_noe1e2e3ni 
	mv& mv::operator=(const __syn_smv___noe1e3_noe1ni_noe3ni_e1e3ni_noe1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___noe1e2_noe1ni_noe2ni_e1e2ni_noe1e2e3ni 
	mv& mv::operator=(const __syn_smv___noe1e2_noe1ni_noe2ni_e1e2ni_noe1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1e2e3_e1e2ni_e1e3ni_e2e3ni_noe1e2e3ni 
	mv& mv::operator=(const __syn_smv___e1e2e3_e1e2ni_e1e3ni_e2e3ni_noe1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___noe1e2e3ni 
	mv& mv::operator=(const __syn_smv___noe1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1e2e3_e1e2ni_e1e3ni_e2e3ni 
	mv& mv::operator=(const __syn_smv___e1e2e3_e1e2ni_e1e3ni_e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1e2e3 
	mv& mv::operator=(const __syn_smv___e1e2e3& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1e3_e2e3 
	mv& mv::operator=(const __syn_smv___e1e3_e2e3& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalarf1_0 
	mv& mv::operator=(const __syn_smv___scalarf1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___ni_nof1_0 
	mv& mv::operator=(const __syn_smv___ni_nof1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1_e2_e3_nof1_0 
	mv& mv::operator=(const __syn_smv___e1_e2_e3_nof1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1_e2_e3_ni_nof2_0 
	mv& mv::operator=(const __syn_smv___e1_e2_e3_ni_nof2_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1_e2_e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni_nof1_0 
	mv& mv::operator=(const __syn_smv___e1_e2_e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni_nof1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_e1e2 
	mv& mv::operator=(const __syn_smv___scalar_e1e2& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_e1e3_e2e3 
	mv& mv::operator=(const __syn_smv___scalar_e1e3_e2e3& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1e2f1_0 
	mv& mv::operator=(const __syn_smv___e1e2f1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1e2nif1_0 
	mv& mv::operator=(const __syn_smv___e1e2nif1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___noe1e2f1_0 
	mv& mv::operator=(const __syn_smv___noe1e2f1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___noe1e2f1_0_e1e2nif1_0 
	mv& mv::operator=(const __syn_smv___noe1e2f1_0_e1e2nif1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1e2_e1e3_e2e3_noe1e2e3_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni 
	mv& mv::operator=(const __syn_smv___e1e2_e1e3_e2e3_noe1e2e3_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2ni_noe1e3ni_noe2e3ni_e1e2e3ni 
	mv& mv::operator=(const __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2ni_noe1e3ni_noe2e3ni_e1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___nof1_0 
	mv& mv::operator=(const __syn_smv___nof1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___noe1 
	mv& mv::operator=(const __syn_smv___noe1& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___noe2 
	mv& mv::operator=(const __syn_smv___noe2& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___noe3 
	mv& mv::operator=(const __syn_smv___noe3& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___nonif_1_0 
	mv& mv::operator=(const __syn_smv___nonif_1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_noe2e3_e1e2e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni 
	mv& mv::operator=(const __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_noe2e3_e1e2e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_noe2e3_noe1ni_noe2ni_noe3ni 
	mv& mv::operator=(const __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_noe2e3_noe1ni_noe2ni_noe3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___no_e2_noe1e2_e3_noe1e3_e1e2e3_ni_noe1ni_e1e2ni_e1e3ni 
	mv& mv::operator=(const __syn_smv___no_e2_noe1e2_e3_noe1e3_e1e2e3_ni_noe1ni_e1e2ni_e1e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___no_e1_noe1e2_e3_noe2e3_e1e2e3_ni_noe2ni_e1e2ni_e2e3ni 
	mv& mv::operator=(const __syn_smv___no_e1_noe1e2_e3_noe2e3_e1e2e3_ni_noe2ni_e1e2ni_e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___no_e1_e2_noe1e3_noe2e3_e1e2e3_ni_noe3ni_e1e3ni_e2e3ni 
	mv& mv::operator=(const __syn_smv___no_e1_e2_noe1e3_noe2e3_e1e2e3_ni_noe3ni_e1e3ni_e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1_e2_e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni 
	mv& mv::operator=(const __syn_smv___e1_e2_e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1_e2_noe1e2_e3_noe1e3_noe2e3_ni_noe1ni_noe2ni_noe3ni 
	mv& mv::operator=(const __syn_smv___e1_e2_noe1e2_e3_noe1e3_noe2e3_ni_noe1ni_noe2ni_noe3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___no_e1_e2_e3_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni 
	mv& mv::operator=(const __syn_smv___no_e1_e2_e3_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_noe1_noe2_noe3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni 
	mv& mv::operator=(const __syn_smv___scalar_noe1_noe2_noe3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_noe1_e1e2_e1e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_e1e2e3ni 
	mv& mv::operator=(const __syn_smv___scalar_noe1_e1e2_e1e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_e1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_noe2_e1e2_e2e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe2e3ni_e1e2e3ni 
	mv& mv::operator=(const __syn_smv___scalar_noe2_e1e2_e2e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe2e3ni_e1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_noe3_e1e3_e2e3_noni_e1ni_e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni 
	mv& mv::operator=(const __syn_smv___scalar_noe3_e1e3_e2e3_noni_e1ni_e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_noe1_noe2_e1e2_noe3_e1e3_e2e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni 
	mv& mv::operator=(const __syn_smv___scalar_noe1_noe2_e1e2_noe3_e1e3_e2e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1e2_e1e3_e2e3_noe1e2e3_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni 
	mv& mv::operator=(const __syn_smv___e1e2_e1e3_e2e3_noe1e2e3_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1e2 
	mv& mv::operator=(const __syn_smv___e1e2& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___noe2ni_noe3ni_e2e3ni_noe1e2e3ni 
	mv& mv::operator=(const __syn_smv___noe2ni_noe3ni_e2e3ni_noe1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1_e2_e3_e1e2e3_ni_e1e2ni_e1e3ni 
	mv& mv::operator=(const __syn_smv___e1_e2_e3_e1e2e3_ni_e1e2ni_e1e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___noe1ni_noe3ni_e1e3ni_noe1e2e3ni 
	mv& mv::operator=(const __syn_smv___noe1ni_noe3ni_e1e3ni_noe1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1_e2_e3_e1e2e3_ni_e1e2ni_e2e3ni 
	mv& mv::operator=(const __syn_smv___e1_e2_e3_e1e2e3_ni_e1e2ni_e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___noe1ni_noe2ni_e1e2ni_noe1e2e3ni 
	mv& mv::operator=(const __syn_smv___noe1ni_noe2ni_e1e2ni_noe1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1_e2_e3_e1e2e3_ni_e1e3ni_e2e3ni 
	mv& mv::operator=(const __syn_smv___e1_e2_e3_e1e2e3_ni_e1e3ni_e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_e1ni_e2ni_e3ni_e1e2e3ni 
	mv& mv::operator=(const __syn_smv___scalar_e1ni_e2ni_e3ni_e1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1e2_e1e3_e2e3_noni 
	mv& mv::operator=(const __syn_smv___e1e2_e1e3_e2e3_noni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1e2_e1e3_e2e3_noni_e1ni_e2ni_e3ni_e1e2e3ni 
	mv& mv::operator=(const __syn_smv___e1e2_e1e3_e2e3_noni_e1ni_e2ni_e3ni_e1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_e1e2_e1e3_e2e3_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni 
	mv& mv::operator=(const __syn_smv___scalar_e1e2_e1e3_e2e3_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_e1e2_e1e3_e2e3_noni_e1ni_e2ni_e3ni 
	mv& mv::operator=(const __syn_smv___scalar_e1e2_e1e3_e2e3_noni_e1ni_e2ni_e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___nof1_0_e2f1_0 
	mv& mv::operator=(const __syn_smv___nof1_0_e2f1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___nonif1_0_e2nif1_0 
	mv& mv::operator=(const __syn_smv___nonif1_0_e2nif1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___noe1f1_0_e1e2f_1_0 
	mv& mv::operator=(const __syn_smv___noe1f1_0_e1e2f_1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___noe2e3f1_0_noe3nif_1_0 
	mv& mv::operator=(const __syn_smv___noe2e3f1_0_noe3nif_1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e3ni 
	mv& mv::operator=(const __syn_smv___e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1_e2_noe1e2_e3_noe1e3_noe2e3_e1e2e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni_noe1e2e3ni 
	mv& mv::operator=(const __syn_smv___e1_e2_noe1e2_e3_noe1e3_noe2e3_e1e2e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni_noe1e2e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1e2e3ni_noe1e2e3f1_0 
	mv& mv::operator=(const __syn_smv___e1e2e3ni_noe1e2e3f1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e2ni 
	mv& mv::operator=(const __syn_smv___e2ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e2ni_e3ni 
	mv& mv::operator=(const __syn_smv___e2ni_e3ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_e3ni 
	mv& mv::operator=(const __syn_smv___scalar_e3ni& arg1) {
		set(arg1);
		return *this;
	}




	float mv::largestCoordinate() const {
		int nc = mv_size[gu()], i;
		Float maxC = -1.0, C;

		for (i = 0; i < nc; i++) {
			C = (m_c[i] < (Float)0.0) ? -m_c[i] : m_c[i];
			if (C > maxC) maxC = C;
		}

		return maxC;
	}

	float mv::largestBasisBlade(unsigned int &bm) const {
		int nc = mv_size[gu()];
		Float maxC = -1.0, C;

		int idx = 0;
		int grade = 0;
		int i = 0;

		while (i < nc) {
			if (gu() & (1 << grade)) {
				for (int j = 0; j < mv_gradeSize[grade]; j++) {
					C = (m_c[i] < (Float)0.0) ? -m_c[i] : m_c[i];
					if (C > maxC) {
						maxC = C;
						bm = mv_basisElementBitmapByIndex[idx];
					}
					idx++;
					i++;
				}
			}
			else idx += mv_gradeSize[grade];
			grade++;
		}

		return maxC;
	}








	// set to mv 
	void no_t::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[0] = (Float)0.0;
		}


	}




	float no_t::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];

		return maxC;
	}

	float no_t::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		bm = 1;

		return maxC;
	}




	// set to mv 
	void e1_t::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 1];
		}
		else {
			m_c[0] = (Float)0.0;
		}


	}




	float e1_t::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];

		return maxC;
	}

	float e1_t::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		bm = 2;

		return maxC;
	}




	// set to mv 
	void e2_t::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 2];
		}
		else {
			m_c[0] = (Float)0.0;
		}


	}




	float e2_t::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];

		return maxC;
	}

	float e2_t::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		bm = 4;

		return maxC;
	}




	// set to mv 
	void e3_t::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 3];
		}
		else {
			m_c[0] = (Float)0.0;
		}


	}




	float e3_t::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];

		return maxC;
	}

	float e3_t::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		bm = 8;

		return maxC;
	}




	// set to mv 
	void ni_t::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 4];
		}
		else {
			m_c[0] = (Float)0.0;
		}


	}




	float ni_t::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];

		return maxC;
	}

	float ni_t::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		bm = 16;

		return maxC;
	}




	// set to mv 
	void scalar::set(const mv & arg1) {


		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[0];
		}
		else {
			m_c[0] = (Float)0.0;
		}


	}




	float scalar::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];

		return maxC;
	}

	float scalar::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		bm = 0;

		return maxC;
	}




	// set to mv 
	void noni_t::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 9];
		}
		else {
			m_c[0] = (Float)0.0;
		}


	}




	float noni_t::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];

		return maxC;
	}

	float noni_t::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		bm = 17;

		return maxC;
	}




	// set to mv 
	void point::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 2];
			m_c[3] = arg1.m_c[gidx + 3];
			m_c[4] = arg1.m_c[gidx + 4];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
		}


	}




	float point::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float point::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 1;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 2;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 8;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 16;
		}
		return maxC;
	}




	// set to mv 
	void normalizedPoint::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 1];
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[2] = arg1.m_c[gidx + 3];
			m_c[3] = arg1.m_c[gidx + 4];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}


	}




	float normalizedPoint::largestCoordinate() const {

		Float maxC = (Float)1.0f, C;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) maxC = C;
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float normalizedPoint::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f, C;
		bm = 1;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) {
			maxC = C;
			bm = 2;
		}
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 8;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 16;
		}
		return maxC;
	}




	// set to mv 
	void flatPoint::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 6];
			m_c[1] = arg1.m_c[gidx + 7];
			m_c[2] = arg1.m_c[gidx + 8];
			m_c[3] = arg1.m_c[gidx + 9];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}


	}




	float flatPoint::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float flatPoint::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 18;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 17;
		}
		return maxC;
	}




	// set to mv 
	void normalizedFlatPoint::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 6];
			m_c[1] = arg1.m_c[gidx + 7];
			m_c[2] = arg1.m_c[gidx + 8];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}


	}




	float normalizedFlatPoint::largestCoordinate() const {

		Float maxC = (Float)1.0f, C;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) maxC = C;
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float normalizedFlatPoint::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f, C;
		bm = 17;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		return maxC;
	}




	// set to mv 
	void pointPair::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 2];
			m_c[3] = arg1.m_c[gidx + 3];
			m_c[4] = arg1.m_c[gidx + 4];
			m_c[5] = arg1.m_c[gidx + 5];
			m_c[6] = arg1.m_c[gidx + 6];
			m_c[7] = arg1.m_c[gidx + 7];
			m_c[8] = arg1.m_c[gidx + 8];
			m_c[9] = arg1.m_c[gidx + 9];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[7] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
		}


	}




	float pointPair::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float pointPair::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 3;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 5;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 9;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 6;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 17;
		}
		return maxC;
	}




	// set to mv 
	void line::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[0] = arg1.m_c[gidx + 2];
			m_c[1] = arg1.m_c[gidx + 1]* (Float)-1.0;
			m_c[2] = arg1.m_c[gidx + 0];
			m_c[3] = arg1.m_c[gidx + 4]* (Float)-1.0;
			m_c[4] = arg1.m_c[gidx + 5]* (Float)-1.0;
			m_c[5] = arg1.m_c[gidx + 3]* (Float)-1.0;
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
		}


	}




	float line::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float line::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 22;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 26;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 28;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 19;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 21;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 25;
		}
		return maxC;
	}




	// set to mv 
	void dualLine::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 3];
			m_c[1] = arg1.m_c[gidx + 5]* (Float)-1.0;
			m_c[2] = arg1.m_c[gidx + 4];
			m_c[3] = arg1.m_c[gidx + 6];
			m_c[4] = arg1.m_c[gidx + 7];
			m_c[5] = arg1.m_c[gidx + 8];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
		}


	}




	float dualLine::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float dualLine::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 6;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		return maxC;
	}




	// set to mv 
	void plane::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 3];
			m_c[2] = arg1.m_c[gidx + 2]* (Float)-1.0;
			m_c[3] = arg1.m_c[gidx + 1];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}


	}




	float plane::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float plane::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 30;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 23;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 27;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 29;
		}
		return maxC;
	}




	// set to mv 
	void dualPlane::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 1];
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[2] = arg1.m_c[gidx + 3];
			m_c[3] = arg1.m_c[gidx + 4];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}


	}




	float dualPlane::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float dualPlane::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 2;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 8;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 16;
		}
		return maxC;
	}




	// set to mv 
	void circle::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 2];
			m_c[3] = arg1.m_c[gidx + 3];
			m_c[4] = arg1.m_c[gidx + 4];
			m_c[5] = arg1.m_c[gidx + 5];
			m_c[6] = arg1.m_c[gidx + 6];
			m_c[7] = arg1.m_c[gidx + 7];
			m_c[8] = arg1.m_c[gidx + 8];
			m_c[9] = arg1.m_c[gidx + 9];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[7] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
		}


	}




	float circle::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float circle::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 28;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 26;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 22;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 25;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 19;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 21;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 13;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 11;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 7;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 14;
		}
		return maxC;
	}




	// set to mv 
	void sphere::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 3];
			m_c[2] = arg1.m_c[gidx + 2]* (Float)-1.0;
			m_c[3] = arg1.m_c[gidx + 1];
			m_c[4] = arg1.m_c[gidx + 4]* (Float)-1.0;
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
		}


	}




	float sphere::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float sphere::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 30;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 23;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 27;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 29;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 15;
		}
		return maxC;
	}




	// set to mv 
	void dualSphere::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 2];
			m_c[3] = arg1.m_c[gidx + 3];
			m_c[4] = arg1.m_c[gidx + 4];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
		}


	}




	float dualSphere::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float dualSphere::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 1;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 2;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 8;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 16;
		}
		return maxC;
	}




	// set to mv 
	void normalizedSphere::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[0] = arg1.m_c[gidx + 3];
			m_c[1] = arg1.m_c[gidx + 2]* (Float)-1.0;
			m_c[2] = arg1.m_c[gidx + 1];
			m_c[3] = arg1.m_c[gidx + 4]* (Float)-1.0;
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}


	}




	float normalizedSphere::largestCoordinate() const {

		Float maxC = (Float)1.0f, C;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) maxC = C;
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float normalizedSphere::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f, C;
		bm = 30;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) {
			maxC = C;
			bm = 23;
		}
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 27;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 29;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 15;
		}
		return maxC;
	}




	// set to mv 
	void normalizedDualSphere::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 1];
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[2] = arg1.m_c[gidx + 3];
			m_c[3] = arg1.m_c[gidx + 4];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}


	}




	float normalizedDualSphere::largestCoordinate() const {

		Float maxC = (Float)1.0f, C;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) maxC = C;
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float normalizedDualSphere::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f, C;
		bm = 1;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) {
			maxC = C;
			bm = 2;
		}
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 8;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 16;
		}
		return maxC;
	}




	// set to mv 
	void freeVector::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 6];
			m_c[1] = arg1.m_c[gidx + 7];
			m_c[2] = arg1.m_c[gidx + 8];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}


	}




	float freeVector::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float freeVector::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 18;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		return maxC;
	}




	// set to mv 
	void freeBivector::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[0] = arg1.m_c[gidx + 2];
			m_c[1] = arg1.m_c[gidx + 0];
			m_c[2] = arg1.m_c[gidx + 1];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}


	}




	float freeBivector::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float freeBivector::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 22;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 28;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 26;
		}
		return maxC;
	}




	// set to mv 
	void freeTrivector::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[0] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[0] = (Float)0.0;
		}


	}




	float freeTrivector::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];

		return maxC;
	}

	float freeTrivector::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		bm = 30;

		return maxC;
	}




	// set to mv 
	void tangentVector::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 2];
			m_c[3] = arg1.m_c[gidx + 3];
			m_c[4] = arg1.m_c[gidx + 4];
			m_c[5] = arg1.m_c[gidx + 5];
			m_c[6] = arg1.m_c[gidx + 6];
			m_c[7] = arg1.m_c[gidx + 7];
			m_c[8] = arg1.m_c[gidx + 8];
			m_c[9] = arg1.m_c[gidx + 9];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[7] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
		}


	}




	float tangentVector::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float tangentVector::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 3;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 5;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 9;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 6;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 17;
		}
		return maxC;
	}




	// set to mv 
	void tangentBivector::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[0] = arg1.m_c[gidx + 9];
			m_c[1] = arg1.m_c[gidx + 0];
			m_c[2] = arg1.m_c[gidx + 1];
			m_c[3] = arg1.m_c[gidx + 2];
			m_c[4] = arg1.m_c[gidx + 3];
			m_c[5] = arg1.m_c[gidx + 4];
			m_c[6] = arg1.m_c[gidx + 5];
			m_c[7] = arg1.m_c[gidx + 6];
			m_c[8] = arg1.m_c[gidx + 7];
			m_c[9] = arg1.m_c[gidx + 8];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[7] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
		}


	}




	float tangentBivector::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float tangentBivector::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 14;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 28;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 26;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 22;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 25;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 19;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 21;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 13;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 11;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 7;
		}
		return maxC;
	}




	// set to mv 
	void vectorE2GA::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 1];
			m_c[1] = arg1.m_c[gidx + 2];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
		}


	}




	float vectorE2GA::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float vectorE2GA::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 2;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		return maxC;
	}




	// set to mv 
	void vectorE3GA::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 1];
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[2] = arg1.m_c[gidx + 3];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}


	}




	float vectorE3GA::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float vectorE3GA::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 2;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 8;
		}
		return maxC;
	}




	// set to mv 
	void bivectorE3GA::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 3];
			m_c[1] = arg1.m_c[gidx + 4];
			m_c[2] = arg1.m_c[gidx + 5];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}


	}




	float bivectorE3GA::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float bivectorE3GA::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 6;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		return maxC;
	}




	// set to mv 
	void TRversorLog::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 3];
			m_c[1] = arg1.m_c[gidx + 4];
			m_c[2] = arg1.m_c[gidx + 5];
			m_c[3] = arg1.m_c[gidx + 6];
			m_c[4] = arg1.m_c[gidx + 7];
			m_c[5] = arg1.m_c[gidx + 8];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
		}


	}




	float TRversorLog::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float TRversorLog::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 6;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		return maxC;
	}




	// set to mv 
	void TRSversorLog::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 3];
			m_c[1] = arg1.m_c[gidx + 5]* (Float)-1.0;
			m_c[2] = arg1.m_c[gidx + 4];
			m_c[3] = arg1.m_c[gidx + 6];
			m_c[4] = arg1.m_c[gidx + 7];
			m_c[5] = arg1.m_c[gidx + 8];
			m_c[6] = arg1.m_c[gidx + 9];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
		}


	}




	float TRSversorLog::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float TRSversorLog::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 6;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 17;
		}
		return maxC;
	}




	// set to mv 
	void TRversor::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 3];
			m_c[2] = arg1.m_c[gidx + 5]* (Float)-1.0;
			m_c[3] = arg1.m_c[gidx + 4];
			m_c[4] = arg1.m_c[gidx + 6];
			m_c[5] = arg1.m_c[gidx + 7];
			m_c[6] = arg1.m_c[gidx + 8];
			gidx += 10;		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[7] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[7] = (Float)0.0;
		}


	}




	float TRversor::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float TRversor::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 0;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 6;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 30;
		}
		return maxC;
	}




	// set to mv 
	void TRSversor::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 3];
			m_c[2] = arg1.m_c[gidx + 5]* (Float)-1.0;
			m_c[3] = arg1.m_c[gidx + 4];
			m_c[4] = arg1.m_c[gidx + 6];
			m_c[5] = arg1.m_c[gidx + 7];
			m_c[6] = arg1.m_c[gidx + 8];
			m_c[7] = arg1.m_c[gidx + 9];
			gidx += 10;		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[7] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[8] = arg1.m_c[gidx + 3];
			m_c[9] = arg1.m_c[gidx + 2]* (Float)-1.0;
			m_c[10] = arg1.m_c[gidx + 1];
			m_c[11] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
			m_c[10] = (Float)0.0;
			m_c[11] = (Float)0.0;
		}


	}




	float TRSversor::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) maxC = C;
		C = (m_c[11] < (Float)0.0) ? -m_c[11] : m_c[11];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float TRSversor::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 0;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 6;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 17;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 23;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 27;
		}
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) {
			maxC = C;
			bm = 29;
		}
		C = (m_c[11] < (Float)0.0) ? -m_c[11] : m_c[11];
		if (C > maxC) {
			maxC = C;
			bm = 30;
		}
		return maxC;
	}




	// set to mv 
	void evenVersor::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 0];
			m_c[2] = arg1.m_c[gidx + 1];
			m_c[3] = arg1.m_c[gidx + 2];
			m_c[4] = arg1.m_c[gidx + 3];
			m_c[5] = arg1.m_c[gidx + 4];
			m_c[6] = arg1.m_c[gidx + 5];
			m_c[7] = arg1.m_c[gidx + 6];
			m_c[8] = arg1.m_c[gidx + 7];
			m_c[9] = arg1.m_c[gidx + 8];
			m_c[10] = arg1.m_c[gidx + 9];
			gidx += 10;		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[7] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
			m_c[10] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[11] = arg1.m_c[gidx + 0];
			m_c[12] = arg1.m_c[gidx + 3];
			m_c[13] = arg1.m_c[gidx + 2]* (Float)-1.0;
			m_c[14] = arg1.m_c[gidx + 1];
			m_c[15] = arg1.m_c[gidx + 4]* (Float)-1.0;
		}
		else {
			m_c[11] = (Float)0.0;
			m_c[12] = (Float)0.0;
			m_c[13] = (Float)0.0;
			m_c[14] = (Float)0.0;
			m_c[15] = (Float)0.0;
		}


	}




	float evenVersor::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) maxC = C;
		C = (m_c[11] < (Float)0.0) ? -m_c[11] : m_c[11];
		if (C > maxC) maxC = C;
		C = (m_c[12] < (Float)0.0) ? -m_c[12] : m_c[12];
		if (C > maxC) maxC = C;
		C = (m_c[13] < (Float)0.0) ? -m_c[13] : m_c[13];
		if (C > maxC) maxC = C;
		C = (m_c[14] < (Float)0.0) ? -m_c[14] : m_c[14];
		if (C > maxC) maxC = C;
		C = (m_c[15] < (Float)0.0) ? -m_c[15] : m_c[15];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float evenVersor::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 0;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 3;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 5;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 9;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 6;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) {
			maxC = C;
			bm = 17;
		}
		C = (m_c[11] < (Float)0.0) ? -m_c[11] : m_c[11];
		if (C > maxC) {
			maxC = C;
			bm = 30;
		}
		C = (m_c[12] < (Float)0.0) ? -m_c[12] : m_c[12];
		if (C > maxC) {
			maxC = C;
			bm = 23;
		}
		C = (m_c[13] < (Float)0.0) ? -m_c[13] : m_c[13];
		if (C > maxC) {
			maxC = C;
			bm = 27;
		}
		C = (m_c[14] < (Float)0.0) ? -m_c[14] : m_c[14];
		if (C > maxC) {
			maxC = C;
			bm = 29;
		}
		C = (m_c[15] < (Float)0.0) ? -m_c[15] : m_c[15];
		if (C > maxC) {
			maxC = C;
			bm = 15;
		}
		return maxC;
	}




	// set to mv 
	void translator::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 6];
			m_c[2] = arg1.m_c[gidx + 7];
			m_c[3] = arg1.m_c[gidx + 8];
		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}


	}




	float translator::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float translator::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 0;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		return maxC;
	}




	// set to mv 
	void normalizedTranslator::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 6];
			m_c[1] = arg1.m_c[gidx + 7];
			m_c[2] = arg1.m_c[gidx + 8];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}


	}




	float normalizedTranslator::largestCoordinate() const {

		Float maxC = (Float)1.0f, C;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) maxC = C;
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float normalizedTranslator::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f, C;
		bm = 0;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		return maxC;
	}




	// set to mv 
	void rotor::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 3];
			m_c[2] = arg1.m_c[gidx + 4];
			m_c[3] = arg1.m_c[gidx + 5];
		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}


	}




	float rotor::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float rotor::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 0;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 6;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		return maxC;
	}




	// set to mv 
	void scalor::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 9];
		}
		else {
			m_c[1] = (Float)0.0;
		}


	}




	float scalor::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float scalor::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 0;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 17;
		}
		return maxC;
	}




	// set to mv 
	void __no_ct__::set(const mv & arg1) {



	}




	float __no_ct__::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __no_ct__::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 1;

		return maxC;
	}




	// set to mv 
	void __e1_ct__::set(const mv & arg1) {



	}




	float __e1_ct__::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __e1_ct__::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 2;

		return maxC;
	}




	// set to mv 
	void __e2_ct__::set(const mv & arg1) {



	}




	float __e2_ct__::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __e2_ct__::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 4;

		return maxC;
	}




	// set to mv 
	void __e3_ct__::set(const mv & arg1) {



	}




	float __e3_ct__::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __e3_ct__::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 8;

		return maxC;
	}




	// set to mv 
	void __ni_ct__::set(const mv & arg1) {



	}




	float __ni_ct__::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __ni_ct__::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 16;

		return maxC;
	}




	// set to mv 
	void __noni_ct__::set(const mv & arg1) {



	}




	float __noni_ct__::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __noni_ct__::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 17;

		return maxC;
	}




	// set to mv 
	void __e3ni_ct__::set(const mv & arg1) {



	}




	float __e3ni_ct__::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __e3ni_ct__::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 24;

		return maxC;
	}




	// set to mv 
	void __e2ni_ct__::set(const mv & arg1) {



	}




	float __e2ni_ct__::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __e2ni_ct__::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 20;

		return maxC;
	}




	// set to mv 
	void __I3_ct__::set(const mv & arg1) {



	}




	float __I3_ct__::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __I3_ct__::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 14;

		return maxC;
	}




	// set to mv 
	void __e1ni_ct__::set(const mv & arg1) {



	}




	float __e1ni_ct__::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __e1ni_ct__::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 18;

		return maxC;
	}




	// set to mv 
	void __I5_ct__::set(const mv & arg1) {



	}




	float __I5_ct__::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __I5_ct__::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 31;

		return maxC;
	}




	// set to mv 
	void __I5i_ct__::set(const mv & arg1) {



	}




	float __I5i_ct__::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __I5i_ct__::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 31;

		return maxC;
	}




	// set to mv 
	void __syn_smv___e1_e2_e3_ni_nof_1_0::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 1];
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[2] = arg1.m_c[gidx + 3];
			m_c[3] = arg1.m_c[gidx + 4];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}


	}




	float __syn_smv___e1_e2_e3_ni_nof_1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f, C;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) maxC = C;
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1_e2_e3_ni_nof_1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f, C;
		bm = 1;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) {
			maxC = C;
			bm = 2;
		}
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 8;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 16;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalar_noe1_noe2_e1e2_noe3_e1e3_e2e3_noni_e1ni_e2ni_e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 0];
			m_c[2] = arg1.m_c[gidx + 1];
			m_c[3] = arg1.m_c[gidx + 3];
			m_c[4] = arg1.m_c[gidx + 2];
			m_c[5] = arg1.m_c[gidx + 5]* (Float)-1.0;
			m_c[6] = arg1.m_c[gidx + 4];
			m_c[7] = arg1.m_c[gidx + 9];
			m_c[8] = arg1.m_c[gidx + 6];
			m_c[9] = arg1.m_c[gidx + 7];
			m_c[10] = arg1.m_c[gidx + 8];
		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[7] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
			m_c[10] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_noe1_noe2_e1e2_noe3_e1e3_e2e3_noni_e1ni_e2ni_e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___scalar_noe1_noe2_e1e2_noe3_e1e3_e2e3_noni_e1ni_e2ni_e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 0;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 3;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 5;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 6;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 9;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 17;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalar_noe1_noe2_noe3_noni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 0];
			m_c[2] = arg1.m_c[gidx + 1];
			m_c[3] = arg1.m_c[gidx + 2];
			m_c[4] = arg1.m_c[gidx + 9];
		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_noe1_noe2_noe3_noni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___scalar_noe1_noe2_noe3_noni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 0;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 3;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 5;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 9;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 17;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_noe2e3_ni_noe1ni_noe2ni_noe3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 2];
			m_c[4] = arg1.m_c[gidx + 3];
			m_c[7] = arg1.m_c[gidx + 4];
			gidx += 5;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[7] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[3] = arg1.m_c[gidx + 8];
			m_c[5] = arg1.m_c[gidx + 7];
			m_c[6] = arg1.m_c[gidx + 6];
			m_c[8] = arg1.m_c[gidx + 4];
			m_c[9] = arg1.m_c[gidx + 5];
			m_c[10] = arg1.m_c[gidx + 3];
		}
		else {
			m_c[3] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
			m_c[10] = (Float)0.0;
		}


	}




	float __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_noe2e3_ni_noe1ni_noe2ni_noe3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_noe2e3_ni_noe1ni_noe2ni_noe3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 1;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 2;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 7;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 8;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 11;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 13;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 16;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 19;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 21;
		}
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) {
			maxC = C;
			bm = 25;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalar_noe1_e1e2_e1e3_e1ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 0];
			m_c[2] = arg1.m_c[gidx + 3];
			m_c[3] = arg1.m_c[gidx + 5]* (Float)-1.0;
			m_c[4] = arg1.m_c[gidx + 6];
		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_noe1_e1e2_e1e3_e1ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___scalar_noe1_e1e2_e1e3_e1ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 0;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 3;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 6;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_e1e2e3_ni_noe1ni_e1e2ni_e1e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 2];
			m_c[4] = arg1.m_c[gidx + 3];
			m_c[7] = arg1.m_c[gidx + 4];
			gidx += 5;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[7] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[3] = arg1.m_c[gidx + 8];
			m_c[5] = arg1.m_c[gidx + 7];
			m_c[6] = arg1.m_c[gidx + 9];
			m_c[8] = arg1.m_c[gidx + 4];
			m_c[9] = arg1.m_c[gidx + 2];
			m_c[10] = arg1.m_c[gidx + 1]* (Float)-1.0;
		}
		else {
			m_c[3] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
			m_c[10] = (Float)0.0;
		}


	}




	float __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_e1e2e3_ni_noe1ni_e1e2ni_e1e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_e1e2e3_ni_noe1ni_e1e2ni_e1e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 1;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 2;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 7;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 8;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 11;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 14;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 16;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 19;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 22;
		}
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) {
			maxC = C;
			bm = 26;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalar_noe2_e1e2_e2e3_e2ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 3];
			m_c[3] = arg1.m_c[gidx + 4];
			m_c[4] = arg1.m_c[gidx + 7];
		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_noe2_e1e2_e2e3_e2ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___scalar_noe2_e1e2_e2e3_e2ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 0;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 5;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 6;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___no_e1_e2_noe1e2_e3_noe2e3_e1e2e3_ni_noe2ni_e1e2ni_e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 2];
			m_c[4] = arg1.m_c[gidx + 3];
			m_c[7] = arg1.m_c[gidx + 4];
			gidx += 5;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[7] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[3] = arg1.m_c[gidx + 8];
			m_c[5] = arg1.m_c[gidx + 6];
			m_c[6] = arg1.m_c[gidx + 9];
			m_c[8] = arg1.m_c[gidx + 5];
			m_c[9] = arg1.m_c[gidx + 2];
			m_c[10] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[3] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
			m_c[10] = (Float)0.0;
		}


	}




	float __syn_smv___no_e1_e2_noe1e2_e3_noe2e3_e1e2e3_ni_noe2ni_e1e2ni_e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___no_e1_e2_noe1e2_e3_noe2e3_e1e2e3_ni_noe2ni_e1e2ni_e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 1;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 2;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 7;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 8;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 13;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 14;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 16;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 21;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 22;
		}
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) {
			maxC = C;
			bm = 28;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalar_noe3_e1e3_e2e3_e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[2] = arg1.m_c[gidx + 5]* (Float)-1.0;
			m_c[3] = arg1.m_c[gidx + 4];
			m_c[4] = arg1.m_c[gidx + 8];
		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_noe3_e1e3_e2e3_e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___scalar_noe3_e1e3_e2e3_e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 0;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 9;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___no_e1_e2_e3_noe1e3_noe2e3_e1e2e3_ni_noe3ni_e1e3ni_e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 2];
			m_c[3] = arg1.m_c[gidx + 3];
			m_c[7] = arg1.m_c[gidx + 4];
			gidx += 5;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[7] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[4] = arg1.m_c[gidx + 7];
			m_c[5] = arg1.m_c[gidx + 6];
			m_c[6] = arg1.m_c[gidx + 9];
			m_c[8] = arg1.m_c[gidx + 3];
			m_c[9] = arg1.m_c[gidx + 1]* (Float)-1.0;
			m_c[10] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
			m_c[10] = (Float)0.0;
		}


	}




	float __syn_smv___no_e1_e2_e3_noe1e3_noe2e3_e1e2e3_ni_noe3ni_e1e3ni_e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___no_e1_e2_e3_noe1e3_noe2e3_e1e2e3_ni_noe3ni_e1e3ni_e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 1;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 2;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 8;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 11;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 13;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 14;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 16;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 25;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 26;
		}
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) {
			maxC = C;
			bm = 28;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalar_noni_e1ni_e2ni_e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 9];
			m_c[2] = arg1.m_c[gidx + 6];
			m_c[3] = arg1.m_c[gidx + 7];
			m_c[4] = arg1.m_c[gidx + 8];
		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_noni_e1ni_e2ni_e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___scalar_noni_e1ni_e2ni_e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 0;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 17;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___no_e1_e2_e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 2];
			m_c[3] = arg1.m_c[gidx + 3];
			m_c[4] = arg1.m_c[gidx + 4];
			gidx += 5;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[5] = arg1.m_c[gidx + 4];
			m_c[6] = arg1.m_c[gidx + 5];
			m_c[7] = arg1.m_c[gidx + 2];
			m_c[8] = arg1.m_c[gidx + 3];
			m_c[9] = arg1.m_c[gidx + 1]* (Float)-1.0;
			m_c[10] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[7] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
			m_c[10] = (Float)0.0;
		}


	}




	float __syn_smv___no_e1_e2_e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___no_e1_e2_e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 1;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 2;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 8;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 16;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 19;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 21;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 22;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 25;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 26;
		}
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) {
			maxC = C;
			bm = 28;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1ni_e2ni_e3ni_nonif_1_0::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 6];
			m_c[1] = arg1.m_c[gidx + 7];
			m_c[2] = arg1.m_c[gidx + 8];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}


	}




	float __syn_smv___e1ni_e2ni_e3ni_nonif_1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f, C;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) maxC = C;
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1ni_e2ni_e3ni_nonif_1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f, C;
		bm = 17;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalarf_1_0::set(const mv & arg1) {



	}




	float __syn_smv___scalarf_1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __syn_smv___scalarf_1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 0;

		return maxC;
	}




	// set to mv 
	void __syn_smv___nif_1_0::set(const mv & arg1) {



	}




	float __syn_smv___nif_1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __syn_smv___nif_1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 16;

		return maxC;
	}




	// set to mv 
	void __syn_smv___nif1_0::set(const mv & arg1) {



	}




	float __syn_smv___nif1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __syn_smv___nif1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 16;

		return maxC;
	}




	// set to mv 
	void __syn_smv___noe1e2ni_noe1e3ni_noe2e3ni_e1e2e3ni_noe1e2e3f1_0::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[0] = arg1.m_c[gidx + 3];
			m_c[1] = arg1.m_c[gidx + 2]* (Float)-1.0;
			m_c[2] = arg1.m_c[gidx + 1];
			m_c[3] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}


	}




	float __syn_smv___noe1e2ni_noe1e3ni_noe2e3ni_e1e2e3ni_noe1e2e3f1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f, C;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) maxC = C;
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___noe1e2ni_noe1e3ni_noe2e3ni_e1e2e3ni_noe1e2e3f1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f, C;
		bm = 15;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) {
			maxC = C;
			bm = 23;
		}
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 27;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 29;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 30;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2ni_noe1e3ni_noe2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 3];
			m_c[3] = arg1.m_c[gidx + 2];
			m_c[4] = arg1.m_c[gidx + 5]* (Float)-1.0;
			m_c[5] = arg1.m_c[gidx + 4];
			gidx += 10;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[6] = arg1.m_c[gidx + 3];
			m_c[7] = arg1.m_c[gidx + 2]* (Float)-1.0;
			m_c[8] = arg1.m_c[gidx + 1];
		}
		else {
			m_c[6] = (Float)0.0;
			m_c[7] = (Float)0.0;
			m_c[8] = (Float)0.0;
		}


	}




	float __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2ni_noe1e3ni_noe2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2ni_noe1e3ni_noe2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 3;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 5;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 6;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 9;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 23;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 27;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 29;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_noe2e3_e1e2e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni_noe1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 2];
			m_c[4] = arg1.m_c[gidx + 3];
			m_c[8] = arg1.m_c[gidx + 4];
			gidx += 5;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[8] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[3] = arg1.m_c[gidx + 8];
			m_c[5] = arg1.m_c[gidx + 7];
			m_c[6] = arg1.m_c[gidx + 6];
			m_c[7] = arg1.m_c[gidx + 9];
			m_c[9] = arg1.m_c[gidx + 4];
			m_c[10] = arg1.m_c[gidx + 5];
			m_c[11] = arg1.m_c[gidx + 2];
			m_c[12] = arg1.m_c[gidx + 3];
			m_c[13] = arg1.m_c[gidx + 1]* (Float)-1.0;
			m_c[14] = arg1.m_c[gidx + 0];
			gidx += 10;		}
		else {
			m_c[3] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[7] = (Float)0.0;
			m_c[9] = (Float)0.0;
			m_c[10] = (Float)0.0;
			m_c[11] = (Float)0.0;
			m_c[12] = (Float)0.0;
			m_c[13] = (Float)0.0;
			m_c[14] = (Float)0.0;
		}

		if (arg1.gu() & 16) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 32) {
			m_c[15] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[15] = (Float)0.0;
		}


	}




	float __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_noe2e3_e1e2e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni_noe1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) maxC = C;
		C = (m_c[11] < (Float)0.0) ? -m_c[11] : m_c[11];
		if (C > maxC) maxC = C;
		C = (m_c[12] < (Float)0.0) ? -m_c[12] : m_c[12];
		if (C > maxC) maxC = C;
		C = (m_c[13] < (Float)0.0) ? -m_c[13] : m_c[13];
		if (C > maxC) maxC = C;
		C = (m_c[14] < (Float)0.0) ? -m_c[14] : m_c[14];
		if (C > maxC) maxC = C;
		C = (m_c[15] < (Float)0.0) ? -m_c[15] : m_c[15];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_noe2e3_e1e2e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni_noe1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 1;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 2;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 7;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 8;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 11;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 13;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 14;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 16;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 19;
		}
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) {
			maxC = C;
			bm = 21;
		}
		C = (m_c[11] < (Float)0.0) ? -m_c[11] : m_c[11];
		if (C > maxC) {
			maxC = C;
			bm = 22;
		}
		C = (m_c[12] < (Float)0.0) ? -m_c[12] : m_c[12];
		if (C > maxC) {
			maxC = C;
			bm = 25;
		}
		C = (m_c[13] < (Float)0.0) ? -m_c[13] : m_c[13];
		if (C > maxC) {
			maxC = C;
			bm = 26;
		}
		C = (m_c[14] < (Float)0.0) ? -m_c[14] : m_c[14];
		if (C > maxC) {
			maxC = C;
			bm = 28;
		}
		C = (m_c[15] < (Float)0.0) ? -m_c[15] : m_c[15];
		if (C > maxC) {
			maxC = C;
			bm = 31;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___noni_e2ni_noe1e2ni_e3ni_noe1e3ni_e1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 9];
			m_c[1] = arg1.m_c[gidx + 7];
			m_c[3] = arg1.m_c[gidx + 8];
			gidx += 10;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[2] = arg1.m_c[gidx + 3];
			m_c[4] = arg1.m_c[gidx + 2]* (Float)-1.0;
			m_c[5] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[2] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
		}


	}




	float __syn_smv___noni_e2ni_noe1e2ni_e3ni_noe1e3ni_e1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___noni_e2ni_noe1e2ni_e3ni_noe1e3ni_e1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 17;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 23;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 27;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 30;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1_e2_e3_e1e2e3_ni_e1e2ni_e1e3ni_e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 1];
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[2] = arg1.m_c[gidx + 3];
			m_c[4] = arg1.m_c[gidx + 4];
			gidx += 5;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[4] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[3] = arg1.m_c[gidx + 9];
			m_c[5] = arg1.m_c[gidx + 2];
			m_c[6] = arg1.m_c[gidx + 1]* (Float)-1.0;
			m_c[7] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[3] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[7] = (Float)0.0;
		}


	}




	float __syn_smv___e1_e2_e3_e1e2e3_ni_e1e2ni_e1e3ni_e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1_e2_e3_e1e2e3_ni_e1e2ni_e1e3ni_e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 2;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 8;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 14;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 16;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 22;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 26;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 28;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___noni_e1ni_noe1e2ni_e3ni_noe2e3ni_e1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 9];
			m_c[1] = arg1.m_c[gidx + 6];
			m_c[3] = arg1.m_c[gidx + 8];
			gidx += 10;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[2] = arg1.m_c[gidx + 3];
			m_c[4] = arg1.m_c[gidx + 1];
			m_c[5] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[2] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
		}


	}




	float __syn_smv___noni_e1ni_noe1e2ni_e3ni_noe2e3ni_e1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___noni_e1ni_noe1e2ni_e3ni_noe2e3ni_e1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 17;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 23;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 29;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 30;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___noni_e1ni_e2ni_noe1e3ni_noe2e3ni_e1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 9];
			m_c[1] = arg1.m_c[gidx + 6];
			m_c[2] = arg1.m_c[gidx + 7];
			gidx += 10;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[3] = arg1.m_c[gidx + 2]* (Float)-1.0;
			m_c[4] = arg1.m_c[gidx + 1];
			m_c[5] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
		}


	}




	float __syn_smv___noni_e1ni_e2ni_noe1e3ni_noe2e3ni_e1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___noni_e1ni_e2ni_noe1e3ni_noe2e3ni_e1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 17;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 27;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 29;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 30;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___ni_e1e2ni_e1e3ni_e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 4];
			gidx += 5;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[2] = arg1.m_c[gidx + 1]* (Float)-1.0;
			m_c[3] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}


	}




	float __syn_smv___ni_e1e2ni_e1e3ni_e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___ni_e1e2ni_e1e3ni_e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 16;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 22;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 26;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 28;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalarf0_0::set(const mv & arg1) {



	}




	float __syn_smv___scalarf0_0::largestCoordinate() const {

		Float maxC = (Float)0.0f;

		return maxC;
	}

	float __syn_smv___scalarf0_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)0.0f;
		bm = 0;

		return maxC;
	}




	// set to mv 
	void __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2e3_noe1e2ni_noe1e3ni_noe2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 3];
			m_c[3] = arg1.m_c[gidx + 2];
			m_c[4] = arg1.m_c[gidx + 5]* (Float)-1.0;
			m_c[5] = arg1.m_c[gidx + 4];
			gidx += 10;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[6] = arg1.m_c[gidx + 4];
			m_c[7] = arg1.m_c[gidx + 3];
			m_c[8] = arg1.m_c[gidx + 2]* (Float)-1.0;
			m_c[9] = arg1.m_c[gidx + 1];
		}
		else {
			m_c[6] = (Float)0.0;
			m_c[7] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
		}


	}




	float __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2e3_noe1e2ni_noe1e3ni_noe2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2e3_noe1e2ni_noe1e3ni_noe2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 3;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 5;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 6;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 9;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 15;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 23;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 27;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 29;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___noe2_noe3_e2e3_noe1e2e3_noni_e2ni_noe1e2ni_e3ni_noe1e3ni_e1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 1];
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[2] = arg1.m_c[gidx + 4];
			m_c[4] = arg1.m_c[gidx + 9];
			m_c[5] = arg1.m_c[gidx + 7];
			m_c[7] = arg1.m_c[gidx + 8];
			gidx += 10;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[7] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[3] = arg1.m_c[gidx + 4];
			m_c[6] = arg1.m_c[gidx + 3];
			m_c[8] = arg1.m_c[gidx + 2]* (Float)-1.0;
			m_c[9] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[3] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
		}


	}




	float __syn_smv___noe2_noe3_e2e3_noe1e2e3_noni_e2ni_noe1e2ni_e3ni_noe1e3ni_e1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___noe2_noe3_e2e3_noe1e2e3_noni_e2ni_noe1e2ni_e3ni_noe1e3ni_e1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 5;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 9;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 15;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 17;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 23;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 27;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 30;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___noe1_noe3_e1e3_noe1e2e3_noni_e1ni_noe1e2ni_e3ni_noe2e3ni_e1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[2] = arg1.m_c[gidx + 5]* (Float)-1.0;
			m_c[4] = arg1.m_c[gidx + 9];
			m_c[5] = arg1.m_c[gidx + 6];
			m_c[7] = arg1.m_c[gidx + 8];
			gidx += 10;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[7] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[3] = arg1.m_c[gidx + 4];
			m_c[6] = arg1.m_c[gidx + 3];
			m_c[8] = arg1.m_c[gidx + 1];
			m_c[9] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[3] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
		}


	}




	float __syn_smv___noe1_noe3_e1e3_noe1e2e3_noni_e1ni_noe1e2ni_e3ni_noe2e3ni_e1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___noe1_noe3_e1e3_noe1e2e3_noni_e1ni_noe1e2ni_e3ni_noe2e3ni_e1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 3;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 9;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 15;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 17;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 23;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 29;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 30;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___noe1_noe2_e1e2_noe1e2e3_noni_e1ni_e2ni_noe1e3ni_noe2e3ni_e1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 3];
			m_c[4] = arg1.m_c[gidx + 9];
			m_c[5] = arg1.m_c[gidx + 6];
			m_c[6] = arg1.m_c[gidx + 7];
			gidx += 10;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[3] = arg1.m_c[gidx + 4];
			m_c[7] = arg1.m_c[gidx + 2]* (Float)-1.0;
			m_c[8] = arg1.m_c[gidx + 1];
			m_c[9] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[3] = (Float)0.0;
			m_c[7] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
		}


	}




	float __syn_smv___noe1_noe2_e1e2_noe1e2e3_noni_e1ni_e2ni_noe1e3ni_noe2e3ni_e1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___noe1_noe2_e1e2_noe1e2e3_noni_e1ni_e2ni_noe1e3ni_noe2e3ni_e1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 3;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 5;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 6;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 15;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 17;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 27;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 29;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 30;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1e2_e1e3_e2e3_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 3];
			m_c[1] = arg1.m_c[gidx + 5]* (Float)-1.0;
			m_c[2] = arg1.m_c[gidx + 4];
			m_c[3] = arg1.m_c[gidx + 6];
			m_c[4] = arg1.m_c[gidx + 7];
			m_c[6] = arg1.m_c[gidx + 8];
			gidx += 10;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[6] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[5] = arg1.m_c[gidx + 3];
			m_c[7] = arg1.m_c[gidx + 2]* (Float)-1.0;
			m_c[8] = arg1.m_c[gidx + 1];
			m_c[9] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[5] = (Float)0.0;
			m_c[7] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
		}


	}




	float __syn_smv___e1e2_e1e3_e2e3_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1e2_e1e3_e2e3_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 6;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 23;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 27;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 29;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 30;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 3];
			m_c[3] = arg1.m_c[gidx + 2];
			m_c[4] = arg1.m_c[gidx + 5]* (Float)-1.0;
			m_c[5] = arg1.m_c[gidx + 4];
			m_c[6] = arg1.m_c[gidx + 9];
			m_c[7] = arg1.m_c[gidx + 6];
			m_c[8] = arg1.m_c[gidx + 7];
			m_c[10] = arg1.m_c[gidx + 8];
			gidx += 10;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[7] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[10] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[9] = arg1.m_c[gidx + 3];
			m_c[11] = arg1.m_c[gidx + 2]* (Float)-1.0;
			m_c[12] = arg1.m_c[gidx + 1];
			m_c[13] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[9] = (Float)0.0;
			m_c[11] = (Float)0.0;
			m_c[12] = (Float)0.0;
			m_c[13] = (Float)0.0;
		}


	}




	float __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) maxC = C;
		C = (m_c[11] < (Float)0.0) ? -m_c[11] : m_c[11];
		if (C > maxC) maxC = C;
		C = (m_c[12] < (Float)0.0) ? -m_c[12] : m_c[12];
		if (C > maxC) maxC = C;
		C = (m_c[13] < (Float)0.0) ? -m_c[13] : m_c[13];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 3;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 5;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 6;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 9;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 17;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 23;
		}
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		C = (m_c[11] < (Float)0.0) ? -m_c[11] : m_c[11];
		if (C > maxC) {
			maxC = C;
			bm = 27;
		}
		C = (m_c[12] < (Float)0.0) ? -m_c[12] : m_c[12];
		if (C > maxC) {
			maxC = C;
			bm = 29;
		}
		C = (m_c[13] < (Float)0.0) ? -m_c[13] : m_c[13];
		if (C > maxC) {
			maxC = C;
			bm = 30;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalar_noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2e3_noni_noe1e2ni_noe1e3ni_noe2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 0];
			m_c[2] = arg1.m_c[gidx + 1];
			m_c[3] = arg1.m_c[gidx + 3];
			m_c[4] = arg1.m_c[gidx + 2];
			m_c[5] = arg1.m_c[gidx + 5]* (Float)-1.0;
			m_c[6] = arg1.m_c[gidx + 4];
			m_c[8] = arg1.m_c[gidx + 9];
			gidx += 10;		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[8] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[7] = arg1.m_c[gidx + 4];
			m_c[9] = arg1.m_c[gidx + 3];
			m_c[10] = arg1.m_c[gidx + 2]* (Float)-1.0;
			m_c[11] = arg1.m_c[gidx + 1];
		}
		else {
			m_c[7] = (Float)0.0;
			m_c[9] = (Float)0.0;
			m_c[10] = (Float)0.0;
			m_c[11] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2e3_noni_noe1e2ni_noe1e3ni_noe2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) maxC = C;
		C = (m_c[11] < (Float)0.0) ? -m_c[11] : m_c[11];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___scalar_noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2e3_noni_noe1e2ni_noe1e3ni_noe2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 0;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 3;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 5;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 6;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 9;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 15;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 17;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 23;
		}
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) {
			maxC = C;
			bm = 27;
		}
		C = (m_c[11] < (Float)0.0) ? -m_c[11] : m_c[11];
		if (C > maxC) {
			maxC = C;
			bm = 29;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 9];
			m_c[1] = arg1.m_c[gidx + 6];
			m_c[2] = arg1.m_c[gidx + 7];
			m_c[4] = arg1.m_c[gidx + 8];
			gidx += 10;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[4] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[3] = arg1.m_c[gidx + 3];
			m_c[5] = arg1.m_c[gidx + 2]* (Float)-1.0;
			m_c[6] = arg1.m_c[gidx + 1];
			m_c[7] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[3] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[7] = (Float)0.0;
		}


	}




	float __syn_smv___noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 17;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 23;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 27;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 29;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 30;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 3];
			m_c[3] = arg1.m_c[gidx + 2];
			m_c[4] = arg1.m_c[gidx + 5]* (Float)-1.0;
			m_c[5] = arg1.m_c[gidx + 4];
			m_c[7] = arg1.m_c[gidx + 9];
			m_c[8] = arg1.m_c[gidx + 6];
			m_c[9] = arg1.m_c[gidx + 7];
			m_c[11] = arg1.m_c[gidx + 8];
			gidx += 10;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[7] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
			m_c[11] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[6] = arg1.m_c[gidx + 4];
			m_c[10] = arg1.m_c[gidx + 3];
			m_c[12] = arg1.m_c[gidx + 2]* (Float)-1.0;
			m_c[13] = arg1.m_c[gidx + 1];
			m_c[14] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[6] = (Float)0.0;
			m_c[10] = (Float)0.0;
			m_c[12] = (Float)0.0;
			m_c[13] = (Float)0.0;
			m_c[14] = (Float)0.0;
		}


	}




	float __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) maxC = C;
		C = (m_c[11] < (Float)0.0) ? -m_c[11] : m_c[11];
		if (C > maxC) maxC = C;
		C = (m_c[12] < (Float)0.0) ? -m_c[12] : m_c[12];
		if (C > maxC) maxC = C;
		C = (m_c[13] < (Float)0.0) ? -m_c[13] : m_c[13];
		if (C > maxC) maxC = C;
		C = (m_c[14] < (Float)0.0) ? -m_c[14] : m_c[14];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 3;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 5;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 6;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 9;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 15;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 17;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) {
			maxC = C;
			bm = 23;
		}
		C = (m_c[11] < (Float)0.0) ? -m_c[11] : m_c[11];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		C = (m_c[12] < (Float)0.0) ? -m_c[12] : m_c[12];
		if (C > maxC) {
			maxC = C;
			bm = 27;
		}
		C = (m_c[13] < (Float)0.0) ? -m_c[13] : m_c[13];
		if (C > maxC) {
			maxC = C;
			bm = 29;
		}
		C = (m_c[14] < (Float)0.0) ? -m_c[14] : m_c[14];
		if (C > maxC) {
			maxC = C;
			bm = 30;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalar_e1e2_e1e3_e2e3_e1ni_e2ni_e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 3];
			m_c[2] = arg1.m_c[gidx + 5]* (Float)-1.0;
			m_c[3] = arg1.m_c[gidx + 4];
			m_c[4] = arg1.m_c[gidx + 6];
			m_c[5] = arg1.m_c[gidx + 7];
			m_c[6] = arg1.m_c[gidx + 8];
		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_e1e2_e1e3_e2e3_e1ni_e2ni_e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___scalar_e1e2_e1e3_e2e3_e1ni_e2ni_e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 0;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 6;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___nof_1_0::set(const mv & arg1) {



	}




	float __syn_smv___nof_1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __syn_smv___nof_1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 1;

		return maxC;
	}




	// set to mv 
	void __syn_smv___e1_e2_e3_e1e2e3::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 1];
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[2] = arg1.m_c[gidx + 3];
			gidx += 5;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[3] = arg1.m_c[gidx + 9];
		}
		else {
			m_c[3] = (Float)0.0;
		}


	}




	float __syn_smv___e1_e2_e3_e1e2e3::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1_e2_e3_e1e2e3::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 2;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 8;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 14;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1ni_e2ni_e3ni_e1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 6];
			m_c[1] = arg1.m_c[gidx + 7];
			m_c[2] = arg1.m_c[gidx + 8];
			gidx += 10;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[3] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[3] = (Float)0.0;
		}


	}




	float __syn_smv___e1ni_e2ni_e3ni_e1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1ni_e2ni_e3ni_e1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 18;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 30;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1e2_e1e3_e2e3_e1ni_e2ni_e3ni_e1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 3];
			m_c[1] = arg1.m_c[gidx + 5]* (Float)-1.0;
			m_c[2] = arg1.m_c[gidx + 4];
			m_c[3] = arg1.m_c[gidx + 6];
			m_c[4] = arg1.m_c[gidx + 7];
			m_c[5] = arg1.m_c[gidx + 8];
			gidx += 10;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[6] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[6] = (Float)0.0;
		}


	}




	float __syn_smv___e1e2_e1e3_e2e3_e1ni_e2ni_e3ni_e1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1e2_e1e3_e2e3_e1ni_e2ni_e3ni_e1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 6;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 30;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___noe1e2_noe1e3_noe2e3_e1e2e3_noe1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[0] = arg1.m_c[gidx + 8];
			m_c[1] = arg1.m_c[gidx + 7];
			m_c[2] = arg1.m_c[gidx + 6];
			m_c[3] = arg1.m_c[gidx + 9];
			gidx += 10;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}

		if (arg1.gu() & 16) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 32) {
			m_c[4] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[4] = (Float)0.0;
		}


	}




	float __syn_smv___noe1e2_noe1e3_noe2e3_e1e2e3_noe1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___noe1e2_noe1e3_noe2e3_e1e2e3_noe1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 7;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 11;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 13;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 14;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 31;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___noe2e3_noe2ni_noe3ni_e2e3ni_noe1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[0] = arg1.m_c[gidx + 6];
			m_c[1] = arg1.m_c[gidx + 5];
			m_c[2] = arg1.m_c[gidx + 3];
			m_c[3] = arg1.m_c[gidx + 0];
			gidx += 10;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}

		if (arg1.gu() & 16) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 32) {
			m_c[4] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[4] = (Float)0.0;
		}


	}




	float __syn_smv___noe2e3_noe2ni_noe3ni_e2e3ni_noe1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___noe2e3_noe2ni_noe3ni_e2e3ni_noe1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 13;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 21;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 25;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 28;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 31;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___noe1e3_noe1ni_noe3ni_e1e3ni_noe1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[0] = arg1.m_c[gidx + 7];
			m_c[1] = arg1.m_c[gidx + 4];
			m_c[2] = arg1.m_c[gidx + 3];
			m_c[3] = arg1.m_c[gidx + 1]* (Float)-1.0;
			gidx += 10;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}

		if (arg1.gu() & 16) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 32) {
			m_c[4] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[4] = (Float)0.0;
		}


	}




	float __syn_smv___noe1e3_noe1ni_noe3ni_e1e3ni_noe1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___noe1e3_noe1ni_noe3ni_e1e3ni_noe1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 11;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 19;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 25;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 26;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 31;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___noe1e2_noe1ni_noe2ni_e1e2ni_noe1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[0] = arg1.m_c[gidx + 8];
			m_c[1] = arg1.m_c[gidx + 4];
			m_c[2] = arg1.m_c[gidx + 5];
			m_c[3] = arg1.m_c[gidx + 2];
			gidx += 10;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}

		if (arg1.gu() & 16) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 32) {
			m_c[4] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[4] = (Float)0.0;
		}


	}




	float __syn_smv___noe1e2_noe1ni_noe2ni_e1e2ni_noe1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___noe1e2_noe1ni_noe2ni_e1e2ni_noe1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 7;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 19;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 21;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 22;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 31;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1e2e3_e1e2ni_e1e3ni_e2e3ni_noe1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[0] = arg1.m_c[gidx + 9];
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[2] = arg1.m_c[gidx + 1]* (Float)-1.0;
			m_c[3] = arg1.m_c[gidx + 0];
			gidx += 10;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}

		if (arg1.gu() & 16) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 32) {
			m_c[4] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[4] = (Float)0.0;
		}


	}




	float __syn_smv___e1e2e3_e1e2ni_e1e3ni_e2e3ni_noe1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1e2e3_e1e2ni_e1e3ni_e2e3ni_noe1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 14;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 22;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 26;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 28;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 31;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___noe1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 32) {
			m_c[0] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[0] = (Float)0.0;
		}


	}




	float __syn_smv___noe1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];

		return maxC;
	}

	float __syn_smv___noe1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		bm = 31;

		return maxC;
	}




	// set to mv 
	void __syn_smv___e1e2e3_e1e2ni_e1e3ni_e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[0] = arg1.m_c[gidx + 9];
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[2] = arg1.m_c[gidx + 1]* (Float)-1.0;
			m_c[3] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}


	}




	float __syn_smv___e1e2e3_e1e2ni_e1e3ni_e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1e2e3_e1e2ni_e1e3ni_e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 14;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 22;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 26;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 28;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1e2e3::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[0] = arg1.m_c[gidx + 9];
		}
		else {
			m_c[0] = (Float)0.0;
		}


	}




	float __syn_smv___e1e2e3::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];

		return maxC;
	}

	float __syn_smv___e1e2e3::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		bm = 14;

		return maxC;
	}




	// set to mv 
	void __syn_smv___e1e3_e2e3::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 5]* (Float)-1.0;
			m_c[1] = arg1.m_c[gidx + 4];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
		}


	}




	float __syn_smv___e1e3_e2e3::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1e3_e2e3::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 10;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalarf1_0::set(const mv & arg1) {



	}




	float __syn_smv___scalarf1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __syn_smv___scalarf1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 0;

		return maxC;
	}




	// set to mv 
	void __syn_smv___ni_nof1_0::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 4];
		}
		else {
			m_c[0] = (Float)0.0;
		}


	}




	float __syn_smv___ni_nof1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f, C;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___ni_nof1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f, C;
		bm = 1;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) {
			maxC = C;
			bm = 16;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1_e2_e3_nof1_0::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 1];
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[2] = arg1.m_c[gidx + 3];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}


	}




	float __syn_smv___e1_e2_e3_nof1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f, C;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) maxC = C;
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1_e2_e3_nof1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f, C;
		bm = 1;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) {
			maxC = C;
			bm = 2;
		}
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 8;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1_e2_e3_ni_nof2_0::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 1];
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[2] = arg1.m_c[gidx + 3];
			m_c[3] = arg1.m_c[gidx + 4];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}


	}




	float __syn_smv___e1_e2_e3_ni_nof2_0::largestCoordinate() const {

		Float maxC = (Float)2.0f, C;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) maxC = C;
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1_e2_e3_ni_nof2_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)2.0f, C;
		bm = 1;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) {
			maxC = C;
			bm = 2;
		}
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 8;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 16;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1_e2_e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni_nof1_0::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 1];
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[2] = arg1.m_c[gidx + 3];
			m_c[3] = arg1.m_c[gidx + 4];
			gidx += 5;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[4] = arg1.m_c[gidx + 4];
			m_c[5] = arg1.m_c[gidx + 5];
			m_c[6] = arg1.m_c[gidx + 2];
			m_c[7] = arg1.m_c[gidx + 3];
			m_c[8] = arg1.m_c[gidx + 1]* (Float)-1.0;
			m_c[9] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[7] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
		}


	}




	float __syn_smv___e1_e2_e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni_nof1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f, C;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) maxC = C;
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1_e2_e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni_nof1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f, C;
		bm = 1;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) {
			maxC = C;
			bm = 2;
		}
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 8;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 16;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 19;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 21;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 22;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 25;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 26;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 28;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalar_e1e2::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 3];
		}
		else {
			m_c[1] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_e1e2::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___scalar_e1e2::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 0;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 6;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalar_e1e3_e2e3::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 5]* (Float)-1.0;
			m_c[2] = arg1.m_c[gidx + 4];
		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_e1e3_e2e3::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___scalar_e1e3_e2e3::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 0;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1e2f1_0::set(const mv & arg1) {



	}




	float __syn_smv___e1e2f1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __syn_smv___e1e2f1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 6;

		return maxC;
	}




	// set to mv 
	void __syn_smv___e1e2nif1_0::set(const mv & arg1) {



	}




	float __syn_smv___e1e2nif1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __syn_smv___e1e2nif1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 22;

		return maxC;
	}




	// set to mv 
	void __syn_smv___noe1e2f1_0::set(const mv & arg1) {



	}




	float __syn_smv___noe1e2f1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __syn_smv___noe1e2f1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 7;

		return maxC;
	}




	// set to mv 
	void __syn_smv___noe1e2f1_0_e1e2nif1_0::set(const mv & arg1) {



	}




	float __syn_smv___noe1e2f1_0_e1e2nif1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __syn_smv___noe1e2f1_0_e1e2nif1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 22;

		return maxC;
	}




	// set to mv 
	void __syn_smv___e1e2_e1e3_e2e3_noe1e2e3_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 3];
			m_c[1] = arg1.m_c[gidx + 5]* (Float)-1.0;
			m_c[2] = arg1.m_c[gidx + 4];
			m_c[4] = arg1.m_c[gidx + 6];
			m_c[5] = arg1.m_c[gidx + 7];
			m_c[7] = arg1.m_c[gidx + 8];
			gidx += 10;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[7] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[3] = arg1.m_c[gidx + 4];
			m_c[6] = arg1.m_c[gidx + 3];
			m_c[8] = arg1.m_c[gidx + 2]* (Float)-1.0;
			m_c[9] = arg1.m_c[gidx + 1];
		}
		else {
			m_c[3] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
		}


	}




	float __syn_smv___e1e2_e1e3_e2e3_noe1e2e3_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1e2_e1e3_e2e3_noe1e2e3_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 6;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 15;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 23;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 27;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 29;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2ni_noe1e3ni_noe2e3ni_e1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 3];
			m_c[3] = arg1.m_c[gidx + 2];
			m_c[4] = arg1.m_c[gidx + 5]* (Float)-1.0;
			m_c[5] = arg1.m_c[gidx + 4];
			gidx += 10;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[6] = arg1.m_c[gidx + 3];
			m_c[7] = arg1.m_c[gidx + 2]* (Float)-1.0;
			m_c[8] = arg1.m_c[gidx + 1];
			m_c[9] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[6] = (Float)0.0;
			m_c[7] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
		}


	}




	float __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2ni_noe1e3ni_noe2e3ni_e1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___noe1_noe2_e1e2_noe3_e1e3_e2e3_noe1e2ni_noe1e3ni_noe2e3ni_e1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 3;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 5;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 6;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 9;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 23;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 27;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 29;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 30;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___nof1_0::set(const mv & arg1) {



	}




	float __syn_smv___nof1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __syn_smv___nof1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 1;

		return maxC;
	}




	// set to mv 
	void __syn_smv___noe1::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[0] = (Float)0.0;
		}


	}




	float __syn_smv___noe1::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];

		return maxC;
	}

	float __syn_smv___noe1::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		bm = 3;

		return maxC;
	}




	// set to mv 
	void __syn_smv___noe2::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 1];
		}
		else {
			m_c[0] = (Float)0.0;
		}


	}




	float __syn_smv___noe2::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];

		return maxC;
	}

	float __syn_smv___noe2::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		bm = 5;

		return maxC;
	}




	// set to mv 
	void __syn_smv___noe3::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 2];
		}
		else {
			m_c[0] = (Float)0.0;
		}


	}




	float __syn_smv___noe3::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];

		return maxC;
	}

	float __syn_smv___noe3::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		bm = 9;

		return maxC;
	}




	// set to mv 
	void __syn_smv___nonif_1_0::set(const mv & arg1) {



	}




	float __syn_smv___nonif_1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __syn_smv___nonif_1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 17;

		return maxC;
	}




	// set to mv 
	void __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_noe2e3_e1e2e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 2];
			m_c[4] = arg1.m_c[gidx + 3];
			m_c[8] = arg1.m_c[gidx + 4];
			gidx += 5;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[8] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[3] = arg1.m_c[gidx + 8];
			m_c[5] = arg1.m_c[gidx + 7];
			m_c[6] = arg1.m_c[gidx + 6];
			m_c[7] = arg1.m_c[gidx + 9];
			m_c[9] = arg1.m_c[gidx + 4];
			m_c[10] = arg1.m_c[gidx + 5];
			m_c[11] = arg1.m_c[gidx + 2];
			m_c[12] = arg1.m_c[gidx + 3];
			m_c[13] = arg1.m_c[gidx + 1]* (Float)-1.0;
			m_c[14] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[3] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[7] = (Float)0.0;
			m_c[9] = (Float)0.0;
			m_c[10] = (Float)0.0;
			m_c[11] = (Float)0.0;
			m_c[12] = (Float)0.0;
			m_c[13] = (Float)0.0;
			m_c[14] = (Float)0.0;
		}


	}




	float __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_noe2e3_e1e2e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) maxC = C;
		C = (m_c[11] < (Float)0.0) ? -m_c[11] : m_c[11];
		if (C > maxC) maxC = C;
		C = (m_c[12] < (Float)0.0) ? -m_c[12] : m_c[12];
		if (C > maxC) maxC = C;
		C = (m_c[13] < (Float)0.0) ? -m_c[13] : m_c[13];
		if (C > maxC) maxC = C;
		C = (m_c[14] < (Float)0.0) ? -m_c[14] : m_c[14];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_noe2e3_e1e2e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 1;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 2;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 7;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 8;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 11;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 13;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 14;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 16;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 19;
		}
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) {
			maxC = C;
			bm = 21;
		}
		C = (m_c[11] < (Float)0.0) ? -m_c[11] : m_c[11];
		if (C > maxC) {
			maxC = C;
			bm = 22;
		}
		C = (m_c[12] < (Float)0.0) ? -m_c[12] : m_c[12];
		if (C > maxC) {
			maxC = C;
			bm = 25;
		}
		C = (m_c[13] < (Float)0.0) ? -m_c[13] : m_c[13];
		if (C > maxC) {
			maxC = C;
			bm = 26;
		}
		C = (m_c[14] < (Float)0.0) ? -m_c[14] : m_c[14];
		if (C > maxC) {
			maxC = C;
			bm = 28;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_noe2e3_noe1ni_noe2ni_noe3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 2];
			m_c[4] = arg1.m_c[gidx + 3];
			gidx += 5;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[4] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[3] = arg1.m_c[gidx + 8];
			m_c[5] = arg1.m_c[gidx + 7];
			m_c[6] = arg1.m_c[gidx + 6];
			m_c[7] = arg1.m_c[gidx + 4];
			m_c[8] = arg1.m_c[gidx + 5];
			m_c[9] = arg1.m_c[gidx + 3];
		}
		else {
			m_c[3] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[7] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
		}


	}




	float __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_noe2e3_noe1ni_noe2ni_noe3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___no_e1_e2_noe1e2_e3_noe1e3_noe2e3_noe1ni_noe2ni_noe3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 1;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 2;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 7;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 8;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 11;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 13;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 19;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 21;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 25;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___no_e2_noe1e2_e3_noe1e3_e1e2e3_ni_noe1ni_e1e2ni_e1e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[3] = arg1.m_c[gidx + 3];
			m_c[6] = arg1.m_c[gidx + 4];
			gidx += 5;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[6] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[2] = arg1.m_c[gidx + 8];
			m_c[4] = arg1.m_c[gidx + 7];
			m_c[5] = arg1.m_c[gidx + 9];
			m_c[7] = arg1.m_c[gidx + 4];
			m_c[8] = arg1.m_c[gidx + 2];
			m_c[9] = arg1.m_c[gidx + 1]* (Float)-1.0;
		}
		else {
			m_c[2] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[7] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
		}


	}




	float __syn_smv___no_e2_noe1e2_e3_noe1e3_e1e2e3_ni_noe1ni_e1e2ni_e1e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___no_e2_noe1e2_e3_noe1e3_e1e2e3_ni_noe1ni_e1e2ni_e1e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 1;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 7;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 8;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 11;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 14;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 16;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 19;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 22;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 26;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___no_e1_noe1e2_e3_noe2e3_e1e2e3_ni_noe2ni_e1e2ni_e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[3] = arg1.m_c[gidx + 3];
			m_c[6] = arg1.m_c[gidx + 4];
			gidx += 5;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[6] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[2] = arg1.m_c[gidx + 8];
			m_c[4] = arg1.m_c[gidx + 6];
			m_c[5] = arg1.m_c[gidx + 9];
			m_c[7] = arg1.m_c[gidx + 5];
			m_c[8] = arg1.m_c[gidx + 2];
			m_c[9] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[2] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[7] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
		}


	}




	float __syn_smv___no_e1_noe1e2_e3_noe2e3_e1e2e3_ni_noe2ni_e1e2ni_e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___no_e1_noe1e2_e3_noe2e3_e1e2e3_ni_noe2ni_e1e2ni_e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 1;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 2;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 7;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 8;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 13;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 14;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 16;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 21;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 22;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 28;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___no_e1_e2_noe1e3_noe2e3_e1e2e3_ni_noe3ni_e1e3ni_e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 2];
			m_c[6] = arg1.m_c[gidx + 4];
			gidx += 5;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[6] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[3] = arg1.m_c[gidx + 7];
			m_c[4] = arg1.m_c[gidx + 6];
			m_c[5] = arg1.m_c[gidx + 9];
			m_c[7] = arg1.m_c[gidx + 3];
			m_c[8] = arg1.m_c[gidx + 1]* (Float)-1.0;
			m_c[9] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[7] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
		}


	}




	float __syn_smv___no_e1_e2_noe1e3_noe2e3_e1e2e3_ni_noe3ni_e1e3ni_e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___no_e1_e2_noe1e3_noe2e3_e1e2e3_ni_noe3ni_e1e3ni_e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 1;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 2;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 11;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 13;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 14;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 16;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 25;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 26;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 28;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1_e2_e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 1];
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[2] = arg1.m_c[gidx + 3];
			m_c[3] = arg1.m_c[gidx + 4];
			gidx += 5;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[4] = arg1.m_c[gidx + 4];
			m_c[5] = arg1.m_c[gidx + 5];
			m_c[6] = arg1.m_c[gidx + 2];
			m_c[7] = arg1.m_c[gidx + 3];
			m_c[8] = arg1.m_c[gidx + 1]* (Float)-1.0;
			m_c[9] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[7] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
		}


	}




	float __syn_smv___e1_e2_e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1_e2_e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 2;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 8;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 16;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 19;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 21;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 22;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 25;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 26;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 28;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1_e2_noe1e2_e3_noe1e3_noe2e3_ni_noe1ni_noe2ni_noe3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 1];
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[3] = arg1.m_c[gidx + 3];
			m_c[6] = arg1.m_c[gidx + 4];
			gidx += 5;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[6] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[2] = arg1.m_c[gidx + 8];
			m_c[4] = arg1.m_c[gidx + 7];
			m_c[5] = arg1.m_c[gidx + 6];
			m_c[7] = arg1.m_c[gidx + 4];
			m_c[8] = arg1.m_c[gidx + 5];
			m_c[9] = arg1.m_c[gidx + 3];
		}
		else {
			m_c[2] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[7] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
		}


	}




	float __syn_smv___e1_e2_noe1e2_e3_noe1e3_noe2e3_ni_noe1ni_noe2ni_noe3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1_e2_noe1e2_e3_noe1e3_noe2e3_ni_noe1ni_noe2ni_noe3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 2;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 7;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 8;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 11;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 13;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 16;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 19;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 21;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 25;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___no_e1_e2_e3_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 2];
			m_c[3] = arg1.m_c[gidx + 3];
			gidx += 5;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[4] = arg1.m_c[gidx + 4];
			m_c[5] = arg1.m_c[gidx + 5];
			m_c[6] = arg1.m_c[gidx + 2];
			m_c[7] = arg1.m_c[gidx + 3];
			m_c[8] = arg1.m_c[gidx + 1]* (Float)-1.0;
			m_c[9] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[7] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
		}


	}




	float __syn_smv___no_e1_e2_e3_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___no_e1_e2_e3_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 1;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 2;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 8;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 19;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 21;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 22;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 25;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 26;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 28;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalar_noe1_noe2_noe3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 0];
			m_c[2] = arg1.m_c[gidx + 1];
			m_c[3] = arg1.m_c[gidx + 2];
			m_c[4] = arg1.m_c[gidx + 9];
			m_c[5] = arg1.m_c[gidx + 6];
			m_c[6] = arg1.m_c[gidx + 7];
			m_c[8] = arg1.m_c[gidx + 8];
			gidx += 10;		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[8] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[7] = arg1.m_c[gidx + 3];
			m_c[9] = arg1.m_c[gidx + 2]* (Float)-1.0;
			m_c[10] = arg1.m_c[gidx + 1];
		}
		else {
			m_c[7] = (Float)0.0;
			m_c[9] = (Float)0.0;
			m_c[10] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_noe1_noe2_noe3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___scalar_noe1_noe2_noe3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 0;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 3;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 5;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 9;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 17;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 23;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 27;
		}
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) {
			maxC = C;
			bm = 29;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalar_noe1_e1e2_e1e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_e1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 0];
			m_c[2] = arg1.m_c[gidx + 3];
			m_c[3] = arg1.m_c[gidx + 5]* (Float)-1.0;
			m_c[4] = arg1.m_c[gidx + 9];
			m_c[5] = arg1.m_c[gidx + 6];
			m_c[6] = arg1.m_c[gidx + 7];
			m_c[8] = arg1.m_c[gidx + 8];
			gidx += 10;		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[8] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[7] = arg1.m_c[gidx + 3];
			m_c[9] = arg1.m_c[gidx + 2]* (Float)-1.0;
			m_c[10] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[7] = (Float)0.0;
			m_c[9] = (Float)0.0;
			m_c[10] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_noe1_e1e2_e1e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_e1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___scalar_noe1_e1e2_e1e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_e1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 0;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 3;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 6;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 17;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 23;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 27;
		}
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) {
			maxC = C;
			bm = 30;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalar_noe2_e1e2_e2e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe2e3ni_e1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 3];
			m_c[3] = arg1.m_c[gidx + 4];
			m_c[4] = arg1.m_c[gidx + 9];
			m_c[5] = arg1.m_c[gidx + 6];
			m_c[6] = arg1.m_c[gidx + 7];
			m_c[8] = arg1.m_c[gidx + 8];
			gidx += 10;		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[8] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[7] = arg1.m_c[gidx + 3];
			m_c[9] = arg1.m_c[gidx + 1];
			m_c[10] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[7] = (Float)0.0;
			m_c[9] = (Float)0.0;
			m_c[10] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_noe2_e1e2_e2e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe2e3ni_e1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___scalar_noe2_e1e2_e2e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe2e3ni_e1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 0;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 5;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 6;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 17;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 23;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 29;
		}
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) {
			maxC = C;
			bm = 30;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalar_noe3_e1e3_e2e3_noni_e1ni_e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[2] = arg1.m_c[gidx + 5]* (Float)-1.0;
			m_c[3] = arg1.m_c[gidx + 4];
			m_c[4] = arg1.m_c[gidx + 9];
			m_c[5] = arg1.m_c[gidx + 6];
			m_c[6] = arg1.m_c[gidx + 7];
			m_c[7] = arg1.m_c[gidx + 8];
			gidx += 10;		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[7] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[8] = arg1.m_c[gidx + 2]* (Float)-1.0;
			m_c[9] = arg1.m_c[gidx + 1];
			m_c[10] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
			m_c[10] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_noe3_e1e3_e2e3_noni_e1ni_e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___scalar_noe3_e1e3_e2e3_noni_e1ni_e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 0;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 9;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 17;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 27;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 29;
		}
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) {
			maxC = C;
			bm = 30;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalar_noe1_noe2_e1e2_noe3_e1e3_e2e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 0];
			m_c[2] = arg1.m_c[gidx + 1];
			m_c[3] = arg1.m_c[gidx + 3];
			m_c[4] = arg1.m_c[gidx + 2];
			m_c[5] = arg1.m_c[gidx + 5]* (Float)-1.0;
			m_c[6] = arg1.m_c[gidx + 4];
			m_c[7] = arg1.m_c[gidx + 9];
			m_c[8] = arg1.m_c[gidx + 6];
			m_c[9] = arg1.m_c[gidx + 7];
			m_c[11] = arg1.m_c[gidx + 8];
			gidx += 10;		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[7] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
			m_c[11] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[10] = arg1.m_c[gidx + 3];
			m_c[12] = arg1.m_c[gidx + 2]* (Float)-1.0;
			m_c[13] = arg1.m_c[gidx + 1];
			m_c[14] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[10] = (Float)0.0;
			m_c[12] = (Float)0.0;
			m_c[13] = (Float)0.0;
			m_c[14] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_noe1_noe2_e1e2_noe3_e1e3_e2e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) maxC = C;
		C = (m_c[11] < (Float)0.0) ? -m_c[11] : m_c[11];
		if (C > maxC) maxC = C;
		C = (m_c[12] < (Float)0.0) ? -m_c[12] : m_c[12];
		if (C > maxC) maxC = C;
		C = (m_c[13] < (Float)0.0) ? -m_c[13] : m_c[13];
		if (C > maxC) maxC = C;
		C = (m_c[14] < (Float)0.0) ? -m_c[14] : m_c[14];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___scalar_noe1_noe2_e1e2_noe3_e1e3_e2e3_noni_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 0;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 3;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 5;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 6;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 9;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 17;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) {
			maxC = C;
			bm = 23;
		}
		C = (m_c[11] < (Float)0.0) ? -m_c[11] : m_c[11];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		C = (m_c[12] < (Float)0.0) ? -m_c[12] : m_c[12];
		if (C > maxC) {
			maxC = C;
			bm = 27;
		}
		C = (m_c[13] < (Float)0.0) ? -m_c[13] : m_c[13];
		if (C > maxC) {
			maxC = C;
			bm = 29;
		}
		C = (m_c[14] < (Float)0.0) ? -m_c[14] : m_c[14];
		if (C > maxC) {
			maxC = C;
			bm = 30;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1e2_e1e3_e2e3_noe1e2e3_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 3];
			m_c[1] = arg1.m_c[gidx + 5]* (Float)-1.0;
			m_c[2] = arg1.m_c[gidx + 4];
			m_c[4] = arg1.m_c[gidx + 6];
			m_c[5] = arg1.m_c[gidx + 7];
			m_c[7] = arg1.m_c[gidx + 8];
			gidx += 10;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[7] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[3] = arg1.m_c[gidx + 4];
			m_c[6] = arg1.m_c[gidx + 3];
			m_c[8] = arg1.m_c[gidx + 2]* (Float)-1.0;
			m_c[9] = arg1.m_c[gidx + 1];
			m_c[10] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[3] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
			m_c[10] = (Float)0.0;
		}


	}




	float __syn_smv___e1e2_e1e3_e2e3_noe1e2e3_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1e2_e1e3_e2e3_noe1e2e3_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 6;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 15;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 23;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 27;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 29;
		}
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) {
			maxC = C;
			bm = 30;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1e2::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 3];
		}
		else {
			m_c[0] = (Float)0.0;
		}


	}




	float __syn_smv___e1e2::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];

		return maxC;
	}

	float __syn_smv___e1e2::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		bm = 6;

		return maxC;
	}




	// set to mv 
	void __syn_smv___noe2ni_noe3ni_e2e3ni_noe1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[0] = arg1.m_c[gidx + 5];
			m_c[1] = arg1.m_c[gidx + 3];
			m_c[2] = arg1.m_c[gidx + 0];
			gidx += 10;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}

		if (arg1.gu() & 16) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 32) {
			m_c[3] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[3] = (Float)0.0;
		}


	}




	float __syn_smv___noe2ni_noe3ni_e2e3ni_noe1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___noe2ni_noe3ni_e2e3ni_noe1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 21;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 25;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 28;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 31;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1_e2_e3_e1e2e3_ni_e1e2ni_e1e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 1];
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[2] = arg1.m_c[gidx + 3];
			m_c[4] = arg1.m_c[gidx + 4];
			gidx += 5;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[4] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[3] = arg1.m_c[gidx + 9];
			m_c[5] = arg1.m_c[gidx + 2];
			m_c[6] = arg1.m_c[gidx + 1]* (Float)-1.0;
		}
		else {
			m_c[3] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
		}


	}




	float __syn_smv___e1_e2_e3_e1e2e3_ni_e1e2ni_e1e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1_e2_e3_e1e2e3_ni_e1e2ni_e1e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 2;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 8;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 14;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 16;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 22;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 26;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___noe1ni_noe3ni_e1e3ni_noe1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[0] = arg1.m_c[gidx + 4];
			m_c[1] = arg1.m_c[gidx + 3];
			m_c[2] = arg1.m_c[gidx + 1]* (Float)-1.0;
			gidx += 10;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}

		if (arg1.gu() & 16) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 32) {
			m_c[3] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[3] = (Float)0.0;
		}


	}




	float __syn_smv___noe1ni_noe3ni_e1e3ni_noe1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___noe1ni_noe3ni_e1e3ni_noe1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 19;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 25;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 26;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 31;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1_e2_e3_e1e2e3_ni_e1e2ni_e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 1];
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[2] = arg1.m_c[gidx + 3];
			m_c[4] = arg1.m_c[gidx + 4];
			gidx += 5;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[4] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[3] = arg1.m_c[gidx + 9];
			m_c[5] = arg1.m_c[gidx + 2];
			m_c[6] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[3] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
		}


	}




	float __syn_smv___e1_e2_e3_e1e2e3_ni_e1e2ni_e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1_e2_e3_e1e2e3_ni_e1e2ni_e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 2;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 8;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 14;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 16;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 22;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 28;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___noe1ni_noe2ni_e1e2ni_noe1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[0] = arg1.m_c[gidx + 4];
			m_c[1] = arg1.m_c[gidx + 5];
			m_c[2] = arg1.m_c[gidx + 2];
			gidx += 10;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}

		if (arg1.gu() & 16) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 32) {
			m_c[3] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[3] = (Float)0.0;
		}


	}




	float __syn_smv___noe1ni_noe2ni_e1e2ni_noe1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___noe1ni_noe2ni_e1e2ni_noe1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 19;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 21;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 22;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 31;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1_e2_e3_e1e2e3_ni_e1e3ni_e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 1];
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[2] = arg1.m_c[gidx + 3];
			m_c[4] = arg1.m_c[gidx + 4];
			gidx += 5;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[4] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[3] = arg1.m_c[gidx + 9];
			m_c[5] = arg1.m_c[gidx + 1]* (Float)-1.0;
			m_c[6] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[3] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
		}


	}




	float __syn_smv___e1_e2_e3_e1e2e3_ni_e1e3ni_e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1_e2_e3_e1e2e3_ni_e1e3ni_e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 2;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 8;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 14;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 16;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 26;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 28;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalar_e1ni_e2ni_e3ni_e1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 6];
			m_c[2] = arg1.m_c[gidx + 7];
			m_c[3] = arg1.m_c[gidx + 8];
			gidx += 10;		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[4] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[4] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_e1ni_e2ni_e3ni_e1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___scalar_e1ni_e2ni_e3ni_e1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 0;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 30;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1e2_e1e3_e2e3_noni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 3];
			m_c[1] = arg1.m_c[gidx + 5]* (Float)-1.0;
			m_c[2] = arg1.m_c[gidx + 4];
			m_c[3] = arg1.m_c[gidx + 9];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}


	}




	float __syn_smv___e1e2_e1e3_e2e3_noni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1e2_e1e3_e2e3_noni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 6;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 17;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1e2_e1e3_e2e3_noni_e1ni_e2ni_e3ni_e1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 3];
			m_c[1] = arg1.m_c[gidx + 5]* (Float)-1.0;
			m_c[2] = arg1.m_c[gidx + 4];
			m_c[3] = arg1.m_c[gidx + 9];
			m_c[4] = arg1.m_c[gidx + 6];
			m_c[5] = arg1.m_c[gidx + 7];
			m_c[6] = arg1.m_c[gidx + 8];
			gidx += 10;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[7] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[7] = (Float)0.0;
		}


	}




	float __syn_smv___e1e2_e1e3_e2e3_noni_e1ni_e2ni_e3ni_e1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1e2_e1e3_e2e3_noni_e1ni_e2ni_e3ni_e1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 6;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 17;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 30;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalar_e1e2_e1e3_e2e3_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 3];
			m_c[2] = arg1.m_c[gidx + 5]* (Float)-1.0;
			m_c[3] = arg1.m_c[gidx + 4];
			m_c[4] = arg1.m_c[gidx + 6];
			m_c[5] = arg1.m_c[gidx + 7];
			m_c[7] = arg1.m_c[gidx + 8];
			gidx += 10;		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[7] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[6] = arg1.m_c[gidx + 3];
			m_c[8] = arg1.m_c[gidx + 2]* (Float)-1.0;
			m_c[9] = arg1.m_c[gidx + 1];
			m_c[10] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[6] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
			m_c[10] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_e1e2_e1e3_e2e3_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___scalar_e1e2_e1e3_e2e3_e1ni_e2ni_noe1e2ni_e3ni_noe1e3ni_noe2e3ni_e1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 0;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 6;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 23;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 27;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 29;
		}
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) {
			maxC = C;
			bm = 30;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalar_e1e2_e1e3_e2e3_noni_e1ni_e2ni_e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 3];
			m_c[2] = arg1.m_c[gidx + 5]* (Float)-1.0;
			m_c[3] = arg1.m_c[gidx + 4];
			m_c[4] = arg1.m_c[gidx + 9];
			m_c[5] = arg1.m_c[gidx + 6];
			m_c[6] = arg1.m_c[gidx + 7];
			m_c[7] = arg1.m_c[gidx + 8];
		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[7] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_e1e2_e1e3_e2e3_noni_e1ni_e2ni_e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___scalar_e1e2_e1e3_e2e3_noni_e1ni_e2ni_e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 0;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 6;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 17;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 18;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 20;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___nof1_0_e2f1_0::set(const mv & arg1) {



	}




	float __syn_smv___nof1_0_e2f1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __syn_smv___nof1_0_e2f1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 4;

		return maxC;
	}




	// set to mv 
	void __syn_smv___nonif1_0_e2nif1_0::set(const mv & arg1) {



	}




	float __syn_smv___nonif1_0_e2nif1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __syn_smv___nonif1_0_e2nif1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 20;

		return maxC;
	}




	// set to mv 
	void __syn_smv___noe1f1_0_e1e2f_1_0::set(const mv & arg1) {



	}




	float __syn_smv___noe1f1_0_e1e2f_1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __syn_smv___noe1f1_0_e1e2f_1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 6;

		return maxC;
	}




	// set to mv 
	void __syn_smv___noe2e3f1_0_noe3nif_1_0::set(const mv & arg1) {



	}




	float __syn_smv___noe2e3f1_0_noe3nif_1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __syn_smv___noe2e3f1_0_noe3nif_1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 25;

		return maxC;
	}




	// set to mv 
	void __syn_smv___e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 8];
		}
		else {
			m_c[0] = (Float)0.0;
		}


	}




	float __syn_smv___e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];

		return maxC;
	}

	float __syn_smv___e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		bm = 24;

		return maxC;
	}




	// set to mv 
	void __syn_smv___e1_e2_noe1e2_e3_noe1e3_noe2e3_e1e2e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni_noe1e2e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 1];
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[3] = arg1.m_c[gidx + 3];
			m_c[7] = arg1.m_c[gidx + 4];
			gidx += 5;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[7] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[2] = arg1.m_c[gidx + 8];
			m_c[4] = arg1.m_c[gidx + 7];
			m_c[5] = arg1.m_c[gidx + 6];
			m_c[6] = arg1.m_c[gidx + 9];
			m_c[8] = arg1.m_c[gidx + 4];
			m_c[9] = arg1.m_c[gidx + 5];
			m_c[10] = arg1.m_c[gidx + 2];
			m_c[11] = arg1.m_c[gidx + 3];
			m_c[12] = arg1.m_c[gidx + 1]* (Float)-1.0;
			m_c[13] = arg1.m_c[gidx + 0];
			gidx += 10;		}
		else {
			m_c[2] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
			m_c[8] = (Float)0.0;
			m_c[9] = (Float)0.0;
			m_c[10] = (Float)0.0;
			m_c[11] = (Float)0.0;
			m_c[12] = (Float)0.0;
			m_c[13] = (Float)0.0;
		}

		if (arg1.gu() & 16) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 32) {
			m_c[14] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[14] = (Float)0.0;
		}


	}




	float __syn_smv___e1_e2_noe1e2_e3_noe1e3_noe2e3_e1e2e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni_noe1e2e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) maxC = C;
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) maxC = C;
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) maxC = C;
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) maxC = C;
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) maxC = C;
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) maxC = C;
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) maxC = C;
		C = (m_c[11] < (Float)0.0) ? -m_c[11] : m_c[11];
		if (C > maxC) maxC = C;
		C = (m_c[12] < (Float)0.0) ? -m_c[12] : m_c[12];
		if (C > maxC) maxC = C;
		C = (m_c[13] < (Float)0.0) ? -m_c[13] : m_c[13];
		if (C > maxC) maxC = C;
		C = (m_c[14] < (Float)0.0) ? -m_c[14] : m_c[14];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1_e2_noe1e2_e3_noe1e3_noe2e3_e1e2e3_ni_noe1ni_noe2ni_e1e2ni_noe3ni_e1e3ni_e2e3ni_noe1e2e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 2;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 7;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 8;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 11;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 13;
		}
		C = (m_c[6] < (Float)0.0) ? -m_c[6] : m_c[6];
		if (C > maxC) {
			maxC = C;
			bm = 14;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
		if (C > maxC) {
			maxC = C;
			bm = 16;
		}
		C = (m_c[8] < (Float)0.0) ? -m_c[8] : m_c[8];
		if (C > maxC) {
			maxC = C;
			bm = 19;
		}
		C = (m_c[9] < (Float)0.0) ? -m_c[9] : m_c[9];
		if (C > maxC) {
			maxC = C;
			bm = 21;
		}
		C = (m_c[10] < (Float)0.0) ? -m_c[10] : m_c[10];
		if (C > maxC) {
			maxC = C;
			bm = 22;
		}
		C = (m_c[11] < (Float)0.0) ? -m_c[11] : m_c[11];
		if (C > maxC) {
			maxC = C;
			bm = 25;
		}
		C = (m_c[12] < (Float)0.0) ? -m_c[12] : m_c[12];
		if (C > maxC) {
			maxC = C;
			bm = 26;
		}
		C = (m_c[13] < (Float)0.0) ? -m_c[13] : m_c[13];
		if (C > maxC) {
			maxC = C;
			bm = 28;
		}
		C = (m_c[14] < (Float)0.0) ? -m_c[14] : m_c[14];
		if (C > maxC) {
			maxC = C;
			bm = 31;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1e2e3ni_noe1e2e3f1_0::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 8) {
			gidx += 10;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[0] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[0] = (Float)0.0;
		}


	}




	float __syn_smv___e1e2e3ni_noe1e2e3f1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f, C;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1e2e3ni_noe1e2e3f1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f, C;
		bm = 15;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) {
			maxC = C;
			bm = 30;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e2ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 7];
		}
		else {
			m_c[0] = (Float)0.0;
		}


	}




	float __syn_smv___e2ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];

		return maxC;
	}

	float __syn_smv___e2ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		bm = 20;

		return maxC;
	}




	// set to mv 
	void __syn_smv___e2ni_e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 7];
			m_c[1] = arg1.m_c[gidx + 8];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
		}


	}




	float __syn_smv___e2ni_e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e2ni_e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 20;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalar_e3ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 5;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 8];
		}
		else {
			m_c[1] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_e3ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___scalar_e3ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 0;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 24;
		}
		return maxC;
	}






	// set to identity 'I'
	void om::set() {
		// simplify forward call to set(scalar)
		set(1.0);
	}

	// set to copy
	void om::set(const om &arg1) {
		mv_memcpy(m_c, arg1.m_c, 251);
	}

	// set to scalar
	void om::set(Float scalarVal) {
		c3ga::__G2_GENERATED__::set(*this, point(point_no_e1_e2_e3_ni, scalarVal, (Float)0, (Float)0, (Float)0, (Float)0), point(point_no_e1_e2_e3_ni, (Float)0, scalarVal, (Float)0, (Float)0, (Float)0), point(point_no_e1_e2_e3_ni, (Float)0, (Float)0, scalarVal, (Float)0, (Float)0), point(point_no_e1_e2_e3_ni, (Float)0, (Float)0, (Float)0, scalarVal, (Float)0), point(point_no_e1_e2_e3_ni, (Float)0, (Float)0, (Float)0, (Float)0, scalarVal));
	}

	// set to coordinates 
	void om::set(const Float *coordinates) {
		mv_memcpy(m_c, coordinates, 251);
	}

	// set from basis vectors array
	void om::set(const point *vectors) {
		c3ga::__G2_GENERATED__::set(*this, vectors[0], vectors[1], vectors[2], vectors[3], vectors[4]);
	}


	// set from basis vectors 
	void om::set(const point & image_of_no, const point & image_of_e1, const point & image_of_e2, const point & image_of_e3, const point & image_of_ni) {
		c3ga::__G2_GENERATED__::set(*this, image_of_no, image_of_e1, image_of_e2, image_of_e3, image_of_ni);
	}

	// set to specialization
	void om::set(const omFlatPoint &arg1) {
		c3ga::__G2_GENERATED__::set(*this, arg1);
	}

	// set by coordinates, transpose
	void om::set(const Float *coordinates, bool transpose) {
		if (transpose) {
			m_c[0] = coordinates[0];
			m_c[5] = coordinates[1];
			m_c[10] = coordinates[2];
			m_c[15] = coordinates[3];
			m_c[20] = coordinates[4];
			m_c[1] = coordinates[5];
			m_c[6] = coordinates[6];
			m_c[11] = coordinates[7];
			m_c[16] = coordinates[8];
			m_c[21] = coordinates[9];
			m_c[2] = coordinates[10];
			m_c[7] = coordinates[11];
			m_c[12] = coordinates[12];
			m_c[17] = coordinates[13];
			m_c[22] = coordinates[14];
			m_c[3] = coordinates[15];
			m_c[8] = coordinates[16];
			m_c[13] = coordinates[17];
			m_c[18] = coordinates[18];
			m_c[23] = coordinates[19];
			m_c[4] = coordinates[20];
			m_c[9] = coordinates[21];
			m_c[14] = coordinates[22];
			m_c[19] = coordinates[23];
			m_c[24] = coordinates[24];
			m_c[25] = coordinates[25];
			m_c[35] = coordinates[26];
			m_c[45] = coordinates[27];
			m_c[55] = coordinates[28];
			m_c[65] = coordinates[29];
			m_c[75] = coordinates[30];
			m_c[85] = coordinates[31];
			m_c[95] = coordinates[32];
			m_c[105] = coordinates[33];
			m_c[115] = coordinates[34];
			m_c[26] = coordinates[35];
			m_c[36] = coordinates[36];
			m_c[46] = coordinates[37];
			m_c[56] = coordinates[38];
			m_c[66] = coordinates[39];
			m_c[76] = coordinates[40];
			m_c[86] = coordinates[41];
			m_c[96] = coordinates[42];
			m_c[106] = coordinates[43];
			m_c[116] = coordinates[44];
			m_c[27] = coordinates[45];
			m_c[37] = coordinates[46];
			m_c[47] = coordinates[47];
			m_c[57] = coordinates[48];
			m_c[67] = coordinates[49];
			m_c[77] = coordinates[50];
			m_c[87] = coordinates[51];
			m_c[97] = coordinates[52];
			m_c[107] = coordinates[53];
			m_c[117] = coordinates[54];
			m_c[28] = coordinates[55];
			m_c[38] = coordinates[56];
			m_c[48] = coordinates[57];
			m_c[58] = coordinates[58];
			m_c[68] = coordinates[59];
			m_c[78] = coordinates[60];
			m_c[88] = coordinates[61];
			m_c[98] = coordinates[62];
			m_c[108] = coordinates[63];
			m_c[118] = coordinates[64];
			m_c[29] = coordinates[65];
			m_c[39] = coordinates[66];
			m_c[49] = coordinates[67];
			m_c[59] = coordinates[68];
			m_c[69] = coordinates[69];
			m_c[79] = coordinates[70];
			m_c[89] = coordinates[71];
			m_c[99] = coordinates[72];
			m_c[109] = coordinates[73];
			m_c[119] = coordinates[74];
			m_c[30] = coordinates[75];
			m_c[40] = coordinates[76];
			m_c[50] = coordinates[77];
			m_c[60] = coordinates[78];
			m_c[70] = coordinates[79];
			m_c[80] = coordinates[80];
			m_c[90] = coordinates[81];
			m_c[100] = coordinates[82];
			m_c[110] = coordinates[83];
			m_c[120] = coordinates[84];
			m_c[31] = coordinates[85];
			m_c[41] = coordinates[86];
			m_c[51] = coordinates[87];
			m_c[61] = coordinates[88];
			m_c[71] = coordinates[89];
			m_c[81] = coordinates[90];
			m_c[91] = coordinates[91];
			m_c[101] = coordinates[92];
			m_c[111] = coordinates[93];
			m_c[121] = coordinates[94];
			m_c[32] = coordinates[95];
			m_c[42] = coordinates[96];
			m_c[52] = coordinates[97];
			m_c[62] = coordinates[98];
			m_c[72] = coordinates[99];
			m_c[82] = coordinates[100];
			m_c[92] = coordinates[101];
			m_c[102] = coordinates[102];
			m_c[112] = coordinates[103];
			m_c[122] = coordinates[104];
			m_c[33] = coordinates[105];
			m_c[43] = coordinates[106];
			m_c[53] = coordinates[107];
			m_c[63] = coordinates[108];
			m_c[73] = coordinates[109];
			m_c[83] = coordinates[110];
			m_c[93] = coordinates[111];
			m_c[103] = coordinates[112];
			m_c[113] = coordinates[113];
			m_c[123] = coordinates[114];
			m_c[34] = coordinates[115];
			m_c[44] = coordinates[116];
			m_c[54] = coordinates[117];
			m_c[64] = coordinates[118];
			m_c[74] = coordinates[119];
			m_c[84] = coordinates[120];
			m_c[94] = coordinates[121];
			m_c[104] = coordinates[122];
			m_c[114] = coordinates[123];
			m_c[124] = coordinates[124];
			m_c[125] = coordinates[125];
			m_c[135] = coordinates[126];
			m_c[145] = coordinates[127];
			m_c[155] = coordinates[128];
			m_c[165] = coordinates[129];
			m_c[175] = coordinates[130];
			m_c[185] = coordinates[131];
			m_c[195] = coordinates[132];
			m_c[205] = coordinates[133];
			m_c[215] = coordinates[134];
			m_c[126] = coordinates[135];
			m_c[136] = coordinates[136];
			m_c[146] = coordinates[137];
			m_c[156] = coordinates[138];
			m_c[166] = coordinates[139];
			m_c[176] = coordinates[140];
			m_c[186] = coordinates[141];
			m_c[196] = coordinates[142];
			m_c[206] = coordinates[143];
			m_c[216] = coordinates[144];
			m_c[127] = coordinates[145];
			m_c[137] = coordinates[146];
			m_c[147] = coordinates[147];
			m_c[157] = coordinates[148];
			m_c[167] = coordinates[149];
			m_c[177] = coordinates[150];
			m_c[187] = coordinates[151];
			m_c[197] = coordinates[152];
			m_c[207] = coordinates[153];
			m_c[217] = coordinates[154];
			m_c[128] = coordinates[155];
			m_c[138] = coordinates[156];
			m_c[148] = coordinates[157];
			m_c[158] = coordinates[158];
			m_c[168] = coordinates[159];
			m_c[178] = coordinates[160];
			m_c[188] = coordinates[161];
			m_c[198] = coordinates[162];
			m_c[208] = coordinates[163];
			m_c[218] = coordinates[164];
			m_c[129] = coordinates[165];
			m_c[139] = coordinates[166];
			m_c[149] = coordinates[167];
			m_c[159] = coordinates[168];
			m_c[169] = coordinates[169];
			m_c[179] = coordinates[170];
			m_c[189] = coordinates[171];
			m_c[199] = coordinates[172];
			m_c[209] = coordinates[173];
			m_c[219] = coordinates[174];
			m_c[130] = coordinates[175];
			m_c[140] = coordinates[176];
			m_c[150] = coordinates[177];
			m_c[160] = coordinates[178];
			m_c[170] = coordinates[179];
			m_c[180] = coordinates[180];
			m_c[190] = coordinates[181];
			m_c[200] = coordinates[182];
			m_c[210] = coordinates[183];
			m_c[220] = coordinates[184];
			m_c[131] = coordinates[185];
			m_c[141] = coordinates[186];
			m_c[151] = coordinates[187];
			m_c[161] = coordinates[188];
			m_c[171] = coordinates[189];
			m_c[181] = coordinates[190];
			m_c[191] = coordinates[191];
			m_c[201] = coordinates[192];
			m_c[211] = coordinates[193];
			m_c[221] = coordinates[194];
			m_c[132] = coordinates[195];
			m_c[142] = coordinates[196];
			m_c[152] = coordinates[197];
			m_c[162] = coordinates[198];
			m_c[172] = coordinates[199];
			m_c[182] = coordinates[200];
			m_c[192] = coordinates[201];
			m_c[202] = coordinates[202];
			m_c[212] = coordinates[203];
			m_c[222] = coordinates[204];
			m_c[133] = coordinates[205];
			m_c[143] = coordinates[206];
			m_c[153] = coordinates[207];
			m_c[163] = coordinates[208];
			m_c[173] = coordinates[209];
			m_c[183] = coordinates[210];
			m_c[193] = coordinates[211];
			m_c[203] = coordinates[212];
			m_c[213] = coordinates[213];
			m_c[223] = coordinates[214];
			m_c[134] = coordinates[215];
			m_c[144] = coordinates[216];
			m_c[154] = coordinates[217];
			m_c[164] = coordinates[218];
			m_c[174] = coordinates[219];
			m_c[184] = coordinates[220];
			m_c[194] = coordinates[221];
			m_c[204] = coordinates[222];
			m_c[214] = coordinates[223];
			m_c[224] = coordinates[224];
			m_c[225] = coordinates[225];
			m_c[230] = coordinates[226];
			m_c[235] = coordinates[227];
			m_c[240] = coordinates[228];
			m_c[245] = coordinates[229];
			m_c[226] = coordinates[230];
			m_c[231] = coordinates[231];
			m_c[236] = coordinates[232];
			m_c[241] = coordinates[233];
			m_c[246] = coordinates[234];
			m_c[227] = coordinates[235];
			m_c[232] = coordinates[236];
			m_c[237] = coordinates[237];
			m_c[242] = coordinates[238];
			m_c[247] = coordinates[239];
			m_c[228] = coordinates[240];
			m_c[233] = coordinates[241];
			m_c[238] = coordinates[242];
			m_c[243] = coordinates[243];
			m_c[248] = coordinates[244];
			m_c[229] = coordinates[245];
			m_c[234] = coordinates[246];
			m_c[239] = coordinates[247];
			m_c[244] = coordinates[248];
			m_c[249] = coordinates[249];
			m_c[250] = coordinates[250];
		}
		else set(coordinates);
	}




	// assign copy
	om &om::operator=(const om &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar (creates scalar * 'I' outermorphism)
	om &om::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}

	/// assign specialization:
	om &om::operator=(const omFlatPoint &arg1) {
		set(arg1);
		return *this;
	}









	// G2 functions:
	mv lcont(const mv& x, const mv& y) {
		mv __temp_var_1__;
		float __tmp_coord_array_1__[32] ;
		mv_zero(__tmp_coord_array_1__, 32);
		const float* __y_xpd__[6] ;
		y.expand(__y_xpd__, true);
		const float* __x_xpd__[6] ;
		x.expand(__x_xpd__, true);
		if (((y.m_gu & 1) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_1__[0] += (__x_xpd__[0][0] * __y_xpd__[0][0]);

			}

		}
		if (((y.m_gu & 2) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_1__[1] += (__y_xpd__[1][0] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[2] += (__y_xpd__[1][1] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[3] += (__y_xpd__[1][2] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[4] += (__y_xpd__[1][3] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[5] += (__y_xpd__[1][4] * __x_xpd__[0][0]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_1__[0] += ((-1.0f * __x_xpd__[1][4] * __y_xpd__[1][0]) + (__x_xpd__[1][3] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[1][0] * __y_xpd__[1][4]) + (__x_xpd__[1][2] * __y_xpd__[1][2]) + (__x_xpd__[1][1] * __y_xpd__[1][1]));

			}

		}
		if (((y.m_gu & 4) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_1__[6] += (__y_xpd__[2][0] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[7] += (__y_xpd__[2][1] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[8] += (__y_xpd__[2][2] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[9] += (__y_xpd__[2][3] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[10] += (__y_xpd__[2][4] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[11] += (__y_xpd__[2][5] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[12] += (__y_xpd__[2][6] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[13] += (__y_xpd__[2][7] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[14] += (__y_xpd__[2][8] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[15] += (__y_xpd__[2][9] * __x_xpd__[0][0]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_1__[1] += ((-1.0f * __x_xpd__[1][2] * __y_xpd__[2][1]) + (__x_xpd__[1][0] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[2][0]));
				__tmp_coord_array_1__[2] += ((__x_xpd__[1][0] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[2][0]) + (__x_xpd__[1][3] * __y_xpd__[2][5]));
				__tmp_coord_array_1__[3] += ((__x_xpd__[1][1] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[2][4]) + (__x_xpd__[1][0] * __y_xpd__[2][7]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[2][1]));
				__tmp_coord_array_1__[4] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[2][2]) + (__x_xpd__[1][2] * __y_xpd__[2][4]) + (__x_xpd__[1][0] * __y_xpd__[2][8]));
				__tmp_coord_array_1__[5] += ((__x_xpd__[1][3] * __y_xpd__[2][8]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[2][9]) + (__x_xpd__[1][2] * __y_xpd__[2][7]) + (__x_xpd__[1][1] * __y_xpd__[2][6]));

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_1__[0] += ((-1.0f * __x_xpd__[2][1] * __y_xpd__[2][7]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[2][6]) + (__x_xpd__[2][9] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[2][8]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[2][3]));

			}

		}
		if (((y.m_gu & 8) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_1__[16] += (__y_xpd__[3][0] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[17] += (__y_xpd__[3][1] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[18] += (__y_xpd__[3][2] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[19] += (__y_xpd__[3][3] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[20] += (__y_xpd__[3][4] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[21] += (__y_xpd__[3][5] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[22] += (__y_xpd__[3][6] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[23] += (__y_xpd__[3][7] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[24] += (__y_xpd__[3][8] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[25] += (__y_xpd__[3][9] * __x_xpd__[0][0]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_1__[6] += ((__x_xpd__[1][3] * __y_xpd__[3][7]) + (__x_xpd__[1][2] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[1][0] * __y_xpd__[3][4]));
				__tmp_coord_array_1__[7] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[1][0] * __y_xpd__[3][5]) + (__x_xpd__[1][3] * __y_xpd__[3][6]));
				__tmp_coord_array_1__[8] += ((-1.0f * __x_xpd__[1][0] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[3][7]));
				__tmp_coord_array_1__[9] += ((-1.0f * __x_xpd__[1][4] * __y_xpd__[3][8]) + (__x_xpd__[1][3] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[1][0] * __y_xpd__[3][2]));
				__tmp_coord_array_1__[10] += ((-1.0f * __x_xpd__[1][4] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[1][0] * __y_xpd__[3][0]) + (__x_xpd__[1][1] * __y_xpd__[3][9]));
				__tmp_coord_array_1__[11] += ((__x_xpd__[1][4] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[1][0] * __y_xpd__[3][1]) + (__x_xpd__[1][2] * __y_xpd__[3][9]));
				__tmp_coord_array_1__[12] += ((-1.0f * __x_xpd__[1][4] * __y_xpd__[3][4]) + (__x_xpd__[1][3] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[3][2]));
				__tmp_coord_array_1__[13] += ((-1.0f * __x_xpd__[1][4] * __y_xpd__[3][5]) + (__x_xpd__[1][1] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[3][0]));
				__tmp_coord_array_1__[14] += ((-1.0f * __x_xpd__[1][4] * __y_xpd__[3][3]) + (__x_xpd__[1][2] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[3][1]));
				__tmp_coord_array_1__[15] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[3][4]));

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_1__[1] += ((-1.0f * __x_xpd__[2][4] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[3][5]) + (__x_xpd__[2][5] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[3][3]));
				__tmp_coord_array_1__[2] += ((__x_xpd__[2][2] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[3][4]) + (__x_xpd__[2][8] * __y_xpd__[3][7]) + (__x_xpd__[2][7] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[3][9]));
				__tmp_coord_array_1__[3] += ((__x_xpd__[2][8] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[3][0]) + (__x_xpd__[2][0] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[3][5]));
				__tmp_coord_array_1__[4] += ((__x_xpd__[2][1] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[3][3]));
				__tmp_coord_array_1__[5] += ((-1.0f * __x_xpd__[2][7] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[3][3]));

			}
			if (((x.m_gu & 8) != 0)) {
				__tmp_coord_array_1__[0] += ((__x_xpd__[3][2] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[3][9]) + (__x_xpd__[3][4] * __y_xpd__[3][4]) + (__x_xpd__[3][5] * __y_xpd__[3][5]) + (__x_xpd__[3][0] * __y_xpd__[3][6]) + (__x_xpd__[3][6] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[3][7]) + (__x_xpd__[3][8] * __y_xpd__[3][2]) + (__x_xpd__[3][3] * __y_xpd__[3][3]));

			}

		}
		if (((y.m_gu & 16) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_1__[26] += (__y_xpd__[4][0] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[27] += (__y_xpd__[4][1] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[28] += (__y_xpd__[4][2] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[29] += (__y_xpd__[4][3] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[30] += (__y_xpd__[4][4] * __x_xpd__[0][0]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_1__[16] += ((__x_xpd__[1][1] * __y_xpd__[4][0]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[4][1]));
				__tmp_coord_array_1__[17] += ((-1.0f * __x_xpd__[1][4] * __y_xpd__[4][2]) + (__x_xpd__[1][2] * __y_xpd__[4][0]));
				__tmp_coord_array_1__[18] += ((-1.0f * __x_xpd__[1][4] * __y_xpd__[4][3]) + (__x_xpd__[1][3] * __y_xpd__[4][0]));
				__tmp_coord_array_1__[19] += ((-1.0f * __x_xpd__[1][2] * __y_xpd__[4][1]) + (__x_xpd__[1][1] * __y_xpd__[4][2]));
				__tmp_coord_array_1__[20] += ((__x_xpd__[1][2] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[4][2]));
				__tmp_coord_array_1__[21] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[4][3]) + (__x_xpd__[1][3] * __y_xpd__[4][1]));
				__tmp_coord_array_1__[22] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[4][4]) + (__x_xpd__[1][0] * __y_xpd__[4][1]));
				__tmp_coord_array_1__[23] += ((__x_xpd__[1][2] * __y_xpd__[4][4]) + (-1.0f * __x_xpd__[1][0] * __y_xpd__[4][2]));
				__tmp_coord_array_1__[24] += ((__x_xpd__[1][0] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[4][4]));
				__tmp_coord_array_1__[25] += ((__x_xpd__[1][0] * __y_xpd__[4][0]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[4][4]));

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_1__[6] += ((-1.0f * __x_xpd__[2][1] * __y_xpd__[4][3]) + (__x_xpd__[2][2] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[4][4]));
				__tmp_coord_array_1__[7] += ((-1.0f * __x_xpd__[2][2] * __y_xpd__[4][1]) + (__x_xpd__[2][0] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[4][4]));
				__tmp_coord_array_1__[8] += ((-1.0f * __x_xpd__[2][0] * __y_xpd__[4][2]) + (__x_xpd__[2][1] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[4][4]));
				__tmp_coord_array_1__[9] += ((-1.0f * __x_xpd__[2][2] * __y_xpd__[4][0]) + (__x_xpd__[2][9] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[4][4]));
				__tmp_coord_array_1__[10] += ((-1.0f * __x_xpd__[2][6] * __y_xpd__[4][4]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[4][0]) + (__x_xpd__[2][9] * __y_xpd__[4][1]));
				__tmp_coord_array_1__[11] += ((-1.0f * __x_xpd__[2][7] * __y_xpd__[4][4]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[4][0]) + (__x_xpd__[2][9] * __y_xpd__[4][2]));
				__tmp_coord_array_1__[12] += ((__x_xpd__[2][7] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[4][0]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[4][2]));
				__tmp_coord_array_1__[13] += ((__x_xpd__[2][8] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[4][0]));
				__tmp_coord_array_1__[14] += ((__x_xpd__[2][6] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[4][0]));
				__tmp_coord_array_1__[15] += ((-1.0f * __x_xpd__[2][3] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[4][2]));

			}
			if (((x.m_gu & 8) != 0)) {
				__tmp_coord_array_1__[1] += ((-1.0f * __x_xpd__[3][8] * __y_xpd__[4][3]) + (__x_xpd__[3][9] * __y_xpd__[4][4]) + (__x_xpd__[3][7] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[4][1]));
				__tmp_coord_array_1__[2] += ((__x_xpd__[3][0] * __y_xpd__[4][4]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[4][2]) + (__x_xpd__[3][5] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[4][0]));
				__tmp_coord_array_1__[3] += ((__x_xpd__[3][7] * __y_xpd__[4][0]) + (__x_xpd__[3][1] * __y_xpd__[4][4]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[4][3]) + (__x_xpd__[3][3] * __y_xpd__[4][1]));
				__tmp_coord_array_1__[4] += ((-1.0f * __x_xpd__[3][8] * __y_xpd__[4][0]) + (__x_xpd__[3][4] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[4][1]) + (__x_xpd__[3][2] * __y_xpd__[4][4]));
				__tmp_coord_array_1__[5] += ((__x_xpd__[3][1] * __y_xpd__[4][2]) + (__x_xpd__[3][2] * __y_xpd__[4][3]) + (__x_xpd__[3][0] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[4][0]));

			}
			if (((x.m_gu & 16) != 0)) {
				__tmp_coord_array_1__[0] += ((-1.0f * __x_xpd__[4][3] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[4][2] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[4][1] * __y_xpd__[4][1]) + (__x_xpd__[4][0] * __y_xpd__[4][4]) + (__x_xpd__[4][4] * __y_xpd__[4][0]));

			}

		}
		if (((y.m_gu & 32) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_1__[31] += (__y_xpd__[5][0] * __x_xpd__[0][0]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_1__[26] += (-1.0f * __x_xpd__[1][4] * __y_xpd__[5][0]);
				__tmp_coord_array_1__[27] += (-1.0f * __x_xpd__[1][1] * __y_xpd__[5][0]);
				__tmp_coord_array_1__[28] += (-1.0f * __x_xpd__[1][2] * __y_xpd__[5][0]);
				__tmp_coord_array_1__[29] += (-1.0f * __x_xpd__[1][3] * __y_xpd__[5][0]);
				__tmp_coord_array_1__[30] += (-1.0f * __x_xpd__[1][0] * __y_xpd__[5][0]);

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_1__[16] += (-1.0f * __x_xpd__[2][6] * __y_xpd__[5][0]);
				__tmp_coord_array_1__[17] += (-1.0f * __x_xpd__[2][7] * __y_xpd__[5][0]);
				__tmp_coord_array_1__[18] += (-1.0f * __x_xpd__[2][8] * __y_xpd__[5][0]);
				__tmp_coord_array_1__[19] += (-1.0f * __x_xpd__[2][3] * __y_xpd__[5][0]);
				__tmp_coord_array_1__[20] += (-1.0f * __x_xpd__[2][4] * __y_xpd__[5][0]);
				__tmp_coord_array_1__[21] += (-1.0f * __x_xpd__[2][5] * __y_xpd__[5][0]);
				__tmp_coord_array_1__[22] += (-1.0f * __x_xpd__[2][0] * __y_xpd__[5][0]);
				__tmp_coord_array_1__[23] += (__x_xpd__[2][1] * __y_xpd__[5][0]);
				__tmp_coord_array_1__[24] += (-1.0f * __x_xpd__[2][2] * __y_xpd__[5][0]);
				__tmp_coord_array_1__[25] += (-1.0f * __x_xpd__[2][9] * __y_xpd__[5][0]);

			}
			if (((x.m_gu & 8) != 0)) {
				__tmp_coord_array_1__[6] += (__x_xpd__[3][6] * __y_xpd__[5][0]);
				__tmp_coord_array_1__[7] += (-1.0f * __x_xpd__[3][7] * __y_xpd__[5][0]);
				__tmp_coord_array_1__[8] += (__x_xpd__[3][8] * __y_xpd__[5][0]);
				__tmp_coord_array_1__[9] += (__x_xpd__[3][3] * __y_xpd__[5][0]);
				__tmp_coord_array_1__[10] += (__x_xpd__[3][4] * __y_xpd__[5][0]);
				__tmp_coord_array_1__[11] += (__x_xpd__[3][5] * __y_xpd__[5][0]);
				__tmp_coord_array_1__[12] += (__x_xpd__[3][0] * __y_xpd__[5][0]);
				__tmp_coord_array_1__[13] += (__x_xpd__[3][1] * __y_xpd__[5][0]);
				__tmp_coord_array_1__[14] += (__x_xpd__[3][2] * __y_xpd__[5][0]);
				__tmp_coord_array_1__[15] += (__x_xpd__[3][9] * __y_xpd__[5][0]);

			}
			if (((x.m_gu & 16) != 0)) {
				__tmp_coord_array_1__[1] += (__x_xpd__[4][4] * __y_xpd__[5][0]);
				__tmp_coord_array_1__[2] += (__x_xpd__[4][1] * __y_xpd__[5][0]);
				__tmp_coord_array_1__[3] += (__x_xpd__[4][2] * __y_xpd__[5][0]);
				__tmp_coord_array_1__[4] += (__x_xpd__[4][3] * __y_xpd__[5][0]);
				__tmp_coord_array_1__[5] += (__x_xpd__[4][0] * __y_xpd__[5][0]);

			}
			if (((x.m_gu & 32) != 0)) {
				__tmp_coord_array_1__[0] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[5][0]);

			}

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_1__);
		return __temp_var_1__;
	}
	scalar scp(const mv& x, const mv& y) {
		scalar __temp_var_1__;
		const float* __y_xpd__[6] ;
		y.expand(__y_xpd__, true);
		const float* __x_xpd__[6] ;
		x.expand(__x_xpd__, true);
		if (((y.m_gu & 1) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__temp_var_1__.m_c[0] += (__x_xpd__[0][0] * __y_xpd__[0][0]);

			}

		}
		if (((y.m_gu & 2) != 0)) {
			if (((x.m_gu & 2) != 0)) {
				__temp_var_1__.m_c[0] += ((__x_xpd__[1][3] * __y_xpd__[1][3]) + (__x_xpd__[1][1] * __y_xpd__[1][1]) + (__x_xpd__[1][2] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[1][0] * __y_xpd__[1][4]));

			}

		}
		if (((y.m_gu & 4) != 0)) {
			if (((x.m_gu & 4) != 0)) {
				__temp_var_1__.m_c[0] += ((-1.0f * __x_xpd__[2][7] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[2][0]) + (__x_xpd__[2][9] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[2][8]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[2][7]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[2][5]));

			}

		}
		if (((y.m_gu & 8) != 0)) {
			if (((x.m_gu & 8) != 0)) {
				__temp_var_1__.m_c[0] += ((-1.0f * __x_xpd__[3][9] * __y_xpd__[3][9]) + (__x_xpd__[3][6] * __y_xpd__[3][0]) + (__x_xpd__[3][5] * __y_xpd__[3][5]) + (__x_xpd__[3][4] * __y_xpd__[3][4]) + (__x_xpd__[3][0] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[3][1]) + (__x_xpd__[3][3] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[3][7]) + (__x_xpd__[3][2] * __y_xpd__[3][8]) + (__x_xpd__[3][8] * __y_xpd__[3][2]));

			}

		}
		if (((y.m_gu & 16) != 0)) {
			if (((x.m_gu & 16) != 0)) {
				__temp_var_1__.m_c[0] += ((-1.0f * __x_xpd__[4][3] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[4][2] * __y_xpd__[4][2]) + (__x_xpd__[4][4] * __y_xpd__[4][0]) + (__x_xpd__[4][0] * __y_xpd__[4][4]) + (-1.0f * __x_xpd__[4][1] * __y_xpd__[4][1]));

			}

		}
		if (((y.m_gu & 32) != 0)) {
			if (((x.m_gu & 32) != 0)) {
				__temp_var_1__.m_c[0] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[5][0]);

			}

		}
		return __temp_var_1__;
	}
	mv gp(const mv& x, const mv& y) {
		mv __temp_var_1__;
		float __tmp_coord_array_2__[32] ;
		mv_zero(__tmp_coord_array_2__, 32);
		const float* __x_xpd__[6] ;
		x.expand(__x_xpd__, true);
		const float* __y_xpd__[6] ;
		y.expand(__y_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			if (((y.m_gu & 1) != 0)) {
				__tmp_coord_array_2__[0] += (__x_xpd__[0][0] * __y_xpd__[0][0]);

			}
			if (((y.m_gu & 2) != 0)) {
				__tmp_coord_array_2__[1] += (__x_xpd__[0][0] * __y_xpd__[1][0]);
				__tmp_coord_array_2__[2] += (__x_xpd__[0][0] * __y_xpd__[1][1]);
				__tmp_coord_array_2__[3] += (__x_xpd__[0][0] * __y_xpd__[1][2]);
				__tmp_coord_array_2__[4] += (__x_xpd__[0][0] * __y_xpd__[1][3]);
				__tmp_coord_array_2__[5] += (__x_xpd__[0][0] * __y_xpd__[1][4]);

			}
			if (((y.m_gu & 4) != 0)) {
				__tmp_coord_array_2__[6] += (__x_xpd__[0][0] * __y_xpd__[2][0]);
				__tmp_coord_array_2__[7] += (__x_xpd__[0][0] * __y_xpd__[2][1]);
				__tmp_coord_array_2__[8] += (__x_xpd__[0][0] * __y_xpd__[2][2]);
				__tmp_coord_array_2__[9] += (__x_xpd__[0][0] * __y_xpd__[2][3]);
				__tmp_coord_array_2__[10] += (__x_xpd__[0][0] * __y_xpd__[2][4]);
				__tmp_coord_array_2__[11] += (__x_xpd__[0][0] * __y_xpd__[2][5]);
				__tmp_coord_array_2__[12] += (__x_xpd__[0][0] * __y_xpd__[2][6]);
				__tmp_coord_array_2__[13] += (__x_xpd__[0][0] * __y_xpd__[2][7]);
				__tmp_coord_array_2__[14] += (__x_xpd__[0][0] * __y_xpd__[2][8]);
				__tmp_coord_array_2__[15] += (__x_xpd__[0][0] * __y_xpd__[2][9]);

			}
			if (((y.m_gu & 8) != 0)) {
				__tmp_coord_array_2__[16] += (__x_xpd__[0][0] * __y_xpd__[3][0]);
				__tmp_coord_array_2__[17] += (__x_xpd__[0][0] * __y_xpd__[3][1]);
				__tmp_coord_array_2__[18] += (__x_xpd__[0][0] * __y_xpd__[3][2]);
				__tmp_coord_array_2__[19] += (__x_xpd__[0][0] * __y_xpd__[3][3]);
				__tmp_coord_array_2__[20] += (__x_xpd__[0][0] * __y_xpd__[3][4]);
				__tmp_coord_array_2__[21] += (__x_xpd__[0][0] * __y_xpd__[3][5]);
				__tmp_coord_array_2__[22] += (__x_xpd__[0][0] * __y_xpd__[3][6]);
				__tmp_coord_array_2__[23] += (__x_xpd__[0][0] * __y_xpd__[3][7]);
				__tmp_coord_array_2__[24] += (__x_xpd__[0][0] * __y_xpd__[3][8]);
				__tmp_coord_array_2__[25] += (__x_xpd__[0][0] * __y_xpd__[3][9]);

			}
			if (((y.m_gu & 16) != 0)) {
				__tmp_coord_array_2__[26] += (__x_xpd__[0][0] * __y_xpd__[4][0]);
				__tmp_coord_array_2__[27] += (__x_xpd__[0][0] * __y_xpd__[4][1]);
				__tmp_coord_array_2__[28] += (__x_xpd__[0][0] * __y_xpd__[4][2]);
				__tmp_coord_array_2__[29] += (__x_xpd__[0][0] * __y_xpd__[4][3]);
				__tmp_coord_array_2__[30] += (__x_xpd__[0][0] * __y_xpd__[4][4]);

			}
			if (((y.m_gu & 32) != 0)) {
				__tmp_coord_array_2__[31] += (__x_xpd__[0][0] * __y_xpd__[5][0]);

			}

		}
		if (((x.m_gu & 2) != 0)) {
			if (((y.m_gu & 1) != 0)) {
				__tmp_coord_array_2__[1] += (__x_xpd__[1][0] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[2] += (__x_xpd__[1][1] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[3] += (__x_xpd__[1][2] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[4] += (__x_xpd__[1][3] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[5] += (__x_xpd__[1][4] * __y_xpd__[0][0]);

			}
			if (((y.m_gu & 2) != 0)) {
				__tmp_coord_array_2__[0] += ((__x_xpd__[1][3] * __y_xpd__[1][3]) + (__x_xpd__[1][1] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[1][0] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[1][0]) + (__x_xpd__[1][2] * __y_xpd__[1][2]));
				__tmp_coord_array_2__[6] += ((__x_xpd__[1][0] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[1][0]));
				__tmp_coord_array_2__[7] += ((__x_xpd__[1][0] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[1][0]));
				__tmp_coord_array_2__[8] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[1][0]) + (__x_xpd__[1][0] * __y_xpd__[1][3]));
				__tmp_coord_array_2__[9] += ((-1.0f * __x_xpd__[1][2] * __y_xpd__[1][1]) + (__x_xpd__[1][1] * __y_xpd__[1][2]));
				__tmp_coord_array_2__[10] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[1][2]) + (__x_xpd__[1][2] * __y_xpd__[1][3]));
				__tmp_coord_array_2__[11] += ((__x_xpd__[1][3] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[1][3]));
				__tmp_coord_array_2__[12] += ((__x_xpd__[1][1] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[1][1]));
				__tmp_coord_array_2__[13] += ((__x_xpd__[1][2] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[1][2]));
				__tmp_coord_array_2__[14] += ((__x_xpd__[1][3] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[1][3]));
				__tmp_coord_array_2__[15] += ((__x_xpd__[1][0] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[1][0]));

			}
			if (((y.m_gu & 4) != 0)) {
				__tmp_coord_array_2__[1] += ((-1.0f * __x_xpd__[1][2] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[2][2]) + (__x_xpd__[1][0] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[2][0]));
				__tmp_coord_array_2__[2] += ((-1.0f * __x_xpd__[1][2] * __y_xpd__[2][3]) + (__x_xpd__[1][3] * __y_xpd__[2][5]) + (__x_xpd__[1][0] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[2][0]));
				__tmp_coord_array_2__[3] += ((__x_xpd__[1][0] * __y_xpd__[2][7]) + (__x_xpd__[1][1] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[2][4]));
				__tmp_coord_array_2__[4] += ((__x_xpd__[1][0] * __y_xpd__[2][8]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[2][5]) + (__x_xpd__[1][2] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[2][2]));
				__tmp_coord_array_2__[5] += ((__x_xpd__[1][2] * __y_xpd__[2][7]) + (__x_xpd__[1][3] * __y_xpd__[2][8]) + (__x_xpd__[1][1] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[2][9]));
				__tmp_coord_array_2__[16] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[2][7]) + (__x_xpd__[1][4] * __y_xpd__[2][4]) + (__x_xpd__[1][2] * __y_xpd__[2][8]));
				__tmp_coord_array_2__[17] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[2][8]) + (__x_xpd__[1][4] * __y_xpd__[2][5]) + (__x_xpd__[1][3] * __y_xpd__[2][6]));
				__tmp_coord_array_2__[18] += ((-1.0f * __x_xpd__[1][2] * __y_xpd__[2][6]) + (__x_xpd__[1][1] * __y_xpd__[2][7]) + (__x_xpd__[1][4] * __y_xpd__[2][3]));
				__tmp_coord_array_2__[19] += ((__x_xpd__[1][0] * __y_xpd__[2][8]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[2][9]) + (__x_xpd__[1][4] * __y_xpd__[2][2]));
				__tmp_coord_array_2__[20] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[2][9]) + (__x_xpd__[1][0] * __y_xpd__[2][6]) + (__x_xpd__[1][4] * __y_xpd__[2][0]));
				__tmp_coord_array_2__[21] += ((__x_xpd__[1][4] * __y_xpd__[2][1]) + (__x_xpd__[1][0] * __y_xpd__[2][7]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[2][9]));
				__tmp_coord_array_2__[22] += ((-1.0f * __x_xpd__[1][2] * __y_xpd__[2][2]) + (__x_xpd__[1][0] * __y_xpd__[2][4]) + (__x_xpd__[1][3] * __y_xpd__[2][1]));
				__tmp_coord_array_2__[23] += ((__x_xpd__[1][3] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[1][0] * __y_xpd__[2][5]));
				__tmp_coord_array_2__[24] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[2][1]) + (__x_xpd__[1][2] * __y_xpd__[2][0]) + (__x_xpd__[1][0] * __y_xpd__[2][3]));
				__tmp_coord_array_2__[25] += ((__x_xpd__[1][1] * __y_xpd__[2][4]) + (__x_xpd__[1][2] * __y_xpd__[2][5]) + (__x_xpd__[1][3] * __y_xpd__[2][3]));

			}
			if (((y.m_gu & 8) != 0)) {
				__tmp_coord_array_2__[6] += ((__x_xpd__[1][2] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[1][0] * __y_xpd__[3][4]) + (__x_xpd__[1][3] * __y_xpd__[3][7]));
				__tmp_coord_array_2__[7] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[1][0] * __y_xpd__[3][5]) + (__x_xpd__[1][3] * __y_xpd__[3][6]));
				__tmp_coord_array_2__[8] += ((-1.0f * __x_xpd__[1][0] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[3][6]));
				__tmp_coord_array_2__[9] += ((-1.0f * __x_xpd__[1][0] * __y_xpd__[3][2]) + (__x_xpd__[1][3] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[3][8]));
				__tmp_coord_array_2__[10] += ((__x_xpd__[1][1] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[1][0] * __y_xpd__[3][0]));
				__tmp_coord_array_2__[11] += ((__x_xpd__[1][2] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[1][0] * __y_xpd__[3][1]) + (__x_xpd__[1][4] * __y_xpd__[3][7]));
				__tmp_coord_array_2__[12] += ((-1.0f * __x_xpd__[1][2] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[3][4]) + (__x_xpd__[1][3] * __y_xpd__[3][1]));
				__tmp_coord_array_2__[13] += ((__x_xpd__[1][1] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[3][0]));
				__tmp_coord_array_2__[14] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[3][1]) + (__x_xpd__[1][2] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[3][3]));
				__tmp_coord_array_2__[15] += ((-1.0f * __x_xpd__[1][2] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[3][3]));
				__tmp_coord_array_2__[26] += ((__x_xpd__[1][3] * __y_xpd__[3][2]) + (__x_xpd__[1][1] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[3][9]) + (__x_xpd__[1][2] * __y_xpd__[3][1]));
				__tmp_coord_array_2__[27] += ((-1.0f * __x_xpd__[1][4] * __y_xpd__[3][6]) + (__x_xpd__[1][3] * __y_xpd__[3][5]) + (__x_xpd__[1][0] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[3][3]));
				__tmp_coord_array_2__[28] += ((__x_xpd__[1][0] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[3][4]) + (__x_xpd__[1][1] * __y_xpd__[3][3]) + (__x_xpd__[1][4] * __y_xpd__[3][7]));
				__tmp_coord_array_2__[29] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[3][5]) + (__x_xpd__[1][2] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[3][8]) + (__x_xpd__[1][0] * __y_xpd__[3][2]));
				__tmp_coord_array_2__[30] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[3][6]) + (__x_xpd__[1][2] * __y_xpd__[3][7]) + (__x_xpd__[1][0] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[3][8]));

			}
			if (((y.m_gu & 16) != 0)) {
				__tmp_coord_array_2__[16] += ((-1.0f * __x_xpd__[1][4] * __y_xpd__[4][1]) + (__x_xpd__[1][1] * __y_xpd__[4][0]));
				__tmp_coord_array_2__[17] += ((-1.0f * __x_xpd__[1][4] * __y_xpd__[4][2]) + (__x_xpd__[1][2] * __y_xpd__[4][0]));
				__tmp_coord_array_2__[18] += ((__x_xpd__[1][3] * __y_xpd__[4][0]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[4][3]));
				__tmp_coord_array_2__[19] += ((__x_xpd__[1][1] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[4][1]));
				__tmp_coord_array_2__[20] += ((__x_xpd__[1][2] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[4][2]));
				__tmp_coord_array_2__[21] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[4][3]) + (__x_xpd__[1][3] * __y_xpd__[4][1]));
				__tmp_coord_array_2__[22] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[4][4]) + (__x_xpd__[1][0] * __y_xpd__[4][1]));
				__tmp_coord_array_2__[23] += ((__x_xpd__[1][2] * __y_xpd__[4][4]) + (-1.0f * __x_xpd__[1][0] * __y_xpd__[4][2]));
				__tmp_coord_array_2__[24] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[4][4]) + (__x_xpd__[1][0] * __y_xpd__[4][3]));
				__tmp_coord_array_2__[25] += ((-1.0f * __x_xpd__[1][4] * __y_xpd__[4][4]) + (__x_xpd__[1][0] * __y_xpd__[4][0]));
				__tmp_coord_array_2__[31] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[4][1]) + (__x_xpd__[1][4] * __y_xpd__[4][4]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[4][2]) + (__x_xpd__[1][0] * __y_xpd__[4][0]));

			}
			if (((y.m_gu & 32) != 0)) {
				__tmp_coord_array_2__[26] += (-1.0f * __x_xpd__[1][4] * __y_xpd__[5][0]);
				__tmp_coord_array_2__[27] += (-1.0f * __x_xpd__[1][1] * __y_xpd__[5][0]);
				__tmp_coord_array_2__[28] += (-1.0f * __x_xpd__[1][2] * __y_xpd__[5][0]);
				__tmp_coord_array_2__[29] += (-1.0f * __x_xpd__[1][3] * __y_xpd__[5][0]);
				__tmp_coord_array_2__[30] += (-1.0f * __x_xpd__[1][0] * __y_xpd__[5][0]);

			}

		}
		if (((x.m_gu & 4) != 0)) {
			if (((y.m_gu & 1) != 0)) {
				__tmp_coord_array_2__[6] += (__x_xpd__[2][0] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[7] += (__x_xpd__[2][1] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[8] += (__x_xpd__[2][2] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[9] += (__x_xpd__[2][3] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[10] += (__x_xpd__[2][4] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[11] += (__x_xpd__[2][5] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[12] += (__x_xpd__[2][6] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[13] += (__x_xpd__[2][7] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[14] += (__x_xpd__[2][8] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[15] += (__x_xpd__[2][9] * __y_xpd__[0][0]);

			}
			if (((y.m_gu & 2) != 0)) {
				__tmp_coord_array_2__[1] += ((__x_xpd__[2][1] * __y_xpd__[1][2]) + (__x_xpd__[2][2] * __y_xpd__[1][3]) + (__x_xpd__[2][0] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[1][0]));
				__tmp_coord_array_2__[2] += ((-1.0f * __x_xpd__[2][5] * __y_xpd__[1][3]) + (__x_xpd__[2][0] * __y_xpd__[1][4]) + (__x_xpd__[2][3] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[1][0]));
				__tmp_coord_array_2__[3] += ((-1.0f * __x_xpd__[2][3] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[1][0]) + (__x_xpd__[2][4] * __y_xpd__[1][3]) + (__x_xpd__[2][1] * __y_xpd__[1][4]));
				__tmp_coord_array_2__[4] += ((-1.0f * __x_xpd__[2][8] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[1][2]) + (__x_xpd__[2][2] * __y_xpd__[1][4]) + (__x_xpd__[2][5] * __y_xpd__[1][1]));
				__tmp_coord_array_2__[5] += ((-1.0f * __x_xpd__[2][7] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[1][3]) + (__x_xpd__[2][9] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[1][1]));
				__tmp_coord_array_2__[16] += ((__x_xpd__[2][8] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[1][3]) + (__x_xpd__[2][4] * __y_xpd__[1][4]));
				__tmp_coord_array_2__[17] += ((__x_xpd__[2][5] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[1][1]) + (__x_xpd__[2][6] * __y_xpd__[1][3]));
				__tmp_coord_array_2__[18] += ((-1.0f * __x_xpd__[2][6] * __y_xpd__[1][2]) + (__x_xpd__[2][3] * __y_xpd__[1][4]) + (__x_xpd__[2][7] * __y_xpd__[1][1]));
				__tmp_coord_array_2__[19] += ((__x_xpd__[2][8] * __y_xpd__[1][0]) + (__x_xpd__[2][2] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[1][3]));
				__tmp_coord_array_2__[20] += ((-1.0f * __x_xpd__[2][9] * __y_xpd__[1][1]) + (__x_xpd__[2][0] * __y_xpd__[1][4]) + (__x_xpd__[2][6] * __y_xpd__[1][0]));
				__tmp_coord_array_2__[21] += ((__x_xpd__[2][7] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[1][2]) + (__x_xpd__[2][1] * __y_xpd__[1][4]));
				__tmp_coord_array_2__[22] += ((__x_xpd__[2][4] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[1][2]) + (__x_xpd__[2][1] * __y_xpd__[1][3]));
				__tmp_coord_array_2__[23] += ((-1.0f * __x_xpd__[2][2] * __y_xpd__[1][1]) + (__x_xpd__[2][0] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[1][0]));
				__tmp_coord_array_2__[24] += ((__x_xpd__[2][0] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[1][1]) + (__x_xpd__[2][3] * __y_xpd__[1][0]));
				__tmp_coord_array_2__[25] += ((__x_xpd__[2][4] * __y_xpd__[1][1]) + (__x_xpd__[2][3] * __y_xpd__[1][3]) + (__x_xpd__[2][5] * __y_xpd__[1][2]));

			}
			if (((y.m_gu & 4) != 0)) {
				__tmp_coord_array_2__[0] += ((-1.0f * __x_xpd__[2][5] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[2][8]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[2][7]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[2][1]) + (__x_xpd__[2][9] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[2][4]));
				__tmp_coord_array_2__[6] += ((__x_xpd__[2][3] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[2][3]) + (__x_xpd__[2][2] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[2][0]) + (__x_xpd__[2][0] * __y_xpd__[2][9]));
				__tmp_coord_array_2__[7] += ((__x_xpd__[2][0] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[2][1]) + (__x_xpd__[2][4] * __y_xpd__[2][2]) + (__x_xpd__[2][1] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[2][4]));
				__tmp_coord_array_2__[8] += ((-1.0f * __x_xpd__[2][9] * __y_xpd__[2][2]) + (__x_xpd__[2][1] * __y_xpd__[2][4]) + (__x_xpd__[2][2] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[2][5]) + (__x_xpd__[2][5] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[2][1]));
				__tmp_coord_array_2__[9] += ((-1.0f * __x_xpd__[2][6] * __y_xpd__[2][1]) + (__x_xpd__[2][7] * __y_xpd__[2][0]) + (__x_xpd__[2][1] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[2][7]) + (__x_xpd__[2][5] * __y_xpd__[2][4]));
				__tmp_coord_array_2__[10] += ((__x_xpd__[2][8] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[2][8]) + (__x_xpd__[2][3] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[2][2]) + (__x_xpd__[2][2] * __y_xpd__[2][7]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[2][3]));
				__tmp_coord_array_2__[11] += ((-1.0f * __x_xpd__[2][2] * __y_xpd__[2][6]) + (__x_xpd__[2][0] * __y_xpd__[2][8]) + (__x_xpd__[2][4] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[2][0]) + (__x_xpd__[2][6] * __y_xpd__[2][2]));
				__tmp_coord_array_2__[12] += ((-1.0f * __x_xpd__[2][5] * __y_xpd__[2][8]) + (__x_xpd__[2][9] * __y_xpd__[2][6]) + (__x_xpd__[2][8] * __y_xpd__[2][5]) + (__x_xpd__[2][3] * __y_xpd__[2][7]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[2][3]));
				__tmp_coord_array_2__[13] += ((__x_xpd__[2][6] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[2][4]) + (__x_xpd__[2][9] * __y_xpd__[2][7]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[2][9]) + (__x_xpd__[2][4] * __y_xpd__[2][8]));
				__tmp_coord_array_2__[14] += ((__x_xpd__[2][7] * __y_xpd__[2][4]) + (__x_xpd__[2][5] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[2][7]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[2][5]) + (__x_xpd__[2][9] * __y_xpd__[2][8]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[2][9]));
				__tmp_coord_array_2__[15] += ((-1.0f * __x_xpd__[2][8] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[2][0]) + (__x_xpd__[2][2] * __y_xpd__[2][8]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[2][1]) + (__x_xpd__[2][1] * __y_xpd__[2][7]) + (__x_xpd__[2][0] * __y_xpd__[2][6]));
				__tmp_coord_array_2__[26] += ((__x_xpd__[2][6] * __y_xpd__[2][4]) + (__x_xpd__[2][3] * __y_xpd__[2][8]) + (__x_xpd__[2][8] * __y_xpd__[2][3]) + (__x_xpd__[2][5] * __y_xpd__[2][7]) + (__x_xpd__[2][7] * __y_xpd__[2][5]) + (__x_xpd__[2][4] * __y_xpd__[2][6]));
				__tmp_coord_array_2__[27] += ((__x_xpd__[2][4] * __y_xpd__[2][9]) + (__x_xpd__[2][1] * __y_xpd__[2][8]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[2][7]) + (__x_xpd__[2][8] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[2][2]) + (__x_xpd__[2][9] * __y_xpd__[2][4]));
				__tmp_coord_array_2__[28] += ((__x_xpd__[2][2] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[2][0]) + (__x_xpd__[2][6] * __y_xpd__[2][2]) + (__x_xpd__[2][9] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[2][8]) + (__x_xpd__[2][5] * __y_xpd__[2][9]));
				__tmp_coord_array_2__[29] += ((-1.0f * __x_xpd__[2][6] * __y_xpd__[2][1]) + (__x_xpd__[2][7] * __y_xpd__[2][0]) + (__x_xpd__[2][9] * __y_xpd__[2][3]) + (__x_xpd__[2][3] * __y_xpd__[2][9]) + (__x_xpd__[2][0] * __y_xpd__[2][7]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[2][6]));
				__tmp_coord_array_2__[30] += ((__x_xpd__[2][2] * __y_xpd__[2][3]) + (__x_xpd__[2][5] * __y_xpd__[2][1]) + (__x_xpd__[2][1] * __y_xpd__[2][5]) + (__x_xpd__[2][0] * __y_xpd__[2][4]) + (__x_xpd__[2][4] * __y_xpd__[2][0]) + (__x_xpd__[2][3] * __y_xpd__[2][2]));

			}
			if (((y.m_gu & 8) != 0)) {
				__tmp_coord_array_2__[1] += ((-1.0f * __x_xpd__[2][2] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[3][6]) + (__x_xpd__[2][5] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[3][4]));
				__tmp_coord_array_2__[2] += ((-1.0f * __x_xpd__[2][4] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[3][4]) + (__x_xpd__[2][8] * __y_xpd__[3][7]) + (__x_xpd__[2][2] * __y_xpd__[3][1]) + (__x_xpd__[2][7] * __y_xpd__[3][8]));
				__tmp_coord_array_2__[3] += ((-1.0f * __x_xpd__[2][2] * __y_xpd__[3][0]) + (__x_xpd__[2][0] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[3][8]) + (__x_xpd__[2][8] * __y_xpd__[3][6]));
				__tmp_coord_array_2__[4] += ((__x_xpd__[2][1] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[3][3]));
				__tmp_coord_array_2__[5] += ((-1.0f * __x_xpd__[2][8] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[3][1]));
				__tmp_coord_array_2__[16] += ((-1.0f * __x_xpd__[2][6] * __y_xpd__[3][9]) + (__x_xpd__[2][8] * __y_xpd__[3][5]) + (__x_xpd__[2][3] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[3][3]) + (__x_xpd__[2][9] * __y_xpd__[3][0]));
				__tmp_coord_array_2__[17] += ((__x_xpd__[2][9] * __y_xpd__[3][1]) + (__x_xpd__[2][6] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[3][9]) + (__x_xpd__[2][4] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[3][0]));
				__tmp_coord_array_2__[18] += ((-1.0f * __x_xpd__[2][4] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[3][9]) + (__x_xpd__[2][9] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[3][5]) + (__x_xpd__[2][7] * __y_xpd__[3][4]) + (__x_xpd__[2][5] * __y_xpd__[3][0]));
				__tmp_coord_array_2__[19] += ((__x_xpd__[2][1] * __y_xpd__[3][0]) + (__x_xpd__[2][7] * __y_xpd__[3][6]) + (__x_xpd__[2][6] * __y_xpd__[3][7]) + (__x_xpd__[2][5] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[3][5]));
				__tmp_coord_array_2__[20] += ((-1.0f * __x_xpd__[2][5] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[3][2]) + (__x_xpd__[2][3] * __y_xpd__[3][5]) + (__x_xpd__[2][2] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[3][8]));
				__tmp_coord_array_2__[21] += ((__x_xpd__[2][6] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[3][0]) + (__x_xpd__[2][4] * __y_xpd__[3][3]) + (__x_xpd__[2][0] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[3][6]));
				__tmp_coord_array_2__[22] += ((__x_xpd__[2][2] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[3][8]) + (__x_xpd__[2][0] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[3][7]));
				__tmp_coord_array_2__[23] += ((__x_xpd__[2][2] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[3][9]) + (__x_xpd__[2][3] * __y_xpd__[3][6]));
				__tmp_coord_array_2__[24] += ((__x_xpd__[2][2] * __y_xpd__[3][9]) + (__x_xpd__[2][1] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[3][5]) + (__x_xpd__[2][4] * __y_xpd__[3][7]) + (__x_xpd__[2][5] * __y_xpd__[3][6]));
				__tmp_coord_array_2__[25] += ((__x_xpd__[2][7] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[3][8]) + (__x_xpd__[2][1] * __y_xpd__[3][1]) + (__x_xpd__[2][0] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[3][6]) + (__x_xpd__[2][2] * __y_xpd__[3][2]));
				__tmp_coord_array_2__[31] += ((__x_xpd__[2][6] * __y_xpd__[3][6]) + (__x_xpd__[2][8] * __y_xpd__[3][8]) + (__x_xpd__[2][5] * __y_xpd__[3][5]) + (__x_xpd__[2][4] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[3][7]) + (__x_xpd__[2][1] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[3][9]) + (__x_xpd__[2][0] * __y_xpd__[3][0]) + (__x_xpd__[2][2] * __y_xpd__[3][2]) + (__x_xpd__[2][3] * __y_xpd__[3][3]));

			}
			if (((y.m_gu & 16) != 0)) {
				__tmp_coord_array_2__[6] += ((-1.0f * __x_xpd__[2][1] * __y_xpd__[4][3]) + (__x_xpd__[2][2] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[4][4]));
				__tmp_coord_array_2__[7] += ((-1.0f * __x_xpd__[2][5] * __y_xpd__[4][4]) + (__x_xpd__[2][0] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[4][1]));
				__tmp_coord_array_2__[8] += ((-1.0f * __x_xpd__[2][0] * __y_xpd__[4][2]) + (__x_xpd__[2][1] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[4][4]));
				__tmp_coord_array_2__[9] += ((-1.0f * __x_xpd__[2][8] * __y_xpd__[4][4]) + (__x_xpd__[2][9] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[4][0]));
				__tmp_coord_array_2__[10] += ((-1.0f * __x_xpd__[2][6] * __y_xpd__[4][4]) + (__x_xpd__[2][9] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[4][0]));
				__tmp_coord_array_2__[11] += ((-1.0f * __x_xpd__[2][1] * __y_xpd__[4][0]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[4][4]) + (__x_xpd__[2][9] * __y_xpd__[4][2]));
				__tmp_coord_array_2__[12] += ((__x_xpd__[2][7] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[4][0]));
				__tmp_coord_array_2__[13] += ((__x_xpd__[2][8] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[4][0]));
				__tmp_coord_array_2__[14] += ((-1.0f * __x_xpd__[2][7] * __y_xpd__[4][1]) + (__x_xpd__[2][6] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[4][0]));
				__tmp_coord_array_2__[15] += ((-1.0f * __x_xpd__[2][5] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[4][3]));
				__tmp_coord_array_2__[26] += ((-1.0f * __x_xpd__[2][8] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[4][1]) + (__x_xpd__[2][9] * __y_xpd__[4][0]));
				__tmp_coord_array_2__[27] += ((-1.0f * __x_xpd__[2][6] * __y_xpd__[4][4]) + (__x_xpd__[2][0] * __y_xpd__[4][0]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[4][3]) + (__x_xpd__[2][3] * __y_xpd__[4][2]));
				__tmp_coord_array_2__[28] += ((-1.0f * __x_xpd__[2][3] * __y_xpd__[4][1]) + (__x_xpd__[2][4] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[4][4]) + (__x_xpd__[2][1] * __y_xpd__[4][0]));
				__tmp_coord_array_2__[29] += ((-1.0f * __x_xpd__[2][4] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[4][4]) + (__x_xpd__[2][5] * __y_xpd__[4][1]) + (__x_xpd__[2][2] * __y_xpd__[4][0]));
				__tmp_coord_array_2__[30] += ((-1.0f * __x_xpd__[2][9] * __y_xpd__[4][4]) + (__x_xpd__[2][0] * __y_xpd__[4][1]) + (__x_xpd__[2][1] * __y_xpd__[4][2]) + (__x_xpd__[2][2] * __y_xpd__[4][3]));

			}
			if (((y.m_gu & 32) != 0)) {
				__tmp_coord_array_2__[16] += (-1.0f * __x_xpd__[2][6] * __y_xpd__[5][0]);
				__tmp_coord_array_2__[17] += (-1.0f * __x_xpd__[2][7] * __y_xpd__[5][0]);
				__tmp_coord_array_2__[18] += (-1.0f * __x_xpd__[2][8] * __y_xpd__[5][0]);
				__tmp_coord_array_2__[19] += (-1.0f * __x_xpd__[2][3] * __y_xpd__[5][0]);
				__tmp_coord_array_2__[20] += (-1.0f * __x_xpd__[2][4] * __y_xpd__[5][0]);
				__tmp_coord_array_2__[21] += (-1.0f * __x_xpd__[2][5] * __y_xpd__[5][0]);
				__tmp_coord_array_2__[22] += (-1.0f * __x_xpd__[2][0] * __y_xpd__[5][0]);
				__tmp_coord_array_2__[23] += (__x_xpd__[2][1] * __y_xpd__[5][0]);
				__tmp_coord_array_2__[24] += (-1.0f * __x_xpd__[2][2] * __y_xpd__[5][0]);
				__tmp_coord_array_2__[25] += (-1.0f * __x_xpd__[2][9] * __y_xpd__[5][0]);

			}

		}
		if (((x.m_gu & 8) != 0)) {
			if (((y.m_gu & 1) != 0)) {
				__tmp_coord_array_2__[16] += (__x_xpd__[3][0] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[17] += (__x_xpd__[3][1] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[18] += (__x_xpd__[3][2] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[19] += (__x_xpd__[3][3] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[20] += (__x_xpd__[3][4] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[21] += (__x_xpd__[3][5] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[22] += (__x_xpd__[3][6] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[23] += (__x_xpd__[3][7] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[24] += (__x_xpd__[3][8] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[25] += (__x_xpd__[3][9] * __y_xpd__[0][0]);

			}
			if (((y.m_gu & 2) != 0)) {
				__tmp_coord_array_2__[6] += ((__x_xpd__[3][7] * __y_xpd__[1][3]) + (__x_xpd__[3][8] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[1][0]));
				__tmp_coord_array_2__[7] += ((-1.0f * __x_xpd__[3][8] * __y_xpd__[1][1]) + (__x_xpd__[3][6] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[1][0]));
				__tmp_coord_array_2__[8] += ((-1.0f * __x_xpd__[3][6] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[1][1]));
				__tmp_coord_array_2__[9] += ((-1.0f * __x_xpd__[3][2] * __y_xpd__[1][0]) + (__x_xpd__[3][9] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[3][8] * __y_xpd__[1][4]));
				__tmp_coord_array_2__[10] += ((-1.0f * __x_xpd__[3][6] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[1][0]) + (__x_xpd__[3][9] * __y_xpd__[1][1]));
				__tmp_coord_array_2__[11] += ((__x_xpd__[3][7] * __y_xpd__[1][4]) + (__x_xpd__[3][9] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[1][0]));
				__tmp_coord_array_2__[12] += ((-1.0f * __x_xpd__[3][2] * __y_xpd__[1][2]) + (__x_xpd__[3][1] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[1][4]));
				__tmp_coord_array_2__[13] += ((-1.0f * __x_xpd__[3][0] * __y_xpd__[1][3]) + (__x_xpd__[3][2] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[1][4]));
				__tmp_coord_array_2__[14] += ((__x_xpd__[3][0] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[1][4]));
				__tmp_coord_array_2__[15] += ((-1.0f * __x_xpd__[3][3] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[1][2]));
				__tmp_coord_array_2__[26] += ((-1.0f * __x_xpd__[3][1] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[1][3]) + (__x_xpd__[3][9] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[1][1]));
				__tmp_coord_array_2__[27] += ((__x_xpd__[3][6] * __y_xpd__[1][4]) + (__x_xpd__[3][3] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[1][0]));
				__tmp_coord_array_2__[28] += ((__x_xpd__[3][4] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[1][0]));
				__tmp_coord_array_2__[29] += ((-1.0f * __x_xpd__[3][2] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[1][2]) + (__x_xpd__[3][8] * __y_xpd__[1][4]) + (__x_xpd__[3][5] * __y_xpd__[1][1]));
				__tmp_coord_array_2__[30] += ((__x_xpd__[3][6] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[1][0]) + (__x_xpd__[3][8] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[1][2]));

			}
			if (((y.m_gu & 4) != 0)) {
				__tmp_coord_array_2__[1] += ((-1.0f * __x_xpd__[3][6] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[3][8] * __y_xpd__[2][3]) + (__x_xpd__[3][7] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[2][0]));
				__tmp_coord_array_2__[2] += ((-1.0f * __x_xpd__[3][2] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[2][9]) + (__x_xpd__[3][8] * __y_xpd__[2][7]) + (__x_xpd__[3][1] * __y_xpd__[2][2]) + (__x_xpd__[3][7] * __y_xpd__[2][8]));
				__tmp_coord_array_2__[3] += ((__x_xpd__[3][6] * __y_xpd__[2][8]) + (__x_xpd__[3][2] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[3][8] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[2][9]));
				__tmp_coord_array_2__[4] += ((-1.0f * __x_xpd__[3][3] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[2][0]) + (__x_xpd__[3][0] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[2][7]));
				__tmp_coord_array_2__[5] += ((-1.0f * __x_xpd__[3][0] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[2][7]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[2][8]));
				__tmp_coord_array_2__[16] += ((__x_xpd__[3][9] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[2][3]) + (__x_xpd__[3][3] * __y_xpd__[2][7]) + (__x_xpd__[3][2] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[2][8]));
				__tmp_coord_array_2__[17] += ((-1.0f * __x_xpd__[3][1] * __y_xpd__[2][9]) + (__x_xpd__[3][0] * __y_xpd__[2][3]) + (__x_xpd__[3][4] * __y_xpd__[2][8]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[2][4]) + (__x_xpd__[3][9] * __y_xpd__[2][7]));
				__tmp_coord_array_2__[18] += ((-1.0f * __x_xpd__[3][4] * __y_xpd__[2][7]) + (__x_xpd__[3][5] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[2][9]) + (__x_xpd__[3][9] * __y_xpd__[2][8]) + (__x_xpd__[3][1] * __y_xpd__[2][4]));
				__tmp_coord_array_2__[19] += ((__x_xpd__[3][1] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[2][6]) + (__x_xpd__[3][5] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[2][7]));
				__tmp_coord_array_2__[20] += ((-1.0f * __x_xpd__[3][1] * __y_xpd__[2][2]) + (__x_xpd__[3][8] * __y_xpd__[2][7]) + (__x_xpd__[3][3] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[2][3]) + (__x_xpd__[3][2] * __y_xpd__[2][1]) + (__x_xpd__[3][7] * __y_xpd__[2][8]));
				__tmp_coord_array_2__[21] += ((__x_xpd__[3][4] * __y_xpd__[2][3]) + (__x_xpd__[3][0] * __y_xpd__[2][2]) + (__x_xpd__[3][6] * __y_xpd__[2][8]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[3][8] * __y_xpd__[2][6]));
				__tmp_coord_array_2__[22] += ((-1.0f * __x_xpd__[3][5] * __y_xpd__[2][2]) + (__x_xpd__[3][6] * __y_xpd__[2][9]) + (__x_xpd__[3][3] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[2][0]) + (__x_xpd__[3][7] * __y_xpd__[2][3]) + (__x_xpd__[3][8] * __y_xpd__[2][5]));
				__tmp_coord_array_2__[23] += ((__x_xpd__[3][7] * __y_xpd__[2][9]) + (__x_xpd__[3][3] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[2][2]) + (__x_xpd__[3][9] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[2][3]) + (__x_xpd__[3][8] * __y_xpd__[2][4]));
				__tmp_coord_array_2__[24] += ((-1.0f * __x_xpd__[3][9] * __y_xpd__[2][2]) + (__x_xpd__[3][8] * __y_xpd__[2][9]) + (__x_xpd__[3][5] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[2][4]));
				__tmp_coord_array_2__[25] += ((__x_xpd__[3][8] * __y_xpd__[2][8]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[2][7]) + (__x_xpd__[3][6] * __y_xpd__[2][6]));
				__tmp_coord_array_2__[31] += ((__x_xpd__[3][0] * __y_xpd__[2][0]) + (__x_xpd__[3][5] * __y_xpd__[2][5]) + (__x_xpd__[3][8] * __y_xpd__[2][8]) + (__x_xpd__[3][2] * __y_xpd__[2][2]) + (__x_xpd__[3][4] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[2][7]) + (__x_xpd__[3][1] * __y_xpd__[2][1]) + (__x_xpd__[3][3] * __y_xpd__[2][3]) + (__x_xpd__[3][6] * __y_xpd__[2][6]));

			}
			if (((y.m_gu & 8) != 0)) {
				__tmp_coord_array_2__[0] += ((__x_xpd__[3][4] * __y_xpd__[3][4]) + (__x_xpd__[3][6] * __y_xpd__[3][0]) + (__x_xpd__[3][2] * __y_xpd__[3][8]) + (__x_xpd__[3][0] * __y_xpd__[3][6]) + (__x_xpd__[3][8] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[3][9]) + (__x_xpd__[3][5] * __y_xpd__[3][5]) + (__x_xpd__[3][3] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[3][1]));
				__tmp_coord_array_2__[6] += ((__x_xpd__[3][3] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[3][8] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[3][9]) + (__x_xpd__[3][9] * __y_xpd__[3][6]) + (__x_xpd__[3][5] * __y_xpd__[3][8]));
				__tmp_coord_array_2__[7] += ((-1.0f * __x_xpd__[3][6] * __y_xpd__[3][3]) + (__x_xpd__[3][7] * __y_xpd__[3][9]) + (__x_xpd__[3][8] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[3][7]) + (__x_xpd__[3][3] * __y_xpd__[3][6]));
				__tmp_coord_array_2__[8] += ((__x_xpd__[3][9] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[3][6]) + (__x_xpd__[3][7] * __y_xpd__[3][4]) + (__x_xpd__[3][6] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[3][8] * __y_xpd__[3][9]));
				__tmp_coord_array_2__[9] += ((__x_xpd__[3][6] * __y_xpd__[3][1]) + (__x_xpd__[3][4] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[3][4]) + (__x_xpd__[3][7] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[3][6]));
				__tmp_coord_array_2__[10] += ((-1.0f * __x_xpd__[3][3] * __y_xpd__[3][5]) + (__x_xpd__[3][5] * __y_xpd__[3][3]) + (__x_xpd__[3][1] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[3][8] * __y_xpd__[3][1]) + (__x_xpd__[3][2] * __y_xpd__[3][7]));
				__tmp_coord_array_2__[11] += ((__x_xpd__[3][3] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[3][8]) + (__x_xpd__[3][2] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[3][3]) + (__x_xpd__[3][8] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[3][2]));
				__tmp_coord_array_2__[12] += ((__x_xpd__[3][1] * __y_xpd__[3][3]) + (__x_xpd__[3][0] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[3][1]) + (__x_xpd__[3][5] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[3][5]));
				__tmp_coord_array_2__[13] += ((-1.0f * __x_xpd__[3][0] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[3][2]) + (__x_xpd__[3][1] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[3][1]) + (__x_xpd__[3][3] * __y_xpd__[3][0]) + (__x_xpd__[3][2] * __y_xpd__[3][4]));
				__tmp_coord_array_2__[14] += ((-1.0f * __x_xpd__[3][1] * __y_xpd__[3][4]) + (__x_xpd__[3][2] * __y_xpd__[3][9]) + (__x_xpd__[3][4] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[3][0]) + (__x_xpd__[3][0] * __y_xpd__[3][5]));
				__tmp_coord_array_2__[15] += ((__x_xpd__[3][2] * __y_xpd__[3][8]) + (__x_xpd__[3][0] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[3][0]) + (__x_xpd__[3][7] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[3][8] * __y_xpd__[3][2]));
				__tmp_coord_array_2__[26] += ((-1.0f * __x_xpd__[3][2] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[3][1]));
				__tmp_coord_array_2__[27] += ((__x_xpd__[3][7] * __y_xpd__[3][2]) + (__x_xpd__[3][1] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[3][9]) + (__x_xpd__[3][8] * __y_xpd__[3][1]) + (__x_xpd__[3][2] * __y_xpd__[3][7]));
				__tmp_coord_array_2__[28] += ((-1.0f * __x_xpd__[3][0] * __y_xpd__[3][8]) + (__x_xpd__[3][2] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[3][9]) + (__x_xpd__[3][6] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[3][8] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[3][5]));
				__tmp_coord_array_2__[29] += ((-1.0f * __x_xpd__[3][3] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[3][1]));
				__tmp_coord_array_2__[30] += ((__x_xpd__[3][7] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[3][8] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[3][8]) + (__x_xpd__[3][5] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[3][4]));

			}
			if (((y.m_gu & 16) != 0)) {
				__tmp_coord_array_2__[1] += ((-1.0f * __x_xpd__[3][8] * __y_xpd__[4][3]) + (__x_xpd__[3][7] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[4][1]) + (__x_xpd__[3][9] * __y_xpd__[4][4]));
				__tmp_coord_array_2__[2] += ((-1.0f * __x_xpd__[3][3] * __y_xpd__[4][2]) + (__x_xpd__[3][5] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[4][0]) + (__x_xpd__[3][0] * __y_xpd__[4][4]));
				__tmp_coord_array_2__[3] += ((__x_xpd__[3][7] * __y_xpd__[4][0]) + (__x_xpd__[3][3] * __y_xpd__[4][1]) + (__x_xpd__[3][1] * __y_xpd__[4][4]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[4][3]));
				__tmp_coord_array_2__[4] += ((__x_xpd__[3][4] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[3][8] * __y_xpd__[4][0]) + (__x_xpd__[3][2] * __y_xpd__[4][4]));
				__tmp_coord_array_2__[5] += ((__x_xpd__[3][2] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[4][0]) + (__x_xpd__[3][0] * __y_xpd__[4][1]) + (__x_xpd__[3][1] * __y_xpd__[4][2]));
				__tmp_coord_array_2__[16] += ((-1.0f * __x_xpd__[3][4] * __y_xpd__[4][0]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[4][2]) + (__x_xpd__[3][1] * __y_xpd__[4][3]));
				__tmp_coord_array_2__[17] += ((__x_xpd__[3][2] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[4][0]));
				__tmp_coord_array_2__[18] += ((-1.0f * __x_xpd__[3][3] * __y_xpd__[4][0]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[4][1]) + (__x_xpd__[3][0] * __y_xpd__[4][2]));
				__tmp_coord_array_2__[19] += ((-1.0f * __x_xpd__[3][2] * __y_xpd__[4][4]) + (__x_xpd__[3][9] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[3][8] * __y_xpd__[4][0]));
				__tmp_coord_array_2__[20] += ((-1.0f * __x_xpd__[3][6] * __y_xpd__[4][0]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[4][4]) + (__x_xpd__[3][9] * __y_xpd__[4][1]));
				__tmp_coord_array_2__[21] += ((__x_xpd__[3][7] * __y_xpd__[4][0]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[4][4]) + (__x_xpd__[3][9] * __y_xpd__[4][2]));
				__tmp_coord_array_2__[22] += ((__x_xpd__[3][7] * __y_xpd__[4][3]) + (__x_xpd__[3][8] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[4][4]));
				__tmp_coord_array_2__[23] += ((__x_xpd__[3][5] * __y_xpd__[4][4]) + (__x_xpd__[3][8] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[4][3]));
				__tmp_coord_array_2__[24] += ((-1.0f * __x_xpd__[3][7] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[4][4]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[4][2]));
				__tmp_coord_array_2__[25] += ((-1.0f * __x_xpd__[3][4] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[4][3]));

			}
			if (((y.m_gu & 32) != 0)) {
				__tmp_coord_array_2__[6] += (__x_xpd__[3][6] * __y_xpd__[5][0]);
				__tmp_coord_array_2__[7] += (-1.0f * __x_xpd__[3][7] * __y_xpd__[5][0]);
				__tmp_coord_array_2__[8] += (__x_xpd__[3][8] * __y_xpd__[5][0]);
				__tmp_coord_array_2__[9] += (__x_xpd__[3][3] * __y_xpd__[5][0]);
				__tmp_coord_array_2__[10] += (__x_xpd__[3][4] * __y_xpd__[5][0]);
				__tmp_coord_array_2__[11] += (__x_xpd__[3][5] * __y_xpd__[5][0]);
				__tmp_coord_array_2__[12] += (__x_xpd__[3][0] * __y_xpd__[5][0]);
				__tmp_coord_array_2__[13] += (__x_xpd__[3][1] * __y_xpd__[5][0]);
				__tmp_coord_array_2__[14] += (__x_xpd__[3][2] * __y_xpd__[5][0]);
				__tmp_coord_array_2__[15] += (__x_xpd__[3][9] * __y_xpd__[5][0]);

			}

		}
		if (((x.m_gu & 16) != 0)) {
			if (((y.m_gu & 1) != 0)) {
				__tmp_coord_array_2__[26] += (__x_xpd__[4][0] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[27] += (__x_xpd__[4][1] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[28] += (__x_xpd__[4][2] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[29] += (__x_xpd__[4][3] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[30] += (__x_xpd__[4][4] * __y_xpd__[0][0]);

			}
			if (((y.m_gu & 2) != 0)) {
				__tmp_coord_array_2__[16] += ((__x_xpd__[4][1] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[4][0] * __y_xpd__[1][1]));
				__tmp_coord_array_2__[17] += ((__x_xpd__[4][2] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[4][0] * __y_xpd__[1][2]));
				__tmp_coord_array_2__[18] += ((-1.0f * __x_xpd__[4][0] * __y_xpd__[1][3]) + (__x_xpd__[4][3] * __y_xpd__[1][4]));
				__tmp_coord_array_2__[19] += ((__x_xpd__[4][1] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[4][2] * __y_xpd__[1][1]));
				__tmp_coord_array_2__[20] += ((__x_xpd__[4][2] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[4][3] * __y_xpd__[1][2]));
				__tmp_coord_array_2__[21] += ((__x_xpd__[4][3] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[4][1] * __y_xpd__[1][3]));
				__tmp_coord_array_2__[22] += ((-1.0f * __x_xpd__[4][1] * __y_xpd__[1][0]) + (__x_xpd__[4][4] * __y_xpd__[1][1]));
				__tmp_coord_array_2__[23] += ((__x_xpd__[4][2] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[4][4] * __y_xpd__[1][2]));
				__tmp_coord_array_2__[24] += ((-1.0f * __x_xpd__[4][3] * __y_xpd__[1][0]) + (__x_xpd__[4][4] * __y_xpd__[1][3]));
				__tmp_coord_array_2__[25] += ((__x_xpd__[4][4] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[4][0] * __y_xpd__[1][0]));
				__tmp_coord_array_2__[31] += ((__x_xpd__[4][4] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[4][3] * __y_xpd__[1][3]) + (__x_xpd__[4][0] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[4][2] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[4][1] * __y_xpd__[1][1]));

			}
			if (((y.m_gu & 4) != 0)) {
				__tmp_coord_array_2__[6] += ((__x_xpd__[4][2] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[4][3] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[4][4] * __y_xpd__[2][4]));
				__tmp_coord_array_2__[7] += ((-1.0f * __x_xpd__[4][1] * __y_xpd__[2][2]) + (__x_xpd__[4][3] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[4][4] * __y_xpd__[2][5]));
				__tmp_coord_array_2__[8] += ((-1.0f * __x_xpd__[4][4] * __y_xpd__[2][3]) + (__x_xpd__[4][1] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[4][2] * __y_xpd__[2][0]));
				__tmp_coord_array_2__[9] += ((-1.0f * __x_xpd__[4][4] * __y_xpd__[2][8]) + (-1.0f * __x_xpd__[4][0] * __y_xpd__[2][2]) + (__x_xpd__[4][3] * __y_xpd__[2][9]));
				__tmp_coord_array_2__[10] += ((-1.0f * __x_xpd__[4][0] * __y_xpd__[2][0]) + (__x_xpd__[4][1] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[4][4] * __y_xpd__[2][6]));
				__tmp_coord_array_2__[11] += ((__x_xpd__[4][2] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[4][4] * __y_xpd__[2][7]) + (-1.0f * __x_xpd__[4][0] * __y_xpd__[2][1]));
				__tmp_coord_array_2__[12] += ((-1.0f * __x_xpd__[4][0] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[4][2] * __y_xpd__[2][8]) + (__x_xpd__[4][3] * __y_xpd__[2][7]));
				__tmp_coord_array_2__[13] += ((-1.0f * __x_xpd__[4][0] * __y_xpd__[2][5]) + (__x_xpd__[4][1] * __y_xpd__[2][8]) + (-1.0f * __x_xpd__[4][3] * __y_xpd__[2][6]));
				__tmp_coord_array_2__[14] += ((-1.0f * __x_xpd__[4][0] * __y_xpd__[2][3]) + (__x_xpd__[4][2] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[4][1] * __y_xpd__[2][7]));
				__tmp_coord_array_2__[15] += ((-1.0f * __x_xpd__[4][2] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[4][3] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[4][1] * __y_xpd__[2][4]));
				__tmp_coord_array_2__[26] += ((__x_xpd__[4][3] * __y_xpd__[2][8]) + (__x_xpd__[4][1] * __y_xpd__[2][6]) + (__x_xpd__[4][2] * __y_xpd__[2][7]) + (-1.0f * __x_xpd__[4][0] * __y_xpd__[2][9]));
				__tmp_coord_array_2__[27] += ((-1.0f * __x_xpd__[4][0] * __y_xpd__[2][0]) + (__x_xpd__[4][4] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[4][2] * __y_xpd__[2][3]) + (__x_xpd__[4][3] * __y_xpd__[2][5]));
				__tmp_coord_array_2__[28] += ((-1.0f * __x_xpd__[4][0] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[4][3] * __y_xpd__[2][4]) + (__x_xpd__[4][4] * __y_xpd__[2][7]) + (__x_xpd__[4][1] * __y_xpd__[2][3]));
				__tmp_coord_array_2__[29] += ((-1.0f * __x_xpd__[4][0] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[4][1] * __y_xpd__[2][5]) + (__x_xpd__[4][2] * __y_xpd__[2][4]) + (__x_xpd__[4][4] * __y_xpd__[2][8]));
				__tmp_coord_array_2__[30] += ((-1.0f * __x_xpd__[4][2] * __y_xpd__[2][1]) + (__x_xpd__[4][4] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[4][1] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[4][3] * __y_xpd__[2][2]));

			}
			if (((y.m_gu & 8) != 0)) {
				__tmp_coord_array_2__[1] += ((-1.0f * __x_xpd__[4][2] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[4][4] * __y_xpd__[3][9]) + (__x_xpd__[4][3] * __y_xpd__[3][8]) + (__x_xpd__[4][1] * __y_xpd__[3][6]));
				__tmp_coord_array_2__[2] += ((-1.0f * __x_xpd__[4][3] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[4][4] * __y_xpd__[3][0]) + (__x_xpd__[4][0] * __y_xpd__[3][6]) + (__x_xpd__[4][2] * __y_xpd__[3][3]));
				__tmp_coord_array_2__[3] += ((-1.0f * __x_xpd__[4][4] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[4][0] * __y_xpd__[3][7]) + (__x_xpd__[4][3] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[4][1] * __y_xpd__[3][3]));
				__tmp_coord_array_2__[4] += ((__x_xpd__[4][1] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[4][4] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[4][2] * __y_xpd__[3][4]) + (__x_xpd__[4][0] * __y_xpd__[3][8]));
				__tmp_coord_array_2__[5] += ((__x_xpd__[4][0] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[4][2] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[4][1] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[4][3] * __y_xpd__[3][2]));
				__tmp_coord_array_2__[16] += ((__x_xpd__[4][3] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[4][0] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[4][2] * __y_xpd__[3][2]));
				__tmp_coord_array_2__[17] += ((-1.0f * __x_xpd__[4][3] * __y_xpd__[3][0]) + (__x_xpd__[4][1] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[4][0] * __y_xpd__[3][5]));
				__tmp_coord_array_2__[18] += ((__x_xpd__[4][2] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[4][1] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[4][0] * __y_xpd__[3][3]));
				__tmp_coord_array_2__[19] += ((-1.0f * __x_xpd__[4][0] * __y_xpd__[3][8]) + (__x_xpd__[4][3] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[4][4] * __y_xpd__[3][2]));
				__tmp_coord_array_2__[20] += ((-1.0f * __x_xpd__[4][0] * __y_xpd__[3][6]) + (__x_xpd__[4][1] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[4][4] * __y_xpd__[3][0]));
				__tmp_coord_array_2__[21] += ((-1.0f * __x_xpd__[4][4] * __y_xpd__[3][1]) + (__x_xpd__[4][2] * __y_xpd__[3][9]) + (__x_xpd__[4][0] * __y_xpd__[3][7]));
				__tmp_coord_array_2__[22] += ((__x_xpd__[4][2] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[4][4] * __y_xpd__[3][4]) + (__x_xpd__[4][3] * __y_xpd__[3][7]));
				__tmp_coord_array_2__[23] += ((__x_xpd__[4][4] * __y_xpd__[3][5]) + (__x_xpd__[4][1] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[4][3] * __y_xpd__[3][6]));
				__tmp_coord_array_2__[24] += ((-1.0f * __x_xpd__[4][4] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[4][1] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[4][2] * __y_xpd__[3][6]));
				__tmp_coord_array_2__[25] += ((-1.0f * __x_xpd__[4][3] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[4][1] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[4][2] * __y_xpd__[3][5]));

			}
			if (((y.m_gu & 16) != 0)) {
				__tmp_coord_array_2__[0] += ((__x_xpd__[4][0] * __y_xpd__[4][4]) + (-1.0f * __x_xpd__[4][1] * __y_xpd__[4][1]) + (__x_xpd__[4][4] * __y_xpd__[4][0]) + (-1.0f * __x_xpd__[4][2] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[4][3] * __y_xpd__[4][3]));
				__tmp_coord_array_2__[6] += ((__x_xpd__[4][1] * __y_xpd__[4][4]) + (-1.0f * __x_xpd__[4][4] * __y_xpd__[4][1]));
				__tmp_coord_array_2__[7] += ((-1.0f * __x_xpd__[4][4] * __y_xpd__[4][2]) + (__x_xpd__[4][2] * __y_xpd__[4][4]));
				__tmp_coord_array_2__[8] += ((-1.0f * __x_xpd__[4][4] * __y_xpd__[4][3]) + (__x_xpd__[4][3] * __y_xpd__[4][4]));
				__tmp_coord_array_2__[9] += ((-1.0f * __x_xpd__[4][1] * __y_xpd__[4][2]) + (__x_xpd__[4][2] * __y_xpd__[4][1]));
				__tmp_coord_array_2__[10] += ((-1.0f * __x_xpd__[4][2] * __y_xpd__[4][3]) + (__x_xpd__[4][3] * __y_xpd__[4][2]));
				__tmp_coord_array_2__[11] += ((-1.0f * __x_xpd__[4][3] * __y_xpd__[4][1]) + (__x_xpd__[4][1] * __y_xpd__[4][3]));
				__tmp_coord_array_2__[12] += ((-1.0f * __x_xpd__[4][1] * __y_xpd__[4][0]) + (__x_xpd__[4][0] * __y_xpd__[4][1]));
				__tmp_coord_array_2__[13] += ((__x_xpd__[4][0] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[4][2] * __y_xpd__[4][0]));
				__tmp_coord_array_2__[14] += ((-1.0f * __x_xpd__[4][3] * __y_xpd__[4][0]) + (__x_xpd__[4][0] * __y_xpd__[4][3]));
				__tmp_coord_array_2__[15] += ((__x_xpd__[4][0] * __y_xpd__[4][4]) + (-1.0f * __x_xpd__[4][4] * __y_xpd__[4][0]));

			}
			if (((y.m_gu & 32) != 0)) {
				__tmp_coord_array_2__[1] += (__x_xpd__[4][4] * __y_xpd__[5][0]);
				__tmp_coord_array_2__[2] += (__x_xpd__[4][1] * __y_xpd__[5][0]);
				__tmp_coord_array_2__[3] += (__x_xpd__[4][2] * __y_xpd__[5][0]);
				__tmp_coord_array_2__[4] += (__x_xpd__[4][3] * __y_xpd__[5][0]);
				__tmp_coord_array_2__[5] += (__x_xpd__[4][0] * __y_xpd__[5][0]);

			}

		}
		if (((x.m_gu & 32) != 0)) {
			if (((y.m_gu & 1) != 0)) {
				__tmp_coord_array_2__[31] += (__x_xpd__[5][0] * __y_xpd__[0][0]);

			}
			if (((y.m_gu & 2) != 0)) {
				__tmp_coord_array_2__[26] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[1][4]);
				__tmp_coord_array_2__[27] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[1][1]);
				__tmp_coord_array_2__[28] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[1][2]);
				__tmp_coord_array_2__[29] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[1][3]);
				__tmp_coord_array_2__[30] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[1][0]);

			}
			if (((y.m_gu & 4) != 0)) {
				__tmp_coord_array_2__[16] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[2][6]);
				__tmp_coord_array_2__[17] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[2][7]);
				__tmp_coord_array_2__[18] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[2][8]);
				__tmp_coord_array_2__[19] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[2][3]);
				__tmp_coord_array_2__[20] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[2][4]);
				__tmp_coord_array_2__[21] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[2][5]);
				__tmp_coord_array_2__[22] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[2][0]);
				__tmp_coord_array_2__[23] += (__x_xpd__[5][0] * __y_xpd__[2][1]);
				__tmp_coord_array_2__[24] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[2][2]);
				__tmp_coord_array_2__[25] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[2][9]);

			}
			if (((y.m_gu & 8) != 0)) {
				__tmp_coord_array_2__[6] += (__x_xpd__[5][0] * __y_xpd__[3][6]);
				__tmp_coord_array_2__[7] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[3][7]);
				__tmp_coord_array_2__[8] += (__x_xpd__[5][0] * __y_xpd__[3][8]);
				__tmp_coord_array_2__[9] += (__x_xpd__[5][0] * __y_xpd__[3][3]);
				__tmp_coord_array_2__[10] += (__x_xpd__[5][0] * __y_xpd__[3][4]);
				__tmp_coord_array_2__[11] += (__x_xpd__[5][0] * __y_xpd__[3][5]);
				__tmp_coord_array_2__[12] += (__x_xpd__[5][0] * __y_xpd__[3][0]);
				__tmp_coord_array_2__[13] += (__x_xpd__[5][0] * __y_xpd__[3][1]);
				__tmp_coord_array_2__[14] += (__x_xpd__[5][0] * __y_xpd__[3][2]);
				__tmp_coord_array_2__[15] += (__x_xpd__[5][0] * __y_xpd__[3][9]);

			}
			if (((y.m_gu & 16) != 0)) {
				__tmp_coord_array_2__[1] += (__x_xpd__[5][0] * __y_xpd__[4][4]);
				__tmp_coord_array_2__[2] += (__x_xpd__[5][0] * __y_xpd__[4][1]);
				__tmp_coord_array_2__[3] += (__x_xpd__[5][0] * __y_xpd__[4][2]);
				__tmp_coord_array_2__[4] += (__x_xpd__[5][0] * __y_xpd__[4][3]);
				__tmp_coord_array_2__[5] += (__x_xpd__[5][0] * __y_xpd__[4][0]);

			}
			if (((y.m_gu & 32) != 0)) {
				__tmp_coord_array_2__[0] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[5][0]);

			}

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_2__);
		return __temp_var_1__;
	}
	mv gpEM(const mv& x, const mv& y) {
		mv __temp_var_1__;
		float __tmp_coord_array_3__[32] ;
		mv_zero(__tmp_coord_array_3__, 32);
		const float* __x_xpd__[6] ;
		x.expand(__x_xpd__, true);
		const float* __y_xpd__[6] ;
		y.expand(__y_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			if (((y.m_gu & 1) != 0)) {
				__tmp_coord_array_3__[0] += (__x_xpd__[0][0] * __y_xpd__[0][0]);

			}
			if (((y.m_gu & 2) != 0)) {
				__tmp_coord_array_3__[1] += (__x_xpd__[0][0] * __y_xpd__[1][0]);
				__tmp_coord_array_3__[2] += (__x_xpd__[0][0] * __y_xpd__[1][1]);
				__tmp_coord_array_3__[3] += (__x_xpd__[0][0] * __y_xpd__[1][2]);
				__tmp_coord_array_3__[4] += (__x_xpd__[0][0] * __y_xpd__[1][3]);
				__tmp_coord_array_3__[5] += (__x_xpd__[0][0] * __y_xpd__[1][4]);

			}
			if (((y.m_gu & 4) != 0)) {
				__tmp_coord_array_3__[6] += (__x_xpd__[0][0] * __y_xpd__[2][0]);
				__tmp_coord_array_3__[7] += (__x_xpd__[0][0] * __y_xpd__[2][1]);
				__tmp_coord_array_3__[8] += (__x_xpd__[0][0] * __y_xpd__[2][2]);
				__tmp_coord_array_3__[9] += (__x_xpd__[0][0] * __y_xpd__[2][3]);
				__tmp_coord_array_3__[10] += (__x_xpd__[0][0] * __y_xpd__[2][4]);
				__tmp_coord_array_3__[11] += (__x_xpd__[0][0] * __y_xpd__[2][5]);
				__tmp_coord_array_3__[12] += (__x_xpd__[0][0] * __y_xpd__[2][6]);
				__tmp_coord_array_3__[13] += (__x_xpd__[0][0] * __y_xpd__[2][7]);
				__tmp_coord_array_3__[14] += (__x_xpd__[0][0] * __y_xpd__[2][8]);
				__tmp_coord_array_3__[15] += (__x_xpd__[0][0] * __y_xpd__[2][9]);

			}
			if (((y.m_gu & 8) != 0)) {
				__tmp_coord_array_3__[16] += (__x_xpd__[0][0] * __y_xpd__[3][0]);
				__tmp_coord_array_3__[17] += (__x_xpd__[0][0] * __y_xpd__[3][1]);
				__tmp_coord_array_3__[18] += (__x_xpd__[0][0] * __y_xpd__[3][2]);
				__tmp_coord_array_3__[19] += (__x_xpd__[0][0] * __y_xpd__[3][3]);
				__tmp_coord_array_3__[20] += (__x_xpd__[0][0] * __y_xpd__[3][4]);
				__tmp_coord_array_3__[21] += (__x_xpd__[0][0] * __y_xpd__[3][5]);
				__tmp_coord_array_3__[22] += (__x_xpd__[0][0] * __y_xpd__[3][6]);
				__tmp_coord_array_3__[23] += (__x_xpd__[0][0] * __y_xpd__[3][7]);
				__tmp_coord_array_3__[24] += (__x_xpd__[0][0] * __y_xpd__[3][8]);
				__tmp_coord_array_3__[25] += (__x_xpd__[0][0] * __y_xpd__[3][9]);

			}
			if (((y.m_gu & 16) != 0)) {
				__tmp_coord_array_3__[26] += (__x_xpd__[0][0] * __y_xpd__[4][0]);
				__tmp_coord_array_3__[27] += (__x_xpd__[0][0] * __y_xpd__[4][1]);
				__tmp_coord_array_3__[28] += (__x_xpd__[0][0] * __y_xpd__[4][2]);
				__tmp_coord_array_3__[29] += (__x_xpd__[0][0] * __y_xpd__[4][3]);
				__tmp_coord_array_3__[30] += (__x_xpd__[0][0] * __y_xpd__[4][4]);

			}
			if (((y.m_gu & 32) != 0)) {
				__tmp_coord_array_3__[31] += (__x_xpd__[0][0] * __y_xpd__[5][0]);

			}

		}
		if (((x.m_gu & 2) != 0)) {
			if (((y.m_gu & 1) != 0)) {
				__tmp_coord_array_3__[1] += (__x_xpd__[1][0] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[2] += (__x_xpd__[1][1] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[3] += (__x_xpd__[1][2] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[4] += (__x_xpd__[1][3] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[5] += (__x_xpd__[1][4] * __y_xpd__[0][0]);

			}
			if (((y.m_gu & 2) != 0)) {
				__tmp_coord_array_3__[0] += ((__x_xpd__[1][2] * __y_xpd__[1][2]) + (__x_xpd__[1][1] * __y_xpd__[1][1]) + (__x_xpd__[1][3] * __y_xpd__[1][3]) + (__x_xpd__[1][0] * __y_xpd__[1][0]) + (__x_xpd__[1][4] * __y_xpd__[1][4]));
				__tmp_coord_array_3__[6] += ((__x_xpd__[1][0] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[1][0]));
				__tmp_coord_array_3__[7] += ((-1.0f * __x_xpd__[1][2] * __y_xpd__[1][0]) + (__x_xpd__[1][0] * __y_xpd__[1][2]));
				__tmp_coord_array_3__[8] += ((__x_xpd__[1][0] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[1][0]));
				__tmp_coord_array_3__[9] += ((-1.0f * __x_xpd__[1][2] * __y_xpd__[1][1]) + (__x_xpd__[1][1] * __y_xpd__[1][2]));
				__tmp_coord_array_3__[10] += ((__x_xpd__[1][2] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[1][2]));
				__tmp_coord_array_3__[11] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[1][3]) + (__x_xpd__[1][3] * __y_xpd__[1][1]));
				__tmp_coord_array_3__[12] += ((-1.0f * __x_xpd__[1][4] * __y_xpd__[1][1]) + (__x_xpd__[1][1] * __y_xpd__[1][4]));
				__tmp_coord_array_3__[13] += ((-1.0f * __x_xpd__[1][4] * __y_xpd__[1][2]) + (__x_xpd__[1][2] * __y_xpd__[1][4]));
				__tmp_coord_array_3__[14] += ((__x_xpd__[1][3] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[1][3]));
				__tmp_coord_array_3__[15] += ((-1.0f * __x_xpd__[1][4] * __y_xpd__[1][0]) + (__x_xpd__[1][0] * __y_xpd__[1][4]));

			}
			if (((y.m_gu & 4) != 0)) {
				__tmp_coord_array_3__[1] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[2][2]));
				__tmp_coord_array_3__[2] += ((__x_xpd__[1][0] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[2][3]) + (__x_xpd__[1][3] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[2][6]));
				__tmp_coord_array_3__[3] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[2][4]) + (__x_xpd__[1][1] * __y_xpd__[2][3]) + (__x_xpd__[1][0] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[2][7]));
				__tmp_coord_array_3__[4] += ((-1.0f * __x_xpd__[1][4] * __y_xpd__[2][8]) + (__x_xpd__[1][0] * __y_xpd__[2][2]) + (__x_xpd__[1][2] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[2][5]));
				__tmp_coord_array_3__[5] += ((__x_xpd__[1][0] * __y_xpd__[2][9]) + (__x_xpd__[1][3] * __y_xpd__[2][8]) + (__x_xpd__[1][2] * __y_xpd__[2][7]) + (__x_xpd__[1][1] * __y_xpd__[2][6]));
				__tmp_coord_array_3__[16] += ((__x_xpd__[1][2] * __y_xpd__[2][8]) + (__x_xpd__[1][4] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[2][7]));
				__tmp_coord_array_3__[17] += ((__x_xpd__[1][3] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[2][8]) + (__x_xpd__[1][4] * __y_xpd__[2][5]));
				__tmp_coord_array_3__[18] += ((__x_xpd__[1][4] * __y_xpd__[2][3]) + (__x_xpd__[1][1] * __y_xpd__[2][7]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[2][6]));
				__tmp_coord_array_3__[19] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[2][9]) + (__x_xpd__[1][0] * __y_xpd__[2][8]) + (__x_xpd__[1][4] * __y_xpd__[2][2]));
				__tmp_coord_array_3__[20] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[2][9]) + (__x_xpd__[1][0] * __y_xpd__[2][6]) + (__x_xpd__[1][4] * __y_xpd__[2][0]));
				__tmp_coord_array_3__[21] += ((__x_xpd__[1][0] * __y_xpd__[2][7]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[2][9]) + (__x_xpd__[1][4] * __y_xpd__[2][1]));
				__tmp_coord_array_3__[22] += ((__x_xpd__[1][3] * __y_xpd__[2][1]) + (__x_xpd__[1][0] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[2][2]));
				__tmp_coord_array_3__[23] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[1][0] * __y_xpd__[2][5]) + (__x_xpd__[1][3] * __y_xpd__[2][0]));
				__tmp_coord_array_3__[24] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[2][1]) + (__x_xpd__[1][2] * __y_xpd__[2][0]) + (__x_xpd__[1][0] * __y_xpd__[2][3]));
				__tmp_coord_array_3__[25] += ((__x_xpd__[1][1] * __y_xpd__[2][4]) + (__x_xpd__[1][3] * __y_xpd__[2][3]) + (__x_xpd__[1][2] * __y_xpd__[2][5]));

			}
			if (((y.m_gu & 8) != 0)) {
				__tmp_coord_array_3__[6] += ((__x_xpd__[1][4] * __y_xpd__[3][4]) + (__x_xpd__[1][3] * __y_xpd__[3][7]) + (__x_xpd__[1][2] * __y_xpd__[3][8]));
				__tmp_coord_array_3__[7] += ((__x_xpd__[1][3] * __y_xpd__[3][6]) + (__x_xpd__[1][4] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[3][8]));
				__tmp_coord_array_3__[8] += ((__x_xpd__[1][4] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[3][7]));
				__tmp_coord_array_3__[9] += ((__x_xpd__[1][3] * __y_xpd__[3][9]) + (__x_xpd__[1][4] * __y_xpd__[3][2]) + (__x_xpd__[1][0] * __y_xpd__[3][8]));
				__tmp_coord_array_3__[10] += ((__x_xpd__[1][1] * __y_xpd__[3][9]) + (__x_xpd__[1][4] * __y_xpd__[3][0]) + (__x_xpd__[1][0] * __y_xpd__[3][6]));
				__tmp_coord_array_3__[11] += ((__x_xpd__[1][2] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[1][0] * __y_xpd__[3][7]) + (__x_xpd__[1][4] * __y_xpd__[3][1]));
				__tmp_coord_array_3__[12] += ((__x_xpd__[1][3] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[3][2]) + (__x_xpd__[1][0] * __y_xpd__[3][4]));
				__tmp_coord_array_3__[13] += ((__x_xpd__[1][0] * __y_xpd__[3][5]) + (__x_xpd__[1][1] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[3][0]));
				__tmp_coord_array_3__[14] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[3][1]) + (__x_xpd__[1][0] * __y_xpd__[3][3]) + (__x_xpd__[1][2] * __y_xpd__[3][0]));
				__tmp_coord_array_3__[15] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[3][4]));
				__tmp_coord_array_3__[26] += ((__x_xpd__[1][1] * __y_xpd__[3][0]) + (__x_xpd__[1][3] * __y_xpd__[3][2]) + (__x_xpd__[1][2] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[3][9]));
				__tmp_coord_array_3__[27] += ((-1.0f * __x_xpd__[1][2] * __y_xpd__[3][3]) + (__x_xpd__[1][0] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[3][6]) + (__x_xpd__[1][3] * __y_xpd__[3][5]));
				__tmp_coord_array_3__[28] += ((__x_xpd__[1][4] * __y_xpd__[3][7]) + (__x_xpd__[1][1] * __y_xpd__[3][3]) + (__x_xpd__[1][0] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[3][4]));
				__tmp_coord_array_3__[29] += ((__x_xpd__[1][0] * __y_xpd__[3][2]) + (__x_xpd__[1][2] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[3][5]));
				__tmp_coord_array_3__[30] += ((__x_xpd__[1][0] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[3][6]) + (__x_xpd__[1][2] * __y_xpd__[3][7]));

			}
			if (((y.m_gu & 16) != 0)) {
				__tmp_coord_array_3__[16] += ((__x_xpd__[1][1] * __y_xpd__[4][0]) + (__x_xpd__[1][0] * __y_xpd__[4][1]));
				__tmp_coord_array_3__[17] += ((__x_xpd__[1][0] * __y_xpd__[4][2]) + (__x_xpd__[1][2] * __y_xpd__[4][0]));
				__tmp_coord_array_3__[18] += ((__x_xpd__[1][0] * __y_xpd__[4][3]) + (__x_xpd__[1][3] * __y_xpd__[4][0]));
				__tmp_coord_array_3__[19] += ((__x_xpd__[1][1] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[4][1]));
				__tmp_coord_array_3__[20] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[4][2]) + (__x_xpd__[1][2] * __y_xpd__[4][3]));
				__tmp_coord_array_3__[21] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[4][3]) + (__x_xpd__[1][3] * __y_xpd__[4][1]));
				__tmp_coord_array_3__[22] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[4][4]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[4][1]));
				__tmp_coord_array_3__[23] += ((__x_xpd__[1][2] * __y_xpd__[4][4]) + (__x_xpd__[1][4] * __y_xpd__[4][2]));
				__tmp_coord_array_3__[24] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[4][4]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[4][3]));
				__tmp_coord_array_3__[25] += ((__x_xpd__[1][0] * __y_xpd__[4][4]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[4][0]));
				__tmp_coord_array_3__[31] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[4][3]) + (__x_xpd__[1][4] * __y_xpd__[4][4]) + (__x_xpd__[1][0] * __y_xpd__[4][0]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[4][2]));

			}
			if (((y.m_gu & 32) != 0)) {
				__tmp_coord_array_3__[26] += (__x_xpd__[1][0] * __y_xpd__[5][0]);
				__tmp_coord_array_3__[27] += (-1.0f * __x_xpd__[1][1] * __y_xpd__[5][0]);
				__tmp_coord_array_3__[28] += (-1.0f * __x_xpd__[1][2] * __y_xpd__[5][0]);
				__tmp_coord_array_3__[29] += (-1.0f * __x_xpd__[1][3] * __y_xpd__[5][0]);
				__tmp_coord_array_3__[30] += (__x_xpd__[1][4] * __y_xpd__[5][0]);

			}

		}
		if (((x.m_gu & 4) != 0)) {
			if (((y.m_gu & 1) != 0)) {
				__tmp_coord_array_3__[6] += (__x_xpd__[2][0] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[7] += (__x_xpd__[2][1] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[8] += (__x_xpd__[2][2] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[9] += (__x_xpd__[2][3] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[10] += (__x_xpd__[2][4] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[11] += (__x_xpd__[2][5] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[12] += (__x_xpd__[2][6] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[13] += (__x_xpd__[2][7] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[14] += (__x_xpd__[2][8] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[15] += (__x_xpd__[2][9] * __y_xpd__[0][0]);

			}
			if (((y.m_gu & 2) != 0)) {
				__tmp_coord_array_3__[1] += ((__x_xpd__[2][2] * __y_xpd__[1][3]) + (__x_xpd__[2][9] * __y_xpd__[1][4]) + (__x_xpd__[2][0] * __y_xpd__[1][1]) + (__x_xpd__[2][1] * __y_xpd__[1][2]));
				__tmp_coord_array_3__[2] += ((__x_xpd__[2][6] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[1][0]) + (__x_xpd__[2][3] * __y_xpd__[1][2]));
				__tmp_coord_array_3__[3] += ((-1.0f * __x_xpd__[2][1] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[1][1]) + (__x_xpd__[2][4] * __y_xpd__[1][3]) + (__x_xpd__[2][7] * __y_xpd__[1][4]));
				__tmp_coord_array_3__[4] += ((__x_xpd__[2][8] * __y_xpd__[1][4]) + (__x_xpd__[2][5] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[1][2]));
				__tmp_coord_array_3__[5] += ((-1.0f * __x_xpd__[2][9] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[1][2]));
				__tmp_coord_array_3__[16] += ((__x_xpd__[2][4] * __y_xpd__[1][4]) + (__x_xpd__[2][8] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[1][3]));
				__tmp_coord_array_3__[17] += ((__x_xpd__[2][5] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[1][1]) + (__x_xpd__[2][6] * __y_xpd__[1][3]));
				__tmp_coord_array_3__[18] += ((__x_xpd__[2][3] * __y_xpd__[1][4]) + (__x_xpd__[2][7] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[1][2]));
				__tmp_coord_array_3__[19] += ((__x_xpd__[2][2] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[1][3]) + (__x_xpd__[2][8] * __y_xpd__[1][0]));
				__tmp_coord_array_3__[20] += ((__x_xpd__[2][0] * __y_xpd__[1][4]) + (__x_xpd__[2][6] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[1][1]));
				__tmp_coord_array_3__[21] += ((-1.0f * __x_xpd__[2][9] * __y_xpd__[1][2]) + (__x_xpd__[2][7] * __y_xpd__[1][0]) + (__x_xpd__[2][1] * __y_xpd__[1][4]));
				__tmp_coord_array_3__[22] += ((-1.0f * __x_xpd__[2][2] * __y_xpd__[1][2]) + (__x_xpd__[2][1] * __y_xpd__[1][3]) + (__x_xpd__[2][4] * __y_xpd__[1][0]));
				__tmp_coord_array_3__[23] += ((__x_xpd__[2][0] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[1][0]));
				__tmp_coord_array_3__[24] += ((-1.0f * __x_xpd__[2][1] * __y_xpd__[1][1]) + (__x_xpd__[2][0] * __y_xpd__[1][2]) + (__x_xpd__[2][3] * __y_xpd__[1][0]));
				__tmp_coord_array_3__[25] += ((__x_xpd__[2][5] * __y_xpd__[1][2]) + (__x_xpd__[2][3] * __y_xpd__[1][3]) + (__x_xpd__[2][4] * __y_xpd__[1][1]));

			}
			if (((y.m_gu & 4) != 0)) {
				__tmp_coord_array_3__[0] += ((-1.0f * __x_xpd__[2][6] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[2][8]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[2][7]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[2][2]));
				__tmp_coord_array_3__[6] += ((-1.0f * __x_xpd__[2][9] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[2][2]) + (__x_xpd__[2][3] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[2][3]) + (__x_xpd__[2][2] * __y_xpd__[2][5]) + (__x_xpd__[2][6] * __y_xpd__[2][9]));
				__tmp_coord_array_3__[7] += ((-1.0f * __x_xpd__[2][3] * __y_xpd__[2][0]) + (__x_xpd__[2][4] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[2][7]) + (__x_xpd__[2][7] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[2][4]) + (__x_xpd__[2][0] * __y_xpd__[2][3]));
				__tmp_coord_array_3__[8] += ((__x_xpd__[2][5] * __y_xpd__[2][0]) + (__x_xpd__[2][1] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[2][8]) + (__x_xpd__[2][8] * __y_xpd__[2][9]));
				__tmp_coord_array_3__[9] += ((-1.0f * __x_xpd__[2][4] * __y_xpd__[2][5]) + (__x_xpd__[2][1] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[2][1]) + (__x_xpd__[2][5] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[2][7]) + (__x_xpd__[2][7] * __y_xpd__[2][6]));
				__tmp_coord_array_3__[10] += ((-1.0f * __x_xpd__[2][1] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[2][3]) + (__x_xpd__[2][8] * __y_xpd__[2][7]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[2][8]) + (__x_xpd__[2][3] * __y_xpd__[2][5]) + (__x_xpd__[2][2] * __y_xpd__[2][1]));
				__tmp_coord_array_3__[11] += ((-1.0f * __x_xpd__[2][3] * __y_xpd__[2][4]) + (__x_xpd__[2][0] * __y_xpd__[2][2]) + (__x_xpd__[2][6] * __y_xpd__[2][8]) + (__x_xpd__[2][4] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[2][0]));
				__tmp_coord_array_3__[12] += ((__x_xpd__[2][3] * __y_xpd__[2][7]) + (__x_xpd__[2][8] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[2][9]) + (__x_xpd__[2][9] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[2][8]));
				__tmp_coord_array_3__[13] += ((-1.0f * __x_xpd__[2][8] * __y_xpd__[2][4]) + (__x_xpd__[2][4] * __y_xpd__[2][8]) + (__x_xpd__[2][9] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[2][6]) + (__x_xpd__[2][6] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[2][9]));
				__tmp_coord_array_3__[14] += ((-1.0f * __x_xpd__[2][4] * __y_xpd__[2][7]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[2][5]) + (__x_xpd__[2][9] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[2][9]) + (__x_xpd__[2][5] * __y_xpd__[2][6]) + (__x_xpd__[2][7] * __y_xpd__[2][4]));
				__tmp_coord_array_3__[15] += ((-1.0f * __x_xpd__[2][6] * __y_xpd__[2][0]) + (__x_xpd__[2][1] * __y_xpd__[2][7]) + (__x_xpd__[2][0] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[2][2]) + (__x_xpd__[2][2] * __y_xpd__[2][8]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[2][1]));
				__tmp_coord_array_3__[26] += ((__x_xpd__[2][8] * __y_xpd__[2][3]) + (__x_xpd__[2][3] * __y_xpd__[2][8]) + (__x_xpd__[2][6] * __y_xpd__[2][4]) + (__x_xpd__[2][4] * __y_xpd__[2][6]) + (__x_xpd__[2][7] * __y_xpd__[2][5]) + (__x_xpd__[2][5] * __y_xpd__[2][7]));
				__tmp_coord_array_3__[27] += ((-1.0f * __x_xpd__[2][2] * __y_xpd__[2][7]) + (__x_xpd__[2][1] * __y_xpd__[2][8]) + (__x_xpd__[2][8] * __y_xpd__[2][1]) + (__x_xpd__[2][4] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[2][2]) + (__x_xpd__[2][9] * __y_xpd__[2][4]));
				__tmp_coord_array_3__[28] += ((__x_xpd__[2][5] * __y_xpd__[2][9]) + (__x_xpd__[2][2] * __y_xpd__[2][6]) + (__x_xpd__[2][6] * __y_xpd__[2][2]) + (__x_xpd__[2][9] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[2][8]));
				__tmp_coord_array_3__[29] += ((__x_xpd__[2][7] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[2][1]) + (__x_xpd__[2][3] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[2][6]) + (__x_xpd__[2][9] * __y_xpd__[2][3]) + (__x_xpd__[2][0] * __y_xpd__[2][7]));
				__tmp_coord_array_3__[30] += ((__x_xpd__[2][3] * __y_xpd__[2][2]) + (__x_xpd__[2][1] * __y_xpd__[2][5]) + (__x_xpd__[2][2] * __y_xpd__[2][3]) + (__x_xpd__[2][4] * __y_xpd__[2][0]) + (__x_xpd__[2][5] * __y_xpd__[2][1]) + (__x_xpd__[2][0] * __y_xpd__[2][4]));

			}
			if (((y.m_gu & 8) != 0)) {
				__tmp_coord_array_3__[1] += ((__x_xpd__[2][5] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[3][3]));
				__tmp_coord_array_3__[2] += ((__x_xpd__[2][9] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[3][2]) + (__x_xpd__[2][2] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[3][9]) + (__x_xpd__[2][1] * __y_xpd__[3][8]) + (__x_xpd__[2][8] * __y_xpd__[3][1]));
				__tmp_coord_array_3__[3] += ((-1.0f * __x_xpd__[2][8] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[3][9]) + (__x_xpd__[2][9] * __y_xpd__[3][5]) + (__x_xpd__[2][6] * __y_xpd__[3][2]) + (__x_xpd__[2][2] * __y_xpd__[3][6]));
				__tmp_coord_array_3__[4] += ((__x_xpd__[2][7] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[3][1]) + (__x_xpd__[2][9] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[3][7]));
				__tmp_coord_array_3__[5] += ((-1.0f * __x_xpd__[2][0] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[3][0]));
				__tmp_coord_array_3__[16] += ((__x_xpd__[2][2] * __y_xpd__[3][5]) + (__x_xpd__[2][3] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[3][9]));
				__tmp_coord_array_3__[17] += ((-1.0f * __x_xpd__[2][2] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[3][9]) + (__x_xpd__[2][4] * __y_xpd__[3][2]) + (__x_xpd__[2][9] * __y_xpd__[3][7]) + (__x_xpd__[2][0] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[3][0]));
				__tmp_coord_array_3__[18] += ((-1.0f * __x_xpd__[2][8] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[3][8]) + (__x_xpd__[2][5] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[3][1]) + (__x_xpd__[2][1] * __y_xpd__[3][4]));
				__tmp_coord_array_3__[19] += ((-1.0f * __x_xpd__[2][0] * __y_xpd__[3][1]) + (__x_xpd__[2][5] * __y_xpd__[3][4]) + (__x_xpd__[2][1] * __y_xpd__[3][0]) + (__x_xpd__[2][6] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[3][5]) + (__x_xpd__[2][7] * __y_xpd__[3][6]));
				__tmp_coord_array_3__[20] += ((-1.0f * __x_xpd__[2][8] * __y_xpd__[3][7]) + (__x_xpd__[2][3] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[3][3]) + (__x_xpd__[2][2] * __y_xpd__[3][1]));
				__tmp_coord_array_3__[21] += ((__x_xpd__[2][4] * __y_xpd__[3][3]) + (__x_xpd__[2][6] * __y_xpd__[3][8]) + (__x_xpd__[2][0] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[3][6]));
				__tmp_coord_array_3__[22] += ((__x_xpd__[2][0] * __y_xpd__[3][9]) + (__x_xpd__[2][8] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[3][7]) + (__x_xpd__[2][9] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[3][8]));
				__tmp_coord_array_3__[23] += ((-1.0f * __x_xpd__[2][1] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[3][3]) + (__x_xpd__[2][8] * __y_xpd__[3][4]) + (__x_xpd__[2][3] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[3][1]));
				__tmp_coord_array_3__[24] += ((__x_xpd__[2][4] * __y_xpd__[3][7]) + (__x_xpd__[2][9] * __y_xpd__[3][2]) + (__x_xpd__[2][2] * __y_xpd__[3][9]) + (__x_xpd__[2][5] * __y_xpd__[3][6]) + (__x_xpd__[2][7] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[3][5]));
				__tmp_coord_array_3__[25] += ((-1.0f * __x_xpd__[2][2] * __y_xpd__[3][8]) + (__x_xpd__[2][8] * __y_xpd__[3][2]) + (__x_xpd__[2][1] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[3][6]) + (__x_xpd__[2][7] * __y_xpd__[3][1]) + (__x_xpd__[2][6] * __y_xpd__[3][0]));
				__tmp_coord_array_3__[31] += ((__x_xpd__[2][5] * __y_xpd__[3][5]) + (__x_xpd__[2][0] * __y_xpd__[3][0]) + (__x_xpd__[2][3] * __y_xpd__[3][3]) + (__x_xpd__[2][6] * __y_xpd__[3][6]) + (__x_xpd__[2][1] * __y_xpd__[3][1]) + (__x_xpd__[2][4] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[3][7]) + (__x_xpd__[2][2] * __y_xpd__[3][2]) + (__x_xpd__[2][8] * __y_xpd__[3][8]));

			}
			if (((y.m_gu & 16) != 0)) {
				__tmp_coord_array_3__[6] += ((-1.0f * __x_xpd__[2][4] * __y_xpd__[4][4]) + (__x_xpd__[2][8] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[4][3]));
				__tmp_coord_array_3__[7] += ((-1.0f * __x_xpd__[2][8] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[4][4]) + (__x_xpd__[2][6] * __y_xpd__[4][3]));
				__tmp_coord_array_3__[8] += ((-1.0f * __x_xpd__[2][6] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[4][4]) + (__x_xpd__[2][7] * __y_xpd__[4][1]));
				__tmp_coord_array_3__[9] += ((-1.0f * __x_xpd__[2][9] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[4][0]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[4][4]));
				__tmp_coord_array_3__[10] += ((-1.0f * __x_xpd__[2][0] * __y_xpd__[4][4]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[4][0]));
				__tmp_coord_array_3__[11] += ((-1.0f * __x_xpd__[2][1] * __y_xpd__[4][4]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[4][0]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[4][2]));
				__tmp_coord_array_3__[12] += ((-1.0f * __x_xpd__[2][4] * __y_xpd__[4][0]) + (__x_xpd__[2][1] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[4][2]));
				__tmp_coord_array_3__[13] += ((-1.0f * __x_xpd__[2][5] * __y_xpd__[4][0]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[4][3]) + (__x_xpd__[2][2] * __y_xpd__[4][1]));
				__tmp_coord_array_3__[14] += ((-1.0f * __x_xpd__[2][1] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[4][0]) + (__x_xpd__[2][0] * __y_xpd__[4][2]));
				__tmp_coord_array_3__[15] += ((-1.0f * __x_xpd__[2][5] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[4][3]));
				__tmp_coord_array_3__[26] += ((-1.0f * __x_xpd__[2][0] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[4][2]) + (__x_xpd__[2][9] * __y_xpd__[4][4]));
				__tmp_coord_array_3__[27] += ((__x_xpd__[2][3] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[4][4]) + (__x_xpd__[2][0] * __y_xpd__[4][0]));
				__tmp_coord_array_3__[28] += ((-1.0f * __x_xpd__[2][3] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[4][4]) + (__x_xpd__[2][1] * __y_xpd__[4][0]) + (__x_xpd__[2][4] * __y_xpd__[4][3]));
				__tmp_coord_array_3__[29] += ((-1.0f * __x_xpd__[2][4] * __y_xpd__[4][2]) + (__x_xpd__[2][2] * __y_xpd__[4][0]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[4][4]) + (__x_xpd__[2][5] * __y_xpd__[4][1]));
				__tmp_coord_array_3__[30] += ((-1.0f * __x_xpd__[2][9] * __y_xpd__[4][0]) + (__x_xpd__[2][7] * __y_xpd__[4][2]) + (__x_xpd__[2][6] * __y_xpd__[4][1]) + (__x_xpd__[2][8] * __y_xpd__[4][3]));

			}
			if (((y.m_gu & 32) != 0)) {
				__tmp_coord_array_3__[16] += (-1.0f * __x_xpd__[2][0] * __y_xpd__[5][0]);
				__tmp_coord_array_3__[17] += (-1.0f * __x_xpd__[2][1] * __y_xpd__[5][0]);
				__tmp_coord_array_3__[18] += (-1.0f * __x_xpd__[2][2] * __y_xpd__[5][0]);
				__tmp_coord_array_3__[19] += (-1.0f * __x_xpd__[2][3] * __y_xpd__[5][0]);
				__tmp_coord_array_3__[20] += (-1.0f * __x_xpd__[2][4] * __y_xpd__[5][0]);
				__tmp_coord_array_3__[21] += (-1.0f * __x_xpd__[2][5] * __y_xpd__[5][0]);
				__tmp_coord_array_3__[22] += (-1.0f * __x_xpd__[2][6] * __y_xpd__[5][0]);
				__tmp_coord_array_3__[23] += (__x_xpd__[2][7] * __y_xpd__[5][0]);
				__tmp_coord_array_3__[24] += (-1.0f * __x_xpd__[2][8] * __y_xpd__[5][0]);
				__tmp_coord_array_3__[25] += (__x_xpd__[2][9] * __y_xpd__[5][0]);

			}

		}
		if (((x.m_gu & 8) != 0)) {
			if (((y.m_gu & 1) != 0)) {
				__tmp_coord_array_3__[16] += (__x_xpd__[3][0] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[17] += (__x_xpd__[3][1] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[18] += (__x_xpd__[3][2] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[19] += (__x_xpd__[3][3] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[20] += (__x_xpd__[3][4] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[21] += (__x_xpd__[3][5] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[22] += (__x_xpd__[3][6] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[23] += (__x_xpd__[3][7] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[24] += (__x_xpd__[3][8] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[25] += (__x_xpd__[3][9] * __y_xpd__[0][0]);

			}
			if (((y.m_gu & 2) != 0)) {
				__tmp_coord_array_3__[6] += ((__x_xpd__[3][4] * __y_xpd__[1][4]) + (__x_xpd__[3][7] * __y_xpd__[1][3]) + (__x_xpd__[3][8] * __y_xpd__[1][2]));
				__tmp_coord_array_3__[7] += ((__x_xpd__[3][6] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[3][8] * __y_xpd__[1][1]) + (__x_xpd__[3][5] * __y_xpd__[1][4]));
				__tmp_coord_array_3__[8] += ((__x_xpd__[3][3] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[1][1]));
				__tmp_coord_array_3__[9] += ((__x_xpd__[3][8] * __y_xpd__[1][0]) + (__x_xpd__[3][9] * __y_xpd__[1][3]) + (__x_xpd__[3][2] * __y_xpd__[1][4]));
				__tmp_coord_array_3__[10] += ((__x_xpd__[3][9] * __y_xpd__[1][1]) + (__x_xpd__[3][0] * __y_xpd__[1][4]) + (__x_xpd__[3][6] * __y_xpd__[1][0]));
				__tmp_coord_array_3__[11] += ((__x_xpd__[3][9] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[1][0]) + (__x_xpd__[3][1] * __y_xpd__[1][4]));
				__tmp_coord_array_3__[12] += ((-1.0f * __x_xpd__[3][2] * __y_xpd__[1][2]) + (__x_xpd__[3][4] * __y_xpd__[1][0]) + (__x_xpd__[3][1] * __y_xpd__[1][3]));
				__tmp_coord_array_3__[13] += ((-1.0f * __x_xpd__[3][0] * __y_xpd__[1][3]) + (__x_xpd__[3][2] * __y_xpd__[1][1]) + (__x_xpd__[3][5] * __y_xpd__[1][0]));
				__tmp_coord_array_3__[14] += ((__x_xpd__[3][3] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[1][1]) + (__x_xpd__[3][0] * __y_xpd__[1][2]));
				__tmp_coord_array_3__[15] += ((-1.0f * __x_xpd__[3][3] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[1][1]));
				__tmp_coord_array_3__[26] += ((-1.0f * __x_xpd__[3][0] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[1][2]) + (__x_xpd__[3][9] * __y_xpd__[1][4]));
				__tmp_coord_array_3__[27] += ((__x_xpd__[3][6] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[1][0]) + (__x_xpd__[3][3] * __y_xpd__[1][2]));
				__tmp_coord_array_3__[28] += ((-1.0f * __x_xpd__[3][1] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[1][1]) + (__x_xpd__[3][4] * __y_xpd__[1][3]));
				__tmp_coord_array_3__[29] += ((__x_xpd__[3][5] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[1][0]) + (__x_xpd__[3][8] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[1][2]));
				__tmp_coord_array_3__[30] += ((__x_xpd__[3][8] * __y_xpd__[1][3]) + (__x_xpd__[3][6] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[1][0]));

			}
			if (((y.m_gu & 4) != 0)) {
				__tmp_coord_array_3__[1] += ((-1.0f * __x_xpd__[3][5] * __y_xpd__[2][7]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[3][8] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[2][8]) + (__x_xpd__[3][7] * __y_xpd__[2][5]));
				__tmp_coord_array_3__[2] += ((__x_xpd__[3][8] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[2][7]) + (__x_xpd__[3][1] * __y_xpd__[2][8]) + (__x_xpd__[3][7] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[2][4]) + (__x_xpd__[3][4] * __y_xpd__[2][9]));
				__tmp_coord_array_3__[3] += ((__x_xpd__[3][5] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[2][5]) + (__x_xpd__[3][2] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[3][8] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[2][8]) + (__x_xpd__[3][6] * __y_xpd__[2][2]));
				__tmp_coord_array_3__[4] += ((-1.0f * __x_xpd__[3][7] * __y_xpd__[2][0]) + (__x_xpd__[3][0] * __y_xpd__[2][7]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[2][1]) + (__x_xpd__[3][3] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[2][6]));
				__tmp_coord_array_3__[5] += ((-1.0f * __x_xpd__[3][3] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[2][5]));
				__tmp_coord_array_3__[16] += ((__x_xpd__[3][6] * __y_xpd__[2][9]) + (__x_xpd__[3][2] * __y_xpd__[2][5]) + (__x_xpd__[3][9] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[2][2]) + (__x_xpd__[3][3] * __y_xpd__[2][1]));
				__tmp_coord_array_3__[17] += ((__x_xpd__[3][4] * __y_xpd__[2][2]) + (__x_xpd__[3][0] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[2][9]) + (__x_xpd__[3][9] * __y_xpd__[2][7]));
				__tmp_coord_array_3__[18] += ((__x_xpd__[3][8] * __y_xpd__[2][9]) + (__x_xpd__[3][5] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[2][1]) + (__x_xpd__[3][1] * __y_xpd__[2][4]) + (__x_xpd__[3][9] * __y_xpd__[2][8]));
				__tmp_coord_array_3__[19] += ((-1.0f * __x_xpd__[3][6] * __y_xpd__[2][7]) + (__x_xpd__[3][1] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[2][1]) + (__x_xpd__[3][5] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[2][6]));
				__tmp_coord_array_3__[20] += ((__x_xpd__[3][7] * __y_xpd__[2][8]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[2][2]) + (__x_xpd__[3][8] * __y_xpd__[2][7]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[2][3]) + (__x_xpd__[3][3] * __y_xpd__[2][5]) + (__x_xpd__[3][2] * __y_xpd__[2][1]));
				__tmp_coord_array_3__[21] += ((__x_xpd__[3][6] * __y_xpd__[2][8]) + (-1.0f * __x_xpd__[3][8] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[2][0]) + (__x_xpd__[3][0] * __y_xpd__[2][2]) + (__x_xpd__[3][4] * __y_xpd__[2][3]));
				__tmp_coord_array_3__[22] += ((__x_xpd__[3][8] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[2][0]) + (__x_xpd__[3][7] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[2][9]) + (__x_xpd__[3][3] * __y_xpd__[2][7]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[2][8]));
				__tmp_coord_array_3__[23] += ((__x_xpd__[3][8] * __y_xpd__[2][4]) + (__x_xpd__[3][9] * __y_xpd__[2][1]) + (__x_xpd__[3][1] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[2][3]) + (__x_xpd__[3][3] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[2][8]));
				__tmp_coord_array_3__[24] += ((-1.0f * __x_xpd__[3][9] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[2][9]) + (__x_xpd__[3][5] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[2][7]));
				__tmp_coord_array_3__[25] += ((-1.0f * __x_xpd__[3][0] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[2][7]) + (__x_xpd__[3][8] * __y_xpd__[2][2]) + (__x_xpd__[3][6] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[2][8]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[2][1]));
				__tmp_coord_array_3__[31] += ((__x_xpd__[3][2] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[2][7]) + (__x_xpd__[3][4] * __y_xpd__[2][4]) + (__x_xpd__[3][0] * __y_xpd__[2][0]) + (__x_xpd__[3][3] * __y_xpd__[2][3]) + (__x_xpd__[3][5] * __y_xpd__[2][5]) + (__x_xpd__[3][6] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[2][9]) + (__x_xpd__[3][8] * __y_xpd__[2][8]) + (__x_xpd__[3][1] * __y_xpd__[2][1]));

			}
			if (((y.m_gu & 8) != 0)) {
				__tmp_coord_array_3__[0] += ((-1.0f * __x_xpd__[3][7] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[3][8] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[3][6]));
				__tmp_coord_array_3__[6] += ((__x_xpd__[3][3] * __y_xpd__[3][1]) + (__x_xpd__[3][9] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[3][2]) + (__x_xpd__[3][2] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[3][3]));
				__tmp_coord_array_3__[7] += ((-1.0f * __x_xpd__[3][2] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[3][0]) + (__x_xpd__[3][0] * __y_xpd__[3][3]) + (__x_xpd__[3][7] * __y_xpd__[3][9]) + (__x_xpd__[3][4] * __y_xpd__[3][2]));
				__tmp_coord_array_3__[8] += ((__x_xpd__[3][5] * __y_xpd__[3][0]) + (__x_xpd__[3][1] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[3][1]) + (__x_xpd__[3][9] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[3][8] * __y_xpd__[3][9]));
				__tmp_coord_array_3__[9] += ((__x_xpd__[3][5] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[3][5]) + (__x_xpd__[3][6] * __y_xpd__[3][7]) + (__x_xpd__[3][1] * __y_xpd__[3][0]));
				__tmp_coord_array_3__[10] += ((-1.0f * __x_xpd__[3][1] * __y_xpd__[3][2]) + (__x_xpd__[3][7] * __y_xpd__[3][8]) + (__x_xpd__[3][2] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[3][8] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[3][3]) + (__x_xpd__[3][3] * __y_xpd__[3][5]));
				__tmp_coord_array_3__[11] += ((-1.0f * __x_xpd__[3][3] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[3][0]) + (__x_xpd__[3][0] * __y_xpd__[3][2]) + (__x_xpd__[3][4] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[3][8] * __y_xpd__[3][6]) + (__x_xpd__[3][6] * __y_xpd__[3][8]));
				__tmp_coord_array_3__[12] += ((-1.0f * __x_xpd__[3][9] * __y_xpd__[3][0]) + (__x_xpd__[3][7] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[3][7]) + (__x_xpd__[3][0] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[3][8]) + (__x_xpd__[3][8] * __y_xpd__[3][5]));
				__tmp_coord_array_3__[13] += ((__x_xpd__[3][6] * __y_xpd__[3][3]) + (__x_xpd__[3][1] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[3][8] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[3][1]) + (__x_xpd__[3][4] * __y_xpd__[3][8]));
				__tmp_coord_array_3__[14] += ((__x_xpd__[3][2] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[3][4]) + (__x_xpd__[3][4] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[3][2]) + (__x_xpd__[3][5] * __y_xpd__[3][6]));
				__tmp_coord_array_3__[15] += ((-1.0f * __x_xpd__[3][8] * __y_xpd__[3][2]) + (__x_xpd__[3][0] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[3][7]) + (__x_xpd__[3][7] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[3][0]) + (__x_xpd__[3][2] * __y_xpd__[3][8]));
				__tmp_coord_array_3__[26] += ((-1.0f * __x_xpd__[3][7] * __y_xpd__[3][5]) + (__x_xpd__[3][3] * __y_xpd__[3][8]) + (__x_xpd__[3][4] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[3][7]) + (__x_xpd__[3][6] * __y_xpd__[3][4]) + (__x_xpd__[3][8] * __y_xpd__[3][3]));
				__tmp_coord_array_3__[27] += ((-1.0f * __x_xpd__[3][4] * __y_xpd__[3][9]) + (__x_xpd__[3][7] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[3][4]) + (__x_xpd__[3][1] * __y_xpd__[3][8]) + (__x_xpd__[3][8] * __y_xpd__[3][1]) + (__x_xpd__[3][2] * __y_xpd__[3][7]));
				__tmp_coord_array_3__[28] += ((__x_xpd__[3][2] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[3][8] * __y_xpd__[3][0]) + (__x_xpd__[3][6] * __y_xpd__[3][2]));
				__tmp_coord_array_3__[29] += ((-1.0f * __x_xpd__[3][7] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[3][6]));
				__tmp_coord_array_3__[30] += ((__x_xpd__[3][0] * __y_xpd__[3][4]) + (__x_xpd__[3][3] * __y_xpd__[3][2]) + (__x_xpd__[3][4] * __y_xpd__[3][0]) + (__x_xpd__[3][1] * __y_xpd__[3][5]) + (__x_xpd__[3][5] * __y_xpd__[3][1]) + (__x_xpd__[3][2] * __y_xpd__[3][3]));

			}
			if (((y.m_gu & 16) != 0)) {
				__tmp_coord_array_3__[1] += ((__x_xpd__[3][9] * __y_xpd__[4][4]) + (__x_xpd__[3][0] * __y_xpd__[4][1]) + (__x_xpd__[3][1] * __y_xpd__[4][2]) + (__x_xpd__[3][2] * __y_xpd__[4][3]));
				__tmp_coord_array_3__[2] += ((-1.0f * __x_xpd__[3][6] * __y_xpd__[4][4]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[4][3]) + (__x_xpd__[3][0] * __y_xpd__[4][0]) + (__x_xpd__[3][3] * __y_xpd__[4][2]));
				__tmp_coord_array_3__[3] += ((__x_xpd__[3][4] * __y_xpd__[4][3]) + (__x_xpd__[3][7] * __y_xpd__[4][4]) + (__x_xpd__[3][1] * __y_xpd__[4][0]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[4][1]));
				__tmp_coord_array_3__[4] += ((-1.0f * __x_xpd__[3][4] * __y_xpd__[4][2]) + (__x_xpd__[3][2] * __y_xpd__[4][0]) + (-1.0f * __x_xpd__[3][8] * __y_xpd__[4][4]) + (__x_xpd__[3][5] * __y_xpd__[4][1]));
				__tmp_coord_array_3__[5] += ((__x_xpd__[3][7] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[3][8] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[4][0]));
				__tmp_coord_array_3__[16] += ((__x_xpd__[3][7] * __y_xpd__[4][3]) + (__x_xpd__[3][8] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[4][4]));
				__tmp_coord_array_3__[17] += ((__x_xpd__[3][6] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[3][8] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[4][4]));
				__tmp_coord_array_3__[18] += ((-1.0f * __x_xpd__[3][7] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[4][4]));
				__tmp_coord_array_3__[19] += ((-1.0f * __x_xpd__[3][2] * __y_xpd__[4][4]) + (__x_xpd__[3][9] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[3][8] * __y_xpd__[4][0]));
				__tmp_coord_array_3__[20] += ((__x_xpd__[3][9] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[4][4]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[4][0]));
				__tmp_coord_array_3__[21] += ((__x_xpd__[3][7] * __y_xpd__[4][0]) + (__x_xpd__[3][9] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[4][4]));
				__tmp_coord_array_3__[22] += ((__x_xpd__[3][1] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[4][0]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[4][2]));
				__tmp_coord_array_3__[23] += ((__x_xpd__[3][0] * __y_xpd__[4][3]) + (__x_xpd__[3][5] * __y_xpd__[4][0]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[4][1]));
				__tmp_coord_array_3__[24] += ((-1.0f * __x_xpd__[3][1] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[4][0]) + (__x_xpd__[3][0] * __y_xpd__[4][2]));
				__tmp_coord_array_3__[25] += ((__x_xpd__[3][5] * __y_xpd__[4][2]) + (__x_xpd__[3][4] * __y_xpd__[4][1]) + (__x_xpd__[3][3] * __y_xpd__[4][3]));

			}
			if (((y.m_gu & 32) != 0)) {
				__tmp_coord_array_3__[6] += (-1.0f * __x_xpd__[3][0] * __y_xpd__[5][0]);
				__tmp_coord_array_3__[7] += (-1.0f * __x_xpd__[3][1] * __y_xpd__[5][0]);
				__tmp_coord_array_3__[8] += (-1.0f * __x_xpd__[3][2] * __y_xpd__[5][0]);
				__tmp_coord_array_3__[9] += (-1.0f * __x_xpd__[3][3] * __y_xpd__[5][0]);
				__tmp_coord_array_3__[10] += (-1.0f * __x_xpd__[3][4] * __y_xpd__[5][0]);
				__tmp_coord_array_3__[11] += (-1.0f * __x_xpd__[3][5] * __y_xpd__[5][0]);
				__tmp_coord_array_3__[12] += (-1.0f * __x_xpd__[3][6] * __y_xpd__[5][0]);
				__tmp_coord_array_3__[13] += (__x_xpd__[3][7] * __y_xpd__[5][0]);
				__tmp_coord_array_3__[14] += (-1.0f * __x_xpd__[3][8] * __y_xpd__[5][0]);
				__tmp_coord_array_3__[15] += (__x_xpd__[3][9] * __y_xpd__[5][0]);

			}

		}
		if (((x.m_gu & 16) != 0)) {
			if (((y.m_gu & 1) != 0)) {
				__tmp_coord_array_3__[26] += (__x_xpd__[4][0] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[27] += (__x_xpd__[4][1] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[28] += (__x_xpd__[4][2] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[29] += (__x_xpd__[4][3] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[30] += (__x_xpd__[4][4] * __y_xpd__[0][0]);

			}
			if (((y.m_gu & 2) != 0)) {
				__tmp_coord_array_3__[16] += ((-1.0f * __x_xpd__[4][0] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[4][1] * __y_xpd__[1][0]));
				__tmp_coord_array_3__[17] += ((-1.0f * __x_xpd__[4][0] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[4][2] * __y_xpd__[1][0]));
				__tmp_coord_array_3__[18] += ((-1.0f * __x_xpd__[4][3] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[4][0] * __y_xpd__[1][3]));
				__tmp_coord_array_3__[19] += ((-1.0f * __x_xpd__[4][2] * __y_xpd__[1][1]) + (__x_xpd__[4][1] * __y_xpd__[1][2]));
				__tmp_coord_array_3__[20] += ((-1.0f * __x_xpd__[4][3] * __y_xpd__[1][2]) + (__x_xpd__[4][2] * __y_xpd__[1][3]));
				__tmp_coord_array_3__[21] += ((-1.0f * __x_xpd__[4][1] * __y_xpd__[1][3]) + (__x_xpd__[4][3] * __y_xpd__[1][1]));
				__tmp_coord_array_3__[22] += ((__x_xpd__[4][1] * __y_xpd__[1][4]) + (__x_xpd__[4][4] * __y_xpd__[1][1]));
				__tmp_coord_array_3__[23] += ((-1.0f * __x_xpd__[4][4] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[4][2] * __y_xpd__[1][4]));
				__tmp_coord_array_3__[24] += ((__x_xpd__[4][3] * __y_xpd__[1][4]) + (__x_xpd__[4][4] * __y_xpd__[1][3]));
				__tmp_coord_array_3__[25] += ((-1.0f * __x_xpd__[4][4] * __y_xpd__[1][0]) + (__x_xpd__[4][0] * __y_xpd__[1][4]));
				__tmp_coord_array_3__[31] += ((__x_xpd__[4][0] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[4][3] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[4][2] * __y_xpd__[1][2]) + (__x_xpd__[4][4] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[4][1] * __y_xpd__[1][1]));

			}
			if (((y.m_gu & 4) != 0)) {
				__tmp_coord_array_3__[6] += ((-1.0f * __x_xpd__[4][3] * __y_xpd__[2][7]) + (-1.0f * __x_xpd__[4][4] * __y_xpd__[2][4]) + (__x_xpd__[4][2] * __y_xpd__[2][8]));
				__tmp_coord_array_3__[7] += ((-1.0f * __x_xpd__[4][1] * __y_xpd__[2][8]) + (__x_xpd__[4][3] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[4][4] * __y_xpd__[2][5]));
				__tmp_coord_array_3__[8] += ((__x_xpd__[4][1] * __y_xpd__[2][7]) + (-1.0f * __x_xpd__[4][4] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[4][2] * __y_xpd__[2][6]));
				__tmp_coord_array_3__[9] += ((-1.0f * __x_xpd__[4][3] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[4][0] * __y_xpd__[2][8]) + (-1.0f * __x_xpd__[4][4] * __y_xpd__[2][2]));
				__tmp_coord_array_3__[10] += ((-1.0f * __x_xpd__[4][1] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[4][0] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[4][4] * __y_xpd__[2][0]));
				__tmp_coord_array_3__[11] += ((-1.0f * __x_xpd__[4][0] * __y_xpd__[2][7]) + (-1.0f * __x_xpd__[4][2] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[4][4] * __y_xpd__[2][1]));
				__tmp_coord_array_3__[12] += ((-1.0f * __x_xpd__[4][0] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[4][2] * __y_xpd__[2][2]) + (__x_xpd__[4][3] * __y_xpd__[2][1]));
				__tmp_coord_array_3__[13] += ((-1.0f * __x_xpd__[4][3] * __y_xpd__[2][0]) + (__x_xpd__[4][1] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[4][0] * __y_xpd__[2][5]));
				__tmp_coord_array_3__[14] += ((__x_xpd__[4][2] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[4][1] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[4][0] * __y_xpd__[2][3]));
				__tmp_coord_array_3__[15] += ((-1.0f * __x_xpd__[4][1] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[4][2] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[4][3] * __y_xpd__[2][3]));
				__tmp_coord_array_3__[26] += ((__x_xpd__[4][1] * __y_xpd__[2][0]) + (__x_xpd__[4][2] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[4][4] * __y_xpd__[2][9]) + (__x_xpd__[4][3] * __y_xpd__[2][2]));
				__tmp_coord_array_3__[27] += ((__x_xpd__[4][4] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[4][2] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[4][0] * __y_xpd__[2][0]) + (__x_xpd__[4][3] * __y_xpd__[2][5]));
				__tmp_coord_array_3__[28] += ((__x_xpd__[4][1] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[4][0] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[4][3] * __y_xpd__[2][4]) + (__x_xpd__[4][4] * __y_xpd__[2][7]));
				__tmp_coord_array_3__[29] += ((__x_xpd__[4][4] * __y_xpd__[2][8]) + (-1.0f * __x_xpd__[4][0] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[4][1] * __y_xpd__[2][5]) + (__x_xpd__[4][2] * __y_xpd__[2][4]));
				__tmp_coord_array_3__[30] += ((-1.0f * __x_xpd__[4][1] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[4][3] * __y_xpd__[2][8]) + (-1.0f * __x_xpd__[4][2] * __y_xpd__[2][7]) + (__x_xpd__[4][0] * __y_xpd__[2][9]));

			}
			if (((y.m_gu & 8) != 0)) {
				__tmp_coord_array_3__[1] += ((-1.0f * __x_xpd__[4][3] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[4][2] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[4][4] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[4][1] * __y_xpd__[3][0]));
				__tmp_coord_array_3__[2] += ((__x_xpd__[4][3] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[4][2] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[4][0] * __y_xpd__[3][0]) + (__x_xpd__[4][4] * __y_xpd__[3][6]));
				__tmp_coord_array_3__[3] += ((-1.0f * __x_xpd__[4][0] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[4][4] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[4][3] * __y_xpd__[3][4]) + (__x_xpd__[4][1] * __y_xpd__[3][3]));
				__tmp_coord_array_3__[4] += ((__x_xpd__[4][4] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[4][0] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[4][1] * __y_xpd__[3][5]) + (__x_xpd__[4][2] * __y_xpd__[3][4]));
				__tmp_coord_array_3__[5] += ((__x_xpd__[4][3] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[4][2] * __y_xpd__[3][7]) + (__x_xpd__[4][1] * __y_xpd__[3][6]) + (__x_xpd__[4][0] * __y_xpd__[3][9]));
				__tmp_coord_array_3__[16] += ((__x_xpd__[4][2] * __y_xpd__[3][8]) + (__x_xpd__[4][3] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[4][4] * __y_xpd__[3][4]));
				__tmp_coord_array_3__[17] += ((__x_xpd__[4][3] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[4][1] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[4][4] * __y_xpd__[3][5]));
				__tmp_coord_array_3__[18] += ((-1.0f * __x_xpd__[4][2] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[4][1] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[4][4] * __y_xpd__[3][3]));
				__tmp_coord_array_3__[19] += ((-1.0f * __x_xpd__[4][0] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[4][4] * __y_xpd__[3][2]) + (__x_xpd__[4][3] * __y_xpd__[3][9]));
				__tmp_coord_array_3__[20] += ((-1.0f * __x_xpd__[4][0] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[4][4] * __y_xpd__[3][0]) + (__x_xpd__[4][1] * __y_xpd__[3][9]));
				__tmp_coord_array_3__[21] += ((__x_xpd__[4][2] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[4][4] * __y_xpd__[3][1]) + (__x_xpd__[4][0] * __y_xpd__[3][7]));
				__tmp_coord_array_3__[22] += ((__x_xpd__[4][3] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[4][0] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[4][2] * __y_xpd__[3][2]));
				__tmp_coord_array_3__[23] += ((__x_xpd__[4][0] * __y_xpd__[3][5]) + (__x_xpd__[4][3] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[4][1] * __y_xpd__[3][2]));
				__tmp_coord_array_3__[24] += ((-1.0f * __x_xpd__[4][0] * __y_xpd__[3][3]) + (__x_xpd__[4][2] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[4][1] * __y_xpd__[3][1]));
				__tmp_coord_array_3__[25] += ((__x_xpd__[4][3] * __y_xpd__[3][3]) + (__x_xpd__[4][2] * __y_xpd__[3][5]) + (__x_xpd__[4][1] * __y_xpd__[3][4]));

			}
			if (((y.m_gu & 16) != 0)) {
				__tmp_coord_array_3__[0] += ((__x_xpd__[4][4] * __y_xpd__[4][4]) + (__x_xpd__[4][1] * __y_xpd__[4][1]) + (__x_xpd__[4][0] * __y_xpd__[4][0]) + (__x_xpd__[4][3] * __y_xpd__[4][3]) + (__x_xpd__[4][2] * __y_xpd__[4][2]));
				__tmp_coord_array_3__[6] += ((-1.0f * __x_xpd__[4][0] * __y_xpd__[4][1]) + (__x_xpd__[4][1] * __y_xpd__[4][0]));
				__tmp_coord_array_3__[7] += ((__x_xpd__[4][2] * __y_xpd__[4][0]) + (-1.0f * __x_xpd__[4][0] * __y_xpd__[4][2]));
				__tmp_coord_array_3__[8] += ((__x_xpd__[4][3] * __y_xpd__[4][0]) + (-1.0f * __x_xpd__[4][0] * __y_xpd__[4][3]));
				__tmp_coord_array_3__[9] += ((-1.0f * __x_xpd__[4][2] * __y_xpd__[4][1]) + (__x_xpd__[4][1] * __y_xpd__[4][2]));
				__tmp_coord_array_3__[10] += ((-1.0f * __x_xpd__[4][3] * __y_xpd__[4][2]) + (__x_xpd__[4][2] * __y_xpd__[4][3]));
				__tmp_coord_array_3__[11] += ((-1.0f * __x_xpd__[4][1] * __y_xpd__[4][3]) + (__x_xpd__[4][3] * __y_xpd__[4][1]));
				__tmp_coord_array_3__[12] += ((__x_xpd__[4][4] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[4][1] * __y_xpd__[4][4]));
				__tmp_coord_array_3__[13] += ((-1.0f * __x_xpd__[4][2] * __y_xpd__[4][4]) + (__x_xpd__[4][4] * __y_xpd__[4][2]));
				__tmp_coord_array_3__[14] += ((__x_xpd__[4][4] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[4][3] * __y_xpd__[4][4]));
				__tmp_coord_array_3__[15] += ((-1.0f * __x_xpd__[4][4] * __y_xpd__[4][0]) + (__x_xpd__[4][0] * __y_xpd__[4][4]));

			}
			if (((y.m_gu & 32) != 0)) {
				__tmp_coord_array_3__[1] += (__x_xpd__[4][0] * __y_xpd__[5][0]);
				__tmp_coord_array_3__[2] += (-1.0f * __x_xpd__[4][1] * __y_xpd__[5][0]);
				__tmp_coord_array_3__[3] += (-1.0f * __x_xpd__[4][2] * __y_xpd__[5][0]);
				__tmp_coord_array_3__[4] += (-1.0f * __x_xpd__[4][3] * __y_xpd__[5][0]);
				__tmp_coord_array_3__[5] += (__x_xpd__[4][4] * __y_xpd__[5][0]);

			}

		}
		if (((x.m_gu & 32) != 0)) {
			if (((y.m_gu & 1) != 0)) {
				__tmp_coord_array_3__[31] += (__x_xpd__[5][0] * __y_xpd__[0][0]);

			}
			if (((y.m_gu & 2) != 0)) {
				__tmp_coord_array_3__[26] += (__x_xpd__[5][0] * __y_xpd__[1][0]);
				__tmp_coord_array_3__[27] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[1][1]);
				__tmp_coord_array_3__[28] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[1][2]);
				__tmp_coord_array_3__[29] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[1][3]);
				__tmp_coord_array_3__[30] += (__x_xpd__[5][0] * __y_xpd__[1][4]);

			}
			if (((y.m_gu & 4) != 0)) {
				__tmp_coord_array_3__[16] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[2][0]);
				__tmp_coord_array_3__[17] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[2][1]);
				__tmp_coord_array_3__[18] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[2][2]);
				__tmp_coord_array_3__[19] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[2][3]);
				__tmp_coord_array_3__[20] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[2][4]);
				__tmp_coord_array_3__[21] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[2][5]);
				__tmp_coord_array_3__[22] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[2][6]);
				__tmp_coord_array_3__[23] += (__x_xpd__[5][0] * __y_xpd__[2][7]);
				__tmp_coord_array_3__[24] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[2][8]);
				__tmp_coord_array_3__[25] += (__x_xpd__[5][0] * __y_xpd__[2][9]);

			}
			if (((y.m_gu & 8) != 0)) {
				__tmp_coord_array_3__[6] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[3][0]);
				__tmp_coord_array_3__[7] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[3][1]);
				__tmp_coord_array_3__[8] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[3][2]);
				__tmp_coord_array_3__[9] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[3][3]);
				__tmp_coord_array_3__[10] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[3][4]);
				__tmp_coord_array_3__[11] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[3][5]);
				__tmp_coord_array_3__[12] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[3][6]);
				__tmp_coord_array_3__[13] += (__x_xpd__[5][0] * __y_xpd__[3][7]);
				__tmp_coord_array_3__[14] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[3][8]);
				__tmp_coord_array_3__[15] += (__x_xpd__[5][0] * __y_xpd__[3][9]);

			}
			if (((y.m_gu & 16) != 0)) {
				__tmp_coord_array_3__[1] += (__x_xpd__[5][0] * __y_xpd__[4][0]);
				__tmp_coord_array_3__[2] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[4][1]);
				__tmp_coord_array_3__[3] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[4][2]);
				__tmp_coord_array_3__[4] += (-1.0f * __x_xpd__[5][0] * __y_xpd__[4][3]);
				__tmp_coord_array_3__[5] += (__x_xpd__[5][0] * __y_xpd__[4][4]);

			}
			if (((y.m_gu & 32) != 0)) {
				__tmp_coord_array_3__[0] += (__x_xpd__[5][0] * __y_xpd__[5][0]);

			}

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_3__);
		return __temp_var_1__;
	}
	scalar scpEM(const mv& x, const mv& y) {
		scalar __temp_var_1__;
		const float* __y_xpd__[6] ;
		y.expand(__y_xpd__, true);
		const float* __x_xpd__[6] ;
		x.expand(__x_xpd__, true);
		if (((y.m_gu & 1) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__temp_var_1__.m_c[0] += (__x_xpd__[0][0] * __y_xpd__[0][0]);

			}

		}
		if (((y.m_gu & 2) != 0)) {
			if (((x.m_gu & 2) != 0)) {
				__temp_var_1__.m_c[0] += ((__x_xpd__[1][2] * __y_xpd__[1][2]) + (__x_xpd__[1][1] * __y_xpd__[1][1]) + (__x_xpd__[1][0] * __y_xpd__[1][0]) + (__x_xpd__[1][4] * __y_xpd__[1][4]) + (__x_xpd__[1][3] * __y_xpd__[1][3]));

			}

		}
		if (((y.m_gu & 4) != 0)) {
			if (((x.m_gu & 4) != 0)) {
				__temp_var_1__.m_c[0] += ((-1.0f * __x_xpd__[2][5] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[2][8]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[2][7]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[2][1]));

			}

		}
		if (((y.m_gu & 8) != 0)) {
			if (((x.m_gu & 8) != 0)) {
				__temp_var_1__.m_c[0] += ((-1.0f * __x_xpd__[3][5] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[3][8] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[3][0]));

			}

		}
		if (((y.m_gu & 16) != 0)) {
			if (((x.m_gu & 16) != 0)) {
				__temp_var_1__.m_c[0] += ((__x_xpd__[4][4] * __y_xpd__[4][4]) + (__x_xpd__[4][3] * __y_xpd__[4][3]) + (__x_xpd__[4][2] * __y_xpd__[4][2]) + (__x_xpd__[4][1] * __y_xpd__[4][1]) + (__x_xpd__[4][0] * __y_xpd__[4][0]));

			}

		}
		if (((y.m_gu & 32) != 0)) {
			if (((x.m_gu & 32) != 0)) {
				__temp_var_1__.m_c[0] += (__x_xpd__[5][0] * __y_xpd__[5][0]);

			}

		}
		return __temp_var_1__;
	}
	mv lcontEM(const mv& x, const mv& y) {
		mv __temp_var_1__;
		float __tmp_coord_array_4__[32] ;
		mv_zero(__tmp_coord_array_4__, 32);
		const float* __y_xpd__[6] ;
		y.expand(__y_xpd__, true);
		const float* __x_xpd__[6] ;
		x.expand(__x_xpd__, true);
		if (((y.m_gu & 1) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_4__[0] += (__x_xpd__[0][0] * __y_xpd__[0][0]);

			}

		}
		if (((y.m_gu & 2) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_4__[1] += (__y_xpd__[1][0] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[2] += (__y_xpd__[1][1] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[3] += (__y_xpd__[1][2] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[4] += (__y_xpd__[1][3] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[5] += (__y_xpd__[1][4] * __x_xpd__[0][0]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_4__[0] += ((__x_xpd__[1][2] * __y_xpd__[1][2]) + (__x_xpd__[1][1] * __y_xpd__[1][1]) + (__x_xpd__[1][4] * __y_xpd__[1][4]) + (__x_xpd__[1][3] * __y_xpd__[1][3]) + (__x_xpd__[1][0] * __y_xpd__[1][0]));

			}

		}
		if (((y.m_gu & 4) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_4__[6] += (__y_xpd__[2][0] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[7] += (__y_xpd__[2][1] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[8] += (__y_xpd__[2][2] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[9] += (__y_xpd__[2][3] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[10] += (__y_xpd__[2][4] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[11] += (__y_xpd__[2][5] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[12] += (__y_xpd__[2][6] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[13] += (__y_xpd__[2][7] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[14] += (__y_xpd__[2][8] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[15] += (__y_xpd__[2][9] * __x_xpd__[0][0]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_4__[1] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[2][9]));
				__tmp_coord_array_4__[2] += ((-1.0f * __x_xpd__[1][4] * __y_xpd__[2][6]) + (__x_xpd__[1][3] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[2][3]) + (__x_xpd__[1][0] * __y_xpd__[2][0]));
				__tmp_coord_array_4__[3] += ((__x_xpd__[1][0] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[2][7]) + (__x_xpd__[1][1] * __y_xpd__[2][3]));
				__tmp_coord_array_4__[4] += ((__x_xpd__[1][0] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[2][8]) + (__x_xpd__[1][2] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[2][5]));
				__tmp_coord_array_4__[5] += ((__x_xpd__[1][0] * __y_xpd__[2][9]) + (__x_xpd__[1][2] * __y_xpd__[2][7]) + (__x_xpd__[1][3] * __y_xpd__[2][8]) + (__x_xpd__[1][1] * __y_xpd__[2][6]));

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_4__[0] += ((-1.0f * __x_xpd__[2][5] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[2][7]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[2][8]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[2][4]));

			}

		}
		if (((y.m_gu & 8) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_4__[16] += (__y_xpd__[3][0] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[17] += (__y_xpd__[3][1] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[18] += (__y_xpd__[3][2] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[19] += (__y_xpd__[3][3] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[20] += (__y_xpd__[3][4] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[21] += (__y_xpd__[3][5] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[22] += (__y_xpd__[3][6] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[23] += (__y_xpd__[3][7] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[24] += (__y_xpd__[3][8] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[25] += (__y_xpd__[3][9] * __x_xpd__[0][0]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_4__[6] += ((__x_xpd__[1][3] * __y_xpd__[3][7]) + (__x_xpd__[1][4] * __y_xpd__[3][4]) + (__x_xpd__[1][2] * __y_xpd__[3][8]));
				__tmp_coord_array_4__[7] += ((__x_xpd__[1][4] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[3][8]) + (__x_xpd__[1][3] * __y_xpd__[3][6]));
				__tmp_coord_array_4__[8] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[3][6]) + (__x_xpd__[1][4] * __y_xpd__[3][3]));
				__tmp_coord_array_4__[9] += ((__x_xpd__[1][3] * __y_xpd__[3][9]) + (__x_xpd__[1][4] * __y_xpd__[3][2]) + (__x_xpd__[1][0] * __y_xpd__[3][8]));
				__tmp_coord_array_4__[10] += ((__x_xpd__[1][1] * __y_xpd__[3][9]) + (__x_xpd__[1][0] * __y_xpd__[3][6]) + (__x_xpd__[1][4] * __y_xpd__[3][0]));
				__tmp_coord_array_4__[11] += ((__x_xpd__[1][2] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[1][0] * __y_xpd__[3][7]) + (__x_xpd__[1][4] * __y_xpd__[3][1]));
				__tmp_coord_array_4__[12] += ((__x_xpd__[1][0] * __y_xpd__[3][4]) + (__x_xpd__[1][3] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[3][2]));
				__tmp_coord_array_4__[13] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[3][0]) + (__x_xpd__[1][1] * __y_xpd__[3][2]) + (__x_xpd__[1][0] * __y_xpd__[3][5]));
				__tmp_coord_array_4__[14] += ((__x_xpd__[1][0] * __y_xpd__[3][3]) + (__x_xpd__[1][2] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[3][1]));
				__tmp_coord_array_4__[15] += ((-1.0f * __x_xpd__[1][2] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[3][3]));

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_4__[1] += ((-1.0f * __x_xpd__[2][8] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[3][8]) + (__x_xpd__[2][5] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[3][6]));
				__tmp_coord_array_4__[2] += ((__x_xpd__[2][1] * __y_xpd__[3][8]) + (__x_xpd__[2][8] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[3][9]) + (__x_xpd__[2][2] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[2][7] * __y_xpd__[3][2]) + (__x_xpd__[2][9] * __y_xpd__[3][4]));
				__tmp_coord_array_4__[3] += ((__x_xpd__[2][9] * __y_xpd__[3][5]) + (__x_xpd__[2][6] * __y_xpd__[3][2]) + (__x_xpd__[2][2] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[3][9]));
				__tmp_coord_array_4__[4] += ((-1.0f * __x_xpd__[2][0] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[3][1]) + (__x_xpd__[2][9] * __y_xpd__[3][3]) + (__x_xpd__[2][7] * __y_xpd__[3][0]));
				__tmp_coord_array_4__[5] += ((-1.0f * __x_xpd__[2][3] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[3][4]));

			}
			if (((x.m_gu & 8) != 0)) {
				__tmp_coord_array_4__[0] += ((-1.0f * __x_xpd__[3][5] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[3][9]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[3][8] * __y_xpd__[3][8]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[3][4]));

			}

		}
		if (((y.m_gu & 16) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_4__[26] += (__y_xpd__[4][0] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[27] += (__y_xpd__[4][1] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[28] += (__y_xpd__[4][2] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[29] += (__y_xpd__[4][3] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[30] += (__y_xpd__[4][4] * __x_xpd__[0][0]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_4__[16] += ((__x_xpd__[1][0] * __y_xpd__[4][1]) + (__x_xpd__[1][1] * __y_xpd__[4][0]));
				__tmp_coord_array_4__[17] += ((__x_xpd__[1][2] * __y_xpd__[4][0]) + (__x_xpd__[1][0] * __y_xpd__[4][2]));
				__tmp_coord_array_4__[18] += ((__x_xpd__[1][0] * __y_xpd__[4][3]) + (__x_xpd__[1][3] * __y_xpd__[4][0]));
				__tmp_coord_array_4__[19] += ((__x_xpd__[1][1] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[4][1]));
				__tmp_coord_array_4__[20] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[4][2]) + (__x_xpd__[1][2] * __y_xpd__[4][3]));
				__tmp_coord_array_4__[21] += ((__x_xpd__[1][3] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[4][3]));
				__tmp_coord_array_4__[22] += ((-1.0f * __x_xpd__[1][4] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[4][4]));
				__tmp_coord_array_4__[23] += ((__x_xpd__[1][2] * __y_xpd__[4][4]) + (__x_xpd__[1][4] * __y_xpd__[4][2]));
				__tmp_coord_array_4__[24] += ((-1.0f * __x_xpd__[1][4] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[4][4]));
				__tmp_coord_array_4__[25] += ((__x_xpd__[1][0] * __y_xpd__[4][4]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[4][0]));

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_4__[6] += ((-1.0f * __x_xpd__[2][7] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[4][4]) + (__x_xpd__[2][8] * __y_xpd__[4][2]));
				__tmp_coord_array_4__[7] += ((__x_xpd__[2][6] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[4][4]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[4][1]));
				__tmp_coord_array_4__[8] += ((-1.0f * __x_xpd__[2][3] * __y_xpd__[4][4]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[4][2]) + (__x_xpd__[2][7] * __y_xpd__[4][1]));
				__tmp_coord_array_4__[9] += ((-1.0f * __x_xpd__[2][8] * __y_xpd__[4][0]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[4][4]));
				__tmp_coord_array_4__[10] += ((-1.0f * __x_xpd__[2][6] * __y_xpd__[4][0]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[4][4]));
				__tmp_coord_array_4__[11] += ((-1.0f * __x_xpd__[2][7] * __y_xpd__[4][0]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[4][4]));
				__tmp_coord_array_4__[12] += ((__x_xpd__[2][1] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[4][0]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[4][2]));
				__tmp_coord_array_4__[13] += ((-1.0f * __x_xpd__[2][0] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[4][0]) + (__x_xpd__[2][2] * __y_xpd__[4][1]));
				__tmp_coord_array_4__[14] += ((__x_xpd__[2][0] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[4][0]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[4][1]));
				__tmp_coord_array_4__[15] += ((-1.0f * __x_xpd__[2][5] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[4][3]));

			}
			if (((x.m_gu & 8) != 0)) {
				__tmp_coord_array_4__[1] += ((__x_xpd__[3][1] * __y_xpd__[4][2]) + (__x_xpd__[3][2] * __y_xpd__[4][3]) + (__x_xpd__[3][0] * __y_xpd__[4][1]) + (__x_xpd__[3][9] * __y_xpd__[4][4]));
				__tmp_coord_array_4__[2] += ((-1.0f * __x_xpd__[3][6] * __y_xpd__[4][4]) + (__x_xpd__[3][3] * __y_xpd__[4][2]) + (__x_xpd__[3][0] * __y_xpd__[4][0]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[4][3]));
				__tmp_coord_array_4__[3] += ((__x_xpd__[3][1] * __y_xpd__[4][0]) + (__x_xpd__[3][4] * __y_xpd__[4][3]) + (__x_xpd__[3][7] * __y_xpd__[4][4]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[4][1]));
				__tmp_coord_array_4__[4] += ((-1.0f * __x_xpd__[3][4] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[3][8] * __y_xpd__[4][4]) + (__x_xpd__[3][5] * __y_xpd__[4][1]) + (__x_xpd__[3][2] * __y_xpd__[4][0]));
				__tmp_coord_array_4__[5] += ((-1.0f * __x_xpd__[3][8] * __y_xpd__[4][3]) + (-1.0f * __x_xpd__[3][6] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[4][0]) + (__x_xpd__[3][7] * __y_xpd__[4][2]));

			}
			if (((x.m_gu & 16) != 0)) {
				__tmp_coord_array_4__[0] += ((__x_xpd__[4][3] * __y_xpd__[4][3]) + (__x_xpd__[4][2] * __y_xpd__[4][2]) + (__x_xpd__[4][0] * __y_xpd__[4][0]) + (__x_xpd__[4][1] * __y_xpd__[4][1]) + (__x_xpd__[4][4] * __y_xpd__[4][4]));

			}

		}
		if (((y.m_gu & 32) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_4__[31] += (__y_xpd__[5][0] * __x_xpd__[0][0]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_4__[26] += (__x_xpd__[1][0] * __y_xpd__[5][0]);
				__tmp_coord_array_4__[27] += (-1.0f * __x_xpd__[1][1] * __y_xpd__[5][0]);
				__tmp_coord_array_4__[28] += (-1.0f * __x_xpd__[1][2] * __y_xpd__[5][0]);
				__tmp_coord_array_4__[29] += (-1.0f * __x_xpd__[1][3] * __y_xpd__[5][0]);
				__tmp_coord_array_4__[30] += (__x_xpd__[1][4] * __y_xpd__[5][0]);

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_4__[16] += (-1.0f * __x_xpd__[2][0] * __y_xpd__[5][0]);
				__tmp_coord_array_4__[17] += (-1.0f * __x_xpd__[2][1] * __y_xpd__[5][0]);
				__tmp_coord_array_4__[18] += (-1.0f * __x_xpd__[2][2] * __y_xpd__[5][0]);
				__tmp_coord_array_4__[19] += (-1.0f * __x_xpd__[2][3] * __y_xpd__[5][0]);
				__tmp_coord_array_4__[20] += (-1.0f * __x_xpd__[2][4] * __y_xpd__[5][0]);
				__tmp_coord_array_4__[21] += (-1.0f * __x_xpd__[2][5] * __y_xpd__[5][0]);
				__tmp_coord_array_4__[22] += (-1.0f * __x_xpd__[2][6] * __y_xpd__[5][0]);
				__tmp_coord_array_4__[23] += (__x_xpd__[2][7] * __y_xpd__[5][0]);
				__tmp_coord_array_4__[24] += (-1.0f * __x_xpd__[2][8] * __y_xpd__[5][0]);
				__tmp_coord_array_4__[25] += (__x_xpd__[2][9] * __y_xpd__[5][0]);

			}
			if (((x.m_gu & 8) != 0)) {
				__tmp_coord_array_4__[6] += (-1.0f * __x_xpd__[3][0] * __y_xpd__[5][0]);
				__tmp_coord_array_4__[7] += (-1.0f * __x_xpd__[3][1] * __y_xpd__[5][0]);
				__tmp_coord_array_4__[8] += (-1.0f * __x_xpd__[3][2] * __y_xpd__[5][0]);
				__tmp_coord_array_4__[9] += (-1.0f * __x_xpd__[3][3] * __y_xpd__[5][0]);
				__tmp_coord_array_4__[10] += (-1.0f * __x_xpd__[3][4] * __y_xpd__[5][0]);
				__tmp_coord_array_4__[11] += (-1.0f * __x_xpd__[3][5] * __y_xpd__[5][0]);
				__tmp_coord_array_4__[12] += (-1.0f * __x_xpd__[3][6] * __y_xpd__[5][0]);
				__tmp_coord_array_4__[13] += (__x_xpd__[3][7] * __y_xpd__[5][0]);
				__tmp_coord_array_4__[14] += (-1.0f * __x_xpd__[3][8] * __y_xpd__[5][0]);
				__tmp_coord_array_4__[15] += (__x_xpd__[3][9] * __y_xpd__[5][0]);

			}
			if (((x.m_gu & 16) != 0)) {
				__tmp_coord_array_4__[1] += (__x_xpd__[4][0] * __y_xpd__[5][0]);
				__tmp_coord_array_4__[2] += (-1.0f * __x_xpd__[4][1] * __y_xpd__[5][0]);
				__tmp_coord_array_4__[3] += (-1.0f * __x_xpd__[4][2] * __y_xpd__[5][0]);
				__tmp_coord_array_4__[4] += (-1.0f * __x_xpd__[4][3] * __y_xpd__[5][0]);
				__tmp_coord_array_4__[5] += (__x_xpd__[4][4] * __y_xpd__[5][0]);

			}
			if (((x.m_gu & 32) != 0)) {
				__tmp_coord_array_4__[0] += (__x_xpd__[5][0] * __y_xpd__[5][0]);

			}

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_4__);
		return __temp_var_1__;
	}
	mv op(const mv& x, const mv& y) {
		mv __temp_var_1__;
		float __tmp_coord_array_5__[32] ;
		mv_zero(__tmp_coord_array_5__, 32);
		const float* __y_xpd__[6] ;
		y.expand(__y_xpd__, true);
		const float* __x_xpd__[6] ;
		x.expand(__x_xpd__, true);
		if (((y.m_gu & 1) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_5__[0] += (__x_xpd__[0][0] * __y_xpd__[0][0]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_5__[1] += (__x_xpd__[1][0] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[2] += (__x_xpd__[1][1] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[3] += (__x_xpd__[1][2] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[4] += (__x_xpd__[1][3] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[5] += (__x_xpd__[1][4] * __y_xpd__[0][0]);

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_5__[6] += (__x_xpd__[2][0] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[7] += (__x_xpd__[2][1] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[8] += (__x_xpd__[2][2] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[9] += (__x_xpd__[2][3] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[10] += (__x_xpd__[2][4] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[11] += (__x_xpd__[2][5] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[12] += (__x_xpd__[2][6] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[13] += (__x_xpd__[2][7] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[14] += (__x_xpd__[2][8] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[15] += (__x_xpd__[2][9] * __y_xpd__[0][0]);

			}
			if (((x.m_gu & 8) != 0)) {
				__tmp_coord_array_5__[16] += (__x_xpd__[3][0] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[17] += (__x_xpd__[3][1] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[18] += (__x_xpd__[3][2] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[19] += (__x_xpd__[3][3] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[20] += (__x_xpd__[3][4] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[21] += (__x_xpd__[3][5] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[22] += (__x_xpd__[3][6] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[23] += (__x_xpd__[3][7] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[24] += (__x_xpd__[3][8] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[25] += (__x_xpd__[3][9] * __y_xpd__[0][0]);

			}
			if (((x.m_gu & 16) != 0)) {
				__tmp_coord_array_5__[26] += (__x_xpd__[4][0] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[27] += (__x_xpd__[4][1] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[28] += (__x_xpd__[4][2] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[29] += (__x_xpd__[4][3] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[30] += (__x_xpd__[4][4] * __y_xpd__[0][0]);

			}
			if (((x.m_gu & 32) != 0)) {
				__tmp_coord_array_5__[31] += (__x_xpd__[5][0] * __y_xpd__[0][0]);

			}

		}
		if (((y.m_gu & 2) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_5__[1] += (__x_xpd__[0][0] * __y_xpd__[1][0]);
				__tmp_coord_array_5__[2] += (__x_xpd__[0][0] * __y_xpd__[1][1]);
				__tmp_coord_array_5__[3] += (__x_xpd__[0][0] * __y_xpd__[1][2]);
				__tmp_coord_array_5__[4] += (__x_xpd__[0][0] * __y_xpd__[1][3]);
				__tmp_coord_array_5__[5] += (__x_xpd__[0][0] * __y_xpd__[1][4]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_5__[6] += ((__x_xpd__[1][0] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[1][0]));
				__tmp_coord_array_5__[7] += ((-1.0f * __x_xpd__[1][2] * __y_xpd__[1][0]) + (__x_xpd__[1][0] * __y_xpd__[1][2]));
				__tmp_coord_array_5__[8] += ((__x_xpd__[1][0] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[1][0]));
				__tmp_coord_array_5__[9] += ((__x_xpd__[1][1] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[1][1]));
				__tmp_coord_array_5__[10] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[1][2]) + (__x_xpd__[1][2] * __y_xpd__[1][3]));
				__tmp_coord_array_5__[11] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[1][3]) + (__x_xpd__[1][3] * __y_xpd__[1][1]));
				__tmp_coord_array_5__[12] += ((-1.0f * __x_xpd__[1][4] * __y_xpd__[1][1]) + (__x_xpd__[1][1] * __y_xpd__[1][4]));
				__tmp_coord_array_5__[13] += ((__x_xpd__[1][2] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[1][2]));
				__tmp_coord_array_5__[14] += ((__x_xpd__[1][3] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[1][3]));
				__tmp_coord_array_5__[15] += ((-1.0f * __x_xpd__[1][4] * __y_xpd__[1][0]) + (__x_xpd__[1][0] * __y_xpd__[1][4]));

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_5__[16] += ((-1.0f * __x_xpd__[2][7] * __y_xpd__[1][3]) + (__x_xpd__[2][8] * __y_xpd__[1][2]) + (__x_xpd__[2][4] * __y_xpd__[1][4]));
				__tmp_coord_array_5__[17] += ((-1.0f * __x_xpd__[2][8] * __y_xpd__[1][1]) + (__x_xpd__[2][6] * __y_xpd__[1][3]) + (__x_xpd__[2][5] * __y_xpd__[1][4]));
				__tmp_coord_array_5__[18] += ((__x_xpd__[2][7] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[1][2]) + (__x_xpd__[2][3] * __y_xpd__[1][4]));
				__tmp_coord_array_5__[19] += ((__x_xpd__[2][8] * __y_xpd__[1][0]) + (__x_xpd__[2][2] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[1][3]));
				__tmp_coord_array_5__[20] += ((__x_xpd__[2][6] * __y_xpd__[1][0]) + (__x_xpd__[2][0] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[1][1]));
				__tmp_coord_array_5__[21] += ((__x_xpd__[2][7] * __y_xpd__[1][0]) + (__x_xpd__[2][1] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[1][2]));
				__tmp_coord_array_5__[22] += ((__x_xpd__[2][4] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[1][2]) + (__x_xpd__[2][1] * __y_xpd__[1][3]));
				__tmp_coord_array_5__[23] += ((-1.0f * __x_xpd__[2][2] * __y_xpd__[1][1]) + (__x_xpd__[2][0] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[1][0]));
				__tmp_coord_array_5__[24] += ((__x_xpd__[2][3] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[1][1]) + (__x_xpd__[2][0] * __y_xpd__[1][2]));
				__tmp_coord_array_5__[25] += ((__x_xpd__[2][5] * __y_xpd__[1][2]) + (__x_xpd__[2][3] * __y_xpd__[1][3]) + (__x_xpd__[2][4] * __y_xpd__[1][1]));

			}
			if (((x.m_gu & 8) != 0)) {
				__tmp_coord_array_5__[26] += ((-1.0f * __x_xpd__[3][2] * __y_xpd__[1][3]) + (__x_xpd__[3][9] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[1][1]));
				__tmp_coord_array_5__[27] += ((__x_xpd__[3][3] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[1][0]) + (__x_xpd__[3][6] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[3][5] * __y_xpd__[1][3]));
				__tmp_coord_array_5__[28] += ((-1.0f * __x_xpd__[3][1] * __y_xpd__[1][0]) + (__x_xpd__[3][4] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[1][1]));
				__tmp_coord_array_5__[29] += ((-1.0f * __x_xpd__[3][2] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[3][4] * __y_xpd__[1][2]) + (__x_xpd__[3][5] * __y_xpd__[1][1]) + (__x_xpd__[3][8] * __y_xpd__[1][4]));
				__tmp_coord_array_5__[30] += ((__x_xpd__[3][8] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[1][0]) + (__x_xpd__[3][6] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[1][2]));

			}
			if (((x.m_gu & 16) != 0)) {
				__tmp_coord_array_5__[31] += ((-1.0f * __x_xpd__[4][2] * __y_xpd__[1][2]) + (__x_xpd__[4][4] * __y_xpd__[1][4]) + (-1.0f * __x_xpd__[4][1] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[4][3] * __y_xpd__[1][3]) + (__x_xpd__[4][0] * __y_xpd__[1][0]));

			}

		}
		if (((y.m_gu & 4) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_5__[6] += (__x_xpd__[0][0] * __y_xpd__[2][0]);
				__tmp_coord_array_5__[7] += (__x_xpd__[0][0] * __y_xpd__[2][1]);
				__tmp_coord_array_5__[8] += (__x_xpd__[0][0] * __y_xpd__[2][2]);
				__tmp_coord_array_5__[9] += (__x_xpd__[0][0] * __y_xpd__[2][3]);
				__tmp_coord_array_5__[10] += (__x_xpd__[0][0] * __y_xpd__[2][4]);
				__tmp_coord_array_5__[11] += (__x_xpd__[0][0] * __y_xpd__[2][5]);
				__tmp_coord_array_5__[12] += (__x_xpd__[0][0] * __y_xpd__[2][6]);
				__tmp_coord_array_5__[13] += (__x_xpd__[0][0] * __y_xpd__[2][7]);
				__tmp_coord_array_5__[14] += (__x_xpd__[0][0] * __y_xpd__[2][8]);
				__tmp_coord_array_5__[15] += (__x_xpd__[0][0] * __y_xpd__[2][9]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_5__[16] += ((__x_xpd__[1][2] * __y_xpd__[2][8]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[2][7]) + (__x_xpd__[1][4] * __y_xpd__[2][4]));
				__tmp_coord_array_5__[17] += ((__x_xpd__[1][3] * __y_xpd__[2][6]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[2][8]) + (__x_xpd__[1][4] * __y_xpd__[2][5]));
				__tmp_coord_array_5__[18] += ((__x_xpd__[1][1] * __y_xpd__[2][7]) + (__x_xpd__[1][4] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[2][6]));
				__tmp_coord_array_5__[19] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[2][9]) + (__x_xpd__[1][0] * __y_xpd__[2][8]) + (__x_xpd__[1][4] * __y_xpd__[2][2]));
				__tmp_coord_array_5__[20] += ((__x_xpd__[1][0] * __y_xpd__[2][6]) + (__x_xpd__[1][4] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[2][9]));
				__tmp_coord_array_5__[21] += ((__x_xpd__[1][0] * __y_xpd__[2][7]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[2][9]) + (__x_xpd__[1][4] * __y_xpd__[2][1]));
				__tmp_coord_array_5__[22] += ((__x_xpd__[1][0] * __y_xpd__[2][4]) + (__x_xpd__[1][3] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[2][2]));
				__tmp_coord_array_5__[23] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[2][2]) + (__x_xpd__[1][3] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[1][0] * __y_xpd__[2][5]));
				__tmp_coord_array_5__[24] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[2][1]) + (__x_xpd__[1][0] * __y_xpd__[2][3]) + (__x_xpd__[1][2] * __y_xpd__[2][0]));
				__tmp_coord_array_5__[25] += ((__x_xpd__[1][2] * __y_xpd__[2][5]) + (__x_xpd__[1][3] * __y_xpd__[2][3]) + (__x_xpd__[1][1] * __y_xpd__[2][4]));

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_5__[26] += ((__x_xpd__[2][8] * __y_xpd__[2][3]) + (__x_xpd__[2][7] * __y_xpd__[2][5]) + (__x_xpd__[2][6] * __y_xpd__[2][4]) + (__x_xpd__[2][4] * __y_xpd__[2][6]) + (__x_xpd__[2][3] * __y_xpd__[2][8]) + (__x_xpd__[2][5] * __y_xpd__[2][7]));
				__tmp_coord_array_5__[27] += ((-1.0f * __x_xpd__[2][7] * __y_xpd__[2][2]) + (__x_xpd__[2][4] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[2][7]) + (__x_xpd__[2][1] * __y_xpd__[2][8]) + (__x_xpd__[2][9] * __y_xpd__[2][4]) + (__x_xpd__[2][8] * __y_xpd__[2][1]));
				__tmp_coord_array_5__[28] += ((__x_xpd__[2][5] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[2][8]) + (__x_xpd__[2][2] * __y_xpd__[2][6]) + (__x_xpd__[2][6] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[2][8] * __y_xpd__[2][0]) + (__x_xpd__[2][9] * __y_xpd__[2][5]));
				__tmp_coord_array_5__[29] += ((__x_xpd__[2][3] * __y_xpd__[2][9]) + (-1.0f * __x_xpd__[2][6] * __y_xpd__[2][1]) + (__x_xpd__[2][9] * __y_xpd__[2][3]) + (__x_xpd__[2][7] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[2][6]) + (__x_xpd__[2][0] * __y_xpd__[2][7]));
				__tmp_coord_array_5__[30] += ((__x_xpd__[2][1] * __y_xpd__[2][5]) + (__x_xpd__[2][3] * __y_xpd__[2][2]) + (__x_xpd__[2][0] * __y_xpd__[2][4]) + (__x_xpd__[2][5] * __y_xpd__[2][1]) + (__x_xpd__[2][4] * __y_xpd__[2][0]) + (__x_xpd__[2][2] * __y_xpd__[2][3]));

			}
			if (((x.m_gu & 8) != 0)) {
				__tmp_coord_array_5__[31] += ((__x_xpd__[3][6] * __y_xpd__[2][6]) + (__x_xpd__[3][5] * __y_xpd__[2][5]) + (__x_xpd__[3][1] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[3][7] * __y_xpd__[2][7]) + (-1.0f * __x_xpd__[3][9] * __y_xpd__[2][9]) + (__x_xpd__[3][3] * __y_xpd__[2][3]) + (__x_xpd__[3][0] * __y_xpd__[2][0]) + (__x_xpd__[3][8] * __y_xpd__[2][8]) + (__x_xpd__[3][2] * __y_xpd__[2][2]) + (__x_xpd__[3][4] * __y_xpd__[2][4]));

			}

		}
		if (((y.m_gu & 8) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_5__[16] += (__x_xpd__[0][0] * __y_xpd__[3][0]);
				__tmp_coord_array_5__[17] += (__x_xpd__[0][0] * __y_xpd__[3][1]);
				__tmp_coord_array_5__[18] += (__x_xpd__[0][0] * __y_xpd__[3][2]);
				__tmp_coord_array_5__[19] += (__x_xpd__[0][0] * __y_xpd__[3][3]);
				__tmp_coord_array_5__[20] += (__x_xpd__[0][0] * __y_xpd__[3][4]);
				__tmp_coord_array_5__[21] += (__x_xpd__[0][0] * __y_xpd__[3][5]);
				__tmp_coord_array_5__[22] += (__x_xpd__[0][0] * __y_xpd__[3][6]);
				__tmp_coord_array_5__[23] += (__x_xpd__[0][0] * __y_xpd__[3][7]);
				__tmp_coord_array_5__[24] += (__x_xpd__[0][0] * __y_xpd__[3][8]);
				__tmp_coord_array_5__[25] += (__x_xpd__[0][0] * __y_xpd__[3][9]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_5__[26] += ((__x_xpd__[1][1] * __y_xpd__[3][0]) + (__x_xpd__[1][2] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[3][9]) + (__x_xpd__[1][3] * __y_xpd__[3][2]));
				__tmp_coord_array_5__[27] += ((__x_xpd__[1][0] * __y_xpd__[3][0]) + (__x_xpd__[1][3] * __y_xpd__[3][5]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[3][6]));
				__tmp_coord_array_5__[28] += ((__x_xpd__[1][0] * __y_xpd__[3][1]) + (__x_xpd__[1][4] * __y_xpd__[3][7]) + (__x_xpd__[1][1] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[3][4]));
				__tmp_coord_array_5__[29] += ((__x_xpd__[1][2] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[1][4] * __y_xpd__[3][8]) + (__x_xpd__[1][0] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[3][5]));
				__tmp_coord_array_5__[30] += ((__x_xpd__[1][2] * __y_xpd__[3][7]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[3][6]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[3][8]) + (__x_xpd__[1][0] * __y_xpd__[3][9]));

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_5__[31] += ((-1.0f * __x_xpd__[2][7] * __y_xpd__[3][7]) + (__x_xpd__[2][4] * __y_xpd__[3][4]) + (-1.0f * __x_xpd__[2][9] * __y_xpd__[3][9]) + (__x_xpd__[2][0] * __y_xpd__[3][0]) + (__x_xpd__[2][5] * __y_xpd__[3][5]) + (__x_xpd__[2][3] * __y_xpd__[3][3]) + (__x_xpd__[2][1] * __y_xpd__[3][1]) + (__x_xpd__[2][2] * __y_xpd__[3][2]) + (__x_xpd__[2][8] * __y_xpd__[3][8]) + (__x_xpd__[2][6] * __y_xpd__[3][6]));

			}

		}
		if (((y.m_gu & 16) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_5__[26] += (__x_xpd__[0][0] * __y_xpd__[4][0]);
				__tmp_coord_array_5__[27] += (__x_xpd__[0][0] * __y_xpd__[4][1]);
				__tmp_coord_array_5__[28] += (__x_xpd__[0][0] * __y_xpd__[4][2]);
				__tmp_coord_array_5__[29] += (__x_xpd__[0][0] * __y_xpd__[4][3]);
				__tmp_coord_array_5__[30] += (__x_xpd__[0][0] * __y_xpd__[4][4]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_5__[31] += ((__x_xpd__[1][4] * __y_xpd__[4][4]) + (__x_xpd__[1][0] * __y_xpd__[4][0]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[4][1]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[4][2]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[4][3]));

			}

		}
		if (((y.m_gu & 32) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_5__[31] += (__x_xpd__[0][0] * __y_xpd__[5][0]);

			}

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_5__);
		return __temp_var_1__;
	}
	mv add(const mv& x, const mv& y) {
		mv __temp_var_1__;
		float __tmp_coord_array_6__[32] ;
		mv_zero(__tmp_coord_array_6__, 32);
		const float* __y_xpd__[6] ;
		y.expand(__y_xpd__, true);
		const float* __x_xpd__[6] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_6__[0] += __x_xpd__[0][0];

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_6__[1] += __x_xpd__[1][0];
			__tmp_coord_array_6__[2] += __x_xpd__[1][1];
			__tmp_coord_array_6__[3] += __x_xpd__[1][2];
			__tmp_coord_array_6__[4] += __x_xpd__[1][3];
			__tmp_coord_array_6__[5] += __x_xpd__[1][4];

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_6__[6] += __x_xpd__[2][0];
			__tmp_coord_array_6__[7] += __x_xpd__[2][1];
			__tmp_coord_array_6__[8] += __x_xpd__[2][2];
			__tmp_coord_array_6__[9] += __x_xpd__[2][3];
			__tmp_coord_array_6__[10] += __x_xpd__[2][4];
			__tmp_coord_array_6__[11] += __x_xpd__[2][5];
			__tmp_coord_array_6__[12] += __x_xpd__[2][6];
			__tmp_coord_array_6__[13] += __x_xpd__[2][7];
			__tmp_coord_array_6__[14] += __x_xpd__[2][8];
			__tmp_coord_array_6__[15] += __x_xpd__[2][9];

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_6__[16] += __x_xpd__[3][0];
			__tmp_coord_array_6__[17] += __x_xpd__[3][1];
			__tmp_coord_array_6__[18] += __x_xpd__[3][2];
			__tmp_coord_array_6__[19] += __x_xpd__[3][3];
			__tmp_coord_array_6__[20] += __x_xpd__[3][4];
			__tmp_coord_array_6__[21] += __x_xpd__[3][5];
			__tmp_coord_array_6__[22] += __x_xpd__[3][6];
			__tmp_coord_array_6__[23] += __x_xpd__[3][7];
			__tmp_coord_array_6__[24] += __x_xpd__[3][8];
			__tmp_coord_array_6__[25] += __x_xpd__[3][9];

		}
		if (((x.m_gu & 16) != 0)) {
			__tmp_coord_array_6__[26] += __x_xpd__[4][0];
			__tmp_coord_array_6__[27] += __x_xpd__[4][1];
			__tmp_coord_array_6__[28] += __x_xpd__[4][2];
			__tmp_coord_array_6__[29] += __x_xpd__[4][3];
			__tmp_coord_array_6__[30] += __x_xpd__[4][4];

		}
		if (((x.m_gu & 32) != 0)) {
			__tmp_coord_array_6__[31] += __x_xpd__[5][0];

		}
		if (((y.m_gu & 1) != 0)) {
			__tmp_coord_array_6__[0] += __y_xpd__[0][0];

		}
		if (((y.m_gu & 2) != 0)) {
			__tmp_coord_array_6__[1] += __y_xpd__[1][0];
			__tmp_coord_array_6__[2] += __y_xpd__[1][1];
			__tmp_coord_array_6__[3] += __y_xpd__[1][2];
			__tmp_coord_array_6__[4] += __y_xpd__[1][3];
			__tmp_coord_array_6__[5] += __y_xpd__[1][4];

		}
		if (((y.m_gu & 4) != 0)) {
			__tmp_coord_array_6__[6] += __y_xpd__[2][0];
			__tmp_coord_array_6__[7] += __y_xpd__[2][1];
			__tmp_coord_array_6__[8] += __y_xpd__[2][2];
			__tmp_coord_array_6__[9] += __y_xpd__[2][3];
			__tmp_coord_array_6__[10] += __y_xpd__[2][4];
			__tmp_coord_array_6__[11] += __y_xpd__[2][5];
			__tmp_coord_array_6__[12] += __y_xpd__[2][6];
			__tmp_coord_array_6__[13] += __y_xpd__[2][7];
			__tmp_coord_array_6__[14] += __y_xpd__[2][8];
			__tmp_coord_array_6__[15] += __y_xpd__[2][9];

		}
		if (((y.m_gu & 8) != 0)) {
			__tmp_coord_array_6__[16] += __y_xpd__[3][0];
			__tmp_coord_array_6__[17] += __y_xpd__[3][1];
			__tmp_coord_array_6__[18] += __y_xpd__[3][2];
			__tmp_coord_array_6__[19] += __y_xpd__[3][3];
			__tmp_coord_array_6__[20] += __y_xpd__[3][4];
			__tmp_coord_array_6__[21] += __y_xpd__[3][5];
			__tmp_coord_array_6__[22] += __y_xpd__[3][6];
			__tmp_coord_array_6__[23] += __y_xpd__[3][7];
			__tmp_coord_array_6__[24] += __y_xpd__[3][8];
			__tmp_coord_array_6__[25] += __y_xpd__[3][9];

		}
		if (((y.m_gu & 16) != 0)) {
			__tmp_coord_array_6__[26] += __y_xpd__[4][0];
			__tmp_coord_array_6__[27] += __y_xpd__[4][1];
			__tmp_coord_array_6__[28] += __y_xpd__[4][2];
			__tmp_coord_array_6__[29] += __y_xpd__[4][3];
			__tmp_coord_array_6__[30] += __y_xpd__[4][4];

		}
		if (((y.m_gu & 32) != 0)) {
			__tmp_coord_array_6__[31] += __y_xpd__[5][0];

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_6__);
		return __temp_var_1__;
	}
	mv subtract(const mv& x, const mv& y) {
		mv __temp_var_1__;
		float __tmp_coord_array_7__[32] ;
		mv_zero(__tmp_coord_array_7__, 32);
		const float* __y_xpd__[6] ;
		y.expand(__y_xpd__, true);
		const float* __x_xpd__[6] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_7__[0] += __x_xpd__[0][0];

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_7__[1] += __x_xpd__[1][0];
			__tmp_coord_array_7__[2] += __x_xpd__[1][1];
			__tmp_coord_array_7__[3] += __x_xpd__[1][2];
			__tmp_coord_array_7__[4] += __x_xpd__[1][3];
			__tmp_coord_array_7__[5] += __x_xpd__[1][4];

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_7__[6] += __x_xpd__[2][0];
			__tmp_coord_array_7__[7] += __x_xpd__[2][1];
			__tmp_coord_array_7__[8] += __x_xpd__[2][2];
			__tmp_coord_array_7__[9] += __x_xpd__[2][3];
			__tmp_coord_array_7__[10] += __x_xpd__[2][4];
			__tmp_coord_array_7__[11] += __x_xpd__[2][5];
			__tmp_coord_array_7__[12] += __x_xpd__[2][6];
			__tmp_coord_array_7__[13] += __x_xpd__[2][7];
			__tmp_coord_array_7__[14] += __x_xpd__[2][8];
			__tmp_coord_array_7__[15] += __x_xpd__[2][9];

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_7__[16] += __x_xpd__[3][0];
			__tmp_coord_array_7__[17] += __x_xpd__[3][1];
			__tmp_coord_array_7__[18] += __x_xpd__[3][2];
			__tmp_coord_array_7__[19] += __x_xpd__[3][3];
			__tmp_coord_array_7__[20] += __x_xpd__[3][4];
			__tmp_coord_array_7__[21] += __x_xpd__[3][5];
			__tmp_coord_array_7__[22] += __x_xpd__[3][6];
			__tmp_coord_array_7__[23] += __x_xpd__[3][7];
			__tmp_coord_array_7__[24] += __x_xpd__[3][8];
			__tmp_coord_array_7__[25] += __x_xpd__[3][9];

		}
		if (((x.m_gu & 16) != 0)) {
			__tmp_coord_array_7__[26] += __x_xpd__[4][0];
			__tmp_coord_array_7__[27] += __x_xpd__[4][1];
			__tmp_coord_array_7__[28] += __x_xpd__[4][2];
			__tmp_coord_array_7__[29] += __x_xpd__[4][3];
			__tmp_coord_array_7__[30] += __x_xpd__[4][4];

		}
		if (((x.m_gu & 32) != 0)) {
			__tmp_coord_array_7__[31] += __x_xpd__[5][0];

		}
		if (((y.m_gu & 1) != 0)) {
			__tmp_coord_array_7__[0] += (-1.0f * __y_xpd__[0][0]);

		}
		if (((y.m_gu & 2) != 0)) {
			__tmp_coord_array_7__[1] += (-1.0f * __y_xpd__[1][0]);
			__tmp_coord_array_7__[2] += (-1.0f * __y_xpd__[1][1]);
			__tmp_coord_array_7__[3] += (-1.0f * __y_xpd__[1][2]);
			__tmp_coord_array_7__[4] += (-1.0f * __y_xpd__[1][3]);
			__tmp_coord_array_7__[5] += (-1.0f * __y_xpd__[1][4]);

		}
		if (((y.m_gu & 4) != 0)) {
			__tmp_coord_array_7__[6] += (-1.0f * __y_xpd__[2][0]);
			__tmp_coord_array_7__[7] += (-1.0f * __y_xpd__[2][1]);
			__tmp_coord_array_7__[8] += (-1.0f * __y_xpd__[2][2]);
			__tmp_coord_array_7__[9] += (-1.0f * __y_xpd__[2][3]);
			__tmp_coord_array_7__[10] += (-1.0f * __y_xpd__[2][4]);
			__tmp_coord_array_7__[11] += (-1.0f * __y_xpd__[2][5]);
			__tmp_coord_array_7__[12] += (-1.0f * __y_xpd__[2][6]);
			__tmp_coord_array_7__[13] += (-1.0f * __y_xpd__[2][7]);
			__tmp_coord_array_7__[14] += (-1.0f * __y_xpd__[2][8]);
			__tmp_coord_array_7__[15] += (-1.0f * __y_xpd__[2][9]);

		}
		if (((y.m_gu & 8) != 0)) {
			__tmp_coord_array_7__[16] += (-1.0f * __y_xpd__[3][0]);
			__tmp_coord_array_7__[17] += (-1.0f * __y_xpd__[3][1]);
			__tmp_coord_array_7__[18] += (-1.0f * __y_xpd__[3][2]);
			__tmp_coord_array_7__[19] += (-1.0f * __y_xpd__[3][3]);
			__tmp_coord_array_7__[20] += (-1.0f * __y_xpd__[3][4]);
			__tmp_coord_array_7__[21] += (-1.0f * __y_xpd__[3][5]);
			__tmp_coord_array_7__[22] += (-1.0f * __y_xpd__[3][6]);
			__tmp_coord_array_7__[23] += (-1.0f * __y_xpd__[3][7]);
			__tmp_coord_array_7__[24] += (-1.0f * __y_xpd__[3][8]);
			__tmp_coord_array_7__[25] += (-1.0f * __y_xpd__[3][9]);

		}
		if (((y.m_gu & 16) != 0)) {
			__tmp_coord_array_7__[26] += (-1.0f * __y_xpd__[4][0]);
			__tmp_coord_array_7__[27] += (-1.0f * __y_xpd__[4][1]);
			__tmp_coord_array_7__[28] += (-1.0f * __y_xpd__[4][2]);
			__tmp_coord_array_7__[29] += (-1.0f * __y_xpd__[4][3]);
			__tmp_coord_array_7__[30] += (-1.0f * __y_xpd__[4][4]);

		}
		if (((y.m_gu & 32) != 0)) {
			__tmp_coord_array_7__[31] += (-1.0f * __y_xpd__[5][0]);

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_7__);
		return __temp_var_1__;
	}
	scalar norm_e2(const mv& x) {
		scalar __temp_var_1__;
		const float* __x_xpd__[6] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			__temp_var_1__.m_c[0] += (__x_xpd__[0][0] * __x_xpd__[0][0]);

		}
		if (((x.m_gu & 2) != 0)) {
			__temp_var_1__.m_c[0] += ((__x_xpd__[1][2] * __x_xpd__[1][2]) + (__x_xpd__[1][3] * __x_xpd__[1][3]) + (__x_xpd__[1][0] * __x_xpd__[1][0]) + (__x_xpd__[1][1] * __x_xpd__[1][1]) + (__x_xpd__[1][4] * __x_xpd__[1][4]));

		}
		if (((x.m_gu & 4) != 0)) {
			__temp_var_1__.m_c[0] += ((__x_xpd__[2][1] * __x_xpd__[2][1]) + (__x_xpd__[2][5] * __x_xpd__[2][5]) + (__x_xpd__[2][3] * __x_xpd__[2][3]) + (__x_xpd__[2][0] * __x_xpd__[2][0]) + (__x_xpd__[2][7] * __x_xpd__[2][7]) + (__x_xpd__[2][6] * __x_xpd__[2][6]) + (__x_xpd__[2][9] * __x_xpd__[2][9]) + (__x_xpd__[2][8] * __x_xpd__[2][8]) + (__x_xpd__[2][2] * __x_xpd__[2][2]) + (__x_xpd__[2][4] * __x_xpd__[2][4]));

		}
		if (((x.m_gu & 8) != 0)) {
			__temp_var_1__.m_c[0] += ((__x_xpd__[3][2] * __x_xpd__[3][2]) + (__x_xpd__[3][7] * __x_xpd__[3][7]) + (__x_xpd__[3][6] * __x_xpd__[3][6]) + (__x_xpd__[3][3] * __x_xpd__[3][3]) + (__x_xpd__[3][1] * __x_xpd__[3][1]) + (__x_xpd__[3][0] * __x_xpd__[3][0]) + (__x_xpd__[3][8] * __x_xpd__[3][8]) + (__x_xpd__[3][4] * __x_xpd__[3][4]) + (__x_xpd__[3][9] * __x_xpd__[3][9]) + (__x_xpd__[3][5] * __x_xpd__[3][5]));

		}
		if (((x.m_gu & 16) != 0)) {
			__temp_var_1__.m_c[0] += ((__x_xpd__[4][4] * __x_xpd__[4][4]) + (__x_xpd__[4][3] * __x_xpd__[4][3]) + (__x_xpd__[4][1] * __x_xpd__[4][1]) + (__x_xpd__[4][2] * __x_xpd__[4][2]) + (__x_xpd__[4][0] * __x_xpd__[4][0]));

		}
		if (((x.m_gu & 32) != 0)) {
			__temp_var_1__.m_c[0] += (__x_xpd__[5][0] * __x_xpd__[5][0]);

		}
		return __temp_var_1__;
	}
	scalar norm_e(const mv& x) {
		scalar e2;
		const float* __x_xpd__[6] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			e2.m_c[0] += (__x_xpd__[0][0] * __x_xpd__[0][0]);

		}
		if (((x.m_gu & 2) != 0)) {
			e2.m_c[0] += ((__x_xpd__[1][1] * __x_xpd__[1][1]) + (__x_xpd__[1][3] * __x_xpd__[1][3]) + (__x_xpd__[1][4] * __x_xpd__[1][4]) + (__x_xpd__[1][2] * __x_xpd__[1][2]) + (__x_xpd__[1][0] * __x_xpd__[1][0]));

		}
		if (((x.m_gu & 4) != 0)) {
			e2.m_c[0] += ((__x_xpd__[2][9] * __x_xpd__[2][9]) + (__x_xpd__[2][5] * __x_xpd__[2][5]) + (__x_xpd__[2][0] * __x_xpd__[2][0]) + (__x_xpd__[2][3] * __x_xpd__[2][3]) + (__x_xpd__[2][8] * __x_xpd__[2][8]) + (__x_xpd__[2][2] * __x_xpd__[2][2]) + (__x_xpd__[2][4] * __x_xpd__[2][4]) + (__x_xpd__[2][6] * __x_xpd__[2][6]) + (__x_xpd__[2][1] * __x_xpd__[2][1]) + (__x_xpd__[2][7] * __x_xpd__[2][7]));

		}
		if (((x.m_gu & 8) != 0)) {
			e2.m_c[0] += ((__x_xpd__[3][5] * __x_xpd__[3][5]) + (__x_xpd__[3][7] * __x_xpd__[3][7]) + (__x_xpd__[3][0] * __x_xpd__[3][0]) + (__x_xpd__[3][3] * __x_xpd__[3][3]) + (__x_xpd__[3][8] * __x_xpd__[3][8]) + (__x_xpd__[3][4] * __x_xpd__[3][4]) + (__x_xpd__[3][1] * __x_xpd__[3][1]) + (__x_xpd__[3][9] * __x_xpd__[3][9]) + (__x_xpd__[3][2] * __x_xpd__[3][2]) + (__x_xpd__[3][6] * __x_xpd__[3][6]));

		}
		if (((x.m_gu & 16) != 0)) {
			e2.m_c[0] += ((__x_xpd__[4][0] * __x_xpd__[4][0]) + (__x_xpd__[4][1] * __x_xpd__[4][1]) + (__x_xpd__[4][3] * __x_xpd__[4][3]) + (__x_xpd__[4][4] * __x_xpd__[4][4]) + (__x_xpd__[4][2] * __x_xpd__[4][2]));

		}
		if (((x.m_gu & 32) != 0)) {
			e2.m_c[0] += (__x_xpd__[5][0] * __x_xpd__[5][0]);

		}
		return scalar(scalar_scalar, sqrt(e2.m_c[0]));
	}
	mv unit_e(const mv& x) {
		scalar e2;
		const float* __x_xpd__[6] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			e2.m_c[0] += (__x_xpd__[0][0] * __x_xpd__[0][0]);

		}
		if (((x.m_gu & 2) != 0)) {
			e2.m_c[0] += ((__x_xpd__[1][2] * __x_xpd__[1][2]) + (__x_xpd__[1][4] * __x_xpd__[1][4]) + (__x_xpd__[1][3] * __x_xpd__[1][3]) + (__x_xpd__[1][0] * __x_xpd__[1][0]) + (__x_xpd__[1][1] * __x_xpd__[1][1]));

		}
		if (((x.m_gu & 4) != 0)) {
			e2.m_c[0] += ((__x_xpd__[2][1] * __x_xpd__[2][1]) + (__x_xpd__[2][3] * __x_xpd__[2][3]) + (__x_xpd__[2][7] * __x_xpd__[2][7]) + (__x_xpd__[2][2] * __x_xpd__[2][2]) + (__x_xpd__[2][4] * __x_xpd__[2][4]) + (__x_xpd__[2][8] * __x_xpd__[2][8]) + (__x_xpd__[2][6] * __x_xpd__[2][6]) + (__x_xpd__[2][5] * __x_xpd__[2][5]) + (__x_xpd__[2][0] * __x_xpd__[2][0]) + (__x_xpd__[2][9] * __x_xpd__[2][9]));

		}
		if (((x.m_gu & 8) != 0)) {
			e2.m_c[0] += ((__x_xpd__[3][3] * __x_xpd__[3][3]) + (__x_xpd__[3][4] * __x_xpd__[3][4]) + (__x_xpd__[3][5] * __x_xpd__[3][5]) + (__x_xpd__[3][0] * __x_xpd__[3][0]) + (__x_xpd__[3][9] * __x_xpd__[3][9]) + (__x_xpd__[3][2] * __x_xpd__[3][2]) + (__x_xpd__[3][8] * __x_xpd__[3][8]) + (__x_xpd__[3][7] * __x_xpd__[3][7]) + (__x_xpd__[3][6] * __x_xpd__[3][6]) + (__x_xpd__[3][1] * __x_xpd__[3][1]));

		}
		if (((x.m_gu & 16) != 0)) {
			e2.m_c[0] += ((__x_xpd__[4][4] * __x_xpd__[4][4]) + (__x_xpd__[4][1] * __x_xpd__[4][1]) + (__x_xpd__[4][0] * __x_xpd__[4][0]) + (__x_xpd__[4][3] * __x_xpd__[4][3]) + (__x_xpd__[4][2] * __x_xpd__[4][2]));

		}
		if (((x.m_gu & 32) != 0)) {
			e2.m_c[0] += (__x_xpd__[5][0] * __x_xpd__[5][0]);

		}
		scalar ie;
		ie.m_c[0] = ((char)1 / sqrt(e2.m_c[0]));
		mv __temp_var_1__;
		float __tmp_coord_array_8__[32] ;
		mv_zero(__tmp_coord_array_8__, 32);
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_8__[0] += (__x_xpd__[0][0] * ie.m_c[0]);

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_8__[1] += (__x_xpd__[1][0] * ie.m_c[0]);
			__tmp_coord_array_8__[2] += (__x_xpd__[1][1] * ie.m_c[0]);
			__tmp_coord_array_8__[3] += (__x_xpd__[1][2] * ie.m_c[0]);
			__tmp_coord_array_8__[4] += (__x_xpd__[1][3] * ie.m_c[0]);
			__tmp_coord_array_8__[5] += (__x_xpd__[1][4] * ie.m_c[0]);

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_8__[6] += (__x_xpd__[2][0] * ie.m_c[0]);
			__tmp_coord_array_8__[7] += (__x_xpd__[2][1] * ie.m_c[0]);
			__tmp_coord_array_8__[8] += (__x_xpd__[2][2] * ie.m_c[0]);
			__tmp_coord_array_8__[9] += (__x_xpd__[2][3] * ie.m_c[0]);
			__tmp_coord_array_8__[10] += (__x_xpd__[2][4] * ie.m_c[0]);
			__tmp_coord_array_8__[11] += (__x_xpd__[2][5] * ie.m_c[0]);
			__tmp_coord_array_8__[12] += (__x_xpd__[2][6] * ie.m_c[0]);
			__tmp_coord_array_8__[13] += (__x_xpd__[2][7] * ie.m_c[0]);
			__tmp_coord_array_8__[14] += (__x_xpd__[2][8] * ie.m_c[0]);
			__tmp_coord_array_8__[15] += (__x_xpd__[2][9] * ie.m_c[0]);

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_8__[16] += (__x_xpd__[3][0] * ie.m_c[0]);
			__tmp_coord_array_8__[17] += (__x_xpd__[3][1] * ie.m_c[0]);
			__tmp_coord_array_8__[18] += (__x_xpd__[3][2] * ie.m_c[0]);
			__tmp_coord_array_8__[19] += (__x_xpd__[3][3] * ie.m_c[0]);
			__tmp_coord_array_8__[20] += (__x_xpd__[3][4] * ie.m_c[0]);
			__tmp_coord_array_8__[21] += (__x_xpd__[3][5] * ie.m_c[0]);
			__tmp_coord_array_8__[22] += (__x_xpd__[3][6] * ie.m_c[0]);
			__tmp_coord_array_8__[23] += (__x_xpd__[3][7] * ie.m_c[0]);
			__tmp_coord_array_8__[24] += (__x_xpd__[3][8] * ie.m_c[0]);
			__tmp_coord_array_8__[25] += (__x_xpd__[3][9] * ie.m_c[0]);

		}
		if (((x.m_gu & 16) != 0)) {
			__tmp_coord_array_8__[26] += (__x_xpd__[4][0] * ie.m_c[0]);
			__tmp_coord_array_8__[27] += (__x_xpd__[4][1] * ie.m_c[0]);
			__tmp_coord_array_8__[28] += (__x_xpd__[4][2] * ie.m_c[0]);
			__tmp_coord_array_8__[29] += (__x_xpd__[4][3] * ie.m_c[0]);
			__tmp_coord_array_8__[30] += (__x_xpd__[4][4] * ie.m_c[0]);

		}
		if (((x.m_gu & 32) != 0)) {
			__tmp_coord_array_8__[31] += (__x_xpd__[5][0] * ie.m_c[0]);

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_8__);
		return __temp_var_1__;
	}
	scalar norm_r2(const mv& x) {
		scalar __temp_var_1__;
		const float* __x_xpd__[6] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			__temp_var_1__.m_c[0] += (__x_xpd__[0][0] * __x_xpd__[0][0]);

		}
		if (((x.m_gu & 2) != 0)) {
			__temp_var_1__.m_c[0] += ((-1.0f * __x_xpd__[1][4] * __x_xpd__[1][0]) + (__x_xpd__[1][2] * __x_xpd__[1][2]) + (__x_xpd__[1][1] * __x_xpd__[1][1]) + (__x_xpd__[1][3] * __x_xpd__[1][3]) + (-1.0f * __x_xpd__[1][0] * __x_xpd__[1][4]));

		}
		if (((x.m_gu & 4) != 0)) {
			__temp_var_1__.m_c[0] += ((__x_xpd__[2][7] * __x_xpd__[2][1]) + (__x_xpd__[2][5] * __x_xpd__[2][5]) + (__x_xpd__[2][1] * __x_xpd__[2][7]) + (__x_xpd__[2][6] * __x_xpd__[2][0]) + (__x_xpd__[2][0] * __x_xpd__[2][6]) + (__x_xpd__[2][8] * __x_xpd__[2][2]) + (__x_xpd__[2][4] * __x_xpd__[2][4]) + (__x_xpd__[2][3] * __x_xpd__[2][3]) + (__x_xpd__[2][2] * __x_xpd__[2][8]) + (-1.0f * __x_xpd__[2][9] * __x_xpd__[2][9]));

		}
		if (((x.m_gu & 8) != 0)) {
			__temp_var_1__.m_c[0] += ((-1.0f * __x_xpd__[3][5] * __x_xpd__[3][5]) + (-1.0f * __x_xpd__[3][8] * __x_xpd__[3][2]) + (-1.0f * __x_xpd__[3][0] * __x_xpd__[3][6]) + (__x_xpd__[3][1] * __x_xpd__[3][7]) + (-1.0f * __x_xpd__[3][2] * __x_xpd__[3][8]) + (-1.0f * __x_xpd__[3][6] * __x_xpd__[3][0]) + (-1.0f * __x_xpd__[3][4] * __x_xpd__[3][4]) + (__x_xpd__[3][7] * __x_xpd__[3][1]) + (__x_xpd__[3][9] * __x_xpd__[3][9]) + (-1.0f * __x_xpd__[3][3] * __x_xpd__[3][3]));

		}
		if (((x.m_gu & 16) != 0)) {
			__temp_var_1__.m_c[0] += ((-1.0f * __x_xpd__[4][2] * __x_xpd__[4][2]) + (__x_xpd__[4][4] * __x_xpd__[4][0]) + (-1.0f * __x_xpd__[4][3] * __x_xpd__[4][3]) + (-1.0f * __x_xpd__[4][1] * __x_xpd__[4][1]) + (__x_xpd__[4][0] * __x_xpd__[4][4]));

		}
		if (((x.m_gu & 32) != 0)) {
			__temp_var_1__.m_c[0] += (-1.0f * __x_xpd__[5][0] * __x_xpd__[5][0]);

		}
		return __temp_var_1__;
	}
	scalar norm_r(const mv& x) {
		scalar r2;
		const float* __x_xpd__[6] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			r2.m_c[0] += (__x_xpd__[0][0] * __x_xpd__[0][0]);

		}
		if (((x.m_gu & 2) != 0)) {
			r2.m_c[0] += ((__x_xpd__[1][3] * __x_xpd__[1][3]) + (-1.0f * __x_xpd__[1][4] * __x_xpd__[1][0]) + (-1.0f * __x_xpd__[1][0] * __x_xpd__[1][4]) + (__x_xpd__[1][2] * __x_xpd__[1][2]) + (__x_xpd__[1][1] * __x_xpd__[1][1]));

		}
		if (((x.m_gu & 4) != 0)) {
			r2.m_c[0] += ((-1.0f * __x_xpd__[2][9] * __x_xpd__[2][9]) + (__x_xpd__[2][4] * __x_xpd__[2][4]) + (__x_xpd__[2][3] * __x_xpd__[2][3]) + (__x_xpd__[2][2] * __x_xpd__[2][8]) + (__x_xpd__[2][8] * __x_xpd__[2][2]) + (__x_xpd__[2][0] * __x_xpd__[2][6]) + (__x_xpd__[2][6] * __x_xpd__[2][0]) + (__x_xpd__[2][1] * __x_xpd__[2][7]) + (__x_xpd__[2][7] * __x_xpd__[2][1]) + (__x_xpd__[2][5] * __x_xpd__[2][5]));

		}
		if (((x.m_gu & 8) != 0)) {
			r2.m_c[0] += ((-1.0f * __x_xpd__[3][5] * __x_xpd__[3][5]) + (-1.0f * __x_xpd__[3][8] * __x_xpd__[3][2]) + (-1.0f * __x_xpd__[3][0] * __x_xpd__[3][6]) + (__x_xpd__[3][7] * __x_xpd__[3][1]) + (__x_xpd__[3][1] * __x_xpd__[3][7]) + (-1.0f * __x_xpd__[3][6] * __x_xpd__[3][0]) + (-1.0f * __x_xpd__[3][2] * __x_xpd__[3][8]) + (__x_xpd__[3][9] * __x_xpd__[3][9]) + (-1.0f * __x_xpd__[3][4] * __x_xpd__[3][4]) + (-1.0f * __x_xpd__[3][3] * __x_xpd__[3][3]));

		}
		if (((x.m_gu & 16) != 0)) {
			r2.m_c[0] += ((__x_xpd__[4][0] * __x_xpd__[4][4]) + (-1.0f * __x_xpd__[4][1] * __x_xpd__[4][1]) + (__x_xpd__[4][4] * __x_xpd__[4][0]) + (-1.0f * __x_xpd__[4][3] * __x_xpd__[4][3]) + (-1.0f * __x_xpd__[4][2] * __x_xpd__[4][2]));

		}
		if (((x.m_gu & 32) != 0)) {
			r2.m_c[0] += (-1.0f * __x_xpd__[5][0] * __x_xpd__[5][0]);

		}
		return scalar(scalar_scalar, ((((r2.m_c[0] < (char)0)) ? (char)-1 : ((((r2.m_c[0] > (char)0)) ? (char)1 : (char)0))) * sqrt((((r2.m_c[0] < (char)0)) ? ((-r2.m_c[0])) : (r2.m_c[0])))));
	}
	mv unit_r(const mv& x) {
		scalar r2;
		const float* __x_xpd__[6] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			r2.m_c[0] += (__x_xpd__[0][0] * __x_xpd__[0][0]);

		}
		if (((x.m_gu & 2) != 0)) {
			r2.m_c[0] += ((__x_xpd__[1][1] * __x_xpd__[1][1]) + (-1.0f * __x_xpd__[1][4] * __x_xpd__[1][0]) + (__x_xpd__[1][2] * __x_xpd__[1][2]) + (__x_xpd__[1][3] * __x_xpd__[1][3]) + (-1.0f * __x_xpd__[1][0] * __x_xpd__[1][4]));

		}
		if (((x.m_gu & 4) != 0)) {
			r2.m_c[0] += ((__x_xpd__[2][7] * __x_xpd__[2][1]) + (__x_xpd__[2][5] * __x_xpd__[2][5]) + (__x_xpd__[2][2] * __x_xpd__[2][8]) + (__x_xpd__[2][1] * __x_xpd__[2][7]) + (__x_xpd__[2][0] * __x_xpd__[2][6]) + (__x_xpd__[2][3] * __x_xpd__[2][3]) + (__x_xpd__[2][6] * __x_xpd__[2][0]) + (__x_xpd__[2][4] * __x_xpd__[2][4]) + (-1.0f * __x_xpd__[2][9] * __x_xpd__[2][9]) + (__x_xpd__[2][8] * __x_xpd__[2][2]));

		}
		if (((x.m_gu & 8) != 0)) {
			r2.m_c[0] += ((-1.0f * __x_xpd__[3][2] * __x_xpd__[3][8]) + (-1.0f * __x_xpd__[3][4] * __x_xpd__[3][4]) + (-1.0f * __x_xpd__[3][5] * __x_xpd__[3][5]) + (__x_xpd__[3][1] * __x_xpd__[3][7]) + (__x_xpd__[3][9] * __x_xpd__[3][9]) + (__x_xpd__[3][7] * __x_xpd__[3][1]) + (-1.0f * __x_xpd__[3][8] * __x_xpd__[3][2]) + (-1.0f * __x_xpd__[3][0] * __x_xpd__[3][6]) + (-1.0f * __x_xpd__[3][3] * __x_xpd__[3][3]) + (-1.0f * __x_xpd__[3][6] * __x_xpd__[3][0]));

		}
		if (((x.m_gu & 16) != 0)) {
			r2.m_c[0] += ((-1.0f * __x_xpd__[4][1] * __x_xpd__[4][1]) + (__x_xpd__[4][0] * __x_xpd__[4][4]) + (__x_xpd__[4][4] * __x_xpd__[4][0]) + (-1.0f * __x_xpd__[4][3] * __x_xpd__[4][3]) + (-1.0f * __x_xpd__[4][2] * __x_xpd__[4][2]));

		}
		if (((x.m_gu & 32) != 0)) {
			r2.m_c[0] += (-1.0f * __x_xpd__[5][0] * __x_xpd__[5][0]);

		}
		scalar ir;
		ir.m_c[0] = ((char)1 / sqrt((((r2.m_c[0] < (char)0)) ? ((-r2.m_c[0])) : (r2.m_c[0]))));
		mv __temp_var_1__;
		float __tmp_coord_array_9__[32] ;
		mv_zero(__tmp_coord_array_9__, 32);
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_9__[0] += (__x_xpd__[0][0] * ir.m_c[0]);

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_9__[1] += (__x_xpd__[1][0] * ir.m_c[0]);
			__tmp_coord_array_9__[2] += (__x_xpd__[1][1] * ir.m_c[0]);
			__tmp_coord_array_9__[3] += (__x_xpd__[1][2] * ir.m_c[0]);
			__tmp_coord_array_9__[4] += (__x_xpd__[1][3] * ir.m_c[0]);
			__tmp_coord_array_9__[5] += (__x_xpd__[1][4] * ir.m_c[0]);

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_9__[6] += (__x_xpd__[2][0] * ir.m_c[0]);
			__tmp_coord_array_9__[7] += (__x_xpd__[2][1] * ir.m_c[0]);
			__tmp_coord_array_9__[8] += (__x_xpd__[2][2] * ir.m_c[0]);
			__tmp_coord_array_9__[9] += (__x_xpd__[2][3] * ir.m_c[0]);
			__tmp_coord_array_9__[10] += (__x_xpd__[2][4] * ir.m_c[0]);
			__tmp_coord_array_9__[11] += (__x_xpd__[2][5] * ir.m_c[0]);
			__tmp_coord_array_9__[12] += (__x_xpd__[2][6] * ir.m_c[0]);
			__tmp_coord_array_9__[13] += (__x_xpd__[2][7] * ir.m_c[0]);
			__tmp_coord_array_9__[14] += (__x_xpd__[2][8] * ir.m_c[0]);
			__tmp_coord_array_9__[15] += (__x_xpd__[2][9] * ir.m_c[0]);

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_9__[16] += (__x_xpd__[3][0] * ir.m_c[0]);
			__tmp_coord_array_9__[17] += (__x_xpd__[3][1] * ir.m_c[0]);
			__tmp_coord_array_9__[18] += (__x_xpd__[3][2] * ir.m_c[0]);
			__tmp_coord_array_9__[19] += (__x_xpd__[3][3] * ir.m_c[0]);
			__tmp_coord_array_9__[20] += (__x_xpd__[3][4] * ir.m_c[0]);
			__tmp_coord_array_9__[21] += (__x_xpd__[3][5] * ir.m_c[0]);
			__tmp_coord_array_9__[22] += (__x_xpd__[3][6] * ir.m_c[0]);
			__tmp_coord_array_9__[23] += (__x_xpd__[3][7] * ir.m_c[0]);
			__tmp_coord_array_9__[24] += (__x_xpd__[3][8] * ir.m_c[0]);
			__tmp_coord_array_9__[25] += (__x_xpd__[3][9] * ir.m_c[0]);

		}
		if (((x.m_gu & 16) != 0)) {
			__tmp_coord_array_9__[26] += (__x_xpd__[4][0] * ir.m_c[0]);
			__tmp_coord_array_9__[27] += (__x_xpd__[4][1] * ir.m_c[0]);
			__tmp_coord_array_9__[28] += (__x_xpd__[4][2] * ir.m_c[0]);
			__tmp_coord_array_9__[29] += (__x_xpd__[4][3] * ir.m_c[0]);
			__tmp_coord_array_9__[30] += (__x_xpd__[4][4] * ir.m_c[0]);

		}
		if (((x.m_gu & 32) != 0)) {
			__tmp_coord_array_9__[31] += (__x_xpd__[5][0] * ir.m_c[0]);

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_9__);
		return __temp_var_1__;
	}
	mv reverse(const mv& x) {
		mv __temp_var_1__;
		float __tmp_coord_array_10__[32] ;
		mv_zero(__tmp_coord_array_10__, 32);
		const float* __x_xpd__[6] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_10__[0] += __x_xpd__[0][0];

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_10__[1] += __x_xpd__[1][0];
			__tmp_coord_array_10__[2] += __x_xpd__[1][1];
			__tmp_coord_array_10__[3] += __x_xpd__[1][2];
			__tmp_coord_array_10__[4] += __x_xpd__[1][3];
			__tmp_coord_array_10__[5] += __x_xpd__[1][4];

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_10__[6] += (-1.0f * __x_xpd__[2][0]);
			__tmp_coord_array_10__[7] += (-1.0f * __x_xpd__[2][1]);
			__tmp_coord_array_10__[8] += (-1.0f * __x_xpd__[2][2]);
			__tmp_coord_array_10__[9] += (-1.0f * __x_xpd__[2][3]);
			__tmp_coord_array_10__[10] += (-1.0f * __x_xpd__[2][4]);
			__tmp_coord_array_10__[11] += (-1.0f * __x_xpd__[2][5]);
			__tmp_coord_array_10__[12] += (-1.0f * __x_xpd__[2][6]);
			__tmp_coord_array_10__[13] += (-1.0f * __x_xpd__[2][7]);
			__tmp_coord_array_10__[14] += (-1.0f * __x_xpd__[2][8]);
			__tmp_coord_array_10__[15] += (-1.0f * __x_xpd__[2][9]);

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_10__[16] += (-1.0f * __x_xpd__[3][0]);
			__tmp_coord_array_10__[17] += (-1.0f * __x_xpd__[3][1]);
			__tmp_coord_array_10__[18] += (-1.0f * __x_xpd__[3][2]);
			__tmp_coord_array_10__[19] += (-1.0f * __x_xpd__[3][3]);
			__tmp_coord_array_10__[20] += (-1.0f * __x_xpd__[3][4]);
			__tmp_coord_array_10__[21] += (-1.0f * __x_xpd__[3][5]);
			__tmp_coord_array_10__[22] += (-1.0f * __x_xpd__[3][6]);
			__tmp_coord_array_10__[23] += (-1.0f * __x_xpd__[3][7]);
			__tmp_coord_array_10__[24] += (-1.0f * __x_xpd__[3][8]);
			__tmp_coord_array_10__[25] += (-1.0f * __x_xpd__[3][9]);

		}
		if (((x.m_gu & 16) != 0)) {
			__tmp_coord_array_10__[26] += __x_xpd__[4][0];
			__tmp_coord_array_10__[27] += __x_xpd__[4][1];
			__tmp_coord_array_10__[28] += __x_xpd__[4][2];
			__tmp_coord_array_10__[29] += __x_xpd__[4][3];
			__tmp_coord_array_10__[30] += __x_xpd__[4][4];

		}
		if (((x.m_gu & 32) != 0)) {
			__tmp_coord_array_10__[31] += __x_xpd__[5][0];

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_10__);
		return __temp_var_1__;
	}
	mv negate(const mv& x) {
		mv __temp_var_1__;
		float __tmp_coord_array_11__[32] ;
		mv_zero(__tmp_coord_array_11__, 32);
		const float* __x_xpd__[6] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_11__[0] += (-1.0f * __x_xpd__[0][0]);

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_11__[1] += (-1.0f * __x_xpd__[1][0]);
			__tmp_coord_array_11__[2] += (-1.0f * __x_xpd__[1][1]);
			__tmp_coord_array_11__[3] += (-1.0f * __x_xpd__[1][2]);
			__tmp_coord_array_11__[4] += (-1.0f * __x_xpd__[1][3]);
			__tmp_coord_array_11__[5] += (-1.0f * __x_xpd__[1][4]);

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_11__[6] += (-1.0f * __x_xpd__[2][0]);
			__tmp_coord_array_11__[7] += (-1.0f * __x_xpd__[2][1]);
			__tmp_coord_array_11__[8] += (-1.0f * __x_xpd__[2][2]);
			__tmp_coord_array_11__[9] += (-1.0f * __x_xpd__[2][3]);
			__tmp_coord_array_11__[10] += (-1.0f * __x_xpd__[2][4]);
			__tmp_coord_array_11__[11] += (-1.0f * __x_xpd__[2][5]);
			__tmp_coord_array_11__[12] += (-1.0f * __x_xpd__[2][6]);
			__tmp_coord_array_11__[13] += (-1.0f * __x_xpd__[2][7]);
			__tmp_coord_array_11__[14] += (-1.0f * __x_xpd__[2][8]);
			__tmp_coord_array_11__[15] += (-1.0f * __x_xpd__[2][9]);

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_11__[16] += (-1.0f * __x_xpd__[3][0]);
			__tmp_coord_array_11__[17] += (-1.0f * __x_xpd__[3][1]);
			__tmp_coord_array_11__[18] += (-1.0f * __x_xpd__[3][2]);
			__tmp_coord_array_11__[19] += (-1.0f * __x_xpd__[3][3]);
			__tmp_coord_array_11__[20] += (-1.0f * __x_xpd__[3][4]);
			__tmp_coord_array_11__[21] += (-1.0f * __x_xpd__[3][5]);
			__tmp_coord_array_11__[22] += (-1.0f * __x_xpd__[3][6]);
			__tmp_coord_array_11__[23] += (-1.0f * __x_xpd__[3][7]);
			__tmp_coord_array_11__[24] += (-1.0f * __x_xpd__[3][8]);
			__tmp_coord_array_11__[25] += (-1.0f * __x_xpd__[3][9]);

		}
		if (((x.m_gu & 16) != 0)) {
			__tmp_coord_array_11__[26] += (-1.0f * __x_xpd__[4][0]);
			__tmp_coord_array_11__[27] += (-1.0f * __x_xpd__[4][1]);
			__tmp_coord_array_11__[28] += (-1.0f * __x_xpd__[4][2]);
			__tmp_coord_array_11__[29] += (-1.0f * __x_xpd__[4][3]);
			__tmp_coord_array_11__[30] += (-1.0f * __x_xpd__[4][4]);

		}
		if (((x.m_gu & 32) != 0)) {
			__tmp_coord_array_11__[31] += (-1.0f * __x_xpd__[5][0]);

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_11__);
		return __temp_var_1__;
	}
	mv dual(const mv& x) {
		mv __temp_var_1__;
		float __tmp_coord_array_12__[32] ;
		mv_zero(__tmp_coord_array_12__, 32);
		const float* __x_xpd__[6] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_12__[31] += (-1.0f * __x_xpd__[0][0]);

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_12__[26] += __x_xpd__[1][4];
			__tmp_coord_array_12__[27] += __x_xpd__[1][1];
			__tmp_coord_array_12__[28] += __x_xpd__[1][2];
			__tmp_coord_array_12__[29] += __x_xpd__[1][3];
			__tmp_coord_array_12__[30] += __x_xpd__[1][0];

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_12__[16] += __x_xpd__[2][6];
			__tmp_coord_array_12__[17] += __x_xpd__[2][7];
			__tmp_coord_array_12__[18] += __x_xpd__[2][8];
			__tmp_coord_array_12__[19] += __x_xpd__[2][3];
			__tmp_coord_array_12__[20] += __x_xpd__[2][4];
			__tmp_coord_array_12__[21] += __x_xpd__[2][5];
			__tmp_coord_array_12__[22] += __x_xpd__[2][0];
			__tmp_coord_array_12__[23] += (-1.0f * __x_xpd__[2][1]);
			__tmp_coord_array_12__[24] += __x_xpd__[2][2];
			__tmp_coord_array_12__[25] += __x_xpd__[2][9];

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_12__[6] += (-1.0f * __x_xpd__[3][6]);
			__tmp_coord_array_12__[7] += __x_xpd__[3][7];
			__tmp_coord_array_12__[8] += (-1.0f * __x_xpd__[3][8]);
			__tmp_coord_array_12__[9] += (-1.0f * __x_xpd__[3][3]);
			__tmp_coord_array_12__[10] += (-1.0f * __x_xpd__[3][4]);
			__tmp_coord_array_12__[11] += (-1.0f * __x_xpd__[3][5]);
			__tmp_coord_array_12__[12] += (-1.0f * __x_xpd__[3][0]);
			__tmp_coord_array_12__[13] += (-1.0f * __x_xpd__[3][1]);
			__tmp_coord_array_12__[14] += (-1.0f * __x_xpd__[3][2]);
			__tmp_coord_array_12__[15] += (-1.0f * __x_xpd__[3][9]);

		}
		if (((x.m_gu & 16) != 0)) {
			__tmp_coord_array_12__[1] += (-1.0f * __x_xpd__[4][4]);
			__tmp_coord_array_12__[2] += (-1.0f * __x_xpd__[4][1]);
			__tmp_coord_array_12__[3] += (-1.0f * __x_xpd__[4][2]);
			__tmp_coord_array_12__[4] += (-1.0f * __x_xpd__[4][3]);
			__tmp_coord_array_12__[5] += (-1.0f * __x_xpd__[4][0]);

		}
		if (((x.m_gu & 32) != 0)) {
			__tmp_coord_array_12__[0] += __x_xpd__[5][0];

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_12__);
		return __temp_var_1__;
	}
	mv undual(const mv& x) {
		mv __temp_var_1__;
		float __tmp_coord_array_13__[32] ;
		mv_zero(__tmp_coord_array_13__, 32);
		const float* __x_xpd__[6] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_13__[31] += __x_xpd__[0][0];

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_13__[26] += (-1.0f * __x_xpd__[1][4]);
			__tmp_coord_array_13__[27] += (-1.0f * __x_xpd__[1][1]);
			__tmp_coord_array_13__[28] += (-1.0f * __x_xpd__[1][2]);
			__tmp_coord_array_13__[29] += (-1.0f * __x_xpd__[1][3]);
			__tmp_coord_array_13__[30] += (-1.0f * __x_xpd__[1][0]);

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_13__[16] += (-1.0f * __x_xpd__[2][6]);
			__tmp_coord_array_13__[17] += (-1.0f * __x_xpd__[2][7]);
			__tmp_coord_array_13__[18] += (-1.0f * __x_xpd__[2][8]);
			__tmp_coord_array_13__[19] += (-1.0f * __x_xpd__[2][3]);
			__tmp_coord_array_13__[20] += (-1.0f * __x_xpd__[2][4]);
			__tmp_coord_array_13__[21] += (-1.0f * __x_xpd__[2][5]);
			__tmp_coord_array_13__[22] += (-1.0f * __x_xpd__[2][0]);
			__tmp_coord_array_13__[23] += __x_xpd__[2][1];
			__tmp_coord_array_13__[24] += (-1.0f * __x_xpd__[2][2]);
			__tmp_coord_array_13__[25] += (-1.0f * __x_xpd__[2][9]);

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_13__[6] += __x_xpd__[3][6];
			__tmp_coord_array_13__[7] += (-1.0f * __x_xpd__[3][7]);
			__tmp_coord_array_13__[8] += __x_xpd__[3][8];
			__tmp_coord_array_13__[9] += __x_xpd__[3][3];
			__tmp_coord_array_13__[10] += __x_xpd__[3][4];
			__tmp_coord_array_13__[11] += __x_xpd__[3][5];
			__tmp_coord_array_13__[12] += __x_xpd__[3][0];
			__tmp_coord_array_13__[13] += __x_xpd__[3][1];
			__tmp_coord_array_13__[14] += __x_xpd__[3][2];
			__tmp_coord_array_13__[15] += __x_xpd__[3][9];

		}
		if (((x.m_gu & 16) != 0)) {
			__tmp_coord_array_13__[1] += __x_xpd__[4][4];
			__tmp_coord_array_13__[2] += __x_xpd__[4][1];
			__tmp_coord_array_13__[3] += __x_xpd__[4][2];
			__tmp_coord_array_13__[4] += __x_xpd__[4][3];
			__tmp_coord_array_13__[5] += __x_xpd__[4][0];

		}
		if (((x.m_gu & 32) != 0)) {
			__tmp_coord_array_13__[0] += (-1.0f * __x_xpd__[5][0]);

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_13__);
		return __temp_var_1__;
	}
	mv inverse(const mv& x) {
		scalar n;
		const float* __x_xpd__[6] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			n.m_c[0] += (__x_xpd__[0][0] * __x_xpd__[0][0]);

		}
		if (((x.m_gu & 2) != 0)) {
			n.m_c[0] += ((-1.0f * __x_xpd__[1][4] * __x_xpd__[1][0]) + (__x_xpd__[1][3] * __x_xpd__[1][3]) + (__x_xpd__[1][1] * __x_xpd__[1][1]) + (-1.0f * __x_xpd__[1][0] * __x_xpd__[1][4]) + (__x_xpd__[1][2] * __x_xpd__[1][2]));

		}
		if (((x.m_gu & 4) != 0)) {
			n.m_c[0] += ((__x_xpd__[2][0] * __x_xpd__[2][6]) + (-1.0f * __x_xpd__[2][9] * __x_xpd__[2][9]) + (__x_xpd__[2][1] * __x_xpd__[2][7]) + (__x_xpd__[2][6] * __x_xpd__[2][0]) + (__x_xpd__[2][3] * __x_xpd__[2][3]) + (__x_xpd__[2][7] * __x_xpd__[2][1]) + (__x_xpd__[2][4] * __x_xpd__[2][4]) + (__x_xpd__[2][5] * __x_xpd__[2][5]) + (__x_xpd__[2][2] * __x_xpd__[2][8]) + (__x_xpd__[2][8] * __x_xpd__[2][2]));

		}
		if (((x.m_gu & 8) != 0)) {
			n.m_c[0] += ((-1.0f * __x_xpd__[3][8] * __x_xpd__[3][2]) + (-1.0f * __x_xpd__[3][5] * __x_xpd__[3][5]) + (-1.0f * __x_xpd__[3][3] * __x_xpd__[3][3]) + (__x_xpd__[3][9] * __x_xpd__[3][9]) + (-1.0f * __x_xpd__[3][2] * __x_xpd__[3][8]) + (__x_xpd__[3][7] * __x_xpd__[3][1]) + (-1.0f * __x_xpd__[3][6] * __x_xpd__[3][0]) + (__x_xpd__[3][1] * __x_xpd__[3][7]) + (-1.0f * __x_xpd__[3][0] * __x_xpd__[3][6]) + (-1.0f * __x_xpd__[3][4] * __x_xpd__[3][4]));

		}
		if (((x.m_gu & 16) != 0)) {
			n.m_c[0] += ((__x_xpd__[4][0] * __x_xpd__[4][4]) + (-1.0f * __x_xpd__[4][1] * __x_xpd__[4][1]) + (-1.0f * __x_xpd__[4][2] * __x_xpd__[4][2]) + (-1.0f * __x_xpd__[4][3] * __x_xpd__[4][3]) + (__x_xpd__[4][4] * __x_xpd__[4][0]));

		}
		if (((x.m_gu & 32) != 0)) {
			n.m_c[0] += (-1.0f * __x_xpd__[5][0] * __x_xpd__[5][0]);

		}
		scalar in;
		in.m_c[0] = ((char)1 / n.m_c[0]);
		mv __temp_var_1__;
		float __tmp_coord_array_14__[32] ;
		mv_zero(__tmp_coord_array_14__, 32);
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_14__[0] += (__x_xpd__[0][0] * in.m_c[0]);

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_14__[1] += (__x_xpd__[1][0] * in.m_c[0]);
			__tmp_coord_array_14__[2] += (__x_xpd__[1][1] * in.m_c[0]);
			__tmp_coord_array_14__[3] += (__x_xpd__[1][2] * in.m_c[0]);
			__tmp_coord_array_14__[4] += (__x_xpd__[1][3] * in.m_c[0]);
			__tmp_coord_array_14__[5] += (__x_xpd__[1][4] * in.m_c[0]);

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_14__[6] += (-1.0f * __x_xpd__[2][0] * in.m_c[0]);
			__tmp_coord_array_14__[7] += (-1.0f * __x_xpd__[2][1] * in.m_c[0]);
			__tmp_coord_array_14__[8] += (-1.0f * __x_xpd__[2][2] * in.m_c[0]);
			__tmp_coord_array_14__[9] += (-1.0f * __x_xpd__[2][3] * in.m_c[0]);
			__tmp_coord_array_14__[10] += (-1.0f * __x_xpd__[2][4] * in.m_c[0]);
			__tmp_coord_array_14__[11] += (-1.0f * __x_xpd__[2][5] * in.m_c[0]);
			__tmp_coord_array_14__[12] += (-1.0f * __x_xpd__[2][6] * in.m_c[0]);
			__tmp_coord_array_14__[13] += (-1.0f * __x_xpd__[2][7] * in.m_c[0]);
			__tmp_coord_array_14__[14] += (-1.0f * __x_xpd__[2][8] * in.m_c[0]);
			__tmp_coord_array_14__[15] += (-1.0f * __x_xpd__[2][9] * in.m_c[0]);

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_14__[16] += (-1.0f * __x_xpd__[3][0] * in.m_c[0]);
			__tmp_coord_array_14__[17] += (-1.0f * __x_xpd__[3][1] * in.m_c[0]);
			__tmp_coord_array_14__[18] += (-1.0f * __x_xpd__[3][2] * in.m_c[0]);
			__tmp_coord_array_14__[19] += (-1.0f * __x_xpd__[3][3] * in.m_c[0]);
			__tmp_coord_array_14__[20] += (-1.0f * __x_xpd__[3][4] * in.m_c[0]);
			__tmp_coord_array_14__[21] += (-1.0f * __x_xpd__[3][5] * in.m_c[0]);
			__tmp_coord_array_14__[22] += (-1.0f * __x_xpd__[3][6] * in.m_c[0]);
			__tmp_coord_array_14__[23] += (-1.0f * __x_xpd__[3][7] * in.m_c[0]);
			__tmp_coord_array_14__[24] += (-1.0f * __x_xpd__[3][8] * in.m_c[0]);
			__tmp_coord_array_14__[25] += (-1.0f * __x_xpd__[3][9] * in.m_c[0]);

		}
		if (((x.m_gu & 16) != 0)) {
			__tmp_coord_array_14__[26] += (__x_xpd__[4][0] * in.m_c[0]);
			__tmp_coord_array_14__[27] += (__x_xpd__[4][1] * in.m_c[0]);
			__tmp_coord_array_14__[28] += (__x_xpd__[4][2] * in.m_c[0]);
			__tmp_coord_array_14__[29] += (__x_xpd__[4][3] * in.m_c[0]);
			__tmp_coord_array_14__[30] += (__x_xpd__[4][4] * in.m_c[0]);

		}
		if (((x.m_gu & 32) != 0)) {
			__tmp_coord_array_14__[31] += (__x_xpd__[5][0] * in.m_c[0]);

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_14__);
		return __temp_var_1__;
	}
	mv inverseEM(const mv& x) {
		scalar n;
		const float* __x_xpd__[6] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			n.m_c[0] += (__x_xpd__[0][0] * __x_xpd__[0][0]);

		}
		if (((x.m_gu & 2) != 0)) {
			n.m_c[0] += ((__x_xpd__[1][3] * __x_xpd__[1][3]) + (__x_xpd__[1][4] * __x_xpd__[1][4]) + (__x_xpd__[1][2] * __x_xpd__[1][2]) + (__x_xpd__[1][0] * __x_xpd__[1][0]) + (__x_xpd__[1][1] * __x_xpd__[1][1]));

		}
		if (((x.m_gu & 4) != 0)) {
			n.m_c[0] += ((__x_xpd__[2][9] * __x_xpd__[2][9]) + (__x_xpd__[2][2] * __x_xpd__[2][2]) + (__x_xpd__[2][5] * __x_xpd__[2][5]) + (__x_xpd__[2][7] * __x_xpd__[2][7]) + (__x_xpd__[2][3] * __x_xpd__[2][3]) + (__x_xpd__[2][6] * __x_xpd__[2][6]) + (__x_xpd__[2][4] * __x_xpd__[2][4]) + (__x_xpd__[2][0] * __x_xpd__[2][0]) + (__x_xpd__[2][8] * __x_xpd__[2][8]) + (__x_xpd__[2][1] * __x_xpd__[2][1]));

		}
		if (((x.m_gu & 8) != 0)) {
			n.m_c[0] += ((__x_xpd__[3][2] * __x_xpd__[3][2]) + (__x_xpd__[3][6] * __x_xpd__[3][6]) + (__x_xpd__[3][5] * __x_xpd__[3][5]) + (__x_xpd__[3][9] * __x_xpd__[3][9]) + (__x_xpd__[3][7] * __x_xpd__[3][7]) + (__x_xpd__[3][3] * __x_xpd__[3][3]) + (__x_xpd__[3][8] * __x_xpd__[3][8]) + (__x_xpd__[3][4] * __x_xpd__[3][4]) + (__x_xpd__[3][1] * __x_xpd__[3][1]) + (__x_xpd__[3][0] * __x_xpd__[3][0]));

		}
		if (((x.m_gu & 16) != 0)) {
			n.m_c[0] += ((__x_xpd__[4][1] * __x_xpd__[4][1]) + (__x_xpd__[4][3] * __x_xpd__[4][3]) + (__x_xpd__[4][4] * __x_xpd__[4][4]) + (__x_xpd__[4][0] * __x_xpd__[4][0]) + (__x_xpd__[4][2] * __x_xpd__[4][2]));

		}
		if (((x.m_gu & 32) != 0)) {
			n.m_c[0] += (__x_xpd__[5][0] * __x_xpd__[5][0]);

		}
		scalar in;
		in.m_c[0] = ((char)1 / n.m_c[0]);
		mv __temp_var_1__;
		float __tmp_coord_array_15__[32] ;
		mv_zero(__tmp_coord_array_15__, 32);
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_15__[0] += (__x_xpd__[0][0] * in.m_c[0]);

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_15__[1] += (__x_xpd__[1][0] * in.m_c[0]);
			__tmp_coord_array_15__[2] += (__x_xpd__[1][1] * in.m_c[0]);
			__tmp_coord_array_15__[3] += (__x_xpd__[1][2] * in.m_c[0]);
			__tmp_coord_array_15__[4] += (__x_xpd__[1][3] * in.m_c[0]);
			__tmp_coord_array_15__[5] += (__x_xpd__[1][4] * in.m_c[0]);

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_15__[6] += (-1.0f * __x_xpd__[2][0] * in.m_c[0]);
			__tmp_coord_array_15__[7] += (-1.0f * __x_xpd__[2][1] * in.m_c[0]);
			__tmp_coord_array_15__[8] += (-1.0f * __x_xpd__[2][2] * in.m_c[0]);
			__tmp_coord_array_15__[9] += (-1.0f * __x_xpd__[2][3] * in.m_c[0]);
			__tmp_coord_array_15__[10] += (-1.0f * __x_xpd__[2][4] * in.m_c[0]);
			__tmp_coord_array_15__[11] += (-1.0f * __x_xpd__[2][5] * in.m_c[0]);
			__tmp_coord_array_15__[12] += (-1.0f * __x_xpd__[2][6] * in.m_c[0]);
			__tmp_coord_array_15__[13] += (-1.0f * __x_xpd__[2][7] * in.m_c[0]);
			__tmp_coord_array_15__[14] += (-1.0f * __x_xpd__[2][8] * in.m_c[0]);
			__tmp_coord_array_15__[15] += (-1.0f * __x_xpd__[2][9] * in.m_c[0]);

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_15__[16] += (-1.0f * __x_xpd__[3][0] * in.m_c[0]);
			__tmp_coord_array_15__[17] += (-1.0f * __x_xpd__[3][1] * in.m_c[0]);
			__tmp_coord_array_15__[18] += (-1.0f * __x_xpd__[3][2] * in.m_c[0]);
			__tmp_coord_array_15__[19] += (-1.0f * __x_xpd__[3][3] * in.m_c[0]);
			__tmp_coord_array_15__[20] += (-1.0f * __x_xpd__[3][4] * in.m_c[0]);
			__tmp_coord_array_15__[21] += (-1.0f * __x_xpd__[3][5] * in.m_c[0]);
			__tmp_coord_array_15__[22] += (-1.0f * __x_xpd__[3][6] * in.m_c[0]);
			__tmp_coord_array_15__[23] += (-1.0f * __x_xpd__[3][7] * in.m_c[0]);
			__tmp_coord_array_15__[24] += (-1.0f * __x_xpd__[3][8] * in.m_c[0]);
			__tmp_coord_array_15__[25] += (-1.0f * __x_xpd__[3][9] * in.m_c[0]);

		}
		if (((x.m_gu & 16) != 0)) {
			__tmp_coord_array_15__[26] += (__x_xpd__[4][0] * in.m_c[0]);
			__tmp_coord_array_15__[27] += (__x_xpd__[4][1] * in.m_c[0]);
			__tmp_coord_array_15__[28] += (__x_xpd__[4][2] * in.m_c[0]);
			__tmp_coord_array_15__[29] += (__x_xpd__[4][3] * in.m_c[0]);
			__tmp_coord_array_15__[30] += (__x_xpd__[4][4] * in.m_c[0]);

		}
		if (((x.m_gu & 32) != 0)) {
			__tmp_coord_array_15__[31] += (__x_xpd__[5][0] * in.m_c[0]);

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_15__);
		return __temp_var_1__;
	}
	mv gradeInvolution(const mv& x) {
		mv __temp_var_1__;
		float __tmp_coord_array_16__[32] ;
		mv_zero(__tmp_coord_array_16__, 32);
		const float* __x_xpd__[6] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_16__[0] += __x_xpd__[0][0];

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_16__[1] += (-1.0f * __x_xpd__[1][0]);
			__tmp_coord_array_16__[2] += (-1.0f * __x_xpd__[1][1]);
			__tmp_coord_array_16__[3] += (-1.0f * __x_xpd__[1][2]);
			__tmp_coord_array_16__[4] += (-1.0f * __x_xpd__[1][3]);
			__tmp_coord_array_16__[5] += (-1.0f * __x_xpd__[1][4]);

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_16__[6] += __x_xpd__[2][0];
			__tmp_coord_array_16__[7] += __x_xpd__[2][1];
			__tmp_coord_array_16__[8] += __x_xpd__[2][2];
			__tmp_coord_array_16__[9] += __x_xpd__[2][3];
			__tmp_coord_array_16__[10] += __x_xpd__[2][4];
			__tmp_coord_array_16__[11] += __x_xpd__[2][5];
			__tmp_coord_array_16__[12] += __x_xpd__[2][6];
			__tmp_coord_array_16__[13] += __x_xpd__[2][7];
			__tmp_coord_array_16__[14] += __x_xpd__[2][8];
			__tmp_coord_array_16__[15] += __x_xpd__[2][9];

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_16__[16] += (-1.0f * __x_xpd__[3][0]);
			__tmp_coord_array_16__[17] += (-1.0f * __x_xpd__[3][1]);
			__tmp_coord_array_16__[18] += (-1.0f * __x_xpd__[3][2]);
			__tmp_coord_array_16__[19] += (-1.0f * __x_xpd__[3][3]);
			__tmp_coord_array_16__[20] += (-1.0f * __x_xpd__[3][4]);
			__tmp_coord_array_16__[21] += (-1.0f * __x_xpd__[3][5]);
			__tmp_coord_array_16__[22] += (-1.0f * __x_xpd__[3][6]);
			__tmp_coord_array_16__[23] += (-1.0f * __x_xpd__[3][7]);
			__tmp_coord_array_16__[24] += (-1.0f * __x_xpd__[3][8]);
			__tmp_coord_array_16__[25] += (-1.0f * __x_xpd__[3][9]);

		}
		if (((x.m_gu & 16) != 0)) {
			__tmp_coord_array_16__[26] += __x_xpd__[4][0];
			__tmp_coord_array_16__[27] += __x_xpd__[4][1];
			__tmp_coord_array_16__[28] += __x_xpd__[4][2];
			__tmp_coord_array_16__[29] += __x_xpd__[4][3];
			__tmp_coord_array_16__[30] += __x_xpd__[4][4];

		}
		if (((x.m_gu & 32) != 0)) {
			__tmp_coord_array_16__[31] += (-1.0f * __x_xpd__[5][0]);

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_16__);
		return __temp_var_1__;
	}

	// G2 functions:
	mv apply_om(const om& x, const mv& y) {
		mv __temp_var_1__;
		float __tmp_coord_array_17__[32] ;
		mv_zero(__tmp_coord_array_17__, 32);
		const float* __y_xpd__[6] ;
		y.expand(__y_xpd__, true);
		if (((y.m_gu & 2) != 0)) {
			__tmp_coord_array_17__[1] += ((x.m_c[1] * __y_xpd__[1][1]) + (x.m_c[0] * __y_xpd__[1][0]) + (x.m_c[2] * __y_xpd__[1][2]) + (x.m_c[3] * __y_xpd__[1][3]) + (x.m_c[4] * __y_xpd__[1][4]));
			__tmp_coord_array_17__[2] += ((x.m_c[7] * __y_xpd__[1][2]) + (x.m_c[8] * __y_xpd__[1][3]) + (x.m_c[9] * __y_xpd__[1][4]) + (x.m_c[5] * __y_xpd__[1][0]) + (x.m_c[6] * __y_xpd__[1][1]));
			__tmp_coord_array_17__[3] += ((x.m_c[14] * __y_xpd__[1][4]) + (x.m_c[13] * __y_xpd__[1][3]) + (x.m_c[10] * __y_xpd__[1][0]) + (x.m_c[12] * __y_xpd__[1][2]) + (x.m_c[11] * __y_xpd__[1][1]));
			__tmp_coord_array_17__[4] += ((x.m_c[17] * __y_xpd__[1][2]) + (x.m_c[15] * __y_xpd__[1][0]) + (x.m_c[16] * __y_xpd__[1][1]) + (x.m_c[19] * __y_xpd__[1][4]) + (x.m_c[18] * __y_xpd__[1][3]));
			__tmp_coord_array_17__[5] += ((x.m_c[23] * __y_xpd__[1][3]) + (x.m_c[24] * __y_xpd__[1][4]) + (x.m_c[20] * __y_xpd__[1][0]) + (x.m_c[21] * __y_xpd__[1][1]) + (x.m_c[22] * __y_xpd__[1][2]));

		}
		if (((y.m_gu & 4) != 0)) {
			__tmp_coord_array_17__[6] += ((x.m_c[29] * __y_xpd__[2][4]) + (x.m_c[33] * __y_xpd__[2][8]) + (x.m_c[30] * __y_xpd__[2][5]) + (x.m_c[25] * __y_xpd__[2][0]) + (x.m_c[27] * __y_xpd__[2][2]) + (x.m_c[32] * __y_xpd__[2][7]) + (x.m_c[26] * __y_xpd__[2][1]) + (x.m_c[34] * __y_xpd__[2][9]) + (x.m_c[31] * __y_xpd__[2][6]) + (x.m_c[28] * __y_xpd__[2][3]));
			__tmp_coord_array_17__[7] += ((x.m_c[43] * __y_xpd__[2][8]) + (x.m_c[41] * __y_xpd__[2][6]) + (x.m_c[36] * __y_xpd__[2][1]) + (x.m_c[38] * __y_xpd__[2][3]) + (x.m_c[39] * __y_xpd__[2][4]) + (x.m_c[42] * __y_xpd__[2][7]) + (x.m_c[35] * __y_xpd__[2][0]) + (x.m_c[37] * __y_xpd__[2][2]) + (x.m_c[40] * __y_xpd__[2][5]) + (x.m_c[44] * __y_xpd__[2][9]));
			__tmp_coord_array_17__[8] += ((x.m_c[49] * __y_xpd__[2][4]) + (x.m_c[45] * __y_xpd__[2][0]) + (x.m_c[50] * __y_xpd__[2][5]) + (x.m_c[47] * __y_xpd__[2][2]) + (x.m_c[46] * __y_xpd__[2][1]) + (x.m_c[51] * __y_xpd__[2][6]) + (x.m_c[52] * __y_xpd__[2][7]) + (x.m_c[48] * __y_xpd__[2][3]) + (x.m_c[53] * __y_xpd__[2][8]) + (x.m_c[54] * __y_xpd__[2][9]));
			__tmp_coord_array_17__[9] += ((x.m_c[64] * __y_xpd__[2][9]) + (x.m_c[59] * __y_xpd__[2][4]) + (x.m_c[62] * __y_xpd__[2][7]) + (x.m_c[55] * __y_xpd__[2][0]) + (x.m_c[56] * __y_xpd__[2][1]) + (x.m_c[60] * __y_xpd__[2][5]) + (x.m_c[63] * __y_xpd__[2][8]) + (x.m_c[57] * __y_xpd__[2][2]) + (x.m_c[58] * __y_xpd__[2][3]) + (x.m_c[61] * __y_xpd__[2][6]));
			__tmp_coord_array_17__[10] += ((x.m_c[67] * __y_xpd__[2][2]) + (x.m_c[71] * __y_xpd__[2][6]) + (x.m_c[65] * __y_xpd__[2][0]) + (x.m_c[69] * __y_xpd__[2][4]) + (x.m_c[74] * __y_xpd__[2][9]) + (x.m_c[68] * __y_xpd__[2][3]) + (x.m_c[72] * __y_xpd__[2][7]) + (x.m_c[73] * __y_xpd__[2][8]) + (x.m_c[66] * __y_xpd__[2][1]) + (x.m_c[70] * __y_xpd__[2][5]));
			__tmp_coord_array_17__[11] += ((x.m_c[82] * __y_xpd__[2][7]) + (x.m_c[81] * __y_xpd__[2][6]) + (x.m_c[79] * __y_xpd__[2][4]) + (x.m_c[84] * __y_xpd__[2][9]) + (x.m_c[83] * __y_xpd__[2][8]) + (x.m_c[75] * __y_xpd__[2][0]) + (x.m_c[77] * __y_xpd__[2][2]) + (x.m_c[76] * __y_xpd__[2][1]) + (x.m_c[80] * __y_xpd__[2][5]) + (x.m_c[78] * __y_xpd__[2][3]));
			__tmp_coord_array_17__[12] += ((x.m_c[90] * __y_xpd__[2][5]) + (x.m_c[88] * __y_xpd__[2][3]) + (x.m_c[94] * __y_xpd__[2][9]) + (x.m_c[86] * __y_xpd__[2][1]) + (x.m_c[89] * __y_xpd__[2][4]) + (x.m_c[87] * __y_xpd__[2][2]) + (x.m_c[93] * __y_xpd__[2][8]) + (x.m_c[91] * __y_xpd__[2][6]) + (x.m_c[85] * __y_xpd__[2][0]) + (x.m_c[92] * __y_xpd__[2][7]));
			__tmp_coord_array_17__[13] += ((x.m_c[102] * __y_xpd__[2][7]) + (x.m_c[97] * __y_xpd__[2][2]) + (x.m_c[101] * __y_xpd__[2][6]) + (x.m_c[98] * __y_xpd__[2][3]) + (x.m_c[100] * __y_xpd__[2][5]) + (x.m_c[95] * __y_xpd__[2][0]) + (x.m_c[96] * __y_xpd__[2][1]) + (x.m_c[99] * __y_xpd__[2][4]) + (x.m_c[103] * __y_xpd__[2][8]) + (x.m_c[104] * __y_xpd__[2][9]));
			__tmp_coord_array_17__[14] += ((x.m_c[110] * __y_xpd__[2][5]) + (x.m_c[114] * __y_xpd__[2][9]) + (x.m_c[111] * __y_xpd__[2][6]) + (x.m_c[108] * __y_xpd__[2][3]) + (x.m_c[112] * __y_xpd__[2][7]) + (x.m_c[107] * __y_xpd__[2][2]) + (x.m_c[105] * __y_xpd__[2][0]) + (x.m_c[109] * __y_xpd__[2][4]) + (x.m_c[106] * __y_xpd__[2][1]) + (x.m_c[113] * __y_xpd__[2][8]));
			__tmp_coord_array_17__[15] += ((x.m_c[124] * __y_xpd__[2][9]) + (x.m_c[118] * __y_xpd__[2][3]) + (x.m_c[122] * __y_xpd__[2][7]) + (x.m_c[123] * __y_xpd__[2][8]) + (x.m_c[121] * __y_xpd__[2][6]) + (x.m_c[117] * __y_xpd__[2][2]) + (x.m_c[120] * __y_xpd__[2][5]) + (x.m_c[116] * __y_xpd__[2][1]) + (x.m_c[115] * __y_xpd__[2][0]) + (x.m_c[119] * __y_xpd__[2][4]));

		}
		if (((y.m_gu & 8) != 0)) {
			__tmp_coord_array_17__[16] += ((x.m_c[128] * __y_xpd__[3][3]) + (x.m_c[131] * __y_xpd__[3][6]) + (x.m_c[132] * __y_xpd__[3][7]) + (x.m_c[129] * __y_xpd__[3][4]) + (x.m_c[134] * __y_xpd__[3][9]) + (x.m_c[127] * __y_xpd__[3][2]) + (x.m_c[125] * __y_xpd__[3][0]) + (x.m_c[130] * __y_xpd__[3][5]) + (x.m_c[126] * __y_xpd__[3][1]) + (x.m_c[133] * __y_xpd__[3][8]));
			__tmp_coord_array_17__[17] += ((x.m_c[141] * __y_xpd__[3][6]) + (x.m_c[144] * __y_xpd__[3][9]) + (x.m_c[142] * __y_xpd__[3][7]) + (x.m_c[137] * __y_xpd__[3][2]) + (x.m_c[135] * __y_xpd__[3][0]) + (x.m_c[140] * __y_xpd__[3][5]) + (x.m_c[138] * __y_xpd__[3][3]) + (x.m_c[136] * __y_xpd__[3][1]) + (x.m_c[139] * __y_xpd__[3][4]) + (x.m_c[143] * __y_xpd__[3][8]));
			__tmp_coord_array_17__[18] += ((x.m_c[148] * __y_xpd__[3][3]) + (x.m_c[149] * __y_xpd__[3][4]) + (x.m_c[154] * __y_xpd__[3][9]) + (x.m_c[152] * __y_xpd__[3][7]) + (x.m_c[146] * __y_xpd__[3][1]) + (x.m_c[151] * __y_xpd__[3][6]) + (x.m_c[145] * __y_xpd__[3][0]) + (x.m_c[147] * __y_xpd__[3][2]) + (x.m_c[153] * __y_xpd__[3][8]) + (x.m_c[150] * __y_xpd__[3][5]));
			__tmp_coord_array_17__[19] += ((x.m_c[156] * __y_xpd__[3][1]) + (x.m_c[157] * __y_xpd__[3][2]) + (x.m_c[158] * __y_xpd__[3][3]) + (x.m_c[155] * __y_xpd__[3][0]) + (x.m_c[159] * __y_xpd__[3][4]) + (x.m_c[161] * __y_xpd__[3][6]) + (x.m_c[163] * __y_xpd__[3][8]) + (x.m_c[160] * __y_xpd__[3][5]) + (x.m_c[164] * __y_xpd__[3][9]) + (x.m_c[162] * __y_xpd__[3][7]));
			__tmp_coord_array_17__[20] += ((x.m_c[171] * __y_xpd__[3][6]) + (x.m_c[165] * __y_xpd__[3][0]) + (x.m_c[170] * __y_xpd__[3][5]) + (x.m_c[174] * __y_xpd__[3][9]) + (x.m_c[173] * __y_xpd__[3][8]) + (x.m_c[168] * __y_xpd__[3][3]) + (x.m_c[172] * __y_xpd__[3][7]) + (x.m_c[166] * __y_xpd__[3][1]) + (x.m_c[167] * __y_xpd__[3][2]) + (x.m_c[169] * __y_xpd__[3][4]));
			__tmp_coord_array_17__[21] += ((x.m_c[175] * __y_xpd__[3][0]) + (x.m_c[179] * __y_xpd__[3][4]) + (x.m_c[181] * __y_xpd__[3][6]) + (x.m_c[177] * __y_xpd__[3][2]) + (x.m_c[180] * __y_xpd__[3][5]) + (x.m_c[184] * __y_xpd__[3][9]) + (x.m_c[182] * __y_xpd__[3][7]) + (x.m_c[178] * __y_xpd__[3][3]) + (x.m_c[176] * __y_xpd__[3][1]) + (x.m_c[183] * __y_xpd__[3][8]));
			__tmp_coord_array_17__[22] += ((x.m_c[190] * __y_xpd__[3][5]) + (x.m_c[186] * __y_xpd__[3][1]) + (x.m_c[192] * __y_xpd__[3][7]) + (x.m_c[189] * __y_xpd__[3][4]) + (x.m_c[185] * __y_xpd__[3][0]) + (x.m_c[191] * __y_xpd__[3][6]) + (x.m_c[193] * __y_xpd__[3][8]) + (x.m_c[194] * __y_xpd__[3][9]) + (x.m_c[187] * __y_xpd__[3][2]) + (x.m_c[188] * __y_xpd__[3][3]));
			__tmp_coord_array_17__[23] += ((x.m_c[199] * __y_xpd__[3][4]) + (x.m_c[195] * __y_xpd__[3][0]) + (x.m_c[204] * __y_xpd__[3][9]) + (x.m_c[198] * __y_xpd__[3][3]) + (x.m_c[202] * __y_xpd__[3][7]) + (x.m_c[200] * __y_xpd__[3][5]) + (x.m_c[203] * __y_xpd__[3][8]) + (x.m_c[197] * __y_xpd__[3][2]) + (x.m_c[201] * __y_xpd__[3][6]) + (x.m_c[196] * __y_xpd__[3][1]));
			__tmp_coord_array_17__[24] += ((x.m_c[208] * __y_xpd__[3][3]) + (x.m_c[210] * __y_xpd__[3][5]) + (x.m_c[213] * __y_xpd__[3][8]) + (x.m_c[206] * __y_xpd__[3][1]) + (x.m_c[205] * __y_xpd__[3][0]) + (x.m_c[211] * __y_xpd__[3][6]) + (x.m_c[207] * __y_xpd__[3][2]) + (x.m_c[214] * __y_xpd__[3][9]) + (x.m_c[209] * __y_xpd__[3][4]) + (x.m_c[212] * __y_xpd__[3][7]));
			__tmp_coord_array_17__[25] += ((x.m_c[222] * __y_xpd__[3][7]) + (x.m_c[221] * __y_xpd__[3][6]) + (x.m_c[217] * __y_xpd__[3][2]) + (x.m_c[216] * __y_xpd__[3][1]) + (x.m_c[220] * __y_xpd__[3][5]) + (x.m_c[218] * __y_xpd__[3][3]) + (x.m_c[224] * __y_xpd__[3][9]) + (x.m_c[219] * __y_xpd__[3][4]) + (x.m_c[223] * __y_xpd__[3][8]) + (x.m_c[215] * __y_xpd__[3][0]));

		}
		if (((y.m_gu & 16) != 0)) {
			__tmp_coord_array_17__[26] += ((-1.0f * x.m_c[227] * __y_xpd__[4][2]) + (x.m_c[226] * __y_xpd__[4][1]) + (x.m_c[225] * __y_xpd__[4][0]) + (x.m_c[228] * __y_xpd__[4][3]) + (x.m_c[229] * __y_xpd__[4][4]));
			__tmp_coord_array_17__[27] += ((x.m_c[234] * __y_xpd__[4][4]) + (-1.0f * x.m_c[232] * __y_xpd__[4][2]) + (x.m_c[231] * __y_xpd__[4][1]) + (x.m_c[230] * __y_xpd__[4][0]) + (x.m_c[233] * __y_xpd__[4][3]));
			__tmp_coord_array_17__[28] += ((x.m_c[237] * __y_xpd__[4][2]) + (-1.0f * x.m_c[238] * __y_xpd__[4][3]) + (-1.0f * x.m_c[235] * __y_xpd__[4][0]) + (-1.0f * x.m_c[236] * __y_xpd__[4][1]) + (-1.0f * x.m_c[239] * __y_xpd__[4][4]));
			__tmp_coord_array_17__[29] += ((x.m_c[241] * __y_xpd__[4][1]) + (x.m_c[240] * __y_xpd__[4][0]) + (x.m_c[243] * __y_xpd__[4][3]) + (x.m_c[244] * __y_xpd__[4][4]) + (-1.0f * x.m_c[242] * __y_xpd__[4][2]));
			__tmp_coord_array_17__[30] += ((-1.0f * x.m_c[247] * __y_xpd__[4][2]) + (x.m_c[246] * __y_xpd__[4][1]) + (x.m_c[245] * __y_xpd__[4][0]) + (x.m_c[249] * __y_xpd__[4][4]) + (x.m_c[248] * __y_xpd__[4][3]));

		}
		if (((y.m_gu & 32) != 0)) {
			__tmp_coord_array_17__[31] += (x.m_c[250] * __y_xpd__[5][0]);

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_17__);
		return __temp_var_1__;
	}
	namespace __G2_GENERATED__ {
		void set(om& __x__, const point& __image_of_no__, const point& __image_of_e1__, const point& __image_of_e2__, const point& __image_of_e3__, const point& __image_of_ni__) {
			__x__.m_c[0] = __image_of_no__.m_c[0];
			__x__.m_c[5] = __image_of_no__.m_c[1];
			__x__.m_c[10] = __image_of_no__.m_c[2];
			__x__.m_c[15] = __image_of_no__.m_c[3];
			__x__.m_c[20] = __image_of_no__.m_c[4];
			__x__.m_c[1] = __image_of_e1__.m_c[0];
			__x__.m_c[6] = __image_of_e1__.m_c[1];
			__x__.m_c[11] = __image_of_e1__.m_c[2];
			__x__.m_c[16] = __image_of_e1__.m_c[3];
			__x__.m_c[21] = __image_of_e1__.m_c[4];
			__x__.m_c[2] = __image_of_e2__.m_c[0];
			__x__.m_c[7] = __image_of_e2__.m_c[1];
			__x__.m_c[12] = __image_of_e2__.m_c[2];
			__x__.m_c[17] = __image_of_e2__.m_c[3];
			__x__.m_c[22] = __image_of_e2__.m_c[4];
			__x__.m_c[3] = __image_of_e3__.m_c[0];
			__x__.m_c[8] = __image_of_e3__.m_c[1];
			__x__.m_c[13] = __image_of_e3__.m_c[2];
			__x__.m_c[18] = __image_of_e3__.m_c[3];
			__x__.m_c[23] = __image_of_e3__.m_c[4];
			__x__.m_c[4] = __image_of_ni__.m_c[0];
			__x__.m_c[9] = __image_of_ni__.m_c[1];
			__x__.m_c[14] = __image_of_ni__.m_c[2];
			__x__.m_c[19] = __image_of_ni__.m_c[3];
			__x__.m_c[24] = __image_of_ni__.m_c[4];
			__x__.m_c[25] = ((-1.0f * __x__.m_c[1] * __x__.m_c[5]) + (__x__.m_c[6] * __x__.m_c[0]));
			__x__.m_c[35] = ((__x__.m_c[11] * __x__.m_c[0]) + (-1.0f * __x__.m_c[1] * __x__.m_c[10]));
			__x__.m_c[45] = ((__x__.m_c[16] * __x__.m_c[0]) + (-1.0f * __x__.m_c[1] * __x__.m_c[15]));
			__x__.m_c[55] = ((-1.0f * __x__.m_c[6] * __x__.m_c[10]) + (__x__.m_c[11] * __x__.m_c[5]));
			__x__.m_c[65] = ((__x__.m_c[16] * __x__.m_c[10]) + (-1.0f * __x__.m_c[11] * __x__.m_c[15]));
			__x__.m_c[75] = ((-1.0f * __x__.m_c[16] * __x__.m_c[5]) + (__x__.m_c[6] * __x__.m_c[15]));
			__x__.m_c[85] = ((-1.0f * __x__.m_c[6] * __x__.m_c[20]) + (__x__.m_c[21] * __x__.m_c[5]));
			__x__.m_c[95] = ((__x__.m_c[21] * __x__.m_c[10]) + (-1.0f * __x__.m_c[11] * __x__.m_c[20]));
			__x__.m_c[105] = ((__x__.m_c[21] * __x__.m_c[15]) + (-1.0f * __x__.m_c[16] * __x__.m_c[20]));
			__x__.m_c[115] = ((-1.0f * __x__.m_c[1] * __x__.m_c[20]) + (__x__.m_c[21] * __x__.m_c[0]));
			__x__.m_c[26] = ((-1.0f * __x__.m_c[2] * __x__.m_c[5]) + (__x__.m_c[7] * __x__.m_c[0]));
			__x__.m_c[36] = ((-1.0f * __x__.m_c[2] * __x__.m_c[10]) + (__x__.m_c[12] * __x__.m_c[0]));
			__x__.m_c[46] = ((__x__.m_c[17] * __x__.m_c[0]) + (-1.0f * __x__.m_c[2] * __x__.m_c[15]));
			__x__.m_c[56] = ((-1.0f * __x__.m_c[7] * __x__.m_c[10]) + (__x__.m_c[12] * __x__.m_c[5]));
			__x__.m_c[66] = ((__x__.m_c[17] * __x__.m_c[10]) + (-1.0f * __x__.m_c[12] * __x__.m_c[15]));
			__x__.m_c[76] = ((__x__.m_c[7] * __x__.m_c[15]) + (-1.0f * __x__.m_c[17] * __x__.m_c[5]));
			__x__.m_c[86] = ((__x__.m_c[22] * __x__.m_c[5]) + (-1.0f * __x__.m_c[7] * __x__.m_c[20]));
			__x__.m_c[96] = ((__x__.m_c[22] * __x__.m_c[10]) + (-1.0f * __x__.m_c[12] * __x__.m_c[20]));
			__x__.m_c[106] = ((-1.0f * __x__.m_c[17] * __x__.m_c[20]) + (__x__.m_c[22] * __x__.m_c[15]));
			__x__.m_c[116] = ((-1.0f * __x__.m_c[2] * __x__.m_c[20]) + (__x__.m_c[22] * __x__.m_c[0]));
			__x__.m_c[27] = ((-1.0f * __x__.m_c[3] * __x__.m_c[5]) + (__x__.m_c[8] * __x__.m_c[0]));
			__x__.m_c[37] = ((__x__.m_c[13] * __x__.m_c[0]) + (-1.0f * __x__.m_c[3] * __x__.m_c[10]));
			__x__.m_c[47] = ((__x__.m_c[18] * __x__.m_c[0]) + (-1.0f * __x__.m_c[3] * __x__.m_c[15]));
			__x__.m_c[57] = ((-1.0f * __x__.m_c[8] * __x__.m_c[10]) + (__x__.m_c[13] * __x__.m_c[5]));
			__x__.m_c[67] = ((__x__.m_c[18] * __x__.m_c[10]) + (-1.0f * __x__.m_c[13] * __x__.m_c[15]));
			__x__.m_c[77] = ((__x__.m_c[8] * __x__.m_c[15]) + (-1.0f * __x__.m_c[18] * __x__.m_c[5]));
			__x__.m_c[87] = ((__x__.m_c[23] * __x__.m_c[5]) + (-1.0f * __x__.m_c[8] * __x__.m_c[20]));
			__x__.m_c[97] = ((__x__.m_c[23] * __x__.m_c[10]) + (-1.0f * __x__.m_c[13] * __x__.m_c[20]));
			__x__.m_c[107] = ((__x__.m_c[23] * __x__.m_c[15]) + (-1.0f * __x__.m_c[18] * __x__.m_c[20]));
			__x__.m_c[117] = ((__x__.m_c[23] * __x__.m_c[0]) + (-1.0f * __x__.m_c[3] * __x__.m_c[20]));
			__x__.m_c[28] = ((__x__.m_c[7] * __x__.m_c[1]) + (-1.0f * __x__.m_c[2] * __x__.m_c[6]));
			__x__.m_c[38] = ((-1.0f * __x__.m_c[2] * __x__.m_c[11]) + (__x__.m_c[12] * __x__.m_c[1]));
			__x__.m_c[48] = ((-1.0f * __x__.m_c[2] * __x__.m_c[16]) + (__x__.m_c[17] * __x__.m_c[1]));
			__x__.m_c[58] = ((__x__.m_c[12] * __x__.m_c[6]) + (-1.0f * __x__.m_c[7] * __x__.m_c[11]));
			__x__.m_c[68] = ((-1.0f * __x__.m_c[12] * __x__.m_c[16]) + (__x__.m_c[17] * __x__.m_c[11]));
			__x__.m_c[78] = ((-1.0f * __x__.m_c[17] * __x__.m_c[6]) + (__x__.m_c[7] * __x__.m_c[16]));
			__x__.m_c[88] = ((-1.0f * __x__.m_c[7] * __x__.m_c[21]) + (__x__.m_c[22] * __x__.m_c[6]));
			__x__.m_c[98] = ((-1.0f * __x__.m_c[12] * __x__.m_c[21]) + (__x__.m_c[22] * __x__.m_c[11]));
			__x__.m_c[108] = ((__x__.m_c[22] * __x__.m_c[16]) + (-1.0f * __x__.m_c[17] * __x__.m_c[21]));
			__x__.m_c[118] = ((__x__.m_c[22] * __x__.m_c[1]) + (-1.0f * __x__.m_c[2] * __x__.m_c[21]));
			__x__.m_c[29] = ((__x__.m_c[8] * __x__.m_c[2]) + (-1.0f * __x__.m_c[3] * __x__.m_c[7]));
			__x__.m_c[39] = ((__x__.m_c[13] * __x__.m_c[2]) + (-1.0f * __x__.m_c[3] * __x__.m_c[12]));
			__x__.m_c[49] = ((__x__.m_c[18] * __x__.m_c[2]) + (-1.0f * __x__.m_c[3] * __x__.m_c[17]));
			__x__.m_c[59] = ((__x__.m_c[13] * __x__.m_c[7]) + (-1.0f * __x__.m_c[8] * __x__.m_c[12]));
			__x__.m_c[69] = ((-1.0f * __x__.m_c[13] * __x__.m_c[17]) + (__x__.m_c[18] * __x__.m_c[12]));
			__x__.m_c[79] = ((-1.0f * __x__.m_c[18] * __x__.m_c[7]) + (__x__.m_c[8] * __x__.m_c[17]));
			__x__.m_c[89] = ((__x__.m_c[23] * __x__.m_c[7]) + (-1.0f * __x__.m_c[8] * __x__.m_c[22]));
			__x__.m_c[99] = ((-1.0f * __x__.m_c[13] * __x__.m_c[22]) + (__x__.m_c[23] * __x__.m_c[12]));
			__x__.m_c[109] = ((__x__.m_c[23] * __x__.m_c[17]) + (-1.0f * __x__.m_c[18] * __x__.m_c[22]));
			__x__.m_c[119] = ((__x__.m_c[23] * __x__.m_c[2]) + (-1.0f * __x__.m_c[3] * __x__.m_c[22]));
			__x__.m_c[30] = ((__x__.m_c[3] * __x__.m_c[6]) + (-1.0f * __x__.m_c[8] * __x__.m_c[1]));
			__x__.m_c[40] = ((__x__.m_c[3] * __x__.m_c[11]) + (-1.0f * __x__.m_c[13] * __x__.m_c[1]));
			__x__.m_c[50] = ((__x__.m_c[3] * __x__.m_c[16]) + (-1.0f * __x__.m_c[18] * __x__.m_c[1]));
			__x__.m_c[60] = ((__x__.m_c[8] * __x__.m_c[11]) + (-1.0f * __x__.m_c[13] * __x__.m_c[6]));
			__x__.m_c[70] = ((-1.0f * __x__.m_c[18] * __x__.m_c[11]) + (__x__.m_c[13] * __x__.m_c[16]));
			__x__.m_c[80] = ((__x__.m_c[18] * __x__.m_c[6]) + (-1.0f * __x__.m_c[8] * __x__.m_c[16]));
			__x__.m_c[90] = ((__x__.m_c[8] * __x__.m_c[21]) + (-1.0f * __x__.m_c[23] * __x__.m_c[6]));
			__x__.m_c[100] = ((-1.0f * __x__.m_c[23] * __x__.m_c[11]) + (__x__.m_c[13] * __x__.m_c[21]));
			__x__.m_c[110] = ((__x__.m_c[18] * __x__.m_c[21]) + (-1.0f * __x__.m_c[23] * __x__.m_c[16]));
			__x__.m_c[120] = ((__x__.m_c[3] * __x__.m_c[21]) + (-1.0f * __x__.m_c[23] * __x__.m_c[1]));
			__x__.m_c[31] = ((__x__.m_c[9] * __x__.m_c[1]) + (-1.0f * __x__.m_c[4] * __x__.m_c[6]));
			__x__.m_c[41] = ((-1.0f * __x__.m_c[4] * __x__.m_c[11]) + (__x__.m_c[14] * __x__.m_c[1]));
			__x__.m_c[51] = ((-1.0f * __x__.m_c[4] * __x__.m_c[16]) + (__x__.m_c[19] * __x__.m_c[1]));
			__x__.m_c[61] = ((__x__.m_c[14] * __x__.m_c[6]) + (-1.0f * __x__.m_c[9] * __x__.m_c[11]));
			__x__.m_c[71] = ((-1.0f * __x__.m_c[14] * __x__.m_c[16]) + (__x__.m_c[19] * __x__.m_c[11]));
			__x__.m_c[81] = ((__x__.m_c[9] * __x__.m_c[16]) + (-1.0f * __x__.m_c[19] * __x__.m_c[6]));
			__x__.m_c[91] = ((-1.0f * __x__.m_c[9] * __x__.m_c[21]) + (__x__.m_c[24] * __x__.m_c[6]));
			__x__.m_c[101] = ((-1.0f * __x__.m_c[14] * __x__.m_c[21]) + (__x__.m_c[24] * __x__.m_c[11]));
			__x__.m_c[111] = ((-1.0f * __x__.m_c[19] * __x__.m_c[21]) + (__x__.m_c[24] * __x__.m_c[16]));
			__x__.m_c[121] = ((__x__.m_c[24] * __x__.m_c[1]) + (-1.0f * __x__.m_c[4] * __x__.m_c[21]));
			__x__.m_c[32] = ((-1.0f * __x__.m_c[4] * __x__.m_c[7]) + (__x__.m_c[9] * __x__.m_c[2]));
			__x__.m_c[42] = ((__x__.m_c[14] * __x__.m_c[2]) + (-1.0f * __x__.m_c[4] * __x__.m_c[12]));
			__x__.m_c[52] = ((__x__.m_c[19] * __x__.m_c[2]) + (-1.0f * __x__.m_c[4] * __x__.m_c[17]));
			__x__.m_c[62] = ((__x__.m_c[14] * __x__.m_c[7]) + (-1.0f * __x__.m_c[9] * __x__.m_c[12]));
			__x__.m_c[72] = ((-1.0f * __x__.m_c[14] * __x__.m_c[17]) + (__x__.m_c[19] * __x__.m_c[12]));
			__x__.m_c[82] = ((__x__.m_c[9] * __x__.m_c[17]) + (-1.0f * __x__.m_c[19] * __x__.m_c[7]));
			__x__.m_c[92] = ((-1.0f * __x__.m_c[9] * __x__.m_c[22]) + (__x__.m_c[24] * __x__.m_c[7]));
			__x__.m_c[102] = ((__x__.m_c[24] * __x__.m_c[12]) + (-1.0f * __x__.m_c[14] * __x__.m_c[22]));
			__x__.m_c[112] = ((__x__.m_c[24] * __x__.m_c[17]) + (-1.0f * __x__.m_c[19] * __x__.m_c[22]));
			__x__.m_c[122] = ((__x__.m_c[24] * __x__.m_c[2]) + (-1.0f * __x__.m_c[4] * __x__.m_c[22]));
			__x__.m_c[33] = ((-1.0f * __x__.m_c[4] * __x__.m_c[8]) + (__x__.m_c[9] * __x__.m_c[3]));
			__x__.m_c[43] = ((-1.0f * __x__.m_c[4] * __x__.m_c[13]) + (__x__.m_c[14] * __x__.m_c[3]));
			__x__.m_c[53] = ((-1.0f * __x__.m_c[4] * __x__.m_c[18]) + (__x__.m_c[19] * __x__.m_c[3]));
			__x__.m_c[63] = ((__x__.m_c[14] * __x__.m_c[8]) + (-1.0f * __x__.m_c[9] * __x__.m_c[13]));
			__x__.m_c[73] = ((-1.0f * __x__.m_c[14] * __x__.m_c[18]) + (__x__.m_c[19] * __x__.m_c[13]));
			__x__.m_c[83] = ((__x__.m_c[9] * __x__.m_c[18]) + (-1.0f * __x__.m_c[19] * __x__.m_c[8]));
			__x__.m_c[93] = ((__x__.m_c[24] * __x__.m_c[8]) + (-1.0f * __x__.m_c[9] * __x__.m_c[23]));
			__x__.m_c[103] = ((-1.0f * __x__.m_c[14] * __x__.m_c[23]) + (__x__.m_c[24] * __x__.m_c[13]));
			__x__.m_c[113] = ((-1.0f * __x__.m_c[19] * __x__.m_c[23]) + (__x__.m_c[24] * __x__.m_c[18]));
			__x__.m_c[123] = ((__x__.m_c[24] * __x__.m_c[3]) + (-1.0f * __x__.m_c[4] * __x__.m_c[23]));
			__x__.m_c[34] = ((-1.0f * __x__.m_c[4] * __x__.m_c[5]) + (__x__.m_c[9] * __x__.m_c[0]));
			__x__.m_c[44] = ((-1.0f * __x__.m_c[4] * __x__.m_c[10]) + (__x__.m_c[14] * __x__.m_c[0]));
			__x__.m_c[54] = ((-1.0f * __x__.m_c[4] * __x__.m_c[15]) + (__x__.m_c[19] * __x__.m_c[0]));
			__x__.m_c[64] = ((-1.0f * __x__.m_c[9] * __x__.m_c[10]) + (__x__.m_c[14] * __x__.m_c[5]));
			__x__.m_c[74] = ((-1.0f * __x__.m_c[14] * __x__.m_c[15]) + (__x__.m_c[19] * __x__.m_c[10]));
			__x__.m_c[84] = ((-1.0f * __x__.m_c[19] * __x__.m_c[5]) + (__x__.m_c[9] * __x__.m_c[15]));
			__x__.m_c[94] = ((-1.0f * __x__.m_c[9] * __x__.m_c[20]) + (__x__.m_c[24] * __x__.m_c[5]));
			__x__.m_c[104] = ((__x__.m_c[24] * __x__.m_c[10]) + (-1.0f * __x__.m_c[14] * __x__.m_c[20]));
			__x__.m_c[114] = ((-1.0f * __x__.m_c[19] * __x__.m_c[20]) + (__x__.m_c[24] * __x__.m_c[15]));
			__x__.m_c[124] = ((-1.0f * __x__.m_c[4] * __x__.m_c[20]) + (__x__.m_c[24] * __x__.m_c[0]));
			__x__.m_c[125] = ((-1.0f * __x__.m_c[103] * __x__.m_c[17]) + (__x__.m_c[73] * __x__.m_c[22]) + (__x__.m_c[113] * __x__.m_c[12]));
			__x__.m_c[135] = ((__x__.m_c[93] * __x__.m_c[17]) + (__x__.m_c[83] * __x__.m_c[22]) + (-1.0f * __x__.m_c[113] * __x__.m_c[7]));
			__x__.m_c[145] = ((__x__.m_c[63] * __x__.m_c[22]) + (-1.0f * __x__.m_c[93] * __x__.m_c[12]) + (__x__.m_c[103] * __x__.m_c[7]));
			__x__.m_c[155] = ((__x__.m_c[53] * __x__.m_c[22]) + (__x__.m_c[113] * __x__.m_c[2]) + (-1.0f * __x__.m_c[123] * __x__.m_c[17]));
			__x__.m_c[165] = ((-1.0f * __x__.m_c[123] * __x__.m_c[7]) + (__x__.m_c[33] * __x__.m_c[22]) + (__x__.m_c[93] * __x__.m_c[2]));
			__x__.m_c[175] = ((-1.0f * __x__.m_c[123] * __x__.m_c[12]) + (__x__.m_c[103] * __x__.m_c[2]) + (__x__.m_c[43] * __x__.m_c[22]));
			__x__.m_c[185] = ((-1.0f * __x__.m_c[53] * __x__.m_c[12]) + (__x__.m_c[43] * __x__.m_c[17]) + (__x__.m_c[73] * __x__.m_c[2]));
			__x__.m_c[195] = ((-1.0f * __x__.m_c[83] * __x__.m_c[2]) + (-1.0f * __x__.m_c[53] * __x__.m_c[7]) + (__x__.m_c[33] * __x__.m_c[17]));
			__x__.m_c[205] = ((__x__.m_c[33] * __x__.m_c[12]) + (__x__.m_c[63] * __x__.m_c[2]) + (-1.0f * __x__.m_c[43] * __x__.m_c[7]));
			__x__.m_c[215] = ((__x__.m_c[83] * __x__.m_c[12]) + (__x__.m_c[73] * __x__.m_c[7]) + (__x__.m_c[63] * __x__.m_c[17]));
			__x__.m_c[126] = ((-1.0f * __x__.m_c[73] * __x__.m_c[21]) + (__x__.m_c[103] * __x__.m_c[16]) + (-1.0f * __x__.m_c[113] * __x__.m_c[11]));
			__x__.m_c[136] = ((-1.0f * __x__.m_c[93] * __x__.m_c[16]) + (__x__.m_c[113] * __x__.m_c[6]) + (-1.0f * __x__.m_c[83] * __x__.m_c[21]));
			__x__.m_c[146] = ((__x__.m_c[93] * __x__.m_c[11]) + (-1.0f * __x__.m_c[63] * __x__.m_c[21]) + (-1.0f * __x__.m_c[103] * __x__.m_c[6]));
			__x__.m_c[156] = ((__x__.m_c[123] * __x__.m_c[16]) + (-1.0f * __x__.m_c[53] * __x__.m_c[21]) + (-1.0f * __x__.m_c[113] * __x__.m_c[1]));
			__x__.m_c[166] = ((__x__.m_c[123] * __x__.m_c[6]) + (-1.0f * __x__.m_c[33] * __x__.m_c[21]) + (-1.0f * __x__.m_c[93] * __x__.m_c[1]));
			__x__.m_c[176] = ((-1.0f * __x__.m_c[103] * __x__.m_c[1]) + (-1.0f * __x__.m_c[43] * __x__.m_c[21]) + (__x__.m_c[123] * __x__.m_c[11]));
			__x__.m_c[186] = ((-1.0f * __x__.m_c[73] * __x__.m_c[1]) + (__x__.m_c[53] * __x__.m_c[11]) + (-1.0f * __x__.m_c[43] * __x__.m_c[16]));
			__x__.m_c[196] = ((-1.0f * __x__.m_c[33] * __x__.m_c[16]) + (__x__.m_c[83] * __x__.m_c[1]) + (__x__.m_c[53] * __x__.m_c[6]));
			__x__.m_c[206] = ((__x__.m_c[43] * __x__.m_c[6]) + (-1.0f * __x__.m_c[63] * __x__.m_c[1]) + (-1.0f * __x__.m_c[33] * __x__.m_c[11]));
			__x__.m_c[216] = ((-1.0f * __x__.m_c[83] * __x__.m_c[11]) + (-1.0f * __x__.m_c[63] * __x__.m_c[16]) + (-1.0f * __x__.m_c[73] * __x__.m_c[6]));
			__x__.m_c[127] = ((-1.0f * __x__.m_c[102] * __x__.m_c[16]) + (__x__.m_c[112] * __x__.m_c[11]) + (__x__.m_c[72] * __x__.m_c[21]));
			__x__.m_c[137] = ((-1.0f * __x__.m_c[112] * __x__.m_c[6]) + (__x__.m_c[92] * __x__.m_c[16]) + (__x__.m_c[82] * __x__.m_c[21]));
			__x__.m_c[147] = ((__x__.m_c[102] * __x__.m_c[6]) + (__x__.m_c[62] * __x__.m_c[21]) + (-1.0f * __x__.m_c[92] * __x__.m_c[11]));
			__x__.m_c[157] = ((-1.0f * __x__.m_c[122] * __x__.m_c[16]) + (__x__.m_c[52] * __x__.m_c[21]) + (__x__.m_c[112] * __x__.m_c[1]));
			__x__.m_c[167] = ((-1.0f * __x__.m_c[122] * __x__.m_c[6]) + (__x__.m_c[92] * __x__.m_c[1]) + (__x__.m_c[32] * __x__.m_c[21]));
			__x__.m_c[177] = ((-1.0f * __x__.m_c[122] * __x__.m_c[11]) + (__x__.m_c[102] * __x__.m_c[1]) + (__x__.m_c[42] * __x__.m_c[21]));
			__x__.m_c[187] = ((__x__.m_c[42] * __x__.m_c[16]) + (__x__.m_c[72] * __x__.m_c[1]) + (-1.0f * __x__.m_c[52] * __x__.m_c[11]));
			__x__.m_c[197] = ((-1.0f * __x__.m_c[52] * __x__.m_c[6]) + (__x__.m_c[32] * __x__.m_c[16]) + (-1.0f * __x__.m_c[82] * __x__.m_c[1]));
			__x__.m_c[207] = ((-1.0f * __x__.m_c[42] * __x__.m_c[6]) + (__x__.m_c[32] * __x__.m_c[11]) + (__x__.m_c[62] * __x__.m_c[1]));
			__x__.m_c[217] = ((__x__.m_c[62] * __x__.m_c[16]) + (__x__.m_c[82] * __x__.m_c[11]) + (__x__.m_c[72] * __x__.m_c[6]));
			__x__.m_c[128] = ((-1.0f * __x__.m_c[114] * __x__.m_c[13]) + (__x__.m_c[104] * __x__.m_c[18]) + (-1.0f * __x__.m_c[74] * __x__.m_c[23]));
			__x__.m_c[138] = ((__x__.m_c[114] * __x__.m_c[8]) + (-1.0f * __x__.m_c[94] * __x__.m_c[18]) + (-1.0f * __x__.m_c[84] * __x__.m_c[23]));
			__x__.m_c[148] = ((-1.0f * __x__.m_c[64] * __x__.m_c[23]) + (-1.0f * __x__.m_c[104] * __x__.m_c[8]) + (__x__.m_c[94] * __x__.m_c[13]));
			__x__.m_c[158] = ((-1.0f * __x__.m_c[54] * __x__.m_c[23]) + (__x__.m_c[124] * __x__.m_c[18]) + (-1.0f * __x__.m_c[114] * __x__.m_c[3]));
			__x__.m_c[168] = ((__x__.m_c[124] * __x__.m_c[8]) + (-1.0f * __x__.m_c[34] * __x__.m_c[23]) + (-1.0f * __x__.m_c[94] * __x__.m_c[3]));
			__x__.m_c[178] = ((-1.0f * __x__.m_c[44] * __x__.m_c[23]) + (__x__.m_c[124] * __x__.m_c[13]) + (-1.0f * __x__.m_c[104] * __x__.m_c[3]));
			__x__.m_c[188] = ((__x__.m_c[54] * __x__.m_c[13]) + (-1.0f * __x__.m_c[44] * __x__.m_c[18]) + (-1.0f * __x__.m_c[74] * __x__.m_c[3]));
			__x__.m_c[198] = ((-1.0f * __x__.m_c[34] * __x__.m_c[18]) + (__x__.m_c[84] * __x__.m_c[3]) + (__x__.m_c[54] * __x__.m_c[8]));
			__x__.m_c[208] = ((-1.0f * __x__.m_c[34] * __x__.m_c[13]) + (__x__.m_c[44] * __x__.m_c[8]) + (-1.0f * __x__.m_c[64] * __x__.m_c[3]));
			__x__.m_c[218] = ((-1.0f * __x__.m_c[64] * __x__.m_c[18]) + (-1.0f * __x__.m_c[84] * __x__.m_c[13]) + (-1.0f * __x__.m_c[74] * __x__.m_c[8]));
			__x__.m_c[129] = ((-1.0f * __x__.m_c[114] * __x__.m_c[11]) + (__x__.m_c[104] * __x__.m_c[16]) + (-1.0f * __x__.m_c[74] * __x__.m_c[21]));
			__x__.m_c[139] = ((__x__.m_c[114] * __x__.m_c[6]) + (-1.0f * __x__.m_c[84] * __x__.m_c[21]) + (-1.0f * __x__.m_c[94] * __x__.m_c[16]));
			__x__.m_c[149] = ((-1.0f * __x__.m_c[64] * __x__.m_c[21]) + (__x__.m_c[94] * __x__.m_c[11]) + (-1.0f * __x__.m_c[104] * __x__.m_c[6]));
			__x__.m_c[159] = ((-1.0f * __x__.m_c[114] * __x__.m_c[1]) + (-1.0f * __x__.m_c[54] * __x__.m_c[21]) + (__x__.m_c[124] * __x__.m_c[16]));
			__x__.m_c[169] = ((-1.0f * __x__.m_c[94] * __x__.m_c[1]) + (-1.0f * __x__.m_c[34] * __x__.m_c[21]) + (__x__.m_c[124] * __x__.m_c[6]));
			__x__.m_c[179] = ((-1.0f * __x__.m_c[104] * __x__.m_c[1]) + (__x__.m_c[124] * __x__.m_c[11]) + (-1.0f * __x__.m_c[44] * __x__.m_c[21]));
			__x__.m_c[189] = ((__x__.m_c[54] * __x__.m_c[11]) + (-1.0f * __x__.m_c[44] * __x__.m_c[16]) + (-1.0f * __x__.m_c[74] * __x__.m_c[1]));
			__x__.m_c[199] = ((__x__.m_c[84] * __x__.m_c[1]) + (__x__.m_c[54] * __x__.m_c[6]) + (-1.0f * __x__.m_c[34] * __x__.m_c[16]));
			__x__.m_c[209] = ((__x__.m_c[44] * __x__.m_c[6]) + (-1.0f * __x__.m_c[64] * __x__.m_c[1]) + (-1.0f * __x__.m_c[34] * __x__.m_c[11]));
			__x__.m_c[219] = ((-1.0f * __x__.m_c[64] * __x__.m_c[16]) + (-1.0f * __x__.m_c[84] * __x__.m_c[11]) + (-1.0f * __x__.m_c[74] * __x__.m_c[6]));
			__x__.m_c[130] = ((__x__.m_c[104] * __x__.m_c[17]) + (-1.0f * __x__.m_c[114] * __x__.m_c[12]) + (-1.0f * __x__.m_c[74] * __x__.m_c[22]));
			__x__.m_c[140] = ((__x__.m_c[114] * __x__.m_c[7]) + (-1.0f * __x__.m_c[94] * __x__.m_c[17]) + (-1.0f * __x__.m_c[84] * __x__.m_c[22]));
			__x__.m_c[150] = ((-1.0f * __x__.m_c[104] * __x__.m_c[7]) + (-1.0f * __x__.m_c[64] * __x__.m_c[22]) + (__x__.m_c[94] * __x__.m_c[12]));
			__x__.m_c[160] = ((-1.0f * __x__.m_c[114] * __x__.m_c[2]) + (-1.0f * __x__.m_c[54] * __x__.m_c[22]) + (__x__.m_c[124] * __x__.m_c[17]));
			__x__.m_c[170] = ((-1.0f * __x__.m_c[94] * __x__.m_c[2]) + (-1.0f * __x__.m_c[34] * __x__.m_c[22]) + (__x__.m_c[124] * __x__.m_c[7]));
			__x__.m_c[180] = ((-1.0f * __x__.m_c[44] * __x__.m_c[22]) + (-1.0f * __x__.m_c[104] * __x__.m_c[2]) + (__x__.m_c[124] * __x__.m_c[12]));
			__x__.m_c[190] = ((-1.0f * __x__.m_c[74] * __x__.m_c[2]) + (-1.0f * __x__.m_c[44] * __x__.m_c[17]) + (__x__.m_c[54] * __x__.m_c[12]));
			__x__.m_c[200] = ((-1.0f * __x__.m_c[34] * __x__.m_c[17]) + (__x__.m_c[54] * __x__.m_c[7]) + (__x__.m_c[84] * __x__.m_c[2]));
			__x__.m_c[210] = ((__x__.m_c[44] * __x__.m_c[7]) + (-1.0f * __x__.m_c[64] * __x__.m_c[2]) + (-1.0f * __x__.m_c[34] * __x__.m_c[12]));
			__x__.m_c[220] = ((-1.0f * __x__.m_c[84] * __x__.m_c[12]) + (-1.0f * __x__.m_c[64] * __x__.m_c[17]) + (-1.0f * __x__.m_c[74] * __x__.m_c[7]));
			__x__.m_c[131] = ((__x__.m_c[69] * __x__.m_c[20]) + (__x__.m_c[109] * __x__.m_c[10]) + (-1.0f * __x__.m_c[99] * __x__.m_c[15]));
			__x__.m_c[141] = ((__x__.m_c[79] * __x__.m_c[20]) + (-1.0f * __x__.m_c[109] * __x__.m_c[5]) + (__x__.m_c[89] * __x__.m_c[15]));
			__x__.m_c[151] = ((__x__.m_c[59] * __x__.m_c[20]) + (__x__.m_c[99] * __x__.m_c[5]) + (-1.0f * __x__.m_c[89] * __x__.m_c[10]));
			__x__.m_c[161] = ((-1.0f * __x__.m_c[119] * __x__.m_c[15]) + (__x__.m_c[109] * __x__.m_c[0]) + (__x__.m_c[49] * __x__.m_c[20]));
			__x__.m_c[171] = ((__x__.m_c[89] * __x__.m_c[0]) + (__x__.m_c[29] * __x__.m_c[20]) + (-1.0f * __x__.m_c[119] * __x__.m_c[5]));
			__x__.m_c[181] = ((-1.0f * __x__.m_c[119] * __x__.m_c[10]) + (__x__.m_c[99] * __x__.m_c[0]) + (__x__.m_c[39] * __x__.m_c[20]));
			__x__.m_c[191] = ((-1.0f * __x__.m_c[49] * __x__.m_c[10]) + (__x__.m_c[39] * __x__.m_c[15]) + (__x__.m_c[69] * __x__.m_c[0]));
			__x__.m_c[201] = ((-1.0f * __x__.m_c[49] * __x__.m_c[5]) + (__x__.m_c[29] * __x__.m_c[15]) + (-1.0f * __x__.m_c[79] * __x__.m_c[0]));
			__x__.m_c[211] = ((__x__.m_c[59] * __x__.m_c[0]) + (__x__.m_c[29] * __x__.m_c[10]) + (-1.0f * __x__.m_c[39] * __x__.m_c[5]));
			__x__.m_c[221] = ((__x__.m_c[69] * __x__.m_c[5]) + (__x__.m_c[59] * __x__.m_c[15]) + (__x__.m_c[79] * __x__.m_c[10]));
			__x__.m_c[132] = ((-1.0f * __x__.m_c[70] * __x__.m_c[20]) + (-1.0f * __x__.m_c[110] * __x__.m_c[10]) + (__x__.m_c[100] * __x__.m_c[15]));
			__x__.m_c[142] = ((-1.0f * __x__.m_c[90] * __x__.m_c[15]) + (__x__.m_c[110] * __x__.m_c[5]) + (-1.0f * __x__.m_c[80] * __x__.m_c[20]));
			__x__.m_c[152] = ((__x__.m_c[90] * __x__.m_c[10]) + (-1.0f * __x__.m_c[100] * __x__.m_c[5]) + (-1.0f * __x__.m_c[60] * __x__.m_c[20]));
			__x__.m_c[162] = ((-1.0f * __x__.m_c[50] * __x__.m_c[20]) + (__x__.m_c[120] * __x__.m_c[15]) + (-1.0f * __x__.m_c[110] * __x__.m_c[0]));
			__x__.m_c[172] = ((-1.0f * __x__.m_c[90] * __x__.m_c[0]) + (-1.0f * __x__.m_c[30] * __x__.m_c[20]) + (__x__.m_c[120] * __x__.m_c[5]));
			__x__.m_c[182] = ((__x__.m_c[120] * __x__.m_c[10]) + (-1.0f * __x__.m_c[40] * __x__.m_c[20]) + (-1.0f * __x__.m_c[100] * __x__.m_c[0]));
			__x__.m_c[192] = ((__x__.m_c[50] * __x__.m_c[10]) + (-1.0f * __x__.m_c[70] * __x__.m_c[0]) + (-1.0f * __x__.m_c[40] * __x__.m_c[15]));
			__x__.m_c[202] = ((__x__.m_c[50] * __x__.m_c[5]) + (__x__.m_c[80] * __x__.m_c[0]) + (-1.0f * __x__.m_c[30] * __x__.m_c[15]));
			__x__.m_c[212] = ((__x__.m_c[40] * __x__.m_c[5]) + (-1.0f * __x__.m_c[60] * __x__.m_c[0]) + (-1.0f * __x__.m_c[30] * __x__.m_c[10]));
			__x__.m_c[222] = ((-1.0f * __x__.m_c[60] * __x__.m_c[15]) + (-1.0f * __x__.m_c[70] * __x__.m_c[5]) + (-1.0f * __x__.m_c[80] * __x__.m_c[10]));
			__x__.m_c[133] = ((-1.0f * __x__.m_c[98] * __x__.m_c[15]) + (__x__.m_c[108] * __x__.m_c[10]) + (__x__.m_c[68] * __x__.m_c[20]));
			__x__.m_c[143] = ((-1.0f * __x__.m_c[108] * __x__.m_c[5]) + (__x__.m_c[88] * __x__.m_c[15]) + (__x__.m_c[78] * __x__.m_c[20]));
			__x__.m_c[153] = ((-1.0f * __x__.m_c[88] * __x__.m_c[10]) + (__x__.m_c[58] * __x__.m_c[20]) + (__x__.m_c[98] * __x__.m_c[5]));
			__x__.m_c[163] = ((-1.0f * __x__.m_c[118] * __x__.m_c[15]) + (__x__.m_c[108] * __x__.m_c[0]) + (__x__.m_c[48] * __x__.m_c[20]));
			__x__.m_c[173] = ((-1.0f * __x__.m_c[118] * __x__.m_c[5]) + (__x__.m_c[88] * __x__.m_c[0]) + (__x__.m_c[28] * __x__.m_c[20]));
			__x__.m_c[183] = ((__x__.m_c[98] * __x__.m_c[0]) + (__x__.m_c[38] * __x__.m_c[20]) + (-1.0f * __x__.m_c[118] * __x__.m_c[10]));
			__x__.m_c[193] = ((__x__.m_c[38] * __x__.m_c[15]) + (__x__.m_c[68] * __x__.m_c[0]) + (-1.0f * __x__.m_c[48] * __x__.m_c[10]));
			__x__.m_c[203] = ((-1.0f * __x__.m_c[48] * __x__.m_c[5]) + (__x__.m_c[28] * __x__.m_c[15]) + (-1.0f * __x__.m_c[78] * __x__.m_c[0]));
			__x__.m_c[213] = ((-1.0f * __x__.m_c[38] * __x__.m_c[5]) + (__x__.m_c[58] * __x__.m_c[0]) + (__x__.m_c[28] * __x__.m_c[10]));
			__x__.m_c[223] = ((__x__.m_c[78] * __x__.m_c[10]) + (__x__.m_c[58] * __x__.m_c[15]) + (__x__.m_c[68] * __x__.m_c[5]));
			__x__.m_c[134] = ((__x__.m_c[70] * __x__.m_c[22]) + (-1.0f * __x__.m_c[100] * __x__.m_c[17]) + (__x__.m_c[110] * __x__.m_c[12]));
			__x__.m_c[144] = ((-1.0f * __x__.m_c[110] * __x__.m_c[7]) + (__x__.m_c[80] * __x__.m_c[22]) + (__x__.m_c[90] * __x__.m_c[17]));
			__x__.m_c[154] = ((__x__.m_c[60] * __x__.m_c[22]) + (-1.0f * __x__.m_c[90] * __x__.m_c[12]) + (__x__.m_c[100] * __x__.m_c[7]));
			__x__.m_c[164] = ((__x__.m_c[110] * __x__.m_c[2]) + (__x__.m_c[50] * __x__.m_c[22]) + (-1.0f * __x__.m_c[120] * __x__.m_c[17]));
			__x__.m_c[174] = ((__x__.m_c[30] * __x__.m_c[22]) + (-1.0f * __x__.m_c[120] * __x__.m_c[7]) + (__x__.m_c[90] * __x__.m_c[2]));
			__x__.m_c[184] = ((__x__.m_c[40] * __x__.m_c[22]) + (-1.0f * __x__.m_c[120] * __x__.m_c[12]) + (__x__.m_c[100] * __x__.m_c[2]));
			__x__.m_c[194] = ((__x__.m_c[70] * __x__.m_c[2]) + (__x__.m_c[40] * __x__.m_c[17]) + (-1.0f * __x__.m_c[50] * __x__.m_c[12]));
			__x__.m_c[204] = ((-1.0f * __x__.m_c[80] * __x__.m_c[2]) + (__x__.m_c[30] * __x__.m_c[17]) + (-1.0f * __x__.m_c[50] * __x__.m_c[7]));
			__x__.m_c[214] = ((__x__.m_c[60] * __x__.m_c[2]) + (__x__.m_c[30] * __x__.m_c[12]) + (-1.0f * __x__.m_c[40] * __x__.m_c[7]));
			__x__.m_c[224] = ((__x__.m_c[80] * __x__.m_c[12]) + (__x__.m_c[70] * __x__.m_c[7]) + (__x__.m_c[60] * __x__.m_c[17]));
			__x__.m_c[225] = ((-1.0f * __x__.m_c[144] * __x__.m_c[14]) + (__x__.m_c[224] * __x__.m_c[24]) + (-1.0f * __x__.m_c[134] * __x__.m_c[9]) + (-1.0f * __x__.m_c[154] * __x__.m_c[19]));
			__x__.m_c[230] = ((__x__.m_c[164] * __x__.m_c[14]) + (-1.0f * __x__.m_c[134] * __x__.m_c[4]) + (__x__.m_c[194] * __x__.m_c[24]) + (-1.0f * __x__.m_c[184] * __x__.m_c[19]));
			__x__.m_c[235] = ((__x__.m_c[204] * __x__.m_c[24]) + (__x__.m_c[144] * __x__.m_c[4]) + (-1.0f * __x__.m_c[174] * __x__.m_c[19]) + (__x__.m_c[164] * __x__.m_c[9]));
			__x__.m_c[240] = ((-1.0f * __x__.m_c[154] * __x__.m_c[4]) + (__x__.m_c[214] * __x__.m_c[24]) + (__x__.m_c[184] * __x__.m_c[9]) + (-1.0f * __x__.m_c[174] * __x__.m_c[14]));
			__x__.m_c[245] = ((-1.0f * __x__.m_c[224] * __x__.m_c[4]) + (-1.0f * __x__.m_c[204] * __x__.m_c[14]) + (__x__.m_c[214] * __x__.m_c[19]) + (__x__.m_c[194] * __x__.m_c[9]));
			__x__.m_c[226] = ((__x__.m_c[221] * __x__.m_c[24]) + (-1.0f * __x__.m_c[141] * __x__.m_c[14]) + (-1.0f * __x__.m_c[131] * __x__.m_c[9]) + (-1.0f * __x__.m_c[151] * __x__.m_c[19]));
			__x__.m_c[231] = ((__x__.m_c[161] * __x__.m_c[14]) + (-1.0f * __x__.m_c[131] * __x__.m_c[4]) + (-1.0f * __x__.m_c[181] * __x__.m_c[19]) + (__x__.m_c[191] * __x__.m_c[24]));
			__x__.m_c[236] = ((__x__.m_c[141] * __x__.m_c[4]) + (__x__.m_c[161] * __x__.m_c[9]) + (-1.0f * __x__.m_c[171] * __x__.m_c[19]) + (__x__.m_c[201] * __x__.m_c[24]));
			__x__.m_c[241] = ((-1.0f * __x__.m_c[151] * __x__.m_c[4]) + (__x__.m_c[181] * __x__.m_c[9]) + (-1.0f * __x__.m_c[171] * __x__.m_c[14]) + (__x__.m_c[211] * __x__.m_c[24]));
			__x__.m_c[246] = ((-1.0f * __x__.m_c[221] * __x__.m_c[4]) + (__x__.m_c[191] * __x__.m_c[9]) + (-1.0f * __x__.m_c[201] * __x__.m_c[14]) + (__x__.m_c[211] * __x__.m_c[19]));
			__x__.m_c[227] = ((__x__.m_c[222] * __x__.m_c[24]) + (-1.0f * __x__.m_c[132] * __x__.m_c[9]) + (-1.0f * __x__.m_c[152] * __x__.m_c[19]) + (-1.0f * __x__.m_c[142] * __x__.m_c[14]));
			__x__.m_c[232] = ((-1.0f * __x__.m_c[132] * __x__.m_c[4]) + (__x__.m_c[162] * __x__.m_c[14]) + (-1.0f * __x__.m_c[182] * __x__.m_c[19]) + (__x__.m_c[192] * __x__.m_c[24]));
			__x__.m_c[237] = ((__x__.m_c[162] * __x__.m_c[9]) + (-1.0f * __x__.m_c[172] * __x__.m_c[19]) + (__x__.m_c[202] * __x__.m_c[24]) + (__x__.m_c[142] * __x__.m_c[4]));
			__x__.m_c[242] = ((-1.0f * __x__.m_c[152] * __x__.m_c[4]) + (__x__.m_c[182] * __x__.m_c[9]) + (-1.0f * __x__.m_c[172] * __x__.m_c[14]) + (__x__.m_c[212] * __x__.m_c[24]));
			__x__.m_c[247] = ((__x__.m_c[212] * __x__.m_c[19]) + (-1.0f * __x__.m_c[202] * __x__.m_c[14]) + (-1.0f * __x__.m_c[222] * __x__.m_c[4]) + (__x__.m_c[192] * __x__.m_c[9]));
			__x__.m_c[228] = ((__x__.m_c[223] * __x__.m_c[24]) + (-1.0f * __x__.m_c[143] * __x__.m_c[14]) + (-1.0f * __x__.m_c[153] * __x__.m_c[19]) + (-1.0f * __x__.m_c[133] * __x__.m_c[9]));
			__x__.m_c[233] = ((-1.0f * __x__.m_c[183] * __x__.m_c[19]) + (-1.0f * __x__.m_c[133] * __x__.m_c[4]) + (__x__.m_c[193] * __x__.m_c[24]) + (__x__.m_c[163] * __x__.m_c[14]));
			__x__.m_c[238] = ((__x__.m_c[143] * __x__.m_c[4]) + (-1.0f * __x__.m_c[173] * __x__.m_c[19]) + (__x__.m_c[203] * __x__.m_c[24]) + (__x__.m_c[163] * __x__.m_c[9]));
			__x__.m_c[243] = ((-1.0f * __x__.m_c[153] * __x__.m_c[4]) + (__x__.m_c[213] * __x__.m_c[24]) + (__x__.m_c[183] * __x__.m_c[9]) + (-1.0f * __x__.m_c[173] * __x__.m_c[14]));
			__x__.m_c[248] = ((__x__.m_c[193] * __x__.m_c[9]) + (-1.0f * __x__.m_c[203] * __x__.m_c[14]) + (__x__.m_c[213] * __x__.m_c[19]) + (-1.0f * __x__.m_c[223] * __x__.m_c[4]));
			__x__.m_c[229] = ((__x__.m_c[134] * __x__.m_c[5]) + (__x__.m_c[154] * __x__.m_c[15]) + (__x__.m_c[144] * __x__.m_c[10]) + (-1.0f * __x__.m_c[224] * __x__.m_c[20]));
			__x__.m_c[234] = ((__x__.m_c[184] * __x__.m_c[15]) + (__x__.m_c[134] * __x__.m_c[0]) + (-1.0f * __x__.m_c[164] * __x__.m_c[10]) + (-1.0f * __x__.m_c[194] * __x__.m_c[20]));
			__x__.m_c[239] = ((__x__.m_c[174] * __x__.m_c[15]) + (-1.0f * __x__.m_c[204] * __x__.m_c[20]) + (-1.0f * __x__.m_c[144] * __x__.m_c[0]) + (-1.0f * __x__.m_c[164] * __x__.m_c[5]));
			__x__.m_c[244] = ((__x__.m_c[174] * __x__.m_c[10]) + (-1.0f * __x__.m_c[184] * __x__.m_c[5]) + (__x__.m_c[154] * __x__.m_c[0]) + (-1.0f * __x__.m_c[214] * __x__.m_c[20]));
			__x__.m_c[249] = ((__x__.m_c[204] * __x__.m_c[10]) + (-1.0f * __x__.m_c[194] * __x__.m_c[5]) + (-1.0f * __x__.m_c[214] * __x__.m_c[15]) + (__x__.m_c[224] * __x__.m_c[0]));
			__x__.m_c[250] = ((__x__.m_c[239] * __x__.m_c[14]) + (__x__.m_c[229] * __x__.m_c[4]) + (-1.0f * __x__.m_c[244] * __x__.m_c[19]) + (__x__.m_c[249] * __x__.m_c[24]) + (-1.0f * __x__.m_c[234] * __x__.m_c[9]));
		}
		void set(om& __x__, const omFlatPoint& __y__) {
			__x__.m_c[0] = (char)0;
			__x__.m_c[5] = (char)0;
			__x__.m_c[10] = (char)0;
			__x__.m_c[15] = (char)0;
			__x__.m_c[20] = (char)0;
			__x__.m_c[1] = (char)0;
			__x__.m_c[6] = (char)0;
			__x__.m_c[11] = (char)0;
			__x__.m_c[16] = (char)0;
			__x__.m_c[21] = (char)0;
			__x__.m_c[2] = (char)0;
			__x__.m_c[7] = (char)0;
			__x__.m_c[12] = (char)0;
			__x__.m_c[17] = (char)0;
			__x__.m_c[22] = (char)0;
			__x__.m_c[3] = (char)0;
			__x__.m_c[8] = (char)0;
			__x__.m_c[13] = (char)0;
			__x__.m_c[18] = (char)0;
			__x__.m_c[23] = (char)0;
			__x__.m_c[4] = (char)0;
			__x__.m_c[9] = (char)0;
			__x__.m_c[14] = (char)0;
			__x__.m_c[19] = (char)0;
			__x__.m_c[24] = (char)0;
			__x__.m_c[25] = ((__x__.m_c[6] * __x__.m_c[0]) + (-1.0f * __x__.m_c[1] * __x__.m_c[5]));
			__x__.m_c[35] = ((__x__.m_c[11] * __x__.m_c[0]) + (-1.0f * __x__.m_c[1] * __x__.m_c[10]));
			__x__.m_c[45] = ((-1.0f * __x__.m_c[1] * __x__.m_c[15]) + (__x__.m_c[16] * __x__.m_c[0]));
			__x__.m_c[55] = ((-1.0f * __x__.m_c[6] * __x__.m_c[10]) + (__x__.m_c[11] * __x__.m_c[5]));
			__x__.m_c[65] = ((__x__.m_c[16] * __x__.m_c[10]) + (-1.0f * __x__.m_c[11] * __x__.m_c[15]));
			__x__.m_c[75] = ((__x__.m_c[6] * __x__.m_c[15]) + (-1.0f * __x__.m_c[16] * __x__.m_c[5]));
			__x__.m_c[85] = ((__x__.m_c[21] * __x__.m_c[5]) + (-1.0f * __x__.m_c[6] * __x__.m_c[20]));
			__x__.m_c[95] = ((-1.0f * __x__.m_c[11] * __x__.m_c[20]) + (__x__.m_c[21] * __x__.m_c[10]));
			__x__.m_c[105] = ((__x__.m_c[21] * __x__.m_c[15]) + (-1.0f * __x__.m_c[16] * __x__.m_c[20]));
			__x__.m_c[115] = ((-1.0f * __x__.m_c[1] * __x__.m_c[20]) + (__x__.m_c[21] * __x__.m_c[0]));
			__x__.m_c[26] = ((__x__.m_c[7] * __x__.m_c[0]) + (-1.0f * __x__.m_c[2] * __x__.m_c[5]));
			__x__.m_c[36] = ((-1.0f * __x__.m_c[2] * __x__.m_c[10]) + (__x__.m_c[12] * __x__.m_c[0]));
			__x__.m_c[46] = ((-1.0f * __x__.m_c[2] * __x__.m_c[15]) + (__x__.m_c[17] * __x__.m_c[0]));
			__x__.m_c[56] = ((__x__.m_c[12] * __x__.m_c[5]) + (-1.0f * __x__.m_c[7] * __x__.m_c[10]));
			__x__.m_c[66] = ((-1.0f * __x__.m_c[12] * __x__.m_c[15]) + (__x__.m_c[17] * __x__.m_c[10]));
			__x__.m_c[76] = ((__x__.m_c[7] * __x__.m_c[15]) + (-1.0f * __x__.m_c[17] * __x__.m_c[5]));
			__x__.m_c[86] = ((-1.0f * __x__.m_c[7] * __x__.m_c[20]) + (__x__.m_c[22] * __x__.m_c[5]));
			__x__.m_c[96] = ((__x__.m_c[22] * __x__.m_c[10]) + (-1.0f * __x__.m_c[12] * __x__.m_c[20]));
			__x__.m_c[106] = ((-1.0f * __x__.m_c[17] * __x__.m_c[20]) + (__x__.m_c[22] * __x__.m_c[15]));
			__x__.m_c[116] = ((__x__.m_c[22] * __x__.m_c[0]) + (-1.0f * __x__.m_c[2] * __x__.m_c[20]));
			__x__.m_c[27] = ((-1.0f * __x__.m_c[3] * __x__.m_c[5]) + (__x__.m_c[8] * __x__.m_c[0]));
			__x__.m_c[37] = ((__x__.m_c[13] * __x__.m_c[0]) + (-1.0f * __x__.m_c[3] * __x__.m_c[10]));
			__x__.m_c[47] = ((-1.0f * __x__.m_c[3] * __x__.m_c[15]) + (__x__.m_c[18] * __x__.m_c[0]));
			__x__.m_c[57] = ((__x__.m_c[13] * __x__.m_c[5]) + (-1.0f * __x__.m_c[8] * __x__.m_c[10]));
			__x__.m_c[67] = ((-1.0f * __x__.m_c[13] * __x__.m_c[15]) + (__x__.m_c[18] * __x__.m_c[10]));
			__x__.m_c[77] = ((__x__.m_c[8] * __x__.m_c[15]) + (-1.0f * __x__.m_c[18] * __x__.m_c[5]));
			__x__.m_c[87] = ((-1.0f * __x__.m_c[8] * __x__.m_c[20]) + (__x__.m_c[23] * __x__.m_c[5]));
			__x__.m_c[97] = ((__x__.m_c[23] * __x__.m_c[10]) + (-1.0f * __x__.m_c[13] * __x__.m_c[20]));
			__x__.m_c[107] = ((-1.0f * __x__.m_c[18] * __x__.m_c[20]) + (__x__.m_c[23] * __x__.m_c[15]));
			__x__.m_c[117] = ((-1.0f * __x__.m_c[3] * __x__.m_c[20]) + (__x__.m_c[23] * __x__.m_c[0]));
			__x__.m_c[28] = ((__x__.m_c[7] * __x__.m_c[1]) + (-1.0f * __x__.m_c[2] * __x__.m_c[6]));
			__x__.m_c[38] = ((-1.0f * __x__.m_c[2] * __x__.m_c[11]) + (__x__.m_c[12] * __x__.m_c[1]));
			__x__.m_c[48] = ((-1.0f * __x__.m_c[2] * __x__.m_c[16]) + (__x__.m_c[17] * __x__.m_c[1]));
			__x__.m_c[58] = ((-1.0f * __x__.m_c[7] * __x__.m_c[11]) + (__x__.m_c[12] * __x__.m_c[6]));
			__x__.m_c[68] = ((-1.0f * __x__.m_c[12] * __x__.m_c[16]) + (__x__.m_c[17] * __x__.m_c[11]));
			__x__.m_c[78] = ((__x__.m_c[7] * __x__.m_c[16]) + (-1.0f * __x__.m_c[17] * __x__.m_c[6]));
			__x__.m_c[88] = ((__x__.m_c[22] * __x__.m_c[6]) + (-1.0f * __x__.m_c[7] * __x__.m_c[21]));
			__x__.m_c[98] = ((__x__.m_c[22] * __x__.m_c[11]) + (-1.0f * __x__.m_c[12] * __x__.m_c[21]));
			__x__.m_c[108] = ((-1.0f * __x__.m_c[17] * __x__.m_c[21]) + (__x__.m_c[22] * __x__.m_c[16]));
			__x__.m_c[118] = ((__x__.m_c[22] * __x__.m_c[1]) + (-1.0f * __x__.m_c[2] * __x__.m_c[21]));
			__x__.m_c[29] = ((__x__.m_c[8] * __x__.m_c[2]) + (-1.0f * __x__.m_c[3] * __x__.m_c[7]));
			__x__.m_c[39] = ((-1.0f * __x__.m_c[3] * __x__.m_c[12]) + (__x__.m_c[13] * __x__.m_c[2]));
			__x__.m_c[49] = ((-1.0f * __x__.m_c[3] * __x__.m_c[17]) + (__x__.m_c[18] * __x__.m_c[2]));
			__x__.m_c[59] = ((__x__.m_c[13] * __x__.m_c[7]) + (-1.0f * __x__.m_c[8] * __x__.m_c[12]));
			__x__.m_c[69] = ((__x__.m_c[18] * __x__.m_c[12]) + (-1.0f * __x__.m_c[13] * __x__.m_c[17]));
			__x__.m_c[79] = ((__x__.m_c[8] * __x__.m_c[17]) + (-1.0f * __x__.m_c[18] * __x__.m_c[7]));
			__x__.m_c[89] = ((-1.0f * __x__.m_c[8] * __x__.m_c[22]) + (__x__.m_c[23] * __x__.m_c[7]));
			__x__.m_c[99] = ((__x__.m_c[23] * __x__.m_c[12]) + (-1.0f * __x__.m_c[13] * __x__.m_c[22]));
			__x__.m_c[109] = ((-1.0f * __x__.m_c[18] * __x__.m_c[22]) + (__x__.m_c[23] * __x__.m_c[17]));
			__x__.m_c[119] = ((-1.0f * __x__.m_c[3] * __x__.m_c[22]) + (__x__.m_c[23] * __x__.m_c[2]));
			__x__.m_c[30] = ((-1.0f * __x__.m_c[8] * __x__.m_c[1]) + (__x__.m_c[3] * __x__.m_c[6]));
			__x__.m_c[40] = ((-1.0f * __x__.m_c[13] * __x__.m_c[1]) + (__x__.m_c[3] * __x__.m_c[11]));
			__x__.m_c[50] = ((__x__.m_c[3] * __x__.m_c[16]) + (-1.0f * __x__.m_c[18] * __x__.m_c[1]));
			__x__.m_c[60] = ((__x__.m_c[8] * __x__.m_c[11]) + (-1.0f * __x__.m_c[13] * __x__.m_c[6]));
			__x__.m_c[70] = ((__x__.m_c[13] * __x__.m_c[16]) + (-1.0f * __x__.m_c[18] * __x__.m_c[11]));
			__x__.m_c[80] = ((-1.0f * __x__.m_c[8] * __x__.m_c[16]) + (__x__.m_c[18] * __x__.m_c[6]));
			__x__.m_c[90] = ((-1.0f * __x__.m_c[23] * __x__.m_c[6]) + (__x__.m_c[8] * __x__.m_c[21]));
			__x__.m_c[100] = ((-1.0f * __x__.m_c[23] * __x__.m_c[11]) + (__x__.m_c[13] * __x__.m_c[21]));
			__x__.m_c[110] = ((__x__.m_c[18] * __x__.m_c[21]) + (-1.0f * __x__.m_c[23] * __x__.m_c[16]));
			__x__.m_c[120] = ((__x__.m_c[3] * __x__.m_c[21]) + (-1.0f * __x__.m_c[23] * __x__.m_c[1]));
			__x__.m_c[31] = ((__x__.m_c[9] * __x__.m_c[1]) + (-1.0f * __x__.m_c[4] * __x__.m_c[6]));
			__x__.m_c[41] = ((-1.0f * __x__.m_c[4] * __x__.m_c[11]) + (__x__.m_c[14] * __x__.m_c[1]));
			__x__.m_c[51] = ((-1.0f * __x__.m_c[4] * __x__.m_c[16]) + (__x__.m_c[19] * __x__.m_c[1]));
			__x__.m_c[61] = ((__x__.m_c[14] * __x__.m_c[6]) + (-1.0f * __x__.m_c[9] * __x__.m_c[11]));
			__x__.m_c[71] = ((__x__.m_c[19] * __x__.m_c[11]) + (-1.0f * __x__.m_c[14] * __x__.m_c[16]));
			__x__.m_c[81] = ((__x__.m_c[9] * __x__.m_c[16]) + (-1.0f * __x__.m_c[19] * __x__.m_c[6]));
			__x__.m_c[91] = ((__x__.m_c[24] * __x__.m_c[6]) + (-1.0f * __x__.m_c[9] * __x__.m_c[21]));
			__x__.m_c[101] = ((__x__.m_c[24] * __x__.m_c[11]) + (-1.0f * __x__.m_c[14] * __x__.m_c[21]));
			__x__.m_c[111] = ((__x__.m_c[24] * __x__.m_c[16]) + (-1.0f * __x__.m_c[19] * __x__.m_c[21]));
			__x__.m_c[121] = ((-1.0f * __x__.m_c[4] * __x__.m_c[21]) + (__x__.m_c[24] * __x__.m_c[1]));
			__x__.m_c[32] = ((__x__.m_c[9] * __x__.m_c[2]) + (-1.0f * __x__.m_c[4] * __x__.m_c[7]));
			__x__.m_c[42] = ((__x__.m_c[14] * __x__.m_c[2]) + (-1.0f * __x__.m_c[4] * __x__.m_c[12]));
			__x__.m_c[52] = ((-1.0f * __x__.m_c[4] * __x__.m_c[17]) + (__x__.m_c[19] * __x__.m_c[2]));
			__x__.m_c[62] = ((-1.0f * __x__.m_c[9] * __x__.m_c[12]) + (__x__.m_c[14] * __x__.m_c[7]));
			__x__.m_c[72] = ((-1.0f * __x__.m_c[14] * __x__.m_c[17]) + (__x__.m_c[19] * __x__.m_c[12]));
			__x__.m_c[82] = ((__x__.m_c[9] * __x__.m_c[17]) + (-1.0f * __x__.m_c[19] * __x__.m_c[7]));
			__x__.m_c[92] = ((-1.0f * __x__.m_c[9] * __x__.m_c[22]) + (__x__.m_c[24] * __x__.m_c[7]));
			__x__.m_c[102] = ((-1.0f * __x__.m_c[14] * __x__.m_c[22]) + (__x__.m_c[24] * __x__.m_c[12]));
			__x__.m_c[112] = ((-1.0f * __x__.m_c[19] * __x__.m_c[22]) + (__x__.m_c[24] * __x__.m_c[17]));
			__x__.m_c[122] = ((__x__.m_c[24] * __x__.m_c[2]) + (-1.0f * __x__.m_c[4] * __x__.m_c[22]));
			__x__.m_c[33] = ((__x__.m_c[9] * __x__.m_c[3]) + (-1.0f * __x__.m_c[4] * __x__.m_c[8]));
			__x__.m_c[43] = ((__x__.m_c[14] * __x__.m_c[3]) + (-1.0f * __x__.m_c[4] * __x__.m_c[13]));
			__x__.m_c[53] = ((__x__.m_c[19] * __x__.m_c[3]) + (-1.0f * __x__.m_c[4] * __x__.m_c[18]));
			__x__.m_c[63] = ((-1.0f * __x__.m_c[9] * __x__.m_c[13]) + (__x__.m_c[14] * __x__.m_c[8]));
			__x__.m_c[73] = ((__x__.m_c[19] * __x__.m_c[13]) + (-1.0f * __x__.m_c[14] * __x__.m_c[18]));
			__x__.m_c[83] = ((-1.0f * __x__.m_c[19] * __x__.m_c[8]) + (__x__.m_c[9] * __x__.m_c[18]));
			__x__.m_c[93] = ((-1.0f * __x__.m_c[9] * __x__.m_c[23]) + (__x__.m_c[24] * __x__.m_c[8]));
			__x__.m_c[103] = ((-1.0f * __x__.m_c[14] * __x__.m_c[23]) + (__x__.m_c[24] * __x__.m_c[13]));
			__x__.m_c[113] = ((-1.0f * __x__.m_c[19] * __x__.m_c[23]) + (__x__.m_c[24] * __x__.m_c[18]));
			__x__.m_c[123] = ((-1.0f * __x__.m_c[4] * __x__.m_c[23]) + (__x__.m_c[24] * __x__.m_c[3]));
			__x__.m_c[34] = ((__x__.m_c[9] * __x__.m_c[0]) + (-1.0f * __x__.m_c[4] * __x__.m_c[5]));
			__x__.m_c[44] = ((__x__.m_c[14] * __x__.m_c[0]) + (-1.0f * __x__.m_c[4] * __x__.m_c[10]));
			__x__.m_c[54] = ((-1.0f * __x__.m_c[4] * __x__.m_c[15]) + (__x__.m_c[19] * __x__.m_c[0]));
			__x__.m_c[64] = ((-1.0f * __x__.m_c[9] * __x__.m_c[10]) + (__x__.m_c[14] * __x__.m_c[5]));
			__x__.m_c[74] = ((-1.0f * __x__.m_c[14] * __x__.m_c[15]) + (__x__.m_c[19] * __x__.m_c[10]));
			__x__.m_c[84] = ((__x__.m_c[9] * __x__.m_c[15]) + (-1.0f * __x__.m_c[19] * __x__.m_c[5]));
			__x__.m_c[94] = ((__x__.m_c[24] * __x__.m_c[5]) + (-1.0f * __x__.m_c[9] * __x__.m_c[20]));
			__x__.m_c[104] = ((-1.0f * __x__.m_c[14] * __x__.m_c[20]) + (__x__.m_c[24] * __x__.m_c[10]));
			__x__.m_c[114] = ((__x__.m_c[24] * __x__.m_c[15]) + (-1.0f * __x__.m_c[19] * __x__.m_c[20]));
			__x__.m_c[124] = ((__x__.m_c[24] * __x__.m_c[0]) + (-1.0f * __x__.m_c[4] * __x__.m_c[20]));
			__x__.m_c[125] = ((__x__.m_c[73] * __x__.m_c[22]) + (-1.0f * __x__.m_c[103] * __x__.m_c[17]) + (__x__.m_c[113] * __x__.m_c[12]));
			__x__.m_c[135] = ((-1.0f * __x__.m_c[113] * __x__.m_c[7]) + (__x__.m_c[93] * __x__.m_c[17]) + (__x__.m_c[83] * __x__.m_c[22]));
			__x__.m_c[145] = ((__x__.m_c[63] * __x__.m_c[22]) + (-1.0f * __x__.m_c[93] * __x__.m_c[12]) + (__x__.m_c[103] * __x__.m_c[7]));
			__x__.m_c[155] = ((__x__.m_c[113] * __x__.m_c[2]) + (-1.0f * __x__.m_c[123] * __x__.m_c[17]) + (__x__.m_c[53] * __x__.m_c[22]));
			__x__.m_c[165] = ((-1.0f * __x__.m_c[123] * __x__.m_c[7]) + (__x__.m_c[33] * __x__.m_c[22]) + (__x__.m_c[93] * __x__.m_c[2]));
			__x__.m_c[175] = ((__x__.m_c[103] * __x__.m_c[2]) + (-1.0f * __x__.m_c[123] * __x__.m_c[12]) + (__x__.m_c[43] * __x__.m_c[22]));
			__x__.m_c[185] = ((-1.0f * __x__.m_c[53] * __x__.m_c[12]) + (__x__.m_c[43] * __x__.m_c[17]) + (__x__.m_c[73] * __x__.m_c[2]));
			__x__.m_c[195] = ((-1.0f * __x__.m_c[83] * __x__.m_c[2]) + (-1.0f * __x__.m_c[53] * __x__.m_c[7]) + (__x__.m_c[33] * __x__.m_c[17]));
			__x__.m_c[205] = ((-1.0f * __x__.m_c[43] * __x__.m_c[7]) + (__x__.m_c[33] * __x__.m_c[12]) + (__x__.m_c[63] * __x__.m_c[2]));
			__x__.m_c[215] = ((__x__.m_c[83] * __x__.m_c[12]) + (__x__.m_c[73] * __x__.m_c[7]) + (__x__.m_c[63] * __x__.m_c[17]));
			__x__.m_c[126] = ((-1.0f * __x__.m_c[73] * __x__.m_c[21]) + (__x__.m_c[103] * __x__.m_c[16]) + (-1.0f * __x__.m_c[113] * __x__.m_c[11]));
			__x__.m_c[136] = ((-1.0f * __x__.m_c[83] * __x__.m_c[21]) + (-1.0f * __x__.m_c[93] * __x__.m_c[16]) + (__x__.m_c[113] * __x__.m_c[6]));
			__x__.m_c[146] = ((-1.0f * __x__.m_c[103] * __x__.m_c[6]) + (-1.0f * __x__.m_c[63] * __x__.m_c[21]) + (__x__.m_c[93] * __x__.m_c[11]));
			__x__.m_c[156] = ((-1.0f * __x__.m_c[53] * __x__.m_c[21]) + (-1.0f * __x__.m_c[113] * __x__.m_c[1]) + (__x__.m_c[123] * __x__.m_c[16]));
			__x__.m_c[166] = ((__x__.m_c[123] * __x__.m_c[6]) + (-1.0f * __x__.m_c[93] * __x__.m_c[1]) + (-1.0f * __x__.m_c[33] * __x__.m_c[21]));
			__x__.m_c[176] = ((-1.0f * __x__.m_c[103] * __x__.m_c[1]) + (__x__.m_c[123] * __x__.m_c[11]) + (-1.0f * __x__.m_c[43] * __x__.m_c[21]));
			__x__.m_c[186] = ((__x__.m_c[53] * __x__.m_c[11]) + (-1.0f * __x__.m_c[73] * __x__.m_c[1]) + (-1.0f * __x__.m_c[43] * __x__.m_c[16]));
			__x__.m_c[196] = ((__x__.m_c[53] * __x__.m_c[6]) + (__x__.m_c[83] * __x__.m_c[1]) + (-1.0f * __x__.m_c[33] * __x__.m_c[16]));
			__x__.m_c[206] = ((-1.0f * __x__.m_c[63] * __x__.m_c[1]) + (-1.0f * __x__.m_c[33] * __x__.m_c[11]) + (__x__.m_c[43] * __x__.m_c[6]));
			__x__.m_c[216] = ((-1.0f * __x__.m_c[63] * __x__.m_c[16]) + (-1.0f * __x__.m_c[73] * __x__.m_c[6]) + (-1.0f * __x__.m_c[83] * __x__.m_c[11]));
			__x__.m_c[127] = ((-1.0f * __x__.m_c[102] * __x__.m_c[16]) + (__x__.m_c[72] * __x__.m_c[21]) + (__x__.m_c[112] * __x__.m_c[11]));
			__x__.m_c[137] = ((-1.0f * __x__.m_c[112] * __x__.m_c[6]) + (__x__.m_c[92] * __x__.m_c[16]) + (__x__.m_c[82] * __x__.m_c[21]));
			__x__.m_c[147] = ((__x__.m_c[62] * __x__.m_c[21]) + (__x__.m_c[102] * __x__.m_c[6]) + (-1.0f * __x__.m_c[92] * __x__.m_c[11]));
			__x__.m_c[157] = ((-1.0f * __x__.m_c[122] * __x__.m_c[16]) + (__x__.m_c[52] * __x__.m_c[21]) + (__x__.m_c[112] * __x__.m_c[1]));
			__x__.m_c[167] = ((-1.0f * __x__.m_c[122] * __x__.m_c[6]) + (__x__.m_c[92] * __x__.m_c[1]) + (__x__.m_c[32] * __x__.m_c[21]));
			__x__.m_c[177] = ((-1.0f * __x__.m_c[122] * __x__.m_c[11]) + (__x__.m_c[102] * __x__.m_c[1]) + (__x__.m_c[42] * __x__.m_c[21]));
			__x__.m_c[187] = ((-1.0f * __x__.m_c[52] * __x__.m_c[11]) + (__x__.m_c[72] * __x__.m_c[1]) + (__x__.m_c[42] * __x__.m_c[16]));
			__x__.m_c[197] = ((__x__.m_c[32] * __x__.m_c[16]) + (-1.0f * __x__.m_c[82] * __x__.m_c[1]) + (-1.0f * __x__.m_c[52] * __x__.m_c[6]));
			__x__.m_c[207] = ((__x__.m_c[32] * __x__.m_c[11]) + (-1.0f * __x__.m_c[42] * __x__.m_c[6]) + (__x__.m_c[62] * __x__.m_c[1]));
			__x__.m_c[217] = ((__x__.m_c[72] * __x__.m_c[6]) + (__x__.m_c[62] * __x__.m_c[16]) + (__x__.m_c[82] * __x__.m_c[11]));
			__x__.m_c[128] = ((-1.0f * __x__.m_c[74] * __x__.m_c[23]) + (__x__.m_c[104] * __x__.m_c[18]) + (-1.0f * __x__.m_c[114] * __x__.m_c[13]));
			__x__.m_c[138] = ((-1.0f * __x__.m_c[94] * __x__.m_c[18]) + (-1.0f * __x__.m_c[84] * __x__.m_c[23]) + (__x__.m_c[114] * __x__.m_c[8]));
			__x__.m_c[148] = ((-1.0f * __x__.m_c[64] * __x__.m_c[23]) + (__x__.m_c[94] * __x__.m_c[13]) + (-1.0f * __x__.m_c[104] * __x__.m_c[8]));
			__x__.m_c[158] = ((__x__.m_c[124] * __x__.m_c[18]) + (-1.0f * __x__.m_c[54] * __x__.m_c[23]) + (-1.0f * __x__.m_c[114] * __x__.m_c[3]));
			__x__.m_c[168] = ((__x__.m_c[124] * __x__.m_c[8]) + (-1.0f * __x__.m_c[94] * __x__.m_c[3]) + (-1.0f * __x__.m_c[34] * __x__.m_c[23]));
			__x__.m_c[178] = ((__x__.m_c[124] * __x__.m_c[13]) + (-1.0f * __x__.m_c[44] * __x__.m_c[23]) + (-1.0f * __x__.m_c[104] * __x__.m_c[3]));
			__x__.m_c[188] = ((-1.0f * __x__.m_c[74] * __x__.m_c[3]) + (-1.0f * __x__.m_c[44] * __x__.m_c[18]) + (__x__.m_c[54] * __x__.m_c[13]));
			__x__.m_c[198] = ((-1.0f * __x__.m_c[34] * __x__.m_c[18]) + (__x__.m_c[84] * __x__.m_c[3]) + (__x__.m_c[54] * __x__.m_c[8]));
			__x__.m_c[208] = ((-1.0f * __x__.m_c[64] * __x__.m_c[3]) + (__x__.m_c[44] * __x__.m_c[8]) + (-1.0f * __x__.m_c[34] * __x__.m_c[13]));
			__x__.m_c[218] = ((-1.0f * __x__.m_c[84] * __x__.m_c[13]) + (-1.0f * __x__.m_c[74] * __x__.m_c[8]) + (-1.0f * __x__.m_c[64] * __x__.m_c[18]));
			__x__.m_c[129] = ((__x__.m_c[104] * __x__.m_c[16]) + (-1.0f * __x__.m_c[74] * __x__.m_c[21]) + (-1.0f * __x__.m_c[114] * __x__.m_c[11]));
			__x__.m_c[139] = ((-1.0f * __x__.m_c[94] * __x__.m_c[16]) + (__x__.m_c[114] * __x__.m_c[6]) + (-1.0f * __x__.m_c[84] * __x__.m_c[21]));
			__x__.m_c[149] = ((__x__.m_c[94] * __x__.m_c[11]) + (-1.0f * __x__.m_c[104] * __x__.m_c[6]) + (-1.0f * __x__.m_c[64] * __x__.m_c[21]));
			__x__.m_c[159] = ((-1.0f * __x__.m_c[54] * __x__.m_c[21]) + (__x__.m_c[124] * __x__.m_c[16]) + (-1.0f * __x__.m_c[114] * __x__.m_c[1]));
			__x__.m_c[169] = ((__x__.m_c[124] * __x__.m_c[6]) + (-1.0f * __x__.m_c[94] * __x__.m_c[1]) + (-1.0f * __x__.m_c[34] * __x__.m_c[21]));
			__x__.m_c[179] = ((-1.0f * __x__.m_c[104] * __x__.m_c[1]) + (__x__.m_c[124] * __x__.m_c[11]) + (-1.0f * __x__.m_c[44] * __x__.m_c[21]));
			__x__.m_c[189] = ((-1.0f * __x__.m_c[44] * __x__.m_c[16]) + (-1.0f * __x__.m_c[74] * __x__.m_c[1]) + (__x__.m_c[54] * __x__.m_c[11]));
			__x__.m_c[199] = ((__x__.m_c[54] * __x__.m_c[6]) + (-1.0f * __x__.m_c[34] * __x__.m_c[16]) + (__x__.m_c[84] * __x__.m_c[1]));
			__x__.m_c[209] = ((-1.0f * __x__.m_c[34] * __x__.m_c[11]) + (-1.0f * __x__.m_c[64] * __x__.m_c[1]) + (__x__.m_c[44] * __x__.m_c[6]));
			__x__.m_c[219] = ((-1.0f * __x__.m_c[84] * __x__.m_c[11]) + (-1.0f * __x__.m_c[74] * __x__.m_c[6]) + (-1.0f * __x__.m_c[64] * __x__.m_c[16]));
			__x__.m_c[130] = ((-1.0f * __x__.m_c[114] * __x__.m_c[12]) + (__x__.m_c[104] * __x__.m_c[17]) + (-1.0f * __x__.m_c[74] * __x__.m_c[22]));
			__x__.m_c[140] = ((-1.0f * __x__.m_c[94] * __x__.m_c[17]) + (__x__.m_c[114] * __x__.m_c[7]) + (-1.0f * __x__.m_c[84] * __x__.m_c[22]));
			__x__.m_c[150] = ((-1.0f * __x__.m_c[64] * __x__.m_c[22]) + (__x__.m_c[94] * __x__.m_c[12]) + (-1.0f * __x__.m_c[104] * __x__.m_c[7]));
			__x__.m_c[160] = ((-1.0f * __x__.m_c[114] * __x__.m_c[2]) + (-1.0f * __x__.m_c[54] * __x__.m_c[22]) + (__x__.m_c[124] * __x__.m_c[17]));
			__x__.m_c[170] = ((__x__.m_c[124] * __x__.m_c[7]) + (-1.0f * __x__.m_c[34] * __x__.m_c[22]) + (-1.0f * __x__.m_c[94] * __x__.m_c[2]));
			__x__.m_c[180] = ((__x__.m_c[124] * __x__.m_c[12]) + (-1.0f * __x__.m_c[104] * __x__.m_c[2]) + (-1.0f * __x__.m_c[44] * __x__.m_c[22]));
			__x__.m_c[190] = ((-1.0f * __x__.m_c[74] * __x__.m_c[2]) + (-1.0f * __x__.m_c[44] * __x__.m_c[17]) + (__x__.m_c[54] * __x__.m_c[12]));
			__x__.m_c[200] = ((__x__.m_c[84] * __x__.m_c[2]) + (__x__.m_c[54] * __x__.m_c[7]) + (-1.0f * __x__.m_c[34] * __x__.m_c[17]));
			__x__.m_c[210] = ((-1.0f * __x__.m_c[64] * __x__.m_c[2]) + (__x__.m_c[44] * __x__.m_c[7]) + (-1.0f * __x__.m_c[34] * __x__.m_c[12]));
			__x__.m_c[220] = ((-1.0f * __x__.m_c[64] * __x__.m_c[17]) + (-1.0f * __x__.m_c[74] * __x__.m_c[7]) + (-1.0f * __x__.m_c[84] * __x__.m_c[12]));
			__x__.m_c[131] = ((__x__.m_c[109] * __x__.m_c[10]) + (__x__.m_c[69] * __x__.m_c[20]) + (-1.0f * __x__.m_c[99] * __x__.m_c[15]));
			__x__.m_c[141] = ((-1.0f * __x__.m_c[109] * __x__.m_c[5]) + (__x__.m_c[89] * __x__.m_c[15]) + (__x__.m_c[79] * __x__.m_c[20]));
			__x__.m_c[151] = ((__x__.m_c[99] * __x__.m_c[5]) + (-1.0f * __x__.m_c[89] * __x__.m_c[10]) + (__x__.m_c[59] * __x__.m_c[20]));
			__x__.m_c[161] = ((__x__.m_c[49] * __x__.m_c[20]) + (__x__.m_c[109] * __x__.m_c[0]) + (-1.0f * __x__.m_c[119] * __x__.m_c[15]));
			__x__.m_c[171] = ((-1.0f * __x__.m_c[119] * __x__.m_c[5]) + (__x__.m_c[29] * __x__.m_c[20]) + (__x__.m_c[89] * __x__.m_c[0]));
			__x__.m_c[181] = ((-1.0f * __x__.m_c[119] * __x__.m_c[10]) + (__x__.m_c[99] * __x__.m_c[0]) + (__x__.m_c[39] * __x__.m_c[20]));
			__x__.m_c[191] = ((__x__.m_c[39] * __x__.m_c[15]) + (__x__.m_c[69] * __x__.m_c[0]) + (-1.0f * __x__.m_c[49] * __x__.m_c[10]));
			__x__.m_c[201] = ((-1.0f * __x__.m_c[49] * __x__.m_c[5]) + (-1.0f * __x__.m_c[79] * __x__.m_c[0]) + (__x__.m_c[29] * __x__.m_c[15]));
			__x__.m_c[211] = ((__x__.m_c[29] * __x__.m_c[10]) + (__x__.m_c[59] * __x__.m_c[0]) + (-1.0f * __x__.m_c[39] * __x__.m_c[5]));
			__x__.m_c[221] = ((__x__.m_c[59] * __x__.m_c[15]) + (__x__.m_c[69] * __x__.m_c[5]) + (__x__.m_c[79] * __x__.m_c[10]));
			__x__.m_c[132] = ((-1.0f * __x__.m_c[110] * __x__.m_c[10]) + (-1.0f * __x__.m_c[70] * __x__.m_c[20]) + (__x__.m_c[100] * __x__.m_c[15]));
			__x__.m_c[142] = ((-1.0f * __x__.m_c[80] * __x__.m_c[20]) + (__x__.m_c[110] * __x__.m_c[5]) + (-1.0f * __x__.m_c[90] * __x__.m_c[15]));
			__x__.m_c[152] = ((__x__.m_c[90] * __x__.m_c[10]) + (-1.0f * __x__.m_c[60] * __x__.m_c[20]) + (-1.0f * __x__.m_c[100] * __x__.m_c[5]));
			__x__.m_c[162] = ((-1.0f * __x__.m_c[110] * __x__.m_c[0]) + (__x__.m_c[120] * __x__.m_c[15]) + (-1.0f * __x__.m_c[50] * __x__.m_c[20]));
			__x__.m_c[172] = ((-1.0f * __x__.m_c[90] * __x__.m_c[0]) + (__x__.m_c[120] * __x__.m_c[5]) + (-1.0f * __x__.m_c[30] * __x__.m_c[20]));
			__x__.m_c[182] = ((-1.0f * __x__.m_c[40] * __x__.m_c[20]) + (__x__.m_c[120] * __x__.m_c[10]) + (-1.0f * __x__.m_c[100] * __x__.m_c[0]));
			__x__.m_c[192] = ((-1.0f * __x__.m_c[70] * __x__.m_c[0]) + (__x__.m_c[50] * __x__.m_c[10]) + (-1.0f * __x__.m_c[40] * __x__.m_c[15]));
			__x__.m_c[202] = ((-1.0f * __x__.m_c[30] * __x__.m_c[15]) + (__x__.m_c[80] * __x__.m_c[0]) + (__x__.m_c[50] * __x__.m_c[5]));
			__x__.m_c[212] = ((__x__.m_c[40] * __x__.m_c[5]) + (-1.0f * __x__.m_c[30] * __x__.m_c[10]) + (-1.0f * __x__.m_c[60] * __x__.m_c[0]));
			__x__.m_c[222] = ((-1.0f * __x__.m_c[70] * __x__.m_c[5]) + (-1.0f * __x__.m_c[60] * __x__.m_c[15]) + (-1.0f * __x__.m_c[80] * __x__.m_c[10]));
			__x__.m_c[133] = ((__x__.m_c[108] * __x__.m_c[10]) + (-1.0f * __x__.m_c[98] * __x__.m_c[15]) + (__x__.m_c[68] * __x__.m_c[20]));
			__x__.m_c[143] = ((__x__.m_c[88] * __x__.m_c[15]) + (-1.0f * __x__.m_c[108] * __x__.m_c[5]) + (__x__.m_c[78] * __x__.m_c[20]));
			__x__.m_c[153] = ((__x__.m_c[98] * __x__.m_c[5]) + (__x__.m_c[58] * __x__.m_c[20]) + (-1.0f * __x__.m_c[88] * __x__.m_c[10]));
			__x__.m_c[163] = ((__x__.m_c[48] * __x__.m_c[20]) + (-1.0f * __x__.m_c[118] * __x__.m_c[15]) + (__x__.m_c[108] * __x__.m_c[0]));
			__x__.m_c[173] = ((__x__.m_c[28] * __x__.m_c[20]) + (__x__.m_c[88] * __x__.m_c[0]) + (-1.0f * __x__.m_c[118] * __x__.m_c[5]));
			__x__.m_c[183] = ((__x__.m_c[98] * __x__.m_c[0]) + (__x__.m_c[38] * __x__.m_c[20]) + (-1.0f * __x__.m_c[118] * __x__.m_c[10]));
			__x__.m_c[193] = ((__x__.m_c[38] * __x__.m_c[15]) + (-1.0f * __x__.m_c[48] * __x__.m_c[10]) + (__x__.m_c[68] * __x__.m_c[0]));
			__x__.m_c[203] = ((-1.0f * __x__.m_c[78] * __x__.m_c[0]) + (-1.0f * __x__.m_c[48] * __x__.m_c[5]) + (__x__.m_c[28] * __x__.m_c[15]));
			__x__.m_c[213] = ((-1.0f * __x__.m_c[38] * __x__.m_c[5]) + (__x__.m_c[28] * __x__.m_c[10]) + (__x__.m_c[58] * __x__.m_c[0]));
			__x__.m_c[223] = ((__x__.m_c[58] * __x__.m_c[15]) + (__x__.m_c[78] * __x__.m_c[10]) + (__x__.m_c[68] * __x__.m_c[5]));
			__x__.m_c[134] = ((__x__.m_c[70] * __x__.m_c[22]) + (__x__.m_c[110] * __x__.m_c[12]) + (-1.0f * __x__.m_c[100] * __x__.m_c[17]));
			__x__.m_c[144] = ((-1.0f * __x__.m_c[110] * __x__.m_c[7]) + (__x__.m_c[80] * __x__.m_c[22]) + (__x__.m_c[90] * __x__.m_c[17]));
			__x__.m_c[154] = ((__x__.m_c[100] * __x__.m_c[7]) + (__x__.m_c[60] * __x__.m_c[22]) + (-1.0f * __x__.m_c[90] * __x__.m_c[12]));
			__x__.m_c[164] = ((__x__.m_c[50] * __x__.m_c[22]) + (-1.0f * __x__.m_c[120] * __x__.m_c[17]) + (__x__.m_c[110] * __x__.m_c[2]));
			__x__.m_c[174] = ((-1.0f * __x__.m_c[120] * __x__.m_c[7]) + (__x__.m_c[30] * __x__.m_c[22]) + (__x__.m_c[90] * __x__.m_c[2]));
			__x__.m_c[184] = ((__x__.m_c[40] * __x__.m_c[22]) + (-1.0f * __x__.m_c[120] * __x__.m_c[12]) + (__x__.m_c[100] * __x__.m_c[2]));
			__x__.m_c[194] = ((__x__.m_c[70] * __x__.m_c[2]) + (-1.0f * __x__.m_c[50] * __x__.m_c[12]) + (__x__.m_c[40] * __x__.m_c[17]));
			__x__.m_c[204] = ((-1.0f * __x__.m_c[80] * __x__.m_c[2]) + (-1.0f * __x__.m_c[50] * __x__.m_c[7]) + (__x__.m_c[30] * __x__.m_c[17]));
			__x__.m_c[214] = ((__x__.m_c[60] * __x__.m_c[2]) + (-1.0f * __x__.m_c[40] * __x__.m_c[7]) + (__x__.m_c[30] * __x__.m_c[12]));
			__x__.m_c[224] = ((__x__.m_c[60] * __x__.m_c[17]) + (__x__.m_c[70] * __x__.m_c[7]) + (__x__.m_c[80] * __x__.m_c[12]));
			__x__.m_c[225] = ((-1.0f * __x__.m_c[144] * __x__.m_c[14]) + (__x__.m_c[224] * __x__.m_c[24]) + (-1.0f * __x__.m_c[134] * __x__.m_c[9]) + (-1.0f * __x__.m_c[154] * __x__.m_c[19]));
			__x__.m_c[230] = ((-1.0f * __x__.m_c[134] * __x__.m_c[4]) + (-1.0f * __x__.m_c[184] * __x__.m_c[19]) + (__x__.m_c[164] * __x__.m_c[14]) + (__x__.m_c[194] * __x__.m_c[24]));
			__x__.m_c[235] = ((__x__.m_c[164] * __x__.m_c[9]) + (__x__.m_c[204] * __x__.m_c[24]) + (__x__.m_c[144] * __x__.m_c[4]) + (-1.0f * __x__.m_c[174] * __x__.m_c[19]));
			__x__.m_c[240] = ((-1.0f * __x__.m_c[154] * __x__.m_c[4]) + (__x__.m_c[214] * __x__.m_c[24]) + (-1.0f * __x__.m_c[174] * __x__.m_c[14]) + (__x__.m_c[184] * __x__.m_c[9]));
			__x__.m_c[245] = ((-1.0f * __x__.m_c[224] * __x__.m_c[4]) + (__x__.m_c[214] * __x__.m_c[19]) + (__x__.m_c[194] * __x__.m_c[9]) + (-1.0f * __x__.m_c[204] * __x__.m_c[14]));
			__x__.m_c[226] = ((__x__.m_c[221] * __x__.m_c[24]) + (-1.0f * __x__.m_c[151] * __x__.m_c[19]) + (-1.0f * __x__.m_c[131] * __x__.m_c[9]) + (-1.0f * __x__.m_c[141] * __x__.m_c[14]));
			__x__.m_c[231] = ((__x__.m_c[191] * __x__.m_c[24]) + (__x__.m_c[161] * __x__.m_c[14]) + (-1.0f * __x__.m_c[181] * __x__.m_c[19]) + (-1.0f * __x__.m_c[131] * __x__.m_c[4]));
			__x__.m_c[236] = ((__x__.m_c[141] * __x__.m_c[4]) + (__x__.m_c[201] * __x__.m_c[24]) + (-1.0f * __x__.m_c[171] * __x__.m_c[19]) + (__x__.m_c[161] * __x__.m_c[9]));
			__x__.m_c[241] = ((-1.0f * __x__.m_c[171] * __x__.m_c[14]) + (__x__.m_c[211] * __x__.m_c[24]) + (__x__.m_c[181] * __x__.m_c[9]) + (-1.0f * __x__.m_c[151] * __x__.m_c[4]));
			__x__.m_c[246] = ((__x__.m_c[211] * __x__.m_c[19]) + (__x__.m_c[191] * __x__.m_c[9]) + (-1.0f * __x__.m_c[221] * __x__.m_c[4]) + (-1.0f * __x__.m_c[201] * __x__.m_c[14]));
			__x__.m_c[227] = ((-1.0f * __x__.m_c[142] * __x__.m_c[14]) + (-1.0f * __x__.m_c[132] * __x__.m_c[9]) + (__x__.m_c[222] * __x__.m_c[24]) + (-1.0f * __x__.m_c[152] * __x__.m_c[19]));
			__x__.m_c[232] = ((-1.0f * __x__.m_c[132] * __x__.m_c[4]) + (-1.0f * __x__.m_c[182] * __x__.m_c[19]) + (__x__.m_c[162] * __x__.m_c[14]) + (__x__.m_c[192] * __x__.m_c[24]));
			__x__.m_c[237] = ((__x__.m_c[142] * __x__.m_c[4]) + (__x__.m_c[202] * __x__.m_c[24]) + (-1.0f * __x__.m_c[172] * __x__.m_c[19]) + (__x__.m_c[162] * __x__.m_c[9]));
			__x__.m_c[242] = ((__x__.m_c[212] * __x__.m_c[24]) + (-1.0f * __x__.m_c[172] * __x__.m_c[14]) + (__x__.m_c[182] * __x__.m_c[9]) + (-1.0f * __x__.m_c[152] * __x__.m_c[4]));
			__x__.m_c[247] = ((__x__.m_c[192] * __x__.m_c[9]) + (-1.0f * __x__.m_c[202] * __x__.m_c[14]) + (-1.0f * __x__.m_c[222] * __x__.m_c[4]) + (__x__.m_c[212] * __x__.m_c[19]));
			__x__.m_c[228] = ((__x__.m_c[223] * __x__.m_c[24]) + (-1.0f * __x__.m_c[133] * __x__.m_c[9]) + (-1.0f * __x__.m_c[143] * __x__.m_c[14]) + (-1.0f * __x__.m_c[153] * __x__.m_c[19]));
			__x__.m_c[233] = ((__x__.m_c[193] * __x__.m_c[24]) + (-1.0f * __x__.m_c[133] * __x__.m_c[4]) + (-1.0f * __x__.m_c[183] * __x__.m_c[19]) + (__x__.m_c[163] * __x__.m_c[14]));
			__x__.m_c[238] = ((__x__.m_c[163] * __x__.m_c[9]) + (-1.0f * __x__.m_c[173] * __x__.m_c[19]) + (__x__.m_c[203] * __x__.m_c[24]) + (__x__.m_c[143] * __x__.m_c[4]));
			__x__.m_c[243] = ((-1.0f * __x__.m_c[153] * __x__.m_c[4]) + (__x__.m_c[213] * __x__.m_c[24]) + (__x__.m_c[183] * __x__.m_c[9]) + (-1.0f * __x__.m_c[173] * __x__.m_c[14]));
			__x__.m_c[248] = ((__x__.m_c[193] * __x__.m_c[9]) + (-1.0f * __x__.m_c[223] * __x__.m_c[4]) + (__x__.m_c[213] * __x__.m_c[19]) + (-1.0f * __x__.m_c[203] * __x__.m_c[14]));
			__x__.m_c[229] = ((__x__.m_c[154] * __x__.m_c[15]) + (__x__.m_c[134] * __x__.m_c[5]) + (__x__.m_c[144] * __x__.m_c[10]) + (-1.0f * __x__.m_c[224] * __x__.m_c[20]));
			__x__.m_c[234] = ((-1.0f * __x__.m_c[194] * __x__.m_c[20]) + (__x__.m_c[134] * __x__.m_c[0]) + (-1.0f * __x__.m_c[164] * __x__.m_c[10]) + (__x__.m_c[184] * __x__.m_c[15]));
			__x__.m_c[239] = ((-1.0f * __x__.m_c[164] * __x__.m_c[5]) + (__x__.m_c[174] * __x__.m_c[15]) + (-1.0f * __x__.m_c[204] * __x__.m_c[20]) + (-1.0f * __x__.m_c[144] * __x__.m_c[0]));
			__x__.m_c[244] = ((-1.0f * __x__.m_c[184] * __x__.m_c[5]) + (__x__.m_c[154] * __x__.m_c[0]) + (__x__.m_c[174] * __x__.m_c[10]) + (-1.0f * __x__.m_c[214] * __x__.m_c[20]));
			__x__.m_c[249] = ((__x__.m_c[204] * __x__.m_c[10]) + (-1.0f * __x__.m_c[214] * __x__.m_c[15]) + (-1.0f * __x__.m_c[194] * __x__.m_c[5]) + (__x__.m_c[224] * __x__.m_c[0]));
			__x__.m_c[250] = ((__x__.m_c[229] * __x__.m_c[4]) + (-1.0f * __x__.m_c[244] * __x__.m_c[19]) + (-1.0f * __x__.m_c[234] * __x__.m_c[9]) + (__x__.m_c[249] * __x__.m_c[24]) + (__x__.m_c[239] * __x__.m_c[14]));
		}
		void set(omFlatPoint& __x__, const om& __y__) {
			__x__.m_c[0] = ((-1.0f * __y__.m_c[9] * __y__.m_c[21]) + (__y__.m_c[24] * __y__.m_c[6]));
			__x__.m_c[1] = ((-1.0f * __y__.m_c[14] * __y__.m_c[21]) + (__y__.m_c[24] * __y__.m_c[11]));
			__x__.m_c[2] = ((-1.0f * __y__.m_c[19] * __y__.m_c[21]) + (__y__.m_c[24] * __y__.m_c[16]));
			__x__.m_c[3] = ((__y__.m_c[24] * __y__.m_c[1]) + (-1.0f * __y__.m_c[4] * __y__.m_c[21]));
			__x__.m_c[4] = ((-1.0f * __y__.m_c[9] * __y__.m_c[22]) + (__y__.m_c[24] * __y__.m_c[7]));
			__x__.m_c[5] = ((__y__.m_c[24] * __y__.m_c[12]) + (-1.0f * __y__.m_c[14] * __y__.m_c[22]));
			__x__.m_c[6] = ((__y__.m_c[24] * __y__.m_c[17]) + (-1.0f * __y__.m_c[19] * __y__.m_c[22]));
			__x__.m_c[7] = ((-1.0f * __y__.m_c[4] * __y__.m_c[22]) + (__y__.m_c[24] * __y__.m_c[2]));
			__x__.m_c[8] = ((__y__.m_c[24] * __y__.m_c[8]) + (-1.0f * __y__.m_c[9] * __y__.m_c[23]));
			__x__.m_c[9] = ((__y__.m_c[24] * __y__.m_c[13]) + (-1.0f * __y__.m_c[14] * __y__.m_c[23]));
			__x__.m_c[10] = ((__y__.m_c[24] * __y__.m_c[18]) + (-1.0f * __y__.m_c[19] * __y__.m_c[23]));
			__x__.m_c[11] = ((__y__.m_c[24] * __y__.m_c[3]) + (-1.0f * __y__.m_c[4] * __y__.m_c[23]));
			__x__.m_c[12] = ((__y__.m_c[24] * __y__.m_c[5]) + (-1.0f * __y__.m_c[9] * __y__.m_c[20]));
			__x__.m_c[13] = ((__y__.m_c[24] * __y__.m_c[10]) + (-1.0f * __y__.m_c[14] * __y__.m_c[20]));
			__x__.m_c[14] = ((-1.0f * __y__.m_c[19] * __y__.m_c[20]) + (__y__.m_c[24] * __y__.m_c[15]));
			__x__.m_c[15] = ((-1.0f * __y__.m_c[4] * __y__.m_c[20]) + (__y__.m_c[24] * __y__.m_c[0]));
		}
	} /* end of namespace __G2_GENERATED__ */


	// algebra / user constants:
	__e3ni_ct__ e3ni;
	__e2ni_ct__ e2ni;
	__e1_ct__ e1;
	__I5i_ct__ I5i;
	__I3_ct__ I3;
	__ni_ct__ ni;
	__e3_ct__ e3;
	__e2_ct__ e2;
	__e1ni_ct__ e1ni;
	__no_ct__ no;
	__noni_ct__ noni;
	__I5_ct__ I5;

	char *string(const mv & obj, char *str, int maxLength, const char *fp /* = NULL */) {
		int stdIdx = 0, l;
		char tmpBuf[256], tmpFloatBuf[256]; 
		int i, j, k = 0, bei, ia = 0, s = mv_size[obj.gu()], p = 0, cnt = 0;

		// set up the floating point precision
		if (fp == NULL) fp = mv_string_fp;

		// start the string
		l = sprintf(tmpBuf, "%s", mv_string_start);
		if (stdIdx + l <= maxLength) {
			strcpy(str + stdIdx, tmpBuf);
			stdIdx += l;
		}
		else mv_throw_exception("Buffer supplied to string() is too small", MV_EXCEPTION_ERROR);

		// print all coordinates
		for (i = 0; i <= 5; i++) {
			if (obj.gu() & (1 << i)) {
				for (j = 0; j < mv_gradeSize[i]; j++) {
					float coord = (float)mv_basisElementSignByIndex[ia] * obj.m_c[k];
					/* goal: print [+|-]obj.m_c[k][* basisVector1 ^ ... ^ basisVectorN] */			
					sprintf(tmpFloatBuf, fp, fabs(coord));
					if (atof(tmpFloatBuf) != 0.0) {
						l = 0;

						// print [+|-]
						l += sprintf(tmpBuf + l, "%s", (coord >= 0.0) 
							? (cnt ? mv_string_plus : "")
							: mv_string_minus);
						// print obj.m_c[k]
						l += sprintf(tmpBuf + l, tmpFloatBuf);

						if (i) { // if not grade 0, print [* basisVector1 ^ ... ^ basisVectorN]
							l += sprintf(tmpBuf + l, "%s", mv_string_mul);

							// print all basis vectors
							bei = 0;
							while (mv_basisElements[ia][bei] >= 0) {
								l += sprintf(tmpBuf + l, "%s%s", (bei) ? mv_string_wedge : "", 
									mv_basisVectorNames[mv_basisElements[ia][bei]]);
								bei++;
							}
						}

						//copy all to 'str'
						if (stdIdx + l <= maxLength) {
							strcpy(str + stdIdx, tmpBuf);
							stdIdx += l;
						}
						else mv_throw_exception("Buffer supplied to string() is too small", MV_EXCEPTION_ERROR);
						cnt++;
					}
					k++; ia++;
				}
			}
			else ia += mv_gradeSize[i];
		}

		// if no coordinates printed: 0
		l = 0;
		if (cnt == 0) {
			l += sprintf(tmpBuf + l, "0");
		}

		// end the string
		l += sprintf(tmpBuf + l, "%s", mv_string_end);
		if (stdIdx + l <= maxLength) {
			strcpy(str + stdIdx, tmpBuf);
			stdIdx += l;
		}
		else mv_throw_exception("Buffer supplied to string() is too small", MV_EXCEPTION_ERROR);

		return str;
	}

	// this function should be deprecated (conflicts with C++ stdlib)
	char *string(const mv & obj, const char *fp /* = NULL */) {
		// not multithreading safe, but not fatal either.
		static char str[2048];
		return string(obj, str, 2047, fp);
	}

	char *c_str(const mv & obj, const char *fp /* = NULL */) {
		return string(obj, fp);
	}

	std::string toString(const mv & obj, const char *fp /* = NULL */) {
		std::string str;
		const int SIZE = 2048;
		str.resize(SIZE);
		string(obj, &(str[0]), SIZE-1, fp);
		str.resize(strlen(&(str[0])));
		return str;
	}






	/** This function is not for external use. It compressed arrays of floats for storage in multivectors. */
	void compress(const float *c, float *cc, int &cgu, float epsilon /*= 0.0*/, int gu /*= ...*/) {
		int i, j, ia = 0, ib = 0, f, s;
		cgu = 0;

		// for all grade parts...
		for (i = 0; i <= 5; i++) {
			// check if grade part has memory use:
			if (!(gu & (1 << i))) continue;

			// check if abs coordinates of grade part are all < epsilon
			s = mv_gradeSize[i];
			j = ia + s;
			f = 0;
			for (; ia < j; ia++)
			if (mv_absLessThan(c[ia], epsilon)) {f = 1; break;}
			ia = j;
			if (f) {
				mv_memcpy(cc + ib, c + ia - s, s);
				ib += s;
				cgu |= (1 << i);
			}
		}	
	}

	mv mv_compress(const float *c, float epsilon/*= 0.0*/, int gu /*= ...*/) {
		float cc[32];
		int cgu;
		compress(c, cc, cgu, epsilon, gu);
		return mv(cgu, cc);
	}

	mv compress(const mv & arg1, float epsilon /*= 0.0*/) {
		return mv_compress(arg1.m_c, epsilon, arg1.m_gu);
	}

	void mv::compress(float epsilon /*= 0.0*/) {
		float cc[32];
		int cgu;
		c3ga::compress(m_c, cc, cgu, epsilon, m_gu);
		set(cgu, cc);
	}

	mv mv_compress(int nbBlades, const unsigned int *bitmaps, const mv::Float *coords) {	
		// convert basis blade compression to regular coordinate array:
		mv::Float A[32];
		mv_zero(A, 32);

		//	int gu = 0;
		for (int i = 0; i < nbBlades; i++) {
			A[mv_basisElementIndexByBitmap[bitmaps[i]]] = coords[i] * (mv::Float)mv_basisElementSignByBitmap[bitmaps[i]];		
			//	gu |= (1 << mv_basisElementGradeByBitmap[bitmaps[i]]);
		}

		return mv_compress(A); //, (mv::Float)0.0, gu);
	}

	/** This function is not for external use. It decompresses the coordinates stored in this */
	void mv::expand(const Float *ptrs[], bool nulls /* = true */) const {
		const Float *c(m_c);
		const Float *null = (nulls) ? NULL : nullFloats();

		if (m_gu & 1) {
			ptrs[0] =  c;
			c += 1;
		}
		else ptrs[0] = null;	
		if (m_gu & 2) {
			ptrs[1] =  c;
			c += 5;
		}
		else ptrs[1] = null;	
		if (m_gu & 4) {
			ptrs[2] =  c;
			c += 10;
		}
		else ptrs[2] = null;	
		if (m_gu & 8) {
			ptrs[3] =  c;
			c += 10;
		}
		else ptrs[3] = null;	
		if (m_gu & 16) {
			ptrs[4] =  c;
			c += 5;
		}
		else ptrs[4] = null;	
		if (m_gu & 32) {
			ptrs[5] =  c;
			c += 1;
		}
		else ptrs[5] = null;	
	}


	void mvType::init(const mv &X, mv::Float epsilon) {
		m_type = MULTIVECTOR;

		// first of all determine grade usage & parity
		mv cX = X;
		cX.compress(epsilon);
		m_gradeUsage = (int)cX.gu();
		int cnt[2] = {0,0}; // nb even, odd grade parts in use
		{
			// count grade part usage:
			int cntIdx = 0;
			int gu = m_gradeUsage;
			while (gu != 0) {
				if ((gu & 1) != 0)
					cnt[cntIdx & 1]++;
				gu >>= 1;
				m_grade = cntIdx;
				cntIdx++;
			}

			// if no grade part in use: zero blade
			if ((cnt[0] == 0) && (cnt[1] == 0)) {
				// multivector = zero blade, case closed
				m_zero = true;
				m_type = BLADE;
				m_parity = 0;
				m_grade = 0; // forced to grade 0, but actually, does not really have a grade
				return;
			}
			else {
				m_zero = false;
				// if both even and odd grade parts in use: multivector
				if ((cnt[0] != 0) && (cnt[1] != 0)) {
					// X = multivector, case closed
					m_parity = -1;
					return;
				}
				else // more work to do, but parity is known:
				// either a blade, or a versor, TBD below
				m_parity = (cnt[1] != 0) ? 1 : 0;
			}
		}

		// first test for versor:
		bool useAlgebraMetric = true;
		init(X, epsilon, useAlgebraMetric, cnt[0] + cnt[1]);

		// Only if metric is not Euclidean:
		// If it was not a versor, or blade using the algebra metric, then try again,
		// at least, if only one grade part is in use:
		if ((m_type == MULTIVECTOR) && ((cnt[0] + cnt[1]) == 1)) {
			useAlgebraMetric = false;
			init(X, epsilon, useAlgebraMetric, cnt[0] + cnt[1]);
		}
	}


	void mvType::init(const mv &X, mv::Float epsilon, bool useAlgebraMetric, int guCnt) {
		mv rX = reverse(X);

		// test if null:
		mv Sq = (useAlgebraMetric) ? scp(X, rX) : scpEM(X, rX);
		Sq.compress(epsilon);
		if (_Float(Sq) == 0) {
			// X = multivector, case closed
			m_type = MULTIVECTOR;
			return;
		}

		// versor inverse must be true inverse:
		mv Xvi = (useAlgebraMetric) ? inverse(X) : inverseEM(X);
		mv Xgi = gradeInvolution(X);

		// check if (Xgi Xvi) is a scalar:
		mv XgiXvi = (useAlgebraMetric) ? gp(Xgi, Xvi) : gpEM(Xgi, Xvi);
		{
			mv tmp = XgiXvi;
			tmp.compress(epsilon);
			if (tmp.gu() != GRADE_0) { // if not scalar:
				// X = multivector, case closed
				m_type = MULTIVECTOR;
				return;
			}
		}

		// check if Xgi Xvi == Xvi Xgi
		mv XviXgi = (useAlgebraMetric) ? gp(Xvi, Xgi) : gpEM(Xvi, Xgi);
		{
			mv tmp = XviXgi - XgiXvi;
			tmp.compress(epsilon); // this should result in 0
			if (tmp.gu()) {
				// if not:
				// X = multivector, case closed
				m_type = MULTIVECTOR;
				return;
			}
		}

		// check if grade preserving for all basis vectors:
		{
			{
				// test no		
				mv tmp = (useAlgebraMetric) ? gp(gp(Xvi, no), Xgi) : gpEM(gpEM(Xvi, no), Xgi);
				tmp.compress(epsilon);
				if (tmp.gu() != GRADE_1) { // X = multivector, case closed
					m_type = MULTIVECTOR;
					return;
				}
			}
			{
				// test e1		
				mv tmp = (useAlgebraMetric) ? gp(gp(Xvi, e1), Xgi) : gpEM(gpEM(Xvi, e1), Xgi);
				tmp.compress(epsilon);
				if (tmp.gu() != GRADE_1) { // X = multivector, case closed
					m_type = MULTIVECTOR;
					return;
				}
			}
			{
				// test e2		
				mv tmp = (useAlgebraMetric) ? gp(gp(Xvi, e2), Xgi) : gpEM(gpEM(Xvi, e2), Xgi);
				tmp.compress(epsilon);
				if (tmp.gu() != GRADE_1) { // X = multivector, case closed
					m_type = MULTIVECTOR;
					return;
				}
			}
			{
				// test e3		
				mv tmp = (useAlgebraMetric) ? gp(gp(Xvi, e3), Xgi) : gpEM(gpEM(Xvi, e3), Xgi);
				tmp.compress(epsilon);
				if (tmp.gu() != GRADE_1) { // X = multivector, case closed
					m_type = MULTIVECTOR;
					return;
				}
			}
			{
				// test ni		
				mv tmp = (useAlgebraMetric) ? gp(gp(Xvi, ni), Xgi) : gpEM(gpEM(Xvi, ni), Xgi);
				tmp.compress(epsilon);
				if (tmp.gu() != GRADE_1) { // X = multivector, case closed
					m_type = MULTIVECTOR;
					return;
				}
			}
		}

		// if homogeneous: blade
		if (guCnt == 1) m_type = BLADE;
		else m_type = VERSOR;
	}



	std::string mvType::toString() const {
		char buf[1024];
		sprintf(buf, "%s, grade: %d, gradeUsage: %X, parity: %s",
			(m_type == MULTIVECTOR) ? "multivector" : ((m_type == BLADE) ? "blade" : "versor"),
			m_grade, m_gradeUsage,
			(m_parity < 0) ? "none" : ((m_parity == 0) ? "even" : "odd"));
		return buf;
	}










} // end of namespace c3ga
// post_cpp_include

