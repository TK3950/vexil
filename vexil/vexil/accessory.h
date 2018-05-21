#pragma once
#ifndef ACCESSORY_H
#define ACCESSORY_H 1
#include "color.h"
#include "vexmath.h"
#include "canvas.h"

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

		enum AccessoryLocation { // if multiple acc., what pattern do they appear in
			topLeft = 0,
			topRight,
			bottomLeft,
			bottomRight,
			center
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

		void renderSingle(Canvas*);
		void renderGrid(Canvas*);
		void renderCircular(Canvas*);
		void renderBow(Canvas*);
		void renderStagGrid(Canvas*);

		void renderShape(Canvas *, int, int);

		void renderStar(Canvas*, int, int);
		void renderCross(Canvas*, int, int);
		void renderMoon(Canvas*, int, int);
		void renderCircle(Canvas*, int, int);
		void renderLeaf(Canvas*, int, int);
		void renderTree(Canvas*, int, int);
		void renderDiamond(Canvas*, int, int);
		void renderSun(Canvas*, int, int);
		void renderEmblem(Canvas *, int, int);
	};
}
#endif