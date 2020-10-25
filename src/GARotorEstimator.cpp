#include "GARotorEstimator.h"
#include <array>

using Eigen::Vector3d;
using Eigen::Vector4d;
using Eigen::Matrix3d;
using Eigen::Matrix4d;
using Eigen::Quaterniond;
using std::vector;
using std::array;

/*
	a = H4 * e1 + H5 * e2 + H6 * e3 + H1 * e4;
	b = H5 * e1 + H7 * e2 + H8 * e3 + H2 * e4;
	c = H6 * e1 + H8 * e2 + H9 * e3 + H3 * e4;
	d = H1 * e1 + H2 * e2 + H3 * e3 + H0 * e4;

	x1 = (a - (lambda * e1));
	x2 = (b - (lambda * e2));
	x3 = (c - (lambda * e3));
	x4 = (d - (lambda * e4));

	? det = x1^x2^x3^x4;
*/
double characteristic(const array<double, 10>& H, double lambda)
{
	Vector4d x;
	x[0] = H[4] - lambda; // e1
	x[1] = H[7] - lambda; // e2
	x[2] = H[9] - lambda; // e3
	x[3] = H[0] - lambda; // e4
	return ((x[0] * x[1] + (-(H[5] * H[5]))) * x[2] + (-((x[0] * H[8] + (-(H[6] * H[5]))) * H[8])) 
		+ (H[5] * H[8] + (-(H[6] * x[1]))) * H[6]) * x[3] + (-(((x[0] * x[1] + (-(H[5] * H[5]))) * H[3] 
		+ (-((x[0] * H[2] + (-(H[1] * H[5]))) * H[8])) + (H[5] * H[2] + (-(H[1] * x[1]))) * H[6]) * H[3])) 
		+ ((x[0] * H[8] + (-(H[6] * H[5]))) * H[3] + (-((x[0] * H[2] + (-(H[1] * H[5]))) * x[2])) 
		+ (H[6] * H[2] + (-(H[1] * H[8]))) * H[6]) * H[2] + (-(((H[5] * H[8] + (-(H[6] * x[1]))) * H[3] 
		+ (-((H[5] * H[2] + (-(H[1] * x[1]))) * x[2])) + (H[6] * H[2] + (-(H[1] * H[8]))) * H[8]) * H[1])); // e1 ^ (e2 ^ (e3 ^ e4))		
}

/*
	a = H4 * e1 + H5 * e2 + H6 * e3 + H1 * e4;
	b = H5 * e1 + H7 * e2 + H8 * e3 + H2 * e4;
	c = H6 * e1 + H8 * e2 + H9 * e3 + H3 * e4;
	d = H1 * e1 + H2 * e2 + H3 * e3 + H0 * e4;

	x1 = (a - (lambda * e1));
	x2 = (b - (lambda * e2));
	x3 = (c - (lambda * e3));
	x4 = (d - (lambda * e4));

	? ddet = -e1^x2^x3^x4 - x1^e2^x3^x4 - x1^x2^e3^x4 - x1^x2^x3^e4;	
*/
double deriv_characteristic(const array<double, 10>& H, double lambda)
{
	Vector4d x;
	x[0] = H[4] - lambda; // e1
	x[1] = H[7] - lambda; // e2
	x[2] = H[9] - lambda; // e3
	x[3] = H[0] - lambda; // e4
	return (((-x[1]) * x[2] + (-((-H[8]) * H[8]))) * x[3] 
		+ (-(((-x[1]) * H[3] + (-((-H[2]) * H[8]))) * H[3])) + ((-H[8]) * H[3] + (-((-H[2]) * x[2]))) * H[2]) 
		- ((x[0] * x[2] + (-H[6]) * H[6]) * x[3] + (-((x[0] * H[3] + (-H[1]) * H[6]) * H[3])) 
		+ (-(((-H[6]) * H[3] + (-((-H[1]) * x[2]))) * H[1]))) - ((x[0] * x[1] + (-(H[5] * H[5]))) * x[3] 
		+ (-(x[0] * H[2] + (-(H[1] * H[5])))) * H[2] + (-((-(H[5] * H[2] + (-(H[1] * x[1])))) * H[1]))) 
		- ((x[0] * x[1] + (-(H[5] * H[5]))) * x[2] + (-((x[0] * H[8] + (-(H[6] * H[5]))) * H[8])) 
		+ (H[5] * H[8] + (-(H[6] * x[1]))) * H[6]); // e1 ^ (e2 ^ (e3 ^ e4))
}

