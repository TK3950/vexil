#pragma once
#ifndef ACCESSORY_H
#define ACCESSORY_H 1
#include "color.h"
#include "vexmath.h"
#include "canvas.h"
#include "palette.h"

namespace Vexil
{
	class Accessory {
	public:
		Accessory();
		enum AccessoryType {
			accNone = 0,
			star,
			accCross,
			moon,
			circle,
			leaf,
			tree,
			diamond,
			sun,
			emblem,
			//animals? or should they be considered emblems?
		};

		enum AccessoryPattern { // if multiple acc., what pattern do they appear in
			single = 0,
			grid,
			staggeredGrid,
			circular,
			bow,
		};

		enum AccessoryLocation { // where does the accessory appear
			topLeft = 0,
			topRight,
			bottomLeft,
			bottomRight,
			left,
			right,
			top,
			bottom,
			center,
		};

	private:
		AccessoryType type;
		AccessoryPattern accessoryPattern;
		AccessoryLocation location;
		int count; // how many of the accessory
		double size;
		bool blockPatterns; // if true, render base color inside bounding box of acc.
		int x;
		int y; // accessories have positions
		Color* color;
		int colorSelect;

	public:
		AccessoryType getType();
		AccessoryPattern getPattern();
		AccessoryLocation getLocation();
		
		int getCount();
		double getSize();
		bool isBlocking();
		int getX();
		int getY();
		Color* getColor();

		void setDrawColor(Canvas*, Color*);

		void renderSingle(Canvas*, Palette* palette);
		void renderGrid(Canvas*, Palette* palette);
		void renderCircular(Canvas*, Palette* palette);
		void renderBow(Canvas*, Palette* palette);
		void renderStagGrid(Canvas*, Palette* palette);

		void renderShape(Canvas *, Palette* palette, int, int);

		void renderStar(Canvas*, Palette* palette, int, int);
		void renderCross(Canvas*, Palette* palette, int, int);
		void renderMoon(Canvas*, Palette* palette, int, int);
		void renderCircle(Canvas*, Palette* palette, int, int);
		void renderLeaf(Canvas*, Palette* palette, int, int);
		void renderTree(Canvas*, Palette* palette, int, int);
		void renderDiamond(Canvas*, Palette* palette, int, int);
		void renderSun(Canvas*, Palette* palette, int, int);
		void renderEmblem(Canvas *, Palette* palette, int, int);
	};
}
#endif