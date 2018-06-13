#include "palette.h"
#include "vexmath.h"
#include <iostream>

Vexil::Palette::Palette()
{

	type = (VexMath::getBool(124, 536)) ? PaletteType::Tri : PaletteType::Tetra;

	baseHue = VexMath::getDouble(2341, 625, 0.0f, 360.f);
	deltaHue = VexMath::getDouble(1243, 324, 0.0f, 180.0f);
	double maxSV = 0.8f;
	baseSaturation = VexMath::getDouble(214, 532, 0.0f, maxSV);
	baseValue = VexMath::getDouble(3251, 213331, 0.0f, maxSV);
	
	
	

	colorNull = new Color(0.0f, 0.0f, 0.0f, maxSV);
	base = new Color(baseHue, baseSaturation, baseValue);
	
	complements = new Color*[3];

	if (type == PaletteType::Tetra)
	{
		complements[0] = new Color(baseHue + deltaHue,
			VexMath::getDouble(3763, 643, 0.0f, maxSV),
			VexMath::getDouble(2345, 14562, 0.0f, maxSV));

		complements[1] = new Color(baseHue + 180.0,
			VexMath::getDouble(3124, 34, 0.0f, maxSV),
			VexMath::getDouble(356, 3525, 0.0f, maxSV));

		complements[2] = new Color(baseHue + 180.0 + deltaHue,
			VexMath::getDouble(1945, 536, 0.0f, maxSV),
			VexMath::getDouble(7372, 23467, 0.0f, maxSV));

		
	}
	if (type == PaletteType::Tri)
	{

		complements[0] = new Color(baseHue + deltaHue,
			VexMath::getDouble(32763, 6243, 0.0f, maxSV),
			VexMath::getDouble(23245, 145262, 0.0f, maxSV));

		complements[1] = new Color(baseHue -deltaHue,
			VexMath::getDouble(31224, 324, 0.0f, maxSV),
			VexMath::getDouble(3526, 23525, 0.0f, maxSV));

		complements[2] = new Color(baseHue,
			VexMath::getDouble(19425, 2536, 0.0f, maxSV),
			VexMath::getDouble(27372, 223467, 0.0f, maxSV));
	}

}

Vexil::Palette::Palette(double h, double d, PaletteType t)
{
	baseHue = h;
	deltaHue = d;
	type = t;
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

Vexil::Palette::~Palette()
{
	delete base;
	delete colorNull;
	delete *complements;
	delete complements;
}