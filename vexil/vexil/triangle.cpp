#include "triangle.h"
#include <iostream>

Vexil::Triangle::Triangle(Point aa, Point bb, Point cc)
{
	a = aa;
	b = bb;
	c = cc;
	std::cout << a.getX() << "," << a.getY() << "\n";
	std::cout << b.getX() << "," << b.getY() << "\n";
	std::cout << c.getX() << "," << c.getY() << "\n";
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
