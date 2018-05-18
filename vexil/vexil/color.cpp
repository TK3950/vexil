#include "color.h"

Color::Color(double tr, double tg, double tb, double ta)
{
	r = (tr > 1.0f) ? 1.0f : tr;
	r = (tr < 0.0f) ? 0.0f : tr;

	g = (tg > 1.0f) ? 1.0f : tg;
	g = (tg < 0.0f) ? 0.0f : tg;

	b = (tb > 1.0f) ? 1.0f : tb;
	b = (tb < 0.0f) ? 0.0f : tb;

	a = (ta > 1.0f) ? 1.0f : ta;
	a = (ta < 0.0f) ? 0.0f : ta;
}

double Color::getAlpha()
{
	return a;
}

double Color::getRed()
{
	return r;
}

double Color::getGreen()
{
	return g;
}

double Color::getBlue()
{
	return b;
}