/*
	a = H4 * e1 + H5 * e2 + H6 * e3 + H1 * e4;
	b = H5 * e1 + H7 * e2 + H8 * e3 + H2 * e4;
	c = H6 * e1 + H8 * e2 + H9 * e3 + H3 * e4;
	d = H1 * e1 + H2 * e2 + H3 * e3 + H0 * e4;

	x1 = (a - (lambda * e1));
	x2 = (b - (lambda * e2));
	x3 = (c - (lambda * e3));
	x4 = (d - (lambda * e4));

	? R0 = (x1^x3^x4 + x1^x2^x4 + x1^x2^x3 + x2^x3^x4) . (e1^e2^e3^e4);
*/
Vector4d hyperplanes_intersection(const array<double, 10>& H, double lambda)
{
	Vector4d R0, x;
	x[0] = H[4] - lambda; // e1
	x[1] = H[7] - lambda; // e2
	x[2] = H[9] - lambda; // e3
	x[3] = H[0] - lambda; // e4
	R0[0] = (H[5] * x[2] + (-(H[6] * H[8]))) * x[3] + (-((H[5] * H[3] + (-(H[1] * H[8]))) * H[3])) + (H[6] * H[3] + (-(H[1] * x[2]))) * H[2] + (H[5] * H[8] + (-(H[6] * x[1]))) * x[3] + (-((H[5] * H[2] + (-(H[1] * x[1]))) * H[3])) + (H[6] * H[2] + (-(H[1] * H[8]))) * H[2] + (H[5] * H[8] + (-(H[6] * x[1]))) * H[3] + (-((H[5] * H[2] + (-(H[1] * x[1]))) * x[2])) + (H[6] * H[2] + (-(H[1] * H[8]))) * H[8] + (x[1] * x[2] + (-(H[8] * H[8]))) * x[3] + (-((x[1] * H[3] + (-(H[2] * H[8]))) * H[3])) + (H[8] * H[3] + (-(H[2] * x[2]))) * H[2]; // e1
	R0[1] = (-((x[0] * x[2] + (-(H[6] * H[6]))) * x[3] + (-((x[0] * H[3] + (-(H[1] * H[6]))) * H[3])) + (H[6] * H[3] + (-(H[1] * x[2]))) * H[1] + (x[0] * H[8] + (-(H[6] * H[5]))) * x[3] + (-((x[0] * H[2] + (-(H[1] * H[5]))) * H[3])) + (H[6] * H[2] + (-(H[1] * H[8]))) * H[1] + (x[0] * H[8] + (-(H[6] * H[5]))) * H[3] + (-((x[0] * H[2] + (-(H[1] * H[5]))) * x[2])) + (H[6] * H[2] + (-(H[1] * H[8]))) * H[6] + (H[5] * x[2] + (-(H[8] * H[6]))) * x[3] + (-((H[5] * H[3] + (-(H[2] * H[6]))) * H[3])) + (H[8] * H[3] + (-(H[2] * x[2]))) * H[1])); // e2
	R0[2] = (x[0] * H[8] + (-(H[5] * H[6]))) * x[3] + (-((x[0] * H[3] + (-(H[1] * H[6]))) * H[2])) + (H[5] * H[3] + (-(H[1] * H[8]))) * H[1] + (x[0] * x[1] + (-(H[5] * H[5]))) * x[3] + (-((x[0] * H[2] + (-(H[1] * H[5]))) * H[2])) + (H[5] * H[2] + (-(H[1] * x[1]))) * H[1] + (x[0] * x[1] + (-(H[5] * H[5]))) * H[3] + (-((x[0] * H[2] + (-(H[1] * H[5]))) * H[8])) + (H[5] * H[2] + (-(H[1] * x[1]))) * H[6] + (H[5] * H[8] + (-(x[1] * H[6]))) * x[3] + (-((H[5] * H[3] + (-(H[2] * H[6]))) * H[2])) + (x[1] * H[3] + (-(H[2] * H[8]))) * H[1]; // e3
	R0[3] = (-((x[0] * H[8] + (-(H[5] * H[6]))) * H[3] + (-((x[0] * x[2] + (-(H[6] * H[6]))) * H[2])) + (H[5] * x[2] + (-(H[6] * H[8]))) * H[1] + (x[0] * x[1] + (-(H[5] * H[5]))) * H[3] + (-((x[0] * H[8] + (-(H[6] * H[5]))) * H[2])) + (H[5] * H[8] + (-(H[6] * x[1]))) * H[1] + (x[0] * x[1] + (-(H[5] * H[5]))) * x[2] + (-((x[0] * H[8] + (-(H[6] * H[5]))) * H[8])) + (H[5] * H[8] + (-(H[6] * x[1]))) * H[6] + (H[5] * H[8] + (-(x[1] * H[6]))) * H[3] + (-((H[5] * x[2] + (-(H[8] * H[6]))) * H[2])) + (x[1] * x[2] + (-(H[8] * H[8]))) * H[1])); // e4

	return R0;
}

