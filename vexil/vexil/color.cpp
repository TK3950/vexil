#include "color.h"

Color::Color(double tr, double tg, double tb, double ta)
{
	// sanity checks
	r = (tr > 1.0f) ? 1.0f : tr;
	r = (tr < 0.0f) ? 0.0f : tr;

	g = (tg > 1.0f) ? 1.0f : tg;
	g = (tg < 0.0f) ? 0.0f : tg;

	b = (tb > 1.0f) ? 1.0f : tb;
	b = (tb < 0.0f) ? 0.0f : tb;

	a = (ta > 1.0f) ? 1.0f : ta;
	a = (ta < 0.0f) ? 0.0f : ta;

	makeHSV();
}

Color::Color(double th, double ts, double tv)
{
	while (th >= 360.0)
	{
		th -= 360.0;
	}
	while (th < 0)
	{
		th += 360.0;
	}
	h = th;
	
	s = (ts > 1.0f) ? 1.0f : ts;
	s = (ts < 0.0f) ? 0.0f : ts;

	v = (tv > 1.0f) ? 1.0f : tv;
	v = (tv < 0.0f) ? 0.0f : tv;
	
	makeRBG();
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

void Color::makeHSV()
{
	// Copied / modified from StackOverflow. Tread with caution
	double m, max, delta;

	m = (r < g) ? r : g;
	m = (m  < b) ? m : b;

	max = r > g ? r : g;
	max = max  > b ? max : b;

	v = max;
	delta = max - m;

	if (delta < 0.00001)
	{
		s = 0;
		h = 0; // undefed, maybe nan?
		return;
	}

	if (max > 0.0) { // NOTE: if Max is == 0, this divide would cause a crash
		s = (delta / max);                  // s
	}
	else {
		// if max is 0, then r = g = b = 0              
		// s = 0, h is undefed
		s = 0.0;
		h = 0.0;                            // its now undefed
		return;
	}

	if (r >= max)                           // > is bogus, just keeps compiler happy
		h = (g - b) / delta;        // between yellow & magenta
	else
		if (g >= max)
			h = 2.0 + (b - r) / delta;  // between cyan & yellow
		else
			h = 4.0 + (r - g) / delta;  // between magenta & cyan

	h *= 60.0;                              // degrees

	if (h < 0.0)
		h += 360.0;

	return;
}


void Color::makeRBG()
{
	double      hh, p, q, t, ff;
	long        i;

	if (s <= 0.0) {       // < is bogus, just shuts up warngs
		r = v;
		g = v;
		b = v;
		return;
	}
	hh = h;
	if (hh >= 360.0) hh = 0.0;
	hh /= 60.0;
	i = (long)hh;
	ff = hh - i;
	p = v * (1.0 - s);
	q = v * (1.0 - (s * ff));
	t = v * (1.0 - (s * (1.0 - ff)));

	switch (i) {
	case 0:
		r = v;
		g = t;
		b = p;
		break;
	case 1:
		r = q;
		g = v;
		b = p;
		break;
	case 2:
		r = p;
		g = v;
		b = t;
		break;

	case 3:
		r = p;
		g = q;
		b = v;
		break;
	case 4:
		r = t;
		g = p;
		b = v;
		break;
	case 5:
	default:
		r = v;
		g = p;
		b = q;
		break;
	}
	return;
}

double Color::getHue()
{
	return h;
}
double Color::getSaturation()
{
	return s;
}
double Color::getValue()
{
	return v;
}