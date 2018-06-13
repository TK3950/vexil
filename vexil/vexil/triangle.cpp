#include "triangle.h"
#include <iostream>

Vexil::Triangle::Triangle(Point aa, Point bb, Point cc)
{
	a = aa;
	b = bb;
	c = cc;
}
Vexil::Triangle::Triangle()
{
	a = Point(0,0);
	b = Point(0, 0);
	c = Point(0, 0);
}


Vexil::Point Vexil::Triangle::getA()
{
	return a;
}
 Vexil::Point Vexil::Triangle::getB()
{
	 return b;
}
 Vexil::Point Vexil::Triangle::getC()
{
	 return c;
}

 void Vexil::Triangle::set(Point aa, Point bb, Point cc)
 {
	 a = aa;
	 b = bb;
	 c = cc;
 }
