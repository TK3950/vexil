#pragma once
#ifndef PATTERN_H
#define PATTERN_H 1
#include "color.h"
#include "vexmath.h"

namespace Vexil {
	class Pattern {
	public:
		enum PatternType {
			none = 0,
			vStripes,
			hStripes,
			dStripes,
			cross,
			triangle,
			rectangle,
			checkers
		};

		enum Symmetry {
			none = 0,
			horizontal,
			vertical,
			quad,
			diagonalPositive,
			diagonalNegative,
			diagonalQuad
		};

		enum Position {
			top = 0,
			topRight,
			right,
			bottomRight,
			bottom,
			bottomLeft,
			left,
			topLeft
		};
	private:

		
		PatternType type;
		Symmetry symmetry;
		Position firstPosition;
		double strength;
		Color* color;
	public:
		Pattern();
		PatternType getType();
		Symmetry getSymmetry();
		double getStrength();
		Color* getColor();
		
	};
}

#endif