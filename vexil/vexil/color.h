#pragma once
#ifndef COLOR_H
#define COLOR_H 1

class Color {
	double r, g, b, a;
public:
	Color(double, double, double, double);
	double getRed();
	double getBlue();
	double getGreen();
	double getAlpha();

};

#endif