#pragma once
#ifndef VEXMATH_H
#define VEXMATH_H 1
#define PI 3.1415926535
#define DEG180 (PI)
#define DEG360 (2*PI)
#define DEG90 (PI/2)
#include "opensimplexnoise.hpp"
#include "point.h"
#include "vec2d.h"

namespace Vexil
{
	class VexMath
	{
		
	public:
		static double getDouble(double x, double y, double min, double max);
		static int getInt(double x, double y, int min, int max);
		static double getRawNoise(int x,int y);
		static bool getBool(int x, int y);
		static double crossProduct(Vec2d v1, Vec2d v2);
		static double dotProduct(Vec2d v1, Vec2d v2);
		static double angle(Vec2d v1, Vec2d v2);
		static bool sameSideOfLine(Point tp, Point ref, Point a, Point b);
		static bool isInsideTriangle(Point tp, Point a, Point b, Point c);
	};
}
#endif