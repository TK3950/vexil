#include "vec2d.h"

Vexil::Vec2d::Vec2d(double x1, double y1, double x2, double y2)
{
	setOriginX(x1);
	setOriginY(y1);
	setX(x2 - x1);
	setY(y2 - y1);
}
Vexil::Vec2d::Vec2d(Point p1, Point p2)
{
	setOriginX(p1.getX());
	setOriginY(p1.getY());
	setX(p2.getX() - p1.getX());
	setY(p2.getY() - p1.getY());
}
double Vexil::Vec2d::getOriginX()
{
	return originX;
}
double Vexil::Vec2d::getOriginY()
{
	return originY;
}
void Vexil::Vec2d::setOriginX(double ox)
{
	originX = ox;
}
void Vexil::Vec2d::setOriginY(double oy)
{
	originY = oy;
}
double Vexil::Vec2d::getX()
{
	return x;
}
double Vexil::Vec2d::getY()
{
	return y;
}
void Vexil::Vec2d::setX(double xx)
{
	x = xx;
}
void Vexil::Vec2d::setY(double yy)
{
	y = yy;
}