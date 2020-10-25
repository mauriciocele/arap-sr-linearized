
// Generated on 2007-08-08 10:15:12 by G2 0.1 from 'E:\gasandbox\ga_sandbox\libgasandbox\e2ga.gs2'

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

	#ifndef _GA_e2ga_h_H_
	#define _GA_e2ga_h_H_

	namespace e2ga {

	// multivector types:
	enum g2Type {
		MVT_NONE = -1,
			MVT_E1_T = 10,
			MVT_E2_T = 11,
			MVT_SCALAR = 12,
			MVT_VECTOR = 13,
			MVT_BIVECTOR = 14,
			MVT_ROTOR = 15,
			MVT___E1_CT__ = 16,
			MVT___E2_CT__ = 17,
			MVT___I2_CT__ = 18,
			MVT___I2I_CT__ = 19,
			MVT_MV = 8,
			MVT_LAST = 20 
	};

	// outermorphism types:
	enum omType {
		OMT_NONE = -2,
			OMT_OM = 9,
			OMT_LAST = 20 
	};

	// grade definitions that can be joined using the '|' operator:
	const int GRADE_0 = 1;
	const int GRADE_1 = 2;
	const int GRADE_2 = 4;

	// The dimension of the space:
	extern const int mv_spaceDim;

	// Is the metric of the space Euclidean?
	extern const bool mv_metricEuclidean;

	// This array can be used to lookup the number of coordinates for a grade part of a general multivector
	extern const int mv_gradeSize[3];

	// This array can be used to lookup the number of coordinates based on a grade usage bitmap
	extern const int mv_size[8];

	// This array of ASCIIZ strings contains the names of the basis vectors
	extern const char *mv_basisVectorNames[2];

	// This array of integers contains the order of basis elements in the general multivector
	// Use it to answer: 'what basis vectors are in the basis element at position [x]?
	extern const int mv_basisElements[4][3];

	// This array of integers contains the 'sign' (even/odd permutation of canonical order) of basis elements in the general multivector
	// Use it to answer 'what is the permutation of the coordinate at index [x]'?
	extern const double mv_basisElementSignByIndex[4];

	// This array of integers contains the 'sign' (even/odd permutation of canonical order) of basis elements in the general multivector
	// Use it to answer 'what is the permutation of the coordinate of bitmap [x]'?
	extern const double mv_basisElementSignByBitmap[4];

	// This array of integers contains the order of basis elements in the general multivector
	// Use it to answer: 'at what index do I find basis element [x] (x = basis vector bitmap)?'
	extern const int mv_basisElementIndexByBitmap[4];

	// This array of integers contains the indices of basis elements in the general multivector
	// Use it to answer: 'what basis element do I find at index [x]'?
	extern const int mv_basisElementBitmapByIndex[4];

	// This array of grade of each basis elements in the general multivector
	// Use it to answer: 'what is the grade of basis element bitmap [x]'?
	extern const int mv_basisElementGradeByBitmap[4];




	/* *************************************************************************** */
	/* *************************** define all classes upfront *************************** */
	/* *************************************************************************** */
	class e1_t;
	class e2_t;
	class scalar;
	class vector;
	class bivector;
	class rotor;
	class __e1_ct__;
	class __e2_ct__;
	class __I2_ct__;
	class __I2i_ct__;
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
		void save(const char *filename = "E:\\gasandbox\\ga_sandbox\\libgasandbox\\e2ga.gp2", bool append = true);
		void init(const char *filename = "E:\\gasandbox\\ga_sandbox\\libgasandbox\\e2ga.gp2",
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

		/// init from e1_t constructor
		inline mv(const e1_t &arg1) {
			set(arg1);
		}
		/// init from e2_t constructor
		inline mv(const e2_t &arg1) {
			set(arg1);
		}
		/// init from scalar constructor
		inline mv(const scalar &arg1) {
			set(arg1);
		}
		/// init from vector constructor
		inline mv(const vector &arg1) {
			set(arg1);
		}
		/// init from bivector constructor
		inline mv(const bivector &arg1) {
			set(arg1);
		}
		/// init from rotor constructor
		inline mv(const rotor &arg1) {
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
		/// init from __I2_ct__ constructor
		inline mv(const __I2_ct__ &arg1) {
			set(arg1);
		}
		/// init from __I2i_ct__ constructor
		inline mv(const __I2i_ct__ &arg1) {
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


		/// set to e1_t 
		void set(const e1_t &arg1);
		/// set to e2_t 
		void set(const e2_t &arg1);
		/// set to scalar 
		void set(const scalar &arg1);
		/// set to vector 
		void set(const vector &arg1);
		/// set to bivector 
		void set(const bivector &arg1);
		/// set to rotor 
		void set(const rotor &arg1);
		/// set to __e1_ct__ 
		void set(const __e1_ct__ &arg1);
		/// set to __e2_ct__ 
		void set(const __e2_ct__ &arg1);
		/// set to __I2_ct__ 
		void set(const __I2_ct__ &arg1);
		/// set to __I2i_ct__ 
		void set(const __I2i_ct__ &arg1);


		/// assign copy
		mv &operator=(const mv &arg1);

		/// assign scalar
		mv &operator=(Float scalar);

		/// assign e1_t 
		mv&operator=(const e1_t& arg1);
		/// assign e2_t 
		mv&operator=(const e2_t& arg1);
		/// assign scalar 
		mv&operator=(const scalar& arg1);
		/// assign vector 
		mv&operator=(const vector& arg1);
		/// assign bivector 
		mv&operator=(const bivector& arg1);
		/// assign rotor 
		mv&operator=(const rotor& arg1);
		/// assign __e1_ct__ 
		mv&operator=(const __e1_ct__& arg1);
		/// assign __e2_ct__ 
		mv&operator=(const __e2_ct__& arg1);
		/// assign __I2_ct__ 
		mv&operator=(const __I2_ct__& arg1);
		/// assign __I2i_ct__ 
		mv&operator=(const __I2i_ct__& arg1);


		void compress(Float epsilon = 0.0);
		inline Float const *nullFloats() const {
			static Float *nf = NULL;
			if (nf == NULL) nf = new Float[4];
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
		inline Float e1() const {
			if (gu() & 2)
				return m_c[mv_size[gu() & 1] + 0];
			else return (float)0.0;
		}
		inline Float e2() const {
			if (gu() & 2)
				return m_c[mv_size[gu() & 1] + 1];
			else return (float)0.0;
		}
		inline Float e1e2() const {
			if (gu() & 4)
				return m_c[mv_size[gu() & 3] + 0];
			else return (float)0.0;
		}

		// coordinate storage, grade usage
		Float m_c[4]; ///< coordinate storage (TODO: if parity pure, allocate only half of the coordinates!!!)
		unsigned int m_gu; ///< grade usage
		inline unsigned int gu() const {return m_gu;}
		inline void gu(unsigned int g) {m_gu = g;}



		inline const char * c_str(const char *fp = NULL) const {
			return ::e2ga::c_str(*this, fp);
		}
		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::e2ga::toString(*this, fp);
		}
		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}



	}; // end of class mv 

	char *string(const mv & obj, char *str, int maxLength, const char *fp = NULL);
	// this function should be deprecated (conflicts with C++ stdlib)
	char *string(const mv & obj, const char *fp = NULL);


	mv mv_compress(const float *coordinates, float epsilon = (float)0.0, int gu = 4 * 2 -1);
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
		}
		if (m_gu & 4) {
			if (m_c[idxC] != (Float)0.0) {
				bitmaps[idxB] = 3; coords[idxB] = m_c[idxC]; idxB++;}
			idxC++;
		}
		return idxB;
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
			return ::e2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::e2ga::toString(*this, fp);
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
			return ::e2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::e2ga::toString(*this, fp);
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
			return ::e2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::e2ga::toString(*this, fp);
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


	/// enum for the coordinates of vector 
	enum __vector_coordinates__ {vector_e1_e2};

	class vector {
		public:
			typedef float Float;

		/// zero constructor
		inline vector() {

			set();
		}

		/// scalar constructor 
		inline vector(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> vector	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline vector(const vector &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline vector(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> vector	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline vector(__vector_coordinates__, const Float *coordinates) {

			set(vector_e1_e2, coordinates);
		}

		/// coordinates constructor
		inline vector(__vector_coordinates__, Float c_e1, Float c_e2) {

			set(vector_e1_e2, c_e1, c_e2);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const vector &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__vector_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__vector_coordinates__, Float c_e1, Float c_e2);

		/// assign copy
		vector &operator=(const vector &arg1);

		/// assign general multivector
		vector &operator=(const mv &arg1);

		/// assign scalar
		vector &operator=(Float scalarVal);

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
		const Float *getC(__vector_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[2];



		inline const char * c_str(const char *fp = NULL) const {
			return ::e2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::e2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class vector 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline vector _vector(const mv &arg1) {
		return vector(arg1, 0);
	}
	/// from const specialization class:
	inline const vector &_vector(const vector &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline vector &_vector(vector &arg1) {
		return arg1;
	}
	/// from Float:
	inline vector _vector(vector::Float arg1) {
		return vector(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline vector like(const mv &what, const vector &example) {return _vector(what);}
	/// from const specialization class:
	inline const vector like(const vector &what, const vector &example) {return _vector(what);}
	/// from non-const specialization class:
	inline vector like(vector &what, const vector &example) {return _vector(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const vector & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const vector & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const vector & v) {
		return (float)0;
	}


	/// enum for the coordinates of bivector 
	enum __bivector_coordinates__ {bivector_e1e2};

	class bivector {
		public:
			typedef float Float;

		/// zero constructor
		inline bivector() {

			set();
		}

		/// scalar constructor 
		inline bivector(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> bivector	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline bivector(const bivector &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline bivector(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> bivector	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline bivector(__bivector_coordinates__, const Float *coordinates) {

			set(bivector_e1e2, coordinates);
		}

		/// coordinates constructor
		inline bivector(__bivector_coordinates__, Float c_e1e2) {

			set(bivector_e1e2, c_e1e2);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const bivector &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(__bivector_coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(__bivector_coordinates__, Float c_e1e2);

		/// assign copy
		bivector &operator=(const bivector &arg1);

		/// assign general multivector
		bivector &operator=(const mv &arg1);

		/// assign scalar
		bivector &operator=(Float scalarVal);

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
		const Float *getC(__bivector_coordinates__ sanityCheckValue) const {
			return m_c;
		}

		/// coordinate storage
		Float m_c[1];



		inline const char * c_str(const char *fp = NULL) const {
			return ::e2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::e2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class bivector 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline bivector _bivector(const mv &arg1) {
		return bivector(arg1, 0);
	}
	/// from const specialization class:
	inline const bivector &_bivector(const bivector &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline bivector &_bivector(bivector &arg1) {
		return arg1;
	}
	/// from Float:
	inline bivector _bivector(bivector::Float arg1) {
		return bivector(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline bivector like(const mv &what, const bivector &example) {return _bivector(what);}
	/// from const specialization class:
	inline const bivector like(const bivector &what, const bivector &example) {return _bivector(what);}
	/// from non-const specialization class:
	inline bivector like(bivector &what, const bivector &example) {return _bivector(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const bivector & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const bivector & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const bivector & v) {
		return (float)0;
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
			return ::e2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::e2ga::toString(*this, fp);
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
			return ::e2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::e2ga::toString(*this, fp);
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
			return ::e2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::e2ga::toString(*this, fp);
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
			return ::e2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::e2ga::toString(*this, fp);
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


	/// enum for the coordinates of __I2i_ct__ 
	enum ____I2i_ct___coordinates__ {__I2i_ct___e1e2f_1_0};

	class __I2i_ct__ {
		public:
			typedef float Float;

		/// zero constructor
		inline __I2i_ct__() {

			set();
		}

		/// scalar constructor 
		inline __I2i_ct__(Float s, int filler) { // filler can have any value, it simply prevents implicit conversion from Float -> __I2i_ct__	 
			set(s);
		}




		/// copy constructor (MUST PASS BY REFERENCE)
		inline __I2i_ct__(const __I2i_ct__ &arg1) {

			set(arg1);
		}

		/// general multivector constructor (that can not be selected for implicit conversion by C++)
		inline __I2i_ct__(const mv &arg1, int filler) { // filler can have any value, it simply prevents implicit conversion from mv -> __I2i_ct__	 
			set(arg1);
		}

		/// pointer to coordinates constructor
		inline __I2i_ct__(____I2i_ct___coordinates__, const Float *coordinates) {

			set(__I2i_ct___e1e2f_1_0, coordinates);
		}

		/// coordinates constructor
		inline __I2i_ct__(____I2i_ct___coordinates__) {

			set(__I2i_ct___e1e2f_1_0);
		}

		/// set to null
		void set();

		/// set to scalar
		void set(Float s);

		/// set to copy
		void set(const __I2i_ct__ &arg1);

		/// set to copy of general multivector
		void set(const mv &arg1);

		/// pointer to coordinates constructor
		void set(____I2i_ct___coordinates__, const Float *coordinates);

		/// set to coordinates
		void set(____I2i_ct___coordinates__);

		/// assign copy
		__I2i_ct__ &operator=(const __I2i_ct__ &arg1);

		/// assign general multivector
		__I2i_ct__ &operator=(const mv &arg1);

		/// assign scalar
		__I2i_ct__ &operator=(Float scalarVal);

		/// returns absolute largest coordinate
		Float largestCoordinate() const;
		/// returns the absolute largest coordinate, and the corresponding basis blade bitmap 
		Float largestBasisBlade(unsigned int &bm) const;

		/// coordinate extraction by name

		/// const coordinate extraction by name
		inline Float e1e2f_1_0() const {
			return -1.0f;
		}

		/// get all coordinates (returns NULL for fully constant specialization
		const Float *getC(____I2i_ct___coordinates__ sanityCheckValue) const {
			return NULL;
		}

		// constants, so no coordinate storage



		inline const char * c_str(const char *fp = NULL) const {
			return ::e2ga::c_str(*this, fp);
		}

		inline const char * c_str_f() const {return c_str("%f");}
		inline const char * c_str_e() const {return c_str("%e");}
		inline const char * c_str_e20() const {return c_str("%2.20e");}

		inline std::string toString(const char *fp = NULL) const {
			return ::e2ga::toString(*this, fp);
		}

		inline std::string toString_f() const {return toString("%f");}
		inline std::string toString_e() const {return toString("%e");}
		inline std::string toString_e20() const {return toString("%2.20e");}







	}; // end of class __I2i_ct__ 

	/* 'underscore constructors' */
	/// underscore constructor from general multivector:
	inline __I2i_ct__ ___I2i_ct__(const mv &arg1) {
		return __I2i_ct__(arg1, 0);
	}
	/// from const specialization class:
	inline const __I2i_ct__ &___I2i_ct__(const __I2i_ct__ &arg1) {
		return arg1;
	}
	/// from non-const specialization class:
	inline __I2i_ct__ &___I2i_ct__(__I2i_ct__ &arg1) {
		return arg1;
	}
	/// from Float:
	inline __I2i_ct__ ___I2i_ct__(__I2i_ct__::Float arg1) {
		return __I2i_ct__(arg1, 0); // 0 = filler; can have any value, it simply prevents implicit conversion from mv -> vector	 
	}



	// like example constructors, for use with templates
	/// underscore constructor from general multivector:
	inline __I2i_ct__ like(const mv &what, const __I2i_ct__ &example) {return ___I2i_ct__(what);}
	/// from const specialization class:
	inline const __I2i_ct__ like(const __I2i_ct__ &what, const __I2i_ct__ &example) {return ___I2i_ct__(what);}
	/// from non-const specialization class:
	inline __I2i_ct__ like(__I2i_ct__ &what, const __I2i_ct__ &example) {return ___I2i_ct__(what);}




	// underscore 'constructors' for float types:

	/// returns scalar part of v as float
	inline float _float(const __I2i_ct__ & v) {
		return (float)0;
	}
	/// returns scalar part of v as double
	inline double _double(const __I2i_ct__ & v) {
		return (double)0;
	}
	/// returns scalar part of v as Float
	inline float _Float(const __I2i_ct__ & v) {
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
		inline om(const vector *vectors) {
			set(vectors);
		}

		/// constructor from basis vectors 
		inline om(const vector & image_of_e1, const vector & image_of_e2) {
			set(image_of_e1, image_of_e2);
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
		void set(const vector *vectors);

		/// set from basis vectors 
		void set(
			const vector & image_of_e1, const vector & image_of_e2);


		/// assign copy
		om &operator=(const om &arg1);

		/// assign scalar (creates scalar * 'I' outermorphism)
		om &operator=(Float scalarVal);

		/// assign specialization:


		Float m_c[5]; ///< coordinate storage




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



	mv::Float fastFactorBlade(const mv &X, vector factor[], int gradeOfX = -1);
	void fastJoinBlades(const mv &A, const mv &B, mv &J, mv *M = NULL);



	// extra underscore constructors from profile:


	extern __I2i_ct__ I2i;
	extern __I2_ct__ I2;
	extern __e1_ct__ e1;
	extern __e2_ct__ e2;
	mv lcont(const mv& x, const mv& y);
	scalar scp(const mv& x, const mv& y);
	mv gp(const mv& x, const mv& y);
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
	mv apply_om(const om& x, const mv& y);
	mv gradeInvolution(const mv& x);
	namespace __G2_GENERATED__ {
		void set(om& __x__, const vector& __image_of_e1__, const vector& __image_of_e2__);
	} /* end of namespace __G2_GENERATED__ */
	inline vector unit_e(const vector& x);
	inline vector inverse(const vector& x);
	inline rotor gp(const vector& x, const __e1_ct__& y);
	inline bivector gradeInvolution(const bivector& x);
	inline e1_t gp(const scalar& x, const __e1_ct__& y);
	inline scalar subtract(const scalar& x, const scalar& y);
	inline rotor subtract(const rotor& x, const rotor& y);
	inline vector subtract(const vector& x, const vector& y);
	inline scalar scp(const bivector& x, const bivector& y);
	inline vector add(const e1_t& x, const e2_t& y);
	inline e1_t gp(const bivector& x, const __e2_ct__& y);
	inline scalar norm_e2(const vector& x);
	inline scalar norm_e(const bivector& x);
	inline rotor gp(const vector& x, const __e2_ct__& y);
	inline scalar gp(const bivector& x, const bivector& y);
	inline bivector op(const vector& x, const vector& y);
	inline vector subtract(const e1_t& x, const e2_t& y);
	inline vector add(const vector& x, const vector& y);
	inline vector gradeInvolution(const vector& x);
	inline scalar norm_e(const vector& x);
	inline bivector inverse(const bivector& x);
	inline e2_t gp(const bivector& x, const __e1_ct__& y);
	inline rotor gp(const vector& x, const vector& y);
	inline vector gp(const vector& x, const scalar& y);
	inline bivector reverse(const bivector& x);
	inline vector reverse(const vector& x);
	inline e1_t gp(const e2_t& x, const bivector& y);
	inline vector gp(const scalar& x, const vector& y);
	inline e2_t gp(const e1_t& x, const bivector& y);
	inline vector gp(const rotor& x, const vector& y);
	inline e2_t gp(const scalar& x, const __e2_ct__& y);
	inline scalar scp(const vector& x, const vector& y);
	inline mv operator+=(mv& arg1, const mv& arg2);
	inline e1_t operator+=(e1_t& arg1, const e2_t& arg2);
	inline vector operator+=(vector& arg1, const vector& arg2);
	inline e2_t operator+=(e2_t& arg1, const mv& arg2);
	inline scalar operator+=(scalar& arg1, const mv& arg2);
	inline bivector operator+=(bivector& arg1, const mv& arg2);
	inline rotor operator+=(rotor& arg1, const mv& arg2);
	inline __e1_ct__ operator+=(__e1_ct__& arg1, const mv& arg2);
	inline __e2_ct__ operator+=(__e2_ct__& arg1, const mv& arg2);
	inline __I2_ct__ operator+=(__I2_ct__& arg1, const mv& arg2);
	inline __I2i_ct__ operator+=(__I2i_ct__& arg1, const mv& arg2);
	inline mv operator+(const mv& arg1, const mv& arg2);
	inline vector operator+(const e1_t& arg1, const e2_t& arg2);
	inline vector operator+(const vector& arg1, const vector& arg2);
	inline mv operator-=(mv& arg1, const mv& arg2);
	inline scalar operator-=(scalar& arg1, const scalar& arg2);
	inline scalar operator-=(scalar& arg1, float arg2);
	inline rotor operator-=(rotor& arg1, const rotor& arg2);
	inline vector operator-=(vector& arg1, const vector& arg2);
	inline e1_t operator-=(e1_t& arg1, const e2_t& arg2);
	inline e2_t operator-=(e2_t& arg1, const mv& arg2);
	inline bivector operator-=(bivector& arg1, const mv& arg2);
	inline __e1_ct__ operator-=(__e1_ct__& arg1, const mv& arg2);
	inline __e2_ct__ operator-=(__e2_ct__& arg1, const mv& arg2);
	inline __I2_ct__ operator-=(__I2_ct__& arg1, const mv& arg2);
	inline __I2i_ct__ operator-=(__I2i_ct__& arg1, const mv& arg2);
	inline mv operator-(const mv& arg1, const mv& arg2);
	inline scalar operator-(const scalar& arg1, const scalar& arg2);
	inline scalar operator-(float arg1, const scalar& arg2);
	inline scalar operator-(const scalar& arg1, float arg2);
	inline rotor operator-(const rotor& arg1, const rotor& arg2);
	inline vector operator-(const vector& arg1, const vector& arg2);
	inline vector operator-(const e1_t& arg1, const e2_t& arg2);
	inline mv operator-(const mv& arg1);
	inline mv operator%=(mv& arg1, const mv& arg2);
	inline bivector operator%=(bivector& arg1, const bivector& arg2);
	inline vector operator%=(vector& arg1, const vector& arg2);
	inline e1_t operator%=(e1_t& arg1, const mv& arg2);
	inline e2_t operator%=(e2_t& arg1, const mv& arg2);
	inline scalar operator%=(scalar& arg1, const mv& arg2);
	inline rotor operator%=(rotor& arg1, const mv& arg2);
	inline __e1_ct__ operator%=(__e1_ct__& arg1, const mv& arg2);
	inline __e2_ct__ operator%=(__e2_ct__& arg1, const mv& arg2);
	inline __I2_ct__ operator%=(__I2_ct__& arg1, const mv& arg2);
	inline __I2i_ct__ operator%=(__I2i_ct__& arg1, const mv& arg2);
	inline scalar operator%(const mv& arg1, const mv& arg2);
	inline scalar operator%(const bivector& arg1, const bivector& arg2);
	inline scalar operator%(const vector& arg1, const vector& arg2);
	inline mv operator^=(mv& arg1, const mv& arg2);
	inline vector operator^=(vector& arg1, const vector& arg2);
	inline e1_t operator^=(e1_t& arg1, const mv& arg2);
	inline e2_t operator^=(e2_t& arg1, const mv& arg2);
	inline scalar operator^=(scalar& arg1, const mv& arg2);
	inline bivector operator^=(bivector& arg1, const mv& arg2);
	inline rotor operator^=(rotor& arg1, const mv& arg2);
	inline __e1_ct__ operator^=(__e1_ct__& arg1, const mv& arg2);
	inline __e2_ct__ operator^=(__e2_ct__& arg1, const mv& arg2);
	inline __I2_ct__ operator^=(__I2_ct__& arg1, const mv& arg2);
	inline __I2i_ct__ operator^=(__I2i_ct__& arg1, const mv& arg2);
	inline mv operator^(const mv& arg1, const mv& arg2);
	inline bivector operator^(const vector& arg1, const vector& arg2);
	inline mv operator*=(mv& arg1, const mv& arg2);
	inline vector operator*=(vector& arg1, const __e1_ct__& arg2);
	inline scalar operator*=(scalar& arg1, const __e1_ct__& arg2);
	inline bivector operator*=(bivector& arg1, const __e2_ct__& arg2);
	inline vector operator*=(vector& arg1, const __e2_ct__& arg2);
	inline bivector operator*=(bivector& arg1, const bivector& arg2);
	inline bivector operator*=(bivector& arg1, const __e1_ct__& arg2);
	inline vector operator*=(vector& arg1, const vector& arg2);
	inline vector operator*=(vector& arg1, const scalar& arg2);
	inline vector operator*=(vector& arg1, float arg2);
	inline e2_t operator*=(e2_t& arg1, const bivector& arg2);
	inline scalar operator*=(scalar& arg1, const vector& arg2);
	inline e1_t operator*=(e1_t& arg1, const bivector& arg2);
	inline rotor operator*=(rotor& arg1, const vector& arg2);
	inline scalar operator*=(scalar& arg1, const __e2_ct__& arg2);
	inline __e1_ct__ operator*=(__e1_ct__& arg1, const mv& arg2);
	inline __e2_ct__ operator*=(__e2_ct__& arg1, const mv& arg2);
	inline __I2_ct__ operator*=(__I2_ct__& arg1, const mv& arg2);
	inline __I2i_ct__ operator*=(__I2i_ct__& arg1, const mv& arg2);
	inline mv operator*(const mv& arg1, const mv& arg2);
	inline rotor operator*(const vector& arg1, const __e1_ct__& arg2);
	inline e1_t operator*(const scalar& arg1, const __e1_ct__& arg2);
	inline e1_t operator*(float arg1, const __e1_ct__& arg2);
	inline e1_t operator*(const bivector& arg1, const __e2_ct__& arg2);
	inline rotor operator*(const vector& arg1, const __e2_ct__& arg2);
	inline scalar operator*(const bivector& arg1, const bivector& arg2);
	inline e2_t operator*(const bivector& arg1, const __e1_ct__& arg2);
	inline rotor operator*(const vector& arg1, const vector& arg2);
	inline vector operator*(const vector& arg1, const scalar& arg2);
	inline vector operator*(const vector& arg1, float arg2);
	inline e1_t operator*(const e2_t& arg1, const bivector& arg2);
	inline vector operator*(const scalar& arg1, const vector& arg2);
	inline vector operator*(float arg1, const vector& arg2);
	inline e2_t operator*(const e1_t& arg1, const bivector& arg2);
	inline vector operator*(const rotor& arg1, const vector& arg2);
	inline e2_t operator*(const scalar& arg1, const __e2_ct__& arg2);
	inline e2_t operator*(float arg1, const __e2_ct__& arg2);
	inline mv operator<<=(mv& arg1, const mv& arg2);
	inline e1_t operator<<=(e1_t& arg1, const mv& arg2);
	inline e2_t operator<<=(e2_t& arg1, const mv& arg2);
	inline scalar operator<<=(scalar& arg1, const mv& arg2);
	inline vector operator<<=(vector& arg1, const mv& arg2);
	inline bivector operator<<=(bivector& arg1, const mv& arg2);
	inline rotor operator<<=(rotor& arg1, const mv& arg2);
	inline __e1_ct__ operator<<=(__e1_ct__& arg1, const mv& arg2);
	inline __e2_ct__ operator<<=(__e2_ct__& arg1, const mv& arg2);
	inline __I2_ct__ operator<<=(__I2_ct__& arg1, const mv& arg2);
	inline __I2i_ct__ operator<<=(__I2i_ct__& arg1, const mv& arg2);
	inline mv operator<<(const mv& arg1, const mv& arg2);
	inline mv operator*(const mv& arg1);
	inline mv operator!(const mv& arg1);
	inline vector operator!(const vector& arg1);
	inline bivector operator!(const bivector& arg1);
	inline mv operator~(const mv& arg1);
	inline bivector operator~(const bivector& arg1);
	inline vector operator~(const vector& arg1);














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
	inline void vector::set() {
		// set coordinates to 0
		mv_zero(m_c, 2);

	}

	// set to scalar 
	inline void vector::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;
		m_c[1] = (Float)0.0;

	}


	// set to copy
	inline void vector::set(const vector &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 2);
		m_c[0] = arg1.m_c[0];
		m_c[1] = arg1.m_c[1];

	}

	// set to pointer to coordinates
	inline void vector::set(__vector_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 2);
		m_c[0] = coordinates[0];
		m_c[1] = coordinates[1];

	}

	// set to 'coordinates specified' 
	inline void vector::set(__vector_coordinates__, Float c_e1, Float c_e2) {
		// set coordinates
		m_c[0] = c_e1;
		m_c[1] = c_e2;

	}





	// assign copy
	inline vector &vector::operator=(const vector &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline vector &vector::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline vector &vector::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}






	// set to zero
	inline void bivector::set() {
		// set coordinates to 0
		mv_zero(m_c, 1);

	}

	// set to scalar 
	inline void bivector::set(Float s) {
		// set coordinates 0, except for scalar (if any)
		m_c[0] = (Float)0.0;

	}


	// set to copy
	inline void bivector::set(const bivector &arg1) {
		// copy coordinates
		//mv_memcpy(m_c, arg1.m_c, 1);
		m_c[0] = arg1.m_c[0];

	}

	// set to pointer to coordinates
	inline void bivector::set(__bivector_coordinates__, const Float *coordinates) {
		// copy coordinates
		//mv_memcpy(m_c, coordinates, 1);
		m_c[0] = coordinates[0];

	}

	// set to 'coordinates specified' 
	inline void bivector::set(__bivector_coordinates__, Float c_e1e2) {
		// set coordinates
		m_c[0] = c_e1e2;

	}





	// assign copy
	inline bivector &bivector::operator=(const bivector &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline bivector &bivector::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline bivector &bivector::operator=(Float scalarVal) {
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
	inline void __I2i_ct__::set() {
		// set coordinates to 0
	}

	// set to scalar 
	inline void __I2i_ct__::set(Float s) {
		// set coordinates 0, except for scalar (if any)

	}


	// set to copy
	inline void __I2i_ct__::set(const __I2i_ct__ &arg1) {
	}

	// set to pointer to coordinates
	inline void __I2i_ct__::set(____I2i_ct___coordinates__, const Float *coordinates) {
		// copy coordinates
	}

	// set to 'coordinates specified' 
	inline void __I2i_ct__::set(____I2i_ct___coordinates__) {
		// set coordinates

	}





	// assign copy
	inline __I2i_ct__ &__I2i_ct__::operator=(const __I2i_ct__ &arg1) {
		set(arg1);
		return *this;
	}

	// assign general multivector
	inline __I2i_ct__ &__I2i_ct__::operator=(const mv &arg1) {
		set(arg1);
		return *this;
	}

	// assign scalar
	inline __I2i_ct__ &__I2i_ct__::operator=(Float scalarVal) {
		set(scalarVal);
		return *this;
	}










	inline mv operator+=(mv& arg1, const mv& arg2) {
		arg1.set(::e2ga::add(arg1, arg2));
		return arg1;
	}
	inline e1_t operator+=(e1_t& arg1, const e2_t& arg2) {
		arg1.set(::e2ga::add(arg1, arg2));
		return arg1;
	}
	inline vector operator+=(vector& arg1, const vector& arg2) {
		arg1.set(::e2ga::add(arg1, arg2));
		return arg1;
	}
	inline e2_t operator+=(e2_t& arg1, const mv& arg2) {
		arg1.set(::e2ga::add(arg1, arg2));
		return arg1;
	}
	inline scalar operator+=(scalar& arg1, const mv& arg2) {
		arg1.set(::e2ga::add(arg1, arg2));
		return arg1;
	}
	inline bivector operator+=(bivector& arg1, const mv& arg2) {
		arg1.set(::e2ga::add(arg1, arg2));
		return arg1;
	}
	inline rotor operator+=(rotor& arg1, const mv& arg2) {
		arg1.set(::e2ga::add(arg1, arg2));
		return arg1;
	}
	inline __e1_ct__ operator+=(__e1_ct__& arg1, const mv& arg2) {
		arg1.set(::e2ga::add(arg1, arg2));
		return arg1;
	}
	inline __e2_ct__ operator+=(__e2_ct__& arg1, const mv& arg2) {
		arg1.set(::e2ga::add(arg1, arg2));
		return arg1;
	}
	inline __I2_ct__ operator+=(__I2_ct__& arg1, const mv& arg2) {
		arg1.set(::e2ga::add(arg1, arg2));
		return arg1;
	}
	inline __I2i_ct__ operator+=(__I2i_ct__& arg1, const mv& arg2) {
		arg1.set(::e2ga::add(arg1, arg2));
		return arg1;
	}
	inline mv operator+(const mv& arg1, const mv& arg2) {
		return ::e2ga::add(arg1, arg2);
	}
	inline vector operator+(const e1_t& arg1, const e2_t& arg2) {
		return ::e2ga::add(arg1, arg2);
	}
	inline vector operator+(const vector& arg1, const vector& arg2) {
		return ::e2ga::add(arg1, arg2);
	}
	inline mv operator-=(mv& arg1, const mv& arg2) {
		arg1.set(::e2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline scalar operator-=(scalar& arg1, const scalar& arg2) {
		arg1.set(::e2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline scalar operator-=(scalar& arg1, float arg2) {
		arg1.set(::e2ga::subtract(arg1, ::e2ga::scalar(arg2)));
		return arg1;
	}
	inline rotor operator-=(rotor& arg1, const rotor& arg2) {
		arg1.set(::e2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline vector operator-=(vector& arg1, const vector& arg2) {
		arg1.set(::e2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline e1_t operator-=(e1_t& arg1, const e2_t& arg2) {
		arg1.set(::e2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline e2_t operator-=(e2_t& arg1, const mv& arg2) {
		arg1.set(::e2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline bivector operator-=(bivector& arg1, const mv& arg2) {
		arg1.set(::e2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __e1_ct__ operator-=(__e1_ct__& arg1, const mv& arg2) {
		arg1.set(::e2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __e2_ct__ operator-=(__e2_ct__& arg1, const mv& arg2) {
		arg1.set(::e2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __I2_ct__ operator-=(__I2_ct__& arg1, const mv& arg2) {
		arg1.set(::e2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline __I2i_ct__ operator-=(__I2i_ct__& arg1, const mv& arg2) {
		arg1.set(::e2ga::subtract(arg1, arg2));
		return arg1;
	}
	inline mv operator-(const mv& arg1, const mv& arg2) {
		return ::e2ga::subtract(arg1, arg2);
	}
	inline scalar operator-(const scalar& arg1, const scalar& arg2) {
		return ::e2ga::subtract(arg1, arg2);
	}
	inline scalar operator-(float arg1, const scalar& arg2) {
		return ::e2ga::subtract(::e2ga::scalar(arg1), arg2);
	}
	inline scalar operator-(const scalar& arg1, float arg2) {
		return ::e2ga::subtract(arg1, ::e2ga::scalar(arg2));
	}
	inline rotor operator-(const rotor& arg1, const rotor& arg2) {
		return ::e2ga::subtract(arg1, arg2);
	}
	inline vector operator-(const vector& arg1, const vector& arg2) {
		return ::e2ga::subtract(arg1, arg2);
	}
	inline vector operator-(const e1_t& arg1, const e2_t& arg2) {
		return ::e2ga::subtract(arg1, arg2);
	}
	inline mv operator-(const mv& arg1) {
		return ::e2ga::negate(arg1);
	}
	inline mv operator%=(mv& arg1, const mv& arg2) {
		arg1.set(::e2ga::scp(arg1, arg2));
		return arg1;
	}
	inline bivector operator%=(bivector& arg1, const bivector& arg2) {
		arg1.set(::e2ga::scp(arg1, arg2));
		return arg1;
	}
	inline vector operator%=(vector& arg1, const vector& arg2) {
		arg1.set(::e2ga::scp(arg1, arg2));
		return arg1;
	}
	inline e1_t operator%=(e1_t& arg1, const mv& arg2) {
		arg1.set(::e2ga::scp(arg1, arg2));
		return arg1;
	}
	inline e2_t operator%=(e2_t& arg1, const mv& arg2) {
		arg1.set(::e2ga::scp(arg1, arg2));
		return arg1;
	}
	inline scalar operator%=(scalar& arg1, const mv& arg2) {
		arg1.set(::e2ga::scp(arg1, arg2));
		return arg1;
	}
	inline rotor operator%=(rotor& arg1, const mv& arg2) {
		arg1.set(::e2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __e1_ct__ operator%=(__e1_ct__& arg1, const mv& arg2) {
		arg1.set(::e2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __e2_ct__ operator%=(__e2_ct__& arg1, const mv& arg2) {
		arg1.set(::e2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __I2_ct__ operator%=(__I2_ct__& arg1, const mv& arg2) {
		arg1.set(::e2ga::scp(arg1, arg2));
		return arg1;
	}
	inline __I2i_ct__ operator%=(__I2i_ct__& arg1, const mv& arg2) {
		arg1.set(::e2ga::scp(arg1, arg2));
		return arg1;
	}
	inline scalar operator%(const mv& arg1, const mv& arg2) {
		return ::e2ga::scp(arg1, arg2);
	}
	inline scalar operator%(const bivector& arg1, const bivector& arg2) {
		return ::e2ga::scp(arg1, arg2);
	}
	inline scalar operator%(const vector& arg1, const vector& arg2) {
		return ::e2ga::scp(arg1, arg2);
	}
	inline mv operator^=(mv& arg1, const mv& arg2) {
		arg1.set(::e2ga::op(arg1, arg2));
		return arg1;
	}
	inline vector operator^=(vector& arg1, const vector& arg2) {
		arg1.set(::e2ga::op(arg1, arg2));
		return arg1;
	}
	inline e1_t operator^=(e1_t& arg1, const mv& arg2) {
		arg1.set(::e2ga::op(arg1, arg2));
		return arg1;
	}
	inline e2_t operator^=(e2_t& arg1, const mv& arg2) {
		arg1.set(::e2ga::op(arg1, arg2));
		return arg1;
	}
	inline scalar operator^=(scalar& arg1, const mv& arg2) {
		arg1.set(::e2ga::op(arg1, arg2));
		return arg1;
	}
	inline bivector operator^=(bivector& arg1, const mv& arg2) {
		arg1.set(::e2ga::op(arg1, arg2));
		return arg1;
	}
	inline rotor operator^=(rotor& arg1, const mv& arg2) {
		arg1.set(::e2ga::op(arg1, arg2));
		return arg1;
	}
	inline __e1_ct__ operator^=(__e1_ct__& arg1, const mv& arg2) {
		arg1.set(::e2ga::op(arg1, arg2));
		return arg1;
	}
	inline __e2_ct__ operator^=(__e2_ct__& arg1, const mv& arg2) {
		arg1.set(::e2ga::op(arg1, arg2));
		return arg1;
	}
	inline __I2_ct__ operator^=(__I2_ct__& arg1, const mv& arg2) {
		arg1.set(::e2ga::op(arg1, arg2));
		return arg1;
	}
	inline __I2i_ct__ operator^=(__I2i_ct__& arg1, const mv& arg2) {
		arg1.set(::e2ga::op(arg1, arg2));
		return arg1;
	}
	inline mv operator^(const mv& arg1, const mv& arg2) {
		return ::e2ga::op(arg1, arg2);
	}
	inline bivector operator^(const vector& arg1, const vector& arg2) {
		return ::e2ga::op(arg1, arg2);
	}
	inline mv operator*=(mv& arg1, const mv& arg2) {
		arg1.set(::e2ga::gp(arg1, arg2));
		return arg1;
	}
	inline vector operator*=(vector& arg1, const __e1_ct__& arg2) {
		arg1.set(::e2ga::gp(arg1, arg2));
		return arg1;
	}
	inline scalar operator*=(scalar& arg1, const __e1_ct__& arg2) {
		arg1.set(::e2ga::gp(arg1, arg2));
		return arg1;
	}
	inline bivector operator*=(bivector& arg1, const __e2_ct__& arg2) {
		arg1.set(::e2ga::gp(arg1, arg2));
		return arg1;
	}
	inline vector operator*=(vector& arg1, const __e2_ct__& arg2) {
		arg1.set(::e2ga::gp(arg1, arg2));
		return arg1;
	}
	inline bivector operator*=(bivector& arg1, const bivector& arg2) {
		arg1.set(::e2ga::gp(arg1, arg2));
		return arg1;
	}
	inline bivector operator*=(bivector& arg1, const __e1_ct__& arg2) {
		arg1.set(::e2ga::gp(arg1, arg2));
		return arg1;
	}
	inline vector operator*=(vector& arg1, const vector& arg2) {
		arg1.set(::e2ga::gp(arg1, arg2));
		return arg1;
	}
	inline vector operator*=(vector& arg1, const scalar& arg2) {
		arg1.set(::e2ga::gp(arg1, arg2));
		return arg1;
	}
	inline vector operator*=(vector& arg1, float arg2) {
		arg1.set(::e2ga::gp(arg1, ::e2ga::scalar(arg2)));
		return arg1;
	}
	inline e2_t operator*=(e2_t& arg1, const bivector& arg2) {
		arg1.set(::e2ga::gp(arg1, arg2));
		return arg1;
	}
	inline scalar operator*=(scalar& arg1, const vector& arg2) {
		arg1.set(::e2ga::gp(arg1, arg2));
		return arg1;
	}
	inline e1_t operator*=(e1_t& arg1, const bivector& arg2) {
		arg1.set(::e2ga::gp(arg1, arg2));
		return arg1;
	}
	inline rotor operator*=(rotor& arg1, const vector& arg2) {
		arg1.set(::e2ga::gp(arg1, arg2));
		return arg1;
	}
	inline scalar operator*=(scalar& arg1, const __e2_ct__& arg2) {
		arg1.set(::e2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __e1_ct__ operator*=(__e1_ct__& arg1, const mv& arg2) {
		arg1.set(::e2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __e2_ct__ operator*=(__e2_ct__& arg1, const mv& arg2) {
		arg1.set(::e2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __I2_ct__ operator*=(__I2_ct__& arg1, const mv& arg2) {
		arg1.set(::e2ga::gp(arg1, arg2));
		return arg1;
	}
	inline __I2i_ct__ operator*=(__I2i_ct__& arg1, const mv& arg2) {
		arg1.set(::e2ga::gp(arg1, arg2));
		return arg1;
	}
	inline mv operator*(const mv& arg1, const mv& arg2) {
		return ::e2ga::gp(arg1, arg2);
	}
	inline rotor operator*(const vector& arg1, const __e1_ct__& arg2) {
		return ::e2ga::gp(arg1, arg2);
	}
	inline e1_t operator*(const scalar& arg1, const __e1_ct__& arg2) {
		return ::e2ga::gp(arg1, arg2);
	}
	inline e1_t operator*(float arg1, const __e1_ct__& arg2) {
		return ::e2ga::gp(::e2ga::scalar(arg1), arg2);
	}
	inline e1_t operator*(const bivector& arg1, const __e2_ct__& arg2) {
		return ::e2ga::gp(arg1, arg2);
	}
	inline rotor operator*(const vector& arg1, const __e2_ct__& arg2) {
		return ::e2ga::gp(arg1, arg2);
	}
	inline scalar operator*(const bivector& arg1, const bivector& arg2) {
		return ::e2ga::gp(arg1, arg2);
	}
	inline e2_t operator*(const bivector& arg1, const __e1_ct__& arg2) {
		return ::e2ga::gp(arg1, arg2);
	}
	inline rotor operator*(const vector& arg1, const vector& arg2) {
		return ::e2ga::gp(arg1, arg2);
	}
	inline vector operator*(const vector& arg1, const scalar& arg2) {
		return ::e2ga::gp(arg1, arg2);
	}
	inline vector operator*(const vector& arg1, float arg2) {
		return ::e2ga::gp(arg1, ::e2ga::scalar(arg2));
	}
	inline e1_t operator*(const e2_t& arg1, const bivector& arg2) {
		return ::e2ga::gp(arg1, arg2);
	}
	inline vector operator*(const scalar& arg1, const vector& arg2) {
		return ::e2ga::gp(arg1, arg2);
	}
	inline vector operator*(float arg1, const vector& arg2) {
		return ::e2ga::gp(::e2ga::scalar(arg1), arg2);
	}
	inline e2_t operator*(const e1_t& arg1, const bivector& arg2) {
		return ::e2ga::gp(arg1, arg2);
	}
	inline vector operator*(const rotor& arg1, const vector& arg2) {
		return ::e2ga::gp(arg1, arg2);
	}
	inline e2_t operator*(const scalar& arg1, const __e2_ct__& arg2) {
		return ::e2ga::gp(arg1, arg2);
	}
	inline e2_t operator*(float arg1, const __e2_ct__& arg2) {
		return ::e2ga::gp(::e2ga::scalar(arg1), arg2);
	}
	inline mv operator<<=(mv& arg1, const mv& arg2) {
		arg1.set(::e2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline e1_t operator<<=(e1_t& arg1, const mv& arg2) {
		arg1.set(::e2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline e2_t operator<<=(e2_t& arg1, const mv& arg2) {
		arg1.set(::e2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline scalar operator<<=(scalar& arg1, const mv& arg2) {
		arg1.set(::e2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline vector operator<<=(vector& arg1, const mv& arg2) {
		arg1.set(::e2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline bivector operator<<=(bivector& arg1, const mv& arg2) {
		arg1.set(::e2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline rotor operator<<=(rotor& arg1, const mv& arg2) {
		arg1.set(::e2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __e1_ct__ operator<<=(__e1_ct__& arg1, const mv& arg2) {
		arg1.set(::e2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __e2_ct__ operator<<=(__e2_ct__& arg1, const mv& arg2) {
		arg1.set(::e2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __I2_ct__ operator<<=(__I2_ct__& arg1, const mv& arg2) {
		arg1.set(::e2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline __I2i_ct__ operator<<=(__I2i_ct__& arg1, const mv& arg2) {
		arg1.set(::e2ga::lcont(arg1, arg2));
		return arg1;
	}
	inline mv operator<<(const mv& arg1, const mv& arg2) {
		return ::e2ga::lcont(arg1, arg2);
	}
	inline mv operator*(const mv& arg1) {
		return ::e2ga::dual(arg1);
	}
	inline mv operator!(const mv& arg1) {
		return ::e2ga::inverse(arg1);
	}
	inline vector operator!(const vector& arg1) {
		return ::e2ga::inverse(arg1);
	}
	inline bivector operator!(const bivector& arg1) {
		return ::e2ga::inverse(arg1);
	}
	inline mv operator~(const mv& arg1) {
		return ::e2ga::reverse(arg1);
	}
	inline bivector operator~(const bivector& arg1) {
		return ::e2ga::reverse(arg1);
	}
	inline vector operator~(const vector& arg1) {
		return ::e2ga::reverse(arg1);
	}


	// G2 functions:
	inline vector unit_e(const vector& x) {
		scalar e2;
		e2.m_c[0] = ((x.m_c[0] * x.m_c[0]) + (x.m_c[1] * x.m_c[1]));
		scalar ie;
		ie.m_c[0] = ((char)1 / sqrt(e2.m_c[0]));
		return vector(vector_e1_e2, (x.m_c[0] * ie.m_c[0]), (x.m_c[1] * ie.m_c[0]));
	}
	inline vector inverse(const vector& x) {
		scalar n;
		n.m_c[0] = ((x.m_c[1] * x.m_c[1]) + (x.m_c[0] * x.m_c[0]));
		scalar in;
		in.m_c[0] = ((char)1 / n.m_c[0]);
		return vector(vector_e1_e2, (x.m_c[0] * in.m_c[0]), (x.m_c[1] * in.m_c[0]));
	}
	inline rotor gp(const vector& x, const __e1_ct__& y) {
		return rotor(rotor_scalar_e1e2, x.m_c[0], (-1.0f * x.m_c[1]));
	}
	inline bivector gradeInvolution(const bivector& x) {
		return bivector(bivector_e1e2, x.m_c[0]);
	}
	inline e1_t gp(const scalar& x, const __e1_ct__& y) {
		return e1_t(e1_t_e1, x.m_c[0]);
	}
	inline scalar subtract(const scalar& x, const scalar& y) {
		return scalar(scalar_scalar, ((-1.0f * y.m_c[0]) + x.m_c[0]));
	}
	inline rotor subtract(const rotor& x, const rotor& y) {
		return rotor(rotor_scalar_e1e2, ((-1.0f * y.m_c[0]) + x.m_c[0]), (x.m_c[1] + (-1.0f * y.m_c[1])));
	}
	inline vector subtract(const vector& x, const vector& y) {
		return vector(vector_e1_e2, (x.m_c[0] + (-1.0f * y.m_c[0])), ((-1.0f * y.m_c[1]) + x.m_c[1]));
	}
	inline scalar scp(const bivector& x, const bivector& y) {
		return scalar(scalar_scalar, (-1.0f * x.m_c[0] * y.m_c[0]));
	}
	inline vector add(const e1_t& x, const e2_t& y) {
		return vector(vector_e1_e2, x.m_c[0], y.m_c[0]);
	}
	inline e1_t gp(const bivector& x, const __e2_ct__& y) {
		return e1_t(e1_t_e1, x.m_c[0]);
	}
	inline scalar norm_e2(const vector& x) {
		return scalar(scalar_scalar, ((x.m_c[0] * x.m_c[0]) + (x.m_c[1] * x.m_c[1])));
	}
	inline scalar norm_e(const bivector& x) {
		scalar e2;
		e2.m_c[0] = (x.m_c[0] * x.m_c[0]);
		return scalar(scalar_scalar, sqrt(e2.m_c[0]));
	}
	inline rotor gp(const vector& x, const __e2_ct__& y) {
		return rotor(rotor_scalar_e1e2, x.m_c[1], x.m_c[0]);
	}
	inline scalar gp(const bivector& x, const bivector& y) {
		return scalar(scalar_scalar, (-1.0f * x.m_c[0] * y.m_c[0]));
	}
	inline bivector op(const vector& x, const vector& y) {
		return bivector(bivector_e1e2, ((x.m_c[0] * y.m_c[1]) + (-1.0f * x.m_c[1] * y.m_c[0])));
	}
	inline vector subtract(const e1_t& x, const e2_t& y) {
		return vector(vector_e1_e2, x.m_c[0], (-1.0f * y.m_c[0]));
	}
	inline vector add(const vector& x, const vector& y) {
		return vector(vector_e1_e2, (y.m_c[0] + x.m_c[0]), (y.m_c[1] + x.m_c[1]));
	}
	inline vector gradeInvolution(const vector& x) {
		return vector(vector_e1_e2, (-1.0f * x.m_c[0]), (-1.0f * x.m_c[1]));
	}
	inline scalar norm_e(const vector& x) {
		scalar e2;
		e2.m_c[0] = ((x.m_c[0] * x.m_c[0]) + (x.m_c[1] * x.m_c[1]));
		return scalar(scalar_scalar, sqrt(e2.m_c[0]));
	}
	inline bivector inverse(const bivector& x) {
		scalar n;
		n.m_c[0] = (x.m_c[0] * x.m_c[0]);
		scalar in;
		in.m_c[0] = ((char)1 / n.m_c[0]);
		return bivector(bivector_e1e2, (-1.0f * x.m_c[0] * in.m_c[0]));
	}
	inline e2_t gp(const bivector& x, const __e1_ct__& y) {
		return e2_t(e2_t_e2, (-1.0f * x.m_c[0]));
	}
	inline rotor gp(const vector& x, const vector& y) {
		return rotor(rotor_scalar_e1e2, ((x.m_c[1] * y.m_c[1]) + (x.m_c[0] * y.m_c[0])), ((-1.0f * x.m_c[1] * y.m_c[0]) + (x.m_c[0] * y.m_c[1])));
	}
	inline vector gp(const vector& x, const scalar& y) {
		return vector(vector_e1_e2, (x.m_c[0] * y.m_c[0]), (x.m_c[1] * y.m_c[0]));
	}
	inline bivector reverse(const bivector& x) {
		return bivector(bivector_e1e2, (-1.0f * x.m_c[0]));
	}
	inline vector reverse(const vector& x) {
		return vector(vector_e1_e2, x.m_c[0], x.m_c[1]);
	}
	inline e1_t gp(const e2_t& x, const bivector& y) {
		return e1_t(e1_t_e1, (-1.0f * x.m_c[0] * y.m_c[0]));
	}
	inline vector gp(const scalar& x, const vector& y) {
		return vector(vector_e1_e2, (x.m_c[0] * y.m_c[0]), (x.m_c[0] * y.m_c[1]));
	}
	inline e2_t gp(const e1_t& x, const bivector& y) {
		return e2_t(e2_t_e2, (x.m_c[0] * y.m_c[0]));
	}
	inline vector gp(const rotor& x, const vector& y) {
		return vector(vector_e1_e2, ((x.m_c[1] * y.m_c[1]) + (x.m_c[0] * y.m_c[0])), ((x.m_c[0] * y.m_c[1]) + (-1.0f * x.m_c[1] * y.m_c[0])));
	}
	inline e2_t gp(const scalar& x, const __e2_ct__& y) {
		return e2_t(e2_t_e2, x.m_c[0]);
	}
	inline scalar scp(const vector& x, const vector& y) {
		return scalar(scalar_scalar, ((x.m_c[1] * y.m_c[1]) + (x.m_c[0] * y.m_c[0])));
	}









} // end of namespace e2ga
// post_h_include


#endif //  _GA_e2ga_h_H_
