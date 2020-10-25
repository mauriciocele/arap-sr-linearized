#include "primitivedraw.h"
#include <algorithm>

#ifdef WIN32
#define NOMINMAX
#include <windows.h>
#endif

#if defined (__APPLE__) || defined (OSX)
	#include <OpenGL/gl.h>
	#include <GLUT/glut.h>
#else
	#include <GL/gl.h>
	#include <GL/glut.h>
#endif

GLUquadric* quadratic = NULL;

void InitializeDrawing()
{
	quadratic = gluNewQuadric();
	gluQuadricNormals(quadratic, GLU_SMOOTH);
}

void ReleaseDrawing()
{
	if(quadratic != NULL)
	{
		gluDeleteQuadric(quadratic);
		quadratic = NULL;
	}
}

void DrawPoint(const normalizedPoint& p)
{
	float		specular[] = { 1.f, 1.f, 1.f };
	float		objectDiffuse[] = { .0f, .0f, .5f, 1.f };

	glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, objectDiffuse );
	glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, specular );
	glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, 50.f );

	glPushMatrix();
		glTranslatef( p.e1(), p.e2(), p.e3() );
		gluSphere(quadratic, 0.01, 16, 16);
	glPopMatrix();
}

void DrawDualSphere( const dualSphere& circle, float objectDiffuse[4])
{
	normalizedPoint center = DualSphereCenter(circle);
	float	radius = sqrt(abs(_Float(-1*_scalar(circle * gradeInvolution(circle)) * inverse(norm_r2(ni << circle)))));

	float		specular[] = { 1.f, 1.f, 1.f };
	//float		objectDiffuse[] = { .0f, .5f, .5f, 0.3f };

	glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, objectDiffuse );
	glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, specular );
	glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, 50.f );

	glPushMatrix();
		glTranslatef( center.e1(), center.e2(), center.e3() );
		gluSphere(quadratic, radius, 32, 32);
	glPopMatrix();

}

void DrawTransparentDualSphere( const dualSphere& circle, float objectDiffuse[4])
{
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	DrawDualSphere(circle, objectDiffuse);

	glDisable(GL_BLEND);
}

void DrawLine(double x1, double y1, double z1, double x2, double y2, double z2)
{
	float		objectDiffuse[] = { 1.0f, 0.f, 0.f, 1.f };
	glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, objectDiffuse );
	glLineWidth(5.f);

	glBegin (GL_LINES);
		glVertex3d( x1, y1, z1 );
		glVertex3d( x2, y2, z2 );
	glEnd();

	glLineWidth(1.f);
}

void DrawArc(const dualCircle& circle, const normalizedPoint& a, const normalizedPoint& b)
{
	normalizedPoint center = _normalizedPoint(-0.5*(circle * ni * circle) * inverse(norm_r2(ni << circle)));
	float	radius = sqrt(abs(_Float(-1*_scalar(circle * gradeInvolution(circle)) * inverse(norm_r2(ni << circle)))));

	if(radius > 10000)
	{
		::DrawLine( a.e1(), a.e2(), a.e3(), b.e1(), b.e2(), b.e3() );
		return;
	}

	vectorE3GA vecA = _vectorE3GA(a) - _vectorE3GA(center);
	vectorE3GA vecB = _vectorE3GA(b) - _vectorE3GA(center);

	vecA = vecA * (1.0/_double(norm_e(vecA)));
	vecB = vecB * (1.0/_double(norm_e(vecB)));

	int size = 50; std::min( abs(radius), 50.0f);

	vectorE3GA vecXi = vecA;
	for( int i = 1 ; i <= size; ++i)
	{
		vectorE3GA vecXiplus1 = Slerp(vecA, vecB, i / (double)size);
		::DrawLine(	center.e1() + vecXi.e1() * radius, 
					center.e2() + vecXi.e2() * radius, 
					center.e3() + vecXi.e3() * radius,
					center.e1() + vecXiplus1.e1() * radius, 
					center.e2() + vecXiplus1.e2() * radius,
					center.e3() + vecXiplus1.e3() * radius);
		vecXi = vecXiplus1;
	}
}

