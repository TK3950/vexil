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
		static double getDouble(double, double, double, double);
		static int getInt(double, double, int, int);
		static double getRawNoise(int,int);
		static double crossProduct(Vec2d, Vec2d);
		static bool sameSideOfLine(Point, Point, Point, Point);
		static bool isInsideTriangle(Point, Point, Point, Point);
	};
}
#endif