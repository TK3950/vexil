#pragma once
#ifndef VEXMATH_H
#define VEXMATH_H 1
#include "opensimplexnoise.hpp"

namespace Vexil
{
	class VexMath
	{
		static OpenSimplexNoise noise;
	public:
		static double getDouble(double, double, double, double);
		static int getInt(double, double, int, int);
		static double getRawNoise(int,int);
	};
}
#endif