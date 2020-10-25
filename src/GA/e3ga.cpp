
// Generated on 2007-08-08 10:15:15 by G2 0.1 from 'E:\gasandbox\ga_sandbox\libgasandbox\e3ga.gs2'

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
#include "e3ga.h"

	// pre_cpp_include


	namespace e3ga {

	// The dimension of the space:
	const int mv_spaceDim = 3;

	// Is the metric of the space Euclidean?
	const bool mv_metricEuclidean = true;


	// This array can be used to lookup the number of coordinates for a grade part of a general multivector
	const int mv_gradeSize[4] = {
		1, 3, 3, 1 
	};

	// This array can be used to lookup the number of coordinates based on a grade usage bitmap
	const int mv_size[16] = {
		0, 1, 3, 4, 3, 4, 6, 7, 1, 2, 4, 5, 4, 5, 7, 8 
	};

	// This array of ASCIIZ strings contains the names of the basis vectors
	const char *mv_basisVectorNames[3] = {
		"e1", "e2", "e3" 
	};

	// This array of integers contains the order of basis elements in the general multivector
	const int mv_basisElements[8][4] = {
		{-1}
		, {0, -1}
		, {1, -1}
		, {2, -1}
		, {0, 1, -1}
		, {1, 2, -1}
		, {0, 2, -1}
		, {0, 1, 2, -1}
	};

	// This array of integers contains the 'sign' (even/odd permutation of the canonical order) of basis elements in the general multivector
	// Use it to answer 'what is the permutation of the coordinate at index [x]'?
	const double mv_basisElementSignByIndex[8] = {
		1.0, 1.0, 1.0, 1.0, 1.0, 1.0, -1.0, 1.0 
	};


	// This array of integers contains the 'sign' (even/odd permutation of canonical order) of basis elements in the general multivector
	// Use it to answer 'what is the permutation of the coordinate of bitmap [x]'?
	const double mv_basisElementSignByBitmap[8] = {
		1.0, 1.0, 1.0, 1.0, 1.0, -1.0, 1.0, 1.0 
	};


	// This array of integers contains the order of basis elements in the general multivector
	// Use it to answer: 'at what index do I find basis element [x] (x = basis vector bitmap)?
	const int mv_basisElementIndexByBitmap[8] = {
		0, 1, 2, 4, 3, 6, 5, 7 
	};

	// This array of integers contains the indices of basis elements in the general multivector
	// Use it to answer: 'what basis element do I find at index [x]'?
	const int mv_basisElementBitmapByIndex[8] = {
		0, 1, 2, 4, 3, 6, 5, 7 
	};


	// This array of grade of each basis elements in the general multivector
	// Use it to answer: 'what is the grade of basis element bitmap [x]'?
	extern const int mv_basisElementGradeByBitmap[8] = {
		0, 1, 1, 2, 1, 2, 2, 3 
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
		void save(const char *filename /*= "E:\\gasandbox\\ga_sandbox\\libgasandbox\\e3ga.gp2"*/, bool append /*= false*/) {
		}
		void init(const char *filename /*= "E:\\gasandbox\\ga_sandbox\\libgasandbox\\e3ga.gp2"*/,
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



	// set to e1_t 
	void mv::set(const e1_t & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;


	}
	// set to e2_t 
	void mv::set(const e2_t & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)0;
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = (Float)0;


	}
	// set to e3_t 
	void mv::set(const e3_t & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = arg1.m_c[0] ;


	}
	// set to scalar 
	void mv::set(const scalar & arg1) {

		// set grade usage 
		gu(1);


		m_c[0] = arg1.m_c[0] ;


	}
	// set to vector2D 
	void mv::set(const vector2D & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = (Float)0;


	}
	// set to vector 
	void mv::set(const vector & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;


	}
	// set to bivector 
	void mv::set(const bivector & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;


	}
	// set to trivector 
	void mv::set(const trivector & arg1) {

		// set grade usage 
		gu(8);


		m_c[0] = arg1.m_c[0] ;


	}
	// set to rotor 
	void mv::set(const rotor & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[3] ;


	}
	// set to __e1_ct__ 
	void mv::set(const __e1_ct__ & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)1.0f; 
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;


	}
	// set to __e2_ct__ 
	void mv::set(const __e2_ct__ & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)0;
		m_c[1] = (Float)1.0f; 
		m_c[2] = (Float)0;


	}
	// set to __e3_ct__ 
	void mv::set(const __e3_ct__ & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)1.0f; 


	}
	// set to __I3_ct__ 
	void mv::set(const __I3_ct__ & arg1) {

		// set grade usage 
		gu(8);


		m_c[0] = (Float)1.0f; 


	}
	// set to __I3i_ct__ 
	void mv::set(const __I3i_ct__ & arg1) {

		// set grade usage 
		gu(8);


		m_c[0] = (Float)-1.0f; 


	}
	// set to __syn_smv___e1_e2_e3_e1e2e3 
	void mv::set(const __syn_smv___e1_e2_e3_e1e2e3 & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[3] ;


	}
	// set to __syn_smv___e1e2f1_0 
	void mv::set(const __syn_smv___e1e2f1_0 & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)1.0f; 
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;


	}
	// set to __syn_smv___e1e2 
	void mv::set(const __syn_smv___e1e2 & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;


	}
	// set to __syn_smv___scalar_e1e2 
	void mv::set(const __syn_smv___scalar_e1e2 & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = (Float)0;
		m_c[3] = (Float)0;


	}
	// set to __syn_smv___e3f_1_0 
	void mv::set(const __syn_smv___e3f_1_0 & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)-1.0f; 


	}
	// set to __syn_smv___e1e3_e2e3 
	void mv::set(const __syn_smv___e1e3_e2e3 & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[0] * (Float)-1.0;


	}
	// set to __syn_smv___scalar_e1e3_e2e3 
	void mv::set(const __syn_smv___scalar_e1e3_e2e3 & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[1] * (Float)-1.0;


	}
	// set to __syn_smv___e1e2_e1e3_e2e3_e1e2e3 
	void mv::set(const __syn_smv___e1e2_e1e3_e2e3_e1e2e3 & arg1) {

		// set grade usage 
		gu(12);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[2] ;
		m_c[2] = arg1.m_c[1] * (Float)-1.0;
		m_c[3] = arg1.m_c[3] ;


	}
	// set to __syn_smv___e1e3f_1_0 
	void mv::set(const __syn_smv___e1e3f_1_0 & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = (Float)1.0f; 


	}
	// set to __syn_smv___e1e3 
	void mv::set(const __syn_smv___e1e3 & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)0;
		m_c[2] = arg1.m_c[0] * (Float)-1.0;


	}
	// set to __syn_smv___scalar_e1e3 
	void mv::set(const __syn_smv___scalar_e1e3 & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[1] * (Float)-1.0;


	}
	// set to __syn_smv___e2e3f1_0 
	void mv::set(const __syn_smv___e2e3f1_0 & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = (Float)1.0f; 
		m_c[2] = (Float)0;


	}
	// set to __syn_smv___e2e3 
	void mv::set(const __syn_smv___e2e3 & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = (Float)0;
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = (Float)0;


	}
	// set to __syn_smv___scalar_e2e3 
	void mv::set(const __syn_smv___scalar_e2e3 & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = (Float)0;


	}
	// set to __syn_smv___e2_e3 
	void mv::set(const __syn_smv___e2_e3 & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)0;
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = arg1.m_c[1] ;


	}
	// set to __syn_smv___e1_e3 
	void mv::set(const __syn_smv___e1_e3 & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = arg1.m_c[1] ;


	}
	// set to __syn_smv___e2_e3_e1e2e3 
	void mv::set(const __syn_smv___e2_e3_e1e2e3 & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = (Float)0;
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = arg1.m_c[2] ;


	}
	// set to __syn_smv___e1_e3_e1e2e3 
	void mv::set(const __syn_smv___e1_e3_e1e2e3 & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = arg1.m_c[1] ;
		m_c[3] = arg1.m_c[2] ;


	}
	// set to __syn_smv___e1_e2_e1e2e3 
	void mv::set(const __syn_smv___e1_e2_e1e2e3 & arg1) {

		// set grade usage 
		gu(10);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[2] ;


	}
	// set to __syn_smv___scalar_e1e2_e1e3 
	void mv::set(const __syn_smv___scalar_e1e2_e1e3 & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = (Float)0;
		m_c[3] = arg1.m_c[2] * (Float)-1.0;


	}
	// set to __syn_smv___scalar_e1e2_e2e3 
	void mv::set(const __syn_smv___scalar_e1e2_e2e3 & arg1) {

		// set grade usage 
		gu(5);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = (Float)0;


	}
	// set to __syn_smv___e2f_1_0 
	void mv::set(const __syn_smv___e2f_1_0 & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)0;
		m_c[1] = (Float)-1.0f; 
		m_c[2] = (Float)0;


	}
	// set to __syn_smv___e1e2_e1e3 
	void mv::set(const __syn_smv___e1e2_e1e3 & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = arg1.m_c[1] * (Float)-1.0;


	}
	// set to __syn_smv___e1e2_e2e3 
	void mv::set(const __syn_smv___e1e2_e2e3 & arg1) {

		// set grade usage 
		gu(4);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = (Float)0;


	}
	// set to __syn_smv___e1f1_0_e2f1_0 
	void mv::set(const __syn_smv___e1f1_0_e2f1_0 & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)1.0f; 
		m_c[1] = (Float)1.0f; 
		m_c[2] = (Float)0;


	}
	// set to __syn_smv___e1f1_0_e2f1_0_e3f1_0 
	void mv::set(const __syn_smv___e1f1_0_e2f1_0_e3f1_0 & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)1.0f; 
		m_c[1] = (Float)1.0f; 
		m_c[2] = (Float)1.0f; 


	}
	// set to __syn_smv___e2_e1f1_0 
	void mv::set(const __syn_smv___e2_e1f1_0 & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = (Float)1.0f; 
		m_c[1] = arg1.m_c[0] ;
		m_c[2] = (Float)0;


	}
	// set to __syn_smv___scalar_e1_e2_e3_e1e2e3 
	void mv::set(const __syn_smv___scalar_e1_e2_e3_e1e2e3 & arg1) {

		// set grade usage 
		gu(11);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = arg1.m_c[1] ;
		m_c[2] = arg1.m_c[2] ;
		m_c[3] = arg1.m_c[3] ;
		m_c[4] = arg1.m_c[4] ;


	}
	// set to __syn_smv___e1_e3f1_0 
	void mv::set(const __syn_smv___e1_e3f1_0 & arg1) {

		// set grade usage 
		gu(2);


		m_c[0] = arg1.m_c[0] ;
		m_c[1] = (Float)0;
		m_c[2] = (Float)1.0f; 


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
	// assign scalar 
	mv& mv::operator=(const scalar& arg1) {
		set(arg1);
		return *this;
	}
	// assign vector2D 
	mv& mv::operator=(const vector2D& arg1) {
		set(arg1);
		return *this;
	}
	// assign vector 
	mv& mv::operator=(const vector& arg1) {
		set(arg1);
		return *this;
	}
	// assign bivector 
	mv& mv::operator=(const bivector& arg1) {
		set(arg1);
		return *this;
	}
	// assign trivector 
	mv& mv::operator=(const trivector& arg1) {
		set(arg1);
		return *this;
	}
	// assign rotor 
	mv& mv::operator=(const rotor& arg1) {
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
	// assign __I3_ct__ 
	mv& mv::operator=(const __I3_ct__& arg1) {
		set(arg1);
		return *this;
	}
	// assign __I3i_ct__ 
	mv& mv::operator=(const __I3i_ct__& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1_e2_e3_e1e2e3 
	mv& mv::operator=(const __syn_smv___e1_e2_e3_e1e2e3& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1e2f1_0 
	mv& mv::operator=(const __syn_smv___e1e2f1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1e2 
	mv& mv::operator=(const __syn_smv___e1e2& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_e1e2 
	mv& mv::operator=(const __syn_smv___scalar_e1e2& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e3f_1_0 
	mv& mv::operator=(const __syn_smv___e3f_1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1e3_e2e3 
	mv& mv::operator=(const __syn_smv___e1e3_e2e3& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_e1e3_e2e3 
	mv& mv::operator=(const __syn_smv___scalar_e1e3_e2e3& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1e2_e1e3_e2e3_e1e2e3 
	mv& mv::operator=(const __syn_smv___e1e2_e1e3_e2e3_e1e2e3& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1e3f_1_0 
	mv& mv::operator=(const __syn_smv___e1e3f_1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1e3 
	mv& mv::operator=(const __syn_smv___e1e3& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_e1e3 
	mv& mv::operator=(const __syn_smv___scalar_e1e3& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e2e3f1_0 
	mv& mv::operator=(const __syn_smv___e2e3f1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e2e3 
	mv& mv::operator=(const __syn_smv___e2e3& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_e2e3 
	mv& mv::operator=(const __syn_smv___scalar_e2e3& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e2_e3 
	mv& mv::operator=(const __syn_smv___e2_e3& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1_e3 
	mv& mv::operator=(const __syn_smv___e1_e3& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e2_e3_e1e2e3 
	mv& mv::operator=(const __syn_smv___e2_e3_e1e2e3& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1_e3_e1e2e3 
	mv& mv::operator=(const __syn_smv___e1_e3_e1e2e3& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1_e2_e1e2e3 
	mv& mv::operator=(const __syn_smv___e1_e2_e1e2e3& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_e1e2_e1e3 
	mv& mv::operator=(const __syn_smv___scalar_e1e2_e1e3& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_e1e2_e2e3 
	mv& mv::operator=(const __syn_smv___scalar_e1e2_e2e3& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e2f_1_0 
	mv& mv::operator=(const __syn_smv___e2f_1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1e2_e1e3 
	mv& mv::operator=(const __syn_smv___e1e2_e1e3& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1e2_e2e3 
	mv& mv::operator=(const __syn_smv___e1e2_e2e3& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1f1_0_e2f1_0 
	mv& mv::operator=(const __syn_smv___e1f1_0_e2f1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1f1_0_e2f1_0_e3f1_0 
	mv& mv::operator=(const __syn_smv___e1f1_0_e2f1_0_e3f1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e2_e1f1_0 
	mv& mv::operator=(const __syn_smv___e2_e1f1_0& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___scalar_e1_e2_e3_e1e2e3 
	mv& mv::operator=(const __syn_smv___scalar_e1_e2_e3_e1e2e3& arg1) {
		set(arg1);
		return *this;
	}
	// assign __syn_smv___e1_e3f1_0 
	mv& mv::operator=(const __syn_smv___e1_e3f1_0& arg1) {
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
	void e1_t::set(const mv & arg1) {

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




	float e1_t::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];

		return maxC;
	}

	float e1_t::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		bm = 1;

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
			m_c[0] = arg1.m_c[gidx + 1];
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
		bm = 2;

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
			m_c[0] = arg1.m_c[gidx + 2];
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
		bm = 4;

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
	void vector2D::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
		}


	}




	float vector2D::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float vector2D::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 1;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 2;
		}
		return maxC;
	}




	// set to mv 
	void vector::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 2];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}


	}




	float vector::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float vector::largestBasisBlade(unsigned int &bm) const {

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
		return maxC;
	}




	// set to mv 
	void bivector::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 3;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 2];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}


	}




	float bivector::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float bivector::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 3;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 6;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 5;
		}
		return maxC;
	}




	// set to mv 
	void trivector::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 3;		}
		else {
		}

		if (arg1.gu() & 4) {
			gidx += 3;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[0] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[0] = (Float)0.0;
		}


	}




	float trivector::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];

		return maxC;
	}

	float trivector::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		bm = 7;

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
			gidx += 3;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 0];
			m_c[2] = arg1.m_c[gidx + 1];
			m_c[3] = arg1.m_c[gidx + 2];
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
			bm = 5;
		}
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
		bm = 1;

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
		bm = 2;

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
		bm = 4;

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
		bm = 7;

		return maxC;
	}




	// set to mv 
	void __I3i_ct__::set(const mv & arg1) {



	}




	float __I3i_ct__::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __I3i_ct__::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 7;

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
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			m_c[2] = arg1.m_c[gidx + 2];
			gidx += 3;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 3;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[3] = arg1.m_c[gidx + 0];
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
		bm = 3;

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
			gidx += 3;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 0];
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
		bm = 3;

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
			gidx += 3;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 0];
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
			bm = 3;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e3f_1_0::set(const mv & arg1) {



	}




	float __syn_smv___e3f_1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __syn_smv___e3f_1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 4;

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
			gidx += 3;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 2]* (Float)-1.0;
			m_c[1] = arg1.m_c[gidx + 1];
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
		bm = 5;

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
			gidx += 3;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 2]* (Float)-1.0;
			m_c[2] = arg1.m_c[gidx + 1];
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
			bm = 5;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 6;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1e2_e1e3_e2e3_e1e2e3::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 3;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 2]* (Float)-1.0;
			m_c[2] = arg1.m_c[gidx + 1];
			gidx += 3;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}

		if (arg1.gu() & 8) {
			m_c[3] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[3] = (Float)0.0;
		}


	}




	float __syn_smv___e1e2_e1e3_e2e3_e1e2e3::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1e2_e1e3_e2e3_e1e2e3::largestBasisBlade(unsigned int &bm) const {

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
			bm = 7;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1e3f_1_0::set(const mv & arg1) {



	}




	float __syn_smv___e1e3f_1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __syn_smv___e1e3f_1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 5;

		return maxC;
	}




	// set to mv 
	void __syn_smv___e1e3::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 3;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 2]* (Float)-1.0;
		}
		else {
			m_c[0] = (Float)0.0;
		}


	}




	float __syn_smv___e1e3::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];

		return maxC;
	}

	float __syn_smv___e1e3::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		bm = 5;

		return maxC;
	}




	// set to mv 
	void __syn_smv___scalar_e1e3::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 3;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 2]* (Float)-1.0;
		}
		else {
			m_c[1] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_e1e3::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___scalar_e1e3::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 0;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 5;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e2e3f1_0::set(const mv & arg1) {



	}




	float __syn_smv___e2e3f1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __syn_smv___e2e3f1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 6;

		return maxC;
	}




	// set to mv 
	void __syn_smv___e2e3::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 3;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 1];
		}
		else {
			m_c[0] = (Float)0.0;
		}


	}




	float __syn_smv___e2e3::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];

		return maxC;
	}

	float __syn_smv___e2e3::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		bm = 6;

		return maxC;
	}




	// set to mv 
	void __syn_smv___scalar_e2e3::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 3;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 1];
		}
		else {
			m_c[1] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_e2e3::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___scalar_e2e3::largestBasisBlade(unsigned int &bm) const {

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
	void __syn_smv___e2_e3::set(const mv & arg1) {

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




	float __syn_smv___e2_e3::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e2_e3::largestBasisBlade(unsigned int &bm) const {

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
	void __syn_smv___e1_e3::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 2];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
		}


	}




	float __syn_smv___e1_e3::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1_e3::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 1;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e2_e3_e1e2e3::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 1];
			m_c[1] = arg1.m_c[gidx + 2];
			gidx += 3;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 3;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[2] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[2] = (Float)0.0;
		}


	}




	float __syn_smv___e2_e3_e1e2e3::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e2_e3_e1e2e3::largestBasisBlade(unsigned int &bm) const {

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
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1_e3_e1e2e3::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 2];
			gidx += 3;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 3;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[2] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[2] = (Float)0.0;
		}


	}




	float __syn_smv___e1_e3_e1e2e3::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1_e3_e1e2e3::largestBasisBlade(unsigned int &bm) const {

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
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1_e2_e1e2e3::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
			gidx += 3;		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 3;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[2] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[2] = (Float)0.0;
		}


	}




	float __syn_smv___e1_e2_e1e2e3::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1_e2_e1e2e3::largestBasisBlade(unsigned int &bm) const {

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
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalar_e1e2_e1e3::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 3;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 0];
			m_c[2] = arg1.m_c[gidx + 2]* (Float)-1.0;
		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_e1e2_e1e3::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___scalar_e1e2_e1e3::largestBasisBlade(unsigned int &bm) const {

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
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalar_e1e2_e2e3::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			gidx += 3;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[1] = arg1.m_c[gidx + 0];
			m_c[2] = arg1.m_c[gidx + 1];
		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_e1e2_e2e3::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___scalar_e1e2_e2e3::largestBasisBlade(unsigned int &bm) const {

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
		return maxC;
	}




	// set to mv 
	void __syn_smv___e2f_1_0::set(const mv & arg1) {



	}




	float __syn_smv___e2f_1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __syn_smv___e2f_1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 2;

		return maxC;
	}




	// set to mv 
	void __syn_smv___e1e2_e1e3::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 3;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 2]* (Float)-1.0;
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
		}


	}




	float __syn_smv___e1e2_e1e3::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1e2_e1e3::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 3;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 5;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1e2_e2e3::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			gidx += 1;		}
		else {
		}

		if (arg1.gu() & 2) {
			gidx += 3;		}
		else {
		}

		if (arg1.gu() & 4) {
			m_c[0] = arg1.m_c[gidx + 0];
			m_c[1] = arg1.m_c[gidx + 1];
		}
		else {
			m_c[0] = (Float)0.0;
			m_c[1] = (Float)0.0;
		}


	}




	float __syn_smv___e1e2_e2e3::largestCoordinate() const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1e2_e2e3::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 3;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 6;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1f1_0_e2f1_0::set(const mv & arg1) {



	}




	float __syn_smv___e1f1_0_e2f1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __syn_smv___e1f1_0_e2f1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 2;

		return maxC;
	}




	// set to mv 
	void __syn_smv___e1f1_0_e2f1_0_e3f1_0::set(const mv & arg1) {



	}




	float __syn_smv___e1f1_0_e2f1_0_e3f1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f;

		return maxC;
	}

	float __syn_smv___e1f1_0_e2f1_0_e3f1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f;
		bm = 4;

		return maxC;
	}




	// set to mv 
	void __syn_smv___e2_e1f1_0::set(const mv & arg1) {

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




	float __syn_smv___e2_e1f1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f, C;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e2_e1f1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f, C;
		bm = 1;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) {
			maxC = C;
			bm = 2;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___scalar_e1_e2_e3_e1e2e3::set(const mv & arg1) {

		int gidx = 0;

		if (arg1.gu() & 1) {
			m_c[0] = arg1.m_c[gidx + 0];
			gidx += 1;		}
		else {
			m_c[0] = (Float)0.0;
		}

		if (arg1.gu() & 2) {
			m_c[1] = arg1.m_c[gidx + 0];
			m_c[2] = arg1.m_c[gidx + 1];
			m_c[3] = arg1.m_c[gidx + 2];
			gidx += 3;		}
		else {
			m_c[1] = (Float)0.0;
			m_c[2] = (Float)0.0;
			m_c[3] = (Float)0.0;
		}

		if (arg1.gu() & 4) {
			gidx += 3;		}
		else {
		}

		if (arg1.gu() & 8) {
			m_c[4] = arg1.m_c[gidx + 0];
		}
		else {
			m_c[4] = (Float)0.0;
		}


	}




	float __syn_smv___scalar_e1_e2_e3_e1e2e3::largestCoordinate() const {

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

	float __syn_smv___scalar_e1_e2_e3_e1e2e3::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0], C;
		bm = 0;

		C = (m_c[1] < (Float)0.0) ? -m_c[1] : m_c[1];
		if (C > maxC) {
			maxC = C;
			bm = 1;
		}
		C = (m_c[2] < (Float)0.0) ? -m_c[2] : m_c[2];
		if (C > maxC) {
			maxC = C;
			bm = 2;
		}
		C = (m_c[3] < (Float)0.0) ? -m_c[3] : m_c[3];
		if (C > maxC) {
			maxC = C;
			bm = 4;
		}
		C = (m_c[4] < (Float)0.0) ? -m_c[4] : m_c[4];
		if (C > maxC) {
			maxC = C;
			bm = 7;
		}
		return maxC;
	}




	// set to mv 
	void __syn_smv___e1_e3f1_0::set(const mv & arg1) {

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




	float __syn_smv___e1_e3f1_0::largestCoordinate() const {

		Float maxC = (Float)1.0f, C;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) maxC = C;
		return maxC;
	}

	float __syn_smv___e1_e3f1_0::largestBasisBlade(unsigned int &bm) const {

		Float maxC = (Float)1.0f, C;
		bm = 4;

		C = (m_c[0] < (Float)0.0) ? -m_c[0] : m_c[0];
		if (C > maxC) {
			maxC = C;
			bm = 1;
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
		mv_memcpy(m_c, arg1.m_c, 19);
	}

	// set to scalar
	void om::set(Float scalarVal) {
		e3ga::__G2_GENERATED__::set(*this, vector(vector_e1_e2_e3, scalarVal, (Float)0, (Float)0), vector(vector_e1_e2_e3, (Float)0, scalarVal, (Float)0), vector(vector_e1_e2_e3, (Float)0, (Float)0, scalarVal));
	}

	// set to coordinates 
	void om::set(const Float *coordinates) {
		mv_memcpy(m_c, coordinates, 19);
	}

	// set from basis vectors array
	void om::set(const vector *vectors) {
		e3ga::__G2_GENERATED__::set(*this, vectors[0], vectors[1], vectors[2]);
	}


	// set from basis vectors 
	void om::set(const vector & image_of_e1, const vector & image_of_e2, const vector & image_of_e3) {
		e3ga::__G2_GENERATED__::set(*this, image_of_e1, image_of_e2, image_of_e3);
	}


	// set by coordinates, transpose
	void om::set(const Float *coordinates, bool transpose) {
		if (transpose) {
			m_c[0] = coordinates[0];
			m_c[3] = coordinates[1];
			m_c[6] = coordinates[2];
			m_c[1] = coordinates[3];
			m_c[4] = coordinates[4];
			m_c[7] = coordinates[5];
			m_c[2] = coordinates[6];
			m_c[5] = coordinates[7];
			m_c[8] = coordinates[8];
			m_c[9] = coordinates[9];
			m_c[12] = coordinates[10];
			m_c[15] = coordinates[11];
			m_c[10] = coordinates[12];
			m_c[13] = coordinates[13];
			m_c[16] = coordinates[14];
			m_c[11] = coordinates[15];
			m_c[14] = coordinates[16];
			m_c[17] = coordinates[17];
			m_c[18] = coordinates[18];
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
		float __tmp_coord_array_1__[8] ;
		mv_zero(__tmp_coord_array_1__, 8);
		const float* __y_xpd__[4] ;
		y.expand(__y_xpd__, true);
		const float* __x_xpd__[4] ;
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

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_1__[0] += ((__x_xpd__[1][1] * __y_xpd__[1][1]) + (__x_xpd__[1][0] * __y_xpd__[1][0]) + (__x_xpd__[1][2] * __y_xpd__[1][2]));

			}

		}
		if (((y.m_gu & 4) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_1__[4] += (__y_xpd__[2][0] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[5] += (__y_xpd__[2][1] * __x_xpd__[0][0]);
				__tmp_coord_array_1__[6] += (__y_xpd__[2][2] * __x_xpd__[0][0]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_1__[1] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[2][0]) + (__x_xpd__[1][2] * __y_xpd__[2][2]));
				__tmp_coord_array_1__[2] += ((-1.0f * __x_xpd__[1][2] * __y_xpd__[2][1]) + (__x_xpd__[1][0] * __y_xpd__[2][0]));
				__tmp_coord_array_1__[3] += ((__x_xpd__[1][1] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[1][0] * __y_xpd__[2][2]));

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_1__[0] += ((-1.0f * __x_xpd__[2][2] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[2][0]));

			}

		}
		if (((y.m_gu & 8) != 0)) {
			if (((x.m_gu & 1) != 0)) {
				__tmp_coord_array_1__[7] += (__y_xpd__[3][0] * __x_xpd__[0][0]);

			}
			if (((x.m_gu & 2) != 0)) {
				__tmp_coord_array_1__[4] += (__x_xpd__[1][2] * __y_xpd__[3][0]);
				__tmp_coord_array_1__[5] += (__x_xpd__[1][0] * __y_xpd__[3][0]);
				__tmp_coord_array_1__[6] += (__x_xpd__[1][1] * __y_xpd__[3][0]);

			}
			if (((x.m_gu & 4) != 0)) {
				__tmp_coord_array_1__[1] += (-1.0f * __x_xpd__[2][1] * __y_xpd__[3][0]);
				__tmp_coord_array_1__[2] += (-1.0f * __x_xpd__[2][2] * __y_xpd__[3][0]);
				__tmp_coord_array_1__[3] += (-1.0f * __x_xpd__[2][0] * __y_xpd__[3][0]);

			}
			if (((x.m_gu & 8) != 0)) {
				__tmp_coord_array_1__[0] += (-1.0f * __x_xpd__[3][0] * __y_xpd__[3][0]);

			}

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_1__);
		return __temp_var_1__;
	}
	scalar scp(const mv& x, const mv& y) {
		scalar __temp_var_1__;
		const float* __x_xpd__[4] ;
		x.expand(__x_xpd__, true);
		const float* __y_xpd__[4] ;
		y.expand(__y_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			if (((y.m_gu & 1) != 0)) {
				__temp_var_1__.m_c[0] += (__x_xpd__[0][0] * __y_xpd__[0][0]);

			}

		}
		if (((x.m_gu & 2) != 0)) {
			if (((y.m_gu & 2) != 0)) {
				__temp_var_1__.m_c[0] += ((__x_xpd__[1][1] * __y_xpd__[1][1]) + (__x_xpd__[1][2] * __y_xpd__[1][2]) + (__x_xpd__[1][0] * __y_xpd__[1][0]));

			}

		}
		if (((x.m_gu & 4) != 0)) {
			if (((y.m_gu & 4) != 0)) {
				__temp_var_1__.m_c[0] += ((-1.0f * __x_xpd__[2][2] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[2][1] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[2][0]));

			}

		}
		if (((x.m_gu & 8) != 0)) {
			if (((y.m_gu & 8) != 0)) {
				__temp_var_1__.m_c[0] += (-1.0f * __x_xpd__[3][0] * __y_xpd__[3][0]);

			}

		}
		return __temp_var_1__;
	}
	mv gp(const mv& x, const mv& y) {
		mv __temp_var_1__;
		float __tmp_coord_array_2__[8] ;
		mv_zero(__tmp_coord_array_2__, 8);
		const float* __x_xpd__[4] ;
		x.expand(__x_xpd__, true);
		const float* __y_xpd__[4] ;
		y.expand(__y_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			if (((y.m_gu & 1) != 0)) {
				__tmp_coord_array_2__[0] += (__x_xpd__[0][0] * __y_xpd__[0][0]);

			}
			if (((y.m_gu & 2) != 0)) {
				__tmp_coord_array_2__[1] += (__x_xpd__[0][0] * __y_xpd__[1][0]);
				__tmp_coord_array_2__[2] += (__x_xpd__[0][0] * __y_xpd__[1][1]);
				__tmp_coord_array_2__[3] += (__x_xpd__[0][0] * __y_xpd__[1][2]);

			}
			if (((y.m_gu & 4) != 0)) {
				__tmp_coord_array_2__[4] += (__x_xpd__[0][0] * __y_xpd__[2][0]);
				__tmp_coord_array_2__[5] += (__x_xpd__[0][0] * __y_xpd__[2][1]);
				__tmp_coord_array_2__[6] += (__x_xpd__[0][0] * __y_xpd__[2][2]);

			}
			if (((y.m_gu & 8) != 0)) {
				__tmp_coord_array_2__[7] += (__x_xpd__[0][0] * __y_xpd__[3][0]);

			}

		}
		if (((x.m_gu & 2) != 0)) {
			if (((y.m_gu & 1) != 0)) {
				__tmp_coord_array_2__[1] += (__x_xpd__[1][0] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[2] += (__x_xpd__[1][1] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[3] += (__x_xpd__[1][2] * __y_xpd__[0][0]);

			}
			if (((y.m_gu & 2) != 0)) {
				__tmp_coord_array_2__[0] += ((__x_xpd__[1][2] * __y_xpd__[1][2]) + (__x_xpd__[1][1] * __y_xpd__[1][1]) + (__x_xpd__[1][0] * __y_xpd__[1][0]));
				__tmp_coord_array_2__[4] += ((__x_xpd__[1][0] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[1][1] * __y_xpd__[1][0]));
				__tmp_coord_array_2__[5] += ((__x_xpd__[1][1] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[1][1]));
				__tmp_coord_array_2__[6] += ((__x_xpd__[1][2] * __y_xpd__[1][0]) + (-1.0f * __x_xpd__[1][0] * __y_xpd__[1][2]));

			}
			if (((y.m_gu & 4) != 0)) {
				__tmp_coord_array_2__[1] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[2][0]) + (__x_xpd__[1][2] * __y_xpd__[2][2]));
				__tmp_coord_array_2__[2] += ((-1.0f * __x_xpd__[1][2] * __y_xpd__[2][1]) + (__x_xpd__[1][0] * __y_xpd__[2][0]));
				__tmp_coord_array_2__[3] += ((-1.0f * __x_xpd__[1][0] * __y_xpd__[2][2]) + (__x_xpd__[1][1] * __y_xpd__[2][1]));
				__tmp_coord_array_2__[7] += ((__x_xpd__[1][1] * __y_xpd__[2][2]) + (__x_xpd__[1][0] * __y_xpd__[2][1]) + (__x_xpd__[1][2] * __y_xpd__[2][0]));

			}
			if (((y.m_gu & 8) != 0)) {
				__tmp_coord_array_2__[4] += (__x_xpd__[1][2] * __y_xpd__[3][0]);
				__tmp_coord_array_2__[5] += (__x_xpd__[1][0] * __y_xpd__[3][0]);
				__tmp_coord_array_2__[6] += (__x_xpd__[1][1] * __y_xpd__[3][0]);

			}

		}
		if (((x.m_gu & 4) != 0)) {
			if (((y.m_gu & 1) != 0)) {
				__tmp_coord_array_2__[4] += (__x_xpd__[2][0] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[5] += (__x_xpd__[2][1] * __y_xpd__[0][0]);
				__tmp_coord_array_2__[6] += (__x_xpd__[2][2] * __y_xpd__[0][0]);

			}
			if (((y.m_gu & 2) != 0)) {
				__tmp_coord_array_2__[1] += ((__x_xpd__[2][0] * __y_xpd__[1][1]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[1][2]));
				__tmp_coord_array_2__[2] += ((__x_xpd__[2][1] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[1][0]));
				__tmp_coord_array_2__[3] += ((-1.0f * __x_xpd__[2][1] * __y_xpd__[1][1]) + (__x_xpd__[2][2] * __y_xpd__[1][0]));
				__tmp_coord_array_2__[7] += ((__x_xpd__[2][0] * __y_xpd__[1][2]) + (__x_xpd__[2][1] * __y_xpd__[1][0]) + (__x_xpd__[2][2] * __y_xpd__[1][1]));

			}
			if (((y.m_gu & 4) != 0)) {
				__tmp_coord_array_2__[0] += ((-1.0f * __x_xpd__[2][1] * __y_xpd__[2][1]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[2][0]));
				__tmp_coord_array_2__[4] += ((-1.0f * __x_xpd__[2][1] * __y_xpd__[2][2]) + (__x_xpd__[2][2] * __y_xpd__[2][1]));
				__tmp_coord_array_2__[5] += ((__x_xpd__[2][0] * __y_xpd__[2][2]) + (-1.0f * __x_xpd__[2][2] * __y_xpd__[2][0]));
				__tmp_coord_array_2__[6] += ((__x_xpd__[2][1] * __y_xpd__[2][0]) + (-1.0f * __x_xpd__[2][0] * __y_xpd__[2][1]));

			}
			if (((y.m_gu & 8) != 0)) {
				__tmp_coord_array_2__[1] += (-1.0f * __x_xpd__[2][1] * __y_xpd__[3][0]);
				__tmp_coord_array_2__[2] += (-1.0f * __x_xpd__[2][2] * __y_xpd__[3][0]);
				__tmp_coord_array_2__[3] += (-1.0f * __x_xpd__[2][0] * __y_xpd__[3][0]);

			}

		}
		if (((x.m_gu & 8) != 0)) {
			if (((y.m_gu & 1) != 0)) {
				__tmp_coord_array_2__[7] += (__x_xpd__[3][0] * __y_xpd__[0][0]);

			}
			if (((y.m_gu & 2) != 0)) {
				__tmp_coord_array_2__[4] += (__x_xpd__[3][0] * __y_xpd__[1][2]);
				__tmp_coord_array_2__[5] += (__x_xpd__[3][0] * __y_xpd__[1][0]);
				__tmp_coord_array_2__[6] += (__x_xpd__[3][0] * __y_xpd__[1][1]);

			}
			if (((y.m_gu & 4) != 0)) {
				__tmp_coord_array_2__[1] += (-1.0f * __x_xpd__[3][0] * __y_xpd__[2][1]);
				__tmp_coord_array_2__[2] += (-1.0f * __x_xpd__[3][0] * __y_xpd__[2][2]);
				__tmp_coord_array_2__[3] += (-1.0f * __x_xpd__[3][0] * __y_xpd__[2][0]);

			}
			if (((y.m_gu & 8) != 0)) {
				__tmp_coord_array_2__[0] += (-1.0f * __x_xpd__[3][0] * __y_xpd__[3][0]);

			}

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_2__);
		return __temp_var_1__;
	}
	mv op(const mv& x, const mv& y) {
		mv __temp_var_1__;
		float __tmp_coord_array_3__[8] ;
		mv_zero(__tmp_coord_array_3__, 8);
		const float* __x_xpd__[4] ;
		x.expand(__x_xpd__, true);
		const float* __y_xpd__[4] ;
		y.expand(__y_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			if (((y.m_gu & 1) != 0)) {
				__tmp_coord_array_3__[0] += (__x_xpd__[0][0] * __y_xpd__[0][0]);

			}
			if (((y.m_gu & 2) != 0)) {
				__tmp_coord_array_3__[1] += (__x_xpd__[0][0] * __y_xpd__[1][0]);
				__tmp_coord_array_3__[2] += (__x_xpd__[0][0] * __y_xpd__[1][1]);
				__tmp_coord_array_3__[3] += (__x_xpd__[0][0] * __y_xpd__[1][2]);

			}
			if (((y.m_gu & 4) != 0)) {
				__tmp_coord_array_3__[4] += (__x_xpd__[0][0] * __y_xpd__[2][0]);
				__tmp_coord_array_3__[5] += (__x_xpd__[0][0] * __y_xpd__[2][1]);
				__tmp_coord_array_3__[6] += (__x_xpd__[0][0] * __y_xpd__[2][2]);

			}
			if (((y.m_gu & 8) != 0)) {
				__tmp_coord_array_3__[7] += (__x_xpd__[0][0] * __y_xpd__[3][0]);

			}

		}
		if (((x.m_gu & 2) != 0)) {
			if (((y.m_gu & 1) != 0)) {
				__tmp_coord_array_3__[1] += (__x_xpd__[1][0] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[2] += (__x_xpd__[1][1] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[3] += (__x_xpd__[1][2] * __y_xpd__[0][0]);

			}
			if (((y.m_gu & 2) != 0)) {
				__tmp_coord_array_3__[4] += ((-1.0f * __x_xpd__[1][1] * __y_xpd__[1][0]) + (__x_xpd__[1][0] * __y_xpd__[1][1]));
				__tmp_coord_array_3__[5] += ((__x_xpd__[1][1] * __y_xpd__[1][2]) + (-1.0f * __x_xpd__[1][2] * __y_xpd__[1][1]));
				__tmp_coord_array_3__[6] += ((-1.0f * __x_xpd__[1][0] * __y_xpd__[1][2]) + (__x_xpd__[1][2] * __y_xpd__[1][0]));

			}
			if (((y.m_gu & 4) != 0)) {
				__tmp_coord_array_3__[7] += ((__x_xpd__[1][0] * __y_xpd__[2][1]) + (__x_xpd__[1][2] * __y_xpd__[2][0]) + (__x_xpd__[1][1] * __y_xpd__[2][2]));

			}

		}
		if (((x.m_gu & 4) != 0)) {
			if (((y.m_gu & 1) != 0)) {
				__tmp_coord_array_3__[4] += (__x_xpd__[2][0] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[5] += (__x_xpd__[2][1] * __y_xpd__[0][0]);
				__tmp_coord_array_3__[6] += (__x_xpd__[2][2] * __y_xpd__[0][0]);

			}
			if (((y.m_gu & 2) != 0)) {
				__tmp_coord_array_3__[7] += ((__x_xpd__[2][2] * __y_xpd__[1][1]) + (__x_xpd__[2][0] * __y_xpd__[1][2]) + (__x_xpd__[2][1] * __y_xpd__[1][0]));

			}

		}
		if (((x.m_gu & 8) != 0)) {
			if (((y.m_gu & 1) != 0)) {
				__tmp_coord_array_3__[7] += (__x_xpd__[3][0] * __y_xpd__[0][0]);

			}

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_3__);
		return __temp_var_1__;
	}
	mv add(const mv& x, const mv& y) {
		mv __temp_var_1__;
		float __tmp_coord_array_4__[8] ;
		mv_zero(__tmp_coord_array_4__, 8);
		const float* __x_xpd__[4] ;
		x.expand(__x_xpd__, true);
		const float* __y_xpd__[4] ;
		y.expand(__y_xpd__, true);
		if (((y.m_gu & 1) != 0)) {
			__tmp_coord_array_4__[0] += __y_xpd__[0][0];

		}
		if (((y.m_gu & 2) != 0)) {
			__tmp_coord_array_4__[1] += __y_xpd__[1][0];
			__tmp_coord_array_4__[2] += __y_xpd__[1][1];
			__tmp_coord_array_4__[3] += __y_xpd__[1][2];

		}
		if (((y.m_gu & 4) != 0)) {
			__tmp_coord_array_4__[4] += __y_xpd__[2][0];
			__tmp_coord_array_4__[5] += __y_xpd__[2][1];
			__tmp_coord_array_4__[6] += __y_xpd__[2][2];

		}
		if (((y.m_gu & 8) != 0)) {
			__tmp_coord_array_4__[7] += __y_xpd__[3][0];

		}
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_4__[0] += __x_xpd__[0][0];

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_4__[1] += __x_xpd__[1][0];
			__tmp_coord_array_4__[2] += __x_xpd__[1][1];
			__tmp_coord_array_4__[3] += __x_xpd__[1][2];

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_4__[4] += __x_xpd__[2][0];
			__tmp_coord_array_4__[5] += __x_xpd__[2][1];
			__tmp_coord_array_4__[6] += __x_xpd__[2][2];

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_4__[7] += __x_xpd__[3][0];

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_4__);
		return __temp_var_1__;
	}
	mv subtract(const mv& x, const mv& y) {
		mv __temp_var_1__;
		float __tmp_coord_array_5__[8] ;
		mv_zero(__tmp_coord_array_5__, 8);
		const float* __x_xpd__[4] ;
		x.expand(__x_xpd__, true);
		const float* __y_xpd__[4] ;
		y.expand(__y_xpd__, true);
		if (((y.m_gu & 1) != 0)) {
			__tmp_coord_array_5__[0] += (-1.0f * __y_xpd__[0][0]);

		}
		if (((y.m_gu & 2) != 0)) {
			__tmp_coord_array_5__[1] += (-1.0f * __y_xpd__[1][0]);
			__tmp_coord_array_5__[2] += (-1.0f * __y_xpd__[1][1]);
			__tmp_coord_array_5__[3] += (-1.0f * __y_xpd__[1][2]);

		}
		if (((y.m_gu & 4) != 0)) {
			__tmp_coord_array_5__[4] += (-1.0f * __y_xpd__[2][0]);
			__tmp_coord_array_5__[5] += (-1.0f * __y_xpd__[2][1]);
			__tmp_coord_array_5__[6] += (-1.0f * __y_xpd__[2][2]);

		}
		if (((y.m_gu & 8) != 0)) {
			__tmp_coord_array_5__[7] += (-1.0f * __y_xpd__[3][0]);

		}
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_5__[0] += __x_xpd__[0][0];

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_5__[1] += __x_xpd__[1][0];
			__tmp_coord_array_5__[2] += __x_xpd__[1][1];
			__tmp_coord_array_5__[3] += __x_xpd__[1][2];

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_5__[4] += __x_xpd__[2][0];
			__tmp_coord_array_5__[5] += __x_xpd__[2][1];
			__tmp_coord_array_5__[6] += __x_xpd__[2][2];

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_5__[7] += __x_xpd__[3][0];

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_5__);
		return __temp_var_1__;
	}
	scalar norm_e2(const mv& x) {
		scalar __temp_var_1__;
		const float* __x_xpd__[4] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			__temp_var_1__.m_c[0] += (__x_xpd__[0][0] * __x_xpd__[0][0]);

		}
		if (((x.m_gu & 2) != 0)) {
			__temp_var_1__.m_c[0] += ((__x_xpd__[1][1] * __x_xpd__[1][1]) + (__x_xpd__[1][0] * __x_xpd__[1][0]) + (__x_xpd__[1][2] * __x_xpd__[1][2]));

		}
		if (((x.m_gu & 4) != 0)) {
			__temp_var_1__.m_c[0] += ((__x_xpd__[2][2] * __x_xpd__[2][2]) + (__x_xpd__[2][1] * __x_xpd__[2][1]) + (__x_xpd__[2][0] * __x_xpd__[2][0]));

		}
		if (((x.m_gu & 8) != 0)) {
			__temp_var_1__.m_c[0] += (__x_xpd__[3][0] * __x_xpd__[3][0]);

		}
		return __temp_var_1__;
	}
	scalar norm_e(const mv& x) {
		scalar e2;
		const float* __x_xpd__[4] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			e2.m_c[0] += (__x_xpd__[0][0] * __x_xpd__[0][0]);

		}
		if (((x.m_gu & 2) != 0)) {
			e2.m_c[0] += ((__x_xpd__[1][0] * __x_xpd__[1][0]) + (__x_xpd__[1][2] * __x_xpd__[1][2]) + (__x_xpd__[1][1] * __x_xpd__[1][1]));

		}
		if (((x.m_gu & 4) != 0)) {
			e2.m_c[0] += ((__x_xpd__[2][0] * __x_xpd__[2][0]) + (__x_xpd__[2][1] * __x_xpd__[2][1]) + (__x_xpd__[2][2] * __x_xpd__[2][2]));

		}
		if (((x.m_gu & 8) != 0)) {
			e2.m_c[0] += (__x_xpd__[3][0] * __x_xpd__[3][0]);

		}
		return scalar(scalar_scalar, sqrt(e2.m_c[0]));
	}
	mv unit_e(const mv& x) {
		scalar e2;
		const float* __x_xpd__[4] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			e2.m_c[0] += (__x_xpd__[0][0] * __x_xpd__[0][0]);

		}
		if (((x.m_gu & 2) != 0)) {
			e2.m_c[0] += ((__x_xpd__[1][2] * __x_xpd__[1][2]) + (__x_xpd__[1][1] * __x_xpd__[1][1]) + (__x_xpd__[1][0] * __x_xpd__[1][0]));

		}
		if (((x.m_gu & 4) != 0)) {
			e2.m_c[0] += ((__x_xpd__[2][1] * __x_xpd__[2][1]) + (__x_xpd__[2][0] * __x_xpd__[2][0]) + (__x_xpd__[2][2] * __x_xpd__[2][2]));

		}
		if (((x.m_gu & 8) != 0)) {
			e2.m_c[0] += (__x_xpd__[3][0] * __x_xpd__[3][0]);

		}
		scalar ie;
		ie.m_c[0] = ((char)1 / sqrt(e2.m_c[0]));
		mv __temp_var_1__;
		float __tmp_coord_array_6__[8] ;
		mv_zero(__tmp_coord_array_6__, 8);
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_6__[0] += (__x_xpd__[0][0] * ie.m_c[0]);

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_6__[1] += (__x_xpd__[1][0] * ie.m_c[0]);
			__tmp_coord_array_6__[2] += (__x_xpd__[1][1] * ie.m_c[0]);
			__tmp_coord_array_6__[3] += (__x_xpd__[1][2] * ie.m_c[0]);

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_6__[4] += (__x_xpd__[2][0] * ie.m_c[0]);
			__tmp_coord_array_6__[5] += (__x_xpd__[2][1] * ie.m_c[0]);
			__tmp_coord_array_6__[6] += (__x_xpd__[2][2] * ie.m_c[0]);

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_6__[7] += (__x_xpd__[3][0] * ie.m_c[0]);

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_6__);
		return __temp_var_1__;
	}
	scalar norm_r2(const mv& x) {
		scalar __temp_var_1__;
		const float* __x_xpd__[4] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			__temp_var_1__.m_c[0] += (__x_xpd__[0][0] * __x_xpd__[0][0]);

		}
		if (((x.m_gu & 2) != 0)) {
			__temp_var_1__.m_c[0] += ((__x_xpd__[1][1] * __x_xpd__[1][1]) + (__x_xpd__[1][2] * __x_xpd__[1][2]) + (__x_xpd__[1][0] * __x_xpd__[1][0]));

		}
		if (((x.m_gu & 4) != 0)) {
			__temp_var_1__.m_c[0] += ((__x_xpd__[2][0] * __x_xpd__[2][0]) + (__x_xpd__[2][1] * __x_xpd__[2][1]) + (__x_xpd__[2][2] * __x_xpd__[2][2]));

		}
		if (((x.m_gu & 8) != 0)) {
			__temp_var_1__.m_c[0] += (__x_xpd__[3][0] * __x_xpd__[3][0]);

		}
		return __temp_var_1__;
	}
	scalar norm_r(const mv& x) {
		scalar r2;
		const float* __x_xpd__[4] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			r2.m_c[0] += (__x_xpd__[0][0] * __x_xpd__[0][0]);

		}
		if (((x.m_gu & 2) != 0)) {
			r2.m_c[0] += ((__x_xpd__[1][1] * __x_xpd__[1][1]) + (__x_xpd__[1][0] * __x_xpd__[1][0]) + (__x_xpd__[1][2] * __x_xpd__[1][2]));

		}
		if (((x.m_gu & 4) != 0)) {
			r2.m_c[0] += ((__x_xpd__[2][1] * __x_xpd__[2][1]) + (__x_xpd__[2][0] * __x_xpd__[2][0]) + (__x_xpd__[2][2] * __x_xpd__[2][2]));

		}
		if (((x.m_gu & 8) != 0)) {
			r2.m_c[0] += (__x_xpd__[3][0] * __x_xpd__[3][0]);

		}
		return scalar(scalar_scalar, ((((r2.m_c[0] < (char)0)) ? (char)-1 : ((((r2.m_c[0] > (char)0)) ? (char)1 : (char)0))) * sqrt((((r2.m_c[0] < (char)0)) ? ((-r2.m_c[0])) : (r2.m_c[0])))));
	}
	mv unit_r(const mv& x) {
		scalar r2;
		const float* __x_xpd__[4] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			r2.m_c[0] += (__x_xpd__[0][0] * __x_xpd__[0][0]);

		}
		if (((x.m_gu & 2) != 0)) {
			r2.m_c[0] += ((__x_xpd__[1][2] * __x_xpd__[1][2]) + (__x_xpd__[1][1] * __x_xpd__[1][1]) + (__x_xpd__[1][0] * __x_xpd__[1][0]));

		}
		if (((x.m_gu & 4) != 0)) {
			r2.m_c[0] += ((__x_xpd__[2][1] * __x_xpd__[2][1]) + (__x_xpd__[2][2] * __x_xpd__[2][2]) + (__x_xpd__[2][0] * __x_xpd__[2][0]));

		}
		if (((x.m_gu & 8) != 0)) {
			r2.m_c[0] += (__x_xpd__[3][0] * __x_xpd__[3][0]);

		}
		scalar ir;
		ir.m_c[0] = ((char)1 / sqrt((((r2.m_c[0] < (char)0)) ? ((-r2.m_c[0])) : (r2.m_c[0]))));
		mv __temp_var_1__;
		float __tmp_coord_array_7__[8] ;
		mv_zero(__tmp_coord_array_7__, 8);
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_7__[0] += (__x_xpd__[0][0] * ir.m_c[0]);

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_7__[1] += (__x_xpd__[1][0] * ir.m_c[0]);
			__tmp_coord_array_7__[2] += (__x_xpd__[1][1] * ir.m_c[0]);
			__tmp_coord_array_7__[3] += (__x_xpd__[1][2] * ir.m_c[0]);

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_7__[4] += (__x_xpd__[2][0] * ir.m_c[0]);
			__tmp_coord_array_7__[5] += (__x_xpd__[2][1] * ir.m_c[0]);
			__tmp_coord_array_7__[6] += (__x_xpd__[2][2] * ir.m_c[0]);

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_7__[7] += (__x_xpd__[3][0] * ir.m_c[0]);

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_7__);
		return __temp_var_1__;
	}
	mv reverse(const mv& x) {
		mv __temp_var_1__;
		float __tmp_coord_array_8__[8] ;
		mv_zero(__tmp_coord_array_8__, 8);
		const float* __x_xpd__[4] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_8__[0] += __x_xpd__[0][0];

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_8__[1] += __x_xpd__[1][0];
			__tmp_coord_array_8__[2] += __x_xpd__[1][1];
			__tmp_coord_array_8__[3] += __x_xpd__[1][2];

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_8__[4] += (-1.0f * __x_xpd__[2][0]);
			__tmp_coord_array_8__[5] += (-1.0f * __x_xpd__[2][1]);
			__tmp_coord_array_8__[6] += (-1.0f * __x_xpd__[2][2]);

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_8__[7] += (-1.0f * __x_xpd__[3][0]);

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_8__);
		return __temp_var_1__;
	}
	mv negate(const mv& x) {
		mv __temp_var_1__;
		float __tmp_coord_array_9__[8] ;
		mv_zero(__tmp_coord_array_9__, 8);
		const float* __x_xpd__[4] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_9__[0] += (-1.0f * __x_xpd__[0][0]);

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_9__[1] += (-1.0f * __x_xpd__[1][0]);
			__tmp_coord_array_9__[2] += (-1.0f * __x_xpd__[1][1]);
			__tmp_coord_array_9__[3] += (-1.0f * __x_xpd__[1][2]);

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_9__[4] += (-1.0f * __x_xpd__[2][0]);
			__tmp_coord_array_9__[5] += (-1.0f * __x_xpd__[2][1]);
			__tmp_coord_array_9__[6] += (-1.0f * __x_xpd__[2][2]);

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_9__[7] += (-1.0f * __x_xpd__[3][0]);

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_9__);
		return __temp_var_1__;
	}
	mv dual(const mv& x) {
		mv __temp_var_1__;
		float __tmp_coord_array_10__[8] ;
		mv_zero(__tmp_coord_array_10__, 8);
		const float* __x_xpd__[4] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_10__[7] += (-1.0f * __x_xpd__[0][0]);

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_10__[4] += (-1.0f * __x_xpd__[1][2]);
			__tmp_coord_array_10__[5] += (-1.0f * __x_xpd__[1][0]);
			__tmp_coord_array_10__[6] += (-1.0f * __x_xpd__[1][1]);

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_10__[1] += __x_xpd__[2][1];
			__tmp_coord_array_10__[2] += __x_xpd__[2][2];
			__tmp_coord_array_10__[3] += __x_xpd__[2][0];

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_10__[0] += __x_xpd__[3][0];

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_10__);
		return __temp_var_1__;
	}
	mv undual(const mv& x) {
		mv __temp_var_1__;
		float __tmp_coord_array_11__[8] ;
		mv_zero(__tmp_coord_array_11__, 8);
		const float* __x_xpd__[4] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_11__[7] += __x_xpd__[0][0];

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_11__[4] += __x_xpd__[1][2];
			__tmp_coord_array_11__[5] += __x_xpd__[1][0];
			__tmp_coord_array_11__[6] += __x_xpd__[1][1];

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_11__[1] += (-1.0f * __x_xpd__[2][1]);
			__tmp_coord_array_11__[2] += (-1.0f * __x_xpd__[2][2]);
			__tmp_coord_array_11__[3] += (-1.0f * __x_xpd__[2][0]);

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_11__[0] += (-1.0f * __x_xpd__[3][0]);

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_11__);
		return __temp_var_1__;
	}
	mv inverse(const mv& x) {
		scalar n;
		const float* __x_xpd__[4] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			n.m_c[0] += (__x_xpd__[0][0] * __x_xpd__[0][0]);

		}
		if (((x.m_gu & 2) != 0)) {
			n.m_c[0] += ((__x_xpd__[1][0] * __x_xpd__[1][0]) + (__x_xpd__[1][1] * __x_xpd__[1][1]) + (__x_xpd__[1][2] * __x_xpd__[1][2]));

		}
		if (((x.m_gu & 4) != 0)) {
			n.m_c[0] += ((__x_xpd__[2][0] * __x_xpd__[2][0]) + (__x_xpd__[2][2] * __x_xpd__[2][2]) + (__x_xpd__[2][1] * __x_xpd__[2][1]));

		}
		if (((x.m_gu & 8) != 0)) {
			n.m_c[0] += (__x_xpd__[3][0] * __x_xpd__[3][0]);

		}
		scalar in;
		in.m_c[0] = ((char)1 / n.m_c[0]);
		mv __temp_var_1__;
		float __tmp_coord_array_12__[8] ;
		mv_zero(__tmp_coord_array_12__, 8);
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_12__[0] += (__x_xpd__[0][0] * in.m_c[0]);

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_12__[1] += (__x_xpd__[1][0] * in.m_c[0]);
			__tmp_coord_array_12__[2] += (__x_xpd__[1][1] * in.m_c[0]);
			__tmp_coord_array_12__[3] += (__x_xpd__[1][2] * in.m_c[0]);

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_12__[4] += (-1.0f * __x_xpd__[2][0] * in.m_c[0]);
			__tmp_coord_array_12__[5] += (-1.0f * __x_xpd__[2][1] * in.m_c[0]);
			__tmp_coord_array_12__[6] += (-1.0f * __x_xpd__[2][2] * in.m_c[0]);

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_12__[7] += (-1.0f * __x_xpd__[3][0] * in.m_c[0]);

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_12__);
		return __temp_var_1__;
	}
	mv gradeInvolution(const mv& x) {
		mv __temp_var_1__;
		float __tmp_coord_array_13__[8] ;
		mv_zero(__tmp_coord_array_13__, 8);
		const float* __x_xpd__[4] ;
		x.expand(__x_xpd__, true);
		if (((x.m_gu & 1) != 0)) {
			__tmp_coord_array_13__[0] += __x_xpd__[0][0];

		}
		if (((x.m_gu & 2) != 0)) {
			__tmp_coord_array_13__[1] += (-1.0f * __x_xpd__[1][0]);
			__tmp_coord_array_13__[2] += (-1.0f * __x_xpd__[1][1]);
			__tmp_coord_array_13__[3] += (-1.0f * __x_xpd__[1][2]);

		}
		if (((x.m_gu & 4) != 0)) {
			__tmp_coord_array_13__[4] += __x_xpd__[2][0];
			__tmp_coord_array_13__[5] += __x_xpd__[2][1];
			__tmp_coord_array_13__[6] += __x_xpd__[2][2];

		}
		if (((x.m_gu & 8) != 0)) {
			__tmp_coord_array_13__[7] += (-1.0f * __x_xpd__[3][0]);

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_13__);
		return __temp_var_1__;
	}

	// G2 functions:
	mv apply_om(const om& x, const mv& y) {
		mv __temp_var_1__;
		float __tmp_coord_array_14__[8] ;
		mv_zero(__tmp_coord_array_14__, 8);
		const float* __y_xpd__[4] ;
		y.expand(__y_xpd__, true);
		if (((y.m_gu & 2) != 0)) {
			__tmp_coord_array_14__[1] += ((x.m_c[2] * __y_xpd__[1][2]) + (x.m_c[1] * __y_xpd__[1][1]) + (x.m_c[0] * __y_xpd__[1][0]));
			__tmp_coord_array_14__[2] += ((x.m_c[3] * __y_xpd__[1][0]) + (x.m_c[4] * __y_xpd__[1][1]) + (x.m_c[5] * __y_xpd__[1][2]));
			__tmp_coord_array_14__[3] += ((x.m_c[6] * __y_xpd__[1][0]) + (x.m_c[7] * __y_xpd__[1][1]) + (x.m_c[8] * __y_xpd__[1][2]));

		}
		if (((y.m_gu & 4) != 0)) {
			__tmp_coord_array_14__[4] += ((x.m_c[9] * __y_xpd__[2][0]) + (x.m_c[11] * __y_xpd__[2][2]) + (x.m_c[10] * __y_xpd__[2][1]));
			__tmp_coord_array_14__[5] += ((x.m_c[14] * __y_xpd__[2][2]) + (x.m_c[12] * __y_xpd__[2][0]) + (x.m_c[13] * __y_xpd__[2][1]));
			__tmp_coord_array_14__[6] += ((x.m_c[15] * __y_xpd__[2][0]) + (x.m_c[17] * __y_xpd__[2][2]) + (x.m_c[16] * __y_xpd__[2][1]));

		}
		if (((y.m_gu & 8) != 0)) {
			__tmp_coord_array_14__[7] += (x.m_c[18] * __y_xpd__[3][0]);

		}
		__temp_var_1__ = mv_compress(__tmp_coord_array_14__);
		return __temp_var_1__;
	}
	namespace __G2_GENERATED__ {
		void set(om& __x__, const vector& __image_of_e1__, const vector& __image_of_e2__, const vector& __image_of_e3__) {
			__x__.m_c[0] = __image_of_e1__.m_c[0];
			__x__.m_c[3] = __image_of_e1__.m_c[1];
			__x__.m_c[6] = __image_of_e1__.m_c[2];
			__x__.m_c[1] = __image_of_e2__.m_c[0];
			__x__.m_c[4] = __image_of_e2__.m_c[1];
			__x__.m_c[7] = __image_of_e2__.m_c[2];
			__x__.m_c[2] = __image_of_e3__.m_c[0];
			__x__.m_c[5] = __image_of_e3__.m_c[1];
			__x__.m_c[8] = __image_of_e3__.m_c[2];
			__x__.m_c[9] = ((-1.0f * __x__.m_c[1] * __x__.m_c[3]) + (__x__.m_c[4] * __x__.m_c[0]));
			__x__.m_c[12] = ((-1.0f * __x__.m_c[4] * __x__.m_c[6]) + (__x__.m_c[7] * __x__.m_c[3]));
			__x__.m_c[15] = ((__x__.m_c[1] * __x__.m_c[6]) + (-1.0f * __x__.m_c[7] * __x__.m_c[0]));
			__x__.m_c[10] = ((__x__.m_c[5] * __x__.m_c[1]) + (-1.0f * __x__.m_c[2] * __x__.m_c[4]));
			__x__.m_c[13] = ((-1.0f * __x__.m_c[5] * __x__.m_c[7]) + (__x__.m_c[8] * __x__.m_c[4]));
			__x__.m_c[16] = ((-1.0f * __x__.m_c[8] * __x__.m_c[1]) + (__x__.m_c[2] * __x__.m_c[7]));
			__x__.m_c[11] = ((__x__.m_c[2] * __x__.m_c[3]) + (-1.0f * __x__.m_c[5] * __x__.m_c[0]));
			__x__.m_c[14] = ((-1.0f * __x__.m_c[8] * __x__.m_c[3]) + (__x__.m_c[5] * __x__.m_c[6]));
			__x__.m_c[17] = ((-1.0f * __x__.m_c[2] * __x__.m_c[6]) + (__x__.m_c[8] * __x__.m_c[0]));
			__x__.m_c[18] = ((__x__.m_c[17] * __x__.m_c[4]) + (__x__.m_c[11] * __x__.m_c[7]) + (__x__.m_c[14] * __x__.m_c[1]));
		}
	} /* end of namespace __G2_GENERATED__ */
	vector apply_om(const om& x, const vector& y) {
		return vector(vector_e1_e2_e3, ((x.m_c[2] * y.m_c[2]) + (x.m_c[1] * y.m_c[1]) + (x.m_c[0] * y.m_c[0])), ((x.m_c[4] * y.m_c[1]) + (x.m_c[3] * y.m_c[0]) + (x.m_c[5] * y.m_c[2])), ((x.m_c[7] * y.m_c[1]) + (x.m_c[6] * y.m_c[0]) + (x.m_c[8] * y.m_c[2])));
	}
	bivector apply_om(const om& x, const bivector& y) {
		return bivector(bivector_e1e2_e2e3_e3e1, ((x.m_c[10] * y.m_c[1]) + (x.m_c[11] * y.m_c[2]) + (x.m_c[9] * y.m_c[0])), ((x.m_c[12] * y.m_c[0]) + (x.m_c[14] * y.m_c[2]) + (x.m_c[13] * y.m_c[1])), ((x.m_c[15] * y.m_c[0]) + (x.m_c[16] * y.m_c[1]) + (x.m_c[17] * y.m_c[2])));
	}


	// algebra / user constants:
	__I3i_ct__ I3i;
	__e3_ct__ e3;
	__I3_ct__ I3;
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
		for (i = 0; i <= 3; i++) {
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
		for (i = 0; i <= 3; i++) {
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
		float cc[8];
		int cgu;
		compress(c, cc, cgu, epsilon, gu);
		return mv(cgu, cc);
	}

	mv compress(const mv & arg1, float epsilon /*= 0.0*/) {
		return mv_compress(arg1.m_c, epsilon, arg1.m_gu);
	}

	void mv::compress(float epsilon /*= 0.0*/) {
		float cc[8];
		int cgu;
		e3ga::compress(m_c, cc, cgu, epsilon, m_gu);
		set(cgu, cc);
	}

	mv mv_compress(int nbBlades, const unsigned int *bitmaps, const mv::Float *coords) {	
		// convert basis blade compression to regular coordinate array:
		mv::Float A[8];
		mv_zero(A, 8);

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
			c += 3;
		}
		else ptrs[1] = null;	
		if (m_gu & 4) {
			ptrs[2] =  c;
			c += 3;
		}
		else ptrs[2] = null;	
		if (m_gu & 8) {
			ptrs[3] =  c;
			c += 1;
		}
		else ptrs[3] = null;	
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

	}


	void mvType::init(const mv &X, mv::Float epsilon, bool useAlgebraMetric, int guCnt) {
		mv rX = reverse(X);

		// test if null:
		mv Sq = (useAlgebraMetric) ? scp(X, rX) : scp(X, rX);
		Sq.compress(epsilon);
		if (_Float(Sq) == 0) {
			// X = multivector, case closed
			m_type = MULTIVECTOR;
			return;
		}

		// versor inverse must be true inverse:
		mv Xvi = (useAlgebraMetric) ? inverse(X) : inverse(X);
		mv Xgi = gradeInvolution(X);

		// check if (Xgi Xvi) is a scalar:
		mv XgiXvi = (useAlgebraMetric) ? gp(Xgi, Xvi) : gp(Xgi, Xvi);
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
		mv XviXgi = (useAlgebraMetric) ? gp(Xvi, Xgi) : gp(Xvi, Xgi);
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
				// test e1		
				mv tmp = (useAlgebraMetric) ? gp(gp(Xvi, e1), Xgi) : gp(gp(Xvi, e1), Xgi);
				tmp.compress(epsilon);
				if (tmp.gu() != GRADE_1) { // X = multivector, case closed
					m_type = MULTIVECTOR;
					return;
				}
			}
			{
				// test e2		
				mv tmp = (useAlgebraMetric) ? gp(gp(Xvi, e2), Xgi) : gp(gp(Xvi, e2), Xgi);
				tmp.compress(epsilon);
				if (tmp.gu() != GRADE_1) { // X = multivector, case closed
					m_type = MULTIVECTOR;
					return;
				}
			}
			{
				// test e3		
				mv tmp = (useAlgebraMetric) ? gp(gp(Xvi, e3), Xgi) : gp(gp(Xvi, e3), Xgi);
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










} // end of namespace e3ga
// post_cpp_include

