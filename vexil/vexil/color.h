#pragma once
#ifndef COLOR_H
#define COLOR_H 1

class Color {
	double r, g, b, a;
	double h, s, v;
public:
	Color(double r, double g, double b, double a);
	Color(double h, double s, double v);
	double getRed();
	double getBlue();
	double getGreen();
	double getAlpha();
	double getHue();
	double getSaturation();
	double getValue();

	void makeHSV();
	void makeRBG();

};

#endif