#include "point.h"

Vexil::Point::Point(double lx=0, double ly=0)
{
	x = lx;
	y = ly;
}
Vexil::Point::Point()
{
	x = 0;
	y = 0;
}
void Vexil::Point::setX(double lx)
{
	x = lx;
}
void Vexil::Point::setY(double ly)
{
	y = ly;
}

double Vexil::Point::getX()
{
	return x;
}

double Vexil::Point::getY()
{
	return y;
}