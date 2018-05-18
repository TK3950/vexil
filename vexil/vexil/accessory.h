#pragma once
#ifndef ACCESSORY_H
#define ACCESSORY_H 1
#include "color.h"
#include "vexmath.h"

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

	private:
		AccessoryType type;
		AccessoryPattern accessoryPattern;
		int count; // how many of the accessory
		double size;
		bool blockPatterns; // if true, render base color inside bounding box of acc.
		int x;
		int y; // accessories have positions
		Color* color;

	public:
		AccessoryType getType();
		AccessoryPattern getPattern();
		int getCount();
		double getSize();
		bool isBlocking();
		int getX();
		int getY();
		Color* getColor();


	};
}
#endif