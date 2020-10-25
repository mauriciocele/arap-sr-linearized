
// Generated on 2007-08-08 10:15:48 by G2 0.1 from 'E:\gasandbox\ga_sandbox\libgasandbox\c2ga.gs2'

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
#include "c2ga.h"

	// pre_cpp_include


	namespace c2ga {

	// The dimension of the space:
	const int mv_spaceDim = 4;

	// Is the metric of the space Euclidean?
	const bool mv_metricEuclidean = false;


	// This array can be used to lookup the number of coordinates for a grade part of a general multivector
	const int mv_gradeSize[5] = {
		1, 4, 6, 4, 1 
	};

	// This array can be used to lookup the number of coordinates based on a grade usage bitmap
	const int mv_size[32] = {
		0, 1, 4, 5, 6, 7, 10, 11, 4, 5, 8, 9, 10, 11, 14, 15, 1, 2, 5, 6, 7, 8, 11, 12, 5, 6, 9, 10, 11, 12, 15, 16 
	};

	// This array of ASCIIZ strings contains the names of the basis vectors
	const char *mv_basisVectorNames[4] = {
		"no", "e1", "e2", "ni" 
	};

	// This array of integers contains the order of basis elements in the general multivector
	const int mv_basisElements[16][5] = {
		{-1}
		, {0, -1}
		, {1, -1}
		, {2, -1}
		, {3, -1}
		, {0, 1, -1}
		, {0, 2, -1}
		, {1, 2, -1}
		, {1, 3, -1}
		, {2, 3, -1}
		, {0, 3, -1}
		, {1, 2, 3, -1}
		, {0, 1, 3, -1}
		, {0, 2, 3, -1}
		, {0, 1, 2, -1}
		, {0, 1, 2, 3, -1}
	};

	// This array of integers contains the 'sign' (even/odd permutation of the canonical order) of basis elements in the general multivector
	// Use it to answer 'what is the permutation of the coordinate at index [x]'?
	const double mv_basisElementSignByIndex[16] = {
		1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 
	};


	// This array of integers contains the 'sign' (even/odd permutation of canonical order) of basis elements in the general multivector
	// Use it to answer 'what is the permutation of the coordinate of bitmap [x]'?
	const double mv_basisElementSignByBitmap[16] = {
		1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 
	};


	// This array of integers contains the order of basis elements in the general multivector
	// Use it to answer: 'at what index do I find basis element [x] (x = basis vector bitmap)?
	const int mv_basisElementIndexByBitmap[16] = {
		0, 1, 2, 5, 3, 6, 7, 14, 4, 10, 8, 12, 9, 13, 11, 15 
	};

	// This array of integers contains the indices of basis elements in the general multivector
	// Use it to answer: 'what basis element do I find at index [x]'?
	const int mv_basisElementBitmapByIndex[16] = {
		0, 1, 2, 4, 8, 3, 5, 6, 10, 12, 9, 14, 11, 13, 7, 15 
	};


	// This array of grade of each basis elements in the general multivector
	// Use it to answer: 'what is the grade of basis element bitmap [x]'?
	extern const int mv_basisElementGradeByBitmap[16] = {
		0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4 
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
		void save(const char *filename /*= "E:\\gasandbox\\ga_sandbox\\libgasandbox\\c2ga.gp2"*/, bool append /*= false*/) {
		}
		void init(const char *filename /*= "E:\\gasandbox\\ga_sandbox\\libgasandbox\\c2ga.gp2"*/,
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



	// set to no_t 
	void mv::set(const no_t & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;


	}
	// set to e1_t 
	void mv::set(const e1_t & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)0;
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;


	}
	// set to e2_t 
	void mv::set(const e2_t & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = arg1.m_c[0] ;
		m_c[3] = (Float)0;


	}
	// set to ni_t 
	void mv::set(const ni_t & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[0] ;


	}
	// set to scalar 
	void mv::set(const scalar & arg1) {

		// set grade usage 
		gu(1);


		m_c[0] = arg1.m_c[0] ;


	}
	// set to point 
	void mv::set(const point & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[3] ;


	}
	// set to normalizedPoint 
	void mv::set(const normalizedPoint & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)1.0f; 
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = arg1.m_c[2] ;


	}
	// set to flatPoint 
	void mv::set(const flatPoint & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[0] ;
		m_c[4] = arg1.m_c[1] ;
		m_c[5] = arg1.m_c[2] ;


	}
	// set to normalizedFlatPoint 
	void mv::set(const normalizedFlatPoint & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[0] ;
		m_c[4] = arg1.m_c[1] ;
		m_c[5] = (Float)1.0f; 


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


	}
	// set to TRversorLog 
	void mv::set(const TRversorLog & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = arg1.m_c[0] ;
		m_c[3] = arg1.m_c[1] ;
		m_c[4] = arg1.m_c[2] ;
		m_c[5] = (Float)0;


	}
	// set to line 
	void mv::set(const line & arg1) {

		// set grade usage 
		gu(8);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] * (Float)-1.0;
		m_c[2] = arg1.m_c[2] * (Float)-1.0;
		m_c[3] = (Float)0;


	}
	// set to dualLine 
	void mv::set(const dualLine & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = arg1.m_c[0] ;
		m_c[3] = arg1.m_c[1] ;
		m_c[4] = arg1.m_c[2] ;
		m_c[5] = (Float)0;


	}
	// set to circle 
	void mv::set(const circle & arg1) {

		// set grade usage 
		gu(8);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[3] ;


	}
	// set to freeVector 
	void mv::set(const freeVector & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[0] ;
		m_c[4] = arg1.m_c[1] ;
		m_c[5] = (Float)0;


	}
	// set to freeBivector 
	void mv::set(const freeBivector & arg1) {

		// set grade usage 
		gu(8);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;


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


	}
	// set to tangentBivector 
	void mv::set(const tangentBivector & arg1) {

		// set grade usage 
		gu(8);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[3] ;


	}
	// set to vectorE2GA 
	void mv::set(const vectorE2GA & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)0;
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = (Float)0;


	}
	// set to bivectorE2GA 
	void mv::set(const bivectorE2GA & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = arg1.m_c[0] ;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;


	}
	// set to TRversor 
	void mv::set(const TRversor & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[1] ;
		m_c[4] = arg1.m_c[2] ;
		m_c[5] = arg1.m_c[3] ;
		m_c[6] = (Float)0;


	}
	// set to TRSversor 
	void mv::set(const TRSversor & arg1) {

		// set grade usage 
		gu(21);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[1] ;
		m_c[4] = arg1.m_c[2] ;
		m_c[5] = arg1.m_c[3] ;
		m_c[6] = arg1.m_c[4] ;
		m_c[7] = arg1.m_c[5] ;


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


	}
	// set to translator 
	void mv::set(const translator & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = arg1.m_c[1] ;
		m_c[5] = arg1.m_c[2] ;
		m_c[6] = (Float)0;


	}
	// set to normalizedTranslator 
	void mv::set(const normalizedTranslator & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = (Float)1.0f; 
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = arg1.m_c[0] ;
		m_c[5] = arg1.m_c[1] ;
		m_c[6] = (Float)0;


	}
	// set to rotor 
	void mv::set(const rotor & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[1] ;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;


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
		m_c[6] = arg1.m_c[1] ;


	}
	// set to __no_ct__ 
	void mv::set(const __no_ct__ & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)1.0f; 
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;


	}
	// set to __e1_ct__ 
	void mv::set(const __e1_ct__ & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)0;
		m_c[1] = (Float)1.0f; 
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;


	}
	// set to __e2_ct__ 
	void mv::set(const __e2_ct__ & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)1.0f; 
		m_c[3] = (Float)0;


	}
	// set to __ni_ct__ 
	void mv::set(const __ni_ct__ & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)1.0f; 


	}
	// set to __I4i_ct__ 
	void mv::set(const __I4i_ct__ & arg1) {

		// set grade usage 
		gu(16);


		m_c[0] = (Float)-1.0f; 


	}
	// set to __I4_ct__ 
	void mv::set(const __I4_ct__ & arg1) {

		// set grade usage 
		gu(16);


		m_c[0] = (Float)1.0f; 


	}
	// set to __I2_ct__ 
	void mv::set(const __I2_ct__ & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)1.0f; 
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;


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
		m_c[5] = (Float)1.0f; 


	}
	// set to __e2ni_ct__ 
	void mv::set(const __e2ni_ct__ & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)1.0f; 
		m_c[5] = (Float)0;


	}
	// set to __e1ni_ct__ 
	void mv::set(const __e1ni_ct__ & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)1.0f; 
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;


	}
	// set to __syn_smv___e1_e2_nof1_0 
	void mv::set(const __syn_smv___e1_e2_nof1_0 & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)1.0f; 
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = (Float)0;


	}
	// set to __syn_smv___e1e2nif1_0 
	void mv::set(const __syn_smv___e1e2nif1_0 & arg1) {

		// set grade usage 
		gu(8);


		m_c[0] = (Float)1.0f; 
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;


	}
	// set to __syn_smv___e1_e2_ni_nof_1_0 
	void mv::set(const __syn_smv___e1_e2_ni_nof_1_0 & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)-1.0f; 
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = arg1.m_c[2] ;


	}
	// set to __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni 
	void mv::set(const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[3] ;
		m_c[4] = arg1.m_c[5] ;
		m_c[5] = arg1.m_c[6] ;
		m_c[6] = arg1.m_c[4] ;


	}
	// set to __syn_smv___scalar_noe1_noe2_noni 
	void mv::set(const __syn_smv___scalar_noe1_noe2_noni & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = (Float)0;
		m_c[6] = arg1.m_c[3] ;


	}
	// set to __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni 
	void mv::set(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[4] ;
		m_c[4] = (Float)0;
		m_c[5] = arg1.m_c[5] ;
		m_c[6] = arg1.m_c[6] ;
		m_c[7] = arg1.m_c[3] ;


	}
	// set to __syn_smv___scalar_noe1_e1e2_e1ni 
	void mv::set(const __syn_smv___scalar_noe1_e1e2_e1ni & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[2] ;
		m_c[4] = arg1.m_c[3] ;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;


	}
	// set to __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni 
	void mv::set(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[4] ;
		m_c[4] = arg1.m_c[6] ;
		m_c[5] = arg1.m_c[5] ;
		m_c[6] = (Float)0;
		m_c[7] = arg1.m_c[3] ;


	}
	// set to __syn_smv___scalar_noe2_e1e2_e2ni 
	void mv::set(const __syn_smv___scalar_noe2_e1e2_e2ni & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = arg1.m_c[2] ;
		m_c[4] = (Float)0;
		m_c[5] = arg1.m_c[3] ;
		m_c[6] = (Float)0;


	}
	// set to __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni 
	void mv::set(const __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[4] ;
		m_c[4] = arg1.m_c[6] ;
		m_c[5] = (Float)0;
		m_c[6] = arg1.m_c[5] ;
		m_c[7] = arg1.m_c[3] ;


	}
	// set to __syn_smv___scalar_noni_e1ni_e2ni 
	void mv::set(const __syn_smv___scalar_noni_e1ni_e2ni & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = arg1.m_c[2] ;
		m_c[5] = arg1.m_c[3] ;
		m_c[6] = arg1.m_c[1] ;


	}
	// set to __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni 
	void mv::set(const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[3] ;
		m_c[4] = arg1.m_c[6] ;
		m_c[5] = arg1.m_c[4] ;
		m_c[6] = arg1.m_c[5] ;
		m_c[7] = (Float)0;


	}
	// set to __syn_smv___e1ni_e2ni_nonif_1_0 
	void mv::set(const __syn_smv___e1ni_e2ni_nonif_1_0 & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[0] ;
		m_c[4] = arg1.m_c[1] ;
		m_c[5] = (Float)-1.0f; 


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
		m_c[3] = (Float)-1.0f; 


	}
	// set to __syn_smv___nif1_0 
	void mv::set(const __syn_smv___nif1_0 & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)1.0f; 


	}
	// set to __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 
	void mv::set(const __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = (Float)1.0f; 
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = arg1.m_c[2] ;
		m_c[4] = arg1.m_c[5] ;
		m_c[5] = arg1.m_c[3] ;
		m_c[6] = arg1.m_c[4] ;
		m_c[7] = (Float)0;


	}
	// set to __syn_smv___e1_e2_ni_nof2_0 
	void mv::set(const __syn_smv___e1_e2_ni_nof2_0 & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)2.0f; 
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = arg1.m_c[2] ;


	}
	// set to __syn_smv___e1_e2_ni 
	void mv::set(const __syn_smv___e1_e2_ni & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)0;
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = arg1.m_c[2] ;


	}
	// set to __syn_smv___noe1_noe2_noni 
	void mv::set(const __syn_smv___noe1_noe2_noni & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = arg1.m_c[2] ;


	}
	// set to __syn_smv___no_noe1e2_noe1ni_noe2ni 
	void mv::set(const __syn_smv___no_noe1e2_noe1ni_noe2ni & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;
		m_c[4] = (Float)0;
		m_c[5] = arg1.m_c[2] ;
		m_c[6] = arg1.m_c[3] ;
		m_c[7] = arg1.m_c[1] ;


	}
	// set to __syn_smv___scalar_e1e2_e1ni 
	void mv::set(const __syn_smv___scalar_e1e2_e1ni & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[1] ;
		m_c[4] = arg1.m_c[2] ;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;


	}
	// set to __syn_smv___e1_e2_ni_e1e2ni 
	void mv::set(const __syn_smv___e1_e2_ni_e1e2ni & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = (Float)0;
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = arg1.m_c[2] ;
		m_c[4] = arg1.m_c[3] ;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;


	}
	// set to __syn_smv___scalar_e1e2_e2ni 
	void mv::set(const __syn_smv___scalar_e1e2_e2ni & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[1] ;
		m_c[4] = (Float)0;
		m_c[5] = arg1.m_c[2] ;
		m_c[6] = (Float)0;


	}
	// set to __syn_smv___scalarf0_0 
	void mv::set(const __syn_smv___scalarf0_0 & arg1) {

		// set grade usage 
		gu(1);


		m_c[0] = (Float)0.0f; 


	}
	// set to __syn_smv___ni_e1e2ni 
	void mv::set(const __syn_smv___ni_e1e2ni & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[0] ;
		m_c[4] = arg1.m_c[1] ;
		m_c[5] = (Float)0;
		m_c[6] = (Float)0;
		m_c[7] = (Float)0;


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
	// assign TRversorLog 
	mv& mv::operator=(const TRversorLog& arg1) {
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
	// assign circle 
	mv& mv::operator=(const circle& arg1) {
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
	// assign bivectorE2GA 
	mv& mv::operator=(const bivectorE2GA& arg1) {
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
	// assign __ni_ct__ 
	mv& mv::operator=(const __ni_ct__& arg1) {
		set(arg1);
		return *this;
	}
	// assign __I4i_ct__ 
	mv& mv::operator=(const __I4i_ct__& arg1) {
		set(arg1);
		return *this;
	}
	// assign __I4_ct__ 
	mv& mv::operator=(const __I4_ct__& arg1) {
		set(arg1);
		return *this;
	}
	// assign __I2_ct__ 
	mv& mv::operator=(const __I2_ct__& arg1) {
		set(arg1);
		return *this;
	}
	// assign __noni_ct__ 
	mv& mv::operator=(const __noni_ct__& arg1) {
		set(arg1);
		return *this;
	}
	// assign __e2ni_ct__ 
	mv& mv::operator=(const __e2ni_ct__& arg1) {
		set(arg1);
		return *this;
	}
	// assign __e1ni_ct__ 
	mv& mv::operator=(const __e1ni_ct__& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1_e2_nof1_0 
	mv& mv::operator=(const __syn_smv___e1_e2_nof1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1e2nif1_0 
	mv& mv::operator=(const __syn_smv___e1e2nif1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1_e2_ni_nof_1_0 
	mv& mv::operator=(const __syn_smv___e1_e2_ni_nof_1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni 
	mv& mv::operator=(const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_noe1_noe2_noni 
	mv& mv::operator=(const __syn_smv___scalar_noe1_noe2_noni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni 
	mv& mv::operator=(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_noe1_e1e2_e1ni 
	mv& mv::operator=(const __syn_smv___scalar_noe1_e1e2_e1ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni 
	mv& mv::operator=(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_noe2_e1e2_e2ni 
	mv& mv::operator=(const __syn_smv___scalar_noe2_e1e2_e2ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni 
	mv& mv::operator=(const __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_noni_e1ni_e2ni 
	mv& mv::operator=(const __syn_smv___scalar_noni_e1ni_e2ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni 
	mv& mv::operator=(const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1ni_e2ni_nonif_1_0 
	mv& mv::operator=(const __syn_smv___e1ni_e2ni_nonif_1_0& arg1) {
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
	// assign __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 
	mv& mv::operator=(const __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1_e2_ni_nof2_0 
	mv& mv::operator=(const __syn_smv___e1_e2_ni_nof2_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1_e2_ni 
	mv& mv::operator=(const __syn_smv___e1_e2_ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___noe1_noe2_noni 
	mv& mv::operator=(const __syn_smv___noe1_noe2_noni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___no_noe1e2_noe1ni_noe2ni 
	mv& mv::operator=(const __syn_smv___no_noe1e2_noe1ni_noe2ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_e1e2_e1ni 
	mv& mv::operator=(const __syn_smv___scalar_e1e2_e1ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1_e2_ni_e1e2ni 
	mv& mv::operator=(const __syn_smv___e1_e2_ni_e1e2ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_e1e2_e2ni 
	mv& mv::operator=(const __syn_smv___scalar_e1e2_e2ni& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalarf0_0 
	mv& mv::operator=(const __syn_smv___scalarf0_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___ni_e1e2ni 
	mv& mv::operator=(const __syn_smv___ni_e1e2ni& arg1) {
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
	void ni_t::set(const mv & arg1) {

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




	float ni_t::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];

		return maxC;
	}

	float ni_t::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		bm = 8;

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
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
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
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
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
			gidx += 4;		}
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




	float flatPoint::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float flatPoint::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 10;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 12;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 9;
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
			gidx += 4;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 3];
			m_c[1] = arg1.m_c[gidx + 4];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
		}


	}




	float normalizedFlatPoint::largestCoordinate() const {

		Float maxC = (Float)1.0f, C;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) maxC = C;
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float normalizedFlatPoint::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f, C;
		bm = 9;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 12;
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
			gidx += 4;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 2];
			m_c[3] = arg1.m_c[gidx + 3];
			m_c[4] = arg1.m_c[gidx + 4];
			m_c[5] = arg1.m_c[gidx + 5];
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
			bm = 12;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 9;
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
			gidx += 4;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 2];
			m_c[1] = arg1.m_c[gidx + 3];
			m_c[2] = arg1.m_c[gidx + 4];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}


	}




	float TRversorLog::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float TRversorLog::largestBasisBlade(unsigned int &bm) const {

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
			gidx += 4;		}
		else {
		}

		if (arg1.gu() & 4) {
			gidx += 6;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1]* (Float)-1.0;
			m_c[2] = arg1.m_c[gidx + 2]* (Float)-1.0;
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}


	}




	float line::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float line::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 14;

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
			gidx += 4;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 2];
			m_c[1] = arg1.m_c[gidx + 3];
			m_c[2] = arg1.m_c[gidx + 4];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}


	}




	float dualLine::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
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
			gidx += 4;		}
		else {
		}

		if (arg1.gu() & 4) {
			gidx += 6;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 2];
			m_c[3] = arg1.m_c[gidx + 3];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
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
		return maxC;
	}

	float circle::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 14;

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
			bm = 7;
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
			gidx += 4;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 3];
			m_c[1] = arg1.m_c[gidx + 4];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
		}


	}




	float freeVector::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float freeVector::largestBasisBlade(unsigned int &bm) const {

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
	void freeBivector::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 4;		}
		else {
		}

		if (arg1.gu() & 4) {
			gidx += 6;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[0] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[0] = (Float)0.0;
		}


	}




	float freeBivector::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];

		return maxC;
	}

	float freeBivector::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		bm = 14;

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
			gidx += 4;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 2];
			m_c[3] = arg1.m_c[gidx + 3];
			m_c[4] = arg1.m_c[gidx + 4];
			m_c[5] = arg1.m_c[gidx + 5];
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
			bm = 12;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 9;
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
			gidx += 4;		}
		else {
		}

		if (arg1.gu() & 4) {
			gidx += 6;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 2];
			m_c[3] = arg1.m_c[gidx + 3];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
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
		return maxC;
	}

	float tangentBivector::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 14;

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
	void bivectorE2GA::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 4;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 2];
		}
		else {
			m_c[0] = (Float)0.0;
		}


	}




	float bivectorE2GA::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];

		return maxC;
	}

	float bivectorE2GA::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		bm = 6;

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
			gidx += 4;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[2] = arg1.m_c[gidx + 3];
			m_c[3] = arg1.m_c[gidx + 4];
		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
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
			gidx += 4;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[2] = arg1.m_c[gidx + 3];
			m_c[3] = arg1.m_c[gidx + 4];
			m_c[4] = arg1.m_c[gidx + 5];
			gidx += 6;		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 4;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[5] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[5] = (Float)0.0;
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
			bm = 9;
		}
		C = (m_c[5] < (Float)0.0) ? -m_c[5] : m_c[5];
		if (C > maxC) {
			maxC = C;
			bm = 15;
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
			gidx += 4;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 0];
			m_c[2] = arg1.m_c[gidx + 1];
			m_c[3] = arg1.m_c[gidx + 2];
			m_c[4] = arg1.m_c[gidx + 3];
			m_c[5] = arg1.m_c[gidx + 4];
			m_c[6] = arg1.m_c[gidx + 5];
			gidx += 6;		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			gidx += 4;		}
		else {
		}

		if (arg1.gu() & 16) {
			m_c[7] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[7] = (Float)0.0;
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
			bm = 6;
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
			bm = 9;
		}
		C = (m_c[7] < (Float)0.0) ? -m_c[7] : m_c[7];
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
			gidx += 4;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 3];
			m_c[2] = arg1.m_c[gidx + 4];
		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}


	}




	float translator::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float translator::largestBasisBlade(unsigned int &bm) const {

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
	void normalizedTranslator::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 4;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 3];
			m_c[1] = arg1.m_c[gidx + 4];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
		}


	}




	float normalizedTranslator::largestCoordinate() const {

		Float maxC = (Float)1.0f, C;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) maxC = C;
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float normalizedTranslator::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f, C;
		bm = 0;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 12;
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
			gidx += 4;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 2];
		}
		else {
			m_c[1] = (Float)0.0;
		}


	}




	float rotor::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
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
			gidx += 4;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 5];
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
			bm = 9;
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
	void __ni_ct__::set(const mv & arg1) {



	}




	float __ni_ct__::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __ni_ct__::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 8;

		return maxC;
	}




	// set to mv 
	void __I4i_ct__::set(const mv & arg1) {



	}




	float __I4i_ct__::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __I4i_ct__::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 15;

		return maxC;
	}




	// set to mv 
	void __I4_ct__::set(const mv & arg1) {



	}




	float __I4_ct__::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __I4_ct__::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 15;

		return maxC;
	}




	// set to mv 
	void __I2_ct__::set(const mv & arg1) {



	}




	float __I2_ct__::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __I2_ct__::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 6;

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
		bm = 9;

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
		bm = 12;

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
		bm = 10;

		return maxC;
	}




	// set to mv 
	void __syn_smv___e1_e2_nof1_0::set(const mv & arg1) {

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




	float __syn_smv___e1_e2_nof1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f, C;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) maxC = C;
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1_e2_nof1_0::largestBasisBlade(unsigned int &bm) const {

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
		bm = 14;

		return maxC;
	}




	// set to mv 
	void __syn_smv___e1_e2_ni_nof_1_0::set(const mv & arg1) {

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




	float __syn_smv___e1_e2_ni_nof_1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f, C;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) maxC = C;
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1_e2_ni_nof_1_0::largestBasisBlade(unsigned int &bm) const {

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
	void __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 4;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 0];
			m_c[2] = arg1.m_c[gidx + 1];
			m_c[3] = arg1.m_c[gidx + 2];
			m_c[4] = arg1.m_c[gidx + 5];
			m_c[5] = arg1.m_c[gidx + 3];
			m_c[6] = arg1.m_c[gidx + 4];
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




	float __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni::largestCoordinate() const {

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

	float __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni::largestBasisBlade(unsigned int &bm) const {

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
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalar_noe1_noe2_noni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 4;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 0];
			m_c[2] = arg1.m_c[gidx + 1];
			m_c[3] = arg1.m_c[gidx + 5];
		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_noe1_noe2_noni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___scalar_noe1_noe2_noni::largestBasisBlade(unsigned int &bm) const {

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
		return maxC;
	}




	// set to mv 
	void __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni::set(const mv & arg1) {

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
			gidx += 4;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[4] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 6;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[3] = arg1.m_c[gidx + 3];
			m_c[5] = arg1.m_c[gidx + 1];
			m_c[6] = arg1.m_c[gidx + 2];
		}
		else {
			m_c[3] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
		}


	}




	float __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni::largestCoordinate() const {

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

	float __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni::largestBasisBlade(unsigned int &bm) const {

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
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalar_noe1_e1e2_e1ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 4;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 0];
			m_c[2] = arg1.m_c[gidx + 2];
			m_c[3] = arg1.m_c[gidx + 3];
		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_noe1_e1e2_e1ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___scalar_noe1_e1e2_e1ni::largestBasisBlade(unsigned int &bm) const {

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
		return maxC;
	}




	// set to mv 
	void __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni::set(const mv & arg1) {

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
			gidx += 4;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[4] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 6;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[3] = arg1.m_c[gidx + 3];
			m_c[5] = arg1.m_c[gidx + 1];
			m_c[6] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[3] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
		}


	}




	float __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni::largestCoordinate() const {

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

	float __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni::largestBasisBlade(unsigned int &bm) const {

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
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalar_noe2_e1e2_e2ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 4;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 2];
			m_c[3] = arg1.m_c[gidx + 4];
		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_noe2_e1e2_e2ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___scalar_noe2_e1e2_e2ni::largestBasisBlade(unsigned int &bm) const {

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
		return maxC;
	}




	// set to mv 
	void __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni::set(const mv & arg1) {

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
			gidx += 4;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[4] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 6;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[3] = arg1.m_c[gidx + 3];
			m_c[5] = arg1.m_c[gidx + 2];
			m_c[6] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[3] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
		}


	}




	float __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni::largestCoordinate() const {

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

	float __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni::largestBasisBlade(unsigned int &bm) const {

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
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalar_noni_e1ni_e2ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 4;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 5];
			m_c[2] = arg1.m_c[gidx + 3];
			m_c[3] = arg1.m_c[gidx + 4];
		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_noni_e1ni_e2ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___scalar_noni_e1ni_e2ni::largestBasisBlade(unsigned int &bm) const {

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
		return maxC;
	}




	// set to mv 
	void __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni::set(const mv & arg1) {

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
			gidx += 4;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 6;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[4] = arg1.m_c[gidx + 1];
			m_c[5] = arg1.m_c[gidx + 2];
			m_c[6] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
			m_c[6] = (Float)0.0;
		}


	}




	float __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni::largestCoordinate() const {

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

	float __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni::largestBasisBlade(unsigned int &bm) const {

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
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1ni_e2ni_nonif_1_0::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 4;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 3];
			m_c[1] = arg1.m_c[gidx + 4];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
		}


	}




	float __syn_smv___e1ni_e2ni_nonif_1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f, C;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) maxC = C;
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1ni_e2ni_nonif_1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f, C;
		bm = 9;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) {
			maxC = C;
			bm = 10;
		}
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 12;
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
		bm = 8;

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
		bm = 8;

		return maxC;
	}




	// set to mv 
	void __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 1];
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[2] = arg1.m_c[gidx + 3];
			gidx += 4;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 6;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[3] = arg1.m_c[gidx + 1];
			m_c[4] = arg1.m_c[gidx + 2];
			m_c[5] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[3] = (Float)0.0;
			m_c[4] = (Float)0.0;
			m_c[5] = (Float)0.0;
		}


	}




	float __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0::largestCoordinate() const {

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
		return maxC;
	}

	float __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0::largestBasisBlade(unsigned int &bm) const {

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
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1_e2_ni_nof2_0::set(const mv & arg1) {

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




	float __syn_smv___e1_e2_ni_nof2_0::largestCoordinate() const {

		Float maxC = (Float)2.0f, C;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) maxC = C;
		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1_e2_ni_nof2_0::largestBasisBlade(unsigned int &bm) const {

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
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1_e2_ni::set(const mv & arg1) {

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




	float __syn_smv___e1_e2_ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1_e2_ni::largestBasisBlade(unsigned int &bm) const {

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
	void __syn_smv___noe1_noe2_noni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 4;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 5];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}


	}




	float __syn_smv___noe1_noe2_noni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___noe1_noe2_noni::largestBasisBlade(unsigned int &bm) const {

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
		return maxC;
	}




	// set to mv 
	void __syn_smv___no_noe1e2_noe1ni_noe2ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 4;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 6;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[1] = arg1.m_c[gidx + 3];
			m_c[2] = arg1.m_c[gidx + 1];
			m_c[3] = arg1.m_c[gidx + 2];
		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}


	}




	float __syn_smv___no_noe1e2_noe1ni_noe2ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___no_noe1e2_noe1ni_noe2ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 1;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 7;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 11;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 13;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalar_e1e2_e1ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 4;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[2] = arg1.m_c[gidx + 3];
		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_e1e2_e1ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___scalar_e1e2_e1ni::largestBasisBlade(unsigned int &bm) const {

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
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1_e2_ni_e1e2ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 1];
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[2] = arg1.m_c[gidx + 3];
			gidx += 4;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 6;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[3] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[3] = (Float)0.0;
		}


	}




	float __syn_smv___e1_e2_ni_e1e2ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1_e2_ni_e1e2ni::largestBasisBlade(unsigned int &bm) const {

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
	void __syn_smv___scalar_e1e2_e2ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 4;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 2];
			m_c[2] = arg1.m_c[gidx + 4];
		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_e1e2_e2ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___scalar_e1e2_e2ni::largestBasisBlade(unsigned int &bm) const {

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
	void __syn_smv___ni_e1e2ni::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 3];
			gidx += 4;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 6;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[1] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[1] = (Float)0.0;
		}


	}




	float __syn_smv___ni_e1e2ni::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___ni_e1e2ni::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 8;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 14;
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
		mv_memcpy(m_c, arg1.m_c, 69);
	}

	// set to scalar
	void om::set(Float scalarVal) {
		c2ga::__G2_GENERATED__::set(*this, point(point_no_e1_e2_ni, scalarVal, (Float)0, (Float)0, (Float)0), point(point_no_e1_e2_ni, (Float)0, scalarVal, (Float)0, (Float)0), point(point_no_e1_e2_ni, (Float)0, (Float)0, scalarVal, (Float)0), point(point_no_e1_e2_ni, (Float)0, (Float)0, (Float)0, scalarVal));
	}

	// set to coordinates 
	void om::set(const Float *coordinates) {
		mv_memcpy(m_c, coordinates, 69);
	}

	// set from basis vectors array
	void om::set(const point *vectors) {
		c2ga::__G2_GENERATED__::set(*this, vectors[0], vectors[1], vectors[2], vectors[3]);
	}


	// set from basis vectors 
	void om::set(const point & image_of_no, const point & image_of_e1, const point & image_of_e2, const point & image_of_ni) {
		c2ga::__G2_GENERATED__::set(*this, image_of_no, image_of_e1, image_of_e2, image_of_ni);
	}


	// set by coordinates, transpose
	void om::set(const Float *coordinates, bool transpose) {
		if (transpose) {
			m_c[0] = coordinates[0];
			m_c[4] = coordinates[1];
			m_c[8] = coordinates[2];
			m_c[12] = coordinates[3];
			m_c[1] = coordinates[4];
			m_c[5] = coordinates[5];
			m_c[9] = coordinates[6];
			m_c[13] = coordinates[7];
			m_c[2] = coordinates[8];
			m_c[6] = coordinates[9];
			m_c[10] = coordinates[10];
			m_c[14] = coordinates[11];
			m_c[3] = coordinates[12];
			m_c[7] = coordinates[13];
			m_c[11] = coordinates[14];
			m_c[15] = coordinates[15];
			m_c[16] = coordinates[16];
			m_c[22] = coordinates[17];
			m_c[28] = coordinates[18];
			m_c[34] = coordinates[19];
			m_c[40] = coordinates[20];
			m_c[46] = coordinates[21];
			m_c[17] = coordinates[22];
			m_c[23] = coordinates[23];
			m_c[29] = coordinates[24];
			m_c[35] = coordinates[25];
			m_c[41] = coordinates[26];
			m_c[47] = coordinates[27];
			m_c[18] = coordinates[28];
			m_c[24] = coordinates[29];
			m_c[30] = coordinates[30];
			m_c[36] = coordinates[31];
			m_c[42] = coordinates[32];
			m_c[48] = coordinates[33];
			m_c[19] = coordinates[34];
			m_c[25] = coordinates[35];
			m_c[31] = coordinates[36];
			m_c[37] = coordinates[37];
			m_c[43] = coordinates[38];
			m_c[49] = coordinates[39];
			m_c[20] = coordinates[40];
			m_c[26] = coordinates[41];
			m_c[32] = coordinates[42];
			m_c[38] = coordinates[43];
			m_c[44] = coordinates[44];
			m_c[50] = coordinates[45];
			m_c[21] = coordinates[46];
			m_c[27] = coordinates[47];
			m_c[33] = coordinates[48];
			m_c[39] = coordinates[49];
			m_c[45] = coordinates[50];
			m_c[51] = coordinates[51];
			m_c[52] = coordinates[52];
			m_c[56] = coordinates[53];
			m_c[60] = coordinates[54];
			m_c[64] = coordinates[55];
			m_c[53] = coordinates[56];
			m_c[57] = coordinates[57];
			m_c[61] = coordinates[58];
			m_c[65] = coordinates[59];
			m_c[54] = coordinates[60];
			m_c[58] = coordinates[61];
			m_c[62] = coordinates[62];
			m_c[66] = coordinates[63];
			m_c[55] = coordinates[64];
			m_c[59] = coordinates[65];
			m_c[63] = coordinates[66];
			m_c[67] = coordinates[67];
			m_c[68] = coordinates[68];
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






	// G2 functions:
	mv lcont(const mv& x, const mv& y) {
		mv __temp_var_1__;
		float __tmp_coord_array_1__[16] ;
		mv_zero(__tmp_coord_array_1__, 16);
		const float* __y_xpd__[5] ;
		y.expand(__y_xpd__, true);
		const float* __x_xpd__[5] ;
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

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_1__[0] += ((__x_xpd__[1][2] * __y_xpd__[1][2]) + (__x_xpd__[1][1] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[1][0] * __y_xpd__[1][3]));

			}

		}
		if (((y.m_gu & 4) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_1__[5] += (__y_xpd__[2][0] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[6] += (__y_xpd__[2][1] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[7] += (__y_xpd__[2][2] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[8] += (__y_xpd__[2][3] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[9] += (__y_xpd__[2][4] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[10] += (__y_xpd__[2][5] * __x_xpd__[0][0]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_1__[1] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[2][0]) + (__x_xpd__[1][0] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[2][1]));
				__tmp_coord_array_1__[2] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[2][0]) + (__x_xpd__[1][0] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[2][2]));
				__tmp_coord_array_1__[3] += ((__x_xpd__[1][0] * __y_xpd__[2][4]) + (__x_xpd__[1][1] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[2][1]));
				__tmp_coord_array_1__[4] += ((__x_xpd__[1][1] * __y_xpd__[2][3]) + (__x_xpd__[1][2] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[2][5]));

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_1__[0] += ((-1.0f * __x_xpd__[2][1] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[2][3]) + (__x_xpd__[2][5] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[2][1]));

			}

		}
		if (((y.m_gu & 8) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_1__[11] += (__y_xpd__[3][0] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[12] += (__y_xpd__[3][1] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[13] += (__y_xpd__[3][2] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[14] += (__y_xpd__[3][3] * __x_xpd__[0][0]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_1__[5] += ((__x_xpd__[1][2] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[1][0] * __y_xpd__[3][1]));
				__tmp_coord_array_1__[6] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[1][0] * __y_xpd__[3][2]));
				__tmp_coord_array_1__[7] += ((-1.0f * __x_xpd__[1][0] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[3][3]));
				__tmp_coord_array_1__[8] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[3][0]));
				__tmp_coord_array_1__[9] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[3][2]) + (__x_xpd__[1][1] * __y_xpd__[3][0]));
				__tmp_coord_array_1__[10] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[3][2]));

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_1__[1] += ((-1.0f * __x_xpd__[2][1] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[3][3]));
				__tmp_coord_array_1__[2] += ((-1.0f * __x_xpd__[2][5] * __y_xpd__[3][1]) + (__x_xpd__[2][4] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[3][0]));
				__tmp_coord_array_1__[3] += ((-1.0f * __x_xpd__[2][5] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[3][3]) + (__x_xpd__[2][0] * __y_xpd__[3][0]));
				__tmp_coord_array_1__[4] += ((-1.0f * __x_xpd__[2][4] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[3][1]));

			}
			if (((x.m_gu & 8) != 0)) {
				__tmp_coord_array_1__[0] += ((__x_xpd__[3][2] * __y_xpd__[3][2]) + (__x_xpd__[3][1] * __y_xpd__[3][1]) + (__x_xpd__[3][0] * __y_xpd__[3][3]) + (__x_xpd__[3][3] * __y_xpd__[3][0]));

			}

		}
		if (((y.m_gu & 16) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_1__[15] += (__y_xpd__[4][0] * __x_xpd__[0][0]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_1__[11] += (-1.0f * __x_xpd__[1][3] * __y_xpd__[4][0]);
				__tmp_coord_array_1__[12] += (__x_xpd__[1][2] * __y_xpd__[4][0]);
				__tmp_coord_array_1__[13] += (-1.0f * __x_xpd__[1][1] * __y_xpd__[4][0]);
				__tmp_coord_array_1__[14] += (__x_xpd__[1][0] * __y_xpd__[4][0]);

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_1__[5] += (-1.0f * __x_xpd__[2][1] * __y_xpd__[4][0]);
				__tmp_coord_array_1__[6] += (__x_xpd__[2][0] * __y_xpd__[4][0]);
				__tmp_coord_array_1__[7] += (__x_xpd__[2][5] * __y_xpd__[4][0]);
				__tmp_coord_array_1__[8] += (__x_xpd__[2][4] * __y_xpd__[4][0]);
				__tmp_coord_array_1__[9] += (-1.0f * __x_xpd__[2][3] * __y_xpd__[4][0]);
				__tmp_coord_array_1__[10] += (-1.0f * __x_xpd__[2][2] * __y_xpd__[4][0]);

			}
			if (((x.m_gu & 8) != 0)) {
				__tmp_coord_array_1__[1] += (-1.0f * __x_xpd__[3][3] * __y_xpd__[4][0]);
				__tmp_coord_array_1__[2] += (__x_xpd__[3][2] * __y_xpd__[4][0]);
				__tmp_coord_array_1__[3] += (-1.0f * __x_xpd__[3][1] * __y_xpd__[4][0]);
				__tmp_coord_array_1__[4] += (__x_xpd__[3][0] * __y_xpd__[4][0]);

			}
			if (((x.m_gu & 16) != 0)) {
				__tmp_coord_array_1__[0] += (-1.0f * __x_xpd__[4][0] * __y_xpd__[4][0]);

			}

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_1__);
		return __temp_var_1__;
	}
	scalar scp(const mv& x, const mv& y) {
		scalar __temp_var_1__;
		const float* __x_xpd__[5] ;
		x.expand(__x_xpd__, true);
		const float* __y_xpd__[5] ;
		y.expand(__y_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			if (((y.m_gu & 1) != 0)) {
				__temp_var_1__.m_c[0] += (__x_xpd__[0][0] * __y_xpd__[0][0]);

			}

		}
		if (((x.m_gu & 2) != 0)) {
			if (((y.m_gu & 2) != 0)) {
				__temp_var_1__.m_c[0] += ((__x_xpd__[1][1] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[1][0] * __y_xpd__[1][3]) + (__x_xpd__[1][2] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[1][0]));

			}

		}
		if (((x.m_gu & 4) != 0)) {
			if (((y.m_gu & 4) != 0)) {
				__temp_var_1__.m_c[0] += ((-1.0f * __x_xpd__[2][0] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[2][1]) + (__x_xpd__[2][5] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[2][4]));

			}

		}
		if (((x.m_gu & 8) != 0)) {
			if (((y.m_gu & 8) != 0)) {
				__temp_var_1__.m_c[0] += ((__x_xpd__[3][2] * __y_xpd__[3][2]) + (__x_xpd__[3][3] * __y_xpd__[3][0]) + (__x_xpd__[3][0] * __y_xpd__[3][3]) + (__x_xpd__[3][1] * __y_xpd__[3][1]));

			}

		}
		if (((x.m_gu & 16) != 0)) {
			if (((y.m_gu & 16) != 0)) {
				__temp_var_1__.m_c[0] += (-1.0f * __x_xpd__[4][0] * __y_xpd__[4][0]);

			}

		}
		return __temp_var_1__;
	}
	mv gp(const mv& x, const mv& y) {
		mv __temp_var_1__;
		float __tmp_coord_array_2__[16] ;
		mv_zero(__tmp_coord_array_2__, 16);
		const float* __y_xpd__[5] ;
		y.expand(__y_xpd__, true);
		const float* __x_xpd__[5] ;
		x.expand(__x_xpd__, true);
		if (((y.m_gu & 1) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_2__[0] += (__x_xpd__[0][0] * __y_xpd__[0][0]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_2__[1] += (__x_xpd__[1][0] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[2] += (__x_xpd__[1][1] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[3] += (__x_xpd__[1][2] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[4] += (__x_xpd__[1][3] * __y_xpd__[0][0]);

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_2__[5] += (__x_xpd__[2][0] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[6] += (__x_xpd__[2][1] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[7] += (__x_xpd__[2][2] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[8] += (__x_xpd__[2][3] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[9] += (__x_xpd__[2][4] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[10] += (__x_xpd__[2][5] * __y_xpd__[0][0]);

			}
			if (((x.m_gu & 8) != 0)) {
				__tmp_coord_array_2__[11] += (__x_xpd__[3][0] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[12] += (__x_xpd__[3][1] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[13] += (__x_xpd__[3][2] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[14] += (__x_xpd__[3][3] * __y_xpd__[0][0]);

			}
			if (((x.m_gu & 16) != 0)) {
				__tmp_coord_array_2__[15] += (__x_xpd__[4][0] * __y_xpd__[0][0]);

			}

		}
		if (((y.m_gu & 2) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_2__[1] += (__x_xpd__[0][0] * __y_xpd__[1][0]);
				__tmp_coord_array_2__[2] += (__x_xpd__[0][0] * __y_xpd__[1][1]);
				__tmp_coord_array_2__[3] += (__x_xpd__[0][0] * __y_xpd__[1][2]);
				__tmp_coord_array_2__[4] += (__x_xpd__[0][0] * __y_xpd__[1][3]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_2__[0] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[1][0]) + (__x_xpd__[1][1] * __y_xpd__[1][1]) + (__x_xpd__[1][2] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[1][0] * __y_xpd__[1][3]));
				__tmp_coord_array_2__[5] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[1][0]) + (__x_xpd__[1][0] * __y_xpd__[1][1]));
				__tmp_coord_array_2__[6] += ((__x_xpd__[1][0] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[1][0]));
				__tmp_coord_array_2__[7] += ((-1.0f * __x_xpd__[1][2] * __y_xpd__[1][1]) + (__x_xpd__[1][1] * __y_xpd__[1][2]));
				__tmp_coord_array_2__[8] += ((__x_xpd__[1][1] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[1][1]));
				__tmp_coord_array_2__[9] += ((__x_xpd__[1][2] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[1][2]));
				__tmp_coord_array_2__[10] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[1][0]) + (__x_xpd__[1][0] * __y_xpd__[1][3]));

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_2__[1] += ((__x_xpd__[2][0] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[1][0]) + (__x_xpd__[2][1] * __y_xpd__[1][2]));
				__tmp_coord_array_2__[2] += ((__x_xpd__[2][0] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[1][0]) + (__x_xpd__[2][2] * __y_xpd__[1][2]));
				__tmp_coord_array_2__[3] += ((-1.0f * __x_xpd__[2][4] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[1][1]) + (__x_xpd__[2][1] * __y_xpd__[1][3]));
				__tmp_coord_array_2__[4] += ((-1.0f * __x_xpd__[2][3] * __y_xpd__[1][1]) + (__x_xpd__[2][5] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[1][2]));
				__tmp_coord_array_2__[11] += ((__x_xpd__[2][4] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[1][2]) + (__x_xpd__[2][2] * __y_xpd__[1][3]));
				__tmp_coord_array_2__[12] += ((__x_xpd__[2][3] * __y_xpd__[1][0]) + (__x_xpd__[2][0] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[1][1]));
				__tmp_coord_array_2__[13] += ((__x_xpd__[2][4] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[1][2]) + (__x_xpd__[2][1] * __y_xpd__[1][3]));
				__tmp_coord_array_2__[14] += ((__x_xpd__[2][0] * __y_xpd__[1][2]) + (__x_xpd__[2][2] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[1][1]));

			}
			if (((x.m_gu & 8) != 0)) {
				__tmp_coord_array_2__[5] += ((__x_xpd__[3][3] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[1][0]));
				__tmp_coord_array_2__[6] += ((-1.0f * __x_xpd__[3][2] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[1][1]));
				__tmp_coord_array_2__[7] += ((-1.0f * __x_xpd__[3][3] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[1][0]));
				__tmp_coord_array_2__[8] += ((-1.0f * __x_xpd__[3][1] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[1][2]));
				__tmp_coord_array_2__[9] += ((__x_xpd__[3][0] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[1][3]));
				__tmp_coord_array_2__[10] += ((-1.0f * __x_xpd__[3][1] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[1][2]));
				__tmp_coord_array_2__[15] += ((__x_xpd__[3][2] * __y_xpd__[1][1]) + (__x_xpd__[3][3] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[1][0]));

			}
			if (((x.m_gu & 16) != 0)) {
				__tmp_coord_array_2__[11] += (__x_xpd__[4][0] * __y_xpd__[1][3]);
				__tmp_coord_array_2__[12] += (-1.0f * __x_xpd__[4][0] * __y_xpd__[1][2]);
				__tmp_coord_array_2__[13] += (__x_xpd__[4][0] * __y_xpd__[1][1]);
				__tmp_coord_array_2__[14] += (-1.0f * __x_xpd__[4][0] * __y_xpd__[1][0]);

			}

		}
		if (((y.m_gu & 4) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_2__[5] += (__x_xpd__[0][0] * __y_xpd__[2][0]);
				__tmp_coord_array_2__[6] += (__x_xpd__[0][0] * __y_xpd__[2][1]);
				__tmp_coord_array_2__[7] += (__x_xpd__[0][0] * __y_xpd__[2][2]);
				__tmp_coord_array_2__[8] += (__x_xpd__[0][0] * __y_xpd__[2][3]);
				__tmp_coord_array_2__[9] += (__x_xpd__[0][0] * __y_xpd__[2][4]);
				__tmp_coord_array_2__[10] += (__x_xpd__[0][0] * __y_xpd__[2][5]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_2__[1] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[2][1]) + (__x_xpd__[1][0] * __y_xpd__[2][5]));
				__tmp_coord_array_2__[2] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[2][0]) + (__x_xpd__[1][0] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[2][2]));
				__tmp_coord_array_2__[3] += ((__x_xpd__[1][1] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[2][1]) + (__x_xpd__[1][0] * __y_xpd__[2][4]));
				__tmp_coord_array_2__[4] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[2][5]) + (__x_xpd__[1][1] * __y_xpd__[2][3]) + (__x_xpd__[1][2] * __y_xpd__[2][4]));
				__tmp_coord_array_2__[11] += ((-1.0f * __x_xpd__[1][2] * __y_xpd__[2][3]) + (__x_xpd__[1][3] * __y_xpd__[2][2]) + (__x_xpd__[1][1] * __y_xpd__[2][4]));
				__tmp_coord_array_2__[12] += ((__x_xpd__[1][3] * __y_xpd__[2][0]) + (__x_xpd__[1][0] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[2][5]));
				__tmp_coord_array_2__[13] += ((-1.0f * __x_xpd__[1][2] * __y_xpd__[2][5]) + (__x_xpd__[1][0] * __y_xpd__[2][4]) + (__x_xpd__[1][3] * __y_xpd__[2][1]));
				__tmp_coord_array_2__[14] += ((__x_xpd__[1][0] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[2][1]) + (__x_xpd__[1][2] * __y_xpd__[2][0]));

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_2__[0] += ((__x_xpd__[2][5] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[2][1]));
				__tmp_coord_array_2__[5] += ((__x_xpd__[2][2] * __y_xpd__[2][1]) + (__x_xpd__[2][0] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[2][0]));
				__tmp_coord_array_2__[6] += ((__x_xpd__[2][1] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[2][0]) + (__x_xpd__[2][0] * __y_xpd__[2][2]));
				__tmp_coord_array_2__[7] += ((__x_xpd__[2][4] * __y_xpd__[2][0]) + (__x_xpd__[2][1] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[2][4]));
				__tmp_coord_array_2__[8] += ((__x_xpd__[2][5] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[2][5]) + (__x_xpd__[2][2] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[2][2]));
				__tmp_coord_array_2__[9] += ((-1.0f * __x_xpd__[2][2] * __y_xpd__[2][3]) + (__x_xpd__[2][3] * __y_xpd__[2][2]) + (__x_xpd__[2][5] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[2][5]));
				__tmp_coord_array_2__[10] += ((__x_xpd__[2][0] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[2][0]) + (__x_xpd__[2][1] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[2][1]));
				__tmp_coord_array_2__[15] += ((__x_xpd__[2][4] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[2][1]) + (__x_xpd__[2][2] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[2][3]) + (__x_xpd__[2][5] * __y_xpd__[2][2]) + (__x_xpd__[2][0] * __y_xpd__[2][4]));

			}
			if (((x.m_gu & 8) != 0)) {
				__tmp_coord_array_2__[1] += ((-1.0f * __x_xpd__[3][2] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[2][2]));
				__tmp_coord_array_2__[2] += ((-1.0f * __x_xpd__[3][1] * __y_xpd__[2][5]) + (__x_xpd__[3][3] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[2][1]));
				__tmp_coord_array_2__[3] += ((__x_xpd__[3][0] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[2][3]));
				__tmp_coord_array_2__[4] += ((-1.0f * __x_xpd__[3][2] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[2][3]));
				__tmp_coord_array_2__[11] += ((-1.0f * __x_xpd__[3][1] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[2][5]) + (__x_xpd__[3][2] * __y_xpd__[2][3]));
				__tmp_coord_array_2__[12] += ((__x_xpd__[3][0] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[2][2]) + (__x_xpd__[3][3] * __y_xpd__[2][4]));
				__tmp_coord_array_2__[13] += ((-1.0f * __x_xpd__[3][3] * __y_xpd__[2][3]) + (__x_xpd__[3][1] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[2][0]));
				__tmp_coord_array_2__[14] += ((-1.0f * __x_xpd__[3][1] * __y_xpd__[2][1]) + (__x_xpd__[3][2] * __y_xpd__[2][0]) + (__x_xpd__[3][3] * __y_xpd__[2][5]));

			}
			if (((x.m_gu & 16) != 0)) {
				__tmp_coord_array_2__[5] += (-1.0f * __x_xpd__[4][0] * __y_xpd__[2][1]);
				__tmp_coord_array_2__[6] += (__x_xpd__[4][0] * __y_xpd__[2][0]);
				__tmp_coord_array_2__[7] += (__x_xpd__[4][0] * __y_xpd__[2][5]);
				__tmp_coord_array_2__[8] += (__x_xpd__[4][0] * __y_xpd__[2][4]);
				__tmp_coord_array_2__[9] += (-1.0f * __x_xpd__[4][0] * __y_xpd__[2][3]);
				__tmp_coord_array_2__[10] += (-1.0f * __x_xpd__[4][0] * __y_xpd__[2][2]);

			}

		}
		if (((y.m_gu & 8) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_2__[11] += (__x_xpd__[0][0] * __y_xpd__[3][0]);
				__tmp_coord_array_2__[12] += (__x_xpd__[0][0] * __y_xpd__[3][1]);
				__tmp_coord_array_2__[13] += (__x_xpd__[0][0] * __y_xpd__[3][2]);
				__tmp_coord_array_2__[14] += (__x_xpd__[0][0] * __y_xpd__[3][3]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_2__[5] += ((__x_xpd__[1][2] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[1][0] * __y_xpd__[3][1]));
				__tmp_coord_array_2__[6] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[1][0] * __y_xpd__[3][2]));
				__tmp_coord_array_2__[7] += ((-1.0f * __x_xpd__[1][0] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[3][3]));
				__tmp_coord_array_2__[8] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[3][0]));
				__tmp_coord_array_2__[9] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[3][2]) + (__x_xpd__[1][1] * __y_xpd__[3][0]));
				__tmp_coord_array_2__[10] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[3][2]));
				__tmp_coord_array_2__[15] += ((__x_xpd__[1][0] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[3][2]) + (__x_xpd__[1][2] * __y_xpd__[3][1]));

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_2__[1] += ((-1.0f * __x_xpd__[2][0] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[3][3]));
				__tmp_coord_array_2__[2] += ((-1.0f * __x_xpd__[2][1] * __y_xpd__[3][0]) + (__x_xpd__[2][4] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[3][1]));
				__tmp_coord_array_2__[3] += ((__x_xpd__[2][0] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[3][2]));
				__tmp_coord_array_2__[4] += ((-1.0f * __x_xpd__[2][3] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[3][2]));
				__tmp_coord_array_2__[11] += ((-1.0f * __x_xpd__[2][3] * __y_xpd__[3][2]) + (__x_xpd__[2][4] * __y_xpd__[3][1]) + (__x_xpd__[2][5] * __y_xpd__[3][0]));
				__tmp_coord_array_2__[12] += ((-1.0f * __x_xpd__[2][1] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[3][3]) + (__x_xpd__[2][2] * __y_xpd__[3][2]));
				__tmp_coord_array_2__[13] += ((__x_xpd__[2][3] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[3][1]) + (__x_xpd__[2][0] * __y_xpd__[3][0]));
				__tmp_coord_array_2__[14] += ((__x_xpd__[2][1] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[3][2]));

			}
			if (((x.m_gu & 8) != 0)) {
				__tmp_coord_array_2__[0] += ((__x_xpd__[3][1] * __y_xpd__[3][1]) + (__x_xpd__[3][2] * __y_xpd__[3][2]) + (__x_xpd__[3][0] * __y_xpd__[3][3]) + (__x_xpd__[3][3] * __y_xpd__[3][0]));
				__tmp_coord_array_2__[5] += ((__x_xpd__[3][2] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[3][2]));
				__tmp_coord_array_2__[6] += ((-1.0f * __x_xpd__[3][1] * __y_xpd__[3][3]) + (__x_xpd__[3][3] * __y_xpd__[3][1]));
				__tmp_coord_array_2__[7] += ((-1.0f * __x_xpd__[3][2] * __y_xpd__[3][1]) + (__x_xpd__[3][1] * __y_xpd__[3][2]));
				__tmp_coord_array_2__[8] += ((-1.0f * __x_xpd__[3][0] * __y_xpd__[3][2]) + (__x_xpd__[3][2] * __y_xpd__[3][0]));
				__tmp_coord_array_2__[9] += ((__x_xpd__[3][0] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[3][0]));
				__tmp_coord_array_2__[10] += ((-1.0f * __x_xpd__[3][3] * __y_xpd__[3][0]) + (__x_xpd__[3][0] * __y_xpd__[3][3]));

			}
			if (((x.m_gu & 16) != 0)) {
				__tmp_coord_array_2__[1] += (__x_xpd__[4][0] * __y_xpd__[3][3]);
				__tmp_coord_array_2__[2] += (-1.0f * __x_xpd__[4][0] * __y_xpd__[3][2]);
				__tmp_coord_array_2__[3] += (__x_xpd__[4][0] * __y_xpd__[3][1]);
				__tmp_coord_array_2__[4] += (-1.0f * __x_xpd__[4][0] * __y_xpd__[3][0]);

			}

		}
		if (((y.m_gu & 16) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_2__[15] += (__x_xpd__[0][0] * __y_xpd__[4][0]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_2__[11] += (-1.0f * __x_xpd__[1][3] * __y_xpd__[4][0]);
				__tmp_coord_array_2__[12] += (__x_xpd__[1][2] * __y_xpd__[4][0]);
				__tmp_coord_array_2__[13] += (-1.0f * __x_xpd__[1][1] * __y_xpd__[4][0]);
				__tmp_coord_array_2__[14] += (__x_xpd__[1][0] * __y_xpd__[4][0]);

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_2__[5] += (-1.0f * __x_xpd__[2][1] * __y_xpd__[4][0]);
				__tmp_coord_array_2__[6] += (__x_xpd__[2][0] * __y_xpd__[4][0]);
				__tmp_coord_array_2__[7] += (__x_xpd__[2][5] * __y_xpd__[4][0]);
				__tmp_coord_array_2__[8] += (__x_xpd__[2][4] * __y_xpd__[4][0]);
				__tmp_coord_array_2__[9] += (-1.0f * __x_xpd__[2][3] * __y_xpd__[4][0]);
				__tmp_coord_array_2__[10] += (-1.0f * __x_xpd__[2][2] * __y_xpd__[4][0]);

			}
			if (((x.m_gu & 8) != 0)) {
				__tmp_coord_array_2__[1] += (-1.0f * __x_xpd__[3][3] * __y_xpd__[4][0]);
				__tmp_coord_array_2__[2] += (__x_xpd__[3][2] * __y_xpd__[4][0]);
				__tmp_coord_array_2__[3] += (-1.0f * __x_xpd__[3][1] * __y_xpd__[4][0]);
				__tmp_coord_array_2__[4] += (__x_xpd__[3][0] * __y_xpd__[4][0]);

			}
			if (((x.m_gu & 16) != 0)) {
				__tmp_coord_array_2__[0] += (-1.0f * __x_xpd__[4][0] * __y_xpd__[4][0]);

			}

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_2__);
		return __temp_var_1__;
	}
	mv gpEM(const mv& x, const mv& y) {
		mv __temp_var_1__;
		float __tmp_coord_array_3__[16] ;
		mv_zero(__tmp_coord_array_3__, 16);
		const float* __y_xpd__[5] ;
		y.expand(__y_xpd__, true);
		const float* __x_xpd__[5] ;
		x.expand(__x_xpd__, true);
		if (((y.m_gu & 1) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_3__[0] += (__x_xpd__[0][0] * __y_xpd__[0][0]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_3__[1] += (__x_xpd__[1][0] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[2] += (__x_xpd__[1][1] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[3] += (__x_xpd__[1][2] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[4] += (__x_xpd__[1][3] * __y_xpd__[0][0]);

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_3__[5] += (__x_xpd__[2][0] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[6] += (__x_xpd__[2][1] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[7] += (__x_xpd__[2][2] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[8] += (__x_xpd__[2][3] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[9] += (__x_xpd__[2][4] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[10] += (__x_xpd__[2][5] * __y_xpd__[0][0]);

			}
			if (((x.m_gu & 8) != 0)) {
				__tmp_coord_array_3__[11] += (__x_xpd__[3][0] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[12] += (__x_xpd__[3][1] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[13] += (__x_xpd__[3][2] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[14] += (__x_xpd__[3][3] * __y_xpd__[0][0]);

			}
			if (((x.m_gu & 16) != 0)) {
				__tmp_coord_array_3__[15] += (__x_xpd__[4][0] * __y_xpd__[0][0]);

			}

		}
		if (((y.m_gu & 2) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_3__[1] += (__x_xpd__[0][0] * __y_xpd__[1][0]);
				__tmp_coord_array_3__[2] += (__x_xpd__[0][0] * __y_xpd__[1][1]);
				__tmp_coord_array_3__[3] += (__x_xpd__[0][0] * __y_xpd__[1][2]);
				__tmp_coord_array_3__[4] += (__x_xpd__[0][0] * __y_xpd__[1][3]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_3__[0] += ((__x_xpd__[1][0] * __y_xpd__[1][0]) + (__x_xpd__[1][2] * __y_xpd__[1][2]) + (__x_xpd__[1][1] * __y_xpd__[1][1]) + (__x_xpd__[1][3] * __y_xpd__[1][3]));
				__tmp_coord_array_3__[5] += ((__x_xpd__[1][0] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[1][0]));
				__tmp_coord_array_3__[6] += ((-1.0f * __x_xpd__[1][2] * __y_xpd__[1][0]) + (__x_xpd__[1][0] * __y_xpd__[1][2]));
				__tmp_coord_array_3__[7] += ((-1.0f * __x_xpd__[1][2] * __y_xpd__[1][1]) + (__x_xpd__[1][1] * __y_xpd__[1][2]));
				__tmp_coord_array_3__[8] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[1][1]) + (__x_xpd__[1][1] * __y_xpd__[1][3]));
				__tmp_coord_array_3__[9] += ((__x_xpd__[1][2] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[1][2]));
				__tmp_coord_array_3__[10] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[1][0]) + (__x_xpd__[1][0] * __y_xpd__[1][3]));

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_3__[1] += ((__x_xpd__[2][1] * __y_xpd__[1][2]) + (__x_xpd__[2][5] * __y_xpd__[1][3]) + (__x_xpd__[2][0] * __y_xpd__[1][1]));
				__tmp_coord_array_3__[2] += ((-1.0f * __x_xpd__[2][0] * __y_xpd__[1][0]) + (__x_xpd__[2][3] * __y_xpd__[1][3]) + (__x_xpd__[2][2] * __y_xpd__[1][2]));
				__tmp_coord_array_3__[3] += ((__x_xpd__[2][4] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[1][0]));
				__tmp_coord_array_3__[4] += ((-1.0f * __x_xpd__[2][3] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[1][2]));
				__tmp_coord_array_3__[11] += ((__x_xpd__[2][2] * __y_xpd__[1][3]) + (__x_xpd__[2][4] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[1][2]));
				__tmp_coord_array_3__[12] += ((__x_xpd__[2][3] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[1][1]) + (__x_xpd__[2][0] * __y_xpd__[1][3]));
				__tmp_coord_array_3__[13] += ((-1.0f * __x_xpd__[2][5] * __y_xpd__[1][2]) + (__x_xpd__[2][1] * __y_xpd__[1][3]) + (__x_xpd__[2][4] * __y_xpd__[1][0]));
				__tmp_coord_array_3__[14] += ((__x_xpd__[2][0] * __y_xpd__[1][2]) + (__x_xpd__[2][2] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[1][1]));

			}
			if (((x.m_gu & 8) != 0)) {
				__tmp_coord_array_3__[5] += ((__x_xpd__[3][3] * __y_xpd__[1][2]) + (__x_xpd__[3][1] * __y_xpd__[1][3]));
				__tmp_coord_array_3__[6] += ((__x_xpd__[3][2] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[1][1]));
				__tmp_coord_array_3__[7] += ((__x_xpd__[3][3] * __y_xpd__[1][0]) + (__x_xpd__[3][0] * __y_xpd__[1][3]));
				__tmp_coord_array_3__[8] += ((-1.0f * __x_xpd__[3][0] * __y_xpd__[1][2]) + (__x_xpd__[3][1] * __y_xpd__[1][0]));
				__tmp_coord_array_3__[9] += ((__x_xpd__[3][2] * __y_xpd__[1][0]) + (__x_xpd__[3][0] * __y_xpd__[1][1]));
				__tmp_coord_array_3__[10] += ((-1.0f * __x_xpd__[3][2] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[1][1]));
				__tmp_coord_array_3__[15] += ((__x_xpd__[3][3] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[1][0]) + (__x_xpd__[3][2] * __y_xpd__[1][1]));

			}
			if (((x.m_gu & 16) != 0)) {
				__tmp_coord_array_3__[11] += (-1.0f * __x_xpd__[4][0] * __y_xpd__[1][0]);
				__tmp_coord_array_3__[12] += (-1.0f * __x_xpd__[4][0] * __y_xpd__[1][2]);
				__tmp_coord_array_3__[13] += (__x_xpd__[4][0] * __y_xpd__[1][1]);
				__tmp_coord_array_3__[14] += (__x_xpd__[4][0] * __y_xpd__[1][3]);

			}

		}
		if (((y.m_gu & 4) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_3__[5] += (__x_xpd__[0][0] * __y_xpd__[2][0]);
				__tmp_coord_array_3__[6] += (__x_xpd__[0][0] * __y_xpd__[2][1]);
				__tmp_coord_array_3__[7] += (__x_xpd__[0][0] * __y_xpd__[2][2]);
				__tmp_coord_array_3__[8] += (__x_xpd__[0][0] * __y_xpd__[2][3]);
				__tmp_coord_array_3__[9] += (__x_xpd__[0][0] * __y_xpd__[2][4]);
				__tmp_coord_array_3__[10] += (__x_xpd__[0][0] * __y_xpd__[2][5]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_3__[1] += ((-1.0f * __x_xpd__[1][2] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[2][5]));
				__tmp_coord_array_3__[2] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[2][3]) + (__x_xpd__[1][0] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[2][2]));
				__tmp_coord_array_3__[3] += ((__x_xpd__[1][1] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[2][4]) + (__x_xpd__[1][0] * __y_xpd__[2][1]));
				__tmp_coord_array_3__[4] += ((__x_xpd__[1][2] * __y_xpd__[2][4]) + (__x_xpd__[1][0] * __y_xpd__[2][5]) + (__x_xpd__[1][1] * __y_xpd__[2][3]));
				__tmp_coord_array_3__[11] += ((-1.0f * __x_xpd__[1][2] * __y_xpd__[2][3]) + (__x_xpd__[1][1] * __y_xpd__[2][4]) + (__x_xpd__[1][3] * __y_xpd__[2][2]));
				__tmp_coord_array_3__[12] += ((__x_xpd__[1][3] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[2][5]) + (__x_xpd__[1][0] * __y_xpd__[2][3]));
				__tmp_coord_array_3__[13] += ((__x_xpd__[1][0] * __y_xpd__[2][4]) + (__x_xpd__[1][3] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[2][5]));
				__tmp_coord_array_3__[14] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[2][1]) + (__x_xpd__[1][0] * __y_xpd__[2][2]) + (__x_xpd__[1][2] * __y_xpd__[2][0]));

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_3__[0] += ((-1.0f * __x_xpd__[2][5] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[2][2]));
				__tmp_coord_array_3__[5] += ((-1.0f * __x_xpd__[2][5] * __y_xpd__[2][3]) + (__x_xpd__[2][2] * __y_xpd__[2][1]) + (__x_xpd__[2][3] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[2][2]));
				__tmp_coord_array_3__[6] += ((__x_xpd__[2][4] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[2][0]) + (__x_xpd__[2][0] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[2][4]));
				__tmp_coord_array_3__[7] += ((-1.0f * __x_xpd__[2][3] * __y_xpd__[2][4]) + (__x_xpd__[2][4] * __y_xpd__[2][3]) + (__x_xpd__[2][1] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[2][1]));
				__tmp_coord_array_3__[8] += ((-1.0f * __x_xpd__[2][0] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[2][2]) + (__x_xpd__[2][2] * __y_xpd__[2][4]) + (__x_xpd__[2][5] * __y_xpd__[2][0]));
				__tmp_coord_array_3__[9] += ((__x_xpd__[2][5] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[2][3]) + (__x_xpd__[2][3] * __y_xpd__[2][2]));
				__tmp_coord_array_3__[10] += ((-1.0f * __x_xpd__[2][4] * __y_xpd__[2][1]) + (__x_xpd__[2][0] * __y_xpd__[2][3]) + (__x_xpd__[2][1] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[2][0]));
				__tmp_coord_array_3__[15] += ((__x_xpd__[2][0] * __y_xpd__[2][4]) + (__x_xpd__[2][4] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[2][1]) + (__x_xpd__[2][5] * __y_xpd__[2][2]) + (__x_xpd__[2][2] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[2][3]));

			}
			if (((x.m_gu & 8) != 0)) {
				__tmp_coord_array_3__[1] += ((-1.0f * __x_xpd__[3][1] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[2][2]));
				__tmp_coord_array_3__[2] += ((__x_xpd__[3][3] * __y_xpd__[2][1]) + (__x_xpd__[3][1] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[2][4]));
				__tmp_coord_array_3__[3] += ((-1.0f * __x_xpd__[3][3] * __y_xpd__[2][0]) + (__x_xpd__[3][0] * __y_xpd__[2][3]) + (__x_xpd__[3][2] * __y_xpd__[2][5]));
				__tmp_coord_array_3__[4] += ((-1.0f * __x_xpd__[3][1] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[2][1]));
				__tmp_coord_array_3__[11] += ((-1.0f * __x_xpd__[3][1] * __y_xpd__[2][1]) + (__x_xpd__[3][2] * __y_xpd__[2][0]) + (__x_xpd__[3][3] * __y_xpd__[2][5]));
				__tmp_coord_array_3__[12] += ((__x_xpd__[3][3] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[2][2]) + (__x_xpd__[3][0] * __y_xpd__[2][1]));
				__tmp_coord_array_3__[13] += ((-1.0f * __x_xpd__[3][3] * __y_xpd__[2][3]) + (__x_xpd__[3][1] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[2][0]));
				__tmp_coord_array_3__[14] += ((__x_xpd__[3][2] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[2][5]));

			}
			if (((x.m_gu & 16) != 0)) {
				__tmp_coord_array_3__[5] += (-1.0f * __x_xpd__[4][0] * __y_xpd__[2][4]);
				__tmp_coord_array_3__[6] += (__x_xpd__[4][0] * __y_xpd__[2][3]);
				__tmp_coord_array_3__[7] += (-1.0f * __x_xpd__[4][0] * __y_xpd__[2][5]);
				__tmp_coord_array_3__[8] += (__x_xpd__[4][0] * __y_xpd__[2][1]);
				__tmp_coord_array_3__[9] += (-1.0f * __x_xpd__[4][0] * __y_xpd__[2][0]);
				__tmp_coord_array_3__[10] += (-1.0f * __x_xpd__[4][0] * __y_xpd__[2][2]);

			}

		}
		if (((y.m_gu & 8) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_3__[11] += (__x_xpd__[0][0] * __y_xpd__[3][0]);
				__tmp_coord_array_3__[12] += (__x_xpd__[0][0] * __y_xpd__[3][1]);
				__tmp_coord_array_3__[13] += (__x_xpd__[0][0] * __y_xpd__[3][2]);
				__tmp_coord_array_3__[14] += (__x_xpd__[0][0] * __y_xpd__[3][3]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_3__[5] += ((__x_xpd__[1][3] * __y_xpd__[3][1]) + (__x_xpd__[1][2] * __y_xpd__[3][3]));
				__tmp_coord_array_3__[6] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[3][3]) + (__x_xpd__[1][3] * __y_xpd__[3][2]));
				__tmp_coord_array_3__[7] += ((__x_xpd__[1][0] * __y_xpd__[3][3]) + (__x_xpd__[1][3] * __y_xpd__[3][0]));
				__tmp_coord_array_3__[8] += ((__x_xpd__[1][0] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[3][0]));
				__tmp_coord_array_3__[9] += ((__x_xpd__[1][0] * __y_xpd__[3][2]) + (__x_xpd__[1][1] * __y_xpd__[3][0]));
				__tmp_coord_array_3__[10] += ((-1.0f * __x_xpd__[1][2] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[3][1]));
				__tmp_coord_array_3__[15] += ((__x_xpd__[1][2] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[3][3]) + (__x_xpd__[1][0] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[3][2]));

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_3__[1] += ((-1.0f * __x_xpd__[2][2] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[3][1]));
				__tmp_coord_array_3__[2] += ((__x_xpd__[2][1] * __y_xpd__[3][3]) + (__x_xpd__[2][5] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[3][0]));
				__tmp_coord_array_3__[3] += ((__x_xpd__[2][3] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[3][3]) + (__x_xpd__[2][5] * __y_xpd__[3][2]));
				__tmp_coord_array_3__[4] += ((-1.0f * __x_xpd__[2][0] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[3][2]));
				__tmp_coord_array_3__[11] += ((__x_xpd__[2][1] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[3][3]));
				__tmp_coord_array_3__[12] += ((-1.0f * __x_xpd__[2][4] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[3][0]) + (__x_xpd__[2][2] * __y_xpd__[3][2]));
				__tmp_coord_array_3__[13] += ((__x_xpd__[2][3] * __y_xpd__[3][3]) + (__x_xpd__[2][0] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[3][1]));
				__tmp_coord_array_3__[14] += ((-1.0f * __x_xpd__[2][3] * __y_xpd__[3][2]) + (__x_xpd__[2][5] * __y_xpd__[3][0]) + (__x_xpd__[2][4] * __y_xpd__[3][1]));

			}
			if (((x.m_gu & 8) != 0)) {
				__tmp_coord_array_3__[0] += ((-1.0f * __x_xpd__[3][1] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[3][0] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[3][3]));
				__tmp_coord_array_3__[5] += ((-1.0f * __x_xpd__[3][2] * __y_xpd__[3][0]) + (__x_xpd__[3][0] * __y_xpd__[3][2]));
				__tmp_coord_array_3__[6] += ((-1.0f * __x_xpd__[3][0] * __y_xpd__[3][1]) + (__x_xpd__[3][1] * __y_xpd__[3][0]));
				__tmp_coord_array_3__[7] += ((__x_xpd__[3][2] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[3][2]));
				__tmp_coord_array_3__[8] += ((-1.0f * __x_xpd__[3][2] * __y_xpd__[3][3]) + (__x_xpd__[3][3] * __y_xpd__[3][2]));
				__tmp_coord_array_3__[9] += ((__x_xpd__[3][1] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[3][1]));
				__tmp_coord_array_3__[10] += ((__x_xpd__[3][0] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[3][0]));

			}
			if (((x.m_gu & 16) != 0)) {
				__tmp_coord_array_3__[1] += (-1.0f * __x_xpd__[4][0] * __y_xpd__[3][0]);
				__tmp_coord_array_3__[2] += (__x_xpd__[4][0] * __y_xpd__[3][2]);
				__tmp_coord_array_3__[3] += (-1.0f * __x_xpd__[4][0] * __y_xpd__[3][1]);
				__tmp_coord_array_3__[4] += (__x_xpd__[4][0] * __y_xpd__[3][3]);

			}

		}
		if (((y.m_gu & 16) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_3__[15] += (__x_xpd__[0][0] * __y_xpd__[4][0]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_3__[11] += (__x_xpd__[1][0] * __y_xpd__[4][0]);
				__tmp_coord_array_3__[12] += (__x_xpd__[1][2] * __y_xpd__[4][0]);
				__tmp_coord_array_3__[13] += (-1.0f * __x_xpd__[1][1] * __y_xpd__[4][0]);
				__tmp_coord_array_3__[14] += (-1.0f * __x_xpd__[1][3] * __y_xpd__[4][0]);

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_3__[5] += (-1.0f * __x_xpd__[2][4] * __y_xpd__[4][0]);
				__tmp_coord_array_3__[6] += (__x_xpd__[2][3] * __y_xpd__[4][0]);
				__tmp_coord_array_3__[7] += (-1.0f * __x_xpd__[2][5] * __y_xpd__[4][0]);
				__tmp_coord_array_3__[8] += (__x_xpd__[2][1] * __y_xpd__[4][0]);
				__tmp_coord_array_3__[9] += (-1.0f * __x_xpd__[2][0] * __y_xpd__[4][0]);
				__tmp_coord_array_3__[10] += (-1.0f * __x_xpd__[2][2] * __y_xpd__[4][0]);

			}
			if (((x.m_gu & 8) != 0)) {
				__tmp_coord_array_3__[1] += (__x_xpd__[3][0] * __y_xpd__[4][0]);
				__tmp_coord_array_3__[2] += (-1.0f * __x_xpd__[3][2] * __y_xpd__[4][0]);
				__tmp_coord_array_3__[3] += (__x_xpd__[3][1] * __y_xpd__[4][0]);
				__tmp_coord_array_3__[4] += (-1.0f * __x_xpd__[3][3] * __y_xpd__[4][0]);

			}
			if (((x.m_gu & 16) != 0)) {
				__tmp_coord_array_3__[0] += (__x_xpd__[4][0] * __y_xpd__[4][0]);

			}

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_3__);
		return __temp_var_1__;
	}
	scalar scpEM(const mv& x, const mv& y) {
		scalar __temp_var_1__;
		const float* __y_xpd__[5] ;
		y.expand(__y_xpd__, true);
		const float* __x_xpd__[5] ;
		x.expand(__x_xpd__, true);
		if (((y.m_gu & 1) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__temp_var_1__.m_c[0] += (__x_xpd__[0][0] * __y_xpd__[0][0]);

			}

		}
		if (((y.m_gu & 2) != 0)) {
			if (((x.m_gu & 2) != 0)) {
				__temp_var_1__.m_c[0] += ((__x_xpd__[1][3] * __y_xpd__[1][3]) + (__x_xpd__[1][1] * __y_xpd__[1][1]) + (__x_xpd__[1][0] * __y_xpd__[1][0]) + (__x_xpd__[1][2] * __y_xpd__[1][2]));

			}

		}
		if (((y.m_gu & 4) != 0)) {
			if (((x.m_gu & 4) != 0)) {
				__temp_var_1__.m_c[0] += ((-1.0f * __x_xpd__[2][2] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[2][0]));

			}

		}
		if (((y.m_gu & 8) != 0)) {
			if (((x.m_gu & 8) != 0)) {
				__temp_var_1__.m_c[0] += ((-1.0f * __x_xpd__[3][0] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[3][1]));

			}

		}
		if (((y.m_gu & 16) != 0)) {
			if (((x.m_gu & 16) != 0)) {
				__temp_var_1__.m_c[0] += (__x_xpd__[4][0] * __y_xpd__[4][0]);

			}

		}
		return __temp_var_1__;
	}
	mv lcontEM(const mv& x, const mv& y) {
		mv __temp_var_1__;
		float __tmp_coord_array_4__[16] ;
		mv_zero(__tmp_coord_array_4__, 16);
		const float* __y_xpd__[5] ;
		y.expand(__y_xpd__, true);
		const float* __x_xpd__[5] ;
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

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_4__[0] += ((__x_xpd__[1][3] * __y_xpd__[1][3]) + (__x_xpd__[1][0] * __y_xpd__[1][0]) + (__x_xpd__[1][2] * __y_xpd__[1][2]) + (__x_xpd__[1][1] * __y_xpd__[1][1]));

			}

		}
		if (((y.m_gu & 4) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_4__[5] += (__y_xpd__[2][0] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[6] += (__y_xpd__[2][1] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[7] += (__y_xpd__[2][2] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[8] += (__y_xpd__[2][3] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[9] += (__y_xpd__[2][4] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[10] += (__y_xpd__[2][5] * __x_xpd__[0][0]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_4__[1] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[2][0]));
				__tmp_coord_array_4__[2] += ((-1.0f * __x_xpd__[1][2] * __y_xpd__[2][2]) + (__x_xpd__[1][0] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[2][3]));
				__tmp_coord_array_4__[3] += ((__x_xpd__[1][1] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[2][4]) + (__x_xpd__[1][0] * __y_xpd__[2][1]));
				__tmp_coord_array_4__[4] += ((__x_xpd__[1][2] * __y_xpd__[2][4]) + (__x_xpd__[1][0] * __y_xpd__[2][5]) + (__x_xpd__[1][1] * __y_xpd__[2][3]));

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_4__[0] += ((-1.0f * __x_xpd__[2][0] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[2][5]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[2][4]));

			}

		}
		if (((y.m_gu & 8) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_4__[11] += (__y_xpd__[3][0] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[12] += (__y_xpd__[3][1] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[13] += (__y_xpd__[3][2] * __x_xpd__[0][0]);
				__tmp_coord_array_4__[14] += (__y_xpd__[3][3] * __x_xpd__[0][0]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_4__[5] += ((__x_xpd__[1][3] * __y_xpd__[3][1]) + (__x_xpd__[1][2] * __y_xpd__[3][3]));
				__tmp_coord_array_4__[6] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[3][3]) + (__x_xpd__[1][3] * __y_xpd__[3][2]));
				__tmp_coord_array_4__[7] += ((__x_xpd__[1][0] * __y_xpd__[3][3]) + (__x_xpd__[1][3] * __y_xpd__[3][0]));
				__tmp_coord_array_4__[8] += ((-1.0f * __x_xpd__[1][2] * __y_xpd__[3][0]) + (__x_xpd__[1][0] * __y_xpd__[3][1]));
				__tmp_coord_array_4__[9] += ((__x_xpd__[1][1] * __y_xpd__[3][0]) + (__x_xpd__[1][0] * __y_xpd__[3][2]));
				__tmp_coord_array_4__[10] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[3][2]));

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_4__[1] += ((-1.0f * __x_xpd__[2][3] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[3][2]));
				__tmp_coord_array_4__[2] += ((__x_xpd__[2][5] * __y_xpd__[3][1]) + (__x_xpd__[2][1] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[2][4] * __y_xpd__[3][0]));
				__tmp_coord_array_4__[3] += ((-1.0f * __x_xpd__[2][0] * __y_xpd__[3][3]) + (__x_xpd__[2][5] * __y_xpd__[3][2]) + (__x_xpd__[2][3] * __y_xpd__[3][0]));
				__tmp_coord_array_4__[4] += ((-1.0f * __x_xpd__[2][2] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[3][2]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[3][1]));

			}
			if (((x.m_gu & 8) != 0)) {
				__tmp_coord_array_4__[0] += ((-1.0f * __x_xpd__[3][0] * __y_xpd__[3][0]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[3][3] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[3][2] * __y_xpd__[3][2]));

			}

		}
		if (((y.m_gu & 16) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_4__[15] += (__y_xpd__[4][0] * __x_xpd__[0][0]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_4__[11] += (__x_xpd__[1][0] * __y_xpd__[4][0]);
				__tmp_coord_array_4__[12] += (__x_xpd__[1][2] * __y_xpd__[4][0]);
				__tmp_coord_array_4__[13] += (-1.0f * __x_xpd__[1][1] * __y_xpd__[4][0]);
				__tmp_coord_array_4__[14] += (-1.0f * __x_xpd__[1][3] * __y_xpd__[4][0]);

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_4__[5] += (-1.0f * __x_xpd__[2][4] * __y_xpd__[4][0]);
				__tmp_coord_array_4__[6] += (__x_xpd__[2][3] * __y_xpd__[4][0]);
				__tmp_coord_array_4__[7] += (-1.0f * __x_xpd__[2][5] * __y_xpd__[4][0]);
				__tmp_coord_array_4__[8] += (__x_xpd__[2][1] * __y_xpd__[4][0]);
				__tmp_coord_array_4__[9] += (-1.0f * __x_xpd__[2][0] * __y_xpd__[4][0]);
				__tmp_coord_array_4__[10] += (-1.0f * __x_xpd__[2][2] * __y_xpd__[4][0]);

			}
			if (((x.m_gu & 8) != 0)) {
				__tmp_coord_array_4__[1] += (__x_xpd__[3][0] * __y_xpd__[4][0]);
				__tmp_coord_array_4__[2] += (-1.0f * __x_xpd__[3][2] * __y_xpd__[4][0]);
				__tmp_coord_array_4__[3] += (__x_xpd__[3][1] * __y_xpd__[4][0]);
				__tmp_coord_array_4__[4] += (-1.0f * __x_xpd__[3][3] * __y_xpd__[4][0]);

			}
			if (((x.m_gu & 16) != 0)) {
				__tmp_coord_array_4__[0] += (__x_xpd__[4][0] * __y_xpd__[4][0]);

			}

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_4__);
		return __temp_var_1__;
	}
	mv op(const mv& x, const mv& y) {
		mv __temp_var_1__;
		float __tmp_coord_array_5__[16] ;
		mv_zero(__tmp_coord_array_5__, 16);
		const float* __x_xpd__[5] ;
		x.expand(__x_xpd__, true);
		const float* __y_xpd__[5] ;
		y.expand(__y_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			if (((y.m_gu & 1) != 0)) {
				__tmp_coord_array_5__[0] += (__x_xpd__[0][0] * __y_xpd__[0][0]);

			}
			if (((y.m_gu & 2) != 0)) {
				__tmp_coord_array_5__[1] += (__x_xpd__[0][0] * __y_xpd__[1][0]);
				__tmp_coord_array_5__[2] += (__x_xpd__[0][0] * __y_xpd__[1][1]);
				__tmp_coord_array_5__[3] += (__x_xpd__[0][0] * __y_xpd__[1][2]);
				__tmp_coord_array_5__[4] += (__x_xpd__[0][0] * __y_xpd__[1][3]);

			}
			if (((y.m_gu & 4) != 0)) {
				__tmp_coord_array_5__[5] += (__x_xpd__[0][0] * __y_xpd__[2][0]);
				__tmp_coord_array_5__[6] += (__x_xpd__[0][0] * __y_xpd__[2][1]);
				__tmp_coord_array_5__[7] += (__x_xpd__[0][0] * __y_xpd__[2][2]);
				__tmp_coord_array_5__[8] += (__x_xpd__[0][0] * __y_xpd__[2][3]);
				__tmp_coord_array_5__[9] += (__x_xpd__[0][0] * __y_xpd__[2][4]);
				__tmp_coord_array_5__[10] += (__x_xpd__[0][0] * __y_xpd__[2][5]);

			}
			if (((y.m_gu & 8) != 0)) {
				__tmp_coord_array_5__[11] += (__x_xpd__[0][0] * __y_xpd__[3][0]);
				__tmp_coord_array_5__[12] += (__x_xpd__[0][0] * __y_xpd__[3][1]);
				__tmp_coord_array_5__[13] += (__x_xpd__[0][0] * __y_xpd__[3][2]);
				__tmp_coord_array_5__[14] += (__x_xpd__[0][0] * __y_xpd__[3][3]);

			}
			if (((y.m_gu & 16) != 0)) {
				__tmp_coord_array_5__[15] += (__x_xpd__[0][0] * __y_xpd__[4][0]);

			}

		}
		if (((x.m_gu & 2) != 0)) {
			if (((y.m_gu & 1) != 0)) {
				__tmp_coord_array_5__[1] += (__x_xpd__[1][0] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[2] += (__x_xpd__[1][1] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[3] += (__x_xpd__[1][2] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[4] += (__x_xpd__[1][3] * __y_xpd__[0][0]);

			}
			if (((y.m_gu & 2) != 0)) {
				__tmp_coord_array_5__[5] += ((__x_xpd__[1][0] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[1][0]));
				__tmp_coord_array_5__[6] += ((-1.0f * __x_xpd__[1][2] * __y_xpd__[1][0]) + (__x_xpd__[1][0] * __y_xpd__[1][2]));
				__tmp_coord_array_5__[7] += ((__x_xpd__[1][1] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[1][1]));
				__tmp_coord_array_5__[8] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[1][1]) + (__x_xpd__[1][1] * __y_xpd__[1][3]));
				__tmp_coord_array_5__[9] += ((__x_xpd__[1][2] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[1][2]));
				__tmp_coord_array_5__[10] += ((-1.0f * __x_xpd__[1][3] * __y_xpd__[1][0]) + (__x_xpd__[1][0] * __y_xpd__[1][3]));

			}
			if (((y.m_gu & 4) != 0)) {
				__tmp_coord_array_5__[11] += ((__x_xpd__[1][1] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[2][3]) + (__x_xpd__[1][3] * __y_xpd__[2][2]));
				__tmp_coord_array_5__[12] += ((__x_xpd__[1][3] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[2][5]) + (__x_xpd__[1][0] * __y_xpd__[2][3]));
				__tmp_coord_array_5__[13] += ((__x_xpd__[1][3] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[2][5]) + (__x_xpd__[1][0] * __y_xpd__[2][4]));
				__tmp_coord_array_5__[14] += ((__x_xpd__[1][0] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[2][1]) + (__x_xpd__[1][2] * __y_xpd__[2][0]));

			}
			if (((y.m_gu & 8) != 0)) {
				__tmp_coord_array_5__[15] += ((__x_xpd__[1][0] * __y_xpd__[3][0]) + (__x_xpd__[1][2] * __y_xpd__[3][1]) + (-1.0f * __x_xpd__[1][3] * __y_xpd__[3][3]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[3][2]));

			}

		}
		if (((x.m_gu & 4) != 0)) {
			if (((y.m_gu & 1) != 0)) {
				__tmp_coord_array_5__[5] += (__x_xpd__[2][0] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[6] += (__x_xpd__[2][1] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[7] += (__x_xpd__[2][2] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[8] += (__x_xpd__[2][3] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[9] += (__x_xpd__[2][4] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[10] += (__x_xpd__[2][5] * __y_xpd__[0][0]);

			}
			if (((y.m_gu & 2) != 0)) {
				__tmp_coord_array_5__[11] += ((__x_xpd__[2][2] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[1][2]) + (__x_xpd__[2][4] * __y_xpd__[1][1]));
				__tmp_coord_array_5__[12] += ((__x_xpd__[2][0] * __y_xpd__[1][3]) + (__x_xpd__[2][3] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[1][1]));
				__tmp_coord_array_5__[13] += ((__x_xpd__[2][1] * __y_xpd__[1][3]) + (__x_xpd__[2][4] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[2][5] * __y_xpd__[1][2]));
				__tmp_coord_array_5__[14] += ((-1.0f * __x_xpd__[2][1] * __y_xpd__[1][1]) + (__x_xpd__[2][2] * __y_xpd__[1][0]) + (__x_xpd__[2][0] * __y_xpd__[1][2]));

			}
			if (((y.m_gu & 4) != 0)) {
				__tmp_coord_array_5__[15] += ((__x_xpd__[2][2] * __y_xpd__[2][5]) + (__x_xpd__[2][4] * __y_xpd__[2][0]) + (__x_xpd__[2][5] * __y_xpd__[2][2]) + (__x_xpd__[2][0] * __y_xpd__[2][4]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[2][3]) + (-1.0f * __x_xpd__[2][3] * __y_xpd__[2][1]));

			}

		}
		if (((x.m_gu & 8) != 0)) {
			if (((y.m_gu & 1) != 0)) {
				__tmp_coord_array_5__[11] += (__x_xpd__[3][0] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[12] += (__x_xpd__[3][1] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[13] += (__x_xpd__[3][2] * __y_xpd__[0][0]);
				__tmp_coord_array_5__[14] += (__x_xpd__[3][3] * __y_xpd__[0][0]);

			}
			if (((y.m_gu & 2) != 0)) {
				__tmp_coord_array_5__[15] += ((-1.0f * __x_xpd__[3][0] * __y_xpd__[1][0]) + (__x_xpd__[3][2] * __y_xpd__[1][1]) + (__x_xpd__[3][3] * __y_xpd__[1][3]) + (-1.0f * __x_xpd__[3][1] * __y_xpd__[1][2]));

			}

		}
		if (((x.m_gu & 16) != 0)) {
			if (((y.m_gu & 1) != 0)) {
				__tmp_coord_array_5__[15] += (__x_xpd__[4][0] * __y_xpd__[0][0]);

			}

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_5__);
		return __temp_var_1__;
	}
	mv add(const mv& x, const mv& y) {
		mv __temp_var_1__;
		float __tmp_coord_array_6__[16] ;
		mv_zero(__tmp_coord_array_6__, 16);
		const float* __x_xpd__[5] ;
		x.expand(__x_xpd__, true);
		const float* __y_xpd__[5] ;
		y.expand(__y_xpd__, true);
		if (((y.m_gu & 1) != 0)) {
			__tmp_coord_array_6__[0] += __y_xpd__[0][0];

		}
		if (((y.m_gu & 2) != 0)) {
			__tmp_coord_array_6__[1] += __y_xpd__[1][0];
			__tmp_coord_array_6__[2] += __y_xpd__[1][1];
			__tmp_coord_array_6__[3] += __y_xpd__[1][2];
			__tmp_coord_array_6__[4] += __y_xpd__[1][3];

		}
		if (((y.m_gu & 4) != 0)) {
			__tmp_coord_array_6__[5] += __y_xpd__[2][0];
			__tmp_coord_array_6__[6] += __y_xpd__[2][1];
			__tmp_coord_array_6__[7] += __y_xpd__[2][2];
			__tmp_coord_array_6__[8] += __y_xpd__[2][3];
			__tmp_coord_array_6__[9] += __y_xpd__[2][4];
			__tmp_coord_array_6__[10] += __y_xpd__[2][5];

		}
		if (((y.m_gu & 8) != 0)) {
			__tmp_coord_array_6__[11] += __y_xpd__[3][0];
			__tmp_coord_array_6__[12] += __y_xpd__[3][1];
			__tmp_coord_array_6__[13] += __y_xpd__[3][2];
			__tmp_coord_array_6__[14] += __y_xpd__[3][3];

		}
		if (((y.m_gu & 16) != 0)) {
			__tmp_coord_array_6__[15] += __y_xpd__[4][0];

		}
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_6__[0] += __x_xpd__[0][0];

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_6__[1] += __x_xpd__[1][0];
			__tmp_coord_array_6__[2] += __x_xpd__[1][1];
			__tmp_coord_array_6__[3] += __x_xpd__[1][2];
			__tmp_coord_array_6__[4] += __x_xpd__[1][3];

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_6__[5] += __x_xpd__[2][0];
			__tmp_coord_array_6__[6] += __x_xpd__[2][1];
			__tmp_coord_array_6__[7] += __x_xpd__[2][2];
			__tmp_coord_array_6__[8] += __x_xpd__[2][3];
			__tmp_coord_array_6__[9] += __x_xpd__[2][4];
			__tmp_coord_array_6__[10] += __x_xpd__[2][5];

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_6__[11] += __x_xpd__[3][0];
			__tmp_coord_array_6__[12] += __x_xpd__[3][1];
			__tmp_coord_array_6__[13] += __x_xpd__[3][2];
			__tmp_coord_array_6__[14] += __x_xpd__[3][3];

		}
		if (((x.m_gu & 16) != 0)) {
			__tmp_coord_array_6__[15] += __x_xpd__[4][0];

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_6__);
		return __temp_var_1__;
	}
	mv subtract(const mv& x, const mv& y) {
		mv __temp_var_1__;
		float __tmp_coord_array_7__[16] ;
		mv_zero(__tmp_coord_array_7__, 16);
		const float* __y_xpd__[5] ;
		y.expand(__y_xpd__, true);
		const float* __x_xpd__[5] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_7__[0] += __x_xpd__[0][0];

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_7__[1] += __x_xpd__[1][0];
			__tmp_coord_array_7__[2] += __x_xpd__[1][1];
			__tmp_coord_array_7__[3] += __x_xpd__[1][2];
			__tmp_coord_array_7__[4] += __x_xpd__[1][3];

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_7__[5] += __x_xpd__[2][0];
			__tmp_coord_array_7__[6] += __x_xpd__[2][1];
			__tmp_coord_array_7__[7] += __x_xpd__[2][2];
			__tmp_coord_array_7__[8] += __x_xpd__[2][3];
			__tmp_coord_array_7__[9] += __x_xpd__[2][4];
			__tmp_coord_array_7__[10] += __x_xpd__[2][5];

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_7__[11] += __x_xpd__[3][0];
			__tmp_coord_array_7__[12] += __x_xpd__[3][1];
			__tmp_coord_array_7__[13] += __x_xpd__[3][2];
			__tmp_coord_array_7__[14] += __x_xpd__[3][3];

		}
		if (((x.m_gu & 16) != 0)) {
			__tmp_coord_array_7__[15] += __x_xpd__[4][0];

		}
		if (((y.m_gu & 1) != 0)) {
			__tmp_coord_array_7__[0] += (-1.0f * __y_xpd__[0][0]);

		}
		if (((y.m_gu & 2) != 0)) {
			__tmp_coord_array_7__[1] += (-1.0f * __y_xpd__[1][0]);
			__tmp_coord_array_7__[2] += (-1.0f * __y_xpd__[1][1]);
			__tmp_coord_array_7__[3] += (-1.0f * __y_xpd__[1][2]);
			__tmp_coord_array_7__[4] += (-1.0f * __y_xpd__[1][3]);

		}
		if (((y.m_gu & 4) != 0)) {
			__tmp_coord_array_7__[5] += (-1.0f * __y_xpd__[2][0]);
			__tmp_coord_array_7__[6] += (-1.0f * __y_xpd__[2][1]);
			__tmp_coord_array_7__[7] += (-1.0f * __y_xpd__[2][2]);
			__tmp_coord_array_7__[8] += (-1.0f * __y_xpd__[2][3]);
			__tmp_coord_array_7__[9] += (-1.0f * __y_xpd__[2][4]);
			__tmp_coord_array_7__[10] += (-1.0f * __y_xpd__[2][5]);

		}
		if (((y.m_gu & 8) != 0)) {
			__tmp_coord_array_7__[11] += (-1.0f * __y_xpd__[3][0]);
			__tmp_coord_array_7__[12] += (-1.0f * __y_xpd__[3][1]);
			__tmp_coord_array_7__[13] += (-1.0f * __y_xpd__[3][2]);
			__tmp_coord_array_7__[14] += (-1.0f * __y_xpd__[3][3]);

		}
		if (((y.m_gu & 16) != 0)) {
			__tmp_coord_array_7__[15] += (-1.0f * __y_xpd__[4][0]);

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_7__);
		return __temp_var_1__;
	}
	scalar norm_e2(const mv& x) {
		scalar __temp_var_1__;
		const float* __x_xpd__[5] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			__temp_var_1__.m_c[0] += (__x_xpd__[0][0] * __x_xpd__[0][0]);

		}
		if (((x.m_gu & 2) != 0)) {
			__temp_var_1__.m_c[0] += ((__x_xpd__[1][2] * __x_xpd__[1][2]) + (__x_xpd__[1][1] * __x_xpd__[1][1]) + (__x_xpd__[1][3] * __x_xpd__[1][3]) + (__x_xpd__[1][0] * __x_xpd__[1][0]));

		}
		if (((x.m_gu & 4) != 0)) {
			__temp_var_1__.m_c[0] += ((__x_xpd__[2][1] * __x_xpd__[2][1]) + (__x_xpd__[2][0] * __x_xpd__[2][0]) + (__x_xpd__[2][2] * __x_xpd__[2][2]) + (__x_xpd__[2][5] * __x_xpd__[2][5]) + (__x_xpd__[2][4] * __x_xpd__[2][4]) + (__x_xpd__[2][3] * __x_xpd__[2][3]));

		}
		if (((x.m_gu & 8) != 0)) {
			__temp_var_1__.m_c[0] += ((__x_xpd__[3][3] * __x_xpd__[3][3]) + (__x_xpd__[3][1] * __x_xpd__[3][1]) + (__x_xpd__[3][2] * __x_xpd__[3][2]) + (__x_xpd__[3][0] * __x_xpd__[3][0]));

		}
		if (((x.m_gu & 16) != 0)) {
			__temp_var_1__.m_c[0] += (__x_xpd__[4][0] * __x_xpd__[4][0]);

		}
		return __temp_var_1__;
	}
	scalar norm_e(const mv& x) {
		scalar e2;
		const float* __x_xpd__[5] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			e2.m_c[0] += (__x_xpd__[0][0] * __x_xpd__[0][0]);

		}
		if (((x.m_gu & 2) != 0)) {
			e2.m_c[0] += ((__x_xpd__[1][1] * __x_xpd__[1][1]) + (__x_xpd__[1][0] * __x_xpd__[1][0]) + (__x_xpd__[1][2] * __x_xpd__[1][2]) + (__x_xpd__[1][3] * __x_xpd__[1][3]));

		}
		if (((x.m_gu & 4) != 0)) {
			e2.m_c[0] += ((__x_xpd__[2][1] * __x_xpd__[2][1]) + (__x_xpd__[2][2] * __x_xpd__[2][2]) + (__x_xpd__[2][3] * __x_xpd__[2][3]) + (__x_xpd__[2][4] * __x_xpd__[2][4]) + (__x_xpd__[2][5] * __x_xpd__[2][5]) + (__x_xpd__[2][0] * __x_xpd__[2][0]));

		}
		if (((x.m_gu & 8) != 0)) {
			e2.m_c[0] += ((__x_xpd__[3][3] * __x_xpd__[3][3]) + (__x_xpd__[3][1] * __x_xpd__[3][1]) + (__x_xpd__[3][2] * __x_xpd__[3][2]) + (__x_xpd__[3][0] * __x_xpd__[3][0]));

		}
		if (((x.m_gu & 16) != 0)) {
			e2.m_c[0] += (__x_xpd__[4][0] * __x_xpd__[4][0]);

		}
		return scalar(scalar_scalar, sqrt(e2.m_c[0]));
	}
	mv unit_e(const mv& x) {
		scalar e2;
		const float* __x_xpd__[5] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			e2.m_c[0] += (__x_xpd__[0][0] * __x_xpd__[0][0]);

		}
		if (((x.m_gu & 2) != 0)) {
			e2.m_c[0] += ((__x_xpd__[1][3] * __x_xpd__[1][3]) + (__x_xpd__[1][1] * __x_xpd__[1][1]) + (__x_xpd__[1][0] * __x_xpd__[1][0]) + (__x_xpd__[1][2] * __x_xpd__[1][2]));

		}
		if (((x.m_gu & 4) != 0)) {
			e2.m_c[0] += ((__x_xpd__[2][0] * __x_xpd__[2][0]) + (__x_xpd__[2][4] * __x_xpd__[2][4]) + (__x_xpd__[2][2] * __x_xpd__[2][2]) + (__x_xpd__[2][3] * __x_xpd__[2][3]) + (__x_xpd__[2][5] * __x_xpd__[2][5]) + (__x_xpd__[2][1] * __x_xpd__[2][1]));

		}
		if (((x.m_gu & 8) != 0)) {
			e2.m_c[0] += ((__x_xpd__[3][0] * __x_xpd__[3][0]) + (__x_xpd__[3][3] * __x_xpd__[3][3]) + (__x_xpd__[3][2] * __x_xpd__[3][2]) + (__x_xpd__[3][1] * __x_xpd__[3][1]));

		}
		if (((x.m_gu & 16) != 0)) {
			e2.m_c[0] += (__x_xpd__[4][0] * __x_xpd__[4][0]);

		}
		scalar ie;
		ie.m_c[0] = ((char)1 / sqrt(e2.m_c[0]));
		mv __temp_var_1__;
		float __tmp_coord_array_8__[16] ;
		mv_zero(__tmp_coord_array_8__, 16);
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_8__[0] += (__x_xpd__[0][0] * ie.m_c[0]);

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_8__[1] += (__x_xpd__[1][0] * ie.m_c[0]);
			__tmp_coord_array_8__[2] += (__x_xpd__[1][1] * ie.m_c[0]);
			__tmp_coord_array_8__[3] += (__x_xpd__[1][2] * ie.m_c[0]);
			__tmp_coord_array_8__[4] += (__x_xpd__[1][3] * ie.m_c[0]);

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_8__[5] += (__x_xpd__[2][0] * ie.m_c[0]);
			__tmp_coord_array_8__[6] += (__x_xpd__[2][1] * ie.m_c[0]);
			__tmp_coord_array_8__[7] += (__x_xpd__[2][2] * ie.m_c[0]);
			__tmp_coord_array_8__[8] += (__x_xpd__[2][3] * ie.m_c[0]);
			__tmp_coord_array_8__[9] += (__x_xpd__[2][4] * ie.m_c[0]);
			__tmp_coord_array_8__[10] += (__x_xpd__[2][5] * ie.m_c[0]);

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_8__[11] += (__x_xpd__[3][0] * ie.m_c[0]);
			__tmp_coord_array_8__[12] += (__x_xpd__[3][1] * ie.m_c[0]);
			__tmp_coord_array_8__[13] += (__x_xpd__[3][2] * ie.m_c[0]);
			__tmp_coord_array_8__[14] += (__x_xpd__[3][3] * ie.m_c[0]);

		}
		if (((x.m_gu & 16) != 0)) {
			__tmp_coord_array_8__[15] += (__x_xpd__[4][0] * ie.m_c[0]);

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_8__);
		return __temp_var_1__;
	}
	scalar norm_r2(const mv& x) {
		scalar __temp_var_1__;
		const float* __x_xpd__[5] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			__temp_var_1__.m_c[0] += (__x_xpd__[0][0] * __x_xpd__[0][0]);

		}
		if (((x.m_gu & 2) != 0)) {
			__temp_var_1__.m_c[0] += ((-1.0f * __x_xpd__[1][3] * __x_xpd__[1][0]) + (__x_xpd__[1][2] * __x_xpd__[1][2]) + (__x_xpd__[1][1] * __x_xpd__[1][1]) + (-1.0f * __x_xpd__[1][0] * __x_xpd__[1][3]));

		}
		if (((x.m_gu & 4) != 0)) {
			__temp_var_1__.m_c[0] += ((-1.0f * __x_xpd__[2][5] * __x_xpd__[2][5]) + (__x_xpd__[2][3] * __x_xpd__[2][0]) + (__x_xpd__[2][4] * __x_xpd__[2][1]) + (__x_xpd__[2][0] * __x_xpd__[2][3]) + (__x_xpd__[2][1] * __x_xpd__[2][4]) + (__x_xpd__[2][2] * __x_xpd__[2][2]));

		}
		if (((x.m_gu & 8) != 0)) {
			__temp_var_1__.m_c[0] += ((-1.0f * __x_xpd__[3][3] * __x_xpd__[3][0]) + (-1.0f * __x_xpd__[3][2] * __x_xpd__[3][2]) + (-1.0f * __x_xpd__[3][1] * __x_xpd__[3][1]) + (-1.0f * __x_xpd__[3][0] * __x_xpd__[3][3]));

		}
		if (((x.m_gu & 16) != 0)) {
			__temp_var_1__.m_c[0] += (-1.0f * __x_xpd__[4][0] * __x_xpd__[4][0]);

		}
		return __temp_var_1__;
	}
	scalar norm_r(const mv& x) {
		scalar r2;
		const float* __x_xpd__[5] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			r2.m_c[0] += (__x_xpd__[0][0] * __x_xpd__[0][0]);

		}
		if (((x.m_gu & 2) != 0)) {
			r2.m_c[0] += ((-1.0f * __x_xpd__[1][3] * __x_xpd__[1][0]) + (__x_xpd__[1][1] * __x_xpd__[1][1]) + (-1.0f * __x_xpd__[1][0] * __x_xpd__[1][3]) + (__x_xpd__[1][2] * __x_xpd__[1][2]));

		}
		if (((x.m_gu & 4) != 0)) {
			r2.m_c[0] += ((__x_xpd__[2][3] * __x_xpd__[2][0]) + (__x_xpd__[2][4] * __x_xpd__[2][1]) + (-1.0f * __x_xpd__[2][5] * __x_xpd__[2][5]) + (__x_xpd__[2][0] * __x_xpd__[2][3]) + (__x_xpd__[2][2] * __x_xpd__[2][2]) + (__x_xpd__[2][1] * __x_xpd__[2][4]));

		}
		if (((x.m_gu & 8) != 0)) {
			r2.m_c[0] += ((-1.0f * __x_xpd__[3][0] * __x_xpd__[3][3]) + (-1.0f * __x_xpd__[3][1] * __x_xpd__[3][1]) + (-1.0f * __x_xpd__[3][3] * __x_xpd__[3][0]) + (-1.0f * __x_xpd__[3][2] * __x_xpd__[3][2]));

		}
		if (((x.m_gu & 16) != 0)) {
			r2.m_c[0] += (-1.0f * __x_xpd__[4][0] * __x_xpd__[4][0]);

		}
		return scalar(scalar_scalar, ((((r2.m_c[0] < (char)0)) ? (char)-1 : ((((r2.m_c[0] > (char)0)) ? (char)1 : (char)0))) * sqrt((((r2.m_c[0] < (char)0)) ? ((-r2.m_c[0])) : (r2.m_c[0])))));
	}
	mv unit_r(const mv& x) {
		scalar r2;
		const float* __x_xpd__[5] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			r2.m_c[0] += (__x_xpd__[0][0] * __x_xpd__[0][0]);

		}
		if (((x.m_gu & 2) != 0)) {
			r2.m_c[0] += ((__x_xpd__[1][1] * __x_xpd__[1][1]) + (-1.0f * __x_xpd__[1][3] * __x_xpd__[1][0]) + (__x_xpd__[1][2] * __x_xpd__[1][2]) + (-1.0f * __x_xpd__[1][0] * __x_xpd__[1][3]));

		}
		if (((x.m_gu & 4) != 0)) {
			r2.m_c[0] += ((-1.0f * __x_xpd__[2][5] * __x_xpd__[2][5]) + (__x_xpd__[2][3] * __x_xpd__[2][0]) + (__x_xpd__[2][1] * __x_xpd__[2][4]) + (__x_xpd__[2][0] * __x_xpd__[2][3]) + (__x_xpd__[2][4] * __x_xpd__[2][1]) + (__x_xpd__[2][2] * __x_xpd__[2][2]));

		}
		if (((x.m_gu & 8) != 0)) {
			r2.m_c[0] += ((-1.0f * __x_xpd__[3][3] * __x_xpd__[3][0]) + (-1.0f * __x_xpd__[3][2] * __x_xpd__[3][2]) + (-1.0f * __x_xpd__[3][1] * __x_xpd__[3][1]) + (-1.0f * __x_xpd__[3][0] * __x_xpd__[3][3]));

		}
		if (((x.m_gu & 16) != 0)) {
			r2.m_c[0] += (-1.0f * __x_xpd__[4][0] * __x_xpd__[4][0]);

		}
		scalar ir;
		ir.m_c[0] = ((char)1 / sqrt((((r2.m_c[0] < (char)0)) ? ((-r2.m_c[0])) : (r2.m_c[0]))));
		mv __temp_var_1__;
		float __tmp_coord_array_9__[16] ;
		mv_zero(__tmp_coord_array_9__, 16);
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_9__[0] += (__x_xpd__[0][0] * ir.m_c[0]);

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_9__[1] += (__x_xpd__[1][0] * ir.m_c[0]);
			__tmp_coord_array_9__[2] += (__x_xpd__[1][1] * ir.m_c[0]);
			__tmp_coord_array_9__[3] += (__x_xpd__[1][2] * ir.m_c[0]);
			__tmp_coord_array_9__[4] += (__x_xpd__[1][3] * ir.m_c[0]);

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_9__[5] += (__x_xpd__[2][0] * ir.m_c[0]);
			__tmp_coord_array_9__[6] += (__x_xpd__[2][1] * ir.m_c[0]);
			__tmp_coord_array_9__[7] += (__x_xpd__[2][2] * ir.m_c[0]);
			__tmp_coord_array_9__[8] += (__x_xpd__[2][3] * ir.m_c[0]);
			__tmp_coord_array_9__[9] += (__x_xpd__[2][4] * ir.m_c[0]);
			__tmp_coord_array_9__[10] += (__x_xpd__[2][5] * ir.m_c[0]);

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_9__[11] += (__x_xpd__[3][0] * ir.m_c[0]);
			__tmp_coord_array_9__[12] += (__x_xpd__[3][1] * ir.m_c[0]);
			__tmp_coord_array_9__[13] += (__x_xpd__[3][2] * ir.m_c[0]);
			__tmp_coord_array_9__[14] += (__x_xpd__[3][3] * ir.m_c[0]);

		}
		if (((x.m_gu & 16) != 0)) {
			__tmp_coord_array_9__[15] += (__x_xpd__[4][0] * ir.m_c[0]);

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_9__);
		return __temp_var_1__;
	}
	mv reverse(const mv& x) {
		mv __temp_var_1__;
		float __tmp_coord_array_10__[16] ;
		mv_zero(__tmp_coord_array_10__, 16);
		const float* __x_xpd__[5] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_10__[0] += __x_xpd__[0][0];

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_10__[1] += __x_xpd__[1][0];
			__tmp_coord_array_10__[2] += __x_xpd__[1][1];
			__tmp_coord_array_10__[3] += __x_xpd__[1][2];
			__tmp_coord_array_10__[4] += __x_xpd__[1][3];

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_10__[5] += (-1.0f * __x_xpd__[2][0]);
			__tmp_coord_array_10__[6] += (-1.0f * __x_xpd__[2][1]);
			__tmp_coord_array_10__[7] += (-1.0f * __x_xpd__[2][2]);
			__tmp_coord_array_10__[8] += (-1.0f * __x_xpd__[2][3]);
			__tmp_coord_array_10__[9] += (-1.0f * __x_xpd__[2][4]);
			__tmp_coord_array_10__[10] += (-1.0f * __x_xpd__[2][5]);

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_10__[11] += (-1.0f * __x_xpd__[3][0]);
			__tmp_coord_array_10__[12] += (-1.0f * __x_xpd__[3][1]);
			__tmp_coord_array_10__[13] += (-1.0f * __x_xpd__[3][2]);
			__tmp_coord_array_10__[14] += (-1.0f * __x_xpd__[3][3]);

		}
		if (((x.m_gu & 16) != 0)) {
			__tmp_coord_array_10__[15] += __x_xpd__[4][0];

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_10__);
		return __temp_var_1__;
	}
	mv negate(const mv& x) {
		mv __temp_var_1__;
		float __tmp_coord_array_11__[16] ;
		mv_zero(__tmp_coord_array_11__, 16);
		const float* __x_xpd__[5] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_11__[0] += (-1.0f * __x_xpd__[0][0]);

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_11__[1] += (-1.0f * __x_xpd__[1][0]);
			__tmp_coord_array_11__[2] += (-1.0f * __x_xpd__[1][1]);
			__tmp_coord_array_11__[3] += (-1.0f * __x_xpd__[1][2]);
			__tmp_coord_array_11__[4] += (-1.0f * __x_xpd__[1][3]);

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_11__[5] += (-1.0f * __x_xpd__[2][0]);
			__tmp_coord_array_11__[6] += (-1.0f * __x_xpd__[2][1]);
			__tmp_coord_array_11__[7] += (-1.0f * __x_xpd__[2][2]);
			__tmp_coord_array_11__[8] += (-1.0f * __x_xpd__[2][3]);
			__tmp_coord_array_11__[9] += (-1.0f * __x_xpd__[2][4]);
			__tmp_coord_array_11__[10] += (-1.0f * __x_xpd__[2][5]);

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_11__[11] += (-1.0f * __x_xpd__[3][0]);
			__tmp_coord_array_11__[12] += (-1.0f * __x_xpd__[3][1]);
			__tmp_coord_array_11__[13] += (-1.0f * __x_xpd__[3][2]);
			__tmp_coord_array_11__[14] += (-1.0f * __x_xpd__[3][3]);

		}
		if (((x.m_gu & 16) != 0)) {
			__tmp_coord_array_11__[15] += (-1.0f * __x_xpd__[4][0]);

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_11__);
		return __temp_var_1__;
	}
	mv dual(const mv& x) {
		mv __temp_var_1__;
		float __tmp_coord_array_12__[16] ;
		mv_zero(__tmp_coord_array_12__, 16);
		const float* __x_xpd__[5] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_12__[15] += (-1.0f * __x_xpd__[0][0]);

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_12__[11] += __x_xpd__[1][3];
			__tmp_coord_array_12__[12] += (-1.0f * __x_xpd__[1][2]);
			__tmp_coord_array_12__[13] += __x_xpd__[1][1];
			__tmp_coord_array_12__[14] += (-1.0f * __x_xpd__[1][0]);

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_12__[5] += __x_xpd__[2][1];
			__tmp_coord_array_12__[6] += (-1.0f * __x_xpd__[2][0]);
			__tmp_coord_array_12__[7] += (-1.0f * __x_xpd__[2][5]);
			__tmp_coord_array_12__[8] += (-1.0f * __x_xpd__[2][4]);
			__tmp_coord_array_12__[9] += __x_xpd__[2][3];
			__tmp_coord_array_12__[10] += __x_xpd__[2][2];

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_12__[1] += __x_xpd__[3][3];
			__tmp_coord_array_12__[2] += (-1.0f * __x_xpd__[3][2]);
			__tmp_coord_array_12__[3] += __x_xpd__[3][1];
			__tmp_coord_array_12__[4] += (-1.0f * __x_xpd__[3][0]);

		}
		if (((x.m_gu & 16) != 0)) {
			__tmp_coord_array_12__[0] += __x_xpd__[4][0];

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_12__);
		return __temp_var_1__;
	}
	mv undual(const mv& x) {
		mv __temp_var_1__;
		float __tmp_coord_array_13__[16] ;
		mv_zero(__tmp_coord_array_13__, 16);
		const float* __x_xpd__[5] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_13__[15] += __x_xpd__[0][0];

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_13__[11] += (-1.0f * __x_xpd__[1][3]);
			__tmp_coord_array_13__[12] += __x_xpd__[1][2];
			__tmp_coord_array_13__[13] += (-1.0f * __x_xpd__[1][1]);
			__tmp_coord_array_13__[14] += __x_xpd__[1][0];

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_13__[5] += (-1.0f * __x_xpd__[2][1]);
			__tmp_coord_array_13__[6] += __x_xpd__[2][0];
			__tmp_coord_array_13__[7] += __x_xpd__[2][5];
			__tmp_coord_array_13__[8] += __x_xpd__[2][4];
			__tmp_coord_array_13__[9] += (-1.0f * __x_xpd__[2][3]);
			__tmp_coord_array_13__[10] += (-1.0f * __x_xpd__[2][2]);

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_13__[1] += (-1.0f * __x_xpd__[3][3]);
			__tmp_coord_array_13__[2] += __x_xpd__[3][2];
			__tmp_coord_array_13__[3] += (-1.0f * __x_xpd__[3][1]);
			__tmp_coord_array_13__[4] += __x_xpd__[3][0];

		}
		if (((x.m_gu & 16) != 0)) {
			__tmp_coord_array_13__[0] += (-1.0f * __x_xpd__[4][0]);

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_13__);
		return __temp_var_1__;
	}
	mv inverse(const mv& x) {
		scalar n;
		const float* __x_xpd__[5] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			n.m_c[0] += (__x_xpd__[0][0] * __x_xpd__[0][0]);

		}
		if (((x.m_gu & 2) != 0)) {
			n.m_c[0] += ((__x_xpd__[1][2] * __x_xpd__[1][2]) + (-1.0f * __x_xpd__[1][0] * __x_xpd__[1][3]) + (__x_xpd__[1][1] * __x_xpd__[1][1]) + (-1.0f * __x_xpd__[1][3] * __x_xpd__[1][0]));

		}
		if (((x.m_gu & 4) != 0)) {
			n.m_c[0] += ((__x_xpd__[2][0] * __x_xpd__[2][3]) + (__x_xpd__[2][2] * __x_xpd__[2][2]) + (__x_xpd__[2][3] * __x_xpd__[2][0]) + (__x_xpd__[2][4] * __x_xpd__[2][1]) + (__x_xpd__[2][1] * __x_xpd__[2][4]) + (-1.0f * __x_xpd__[2][5] * __x_xpd__[2][5]));

		}
		if (((x.m_gu & 8) != 0)) {
			n.m_c[0] += ((-1.0f * __x_xpd__[3][3] * __x_xpd__[3][0]) + (-1.0f * __x_xpd__[3][0] * __x_xpd__[3][3]) + (-1.0f * __x_xpd__[3][1] * __x_xpd__[3][1]) + (-1.0f * __x_xpd__[3][2] * __x_xpd__[3][2]));

		}
		if (((x.m_gu & 16) != 0)) {
			n.m_c[0] += (-1.0f * __x_xpd__[4][0] * __x_xpd__[4][0]);

		}
		scalar in;
		in.m_c[0] = ((char)1 / n.m_c[0]);
		mv __temp_var_1__;
		float __tmp_coord_array_14__[16] ;
		mv_zero(__tmp_coord_array_14__, 16);
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_14__[0] += (__x_xpd__[0][0] * in.m_c[0]);

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_14__[1] += (__x_xpd__[1][0] * in.m_c[0]);
			__tmp_coord_array_14__[2] += (__x_xpd__[1][1] * in.m_c[0]);
			__tmp_coord_array_14__[3] += (__x_xpd__[1][2] * in.m_c[0]);
			__tmp_coord_array_14__[4] += (__x_xpd__[1][3] * in.m_c[0]);

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_14__[5] += (-1.0f * __x_xpd__[2][0] * in.m_c[0]);
			__tmp_coord_array_14__[6] += (-1.0f * __x_xpd__[2][1] * in.m_c[0]);
			__tmp_coord_array_14__[7] += (-1.0f * __x_xpd__[2][2] * in.m_c[0]);
			__tmp_coord_array_14__[8] += (-1.0f * __x_xpd__[2][3] * in.m_c[0]);
			__tmp_coord_array_14__[9] += (-1.0f * __x_xpd__[2][4] * in.m_c[0]);
			__tmp_coord_array_14__[10] += (-1.0f * __x_xpd__[2][5] * in.m_c[0]);

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_14__[11] += (-1.0f * __x_xpd__[3][0] * in.m_c[0]);
			__tmp_coord_array_14__[12] += (-1.0f * __x_xpd__[3][1] * in.m_c[0]);
			__tmp_coord_array_14__[13] += (-1.0f * __x_xpd__[3][2] * in.m_c[0]);
			__tmp_coord_array_14__[14] += (-1.0f * __x_xpd__[3][3] * in.m_c[0]);

		}
		if (((x.m_gu & 16) != 0)) {
			__tmp_coord_array_14__[15] += (__x_xpd__[4][0] * in.m_c[0]);

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_14__);
		return __temp_var_1__;
	}
	mv inverseEM(const mv& x) {
		scalar n;
		const float* __x_xpd__[5] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			n.m_c[0] += (__x_xpd__[0][0] * __x_xpd__[0][0]);

		}
		if (((x.m_gu & 2) != 0)) {
			n.m_c[0] += ((__x_xpd__[1][2] * __x_xpd__[1][2]) + (__x_xpd__[1][1] * __x_xpd__[1][1]) + (__x_xpd__[1][3] * __x_xpd__[1][3]) + (__x_xpd__[1][0] * __x_xpd__[1][0]));

		}
		if (((x.m_gu & 4) != 0)) {
			n.m_c[0] += ((__x_xpd__[2][3] * __x_xpd__[2][3]) + (__x_xpd__[2][4] * __x_xpd__[2][4]) + (__x_xpd__[2][1] * __x_xpd__[2][1]) + (__x_xpd__[2][2] * __x_xpd__[2][2]) + (__x_xpd__[2][5] * __x_xpd__[2][5]) + (__x_xpd__[2][0] * __x_xpd__[2][0]));

		}
		if (((x.m_gu & 8) != 0)) {
			n.m_c[0] += ((__x_xpd__[3][2] * __x_xpd__[3][2]) + (__x_xpd__[3][3] * __x_xpd__[3][3]) + (__x_xpd__[3][0] * __x_xpd__[3][0]) + (__x_xpd__[3][1] * __x_xpd__[3][1]));

		}
		if (((x.m_gu & 16) != 0)) {
			n.m_c[0] += (__x_xpd__[4][0] * __x_xpd__[4][0]);

		}
		scalar in;
		in.m_c[0] = ((char)1 / n.m_c[0]);
		mv __temp_var_1__;
		float __tmp_coord_array_15__[16] ;
		mv_zero(__tmp_coord_array_15__, 16);
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_15__[0] += (__x_xpd__[0][0] * in.m_c[0]);

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_15__[1] += (__x_xpd__[1][0] * in.m_c[0]);
			__tmp_coord_array_15__[2] += (__x_xpd__[1][1] * in.m_c[0]);
			__tmp_coord_array_15__[3] += (__x_xpd__[1][2] * in.m_c[0]);
			__tmp_coord_array_15__[4] += (__x_xpd__[1][3] * in.m_c[0]);

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_15__[5] += (-1.0f * __x_xpd__[2][0] * in.m_c[0]);
			__tmp_coord_array_15__[6] += (-1.0f * __x_xpd__[2][1] * in.m_c[0]);
			__tmp_coord_array_15__[7] += (-1.0f * __x_xpd__[2][2] * in.m_c[0]);
			__tmp_coord_array_15__[8] += (-1.0f * __x_xpd__[2][3] * in.m_c[0]);
			__tmp_coord_array_15__[9] += (-1.0f * __x_xpd__[2][4] * in.m_c[0]);
			__tmp_coord_array_15__[10] += (-1.0f * __x_xpd__[2][5] * in.m_c[0]);

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_15__[11] += (-1.0f * __x_xpd__[3][0] * in.m_c[0]);
			__tmp_coord_array_15__[12] += (-1.0f * __x_xpd__[3][1] * in.m_c[0]);
			__tmp_coord_array_15__[13] += (-1.0f * __x_xpd__[3][2] * in.m_c[0]);
			__tmp_coord_array_15__[14] += (-1.0f * __x_xpd__[3][3] * in.m_c[0]);

		}
		if (((x.m_gu & 16) != 0)) {
			__tmp_coord_array_15__[15] += (__x_xpd__[4][0] * in.m_c[0]);

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_15__);
		return __temp_var_1__;
	}
	mv gradeInvolution(const mv& x) {
		mv __temp_var_1__;
		float __tmp_coord_array_16__[16] ;
		mv_zero(__tmp_coord_array_16__, 16);
		const float* __x_xpd__[5] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_16__[0] += __x_xpd__[0][0];

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_16__[1] += (-1.0f * __x_xpd__[1][0]);
			__tmp_coord_array_16__[2] += (-1.0f * __x_xpd__[1][1]);
			__tmp_coord_array_16__[3] += (-1.0f * __x_xpd__[1][2]);
			__tmp_coord_array_16__[4] += (-1.0f * __x_xpd__[1][3]);

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_16__[5] += __x_xpd__[2][0];
			__tmp_coord_array_16__[6] += __x_xpd__[2][1];
			__tmp_coord_array_16__[7] += __x_xpd__[2][2];
			__tmp_coord_array_16__[8] += __x_xpd__[2][3];
			__tmp_coord_array_16__[9] += __x_xpd__[2][4];
			__tmp_coord_array_16__[10] += __x_xpd__[2][5];

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_16__[11] += (-1.0f * __x_xpd__[3][0]);
			__tmp_coord_array_16__[12] += (-1.0f * __x_xpd__[3][1]);
			__tmp_coord_array_16__[13] += (-1.0f * __x_xpd__[3][2]);
			__tmp_coord_array_16__[14] += (-1.0f * __x_xpd__[3][3]);

		}
		if (((x.m_gu & 16) != 0)) {
			__tmp_coord_array_16__[15] += __x_xpd__[4][0];

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_16__);
		return __temp_var_1__;
	}

	// G2 functions:
	mv apply_om(const om& x, const mv& y) {
		mv __temp_var_1__;
		float __tmp_coord_array_17__[16] ;
		mv_zero(__tmp_coord_array_17__, 16);
		const float* __y_xpd__[5] ;
		y.expand(__y_xpd__, true);
		if (((y.m_gu & 2) != 0)) {
			__tmp_coord_array_17__[1] += ((x.m_c[1] * __y_xpd__[1][1]) + (x.m_c[0] * __y_xpd__[1][0]) + (x.m_c[3] * __y_xpd__[1][3]) + (x.m_c[2] * __y_xpd__[1][2]));
			__tmp_coord_array_17__[2] += ((x.m_c[4] * __y_xpd__[1][0]) + (x.m_c[6] * __y_xpd__[1][2]) + (x.m_c[7] * __y_xpd__[1][3]) + (x.m_c[5] * __y_xpd__[1][1]));
			__tmp_coord_array_17__[3] += ((x.m_c[8] * __y_xpd__[1][0]) + (x.m_c[10] * __y_xpd__[1][2]) + (x.m_c[9] * __y_xpd__[1][1]) + (x.m_c[11] * __y_xpd__[1][3]));
			__tmp_coord_array_17__[4] += ((x.m_c[13] * __y_xpd__[1][1]) + (x.m_c[14] * __y_xpd__[1][2]) + (x.m_c[15] * __y_xpd__[1][3]) + (x.m_c[12] * __y_xpd__[1][0]));

		}
		if (((y.m_gu & 4) != 0)) {
			__tmp_coord_array_17__[5] += ((x.m_c[17] * __y_xpd__[2][1]) + (x.m_c[18] * __y_xpd__[2][2]) + (x.m_c[21] * __y_xpd__[2][5]) + (x.m_c[16] * __y_xpd__[2][0]) + (x.m_c[19] * __y_xpd__[2][3]) + (x.m_c[20] * __y_xpd__[2][4]));
			__tmp_coord_array_17__[6] += ((x.m_c[27] * __y_xpd__[2][5]) + (x.m_c[25] * __y_xpd__[2][3]) + (x.m_c[26] * __y_xpd__[2][4]) + (x.m_c[23] * __y_xpd__[2][1]) + (x.m_c[22] * __y_xpd__[2][0]) + (x.m_c[24] * __y_xpd__[2][2]));
			__tmp_coord_array_17__[7] += ((x.m_c[32] * __y_xpd__[2][4]) + (x.m_c[29] * __y_xpd__[2][1]) + (x.m_c[33] * __y_xpd__[2][5]) + (x.m_c[30] * __y_xpd__[2][2]) + (x.m_c[31] * __y_xpd__[2][3]) + (x.m_c[28] * __y_xpd__[2][0]));
			__tmp_coord_array_17__[8] += ((x.m_c[35] * __y_xpd__[2][1]) + (x.m_c[38] * __y_xpd__[2][4]) + (x.m_c[36] * __y_xpd__[2][2]) + (x.m_c[34] * __y_xpd__[2][0]) + (x.m_c[37] * __y_xpd__[2][3]) + (x.m_c[39] * __y_xpd__[2][5]));
			__tmp_coord_array_17__[9] += ((x.m_c[42] * __y_xpd__[2][2]) + (x.m_c[43] * __y_xpd__[2][3]) + (x.m_c[40] * __y_xpd__[2][0]) + (x.m_c[44] * __y_xpd__[2][4]) + (x.m_c[45] * __y_xpd__[2][5]) + (x.m_c[41] * __y_xpd__[2][1]));
			__tmp_coord_array_17__[10] += ((x.m_c[50] * __y_xpd__[2][4]) + (x.m_c[47] * __y_xpd__[2][1]) + (x.m_c[51] * __y_xpd__[2][5]) + (x.m_c[48] * __y_xpd__[2][2]) + (x.m_c[49] * __y_xpd__[2][3]) + (x.m_c[46] * __y_xpd__[2][0]));

		}
		if (((y.m_gu & 8) != 0)) {
			__tmp_coord_array_17__[11] += ((x.m_c[55] * __y_xpd__[3][3]) + (x.m_c[53] * __y_xpd__[3][1]) + (x.m_c[52] * __y_xpd__[3][0]) + (x.m_c[54] * __y_xpd__[3][2]));
			__tmp_coord_array_17__[12] += ((x.m_c[56] * __y_xpd__[3][0]) + (x.m_c[58] * __y_xpd__[3][2]) + (x.m_c[57] * __y_xpd__[3][1]) + (x.m_c[59] * __y_xpd__[3][3]));
			__tmp_coord_array_17__[13] += ((x.m_c[63] * __y_xpd__[3][3]) + (x.m_c[62] * __y_xpd__[3][2]) + (x.m_c[61] * __y_xpd__[3][1]) + (x.m_c[60] * __y_xpd__[3][0]));
			__tmp_coord_array_17__[14] += ((x.m_c[65] * __y_xpd__[3][1]) + (x.m_c[66] * __y_xpd__[3][2]) + (x.m_c[67] * __y_xpd__[3][3]) + (x.m_c[64] * __y_xpd__[3][0]));

		}
		if (((y.m_gu & 16) != 0)) {
			__tmp_coord_array_17__[15] += (x.m_c[68] * __y_xpd__[4][0]);

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_17__);
		return __temp_var_1__;
	}
	namespace __G2_GENERATED__ {
		void set(om& __x__, const point& __image_of_no__, const point& __image_of_e1__, const point& __image_of_e2__, const point& __image_of_ni__) {
			__x__.m_c[0] = __image_of_no__.m_c[0];
			__x__.m_c[4] = __image_of_no__.m_c[1];
			__x__.m_c[8] = __image_of_no__.m_c[2];
			__x__.m_c[12] = __image_of_no__.m_c[3];
			__x__.m_c[1] = __image_of_e1__.m_c[0];
			__x__.m_c[5] = __image_of_e1__.m_c[1];
			__x__.m_c[9] = __image_of_e1__.m_c[2];
			__x__.m_c[13] = __image_of_e1__.m_c[3];
			__x__.m_c[2] = __image_of_e2__.m_c[0];
			__x__.m_c[6] = __image_of_e2__.m_c[1];
			__x__.m_c[10] = __image_of_e2__.m_c[2];
			__x__.m_c[14] = __image_of_e2__.m_c[3];
			__x__.m_c[3] = __image_of_ni__.m_c[0];
			__x__.m_c[7] = __image_of_ni__.m_c[1];
			__x__.m_c[11] = __image_of_ni__.m_c[2];
			__x__.m_c[15] = __image_of_ni__.m_c[3];
			__x__.m_c[16] = ((-1.0f * __x__.m_c[1] * __x__.m_c[4]) + (__x__.m_c[5] * __x__.m_c[0]));
			__x__.m_c[22] = ((__x__.m_c[9] * __x__.m_c[0]) + (-1.0f * __x__.m_c[1] * __x__.m_c[8]));
			__x__.m_c[28] = ((__x__.m_c[9] * __x__.m_c[4]) + (-1.0f * __x__.m_c[5] * __x__.m_c[8]));
			__x__.m_c[34] = ((__x__.m_c[13] * __x__.m_c[4]) + (-1.0f * __x__.m_c[5] * __x__.m_c[12]));
			__x__.m_c[40] = ((__x__.m_c[13] * __x__.m_c[8]) + (-1.0f * __x__.m_c[9] * __x__.m_c[12]));
			__x__.m_c[46] = ((__x__.m_c[13] * __x__.m_c[0]) + (-1.0f * __x__.m_c[1] * __x__.m_c[12]));
			__x__.m_c[17] = ((-1.0f * __x__.m_c[2] * __x__.m_c[4]) + (__x__.m_c[6] * __x__.m_c[0]));
			__x__.m_c[23] = ((-1.0f * __x__.m_c[2] * __x__.m_c[8]) + (__x__.m_c[10] * __x__.m_c[0]));
			__x__.m_c[29] = ((-1.0f * __x__.m_c[6] * __x__.m_c[8]) + (__x__.m_c[10] * __x__.m_c[4]));
			__x__.m_c[35] = ((-1.0f * __x__.m_c[6] * __x__.m_c[12]) + (__x__.m_c[14] * __x__.m_c[4]));
			__x__.m_c[41] = ((__x__.m_c[14] * __x__.m_c[8]) + (-1.0f * __x__.m_c[10] * __x__.m_c[12]));
			__x__.m_c[47] = ((__x__.m_c[14] * __x__.m_c[0]) + (-1.0f * __x__.m_c[2] * __x__.m_c[12]));
			__x__.m_c[18] = ((-1.0f * __x__.m_c[2] * __x__.m_c[5]) + (__x__.m_c[6] * __x__.m_c[1]));
			__x__.m_c[24] = ((__x__.m_c[10] * __x__.m_c[1]) + (-1.0f * __x__.m_c[2] * __x__.m_c[9]));
			__x__.m_c[30] = ((-1.0f * __x__.m_c[6] * __x__.m_c[9]) + (__x__.m_c[10] * __x__.m_c[5]));
			__x__.m_c[36] = ((-1.0f * __x__.m_c[6] * __x__.m_c[13]) + (__x__.m_c[14] * __x__.m_c[5]));
			__x__.m_c[42] = ((-1.0f * __x__.m_c[10] * __x__.m_c[13]) + (__x__.m_c[14] * __x__.m_c[9]));
			__x__.m_c[48] = ((-1.0f * __x__.m_c[2] * __x__.m_c[13]) + (__x__.m_c[14] * __x__.m_c[1]));
			__x__.m_c[19] = ((-1.0f * __x__.m_c[3] * __x__.m_c[5]) + (__x__.m_c[7] * __x__.m_c[1]));
			__x__.m_c[25] = ((__x__.m_c[11] * __x__.m_c[1]) + (-1.0f * __x__.m_c[3] * __x__.m_c[9]));
			__x__.m_c[31] = ((__x__.m_c[11] * __x__.m_c[5]) + (-1.0f * __x__.m_c[7] * __x__.m_c[9]));
			__x__.m_c[37] = ((-1.0f * __x__.m_c[7] * __x__.m_c[13]) + (__x__.m_c[15] * __x__.m_c[5]));
			__x__.m_c[43] = ((__x__.m_c[15] * __x__.m_c[9]) + (-1.0f * __x__.m_c[11] * __x__.m_c[13]));
			__x__.m_c[49] = ((-1.0f * __x__.m_c[3] * __x__.m_c[13]) + (__x__.m_c[15] * __x__.m_c[1]));
			__x__.m_c[20] = ((-1.0f * __x__.m_c[3] * __x__.m_c[6]) + (__x__.m_c[7] * __x__.m_c[2]));
			__x__.m_c[26] = ((-1.0f * __x__.m_c[3] * __x__.m_c[10]) + (__x__.m_c[11] * __x__.m_c[2]));
			__x__.m_c[32] = ((-1.0f * __x__.m_c[7] * __x__.m_c[10]) + (__x__.m_c[11] * __x__.m_c[6]));
			__x__.m_c[38] = ((-1.0f * __x__.m_c[7] * __x__.m_c[14]) + (__x__.m_c[15] * __x__.m_c[6]));
			__x__.m_c[44] = ((-1.0f * __x__.m_c[11] * __x__.m_c[14]) + (__x__.m_c[15] * __x__.m_c[10]));
			__x__.m_c[50] = ((-1.0f * __x__.m_c[3] * __x__.m_c[14]) + (__x__.m_c[15] * __x__.m_c[2]));
			__x__.m_c[21] = ((__x__.m_c[7] * __x__.m_c[0]) + (-1.0f * __x__.m_c[3] * __x__.m_c[4]));
			__x__.m_c[27] = ((-1.0f * __x__.m_c[3] * __x__.m_c[8]) + (__x__.m_c[11] * __x__.m_c[0]));
			__x__.m_c[33] = ((__x__.m_c[11] * __x__.m_c[4]) + (-1.0f * __x__.m_c[7] * __x__.m_c[8]));
			__x__.m_c[39] = ((__x__.m_c[15] * __x__.m_c[4]) + (-1.0f * __x__.m_c[7] * __x__.m_c[12]));
			__x__.m_c[45] = ((-1.0f * __x__.m_c[11] * __x__.m_c[12]) + (__x__.m_c[15] * __x__.m_c[8]));
			__x__.m_c[51] = ((-1.0f * __x__.m_c[3] * __x__.m_c[12]) + (__x__.m_c[15] * __x__.m_c[0]));
			__x__.m_c[52] = ((-1.0f * __x__.m_c[38] * __x__.m_c[9]) + (__x__.m_c[32] * __x__.m_c[13]) + (__x__.m_c[44] * __x__.m_c[5]));
			__x__.m_c[56] = ((-1.0f * __x__.m_c[50] * __x__.m_c[5]) + (__x__.m_c[38] * __x__.m_c[1]) + (__x__.m_c[20] * __x__.m_c[13]));
			__x__.m_c[60] = ((__x__.m_c[44] * __x__.m_c[1]) + (-1.0f * __x__.m_c[50] * __x__.m_c[9]) + (__x__.m_c[26] * __x__.m_c[13]));
			__x__.m_c[64] = ((__x__.m_c[20] * __x__.m_c[9]) + (-1.0f * __x__.m_c[26] * __x__.m_c[5]) + (__x__.m_c[32] * __x__.m_c[1]));
			__x__.m_c[53] = ((-1.0f * __x__.m_c[45] * __x__.m_c[5]) + (__x__.m_c[39] * __x__.m_c[9]) + (-1.0f * __x__.m_c[33] * __x__.m_c[13]));
			__x__.m_c[57] = ((-1.0f * __x__.m_c[39] * __x__.m_c[1]) + (-1.0f * __x__.m_c[21] * __x__.m_c[13]) + (__x__.m_c[51] * __x__.m_c[5]));
			__x__.m_c[61] = ((-1.0f * __x__.m_c[27] * __x__.m_c[13]) + (-1.0f * __x__.m_c[45] * __x__.m_c[1]) + (__x__.m_c[51] * __x__.m_c[9]));
			__x__.m_c[65] = ((-1.0f * __x__.m_c[33] * __x__.m_c[1]) + (__x__.m_c[27] * __x__.m_c[5]) + (-1.0f * __x__.m_c[21] * __x__.m_c[9]));
			__x__.m_c[54] = ((-1.0f * __x__.m_c[33] * __x__.m_c[14]) + (__x__.m_c[39] * __x__.m_c[10]) + (-1.0f * __x__.m_c[45] * __x__.m_c[6]));
			__x__.m_c[58] = ((-1.0f * __x__.m_c[39] * __x__.m_c[2]) + (-1.0f * __x__.m_c[21] * __x__.m_c[14]) + (__x__.m_c[51] * __x__.m_c[6]));
			__x__.m_c[62] = ((__x__.m_c[51] * __x__.m_c[10]) + (-1.0f * __x__.m_c[27] * __x__.m_c[14]) + (-1.0f * __x__.m_c[45] * __x__.m_c[2]));
			__x__.m_c[66] = ((-1.0f * __x__.m_c[33] * __x__.m_c[2]) + (-1.0f * __x__.m_c[21] * __x__.m_c[10]) + (__x__.m_c[27] * __x__.m_c[6]));
			__x__.m_c[55] = ((__x__.m_c[42] * __x__.m_c[4]) + (-1.0f * __x__.m_c[36] * __x__.m_c[8]) + (__x__.m_c[30] * __x__.m_c[12]));
			__x__.m_c[59] = ((__x__.m_c[18] * __x__.m_c[12]) + (-1.0f * __x__.m_c[48] * __x__.m_c[4]) + (__x__.m_c[36] * __x__.m_c[0]));
			__x__.m_c[63] = ((-1.0f * __x__.m_c[48] * __x__.m_c[8]) + (__x__.m_c[24] * __x__.m_c[12]) + (__x__.m_c[42] * __x__.m_c[0]));
			__x__.m_c[67] = ((__x__.m_c[18] * __x__.m_c[8]) + (-1.0f * __x__.m_c[24] * __x__.m_c[4]) + (__x__.m_c[30] * __x__.m_c[0]));
			__x__.m_c[68] = ((__x__.m_c[67] * __x__.m_c[15]) + (-1.0f * __x__.m_c[59] * __x__.m_c[11]) + (-1.0f * __x__.m_c[55] * __x__.m_c[3]) + (__x__.m_c[63] * __x__.m_c[7]));
		}
	} /* end of namespace __G2_GENERATED__ */


	// algebra / user constants:
	__I2_ct__ I2;
	__e1ni_ct__ e1ni;
	__no_ct__ no;
	__I4_ct__ I4;
	__e2ni_ct__ e2ni;
	__noni_ct__ noni;
	__I4i_ct__ I4i;
	__ni_ct__ ni;
	__e1_ct__ e1;
	__e2_ct__ e2;

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
		for (i = 0; i <= 4; i++) {
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
		for (i = 0; i <= 4; i++) {
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
		float cc[16];
		int cgu;
		compress(c, cc, cgu, epsilon, gu);
		return mv(cgu, cc);
	}

	mv compress(const mv & arg1, float epsilon /*= 0.0*/) {
		return mv_compress(arg1.m_c, epsilon, arg1.m_gu);
	}

	void mv::compress(float epsilon /*= 0.0*/) {
		float cc[16];
		int cgu;
		c2ga::compress(m_c, cc, cgu, epsilon, m_gu);
		set(cgu, cc);
	}

	mv mv_compress(int nbBlades, const unsigned int *bitmaps, const mv::Float *coords) {	
		// convert basis blade compression to regular coordinate array:
		mv::Float A[16];
		mv_zero(A, 16);

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
			c += 4;
		}
		else ptrs[1] = null;	
		if (m_gu & 4) {
			ptrs[2] =  c;
			c += 6;
		}
		else ptrs[2] = null;	
		if (m_gu & 8) {
			ptrs[3] =  c;
			c += 4;
		}
		else ptrs[3] = null;	
		if (m_gu & 16) {
			ptrs[4] =  c;
			c += 1;
		}
		else ptrs[4] = null;	
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










} // end of namespace c2ga
// post_cpp_include

