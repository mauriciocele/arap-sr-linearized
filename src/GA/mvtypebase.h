
#ifndef _MV_TYPE_BASE_CLASS_
#define _MV_TYPE_BASE_CLASS_
	// multivector type
	class mvTypeBase {
	protected:
		static const int _VERSOR = 2;
	static const int _BLADE = 4;
	public:
		const static int MULTIVECTOR = 1;
	const static int VERSOR = MULTIVECTOR | _VERSOR; // a versor is a multivector too
	const static int BLADE = VERSOR | _BLADE; // a blade is a versor too

	inline mvTypeBase() : m_zero(false), m_type(0), 
		m_grade(-1), m_gradeUsage(0), m_parity(-1) {
	}

	inline mvTypeBase(const mvTypeBase &T) : m_zero(T.m_zero), m_type(T.m_type), 
	m_grade(T.m_grade), m_gradeUsage(T.m_gradeUsage), m_parity(T.m_parity) {
	}

	inline mvTypeBase &operator=(const mvTypeBase &T) {
		if (this != &T) {
			m_zero = T.m_zero;
			m_type = T.m_type;
			m_grade = T.m_grade;
			m_gradeUsage = T.m_gradeUsage;
			m_parity = T.m_parity;
		}
		return *this;
	}

	/** true if multivector is zero */
	bool m_zero;

	/** MULTIVECTOR, VERSOR, or BLADE */
	int m_type;
	/** top grade occupied by the multivector */
	int m_grade;
	/** grade usage (bitmap containing what grade parts are present)  */
	int m_gradeUsage;
	/** parity (1 = odd, 0 = even , -1 is none)*/
	int m_parity; 
};

#endif /* _MV_TYPE_BASE_CLASS_ */
