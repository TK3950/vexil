#pragma once
#ifndef PALETTE_H
#define PALETTE_H 1
#include "color.h"
namespace Vexil {
	class Palette {
	public:
		enum PaletteType{
			Mono = 1,
			Tri = 2,
			Tetra = 3,
		};
	private:

		double hue;
		double distance;
		PaletteType type;
		Color getColor(double h, double d);

		Color* base;
		Color** complements;
	public:
		Palette();
		Palette(double h, double d, PaletteType t);
		Color* getColor(int index);
	};
}

#endif