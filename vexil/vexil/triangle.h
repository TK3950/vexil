#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H 1
#include "point.h"

namespace Vexil
{
	class Triangle {
		Point a;
		Point b;
		Point c;
	public:
		Triangle(Point, Point, Point);
		Point getA();
		Point getB();
		Point getC();
	};
}

#endif