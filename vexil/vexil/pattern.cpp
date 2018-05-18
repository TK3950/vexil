#include "pattern.h"

Vexil::Pattern::Pattern()
{
	double r = VexMath::getDouble(456, 123, 0.0f, 1.0f);
	double g = VexMath::getDouble(789, 789, 0.0f, 1.0f);
	double b = VexMath::getDouble(123, 456, 0.0f, 1.0f);
	double a = 1.0f;

	color = new Color(r, g, b, a);
	type = (PatternType)VexMath::getInt(986, 23154, 0, PatternType::checkers);
	symmetry = (Symmetry)VexMath::getInt(21, 5322, 0, Symmetry::diagonalQuad);
	strength = VexMath::getDouble(352, 4112, 0.0f, 1.0f);
	firstPosition = (Position)VexMath::getInt(782, 4561, 0, Position::topLeft);
}

Vexil::Pattern::PatternType Vexil::Pattern::getType()
{
	return type;
}
Vexil::Pattern::Symmetry Vexil::Pattern::getSymmetry()
{
	return symmetry;
}
double Vexil::Pattern::getStrength()
{
	return strength;
}
Color* Vexil::Pattern::getColor()
{
	return color;
}

void Vexil::Pattern::setDrawColor(Canvas* canvas, Color* c)
{
	SDL_SetRenderDrawColor(canvas->getRenderer(),
		(int)(c->getRed() * 255),
		(int)(c->getGreen() * 255),
		(int)(c->getBlue() * 255),
		(int)(c->getAlpha() * 255));
}

void Vexil::Pattern::renderVStripes(Canvas* canvas)
{
	for (int lx = 0; lx < TK_WINDOW_WIDTH; lx++)
	{

		if (firstPosition == topLeft || firstPosition == bottomLeft || firstPosition == left || firstPosition == top)
		{
			if (lx < (TK_WINDOW_WIDTH *strength))
			{
				setDrawColor(canvas, color);
				SDL_RenderDrawLine(canvas->getRenderer(), lx, 0, lx, TK_WINDOW_HEIGHT);
				if (symmetry == Pattern::vertical)
				{
					SDL_RenderDrawLine(canvas->getRenderer(), TK_WINDOW_WIDTH-lx, 0, TK_WINDOW_WIDTH - lx, TK_WINDOW_HEIGHT);
				}
			}
		}

		if (firstPosition == topRight || firstPosition == bottomRight || firstPosition == right || firstPosition == bottom)
		{
			if (lx > (TK_WINDOW_WIDTH *strength))
			{
				setDrawColor(canvas, color);
				SDL_RenderDrawLine(canvas->getRenderer(), lx, 0, lx, TK_WINDOW_HEIGHT);
				if (symmetry == Pattern::vertical)
				{
					SDL_RenderDrawLine(canvas->getRenderer(), TK_WINDOW_WIDTH - lx, 0, TK_WINDOW_WIDTH - lx, TK_WINDOW_HEIGHT);
				}
			}
		}
	}
}

void Vexil::Pattern::renderHStripes(Canvas* canvas)
{
	for (int ly = 0; ly < TK_WINDOW_HEIGHT; ly++)
	{

		if (firstPosition == topLeft || firstPosition == topRight || firstPosition == top || firstPosition == left)
		{
			if (ly < (TK_WINDOW_HEIGHT *strength))
			{
				setDrawColor(canvas, color);
				SDL_RenderDrawLine(canvas->getRenderer(), 0, ly, TK_WINDOW_WIDTH, ly);
				if (symmetry == Pattern::horizontal)
				{
					SDL_RenderDrawLine(canvas->getRenderer(), 0, TK_WINDOW_HEIGHT - ly,TK_WINDOW_WIDTH, TK_WINDOW_HEIGHT - ly);
				}
			}
		}

		if (firstPosition == bottomLeft || firstPosition == bottomRight || firstPosition == bottom || firstPosition == right)
		{
			if (ly > (TK_WINDOW_HEIGHT *strength))
			{
				setDrawColor(canvas, color);
				SDL_RenderDrawLine(canvas->getRenderer(), 0, ly, TK_WINDOW_WIDTH, ly);
				if (symmetry == Pattern::horizontal)
				{
					SDL_RenderDrawLine(canvas->getRenderer(), 0, TK_WINDOW_HEIGHT - ly, TK_WINDOW_WIDTH, TK_WINDOW_HEIGHT - ly);
				}
			}
		}
	}
}