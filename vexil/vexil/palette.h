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

		double baseHue;
		double baseSaturation;
		double baseValue;
		double deltaHue;
		PaletteType type;

		Color* base;
		Color** complements;
		Color** accents;
		Color* colorNull;
	public:
		Palette();
		Palette(double h, double d, PaletteType t);
		Color* getColorAt(int index);
		~Palette();
	};
}

#endif