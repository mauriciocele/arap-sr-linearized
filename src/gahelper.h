#if !defined(__GA_HELPER__H__)
#define __GA_HELPER__H__

#include "GA/c3ga.h"
#include "GA/c3ga_util.h"

using namespace c3ga;

typedef tangentVector dualCircle;
#define SQR(x)		((x)*(x))


inline double arc_cosine ( double c )
//****************************************************************************80
//
//  Purpose:
//
//    ARC_COSINE computes the arc cosine function, with argument truncation.
//
//  Discussion:
//
//    If you call your system ACOS routine with an input argument that is
//    outside the range [-1.0, 1.0 ], you may get an unpleasant surprise.
//    This routine truncates arguments outside the range.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 June 2002
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double C, the argument, the cosine of an angle.
//
//    Output, double ARC_COSINE, an angle whose cosine is C.
//
{
	double angle;
	double pi = 3.141592653589793;

	if ( c <= -1.0 )
	{
		angle = pi;
	}
	else if ( 1.0 <= c )
	{
		angle = 0.0;
	}
	else
	{
		angle = acos ( c );
	}
	return angle;
}

inline double angle_rad_3d ( double p1[3], double p2[3], double p3[3] )
//****************************************************************************80
//
//  Purpose:
//
//    ANGLE_RAD_3D returns the angle between two vectors in 3D.
//
//  Discussion:
//
//    The routine always computes the SMALLER of the two angles between
//    two vectors.  Thus, if the vectors make an (exterior) angle of 200
//    degrees, the (interior) angle of 160 is reported.
//
//    X dot Y = Norm(X) * Norm(Y) * Cos ( Angle(X,Y) )
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    20 June 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double P1[3], P2[3], P3[3], points defining an angle.
//    The rays are P1 - P2 and P3 - P2.
//
//    Output, double ANGLE_RAD_3D, the angle between the two vectors, in radians.
//    This value will always be between 0 and PI.  If either vector has
//    zero length, then the angle is returned as zero.
//
{
	const int DIM_NUM = 3;
	double dot;
	int i;
	double v1norm;
	double v2norm;
	double value;

	v1norm = 0.0;
	for ( i = 0; i < DIM_NUM; i++ )
	{
		v1norm = v1norm + pow ( p1[i] - p2[i], 2 );
	}
	v1norm = sqrt ( v1norm );

	if ( v1norm == 0.0 )
	{
		value = 0.0;
		return value;
	}

	v2norm = 0.0;
	for ( i = 0; i < DIM_NUM; i++ )
	{
		v2norm = v2norm + pow ( p3[i] - p2[i], 2 );
	}
	v2norm = sqrt ( v2norm );

	if ( v2norm == 0.0 )
	{
		value = 0.0;
		return value;
	}

	dot = 0.0;
	for ( i = 0; i < DIM_NUM; i++ )
	{
		dot = dot + ( p1[i] - p2[i] ) * ( p3[i] - p2[i] );
	}

	value = arc_cosine ( dot / ( v1norm * v2norm ) );

	return value;
}

inline dualCircle _dualCircle(const mv &arg1)
{
	return _tangentVector(arg1);
}

inline normalizedPoint _normalizedPoint( const normalizedFlatPoint& p)
{
	return c3gaPoint(p.e1ni(), p.e2ni(), p.e3ni());
}

inline vectorE3GA _vectorE3GA( const normalizedFlatPoint& p)
{
	return vectorE3GA(c3ga::vectorE3GA_e1_e2_e3, p.e1ni(), p.e2ni(), p.e3ni());
}

inline vectorE3GA _vectorE3GA( const double e1, const double e2, const double e3)
{
	return vectorE3GA(c3ga::vectorE3GA_e1_e2_e3, e1, e2, e3);
}

inline normalizedPoint DualSphereCenter( const dualSphere &dS )
{
	return _normalizedPoint(-0.5*(dS * ni * dS) * inverse(norm_r2(ni << dS)));
}

inline double DualSphereRadius( const dualSphere &dS)
{
	return sqrt(abs(_Float(-1*_scalar(dS * gradeInvolution(dS)) * inverse(norm_r2(ni << dS)))));
}

inline normalizedPoint Lerp(const normalizedPoint& a, const normalizedPoint& b, double t)
{
	return _normalizedPoint(-(1 - t)*(b<<ni)*a - t*(a<<ni)*b + t*(1 - t)*(a<<b)*ni);
}

inline vectorE3GA Slerp(const vectorE3GA& a, const vectorE3GA& b, double t)
{
	//double teta = angle_rad_2d(a,vecmat::vector2<double>(0,0), b);
    //double teta = acos(_double(a << b));
	double _a[3] = { a.e1(), a.e2(), a.e3() };
	double _b[3] = { b.e1(), b.e2(), b.e3() };
	double _co[3] = { 0, 0, 0 };
    double teta = angle_rad_3d( _a, _co, _b );
    return (1.0 / sin(teta)) * (a * sin((1.0 - t) * teta) + b * sin(t * teta));
}

inline dualSphere ChangeDualSphereRadiusSize(const dualSphere& ds, float delta)
{
	normalizedPoint c = DualSphereCenter(ds);
	float r = DualSphereRadius(ds);
	r += delta;
	return _dualSphere( c - 0.5 * SQR(r) * ni );
}

inline bivectorE3GA normalize(const bivectorE3GA &arg1)
{
	point p = _point(arg1);
	return _bivectorE3GA(arg1 * (1.0/_double( norm_r(arg1) )));
}

inline normalizedPoint normalize(const point &p)
{
	return _normalizedPoint(p * (1.0/_double(-ni << p)));
}

inline vectorE3GA normalize(const vectorE3GA &arg1)
{
	return _vectorE3GA(arg1 * (1.0/_double(norm_e(arg1))));
}

inline circle normalize(const circle &arg1)
{
	return _circle(arg1 * (1.0/_double(norm_r(arg1))));
}

inline normalizedTranslator normalize(const translator &arg1)
{
	return _normalizedTranslator(arg1 * (1.0/_double(norm_r(arg1))));
}

inline plane normalize(const plane &arg1)
{
	return _plane(arg1 * (1.0/_double(norm_r(arg1))));
}

inline TRversor normalize(const TRversor &arg1)
{
	return _TRversor(arg1 * (1.0/_double(norm_r(arg1))));
}

inline line normalize(const line &arg1)
{
	return _line(arg1 * (1.0/_double(norm_r(arg1))));
}

inline dualSphere normalize(const dualSphere &arg1)
{
	return _dualSphere(arg1 * (1.0/_double(norm_r(arg1))));
}

inline sphere normalize(const sphere &arg1)
{
	return _sphere(arg1 * (1.0/_double(norm_r(arg1))));
}

inline rotor normalize(const rotor &arg1)
{
	return _rotor(arg1 * (1.0/_double(norm_r(arg1))));
}

#endif
