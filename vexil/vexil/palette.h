#pragma once
#ifndef PALETTE_H
#define PALETTE_H 1
#include "color.h"
namespace Vexil {
	class Palette {
	public:
		enum PaletteType{
			Tri = 1,
			Tetra = 2,
		};
	private:

		double hue;
		double saturation;
		double value;
		double deltaHue;
		double deltaSat;
		PaletteType type;
		Color getRgbColor(double h, double d);

		Color* base;
		Color** complements;
		Color* colorNull;
	public:
		Palette();
		Palette(double h, double d, PaletteType t);
		Color* getColorAt(int index);
	};
}

#endif