/*

max | p + R* q R |^2

p + R* q R = 0

p R* + R* q = 0

p (w - L) + (w - L) q = 0

(Remember: inner product of bivectors is negative and commutator anticommute)
w (p + q) + L . (p + q) + (q - p) x L = 0

| 0     s^T  | | w | = | s^T L       |  
| s    [d]_x | | L |   | w s + d x L |

| 0     s^T  | | 0    s^T  | = | s^T s    s^T [d]_x       |
| s   -[d]_x | | s   [d]_x |   |-[d]_x s  s s^T - [d]^2_x |

| 0     s^T  | | 0    s^T  | = | s^T s    s x d         | = | s^T s    s x d                 |
| s   -[d]_x | | s   [d]_x |   | s x d  s s^T - [d]^2_x |   | s x d  s s^T - d d^t + d^T d I |

*/
Quaterniond GARotorEstimator(const vector<Vector3d>& P, const vector<Vector3d>& Q, const size_t N, const vector<double>& w)
{
	array<double, 10> H;
	Matrix3d Sx;
	double wj;
	//const size_t N = P.size();
	Sx.setZero();
	double S = 0;
	for (size_t j = 0; j < N; ++j) {
		wj = w[j];
		const Vector3d& Qj = Q[j];
		const Vector3d& Pj = P[j];
		S += wj * Pj.dot(Pj);
		S += wj * Qj.dot(Qj);
		Sx.noalias() += (wj * Pj) * Qj.transpose();
	}

	wj = 0.5 * S;
 	H[0] = wj + Sx.trace();       // (3,3)
	wj = wj - Sx.trace();
	H[1] = (Sx(1, 2) - Sx(2, 1)); // (3,0)
	H[2] = (Sx(2, 0) - Sx(0, 2)); // (3,1)
	H[3] = (Sx(0, 1) - Sx(1, 0)); // (3,2)
	H[4] = 2.0 * Sx(0, 0) + wj;   // (0,0)
	H[5] = (Sx(0, 1) + Sx(1, 0)); // (1,0) 
	H[6] = (Sx(2, 0) + Sx(0, 2)); // (2,0)
	H[7] = 2.0 * Sx(1, 1) + wj;   // (1,1)
	H[8] = (Sx(1, 2) + Sx(2, 1)); // (2,1)
	H[9] = 2.0 * Sx(2, 2) + wj;   // (2,2)

	double lambda = H[0]+H[4]+H[7]+H[9];
	double lambda_prev;
	do {
		lambda_prev = lambda;
		lambda = lambda - characteristic(H, lambda) / deriv_characteristic(H, lambda);
	} while(std::abs(lambda_prev - lambda) > 1e-5);

	Quaterniond R = Quaterniond(hyperplanes_intersection(H, lambda));
	R.normalize();
	return R;
}

Quaterniond GARotorEstimator(const Matrix3d& Sx, const double S)
{
	array<double, 10> H;
	double wj;

	wj = 0.5 * S;
 	H[0] = wj + Sx.trace();       // (3,3)
	wj = wj - Sx.trace();
	H[1] = (Sx(1, 2) - Sx(2, 1)); // (3,0)
	H[2] = (Sx(2, 0) - Sx(0, 2)); // (3,1)
	H[3] = (Sx(0, 1) - Sx(1, 0)); // (3,2)
	H[4] = 2.0 * Sx(0, 0) + wj;   // (0,0)
	H[5] = (Sx(0, 1) + Sx(1, 0)); // (1,0) 
	H[6] = (Sx(2, 0) + Sx(0, 2)); // (2,0)
	H[7] = 2.0 * Sx(1, 1) + wj;   // (1,1)
	H[8] = (Sx(1, 2) + Sx(2, 1)); // (2,1)
	H[9] = 2.0 * Sx(2, 2) + wj;   // (2,2)

	double lambda = H[0]+H[4]+H[7]+H[9];
	double lambda_prev;
	do {
		lambda_prev = lambda;
		lambda = lambda - characteristic(H, lambda) / deriv_characteristic(H, lambda);
	} while(std::abs(lambda_prev - lambda) > 1e-5);

	Quaterniond R = Quaterniond(hyperplanes_intersection(H, lambda));
	R.normalize();
	return R;
}