void DrawCatmullRomSpline(const std::vector<vectorE3GA> &controlPoints)
{
    int segments = controlPoints.size() - 4 + 1;

	vectorE3GA p0, p1;
    for (int s = 0; s < segments; ++s)
    {
        for (double t = 0; t < 1.01; t += 0.01)
        {
            double basis[4];
            double t2 = t * t;
            double t3 = t2 * t;

            basis[0] = 0.5 * (-t + 2 * t2 - t3);
            basis[1] = 0.5 * (2 - 5 * t2 + 3 * t3);
            basis[2] = 0.5 * (t + 4 * t2 - 3 * t3);
            basis[3] = 0.5 * (-t2 + t3);

            vectorE3GA p = _vectorE3GA(0,0,0);
            for (int i = 0; i < 4; ++i)
                p = p + basis[i] * controlPoints[s + i];

			p1 = p;
			if(t > 0)
				::DrawLine(	p0.e1(), p0.e2(), p0.e3(), p1.e1(), p1.e2(), p1.e3() );
			p0 = p1;
        }
    }
}

void DrawCatmullRomSpline(const std::vector<vectorE3GA> &controlPoints, std::vector<vectorE3GA>& curvePoints, int numCurvePoints)
{
    int segments = controlPoints.size() - 4 + 1;

	double step = (double)segments / (double)numCurvePoints;

    for (int s = 0; s < segments; ++s)
    {
        for (double t = 0; t < 1.0+step; t += step)
        {
            double basis[4];
            double t2 = t * t;
            double t3 = t2 * t;

            basis[0] = 0.5 * (-t + 2 * t2 - t3);
            basis[1] = 0.5 * (2 - 5 * t2 + 3 * t3);
            basis[2] = 0.5 * (t + 4 * t2 - 3 * t3);
            basis[3] = 0.5 * (-t2 + t3);

            vectorE3GA p = _vectorE3GA(0,0,0);
            for (int i = 0; i < 4; ++i)
                p = p + basis[i] * controlPoints[s + i];

			curvePoints.push_back(p);
		}
    }
}


void DrawBezierSpline(const std::vector<vectorE3GA> &controlPoints)
{
    int segments = controlPoints.size() - 4 + 1;

	vectorE3GA p0, p1;
    for (int s = 0; s < segments; ++s)
    {
        for (double t = 0; t < 1.01; t += 0.01)
        {
            double basis[4];
			double t2 = t * t;
			double t3 = t2 * t;
			double oneMinusU = 1.0 - t;
			double oneMinusU2 = oneMinusU * oneMinusU;
			double oneMinusU3 = oneMinusU2 * oneMinusU;

			basis[0] = oneMinusU3;
			basis[1] = 3 * oneMinusU2 * t;
			basis[2] = 3 * oneMinusU * t2;
			basis[3] = t3;
			
            vectorE3GA p = _vectorE3GA(0,0,0);
            for (int i = 0; i < 4; ++i)
                p = p + basis[i] * controlPoints[s + i];

			p1 = p;
			if(t > 0)
				::DrawLine(	p0.e1(), p0.e2(), p0.e3(), p1.e1(), p1.e2(), p1.e3() );
			p0 = p1;
        }
    }
}

void DrawBezierSpline(const std::vector<vectorE3GA> &controlPoints, std::vector<vectorE3GA>& curvePoints, int numCurvePoints)
{
    int segments = controlPoints.size() - 4 + 1;

	double step = (double)segments / (double)numCurvePoints;

    for (int s = 0; s < segments; ++s)
    {
        for (double t = 0; t < 1.0+step; t += step)
        {
            double basis[4];
			double t2 = t * t;
			double t3 = t2 * t;
			double oneMinusU = 1.0 - t;
			double oneMinusU2 = oneMinusU * oneMinusU;
			double oneMinusU3 = oneMinusU2 * oneMinusU;

			basis[0] = oneMinusU3;
			basis[1] = 3 * oneMinusU2 * t;
			basis[2] = 3 * oneMinusU * t2;
			basis[3] = t3;
			
            vectorE3GA p = _vectorE3GA(0,0,0);
            for (int i = 0; i < 4; ++i)
                p = p + basis[i] * controlPoints[s + i];

			curvePoints.push_back(p);
        }
    }
}

static double Nij(int i, int j, double knots[], double t)
{
    if (j == 0)
    {
        if (abs(t - 1.0) < 1e-6)
        {
            if ((t < knots[i + 1] || abs(t - knots[i + 1]) < 1e-6) && t >= knots[i])
                return 1.0;
            else
                return 0.0;
        }

        if (t < knots[i + 1] && t >= knots[i])
            return 1.0;
        else
            return 0.0;
    }

    double coefA, coefB, denom;

    denom = knots[i + j] - knots[i];
    if (denom != 0.0)
        coefA = ((t - knots[i]) / denom) * Nij(i, j - 1, knots, t);
    else
        coefA = 0;

    denom = knots[i + j + 1] - knots[i + 1];
    if (denom != 0.0)
        coefB = ((knots[i + j + 1] - t) / denom) * Nij(i + 1, j - 1, knots, t);
    else
        coefB = 0;

    return coefA + coefB;
}

