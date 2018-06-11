#pragma once
#ifndef FLAG_H
#define FLAG_H 1
#include "canvas.h"
#include "pattern.h"
#include "accessory.h"
#include "opensimplexnoise.hpp"
#include "palette.h"

namespace Vexil
{
	class Flag {
	public:
		enum Form
		{
			solid = 0,
			bicolor,
			tricolor,
			polycolor,
			colonial,
			cross,
			bicross,
			tricross,
		};
	private:
		
		OpenSimplexNoise* noise;
		Color* baseColor;
		int patternCount;
		int accessoryCount;
		Pattern* patterns;
		Accessory* accessories;
		Canvas* canvas;
		Palette* palette;
		
	public:
		Flag(Canvas*);
		void generate();

		Color getBaseColor();
		int getPatternCount();
		int getAccessoryCount();
		
		Pattern getPattern(int);
		Accessory getAccessory(int);

		void setBaseColor(Color);
		void createPatterns(int);
		void createAccessories(int);
		void setDrawColor(Canvas*, Color*);

		void renderBase(); // render first, might need the canvas passed
		void renderPatterns(); // render second
		void renderAccessories(); // render third
		void renderText(); // render last, if ever
		
		void testPalette();
	};
}

#endif