#pragma once
#ifndef PATTERN_H
#define PATTERN_H 1
#include "color.h"
#include "vexmath.h"
#include "canvas.h"

namespace Vexil {
	class Pattern {
	public:
		enum PatternType {
			pattNone = 0,
			vStripes,
			hStripes,
			dStripes,
			pattCross,
			triangle,
			rectangle,
			checkers
		};

		enum Symmetry {
			symmNone = 0,
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
		void setDrawColor(Canvas*, Color*);
		void renderVStripes(Canvas*);
		void renderHStripes(Canvas*);
		void renderDStripes(Canvas*);
		void renderCross(Canvas*);
		void renderTriangle(Canvas*);
		void renderRectangle(Canvas*);
		void renderCheckers(Canvas*);
		
	};
}

#endif