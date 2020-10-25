#if !defined(__PRIMITIVE_DRAW__H__)
#define __PRIMITIVE_DRAW__H__

#include "GA/c3ga.h"
#include "gahelper.h"
#include <vector>

void InitializeDrawing();
void ReleaseDrawing();
void DrawPoint(const normalizedPoint& p);
void DrawDualSphere( const dualSphere& circle, float objectDiffuse[4]);
void DrawTransparentDualSphere( const dualSphere& circle, float objectDiffuse[4]);
void DrawLine(double x1, double y1, double z1, double x2, double y2, double z2);
void DrawArc(const dualCircle& circle, const normalizedPoint& a, const normalizedPoint& b);
void DrawCatmullRomSpline(const std::vector<vectorE3GA> &controlPoints);
void DrawCatmullRomSpline(const std::vector<vectorE3GA> &controlPoints, std::vector<vectorE3GA> &curvePoints, int numCurvePoints);
void DrawBezierSpline(const std::vector<vectorE3GA> &controlPoints);
void DrawBezierSpline(const std::vector<vectorE3GA> &controlPoints, std::vector<vectorE3GA> &curvePoints, int numCurvePoints);
void DrawBSpline(const std::vector<vectorE3GA> &controlPoints);
void DrawBSpline(const std::vector<vectorE3GA> &controlPoints, std::vector<vectorE3GA> &curvePoints, int numCurvePoints);
void DrawArrow(const normalizedPoint& p, const vectorE3GA& dir);
void displayCircle(const vectorE3GA &c, double r, const vectorE3GA &n);
void displayCircle(const circle& c);

#endif
