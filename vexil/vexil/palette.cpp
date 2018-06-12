#include "palette.h"
#include "vexmath.h"
#include <iostream>

Vexil::Palette::Palette()
{
	hue = VexMath::getDouble(2341, 625, 0.0f, 360.f);
	deltaHue = VexMath::getDouble(1243, 324, 0.0f, 180.0f);
	
	type = (VexMath::getBool(124, 536)) ? PaletteType::Tri : PaletteType::Tetra;

	colorNull = new Color(0.0f, 0.0f, 0.0f, 1.0f);
	base = new Color(getRgbColor(hue,0.0f));
	complements = new Color*[3];
	
	if (type == PaletteType::Tetra)
	{
		complements[0] = new Color(getRgbColor(hue, deltaHue));
		complements[1] = new Color(getRgbColor(hue + 180, 0.0f));
		complements[2] = new Color(getRgbColor(hue + 180, deltaHue));
		
	}
	if (type == PaletteType::Tri)
	{
		complements[0] = new Color(getRgbColor(hue, deltaHue));
		complements[1] = new Color(getRgbColor(hue, -deltaHue));
		complements[2] = new Color(getRgbColor(hue, 0.0f));
	}

}

Vexil::Palette::Palette(double h, double d, PaletteType t)
{
	hue = h;
	deltaHue = d;
	type = t;
}

Color Vexil::Palette::getRgbColor(double h, double d)
{
	// this algorithm uses lin. interp. and thus produces inaccurate colors.
	// please adjust this interp
	// given a pallete with h, this is color 1
	h = h + d;
	if (h >= 360)
	{
		h = h - 360;
	}
	if (h < 0)
	{
		h = h + 360;
	}
	double r, g, b;
	if (h <= 120.0f)
	{
		r = 1.0f;
		g = h / 120.0f;
		b = 0;
	}
	if (h >= 315.0f)
	{
		r = 1.0f;
		g = 0;
		b = (-h +360)/45.0f;
	}
	if (h <= 210 && h >= 120)
	{
		g = 1.0f;
		if (h <= 180)
		{
			r = (h - 60) / 60;
			b = 0.0f;
		}
		else
		{
			r = 0.0f;
			b = (h-180) / 30.0f;
		}
		
	}
	if (h <= 315 && h >= 210)
	{
		b = 1.0f;
		r = (h - 210) / 105.0f;
		g = (315 - h) / 105.0f;
	}
	return Color(r, g, b, 0.68f);
}

Color* Vexil::Palette::getColorAt(int index)
{
	if (this != NULL)
	{
		if (index > 3 || index < 0)
			return colorNull;
		else if (index == 3)
			return base;
		else
			return complements[index];
	}
	return colorNull;
}