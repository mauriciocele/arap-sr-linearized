
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

#include <stdio.h>
#include <stdlib.h>
	#include <string.h>
	#include <math.h>
	#include <string>

	#include "mvtypebase.h"

	// pre_h_include


	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>

	#ifndef _GA_c2ga_h_H_
	#define _GA_c2ga_h_H_

	namespace c2ga {

	// multivector types:
	enum g2Type {
		MVT_NONE = -1,
			MVT_NO_T = 10,
			MVT_E1_T = 11,
			MVT_E2_T = 12,
			MVT_NI_T = 13,
			MVT_SCALAR = 14,
			MVT_POINT = 15,
			MVT_NORMALIZEDPOINT = 16,
			MVT_FLATPOINT = 17,
			MVT_NORMALIZEDFLATPOINT = 18,
			MVT_POINTPAIR = 19,
			MVT_TRVERSORLOG = 20,
			MVT_LINE = 21,
			MVT_DUALLINE = 22,
			MVT_CIRCLE = 23,
			MVT_FREEVECTOR = 24,
			MVT_FREEBIVECTOR = 25,
			MVT_TANGENTVECTOR = 26,
			MVT_TANGENTBIVECTOR = 27,
			MVT_VECTORE2GA = 28,
			MVT_BIVECTORE2GA = 29,
			MVT_TRVERSOR = 30,
			MVT_TRSVERSOR = 31,
			MVT_EVENVERSOR = 32,
			MVT_TRANSLATOR = 33,
			MVT_NORMALIZEDTRANSLATOR = 34,
			MVT_ROTOR = 35,
			MVT_SCALOR = 36,
			MVT___NO_CT__ = 37,
			MVT___E1_CT__ = 38,
			MVT___E2_CT__ = 39,
			MVT___NI_CT__ = 40,
			MVT___I4I_CT__ = 41,
			MVT___I4_CT__ = 42,
			MVT___I2_CT__ = 43,
			MVT___NONI_CT__ = 44,
			MVT___E2NI_CT__ = 45,
			MVT___E1NI_CT__ = 46,
			MVT___SYN_SMV___E1_E2_NOF1_0 = 47,
			MVT___SYN_SMV___E1E2NIF1_0 = 48,
			MVT___SYN_SMV___E1_E2_NI_NOF_1_0 = 49,
			MVT___SYN_SMV___SCALAR_NOE1_NOE2_E1E2_NONI_E1NI_E2NI = 50,
			MVT___SYN_SMV___SCALAR_NOE1_NOE2_NONI = 51,
			MVT___SYN_SMV___NO_E1_E2_NOE1E2_NI_NOE1NI_NOE2NI = 52,
			MVT___SYN_SMV___SCALAR_NOE1_E1E2_E1NI = 53,
			MVT___SYN_SMV___NO_E1_E2_NOE1E2_NI_NOE1NI_E1E2NI = 54,
			MVT___SYN_SMV___SCALAR_NOE2_E1E2_E2NI = 55,
			MVT___SYN_SMV___NO_E1_E2_NOE1E2_NI_NOE2NI_E1E2NI = 56,
			MVT___SYN_SMV___SCALAR_NONI_E1NI_E2NI = 57,
			MVT___SYN_SMV___NO_E1_E2_NI_NOE1NI_NOE2NI_E1E2NI = 58,
			MVT___SYN_SMV___E1NI_E2NI_NONIF_1_0 = 59,
			MVT___SYN_SMV___SCALARF_1_0 = 60,
			MVT___SYN_SMV___NIF_1_0 = 61,
			MVT___SYN_SMV___NIF1_0 = 62,
			MVT___SYN_SMV___E1_E2_NI_NOE1NI_NOE2NI_E1E2NI_NOF1_0 = 63,
			MVT___SYN_SMV___E1_E2_NI_NOF2_0 = 64,
			MVT___SYN_SMV___E1_E2_NI = 65,
			MVT___SYN_SMV___NOE1_NOE2_NONI = 66,
			MVT___SYN_SMV___NO_NOE1E2_NOE1NI_NOE2NI = 67,
			MVT___SYN_SMV___SCALAR_E1E2_E1NI = 68,
			MVT___SYN_SMV___E1_E2_NI_E1E2NI = 69,
			MVT___SYN_SMV___SCALAR_E1E2_E2NI = 70,
			MVT___SYN_SMV___SCALARF0_0 = 71,
			MVT___SYN_SMV___NI_E1E2NI = 72,
			MVT_MV = 8,
			MVT_LAST = 73 
	};

	// outermorphism types:
	enum omType {
		OMT_NONE = -2,
			OMT_OM = 9,
			OMT_LAST = 73 
	};

	// grade definitions that can be joined using the '|' operator:
	const int GRADE_0 = 1;
	const int GRADE_1 = 2;
	const int GRADE_2 = 4;
	const int GRADE_3 = 8;
	const int GRADE_4 = 16;

	// The dimension of the space:
	extern const int mv_spaceDim;

	// Is the metric of the space Euclidean?
	extern const bool mv_metricEuclidean;

	// This array can be used to lookup the number of coordinates for a grade part of a general multivector
	extern const int mv_gradeSize[5];

	// This array can be used to lookup the number of coordinates based on a grade usage bitmap
	extern const int mv_size[32];

	// This array of ASCIIZ strings contains the names of the basis vectors
	extern const char *mv_basisVectorNames[4];

	// This array of integers contains the order of basis elements in the general multivector
	// Use it to answer: 'what basis vectors are in the basis element at position [x]?
	extern const int mv_basisElements[16][5];

	// This array of integers contains the 'sign' (even/odd permutation of canonical order) of basis elements in the general multivector
	// Use it to answer 'what is the permutation of the coordinate at index [x]'?
	extern const double mv_basisElementSignByIndex[16];

	// This array of integers contains the 'sign' (even/odd permutation of canonical order) of basis elements in the general multivector
	// Use it to answer 'what is the permutation of the coordinate of bitmap [x]'?
	extern const double mv_basisElementSignByBitmap[16];

	// This array of integers contains the order of basis elements in the general multivector
	// Use it to answer: 'at what index do I find basis element [x] (x = basis vector bitmap)?'
	extern const int mv_basisElementIndexByBitmap[16];

	// This array of integers contains the indices of basis elements in the general multivector
	// Use it to answer: 'what basis element do I find at index [x]'?
	extern const int mv_basisElementBitmapByIndex[16];

	// This array of grade of each basis elements in the general multivector
	// Use it to answer: 'what is the grade of basis element bitmap [x]'?
	extern const int mv_basisElementGradeByBitmap[16];




	/* *************************************************************************** */
	/* *************************** define all classes upfront *************************** */
	/* *************************************************************************** */
	class no_t;
	class e1_t;
	class e2_t;
	class ni_t;
	class scalar;
	class point;
	class normalizedPoint;
	class flatPoint;
	class normalizedFlatPoint;
	class pointPair;
	class TRversorLog;
	class line;
	class dualLine;
	class circle;
	class freeVector;
	class freeBivector;
	class tangentVector;
	class tangentBivector;
	class vectorE2GA;
	class bivectorE2GA;
	class TRversor;
	class TRSversor;
	class evenVersor;
	class translator;
	class normalizedTranslator;
	class rotor;
	class scalor;
	class __no_ct__;
	class __e1_ct__;
	class __e2_ct__;
	class __ni_ct__;
	class __I4i_ct__;
	class __I4_ct__;
	class __I2_ct__;
	class __noni_ct__;
	class __e2ni_ct__;
	class __e1ni_ct__;
	class __syn_smv___e1_e2_nof1_0;
	class __syn_smv___e1e2nif1_0;
	class __syn_smv___e1_e2_ni_nof_1_0;
	class __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni;
	class __syn_smv___scalar_noe1_noe2_noni;
	class __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni;
	class __syn_smv___scalar_noe1_e1e2_e1ni;
	class __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni;
	class __syn_smv___scalar_noe2_e1e2_e2ni;
	class __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni;
	class __syn_smv___scalar_noni_e1ni_e2ni;
	class __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni;
	class __syn_smv___e1ni_e2ni_nonif_1_0;
	class __syn_smv___scalarf_1_0;
	class __syn_smv___nif_1_0;
	class __syn_smv___nif1_0;
	class __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0;
	class __syn_smv___e1_e2_ni_nof2_0;
	class __syn_smv___e1_e2_ni;
	class __syn_smv___noe1_noe2_noni;
	class __syn_smv___no_noe1e2_noe1ni_noe2ni;
	class __syn_smv___scalar_e1e2_e1ni;
	class __syn_smv___e1_e2_ni_e1e2ni;
	class __syn_smv___scalar_e1e2_e2ni;
	class __syn_smv___scalarf0_0;
	class __syn_smv___ni_e1e2ni;
	class mv;
	class om;




	// exception handling:
	const int MV_EXCEPTION_WARNING = 1;
	const int MV_EXCEPTION_ERROR = 2;
	// Exception mechanism: ignore & pray
	inline void mv_throw_exception(const char *msg, int level) {}

	// You can alter the formatting of 'string()' through this function.
	// 'format' = NULL will give you back the default.
	void mv_setStringFormat(const char *what, const char *format = NULL);

	extern const char *mv_string_fp; /* = \"%2.2f\" */
	extern const char *mv_string_start; /* = \"\" */
	extern const char *mv_string_end; /* = \"\" */
	extern const char *mv_string_mul; /* = \"*\" */
	extern const char *mv_string_wedge; /* = \"^\" */
	extern const char *mv_string_plus; /* = \" + \" */
	extern const char *mv_string_minus; /* = \" - \" */

	// declaration of profiling functions
	namespace g2Profiling {
		void profile(unsigned int funcIdx, unsigned short storageTypeIdx, unsigned short nbArg, 
			unsigned short argType[], int nbReturnType, unsigned short returnType[]);
		void reset();
		void save(const char *filename = "E:\\gasandbox\\ga_sandbox\\libgasandbox\\c2ga.gp2", bool append = true);
		void init(const char *filename = "E:\\gasandbox\\ga_sandbox\\libgasandbox\\c2ga.gp2",
			const char *hostName = "localhost", int port = 7693);
	} // end of namespace g2Profiling



	inline void mv_memcpy(float *to, const float *from, const int nb) {
		memcpy(to, from, sizeof(float) * nb);
	}

	inline void mv_zero(float *ptr, const int nb) {
		memset(ptr, 0, sizeof(float) * nb);
	}

	// a is any number, b is positive number
	inline bool mv_absLessThan(const float a, const float b) {
		return ((a > b) || (a < -b));
	}

	inline float mv_stringToNumber(const char *asciiz) {
		return (float)atof(asciiz);
	}

	void updateCoordinateString(const mv &x, char **cs, size_t &csl);
	char *c_str(const mv &  obj, const char *fp = NULL);
	std::string toString(const mv &  obj, const char *fp = NULL);

	inline char *c_str_f(const mv &  obj) {return c_str(obj, "%f");}
	inline char *c_str_e(const mv &  obj) {return c_str(obj, "%e");}
	inline char *c_str_e20(const mv &  obj) {return c_str(obj, "%2.20e");}

	inline std::string toString_f(const mv &  obj) {return toString(obj, "%f");}
	inline std::string toString_e(const mv &  obj) {return toString(obj, "%e");}
	inline std::string toString_e20(const mv &  obj) {return toString(obj, "%2.20e");}


	class mv {
		public:
			typedef float Float;

		/// zero constructor
		inline mv () {

			set();
		}

		/// copy constructor (MUST PASS BY REFERENCE)
		inline mv(const mv &arg1) {

			set(arg1);
		}

		/// scalar constructor
		inline mv(Float scalar) {

			set(scalar);
		}

		/// pointer to coordinates constructor
		inline mv(unsigned int gradeUsage, const Float *coordinates) {

			set(gradeUsage, coordinates);
		}

		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0) {

			set(gradeUsage
				, c0);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1) {

			set(gradeUsage
				, c0, c1);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1, Float c2) {

			set(gradeUsage
				, c0, c1, c2);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1, Float c2, Float c3) {

			set(gradeUsage
				, c0, c1, c2, c3);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1, Float c2, Float c3, Float c4) {

			set(gradeUsage
				, c0, c1, c2, c3, c4);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5) {

			set(gradeUsage
				, c0, c1, c2, c3, c4, c5);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6) {

			set(gradeUsage
				, c0, c1, c2, c3, c4, c5, c6);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7) {

			set(gradeUsage
				, c0, c1, c2, c3, c4, c5, c6, c7);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8) {

			set(gradeUsage
				, c0, c1, c2, c3, c4, c5, c6, c7, c8);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9) {

			set(gradeUsage
				, c0, c1, c2, c3, c4, c5, c6, c7, c8, c9);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10) {

			set(gradeUsage
				, c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11) {

			set(gradeUsage
				, c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12) {

			set(gradeUsage
				, c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13) {

			set(gradeUsage
				, c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13, Float c14) {

			set(gradeUsage
				, c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14);
		}
		/// all 'coordinates specified' constructors
		inline mv(unsigned int gradeUsage
		, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13, Float c14, Float c15) {

			set(gradeUsage
				, c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15);
		}

		/// init from no_t constructor
		inline mv(const no_t &arg1) {
			set(arg1);
		}
		/// init from e1_t constructor
		inline mv(const e1_t &arg1) {
			set(arg1);
		}
		/// init from e2_t constructor
		inline mv(const e2_t &arg1) {
			set(arg1);
		}
		/// init from ni_t constructor
		inline mv(const ni_t &arg1) {
			set(arg1);
		}
		/// init from scalar constructor
		inline mv(const scalar &arg1) {
			set(arg1);
		}
		/// init from point constructor
		inline mv(const point &arg1) {
			set(arg1);
		}
		/// init from normalizedPoint constructor
		inline mv(const normalizedPoint &arg1) {
			set(arg1);
		}
		/// init from flatPoint constructor
		inline mv(const flatPoint &arg1) {
			set(arg1);
		}
		/// init from normalizedFlatPoint constructor
		inline mv(const normalizedFlatPoint &arg1) {
			set(arg1);
		}
		/// init from pointPair constructor
		inline mv(const pointPair &arg1) {
			set(arg1);
		}
		/// init from TRversorLog constructor
		inline mv(const TRversorLog &arg1) {
			set(arg1);
		}
		/// init from line constructor
		inline mv(const line &arg1) {
			set(arg1);
		}
		/// init from dualLine constructor
		inline mv(const dualLine &arg1) {
			set(arg1);
		}
		/// init from circle constructor
		inline mv(const circle &arg1) {
			set(arg1);
		}
		/// init from freeVector constructor
		inline mv(const freeVector &arg1) {
			set(arg1);
		}
		/// init from freeBivector constructor
		inline mv(const freeBivector &arg1) {
			set(arg1);
		}
		/// init from tangentVector constructor
		inline mv(const tangentVector &arg1) {
			set(arg1);
		}
		/// init from tangentBivector constructor
		inline mv(const tangentBivector &arg1) {
			set(arg1);
		}
		/// init from vectorE2GA constructor
		inline mv(const vectorE2GA &arg1) {
			set(arg1);
		}
		/// init from bivectorE2GA constructor
		inline mv(const bivectorE2GA &arg1) {
			set(arg1);
		}
		/// init from TRversor constructor
		inline mv(const TRversor &arg1) {
			set(arg1);
		}
		/// init from TRSversor constructor
		inline mv(const TRSversor &arg1) {
			set(arg1);
		}
		/// init from evenVersor constructor
		inline mv(const evenVersor &arg1) {
			set(arg1);
		}
		/// init from translator constructor
		inline mv(const translator &arg1) {
			set(arg1);
		}
		/// init from normalizedTranslator constructor
		inline mv(const normalizedTranslator &arg1) {
			set(arg1);
		}
		/// init from rotor constructor
		inline mv(const rotor &arg1) {
			set(arg1);
		}
		/// init from scalor constructor
		inline mv(const scalor &arg1) {
			set(arg1);
		}
		/// init from __no_ct__ constructor
		inline mv(const __no_ct__ &arg1) {
			set(arg1);
		}
		/// init from __e1_ct__ constructor
		inline mv(const __e1_ct__ &arg1) {
			set(arg1);
		}
		/// init from __e2_ct__ constructor
		inline mv(const __e2_ct__ &arg1) {
			set(arg1);
		}
		/// init from __ni_ct__ constructor
		inline mv(const __ni_ct__ &arg1) {
			set(arg1);
		}
		/// init from __I4i_ct__ constructor
		inline mv(const __I4i_ct__ &arg1) {
			set(arg1);
		}
		/// init from __I4_ct__ constructor
		inline mv(const __I4_ct__ &arg1) {
			set(arg1);
		}
		/// init from __I2_ct__ constructor
		inline mv(const __I2_ct__ &arg1) {
			set(arg1);
		}
		/// init from __noni_ct__ constructor
		inline mv(const __noni_ct__ &arg1) {
			set(arg1);
		}
		/// init from __e2ni_ct__ constructor
		inline mv(const __e2ni_ct__ &arg1) {
			set(arg1);
		}
		/// init from __e1ni_ct__ constructor
		inline mv(const __e1ni_ct__ &arg1) {
			set(arg1);
		}
		/// init from __syn_smv___e1_e2_nof1_0 constructor
		inline mv(const __syn_smv___e1_e2_nof1_0 &arg1) {
			set(arg1);
		}
		/// init from __syn_smv___e1e2nif1_0 constructor
		inline mv(const __syn_smv___e1e2nif1_0 &arg1) {
			set(arg1);
		}
		/// init from __syn_smv___e1_e2_ni_nof_1_0 constructor
		inline mv(const __syn_smv___e1_e2_ni_nof_1_0 &arg1) {
			set(arg1);
		}
		/// init from __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni constructor
		inline mv(const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni &arg1) {
			set(arg1);
		}
		/// init from __syn_smv___scalar_noe1_noe2_noni constructor
		inline mv(const __syn_smv___scalar_noe1_noe2_noni &arg1) {
			set(arg1);
		}
		/// init from __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni constructor
		inline mv(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni &arg1) {
			set(arg1);
		}
		/// init from __syn_smv___scalar_noe1_e1e2_e1ni constructor
		inline mv(const __syn_smv___scalar_noe1_e1e2_e1ni &arg1) {
			set(arg1);
		}
		/// init from __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni constructor
		inline mv(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni &arg1) {
			set(arg1);
		}
		/// init from __syn_smv___scalar_noe2_e1e2_e2ni constructor
		inline mv(const __syn_smv___scalar_noe2_e1e2_e2ni &arg1) {
			set(arg1);
		}
		/// init from __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni constructor
		inline mv(const __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni &arg1) {
			set(arg1);
		}
		/// init from __syn_smv___scalar_noni_e1ni_e2ni constructor
		inline mv(const __syn_smv___scalar_noni_e1ni_e2ni &arg1) {
			set(arg1);
		}
		/// init from __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni constructor
		inline mv(const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni &arg1) {
			set(arg1);
		}
		/// init from __syn_smv___e1ni_e2ni_nonif_1_0 constructor
		inline mv(const __syn_smv___e1ni_e2ni_nonif_1_0 &arg1) {
			set(arg1);
		}
		/// init from __syn_smv___scalarf_1_0 constructor
		inline mv(const __syn_smv___scalarf_1_0 &arg1) {
			set(arg1);
		}
		/// init from __syn_smv___nif_1_0 constructor
		inline mv(const __syn_smv___nif_1_0 &arg1) {
			set(arg1);
		}
		/// init from __syn_smv___nif1_0 constructor
		inline mv(const __syn_smv___nif1_0 &arg1) {
			set(arg1);
		}
		/// init from __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 constructor
		inline mv(const __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 &arg1) {
			set(arg1);
		}
		/// init from __syn_smv___e1_e2_ni_nof2_0 constructor
		inline mv(const __syn_smv___e1_e2_ni_nof2_0 &arg1) {
			set(arg1);
		}
		/// init from __syn_smv___e1_e2_ni constructor
		inline mv(const __syn_smv___e1_e2_ni &arg1) {
			set(arg1);
		}
		/// init from __syn_smv___noe1_noe2_noni constructor
		inline mv(const __syn_smv___noe1_noe2_noni &arg1) {
			set(arg1);
		}
		/// init from __syn_smv___no_noe1e2_noe1ni_noe2ni constructor
		inline mv(const __syn_smv___no_noe1e2_noe1ni_noe2ni &arg1) {
			set(arg1);
		}
		/// init from __syn_smv___scalar_e1e2_e1ni constructor
		inline mv(const __syn_smv___scalar_e1e2_e1ni &arg1) {
			set(arg1);
		}
		/// init from __syn_smv___e1_e2_ni_e1e2ni constructor
		inline mv(const __syn_smv___e1_e2_ni_e1e2ni &arg1) {
			set(arg1);
		}
		/// init from __syn_smv___scalar_e1e2_e2ni constructor
		inline mv(const __syn_smv___scalar_e1e2_e2ni &arg1) {
			set(arg1);
		}
		/// init from __syn_smv___scalarf0_0 constructor
		inline mv(const __syn_smv___scalarf0_0 &arg1) {
			set(arg1);
		}
		/// init from __syn_smv___ni_e1e2ni constructor
		inline mv(const __syn_smv___ni_e1e2ni &arg1) {
			set(arg1);
		}


		/// set to null
		void set();

		/// set to copy
		void set(const mv &arg1);

		/// set to scalar
		void set(Float scalar);

		/// pointer to coordinates constructor
		void set(unsigned int gradeUsage, const Float *coordinates);


		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1, Float c2);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1, Float c2, Float c3);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1, Float c2, Float c3, Float c4);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13, Float c14);
		/// set to 'coordinates specified' 
		void set (unsigned int gradeUsage
			, Float c0, Float c1, Float c2, Float c3, Float c4, Float c5, Float c6, Float c7, Float c8, Float c9, Float c10, Float c11, Float c12, Float c13, Float c14, Float c15);


		/// set to no_t 
		void set(const no_t &arg1);
		/// set to e1_t 
		void set(const e1_t &arg1);
		/// set to e2_t 
		void set(const e2_t &arg1);
		/// set to ni_t 
		void set(const ni_t &arg1);
		/// set to scalar 
		void set(const scalar &arg1);
		/// set to point 
		void set(const point &arg1);
		/// set to normalizedPoint 
		void set(const normalizedPoint &arg1);
		/// set to flatPoint 
		void set(const flatPoint &arg1);
		/// set to normalizedFlatPoint 
		void set(const normalizedFlatPoint &arg1);
		/// set to pointPair 
		void set(const pointPair &arg1);
		/// set to TRversorLog 
		void set(const TRversorLog &arg1);
		/// set to line 
		void set(const line &arg1);
		/// set to dualLine 
		void set(const dualLine &arg1);
		/// set to circle 
		void set(const circle &arg1);
		/// set to freeVector 
		void set(const freeVector &arg1);
		/// set to freeBivector 
		void set(const freeBivector &arg1);
		/// set to tangentVector 
		void set(const tangentVector &arg1);
		/// set to tangentBivector 
		void set(const tangentBivector &arg1);
		/// set to vectorE2GA 
		void set(const vectorE2GA &arg1);
		/// set to bivectorE2GA 
		void set(const bivectorE2GA &arg1);
		/// set to TRversor 
		void set(const TRversor &arg1);
		/// set to TRSversor 
		void set(const TRSversor &arg1);
		/// set to evenVersor 
		void set(const evenVersor &arg1);
		/// set to translator 
		void set(const translator &arg1);
		/// set to normalizedTranslator 
		void set(const normalizedTranslator &arg1);
		/// set to rotor 
		void set(const rotor &arg1);
		/// set to scalor 
		void set(const scalor &arg1);
		/// set to __no_ct__ 
		void set(const __no_ct__ &arg1);
		/// set to __e1_ct__ 
		void set(const __e1_ct__ &arg1);
		/// set to __e2_ct__ 
		void set(const __e2_ct__ &arg1);
		/// set to __ni_ct__ 
		void set(const __ni_ct__ &arg1);
		/// set to __I4i_ct__ 
		void set(const __I4i_ct__ &arg1);
		/// set to __I4_ct__ 
		void set(const __I4_ct__ &arg1);
		/// set to __I2_ct__ 
		void set(const __I2_ct__ &arg1);
		/// set to __noni_ct__ 
		void set(const __noni_ct__ &arg1);
		/// set to __e2ni_ct__ 
		void set(const __e2ni_ct__ &arg1);
		/// set to __e1ni_ct__ 
		void set(const __e1ni_ct__ &arg1);
		/// set to __syn_smv___e1_e2_nof1_0 
		void set(const __syn_smv___e1_e2_nof1_0 &arg1);
		/// set to __syn_smv___e1e2nif1_0 
		void set(const __syn_smv___e1e2nif1_0 &arg1);
		/// set to __syn_smv___e1_e2_ni_nof_1_0 
		void set(const __syn_smv___e1_e2_ni_nof_1_0 &arg1);
		/// set to __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni 
		void set(const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni &arg1);
		/// set to __syn_smv___scalar_noe1_noe2_noni 
		void set(const __syn_smv___scalar_noe1_noe2_noni &arg1);
		/// set to __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni 
		void set(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni &arg1);
		/// set to __syn_smv___scalar_noe1_e1e2_e1ni 
		void set(const __syn_smv___scalar_noe1_e1e2_e1ni &arg1);
		/// set to __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni 
		void set(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni &arg1);
		/// set to __syn_smv___scalar_noe2_e1e2_e2ni 
		void set(const __syn_smv___scalar_noe2_e1e2_e2ni &arg1);
		/// set to __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni 
		void set(const __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni &arg1);
		/// set to __syn_smv___scalar_noni_e1ni_e2ni 
		void set(const __syn_smv___scalar_noni_e1ni_e2ni &arg1);
		/// set to __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni 
		void set(const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni &arg1);
		/// set to __syn_smv___e1ni_e2ni_nonif_1_0 
		void set(const __syn_smv___e1ni_e2ni_nonif_1_0 &arg1);
		/// set to __syn_smv___scalarf_1_0 
		void set(const __syn_smv___scalarf_1_0 &arg1);
		/// set to __syn_smv___nif_1_0 
		void set(const __syn_smv___nif_1_0 &arg1);
		/// set to __syn_smv___nif1_0 
		void set(const __syn_smv___nif1_0 &arg1);
		/// set to __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 
		void set(const __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 &arg1);
		/// set to __syn_smv___e1_e2_ni_nof2_0 
		void set(const __syn_smv___e1_e2_ni_nof2_0 &arg1);
		/// set to __syn_smv___e1_e2_ni 
		void set(const __syn_smv___e1_e2_ni &arg1);
		/// set to __syn_smv___noe1_noe2_noni 
		void set(const __syn_smv___noe1_noe2_noni &arg1);
		/// set to __syn_smv___no_noe1e2_noe1ni_noe2ni 
		void set(const __syn_smv___no_noe1e2_noe1ni_noe2ni &arg1);
		/// set to __syn_smv___scalar_e1e2_e1ni 
		void set(const __syn_smv___scalar_e1e2_e1ni &arg1);
		/// set to __syn_smv___e1_e2_ni_e1e2ni 
		void set(const __syn_smv___e1_e2_ni_e1e2ni &arg1);
		/// set to __syn_smv___scalar_e1e2_e2ni 
		void set(const __syn_smv___scalar_e1e2_e2ni &arg1);
		/// set to __syn_smv___scalarf0_0 
		void set(const __syn_smv___scalarf0_0 &arg1);
		/// set to __syn_smv___ni_e1e2ni 
		void set(const __syn_smv___ni_e1e2ni &arg1);


		/// assign copy
		mv &operator=(const mv &arg1);

		/// assign scalar
		mv &operator=(Float scalar);

		/// assign no_t 
		mv&operator=(const no_t& arg1);
		/// assign e1_t 
		mv&operator=(const e1_t& arg1);
		/// assign e2_t 
		mv&operator=(const e2_t& arg1);
		/// assign ni_t 
		mv&operator=(const ni_t& arg1);
		/// assign scalar 
		mv&operator=(const scalar& arg1);
		/// assign point 
		mv&operator=(const point& arg1);
		/// assign normalizedPoint 
		mv&operator=(const normalizedPoint& arg1);
		/// assign flatPoint 
		mv&operator=(const flatPoint& arg1);
		/// assign normalizedFlatPoint 
		mv&operator=(const normalizedFlatPoint& arg1);
		/// assign pointPair 
		mv&operator=(const pointPair& arg1);
		/// assign TRversorLog 
		mv&operator=(const TRversorLog& arg1);
		/// assign line 
		mv&operator=(const line& arg1);
		/// assign dualLine 
		mv&operator=(const dualLine& arg1);
		/// assign circle 
		mv&operator=(const circle& arg1);
		/// assign freeVector 
		mv&operator=(const freeVector& arg1);
		/// assign freeBivector 
		mv&operator=(const freeBivector& arg1);
		/// assign tangentVector 
		mv&operator=(const tangentVector& arg1);
		/// assign tangentBivector 
		mv&operator=(const tangentBivector& arg1);
		/// assign vectorE2GA 
		mv&operator=(const vectorE2GA& arg1);
		/// assign bivectorE2GA 
		mv&operator=(const bivectorE2GA& arg1);
		/// assign TRversor 
		mv&operator=(const TRversor& arg1);
		/// assign TRSversor 
		mv&operator=(const TRSversor& arg1);
		/// assign evenVersor 
		mv&operator=(const evenVersor& arg1);
		/// assign translator 
		mv&operator=(const translator& arg1);
		/// assign normalizedTranslator 
		mv&operator=(const normalizedTranslator& arg1);
		/// assign rotor 
		mv&operator=(const rotor& arg1);
		/// assign scalor 
		mv&operator=(const scalor& arg1);
		/// assign __no_ct__ 
		mv&operator=(const __no_ct__& arg1);
		/// assign __e1_ct__ 
		mv&operator=(const __e1_ct__& arg1);
		/// assign __e2_ct__ 
		mv&operator=(const __e2_ct__& arg1);
		/// assign __ni_ct__ 
		mv&operator=(const __ni_ct__& arg1);
		/// assign __I4i_ct__ 
		mv&operator=(const __I4i_ct__& arg1);
		/// assign __I4_ct__ 
		mv&operator=(const __I4_ct__& arg1);
		/// assign __I2_ct__ 
		mv&operator=(const __I2_ct__& arg1);
		/// assign __noni_ct__ 
		mv&operator=(const __noni_ct__& arg1);
		/// assign __e2ni_ct__ 
		mv&operator=(const __e2ni_ct__& arg1);
		/// assign __e1ni_ct__ 
		mv&operator=(const __e1ni_ct__& arg1);
		/// assign __syn_smv___e1_e2_nof1_0 
		mv&operator=(const __syn_smv___e1_e2_nof1_0& arg1);
		/// assign __syn_smv___e1e2nif1_0 
		mv&operator=(const __syn_smv___e1e2nif1_0& arg1);
		/// assign __syn_smv___e1_e2_ni_nof_1_0 
		mv&operator=(const __syn_smv___e1_e2_ni_nof_1_0& arg1);
		/// assign __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni 
		mv&operator=(const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& arg1);
		/// assign __syn_smv___scalar_noe1_noe2_noni 
		mv&operator=(const __syn_smv___scalar_noe1_noe2_noni& arg1);
		/// assign __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni 
		mv&operator=(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni& arg1);
		/// assign __syn_smv___scalar_noe1_e1e2_e1ni 
		mv&operator=(const __syn_smv___scalar_noe1_e1e2_e1ni& arg1);
		/// assign __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni 
		mv&operator=(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni& arg1);
		/// assign __syn_smv___scalar_noe2_e1e2_e2ni 
		mv&operator=(const __syn_smv___scalar_noe2_e1e2_e2ni& arg1);
		/// assign __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni 
		mv&operator=(const __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni& arg1);
		/// assign __syn_smv___scalar_noni_e1ni_e2ni 
		mv&operator=(const __syn_smv___scalar_noni_e1ni_e2ni& arg1);
		/// assign __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni 
		mv&operator=(const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni& arg1);
		/// assign __syn_smv___e1ni_e2ni_nonif_1_0 
		mv&operator=(const __syn_smv___e1ni_e2ni_nonif_1_0& arg1);
		/// assign __syn_smv___scalarf_1_0 
		mv&operator=(const __syn_smv___scalarf_1_0& arg1);
		/// assign __syn_smv___nif_1_0 
		mv&operator=(const __syn_smv___nif_1_0& arg1);
		/// assign __syn_smv___nif1_0 
		mv&operator=(const __syn_smv___nif1_0& arg1);
		/// assign __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 
		mv&operator=(const __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0& arg1);
		/// assign __syn_smv___e1_e2_ni_nof2_0 
		mv&operator=(const __syn_smv___e1_e2_ni_nof2_0& arg1);
		/// assign __syn_smv___e1_e2_ni 
		mv&operator=(const __syn_smv___e1_e2_ni& arg1);
		/// assign __syn_smv___noe1_noe2_noni 
		mv&operator=(const __syn_smv___noe1_noe2_noni& arg1);
		/// assign __syn_smv___no_noe1e2_noe1ni_noe2ni 
		mv&operator=(const __syn_smv___no_noe1e2_noe1ni_noe2ni& arg1);
		/// assign __syn_smv___scalar_e1e2_e1ni 
		mv&operator=(const __syn_smv___scalar_e1e2_e1ni& arg1);
		/// assign __syn_smv___e1_e2_ni_e1e2ni 
		mv&operator=(const __syn_smv___e1_e2_ni_e1e2ni& arg1);
		/// assign __syn_smv___scalar_e1e2_e2ni 
		mv&operator=(const __syn_smv___scalar_e1e2_e2ni& arg1);
		/// assign __syn_smv___scalarf0_0 
		mv&operator=(const __syn_smv___scalarf0_0& arg1);
		/// assign __syn_smv___ni_e1e2ni 
		mv&operator=(const __syn_smv___ni_e1e2ni& arg1);


		void compress(Float epsilon = 0.0);
		inline Float const *nullFloats() const {
			static Float *nf = NULL;
			if (nf == NULL) nf = new Float[16];
			return nf;
		}
		void expand(const Float *ptrs[], bool nulls = true) const;
		/// returns the absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// converts this multvector to an array of basis blade bitmaps and coordinates (returns number of blades)
		int toBasisBladeBitmapArray(unsigned int *bitmaps, Float *coords);

		/// coordinate extraction by name
		inline Float no() const {
			if (gu() & 2)
				return m_c[mv_size[gu() & 1] + 0];
			else return (float)0.0;
		}
		inline Float e1() const {
			if (gu() & 2)
				return m_c[mv_size[gu() & 1] + 1];
			else return (float)0.0;
		}
		inline Float e2() const {
			if (gu() & 2)
				return m_c[mv_size[gu() & 1] + 2];
			else return (float)0.0;
		}
		inline Float ni() const {
			if (gu() & 2)
				return m_c[mv_size[gu() & 1] + 3];
			else return (float)0.0;
		}
		inline Float noe1() const {
			if (gu() & 4)
				return m_c[mv_size[gu() & 3] + 0];
			else return (float)0.0;
		}
		inline Float noe2() const {
			if (gu() & 4)
				return m_c[mv_size[gu() & 3] + 1];
			else return (float)0.0;
		}
		inline Float e1e2() const {
			if (gu() & 4)
				return m_c[mv_size[gu() & 3] + 2];
			else return (float)0.0;
		}
		inline Float e1ni() const {
			if (gu() & 4)
				return m_c[mv_size[gu() & 3] + 3];
			else return (float)0.0;
		}
		inline Float e2ni() const {
			if (gu() & 4)
				return m_c[mv_size[gu() & 3] + 4];
			else return (float)0.0;
		}
		inline Float noni() const {
			if (gu() & 4)
				return m_c[mv_size[gu() & 3] + 5];
			else return (float)0.0;
		}
		inline Float e1e2ni() const {
			if (gu() & 8)
				return m_c[mv_size[gu() & 7] + 0];
			else return (float)0.0;
		}
		inline Float noe1ni() const {
			if (gu() & 8)
				return m_c[mv_size[gu() & 7] + 1];
			else return (float)0.0;
		}
		inline Float noe2ni() const {
			if (gu() & 8)
				return m_c[mv_size[gu() & 7] + 2];
			else return (float)0.0;
		}
		inline Float noe1e2() const {
			if (gu() & 8)
				return m_c[mv_size[gu() & 7] + 3];
			else return (float)0.0;
		}
		inline Float noe1e2ni() const {
			if (gu() & 16)
				return m_c[mv_size[gu() & 15] + 0];
			else return (float)0.0;
		}

		// coordinate storage, grade usage
		Float m_c[16]; ///< coordinate storage (TODO: if parity pure, allocate only half of the coordinates!!!)
		unsigned int m_gu; ///< grade usage
		inline unsigned int gu() const {return m_gu;}
		inline void gu(unsigned int g) {m_gu = g;}



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}
		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}
		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}



	}; // end of class mv 

	char *string(const mv & obj, char *str, int maxLength, const char *fp = NULL);
	// this function should be deprecated (conflicts with C++ stdlib)
	char *string(const mv & obj, const char *fp = NULL);


	mv mv_compress(const float *coordinates, float epsilon = (float)0.0, int gu = 16 * 2 -1);
	mv mv_compress(int nbBlades, const unsigned int *bitmaps, const mv::Float *coords);


	// underscore 'constructors' for float types:

	/// returns scalar part of arg1 as float
	inline float _float(const mv & arg1) {
		return (arg1.m_gu & 1) ? (float)arg1.m_c[0] : 0.0f;
	}
	/// returns scalar part of arg1 as double
	inline double _double(const mv & arg1) {
		return (arg1.m_gu & 1) ? (double)arg1.m_c[0] : 0.0;
	}
	/// returns scalar part of arg1 as Float
	inline float _Float(const mv & arg1) {
		return (arg1.m_gu & 1) ? arg1.m_c[0] : (float)0.0;
	}

	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline const mv like(const mv &what, const mv &example) {return what;}
	inline mv like(mv &what, const mv &example) {return what;}


	/// converts this multvector to an array of basis blade bitmaps and coordinates  (returns number of blades)
	inline int mv::toBasisBladeBitmapArray(unsigned int *bitmaps, mv::Float *coords) {	
		int idxB = 0;
		int idxC = 0;
		if (m_gu & 1) {
			if (m_c[idxC] != (Float)0.0) {
				bitmaps[idxB] = 0; coords[idxB] = m_c[idxC]; idxB++;}
			idxC++;
		}
		if (m_gu & 2) {
			if (m_c[idxC] != (Float)0.0) {
				bitmaps[idxB] = 1; coords[idxB] = m_c[idxC]; idxB++;}
			idxC++;
			if (m_c[idxC] != (Float)0.0) {
				bitmaps[idxB] = 2; coords[idxB] = m_c[idxC]; idxB++;}
			idxC++;
			if (m_c[idxC] != (Float)0.0) {
				bitmaps[idxB] = 4; coords[idxB] = m_c[idxC]; idxB++;}
			idxC++;
			if (m_c[idxC] != (Float)0.0) {
				bitmaps[idxB] = 8; coords[idxB] = m_c[idxC]; idxB++;}
			idxC++;
		}
		if (m_gu & 4) {
			if (m_c[idxC] != (Float)0.0) {
				bitmaps[idxB] = 3; coords[idxB] = m_c[idxC]; idxB++;}
			idxC++;
			if (m_c[idxC] != (Float)0.0) {
				bitmaps[idxB] = 5; coords[idxB] = m_c[idxC]; idxB++;}
			idxC++;
			if (m_c[idxC] != (Float)0.0) {
				bitmaps[idxB] = 6; coords[idxB] = m_c[idxC]; idxB++;}
			idxC++;
			if (m_c[idxC] != (Float)0.0) {
				bitmaps[idxB] = 10; coords[idxB] = m_c[idxC]; idxB++;}
			idxC++;
			if (m_c[idxC] != (Float)0.0) {
				bitmaps[idxB] = 12; coords[idxB] = m_c[idxC]; idxB++;}
			idxC++;
			if (m_c[idxC] != (Float)0.0) {
				bitmaps[idxB] = 9; coords[idxB] = m_c[idxC]; idxB++;}
			idxC++;
		}
		if (m_gu & 8) {
			if (m_c[idxC] != (Float)0.0) {
				bitmaps[idxB] = 14; coords[idxB] = m_c[idxC]; idxB++;}
			idxC++;
			if (m_c[idxC] != (Float)0.0) {
				bitmaps[idxB] = 11; coords[idxB] = m_c[idxC]; idxB++;}
			idxC++;
			if (m_c[idxC] != (Float)0.0) {
				bitmaps[idxB] = 13; coords[idxB] = m_c[idxC]; idxB++;}
			idxC++;
			if (m_c[idxC] != (Float)0.0) {
				bitmaps[idxB] = 7; coords[idxB] = m_c[idxC]; idxB++;}
			idxC++;
		}
		if (m_gu & 16) {
			if (m_c[idxC] != (Float)0.0) {
				bitmaps[idxB] = 15; coords[idxB] = m_c[idxC]; idxB++;}
			idxC++;
		}
		return idxB;
	}


	/// enum for the coordinates of no_t 
	enum __no_t_coordinates__ {no_t_no};

	class no_t {
		public:
			typedef float Float;

		/// zero constructor
		inline no_t() {

			set();
		}

		/// scalar constructor 
		inline no_t(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> no_t	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline no_t(const no_t &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline no_t(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> no_t	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline no_t(__no_t_coordinates__, const Float *coordinates) {

			set(no_t_no, coordinates);
		}

		/// coordinates constructor
		inline no_t(__no_t_coordinates__, Float c_no) {

			set(no_t_no, c_no);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const no_t &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__no_t_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__no_t_coordinates__, Float c_no);

		/// assign copy
		no_t &operator=(const no_t &arg1);

		/// assign general multivector
		no_t &operator=(const mv &arg1);

		/// assign scalar
		no_t &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float no() const {
			return m_c[0];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__no_t_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[1];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class no_t 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline no_t _no_t(const mv &arg1) {
		return no_t(arg1, 0);
	}
	/// from const specialization class:
	inline const no_t &_no_t(const no_t &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline no_t &_no_t(no_t &arg1) {
		return arg1;
	}
	/// from Float:
	inline no_t _no_t(no_t::Float arg1) {
		return no_t(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline no_t like(const mv &what, const no_t &example) {return _no_t(what);}
	/// from const specialization class:
	inline const no_t like(const no_t &what, const no_t &example) {return _no_t(what);}
	/// from non-const specialization class:
	inline no_t like(no_t &what, const no_t &example) {return _no_t(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const no_t & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const no_t & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const no_t & v) {
		return (float)0;
	}


	/// enum for the coordinates of e1_t 
	enum __e1_t_coordinates__ {e1_t_e1};

	class e1_t {
		public:
			typedef float Float;

		/// zero constructor
		inline e1_t() {

			set();
		}

		/// scalar constructor 
		inline e1_t(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> e1_t	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline e1_t(const e1_t &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline e1_t(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> e1_t	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline e1_t(__e1_t_coordinates__, const Float *coordinates) {

			set(e1_t_e1, coordinates);
		}

		/// coordinates constructor
		inline e1_t(__e1_t_coordinates__, Float c_e1) {

			set(e1_t_e1, c_e1);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const e1_t &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__e1_t_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__e1_t_coordinates__, Float c_e1);

		/// assign copy
		e1_t &operator=(const e1_t &arg1);

		/// assign general multivector
		e1_t &operator=(const mv &arg1);

		/// assign scalar
		e1_t &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1() const {
			return m_c[0];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__e1_t_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[1];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class e1_t 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline e1_t _e1_t(const mv &arg1) {
		return e1_t(arg1, 0);
	}
	/// from const specialization class:
	inline const e1_t &_e1_t(const e1_t &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline e1_t &_e1_t(e1_t &arg1) {
		return arg1;
	}
	/// from Float:
	inline e1_t _e1_t(e1_t::Float arg1) {
		return e1_t(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline e1_t like(const mv &what, const e1_t &example) {return _e1_t(what);}
	/// from const specialization class:
	inline const e1_t like(const e1_t &what, const e1_t &example) {return _e1_t(what);}
	/// from non-const specialization class:
	inline e1_t like(e1_t &what, const e1_t &example) {return _e1_t(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const e1_t & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const e1_t & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const e1_t & v) {
		return (float)0;
	}


	/// enum for the coordinates of e2_t 
	enum __e2_t_coordinates__ {e2_t_e2};

	class e2_t {
		public:
			typedef float Float;

		/// zero constructor
		inline e2_t() {

			set();
		}

		/// scalar constructor 
		inline e2_t(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> e2_t	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline e2_t(const e2_t &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline e2_t(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> e2_t	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline e2_t(__e2_t_coordinates__, const Float *coordinates) {

			set(e2_t_e2, coordinates);
		}

		/// coordinates constructor
		inline e2_t(__e2_t_coordinates__, Float c_e2) {

			set(e2_t_e2, c_e2);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const e2_t &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__e2_t_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__e2_t_coordinates__, Float c_e2);

		/// assign copy
		e2_t &operator=(const e2_t &arg1);

		/// assign general multivector
		e2_t &operator=(const mv &arg1);

		/// assign scalar
		e2_t &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e2() const {
			return m_c[0];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__e2_t_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[1];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class e2_t 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline e2_t _e2_t(const mv &arg1) {
		return e2_t(arg1, 0);
	}
	/// from const specialization class:
	inline const e2_t &_e2_t(const e2_t &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline e2_t &_e2_t(e2_t &arg1) {
		return arg1;
	}
	/// from Float:
	inline e2_t _e2_t(e2_t::Float arg1) {
		return e2_t(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline e2_t like(const mv &what, const e2_t &example) {return _e2_t(what);}
	/// from const specialization class:
	inline const e2_t like(const e2_t &what, const e2_t &example) {return _e2_t(what);}
	/// from non-const specialization class:
	inline e2_t like(e2_t &what, const e2_t &example) {return _e2_t(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const e2_t & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const e2_t & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const e2_t & v) {
		return (float)0;
	}


	/// enum for the coordinates of ni_t 
	enum __ni_t_coordinates__ {ni_t_ni};

	class ni_t {
		public:
			typedef float Float;

		/// zero constructor
		inline ni_t() {

			set();
		}

		/// scalar constructor 
		inline ni_t(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> ni_t	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline ni_t(const ni_t &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline ni_t(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> ni_t	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline ni_t(__ni_t_coordinates__, const Float *coordinates) {

			set(ni_t_ni, coordinates);
		}

		/// coordinates constructor
		inline ni_t(__ni_t_coordinates__, Float c_ni) {

			set(ni_t_ni, c_ni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const ni_t &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__ni_t_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__ni_t_coordinates__, Float c_ni);

		/// assign copy
		ni_t &operator=(const ni_t &arg1);

		/// assign general multivector
		ni_t &operator=(const mv &arg1);

		/// assign scalar
		ni_t &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float ni() const {
			return m_c[0];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__ni_t_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[1];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class ni_t 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline ni_t _ni_t(const mv &arg1) {
		return ni_t(arg1, 0);
	}
	/// from const specialization class:
	inline const ni_t &_ni_t(const ni_t &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline ni_t &_ni_t(ni_t &arg1) {
		return arg1;
	}
	/// from Float:
	inline ni_t _ni_t(ni_t::Float arg1) {
		return ni_t(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline ni_t like(const mv &what, const ni_t &example) {return _ni_t(what);}
	/// from const specialization class:
	inline const ni_t like(const ni_t &what, const ni_t &example) {return _ni_t(what);}
	/// from non-const specialization class:
	inline ni_t like(ni_t &what, const ni_t &example) {return _ni_t(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const ni_t & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const ni_t & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const ni_t & v) {
		return (float)0;
	}


	/// enum for the coordinates of scalar 
	enum __scalar_coordinates__ {scalar_scalar};

	class scalar {
		public:
			typedef float Float;

		/// zero constructor
		inline scalar() {

			set();
		}

		/// scalar constructor 
		inline scalar(Float s) {

			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline scalar(const scalar &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline scalar(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> scalar	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline scalar(__scalar_coordinates__, const Float *coordinates) {

			set(scalar_scalar, coordinates);
		}

		/// coordinates constructor
		inline scalar(__scalar_coordinates__, Float c_scalar) {

			set(scalar_scalar, c_scalar);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const scalar &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__scalar_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__scalar_coordinates__, Float c_scalar);

		/// assign copy
		scalar &operator=(const scalar &arg1);

		/// assign general multivector
		scalar &operator=(const mv &arg1);

		/// assign scalar
		scalar &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__scalar_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[1];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class scalar 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline scalar _scalar(const mv &arg1) {
		return scalar(arg1, 0);
	}
	/// from const specialization class:
	inline const scalar &_scalar(const scalar &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline scalar &_scalar(scalar &arg1) {
		return arg1;
	}
	/// from Float:
	inline scalar _scalar(scalar::Float arg1) {
		return scalar(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline scalar like(const mv &what, const scalar &example) {return _scalar(what);}
	/// from const specialization class:
	inline const scalar like(const scalar &what, const scalar &example) {return _scalar(what);}
	/// from non-const specialization class:
	inline scalar like(scalar &what, const scalar &example) {return _scalar(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const scalar & v) {
		return (float)v.m_c[0];
	}
	/// returns scalar part of v as double
	inline double _double(const scalar & v) {
		return (double)v.m_c[0];
	}
	/// returns scalar part of v as Float
	inline float _Float(const scalar & v) {
		return v.m_c[0];
	}


	/// enum for the coordinates of point 
	enum __point_coordinates__ {point_no_e1_e2_ni};

	class point {
		public:
			typedef float Float;

		/// zero constructor
		inline point() {

			set();
		}

		/// scalar constructor 
		inline point(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> point	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline point(const point &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline point(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> point	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline point(__point_coordinates__, const Float *coordinates) {

			set(point_no_e1_e2_ni, coordinates);
		}

		/// coordinates constructor
		inline point(__point_coordinates__, Float c_no, Float c_e1, Float c_e2, Float c_ni) {

			set(point_no_e1_e2_ni, c_no, c_e1, c_e2, c_ni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const point &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__point_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__point_coordinates__, Float c_no, Float c_e1, Float c_e2, Float c_ni);

		/// assign copy
		point &operator=(const point &arg1);

		/// assign general multivector
		point &operator=(const mv &arg1);

		/// assign scalar
		point &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float no() const {
			return m_c[0];
		}
		inline Float e1() const {
			return m_c[1];
		}
		inline Float e2() const {
			return m_c[2];
		}
		inline Float ni() const {
			return m_c[3];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__point_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[4];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class point 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline point _point(const mv &arg1) {
		return point(arg1, 0);
	}
	/// from const specialization class:
	inline const point &_point(const point &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline point &_point(point &arg1) {
		return arg1;
	}
	/// from Float:
	inline point _point(point::Float arg1) {
		return point(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline point like(const mv &what, const point &example) {return _point(what);}
	/// from const specialization class:
	inline const point like(const point &what, const point &example) {return _point(what);}
	/// from non-const specialization class:
	inline point like(point &what, const point &example) {return _point(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const point & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const point & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const point & v) {
		return (float)0;
	}


	/// enum for the coordinates of normalizedPoint 
	enum __normalizedPoint_coordinates__ {normalizedPoint_e1_e2_ni_nof1_0};

	class normalizedPoint {
		public:
			typedef float Float;

		/// zero constructor
		inline normalizedPoint() {

			set();
		}

		/// scalar constructor 
		inline normalizedPoint(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> normalizedPoint	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline normalizedPoint(const normalizedPoint &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline normalizedPoint(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> normalizedPoint	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline normalizedPoint(__normalizedPoint_coordinates__, const Float *coordinates) {

			set(normalizedPoint_e1_e2_ni_nof1_0, coordinates);
		}

		/// coordinates constructor
		inline normalizedPoint(__normalizedPoint_coordinates__, Float c_e1, Float c_e2, Float c_ni) {

			set(normalizedPoint_e1_e2_ni_nof1_0, c_e1, c_e2, c_ni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const normalizedPoint &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__normalizedPoint_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__normalizedPoint_coordinates__, Float c_e1, Float c_e2, Float c_ni);

		/// assign copy
		normalizedPoint &operator=(const normalizedPoint &arg1);

		/// assign general multivector
		normalizedPoint &operator=(const mv &arg1);

		/// assign scalar
		normalizedPoint &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1() const {
			return m_c[0];
		}
		inline Float e2() const {
			return m_c[1];
		}
		inline Float ni() const {
			return m_c[2];
		}

		/// const coordinate extraction by name
		inline Float no() const {
			return 1.0f;
		}

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__normalizedPoint_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[3];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class normalizedPoint 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline normalizedPoint _normalizedPoint(const mv &arg1) {
		return normalizedPoint(arg1, 0);
	}
	/// from const specialization class:
	inline const normalizedPoint &_normalizedPoint(const normalizedPoint &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline normalizedPoint &_normalizedPoint(normalizedPoint &arg1) {
		return arg1;
	}
	/// from Float:
	inline normalizedPoint _normalizedPoint(normalizedPoint::Float arg1) {
		return normalizedPoint(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline normalizedPoint like(const mv &what, const normalizedPoint &example) {return _normalizedPoint(what);}
	/// from const specialization class:
	inline const normalizedPoint like(const normalizedPoint &what, const normalizedPoint &example) {return _normalizedPoint(what);}
	/// from non-const specialization class:
	inline normalizedPoint like(normalizedPoint &what, const normalizedPoint &example) {return _normalizedPoint(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const normalizedPoint & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const normalizedPoint & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const normalizedPoint & v) {
		return (float)0;
	}


	/// enum for the coordinates of flatPoint 
	enum __flatPoint_coordinates__ {flatPoint_e1ni_e2ni_noni};

	class flatPoint {
		public:
			typedef float Float;

		/// zero constructor
		inline flatPoint() {

			set();
		}

		/// scalar constructor 
		inline flatPoint(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> flatPoint	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline flatPoint(const flatPoint &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline flatPoint(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> flatPoint	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline flatPoint(__flatPoint_coordinates__, const Float *coordinates) {

			set(flatPoint_e1ni_e2ni_noni, coordinates);
		}

		/// coordinates constructor
		inline flatPoint(__flatPoint_coordinates__, Float c_e1ni, Float c_e2ni, Float c_noni) {

			set(flatPoint_e1ni_e2ni_noni, c_e1ni, c_e2ni, c_noni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const flatPoint &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__flatPoint_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__flatPoint_coordinates__, Float c_e1ni, Float c_e2ni, Float c_noni);

		/// assign copy
		flatPoint &operator=(const flatPoint &arg1);

		/// assign general multivector
		flatPoint &operator=(const mv &arg1);

		/// assign scalar
		flatPoint &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1ni() const {
			return m_c[0];
		}
		inline Float e2ni() const {
			return m_c[1];
		}
		inline Float noni() const {
			return m_c[2];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__flatPoint_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[3];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class flatPoint 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline flatPoint _flatPoint(const mv &arg1) {
		return flatPoint(arg1, 0);
	}
	/// from const specialization class:
	inline const flatPoint &_flatPoint(const flatPoint &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline flatPoint &_flatPoint(flatPoint &arg1) {
		return arg1;
	}
	/// from Float:
	inline flatPoint _flatPoint(flatPoint::Float arg1) {
		return flatPoint(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline flatPoint like(const mv &what, const flatPoint &example) {return _flatPoint(what);}
	/// from const specialization class:
	inline const flatPoint like(const flatPoint &what, const flatPoint &example) {return _flatPoint(what);}
	/// from non-const specialization class:
	inline flatPoint like(flatPoint &what, const flatPoint &example) {return _flatPoint(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const flatPoint & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const flatPoint & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const flatPoint & v) {
		return (float)0;
	}


	/// enum for the coordinates of normalizedFlatPoint 
	enum __normalizedFlatPoint_coordinates__ {normalizedFlatPoint_e1ni_e2ni_nonif1_0};

	class normalizedFlatPoint {
		public:
			typedef float Float;

		/// zero constructor
		inline normalizedFlatPoint() {

			set();
		}

		/// scalar constructor 
		inline normalizedFlatPoint(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> normalizedFlatPoint	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline normalizedFlatPoint(const normalizedFlatPoint &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline normalizedFlatPoint(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> normalizedFlatPoint	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline normalizedFlatPoint(__normalizedFlatPoint_coordinates__, const Float *coordinates) {

			set(normalizedFlatPoint_e1ni_e2ni_nonif1_0, coordinates);
		}

		/// coordinates constructor
		inline normalizedFlatPoint(__normalizedFlatPoint_coordinates__, Float c_e1ni, Float c_e2ni) {

			set(normalizedFlatPoint_e1ni_e2ni_nonif1_0, c_e1ni, c_e2ni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const normalizedFlatPoint &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__normalizedFlatPoint_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__normalizedFlatPoint_coordinates__, Float c_e1ni, Float c_e2ni);

		/// assign copy
		normalizedFlatPoint &operator=(const normalizedFlatPoint &arg1);

		/// assign general multivector
		normalizedFlatPoint &operator=(const mv &arg1);

		/// assign scalar
		normalizedFlatPoint &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1ni() const {
			return m_c[0];
		}
		inline Float e2ni() const {
			return m_c[1];
		}

		/// const coordinate extraction by name
		inline Float noni() const {
			return 1.0f;
		}

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__normalizedFlatPoint_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[2];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class normalizedFlatPoint 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline normalizedFlatPoint _normalizedFlatPoint(const mv &arg1) {
		return normalizedFlatPoint(arg1, 0);
	}
	/// from const specialization class:
	inline const normalizedFlatPoint &_normalizedFlatPoint(const normalizedFlatPoint &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline normalizedFlatPoint &_normalizedFlatPoint(normalizedFlatPoint &arg1) {
		return arg1;
	}
	/// from Float:
	inline normalizedFlatPoint _normalizedFlatPoint(normalizedFlatPoint::Float arg1) {
		return normalizedFlatPoint(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline normalizedFlatPoint like(const mv &what, const normalizedFlatPoint &example) {return _normalizedFlatPoint(what);}
	/// from const specialization class:
	inline const normalizedFlatPoint like(const normalizedFlatPoint &what, const normalizedFlatPoint &example) {return _normalizedFlatPoint(what);}
	/// from non-const specialization class:
	inline normalizedFlatPoint like(normalizedFlatPoint &what, const normalizedFlatPoint &example) {return _normalizedFlatPoint(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const normalizedFlatPoint & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const normalizedFlatPoint & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const normalizedFlatPoint & v) {
		return (float)0;
	}


	/// enum for the coordinates of pointPair 
	enum __pointPair_coordinates__ {pointPair_noe1_noe2_e1e2_e1ni_e2ni_noni};

	class pointPair {
		public:
			typedef float Float;

		/// zero constructor
		inline pointPair() {

			set();
		}

		/// scalar constructor 
		inline pointPair(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> pointPair	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline pointPair(const pointPair &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline pointPair(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> pointPair	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline pointPair(__pointPair_coordinates__, const Float *coordinates) {

			set(pointPair_noe1_noe2_e1e2_e1ni_e2ni_noni, coordinates);
		}

		/// coordinates constructor
		inline pointPair(__pointPair_coordinates__, Float c_noe1, Float c_noe2, Float c_e1e2, Float c_e1ni, Float c_e2ni, Float c_noni) {

			set(pointPair_noe1_noe2_e1e2_e1ni_e2ni_noni, c_noe1, c_noe2, c_e1e2, c_e1ni, c_e2ni, c_noni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const pointPair &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__pointPair_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__pointPair_coordinates__, Float c_noe1, Float c_noe2, Float c_e1e2, Float c_e1ni, Float c_e2ni, Float c_noni);

		/// assign copy
		pointPair &operator=(const pointPair &arg1);

		/// assign general multivector
		pointPair &operator=(const mv &arg1);

		/// assign scalar
		pointPair &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float noe1() const {
			return m_c[0];
		}
		inline Float noe2() const {
			return m_c[1];
		}
		inline Float e1e2() const {
			return m_c[2];
		}
		inline Float e1ni() const {
			return m_c[3];
		}
		inline Float e2ni() const {
			return m_c[4];
		}
		inline Float noni() const {
			return m_c[5];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__pointPair_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[6];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class pointPair 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline pointPair _pointPair(const mv &arg1) {
		return pointPair(arg1, 0);
	}
	/// from const specialization class:
	inline const pointPair &_pointPair(const pointPair &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline pointPair &_pointPair(pointPair &arg1) {
		return arg1;
	}
	/// from Float:
	inline pointPair _pointPair(pointPair::Float arg1) {
		return pointPair(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline pointPair like(const mv &what, const pointPair &example) {return _pointPair(what);}
	/// from const specialization class:
	inline const pointPair like(const pointPair &what, const pointPair &example) {return _pointPair(what);}
	/// from non-const specialization class:
	inline pointPair like(pointPair &what, const pointPair &example) {return _pointPair(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const pointPair & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const pointPair & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const pointPair & v) {
		return (float)0;
	}


	/// enum for the coordinates of TRversorLog 
	enum __TRversorLog_coordinates__ {TRversorLog_e1e2_e1ni_e2ni};

	class TRversorLog {
		public:
			typedef float Float;

		/// zero constructor
		inline TRversorLog() {

			set();
		}

		/// scalar constructor 
		inline TRversorLog(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> TRversorLog	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline TRversorLog(const TRversorLog &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline TRversorLog(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> TRversorLog	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline TRversorLog(__TRversorLog_coordinates__, const Float *coordinates) {

			set(TRversorLog_e1e2_e1ni_e2ni, coordinates);
		}

		/// coordinates constructor
		inline TRversorLog(__TRversorLog_coordinates__, Float c_e1e2, Float c_e1ni, Float c_e2ni) {

			set(TRversorLog_e1e2_e1ni_e2ni, c_e1e2, c_e1ni, c_e2ni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const TRversorLog &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__TRversorLog_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__TRversorLog_coordinates__, Float c_e1e2, Float c_e1ni, Float c_e2ni);

		/// assign copy
		TRversorLog &operator=(const TRversorLog &arg1);

		/// assign general multivector
		TRversorLog &operator=(const mv &arg1);

		/// assign scalar
		TRversorLog &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1e2() const {
			return m_c[0];
		}
		inline Float e1ni() const {
			return m_c[1];
		}
		inline Float e2ni() const {
			return m_c[2];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__TRversorLog_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[3];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class TRversorLog 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline TRversorLog _TRversorLog(const mv &arg1) {
		return TRversorLog(arg1, 0);
	}
	/// from const specialization class:
	inline const TRversorLog &_TRversorLog(const TRversorLog &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline TRversorLog &_TRversorLog(TRversorLog &arg1) {
		return arg1;
	}
	/// from Float:
	inline TRversorLog _TRversorLog(TRversorLog::Float arg1) {
		return TRversorLog(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline TRversorLog like(const mv &what, const TRversorLog &example) {return _TRversorLog(what);}
	/// from const specialization class:
	inline const TRversorLog like(const TRversorLog &what, const TRversorLog &example) {return _TRversorLog(what);}
	/// from non-const specialization class:
	inline TRversorLog like(TRversorLog &what, const TRversorLog &example) {return _TRversorLog(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const TRversorLog & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const TRversorLog & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const TRversorLog & v) {
		return (float)0;
	}


	/// enum for the coordinates of line 
	enum __line_coordinates__ {line_e1e2ni_e1noni_e2noni};

	class line {
		public:
			typedef float Float;

		/// zero constructor
		inline line() {

			set();
		}

		/// scalar constructor 
		inline line(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> line	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline line(const line &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline line(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> line	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline line(__line_coordinates__, const Float *coordinates) {

			set(line_e1e2ni_e1noni_e2noni, coordinates);
		}

		/// coordinates constructor
		inline line(__line_coordinates__, Float c_e1e2ni, Float c_e1noni, Float c_e2noni) {

			set(line_e1e2ni_e1noni_e2noni, c_e1e2ni, c_e1noni, c_e2noni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const line &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__line_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__line_coordinates__, Float c_e1e2ni, Float c_e1noni, Float c_e2noni);

		/// assign copy
		line &operator=(const line &arg1);

		/// assign general multivector
		line &operator=(const mv &arg1);

		/// assign scalar
		line &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1e2ni() const {
			return m_c[0];
		}
		inline Float e1noni() const {
			return m_c[1];
		}
		inline Float e2noni() const {
			return m_c[2];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__line_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[3];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class line 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline line _line(const mv &arg1) {
		return line(arg1, 0);
	}
	/// from const specialization class:
	inline const line &_line(const line &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline line &_line(line &arg1) {
		return arg1;
	}
	/// from Float:
	inline line _line(line::Float arg1) {
		return line(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline line like(const mv &what, const line &example) {return _line(what);}
	/// from const specialization class:
	inline const line like(const line &what, const line &example) {return _line(what);}
	/// from non-const specialization class:
	inline line like(line &what, const line &example) {return _line(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const line & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const line & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const line & v) {
		return (float)0;
	}


	/// enum for the coordinates of dualLine 
	enum __dualLine_coordinates__ {dualLine_e1e2_e1ni_e2ni};

	class dualLine {
		public:
			typedef float Float;

		/// zero constructor
		inline dualLine() {

			set();
		}

		/// scalar constructor 
		inline dualLine(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> dualLine	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline dualLine(const dualLine &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline dualLine(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> dualLine	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline dualLine(__dualLine_coordinates__, const Float *coordinates) {

			set(dualLine_e1e2_e1ni_e2ni, coordinates);
		}

		/// coordinates constructor
		inline dualLine(__dualLine_coordinates__, Float c_e1e2, Float c_e1ni, Float c_e2ni) {

			set(dualLine_e1e2_e1ni_e2ni, c_e1e2, c_e1ni, c_e2ni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const dualLine &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__dualLine_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__dualLine_coordinates__, Float c_e1e2, Float c_e1ni, Float c_e2ni);

		/// assign copy
		dualLine &operator=(const dualLine &arg1);

		/// assign general multivector
		dualLine &operator=(const mv &arg1);

		/// assign scalar
		dualLine &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1e2() const {
			return m_c[0];
		}
		inline Float e1ni() const {
			return m_c[1];
		}
		inline Float e2ni() const {
			return m_c[2];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__dualLine_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[3];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class dualLine 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline dualLine _dualLine(const mv &arg1) {
		return dualLine(arg1, 0);
	}
	/// from const specialization class:
	inline const dualLine &_dualLine(const dualLine &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline dualLine &_dualLine(dualLine &arg1) {
		return arg1;
	}
	/// from Float:
	inline dualLine _dualLine(dualLine::Float arg1) {
		return dualLine(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline dualLine like(const mv &what, const dualLine &example) {return _dualLine(what);}
	/// from const specialization class:
	inline const dualLine like(const dualLine &what, const dualLine &example) {return _dualLine(what);}
	/// from non-const specialization class:
	inline dualLine like(dualLine &what, const dualLine &example) {return _dualLine(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const dualLine & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const dualLine & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const dualLine & v) {
		return (float)0;
	}


	/// enum for the coordinates of circle 
	enum __circle_coordinates__ {circle_e1e2ni_noe1ni_noe2ni_noe1e2};

	class circle {
		public:
			typedef float Float;

		/// zero constructor
		inline circle() {

			set();
		}

		/// scalar constructor 
		inline circle(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> circle	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline circle(const circle &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline circle(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> circle	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline circle(__circle_coordinates__, const Float *coordinates) {

			set(circle_e1e2ni_noe1ni_noe2ni_noe1e2, coordinates);
		}

		/// coordinates constructor
		inline circle(__circle_coordinates__, Float c_e1e2ni, Float c_noe1ni, Float c_noe2ni, Float c_noe1e2) {

			set(circle_e1e2ni_noe1ni_noe2ni_noe1e2, c_e1e2ni, c_noe1ni, c_noe2ni, c_noe1e2);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const circle &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__circle_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__circle_coordinates__, Float c_e1e2ni, Float c_noe1ni, Float c_noe2ni, Float c_noe1e2);

		/// assign copy
		circle &operator=(const circle &arg1);

		/// assign general multivector
		circle &operator=(const mv &arg1);

		/// assign scalar
		circle &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1e2ni() const {
			return m_c[0];
		}
		inline Float noe1ni() const {
			return m_c[1];
		}
		inline Float noe2ni() const {
			return m_c[2];
		}
		inline Float noe1e2() const {
			return m_c[3];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__circle_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[4];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class circle 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline circle _circle(const mv &arg1) {
		return circle(arg1, 0);
	}
	/// from const specialization class:
	inline const circle &_circle(const circle &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline circle &_circle(circle &arg1) {
		return arg1;
	}
	/// from Float:
	inline circle _circle(circle::Float arg1) {
		return circle(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline circle like(const mv &what, const circle &example) {return _circle(what);}
	/// from const specialization class:
	inline const circle like(const circle &what, const circle &example) {return _circle(what);}
	/// from non-const specialization class:
	inline circle like(circle &what, const circle &example) {return _circle(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const circle & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const circle & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const circle & v) {
		return (float)0;
	}


	/// enum for the coordinates of freeVector 
	enum __freeVector_coordinates__ {freeVector_e1ni_e2ni};

	class freeVector {
		public:
			typedef float Float;

		/// zero constructor
		inline freeVector() {

			set();
		}

		/// scalar constructor 
		inline freeVector(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> freeVector	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline freeVector(const freeVector &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline freeVector(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> freeVector	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline freeVector(__freeVector_coordinates__, const Float *coordinates) {

			set(freeVector_e1ni_e2ni, coordinates);
		}

		/// coordinates constructor
		inline freeVector(__freeVector_coordinates__, Float c_e1ni, Float c_e2ni) {

			set(freeVector_e1ni_e2ni, c_e1ni, c_e2ni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const freeVector &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__freeVector_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__freeVector_coordinates__, Float c_e1ni, Float c_e2ni);

		/// assign copy
		freeVector &operator=(const freeVector &arg1);

		/// assign general multivector
		freeVector &operator=(const mv &arg1);

		/// assign scalar
		freeVector &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1ni() const {
			return m_c[0];
		}
		inline Float e2ni() const {
			return m_c[1];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__freeVector_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[2];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class freeVector 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline freeVector _freeVector(const mv &arg1) {
		return freeVector(arg1, 0);
	}
	/// from const specialization class:
	inline const freeVector &_freeVector(const freeVector &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline freeVector &_freeVector(freeVector &arg1) {
		return arg1;
	}
	/// from Float:
	inline freeVector _freeVector(freeVector::Float arg1) {
		return freeVector(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline freeVector like(const mv &what, const freeVector &example) {return _freeVector(what);}
	/// from const specialization class:
	inline const freeVector like(const freeVector &what, const freeVector &example) {return _freeVector(what);}
	/// from non-const specialization class:
	inline freeVector like(freeVector &what, const freeVector &example) {return _freeVector(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const freeVector & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const freeVector & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const freeVector & v) {
		return (float)0;
	}


	/// enum for the coordinates of freeBivector 
	enum __freeBivector_coordinates__ {freeBivector_e1e2ni};

	class freeBivector {
		public:
			typedef float Float;

		/// zero constructor
		inline freeBivector() {

			set();
		}

		/// scalar constructor 
		inline freeBivector(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> freeBivector	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline freeBivector(const freeBivector &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline freeBivector(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> freeBivector	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline freeBivector(__freeBivector_coordinates__, const Float *coordinates) {

			set(freeBivector_e1e2ni, coordinates);
		}

		/// coordinates constructor
		inline freeBivector(__freeBivector_coordinates__, Float c_e1e2ni) {

			set(freeBivector_e1e2ni, c_e1e2ni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const freeBivector &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__freeBivector_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__freeBivector_coordinates__, Float c_e1e2ni);

		/// assign copy
		freeBivector &operator=(const freeBivector &arg1);

		/// assign general multivector
		freeBivector &operator=(const mv &arg1);

		/// assign scalar
		freeBivector &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1e2ni() const {
			return m_c[0];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__freeBivector_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[1];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class freeBivector 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline freeBivector _freeBivector(const mv &arg1) {
		return freeBivector(arg1, 0);
	}
	/// from const specialization class:
	inline const freeBivector &_freeBivector(const freeBivector &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline freeBivector &_freeBivector(freeBivector &arg1) {
		return arg1;
	}
	/// from Float:
	inline freeBivector _freeBivector(freeBivector::Float arg1) {
		return freeBivector(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline freeBivector like(const mv &what, const freeBivector &example) {return _freeBivector(what);}
	/// from const specialization class:
	inline const freeBivector like(const freeBivector &what, const freeBivector &example) {return _freeBivector(what);}
	/// from non-const specialization class:
	inline freeBivector like(freeBivector &what, const freeBivector &example) {return _freeBivector(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const freeBivector & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const freeBivector & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const freeBivector & v) {
		return (float)0;
	}


	/// enum for the coordinates of tangentVector 
	enum __tangentVector_coordinates__ {tangentVector_noe1_noe2_e1e2_e1ni_e2ni_noni};

	class tangentVector {
		public:
			typedef float Float;

		/// zero constructor
		inline tangentVector() {

			set();
		}

		/// scalar constructor 
		inline tangentVector(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> tangentVector	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline tangentVector(const tangentVector &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline tangentVector(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> tangentVector	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline tangentVector(__tangentVector_coordinates__, const Float *coordinates) {

			set(tangentVector_noe1_noe2_e1e2_e1ni_e2ni_noni, coordinates);
		}

		/// coordinates constructor
		inline tangentVector(__tangentVector_coordinates__, Float c_noe1, Float c_noe2, Float c_e1e2, Float c_e1ni, Float c_e2ni, Float c_noni) {

			set(tangentVector_noe1_noe2_e1e2_e1ni_e2ni_noni, c_noe1, c_noe2, c_e1e2, c_e1ni, c_e2ni, c_noni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const tangentVector &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__tangentVector_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__tangentVector_coordinates__, Float c_noe1, Float c_noe2, Float c_e1e2, Float c_e1ni, Float c_e2ni, Float c_noni);

		/// assign copy
		tangentVector &operator=(const tangentVector &arg1);

		/// assign general multivector
		tangentVector &operator=(const mv &arg1);

		/// assign scalar
		tangentVector &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float noe1() const {
			return m_c[0];
		}
		inline Float noe2() const {
			return m_c[1];
		}
		inline Float e1e2() const {
			return m_c[2];
		}
		inline Float e1ni() const {
			return m_c[3];
		}
		inline Float e2ni() const {
			return m_c[4];
		}
		inline Float noni() const {
			return m_c[5];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__tangentVector_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[6];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class tangentVector 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline tangentVector _tangentVector(const mv &arg1) {
		return tangentVector(arg1, 0);
	}
	/// from const specialization class:
	inline const tangentVector &_tangentVector(const tangentVector &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline tangentVector &_tangentVector(tangentVector &arg1) {
		return arg1;
	}
	/// from Float:
	inline tangentVector _tangentVector(tangentVector::Float arg1) {
		return tangentVector(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline tangentVector like(const mv &what, const tangentVector &example) {return _tangentVector(what);}
	/// from const specialization class:
	inline const tangentVector like(const tangentVector &what, const tangentVector &example) {return _tangentVector(what);}
	/// from non-const specialization class:
	inline tangentVector like(tangentVector &what, const tangentVector &example) {return _tangentVector(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const tangentVector & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const tangentVector & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const tangentVector & v) {
		return (float)0;
	}


	/// enum for the coordinates of tangentBivector 
	enum __tangentBivector_coordinates__ {tangentBivector_e1e2ni_noe1ni_noe2ni_noe1e2};

	class tangentBivector {
		public:
			typedef float Float;

		/// zero constructor
		inline tangentBivector() {

			set();
		}

		/// scalar constructor 
		inline tangentBivector(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> tangentBivector	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline tangentBivector(const tangentBivector &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline tangentBivector(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> tangentBivector	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline tangentBivector(__tangentBivector_coordinates__, const Float *coordinates) {

			set(tangentBivector_e1e2ni_noe1ni_noe2ni_noe1e2, coordinates);
		}

		/// coordinates constructor
		inline tangentBivector(__tangentBivector_coordinates__, Float c_e1e2ni, Float c_noe1ni, Float c_noe2ni, Float c_noe1e2) {

			set(tangentBivector_e1e2ni_noe1ni_noe2ni_noe1e2, c_e1e2ni, c_noe1ni, c_noe2ni, c_noe1e2);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const tangentBivector &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__tangentBivector_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__tangentBivector_coordinates__, Float c_e1e2ni, Float c_noe1ni, Float c_noe2ni, Float c_noe1e2);

		/// assign copy
		tangentBivector &operator=(const tangentBivector &arg1);

		/// assign general multivector
		tangentBivector &operator=(const mv &arg1);

		/// assign scalar
		tangentBivector &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1e2ni() const {
			return m_c[0];
		}
		inline Float noe1ni() const {
			return m_c[1];
		}
		inline Float noe2ni() const {
			return m_c[2];
		}
		inline Float noe1e2() const {
			return m_c[3];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__tangentBivector_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[4];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class tangentBivector 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline tangentBivector _tangentBivector(const mv &arg1) {
		return tangentBivector(arg1, 0);
	}
	/// from const specialization class:
	inline const tangentBivector &_tangentBivector(const tangentBivector &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline tangentBivector &_tangentBivector(tangentBivector &arg1) {
		return arg1;
	}
	/// from Float:
	inline tangentBivector _tangentBivector(tangentBivector::Float arg1) {
		return tangentBivector(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline tangentBivector like(const mv &what, const tangentBivector &example) {return _tangentBivector(what);}
	/// from const specialization class:
	inline const tangentBivector like(const tangentBivector &what, const tangentBivector &example) {return _tangentBivector(what);}
	/// from non-const specialization class:
	inline tangentBivector like(tangentBivector &what, const tangentBivector &example) {return _tangentBivector(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const tangentBivector & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const tangentBivector & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const tangentBivector & v) {
		return (float)0;
	}


	/// enum for the coordinates of vectorE2GA 
	enum __vectorE2GA_coordinates__ {vectorE2GA_e1_e2};

	class vectorE2GA {
		public:
			typedef float Float;

		/// zero constructor
		inline vectorE2GA() {

			set();
		}

		/// scalar constructor 
		inline vectorE2GA(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> vectorE2GA	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline vectorE2GA(const vectorE2GA &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline vectorE2GA(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> vectorE2GA	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline vectorE2GA(__vectorE2GA_coordinates__, const Float *coordinates) {

			set(vectorE2GA_e1_e2, coordinates);
		}

		/// coordinates constructor
		inline vectorE2GA(__vectorE2GA_coordinates__, Float c_e1, Float c_e2) {

			set(vectorE2GA_e1_e2, c_e1, c_e2);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const vectorE2GA &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__vectorE2GA_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__vectorE2GA_coordinates__, Float c_e1, Float c_e2);

		/// assign copy
		vectorE2GA &operator=(const vectorE2GA &arg1);

		/// assign general multivector
		vectorE2GA &operator=(const mv &arg1);

		/// assign scalar
		vectorE2GA &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1() const {
			return m_c[0];
		}
		inline Float e2() const {
			return m_c[1];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__vectorE2GA_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[2];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class vectorE2GA 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline vectorE2GA _vectorE2GA(const mv &arg1) {
		return vectorE2GA(arg1, 0);
	}
	/// from const specialization class:
	inline const vectorE2GA &_vectorE2GA(const vectorE2GA &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline vectorE2GA &_vectorE2GA(vectorE2GA &arg1) {
		return arg1;
	}
	/// from Float:
	inline vectorE2GA _vectorE2GA(vectorE2GA::Float arg1) {
		return vectorE2GA(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline vectorE2GA like(const mv &what, const vectorE2GA &example) {return _vectorE2GA(what);}
	/// from const specialization class:
	inline const vectorE2GA like(const vectorE2GA &what, const vectorE2GA &example) {return _vectorE2GA(what);}
	/// from non-const specialization class:
	inline vectorE2GA like(vectorE2GA &what, const vectorE2GA &example) {return _vectorE2GA(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const vectorE2GA & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const vectorE2GA & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const vectorE2GA & v) {
		return (float)0;
	}


	/// enum for the coordinates of bivectorE2GA 
	enum __bivectorE2GA_coordinates__ {bivectorE2GA_e1e2};

	class bivectorE2GA {
		public:
			typedef float Float;

		/// zero constructor
		inline bivectorE2GA() {

			set();
		}

		/// scalar constructor 
		inline bivectorE2GA(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> bivectorE2GA	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline bivectorE2GA(const bivectorE2GA &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline bivectorE2GA(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> bivectorE2GA	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline bivectorE2GA(__bivectorE2GA_coordinates__, const Float *coordinates) {

			set(bivectorE2GA_e1e2, coordinates);
		}

		/// coordinates constructor
		inline bivectorE2GA(__bivectorE2GA_coordinates__, Float c_e1e2) {

			set(bivectorE2GA_e1e2, c_e1e2);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const bivectorE2GA &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__bivectorE2GA_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__bivectorE2GA_coordinates__, Float c_e1e2);

		/// assign copy
		bivectorE2GA &operator=(const bivectorE2GA &arg1);

		/// assign general multivector
		bivectorE2GA &operator=(const mv &arg1);

		/// assign scalar
		bivectorE2GA &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1e2() const {
			return m_c[0];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__bivectorE2GA_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[1];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class bivectorE2GA 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline bivectorE2GA _bivectorE2GA(const mv &arg1) {
		return bivectorE2GA(arg1, 0);
	}
	/// from const specialization class:
	inline const bivectorE2GA &_bivectorE2GA(const bivectorE2GA &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline bivectorE2GA &_bivectorE2GA(bivectorE2GA &arg1) {
		return arg1;
	}
	/// from Float:
	inline bivectorE2GA _bivectorE2GA(bivectorE2GA::Float arg1) {
		return bivectorE2GA(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline bivectorE2GA like(const mv &what, const bivectorE2GA &example) {return _bivectorE2GA(what);}
	/// from const specialization class:
	inline const bivectorE2GA like(const bivectorE2GA &what, const bivectorE2GA &example) {return _bivectorE2GA(what);}
	/// from non-const specialization class:
	inline bivectorE2GA like(bivectorE2GA &what, const bivectorE2GA &example) {return _bivectorE2GA(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const bivectorE2GA & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const bivectorE2GA & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const bivectorE2GA & v) {
		return (float)0;
	}


	/// enum for the coordinates of TRversor 
	enum __TRversor_coordinates__ {TRversor_scalar_e1e2_e1ni_e2ni};

	class TRversor {
		public:
			typedef float Float;

		/// zero constructor
		inline TRversor() {

			set();
		}

		/// scalar constructor 
		inline TRversor(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> TRversor	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline TRversor(const TRversor &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline TRversor(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> TRversor	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline TRversor(__TRversor_coordinates__, const Float *coordinates) {

			set(TRversor_scalar_e1e2_e1ni_e2ni, coordinates);
		}

		/// coordinates constructor
		inline TRversor(__TRversor_coordinates__, Float c_scalar, Float c_e1e2, Float c_e1ni, Float c_e2ni) {

			set(TRversor_scalar_e1e2_e1ni_e2ni, c_scalar, c_e1e2, c_e1ni, c_e2ni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const TRversor &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__TRversor_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__TRversor_coordinates__, Float c_scalar, Float c_e1e2, Float c_e1ni, Float c_e2ni);

		/// assign copy
		TRversor &operator=(const TRversor &arg1);

		/// assign general multivector
		TRversor &operator=(const mv &arg1);

		/// assign scalar
		TRversor &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1e2() const {
			return m_c[1];
		}
		inline Float e1ni() const {
			return m_c[2];
		}
		inline Float e2ni() const {
			return m_c[3];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__TRversor_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[4];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class TRversor 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline TRversor _TRversor(const mv &arg1) {
		return TRversor(arg1, 0);
	}
	/// from const specialization class:
	inline const TRversor &_TRversor(const TRversor &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline TRversor &_TRversor(TRversor &arg1) {
		return arg1;
	}
	/// from Float:
	inline TRversor _TRversor(TRversor::Float arg1) {
		return TRversor(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline TRversor like(const mv &what, const TRversor &example) {return _TRversor(what);}
	/// from const specialization class:
	inline const TRversor like(const TRversor &what, const TRversor &example) {return _TRversor(what);}
	/// from non-const specialization class:
	inline TRversor like(TRversor &what, const TRversor &example) {return _TRversor(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const TRversor & v) {
		return (float)v.m_c[0];
	}
	/// returns scalar part of v as double
	inline double _double(const TRversor & v) {
		return (double)v.m_c[0];
	}
	/// returns scalar part of v as Float
	inline float _Float(const TRversor & v) {
		return v.m_c[0];
	}


	/// enum for the coordinates of TRSversor 
	enum __TRSversor_coordinates__ {TRSversor_scalar_e1e2_e1ni_e2ni_noni_e1e2noni};

	class TRSversor {
		public:
			typedef float Float;

		/// zero constructor
		inline TRSversor() {

			set();
		}

		/// scalar constructor 
		inline TRSversor(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> TRSversor	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline TRSversor(const TRSversor &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline TRSversor(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> TRSversor	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline TRSversor(__TRSversor_coordinates__, const Float *coordinates) {

			set(TRSversor_scalar_e1e2_e1ni_e2ni_noni_e1e2noni, coordinates);
		}

		/// coordinates constructor
		inline TRSversor(__TRSversor_coordinates__, Float c_scalar, Float c_e1e2, Float c_e1ni, Float c_e2ni, Float c_noni, Float c_e1e2noni) {

			set(TRSversor_scalar_e1e2_e1ni_e2ni_noni_e1e2noni, c_scalar, c_e1e2, c_e1ni, c_e2ni, c_noni, c_e1e2noni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const TRSversor &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__TRSversor_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__TRSversor_coordinates__, Float c_scalar, Float c_e1e2, Float c_e1ni, Float c_e2ni, Float c_noni, Float c_e1e2noni);

		/// assign copy
		TRSversor &operator=(const TRSversor &arg1);

		/// assign general multivector
		TRSversor &operator=(const mv &arg1);

		/// assign scalar
		TRSversor &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1e2() const {
			return m_c[1];
		}
		inline Float e1ni() const {
			return m_c[2];
		}
		inline Float e2ni() const {
			return m_c[3];
		}
		inline Float noni() const {
			return m_c[4];
		}
		inline Float e1e2noni() const {
			return m_c[5];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__TRSversor_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[6];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class TRSversor 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline TRSversor _TRSversor(const mv &arg1) {
		return TRSversor(arg1, 0);
	}
	/// from const specialization class:
	inline const TRSversor &_TRSversor(const TRSversor &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline TRSversor &_TRSversor(TRSversor &arg1) {
		return arg1;
	}
	/// from Float:
	inline TRSversor _TRSversor(TRSversor::Float arg1) {
		return TRSversor(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline TRSversor like(const mv &what, const TRSversor &example) {return _TRSversor(what);}
	/// from const specialization class:
	inline const TRSversor like(const TRSversor &what, const TRSversor &example) {return _TRSversor(what);}
	/// from non-const specialization class:
	inline TRSversor like(TRSversor &what, const TRSversor &example) {return _TRSversor(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const TRSversor & v) {
		return (float)v.m_c[0];
	}
	/// returns scalar part of v as double
	inline double _double(const TRSversor & v) {
		return (double)v.m_c[0];
	}
	/// returns scalar part of v as Float
	inline float _Float(const TRSversor & v) {
		return v.m_c[0];
	}


	/// enum for the coordinates of evenVersor 
	enum __evenVersor_coordinates__ {evenVersor_scalar_noe1_noe2_e1e2_e1ni_e2ni_noni_e1e2noni};

	class evenVersor {
		public:
			typedef float Float;

		/// zero constructor
		inline evenVersor() {

			set();
		}

		/// scalar constructor 
		inline evenVersor(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> evenVersor	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline evenVersor(const evenVersor &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline evenVersor(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> evenVersor	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline evenVersor(__evenVersor_coordinates__, const Float *coordinates) {

			set(evenVersor_scalar_noe1_noe2_e1e2_e1ni_e2ni_noni_e1e2noni, coordinates);
		}

		/// coordinates constructor
		inline evenVersor(__evenVersor_coordinates__, Float c_scalar, Float c_noe1, Float c_noe2, Float c_e1e2, Float c_e1ni, Float c_e2ni, Float c_noni, Float c_e1e2noni) {

			set(evenVersor_scalar_noe1_noe2_e1e2_e1ni_e2ni_noni_e1e2noni, c_scalar, c_noe1, c_noe2, c_e1e2, c_e1ni, c_e2ni, c_noni, c_e1e2noni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const evenVersor &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__evenVersor_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__evenVersor_coordinates__, Float c_scalar, Float c_noe1, Float c_noe2, Float c_e1e2, Float c_e1ni, Float c_e2ni, Float c_noni, Float c_e1e2noni);

		/// assign copy
		evenVersor &operator=(const evenVersor &arg1);

		/// assign general multivector
		evenVersor &operator=(const mv &arg1);

		/// assign scalar
		evenVersor &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float noe1() const {
			return m_c[1];
		}
		inline Float noe2() const {
			return m_c[2];
		}
		inline Float e1e2() const {
			return m_c[3];
		}
		inline Float e1ni() const {
			return m_c[4];
		}
		inline Float e2ni() const {
			return m_c[5];
		}
		inline Float noni() const {
			return m_c[6];
		}
		inline Float e1e2noni() const {
			return m_c[7];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__evenVersor_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[8];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class evenVersor 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline evenVersor _evenVersor(const mv &arg1) {
		return evenVersor(arg1, 0);
	}
	/// from const specialization class:
	inline const evenVersor &_evenVersor(const evenVersor &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline evenVersor &_evenVersor(evenVersor &arg1) {
		return arg1;
	}
	/// from Float:
	inline evenVersor _evenVersor(evenVersor::Float arg1) {
		return evenVersor(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline evenVersor like(const mv &what, const evenVersor &example) {return _evenVersor(what);}
	/// from const specialization class:
	inline const evenVersor like(const evenVersor &what, const evenVersor &example) {return _evenVersor(what);}
	/// from non-const specialization class:
	inline evenVersor like(evenVersor &what, const evenVersor &example) {return _evenVersor(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const evenVersor & v) {
		return (float)v.m_c[0];
	}
	/// returns scalar part of v as double
	inline double _double(const evenVersor & v) {
		return (double)v.m_c[0];
	}
	/// returns scalar part of v as Float
	inline float _Float(const evenVersor & v) {
		return v.m_c[0];
	}


	/// enum for the coordinates of translator 
	enum __translator_coordinates__ {translator_scalar_e1ni_e2ni};

	class translator {
		public:
			typedef float Float;

		/// zero constructor
		inline translator() {

			set();
		}

		/// scalar constructor 
		inline translator(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> translator	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline translator(const translator &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline translator(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> translator	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline translator(__translator_coordinates__, const Float *coordinates) {

			set(translator_scalar_e1ni_e2ni, coordinates);
		}

		/// coordinates constructor
		inline translator(__translator_coordinates__, Float c_scalar, Float c_e1ni, Float c_e2ni) {

			set(translator_scalar_e1ni_e2ni, c_scalar, c_e1ni, c_e2ni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const translator &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__translator_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__translator_coordinates__, Float c_scalar, Float c_e1ni, Float c_e2ni);

		/// assign copy
		translator &operator=(const translator &arg1);

		/// assign general multivector
		translator &operator=(const mv &arg1);

		/// assign scalar
		translator &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1ni() const {
			return m_c[1];
		}
		inline Float e2ni() const {
			return m_c[2];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__translator_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[3];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class translator 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline translator _translator(const mv &arg1) {
		return translator(arg1, 0);
	}
	/// from const specialization class:
	inline const translator &_translator(const translator &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline translator &_translator(translator &arg1) {
		return arg1;
	}
	/// from Float:
	inline translator _translator(translator::Float arg1) {
		return translator(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline translator like(const mv &what, const translator &example) {return _translator(what);}
	/// from const specialization class:
	inline const translator like(const translator &what, const translator &example) {return _translator(what);}
	/// from non-const specialization class:
	inline translator like(translator &what, const translator &example) {return _translator(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const translator & v) {
		return (float)v.m_c[0];
	}
	/// returns scalar part of v as double
	inline double _double(const translator & v) {
		return (double)v.m_c[0];
	}
	/// returns scalar part of v as Float
	inline float _Float(const translator & v) {
		return v.m_c[0];
	}


	/// enum for the coordinates of normalizedTranslator 
	enum __normalizedTranslator_coordinates__ {normalizedTranslator_e1ni_e2ni_scalarf1_0};

	class normalizedTranslator {
		public:
			typedef float Float;

		/// zero constructor
		inline normalizedTranslator() {

			set();
		}

		/// scalar constructor 
		inline normalizedTranslator(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> normalizedTranslator	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline normalizedTranslator(const normalizedTranslator &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline normalizedTranslator(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> normalizedTranslator	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline normalizedTranslator(__normalizedTranslator_coordinates__, const Float *coordinates) {

			set(normalizedTranslator_e1ni_e2ni_scalarf1_0, coordinates);
		}

		/// coordinates constructor
		inline normalizedTranslator(__normalizedTranslator_coordinates__, Float c_e1ni, Float c_e2ni) {

			set(normalizedTranslator_e1ni_e2ni_scalarf1_0, c_e1ni, c_e2ni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const normalizedTranslator &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__normalizedTranslator_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__normalizedTranslator_coordinates__, Float c_e1ni, Float c_e2ni);

		/// assign copy
		normalizedTranslator &operator=(const normalizedTranslator &arg1);

		/// assign general multivector
		normalizedTranslator &operator=(const mv &arg1);

		/// assign scalar
		normalizedTranslator &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1ni() const {
			return m_c[0];
		}
		inline Float e2ni() const {
			return m_c[1];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__normalizedTranslator_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[2];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class normalizedTranslator 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline normalizedTranslator _normalizedTranslator(const mv &arg1) {
		return normalizedTranslator(arg1, 0);
	}
	/// from const specialization class:
	inline const normalizedTranslator &_normalizedTranslator(const normalizedTranslator &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline normalizedTranslator &_normalizedTranslator(normalizedTranslator &arg1) {
		return arg1;
	}
	/// from Float:
	inline normalizedTranslator _normalizedTranslator(normalizedTranslator::Float arg1) {
		return normalizedTranslator(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline normalizedTranslator like(const mv &what, const normalizedTranslator &example) {return _normalizedTranslator(what);}
	/// from const specialization class:
	inline const normalizedTranslator like(const normalizedTranslator &what, const normalizedTranslator &example) {return _normalizedTranslator(what);}
	/// from non-const specialization class:
	inline normalizedTranslator like(normalizedTranslator &what, const normalizedTranslator &example) {return _normalizedTranslator(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const normalizedTranslator & v) {
		return (float)1.0f;
	}
	/// returns scalar part of v as double
	inline double _double(const normalizedTranslator & v) {
		return (double)1.0f;
	}
	/// returns scalar part of v as Float
	inline float _Float(const normalizedTranslator & v) {
		return (float)1.0f;
	}


	/// enum for the coordinates of rotor 
	enum __rotor_coordinates__ {rotor_scalar_e1e2};

	class rotor {
		public:
			typedef float Float;

		/// zero constructor
		inline rotor() {

			set();
		}

		/// scalar constructor 
		inline rotor(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> rotor	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline rotor(const rotor &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline rotor(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> rotor	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline rotor(__rotor_coordinates__, const Float *coordinates) {

			set(rotor_scalar_e1e2, coordinates);
		}

		/// coordinates constructor
		inline rotor(__rotor_coordinates__, Float c_scalar, Float c_e1e2) {

			set(rotor_scalar_e1e2, c_scalar, c_e1e2);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const rotor &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__rotor_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__rotor_coordinates__, Float c_scalar, Float c_e1e2);

		/// assign copy
		rotor &operator=(const rotor &arg1);

		/// assign general multivector
		rotor &operator=(const mv &arg1);

		/// assign scalar
		rotor &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1e2() const {
			return m_c[1];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__rotor_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[2];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class rotor 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline rotor _rotor(const mv &arg1) {
		return rotor(arg1, 0);
	}
	/// from const specialization class:
	inline const rotor &_rotor(const rotor &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline rotor &_rotor(rotor &arg1) {
		return arg1;
	}
	/// from Float:
	inline rotor _rotor(rotor::Float arg1) {
		return rotor(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline rotor like(const mv &what, const rotor &example) {return _rotor(what);}
	/// from const specialization class:
	inline const rotor like(const rotor &what, const rotor &example) {return _rotor(what);}
	/// from non-const specialization class:
	inline rotor like(rotor &what, const rotor &example) {return _rotor(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const rotor & v) {
		return (float)v.m_c[0];
	}
	/// returns scalar part of v as double
	inline double _double(const rotor & v) {
		return (double)v.m_c[0];
	}
	/// returns scalar part of v as Float
	inline float _Float(const rotor & v) {
		return v.m_c[0];
	}


	/// enum for the coordinates of scalor 
	enum __scalor_coordinates__ {scalor_scalar_noni};

	class scalor {
		public:
			typedef float Float;

		/// zero constructor
		inline scalor() {

			set();
		}

		/// scalar constructor 
		inline scalor(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> scalor	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline scalor(const scalor &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline scalor(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> scalor	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline scalor(__scalor_coordinates__, const Float *coordinates) {

			set(scalor_scalar_noni, coordinates);
		}

		/// coordinates constructor
		inline scalor(__scalor_coordinates__, Float c_scalar, Float c_noni) {

			set(scalor_scalar_noni, c_scalar, c_noni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const scalor &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__scalor_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__scalor_coordinates__, Float c_scalar, Float c_noni);

		/// assign copy
		scalor &operator=(const scalor &arg1);

		/// assign general multivector
		scalor &operator=(const mv &arg1);

		/// assign scalar
		scalor &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float noni() const {
			return m_c[1];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(__scalor_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[2];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class scalor 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline scalor _scalor(const mv &arg1) {
		return scalor(arg1, 0);
	}
	/// from const specialization class:
	inline const scalor &_scalor(const scalor &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline scalor &_scalor(scalor &arg1) {
		return arg1;
	}
	/// from Float:
	inline scalor _scalor(scalor::Float arg1) {
		return scalor(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline scalor like(const mv &what, const scalor &example) {return _scalor(what);}
	/// from const specialization class:
	inline const scalor like(const scalor &what, const scalor &example) {return _scalor(what);}
	/// from non-const specialization class:
	inline scalor like(scalor &what, const scalor &example) {return _scalor(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const scalor & v) {
		return (float)v.m_c[0];
	}
	/// returns scalar part of v as double
	inline double _double(const scalor & v) {
		return (double)v.m_c[0];
	}
	/// returns scalar part of v as Float
	inline float _Float(const scalor & v) {
		return v.m_c[0];
	}


	/// enum for the coordinates of __no_ct__ 
	enum ____no_ct___coordinates__ {__no_ct___nof1_0};

	class __no_ct__ {
		public:
			typedef float Float;

		/// zero constructor
		inline __no_ct__() {

			set();
		}

		/// scalar constructor 
		inline __no_ct__(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __no_ct__	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __no_ct__(const __no_ct__ &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __no_ct__(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __no_ct__	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __no_ct__(____no_ct___coordinates__, const Float *coordinates) {

			set(__no_ct___nof1_0, coordinates);
		}

		/// coordinates constructor
		inline __no_ct__(____no_ct___coordinates__) {

			set(__no_ct___nof1_0);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __no_ct__ &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____no_ct___coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____no_ct___coordinates__);

		/// assign copy
		__no_ct__ &operator=(const __no_ct__ &arg1);

		/// assign general multivector
		__no_ct__ &operator=(const mv &arg1);

		/// assign scalar
		__no_ct__ &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name

		/// const coordinate extraction by name
		inline Float nof1_0() const {
			return 1.0f;
		}

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____no_ct___coordinates__ sanityCheckValue) const {
			return NULL;
		}

		// constants, so no coordinate storage



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __no_ct__ 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __no_ct__ ___no_ct__(const mv &arg1) {
		return __no_ct__(arg1, 0);
	}
	/// from const specialization class:
	inline const __no_ct__ &___no_ct__(const __no_ct__ &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __no_ct__ &___no_ct__(__no_ct__ &arg1) {
		return arg1;
	}
	/// from Float:
	inline __no_ct__ ___no_ct__(__no_ct__::Float arg1) {
		return __no_ct__(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __no_ct__ like(const mv &what, const __no_ct__ &example) {return ___no_ct__(what);}
	/// from const specialization class:
	inline const __no_ct__ like(const __no_ct__ &what, const __no_ct__ &example) {return ___no_ct__(what);}
	/// from non-const specialization class:
	inline __no_ct__ like(__no_ct__ &what, const __no_ct__ &example) {return ___no_ct__(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __no_ct__ & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __no_ct__ & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __no_ct__ & v) {
		return (float)0;
	}


	/// enum for the coordinates of __e1_ct__ 
	enum ____e1_ct___coordinates__ {__e1_ct___e1f1_0};

	class __e1_ct__ {
		public:
			typedef float Float;

		/// zero constructor
		inline __e1_ct__() {

			set();
		}

		/// scalar constructor 
		inline __e1_ct__(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __e1_ct__	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __e1_ct__(const __e1_ct__ &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __e1_ct__(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __e1_ct__	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __e1_ct__(____e1_ct___coordinates__, const Float *coordinates) {

			set(__e1_ct___e1f1_0, coordinates);
		}

		/// coordinates constructor
		inline __e1_ct__(____e1_ct___coordinates__) {

			set(__e1_ct___e1f1_0);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __e1_ct__ &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____e1_ct___coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____e1_ct___coordinates__);

		/// assign copy
		__e1_ct__ &operator=(const __e1_ct__ &arg1);

		/// assign general multivector
		__e1_ct__ &operator=(const mv &arg1);

		/// assign scalar
		__e1_ct__ &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name

		/// const coordinate extraction by name
		inline Float e1f1_0() const {
			return 1.0f;
		}

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____e1_ct___coordinates__ sanityCheckValue) const {
			return NULL;
		}

		// constants, so no coordinate storage



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __e1_ct__ 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __e1_ct__ ___e1_ct__(const mv &arg1) {
		return __e1_ct__(arg1, 0);
	}
	/// from const specialization class:
	inline const __e1_ct__ &___e1_ct__(const __e1_ct__ &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __e1_ct__ &___e1_ct__(__e1_ct__ &arg1) {
		return arg1;
	}
	/// from Float:
	inline __e1_ct__ ___e1_ct__(__e1_ct__::Float arg1) {
		return __e1_ct__(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __e1_ct__ like(const mv &what, const __e1_ct__ &example) {return ___e1_ct__(what);}
	/// from const specialization class:
	inline const __e1_ct__ like(const __e1_ct__ &what, const __e1_ct__ &example) {return ___e1_ct__(what);}
	/// from non-const specialization class:
	inline __e1_ct__ like(__e1_ct__ &what, const __e1_ct__ &example) {return ___e1_ct__(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __e1_ct__ & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __e1_ct__ & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __e1_ct__ & v) {
		return (float)0;
	}


	/// enum for the coordinates of __e2_ct__ 
	enum ____e2_ct___coordinates__ {__e2_ct___e2f1_0};

	class __e2_ct__ {
		public:
			typedef float Float;

		/// zero constructor
		inline __e2_ct__() {

			set();
		}

		/// scalar constructor 
		inline __e2_ct__(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __e2_ct__	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __e2_ct__(const __e2_ct__ &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __e2_ct__(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __e2_ct__	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __e2_ct__(____e2_ct___coordinates__, const Float *coordinates) {

			set(__e2_ct___e2f1_0, coordinates);
		}

		/// coordinates constructor
		inline __e2_ct__(____e2_ct___coordinates__) {

			set(__e2_ct___e2f1_0);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __e2_ct__ &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____e2_ct___coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____e2_ct___coordinates__);

		/// assign copy
		__e2_ct__ &operator=(const __e2_ct__ &arg1);

		/// assign general multivector
		__e2_ct__ &operator=(const mv &arg1);

		/// assign scalar
		__e2_ct__ &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name

		/// const coordinate extraction by name
		inline Float e2f1_0() const {
			return 1.0f;
		}

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____e2_ct___coordinates__ sanityCheckValue) const {
			return NULL;
		}

		// constants, so no coordinate storage



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __e2_ct__ 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __e2_ct__ ___e2_ct__(const mv &arg1) {
		return __e2_ct__(arg1, 0);
	}
	/// from const specialization class:
	inline const __e2_ct__ &___e2_ct__(const __e2_ct__ &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __e2_ct__ &___e2_ct__(__e2_ct__ &arg1) {
		return arg1;
	}
	/// from Float:
	inline __e2_ct__ ___e2_ct__(__e2_ct__::Float arg1) {
		return __e2_ct__(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __e2_ct__ like(const mv &what, const __e2_ct__ &example) {return ___e2_ct__(what);}
	/// from const specialization class:
	inline const __e2_ct__ like(const __e2_ct__ &what, const __e2_ct__ &example) {return ___e2_ct__(what);}
	/// from non-const specialization class:
	inline __e2_ct__ like(__e2_ct__ &what, const __e2_ct__ &example) {return ___e2_ct__(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __e2_ct__ & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __e2_ct__ & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __e2_ct__ & v) {
		return (float)0;
	}


	/// enum for the coordinates of __ni_ct__ 
	enum ____ni_ct___coordinates__ {__ni_ct___nif1_0};

	class __ni_ct__ {
		public:
			typedef float Float;

		/// zero constructor
		inline __ni_ct__() {

			set();
		}

		/// scalar constructor 
		inline __ni_ct__(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __ni_ct__	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __ni_ct__(const __ni_ct__ &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __ni_ct__(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __ni_ct__	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __ni_ct__(____ni_ct___coordinates__, const Float *coordinates) {

			set(__ni_ct___nif1_0, coordinates);
		}

		/// coordinates constructor
		inline __ni_ct__(____ni_ct___coordinates__) {

			set(__ni_ct___nif1_0);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __ni_ct__ &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____ni_ct___coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____ni_ct___coordinates__);

		/// assign copy
		__ni_ct__ &operator=(const __ni_ct__ &arg1);

		/// assign general multivector
		__ni_ct__ &operator=(const mv &arg1);

		/// assign scalar
		__ni_ct__ &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name

		/// const coordinate extraction by name
		inline Float nif1_0() const {
			return 1.0f;
		}

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____ni_ct___coordinates__ sanityCheckValue) const {
			return NULL;
		}

		// constants, so no coordinate storage



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __ni_ct__ 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __ni_ct__ ___ni_ct__(const mv &arg1) {
		return __ni_ct__(arg1, 0);
	}
	/// from const specialization class:
	inline const __ni_ct__ &___ni_ct__(const __ni_ct__ &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __ni_ct__ &___ni_ct__(__ni_ct__ &arg1) {
		return arg1;
	}
	/// from Float:
	inline __ni_ct__ ___ni_ct__(__ni_ct__::Float arg1) {
		return __ni_ct__(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __ni_ct__ like(const mv &what, const __ni_ct__ &example) {return ___ni_ct__(what);}
	/// from const specialization class:
	inline const __ni_ct__ like(const __ni_ct__ &what, const __ni_ct__ &example) {return ___ni_ct__(what);}
	/// from non-const specialization class:
	inline __ni_ct__ like(__ni_ct__ &what, const __ni_ct__ &example) {return ___ni_ct__(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __ni_ct__ & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __ni_ct__ & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __ni_ct__ & v) {
		return (float)0;
	}


	/// enum for the coordinates of __I4i_ct__ 
	enum ____I4i_ct___coordinates__ {__I4i_ct___noe1e2nif_1_0};

	class __I4i_ct__ {
		public:
			typedef float Float;

		/// zero constructor
		inline __I4i_ct__() {

			set();
		}

		/// scalar constructor 
		inline __I4i_ct__(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __I4i_ct__	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __I4i_ct__(const __I4i_ct__ &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __I4i_ct__(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __I4i_ct__	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __I4i_ct__(____I4i_ct___coordinates__, const Float *coordinates) {

			set(__I4i_ct___noe1e2nif_1_0, coordinates);
		}

		/// coordinates constructor
		inline __I4i_ct__(____I4i_ct___coordinates__) {

			set(__I4i_ct___noe1e2nif_1_0);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __I4i_ct__ &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____I4i_ct___coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____I4i_ct___coordinates__);

		/// assign copy
		__I4i_ct__ &operator=(const __I4i_ct__ &arg1);

		/// assign general multivector
		__I4i_ct__ &operator=(const mv &arg1);

		/// assign scalar
		__I4i_ct__ &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name

		/// const coordinate extraction by name
		inline Float noe1e2nif_1_0() const {
			return -1.0f;
		}

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____I4i_ct___coordinates__ sanityCheckValue) const {
			return NULL;
		}

		// constants, so no coordinate storage



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __I4i_ct__ 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __I4i_ct__ ___I4i_ct__(const mv &arg1) {
		return __I4i_ct__(arg1, 0);
	}
	/// from const specialization class:
	inline const __I4i_ct__ &___I4i_ct__(const __I4i_ct__ &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __I4i_ct__ &___I4i_ct__(__I4i_ct__ &arg1) {
		return arg1;
	}
	/// from Float:
	inline __I4i_ct__ ___I4i_ct__(__I4i_ct__::Float arg1) {
		return __I4i_ct__(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __I4i_ct__ like(const mv &what, const __I4i_ct__ &example) {return ___I4i_ct__(what);}
	/// from const specialization class:
	inline const __I4i_ct__ like(const __I4i_ct__ &what, const __I4i_ct__ &example) {return ___I4i_ct__(what);}
	/// from non-const specialization class:
	inline __I4i_ct__ like(__I4i_ct__ &what, const __I4i_ct__ &example) {return ___I4i_ct__(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __I4i_ct__ & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __I4i_ct__ & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __I4i_ct__ & v) {
		return (float)0;
	}


	/// enum for the coordinates of __I4_ct__ 
	enum ____I4_ct___coordinates__ {__I4_ct___noe1e2nif1_0};

	class __I4_ct__ {
		public:
			typedef float Float;

		/// zero constructor
		inline __I4_ct__() {

			set();
		}

		/// scalar constructor 
		inline __I4_ct__(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __I4_ct__	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __I4_ct__(const __I4_ct__ &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __I4_ct__(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __I4_ct__	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __I4_ct__(____I4_ct___coordinates__, const Float *coordinates) {

			set(__I4_ct___noe1e2nif1_0, coordinates);
		}

		/// coordinates constructor
		inline __I4_ct__(____I4_ct___coordinates__) {

			set(__I4_ct___noe1e2nif1_0);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __I4_ct__ &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____I4_ct___coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____I4_ct___coordinates__);

		/// assign copy
		__I4_ct__ &operator=(const __I4_ct__ &arg1);

		/// assign general multivector
		__I4_ct__ &operator=(const mv &arg1);

		/// assign scalar
		__I4_ct__ &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name

		/// const coordinate extraction by name
		inline Float noe1e2nif1_0() const {
			return 1.0f;
		}

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____I4_ct___coordinates__ sanityCheckValue) const {
			return NULL;
		}

		// constants, so no coordinate storage



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __I4_ct__ 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __I4_ct__ ___I4_ct__(const mv &arg1) {
		return __I4_ct__(arg1, 0);
	}
	/// from const specialization class:
	inline const __I4_ct__ &___I4_ct__(const __I4_ct__ &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __I4_ct__ &___I4_ct__(__I4_ct__ &arg1) {
		return arg1;
	}
	/// from Float:
	inline __I4_ct__ ___I4_ct__(__I4_ct__::Float arg1) {
		return __I4_ct__(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __I4_ct__ like(const mv &what, const __I4_ct__ &example) {return ___I4_ct__(what);}
	/// from const specialization class:
	inline const __I4_ct__ like(const __I4_ct__ &what, const __I4_ct__ &example) {return ___I4_ct__(what);}
	/// from non-const specialization class:
	inline __I4_ct__ like(__I4_ct__ &what, const __I4_ct__ &example) {return ___I4_ct__(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __I4_ct__ & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __I4_ct__ & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __I4_ct__ & v) {
		return (float)0;
	}


	/// enum for the coordinates of __I2_ct__ 
	enum ____I2_ct___coordinates__ {__I2_ct___e1e2f1_0};

	class __I2_ct__ {
		public:
			typedef float Float;

		/// zero constructor
		inline __I2_ct__() {

			set();
		}

		/// scalar constructor 
		inline __I2_ct__(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __I2_ct__	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __I2_ct__(const __I2_ct__ &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __I2_ct__(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __I2_ct__	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __I2_ct__(____I2_ct___coordinates__, const Float *coordinates) {

			set(__I2_ct___e1e2f1_0, coordinates);
		}

		/// coordinates constructor
		inline __I2_ct__(____I2_ct___coordinates__) {

			set(__I2_ct___e1e2f1_0);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __I2_ct__ &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____I2_ct___coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____I2_ct___coordinates__);

		/// assign copy
		__I2_ct__ &operator=(const __I2_ct__ &arg1);

		/// assign general multivector
		__I2_ct__ &operator=(const mv &arg1);

		/// assign scalar
		__I2_ct__ &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name

		/// const coordinate extraction by name
		inline Float e1e2f1_0() const {
			return 1.0f;
		}

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____I2_ct___coordinates__ sanityCheckValue) const {
			return NULL;
		}

		// constants, so no coordinate storage



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __I2_ct__ 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __I2_ct__ ___I2_ct__(const mv &arg1) {
		return __I2_ct__(arg1, 0);
	}
	/// from const specialization class:
	inline const __I2_ct__ &___I2_ct__(const __I2_ct__ &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __I2_ct__ &___I2_ct__(__I2_ct__ &arg1) {
		return arg1;
	}
	/// from Float:
	inline __I2_ct__ ___I2_ct__(__I2_ct__::Float arg1) {
		return __I2_ct__(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __I2_ct__ like(const mv &what, const __I2_ct__ &example) {return ___I2_ct__(what);}
	/// from const specialization class:
	inline const __I2_ct__ like(const __I2_ct__ &what, const __I2_ct__ &example) {return ___I2_ct__(what);}
	/// from non-const specialization class:
	inline __I2_ct__ like(__I2_ct__ &what, const __I2_ct__ &example) {return ___I2_ct__(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __I2_ct__ & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __I2_ct__ & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __I2_ct__ & v) {
		return (float)0;
	}


	/// enum for the coordinates of __noni_ct__ 
	enum ____noni_ct___coordinates__ {__noni_ct___nonif1_0};

	class __noni_ct__ {
		public:
			typedef float Float;

		/// zero constructor
		inline __noni_ct__() {

			set();
		}

		/// scalar constructor 
		inline __noni_ct__(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __noni_ct__	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __noni_ct__(const __noni_ct__ &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __noni_ct__(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __noni_ct__	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __noni_ct__(____noni_ct___coordinates__, const Float *coordinates) {

			set(__noni_ct___nonif1_0, coordinates);
		}

		/// coordinates constructor
		inline __noni_ct__(____noni_ct___coordinates__) {

			set(__noni_ct___nonif1_0);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __noni_ct__ &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____noni_ct___coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____noni_ct___coordinates__);

		/// assign copy
		__noni_ct__ &operator=(const __noni_ct__ &arg1);

		/// assign general multivector
		__noni_ct__ &operator=(const mv &arg1);

		/// assign scalar
		__noni_ct__ &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name

		/// const coordinate extraction by name
		inline Float nonif1_0() const {
			return 1.0f;
		}

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____noni_ct___coordinates__ sanityCheckValue) const {
			return NULL;
		}

		// constants, so no coordinate storage



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __noni_ct__ 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __noni_ct__ ___noni_ct__(const mv &arg1) {
		return __noni_ct__(arg1, 0);
	}
	/// from const specialization class:
	inline const __noni_ct__ &___noni_ct__(const __noni_ct__ &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __noni_ct__ &___noni_ct__(__noni_ct__ &arg1) {
		return arg1;
	}
	/// from Float:
	inline __noni_ct__ ___noni_ct__(__noni_ct__::Float arg1) {
		return __noni_ct__(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __noni_ct__ like(const mv &what, const __noni_ct__ &example) {return ___noni_ct__(what);}
	/// from const specialization class:
	inline const __noni_ct__ like(const __noni_ct__ &what, const __noni_ct__ &example) {return ___noni_ct__(what);}
	/// from non-const specialization class:
	inline __noni_ct__ like(__noni_ct__ &what, const __noni_ct__ &example) {return ___noni_ct__(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __noni_ct__ & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __noni_ct__ & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __noni_ct__ & v) {
		return (float)0;
	}


	/// enum for the coordinates of __e2ni_ct__ 
	enum ____e2ni_ct___coordinates__ {__e2ni_ct___e2nif1_0};

	class __e2ni_ct__ {
		public:
			typedef float Float;

		/// zero constructor
		inline __e2ni_ct__() {

			set();
		}

		/// scalar constructor 
		inline __e2ni_ct__(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __e2ni_ct__	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __e2ni_ct__(const __e2ni_ct__ &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __e2ni_ct__(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __e2ni_ct__	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __e2ni_ct__(____e2ni_ct___coordinates__, const Float *coordinates) {

			set(__e2ni_ct___e2nif1_0, coordinates);
		}

		/// coordinates constructor
		inline __e2ni_ct__(____e2ni_ct___coordinates__) {

			set(__e2ni_ct___e2nif1_0);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __e2ni_ct__ &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____e2ni_ct___coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____e2ni_ct___coordinates__);

		/// assign copy
		__e2ni_ct__ &operator=(const __e2ni_ct__ &arg1);

		/// assign general multivector
		__e2ni_ct__ &operator=(const mv &arg1);

		/// assign scalar
		__e2ni_ct__ &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name

		/// const coordinate extraction by name
		inline Float e2nif1_0() const {
			return 1.0f;
		}

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____e2ni_ct___coordinates__ sanityCheckValue) const {
			return NULL;
		}

		// constants, so no coordinate storage



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __e2ni_ct__ 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __e2ni_ct__ ___e2ni_ct__(const mv &arg1) {
		return __e2ni_ct__(arg1, 0);
	}
	/// from const specialization class:
	inline const __e2ni_ct__ &___e2ni_ct__(const __e2ni_ct__ &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __e2ni_ct__ &___e2ni_ct__(__e2ni_ct__ &arg1) {
		return arg1;
	}
	/// from Float:
	inline __e2ni_ct__ ___e2ni_ct__(__e2ni_ct__::Float arg1) {
		return __e2ni_ct__(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __e2ni_ct__ like(const mv &what, const __e2ni_ct__ &example) {return ___e2ni_ct__(what);}
	/// from const specialization class:
	inline const __e2ni_ct__ like(const __e2ni_ct__ &what, const __e2ni_ct__ &example) {return ___e2ni_ct__(what);}
	/// from non-const specialization class:
	inline __e2ni_ct__ like(__e2ni_ct__ &what, const __e2ni_ct__ &example) {return ___e2ni_ct__(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __e2ni_ct__ & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __e2ni_ct__ & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __e2ni_ct__ & v) {
		return (float)0;
	}


	/// enum for the coordinates of __e1ni_ct__ 
	enum ____e1ni_ct___coordinates__ {__e1ni_ct___e1nif1_0};

	class __e1ni_ct__ {
		public:
			typedef float Float;

		/// zero constructor
		inline __e1ni_ct__() {

			set();
		}

		/// scalar constructor 
		inline __e1ni_ct__(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __e1ni_ct__	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __e1ni_ct__(const __e1ni_ct__ &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __e1ni_ct__(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __e1ni_ct__	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __e1ni_ct__(____e1ni_ct___coordinates__, const Float *coordinates) {

			set(__e1ni_ct___e1nif1_0, coordinates);
		}

		/// coordinates constructor
		inline __e1ni_ct__(____e1ni_ct___coordinates__) {

			set(__e1ni_ct___e1nif1_0);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __e1ni_ct__ &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____e1ni_ct___coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____e1ni_ct___coordinates__);

		/// assign copy
		__e1ni_ct__ &operator=(const __e1ni_ct__ &arg1);

		/// assign general multivector
		__e1ni_ct__ &operator=(const mv &arg1);

		/// assign scalar
		__e1ni_ct__ &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name

		/// const coordinate extraction by name
		inline Float e1nif1_0() const {
			return 1.0f;
		}

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____e1ni_ct___coordinates__ sanityCheckValue) const {
			return NULL;
		}

		// constants, so no coordinate storage



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __e1ni_ct__ 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __e1ni_ct__ ___e1ni_ct__(const mv &arg1) {
		return __e1ni_ct__(arg1, 0);
	}
	/// from const specialization class:
	inline const __e1ni_ct__ &___e1ni_ct__(const __e1ni_ct__ &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __e1ni_ct__ &___e1ni_ct__(__e1ni_ct__ &arg1) {
		return arg1;
	}
	/// from Float:
	inline __e1ni_ct__ ___e1ni_ct__(__e1ni_ct__::Float arg1) {
		return __e1ni_ct__(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __e1ni_ct__ like(const mv &what, const __e1ni_ct__ &example) {return ___e1ni_ct__(what);}
	/// from const specialization class:
	inline const __e1ni_ct__ like(const __e1ni_ct__ &what, const __e1ni_ct__ &example) {return ___e1ni_ct__(what);}
	/// from non-const specialization class:
	inline __e1ni_ct__ like(__e1ni_ct__ &what, const __e1ni_ct__ &example) {return ___e1ni_ct__(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __e1ni_ct__ & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __e1ni_ct__ & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __e1ni_ct__ & v) {
		return (float)0;
	}


	/// enum for the coordinates of __syn_smv___e1_e2_nof1_0 
	enum ____syn_smv___e1_e2_nof1_0_coordinates__ {__syn_smv___e1_e2_nof1_0_e1_e2_nof1_0};

	class __syn_smv___e1_e2_nof1_0 {
		public:
			typedef float Float;

		/// zero constructor
		inline __syn_smv___e1_e2_nof1_0() {

			set();
		}

		/// scalar constructor 
		inline __syn_smv___e1_e2_nof1_0(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __syn_smv___e1_e2_nof1_0	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __syn_smv___e1_e2_nof1_0(const __syn_smv___e1_e2_nof1_0 &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __syn_smv___e1_e2_nof1_0(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __syn_smv___e1_e2_nof1_0	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __syn_smv___e1_e2_nof1_0(____syn_smv___e1_e2_nof1_0_coordinates__, const Float *coordinates) {

			set(__syn_smv___e1_e2_nof1_0_e1_e2_nof1_0, coordinates);
		}

		/// coordinates constructor
		inline __syn_smv___e1_e2_nof1_0(____syn_smv___e1_e2_nof1_0_coordinates__, Float c_e1, Float c_e2) {

			set(__syn_smv___e1_e2_nof1_0_e1_e2_nof1_0, c_e1, c_e2);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __syn_smv___e1_e2_nof1_0 &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____syn_smv___e1_e2_nof1_0_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____syn_smv___e1_e2_nof1_0_coordinates__, Float c_e1, Float c_e2);

		/// assign copy
		__syn_smv___e1_e2_nof1_0 &operator=(const __syn_smv___e1_e2_nof1_0 &arg1);

		/// assign general multivector
		__syn_smv___e1_e2_nof1_0 &operator=(const mv &arg1);

		/// assign scalar
		__syn_smv___e1_e2_nof1_0 &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1() const {
			return m_c[0];
		}
		inline Float e2() const {
			return m_c[1];
		}

		/// const coordinate extraction by name
		inline Float no() const {
			return 1.0f;
		}

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____syn_smv___e1_e2_nof1_0_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[2];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __syn_smv___e1_e2_nof1_0 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __syn_smv___e1_e2_nof1_0 ___syn_smv___e1_e2_nof1_0(const mv &arg1) {
		return __syn_smv___e1_e2_nof1_0(arg1, 0);
	}
	/// from const specialization class:
	inline const __syn_smv___e1_e2_nof1_0 &___syn_smv___e1_e2_nof1_0(const __syn_smv___e1_e2_nof1_0 &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __syn_smv___e1_e2_nof1_0 &___syn_smv___e1_e2_nof1_0(__syn_smv___e1_e2_nof1_0 &arg1) {
		return arg1;
	}
	/// from Float:
	inline __syn_smv___e1_e2_nof1_0 ___syn_smv___e1_e2_nof1_0(__syn_smv___e1_e2_nof1_0::Float arg1) {
		return __syn_smv___e1_e2_nof1_0(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __syn_smv___e1_e2_nof1_0 like(const mv &what, const __syn_smv___e1_e2_nof1_0 &example) {return ___syn_smv___e1_e2_nof1_0(what);}
	/// from const specialization class:
	inline const __syn_smv___e1_e2_nof1_0 like(const __syn_smv___e1_e2_nof1_0 &what, const __syn_smv___e1_e2_nof1_0 &example) {return ___syn_smv___e1_e2_nof1_0(what);}
	/// from non-const specialization class:
	inline __syn_smv___e1_e2_nof1_0 like(__syn_smv___e1_e2_nof1_0 &what, const __syn_smv___e1_e2_nof1_0 &example) {return ___syn_smv___e1_e2_nof1_0(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __syn_smv___e1_e2_nof1_0 & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __syn_smv___e1_e2_nof1_0 & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __syn_smv___e1_e2_nof1_0 & v) {
		return (float)0;
	}


	/// enum for the coordinates of __syn_smv___e1e2nif1_0 
	enum ____syn_smv___e1e2nif1_0_coordinates__ {__syn_smv___e1e2nif1_0_e1e2nif1_0};

	class __syn_smv___e1e2nif1_0 {
		public:
			typedef float Float;

		/// zero constructor
		inline __syn_smv___e1e2nif1_0() {

			set();
		}

		/// scalar constructor 
		inline __syn_smv___e1e2nif1_0(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __syn_smv___e1e2nif1_0	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __syn_smv___e1e2nif1_0(const __syn_smv___e1e2nif1_0 &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __syn_smv___e1e2nif1_0(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __syn_smv___e1e2nif1_0	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __syn_smv___e1e2nif1_0(____syn_smv___e1e2nif1_0_coordinates__, const Float *coordinates) {

			set(__syn_smv___e1e2nif1_0_e1e2nif1_0, coordinates);
		}

		/// coordinates constructor
		inline __syn_smv___e1e2nif1_0(____syn_smv___e1e2nif1_0_coordinates__) {

			set(__syn_smv___e1e2nif1_0_e1e2nif1_0);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __syn_smv___e1e2nif1_0 &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____syn_smv___e1e2nif1_0_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____syn_smv___e1e2nif1_0_coordinates__);

		/// assign copy
		__syn_smv___e1e2nif1_0 &operator=(const __syn_smv___e1e2nif1_0 &arg1);

		/// assign general multivector
		__syn_smv___e1e2nif1_0 &operator=(const mv &arg1);

		/// assign scalar
		__syn_smv___e1e2nif1_0 &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name

		/// const coordinate extraction by name
		inline Float e1e2ni() const {
			return 1.0f;
		}

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____syn_smv___e1e2nif1_0_coordinates__ sanityCheckValue) const {
			return NULL;
		}

		// constants, so no coordinate storage



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __syn_smv___e1e2nif1_0 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __syn_smv___e1e2nif1_0 ___syn_smv___e1e2nif1_0(const mv &arg1) {
		return __syn_smv___e1e2nif1_0(arg1, 0);
	}
	/// from const specialization class:
	inline const __syn_smv___e1e2nif1_0 &___syn_smv___e1e2nif1_0(const __syn_smv___e1e2nif1_0 &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __syn_smv___e1e2nif1_0 &___syn_smv___e1e2nif1_0(__syn_smv___e1e2nif1_0 &arg1) {
		return arg1;
	}
	/// from Float:
	inline __syn_smv___e1e2nif1_0 ___syn_smv___e1e2nif1_0(__syn_smv___e1e2nif1_0::Float arg1) {
		return __syn_smv___e1e2nif1_0(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __syn_smv___e1e2nif1_0 like(const mv &what, const __syn_smv___e1e2nif1_0 &example) {return ___syn_smv___e1e2nif1_0(what);}
	/// from const specialization class:
	inline const __syn_smv___e1e2nif1_0 like(const __syn_smv___e1e2nif1_0 &what, const __syn_smv___e1e2nif1_0 &example) {return ___syn_smv___e1e2nif1_0(what);}
	/// from non-const specialization class:
	inline __syn_smv___e1e2nif1_0 like(__syn_smv___e1e2nif1_0 &what, const __syn_smv___e1e2nif1_0 &example) {return ___syn_smv___e1e2nif1_0(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __syn_smv___e1e2nif1_0 & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __syn_smv___e1e2nif1_0 & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __syn_smv___e1e2nif1_0 & v) {
		return (float)0;
	}


	/// enum for the coordinates of __syn_smv___e1_e2_ni_nof_1_0 
	enum ____syn_smv___e1_e2_ni_nof_1_0_coordinates__ {__syn_smv___e1_e2_ni_nof_1_0_e1_e2_ni_nof_1_0};

	class __syn_smv___e1_e2_ni_nof_1_0 {
		public:
			typedef float Float;

		/// zero constructor
		inline __syn_smv___e1_e2_ni_nof_1_0() {

			set();
		}

		/// scalar constructor 
		inline __syn_smv___e1_e2_ni_nof_1_0(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __syn_smv___e1_e2_ni_nof_1_0	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __syn_smv___e1_e2_ni_nof_1_0(const __syn_smv___e1_e2_ni_nof_1_0 &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __syn_smv___e1_e2_ni_nof_1_0(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __syn_smv___e1_e2_ni_nof_1_0	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __syn_smv___e1_e2_ni_nof_1_0(____syn_smv___e1_e2_ni_nof_1_0_coordinates__, const Float *coordinates) {

			set(__syn_smv___e1_e2_ni_nof_1_0_e1_e2_ni_nof_1_0, coordinates);
		}

		/// coordinates constructor
		inline __syn_smv___e1_e2_ni_nof_1_0(____syn_smv___e1_e2_ni_nof_1_0_coordinates__, Float c_e1, Float c_e2, Float c_ni) {

			set(__syn_smv___e1_e2_ni_nof_1_0_e1_e2_ni_nof_1_0, c_e1, c_e2, c_ni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __syn_smv___e1_e2_ni_nof_1_0 &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____syn_smv___e1_e2_ni_nof_1_0_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____syn_smv___e1_e2_ni_nof_1_0_coordinates__, Float c_e1, Float c_e2, Float c_ni);

		/// assign copy
		__syn_smv___e1_e2_ni_nof_1_0 &operator=(const __syn_smv___e1_e2_ni_nof_1_0 &arg1);

		/// assign general multivector
		__syn_smv___e1_e2_ni_nof_1_0 &operator=(const mv &arg1);

		/// assign scalar
		__syn_smv___e1_e2_ni_nof_1_0 &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1() const {
			return m_c[0];
		}
		inline Float e2() const {
			return m_c[1];
		}
		inline Float ni() const {
			return m_c[2];
		}

		/// const coordinate extraction by name
		inline Float no() const {
			return -1.0f;
		}

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____syn_smv___e1_e2_ni_nof_1_0_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[3];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __syn_smv___e1_e2_ni_nof_1_0 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __syn_smv___e1_e2_ni_nof_1_0 ___syn_smv___e1_e2_ni_nof_1_0(const mv &arg1) {
		return __syn_smv___e1_e2_ni_nof_1_0(arg1, 0);
	}
	/// from const specialization class:
	inline const __syn_smv___e1_e2_ni_nof_1_0 &___syn_smv___e1_e2_ni_nof_1_0(const __syn_smv___e1_e2_ni_nof_1_0 &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __syn_smv___e1_e2_ni_nof_1_0 &___syn_smv___e1_e2_ni_nof_1_0(__syn_smv___e1_e2_ni_nof_1_0 &arg1) {
		return arg1;
	}
	/// from Float:
	inline __syn_smv___e1_e2_ni_nof_1_0 ___syn_smv___e1_e2_ni_nof_1_0(__syn_smv___e1_e2_ni_nof_1_0::Float arg1) {
		return __syn_smv___e1_e2_ni_nof_1_0(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __syn_smv___e1_e2_ni_nof_1_0 like(const mv &what, const __syn_smv___e1_e2_ni_nof_1_0 &example) {return ___syn_smv___e1_e2_ni_nof_1_0(what);}
	/// from const specialization class:
	inline const __syn_smv___e1_e2_ni_nof_1_0 like(const __syn_smv___e1_e2_ni_nof_1_0 &what, const __syn_smv___e1_e2_ni_nof_1_0 &example) {return ___syn_smv___e1_e2_ni_nof_1_0(what);}
	/// from non-const specialization class:
	inline __syn_smv___e1_e2_ni_nof_1_0 like(__syn_smv___e1_e2_ni_nof_1_0 &what, const __syn_smv___e1_e2_ni_nof_1_0 &example) {return ___syn_smv___e1_e2_ni_nof_1_0(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __syn_smv___e1_e2_ni_nof_1_0 & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __syn_smv___e1_e2_ni_nof_1_0 & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __syn_smv___e1_e2_ni_nof_1_0 & v) {
		return (float)0;
	}


	/// enum for the coordinates of __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni 
	enum ____syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni_coordinates__ {__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni_scalar_noe1_noe2_e1e2_noni_e1ni_e2ni};

	class __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni {
		public:
			typedef float Float;

		/// zero constructor
		inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni() {

			set();
		}

		/// scalar constructor 
		inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni(const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni(____syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni_coordinates__, const Float *coordinates) {

			set(__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni_scalar_noe1_noe2_e1e2_noni_e1ni_e2ni, coordinates);
		}

		/// coordinates constructor
		inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni(____syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni_coordinates__, Float c_scalar, Float c_noe1, Float c_noe2, Float c_e1e2, Float c_noni, Float c_e1ni, Float c_e2ni) {

			set(__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni_scalar_noe1_noe2_e1e2_noni_e1ni_e2ni, c_scalar, c_noe1, c_noe2, c_e1e2, c_noni, c_e1ni, c_e2ni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni_coordinates__, Float c_scalar, Float c_noe1, Float c_noe2, Float c_e1e2, Float c_noni, Float c_e1ni, Float c_e2ni);

		/// assign copy
		__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni &operator=(const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni &arg1);

		/// assign general multivector
		__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni &operator=(const mv &arg1);

		/// assign scalar
		__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float noe1() const {
			return m_c[1];
		}
		inline Float noe2() const {
			return m_c[2];
		}
		inline Float e1e2() const {
			return m_c[3];
		}
		inline Float noni() const {
			return m_c[4];
		}
		inline Float e1ni() const {
			return m_c[5];
		}
		inline Float e2ni() const {
			return m_c[6];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[7];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni ___syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni(const mv &arg1) {
		return __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni(arg1, 0);
	}
	/// from const specialization class:
	inline const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni &___syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni(const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni &___syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni(__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni &arg1) {
		return arg1;
	}
	/// from Float:
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni ___syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni(__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni::Float arg1) {
		return __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni like(const mv &what, const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni &example) {return ___syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni(what);}
	/// from const specialization class:
	inline const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni like(const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni &what, const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni &example) {return ___syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni(what);}
	/// from non-const specialization class:
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni like(__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni &what, const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni &example) {return ___syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni & v) {
		return (float)v.m_c[0];
	}
	/// returns scalar part of v as double
	inline double _double(const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni & v) {
		return (double)v.m_c[0];
	}
	/// returns scalar part of v as Float
	inline float _Float(const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni & v) {
		return v.m_c[0];
	}


	/// enum for the coordinates of __syn_smv___scalar_noe1_noe2_noni 
	enum ____syn_smv___scalar_noe1_noe2_noni_coordinates__ {__syn_smv___scalar_noe1_noe2_noni_scalar_noe1_noe2_noni};

	class __syn_smv___scalar_noe1_noe2_noni {
		public:
			typedef float Float;

		/// zero constructor
		inline __syn_smv___scalar_noe1_noe2_noni() {

			set();
		}

		/// scalar constructor 
		inline __syn_smv___scalar_noe1_noe2_noni(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __syn_smv___scalar_noe1_noe2_noni	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __syn_smv___scalar_noe1_noe2_noni(const __syn_smv___scalar_noe1_noe2_noni &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __syn_smv___scalar_noe1_noe2_noni(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __syn_smv___scalar_noe1_noe2_noni	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __syn_smv___scalar_noe1_noe2_noni(____syn_smv___scalar_noe1_noe2_noni_coordinates__, const Float *coordinates) {

			set(__syn_smv___scalar_noe1_noe2_noni_scalar_noe1_noe2_noni, coordinates);
		}

		/// coordinates constructor
		inline __syn_smv___scalar_noe1_noe2_noni(____syn_smv___scalar_noe1_noe2_noni_coordinates__, Float c_scalar, Float c_noe1, Float c_noe2, Float c_noni) {

			set(__syn_smv___scalar_noe1_noe2_noni_scalar_noe1_noe2_noni, c_scalar, c_noe1, c_noe2, c_noni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __syn_smv___scalar_noe1_noe2_noni &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____syn_smv___scalar_noe1_noe2_noni_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____syn_smv___scalar_noe1_noe2_noni_coordinates__, Float c_scalar, Float c_noe1, Float c_noe2, Float c_noni);

		/// assign copy
		__syn_smv___scalar_noe1_noe2_noni &operator=(const __syn_smv___scalar_noe1_noe2_noni &arg1);

		/// assign general multivector
		__syn_smv___scalar_noe1_noe2_noni &operator=(const mv &arg1);

		/// assign scalar
		__syn_smv___scalar_noe1_noe2_noni &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float noe1() const {
			return m_c[1];
		}
		inline Float noe2() const {
			return m_c[2];
		}
		inline Float noni() const {
			return m_c[3];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____syn_smv___scalar_noe1_noe2_noni_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[4];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __syn_smv___scalar_noe1_noe2_noni 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __syn_smv___scalar_noe1_noe2_noni ___syn_smv___scalar_noe1_noe2_noni(const mv &arg1) {
		return __syn_smv___scalar_noe1_noe2_noni(arg1, 0);
	}
	/// from const specialization class:
	inline const __syn_smv___scalar_noe1_noe2_noni &___syn_smv___scalar_noe1_noe2_noni(const __syn_smv___scalar_noe1_noe2_noni &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __syn_smv___scalar_noe1_noe2_noni &___syn_smv___scalar_noe1_noe2_noni(__syn_smv___scalar_noe1_noe2_noni &arg1) {
		return arg1;
	}
	/// from Float:
	inline __syn_smv___scalar_noe1_noe2_noni ___syn_smv___scalar_noe1_noe2_noni(__syn_smv___scalar_noe1_noe2_noni::Float arg1) {
		return __syn_smv___scalar_noe1_noe2_noni(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __syn_smv___scalar_noe1_noe2_noni like(const mv &what, const __syn_smv___scalar_noe1_noe2_noni &example) {return ___syn_smv___scalar_noe1_noe2_noni(what);}
	/// from const specialization class:
	inline const __syn_smv___scalar_noe1_noe2_noni like(const __syn_smv___scalar_noe1_noe2_noni &what, const __syn_smv___scalar_noe1_noe2_noni &example) {return ___syn_smv___scalar_noe1_noe2_noni(what);}
	/// from non-const specialization class:
	inline __syn_smv___scalar_noe1_noe2_noni like(__syn_smv___scalar_noe1_noe2_noni &what, const __syn_smv___scalar_noe1_noe2_noni &example) {return ___syn_smv___scalar_noe1_noe2_noni(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __syn_smv___scalar_noe1_noe2_noni & v) {
		return (float)v.m_c[0];
	}
	/// returns scalar part of v as double
	inline double _double(const __syn_smv___scalar_noe1_noe2_noni & v) {
		return (double)v.m_c[0];
	}
	/// returns scalar part of v as Float
	inline float _Float(const __syn_smv___scalar_noe1_noe2_noni & v) {
		return v.m_c[0];
	}


	/// enum for the coordinates of __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni 
	enum ____syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni_coordinates__ {__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni_no_e1_e2_noe1e2_ni_noe1ni_noe2ni};

	class __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni {
		public:
			typedef float Float;

		/// zero constructor
		inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni() {

			set();
		}

		/// scalar constructor 
		inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni(____syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni_coordinates__, const Float *coordinates) {

			set(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni_no_e1_e2_noe1e2_ni_noe1ni_noe2ni, coordinates);
		}

		/// coordinates constructor
		inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni(____syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni_coordinates__, Float c_no, Float c_e1, Float c_e2, Float c_noe1e2, Float c_ni, Float c_noe1ni, Float c_noe2ni) {

			set(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni_no_e1_e2_noe1e2_ni_noe1ni_noe2ni, c_no, c_e1, c_e2, c_noe1e2, c_ni, c_noe1ni, c_noe2ni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni_coordinates__, Float c_no, Float c_e1, Float c_e2, Float c_noe1e2, Float c_ni, Float c_noe1ni, Float c_noe2ni);

		/// assign copy
		__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni &operator=(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni &arg1);

		/// assign general multivector
		__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni &operator=(const mv &arg1);

		/// assign scalar
		__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float no() const {
			return m_c[0];
		}
		inline Float e1() const {
			return m_c[1];
		}
		inline Float e2() const {
			return m_c[2];
		}
		inline Float noe1e2() const {
			return m_c[3];
		}
		inline Float ni() const {
			return m_c[4];
		}
		inline Float noe1ni() const {
			return m_c[5];
		}
		inline Float noe2ni() const {
			return m_c[6];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[7];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni ___syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni(const mv &arg1) {
		return __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni(arg1, 0);
	}
	/// from const specialization class:
	inline const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni &___syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni &___syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni &arg1) {
		return arg1;
	}
	/// from Float:
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni ___syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni::Float arg1) {
		return __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni like(const mv &what, const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni &example) {return ___syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni(what);}
	/// from const specialization class:
	inline const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni like(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni &what, const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni &example) {return ___syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni(what);}
	/// from non-const specialization class:
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni like(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni &what, const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni &example) {return ___syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni & v) {
		return (float)0;
	}


	/// enum for the coordinates of __syn_smv___scalar_noe1_e1e2_e1ni 
	enum ____syn_smv___scalar_noe1_e1e2_e1ni_coordinates__ {__syn_smv___scalar_noe1_e1e2_e1ni_scalar_noe1_e1e2_e1ni};

	class __syn_smv___scalar_noe1_e1e2_e1ni {
		public:
			typedef float Float;

		/// zero constructor
		inline __syn_smv___scalar_noe1_e1e2_e1ni() {

			set();
		}

		/// scalar constructor 
		inline __syn_smv___scalar_noe1_e1e2_e1ni(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __syn_smv___scalar_noe1_e1e2_e1ni	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __syn_smv___scalar_noe1_e1e2_e1ni(const __syn_smv___scalar_noe1_e1e2_e1ni &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __syn_smv___scalar_noe1_e1e2_e1ni(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __syn_smv___scalar_noe1_e1e2_e1ni	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __syn_smv___scalar_noe1_e1e2_e1ni(____syn_smv___scalar_noe1_e1e2_e1ni_coordinates__, const Float *coordinates) {

			set(__syn_smv___scalar_noe1_e1e2_e1ni_scalar_noe1_e1e2_e1ni, coordinates);
		}

		/// coordinates constructor
		inline __syn_smv___scalar_noe1_e1e2_e1ni(____syn_smv___scalar_noe1_e1e2_e1ni_coordinates__, Float c_scalar, Float c_noe1, Float c_e1e2, Float c_e1ni) {

			set(__syn_smv___scalar_noe1_e1e2_e1ni_scalar_noe1_e1e2_e1ni, c_scalar, c_noe1, c_e1e2, c_e1ni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __syn_smv___scalar_noe1_e1e2_e1ni &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____syn_smv___scalar_noe1_e1e2_e1ni_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____syn_smv___scalar_noe1_e1e2_e1ni_coordinates__, Float c_scalar, Float c_noe1, Float c_e1e2, Float c_e1ni);

		/// assign copy
		__syn_smv___scalar_noe1_e1e2_e1ni &operator=(const __syn_smv___scalar_noe1_e1e2_e1ni &arg1);

		/// assign general multivector
		__syn_smv___scalar_noe1_e1e2_e1ni &operator=(const mv &arg1);

		/// assign scalar
		__syn_smv___scalar_noe1_e1e2_e1ni &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float noe1() const {
			return m_c[1];
		}
		inline Float e1e2() const {
			return m_c[2];
		}
		inline Float e1ni() const {
			return m_c[3];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____syn_smv___scalar_noe1_e1e2_e1ni_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[4];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __syn_smv___scalar_noe1_e1e2_e1ni 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __syn_smv___scalar_noe1_e1e2_e1ni ___syn_smv___scalar_noe1_e1e2_e1ni(const mv &arg1) {
		return __syn_smv___scalar_noe1_e1e2_e1ni(arg1, 0);
	}
	/// from const specialization class:
	inline const __syn_smv___scalar_noe1_e1e2_e1ni &___syn_smv___scalar_noe1_e1e2_e1ni(const __syn_smv___scalar_noe1_e1e2_e1ni &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __syn_smv___scalar_noe1_e1e2_e1ni &___syn_smv___scalar_noe1_e1e2_e1ni(__syn_smv___scalar_noe1_e1e2_e1ni &arg1) {
		return arg1;
	}
	/// from Float:
	inline __syn_smv___scalar_noe1_e1e2_e1ni ___syn_smv___scalar_noe1_e1e2_e1ni(__syn_smv___scalar_noe1_e1e2_e1ni::Float arg1) {
		return __syn_smv___scalar_noe1_e1e2_e1ni(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __syn_smv___scalar_noe1_e1e2_e1ni like(const mv &what, const __syn_smv___scalar_noe1_e1e2_e1ni &example) {return ___syn_smv___scalar_noe1_e1e2_e1ni(what);}
	/// from const specialization class:
	inline const __syn_smv___scalar_noe1_e1e2_e1ni like(const __syn_smv___scalar_noe1_e1e2_e1ni &what, const __syn_smv___scalar_noe1_e1e2_e1ni &example) {return ___syn_smv___scalar_noe1_e1e2_e1ni(what);}
	/// from non-const specialization class:
	inline __syn_smv___scalar_noe1_e1e2_e1ni like(__syn_smv___scalar_noe1_e1e2_e1ni &what, const __syn_smv___scalar_noe1_e1e2_e1ni &example) {return ___syn_smv___scalar_noe1_e1e2_e1ni(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __syn_smv___scalar_noe1_e1e2_e1ni & v) {
		return (float)v.m_c[0];
	}
	/// returns scalar part of v as double
	inline double _double(const __syn_smv___scalar_noe1_e1e2_e1ni & v) {
		return (double)v.m_c[0];
	}
	/// returns scalar part of v as Float
	inline float _Float(const __syn_smv___scalar_noe1_e1e2_e1ni & v) {
		return v.m_c[0];
	}


	/// enum for the coordinates of __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni 
	enum ____syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni_coordinates__ {__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni_no_e1_e2_noe1e2_ni_noe1ni_e1e2ni};

	class __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni {
		public:
			typedef float Float;

		/// zero constructor
		inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni() {

			set();
		}

		/// scalar constructor 
		inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni(____syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni_coordinates__, const Float *coordinates) {

			set(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni_no_e1_e2_noe1e2_ni_noe1ni_e1e2ni, coordinates);
		}

		/// coordinates constructor
		inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni(____syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni_coordinates__, Float c_no, Float c_e1, Float c_e2, Float c_noe1e2, Float c_ni, Float c_noe1ni, Float c_e1e2ni) {

			set(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni_no_e1_e2_noe1e2_ni_noe1ni_e1e2ni, c_no, c_e1, c_e2, c_noe1e2, c_ni, c_noe1ni, c_e1e2ni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni_coordinates__, Float c_no, Float c_e1, Float c_e2, Float c_noe1e2, Float c_ni, Float c_noe1ni, Float c_e1e2ni);

		/// assign copy
		__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni &operator=(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni &arg1);

		/// assign general multivector
		__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni &operator=(const mv &arg1);

		/// assign scalar
		__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float no() const {
			return m_c[0];
		}
		inline Float e1() const {
			return m_c[1];
		}
		inline Float e2() const {
			return m_c[2];
		}
		inline Float noe1e2() const {
			return m_c[3];
		}
		inline Float ni() const {
			return m_c[4];
		}
		inline Float noe1ni() const {
			return m_c[5];
		}
		inline Float e1e2ni() const {
			return m_c[6];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[7];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni ___syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni(const mv &arg1) {
		return __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni(arg1, 0);
	}
	/// from const specialization class:
	inline const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni &___syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni &___syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni &arg1) {
		return arg1;
	}
	/// from Float:
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni ___syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni::Float arg1) {
		return __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni like(const mv &what, const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni &example) {return ___syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni(what);}
	/// from const specialization class:
	inline const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni like(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni &what, const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni &example) {return ___syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni(what);}
	/// from non-const specialization class:
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni like(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni &what, const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni &example) {return ___syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni & v) {
		return (float)0;
	}


	/// enum for the coordinates of __syn_smv___scalar_noe2_e1e2_e2ni 
	enum ____syn_smv___scalar_noe2_e1e2_e2ni_coordinates__ {__syn_smv___scalar_noe2_e1e2_e2ni_scalar_noe2_e1e2_e2ni};

	class __syn_smv___scalar_noe2_e1e2_e2ni {
		public:
			typedef float Float;

		/// zero constructor
		inline __syn_smv___scalar_noe2_e1e2_e2ni() {

			set();
		}

		/// scalar constructor 
		inline __syn_smv___scalar_noe2_e1e2_e2ni(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __syn_smv___scalar_noe2_e1e2_e2ni	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __syn_smv___scalar_noe2_e1e2_e2ni(const __syn_smv___scalar_noe2_e1e2_e2ni &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __syn_smv___scalar_noe2_e1e2_e2ni(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __syn_smv___scalar_noe2_e1e2_e2ni	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __syn_smv___scalar_noe2_e1e2_e2ni(____syn_smv___scalar_noe2_e1e2_e2ni_coordinates__, const Float *coordinates) {

			set(__syn_smv___scalar_noe2_e1e2_e2ni_scalar_noe2_e1e2_e2ni, coordinates);
		}

		/// coordinates constructor
		inline __syn_smv___scalar_noe2_e1e2_e2ni(____syn_smv___scalar_noe2_e1e2_e2ni_coordinates__, Float c_scalar, Float c_noe2, Float c_e1e2, Float c_e2ni) {

			set(__syn_smv___scalar_noe2_e1e2_e2ni_scalar_noe2_e1e2_e2ni, c_scalar, c_noe2, c_e1e2, c_e2ni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __syn_smv___scalar_noe2_e1e2_e2ni &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____syn_smv___scalar_noe2_e1e2_e2ni_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____syn_smv___scalar_noe2_e1e2_e2ni_coordinates__, Float c_scalar, Float c_noe2, Float c_e1e2, Float c_e2ni);

		/// assign copy
		__syn_smv___scalar_noe2_e1e2_e2ni &operator=(const __syn_smv___scalar_noe2_e1e2_e2ni &arg1);

		/// assign general multivector
		__syn_smv___scalar_noe2_e1e2_e2ni &operator=(const mv &arg1);

		/// assign scalar
		__syn_smv___scalar_noe2_e1e2_e2ni &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float noe2() const {
			return m_c[1];
		}
		inline Float e1e2() const {
			return m_c[2];
		}
		inline Float e2ni() const {
			return m_c[3];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____syn_smv___scalar_noe2_e1e2_e2ni_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[4];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __syn_smv___scalar_noe2_e1e2_e2ni 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __syn_smv___scalar_noe2_e1e2_e2ni ___syn_smv___scalar_noe2_e1e2_e2ni(const mv &arg1) {
		return __syn_smv___scalar_noe2_e1e2_e2ni(arg1, 0);
	}
	/// from const specialization class:
	inline const __syn_smv___scalar_noe2_e1e2_e2ni &___syn_smv___scalar_noe2_e1e2_e2ni(const __syn_smv___scalar_noe2_e1e2_e2ni &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __syn_smv___scalar_noe2_e1e2_e2ni &___syn_smv___scalar_noe2_e1e2_e2ni(__syn_smv___scalar_noe2_e1e2_e2ni &arg1) {
		return arg1;
	}
	/// from Float:
	inline __syn_smv___scalar_noe2_e1e2_e2ni ___syn_smv___scalar_noe2_e1e2_e2ni(__syn_smv___scalar_noe2_e1e2_e2ni::Float arg1) {
		return __syn_smv___scalar_noe2_e1e2_e2ni(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __syn_smv___scalar_noe2_e1e2_e2ni like(const mv &what, const __syn_smv___scalar_noe2_e1e2_e2ni &example) {return ___syn_smv___scalar_noe2_e1e2_e2ni(what);}
	/// from const specialization class:
	inline const __syn_smv___scalar_noe2_e1e2_e2ni like(const __syn_smv___scalar_noe2_e1e2_e2ni &what, const __syn_smv___scalar_noe2_e1e2_e2ni &example) {return ___syn_smv___scalar_noe2_e1e2_e2ni(what);}
	/// from non-const specialization class:
	inline __syn_smv___scalar_noe2_e1e2_e2ni like(__syn_smv___scalar_noe2_e1e2_e2ni &what, const __syn_smv___scalar_noe2_e1e2_e2ni &example) {return ___syn_smv___scalar_noe2_e1e2_e2ni(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __syn_smv___scalar_noe2_e1e2_e2ni & v) {
		return (float)v.m_c[0];
	}
	/// returns scalar part of v as double
	inline double _double(const __syn_smv___scalar_noe2_e1e2_e2ni & v) {
		return (double)v.m_c[0];
	}
	/// returns scalar part of v as Float
	inline float _Float(const __syn_smv___scalar_noe2_e1e2_e2ni & v) {
		return v.m_c[0];
	}


	/// enum for the coordinates of __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni 
	enum ____syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni_coordinates__ {__syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni_no_e1_e2_noe1e2_ni_noe2ni_e1e2ni};

	class __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni {
		public:
			typedef float Float;

		/// zero constructor
		inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni() {

			set();
		}

		/// scalar constructor 
		inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni(const __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni(____syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni_coordinates__, const Float *coordinates) {

			set(__syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni_no_e1_e2_noe1e2_ni_noe2ni_e1e2ni, coordinates);
		}

		/// coordinates constructor
		inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni(____syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni_coordinates__, Float c_no, Float c_e1, Float c_e2, Float c_noe1e2, Float c_ni, Float c_noe2ni, Float c_e1e2ni) {

			set(__syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni_no_e1_e2_noe1e2_ni_noe2ni_e1e2ni, c_no, c_e1, c_e2, c_noe1e2, c_ni, c_noe2ni, c_e1e2ni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni_coordinates__, Float c_no, Float c_e1, Float c_e2, Float c_noe1e2, Float c_ni, Float c_noe2ni, Float c_e1e2ni);

		/// assign copy
		__syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni &operator=(const __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni &arg1);

		/// assign general multivector
		__syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni &operator=(const mv &arg1);

		/// assign scalar
		__syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float no() const {
			return m_c[0];
		}
		inline Float e1() const {
			return m_c[1];
		}
		inline Float e2() const {
			return m_c[2];
		}
		inline Float noe1e2() const {
			return m_c[3];
		}
		inline Float ni() const {
			return m_c[4];
		}
		inline Float noe2ni() const {
			return m_c[5];
		}
		inline Float e1e2ni() const {
			return m_c[6];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[7];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni ___syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni(const mv &arg1) {
		return __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni(arg1, 0);
	}
	/// from const specialization class:
	inline const __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni &___syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni(const __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni &___syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni(__syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni &arg1) {
		return arg1;
	}
	/// from Float:
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni ___syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni(__syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni::Float arg1) {
		return __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni like(const mv &what, const __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni &example) {return ___syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni(what);}
	/// from const specialization class:
	inline const __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni like(const __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni &what, const __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni &example) {return ___syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni(what);}
	/// from non-const specialization class:
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni like(__syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni &what, const __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni &example) {return ___syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni & v) {
		return (float)0;
	}


	/// enum for the coordinates of __syn_smv___scalar_noni_e1ni_e2ni 
	enum ____syn_smv___scalar_noni_e1ni_e2ni_coordinates__ {__syn_smv___scalar_noni_e1ni_e2ni_scalar_noni_e1ni_e2ni};

	class __syn_smv___scalar_noni_e1ni_e2ni {
		public:
			typedef float Float;

		/// zero constructor
		inline __syn_smv___scalar_noni_e1ni_e2ni() {

			set();
		}

		/// scalar constructor 
		inline __syn_smv___scalar_noni_e1ni_e2ni(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __syn_smv___scalar_noni_e1ni_e2ni	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __syn_smv___scalar_noni_e1ni_e2ni(const __syn_smv___scalar_noni_e1ni_e2ni &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __syn_smv___scalar_noni_e1ni_e2ni(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __syn_smv___scalar_noni_e1ni_e2ni	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __syn_smv___scalar_noni_e1ni_e2ni(____syn_smv___scalar_noni_e1ni_e2ni_coordinates__, const Float *coordinates) {

			set(__syn_smv___scalar_noni_e1ni_e2ni_scalar_noni_e1ni_e2ni, coordinates);
		}

		/// coordinates constructor
		inline __syn_smv___scalar_noni_e1ni_e2ni(____syn_smv___scalar_noni_e1ni_e2ni_coordinates__, Float c_scalar, Float c_noni, Float c_e1ni, Float c_e2ni) {

			set(__syn_smv___scalar_noni_e1ni_e2ni_scalar_noni_e1ni_e2ni, c_scalar, c_noni, c_e1ni, c_e2ni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __syn_smv___scalar_noni_e1ni_e2ni &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____syn_smv___scalar_noni_e1ni_e2ni_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____syn_smv___scalar_noni_e1ni_e2ni_coordinates__, Float c_scalar, Float c_noni, Float c_e1ni, Float c_e2ni);

		/// assign copy
		__syn_smv___scalar_noni_e1ni_e2ni &operator=(const __syn_smv___scalar_noni_e1ni_e2ni &arg1);

		/// assign general multivector
		__syn_smv___scalar_noni_e1ni_e2ni &operator=(const mv &arg1);

		/// assign scalar
		__syn_smv___scalar_noni_e1ni_e2ni &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float noni() const {
			return m_c[1];
		}
		inline Float e1ni() const {
			return m_c[2];
		}
		inline Float e2ni() const {
			return m_c[3];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____syn_smv___scalar_noni_e1ni_e2ni_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[4];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __syn_smv___scalar_noni_e1ni_e2ni 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __syn_smv___scalar_noni_e1ni_e2ni ___syn_smv___scalar_noni_e1ni_e2ni(const mv &arg1) {
		return __syn_smv___scalar_noni_e1ni_e2ni(arg1, 0);
	}
	/// from const specialization class:
	inline const __syn_smv___scalar_noni_e1ni_e2ni &___syn_smv___scalar_noni_e1ni_e2ni(const __syn_smv___scalar_noni_e1ni_e2ni &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __syn_smv___scalar_noni_e1ni_e2ni &___syn_smv___scalar_noni_e1ni_e2ni(__syn_smv___scalar_noni_e1ni_e2ni &arg1) {
		return arg1;
	}
	/// from Float:
	inline __syn_smv___scalar_noni_e1ni_e2ni ___syn_smv___scalar_noni_e1ni_e2ni(__syn_smv___scalar_noni_e1ni_e2ni::Float arg1) {
		return __syn_smv___scalar_noni_e1ni_e2ni(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __syn_smv___scalar_noni_e1ni_e2ni like(const mv &what, const __syn_smv___scalar_noni_e1ni_e2ni &example) {return ___syn_smv___scalar_noni_e1ni_e2ni(what);}
	/// from const specialization class:
	inline const __syn_smv___scalar_noni_e1ni_e2ni like(const __syn_smv___scalar_noni_e1ni_e2ni &what, const __syn_smv___scalar_noni_e1ni_e2ni &example) {return ___syn_smv___scalar_noni_e1ni_e2ni(what);}
	/// from non-const specialization class:
	inline __syn_smv___scalar_noni_e1ni_e2ni like(__syn_smv___scalar_noni_e1ni_e2ni &what, const __syn_smv___scalar_noni_e1ni_e2ni &example) {return ___syn_smv___scalar_noni_e1ni_e2ni(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __syn_smv___scalar_noni_e1ni_e2ni & v) {
		return (float)v.m_c[0];
	}
	/// returns scalar part of v as double
	inline double _double(const __syn_smv___scalar_noni_e1ni_e2ni & v) {
		return (double)v.m_c[0];
	}
	/// returns scalar part of v as Float
	inline float _Float(const __syn_smv___scalar_noni_e1ni_e2ni & v) {
		return v.m_c[0];
	}


	/// enum for the coordinates of __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni 
	enum ____syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni_coordinates__ {__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni_no_e1_e2_ni_noe1ni_noe2ni_e1e2ni};

	class __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni {
		public:
			typedef float Float;

		/// zero constructor
		inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni() {

			set();
		}

		/// scalar constructor 
		inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni(const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni(____syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni_coordinates__, const Float *coordinates) {

			set(__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni_no_e1_e2_ni_noe1ni_noe2ni_e1e2ni, coordinates);
		}

		/// coordinates constructor
		inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni(____syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni_coordinates__, Float c_no, Float c_e1, Float c_e2, Float c_ni, Float c_noe1ni, Float c_noe2ni, Float c_e1e2ni) {

			set(__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni_no_e1_e2_ni_noe1ni_noe2ni_e1e2ni, c_no, c_e1, c_e2, c_ni, c_noe1ni, c_noe2ni, c_e1e2ni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni_coordinates__, Float c_no, Float c_e1, Float c_e2, Float c_ni, Float c_noe1ni, Float c_noe2ni, Float c_e1e2ni);

		/// assign copy
		__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni &operator=(const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni &arg1);

		/// assign general multivector
		__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni &operator=(const mv &arg1);

		/// assign scalar
		__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float no() const {
			return m_c[0];
		}
		inline Float e1() const {
			return m_c[1];
		}
		inline Float e2() const {
			return m_c[2];
		}
		inline Float ni() const {
			return m_c[3];
		}
		inline Float noe1ni() const {
			return m_c[4];
		}
		inline Float noe2ni() const {
			return m_c[5];
		}
		inline Float e1e2ni() const {
			return m_c[6];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[7];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni ___syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni(const mv &arg1) {
		return __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni(arg1, 0);
	}
	/// from const specialization class:
	inline const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni &___syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni(const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni &___syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni(__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni &arg1) {
		return arg1;
	}
	/// from Float:
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni ___syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni(__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni::Float arg1) {
		return __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni like(const mv &what, const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni &example) {return ___syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni(what);}
	/// from const specialization class:
	inline const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni like(const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni &what, const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni &example) {return ___syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni(what);}
	/// from non-const specialization class:
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni like(__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni &what, const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni &example) {return ___syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni & v) {
		return (float)0;
	}


	/// enum for the coordinates of __syn_smv___e1ni_e2ni_nonif_1_0 
	enum ____syn_smv___e1ni_e2ni_nonif_1_0_coordinates__ {__syn_smv___e1ni_e2ni_nonif_1_0_e1ni_e2ni_nonif_1_0};

	class __syn_smv___e1ni_e2ni_nonif_1_0 {
		public:
			typedef float Float;

		/// zero constructor
		inline __syn_smv___e1ni_e2ni_nonif_1_0() {

			set();
		}

		/// scalar constructor 
		inline __syn_smv___e1ni_e2ni_nonif_1_0(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __syn_smv___e1ni_e2ni_nonif_1_0	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __syn_smv___e1ni_e2ni_nonif_1_0(const __syn_smv___e1ni_e2ni_nonif_1_0 &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __syn_smv___e1ni_e2ni_nonif_1_0(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __syn_smv___e1ni_e2ni_nonif_1_0	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __syn_smv___e1ni_e2ni_nonif_1_0(____syn_smv___e1ni_e2ni_nonif_1_0_coordinates__, const Float *coordinates) {

			set(__syn_smv___e1ni_e2ni_nonif_1_0_e1ni_e2ni_nonif_1_0, coordinates);
		}

		/// coordinates constructor
		inline __syn_smv___e1ni_e2ni_nonif_1_0(____syn_smv___e1ni_e2ni_nonif_1_0_coordinates__, Float c_e1ni, Float c_e2ni) {

			set(__syn_smv___e1ni_e2ni_nonif_1_0_e1ni_e2ni_nonif_1_0, c_e1ni, c_e2ni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __syn_smv___e1ni_e2ni_nonif_1_0 &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____syn_smv___e1ni_e2ni_nonif_1_0_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____syn_smv___e1ni_e2ni_nonif_1_0_coordinates__, Float c_e1ni, Float c_e2ni);

		/// assign copy
		__syn_smv___e1ni_e2ni_nonif_1_0 &operator=(const __syn_smv___e1ni_e2ni_nonif_1_0 &arg1);

		/// assign general multivector
		__syn_smv___e1ni_e2ni_nonif_1_0 &operator=(const mv &arg1);

		/// assign scalar
		__syn_smv___e1ni_e2ni_nonif_1_0 &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1ni() const {
			return m_c[0];
		}
		inline Float e2ni() const {
			return m_c[1];
		}

		/// const coordinate extraction by name
		inline Float noni() const {
			return -1.0f;
		}

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____syn_smv___e1ni_e2ni_nonif_1_0_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[2];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __syn_smv___e1ni_e2ni_nonif_1_0 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __syn_smv___e1ni_e2ni_nonif_1_0 ___syn_smv___e1ni_e2ni_nonif_1_0(const mv &arg1) {
		return __syn_smv___e1ni_e2ni_nonif_1_0(arg1, 0);
	}
	/// from const specialization class:
	inline const __syn_smv___e1ni_e2ni_nonif_1_0 &___syn_smv___e1ni_e2ni_nonif_1_0(const __syn_smv___e1ni_e2ni_nonif_1_0 &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __syn_smv___e1ni_e2ni_nonif_1_0 &___syn_smv___e1ni_e2ni_nonif_1_0(__syn_smv___e1ni_e2ni_nonif_1_0 &arg1) {
		return arg1;
	}
	/// from Float:
	inline __syn_smv___e1ni_e2ni_nonif_1_0 ___syn_smv___e1ni_e2ni_nonif_1_0(__syn_smv___e1ni_e2ni_nonif_1_0::Float arg1) {
		return __syn_smv___e1ni_e2ni_nonif_1_0(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __syn_smv___e1ni_e2ni_nonif_1_0 like(const mv &what, const __syn_smv___e1ni_e2ni_nonif_1_0 &example) {return ___syn_smv___e1ni_e2ni_nonif_1_0(what);}
	/// from const specialization class:
	inline const __syn_smv___e1ni_e2ni_nonif_1_0 like(const __syn_smv___e1ni_e2ni_nonif_1_0 &what, const __syn_smv___e1ni_e2ni_nonif_1_0 &example) {return ___syn_smv___e1ni_e2ni_nonif_1_0(what);}
	/// from non-const specialization class:
	inline __syn_smv___e1ni_e2ni_nonif_1_0 like(__syn_smv___e1ni_e2ni_nonif_1_0 &what, const __syn_smv___e1ni_e2ni_nonif_1_0 &example) {return ___syn_smv___e1ni_e2ni_nonif_1_0(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __syn_smv___e1ni_e2ni_nonif_1_0 & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __syn_smv___e1ni_e2ni_nonif_1_0 & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __syn_smv___e1ni_e2ni_nonif_1_0 & v) {
		return (float)0;
	}


	/// enum for the coordinates of __syn_smv___scalarf_1_0 
	enum ____syn_smv___scalarf_1_0_coordinates__ {__syn_smv___scalarf_1_0_scalarf_1_0};

	class __syn_smv___scalarf_1_0 {
		public:
			typedef float Float;

		/// zero constructor
		inline __syn_smv___scalarf_1_0() {

			set();
		}

		/// scalar constructor 
		inline __syn_smv___scalarf_1_0(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __syn_smv___scalarf_1_0	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __syn_smv___scalarf_1_0(const __syn_smv___scalarf_1_0 &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __syn_smv___scalarf_1_0(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __syn_smv___scalarf_1_0	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __syn_smv___scalarf_1_0(____syn_smv___scalarf_1_0_coordinates__, const Float *coordinates) {

			set(__syn_smv___scalarf_1_0_scalarf_1_0, coordinates);
		}

		/// coordinates constructor
		inline __syn_smv___scalarf_1_0(____syn_smv___scalarf_1_0_coordinates__) {

			set(__syn_smv___scalarf_1_0_scalarf_1_0);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __syn_smv___scalarf_1_0 &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____syn_smv___scalarf_1_0_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____syn_smv___scalarf_1_0_coordinates__);

		/// assign copy
		__syn_smv___scalarf_1_0 &operator=(const __syn_smv___scalarf_1_0 &arg1);

		/// assign general multivector
		__syn_smv___scalarf_1_0 &operator=(const mv &arg1);

		/// assign scalar
		__syn_smv___scalarf_1_0 &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____syn_smv___scalarf_1_0_coordinates__ sanityCheckValue) const {
			return NULL;
		}

		// constants, so no coordinate storage



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __syn_smv___scalarf_1_0 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __syn_smv___scalarf_1_0 ___syn_smv___scalarf_1_0(const mv &arg1) {
		return __syn_smv___scalarf_1_0(arg1, 0);
	}
	/// from const specialization class:
	inline const __syn_smv___scalarf_1_0 &___syn_smv___scalarf_1_0(const __syn_smv___scalarf_1_0 &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __syn_smv___scalarf_1_0 &___syn_smv___scalarf_1_0(__syn_smv___scalarf_1_0 &arg1) {
		return arg1;
	}
	/// from Float:
	inline __syn_smv___scalarf_1_0 ___syn_smv___scalarf_1_0(__syn_smv___scalarf_1_0::Float arg1) {
		return __syn_smv___scalarf_1_0(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __syn_smv___scalarf_1_0 like(const mv &what, const __syn_smv___scalarf_1_0 &example) {return ___syn_smv___scalarf_1_0(what);}
	/// from const specialization class:
	inline const __syn_smv___scalarf_1_0 like(const __syn_smv___scalarf_1_0 &what, const __syn_smv___scalarf_1_0 &example) {return ___syn_smv___scalarf_1_0(what);}
	/// from non-const specialization class:
	inline __syn_smv___scalarf_1_0 like(__syn_smv___scalarf_1_0 &what, const __syn_smv___scalarf_1_0 &example) {return ___syn_smv___scalarf_1_0(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __syn_smv___scalarf_1_0 & v) {
		return (float)-1.0f;
	}
	/// returns scalar part of v as double
	inline double _double(const __syn_smv___scalarf_1_0 & v) {
		return (double)-1.0f;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __syn_smv___scalarf_1_0 & v) {
		return (float)-1.0f;
	}


	/// enum for the coordinates of __syn_smv___nif_1_0 
	enum ____syn_smv___nif_1_0_coordinates__ {__syn_smv___nif_1_0_nif_1_0};

	class __syn_smv___nif_1_0 {
		public:
			typedef float Float;

		/// zero constructor
		inline __syn_smv___nif_1_0() {

			set();
		}

		/// scalar constructor 
		inline __syn_smv___nif_1_0(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __syn_smv___nif_1_0	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __syn_smv___nif_1_0(const __syn_smv___nif_1_0 &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __syn_smv___nif_1_0(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __syn_smv___nif_1_0	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __syn_smv___nif_1_0(____syn_smv___nif_1_0_coordinates__, const Float *coordinates) {

			set(__syn_smv___nif_1_0_nif_1_0, coordinates);
		}

		/// coordinates constructor
		inline __syn_smv___nif_1_0(____syn_smv___nif_1_0_coordinates__) {

			set(__syn_smv___nif_1_0_nif_1_0);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __syn_smv___nif_1_0 &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____syn_smv___nif_1_0_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____syn_smv___nif_1_0_coordinates__);

		/// assign copy
		__syn_smv___nif_1_0 &operator=(const __syn_smv___nif_1_0 &arg1);

		/// assign general multivector
		__syn_smv___nif_1_0 &operator=(const mv &arg1);

		/// assign scalar
		__syn_smv___nif_1_0 &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name

		/// const coordinate extraction by name
		inline Float ni() const {
			return -1.0f;
		}

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____syn_smv___nif_1_0_coordinates__ sanityCheckValue) const {
			return NULL;
		}

		// constants, so no coordinate storage



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __syn_smv___nif_1_0 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __syn_smv___nif_1_0 ___syn_smv___nif_1_0(const mv &arg1) {
		return __syn_smv___nif_1_0(arg1, 0);
	}
	/// from const specialization class:
	inline const __syn_smv___nif_1_0 &___syn_smv___nif_1_0(const __syn_smv___nif_1_0 &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __syn_smv___nif_1_0 &___syn_smv___nif_1_0(__syn_smv___nif_1_0 &arg1) {
		return arg1;
	}
	/// from Float:
	inline __syn_smv___nif_1_0 ___syn_smv___nif_1_0(__syn_smv___nif_1_0::Float arg1) {
		return __syn_smv___nif_1_0(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __syn_smv___nif_1_0 like(const mv &what, const __syn_smv___nif_1_0 &example) {return ___syn_smv___nif_1_0(what);}
	/// from const specialization class:
	inline const __syn_smv___nif_1_0 like(const __syn_smv___nif_1_0 &what, const __syn_smv___nif_1_0 &example) {return ___syn_smv___nif_1_0(what);}
	/// from non-const specialization class:
	inline __syn_smv___nif_1_0 like(__syn_smv___nif_1_0 &what, const __syn_smv___nif_1_0 &example) {return ___syn_smv___nif_1_0(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __syn_smv___nif_1_0 & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __syn_smv___nif_1_0 & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __syn_smv___nif_1_0 & v) {
		return (float)0;
	}


	/// enum for the coordinates of __syn_smv___nif1_0 
	enum ____syn_smv___nif1_0_coordinates__ {__syn_smv___nif1_0_nif1_0};

	class __syn_smv___nif1_0 {
		public:
			typedef float Float;

		/// zero constructor
		inline __syn_smv___nif1_0() {

			set();
		}

		/// scalar constructor 
		inline __syn_smv___nif1_0(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __syn_smv___nif1_0	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __syn_smv___nif1_0(const __syn_smv___nif1_0 &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __syn_smv___nif1_0(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __syn_smv___nif1_0	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __syn_smv___nif1_0(____syn_smv___nif1_0_coordinates__, const Float *coordinates) {

			set(__syn_smv___nif1_0_nif1_0, coordinates);
		}

		/// coordinates constructor
		inline __syn_smv___nif1_0(____syn_smv___nif1_0_coordinates__) {

			set(__syn_smv___nif1_0_nif1_0);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __syn_smv___nif1_0 &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____syn_smv___nif1_0_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____syn_smv___nif1_0_coordinates__);

		/// assign copy
		__syn_smv___nif1_0 &operator=(const __syn_smv___nif1_0 &arg1);

		/// assign general multivector
		__syn_smv___nif1_0 &operator=(const mv &arg1);

		/// assign scalar
		__syn_smv___nif1_0 &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name

		/// const coordinate extraction by name
		inline Float ni() const {
			return 1.0f;
		}

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____syn_smv___nif1_0_coordinates__ sanityCheckValue) const {
			return NULL;
		}

		// constants, so no coordinate storage



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __syn_smv___nif1_0 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __syn_smv___nif1_0 ___syn_smv___nif1_0(const mv &arg1) {
		return __syn_smv___nif1_0(arg1, 0);
	}
	/// from const specialization class:
	inline const __syn_smv___nif1_0 &___syn_smv___nif1_0(const __syn_smv___nif1_0 &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __syn_smv___nif1_0 &___syn_smv___nif1_0(__syn_smv___nif1_0 &arg1) {
		return arg1;
	}
	/// from Float:
	inline __syn_smv___nif1_0 ___syn_smv___nif1_0(__syn_smv___nif1_0::Float arg1) {
		return __syn_smv___nif1_0(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __syn_smv___nif1_0 like(const mv &what, const __syn_smv___nif1_0 &example) {return ___syn_smv___nif1_0(what);}
	/// from const specialization class:
	inline const __syn_smv___nif1_0 like(const __syn_smv___nif1_0 &what, const __syn_smv___nif1_0 &example) {return ___syn_smv___nif1_0(what);}
	/// from non-const specialization class:
	inline __syn_smv___nif1_0 like(__syn_smv___nif1_0 &what, const __syn_smv___nif1_0 &example) {return ___syn_smv___nif1_0(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __syn_smv___nif1_0 & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __syn_smv___nif1_0 & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __syn_smv___nif1_0 & v) {
		return (float)0;
	}


	/// enum for the coordinates of __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 
	enum ____syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0_coordinates__ {__syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0_e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0};

	class __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 {
		public:
			typedef float Float;

		/// zero constructor
		inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0() {

			set();
		}

		/// scalar constructor 
		inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0(const __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0(____syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0_coordinates__, const Float *coordinates) {

			set(__syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0_e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0, coordinates);
		}

		/// coordinates constructor
		inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0(____syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0_coordinates__, Float c_e1, Float c_e2, Float c_ni, Float c_noe1ni, Float c_noe2ni, Float c_e1e2ni) {

			set(__syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0_e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0, c_e1, c_e2, c_ni, c_noe1ni, c_noe2ni, c_e1e2ni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0_coordinates__, Float c_e1, Float c_e2, Float c_ni, Float c_noe1ni, Float c_noe2ni, Float c_e1e2ni);

		/// assign copy
		__syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 &operator=(const __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 &arg1);

		/// assign general multivector
		__syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 &operator=(const mv &arg1);

		/// assign scalar
		__syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1() const {
			return m_c[0];
		}
		inline Float e2() const {
			return m_c[1];
		}
		inline Float ni() const {
			return m_c[2];
		}
		inline Float noe1ni() const {
			return m_c[3];
		}
		inline Float noe2ni() const {
			return m_c[4];
		}
		inline Float e1e2ni() const {
			return m_c[5];
		}

		/// const coordinate extraction by name
		inline Float no() const {
			return 1.0f;
		}

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[6];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 ___syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0(const mv &arg1) {
		return __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0(arg1, 0);
	}
	/// from const specialization class:
	inline const __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 &___syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0(const __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 &___syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0(__syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 &arg1) {
		return arg1;
	}
	/// from Float:
	inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 ___syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0(__syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0::Float arg1) {
		return __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 like(const mv &what, const __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 &example) {return ___syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0(what);}
	/// from const specialization class:
	inline const __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 like(const __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 &what, const __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 &example) {return ___syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0(what);}
	/// from non-const specialization class:
	inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 like(__syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 &what, const __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 &example) {return ___syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 & v) {
		return (float)0;
	}


	/// enum for the coordinates of __syn_smv___e1_e2_ni_nof2_0 
	enum ____syn_smv___e1_e2_ni_nof2_0_coordinates__ {__syn_smv___e1_e2_ni_nof2_0_e1_e2_ni_nof2_0};

	class __syn_smv___e1_e2_ni_nof2_0 {
		public:
			typedef float Float;

		/// zero constructor
		inline __syn_smv___e1_e2_ni_nof2_0() {

			set();
		}

		/// scalar constructor 
		inline __syn_smv___e1_e2_ni_nof2_0(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __syn_smv___e1_e2_ni_nof2_0	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __syn_smv___e1_e2_ni_nof2_0(const __syn_smv___e1_e2_ni_nof2_0 &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __syn_smv___e1_e2_ni_nof2_0(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __syn_smv___e1_e2_ni_nof2_0	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __syn_smv___e1_e2_ni_nof2_0(____syn_smv___e1_e2_ni_nof2_0_coordinates__, const Float *coordinates) {

			set(__syn_smv___e1_e2_ni_nof2_0_e1_e2_ni_nof2_0, coordinates);
		}

		/// coordinates constructor
		inline __syn_smv___e1_e2_ni_nof2_0(____syn_smv___e1_e2_ni_nof2_0_coordinates__, Float c_e1, Float c_e2, Float c_ni) {

			set(__syn_smv___e1_e2_ni_nof2_0_e1_e2_ni_nof2_0, c_e1, c_e2, c_ni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __syn_smv___e1_e2_ni_nof2_0 &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____syn_smv___e1_e2_ni_nof2_0_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____syn_smv___e1_e2_ni_nof2_0_coordinates__, Float c_e1, Float c_e2, Float c_ni);

		/// assign copy
		__syn_smv___e1_e2_ni_nof2_0 &operator=(const __syn_smv___e1_e2_ni_nof2_0 &arg1);

		/// assign general multivector
		__syn_smv___e1_e2_ni_nof2_0 &operator=(const mv &arg1);

		/// assign scalar
		__syn_smv___e1_e2_ni_nof2_0 &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1() const {
			return m_c[0];
		}
		inline Float e2() const {
			return m_c[1];
		}
		inline Float ni() const {
			return m_c[2];
		}

		/// const coordinate extraction by name
		inline Float no() const {
			return 2.0f;
		}

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____syn_smv___e1_e2_ni_nof2_0_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[3];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __syn_smv___e1_e2_ni_nof2_0 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __syn_smv___e1_e2_ni_nof2_0 ___syn_smv___e1_e2_ni_nof2_0(const mv &arg1) {
		return __syn_smv___e1_e2_ni_nof2_0(arg1, 0);
	}
	/// from const specialization class:
	inline const __syn_smv___e1_e2_ni_nof2_0 &___syn_smv___e1_e2_ni_nof2_0(const __syn_smv___e1_e2_ni_nof2_0 &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __syn_smv___e1_e2_ni_nof2_0 &___syn_smv___e1_e2_ni_nof2_0(__syn_smv___e1_e2_ni_nof2_0 &arg1) {
		return arg1;
	}
	/// from Float:
	inline __syn_smv___e1_e2_ni_nof2_0 ___syn_smv___e1_e2_ni_nof2_0(__syn_smv___e1_e2_ni_nof2_0::Float arg1) {
		return __syn_smv___e1_e2_ni_nof2_0(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __syn_smv___e1_e2_ni_nof2_0 like(const mv &what, const __syn_smv___e1_e2_ni_nof2_0 &example) {return ___syn_smv___e1_e2_ni_nof2_0(what);}
	/// from const specialization class:
	inline const __syn_smv___e1_e2_ni_nof2_0 like(const __syn_smv___e1_e2_ni_nof2_0 &what, const __syn_smv___e1_e2_ni_nof2_0 &example) {return ___syn_smv___e1_e2_ni_nof2_0(what);}
	/// from non-const specialization class:
	inline __syn_smv___e1_e2_ni_nof2_0 like(__syn_smv___e1_e2_ni_nof2_0 &what, const __syn_smv___e1_e2_ni_nof2_0 &example) {return ___syn_smv___e1_e2_ni_nof2_0(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __syn_smv___e1_e2_ni_nof2_0 & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __syn_smv___e1_e2_ni_nof2_0 & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __syn_smv___e1_e2_ni_nof2_0 & v) {
		return (float)0;
	}


	/// enum for the coordinates of __syn_smv___e1_e2_ni 
	enum ____syn_smv___e1_e2_ni_coordinates__ {__syn_smv___e1_e2_ni_e1_e2_ni};

	class __syn_smv___e1_e2_ni {
		public:
			typedef float Float;

		/// zero constructor
		inline __syn_smv___e1_e2_ni() {

			set();
		}

		/// scalar constructor 
		inline __syn_smv___e1_e2_ni(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __syn_smv___e1_e2_ni	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __syn_smv___e1_e2_ni(const __syn_smv___e1_e2_ni &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __syn_smv___e1_e2_ni(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __syn_smv___e1_e2_ni	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __syn_smv___e1_e2_ni(____syn_smv___e1_e2_ni_coordinates__, const Float *coordinates) {

			set(__syn_smv___e1_e2_ni_e1_e2_ni, coordinates);
		}

		/// coordinates constructor
		inline __syn_smv___e1_e2_ni(____syn_smv___e1_e2_ni_coordinates__, Float c_e1, Float c_e2, Float c_ni) {

			set(__syn_smv___e1_e2_ni_e1_e2_ni, c_e1, c_e2, c_ni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __syn_smv___e1_e2_ni &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____syn_smv___e1_e2_ni_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____syn_smv___e1_e2_ni_coordinates__, Float c_e1, Float c_e2, Float c_ni);

		/// assign copy
		__syn_smv___e1_e2_ni &operator=(const __syn_smv___e1_e2_ni &arg1);

		/// assign general multivector
		__syn_smv___e1_e2_ni &operator=(const mv &arg1);

		/// assign scalar
		__syn_smv___e1_e2_ni &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1() const {
			return m_c[0];
		}
		inline Float e2() const {
			return m_c[1];
		}
		inline Float ni() const {
			return m_c[2];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____syn_smv___e1_e2_ni_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[3];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __syn_smv___e1_e2_ni 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __syn_smv___e1_e2_ni ___syn_smv___e1_e2_ni(const mv &arg1) {
		return __syn_smv___e1_e2_ni(arg1, 0);
	}
	/// from const specialization class:
	inline const __syn_smv___e1_e2_ni &___syn_smv___e1_e2_ni(const __syn_smv___e1_e2_ni &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __syn_smv___e1_e2_ni &___syn_smv___e1_e2_ni(__syn_smv___e1_e2_ni &arg1) {
		return arg1;
	}
	/// from Float:
	inline __syn_smv___e1_e2_ni ___syn_smv___e1_e2_ni(__syn_smv___e1_e2_ni::Float arg1) {
		return __syn_smv___e1_e2_ni(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __syn_smv___e1_e2_ni like(const mv &what, const __syn_smv___e1_e2_ni &example) {return ___syn_smv___e1_e2_ni(what);}
	/// from const specialization class:
	inline const __syn_smv___e1_e2_ni like(const __syn_smv___e1_e2_ni &what, const __syn_smv___e1_e2_ni &example) {return ___syn_smv___e1_e2_ni(what);}
	/// from non-const specialization class:
	inline __syn_smv___e1_e2_ni like(__syn_smv___e1_e2_ni &what, const __syn_smv___e1_e2_ni &example) {return ___syn_smv___e1_e2_ni(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __syn_smv___e1_e2_ni & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __syn_smv___e1_e2_ni & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __syn_smv___e1_e2_ni & v) {
		return (float)0;
	}


	/// enum for the coordinates of __syn_smv___noe1_noe2_noni 
	enum ____syn_smv___noe1_noe2_noni_coordinates__ {__syn_smv___noe1_noe2_noni_noe1_noe2_noni};

	class __syn_smv___noe1_noe2_noni {
		public:
			typedef float Float;

		/// zero constructor
		inline __syn_smv___noe1_noe2_noni() {

			set();
		}

		/// scalar constructor 
		inline __syn_smv___noe1_noe2_noni(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __syn_smv___noe1_noe2_noni	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __syn_smv___noe1_noe2_noni(const __syn_smv___noe1_noe2_noni &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __syn_smv___noe1_noe2_noni(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __syn_smv___noe1_noe2_noni	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __syn_smv___noe1_noe2_noni(____syn_smv___noe1_noe2_noni_coordinates__, const Float *coordinates) {

			set(__syn_smv___noe1_noe2_noni_noe1_noe2_noni, coordinates);
		}

		/// coordinates constructor
		inline __syn_smv___noe1_noe2_noni(____syn_smv___noe1_noe2_noni_coordinates__, Float c_noe1, Float c_noe2, Float c_noni) {

			set(__syn_smv___noe1_noe2_noni_noe1_noe2_noni, c_noe1, c_noe2, c_noni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __syn_smv___noe1_noe2_noni &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____syn_smv___noe1_noe2_noni_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____syn_smv___noe1_noe2_noni_coordinates__, Float c_noe1, Float c_noe2, Float c_noni);

		/// assign copy
		__syn_smv___noe1_noe2_noni &operator=(const __syn_smv___noe1_noe2_noni &arg1);

		/// assign general multivector
		__syn_smv___noe1_noe2_noni &operator=(const mv &arg1);

		/// assign scalar
		__syn_smv___noe1_noe2_noni &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float noe1() const {
			return m_c[0];
		}
		inline Float noe2() const {
			return m_c[1];
		}
		inline Float noni() const {
			return m_c[2];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____syn_smv___noe1_noe2_noni_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[3];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __syn_smv___noe1_noe2_noni 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __syn_smv___noe1_noe2_noni ___syn_smv___noe1_noe2_noni(const mv &arg1) {
		return __syn_smv___noe1_noe2_noni(arg1, 0);
	}
	/// from const specialization class:
	inline const __syn_smv___noe1_noe2_noni &___syn_smv___noe1_noe2_noni(const __syn_smv___noe1_noe2_noni &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __syn_smv___noe1_noe2_noni &___syn_smv___noe1_noe2_noni(__syn_smv___noe1_noe2_noni &arg1) {
		return arg1;
	}
	/// from Float:
	inline __syn_smv___noe1_noe2_noni ___syn_smv___noe1_noe2_noni(__syn_smv___noe1_noe2_noni::Float arg1) {
		return __syn_smv___noe1_noe2_noni(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __syn_smv___noe1_noe2_noni like(const mv &what, const __syn_smv___noe1_noe2_noni &example) {return ___syn_smv___noe1_noe2_noni(what);}
	/// from const specialization class:
	inline const __syn_smv___noe1_noe2_noni like(const __syn_smv___noe1_noe2_noni &what, const __syn_smv___noe1_noe2_noni &example) {return ___syn_smv___noe1_noe2_noni(what);}
	/// from non-const specialization class:
	inline __syn_smv___noe1_noe2_noni like(__syn_smv___noe1_noe2_noni &what, const __syn_smv___noe1_noe2_noni &example) {return ___syn_smv___noe1_noe2_noni(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __syn_smv___noe1_noe2_noni & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __syn_smv___noe1_noe2_noni & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __syn_smv___noe1_noe2_noni & v) {
		return (float)0;
	}


	/// enum for the coordinates of __syn_smv___no_noe1e2_noe1ni_noe2ni 
	enum ____syn_smv___no_noe1e2_noe1ni_noe2ni_coordinates__ {__syn_smv___no_noe1e2_noe1ni_noe2ni_no_noe1e2_noe1ni_noe2ni};

	class __syn_smv___no_noe1e2_noe1ni_noe2ni {
		public:
			typedef float Float;

		/// zero constructor
		inline __syn_smv___no_noe1e2_noe1ni_noe2ni() {

			set();
		}

		/// scalar constructor 
		inline __syn_smv___no_noe1e2_noe1ni_noe2ni(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __syn_smv___no_noe1e2_noe1ni_noe2ni	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __syn_smv___no_noe1e2_noe1ni_noe2ni(const __syn_smv___no_noe1e2_noe1ni_noe2ni &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __syn_smv___no_noe1e2_noe1ni_noe2ni(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __syn_smv___no_noe1e2_noe1ni_noe2ni	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __syn_smv___no_noe1e2_noe1ni_noe2ni(____syn_smv___no_noe1e2_noe1ni_noe2ni_coordinates__, const Float *coordinates) {

			set(__syn_smv___no_noe1e2_noe1ni_noe2ni_no_noe1e2_noe1ni_noe2ni, coordinates);
		}

		/// coordinates constructor
		inline __syn_smv___no_noe1e2_noe1ni_noe2ni(____syn_smv___no_noe1e2_noe1ni_noe2ni_coordinates__, Float c_no, Float c_noe1e2, Float c_noe1ni, Float c_noe2ni) {

			set(__syn_smv___no_noe1e2_noe1ni_noe2ni_no_noe1e2_noe1ni_noe2ni, c_no, c_noe1e2, c_noe1ni, c_noe2ni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __syn_smv___no_noe1e2_noe1ni_noe2ni &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____syn_smv___no_noe1e2_noe1ni_noe2ni_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____syn_smv___no_noe1e2_noe1ni_noe2ni_coordinates__, Float c_no, Float c_noe1e2, Float c_noe1ni, Float c_noe2ni);

		/// assign copy
		__syn_smv___no_noe1e2_noe1ni_noe2ni &operator=(const __syn_smv___no_noe1e2_noe1ni_noe2ni &arg1);

		/// assign general multivector
		__syn_smv___no_noe1e2_noe1ni_noe2ni &operator=(const mv &arg1);

		/// assign scalar
		__syn_smv___no_noe1e2_noe1ni_noe2ni &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float no() const {
			return m_c[0];
		}
		inline Float noe1e2() const {
			return m_c[1];
		}
		inline Float noe1ni() const {
			return m_c[2];
		}
		inline Float noe2ni() const {
			return m_c[3];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____syn_smv___no_noe1e2_noe1ni_noe2ni_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[4];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __syn_smv___no_noe1e2_noe1ni_noe2ni 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __syn_smv___no_noe1e2_noe1ni_noe2ni ___syn_smv___no_noe1e2_noe1ni_noe2ni(const mv &arg1) {
		return __syn_smv___no_noe1e2_noe1ni_noe2ni(arg1, 0);
	}
	/// from const specialization class:
	inline const __syn_smv___no_noe1e2_noe1ni_noe2ni &___syn_smv___no_noe1e2_noe1ni_noe2ni(const __syn_smv___no_noe1e2_noe1ni_noe2ni &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __syn_smv___no_noe1e2_noe1ni_noe2ni &___syn_smv___no_noe1e2_noe1ni_noe2ni(__syn_smv___no_noe1e2_noe1ni_noe2ni &arg1) {
		return arg1;
	}
	/// from Float:
	inline __syn_smv___no_noe1e2_noe1ni_noe2ni ___syn_smv___no_noe1e2_noe1ni_noe2ni(__syn_smv___no_noe1e2_noe1ni_noe2ni::Float arg1) {
		return __syn_smv___no_noe1e2_noe1ni_noe2ni(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __syn_smv___no_noe1e2_noe1ni_noe2ni like(const mv &what, const __syn_smv___no_noe1e2_noe1ni_noe2ni &example) {return ___syn_smv___no_noe1e2_noe1ni_noe2ni(what);}
	/// from const specialization class:
	inline const __syn_smv___no_noe1e2_noe1ni_noe2ni like(const __syn_smv___no_noe1e2_noe1ni_noe2ni &what, const __syn_smv___no_noe1e2_noe1ni_noe2ni &example) {return ___syn_smv___no_noe1e2_noe1ni_noe2ni(what);}
	/// from non-const specialization class:
	inline __syn_smv___no_noe1e2_noe1ni_noe2ni like(__syn_smv___no_noe1e2_noe1ni_noe2ni &what, const __syn_smv___no_noe1e2_noe1ni_noe2ni &example) {return ___syn_smv___no_noe1e2_noe1ni_noe2ni(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __syn_smv___no_noe1e2_noe1ni_noe2ni & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __syn_smv___no_noe1e2_noe1ni_noe2ni & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __syn_smv___no_noe1e2_noe1ni_noe2ni & v) {
		return (float)0;
	}


	/// enum for the coordinates of __syn_smv___scalar_e1e2_e1ni 
	enum ____syn_smv___scalar_e1e2_e1ni_coordinates__ {__syn_smv___scalar_e1e2_e1ni_scalar_e1e2_e1ni};

	class __syn_smv___scalar_e1e2_e1ni {
		public:
			typedef float Float;

		/// zero constructor
		inline __syn_smv___scalar_e1e2_e1ni() {

			set();
		}

		/// scalar constructor 
		inline __syn_smv___scalar_e1e2_e1ni(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __syn_smv___scalar_e1e2_e1ni	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __syn_smv___scalar_e1e2_e1ni(const __syn_smv___scalar_e1e2_e1ni &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __syn_smv___scalar_e1e2_e1ni(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __syn_smv___scalar_e1e2_e1ni	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __syn_smv___scalar_e1e2_e1ni(____syn_smv___scalar_e1e2_e1ni_coordinates__, const Float *coordinates) {

			set(__syn_smv___scalar_e1e2_e1ni_scalar_e1e2_e1ni, coordinates);
		}

		/// coordinates constructor
		inline __syn_smv___scalar_e1e2_e1ni(____syn_smv___scalar_e1e2_e1ni_coordinates__, Float c_scalar, Float c_e1e2, Float c_e1ni) {

			set(__syn_smv___scalar_e1e2_e1ni_scalar_e1e2_e1ni, c_scalar, c_e1e2, c_e1ni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __syn_smv___scalar_e1e2_e1ni &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____syn_smv___scalar_e1e2_e1ni_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____syn_smv___scalar_e1e2_e1ni_coordinates__, Float c_scalar, Float c_e1e2, Float c_e1ni);

		/// assign copy
		__syn_smv___scalar_e1e2_e1ni &operator=(const __syn_smv___scalar_e1e2_e1ni &arg1);

		/// assign general multivector
		__syn_smv___scalar_e1e2_e1ni &operator=(const mv &arg1);

		/// assign scalar
		__syn_smv___scalar_e1e2_e1ni &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1e2() const {
			return m_c[1];
		}
		inline Float e1ni() const {
			return m_c[2];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____syn_smv___scalar_e1e2_e1ni_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[3];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __syn_smv___scalar_e1e2_e1ni 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __syn_smv___scalar_e1e2_e1ni ___syn_smv___scalar_e1e2_e1ni(const mv &arg1) {
		return __syn_smv___scalar_e1e2_e1ni(arg1, 0);
	}
	/// from const specialization class:
	inline const __syn_smv___scalar_e1e2_e1ni &___syn_smv___scalar_e1e2_e1ni(const __syn_smv___scalar_e1e2_e1ni &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __syn_smv___scalar_e1e2_e1ni &___syn_smv___scalar_e1e2_e1ni(__syn_smv___scalar_e1e2_e1ni &arg1) {
		return arg1;
	}
	/// from Float:
	inline __syn_smv___scalar_e1e2_e1ni ___syn_smv___scalar_e1e2_e1ni(__syn_smv___scalar_e1e2_e1ni::Float arg1) {
		return __syn_smv___scalar_e1e2_e1ni(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __syn_smv___scalar_e1e2_e1ni like(const mv &what, const __syn_smv___scalar_e1e2_e1ni &example) {return ___syn_smv___scalar_e1e2_e1ni(what);}
	/// from const specialization class:
	inline const __syn_smv___scalar_e1e2_e1ni like(const __syn_smv___scalar_e1e2_e1ni &what, const __syn_smv___scalar_e1e2_e1ni &example) {return ___syn_smv___scalar_e1e2_e1ni(what);}
	/// from non-const specialization class:
	inline __syn_smv___scalar_e1e2_e1ni like(__syn_smv___scalar_e1e2_e1ni &what, const __syn_smv___scalar_e1e2_e1ni &example) {return ___syn_smv___scalar_e1e2_e1ni(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __syn_smv___scalar_e1e2_e1ni & v) {
		return (float)v.m_c[0];
	}
	/// returns scalar part of v as double
	inline double _double(const __syn_smv___scalar_e1e2_e1ni & v) {
		return (double)v.m_c[0];
	}
	/// returns scalar part of v as Float
	inline float _Float(const __syn_smv___scalar_e1e2_e1ni & v) {
		return v.m_c[0];
	}


	/// enum for the coordinates of __syn_smv___e1_e2_ni_e1e2ni 
	enum ____syn_smv___e1_e2_ni_e1e2ni_coordinates__ {__syn_smv___e1_e2_ni_e1e2ni_e1_e2_ni_e1e2ni};

	class __syn_smv___e1_e2_ni_e1e2ni {
		public:
			typedef float Float;

		/// zero constructor
		inline __syn_smv___e1_e2_ni_e1e2ni() {

			set();
		}

		/// scalar constructor 
		inline __syn_smv___e1_e2_ni_e1e2ni(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __syn_smv___e1_e2_ni_e1e2ni	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __syn_smv___e1_e2_ni_e1e2ni(const __syn_smv___e1_e2_ni_e1e2ni &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __syn_smv___e1_e2_ni_e1e2ni(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __syn_smv___e1_e2_ni_e1e2ni	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __syn_smv___e1_e2_ni_e1e2ni(____syn_smv___e1_e2_ni_e1e2ni_coordinates__, const Float *coordinates) {

			set(__syn_smv___e1_e2_ni_e1e2ni_e1_e2_ni_e1e2ni, coordinates);
		}

		/// coordinates constructor
		inline __syn_smv___e1_e2_ni_e1e2ni(____syn_smv___e1_e2_ni_e1e2ni_coordinates__, Float c_e1, Float c_e2, Float c_ni, Float c_e1e2ni) {

			set(__syn_smv___e1_e2_ni_e1e2ni_e1_e2_ni_e1e2ni, c_e1, c_e2, c_ni, c_e1e2ni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __syn_smv___e1_e2_ni_e1e2ni &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____syn_smv___e1_e2_ni_e1e2ni_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____syn_smv___e1_e2_ni_e1e2ni_coordinates__, Float c_e1, Float c_e2, Float c_ni, Float c_e1e2ni);

		/// assign copy
		__syn_smv___e1_e2_ni_e1e2ni &operator=(const __syn_smv___e1_e2_ni_e1e2ni &arg1);

		/// assign general multivector
		__syn_smv___e1_e2_ni_e1e2ni &operator=(const mv &arg1);

		/// assign scalar
		__syn_smv___e1_e2_ni_e1e2ni &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1() const {
			return m_c[0];
		}
		inline Float e2() const {
			return m_c[1];
		}
		inline Float ni() const {
			return m_c[2];
		}
		inline Float e1e2ni() const {
			return m_c[3];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____syn_smv___e1_e2_ni_e1e2ni_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[4];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __syn_smv___e1_e2_ni_e1e2ni 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __syn_smv___e1_e2_ni_e1e2ni ___syn_smv___e1_e2_ni_e1e2ni(const mv &arg1) {
		return __syn_smv___e1_e2_ni_e1e2ni(arg1, 0);
	}
	/// from const specialization class:
	inline const __syn_smv___e1_e2_ni_e1e2ni &___syn_smv___e1_e2_ni_e1e2ni(const __syn_smv___e1_e2_ni_e1e2ni &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __syn_smv___e1_e2_ni_e1e2ni &___syn_smv___e1_e2_ni_e1e2ni(__syn_smv___e1_e2_ni_e1e2ni &arg1) {
		return arg1;
	}
	/// from Float:
	inline __syn_smv___e1_e2_ni_e1e2ni ___syn_smv___e1_e2_ni_e1e2ni(__syn_smv___e1_e2_ni_e1e2ni::Float arg1) {
		return __syn_smv___e1_e2_ni_e1e2ni(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __syn_smv___e1_e2_ni_e1e2ni like(const mv &what, const __syn_smv___e1_e2_ni_e1e2ni &example) {return ___syn_smv___e1_e2_ni_e1e2ni(what);}
	/// from const specialization class:
	inline const __syn_smv___e1_e2_ni_e1e2ni like(const __syn_smv___e1_e2_ni_e1e2ni &what, const __syn_smv___e1_e2_ni_e1e2ni &example) {return ___syn_smv___e1_e2_ni_e1e2ni(what);}
	/// from non-const specialization class:
	inline __syn_smv___e1_e2_ni_e1e2ni like(__syn_smv___e1_e2_ni_e1e2ni &what, const __syn_smv___e1_e2_ni_e1e2ni &example) {return ___syn_smv___e1_e2_ni_e1e2ni(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __syn_smv___e1_e2_ni_e1e2ni & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __syn_smv___e1_e2_ni_e1e2ni & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __syn_smv___e1_e2_ni_e1e2ni & v) {
		return (float)0;
	}


	/// enum for the coordinates of __syn_smv___scalar_e1e2_e2ni 
	enum ____syn_smv___scalar_e1e2_e2ni_coordinates__ {__syn_smv___scalar_e1e2_e2ni_scalar_e1e2_e2ni};

	class __syn_smv___scalar_e1e2_e2ni {
		public:
			typedef float Float;

		/// zero constructor
		inline __syn_smv___scalar_e1e2_e2ni() {

			set();
		}

		/// scalar constructor 
		inline __syn_smv___scalar_e1e2_e2ni(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __syn_smv___scalar_e1e2_e2ni	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __syn_smv___scalar_e1e2_e2ni(const __syn_smv___scalar_e1e2_e2ni &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __syn_smv___scalar_e1e2_e2ni(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __syn_smv___scalar_e1e2_e2ni	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __syn_smv___scalar_e1e2_e2ni(____syn_smv___scalar_e1e2_e2ni_coordinates__, const Float *coordinates) {

			set(__syn_smv___scalar_e1e2_e2ni_scalar_e1e2_e2ni, coordinates);
		}

		/// coordinates constructor
		inline __syn_smv___scalar_e1e2_e2ni(____syn_smv___scalar_e1e2_e2ni_coordinates__, Float c_scalar, Float c_e1e2, Float c_e2ni) {

			set(__syn_smv___scalar_e1e2_e2ni_scalar_e1e2_e2ni, c_scalar, c_e1e2, c_e2ni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __syn_smv___scalar_e1e2_e2ni &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____syn_smv___scalar_e1e2_e2ni_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____syn_smv___scalar_e1e2_e2ni_coordinates__, Float c_scalar, Float c_e1e2, Float c_e2ni);

		/// assign copy
		__syn_smv___scalar_e1e2_e2ni &operator=(const __syn_smv___scalar_e1e2_e2ni &arg1);

		/// assign general multivector
		__syn_smv___scalar_e1e2_e2ni &operator=(const mv &arg1);

		/// assign scalar
		__syn_smv___scalar_e1e2_e2ni &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float e1e2() const {
			return m_c[1];
		}
		inline Float e2ni() const {
			return m_c[2];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____syn_smv___scalar_e1e2_e2ni_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[3];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __syn_smv___scalar_e1e2_e2ni 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __syn_smv___scalar_e1e2_e2ni ___syn_smv___scalar_e1e2_e2ni(const mv &arg1) {
		return __syn_smv___scalar_e1e2_e2ni(arg1, 0);
	}
	/// from const specialization class:
	inline const __syn_smv___scalar_e1e2_e2ni &___syn_smv___scalar_e1e2_e2ni(const __syn_smv___scalar_e1e2_e2ni &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __syn_smv___scalar_e1e2_e2ni &___syn_smv___scalar_e1e2_e2ni(__syn_smv___scalar_e1e2_e2ni &arg1) {
		return arg1;
	}
	/// from Float:
	inline __syn_smv___scalar_e1e2_e2ni ___syn_smv___scalar_e1e2_e2ni(__syn_smv___scalar_e1e2_e2ni::Float arg1) {
		return __syn_smv___scalar_e1e2_e2ni(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __syn_smv___scalar_e1e2_e2ni like(const mv &what, const __syn_smv___scalar_e1e2_e2ni &example) {return ___syn_smv___scalar_e1e2_e2ni(what);}
	/// from const specialization class:
	inline const __syn_smv___scalar_e1e2_e2ni like(const __syn_smv___scalar_e1e2_e2ni &what, const __syn_smv___scalar_e1e2_e2ni &example) {return ___syn_smv___scalar_e1e2_e2ni(what);}
	/// from non-const specialization class:
	inline __syn_smv___scalar_e1e2_e2ni like(__syn_smv___scalar_e1e2_e2ni &what, const __syn_smv___scalar_e1e2_e2ni &example) {return ___syn_smv___scalar_e1e2_e2ni(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __syn_smv___scalar_e1e2_e2ni & v) {
		return (float)v.m_c[0];
	}
	/// returns scalar part of v as double
	inline double _double(const __syn_smv___scalar_e1e2_e2ni & v) {
		return (double)v.m_c[0];
	}
	/// returns scalar part of v as Float
	inline float _Float(const __syn_smv___scalar_e1e2_e2ni & v) {
		return v.m_c[0];
	}


	/// enum for the coordinates of __syn_smv___scalarf0_0 
	enum ____syn_smv___scalarf0_0_coordinates__ {__syn_smv___scalarf0_0_scalarf0_0};

	class __syn_smv___scalarf0_0 {
		public:
			typedef float Float;

		/// zero constructor
		inline __syn_smv___scalarf0_0() {

			set();
		}

		/// scalar constructor 
		inline __syn_smv___scalarf0_0(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __syn_smv___scalarf0_0	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __syn_smv___scalarf0_0(const __syn_smv___scalarf0_0 &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __syn_smv___scalarf0_0(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __syn_smv___scalarf0_0	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __syn_smv___scalarf0_0(____syn_smv___scalarf0_0_coordinates__, const Float *coordinates) {

			set(__syn_smv___scalarf0_0_scalarf0_0, coordinates);
		}

		/// coordinates constructor
		inline __syn_smv___scalarf0_0(____syn_smv___scalarf0_0_coordinates__) {

			set(__syn_smv___scalarf0_0_scalarf0_0);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __syn_smv___scalarf0_0 &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____syn_smv___scalarf0_0_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____syn_smv___scalarf0_0_coordinates__);

		/// assign copy
		__syn_smv___scalarf0_0 &operator=(const __syn_smv___scalarf0_0 &arg1);

		/// assign general multivector
		__syn_smv___scalarf0_0 &operator=(const mv &arg1);

		/// assign scalar
		__syn_smv___scalarf0_0 &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____syn_smv___scalarf0_0_coordinates__ sanityCheckValue) const {
			return NULL;
		}

		// constants, so no coordinate storage



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __syn_smv___scalarf0_0 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __syn_smv___scalarf0_0 ___syn_smv___scalarf0_0(const mv &arg1) {
		return __syn_smv___scalarf0_0(arg1, 0);
	}
	/// from const specialization class:
	inline const __syn_smv___scalarf0_0 &___syn_smv___scalarf0_0(const __syn_smv___scalarf0_0 &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __syn_smv___scalarf0_0 &___syn_smv___scalarf0_0(__syn_smv___scalarf0_0 &arg1) {
		return arg1;
	}
	/// from Float:
	inline __syn_smv___scalarf0_0 ___syn_smv___scalarf0_0(__syn_smv___scalarf0_0::Float arg1) {
		return __syn_smv___scalarf0_0(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __syn_smv___scalarf0_0 like(const mv &what, const __syn_smv___scalarf0_0 &example) {return ___syn_smv___scalarf0_0(what);}
	/// from const specialization class:
	inline const __syn_smv___scalarf0_0 like(const __syn_smv___scalarf0_0 &what, const __syn_smv___scalarf0_0 &example) {return ___syn_smv___scalarf0_0(what);}
	/// from non-const specialization class:
	inline __syn_smv___scalarf0_0 like(__syn_smv___scalarf0_0 &what, const __syn_smv___scalarf0_0 &example) {return ___syn_smv___scalarf0_0(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __syn_smv___scalarf0_0 & v) {
		return (float)0.0f;
	}
	/// returns scalar part of v as double
	inline double _double(const __syn_smv___scalarf0_0 & v) {
		return (double)0.0f;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __syn_smv___scalarf0_0 & v) {
		return (float)0.0f;
	}


	/// enum for the coordinates of __syn_smv___ni_e1e2ni 
	enum ____syn_smv___ni_e1e2ni_coordinates__ {__syn_smv___ni_e1e2ni_ni_e1e2ni};

	class __syn_smv___ni_e1e2ni {
		public:
			typedef float Float;

		/// zero constructor
		inline __syn_smv___ni_e1e2ni() {

			set();
		}

		/// scalar constructor 
		inline __syn_smv___ni_e1e2ni(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __syn_smv___ni_e1e2ni	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __syn_smv___ni_e1e2ni(const __syn_smv___ni_e1e2ni &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __syn_smv___ni_e1e2ni(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __syn_smv___ni_e1e2ni	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __syn_smv___ni_e1e2ni(____syn_smv___ni_e1e2ni_coordinates__, const Float *coordinates) {

			set(__syn_smv___ni_e1e2ni_ni_e1e2ni, coordinates);
		}

		/// coordinates constructor
		inline __syn_smv___ni_e1e2ni(____syn_smv___ni_e1e2ni_coordinates__, Float c_ni, Float c_e1e2ni) {

			set(__syn_smv___ni_e1e2ni_ni_e1e2ni, c_ni, c_e1e2ni);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __syn_smv___ni_e1e2ni &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____syn_smv___ni_e1e2ni_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____syn_smv___ni_e1e2ni_coordinates__, Float c_ni, Float c_e1e2ni);

		/// assign copy
		__syn_smv___ni_e1e2ni &operator=(const __syn_smv___ni_e1e2ni &arg1);

		/// assign general multivector
		__syn_smv___ni_e1e2ni &operator=(const mv &arg1);

		/// assign scalar
		__syn_smv___ni_e1e2ni &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name
		inline Float ni() const {
			return m_c[0];
		}
		inline Float e1e2ni() const {
			return m_c[1];
		}

		/// const coordinate extraction by name

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____syn_smv___ni_e1e2ni_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[2];



		inline const char * c_str(const char *fp = NULL) const {
			return ::c2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::c2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __syn_smv___ni_e1e2ni 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __syn_smv___ni_e1e2ni ___syn_smv___ni_e1e2ni(const mv &arg1) {
		return __syn_smv___ni_e1e2ni(arg1, 0);
	}
	/// from const specialization class:
	inline const __syn_smv___ni_e1e2ni &___syn_smv___ni_e1e2ni(const __syn_smv___ni_e1e2ni &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __syn_smv___ni_e1e2ni &___syn_smv___ni_e1e2ni(__syn_smv___ni_e1e2ni &arg1) {
		return arg1;
	}
	/// from Float:
	inline __syn_smv___ni_e1e2ni ___syn_smv___ni_e1e2ni(__syn_smv___ni_e1e2ni::Float arg1) {
		return __syn_smv___ni_e1e2ni(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __syn_smv___ni_e1e2ni like(const mv &what, const __syn_smv___ni_e1e2ni &example) {return ___syn_smv___ni_e1e2ni(what);}
	/// from const specialization class:
	inline const __syn_smv___ni_e1e2ni like(const __syn_smv___ni_e1e2ni &what, const __syn_smv___ni_e1e2ni &example) {return ___syn_smv___ni_e1e2ni(what);}
	/// from non-const specialization class:
	inline __syn_smv___ni_e1e2ni like(__syn_smv___ni_e1e2ni &what, const __syn_smv___ni_e1e2ni &example) {return ___syn_smv___ni_e1e2ni(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __syn_smv___ni_e1e2ni & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __syn_smv___ni_e1e2ni & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __syn_smv___ni_e1e2ni & v) {
		return (float)0;
	}


	class om {
		public:
			typedef float Float;

		/// identity 'I' constructor
		inline om() {
			set();
		}

		/// copy constructor (MUST PASS BY REFERENCE!)
		inline om(const om &arg1) {
			set(arg1);
		}

		/// scalar constructor (creates scalar * 'I' outermorphism)
		inline om(Float scalar) {
			set(scalar);
		}

		/// pointer to coordinates constructor
		inline om(const Float *coordinates) {
			set(coordinates);
		}

		/// pointer to coordinates/transpose constructor
		inline om(const Float *coordinates, bool transpose) {
			set(coordinates, transpose);
		}

		/// constructor from basis vectors array
		inline om(const point *vectors) {
			set(vectors);
		}

		/// constructor from basis vectors 
		inline om(const point & image_of_no, const point & image_of_e1, const point & image_of_e2, const point & image_of_ni) {
			set(image_of_no, image_of_e1, image_of_e2, image_of_ni);
		}


		/// set to identity 'I'
		void set();

		/// set to copy
		void set(const om &arg1);

		/// set to scalar (creates scalar * 'I' outermorphism)
		void set(Float scalarVal);

		/// set to coordinates 
		void set(const Float *coordinates);

		/// set to coordinates/transpose 
		void set(const Float *coordinates, bool transpose);

		/// set from basis vectors array
		void set(const point *vectors);

		/// set from basis vectors 
		void set(
			const point & image_of_no, const point & image_of_e1, const point & image_of_e2, const point & image_of_ni);


		/// assign copy
		om &operator=(const om &arg1);

		/// assign scalar (creates scalar * 'I' outermorphism)
		om &operator=(Float scalarVal);

		/// assign specialization:


		Float m_c[69]; ///< coordinate storage




	}; // end of class om



	// multivector type
	class mvType : public mvTypeBase {
		public:

			inline mvType() {
		}

		/** Creates a new instance of MultivectorInfo */
		inline mvType(const mv &X) {
			init(X, (mv::Float)0.0);
		}

		/** Creates a new instance of MultivectorInfo */
		inline mvType(const mv &X, mv::Float epsilon) {
			init(X, epsilon);
		}

		inline mvType(const mvType &T) {
		}


		void init(const mv &X, mv::Float epsilon);

		std::string toString() const;

		protected:
			void init(const mv &X, mv::Float epsilon, bool useAlgebraMetric, int guCnt);
	};



	mv::Float fastFactorBlade(const mv &X, point factor[], int gradeOfX = -1);
	void fastJoinBlades(const mv &A, const mv &B, mv &J, mv *M = NULL);



	// extra underscore constructors from profile:
	inline vectorE2GA _vectorE2GA(const point &arg1) {

		return vectorE2GA(vectorE2GA_e1_e2	, (float)arg1.m_c[1], (float)arg1.m_c[2]);
	}
	inline normalizedPoint _normalizedPoint(const __no_ct__ &arg1) {

		return normalizedPoint(normalizedPoint_e1_e2_ni_nof1_0	, (float)0, (float)0, (float)0);
	}
	inline normalizedTranslator _normalizedTranslator(const translator &arg1) {

		return normalizedTranslator(normalizedTranslator_e1ni_e2ni_scalarf1_0	, (float)arg1.m_c[1], (float)arg1.m_c[2]);
	}
	inline normalizedPoint _normalizedPoint(const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni &arg1) {

		return normalizedPoint(normalizedPoint_e1_e2_ni_nof1_0	, (float)arg1.m_c[1], (float)arg1.m_c[2], (float)arg1.m_c[3]);
	}
	inline vectorE2GA _vectorE2GA(const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni &arg1) {

		return vectorE2GA(vectorE2GA_e1_e2	, (float)arg1.m_c[1], (float)arg1.m_c[2]);
	}
	inline vectorE2GA _vectorE2GA(const normalizedPoint &arg1) {

		return vectorE2GA(vectorE2GA_e1_e2	, (float)arg1.m_c[0], (float)arg1.m_c[1]);
	}


	extern __I2_ct__ I2;
	extern __e1ni_ct__ e1ni;
	extern __no_ct__ no;
	extern __I4_ct__ I4;
	extern __e2ni_ct__ e2ni;
	extern __noni_ct__ noni;
	extern __I4i_ct__ I4i;
	extern __ni_ct__ ni;
	extern __e1_ct__ e1;
	extern __e2_ct__ e2;
	mv lcont(const mv& x, const mv& y);
	scalar scp(const mv& x, const mv& y);
	mv gp(const mv& x, const mv& y);
	mv gpEM(const mv& x, const mv& y);
	scalar scpEM(const mv& x, const mv& y);
	mv lcontEM(const mv& x, const mv& y);
	mv op(const mv& x, const mv& y);
	mv add(const mv& x, const mv& y);
	mv subtract(const mv& x, const mv& y);
	scalar norm_e2(const mv& x);
	scalar norm_e(const mv& x);
	mv unit_e(const mv& x);
	scalar norm_r2(const mv& x);
	scalar norm_r(const mv& x);
	mv unit_r(const mv& x);
	mv reverse(const mv& x);
	mv negate(const mv& x);
	mv dual(const mv& x);
	mv undual(const mv& x);
	mv inverse(const mv& x);
	mv inverseEM(const mv& x);
	mv apply_om(const om& x, const mv& y);
	mv gradeInvolution(const mv& x);
	namespace __G2_GENERATED__ {
		void set(om& __x__, const point& __image_of_no__, const point& __image_of_e1__, const point& __image_of_e2__, const point& __image_of_ni__);
	} /* end of namespace __G2_GENERATED__ */
	inline __syn_smv___ni_e1e2ni gp(const freeVector& x, const __syn_smv___e1_e2_ni& y);
	inline scalar norm_e(const __syn_smv___scalarf0_0& x);
	inline scalar norm_r(const bivectorE2GA& x);
	inline TRversorLog inverse(const TRversorLog& x);
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni gp(const circle& x, const TRversorLog& y);
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni subtract(const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& x, const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& y);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni gpEM(const __syn_smv___scalar_noe2_e1e2_e2ni& x, const __syn_smv___e1_e2_ni_nof_1_0& y);
	inline __syn_smv___e1_e2_ni subtract(const normalizedPoint& x, const normalizedPoint& y);
	inline scalar gp(const scalar& x, const scalar& y);
	inline scalar inverse(const scalar& x);
	inline point inverse(const point& x);
	inline ni_t op(const scalar& x, const __ni_ct__& y);
	inline scalar scp(const normalizedPoint& x, const normalizedPoint& y);
	inline __syn_smv___e1_e2_ni gradeInvolution(const __syn_smv___e1_e2_ni& x);
	inline vectorE2GA lcont(const __no_ct__& x, const freeVector& y);
	inline vectorE2GA negate(const vectorE2GA& x);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni gpEM(const __syn_smv___scalar_noe2_e1e2_e2ni& x, const point& y);
	inline ni_t negate(const ni_t& x);
	inline flatPoint op(const __ni_ct__& x, const point& y);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni gp(const __syn_smv___scalar_noe1_noe2_noni& x, const point& y);
	inline scalar scp(const __ni_ct__& x, const point& y);
	inline circle dual(const point& x);
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni gp(const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni& x, const scalar& y);
	inline scalar norm_r2(const normalizedPoint& x);
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni gpEM(const __syn_smv___e1_e2_ni_nof_1_0& x, const point& y);
	inline line inverse(const line& x);
	inline __syn_smv___e1_e2_ni_e1e2ni gp(const __syn_smv___scalar_e1e2_e1ni& x, const __syn_smv___e1_e2_ni& y);
	inline scalar negate(const scalar& x);
	inline scalar norm_e(const flatPoint& x);
	inline scalar scpEM(const __syn_smv___e1_e2_ni& x, const __syn_smv___e1_e2_ni& y);
	inline scalar norm_e(const __syn_smv___scalarf_1_0& x);
	inline __syn_smv___nif_1_0 op(const __syn_smv___scalarf_1_0& x, const __ni_ct__& y);
	inline __syn_smv___scalar_noe1_e1e2_e1ni gpEM(const point& x, const __e1_ct__& y);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni gp(const __syn_smv___scalar_noe1_e1e2_e1ni& x, const point& y);
	inline scalar lcont(const __syn_smv___e1_e2_ni& x, const normalizedPoint& y);
	inline freeVector lcont(const __ni_ct__& x, const line& y);
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni gp(const point& x, const point& y);
	inline scalar lcont(const circle& x, const __syn_smv___e1e2nif1_0& y);
	inline point inverseEM(const normalizedPoint& x);
	inline point gp(const scalar& x, const normalizedPoint& y);
	inline __syn_smv___scalar_e1e2_e2ni gp(const __syn_smv___e1_e2_ni& x, const __e2_ct__& y);
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni gp(const __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0& x, const translator& y);
	inline scalar norm_e(const scalar& x);
	inline vectorE2GA gp(const scalar& x, const vectorE2GA& y);
	inline scalar norm_r2(const __syn_smv___e1_e2_ni& x);
	inline __syn_smv___no_noe1e2_noe1ni_noe2ni gpEM(const __syn_smv___noe1_noe2_noni& x, const __syn_smv___e1_e2_ni& y);
	inline scalar scp(const point& x, const point& y);
	inline point add(const point& x, const point& y);
	inline scalar scp(const __ni_ct__& x, const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni& y);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni gpEM(const __syn_smv___scalar_noe1_noe2_noni& x, const point& y);
	inline scalar norm_e(const __syn_smv___e1ni_e2ni_nonif_1_0& x);
	inline __syn_smv___scalar_e1e2_e2ni gpEM(const __syn_smv___e1_e2_ni& x, const __e2_ct__& y);
	inline point gp(const point& x, const scalar& y);
	inline scalar norm_e(const freeVector& x);
	inline __syn_smv___scalar_noe2_e1e2_e2ni gp(const point& x, const __e2_ct__& y);
	inline __I2_ct__ op(const __e1_ct__& x, const __e2_ct__& y);
	inline point reverse(const point& x);
	inline __syn_smv___scalar_noe1_noe2_noni gpEM(const point& x, const __no_ct__& y);
	inline __syn_smv___e1e2nif1_0 op(const __I2_ct__& x, const __ni_ct__& y);
	inline __syn_smv___e1_e2_ni inverseEM(const __syn_smv___e1_e2_ni& x);
	inline line dual(const __syn_smv___e1_e2_ni& x);
	inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 gp(const normalizedTranslator& x, const normalizedPoint& y);
	inline scalar norm_r(const line& x);
	inline __syn_smv___scalar_noe1_noe2_noni gp(const point& x, const __no_ct__& y);
	inline circle gradeInvolution(const circle& x);
	inline __syn_smv___noe1_noe2_noni gpEM(const __syn_smv___e1_e2_ni& x, const __no_ct__& y);
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni gp(const circle& x, const circle& y);
	inline ni_t gp(const scalar& x, const __ni_ct__& y);
	inline __syn_smv___scalarf_1_0 lcont(const __ni_ct__& x, const normalizedPoint& y);
	inline __syn_smv___scalar_noe2_e1e2_e2ni gpEM(const point& x, const __e2_ct__& y);
	inline normalizedPoint reverse(const normalizedPoint& x);
	inline freeVector negate(const freeVector& x);
	inline scalar scp(const __syn_smv___e1_e2_ni& x, const __syn_smv___e1_e2_ni& y);
	inline freeBivector op(const TRversorLog& x, const __ni_ct__& y);
	inline scalar lcont(const __ni_ct__& x, const point& y);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni gp(const __syn_smv___scalar_noe2_e1e2_e2ni& x, const point& y);
	inline circle negate(const circle& x);
	inline scalar scpEM(const point& x, const point& y);
	inline __syn_smv___e1_e2_ni_e1e2ni gpEM(const __syn_smv___scalar_e1e2_e2ni& x, const __syn_smv___e1_e2_ni& y);
	inline __syn_smv___e1_e2_ni_nof_1_0 gradeInvolution(const normalizedPoint& x);
	inline point inverseEM(const point& x);
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni gpEM(const __syn_smv___scalar_noni_e1ni_e2ni& x, const __syn_smv___e1_e2_ni_nof_1_0& y);
	inline __syn_smv___e1_e2_nof1_0 add(const vectorE2GA& x, const __no_ct__& y);
	inline point subtract(const point& x, const normalizedPoint& y);
	inline __syn_smv___nif1_0 negate(const __syn_smv___nif_1_0& x);
	inline point lcont(const pointPair& x, const line& y);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni gpEM(const __syn_smv___scalar_noe1_e1e2_e1ni& x, const point& y);
	inline scalar norm_e2(const vectorE2GA& x);
	inline __syn_smv___e1_e2_ni inverse(const __syn_smv___e1_e2_ni& x);
	inline translator gpEM(const __syn_smv___e1_e2_ni& x, const __ni_ct__& y);
	inline scalar inverse(const __syn_smv___scalarf_1_0& x);
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni gp(const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& x, const scalar& y);
	inline vectorE2GA subtract(const vectorE2GA& x, const vectorE2GA& y);
	inline freeVector op(const vectorE2GA& x, const __ni_ct__& y);
	inline scalar scpEM(const normalizedPoint& x, const normalizedPoint& y);
	inline point gp(const normalizedPoint& x, const scalar& y);
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni gpEM(const point& x, const point& y);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni gpEM(const __syn_smv___scalar_noe1_noe2_noni& x, const __syn_smv___e1_e2_ni_nof_1_0& y);
	inline vectorE2GA subtract(const e1_t& x, const e2_t& y);
	inline circle op(const pointPair& x, const normalizedPoint& y);
	inline __syn_smv___scalar_noni_e1ni_e2ni gp(const point& x, const __ni_ct__& y);
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni gp(const __syn_smv___scalar_noni_e1ni_e2ni& x, const point& y);
	inline TRversor gp(const __syn_smv___e1_e2_ni& x, const __syn_smv___e1_e2_ni& y);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni gpEM(const __syn_smv___scalar_noe1_e1e2_e1ni& x, const __syn_smv___e1_e2_ni_nof_1_0& y);
	inline TRversor gpEM(const __syn_smv___e1_e2_ni& x, const __syn_smv___e1_e2_ni& y);
	inline freeBivector negate(const freeBivector& x);
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni gpEM(const __syn_smv___scalar_noni_e1ni_e2ni& x, const point& y);
	inline TRversor subtract(const TRversor& x, const TRversor& y);
	inline __syn_smv___scalar_noe1_noe2_noni gp(const __syn_smv___e1_e2_ni& x, const __no_ct__& y);
	inline __syn_smv___e1_e2_ni dual(const line& x);
	inline vectorE2GA unit_e(const vectorE2GA& x);
	inline point gradeInvolution(const point& x);
	inline __syn_smv___scalar_noe1_e1e2_e1ni gp(const point& x, const __e1_ct__& y);
	inline e1_t gp(const scalar& x, const __e1_ct__& y);
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni gpEM(const point& x, const __syn_smv___e1_e2_ni_nof_1_0& y);
	inline translator inverse(const normalizedTranslator& x);
	inline __syn_smv___e1_e2_ni_e1e2ni gpEM(const __syn_smv___scalar_e1e2_e1ni& x, const __syn_smv___e1_e2_ni& y);
	inline __syn_smv___e1ni_e2ni_nonif_1_0 op(const __ni_ct__& x, const normalizedPoint& y);
	inline point gp(const scalar& x, const __syn_smv___e1_e2_ni_nof2_0& y);
	inline TRversorLog lcont(const __ni_ct__& x, const circle& y);
	inline __syn_smv___scalar_noni_e1ni_e2ni gpEM(const point& x, const __ni_ct__& y);
	inline freeVector op(const __ni_ct__& x, const __syn_smv___e1_e2_ni& y);
	inline scalar scp(const TRversorLog& x, const TRversorLog& y);
	inline line op(const pointPair& x, const __ni_ct__& y);
	inline __syn_smv___scalarf0_0 lcont(const __ni_ct__& x, const __syn_smv___e1_e2_ni& y);
	inline pointPair lcont(const normalizedPoint& x, const line& y);
	inline __syn_smv___e1_e2_ni reverse(const __syn_smv___e1_e2_ni& x);
	inline normalizedPoint add(const __syn_smv___e1_e2_nof1_0& x, const ni_t& y);
	inline pointPair op(const normalizedPoint& x, const normalizedPoint& y);
	inline __syn_smv___e1_e2_ni_e1e2ni gpEM(const translator& x, const __syn_smv___e1_e2_ni& y);
	inline bivectorE2GA lcont(const __no_ct__& x, const freeBivector& y);
	inline scalar norm_r2(const point& x);
	inline translator subtract(const scalar& x, const freeVector& y);
	inline __syn_smv___e1_e2_ni_e1e2ni gp(const __syn_smv___scalar_e1e2_e2ni& x, const __syn_smv___e1_e2_ni& y);
	inline __syn_smv___scalar_e1e2_e1ni gpEM(const __syn_smv___e1_e2_ni& x, const __e1_ct__& y);
	inline __syn_smv___e1_e2_ni_nof2_0 add(const normalizedPoint& x, const normalizedPoint& y);
	inline freeVector gp(const __syn_smv___e1_e2_ni& x, const __ni_ct__& y);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni gp(const __syn_smv___scalar_noe1_noe2_noni& x, const __syn_smv___e1_e2_ni& y);
	inline e2_t gp(const scalar& x, const __e2_ct__& y);
	inline __syn_smv___scalar_e1e2_e1ni gp(const __syn_smv___e1_e2_ni& x, const __e1_ct__& y);
	inline mv operator+=(mv& arg1, const mv& arg2);
	inline point operator+=(point& arg1, const point& arg2);
	inline vectorE2GA operator+=(vectorE2GA& arg1, const __no_ct__& arg2);
	inline __syn_smv___e1_e2_nof1_0 operator+=(__syn_smv___e1_e2_nof1_0& arg1, const ni_t& arg2);
	inline normalizedPoint operator+=(normalizedPoint& arg1, const normalizedPoint& arg2);
	inline no_t operator+=(no_t& arg1, const mv& arg2);
	inline e1_t operator+=(e1_t& arg1, const mv& arg2);
	inline e2_t operator+=(e2_t& arg1, const mv& arg2);
	inline ni_t operator+=(ni_t& arg1, const mv& arg2);
	inline scalar operator+=(scalar& arg1, const mv& arg2);
	inline flatPoint operator+=(flatPoint& arg1, const mv& arg2);
	inline normalizedFlatPoint operator+=(normalizedFlatPoint& arg1, const mv& arg2);
	inline pointPair operator+=(pointPair& arg1, const mv& arg2);
	inline TRversorLog operator+=(TRversorLog& arg1, const mv& arg2);
	inline line operator+=(line& arg1, const mv& arg2);
	inline dualLine operator+=(dualLine& arg1, const mv& arg2);
	inline circle operator+=(circle& arg1, const mv& arg2);
	inline freeVector operator+=(freeVector& arg1, const mv& arg2);
	inline freeBivector operator+=(freeBivector& arg1, const mv& arg2);
	inline tangentVector operator+=(tangentVector& arg1, const mv& arg2);
	inline tangentBivector operator+=(tangentBivector& arg1, const mv& arg2);
	inline bivectorE2GA operator+=(bivectorE2GA& arg1, const mv& arg2);
	inline TRversor operator+=(TRversor& arg1, const mv& arg2);
	inline TRSversor operator+=(TRSversor& arg1, const mv& arg2);
	inline evenVersor operator+=(evenVersor& arg1, const mv& arg2);
	inline translator operator+=(translator& arg1, const mv& arg2);
	inline normalizedTranslator operator+=(normalizedTranslator& arg1, const mv& arg2);
	inline rotor operator+=(rotor& arg1, const mv& arg2);
	inline scalor operator+=(scalor& arg1, const mv& arg2);
	inline __no_ct__ operator+=(__no_ct__& arg1, const mv& arg2);
	inline __e1_ct__ operator+=(__e1_ct__& arg1, const mv& arg2);
	inline __e2_ct__ operator+=(__e2_ct__& arg1, const mv& arg2);
	inline __ni_ct__ operator+=(__ni_ct__& arg1, const mv& arg2);
	inline __I4i_ct__ operator+=(__I4i_ct__& arg1, const mv& arg2);
	inline __I4_ct__ operator+=(__I4_ct__& arg1, const mv& arg2);
	inline __I2_ct__ operator+=(__I2_ct__& arg1, const mv& arg2);
	inline __noni_ct__ operator+=(__noni_ct__& arg1, const mv& arg2);
	inline __e2ni_ct__ operator+=(__e2ni_ct__& arg1, const mv& arg2);
	inline __e1ni_ct__ operator+=(__e1ni_ct__& arg1, const mv& arg2);
	inline __syn_smv___e1e2nif1_0 operator+=(__syn_smv___e1e2nif1_0& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_ni_nof_1_0 operator+=(__syn_smv___e1_e2_ni_nof_1_0& arg1, const mv& arg2);
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni operator+=(__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& arg1, const mv& arg2);
	inline __syn_smv___scalar_noe1_noe2_noni operator+=(__syn_smv___scalar_noe1_noe2_noni& arg1, const mv& arg2);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni operator+=(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni& arg1, const mv& arg2);
	inline __syn_smv___scalar_noe1_e1e2_e1ni operator+=(__syn_smv___scalar_noe1_e1e2_e1ni& arg1, const mv& arg2);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni operator+=(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni& arg1, const mv& arg2);
	inline __syn_smv___scalar_noe2_e1e2_e2ni operator+=(__syn_smv___scalar_noe2_e1e2_e2ni& arg1, const mv& arg2);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni operator+=(__syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni& arg1, const mv& arg2);
	inline __syn_smv___scalar_noni_e1ni_e2ni operator+=(__syn_smv___scalar_noni_e1ni_e2ni& arg1, const mv& arg2);
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni operator+=(__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni& arg1, const mv& arg2);
	inline __syn_smv___e1ni_e2ni_nonif_1_0 operator+=(__syn_smv___e1ni_e2ni_nonif_1_0& arg1, const mv& arg2);
	inline __syn_smv___scalarf_1_0 operator+=(__syn_smv___scalarf_1_0& arg1, const mv& arg2);
	inline __syn_smv___nif_1_0 operator+=(__syn_smv___nif_1_0& arg1, const mv& arg2);
	inline __syn_smv___nif1_0 operator+=(__syn_smv___nif1_0& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 operator+=(__syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_ni_nof2_0 operator+=(__syn_smv___e1_e2_ni_nof2_0& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_ni operator+=(__syn_smv___e1_e2_ni& arg1, const mv& arg2);
	inline __syn_smv___noe1_noe2_noni operator+=(__syn_smv___noe1_noe2_noni& arg1, const mv& arg2);
	inline __syn_smv___no_noe1e2_noe1ni_noe2ni operator+=(__syn_smv___no_noe1e2_noe1ni_noe2ni& arg1, const mv& arg2);
	inline __syn_smv___scalar_e1e2_e1ni operator+=(__syn_smv___scalar_e1e2_e1ni& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_ni_e1e2ni operator+=(__syn_smv___e1_e2_ni_e1e2ni& arg1, const mv& arg2);
	inline __syn_smv___scalar_e1e2_e2ni operator+=(__syn_smv___scalar_e1e2_e2ni& arg1, const mv& arg2);
	inline __syn_smv___scalarf0_0 operator+=(__syn_smv___scalarf0_0& arg1, const mv& arg2);
	inline __syn_smv___ni_e1e2ni operator+=(__syn_smv___ni_e1e2ni& arg1, const mv& arg2);
	inline mv operator+(const mv& arg1, const mv& arg2);
	inline point operator+(const point& arg1, const point& arg2);
	inline __syn_smv___e1_e2_nof1_0 operator+(const vectorE2GA& arg1, const __no_ct__& arg2);
	inline normalizedPoint operator+(const __syn_smv___e1_e2_nof1_0& arg1, const ni_t& arg2);
	inline __syn_smv___e1_e2_ni_nof2_0 operator+(const normalizedPoint& arg1, const normalizedPoint& arg2);
	inline mv operator-=(mv& arg1, const mv& arg2);
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni operator-=(__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& arg1, const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& arg2);
	inline normalizedPoint operator-=(normalizedPoint& arg1, const normalizedPoint& arg2);
	inline point operator-=(point& arg1, const normalizedPoint& arg2);
	inline vectorE2GA operator-=(vectorE2GA& arg1, const vectorE2GA& arg2);
	inline e1_t operator-=(e1_t& arg1, const e2_t& arg2);
	inline TRversor operator-=(TRversor& arg1, const TRversor& arg2);
	inline scalar operator-=(scalar& arg1, const freeVector& arg2);
	inline no_t operator-=(no_t& arg1, const mv& arg2);
	inline e2_t operator-=(e2_t& arg1, const mv& arg2);
	inline ni_t operator-=(ni_t& arg1, const mv& arg2);
	inline flatPoint operator-=(flatPoint& arg1, const mv& arg2);
	inline normalizedFlatPoint operator-=(normalizedFlatPoint& arg1, const mv& arg2);
	inline pointPair operator-=(pointPair& arg1, const mv& arg2);
	inline TRversorLog operator-=(TRversorLog& arg1, const mv& arg2);
	inline line operator-=(line& arg1, const mv& arg2);
	inline dualLine operator-=(dualLine& arg1, const mv& arg2);
	inline circle operator-=(circle& arg1, const mv& arg2);
	inline freeVector operator-=(freeVector& arg1, const mv& arg2);
	inline freeBivector operator-=(freeBivector& arg1, const mv& arg2);
	inline tangentVector operator-=(tangentVector& arg1, const mv& arg2);
	inline tangentBivector operator-=(tangentBivector& arg1, const mv& arg2);
	inline bivectorE2GA operator-=(bivectorE2GA& arg1, const mv& arg2);
	inline TRSversor operator-=(TRSversor& arg1, const mv& arg2);
	inline evenVersor operator-=(evenVersor& arg1, const mv& arg2);
	inline translator operator-=(translator& arg1, const mv& arg2);
	inline normalizedTranslator operator-=(normalizedTranslator& arg1, const mv& arg2);
	inline rotor operator-=(rotor& arg1, const mv& arg2);
	inline scalor operator-=(scalor& arg1, const mv& arg2);
	inline __no_ct__ operator-=(__no_ct__& arg1, const mv& arg2);
	inline __e1_ct__ operator-=(__e1_ct__& arg1, const mv& arg2);
	inline __e2_ct__ operator-=(__e2_ct__& arg1, const mv& arg2);
	inline __ni_ct__ operator-=(__ni_ct__& arg1, const mv& arg2);
	inline __I4i_ct__ operator-=(__I4i_ct__& arg1, const mv& arg2);
	inline __I4_ct__ operator-=(__I4_ct__& arg1, const mv& arg2);
	inline __I2_ct__ operator-=(__I2_ct__& arg1, const mv& arg2);
	inline __noni_ct__ operator-=(__noni_ct__& arg1, const mv& arg2);
	inline __e2ni_ct__ operator-=(__e2ni_ct__& arg1, const mv& arg2);
	inline __e1ni_ct__ operator-=(__e1ni_ct__& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_nof1_0 operator-=(__syn_smv___e1_e2_nof1_0& arg1, const mv& arg2);
	inline __syn_smv___e1e2nif1_0 operator-=(__syn_smv___e1e2nif1_0& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_ni_nof_1_0 operator-=(__syn_smv___e1_e2_ni_nof_1_0& arg1, const mv& arg2);
	inline __syn_smv___scalar_noe1_noe2_noni operator-=(__syn_smv___scalar_noe1_noe2_noni& arg1, const mv& arg2);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni operator-=(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni& arg1, const mv& arg2);
	inline __syn_smv___scalar_noe1_e1e2_e1ni operator-=(__syn_smv___scalar_noe1_e1e2_e1ni& arg1, const mv& arg2);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni operator-=(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni& arg1, const mv& arg2);
	inline __syn_smv___scalar_noe2_e1e2_e2ni operator-=(__syn_smv___scalar_noe2_e1e2_e2ni& arg1, const mv& arg2);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni operator-=(__syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni& arg1, const mv& arg2);
	inline __syn_smv___scalar_noni_e1ni_e2ni operator-=(__syn_smv___scalar_noni_e1ni_e2ni& arg1, const mv& arg2);
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni operator-=(__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni& arg1, const mv& arg2);
	inline __syn_smv___e1ni_e2ni_nonif_1_0 operator-=(__syn_smv___e1ni_e2ni_nonif_1_0& arg1, const mv& arg2);
	inline __syn_smv___scalarf_1_0 operator-=(__syn_smv___scalarf_1_0& arg1, const mv& arg2);
	inline __syn_smv___nif_1_0 operator-=(__syn_smv___nif_1_0& arg1, const mv& arg2);
	inline __syn_smv___nif1_0 operator-=(__syn_smv___nif1_0& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 operator-=(__syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_ni_nof2_0 operator-=(__syn_smv___e1_e2_ni_nof2_0& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_ni operator-=(__syn_smv___e1_e2_ni& arg1, const mv& arg2);
	inline __syn_smv___noe1_noe2_noni operator-=(__syn_smv___noe1_noe2_noni& arg1, const mv& arg2);
	inline __syn_smv___no_noe1e2_noe1ni_noe2ni operator-=(__syn_smv___no_noe1e2_noe1ni_noe2ni& arg1, const mv& arg2);
	inline __syn_smv___scalar_e1e2_e1ni operator-=(__syn_smv___scalar_e1e2_e1ni& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_ni_e1e2ni operator-=(__syn_smv___e1_e2_ni_e1e2ni& arg1, const mv& arg2);
	inline __syn_smv___scalar_e1e2_e2ni operator-=(__syn_smv___scalar_e1e2_e2ni& arg1, const mv& arg2);
	inline __syn_smv___scalarf0_0 operator-=(__syn_smv___scalarf0_0& arg1, const mv& arg2);
	inline __syn_smv___ni_e1e2ni operator-=(__syn_smv___ni_e1e2ni& arg1, const mv& arg2);
	inline mv operator-(const mv& arg1, const mv& arg2);
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni operator-(const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& arg1, const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& arg2);
	inline __syn_smv___e1_e2_ni operator-(const normalizedPoint& arg1, const normalizedPoint& arg2);
	inline point operator-(const point& arg1, const normalizedPoint& arg2);
	inline vectorE2GA operator-(const vectorE2GA& arg1, const vectorE2GA& arg2);
	inline vectorE2GA operator-(const e1_t& arg1, const e2_t& arg2);
	inline TRversor operator-(const TRversor& arg1, const TRversor& arg2);
	inline translator operator-(const scalar& arg1, const freeVector& arg2);
	inline translator operator-(float arg1, const freeVector& arg2);
	inline mv operator-(const mv& arg1);
	inline vectorE2GA operator-(const vectorE2GA& arg1);
	inline ni_t operator-(const ni_t& arg1);
	inline scalar operator-(const scalar& arg1);
	inline freeVector operator-(const freeVector& arg1);
	inline circle operator-(const circle& arg1);
	inline __syn_smv___nif1_0 operator-(const __syn_smv___nif_1_0& arg1);
	inline freeBivector operator-(const freeBivector& arg1);
	inline mv operator%=(mv& arg1, const mv& arg2);
	inline normalizedPoint operator%=(normalizedPoint& arg1, const normalizedPoint& arg2);
	inline __ni_ct__ operator%=(__ni_ct__& arg1, const point& arg2);
	inline point operator%=(point& arg1, const point& arg2);
	inline __ni_ct__ operator%=(__ni_ct__& arg1, const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni& arg2);
	inline __syn_smv___e1_e2_ni operator%=(__syn_smv___e1_e2_ni& arg1, const __syn_smv___e1_e2_ni& arg2);
	inline TRversorLog operator%=(TRversorLog& arg1, const TRversorLog& arg2);
	inline no_t operator%=(no_t& arg1, const mv& arg2);
	inline e1_t operator%=(e1_t& arg1, const mv& arg2);
	inline e2_t operator%=(e2_t& arg1, const mv& arg2);
	inline ni_t operator%=(ni_t& arg1, const mv& arg2);
	inline scalar operator%=(scalar& arg1, const mv& arg2);
	inline flatPoint operator%=(flatPoint& arg1, const mv& arg2);
	inline normalizedFlatPoint operator%=(normalizedFlatPoint& arg1, const mv& arg2);
	inline pointPair operator%=(pointPair& arg1, const mv& arg2);
	inline line operator%=(line& arg1, const mv& arg2);
	inline dualLine operator%=(dualLine& arg1, const mv& arg2);
	inline circle operator%=(circle& arg1, const mv& arg2);
	inline freeVector operator%=(freeVector& arg1, const mv& arg2);
	inline freeBivector operator%=(freeBivector& arg1, const mv& arg2);
	inline tangentVector operator%=(tangentVector& arg1, const mv& arg2);
	inline tangentBivector operator%=(tangentBivector& arg1, const mv& arg2);
	inline vectorE2GA operator%=(vectorE2GA& arg1, const mv& arg2);
	inline bivectorE2GA operator%=(bivectorE2GA& arg1, const mv& arg2);
	inline TRversor operator%=(TRversor& arg1, const mv& arg2);
	inline TRSversor operator%=(TRSversor& arg1, const mv& arg2);
	inline evenVersor operator%=(evenVersor& arg1, const mv& arg2);
	inline translator operator%=(translator& arg1, const mv& arg2);
	inline normalizedTranslator operator%=(normalizedTranslator& arg1, const mv& arg2);
	inline rotor operator%=(rotor& arg1, const mv& arg2);
	inline scalor operator%=(scalor& arg1, const mv& arg2);
	inline __no_ct__ operator%=(__no_ct__& arg1, const mv& arg2);
	inline __e1_ct__ operator%=(__e1_ct__& arg1, const mv& arg2);
	inline __e2_ct__ operator%=(__e2_ct__& arg1, const mv& arg2);
	inline __I4i_ct__ operator%=(__I4i_ct__& arg1, const mv& arg2);
	inline __I4_ct__ operator%=(__I4_ct__& arg1, const mv& arg2);
	inline __I2_ct__ operator%=(__I2_ct__& arg1, const mv& arg2);
	inline __noni_ct__ operator%=(__noni_ct__& arg1, const mv& arg2);
	inline __e2ni_ct__ operator%=(__e2ni_ct__& arg1, const mv& arg2);
	inline __e1ni_ct__ operator%=(__e1ni_ct__& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_nof1_0 operator%=(__syn_smv___e1_e2_nof1_0& arg1, const mv& arg2);
	inline __syn_smv___e1e2nif1_0 operator%=(__syn_smv___e1e2nif1_0& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_ni_nof_1_0 operator%=(__syn_smv___e1_e2_ni_nof_1_0& arg1, const mv& arg2);
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni operator%=(__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& arg1, const mv& arg2);
	inline __syn_smv___scalar_noe1_noe2_noni operator%=(__syn_smv___scalar_noe1_noe2_noni& arg1, const mv& arg2);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni operator%=(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni& arg1, const mv& arg2);
	inline __syn_smv___scalar_noe1_e1e2_e1ni operator%=(__syn_smv___scalar_noe1_e1e2_e1ni& arg1, const mv& arg2);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni operator%=(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni& arg1, const mv& arg2);
	inline __syn_smv___scalar_noe2_e1e2_e2ni operator%=(__syn_smv___scalar_noe2_e1e2_e2ni& arg1, const mv& arg2);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni operator%=(__syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni& arg1, const mv& arg2);
	inline __syn_smv___scalar_noni_e1ni_e2ni operator%=(__syn_smv___scalar_noni_e1ni_e2ni& arg1, const mv& arg2);
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni operator%=(__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni& arg1, const mv& arg2);
	inline __syn_smv___e1ni_e2ni_nonif_1_0 operator%=(__syn_smv___e1ni_e2ni_nonif_1_0& arg1, const mv& arg2);
	inline __syn_smv___scalarf_1_0 operator%=(__syn_smv___scalarf_1_0& arg1, const mv& arg2);
	inline __syn_smv___nif_1_0 operator%=(__syn_smv___nif_1_0& arg1, const mv& arg2);
	inline __syn_smv___nif1_0 operator%=(__syn_smv___nif1_0& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 operator%=(__syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_ni_nof2_0 operator%=(__syn_smv___e1_e2_ni_nof2_0& arg1, const mv& arg2);
	inline __syn_smv___noe1_noe2_noni operator%=(__syn_smv___noe1_noe2_noni& arg1, const mv& arg2);
	inline __syn_smv___no_noe1e2_noe1ni_noe2ni operator%=(__syn_smv___no_noe1e2_noe1ni_noe2ni& arg1, const mv& arg2);
	inline __syn_smv___scalar_e1e2_e1ni operator%=(__syn_smv___scalar_e1e2_e1ni& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_ni_e1e2ni operator%=(__syn_smv___e1_e2_ni_e1e2ni& arg1, const mv& arg2);
	inline __syn_smv___scalar_e1e2_e2ni operator%=(__syn_smv___scalar_e1e2_e2ni& arg1, const mv& arg2);
	inline __syn_smv___scalarf0_0 operator%=(__syn_smv___scalarf0_0& arg1, const mv& arg2);
	inline __syn_smv___ni_e1e2ni operator%=(__syn_smv___ni_e1e2ni& arg1, const mv& arg2);
	inline scalar operator%(const mv& arg1, const mv& arg2);
	inline scalar operator%(const normalizedPoint& arg1, const normalizedPoint& arg2);
	inline scalar operator%(const __ni_ct__& arg1, const point& arg2);
	inline scalar operator%(const point& arg1, const point& arg2);
	inline scalar operator%(const __ni_ct__& arg1, const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni& arg2);
	inline scalar operator%(const __syn_smv___e1_e2_ni& arg1, const __syn_smv___e1_e2_ni& arg2);
	inline scalar operator%(const TRversorLog& arg1, const TRversorLog& arg2);
	inline mv operator^=(mv& arg1, const mv& arg2);
	inline scalar operator^=(scalar& arg1, const __ni_ct__& arg2);
	inline __ni_ct__ operator^=(__ni_ct__& arg1, const point& arg2);
	inline __syn_smv___scalarf_1_0 operator^=(__syn_smv___scalarf_1_0& arg1, const __ni_ct__& arg2);
	inline __e1_ct__ operator^=(__e1_ct__& arg1, const __e2_ct__& arg2);
	inline __I2_ct__ operator^=(__I2_ct__& arg1, const __ni_ct__& arg2);
	inline TRversorLog operator^=(TRversorLog& arg1, const __ni_ct__& arg2);
	inline vectorE2GA operator^=(vectorE2GA& arg1, const __ni_ct__& arg2);
	inline pointPair operator^=(pointPair& arg1, const normalizedPoint& arg2);
	inline __ni_ct__ operator^=(__ni_ct__& arg1, const normalizedPoint& arg2);
	inline __ni_ct__ operator^=(__ni_ct__& arg1, const __syn_smv___e1_e2_ni& arg2);
	inline pointPair operator^=(pointPair& arg1, const __ni_ct__& arg2);
	inline normalizedPoint operator^=(normalizedPoint& arg1, const normalizedPoint& arg2);
	inline no_t operator^=(no_t& arg1, const mv& arg2);
	inline e1_t operator^=(e1_t& arg1, const mv& arg2);
	inline e2_t operator^=(e2_t& arg1, const mv& arg2);
	inline ni_t operator^=(ni_t& arg1, const mv& arg2);
	inline point operator^=(point& arg1, const mv& arg2);
	inline flatPoint operator^=(flatPoint& arg1, const mv& arg2);
	inline normalizedFlatPoint operator^=(normalizedFlatPoint& arg1, const mv& arg2);
	inline line operator^=(line& arg1, const mv& arg2);
	inline dualLine operator^=(dualLine& arg1, const mv& arg2);
	inline circle operator^=(circle& arg1, const mv& arg2);
	inline freeVector operator^=(freeVector& arg1, const mv& arg2);
	inline freeBivector operator^=(freeBivector& arg1, const mv& arg2);
	inline tangentVector operator^=(tangentVector& arg1, const mv& arg2);
	inline tangentBivector operator^=(tangentBivector& arg1, const mv& arg2);
	inline bivectorE2GA operator^=(bivectorE2GA& arg1, const mv& arg2);
	inline TRversor operator^=(TRversor& arg1, const mv& arg2);
	inline TRSversor operator^=(TRSversor& arg1, const mv& arg2);
	inline evenVersor operator^=(evenVersor& arg1, const mv& arg2);
	inline translator operator^=(translator& arg1, const mv& arg2);
	inline normalizedTranslator operator^=(normalizedTranslator& arg1, const mv& arg2);
	inline rotor operator^=(rotor& arg1, const mv& arg2);
	inline scalor operator^=(scalor& arg1, const mv& arg2);
	inline __no_ct__ operator^=(__no_ct__& arg1, const mv& arg2);
	inline __e2_ct__ operator^=(__e2_ct__& arg1, const mv& arg2);
	inline __I4i_ct__ operator^=(__I4i_ct__& arg1, const mv& arg2);
	inline __I4_ct__ operator^=(__I4_ct__& arg1, const mv& arg2);
	inline __noni_ct__ operator^=(__noni_ct__& arg1, const mv& arg2);
	inline __e2ni_ct__ operator^=(__e2ni_ct__& arg1, const mv& arg2);
	inline __e1ni_ct__ operator^=(__e1ni_ct__& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_nof1_0 operator^=(__syn_smv___e1_e2_nof1_0& arg1, const mv& arg2);
	inline __syn_smv___e1e2nif1_0 operator^=(__syn_smv___e1e2nif1_0& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_ni_nof_1_0 operator^=(__syn_smv___e1_e2_ni_nof_1_0& arg1, const mv& arg2);
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni operator^=(__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& arg1, const mv& arg2);
	inline __syn_smv___scalar_noe1_noe2_noni operator^=(__syn_smv___scalar_noe1_noe2_noni& arg1, const mv& arg2);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni operator^=(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni& arg1, const mv& arg2);
	inline __syn_smv___scalar_noe1_e1e2_e1ni operator^=(__syn_smv___scalar_noe1_e1e2_e1ni& arg1, const mv& arg2);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni operator^=(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni& arg1, const mv& arg2);
	inline __syn_smv___scalar_noe2_e1e2_e2ni operator^=(__syn_smv___scalar_noe2_e1e2_e2ni& arg1, const mv& arg2);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni operator^=(__syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni& arg1, const mv& arg2);
	inline __syn_smv___scalar_noni_e1ni_e2ni operator^=(__syn_smv___scalar_noni_e1ni_e2ni& arg1, const mv& arg2);
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni operator^=(__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni& arg1, const mv& arg2);
	inline __syn_smv___e1ni_e2ni_nonif_1_0 operator^=(__syn_smv___e1ni_e2ni_nonif_1_0& arg1, const mv& arg2);
	inline __syn_smv___nif_1_0 operator^=(__syn_smv___nif_1_0& arg1, const mv& arg2);
	inline __syn_smv___nif1_0 operator^=(__syn_smv___nif1_0& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 operator^=(__syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_ni_nof2_0 operator^=(__syn_smv___e1_e2_ni_nof2_0& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_ni operator^=(__syn_smv___e1_e2_ni& arg1, const mv& arg2);
	inline __syn_smv___noe1_noe2_noni operator^=(__syn_smv___noe1_noe2_noni& arg1, const mv& arg2);
	inline __syn_smv___no_noe1e2_noe1ni_noe2ni operator^=(__syn_smv___no_noe1e2_noe1ni_noe2ni& arg1, const mv& arg2);
	inline __syn_smv___scalar_e1e2_e1ni operator^=(__syn_smv___scalar_e1e2_e1ni& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_ni_e1e2ni operator^=(__syn_smv___e1_e2_ni_e1e2ni& arg1, const mv& arg2);
	inline __syn_smv___scalar_e1e2_e2ni operator^=(__syn_smv___scalar_e1e2_e2ni& arg1, const mv& arg2);
	inline __syn_smv___scalarf0_0 operator^=(__syn_smv___scalarf0_0& arg1, const mv& arg2);
	inline __syn_smv___ni_e1e2ni operator^=(__syn_smv___ni_e1e2ni& arg1, const mv& arg2);
	inline mv operator^(const mv& arg1, const mv& arg2);
	inline ni_t operator^(const scalar& arg1, const __ni_ct__& arg2);
	inline ni_t operator^(float arg1, const __ni_ct__& arg2);
	inline flatPoint operator^(const __ni_ct__& arg1, const point& arg2);
	inline __syn_smv___nif_1_0 operator^(const __syn_smv___scalarf_1_0& arg1, const __ni_ct__& arg2);
	inline __I2_ct__ operator^(const __e1_ct__& arg1, const __e2_ct__& arg2);
	inline __syn_smv___e1e2nif1_0 operator^(const __I2_ct__& arg1, const __ni_ct__& arg2);
	inline freeBivector operator^(const TRversorLog& arg1, const __ni_ct__& arg2);
	inline freeVector operator^(const vectorE2GA& arg1, const __ni_ct__& arg2);
	inline circle operator^(const pointPair& arg1, const normalizedPoint& arg2);
	inline __syn_smv___e1ni_e2ni_nonif_1_0 operator^(const __ni_ct__& arg1, const normalizedPoint& arg2);
	inline freeVector operator^(const __ni_ct__& arg1, const __syn_smv___e1_e2_ni& arg2);
	inline line operator^(const pointPair& arg1, const __ni_ct__& arg2);
	inline pointPair operator^(const normalizedPoint& arg1, const normalizedPoint& arg2);
	inline mv operator*=(mv& arg1, const mv& arg2);
	inline freeVector operator*=(freeVector& arg1, const __syn_smv___e1_e2_ni& arg2);
	inline circle operator*=(circle& arg1, const TRversorLog& arg2);
	inline scalar operator*=(scalar& arg1, const scalar& arg2);
	inline scalar operator*=(scalar& arg1, float arg2);
	inline __syn_smv___scalar_noe1_noe2_noni operator*=(__syn_smv___scalar_noe1_noe2_noni& arg1, const point& arg2);
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni operator*=(__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni& arg1, const scalar& arg2);
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni operator*=(__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni& arg1, float arg2);
	inline __syn_smv___scalar_e1e2_e1ni operator*=(__syn_smv___scalar_e1e2_e1ni& arg1, const __syn_smv___e1_e2_ni& arg2);
	inline __syn_smv___scalar_noe1_e1e2_e1ni operator*=(__syn_smv___scalar_noe1_e1e2_e1ni& arg1, const point& arg2);
	inline point operator*=(point& arg1, const point& arg2);
	inline scalar operator*=(scalar& arg1, const normalizedPoint& arg2);
	inline __syn_smv___e1_e2_ni operator*=(__syn_smv___e1_e2_ni& arg1, const __e2_ct__& arg2);
	inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 operator*=(__syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0& arg1, const translator& arg2);
	inline scalar operator*=(scalar& arg1, const vectorE2GA& arg2);
	inline point operator*=(point& arg1, const scalar& arg2);
	inline point operator*=(point& arg1, float arg2);
	inline point operator*=(point& arg1, const __e2_ct__& arg2);
	inline normalizedTranslator operator*=(normalizedTranslator& arg1, const normalizedPoint& arg2);
	inline point operator*=(point& arg1, const __no_ct__& arg2);
	inline circle operator*=(circle& arg1, const circle& arg2);
	inline scalar operator*=(scalar& arg1, const __ni_ct__& arg2);
	inline __syn_smv___scalar_noe2_e1e2_e2ni operator*=(__syn_smv___scalar_noe2_e1e2_e2ni& arg1, const point& arg2);
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni operator*=(__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& arg1, const scalar& arg2);
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni operator*=(__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& arg1, float arg2);
	inline normalizedPoint operator*=(normalizedPoint& arg1, const scalar& arg2);
	inline normalizedPoint operator*=(normalizedPoint& arg1, float arg2);
	inline point operator*=(point& arg1, const __ni_ct__& arg2);
	inline __syn_smv___scalar_noni_e1ni_e2ni operator*=(__syn_smv___scalar_noni_e1ni_e2ni& arg1, const point& arg2);
	inline __syn_smv___e1_e2_ni operator*=(__syn_smv___e1_e2_ni& arg1, const __syn_smv___e1_e2_ni& arg2);
	inline __syn_smv___e1_e2_ni operator*=(__syn_smv___e1_e2_ni& arg1, const __no_ct__& arg2);
	inline point operator*=(point& arg1, const __e1_ct__& arg2);
	inline scalar operator*=(scalar& arg1, const __e1_ct__& arg2);
	inline scalar operator*=(scalar& arg1, const __syn_smv___e1_e2_ni_nof2_0& arg2);
	inline __syn_smv___scalar_e1e2_e2ni operator*=(__syn_smv___scalar_e1e2_e2ni& arg1, const __syn_smv___e1_e2_ni& arg2);
	inline __syn_smv___e1_e2_ni operator*=(__syn_smv___e1_e2_ni& arg1, const __ni_ct__& arg2);
	inline __syn_smv___scalar_noe1_noe2_noni operator*=(__syn_smv___scalar_noe1_noe2_noni& arg1, const __syn_smv___e1_e2_ni& arg2);
	inline scalar operator*=(scalar& arg1, const __e2_ct__& arg2);
	inline __syn_smv___e1_e2_ni operator*=(__syn_smv___e1_e2_ni& arg1, const __e1_ct__& arg2);
	inline no_t operator*=(no_t& arg1, const mv& arg2);
	inline e1_t operator*=(e1_t& arg1, const mv& arg2);
	inline e2_t operator*=(e2_t& arg1, const mv& arg2);
	inline ni_t operator*=(ni_t& arg1, const mv& arg2);
	inline flatPoint operator*=(flatPoint& arg1, const mv& arg2);
	inline normalizedFlatPoint operator*=(normalizedFlatPoint& arg1, const mv& arg2);
	inline pointPair operator*=(pointPair& arg1, const mv& arg2);
	inline TRversorLog operator*=(TRversorLog& arg1, const mv& arg2);
	inline line operator*=(line& arg1, const mv& arg2);
	inline dualLine operator*=(dualLine& arg1, const mv& arg2);
	inline freeBivector operator*=(freeBivector& arg1, const mv& arg2);
	inline tangentVector operator*=(tangentVector& arg1, const mv& arg2);
	inline tangentBivector operator*=(tangentBivector& arg1, const mv& arg2);
	inline vectorE2GA operator*=(vectorE2GA& arg1, const mv& arg2);
	inline bivectorE2GA operator*=(bivectorE2GA& arg1, const mv& arg2);
	inline TRversor operator*=(TRversor& arg1, const mv& arg2);
	inline TRSversor operator*=(TRSversor& arg1, const mv& arg2);
	inline evenVersor operator*=(evenVersor& arg1, const mv& arg2);
	inline translator operator*=(translator& arg1, const mv& arg2);
	inline rotor operator*=(rotor& arg1, const mv& arg2);
	inline scalor operator*=(scalor& arg1, const mv& arg2);
	inline __no_ct__ operator*=(__no_ct__& arg1, const mv& arg2);
	inline __e1_ct__ operator*=(__e1_ct__& arg1, const mv& arg2);
	inline __e2_ct__ operator*=(__e2_ct__& arg1, const mv& arg2);
	inline __ni_ct__ operator*=(__ni_ct__& arg1, const mv& arg2);
	inline __I4i_ct__ operator*=(__I4i_ct__& arg1, const mv& arg2);
	inline __I4_ct__ operator*=(__I4_ct__& arg1, const mv& arg2);
	inline __I2_ct__ operator*=(__I2_ct__& arg1, const mv& arg2);
	inline __noni_ct__ operator*=(__noni_ct__& arg1, const mv& arg2);
	inline __e2ni_ct__ operator*=(__e2ni_ct__& arg1, const mv& arg2);
	inline __e1ni_ct__ operator*=(__e1ni_ct__& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_nof1_0 operator*=(__syn_smv___e1_e2_nof1_0& arg1, const mv& arg2);
	inline __syn_smv___e1e2nif1_0 operator*=(__syn_smv___e1e2nif1_0& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_ni_nof_1_0 operator*=(__syn_smv___e1_e2_ni_nof_1_0& arg1, const mv& arg2);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni operator*=(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni& arg1, const mv& arg2);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni operator*=(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni& arg1, const mv& arg2);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni operator*=(__syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni& arg1, const mv& arg2);
	inline __syn_smv___e1ni_e2ni_nonif_1_0 operator*=(__syn_smv___e1ni_e2ni_nonif_1_0& arg1, const mv& arg2);
	inline __syn_smv___scalarf_1_0 operator*=(__syn_smv___scalarf_1_0& arg1, const mv& arg2);
	inline __syn_smv___nif_1_0 operator*=(__syn_smv___nif_1_0& arg1, const mv& arg2);
	inline __syn_smv___nif1_0 operator*=(__syn_smv___nif1_0& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_ni_nof2_0 operator*=(__syn_smv___e1_e2_ni_nof2_0& arg1, const mv& arg2);
	inline __syn_smv___noe1_noe2_noni operator*=(__syn_smv___noe1_noe2_noni& arg1, const mv& arg2);
	inline __syn_smv___no_noe1e2_noe1ni_noe2ni operator*=(__syn_smv___no_noe1e2_noe1ni_noe2ni& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_ni_e1e2ni operator*=(__syn_smv___e1_e2_ni_e1e2ni& arg1, const mv& arg2);
	inline __syn_smv___scalarf0_0 operator*=(__syn_smv___scalarf0_0& arg1, const mv& arg2);
	inline __syn_smv___ni_e1e2ni operator*=(__syn_smv___ni_e1e2ni& arg1, const mv& arg2);
	inline mv operator*(const mv& arg1, const mv& arg2);
	inline __syn_smv___ni_e1e2ni operator*(const freeVector& arg1, const __syn_smv___e1_e2_ni& arg2);
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni operator*(const circle& arg1, const TRversorLog& arg2);
	inline scalar operator*(const scalar& arg1, const scalar& arg2);
	inline scalar operator*(float arg1, const scalar& arg2);
	inline scalar operator*(const scalar& arg1, float arg2);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni operator*(const __syn_smv___scalar_noe1_noe2_noni& arg1, const point& arg2);
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni operator*(const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni& arg1, const scalar& arg2);
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni operator*(const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni& arg1, float arg2);
	inline __syn_smv___e1_e2_ni_e1e2ni operator*(const __syn_smv___scalar_e1e2_e1ni& arg1, const __syn_smv___e1_e2_ni& arg2);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni operator*(const __syn_smv___scalar_noe1_e1e2_e1ni& arg1, const point& arg2);
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni operator*(const point& arg1, const point& arg2);
	inline point operator*(const scalar& arg1, const normalizedPoint& arg2);
	inline point operator*(float arg1, const normalizedPoint& arg2);
	inline __syn_smv___scalar_e1e2_e2ni operator*(const __syn_smv___e1_e2_ni& arg1, const __e2_ct__& arg2);
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni operator*(const __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0& arg1, const translator& arg2);
	inline vectorE2GA operator*(const scalar& arg1, const vectorE2GA& arg2);
	inline vectorE2GA operator*(float arg1, const vectorE2GA& arg2);
	inline point operator*(const point& arg1, const scalar& arg2);
	inline point operator*(const point& arg1, float arg2);
	inline __syn_smv___scalar_noe2_e1e2_e2ni operator*(const point& arg1, const __e2_ct__& arg2);
	inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 operator*(const normalizedTranslator& arg1, const normalizedPoint& arg2);
	inline __syn_smv___scalar_noe1_noe2_noni operator*(const point& arg1, const __no_ct__& arg2);
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni operator*(const circle& arg1, const circle& arg2);
	inline ni_t operator*(const scalar& arg1, const __ni_ct__& arg2);
	inline ni_t operator*(float arg1, const __ni_ct__& arg2);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni operator*(const __syn_smv___scalar_noe2_e1e2_e2ni& arg1, const point& arg2);
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni operator*(const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& arg1, const scalar& arg2);
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni operator*(const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& arg1, float arg2);
	inline point operator*(const normalizedPoint& arg1, const scalar& arg2);
	inline point operator*(const normalizedPoint& arg1, float arg2);
	inline __syn_smv___scalar_noni_e1ni_e2ni operator*(const point& arg1, const __ni_ct__& arg2);
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni operator*(const __syn_smv___scalar_noni_e1ni_e2ni& arg1, const point& arg2);
	inline TRversor operator*(const __syn_smv___e1_e2_ni& arg1, const __syn_smv___e1_e2_ni& arg2);
	inline __syn_smv___scalar_noe1_noe2_noni operator*(const __syn_smv___e1_e2_ni& arg1, const __no_ct__& arg2);
	inline __syn_smv___scalar_noe1_e1e2_e1ni operator*(const point& arg1, const __e1_ct__& arg2);
	inline e1_t operator*(const scalar& arg1, const __e1_ct__& arg2);
	inline e1_t operator*(float arg1, const __e1_ct__& arg2);
	inline point operator*(const scalar& arg1, const __syn_smv___e1_e2_ni_nof2_0& arg2);
	inline point operator*(float arg1, const __syn_smv___e1_e2_ni_nof2_0& arg2);
	inline __syn_smv___e1_e2_ni_e1e2ni operator*(const __syn_smv___scalar_e1e2_e2ni& arg1, const __syn_smv___e1_e2_ni& arg2);
	inline freeVector operator*(const __syn_smv___e1_e2_ni& arg1, const __ni_ct__& arg2);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni operator*(const __syn_smv___scalar_noe1_noe2_noni& arg1, const __syn_smv___e1_e2_ni& arg2);
	inline e2_t operator*(const scalar& arg1, const __e2_ct__& arg2);
	inline e2_t operator*(float arg1, const __e2_ct__& arg2);
	inline __syn_smv___scalar_e1e2_e1ni operator*(const __syn_smv___e1_e2_ni& arg1, const __e1_ct__& arg2);
	inline mv operator<<=(mv& arg1, const mv& arg2);
	inline __no_ct__ operator<<=(__no_ct__& arg1, const freeVector& arg2);
	inline __syn_smv___e1_e2_ni operator<<=(__syn_smv___e1_e2_ni& arg1, const normalizedPoint& arg2);
	inline __ni_ct__ operator<<=(__ni_ct__& arg1, const line& arg2);
	inline circle operator<<=(circle& arg1, const __syn_smv___e1e2nif1_0& arg2);
	inline __ni_ct__ operator<<=(__ni_ct__& arg1, const normalizedPoint& arg2);
	inline __ni_ct__ operator<<=(__ni_ct__& arg1, const point& arg2);
	inline pointPair operator<<=(pointPair& arg1, const line& arg2);
	inline __ni_ct__ operator<<=(__ni_ct__& arg1, const circle& arg2);
	inline __ni_ct__ operator<<=(__ni_ct__& arg1, const __syn_smv___e1_e2_ni& arg2);
	inline normalizedPoint operator<<=(normalizedPoint& arg1, const line& arg2);
	inline __no_ct__ operator<<=(__no_ct__& arg1, const freeBivector& arg2);
	inline no_t operator<<=(no_t& arg1, const mv& arg2);
	inline e1_t operator<<=(e1_t& arg1, const mv& arg2);
	inline e2_t operator<<=(e2_t& arg1, const mv& arg2);
	inline ni_t operator<<=(ni_t& arg1, const mv& arg2);
	inline scalar operator<<=(scalar& arg1, const mv& arg2);
	inline point operator<<=(point& arg1, const mv& arg2);
	inline flatPoint operator<<=(flatPoint& arg1, const mv& arg2);
	inline normalizedFlatPoint operator<<=(normalizedFlatPoint& arg1, const mv& arg2);
	inline TRversorLog operator<<=(TRversorLog& arg1, const mv& arg2);
	inline line operator<<=(line& arg1, const mv& arg2);
	inline dualLine operator<<=(dualLine& arg1, const mv& arg2);
	inline freeVector operator<<=(freeVector& arg1, const mv& arg2);
	inline freeBivector operator<<=(freeBivector& arg1, const mv& arg2);
	inline tangentVector operator<<=(tangentVector& arg1, const mv& arg2);
	inline tangentBivector operator<<=(tangentBivector& arg1, const mv& arg2);
	inline vectorE2GA operator<<=(vectorE2GA& arg1, const mv& arg2);
	inline bivectorE2GA operator<<=(bivectorE2GA& arg1, const mv& arg2);
	inline TRversor operator<<=(TRversor& arg1, const mv& arg2);
	inline TRSversor operator<<=(TRSversor& arg1, const mv& arg2);
	inline evenVersor operator<<=(evenVersor& arg1, const mv& arg2);
	inline translator operator<<=(translator& arg1, const mv& arg2);
	inline normalizedTranslator operator<<=(normalizedTranslator& arg1, const mv& arg2);
	inline rotor operator<<=(rotor& arg1, const mv& arg2);
	inline scalor operator<<=(scalor& arg1, const mv& arg2);
	inline __e1_ct__ operator<<=(__e1_ct__& arg1, const mv& arg2);
	inline __e2_ct__ operator<<=(__e2_ct__& arg1, const mv& arg2);
	inline __I4i_ct__ operator<<=(__I4i_ct__& arg1, const mv& arg2);
	inline __I4_ct__ operator<<=(__I4_ct__& arg1, const mv& arg2);
	inline __I2_ct__ operator<<=(__I2_ct__& arg1, const mv& arg2);
	inline __noni_ct__ operator<<=(__noni_ct__& arg1, const mv& arg2);
	inline __e2ni_ct__ operator<<=(__e2ni_ct__& arg1, const mv& arg2);
	inline __e1ni_ct__ operator<<=(__e1ni_ct__& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_nof1_0 operator<<=(__syn_smv___e1_e2_nof1_0& arg1, const mv& arg2);
	inline __syn_smv___e1e2nif1_0 operator<<=(__syn_smv___e1e2nif1_0& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_ni_nof_1_0 operator<<=(__syn_smv___e1_e2_ni_nof_1_0& arg1, const mv& arg2);
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni operator<<=(__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& arg1, const mv& arg2);
	inline __syn_smv___scalar_noe1_noe2_noni operator<<=(__syn_smv___scalar_noe1_noe2_noni& arg1, const mv& arg2);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni operator<<=(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni& arg1, const mv& arg2);
	inline __syn_smv___scalar_noe1_e1e2_e1ni operator<<=(__syn_smv___scalar_noe1_e1e2_e1ni& arg1, const mv& arg2);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni operator<<=(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni& arg1, const mv& arg2);
	inline __syn_smv___scalar_noe2_e1e2_e2ni operator<<=(__syn_smv___scalar_noe2_e1e2_e2ni& arg1, const mv& arg2);
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni operator<<=(__syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni& arg1, const mv& arg2);
	inline __syn_smv___scalar_noni_e1ni_e2ni operator<<=(__syn_smv___scalar_noni_e1ni_e2ni& arg1, const mv& arg2);
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni operator<<=(__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni& arg1, const mv& arg2);
	inline __syn_smv___e1ni_e2ni_nonif_1_0 operator<<=(__syn_smv___e1ni_e2ni_nonif_1_0& arg1, const mv& arg2);
	inline __syn_smv___scalarf_1_0 operator<<=(__syn_smv___scalarf_1_0& arg1, const mv& arg2);
	inline __syn_smv___nif_1_0 operator<<=(__syn_smv___nif_1_0& arg1, const mv& arg2);
	inline __syn_smv___nif1_0 operator<<=(__syn_smv___nif1_0& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 operator<<=(__syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_ni_nof2_0 operator<<=(__syn_smv___e1_e2_ni_nof2_0& arg1, const mv& arg2);
	inline __syn_smv___noe1_noe2_noni operator<<=(__syn_smv___noe1_noe2_noni& arg1, const mv& arg2);
	inline __syn_smv___no_noe1e2_noe1ni_noe2ni operator<<=(__syn_smv___no_noe1e2_noe1ni_noe2ni& arg1, const mv& arg2);
	inline __syn_smv___scalar_e1e2_e1ni operator<<=(__syn_smv___scalar_e1e2_e1ni& arg1, const mv& arg2);
	inline __syn_smv___e1_e2_ni_e1e2ni operator<<=(__syn_smv___e1_e2_ni_e1e2ni& arg1, const mv& arg2);
	inline __syn_smv___scalar_e1e2_e2ni operator<<=(__syn_smv___scalar_e1e2_e2ni& arg1, const mv& arg2);
	inline __syn_smv___scalarf0_0 operator<<=(__syn_smv___scalarf0_0& arg1, const mv& arg2);
	inline __syn_smv___ni_e1e2ni operator<<=(__syn_smv___ni_e1e2ni& arg1, const mv& arg2);
	inline mv operator<<(const mv& arg1, const mv& arg2);
	inline vectorE2GA operator<<(const __no_ct__& arg1, const freeVector& arg2);
	inline scalar operator<<(const __syn_smv___e1_e2_ni& arg1, const normalizedPoint& arg2);
	inline freeVector operator<<(const __ni_ct__& arg1, const line& arg2);
	inline scalar operator<<(const circle& arg1, const __syn_smv___e1e2nif1_0& arg2);
	inline __syn_smv___scalarf_1_0 operator<<(const __ni_ct__& arg1, const normalizedPoint& arg2);
	inline scalar operator<<(const __ni_ct__& arg1, const point& arg2);
	inline point operator<<(const pointPair& arg1, const line& arg2);
	inline TRversorLog operator<<(const __ni_ct__& arg1, const circle& arg2);
	inline __syn_smv___scalarf0_0 operator<<(const __ni_ct__& arg1, const __syn_smv___e1_e2_ni& arg2);
	inline pointPair operator<<(const normalizedPoint& arg1, const line& arg2);
	inline bivectorE2GA operator<<(const __no_ct__& arg1, const freeBivector& arg2);
	inline mv operator*(const mv& arg1);
	inline circle operator*(const point& arg1);
	inline line operator*(const __syn_smv___e1_e2_ni& arg1);
	inline __syn_smv___e1_e2_ni operator*(const line& arg1);
	inline mv operator!(const mv& arg1);
	inline TRversorLog operator!(const TRversorLog& arg1);
	inline scalar operator!(const scalar& arg1);
	inline point operator!(const point& arg1);
	inline line operator!(const line& arg1);
	inline __syn_smv___e1_e2_ni operator!(const __syn_smv___e1_e2_ni& arg1);
	inline scalar operator!(const __syn_smv___scalarf_1_0& arg1);
	inline translator operator!(const normalizedTranslator& arg1);
	inline mv operator~(const mv& arg1);
	inline point operator~(const point& arg1);
	inline normalizedPoint operator~(const normalizedPoint& arg1);
	inline __syn_smv___e1_e2_ni operator~(const __syn_smv___e1_e2_ni& arg1);














	// set to zero
	inline void no_t::set() {
		// set coordinates to 0
		mv_zero(m_c, 1);

	}

	// set to scalar 
	inline void no_t::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;

	}


	// set to copy
	inline void no_t::set(const no_t &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 1);
		m_c[0] = arg1.m_c[0];

	}

	// set to pointer to coordinates
	inline void no_t::set(__no_t_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 1);
		m_c[0] = coordinates[0];

	}

	// set to 'coordinates specified' 
	inline void no_t::set(__no_t_coordinates__, Float c_no) {
		// set coordinates
		m_c[0] = c_no;

	}





	// assign copy
	inline no_t &no_t::operator=(const no_t &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline no_t &no_t::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline no_t &no_t::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void e1_t::set() {
		// set coordinates to 0
		mv_zero(m_c, 1);

	}

	// set to scalar 
	inline void e1_t::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;

	}


	// set to copy
	inline void e1_t::set(const e1_t &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 1);
		m_c[0] = arg1.m_c[0];

	}

	// set to pointer to coordinates
	inline void e1_t::set(__e1_t_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 1);
		m_c[0] = coordinates[0];

	}

	// set to 'coordinates specified' 
	inline void e1_t::set(__e1_t_coordinates__, Float c_e1) {
		// set coordinates
		m_c[0] = c_e1;

	}





	// assign copy
	inline e1_t &e1_t::operator=(const e1_t &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline e1_t &e1_t::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline e1_t &e1_t::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void e2_t::set() {
		// set coordinates to 0
		mv_zero(m_c, 1);

	}

	// set to scalar 
	inline void e2_t::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;

	}


	// set to copy
	inline void e2_t::set(const e2_t &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 1);
		m_c[0] = arg1.m_c[0];

	}

	// set to pointer to coordinates
	inline void e2_t::set(__e2_t_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 1);
		m_c[0] = coordinates[0];

	}

	// set to 'coordinates specified' 
	inline void e2_t::set(__e2_t_coordinates__, Float c_e2) {
		// set coordinates
		m_c[0] = c_e2;

	}





	// assign copy
	inline e2_t &e2_t::operator=(const e2_t &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline e2_t &e2_t::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline e2_t &e2_t::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void ni_t::set() {
		// set coordinates to 0
		mv_zero(m_c, 1);

	}

	// set to scalar 
	inline void ni_t::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;

	}


	// set to copy
	inline void ni_t::set(const ni_t &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 1);
		m_c[0] = arg1.m_c[0];

	}

	// set to pointer to coordinates
	inline void ni_t::set(__ni_t_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 1);
		m_c[0] = coordinates[0];

	}

	// set to 'coordinates specified' 
	inline void ni_t::set(__ni_t_coordinates__, Float c_ni) {
		// set coordinates
		m_c[0] = c_ni;

	}





	// assign copy
	inline ni_t &ni_t::operator=(const ni_t &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline ni_t &ni_t::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline ni_t &ni_t::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void scalar::set() {
		// set coordinates to 0
		mv_zero(m_c, 1);

	}

	// set to scalar 
	inline void scalar::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = s ;

	}


	// set to copy
	inline void scalar::set(const scalar &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 1);
		m_c[0] = arg1.m_c[0];

	}

	// set to pointer to coordinates
	inline void scalar::set(__scalar_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 1);
		m_c[0] = coordinates[0];

	}

	// set to 'coordinates specified' 
	inline void scalar::set(__scalar_coordinates__, Float c_scalar) {
		// set coordinates
		m_c[0] = c_scalar;

	}





	// assign copy
	inline scalar &scalar::operator=(const scalar &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline scalar &scalar::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline scalar &scalar::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void point::set() {
		// set coordinates to 0
		mv_zero(m_c, 4);

	}

	// set to scalar 
	inline void point::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;
		m_c[3] = (Float)0.0;

	}


	// set to copy
	inline void point::set(const point &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 4);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];
		m_c[3] = arg1.m_c[3];

	}

	// set to pointer to coordinates
	inline void point::set(__point_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 4);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];
		m_c[3] = coordinates[3];

	}

	// set to 'coordinates specified' 
	inline void point::set(__point_coordinates__, Float c_no, Float c_e1, Float c_e2, Float c_ni) {
		// set coordinates
		m_c[0] = c_no;
		m_c[1] = c_e1;
		m_c[2] = c_e2;
		m_c[3] = c_ni;

	}





	// assign copy
	inline point &point::operator=(const point &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline point &point::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline point &point::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void normalizedPoint::set() {
		// set coordinates to 0
		mv_zero(m_c, 3);

	}

	// set to scalar 
	inline void normalizedPoint::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;

	}


	// set to copy
	inline void normalizedPoint::set(const normalizedPoint &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 3);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];

	}

	// set to pointer to coordinates
	inline void normalizedPoint::set(__normalizedPoint_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 3);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];

	}

	// set to 'coordinates specified' 
	inline void normalizedPoint::set(__normalizedPoint_coordinates__, Float c_e1, Float c_e2, Float c_ni) {
		// set coordinates
		m_c[0] = c_e1;
		m_c[1] = c_e2;
		m_c[2] = c_ni;

	}





	// assign copy
	inline normalizedPoint &normalizedPoint::operator=(const normalizedPoint &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline normalizedPoint &normalizedPoint::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline normalizedPoint &normalizedPoint::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void flatPoint::set() {
		// set coordinates to 0
		mv_zero(m_c, 3);

	}

	// set to scalar 
	inline void flatPoint::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;

	}


	// set to copy
	inline void flatPoint::set(const flatPoint &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 3);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];

	}

	// set to pointer to coordinates
	inline void flatPoint::set(__flatPoint_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 3);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];

	}

	// set to 'coordinates specified' 
	inline void flatPoint::set(__flatPoint_coordinates__, Float c_e1ni, Float c_e2ni, Float c_noni) {
		// set coordinates
		m_c[0] = c_e1ni;
		m_c[1] = c_e2ni;
		m_c[2] = c_noni;

	}





	// assign copy
	inline flatPoint &flatPoint::operator=(const flatPoint &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline flatPoint &flatPoint::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline flatPoint &flatPoint::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void normalizedFlatPoint::set() {
		// set coordinates to 0
		mv_zero(m_c, 2);

	}

	// set to scalar 
	inline void normalizedFlatPoint::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;

	}


	// set to copy
	inline void normalizedFlatPoint::set(const normalizedFlatPoint &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 2);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];

	}

	// set to pointer to coordinates
	inline void normalizedFlatPoint::set(__normalizedFlatPoint_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 2);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];

	}

	// set to 'coordinates specified' 
	inline void normalizedFlatPoint::set(__normalizedFlatPoint_coordinates__, Float c_e1ni, Float c_e2ni) {
		// set coordinates
		m_c[0] = c_e1ni;
		m_c[1] = c_e2ni;

	}





	// assign copy
	inline normalizedFlatPoint &normalizedFlatPoint::operator=(const normalizedFlatPoint &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline normalizedFlatPoint &normalizedFlatPoint::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline normalizedFlatPoint &normalizedFlatPoint::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void pointPair::set() {
		// set coordinates to 0
		mv_zero(m_c, 6);

	}

	// set to scalar 
	inline void pointPair::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;
		m_c[3] = (Float)0.0;
		m_c[4] = (Float)0.0;
		m_c[5] = (Float)0.0;

	}


	// set to copy
	inline void pointPair::set(const pointPair &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 6);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];
		m_c[3] = arg1.m_c[3];
		m_c[4] = arg1.m_c[4];
		m_c[5] = arg1.m_c[5];

	}

	// set to pointer to coordinates
	inline void pointPair::set(__pointPair_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 6);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];
		m_c[3] = coordinates[3];
		m_c[4] = coordinates[4];
		m_c[5] = coordinates[5];

	}

	// set to 'coordinates specified' 
	inline void pointPair::set(__pointPair_coordinates__, Float c_noe1, Float c_noe2, Float c_e1e2, Float c_e1ni, Float c_e2ni, Float c_noni) {
		// set coordinates
		m_c[0] = c_noe1;
		m_c[1] = c_noe2;
		m_c[2] = c_e1e2;
		m_c[3] = c_e1ni;
		m_c[4] = c_e2ni;
		m_c[5] = c_noni;

	}





	// assign copy
	inline pointPair &pointPair::operator=(const pointPair &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline pointPair &pointPair::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline pointPair &pointPair::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void TRversorLog::set() {
		// set coordinates to 0
		mv_zero(m_c, 3);

	}

	// set to scalar 
	inline void TRversorLog::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;

	}


	// set to copy
	inline void TRversorLog::set(const TRversorLog &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 3);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];

	}

	// set to pointer to coordinates
	inline void TRversorLog::set(__TRversorLog_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 3);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];

	}

	// set to 'coordinates specified' 
	inline void TRversorLog::set(__TRversorLog_coordinates__, Float c_e1e2, Float c_e1ni, Float c_e2ni) {
		// set coordinates
		m_c[0] = c_e1e2;
		m_c[1] = c_e1ni;
		m_c[2] = c_e2ni;

	}





	// assign copy
	inline TRversorLog &TRversorLog::operator=(const TRversorLog &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline TRversorLog &TRversorLog::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline TRversorLog &TRversorLog::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void line::set() {
		// set coordinates to 0
		mv_zero(m_c, 3);

	}

	// set to scalar 
	inline void line::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;

	}


	// set to copy
	inline void line::set(const line &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 3);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];

	}

	// set to pointer to coordinates
	inline void line::set(__line_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 3);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];

	}

	// set to 'coordinates specified' 
	inline void line::set(__line_coordinates__, Float c_e1e2ni, Float c_e1noni, Float c_e2noni) {
		// set coordinates
		m_c[0] = c_e1e2ni;
		m_c[1] = c_e1noni;
		m_c[2] = c_e2noni;

	}





	// assign copy
	inline line &line::operator=(const line &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline line &line::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline line &line::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void dualLine::set() {
		// set coordinates to 0
		mv_zero(m_c, 3);

	}

	// set to scalar 
	inline void dualLine::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;

	}


	// set to copy
	inline void dualLine::set(const dualLine &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 3);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];

	}

	// set to pointer to coordinates
	inline void dualLine::set(__dualLine_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 3);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];

	}

	// set to 'coordinates specified' 
	inline void dualLine::set(__dualLine_coordinates__, Float c_e1e2, Float c_e1ni, Float c_e2ni) {
		// set coordinates
		m_c[0] = c_e1e2;
		m_c[1] = c_e1ni;
		m_c[2] = c_e2ni;

	}





	// assign copy
	inline dualLine &dualLine::operator=(const dualLine &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline dualLine &dualLine::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline dualLine &dualLine::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void circle::set() {
		// set coordinates to 0
		mv_zero(m_c, 4);

	}

	// set to scalar 
	inline void circle::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;
		m_c[3] = (Float)0.0;

	}


	// set to copy
	inline void circle::set(const circle &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 4);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];
		m_c[3] = arg1.m_c[3];

	}

	// set to pointer to coordinates
	inline void circle::set(__circle_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 4);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];
		m_c[3] = coordinates[3];

	}

	// set to 'coordinates specified' 
	inline void circle::set(__circle_coordinates__, Float c_e1e2ni, Float c_noe1ni, Float c_noe2ni, Float c_noe1e2) {
		// set coordinates
		m_c[0] = c_e1e2ni;
		m_c[1] = c_noe1ni;
		m_c[2] = c_noe2ni;
		m_c[3] = c_noe1e2;

	}





	// assign copy
	inline circle &circle::operator=(const circle &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline circle &circle::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline circle &circle::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void freeVector::set() {
		// set coordinates to 0
		mv_zero(m_c, 2);

	}

	// set to scalar 
	inline void freeVector::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;

	}


	// set to copy
	inline void freeVector::set(const freeVector &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 2);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];

	}

	// set to pointer to coordinates
	inline void freeVector::set(__freeVector_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 2);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];

	}

	// set to 'coordinates specified' 
	inline void freeVector::set(__freeVector_coordinates__, Float c_e1ni, Float c_e2ni) {
		// set coordinates
		m_c[0] = c_e1ni;
		m_c[1] = c_e2ni;

	}





	// assign copy
	inline freeVector &freeVector::operator=(const freeVector &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline freeVector &freeVector::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline freeVector &freeVector::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void freeBivector::set() {
		// set coordinates to 0
		mv_zero(m_c, 1);

	}

	// set to scalar 
	inline void freeBivector::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;

	}


	// set to copy
	inline void freeBivector::set(const freeBivector &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 1);
		m_c[0] = arg1.m_c[0];

	}

	// set to pointer to coordinates
	inline void freeBivector::set(__freeBivector_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 1);
		m_c[0] = coordinates[0];

	}

	// set to 'coordinates specified' 
	inline void freeBivector::set(__freeBivector_coordinates__, Float c_e1e2ni) {
		// set coordinates
		m_c[0] = c_e1e2ni;

	}





	// assign copy
	inline freeBivector &freeBivector::operator=(const freeBivector &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline freeBivector &freeBivector::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline freeBivector &freeBivector::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void tangentVector::set() {
		// set coordinates to 0
		mv_zero(m_c, 6);

	}

	// set to scalar 
	inline void tangentVector::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;
		m_c[3] = (Float)0.0;
		m_c[4] = (Float)0.0;
		m_c[5] = (Float)0.0;

	}


	// set to copy
	inline void tangentVector::set(const tangentVector &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 6);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];
		m_c[3] = arg1.m_c[3];
		m_c[4] = arg1.m_c[4];
		m_c[5] = arg1.m_c[5];

	}

	// set to pointer to coordinates
	inline void tangentVector::set(__tangentVector_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 6);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];
		m_c[3] = coordinates[3];
		m_c[4] = coordinates[4];
		m_c[5] = coordinates[5];

	}

	// set to 'coordinates specified' 
	inline void tangentVector::set(__tangentVector_coordinates__, Float c_noe1, Float c_noe2, Float c_e1e2, Float c_e1ni, Float c_e2ni, Float c_noni) {
		// set coordinates
		m_c[0] = c_noe1;
		m_c[1] = c_noe2;
		m_c[2] = c_e1e2;
		m_c[3] = c_e1ni;
		m_c[4] = c_e2ni;
		m_c[5] = c_noni;

	}





	// assign copy
	inline tangentVector &tangentVector::operator=(const tangentVector &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline tangentVector &tangentVector::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline tangentVector &tangentVector::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void tangentBivector::set() {
		// set coordinates to 0
		mv_zero(m_c, 4);

	}

	// set to scalar 
	inline void tangentBivector::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;
		m_c[3] = (Float)0.0;

	}


	// set to copy
	inline void tangentBivector::set(const tangentBivector &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 4);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];
		m_c[3] = arg1.m_c[3];

	}

	// set to pointer to coordinates
	inline void tangentBivector::set(__tangentBivector_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 4);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];
		m_c[3] = coordinates[3];

	}

	// set to 'coordinates specified' 
	inline void tangentBivector::set(__tangentBivector_coordinates__, Float c_e1e2ni, Float c_noe1ni, Float c_noe2ni, Float c_noe1e2) {
		// set coordinates
		m_c[0] = c_e1e2ni;
		m_c[1] = c_noe1ni;
		m_c[2] = c_noe2ni;
		m_c[3] = c_noe1e2;

	}





	// assign copy
	inline tangentBivector &tangentBivector::operator=(const tangentBivector &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline tangentBivector &tangentBivector::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline tangentBivector &tangentBivector::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void vectorE2GA::set() {
		// set coordinates to 0
		mv_zero(m_c, 2);

	}

	// set to scalar 
	inline void vectorE2GA::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;

	}


	// set to copy
	inline void vectorE2GA::set(const vectorE2GA &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 2);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];

	}

	// set to pointer to coordinates
	inline void vectorE2GA::set(__vectorE2GA_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 2);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];

	}

	// set to 'coordinates specified' 
	inline void vectorE2GA::set(__vectorE2GA_coordinates__, Float c_e1, Float c_e2) {
		// set coordinates
		m_c[0] = c_e1;
		m_c[1] = c_e2;

	}





	// assign copy
	inline vectorE2GA &vectorE2GA::operator=(const vectorE2GA &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline vectorE2GA &vectorE2GA::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline vectorE2GA &vectorE2GA::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void bivectorE2GA::set() {
		// set coordinates to 0
		mv_zero(m_c, 1);

	}

	// set to scalar 
	inline void bivectorE2GA::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;

	}


	// set to copy
	inline void bivectorE2GA::set(const bivectorE2GA &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 1);
		m_c[0] = arg1.m_c[0];

	}

	// set to pointer to coordinates
	inline void bivectorE2GA::set(__bivectorE2GA_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 1);
		m_c[0] = coordinates[0];

	}

	// set to 'coordinates specified' 
	inline void bivectorE2GA::set(__bivectorE2GA_coordinates__, Float c_e1e2) {
		// set coordinates
		m_c[0] = c_e1e2;

	}





	// assign copy
	inline bivectorE2GA &bivectorE2GA::operator=(const bivectorE2GA &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline bivectorE2GA &bivectorE2GA::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline bivectorE2GA &bivectorE2GA::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void TRversor::set() {
		// set coordinates to 0
		mv_zero(m_c, 4);

	}

	// set to scalar 
	inline void TRversor::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = s ;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;
		m_c[3] = (Float)0.0;

	}


	// set to copy
	inline void TRversor::set(const TRversor &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 4);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];
		m_c[3] = arg1.m_c[3];

	}

	// set to pointer to coordinates
	inline void TRversor::set(__TRversor_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 4);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];
		m_c[3] = coordinates[3];

	}

	// set to 'coordinates specified' 
	inline void TRversor::set(__TRversor_coordinates__, Float c_scalar, Float c_e1e2, Float c_e1ni, Float c_e2ni) {
		// set coordinates
		m_c[0] = c_scalar;
		m_c[1] = c_e1e2;
		m_c[2] = c_e1ni;
		m_c[3] = c_e2ni;

	}





	// assign copy
	inline TRversor &TRversor::operator=(const TRversor &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline TRversor &TRversor::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline TRversor &TRversor::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void TRSversor::set() {
		// set coordinates to 0
		mv_zero(m_c, 6);

	}

	// set to scalar 
	inline void TRSversor::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = s ;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;
		m_c[3] = (Float)0.0;
		m_c[4] = (Float)0.0;
		m_c[5] = (Float)0.0;

	}


	// set to copy
	inline void TRSversor::set(const TRSversor &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 6);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];
		m_c[3] = arg1.m_c[3];
		m_c[4] = arg1.m_c[4];
		m_c[5] = arg1.m_c[5];

	}

	// set to pointer to coordinates
	inline void TRSversor::set(__TRSversor_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 6);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];
		m_c[3] = coordinates[3];
		m_c[4] = coordinates[4];
		m_c[5] = coordinates[5];

	}

	// set to 'coordinates specified' 
	inline void TRSversor::set(__TRSversor_coordinates__, Float c_scalar, Float c_e1e2, Float c_e1ni, Float c_e2ni, Float c_noni, Float c_e1e2noni) {
		// set coordinates
		m_c[0] = c_scalar;
		m_c[1] = c_e1e2;
		m_c[2] = c_e1ni;
		m_c[3] = c_e2ni;
		m_c[4] = c_noni;
		m_c[5] = c_e1e2noni;

	}





	// assign copy
	inline TRSversor &TRSversor::operator=(const TRSversor &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline TRSversor &TRSversor::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline TRSversor &TRSversor::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void evenVersor::set() {
		// set coordinates to 0
		mv_zero(m_c, 8);

	}

	// set to scalar 
	inline void evenVersor::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = s ;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;
		m_c[3] = (Float)0.0;
		m_c[4] = (Float)0.0;
		m_c[5] = (Float)0.0;
		m_c[6] = (Float)0.0;
		m_c[7] = (Float)0.0;

	}


	// set to copy
	inline void evenVersor::set(const evenVersor &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 8);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];
		m_c[3] = arg1.m_c[3];
		m_c[4] = arg1.m_c[4];
		m_c[5] = arg1.m_c[5];
		m_c[6] = arg1.m_c[6];
		m_c[7] = arg1.m_c[7];

	}

	// set to pointer to coordinates
	inline void evenVersor::set(__evenVersor_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 8);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];
		m_c[3] = coordinates[3];
		m_c[4] = coordinates[4];
		m_c[5] = coordinates[5];
		m_c[6] = coordinates[6];
		m_c[7] = coordinates[7];

	}

	// set to 'coordinates specified' 
	inline void evenVersor::set(__evenVersor_coordinates__, Float c_scalar, Float c_noe1, Float c_noe2, Float c_e1e2, Float c_e1ni, Float c_e2ni, Float c_noni, Float c_e1e2noni) {
		// set coordinates
		m_c[0] = c_scalar;
		m_c[1] = c_noe1;
		m_c[2] = c_noe2;
		m_c[3] = c_e1e2;
		m_c[4] = c_e1ni;
		m_c[5] = c_e2ni;
		m_c[6] = c_noni;
		m_c[7] = c_e1e2noni;

	}





	// assign copy
	inline evenVersor &evenVersor::operator=(const evenVersor &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline evenVersor &evenVersor::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline evenVersor &evenVersor::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void translator::set() {
		// set coordinates to 0
		mv_zero(m_c, 3);

	}

	// set to scalar 
	inline void translator::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = s ;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;

	}


	// set to copy
	inline void translator::set(const translator &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 3);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];

	}

	// set to pointer to coordinates
	inline void translator::set(__translator_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 3);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];

	}

	// set to 'coordinates specified' 
	inline void translator::set(__translator_coordinates__, Float c_scalar, Float c_e1ni, Float c_e2ni) {
		// set coordinates
		m_c[0] = c_scalar;
		m_c[1] = c_e1ni;
		m_c[2] = c_e2ni;

	}





	// assign copy
	inline translator &translator::operator=(const translator &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline translator &translator::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline translator &translator::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void normalizedTranslator::set() {
		// set coordinates to 0
		mv_zero(m_c, 2);

	}

	// set to scalar 
	inline void normalizedTranslator::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;

	}


	// set to copy
	inline void normalizedTranslator::set(const normalizedTranslator &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 2);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];

	}

	// set to pointer to coordinates
	inline void normalizedTranslator::set(__normalizedTranslator_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 2);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];

	}

	// set to 'coordinates specified' 
	inline void normalizedTranslator::set(__normalizedTranslator_coordinates__, Float c_e1ni, Float c_e2ni) {
		// set coordinates
		m_c[0] = c_e1ni;
		m_c[1] = c_e2ni;

	}





	// assign copy
	inline normalizedTranslator &normalizedTranslator::operator=(const normalizedTranslator &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline normalizedTranslator &normalizedTranslator::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline normalizedTranslator &normalizedTranslator::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void rotor::set() {
		// set coordinates to 0
		mv_zero(m_c, 2);

	}

	// set to scalar 
	inline void rotor::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = s ;
		m_c[1] = (Float)0.0;

	}


	// set to copy
	inline void rotor::set(const rotor &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 2);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];

	}

	// set to pointer to coordinates
	inline void rotor::set(__rotor_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 2);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];

	}

	// set to 'coordinates specified' 
	inline void rotor::set(__rotor_coordinates__, Float c_scalar, Float c_e1e2) {
		// set coordinates
		m_c[0] = c_scalar;
		m_c[1] = c_e1e2;

	}





	// assign copy
	inline rotor &rotor::operator=(const rotor &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline rotor &rotor::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline rotor &rotor::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void scalor::set() {
		// set coordinates to 0
		mv_zero(m_c, 2);

	}

	// set to scalar 
	inline void scalor::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = s ;
		m_c[1] = (Float)0.0;

	}


	// set to copy
	inline void scalor::set(const scalor &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 2);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];

	}

	// set to pointer to coordinates
	inline void scalor::set(__scalor_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 2);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];

	}

	// set to 'coordinates specified' 
	inline void scalor::set(__scalor_coordinates__, Float c_scalar, Float c_noni) {
		// set coordinates
		m_c[0] = c_scalar;
		m_c[1] = c_noni;

	}





	// assign copy
	inline scalor &scalor::operator=(const scalor &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline scalor &scalor::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline scalor &scalor::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __no_ct__::set() {
		// set coordinates to 0
	}

	// set to scalar 
	inline void __no_ct__::set(Float s) {
		// set coordinates 0, except for scalar (if any)

	}


	// set to copy
	inline void __no_ct__::set(const __no_ct__ &arg1) {
	}

	// set to pointer to coordinates
	inline void __no_ct__::set(____no_ct___coordinates__, const Float *coordinates) {
		// copy coordinates
	}

	// set to 'coordinates specified' 
	inline void __no_ct__::set(____no_ct___coordinates__) {
		// set coordinates

	}





	// assign copy
	inline __no_ct__ &__no_ct__::operator=(const __no_ct__ &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __no_ct__ &__no_ct__::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __no_ct__ &__no_ct__::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __e1_ct__::set() {
		// set coordinates to 0
	}

	// set to scalar 
	inline void __e1_ct__::set(Float s) {
		// set coordinates 0, except for scalar (if any)

	}


	// set to copy
	inline void __e1_ct__::set(const __e1_ct__ &arg1) {
	}

	// set to pointer to coordinates
	inline void __e1_ct__::set(____e1_ct___coordinates__, const Float *coordinates) {
		// copy coordinates
	}

	// set to 'coordinates specified' 
	inline void __e1_ct__::set(____e1_ct___coordinates__) {
		// set coordinates

	}





	// assign copy
	inline __e1_ct__ &__e1_ct__::operator=(const __e1_ct__ &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __e1_ct__ &__e1_ct__::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __e1_ct__ &__e1_ct__::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __e2_ct__::set() {
		// set coordinates to 0
	}

	// set to scalar 
	inline void __e2_ct__::set(Float s) {
		// set coordinates 0, except for scalar (if any)

	}


	// set to copy
	inline void __e2_ct__::set(const __e2_ct__ &arg1) {
	}

	// set to pointer to coordinates
	inline void __e2_ct__::set(____e2_ct___coordinates__, const Float *coordinates) {
		// copy coordinates
	}

	// set to 'coordinates specified' 
	inline void __e2_ct__::set(____e2_ct___coordinates__) {
		// set coordinates

	}





	// assign copy
	inline __e2_ct__ &__e2_ct__::operator=(const __e2_ct__ &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __e2_ct__ &__e2_ct__::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __e2_ct__ &__e2_ct__::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __ni_ct__::set() {
		// set coordinates to 0
	}

	// set to scalar 
	inline void __ni_ct__::set(Float s) {
		// set coordinates 0, except for scalar (if any)

	}


	// set to copy
	inline void __ni_ct__::set(const __ni_ct__ &arg1) {
	}

	// set to pointer to coordinates
	inline void __ni_ct__::set(____ni_ct___coordinates__, const Float *coordinates) {
		// copy coordinates
	}

	// set to 'coordinates specified' 
	inline void __ni_ct__::set(____ni_ct___coordinates__) {
		// set coordinates

	}





	// assign copy
	inline __ni_ct__ &__ni_ct__::operator=(const __ni_ct__ &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __ni_ct__ &__ni_ct__::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __ni_ct__ &__ni_ct__::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __I4i_ct__::set() {
		// set coordinates to 0
	}

	// set to scalar 
	inline void __I4i_ct__::set(Float s) {
		// set coordinates 0, except for scalar (if any)

	}


	// set to copy
	inline void __I4i_ct__::set(const __I4i_ct__ &arg1) {
	}

	// set to pointer to coordinates
	inline void __I4i_ct__::set(____I4i_ct___coordinates__, const Float *coordinates) {
		// copy coordinates
	}

	// set to 'coordinates specified' 
	inline void __I4i_ct__::set(____I4i_ct___coordinates__) {
		// set coordinates

	}





	// assign copy
	inline __I4i_ct__ &__I4i_ct__::operator=(const __I4i_ct__ &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __I4i_ct__ &__I4i_ct__::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __I4i_ct__ &__I4i_ct__::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __I4_ct__::set() {
		// set coordinates to 0
	}

	// set to scalar 
	inline void __I4_ct__::set(Float s) {
		// set coordinates 0, except for scalar (if any)

	}


	// set to copy
	inline void __I4_ct__::set(const __I4_ct__ &arg1) {
	}

	// set to pointer to coordinates
	inline void __I4_ct__::set(____I4_ct___coordinates__, const Float *coordinates) {
		// copy coordinates
	}

	// set to 'coordinates specified' 
	inline void __I4_ct__::set(____I4_ct___coordinates__) {
		// set coordinates

	}





	// assign copy
	inline __I4_ct__ &__I4_ct__::operator=(const __I4_ct__ &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __I4_ct__ &__I4_ct__::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __I4_ct__ &__I4_ct__::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __I2_ct__::set() {
		// set coordinates to 0
	}

	// set to scalar 
	inline void __I2_ct__::set(Float s) {
		// set coordinates 0, except for scalar (if any)

	}


	// set to copy
	inline void __I2_ct__::set(const __I2_ct__ &arg1) {
	}

	// set to pointer to coordinates
	inline void __I2_ct__::set(____I2_ct___coordinates__, const Float *coordinates) {
		// copy coordinates
	}

	// set to 'coordinates specified' 
	inline void __I2_ct__::set(____I2_ct___coordinates__) {
		// set coordinates

	}





	// assign copy
	inline __I2_ct__ &__I2_ct__::operator=(const __I2_ct__ &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __I2_ct__ &__I2_ct__::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __I2_ct__ &__I2_ct__::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __noni_ct__::set() {
		// set coordinates to 0
	}

	// set to scalar 
	inline void __noni_ct__::set(Float s) {
		// set coordinates 0, except for scalar (if any)

	}


	// set to copy
	inline void __noni_ct__::set(const __noni_ct__ &arg1) {
	}

	// set to pointer to coordinates
	inline void __noni_ct__::set(____noni_ct___coordinates__, const Float *coordinates) {
		// copy coordinates
	}

	// set to 'coordinates specified' 
	inline void __noni_ct__::set(____noni_ct___coordinates__) {
		// set coordinates

	}





	// assign copy
	inline __noni_ct__ &__noni_ct__::operator=(const __noni_ct__ &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __noni_ct__ &__noni_ct__::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __noni_ct__ &__noni_ct__::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __e2ni_ct__::set() {
		// set coordinates to 0
	}

	// set to scalar 
	inline void __e2ni_ct__::set(Float s) {
		// set coordinates 0, except for scalar (if any)

	}


	// set to copy
	inline void __e2ni_ct__::set(const __e2ni_ct__ &arg1) {
	}

	// set to pointer to coordinates
	inline void __e2ni_ct__::set(____e2ni_ct___coordinates__, const Float *coordinates) {
		// copy coordinates
	}

	// set to 'coordinates specified' 
	inline void __e2ni_ct__::set(____e2ni_ct___coordinates__) {
		// set coordinates

	}





	// assign copy
	inline __e2ni_ct__ &__e2ni_ct__::operator=(const __e2ni_ct__ &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __e2ni_ct__ &__e2ni_ct__::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __e2ni_ct__ &__e2ni_ct__::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __e1ni_ct__::set() {
		// set coordinates to 0
	}

	// set to scalar 
	inline void __e1ni_ct__::set(Float s) {
		// set coordinates 0, except for scalar (if any)

	}


	// set to copy
	inline void __e1ni_ct__::set(const __e1ni_ct__ &arg1) {
	}

	// set to pointer to coordinates
	inline void __e1ni_ct__::set(____e1ni_ct___coordinates__, const Float *coordinates) {
		// copy coordinates
	}

	// set to 'coordinates specified' 
	inline void __e1ni_ct__::set(____e1ni_ct___coordinates__) {
		// set coordinates

	}





	// assign copy
	inline __e1ni_ct__ &__e1ni_ct__::operator=(const __e1ni_ct__ &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __e1ni_ct__ &__e1ni_ct__::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __e1ni_ct__ &__e1ni_ct__::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __syn_smv___e1_e2_nof1_0::set() {
		// set coordinates to 0
		mv_zero(m_c, 2);

	}

	// set to scalar 
	inline void __syn_smv___e1_e2_nof1_0::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;

	}


	// set to copy
	inline void __syn_smv___e1_e2_nof1_0::set(const __syn_smv___e1_e2_nof1_0 &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 2);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];

	}

	// set to pointer to coordinates
	inline void __syn_smv___e1_e2_nof1_0::set(____syn_smv___e1_e2_nof1_0_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 2);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];

	}

	// set to 'coordinates specified' 
	inline void __syn_smv___e1_e2_nof1_0::set(____syn_smv___e1_e2_nof1_0_coordinates__, Float c_e1, Float c_e2) {
		// set coordinates
		m_c[0] = c_e1;
		m_c[1] = c_e2;

	}





	// assign copy
	inline __syn_smv___e1_e2_nof1_0 &__syn_smv___e1_e2_nof1_0::operator=(const __syn_smv___e1_e2_nof1_0 &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __syn_smv___e1_e2_nof1_0 &__syn_smv___e1_e2_nof1_0::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __syn_smv___e1_e2_nof1_0 &__syn_smv___e1_e2_nof1_0::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __syn_smv___e1e2nif1_0::set() {
		// set coordinates to 0
	}

	// set to scalar 
	inline void __syn_smv___e1e2nif1_0::set(Float s) {
		// set coordinates 0, except for scalar (if any)

	}


	// set to copy
	inline void __syn_smv___e1e2nif1_0::set(const __syn_smv___e1e2nif1_0 &arg1) {
	}

	// set to pointer to coordinates
	inline void __syn_smv___e1e2nif1_0::set(____syn_smv___e1e2nif1_0_coordinates__, const Float *coordinates) {
		// copy coordinates
	}

	// set to 'coordinates specified' 
	inline void __syn_smv___e1e2nif1_0::set(____syn_smv___e1e2nif1_0_coordinates__) {
		// set coordinates

	}





	// assign copy
	inline __syn_smv___e1e2nif1_0 &__syn_smv___e1e2nif1_0::operator=(const __syn_smv___e1e2nif1_0 &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __syn_smv___e1e2nif1_0 &__syn_smv___e1e2nif1_0::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __syn_smv___e1e2nif1_0 &__syn_smv___e1e2nif1_0::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __syn_smv___e1_e2_ni_nof_1_0::set() {
		// set coordinates to 0
		mv_zero(m_c, 3);

	}

	// set to scalar 
	inline void __syn_smv___e1_e2_ni_nof_1_0::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;

	}


	// set to copy
	inline void __syn_smv___e1_e2_ni_nof_1_0::set(const __syn_smv___e1_e2_ni_nof_1_0 &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 3);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];

	}

	// set to pointer to coordinates
	inline void __syn_smv___e1_e2_ni_nof_1_0::set(____syn_smv___e1_e2_ni_nof_1_0_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 3);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];

	}

	// set to 'coordinates specified' 
	inline void __syn_smv___e1_e2_ni_nof_1_0::set(____syn_smv___e1_e2_ni_nof_1_0_coordinates__, Float c_e1, Float c_e2, Float c_ni) {
		// set coordinates
		m_c[0] = c_e1;
		m_c[1] = c_e2;
		m_c[2] = c_ni;

	}





	// assign copy
	inline __syn_smv___e1_e2_ni_nof_1_0 &__syn_smv___e1_e2_ni_nof_1_0::operator=(const __syn_smv___e1_e2_ni_nof_1_0 &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __syn_smv___e1_e2_ni_nof_1_0 &__syn_smv___e1_e2_ni_nof_1_0::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __syn_smv___e1_e2_ni_nof_1_0 &__syn_smv___e1_e2_ni_nof_1_0::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni::set() {
		// set coordinates to 0
		mv_zero(m_c, 7);

	}

	// set to scalar 
	inline void __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = s ;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;
		m_c[3] = (Float)0.0;
		m_c[4] = (Float)0.0;
		m_c[5] = (Float)0.0;
		m_c[6] = (Float)0.0;

	}


	// set to copy
	inline void __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni::set(const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 7);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];
		m_c[3] = arg1.m_c[3];
		m_c[4] = arg1.m_c[4];
		m_c[5] = arg1.m_c[5];
		m_c[6] = arg1.m_c[6];

	}

	// set to pointer to coordinates
	inline void __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni::set(____syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 7);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];
		m_c[3] = coordinates[3];
		m_c[4] = coordinates[4];
		m_c[5] = coordinates[5];
		m_c[6] = coordinates[6];

	}

	// set to 'coordinates specified' 
	inline void __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni::set(____syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni_coordinates__, Float c_scalar, Float c_noe1, Float c_noe2, Float c_e1e2, Float c_noni, Float c_e1ni, Float c_e2ni) {
		// set coordinates
		m_c[0] = c_scalar;
		m_c[1] = c_noe1;
		m_c[2] = c_noe2;
		m_c[3] = c_e1e2;
		m_c[4] = c_noni;
		m_c[5] = c_e1ni;
		m_c[6] = c_e2ni;

	}





	// assign copy
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni &__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni::operator=(const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni &__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni &__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __syn_smv___scalar_noe1_noe2_noni::set() {
		// set coordinates to 0
		mv_zero(m_c, 4);

	}

	// set to scalar 
	inline void __syn_smv___scalar_noe1_noe2_noni::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = s ;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;
		m_c[3] = (Float)0.0;

	}


	// set to copy
	inline void __syn_smv___scalar_noe1_noe2_noni::set(const __syn_smv___scalar_noe1_noe2_noni &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 4);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];
		m_c[3] = arg1.m_c[3];

	}

	// set to pointer to coordinates
	inline void __syn_smv___scalar_noe1_noe2_noni::set(____syn_smv___scalar_noe1_noe2_noni_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 4);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];
		m_c[3] = coordinates[3];

	}

	// set to 'coordinates specified' 
	inline void __syn_smv___scalar_noe1_noe2_noni::set(____syn_smv___scalar_noe1_noe2_noni_coordinates__, Float c_scalar, Float c_noe1, Float c_noe2, Float c_noni) {
		// set coordinates
		m_c[0] = c_scalar;
		m_c[1] = c_noe1;
		m_c[2] = c_noe2;
		m_c[3] = c_noni;

	}





	// assign copy
	inline __syn_smv___scalar_noe1_noe2_noni &__syn_smv___scalar_noe1_noe2_noni::operator=(const __syn_smv___scalar_noe1_noe2_noni &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __syn_smv___scalar_noe1_noe2_noni &__syn_smv___scalar_noe1_noe2_noni::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __syn_smv___scalar_noe1_noe2_noni &__syn_smv___scalar_noe1_noe2_noni::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni::set() {
		// set coordinates to 0
		mv_zero(m_c, 7);

	}

	// set to scalar 
	inline void __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;
		m_c[3] = (Float)0.0;
		m_c[4] = (Float)0.0;
		m_c[5] = (Float)0.0;
		m_c[6] = (Float)0.0;

	}


	// set to copy
	inline void __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni::set(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 7);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];
		m_c[3] = arg1.m_c[3];
		m_c[4] = arg1.m_c[4];
		m_c[5] = arg1.m_c[5];
		m_c[6] = arg1.m_c[6];

	}

	// set to pointer to coordinates
	inline void __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni::set(____syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 7);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];
		m_c[3] = coordinates[3];
		m_c[4] = coordinates[4];
		m_c[5] = coordinates[5];
		m_c[6] = coordinates[6];

	}

	// set to 'coordinates specified' 
	inline void __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni::set(____syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni_coordinates__, Float c_no, Float c_e1, Float c_e2, Float c_noe1e2, Float c_ni, Float c_noe1ni, Float c_noe2ni) {
		// set coordinates
		m_c[0] = c_no;
		m_c[1] = c_e1;
		m_c[2] = c_e2;
		m_c[3] = c_noe1e2;
		m_c[4] = c_ni;
		m_c[5] = c_noe1ni;
		m_c[6] = c_noe2ni;

	}





	// assign copy
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni &__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni::operator=(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni &__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni &__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __syn_smv___scalar_noe1_e1e2_e1ni::set() {
		// set coordinates to 0
		mv_zero(m_c, 4);

	}

	// set to scalar 
	inline void __syn_smv___scalar_noe1_e1e2_e1ni::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = s ;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;
		m_c[3] = (Float)0.0;

	}


	// set to copy
	inline void __syn_smv___scalar_noe1_e1e2_e1ni::set(const __syn_smv___scalar_noe1_e1e2_e1ni &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 4);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];
		m_c[3] = arg1.m_c[3];

	}

	// set to pointer to coordinates
	inline void __syn_smv___scalar_noe1_e1e2_e1ni::set(____syn_smv___scalar_noe1_e1e2_e1ni_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 4);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];
		m_c[3] = coordinates[3];

	}

	// set to 'coordinates specified' 
	inline void __syn_smv___scalar_noe1_e1e2_e1ni::set(____syn_smv___scalar_noe1_e1e2_e1ni_coordinates__, Float c_scalar, Float c_noe1, Float c_e1e2, Float c_e1ni) {
		// set coordinates
		m_c[0] = c_scalar;
		m_c[1] = c_noe1;
		m_c[2] = c_e1e2;
		m_c[3] = c_e1ni;

	}





	// assign copy
	inline __syn_smv___scalar_noe1_e1e2_e1ni &__syn_smv___scalar_noe1_e1e2_e1ni::operator=(const __syn_smv___scalar_noe1_e1e2_e1ni &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __syn_smv___scalar_noe1_e1e2_e1ni &__syn_smv___scalar_noe1_e1e2_e1ni::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __syn_smv___scalar_noe1_e1e2_e1ni &__syn_smv___scalar_noe1_e1e2_e1ni::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni::set() {
		// set coordinates to 0
		mv_zero(m_c, 7);

	}

	// set to scalar 
	inline void __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;
		m_c[3] = (Float)0.0;
		m_c[4] = (Float)0.0;
		m_c[5] = (Float)0.0;
		m_c[6] = (Float)0.0;

	}


	// set to copy
	inline void __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni::set(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 7);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];
		m_c[3] = arg1.m_c[3];
		m_c[4] = arg1.m_c[4];
		m_c[5] = arg1.m_c[5];
		m_c[6] = arg1.m_c[6];

	}

	// set to pointer to coordinates
	inline void __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni::set(____syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 7);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];
		m_c[3] = coordinates[3];
		m_c[4] = coordinates[4];
		m_c[5] = coordinates[5];
		m_c[6] = coordinates[6];

	}

	// set to 'coordinates specified' 
	inline void __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni::set(____syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni_coordinates__, Float c_no, Float c_e1, Float c_e2, Float c_noe1e2, Float c_ni, Float c_noe1ni, Float c_e1e2ni) {
		// set coordinates
		m_c[0] = c_no;
		m_c[1] = c_e1;
		m_c[2] = c_e2;
		m_c[3] = c_noe1e2;
		m_c[4] = c_ni;
		m_c[5] = c_noe1ni;
		m_c[6] = c_e1e2ni;

	}





	// assign copy
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni &__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni::operator=(const __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni &__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni &__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __syn_smv___scalar_noe2_e1e2_e2ni::set() {
		// set coordinates to 0
		mv_zero(m_c, 4);

	}

	// set to scalar 
	inline void __syn_smv___scalar_noe2_e1e2_e2ni::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = s ;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;
		m_c[3] = (Float)0.0;

	}


	// set to copy
	inline void __syn_smv___scalar_noe2_e1e2_e2ni::set(const __syn_smv___scalar_noe2_e1e2_e2ni &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 4);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];
		m_c[3] = arg1.m_c[3];

	}

	// set to pointer to coordinates
	inline void __syn_smv___scalar_noe2_e1e2_e2ni::set(____syn_smv___scalar_noe2_e1e2_e2ni_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 4);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];
		m_c[3] = coordinates[3];

	}

	// set to 'coordinates specified' 
	inline void __syn_smv___scalar_noe2_e1e2_e2ni::set(____syn_smv___scalar_noe2_e1e2_e2ni_coordinates__, Float c_scalar, Float c_noe2, Float c_e1e2, Float c_e2ni) {
		// set coordinates
		m_c[0] = c_scalar;
		m_c[1] = c_noe2;
		m_c[2] = c_e1e2;
		m_c[3] = c_e2ni;

	}





	// assign copy
	inline __syn_smv___scalar_noe2_e1e2_e2ni &__syn_smv___scalar_noe2_e1e2_e2ni::operator=(const __syn_smv___scalar_noe2_e1e2_e2ni &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __syn_smv___scalar_noe2_e1e2_e2ni &__syn_smv___scalar_noe2_e1e2_e2ni::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __syn_smv___scalar_noe2_e1e2_e2ni &__syn_smv___scalar_noe2_e1e2_e2ni::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni::set() {
		// set coordinates to 0
		mv_zero(m_c, 7);

	}

	// set to scalar 
	inline void __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;
		m_c[3] = (Float)0.0;
		m_c[4] = (Float)0.0;
		m_c[5] = (Float)0.0;
		m_c[6] = (Float)0.0;

	}


	// set to copy
	inline void __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni::set(const __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 7);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];
		m_c[3] = arg1.m_c[3];
		m_c[4] = arg1.m_c[4];
		m_c[5] = arg1.m_c[5];
		m_c[6] = arg1.m_c[6];

	}

	// set to pointer to coordinates
	inline void __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni::set(____syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 7);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];
		m_c[3] = coordinates[3];
		m_c[4] = coordinates[4];
		m_c[5] = coordinates[5];
		m_c[6] = coordinates[6];

	}

	// set to 'coordinates specified' 
	inline void __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni::set(____syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni_coordinates__, Float c_no, Float c_e1, Float c_e2, Float c_noe1e2, Float c_ni, Float c_noe2ni, Float c_e1e2ni) {
		// set coordinates
		m_c[0] = c_no;
		m_c[1] = c_e1;
		m_c[2] = c_e2;
		m_c[3] = c_noe1e2;
		m_c[4] = c_ni;
		m_c[5] = c_noe2ni;
		m_c[6] = c_e1e2ni;

	}





	// assign copy
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni &__syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni::operator=(const __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni &__syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni &__syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __syn_smv___scalar_noni_e1ni_e2ni::set() {
		// set coordinates to 0
		mv_zero(m_c, 4);

	}

	// set to scalar 
	inline void __syn_smv___scalar_noni_e1ni_e2ni::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = s ;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;
		m_c[3] = (Float)0.0;

	}


	// set to copy
	inline void __syn_smv___scalar_noni_e1ni_e2ni::set(const __syn_smv___scalar_noni_e1ni_e2ni &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 4);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];
		m_c[3] = arg1.m_c[3];

	}

	// set to pointer to coordinates
	inline void __syn_smv___scalar_noni_e1ni_e2ni::set(____syn_smv___scalar_noni_e1ni_e2ni_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 4);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];
		m_c[3] = coordinates[3];

	}

	// set to 'coordinates specified' 
	inline void __syn_smv___scalar_noni_e1ni_e2ni::set(____syn_smv___scalar_noni_e1ni_e2ni_coordinates__, Float c_scalar, Float c_noni, Float c_e1ni, Float c_e2ni) {
		// set coordinates
		m_c[0] = c_scalar;
		m_c[1] = c_noni;
		m_c[2] = c_e1ni;
		m_c[3] = c_e2ni;

	}





	// assign copy
	inline __syn_smv___scalar_noni_e1ni_e2ni &__syn_smv___scalar_noni_e1ni_e2ni::operator=(const __syn_smv___scalar_noni_e1ni_e2ni &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __syn_smv___scalar_noni_e1ni_e2ni &__syn_smv___scalar_noni_e1ni_e2ni::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __syn_smv___scalar_noni_e1ni_e2ni &__syn_smv___scalar_noni_e1ni_e2ni::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni::set() {
		// set coordinates to 0
		mv_zero(m_c, 7);

	}

	// set to scalar 
	inline void __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;
		m_c[3] = (Float)0.0;
		m_c[4] = (Float)0.0;
		m_c[5] = (Float)0.0;
		m_c[6] = (Float)0.0;

	}


	// set to copy
	inline void __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni::set(const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 7);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];
		m_c[3] = arg1.m_c[3];
		m_c[4] = arg1.m_c[4];
		m_c[5] = arg1.m_c[5];
		m_c[6] = arg1.m_c[6];

	}

	// set to pointer to coordinates
	inline void __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni::set(____syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 7);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];
		m_c[3] = coordinates[3];
		m_c[4] = coordinates[4];
		m_c[5] = coordinates[5];
		m_c[6] = coordinates[6];

	}

	// set to 'coordinates specified' 
	inline void __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni::set(____syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni_coordinates__, Float c_no, Float c_e1, Float c_e2, Float c_ni, Float c_noe1ni, Float c_noe2ni, Float c_e1e2ni) {
		// set coordinates
		m_c[0] = c_no;
		m_c[1] = c_e1;
		m_c[2] = c_e2;
		m_c[3] = c_ni;
		m_c[4] = c_noe1ni;
		m_c[5] = c_noe2ni;
		m_c[6] = c_e1e2ni;

	}





	// assign copy
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni &__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni::operator=(const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni &__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni &__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __syn_smv___e1ni_e2ni_nonif_1_0::set() {
		// set coordinates to 0
		mv_zero(m_c, 2);

	}

	// set to scalar 
	inline void __syn_smv___e1ni_e2ni_nonif_1_0::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;

	}


	// set to copy
	inline void __syn_smv___e1ni_e2ni_nonif_1_0::set(const __syn_smv___e1ni_e2ni_nonif_1_0 &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 2);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];

	}

	// set to pointer to coordinates
	inline void __syn_smv___e1ni_e2ni_nonif_1_0::set(____syn_smv___e1ni_e2ni_nonif_1_0_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 2);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];

	}

	// set to 'coordinates specified' 
	inline void __syn_smv___e1ni_e2ni_nonif_1_0::set(____syn_smv___e1ni_e2ni_nonif_1_0_coordinates__, Float c_e1ni, Float c_e2ni) {
		// set coordinates
		m_c[0] = c_e1ni;
		m_c[1] = c_e2ni;

	}





	// assign copy
	inline __syn_smv___e1ni_e2ni_nonif_1_0 &__syn_smv___e1ni_e2ni_nonif_1_0::operator=(const __syn_smv___e1ni_e2ni_nonif_1_0 &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __syn_smv___e1ni_e2ni_nonif_1_0 &__syn_smv___e1ni_e2ni_nonif_1_0::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __syn_smv___e1ni_e2ni_nonif_1_0 &__syn_smv___e1ni_e2ni_nonif_1_0::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __syn_smv___scalarf_1_0::set() {
		// set coordinates to 0
	}

	// set to scalar 
	inline void __syn_smv___scalarf_1_0::set(Float s) {
		// set coordinates 0, except for scalar (if any)

	}


	// set to copy
	inline void __syn_smv___scalarf_1_0::set(const __syn_smv___scalarf_1_0 &arg1) {
	}

	// set to pointer to coordinates
	inline void __syn_smv___scalarf_1_0::set(____syn_smv___scalarf_1_0_coordinates__, const Float *coordinates) {
		// copy coordinates
	}

	// set to 'coordinates specified' 
	inline void __syn_smv___scalarf_1_0::set(____syn_smv___scalarf_1_0_coordinates__) {
		// set coordinates

	}





	// assign copy
	inline __syn_smv___scalarf_1_0 &__syn_smv___scalarf_1_0::operator=(const __syn_smv___scalarf_1_0 &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __syn_smv___scalarf_1_0 &__syn_smv___scalarf_1_0::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __syn_smv___scalarf_1_0 &__syn_smv___scalarf_1_0::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __syn_smv___nif_1_0::set() {
		// set coordinates to 0
	}

	// set to scalar 
	inline void __syn_smv___nif_1_0::set(Float s) {
		// set coordinates 0, except for scalar (if any)

	}


	// set to copy
	inline void __syn_smv___nif_1_0::set(const __syn_smv___nif_1_0 &arg1) {
	}

	// set to pointer to coordinates
	inline void __syn_smv___nif_1_0::set(____syn_smv___nif_1_0_coordinates__, const Float *coordinates) {
		// copy coordinates
	}

	// set to 'coordinates specified' 
	inline void __syn_smv___nif_1_0::set(____syn_smv___nif_1_0_coordinates__) {
		// set coordinates

	}





	// assign copy
	inline __syn_smv___nif_1_0 &__syn_smv___nif_1_0::operator=(const __syn_smv___nif_1_0 &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __syn_smv___nif_1_0 &__syn_smv___nif_1_0::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __syn_smv___nif_1_0 &__syn_smv___nif_1_0::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __syn_smv___nif1_0::set() {
		// set coordinates to 0
	}

	// set to scalar 
	inline void __syn_smv___nif1_0::set(Float s) {
		// set coordinates 0, except for scalar (if any)

	}


	// set to copy
	inline void __syn_smv___nif1_0::set(const __syn_smv___nif1_0 &arg1) {
	}

	// set to pointer to coordinates
	inline void __syn_smv___nif1_0::set(____syn_smv___nif1_0_coordinates__, const Float *coordinates) {
		// copy coordinates
	}

	// set to 'coordinates specified' 
	inline void __syn_smv___nif1_0::set(____syn_smv___nif1_0_coordinates__) {
		// set coordinates

	}





	// assign copy
	inline __syn_smv___nif1_0 &__syn_smv___nif1_0::operator=(const __syn_smv___nif1_0 &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __syn_smv___nif1_0 &__syn_smv___nif1_0::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __syn_smv___nif1_0 &__syn_smv___nif1_0::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0::set() {
		// set coordinates to 0
		mv_zero(m_c, 6);

	}

	// set to scalar 
	inline void __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;
		m_c[3] = (Float)0.0;
		m_c[4] = (Float)0.0;
		m_c[5] = (Float)0.0;

	}


	// set to copy
	inline void __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0::set(const __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 6);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];
		m_c[3] = arg1.m_c[3];
		m_c[4] = arg1.m_c[4];
		m_c[5] = arg1.m_c[5];

	}

	// set to pointer to coordinates
	inline void __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0::set(____syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 6);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];
		m_c[3] = coordinates[3];
		m_c[4] = coordinates[4];
		m_c[5] = coordinates[5];

	}

	// set to 'coordinates specified' 
	inline void __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0::set(____syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0_coordinates__, Float c_e1, Float c_e2, Float c_ni, Float c_noe1ni, Float c_noe2ni, Float c_e1e2ni) {
		// set coordinates
		m_c[0] = c_e1;
		m_c[1] = c_e2;
		m_c[2] = c_ni;
		m_c[3] = c_noe1ni;
		m_c[4] = c_noe2ni;
		m_c[5] = c_e1e2ni;

	}





	// assign copy
	inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 &__syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0::operator=(const __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 &__syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 &__syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __syn_smv___e1_e2_ni_nof2_0::set() {
		// set coordinates to 0
		mv_zero(m_c, 3);

	}

	// set to scalar 
	inline void __syn_smv___e1_e2_ni_nof2_0::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;

	}


	// set to copy
	inline void __syn_smv___e1_e2_ni_nof2_0::set(const __syn_smv___e1_e2_ni_nof2_0 &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 3);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];

	}

	// set to pointer to coordinates
	inline void __syn_smv___e1_e2_ni_nof2_0::set(____syn_smv___e1_e2_ni_nof2_0_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 3);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];

	}

	// set to 'coordinates specified' 
	inline void __syn_smv___e1_e2_ni_nof2_0::set(____syn_smv___e1_e2_ni_nof2_0_coordinates__, Float c_e1, Float c_e2, Float c_ni) {
		// set coordinates
		m_c[0] = c_e1;
		m_c[1] = c_e2;
		m_c[2] = c_ni;

	}





	// assign copy
	inline __syn_smv___e1_e2_ni_nof2_0 &__syn_smv___e1_e2_ni_nof2_0::operator=(const __syn_smv___e1_e2_ni_nof2_0 &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __syn_smv___e1_e2_ni_nof2_0 &__syn_smv___e1_e2_ni_nof2_0::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __syn_smv___e1_e2_ni_nof2_0 &__syn_smv___e1_e2_ni_nof2_0::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __syn_smv___e1_e2_ni::set() {
		// set coordinates to 0
		mv_zero(m_c, 3);

	}

	// set to scalar 
	inline void __syn_smv___e1_e2_ni::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;

	}


	// set to copy
	inline void __syn_smv___e1_e2_ni::set(const __syn_smv___e1_e2_ni &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 3);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];

	}

	// set to pointer to coordinates
	inline void __syn_smv___e1_e2_ni::set(____syn_smv___e1_e2_ni_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 3);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];

	}

	// set to 'coordinates specified' 
	inline void __syn_smv___e1_e2_ni::set(____syn_smv___e1_e2_ni_coordinates__, Float c_e1, Float c_e2, Float c_ni) {
		// set coordinates
		m_c[0] = c_e1;
		m_c[1] = c_e2;
		m_c[2] = c_ni;

	}





	// assign copy
	inline __syn_smv___e1_e2_ni &__syn_smv___e1_e2_ni::operator=(const __syn_smv___e1_e2_ni &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __syn_smv___e1_e2_ni &__syn_smv___e1_e2_ni::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __syn_smv___e1_e2_ni &__syn_smv___e1_e2_ni::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __syn_smv___noe1_noe2_noni::set() {
		// set coordinates to 0
		mv_zero(m_c, 3);

	}

	// set to scalar 
	inline void __syn_smv___noe1_noe2_noni::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;

	}


	// set to copy
	inline void __syn_smv___noe1_noe2_noni::set(const __syn_smv___noe1_noe2_noni &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 3);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];

	}

	// set to pointer to coordinates
	inline void __syn_smv___noe1_noe2_noni::set(____syn_smv___noe1_noe2_noni_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 3);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];

	}

	// set to 'coordinates specified' 
	inline void __syn_smv___noe1_noe2_noni::set(____syn_smv___noe1_noe2_noni_coordinates__, Float c_noe1, Float c_noe2, Float c_noni) {
		// set coordinates
		m_c[0] = c_noe1;
		m_c[1] = c_noe2;
		m_c[2] = c_noni;

	}





	// assign copy
	inline __syn_smv___noe1_noe2_noni &__syn_smv___noe1_noe2_noni::operator=(const __syn_smv___noe1_noe2_noni &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __syn_smv___noe1_noe2_noni &__syn_smv___noe1_noe2_noni::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __syn_smv___noe1_noe2_noni &__syn_smv___noe1_noe2_noni::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __syn_smv___no_noe1e2_noe1ni_noe2ni::set() {
		// set coordinates to 0
		mv_zero(m_c, 4);

	}

	// set to scalar 
	inline void __syn_smv___no_noe1e2_noe1ni_noe2ni::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;
		m_c[3] = (Float)0.0;

	}


	// set to copy
	inline void __syn_smv___no_noe1e2_noe1ni_noe2ni::set(const __syn_smv___no_noe1e2_noe1ni_noe2ni &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 4);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];
		m_c[3] = arg1.m_c[3];

	}

	// set to pointer to coordinates
	inline void __syn_smv___no_noe1e2_noe1ni_noe2ni::set(____syn_smv___no_noe1e2_noe1ni_noe2ni_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 4);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];
		m_c[3] = coordinates[3];

	}

	// set to 'coordinates specified' 
	inline void __syn_smv___no_noe1e2_noe1ni_noe2ni::set(____syn_smv___no_noe1e2_noe1ni_noe2ni_coordinates__, Float c_no, Float c_noe1e2, Float c_noe1ni, Float c_noe2ni) {
		// set coordinates
		m_c[0] = c_no;
		m_c[1] = c_noe1e2;
		m_c[2] = c_noe1ni;
		m_c[3] = c_noe2ni;

	}





	// assign copy
	inline __syn_smv___no_noe1e2_noe1ni_noe2ni &__syn_smv___no_noe1e2_noe1ni_noe2ni::operator=(const __syn_smv___no_noe1e2_noe1ni_noe2ni &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __syn_smv___no_noe1e2_noe1ni_noe2ni &__syn_smv___no_noe1e2_noe1ni_noe2ni::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __syn_smv___no_noe1e2_noe1ni_noe2ni &__syn_smv___no_noe1e2_noe1ni_noe2ni::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __syn_smv___scalar_e1e2_e1ni::set() {
		// set coordinates to 0
		mv_zero(m_c, 3);

	}

	// set to scalar 
	inline void __syn_smv___scalar_e1e2_e1ni::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = s ;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;

	}


	// set to copy
	inline void __syn_smv___scalar_e1e2_e1ni::set(const __syn_smv___scalar_e1e2_e1ni &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 3);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];

	}

	// set to pointer to coordinates
	inline void __syn_smv___scalar_e1e2_e1ni::set(____syn_smv___scalar_e1e2_e1ni_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 3);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];

	}

	// set to 'coordinates specified' 
	inline void __syn_smv___scalar_e1e2_e1ni::set(____syn_smv___scalar_e1e2_e1ni_coordinates__, Float c_scalar, Float c_e1e2, Float c_e1ni) {
		// set coordinates
		m_c[0] = c_scalar;
		m_c[1] = c_e1e2;
		m_c[2] = c_e1ni;

	}





	// assign copy
	inline __syn_smv___scalar_e1e2_e1ni &__syn_smv___scalar_e1e2_e1ni::operator=(const __syn_smv___scalar_e1e2_e1ni &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __syn_smv___scalar_e1e2_e1ni &__syn_smv___scalar_e1e2_e1ni::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __syn_smv___scalar_e1e2_e1ni &__syn_smv___scalar_e1e2_e1ni::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __syn_smv___e1_e2_ni_e1e2ni::set() {
		// set coordinates to 0
		mv_zero(m_c, 4);

	}

	// set to scalar 
	inline void __syn_smv___e1_e2_ni_e1e2ni::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;
		m_c[3] = (Float)0.0;

	}


	// set to copy
	inline void __syn_smv___e1_e2_ni_e1e2ni::set(const __syn_smv___e1_e2_ni_e1e2ni &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 4);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];
		m_c[3] = arg1.m_c[3];

	}

	// set to pointer to coordinates
	inline void __syn_smv___e1_e2_ni_e1e2ni::set(____syn_smv___e1_e2_ni_e1e2ni_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 4);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];
		m_c[3] = coordinates[3];

	}

	// set to 'coordinates specified' 
	inline void __syn_smv___e1_e2_ni_e1e2ni::set(____syn_smv___e1_e2_ni_e1e2ni_coordinates__, Float c_e1, Float c_e2, Float c_ni, Float c_e1e2ni) {
		// set coordinates
		m_c[0] = c_e1;
		m_c[1] = c_e2;
		m_c[2] = c_ni;
		m_c[3] = c_e1e2ni;

	}





	// assign copy
	inline __syn_smv___e1_e2_ni_e1e2ni &__syn_smv___e1_e2_ni_e1e2ni::operator=(const __syn_smv___e1_e2_ni_e1e2ni &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __syn_smv___e1_e2_ni_e1e2ni &__syn_smv___e1_e2_ni_e1e2ni::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __syn_smv___e1_e2_ni_e1e2ni &__syn_smv___e1_e2_ni_e1e2ni::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __syn_smv___scalar_e1e2_e2ni::set() {
		// set coordinates to 0
		mv_zero(m_c, 3);

	}

	// set to scalar 
	inline void __syn_smv___scalar_e1e2_e2ni::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = s ;
		m_c[1] = (Float)0.0;
		m_c[2] = (Float)0.0;

	}


	// set to copy
	inline void __syn_smv___scalar_e1e2_e2ni::set(const __syn_smv___scalar_e1e2_e2ni &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 3);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];
		m_c[2] = arg1.m_c[2];

	}

	// set to pointer to coordinates
	inline void __syn_smv___scalar_e1e2_e2ni::set(____syn_smv___scalar_e1e2_e2ni_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 3);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];
		m_c[2] = coordinates[2];

	}

	// set to 'coordinates specified' 
	inline void __syn_smv___scalar_e1e2_e2ni::set(____syn_smv___scalar_e1e2_e2ni_coordinates__, Float c_scalar, Float c_e1e2, Float c_e2ni) {
		// set coordinates
		m_c[0] = c_scalar;
		m_c[1] = c_e1e2;
		m_c[2] = c_e2ni;

	}





	// assign copy
	inline __syn_smv___scalar_e1e2_e2ni &__syn_smv___scalar_e1e2_e2ni::operator=(const __syn_smv___scalar_e1e2_e2ni &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __syn_smv___scalar_e1e2_e2ni &__syn_smv___scalar_e1e2_e2ni::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __syn_smv___scalar_e1e2_e2ni &__syn_smv___scalar_e1e2_e2ni::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __syn_smv___scalarf0_0::set() {
		// set coordinates to 0
	}

	// set to scalar 
	inline void __syn_smv___scalarf0_0::set(Float s) {
		// set coordinates 0, except for scalar (if any)

	}


	// set to copy
	inline void __syn_smv___scalarf0_0::set(const __syn_smv___scalarf0_0 &arg1) {
	}

	// set to pointer to coordinates
	inline void __syn_smv___scalarf0_0::set(____syn_smv___scalarf0_0_coordinates__, const Float *coordinates) {
		// copy coordinates
	}

	// set to 'coordinates specified' 
	inline void __syn_smv___scalarf0_0::set(____syn_smv___scalarf0_0_coordinates__) {
		// set coordinates

	}





	// assign copy
	inline __syn_smv___scalarf0_0 &__syn_smv___scalarf0_0::operator=(const __syn_smv___scalarf0_0 &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __syn_smv___scalarf0_0 &__syn_smv___scalarf0_0::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __syn_smv___scalarf0_0 &__syn_smv___scalarf0_0::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void __syn_smv___ni_e1e2ni::set() {
		// set coordinates to 0
		mv_zero(m_c, 2);

	}

	// set to scalar 
	inline void __syn_smv___ni_e1e2ni::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;

	}


	// set to copy
	inline void __syn_smv___ni_e1e2ni::set(const __syn_smv___ni_e1e2ni &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 2);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];

	}

	// set to pointer to coordinates
	inline void __syn_smv___ni_e1e2ni::set(____syn_smv___ni_e1e2ni_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 2);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];

	}

	// set to 'coordinates specified' 
	inline void __syn_smv___ni_e1e2ni::set(____syn_smv___ni_e1e2ni_coordinates__, Float c_ni, Float c_e1e2ni) {
		// set coordinates
		m_c[0] = c_ni;
		m_c[1] = c_e1e2ni;

	}





	// assign copy
	inline __syn_smv___ni_e1e2ni &__syn_smv___ni_e1e2ni::operator=(const __syn_smv___ni_e1e2ni &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __syn_smv___ni_e1e2ni &__syn_smv___ni_e1e2ni::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __syn_smv___ni_e1e2ni &__syn_smv___ni_e1e2ni::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}










	inline mv operator+=(mv& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline point operator+=(point& arg1, const point& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline vectorE2GA operator+=(vectorE2GA& arg1, const __no_ct__& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_nof1_0 operator+=(__syn_smv___e1_e2_nof1_0& arg1, const ni_t& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline normalizedPoint operator+=(normalizedPoint& arg1, const normalizedPoint& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline no_t operator+=(no_t& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline e1_t operator+=(e1_t& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline e2_t operator+=(e2_t& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline ni_t operator+=(ni_t& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline scalar operator+=(scalar& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline flatPoint operator+=(flatPoint& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline normalizedFlatPoint operator+=(normalizedFlatPoint& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline pointPair operator+=(pointPair& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline TRversorLog operator+=(TRversorLog& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline line operator+=(line& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline dualLine operator+=(dualLine& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline circle operator+=(circle& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline freeVector operator+=(freeVector& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline freeBivector operator+=(freeBivector& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline tangentVector operator+=(tangentVector& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline tangentBivector operator+=(tangentBivector& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline bivectorE2GA operator+=(bivectorE2GA& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline TRversor operator+=(TRversor& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline TRSversor operator+=(TRSversor& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline evenVersor operator+=(evenVersor& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline translator operator+=(translator& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline normalizedTranslator operator+=(normalizedTranslator& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline rotor operator+=(rotor& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline scalor operator+=(scalor& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __no_ct__ operator+=(__no_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __e1_ct__ operator+=(__e1_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __e2_ct__ operator+=(__e2_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __ni_ct__ operator+=(__ni_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __I4i_ct__ operator+=(__I4i_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __I4_ct__ operator+=(__I4_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __I2_ct__ operator+=(__I2_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __noni_ct__ operator+=(__noni_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __e2ni_ct__ operator+=(__e2ni_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __e1ni_ct__ operator+=(__e1ni_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1e2nif1_0 operator+=(__syn_smv___e1e2nif1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni_nof_1_0 operator+=(__syn_smv___e1_e2_ni_nof_1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni operator+=(__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noe1_noe2_noni operator+=(__syn_smv___scalar_noe1_noe2_noni& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni operator+=(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noe1_e1e2_e1ni operator+=(__syn_smv___scalar_noe1_e1e2_e1ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni operator+=(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noe2_e1e2_e2ni operator+=(__syn_smv___scalar_noe2_e1e2_e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni operator+=(__syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noni_e1ni_e2ni operator+=(__syn_smv___scalar_noni_e1ni_e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni operator+=(__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1ni_e2ni_nonif_1_0 operator+=(__syn_smv___e1ni_e2ni_nonif_1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalarf_1_0 operator+=(__syn_smv___scalarf_1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___nif_1_0 operator+=(__syn_smv___nif_1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___nif1_0 operator+=(__syn_smv___nif1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 operator+=(__syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni_nof2_0 operator+=(__syn_smv___e1_e2_ni_nof2_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni operator+=(__syn_smv___e1_e2_ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___noe1_noe2_noni operator+=(__syn_smv___noe1_noe2_noni& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_noe1e2_noe1ni_noe2ni operator+=(__syn_smv___no_noe1e2_noe1ni_noe2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_e1e2_e1ni operator+=(__syn_smv___scalar_e1e2_e1ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni_e1e2ni operator+=(__syn_smv___e1_e2_ni_e1e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_e1e2_e2ni operator+=(__syn_smv___scalar_e1e2_e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalarf0_0 operator+=(__syn_smv___scalarf0_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___ni_e1e2ni operator+=(__syn_smv___ni_e1e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::add(arg1, arg2));
		return arg1;
	}
	inline mv operator+(const mv& arg1, const mv& arg2) {
		return ::c2ga::add(arg1, arg2);
	}
	inline point operator+(const point& arg1, const point& arg2) {
		return ::c2ga::add(arg1, arg2);
	}
	inline __syn_smv___e1_e2_nof1_0 operator+(const vectorE2GA& arg1, const __no_ct__& arg2) {
		return ::c2ga::add(arg1, arg2);
	}
	inline normalizedPoint operator+(const __syn_smv___e1_e2_nof1_0& arg1, const ni_t& arg2) {
		return ::c2ga::add(arg1, arg2);
	}
	inline __syn_smv___e1_e2_ni_nof2_0 operator+(const normalizedPoint& arg1, const normalizedPoint& arg2) {
		return ::c2ga::add(arg1, arg2);
	}
	inline mv operator-=(mv& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni operator-=(__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& arg1, const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline normalizedPoint operator-=(normalizedPoint& arg1, const normalizedPoint& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline point operator-=(point& arg1, const normalizedPoint& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline vectorE2GA operator-=(vectorE2GA& arg1, const vectorE2GA& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline e1_t operator-=(e1_t& arg1, const e2_t& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline TRversor operator-=(TRversor& arg1, const TRversor& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline scalar operator-=(scalar& arg1, const freeVector& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline no_t operator-=(no_t& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline e2_t operator-=(e2_t& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline ni_t operator-=(ni_t& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline flatPoint operator-=(flatPoint& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline normalizedFlatPoint operator-=(normalizedFlatPoint& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline pointPair operator-=(pointPair& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline TRversorLog operator-=(TRversorLog& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline line operator-=(line& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline dualLine operator-=(dualLine& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline circle operator-=(circle& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline freeVector operator-=(freeVector& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline freeBivector operator-=(freeBivector& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline tangentVector operator-=(tangentVector& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline tangentBivector operator-=(tangentBivector& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline bivectorE2GA operator-=(bivectorE2GA& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline TRSversor operator-=(TRSversor& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline evenVersor operator-=(evenVersor& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline translator operator-=(translator& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline normalizedTranslator operator-=(normalizedTranslator& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline rotor operator-=(rotor& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline scalor operator-=(scalor& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __no_ct__ operator-=(__no_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __e1_ct__ operator-=(__e1_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __e2_ct__ operator-=(__e2_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __ni_ct__ operator-=(__ni_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __I4i_ct__ operator-=(__I4i_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __I4_ct__ operator-=(__I4_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __I2_ct__ operator-=(__I2_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __noni_ct__ operator-=(__noni_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __e2ni_ct__ operator-=(__e2ni_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __e1ni_ct__ operator-=(__e1ni_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_nof1_0 operator-=(__syn_smv___e1_e2_nof1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1e2nif1_0 operator-=(__syn_smv___e1e2nif1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni_nof_1_0 operator-=(__syn_smv___e1_e2_ni_nof_1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noe1_noe2_noni operator-=(__syn_smv___scalar_noe1_noe2_noni& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni operator-=(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noe1_e1e2_e1ni operator-=(__syn_smv___scalar_noe1_e1e2_e1ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni operator-=(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noe2_e1e2_e2ni operator-=(__syn_smv___scalar_noe2_e1e2_e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni operator-=(__syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noni_e1ni_e2ni operator-=(__syn_smv___scalar_noni_e1ni_e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni operator-=(__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1ni_e2ni_nonif_1_0 operator-=(__syn_smv___e1ni_e2ni_nonif_1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalarf_1_0 operator-=(__syn_smv___scalarf_1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___nif_1_0 operator-=(__syn_smv___nif_1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___nif1_0 operator-=(__syn_smv___nif1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 operator-=(__syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni_nof2_0 operator-=(__syn_smv___e1_e2_ni_nof2_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni operator-=(__syn_smv___e1_e2_ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___noe1_noe2_noni operator-=(__syn_smv___noe1_noe2_noni& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_noe1e2_noe1ni_noe2ni operator-=(__syn_smv___no_noe1e2_noe1ni_noe2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_e1e2_e1ni operator-=(__syn_smv___scalar_e1e2_e1ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni_e1e2ni operator-=(__syn_smv___e1_e2_ni_e1e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_e1e2_e2ni operator-=(__syn_smv___scalar_e1e2_e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalarf0_0 operator-=(__syn_smv___scalarf0_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___ni_e1e2ni operator-=(__syn_smv___ni_e1e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline mv operator-(const mv& arg1, const mv& arg2) {
		return ::c2ga::subtract(arg1, arg2);
	}
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni operator-(const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& arg1, const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& arg2) {
		return ::c2ga::subtract(arg1, arg2);
	}
	inline __syn_smv___e1_e2_ni operator-(const normalizedPoint& arg1, const normalizedPoint& arg2) {
		return ::c2ga::subtract(arg1, arg2);
	}
	inline point operator-(const point& arg1, const normalizedPoint& arg2) {
		return ::c2ga::subtract(arg1, arg2);
	}
	inline vectorE2GA operator-(const vectorE2GA& arg1, const vectorE2GA& arg2) {
		return ::c2ga::subtract(arg1, arg2);
	}
	inline vectorE2GA operator-(const e1_t& arg1, const e2_t& arg2) {
		return ::c2ga::subtract(arg1, arg2);
	}
	inline TRversor operator-(const TRversor& arg1, const TRversor& arg2) {
		return ::c2ga::subtract(arg1, arg2);
	}
	inline translator operator-(const scalar& arg1, const freeVector& arg2) {
		return ::c2ga::subtract(arg1, arg2);
	}
	inline translator operator-(float arg1, const freeVector& arg2) {
		return ::c2ga::subtract(::c2ga::scalar(arg1), arg2);
	}
	inline mv operator-(const mv& arg1) {
		return ::c2ga::negate(arg1);
	}
	inline vectorE2GA operator-(const vectorE2GA& arg1) {
		return ::c2ga::negate(arg1);
	}
	inline ni_t operator-(const ni_t& arg1) {
		return ::c2ga::negate(arg1);
	}
	inline scalar operator-(const scalar& arg1) {
		return ::c2ga::negate(arg1);
	}
	inline freeVector operator-(const freeVector& arg1) {
		return ::c2ga::negate(arg1);
	}
	inline circle operator-(const circle& arg1) {
		return ::c2ga::negate(arg1);
	}
	inline __syn_smv___nif1_0 operator-(const __syn_smv___nif_1_0& arg1) {
		return ::c2ga::negate(arg1);
	}
	inline freeBivector operator-(const freeBivector& arg1) {
		return ::c2ga::negate(arg1);
	}
	inline mv operator%=(mv& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline normalizedPoint operator%=(normalizedPoint& arg1, const normalizedPoint& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __ni_ct__ operator%=(__ni_ct__& arg1, const point& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline point operator%=(point& arg1, const point& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __ni_ct__ operator%=(__ni_ct__& arg1, const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni operator%=(__syn_smv___e1_e2_ni& arg1, const __syn_smv___e1_e2_ni& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline TRversorLog operator%=(TRversorLog& arg1, const TRversorLog& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline no_t operator%=(no_t& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline e1_t operator%=(e1_t& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline e2_t operator%=(e2_t& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline ni_t operator%=(ni_t& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline scalar operator%=(scalar& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline flatPoint operator%=(flatPoint& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline normalizedFlatPoint operator%=(normalizedFlatPoint& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline pointPair operator%=(pointPair& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline line operator%=(line& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline dualLine operator%=(dualLine& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline circle operator%=(circle& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline freeVector operator%=(freeVector& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline freeBivector operator%=(freeBivector& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline tangentVector operator%=(tangentVector& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline tangentBivector operator%=(tangentBivector& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline vectorE2GA operator%=(vectorE2GA& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline bivectorE2GA operator%=(bivectorE2GA& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline TRversor operator%=(TRversor& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline TRSversor operator%=(TRSversor& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline evenVersor operator%=(evenVersor& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline translator operator%=(translator& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline normalizedTranslator operator%=(normalizedTranslator& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline rotor operator%=(rotor& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline scalor operator%=(scalor& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __no_ct__ operator%=(__no_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __e1_ct__ operator%=(__e1_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __e2_ct__ operator%=(__e2_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __I4i_ct__ operator%=(__I4i_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __I4_ct__ operator%=(__I4_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __I2_ct__ operator%=(__I2_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __noni_ct__ operator%=(__noni_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __e2ni_ct__ operator%=(__e2ni_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __e1ni_ct__ operator%=(__e1ni_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_nof1_0 operator%=(__syn_smv___e1_e2_nof1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1e2nif1_0 operator%=(__syn_smv___e1e2nif1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni_nof_1_0 operator%=(__syn_smv___e1_e2_ni_nof_1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni operator%=(__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noe1_noe2_noni operator%=(__syn_smv___scalar_noe1_noe2_noni& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni operator%=(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noe1_e1e2_e1ni operator%=(__syn_smv___scalar_noe1_e1e2_e1ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni operator%=(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noe2_e1e2_e2ni operator%=(__syn_smv___scalar_noe2_e1e2_e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni operator%=(__syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noni_e1ni_e2ni operator%=(__syn_smv___scalar_noni_e1ni_e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni operator%=(__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1ni_e2ni_nonif_1_0 operator%=(__syn_smv___e1ni_e2ni_nonif_1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalarf_1_0 operator%=(__syn_smv___scalarf_1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___nif_1_0 operator%=(__syn_smv___nif_1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___nif1_0 operator%=(__syn_smv___nif1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 operator%=(__syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni_nof2_0 operator%=(__syn_smv___e1_e2_ni_nof2_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___noe1_noe2_noni operator%=(__syn_smv___noe1_noe2_noni& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_noe1e2_noe1ni_noe2ni operator%=(__syn_smv___no_noe1e2_noe1ni_noe2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_e1e2_e1ni operator%=(__syn_smv___scalar_e1e2_e1ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni_e1e2ni operator%=(__syn_smv___e1_e2_ni_e1e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_e1e2_e2ni operator%=(__syn_smv___scalar_e1e2_e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalarf0_0 operator%=(__syn_smv___scalarf0_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___ni_e1e2ni operator%=(__syn_smv___ni_e1e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::scp(arg1, arg2));
		return arg1;
	}
	inline scalar operator%(const mv& arg1, const mv& arg2) {
		return ::c2ga::scp(arg1, arg2);
	}
	inline scalar operator%(const normalizedPoint& arg1, const normalizedPoint& arg2) {
		return ::c2ga::scp(arg1, arg2);
	}
	inline scalar operator%(const __ni_ct__& arg1, const point& arg2) {
		return ::c2ga::scp(arg1, arg2);
	}
	inline scalar operator%(const point& arg1, const point& arg2) {
		return ::c2ga::scp(arg1, arg2);
	}
	inline scalar operator%(const __ni_ct__& arg1, const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni& arg2) {
		return ::c2ga::scp(arg1, arg2);
	}
	inline scalar operator%(const __syn_smv___e1_e2_ni& arg1, const __syn_smv___e1_e2_ni& arg2) {
		return ::c2ga::scp(arg1, arg2);
	}
	inline scalar operator%(const TRversorLog& arg1, const TRversorLog& arg2) {
		return ::c2ga::scp(arg1, arg2);
	}
	inline mv operator^=(mv& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline scalar operator^=(scalar& arg1, const __ni_ct__& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __ni_ct__ operator^=(__ni_ct__& arg1, const point& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalarf_1_0 operator^=(__syn_smv___scalarf_1_0& arg1, const __ni_ct__& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __e1_ct__ operator^=(__e1_ct__& arg1, const __e2_ct__& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __I2_ct__ operator^=(__I2_ct__& arg1, const __ni_ct__& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline TRversorLog operator^=(TRversorLog& arg1, const __ni_ct__& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline vectorE2GA operator^=(vectorE2GA& arg1, const __ni_ct__& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline pointPair operator^=(pointPair& arg1, const normalizedPoint& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __ni_ct__ operator^=(__ni_ct__& arg1, const normalizedPoint& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __ni_ct__ operator^=(__ni_ct__& arg1, const __syn_smv___e1_e2_ni& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline pointPair operator^=(pointPair& arg1, const __ni_ct__& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline normalizedPoint operator^=(normalizedPoint& arg1, const normalizedPoint& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline no_t operator^=(no_t& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline e1_t operator^=(e1_t& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline e2_t operator^=(e2_t& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline ni_t operator^=(ni_t& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline point operator^=(point& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline flatPoint operator^=(flatPoint& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline normalizedFlatPoint operator^=(normalizedFlatPoint& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline line operator^=(line& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline dualLine operator^=(dualLine& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline circle operator^=(circle& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline freeVector operator^=(freeVector& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline freeBivector operator^=(freeBivector& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline tangentVector operator^=(tangentVector& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline tangentBivector operator^=(tangentBivector& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline bivectorE2GA operator^=(bivectorE2GA& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline TRversor operator^=(TRversor& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline TRSversor operator^=(TRSversor& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline evenVersor operator^=(evenVersor& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline translator operator^=(translator& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline normalizedTranslator operator^=(normalizedTranslator& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline rotor operator^=(rotor& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline scalor operator^=(scalor& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __no_ct__ operator^=(__no_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __e2_ct__ operator^=(__e2_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __I4i_ct__ operator^=(__I4i_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __I4_ct__ operator^=(__I4_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __noni_ct__ operator^=(__noni_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __e2ni_ct__ operator^=(__e2ni_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __e1ni_ct__ operator^=(__e1ni_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_nof1_0 operator^=(__syn_smv___e1_e2_nof1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1e2nif1_0 operator^=(__syn_smv___e1e2nif1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni_nof_1_0 operator^=(__syn_smv___e1_e2_ni_nof_1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni operator^=(__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noe1_noe2_noni operator^=(__syn_smv___scalar_noe1_noe2_noni& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni operator^=(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noe1_e1e2_e1ni operator^=(__syn_smv___scalar_noe1_e1e2_e1ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni operator^=(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noe2_e1e2_e2ni operator^=(__syn_smv___scalar_noe2_e1e2_e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni operator^=(__syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noni_e1ni_e2ni operator^=(__syn_smv___scalar_noni_e1ni_e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni operator^=(__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1ni_e2ni_nonif_1_0 operator^=(__syn_smv___e1ni_e2ni_nonif_1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___nif_1_0 operator^=(__syn_smv___nif_1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___nif1_0 operator^=(__syn_smv___nif1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 operator^=(__syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni_nof2_0 operator^=(__syn_smv___e1_e2_ni_nof2_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni operator^=(__syn_smv___e1_e2_ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___noe1_noe2_noni operator^=(__syn_smv___noe1_noe2_noni& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_noe1e2_noe1ni_noe2ni operator^=(__syn_smv___no_noe1e2_noe1ni_noe2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_e1e2_e1ni operator^=(__syn_smv___scalar_e1e2_e1ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni_e1e2ni operator^=(__syn_smv___e1_e2_ni_e1e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_e1e2_e2ni operator^=(__syn_smv___scalar_e1e2_e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalarf0_0 operator^=(__syn_smv___scalarf0_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___ni_e1e2ni operator^=(__syn_smv___ni_e1e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::op(arg1, arg2));
		return arg1;
	}
	inline mv operator^(const mv& arg1, const mv& arg2) {
		return ::c2ga::op(arg1, arg2);
	}
	inline ni_t operator^(const scalar& arg1, const __ni_ct__& arg2) {
		return ::c2ga::op(arg1, arg2);
	}
	inline ni_t operator^(float arg1, const __ni_ct__& arg2) {
		return ::c2ga::op(::c2ga::scalar(arg1), arg2);
	}
	inline flatPoint operator^(const __ni_ct__& arg1, const point& arg2) {
		return ::c2ga::op(arg1, arg2);
	}
	inline __syn_smv___nif_1_0 operator^(const __syn_smv___scalarf_1_0& arg1, const __ni_ct__& arg2) {
		return ::c2ga::op(arg1, arg2);
	}
	inline __I2_ct__ operator^(const __e1_ct__& arg1, const __e2_ct__& arg2) {
		return ::c2ga::op(arg1, arg2);
	}
	inline __syn_smv___e1e2nif1_0 operator^(const __I2_ct__& arg1, const __ni_ct__& arg2) {
		return ::c2ga::op(arg1, arg2);
	}
	inline freeBivector operator^(const TRversorLog& arg1, const __ni_ct__& arg2) {
		return ::c2ga::op(arg1, arg2);
	}
	inline freeVector operator^(const vectorE2GA& arg1, const __ni_ct__& arg2) {
		return ::c2ga::op(arg1, arg2);
	}
	inline circle operator^(const pointPair& arg1, const normalizedPoint& arg2) {
		return ::c2ga::op(arg1, arg2);
	}
	inline __syn_smv___e1ni_e2ni_nonif_1_0 operator^(const __ni_ct__& arg1, const normalizedPoint& arg2) {
		return ::c2ga::op(arg1, arg2);
	}
	inline freeVector operator^(const __ni_ct__& arg1, const __syn_smv___e1_e2_ni& arg2) {
		return ::c2ga::op(arg1, arg2);
	}
	inline line operator^(const pointPair& arg1, const __ni_ct__& arg2) {
		return ::c2ga::op(arg1, arg2);
	}
	inline pointPair operator^(const normalizedPoint& arg1, const normalizedPoint& arg2) {
		return ::c2ga::op(arg1, arg2);
	}
	inline mv operator*=(mv& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline freeVector operator*=(freeVector& arg1, const __syn_smv___e1_e2_ni& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline circle operator*=(circle& arg1, const TRversorLog& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline scalar operator*=(scalar& arg1, const scalar& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline scalar operator*=(scalar& arg1, float arg2) {
		arg1.set(::c2ga::gp(arg1, ::c2ga::scalar(arg2)));
		return arg1;
	}
	inline __syn_smv___scalar_noe1_noe2_noni operator*=(__syn_smv___scalar_noe1_noe2_noni& arg1, const point& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni operator*=(__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni& arg1, const scalar& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni operator*=(__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni& arg1, float arg2) {
		arg1.set(::c2ga::gp(arg1, ::c2ga::scalar(arg2)));
		return arg1;
	}
	inline __syn_smv___scalar_e1e2_e1ni operator*=(__syn_smv___scalar_e1e2_e1ni& arg1, const __syn_smv___e1_e2_ni& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noe1_e1e2_e1ni operator*=(__syn_smv___scalar_noe1_e1e2_e1ni& arg1, const point& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline point operator*=(point& arg1, const point& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline scalar operator*=(scalar& arg1, const normalizedPoint& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni operator*=(__syn_smv___e1_e2_ni& arg1, const __e2_ct__& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 operator*=(__syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0& arg1, const translator& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline scalar operator*=(scalar& arg1, const vectorE2GA& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline point operator*=(point& arg1, const scalar& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline point operator*=(point& arg1, float arg2) {
		arg1.set(::c2ga::gp(arg1, ::c2ga::scalar(arg2)));
		return arg1;
	}
	inline point operator*=(point& arg1, const __e2_ct__& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline normalizedTranslator operator*=(normalizedTranslator& arg1, const normalizedPoint& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline point operator*=(point& arg1, const __no_ct__& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline circle operator*=(circle& arg1, const circle& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline scalar operator*=(scalar& arg1, const __ni_ct__& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noe2_e1e2_e2ni operator*=(__syn_smv___scalar_noe2_e1e2_e2ni& arg1, const point& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni operator*=(__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& arg1, const scalar& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni operator*=(__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& arg1, float arg2) {
		arg1.set(::c2ga::gp(arg1, ::c2ga::scalar(arg2)));
		return arg1;
	}
	inline normalizedPoint operator*=(normalizedPoint& arg1, const scalar& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline normalizedPoint operator*=(normalizedPoint& arg1, float arg2) {
		arg1.set(::c2ga::gp(arg1, ::c2ga::scalar(arg2)));
		return arg1;
	}
	inline point operator*=(point& arg1, const __ni_ct__& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noni_e1ni_e2ni operator*=(__syn_smv___scalar_noni_e1ni_e2ni& arg1, const point& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni operator*=(__syn_smv___e1_e2_ni& arg1, const __syn_smv___e1_e2_ni& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni operator*=(__syn_smv___e1_e2_ni& arg1, const __no_ct__& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline point operator*=(point& arg1, const __e1_ct__& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline scalar operator*=(scalar& arg1, const __e1_ct__& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline scalar operator*=(scalar& arg1, const __syn_smv___e1_e2_ni_nof2_0& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_e1e2_e2ni operator*=(__syn_smv___scalar_e1e2_e2ni& arg1, const __syn_smv___e1_e2_ni& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni operator*=(__syn_smv___e1_e2_ni& arg1, const __ni_ct__& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noe1_noe2_noni operator*=(__syn_smv___scalar_noe1_noe2_noni& arg1, const __syn_smv___e1_e2_ni& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline scalar operator*=(scalar& arg1, const __e2_ct__& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni operator*=(__syn_smv___e1_e2_ni& arg1, const __e1_ct__& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline no_t operator*=(no_t& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline e1_t operator*=(e1_t& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline e2_t operator*=(e2_t& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline ni_t operator*=(ni_t& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline flatPoint operator*=(flatPoint& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline normalizedFlatPoint operator*=(normalizedFlatPoint& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline pointPair operator*=(pointPair& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline TRversorLog operator*=(TRversorLog& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline line operator*=(line& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline dualLine operator*=(dualLine& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline freeBivector operator*=(freeBivector& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline tangentVector operator*=(tangentVector& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline tangentBivector operator*=(tangentBivector& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline vectorE2GA operator*=(vectorE2GA& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline bivectorE2GA operator*=(bivectorE2GA& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline TRversor operator*=(TRversor& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline TRSversor operator*=(TRSversor& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline evenVersor operator*=(evenVersor& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline translator operator*=(translator& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline rotor operator*=(rotor& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline scalor operator*=(scalor& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __no_ct__ operator*=(__no_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __e1_ct__ operator*=(__e1_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __e2_ct__ operator*=(__e2_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __ni_ct__ operator*=(__ni_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __I4i_ct__ operator*=(__I4i_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __I4_ct__ operator*=(__I4_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __I2_ct__ operator*=(__I2_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __noni_ct__ operator*=(__noni_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __e2ni_ct__ operator*=(__e2ni_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __e1ni_ct__ operator*=(__e1ni_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_nof1_0 operator*=(__syn_smv___e1_e2_nof1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1e2nif1_0 operator*=(__syn_smv___e1e2nif1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni_nof_1_0 operator*=(__syn_smv___e1_e2_ni_nof_1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni operator*=(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni operator*=(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni operator*=(__syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1ni_e2ni_nonif_1_0 operator*=(__syn_smv___e1ni_e2ni_nonif_1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalarf_1_0 operator*=(__syn_smv___scalarf_1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___nif_1_0 operator*=(__syn_smv___nif_1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___nif1_0 operator*=(__syn_smv___nif1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni_nof2_0 operator*=(__syn_smv___e1_e2_ni_nof2_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___noe1_noe2_noni operator*=(__syn_smv___noe1_noe2_noni& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_noe1e2_noe1ni_noe2ni operator*=(__syn_smv___no_noe1e2_noe1ni_noe2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni_e1e2ni operator*=(__syn_smv___e1_e2_ni_e1e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalarf0_0 operator*=(__syn_smv___scalarf0_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___ni_e1e2ni operator*=(__syn_smv___ni_e1e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::gp(arg1, arg2));
		return arg1;
	}
	inline mv operator*(const mv& arg1, const mv& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline __syn_smv___ni_e1e2ni operator*(const freeVector& arg1, const __syn_smv___e1_e2_ni& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni operator*(const circle& arg1, const TRversorLog& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline scalar operator*(const scalar& arg1, const scalar& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline scalar operator*(float arg1, const scalar& arg2) {
		return ::c2ga::gp(::c2ga::scalar(arg1), arg2);
	}
	inline scalar operator*(const scalar& arg1, float arg2) {
		return ::c2ga::gp(arg1, ::c2ga::scalar(arg2));
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni operator*(const __syn_smv___scalar_noe1_noe2_noni& arg1, const point& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni operator*(const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni& arg1, const scalar& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni operator*(const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni& arg1, float arg2) {
		return ::c2ga::gp(arg1, ::c2ga::scalar(arg2));
	}
	inline __syn_smv___e1_e2_ni_e1e2ni operator*(const __syn_smv___scalar_e1e2_e1ni& arg1, const __syn_smv___e1_e2_ni& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni operator*(const __syn_smv___scalar_noe1_e1e2_e1ni& arg1, const point& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni operator*(const point& arg1, const point& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline point operator*(const scalar& arg1, const normalizedPoint& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline point operator*(float arg1, const normalizedPoint& arg2) {
		return ::c2ga::gp(::c2ga::scalar(arg1), arg2);
	}
	inline __syn_smv___scalar_e1e2_e2ni operator*(const __syn_smv___e1_e2_ni& arg1, const __e2_ct__& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni operator*(const __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0& arg1, const translator& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline vectorE2GA operator*(const scalar& arg1, const vectorE2GA& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline vectorE2GA operator*(float arg1, const vectorE2GA& arg2) {
		return ::c2ga::gp(::c2ga::scalar(arg1), arg2);
	}
	inline point operator*(const point& arg1, const scalar& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline point operator*(const point& arg1, float arg2) {
		return ::c2ga::gp(arg1, ::c2ga::scalar(arg2));
	}
	inline __syn_smv___scalar_noe2_e1e2_e2ni operator*(const point& arg1, const __e2_ct__& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 operator*(const normalizedTranslator& arg1, const normalizedPoint& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline __syn_smv___scalar_noe1_noe2_noni operator*(const point& arg1, const __no_ct__& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni operator*(const circle& arg1, const circle& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline ni_t operator*(const scalar& arg1, const __ni_ct__& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline ni_t operator*(float arg1, const __ni_ct__& arg2) {
		return ::c2ga::gp(::c2ga::scalar(arg1), arg2);
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni operator*(const __syn_smv___scalar_noe2_e1e2_e2ni& arg1, const point& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni operator*(const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& arg1, const scalar& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni operator*(const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& arg1, float arg2) {
		return ::c2ga::gp(arg1, ::c2ga::scalar(arg2));
	}
	inline point operator*(const normalizedPoint& arg1, const scalar& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline point operator*(const normalizedPoint& arg1, float arg2) {
		return ::c2ga::gp(arg1, ::c2ga::scalar(arg2));
	}
	inline __syn_smv___scalar_noni_e1ni_e2ni operator*(const point& arg1, const __ni_ct__& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni operator*(const __syn_smv___scalar_noni_e1ni_e2ni& arg1, const point& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline TRversor operator*(const __syn_smv___e1_e2_ni& arg1, const __syn_smv___e1_e2_ni& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline __syn_smv___scalar_noe1_noe2_noni operator*(const __syn_smv___e1_e2_ni& arg1, const __no_ct__& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline __syn_smv___scalar_noe1_e1e2_e1ni operator*(const point& arg1, const __e1_ct__& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline e1_t operator*(const scalar& arg1, const __e1_ct__& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline e1_t operator*(float arg1, const __e1_ct__& arg2) {
		return ::c2ga::gp(::c2ga::scalar(arg1), arg2);
	}
	inline point operator*(const scalar& arg1, const __syn_smv___e1_e2_ni_nof2_0& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline point operator*(float arg1, const __syn_smv___e1_e2_ni_nof2_0& arg2) {
		return ::c2ga::gp(::c2ga::scalar(arg1), arg2);
	}
	inline __syn_smv___e1_e2_ni_e1e2ni operator*(const __syn_smv___scalar_e1e2_e2ni& arg1, const __syn_smv___e1_e2_ni& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline freeVector operator*(const __syn_smv___e1_e2_ni& arg1, const __ni_ct__& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni operator*(const __syn_smv___scalar_noe1_noe2_noni& arg1, const __syn_smv___e1_e2_ni& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline e2_t operator*(const scalar& arg1, const __e2_ct__& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline e2_t operator*(float arg1, const __e2_ct__& arg2) {
		return ::c2ga::gp(::c2ga::scalar(arg1), arg2);
	}
	inline __syn_smv___scalar_e1e2_e1ni operator*(const __syn_smv___e1_e2_ni& arg1, const __e1_ct__& arg2) {
		return ::c2ga::gp(arg1, arg2);
	}
	inline mv operator<<=(mv& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __no_ct__ operator<<=(__no_ct__& arg1, const freeVector& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni operator<<=(__syn_smv___e1_e2_ni& arg1, const normalizedPoint& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __ni_ct__ operator<<=(__ni_ct__& arg1, const line& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline circle operator<<=(circle& arg1, const __syn_smv___e1e2nif1_0& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __ni_ct__ operator<<=(__ni_ct__& arg1, const normalizedPoint& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __ni_ct__ operator<<=(__ni_ct__& arg1, const point& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline pointPair operator<<=(pointPair& arg1, const line& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __ni_ct__ operator<<=(__ni_ct__& arg1, const circle& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __ni_ct__ operator<<=(__ni_ct__& arg1, const __syn_smv___e1_e2_ni& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline normalizedPoint operator<<=(normalizedPoint& arg1, const line& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __no_ct__ operator<<=(__no_ct__& arg1, const freeBivector& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline no_t operator<<=(no_t& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline e1_t operator<<=(e1_t& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline e2_t operator<<=(e2_t& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline ni_t operator<<=(ni_t& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline scalar operator<<=(scalar& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline point operator<<=(point& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline flatPoint operator<<=(flatPoint& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline normalizedFlatPoint operator<<=(normalizedFlatPoint& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline TRversorLog operator<<=(TRversorLog& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline line operator<<=(line& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline dualLine operator<<=(dualLine& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline freeVector operator<<=(freeVector& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline freeBivector operator<<=(freeBivector& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline tangentVector operator<<=(tangentVector& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline tangentBivector operator<<=(tangentBivector& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline vectorE2GA operator<<=(vectorE2GA& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline bivectorE2GA operator<<=(bivectorE2GA& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline TRversor operator<<=(TRversor& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline TRSversor operator<<=(TRSversor& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline evenVersor operator<<=(evenVersor& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline translator operator<<=(translator& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline normalizedTranslator operator<<=(normalizedTranslator& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline rotor operator<<=(rotor& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline scalor operator<<=(scalor& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __e1_ct__ operator<<=(__e1_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __e2_ct__ operator<<=(__e2_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __I4i_ct__ operator<<=(__I4i_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __I4_ct__ operator<<=(__I4_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __I2_ct__ operator<<=(__I2_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __noni_ct__ operator<<=(__noni_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __e2ni_ct__ operator<<=(__e2ni_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __e1ni_ct__ operator<<=(__e1ni_ct__& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_nof1_0 operator<<=(__syn_smv___e1_e2_nof1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1e2nif1_0 operator<<=(__syn_smv___e1e2nif1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni_nof_1_0 operator<<=(__syn_smv___e1_e2_ni_nof_1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni operator<<=(__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noe1_noe2_noni operator<<=(__syn_smv___scalar_noe1_noe2_noni& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni operator<<=(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noe1_e1e2_e1ni operator<<=(__syn_smv___scalar_noe1_e1e2_e1ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni operator<<=(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noe2_e1e2_e2ni operator<<=(__syn_smv___scalar_noe2_e1e2_e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni operator<<=(__syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_noni_e1ni_e2ni operator<<=(__syn_smv___scalar_noni_e1ni_e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni operator<<=(__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1ni_e2ni_nonif_1_0 operator<<=(__syn_smv___e1ni_e2ni_nonif_1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalarf_1_0 operator<<=(__syn_smv___scalarf_1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___nif_1_0 operator<<=(__syn_smv___nif_1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___nif1_0 operator<<=(__syn_smv___nif1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 operator<<=(__syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni_nof2_0 operator<<=(__syn_smv___e1_e2_ni_nof2_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___noe1_noe2_noni operator<<=(__syn_smv___noe1_noe2_noni& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___no_noe1e2_noe1ni_noe2ni operator<<=(__syn_smv___no_noe1e2_noe1ni_noe2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_e1e2_e1ni operator<<=(__syn_smv___scalar_e1e2_e1ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___e1_e2_ni_e1e2ni operator<<=(__syn_smv___e1_e2_ni_e1e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalar_e1e2_e2ni operator<<=(__syn_smv___scalar_e1e2_e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___scalarf0_0 operator<<=(__syn_smv___scalarf0_0& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __syn_smv___ni_e1e2ni operator<<=(__syn_smv___ni_e1e2ni& arg1, const mv& arg2) {
		arg1.set(::c2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline mv operator<<(const mv& arg1, const mv& arg2) {
		return ::c2ga::lcont(arg1, arg2);
	}
	inline vectorE2GA operator<<(const __no_ct__& arg1, const freeVector& arg2) {
		return ::c2ga::lcont(arg1, arg2);
	}
	inline scalar operator<<(const __syn_smv___e1_e2_ni& arg1, const normalizedPoint& arg2) {
		return ::c2ga::lcont(arg1, arg2);
	}
	inline freeVector operator<<(const __ni_ct__& arg1, const line& arg2) {
		return ::c2ga::lcont(arg1, arg2);
	}
	inline scalar operator<<(const circle& arg1, const __syn_smv___e1e2nif1_0& arg2) {
		return ::c2ga::lcont(arg1, arg2);
	}
	inline __syn_smv___scalarf_1_0 operator<<(const __ni_ct__& arg1, const normalizedPoint& arg2) {
		return ::c2ga::lcont(arg1, arg2);
	}
	inline scalar operator<<(const __ni_ct__& arg1, const point& arg2) {
		return ::c2ga::lcont(arg1, arg2);
	}
	inline point operator<<(const pointPair& arg1, const line& arg2) {
		return ::c2ga::lcont(arg1, arg2);
	}
	inline TRversorLog operator<<(const __ni_ct__& arg1, const circle& arg2) {
		return ::c2ga::lcont(arg1, arg2);
	}
	inline __syn_smv___scalarf0_0 operator<<(const __ni_ct__& arg1, const __syn_smv___e1_e2_ni& arg2) {
		return ::c2ga::lcont(arg1, arg2);
	}
	inline pointPair operator<<(const normalizedPoint& arg1, const line& arg2) {
		return ::c2ga::lcont(arg1, arg2);
	}
	inline bivectorE2GA operator<<(const __no_ct__& arg1, const freeBivector& arg2) {
		return ::c2ga::lcont(arg1, arg2);
	}
	inline mv operator*(const mv& arg1) {
		return ::c2ga::dual(arg1);
	}
	inline circle operator*(const point& arg1) {
		return ::c2ga::dual(arg1);
	}
	inline line operator*(const __syn_smv___e1_e2_ni& arg1) {
		return ::c2ga::dual(arg1);
	}
	inline __syn_smv___e1_e2_ni operator*(const line& arg1) {
		return ::c2ga::dual(arg1);
	}
	inline mv operator!(const mv& arg1) {
		return ::c2ga::inverse(arg1);
	}
	inline TRversorLog operator!(const TRversorLog& arg1) {
		return ::c2ga::inverse(arg1);
	}
	inline scalar operator!(const scalar& arg1) {
		return ::c2ga::inverse(arg1);
	}
	inline point operator!(const point& arg1) {
		return ::c2ga::inverse(arg1);
	}
	inline line operator!(const line& arg1) {
		return ::c2ga::inverse(arg1);
	}
	inline __syn_smv___e1_e2_ni operator!(const __syn_smv___e1_e2_ni& arg1) {
		return ::c2ga::inverse(arg1);
	}
	inline scalar operator!(const __syn_smv___scalarf_1_0& arg1) {
		return ::c2ga::inverse(arg1);
	}
	inline translator operator!(const normalizedTranslator& arg1) {
		return ::c2ga::inverse(arg1);
	}
	inline mv operator~(const mv& arg1) {
		return ::c2ga::reverse(arg1);
	}
	inline point operator~(const point& arg1) {
		return ::c2ga::reverse(arg1);
	}
	inline normalizedPoint operator~(const normalizedPoint& arg1) {
		return ::c2ga::reverse(arg1);
	}
	inline __syn_smv___e1_e2_ni operator~(const __syn_smv___e1_e2_ni& arg1) {
		return ::c2ga::reverse(arg1);
	}


	// G2 functions:
	inline __syn_smv___ni_e1e2ni gp(const freeVector& x, const __syn_smv___e1_e2_ni& y) {
		return __syn_smv___ni_e1e2ni(__syn_smv___ni_e1e2ni_ni_e1e2ni, ((-1.0f * x.m_c[0] * y.m_c[0]) + (-1.0f * x.m_c[1] * y.m_c[1])), ((-1.0f * x.m_c[0] * y.m_c[1]) + (x.m_c[1] * y.m_c[0])));
	}
	inline scalar norm_e(const __syn_smv___scalarf0_0& x) {
		scalar e2;
		e2.m_c[0] = 0.0f;
		return scalar(scalar_scalar, sqrt(e2.m_c[0]));
	}
	inline scalar norm_r(const bivectorE2GA& x) {
		scalar r2;
		r2.m_c[0] = (x.m_c[0] * x.m_c[0]);
		return scalar(scalar_scalar, ((((r2.m_c[0] < (char)0)) ? (char)-1 : ((((r2.m_c[0] > (char)0)) ? (char)1 : (char)0))) * sqrt((((r2.m_c[0] < (char)0)) ? ((-r2.m_c[0])) : (r2.m_c[0])))));
	}
	inline TRversorLog inverse(const TRversorLog& x) {
		scalar n;
		n.m_c[0] = (x.m_c[0] * x.m_c[0]);
		scalar in;
		in.m_c[0] = ((char)1 / n.m_c[0]);
		return TRversorLog(TRversorLog_e1e2_e1ni_e2ni, (-1.0f * x.m_c[0] * in.m_c[0]), (-1.0f * x.m_c[1] * in.m_c[0]), (-1.0f * x.m_c[2] * in.m_c[0]));
	}
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni gp(const circle& x, const TRversorLog& y) {
		return __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni(__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni_no_e1_e2_ni_noe1ni_noe2ni_e1e2ni, (-1.0f * x.m_c[3] * y.m_c[0]), (x.m_c[3] * y.m_c[2]), (-1.0f * x.m_c[3] * y.m_c[1]), ((-1.0f * x.m_c[0] * y.m_c[0]) + (-1.0f * x.m_c[2] * y.m_c[2]) + (-1.0f * x.m_c[1] * y.m_c[1])), ((-1.0f * x.m_c[2] * y.m_c[0]) + (x.m_c[3] * y.m_c[2])), ((-1.0f * x.m_c[3] * y.m_c[1]) + (x.m_c[1] * y.m_c[0])), ((x.m_c[2] * y.m_c[1]) + (-1.0f * x.m_c[1] * y.m_c[2])));
	}
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni subtract(const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& x, const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& y) {
		return __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni(__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni_scalar_noe1_noe2_e1e2_noni_e1ni_e2ni, ((-1.0f * y.m_c[0]) + x.m_c[0]), ((-1.0f * y.m_c[1]) + x.m_c[1]), ((-1.0f * y.m_c[2]) + x.m_c[2]), (x.m_c[3] + (-1.0f * y.m_c[3])), ((-1.0f * y.m_c[4]) + x.m_c[4]), ((-1.0f * y.m_c[5]) + x.m_c[5]), (x.m_c[6] + (-1.0f * y.m_c[6])));
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni gpEM(const __syn_smv___scalar_noe2_e1e2_e2ni& x, const __syn_smv___e1_e2_ni_nof_1_0& y) {
		return __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni(__syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni_no_e1_e2_noe1e2_ni_noe2ni_e1e2ni, ((x.m_c[1] * y.m_c[1]) + (-1.0f * x.m_c[0])), ((x.m_c[0] * y.m_c[0]) + (x.m_c[2] * y.m_c[1])), ((x.m_c[3] * y.m_c[2]) + (x.m_c[0] * y.m_c[1]) + x.m_c[1] + (-1.0f * x.m_c[2] * y.m_c[0])), ((-1.0f * x.m_c[2]) + (-1.0f * x.m_c[1] * y.m_c[0])), ((-1.0f * x.m_c[3] * y.m_c[1]) + (x.m_c[0] * y.m_c[2])), ((-1.0f * x.m_c[3]) + (x.m_c[1] * y.m_c[2])), ((x.m_c[3] * y.m_c[0]) + (x.m_c[2] * y.m_c[2])));
	}
	inline __syn_smv___e1_e2_ni subtract(const normalizedPoint& x, const normalizedPoint& y) {
		return __syn_smv___e1_e2_ni(__syn_smv___e1_e2_ni_e1_e2_ni, ((-1.0f * y.m_c[0]) + x.m_c[0]), (x.m_c[1] + (-1.0f * y.m_c[1])), (x.m_c[2] + (-1.0f * y.m_c[2])));
	}
	inline scalar gp(const scalar& x, const scalar& y) {
		return scalar(scalar_scalar, (x.m_c[0] * y.m_c[0]));
	}
	inline scalar inverse(const scalar& x) {
		scalar n;
		n.m_c[0] = (x.m_c[0] * x.m_c[0]);
		scalar in;
		in.m_c[0] = ((char)1 / n.m_c[0]);
		return scalar(scalar_scalar, (x.m_c[0] * in.m_c[0]));
	}
	inline point inverse(const point& x) {
		scalar n;
		n.m_c[0] = ((x.m_c[2] * x.m_c[2]) + (-1.0f * x.m_c[3] * x.m_c[0]) + (x.m_c[1] * x.m_c[1]) + (-1.0f * x.m_c[0] * x.m_c[3]));
		scalar in;
		in.m_c[0] = ((char)1 / n.m_c[0]);
		return point(point_no_e1_e2_ni, (x.m_c[0] * in.m_c[0]), (x.m_c[1] * in.m_c[0]), (x.m_c[2] * in.m_c[0]), (x.m_c[3] * in.m_c[0]));
	}
	inline ni_t op(const scalar& x, const __ni_ct__& y) {
		return ni_t(ni_t_ni, x.m_c[0]);
	}
	inline scalar scp(const normalizedPoint& x, const normalizedPoint& y) {
		return scalar(scalar_scalar, ((-1.0f * x.m_c[2]) + (x.m_c[1] * y.m_c[1]) + (-1.0f * y.m_c[2]) + (x.m_c[0] * y.m_c[0])));
	}
	inline __syn_smv___e1_e2_ni gradeInvolution(const __syn_smv___e1_e2_ni& x) {
		return __syn_smv___e1_e2_ni(__syn_smv___e1_e2_ni_e1_e2_ni, (-1.0f * x.m_c[0]), (-1.0f * x.m_c[1]), (-1.0f * x.m_c[2]));
	}
	inline vectorE2GA lcont(const __no_ct__& x, const freeVector& y) {
		return vectorE2GA(vectorE2GA_e1_e2, y.m_c[0], y.m_c[1]);
	}
	inline vectorE2GA negate(const vectorE2GA& x) {
		return vectorE2GA(vectorE2GA_e1_e2, (-1.0f * x.m_c[0]), (-1.0f * x.m_c[1]));
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni gpEM(const __syn_smv___scalar_noe2_e1e2_e2ni& x, const point& y) {
		return __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni(__syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni_no_e1_e2_noe1e2_ni_noe2ni_e1e2ni, ((x.m_c[0] * y.m_c[0]) + (x.m_c[1] * y.m_c[2])), ((x.m_c[2] * y.m_c[2]) + (x.m_c[0] * y.m_c[1])), ((-1.0f * x.m_c[1] * y.m_c[0]) + (x.m_c[3] * y.m_c[3]) + (-1.0f * x.m_c[2] * y.m_c[1]) + (x.m_c[0] * y.m_c[2])), ((x.m_c[2] * y.m_c[0]) + (-1.0f * x.m_c[1] * y.m_c[1])), ((x.m_c[0] * y.m_c[3]) + (-1.0f * x.m_c[3] * y.m_c[2])), ((x.m_c[3] * y.m_c[0]) + (x.m_c[1] * y.m_c[3])), ((x.m_c[2] * y.m_c[3]) + (x.m_c[3] * y.m_c[1])));
	}
	inline ni_t negate(const ni_t& x) {
		return ni_t(ni_t_ni, (-1.0f * x.m_c[0]));
	}
	inline flatPoint op(const __ni_ct__& x, const point& y) {
		return flatPoint(flatPoint_e1ni_e2ni_noni, (-1.0f * y.m_c[1]), (-1.0f * y.m_c[2]), (-1.0f * y.m_c[0]));
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni gp(const __syn_smv___scalar_noe1_noe2_noni& x, const point& y) {
		return __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni_no_e1_e2_noe1e2_ni_noe1ni_noe2ni, ((-1.0f * x.m_c[3] * y.m_c[0]) + (x.m_c[2] * y.m_c[2]) + (x.m_c[0] * y.m_c[0]) + (x.m_c[1] * y.m_c[1])), ((x.m_c[0] * y.m_c[1]) + (x.m_c[1] * y.m_c[3])), ((x.m_c[0] * y.m_c[2]) + (x.m_c[2] * y.m_c[3])), ((x.m_c[1] * y.m_c[2]) + (-1.0f * x.m_c[2] * y.m_c[1])), ((x.m_c[3] * y.m_c[3]) + (x.m_c[0] * y.m_c[3])), ((x.m_c[1] * y.m_c[3]) + (-1.0f * x.m_c[3] * y.m_c[1])), ((-1.0f * x.m_c[3] * y.m_c[2]) + (x.m_c[2] * y.m_c[3])));
	}
	inline scalar scp(const __ni_ct__& x, const point& y) {
		return scalar(scalar_scalar, (-1.0f * y.m_c[0]));
	}
	inline circle dual(const point& x) {
		return circle(circle_e1e2ni_noe1ni_noe2ni_noe1e2, x.m_c[3], (-1.0f * x.m_c[2]), x.m_c[1], (-1.0f * x.m_c[0]));
	}
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni gp(const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni& x, const scalar& y) {
		return __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni(__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni_no_e1_e2_ni_noe1ni_noe2ni_e1e2ni, (x.m_c[0] * y.m_c[0]), (x.m_c[1] * y.m_c[0]), (x.m_c[2] * y.m_c[0]), (x.m_c[3] * y.m_c[0]), (x.m_c[4] * y.m_c[0]), (x.m_c[5] * y.m_c[0]), (x.m_c[6] * y.m_c[0]));
	}
	inline scalar norm_r2(const normalizedPoint& x) {
		return scalar(scalar_scalar, ((x.m_c[1] * x.m_c[1]) + (x.m_c[0] * x.m_c[0])));
	}
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni gpEM(const __syn_smv___e1_e2_ni_nof_1_0& x, const point& y) {
		return __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni(__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni_scalar_noe1_noe2_e1e2_noni_e1ni_e2ni, ((x.m_c[2] * y.m_c[3]) + (-1.0f * y.m_c[0]) + (x.m_c[0] * y.m_c[1]) + (x.m_c[1] * y.m_c[2])), ((-1.0f * y.m_c[1]) + (-1.0f * x.m_c[0] * y.m_c[0])), ((-1.0f * y.m_c[2]) + (-1.0f * x.m_c[1] * y.m_c[0])), ((-1.0f * x.m_c[1] * y.m_c[1]) + (x.m_c[0] * y.m_c[2])), ((-1.0f * y.m_c[3]) + (-1.0f * x.m_c[2] * y.m_c[0])), ((-1.0f * x.m_c[2] * y.m_c[1]) + (x.m_c[0] * y.m_c[3])), ((-1.0f * x.m_c[2] * y.m_c[2]) + (x.m_c[1] * y.m_c[3])));
	}
	inline line inverse(const line& x) {
		scalar n;
		n.m_c[0] = ((-1.0f * x.m_c[2] * x.m_c[2]) + (-1.0f * x.m_c[1] * x.m_c[1]));
		scalar in;
		in.m_c[0] = ((char)1 / n.m_c[0]);
		return line(line_e1e2ni_e1noni_e2noni, (-1.0f * x.m_c[0] * in.m_c[0]), (-1.0f * x.m_c[1] * in.m_c[0]), (-1.0f * x.m_c[2] * in.m_c[0]));
	}
	inline __syn_smv___e1_e2_ni_e1e2ni gp(const __syn_smv___scalar_e1e2_e1ni& x, const __syn_smv___e1_e2_ni& y) {
		return __syn_smv___e1_e2_ni_e1e2ni(__syn_smv___e1_e2_ni_e1e2ni_e1_e2_ni_e1e2ni, ((x.m_c[0] * y.m_c[0]) + (x.m_c[1] * y.m_c[1])), ((x.m_c[0] * y.m_c[1]) + (-1.0f * x.m_c[1] * y.m_c[0])), ((x.m_c[0] * y.m_c[2]) + (-1.0f * x.m_c[2] * y.m_c[0])), ((x.m_c[1] * y.m_c[2]) + (-1.0f * x.m_c[2] * y.m_c[1])));
	}
	inline scalar negate(const scalar& x) {
		return scalar(scalar_scalar, (-1.0f * x.m_c[0]));
	}
	inline scalar norm_e(const flatPoint& x) {
		scalar e2;
		e2.m_c[0] = ((x.m_c[1] * x.m_c[1]) + (x.m_c[2] * x.m_c[2]) + (x.m_c[0] * x.m_c[0]));
		return scalar(scalar_scalar, sqrt(e2.m_c[0]));
	}
	inline scalar scpEM(const __syn_smv___e1_e2_ni& x, const __syn_smv___e1_e2_ni& y) {
		return scalar(scalar_scalar, ((x.m_c[1] * y.m_c[1]) + (x.m_c[0] * y.m_c[0]) + (x.m_c[2] * y.m_c[2])));
	}
	inline scalar norm_e(const __syn_smv___scalarf_1_0& x) {
		scalar e2;
		e2.m_c[0] = 1.0f;
		return scalar(scalar_scalar, sqrt(e2.m_c[0]));
	}
	inline __syn_smv___nif_1_0 op(const __syn_smv___scalarf_1_0& x, const __ni_ct__& y) {
		return __syn_smv___nif_1_0(__syn_smv___nif_1_0_nif_1_0);
	}
	inline __syn_smv___scalar_noe1_e1e2_e1ni gpEM(const point& x, const __e1_ct__& y) {
		return __syn_smv___scalar_noe1_e1e2_e1ni(__syn_smv___scalar_noe1_e1e2_e1ni_scalar_noe1_e1e2_e1ni, x.m_c[1], x.m_c[0], (-1.0f * x.m_c[2]), (-1.0f * x.m_c[3]));
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni gp(const __syn_smv___scalar_noe1_e1e2_e1ni& x, const point& y) {
		return __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni_no_e1_e2_noe1e2_ni_noe1ni_e1e2ni, ((x.m_c[0] * y.m_c[0]) + (x.m_c[1] * y.m_c[1])), ((x.m_c[0] * y.m_c[1]) + (-1.0f * x.m_c[3] * y.m_c[0]) + (x.m_c[2] * y.m_c[2]) + (x.m_c[1] * y.m_c[3])), ((-1.0f * x.m_c[2] * y.m_c[1]) + (x.m_c[0] * y.m_c[2])), ((x.m_c[2] * y.m_c[0]) + (x.m_c[1] * y.m_c[2])), ((x.m_c[0] * y.m_c[3]) + (-1.0f * x.m_c[3] * y.m_c[1])), ((x.m_c[3] * y.m_c[0]) + (x.m_c[1] * y.m_c[3])), ((x.m_c[2] * y.m_c[3]) + (-1.0f * x.m_c[3] * y.m_c[2])));
	}
	inline scalar lcont(const __syn_smv___e1_e2_ni& x, const normalizedPoint& y) {
		return scalar(scalar_scalar, ((-1.0f * x.m_c[2]) + (x.m_c[0] * y.m_c[0]) + (x.m_c[1] * y.m_c[1])));
	}
	inline freeVector lcont(const __ni_ct__& x, const line& y) {
		return freeVector(freeVector_e1ni_e2ni, y.m_c[1], y.m_c[2]);
	}
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni gp(const point& x, const point& y) {
		return __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni(__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni_scalar_noe1_noe2_e1e2_noni_e1ni_e2ni, ((x.m_c[2] * y.m_c[2]) + (-1.0f * x.m_c[3] * y.m_c[0]) + (-1.0f * x.m_c[0] * y.m_c[3]) + (x.m_c[1] * y.m_c[1])), ((x.m_c[0] * y.m_c[1]) + (-1.0f * x.m_c[1] * y.m_c[0])), ((-1.0f * x.m_c[2] * y.m_c[0]) + (x.m_c[0] * y.m_c[2])), ((-1.0f * x.m_c[2] * y.m_c[1]) + (x.m_c[1] * y.m_c[2])), ((-1.0f * x.m_c[3] * y.m_c[0]) + (x.m_c[0] * y.m_c[3])), ((x.m_c[1] * y.m_c[3]) + (-1.0f * x.m_c[3] * y.m_c[1])), ((x.m_c[2] * y.m_c[3]) + (-1.0f * x.m_c[3] * y.m_c[2])));
	}
	inline scalar lcont(const circle& x, const __syn_smv___e1e2nif1_0& y) {
		return scalar(scalar_scalar, x.m_c[3]);
	}
	inline point inverseEM(const normalizedPoint& x) {
		scalar n;
		n.m_c[0] = (1.0f + (x.m_c[2] * x.m_c[2]) + (x.m_c[0] * x.m_c[0]) + (x.m_c[1] * x.m_c[1]));
		scalar in;
		in.m_c[0] = ((char)1 / n.m_c[0]);
		return point(point_no_e1_e2_ni, in.m_c[0], (x.m_c[0] * in.m_c[0]), (x.m_c[1] * in.m_c[0]), (x.m_c[2] * in.m_c[0]));
	}
	inline point gp(const scalar& x, const normalizedPoint& y) {
		return point(point_no_e1_e2_ni, x.m_c[0], (x.m_c[0] * y.m_c[0]), (x.m_c[0] * y.m_c[1]), (x.m_c[0] * y.m_c[2]));
	}
	inline __syn_smv___scalar_e1e2_e2ni gp(const __syn_smv___e1_e2_ni& x, const __e2_ct__& y) {
		return __syn_smv___scalar_e1e2_e2ni(__syn_smv___scalar_e1e2_e2ni_scalar_e1e2_e2ni, x.m_c[1], x.m_c[0], (-1.0f * x.m_c[2]));
	}
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni gp(const __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0& x, const translator& y) {
		return __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni(__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni_no_e1_e2_ni_noe1ni_noe2ni_e1e2ni, y.m_c[0], ((x.m_c[0] * y.m_c[0]) + y.m_c[1]), (y.m_c[2] + (x.m_c[1] * y.m_c[0])), ((-1.0f * x.m_c[4] * y.m_c[2]) + (x.m_c[2] * y.m_c[0]) + (x.m_c[1] * y.m_c[2]) + (-1.0f * x.m_c[3] * y.m_c[1]) + (x.m_c[0] * y.m_c[1])), ((x.m_c[3] * y.m_c[0]) + y.m_c[1]), (y.m_c[2] + (x.m_c[4] * y.m_c[0])), ((-1.0f * x.m_c[3] * y.m_c[2]) + (-1.0f * x.m_c[1] * y.m_c[1]) + (x.m_c[5] * y.m_c[0]) + (x.m_c[0] * y.m_c[2]) + (x.m_c[4] * y.m_c[1])));
	}
	inline scalar norm_e(const scalar& x) {
		scalar e2;
		e2.m_c[0] = (x.m_c[0] * x.m_c[0]);
		return scalar(scalar_scalar, sqrt(e2.m_c[0]));
	}
	inline vectorE2GA gp(const scalar& x, const vectorE2GA& y) {
		return vectorE2GA(vectorE2GA_e1_e2, (x.m_c[0] * y.m_c[0]), (x.m_c[0] * y.m_c[1]));
	}
	inline scalar norm_r2(const __syn_smv___e1_e2_ni& x) {
		return scalar(scalar_scalar, ((x.m_c[1] * x.m_c[1]) + (x.m_c[0] * x.m_c[0])));
	}
	inline __syn_smv___no_noe1e2_noe1ni_noe2ni gpEM(const __syn_smv___noe1_noe2_noni& x, const __syn_smv___e1_e2_ni& y) {
		return __syn_smv___no_noe1e2_noe1ni_noe2ni(__syn_smv___no_noe1e2_noe1ni_noe2ni_no_noe1e2_noe1ni_noe2ni, ((x.m_c[1] * y.m_c[1]) + (x.m_c[2] * y.m_c[2]) + (x.m_c[0] * y.m_c[0])), ((x.m_c[0] * y.m_c[1]) + (-1.0f * x.m_c[1] * y.m_c[0])), ((-1.0f * x.m_c[2] * y.m_c[0]) + (x.m_c[0] * y.m_c[2])), ((x.m_c[1] * y.m_c[2]) + (-1.0f * x.m_c[2] * y.m_c[1])));
	}
	inline scalar scp(const point& x, const point& y) {
		return scalar(scalar_scalar, ((-1.0f * x.m_c[3] * y.m_c[0]) + (-1.0f * x.m_c[0] * y.m_c[3]) + (x.m_c[1] * y.m_c[1]) + (x.m_c[2] * y.m_c[2])));
	}
	inline point add(const point& x, const point& y) {
		return point(point_no_e1_e2_ni, (y.m_c[0] + x.m_c[0]), (x.m_c[1] + y.m_c[1]), (x.m_c[2] + y.m_c[2]), (x.m_c[3] + y.m_c[3]));
	}
	inline scalar scp(const __ni_ct__& x, const __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni& y) {
		return scalar(scalar_scalar, (-1.0f * y.m_c[0]));
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni gpEM(const __syn_smv___scalar_noe1_noe2_noni& x, const point& y) {
		return __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni_no_e1_e2_noe1e2_ni_noe1ni_noe2ni, ((x.m_c[3] * y.m_c[3]) + (x.m_c[0] * y.m_c[0]) + (x.m_c[2] * y.m_c[2]) + (x.m_c[1] * y.m_c[1])), ((x.m_c[0] * y.m_c[1]) + (-1.0f * x.m_c[1] * y.m_c[0])), ((-1.0f * x.m_c[2] * y.m_c[0]) + (x.m_c[0] * y.m_c[2])), ((-1.0f * x.m_c[2] * y.m_c[1]) + (x.m_c[1] * y.m_c[2])), ((x.m_c[0] * y.m_c[3]) + (-1.0f * x.m_c[3] * y.m_c[0])), ((-1.0f * x.m_c[3] * y.m_c[1]) + (x.m_c[1] * y.m_c[3])), ((-1.0f * x.m_c[3] * y.m_c[2]) + (x.m_c[2] * y.m_c[3])));
	}
	inline scalar norm_e(const __syn_smv___e1ni_e2ni_nonif_1_0& x) {
		scalar e2;
		e2.m_c[0] = (1.0f + (x.m_c[1] * x.m_c[1]) + (x.m_c[0] * x.m_c[0]));
		return scalar(scalar_scalar, sqrt(e2.m_c[0]));
	}
	inline __syn_smv___scalar_e1e2_e2ni gpEM(const __syn_smv___e1_e2_ni& x, const __e2_ct__& y) {
		return __syn_smv___scalar_e1e2_e2ni(__syn_smv___scalar_e1e2_e2ni_scalar_e1e2_e2ni, x.m_c[1], x.m_c[0], (-1.0f * x.m_c[2]));
	}
	inline point gp(const point& x, const scalar& y) {
		return point(point_no_e1_e2_ni, (x.m_c[0] * y.m_c[0]), (x.m_c[1] * y.m_c[0]), (x.m_c[2] * y.m_c[0]), (x.m_c[3] * y.m_c[0]));
	}
	inline scalar norm_e(const freeVector& x) {
		scalar e2;
		e2.m_c[0] = ((x.m_c[0] * x.m_c[0]) + (x.m_c[1] * x.m_c[1]));
		return scalar(scalar_scalar, sqrt(e2.m_c[0]));
	}
	inline __syn_smv___scalar_noe2_e1e2_e2ni gp(const point& x, const __e2_ct__& y) {
		return __syn_smv___scalar_noe2_e1e2_e2ni(__syn_smv___scalar_noe2_e1e2_e2ni_scalar_noe2_e1e2_e2ni, x.m_c[2], x.m_c[0], x.m_c[1], (-1.0f * x.m_c[3]));
	}
	inline __I2_ct__ op(const __e1_ct__& x, const __e2_ct__& y) {
		return __I2_ct__(__I2_ct___e1e2f1_0);
	}
	inline point reverse(const point& x) {
		return point(point_no_e1_e2_ni, x.m_c[0], x.m_c[1], x.m_c[2], x.m_c[3]);
	}
	inline __syn_smv___scalar_noe1_noe2_noni gpEM(const point& x, const __no_ct__& y) {
		return __syn_smv___scalar_noe1_noe2_noni(__syn_smv___scalar_noe1_noe2_noni_scalar_noe1_noe2_noni, x.m_c[0], (-1.0f * x.m_c[1]), (-1.0f * x.m_c[2]), (-1.0f * x.m_c[3]));
	}
	inline __syn_smv___e1e2nif1_0 op(const __I2_ct__& x, const __ni_ct__& y) {
		return __syn_smv___e1e2nif1_0(__syn_smv___e1e2nif1_0_e1e2nif1_0);
	}
	inline __syn_smv___e1_e2_ni inverseEM(const __syn_smv___e1_e2_ni& x) {
		scalar n;
		n.m_c[0] = ((x.m_c[0] * x.m_c[0]) + (x.m_c[1] * x.m_c[1]) + (x.m_c[2] * x.m_c[2]));
		scalar in;
		in.m_c[0] = ((char)1 / n.m_c[0]);
		return __syn_smv___e1_e2_ni(__syn_smv___e1_e2_ni_e1_e2_ni, (x.m_c[0] * in.m_c[0]), (x.m_c[1] * in.m_c[0]), (x.m_c[2] * in.m_c[0]));
	}
	inline line dual(const __syn_smv___e1_e2_ni& x) {
		return line(line_e1e2ni_e1noni_e2noni, x.m_c[2], x.m_c[1], (-1.0f * x.m_c[0]));
	}
	inline __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0 gp(const normalizedTranslator& x, const normalizedPoint& y) {
		return __syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0(__syn_smv___e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0_e1_e2_ni_noe1ni_noe2ni_e1e2ni_nof1_0, (y.m_c[0] + (-1.0f * x.m_c[0])), ((-1.0f * x.m_c[1]) + y.m_c[1]), ((-1.0f * x.m_c[0] * y.m_c[0]) + (-1.0f * x.m_c[1] * y.m_c[1]) + y.m_c[2]), x.m_c[0], x.m_c[1], ((-1.0f * x.m_c[0] * y.m_c[1]) + (x.m_c[1] * y.m_c[0])));
	}
	inline scalar norm_r(const line& x) {
		scalar r2;
		r2.m_c[0] = ((-1.0f * x.m_c[2] * x.m_c[2]) + (-1.0f * x.m_c[1] * x.m_c[1]));
		return scalar(scalar_scalar, ((((r2.m_c[0] < (char)0)) ? (char)-1 : ((((r2.m_c[0] > (char)0)) ? (char)1 : (char)0))) * sqrt((((r2.m_c[0] < (char)0)) ? ((-r2.m_c[0])) : (r2.m_c[0])))));
	}
	inline __syn_smv___scalar_noe1_noe2_noni gp(const point& x, const __no_ct__& y) {
		return __syn_smv___scalar_noe1_noe2_noni(__syn_smv___scalar_noe1_noe2_noni_scalar_noe1_noe2_noni, (-1.0f * x.m_c[3]), (-1.0f * x.m_c[1]), (-1.0f * x.m_c[2]), (-1.0f * x.m_c[3]));
	}
	inline circle gradeInvolution(const circle& x) {
		return circle(circle_e1e2ni_noe1ni_noe2ni_noe1e2, (-1.0f * x.m_c[0]), (-1.0f * x.m_c[1]), (-1.0f * x.m_c[2]), (-1.0f * x.m_c[3]));
	}
	inline __syn_smv___noe1_noe2_noni gpEM(const __syn_smv___e1_e2_ni& x, const __no_ct__& y) {
		return __syn_smv___noe1_noe2_noni(__syn_smv___noe1_noe2_noni_noe1_noe2_noni, (-1.0f * x.m_c[0]), (-1.0f * x.m_c[1]), (-1.0f * x.m_c[2]));
	}
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni gp(const circle& x, const circle& y) {
		return __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni(__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni_scalar_noe1_noe2_e1e2_noni_e1ni_e2ni, ((x.m_c[2] * y.m_c[2]) + (x.m_c[3] * y.m_c[0]) + (x.m_c[0] * y.m_c[3]) + (x.m_c[1] * y.m_c[1])), ((-1.0f * x.m_c[3] * y.m_c[2]) + (x.m_c[2] * y.m_c[3])), ((-1.0f * x.m_c[1] * y.m_c[3]) + (x.m_c[3] * y.m_c[1])), ((x.m_c[1] * y.m_c[2]) + (-1.0f * x.m_c[2] * y.m_c[1])), ((-1.0f * x.m_c[3] * y.m_c[0]) + (x.m_c[0] * y.m_c[3])), ((-1.0f * x.m_c[0] * y.m_c[2]) + (x.m_c[2] * y.m_c[0])), ((-1.0f * x.m_c[1] * y.m_c[0]) + (x.m_c[0] * y.m_c[1])));
	}
	inline ni_t gp(const scalar& x, const __ni_ct__& y) {
		return ni_t(ni_t_ni, x.m_c[0]);
	}
	inline __syn_smv___scalarf_1_0 lcont(const __ni_ct__& x, const normalizedPoint& y) {
		return __syn_smv___scalarf_1_0(__syn_smv___scalarf_1_0_scalarf_1_0);
	}
	inline __syn_smv___scalar_noe2_e1e2_e2ni gpEM(const point& x, const __e2_ct__& y) {
		return __syn_smv___scalar_noe2_e1e2_e2ni(__syn_smv___scalar_noe2_e1e2_e2ni_scalar_noe2_e1e2_e2ni, x.m_c[2], x.m_c[0], x.m_c[1], (-1.0f * x.m_c[3]));
	}
	inline normalizedPoint reverse(const normalizedPoint& x) {
		return normalizedPoint(normalizedPoint_e1_e2_ni_nof1_0, x.m_c[0], x.m_c[1], x.m_c[2]);
	}
	inline freeVector negate(const freeVector& x) {
		return freeVector(freeVector_e1ni_e2ni, (-1.0f * x.m_c[0]), (-1.0f * x.m_c[1]));
	}
	inline scalar scp(const __syn_smv___e1_e2_ni& x, const __syn_smv___e1_e2_ni& y) {
		return scalar(scalar_scalar, ((x.m_c[1] * y.m_c[1]) + (x.m_c[0] * y.m_c[0])));
	}
	inline freeBivector op(const TRversorLog& x, const __ni_ct__& y) {
		return freeBivector(freeBivector_e1e2ni, x.m_c[0]);
	}
	inline scalar lcont(const __ni_ct__& x, const point& y) {
		return scalar(scalar_scalar, (-1.0f * y.m_c[0]));
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni gp(const __syn_smv___scalar_noe2_e1e2_e2ni& x, const point& y) {
		return __syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni(__syn_smv___no_e1_e2_noe1e2_ni_noe2ni_e1e2ni_no_e1_e2_noe1e2_ni_noe2ni_e1e2ni, ((x.m_c[1] * y.m_c[2]) + (x.m_c[0] * y.m_c[0])), ((x.m_c[0] * y.m_c[1]) + (x.m_c[2] * y.m_c[2])), ((-1.0f * x.m_c[3] * y.m_c[0]) + (-1.0f * x.m_c[2] * y.m_c[1]) + (x.m_c[1] * y.m_c[3]) + (x.m_c[0] * y.m_c[2])), ((-1.0f * x.m_c[1] * y.m_c[1]) + (x.m_c[2] * y.m_c[0])), ((-1.0f * x.m_c[3] * y.m_c[2]) + (x.m_c[0] * y.m_c[3])), ((x.m_c[3] * y.m_c[0]) + (x.m_c[1] * y.m_c[3])), ((x.m_c[3] * y.m_c[1]) + (x.m_c[2] * y.m_c[3])));
	}
	inline circle negate(const circle& x) {
		return circle(circle_e1e2ni_noe1ni_noe2ni_noe1e2, (-1.0f * x.m_c[0]), (-1.0f * x.m_c[1]), (-1.0f * x.m_c[2]), (-1.0f * x.m_c[3]));
	}
	inline scalar scpEM(const point& x, const point& y) {
		return scalar(scalar_scalar, ((x.m_c[2] * y.m_c[2]) + (x.m_c[3] * y.m_c[3]) + (x.m_c[1] * y.m_c[1]) + (x.m_c[0] * y.m_c[0])));
	}
	inline __syn_smv___e1_e2_ni_e1e2ni gpEM(const __syn_smv___scalar_e1e2_e2ni& x, const __syn_smv___e1_e2_ni& y) {
		return __syn_smv___e1_e2_ni_e1e2ni(__syn_smv___e1_e2_ni_e1e2ni_e1_e2_ni_e1e2ni, ((x.m_c[1] * y.m_c[1]) + (x.m_c[0] * y.m_c[0])), ((x.m_c[0] * y.m_c[1]) + (x.m_c[2] * y.m_c[2]) + (-1.0f * x.m_c[1] * y.m_c[0])), ((-1.0f * x.m_c[2] * y.m_c[1]) + (x.m_c[0] * y.m_c[2])), ((x.m_c[2] * y.m_c[0]) + (x.m_c[1] * y.m_c[2])));
	}
	inline __syn_smv___e1_e2_ni_nof_1_0 gradeInvolution(const normalizedPoint& x) {
		return __syn_smv___e1_e2_ni_nof_1_0(__syn_smv___e1_e2_ni_nof_1_0_e1_e2_ni_nof_1_0, (-1.0f * x.m_c[0]), (-1.0f * x.m_c[1]), (-1.0f * x.m_c[2]));
	}
	inline point inverseEM(const point& x) {
		scalar n;
		n.m_c[0] = ((x.m_c[3] * x.m_c[3]) + (x.m_c[2] * x.m_c[2]) + (x.m_c[0] * x.m_c[0]) + (x.m_c[1] * x.m_c[1]));
		scalar in;
		in.m_c[0] = ((char)1 / n.m_c[0]);
		return point(point_no_e1_e2_ni, (x.m_c[0] * in.m_c[0]), (x.m_c[1] * in.m_c[0]), (x.m_c[2] * in.m_c[0]), (x.m_c[3] * in.m_c[0]));
	}
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni gpEM(const __syn_smv___scalar_noni_e1ni_e2ni& x, const __syn_smv___e1_e2_ni_nof_1_0& y) {
		return __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni(__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni_no_e1_e2_ni_noe1ni_noe2ni_e1e2ni, ((-1.0f * x.m_c[0]) + (x.m_c[1] * y.m_c[2])), ((x.m_c[2] * y.m_c[2]) + (x.m_c[0] * y.m_c[0])), ((x.m_c[3] * y.m_c[2]) + (x.m_c[0] * y.m_c[1])), ((-1.0f * x.m_c[2] * y.m_c[0]) + x.m_c[1] + (-1.0f * x.m_c[3] * y.m_c[1]) + (x.m_c[0] * y.m_c[2])), ((-1.0f * x.m_c[1] * y.m_c[0]) + (-1.0f * x.m_c[2])), ((-1.0f * x.m_c[1] * y.m_c[1]) + (-1.0f * x.m_c[3])), ((x.m_c[3] * y.m_c[0]) + (-1.0f * x.m_c[2] * y.m_c[1])));
	}
	inline __syn_smv___e1_e2_nof1_0 add(const vectorE2GA& x, const __no_ct__& y) {
		return __syn_smv___e1_e2_nof1_0(__syn_smv___e1_e2_nof1_0_e1_e2_nof1_0, x.m_c[0], x.m_c[1]);
	}
	inline point subtract(const point& x, const normalizedPoint& y) {
		return point(point_no_e1_e2_ni, (-1.0f + x.m_c[0]), (x.m_c[1] + (-1.0f * y.m_c[0])), (x.m_c[2] + (-1.0f * y.m_c[1])), ((-1.0f * y.m_c[2]) + x.m_c[3]));
	}
	inline __syn_smv___nif1_0 negate(const __syn_smv___nif_1_0& x) {
		return __syn_smv___nif1_0(__syn_smv___nif1_0_nif1_0);
	}
	inline point lcont(const pointPair& x, const line& y) {
		return point(point_no_e1_e2_ni, ((x.m_c[1] * y.m_c[2]) + (x.m_c[0] * y.m_c[1])), ((-1.0f * x.m_c[1] * y.m_c[0]) + (x.m_c[5] * y.m_c[1])), ((x.m_c[5] * y.m_c[2]) + (x.m_c[0] * y.m_c[0])), ((x.m_c[4] * y.m_c[2]) + (-1.0f * x.m_c[2] * y.m_c[0]) + (x.m_c[3] * y.m_c[1])));
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni gpEM(const __syn_smv___scalar_noe1_e1e2_e1ni& x, const point& y) {
		return __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni_no_e1_e2_noe1e2_ni_noe1ni_e1e2ni, ((x.m_c[0] * y.m_c[0]) + (x.m_c[1] * y.m_c[1])), ((-1.0f * x.m_c[1] * y.m_c[0]) + (x.m_c[3] * y.m_c[3]) + (x.m_c[2] * y.m_c[2]) + (x.m_c[0] * y.m_c[1])), ((-1.0f * x.m_c[2] * y.m_c[1]) + (x.m_c[0] * y.m_c[2])), ((x.m_c[2] * y.m_c[0]) + (x.m_c[1] * y.m_c[2])), ((x.m_c[0] * y.m_c[3]) + (-1.0f * x.m_c[3] * y.m_c[1])), ((x.m_c[1] * y.m_c[3]) + (x.m_c[3] * y.m_c[0])), ((x.m_c[2] * y.m_c[3]) + (-1.0f * x.m_c[3] * y.m_c[2])));
	}
	inline scalar norm_e2(const vectorE2GA& x) {
		return scalar(scalar_scalar, ((x.m_c[0] * x.m_c[0]) + (x.m_c[1] * x.m_c[1])));
	}
	inline __syn_smv___e1_e2_ni inverse(const __syn_smv___e1_e2_ni& x) {
		scalar n;
		n.m_c[0] = ((x.m_c[0] * x.m_c[0]) + (x.m_c[1] * x.m_c[1]));
		scalar in;
		in.m_c[0] = ((char)1 / n.m_c[0]);
		return __syn_smv___e1_e2_ni(__syn_smv___e1_e2_ni_e1_e2_ni, (x.m_c[0] * in.m_c[0]), (x.m_c[1] * in.m_c[0]), (x.m_c[2] * in.m_c[0]));
	}
	inline translator gpEM(const __syn_smv___e1_e2_ni& x, const __ni_ct__& y) {
		return translator(translator_scalar_e1ni_e2ni, x.m_c[2], x.m_c[0], x.m_c[1]);
	}
	inline scalar inverse(const __syn_smv___scalarf_1_0& x) {
		scalar n;
		n.m_c[0] = 1.0f;
		scalar in;
		in.m_c[0] = ((char)1 / n.m_c[0]);
		return scalar(scalar_scalar, (-1.0f * in.m_c[0]));
	}
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni gp(const __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni& x, const scalar& y) {
		return __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni(__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni_scalar_noe1_noe2_e1e2_noni_e1ni_e2ni, (x.m_c[0] * y.m_c[0]), (x.m_c[1] * y.m_c[0]), (x.m_c[2] * y.m_c[0]), (x.m_c[3] * y.m_c[0]), (x.m_c[4] * y.m_c[0]), (x.m_c[5] * y.m_c[0]), (x.m_c[6] * y.m_c[0]));
	}
	inline vectorE2GA subtract(const vectorE2GA& x, const vectorE2GA& y) {
		return vectorE2GA(vectorE2GA_e1_e2, (x.m_c[0] + (-1.0f * y.m_c[0])), (x.m_c[1] + (-1.0f * y.m_c[1])));
	}
	inline freeVector op(const vectorE2GA& x, const __ni_ct__& y) {
		return freeVector(freeVector_e1ni_e2ni, x.m_c[0], x.m_c[1]);
	}
	inline scalar scpEM(const normalizedPoint& x, const normalizedPoint& y) {
		return scalar(scalar_scalar, (1.0f + (x.m_c[1] * y.m_c[1]) + (x.m_c[0] * y.m_c[0]) + (x.m_c[2] * y.m_c[2])));
	}
	inline point gp(const normalizedPoint& x, const scalar& y) {
		return point(point_no_e1_e2_ni, y.m_c[0], (x.m_c[0] * y.m_c[0]), (x.m_c[1] * y.m_c[0]), (x.m_c[2] * y.m_c[0]));
	}
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni gpEM(const point& x, const point& y) {
		return __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni(__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni_scalar_noe1_noe2_e1e2_noni_e1ni_e2ni, ((x.m_c[3] * y.m_c[3]) + (x.m_c[1] * y.m_c[1]) + (x.m_c[0] * y.m_c[0]) + (x.m_c[2] * y.m_c[2])), ((x.m_c[0] * y.m_c[1]) + (-1.0f * x.m_c[1] * y.m_c[0])), ((x.m_c[0] * y.m_c[2]) + (-1.0f * x.m_c[2] * y.m_c[0])), ((x.m_c[1] * y.m_c[2]) + (-1.0f * x.m_c[2] * y.m_c[1])), ((x.m_c[0] * y.m_c[3]) + (-1.0f * x.m_c[3] * y.m_c[0])), ((x.m_c[1] * y.m_c[3]) + (-1.0f * x.m_c[3] * y.m_c[1])), ((-1.0f * x.m_c[3] * y.m_c[2]) + (x.m_c[2] * y.m_c[3])));
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni gpEM(const __syn_smv___scalar_noe1_noe2_noni& x, const __syn_smv___e1_e2_ni_nof_1_0& y) {
		return __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni_no_e1_e2_noe1e2_ni_noe1ni_noe2ni, ((x.m_c[2] * y.m_c[1]) + (-1.0f * x.m_c[0]) + (x.m_c[3] * y.m_c[2]) + (x.m_c[1] * y.m_c[0])), (x.m_c[1] + (x.m_c[0] * y.m_c[0])), (x.m_c[2] + (x.m_c[0] * y.m_c[1])), ((-1.0f * x.m_c[2] * y.m_c[0]) + (x.m_c[1] * y.m_c[1])), (x.m_c[3] + (x.m_c[0] * y.m_c[2])), ((x.m_c[1] * y.m_c[2]) + (-1.0f * x.m_c[3] * y.m_c[0])), ((-1.0f * x.m_c[3] * y.m_c[1]) + (x.m_c[2] * y.m_c[2])));
	}
	inline vectorE2GA subtract(const e1_t& x, const e2_t& y) {
		return vectorE2GA(vectorE2GA_e1_e2, x.m_c[0], (-1.0f * y.m_c[0]));
	}
	inline circle op(const pointPair& x, const normalizedPoint& y) {
		return circle(circle_e1e2ni_noe1ni_noe2ni_noe1e2, ((x.m_c[4] * y.m_c[0]) + (x.m_c[2] * y.m_c[2]) + (-1.0f * x.m_c[3] * y.m_c[1])), ((-1.0f * x.m_c[5] * y.m_c[0]) + x.m_c[3] + (x.m_c[0] * y.m_c[2])), (x.m_c[4] + (x.m_c[1] * y.m_c[2]) + (-1.0f * x.m_c[5] * y.m_c[1])), (x.m_c[2] + (x.m_c[0] * y.m_c[1]) + (-1.0f * x.m_c[1] * y.m_c[0])));
	}
	inline __syn_smv___scalar_noni_e1ni_e2ni gp(const point& x, const __ni_ct__& y) {
		return __syn_smv___scalar_noni_e1ni_e2ni(__syn_smv___scalar_noni_e1ni_e2ni_scalar_noni_e1ni_e2ni, (-1.0f * x.m_c[0]), x.m_c[0], x.m_c[1], x.m_c[2]);
	}
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni gp(const __syn_smv___scalar_noni_e1ni_e2ni& x, const point& y) {
		return __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni(__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni_no_e1_e2_ni_noe1ni_noe2ni_e1e2ni, ((x.m_c[0] * y.m_c[0]) + (-1.0f * x.m_c[1] * y.m_c[0])), ((-1.0f * x.m_c[2] * y.m_c[0]) + (x.m_c[0] * y.m_c[1])), ((x.m_c[0] * y.m_c[2]) + (-1.0f * x.m_c[3] * y.m_c[0])), ((x.m_c[1] * y.m_c[3]) + (-1.0f * x.m_c[3] * y.m_c[2]) + (-1.0f * x.m_c[2] * y.m_c[1]) + (x.m_c[0] * y.m_c[3])), ((-1.0f * x.m_c[1] * y.m_c[1]) + (x.m_c[2] * y.m_c[0])), ((-1.0f * x.m_c[1] * y.m_c[2]) + (x.m_c[3] * y.m_c[0])), ((x.m_c[3] * y.m_c[1]) + (-1.0f * x.m_c[2] * y.m_c[2])));
	}
	inline TRversor gp(const __syn_smv___e1_e2_ni& x, const __syn_smv___e1_e2_ni& y) {
		return TRversor(TRversor_scalar_e1e2_e1ni_e2ni, ((x.m_c[0] * y.m_c[0]) + (x.m_c[1] * y.m_c[1])), ((-1.0f * x.m_c[1] * y.m_c[0]) + (x.m_c[0] * y.m_c[1])), ((-1.0f * x.m_c[2] * y.m_c[0]) + (x.m_c[0] * y.m_c[2])), ((-1.0f * x.m_c[2] * y.m_c[1]) + (x.m_c[1] * y.m_c[2])));
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni gpEM(const __syn_smv___scalar_noe1_e1e2_e1ni& x, const __syn_smv___e1_e2_ni_nof_1_0& y) {
		return __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_e1e2ni_no_e1_e2_noe1e2_ni_noe1ni_e1e2ni, ((x.m_c[1] * y.m_c[0]) + (-1.0f * x.m_c[0])), (x.m_c[1] + (x.m_c[2] * y.m_c[1]) + (x.m_c[3] * y.m_c[2]) + (x.m_c[0] * y.m_c[0])), ((x.m_c[0] * y.m_c[1]) + (-1.0f * x.m_c[2] * y.m_c[0])), ((-1.0f * x.m_c[2]) + (x.m_c[1] * y.m_c[1])), ((x.m_c[0] * y.m_c[2]) + (-1.0f * x.m_c[3] * y.m_c[0])), ((x.m_c[1] * y.m_c[2]) + (-1.0f * x.m_c[3])), ((x.m_c[2] * y.m_c[2]) + (-1.0f * x.m_c[3] * y.m_c[1])));
	}
	inline TRversor gpEM(const __syn_smv___e1_e2_ni& x, const __syn_smv___e1_e2_ni& y) {
		return TRversor(TRversor_scalar_e1e2_e1ni_e2ni, ((x.m_c[1] * y.m_c[1]) + (x.m_c[0] * y.m_c[0]) + (x.m_c[2] * y.m_c[2])), ((x.m_c[0] * y.m_c[1]) + (-1.0f * x.m_c[1] * y.m_c[0])), ((-1.0f * x.m_c[2] * y.m_c[0]) + (x.m_c[0] * y.m_c[2])), ((-1.0f * x.m_c[2] * y.m_c[1]) + (x.m_c[1] * y.m_c[2])));
	}
	inline freeBivector negate(const freeBivector& x) {
		return freeBivector(freeBivector_e1e2ni, (-1.0f * x.m_c[0]));
	}
	inline __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni gpEM(const __syn_smv___scalar_noni_e1ni_e2ni& x, const point& y) {
		return __syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni(__syn_smv___no_e1_e2_ni_noe1ni_noe2ni_e1e2ni_no_e1_e2_ni_noe1ni_noe2ni_e1e2ni, ((x.m_c[1] * y.m_c[3]) + (x.m_c[0] * y.m_c[0])), ((x.m_c[0] * y.m_c[1]) + (x.m_c[2] * y.m_c[3])), ((x.m_c[3] * y.m_c[3]) + (x.m_c[0] * y.m_c[2])), ((x.m_c[0] * y.m_c[3]) + (-1.0f * x.m_c[1] * y.m_c[0]) + (-1.0f * x.m_c[3] * y.m_c[2]) + (-1.0f * x.m_c[2] * y.m_c[1])), ((x.m_c[2] * y.m_c[0]) + (-1.0f * x.m_c[1] * y.m_c[1])), ((-1.0f * x.m_c[1] * y.m_c[2]) + (x.m_c[3] * y.m_c[0])), ((x.m_c[3] * y.m_c[1]) + (-1.0f * x.m_c[2] * y.m_c[2])));
	}
	inline TRversor subtract(const TRversor& x, const TRversor& y) {
		return TRversor(TRversor_scalar_e1e2_e1ni_e2ni, ((-1.0f * y.m_c[0]) + x.m_c[0]), (x.m_c[1] + (-1.0f * y.m_c[1])), ((-1.0f * y.m_c[2]) + x.m_c[2]), ((-1.0f * y.m_c[3]) + x.m_c[3]));
	}
	inline __syn_smv___scalar_noe1_noe2_noni gp(const __syn_smv___e1_e2_ni& x, const __no_ct__& y) {
		return __syn_smv___scalar_noe1_noe2_noni(__syn_smv___scalar_noe1_noe2_noni_scalar_noe1_noe2_noni, (-1.0f * x.m_c[2]), (-1.0f * x.m_c[0]), (-1.0f * x.m_c[1]), (-1.0f * x.m_c[2]));
	}
	inline __syn_smv___e1_e2_ni dual(const line& x) {
		return __syn_smv___e1_e2_ni(__syn_smv___e1_e2_ni_e1_e2_ni, x.m_c[2], (-1.0f * x.m_c[1]), (-1.0f * x.m_c[0]));
	}
	inline vectorE2GA unit_e(const vectorE2GA& x) {
		scalar e2;
		e2.m_c[0] = ((x.m_c[0] * x.m_c[0]) + (x.m_c[1] * x.m_c[1]));
		scalar ie;
		ie.m_c[0] = ((char)1 / sqrt(e2.m_c[0]));
		return vectorE2GA(vectorE2GA_e1_e2, (x.m_c[0] * ie.m_c[0]), (x.m_c[1] * ie.m_c[0]));
	}
	inline point gradeInvolution(const point& x) {
		return point(point_no_e1_e2_ni, (-1.0f * x.m_c[0]), (-1.0f * x.m_c[1]), (-1.0f * x.m_c[2]), (-1.0f * x.m_c[3]));
	}
	inline __syn_smv___scalar_noe1_e1e2_e1ni gp(const point& x, const __e1_ct__& y) {
		return __syn_smv___scalar_noe1_e1e2_e1ni(__syn_smv___scalar_noe1_e1e2_e1ni_scalar_noe1_e1e2_e1ni, x.m_c[1], x.m_c[0], (-1.0f * x.m_c[2]), (-1.0f * x.m_c[3]));
	}
	inline e1_t gp(const scalar& x, const __e1_ct__& y) {
		return e1_t(e1_t_e1, x.m_c[0]);
	}
	inline __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni gpEM(const point& x, const __syn_smv___e1_e2_ni_nof_1_0& y) {
		return __syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni(__syn_smv___scalar_noe1_noe2_e1e2_noni_e1ni_e2ni_scalar_noe1_noe2_e1e2_noni_e1ni_e2ni, ((-1.0f * x.m_c[0]) + (x.m_c[1] * y.m_c[0]) + (x.m_c[2] * y.m_c[1]) + (x.m_c[3] * y.m_c[2])), (x.m_c[1] + (x.m_c[0] * y.m_c[0])), ((x.m_c[0] * y.m_c[1]) + x.m_c[2]), ((-1.0f * x.m_c[2] * y.m_c[0]) + (x.m_c[1] * y.m_c[1])), (x.m_c[3] + (x.m_c[0] * y.m_c[2])), ((x.m_c[1] * y.m_c[2]) + (-1.0f * x.m_c[3] * y.m_c[0])), ((-1.0f * x.m_c[3] * y.m_c[1]) + (x.m_c[2] * y.m_c[2])));
	}
	inline translator inverse(const normalizedTranslator& x) {
		scalar n;
		n.m_c[0] = 1.0f;
		scalar in;
		in.m_c[0] = ((char)1 / n.m_c[0]);
		return translator(translator_scalar_e1ni_e2ni, in.m_c[0], (-1.0f * x.m_c[0] * in.m_c[0]), (-1.0f * x.m_c[1] * in.m_c[0]));
	}
	inline __syn_smv___e1_e2_ni_e1e2ni gpEM(const __syn_smv___scalar_e1e2_e1ni& x, const __syn_smv___e1_e2_ni& y) {
		return __syn_smv___e1_e2_ni_e1e2ni(__syn_smv___e1_e2_ni_e1e2ni_e1_e2_ni_e1e2ni, ((x.m_c[1] * y.m_c[1]) + (x.m_c[0] * y.m_c[0]) + (x.m_c[2] * y.m_c[2])), ((-1.0f * x.m_c[1] * y.m_c[0]) + (x.m_c[0] * y.m_c[1])), ((-1.0f * x.m_c[2] * y.m_c[0]) + (x.m_c[0] * y.m_c[2])), ((x.m_c[1] * y.m_c[2]) + (-1.0f * x.m_c[2] * y.m_c[1])));
	}
	inline __syn_smv___e1ni_e2ni_nonif_1_0 op(const __ni_ct__& x, const normalizedPoint& y) {
		return __syn_smv___e1ni_e2ni_nonif_1_0(__syn_smv___e1ni_e2ni_nonif_1_0_e1ni_e2ni_nonif_1_0, (-1.0f * y.m_c[0]), (-1.0f * y.m_c[1]));
	}
	inline point gp(const scalar& x, const __syn_smv___e1_e2_ni_nof2_0& y) {
		return point(point_no_e1_e2_ni, (2.0f * x.m_c[0]), (x.m_c[0] * y.m_c[0]), (x.m_c[0] * y.m_c[1]), (x.m_c[0] * y.m_c[2]));
	}
	inline TRversorLog lcont(const __ni_ct__& x, const circle& y) {
		return TRversorLog(TRversorLog_e1e2_e1ni_e2ni, (-1.0f * y.m_c[3]), (-1.0f * y.m_c[1]), (-1.0f * y.m_c[2]));
	}
	inline __syn_smv___scalar_noni_e1ni_e2ni gpEM(const point& x, const __ni_ct__& y) {
		return __syn_smv___scalar_noni_e1ni_e2ni(__syn_smv___scalar_noni_e1ni_e2ni_scalar_noni_e1ni_e2ni, x.m_c[3], x.m_c[0], x.m_c[1], x.m_c[2]);
	}
	inline freeVector op(const __ni_ct__& x, const __syn_smv___e1_e2_ni& y) {
		return freeVector(freeVector_e1ni_e2ni, (-1.0f * y.m_c[0]), (-1.0f * y.m_c[1]));
	}
	inline scalar scp(const TRversorLog& x, const TRversorLog& y) {
		return scalar(scalar_scalar, (-1.0f * x.m_c[0] * y.m_c[0]));
	}
	inline line op(const pointPair& x, const __ni_ct__& y) {
		return line(line_e1e2ni_e1noni_e2noni, x.m_c[2], (-1.0f * x.m_c[0]), (-1.0f * x.m_c[1]));
	}
	inline __syn_smv___scalarf0_0 lcont(const __ni_ct__& x, const __syn_smv___e1_e2_ni& y) {
		return __syn_smv___scalarf0_0(__syn_smv___scalarf0_0_scalarf0_0);
	}
	inline pointPair lcont(const normalizedPoint& x, const line& y) {
		return pointPair(pointPair_noe1_noe2_e1e2_e1ni_e2ni_noni, y.m_c[1], y.m_c[2], (-1.0f * y.m_c[0]), ((x.m_c[2] * y.m_c[1]) + (-1.0f * x.m_c[1] * y.m_c[0])), ((x.m_c[0] * y.m_c[0]) + (x.m_c[2] * y.m_c[2])), ((x.m_c[0] * y.m_c[1]) + (x.m_c[1] * y.m_c[2])));
	}
	inline __syn_smv___e1_e2_ni reverse(const __syn_smv___e1_e2_ni& x) {
		return __syn_smv___e1_e2_ni(__syn_smv___e1_e2_ni_e1_e2_ni, x.m_c[0], x.m_c[1], x.m_c[2]);
	}
	inline normalizedPoint add(const __syn_smv___e1_e2_nof1_0& x, const ni_t& y) {
		return normalizedPoint(normalizedPoint_e1_e2_ni_nof1_0, x.m_c[0], x.m_c[1], y.m_c[0]);
	}
	inline pointPair op(const normalizedPoint& x, const normalizedPoint& y) {
		return pointPair(pointPair_noe1_noe2_e1e2_e1ni_e2ni_noni, ((-1.0f * x.m_c[0]) + y.m_c[0]), ((-1.0f * x.m_c[1]) + y.m_c[1]), ((x.m_c[0] * y.m_c[1]) + (-1.0f * x.m_c[1] * y.m_c[0])), ((x.m_c[0] * y.m_c[2]) + (-1.0f * x.m_c[2] * y.m_c[0])), ((x.m_c[1] * y.m_c[2]) + (-1.0f * x.m_c[2] * y.m_c[1])), ((-1.0f * x.m_c[2]) + y.m_c[2]));
	}
	inline __syn_smv___e1_e2_ni_e1e2ni gpEM(const translator& x, const __syn_smv___e1_e2_ni& y) {
		return __syn_smv___e1_e2_ni_e1e2ni(__syn_smv___e1_e2_ni_e1e2ni_e1_e2_ni_e1e2ni, ((x.m_c[0] * y.m_c[0]) + (x.m_c[1] * y.m_c[2])), ((x.m_c[2] * y.m_c[2]) + (x.m_c[0] * y.m_c[1])), ((x.m_c[0] * y.m_c[2]) + (-1.0f * x.m_c[1] * y.m_c[0]) + (-1.0f * x.m_c[2] * y.m_c[1])), ((-1.0f * x.m_c[1] * y.m_c[1]) + (x.m_c[2] * y.m_c[0])));
	}
	inline bivectorE2GA lcont(const __no_ct__& x, const freeBivector& y) {
		return bivectorE2GA(bivectorE2GA_e1e2, (-1.0f * y.m_c[0]));
	}
	inline scalar norm_r2(const point& x) {
		return scalar(scalar_scalar, ((-1.0f * x.m_c[3] * x.m_c[0]) + (x.m_c[1] * x.m_c[1]) + (-1.0f * x.m_c[0] * x.m_c[3]) + (x.m_c[2] * x.m_c[2])));
	}
	inline translator subtract(const scalar& x, const freeVector& y) {
		return translator(translator_scalar_e1ni_e2ni, x.m_c[0], (-1.0f * y.m_c[0]), (-1.0f * y.m_c[1]));
	}
	inline __syn_smv___e1_e2_ni_e1e2ni gp(const __syn_smv___scalar_e1e2_e2ni& x, const __syn_smv___e1_e2_ni& y) {
		return __syn_smv___e1_e2_ni_e1e2ni(__syn_smv___e1_e2_ni_e1e2ni_e1_e2_ni_e1e2ni, ((x.m_c[0] * y.m_c[0]) + (x.m_c[1] * y.m_c[1])), ((x.m_c[0] * y.m_c[1]) + (-1.0f * x.m_c[1] * y.m_c[0])), ((x.m_c[0] * y.m_c[2]) + (-1.0f * x.m_c[2] * y.m_c[1])), ((x.m_c[2] * y.m_c[0]) + (x.m_c[1] * y.m_c[2])));
	}
	inline __syn_smv___scalar_e1e2_e1ni gpEM(const __syn_smv___e1_e2_ni& x, const __e1_ct__& y) {
		return __syn_smv___scalar_e1e2_e1ni(__syn_smv___scalar_e1e2_e1ni_scalar_e1e2_e1ni, x.m_c[0], (-1.0f * x.m_c[1]), (-1.0f * x.m_c[2]));
	}
	inline __syn_smv___e1_e2_ni_nof2_0 add(const normalizedPoint& x, const normalizedPoint& y) {
		return __syn_smv___e1_e2_ni_nof2_0(__syn_smv___e1_e2_ni_nof2_0_e1_e2_ni_nof2_0, (x.m_c[0] + y.m_c[0]), (y.m_c[1] + x.m_c[1]), (x.m_c[2] + y.m_c[2]));
	}
	inline freeVector gp(const __syn_smv___e1_e2_ni& x, const __ni_ct__& y) {
		return freeVector(freeVector_e1ni_e2ni, x.m_c[0], x.m_c[1]);
	}
	inline __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni gp(const __syn_smv___scalar_noe1_noe2_noni& x, const __syn_smv___e1_e2_ni& y) {
		return __syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni(__syn_smv___no_e1_e2_noe1e2_ni_noe1ni_noe2ni_no_e1_e2_noe1e2_ni_noe1ni_noe2ni, ((x.m_c[2] * y.m_c[1]) + (x.m_c[1] * y.m_c[0])), ((x.m_c[0] * y.m_c[0]) + (x.m_c[1] * y.m_c[2])), ((x.m_c[2] * y.m_c[2]) + (x.m_c[0] * y.m_c[1])), ((x.m_c[1] * y.m_c[1]) + (-1.0f * x.m_c[2] * y.m_c[0])), ((x.m_c[0] * y.m_c[2]) + (x.m_c[3] * y.m_c[2])), ((x.m_c[1] * y.m_c[2]) + (-1.0f * x.m_c[3] * y.m_c[0])), ((x.m_c[2] * y.m_c[2]) + (-1.0f * x.m_c[3] * y.m_c[1])));
	}
	inline e2_t gp(const scalar& x, const __e2_ct__& y) {
		return e2_t(e2_t_e2, x.m_c[0]);
	}
	inline __syn_smv___scalar_e1e2_e1ni gp(const __syn_smv___e1_e2_ni& x, const __e1_ct__& y) {
		return __syn_smv___scalar_e1e2_e1ni(__syn_smv___scalar_e1e2_e1ni_scalar_e1e2_e1ni, x.m_c[0], (-1.0f * x.m_c[1]), (-1.0f * x.m_c[2]));
	}









} // end of namespace c2ga
// post_h_include


#endif //  _GA_c2ga_h_H_
