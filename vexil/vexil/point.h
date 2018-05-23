#pragma once
#ifndef POINT_H
#define POINT_H 1
namespace Vexil {
	class Point {
		double x;
		double y;

	public:
		Point(double, double);
		Point();
		double getX();
		double getY();
		void setX(double);
		void setY(double);
	};
}
#endif