void DrawBSpline(const std::vector<vectorE3GA> &controlPoints)
{
	int N = controlPoints.size() - 1;
	int NplusOne = N + 1;
	int D = 3; //degree
	int NplusDplusOne = N + D + 1;

	double* knots = new double[NplusDplusOne + 1];

	int k = 0;
	for (k = 0; k <= D; ++k)
		knots[k] = 0.0;

	for (; k <= N; ++k)
		knots[k] = (k - D) / (N + 1.0 - D);

	for (; k <= NplusDplusOne; ++k)
		knots[k] = 1.0;

	double* basis = new double[NplusOne];

	vectorE3GA p0, p1;
	for (double t = 0; t < 1.01; t += 0.01)
	{
        for (int i = 0; i <= N; ++i)
            basis[i] = Nij(i, D, knots, t);

        vectorE3GA p = _vectorE3GA(0,0,0);
        for (int i = 0; i < NplusOne; ++i)
            p = p + basis[i] * controlPoints[i];

		p1 = p;
		if(t > 0)
			::DrawLine(	p0.e1(), p0.e2(), p0.e3(), p1.e1(), p1.e2(), p1.e3() );
		p0 = p1;
	}

	delete [] knots;
	delete [] basis;
}

void DrawBSpline(const std::vector<vectorE3GA> &controlPoints, std::vector<vectorE3GA>& curvePoints, int numCurvePoints)
{
	int N = controlPoints.size() - 1;
	int NplusOne = N + 1;
	int D = 3; //degree
	int NplusDplusOne = N + D + 1;

	double* knots = new double[NplusDplusOne + 1];

	int k = 0;
	for (k = 0; k <= D; ++k)
		knots[k] = 0.0;

	for (; k <= N; ++k)
		knots[k] = (k - D) / (N + 1.0 - D);

	for (; k <= NplusDplusOne; ++k)
		knots[k] = 1.0;

	double* basis = new double[NplusOne];

	double step = 1.0 / (double)numCurvePoints;

	for (double t = 0; t < 1.0+step; t += step)
	{
        for (int i = 0; i <= N; ++i)
            basis[i] = Nij(i, D, knots, t);

        vectorE3GA p = _vectorE3GA(0,0,0);
        for (int i = 0; i < NplusOne; ++i)
            p = p + basis[i] * controlPoints[i];

		curvePoints.push_back(p);
	}

	delete [] knots;
	delete [] basis;
}

void DrawArrow(const normalizedPoint& p, const vectorE3GA& dir)
{
	double length = 0.1;
	normalizedTranslator T  = exp( _freeVector(-0.5 * length * (dir)^ni) );
	normalizedPoint p2 = _normalizedPoint(T * p * reverse(T));
	vectorE3GA v = _vectorE3GA(p);
	::DrawLine(p.e1(), p.e2(), p.e3(), p2.e1(), p2.e2(), p2.e3());
}

void displayCircle(const vectorE3GA &c, double r, const vectorE3GA &n)
{
	vectorE3GA  vecTmp(vectorE3GA_e1_e2_e3, 0, 1, 0);

	vectorE3GA		u = _vectorE3GA((n ^ vecTmp) << I3);
	vectorE3GA		v = _vectorE3GA((u ^ n) << I3);
	u = u * inverse( norm_e(u) );
	v = v * inverse( norm_e(v) );

	float		objectDiffuse[] = { 1.0f, 0.f, 0.f, 1.f };
	glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, objectDiffuse );
	glBegin (GL_LINE_STRIP);

		for( double ang = 0.0 ; ang < 2*M_PI ; ang += 0.1 )
		{
			vectorE3GA	p = c + u*r*cos(ang) + v*r*sin(ang);
			glVertex3d( p.e1(), p.e2(), p.e3() );
		}
		vectorE3GA	p = c + u*r;
		glVertex3d( p.e1(), p.e2(), p.e3() );

	glEnd();
}

void displayCircle(const circle& c)
{
	dualCircle circle = _dualCircle(c << I5);
	normalizedPoint center = _normalizedPoint(-0.5*(circle * ni * circle) * inverse(norm_r2(ni << circle)));
	float	radius = sqrt(abs(_Float(-1*_scalar(circle * gradeInvolution(circle)) * inverse(norm_r2(ni << circle)))));

	vectorE3GA n = _vectorE3GA( _dualPlane(( c ^ ni ) << I5) );	
	n = n * inverse( norm_e(n) );

	displayCircle( _vectorE3GA(center), radius, n );
}
