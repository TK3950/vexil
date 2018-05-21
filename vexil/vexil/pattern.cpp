#include "pattern.h"
#include <iostream>

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

void Vexil::Pattern::renderDStripes(Canvas* canvas)
{
	for (int lx = 0; lx < TK_WINDOW_WIDTH; lx++)
	{
		
		if (firstPosition == topLeft || firstPosition == bottomRight || firstPosition == top || firstPosition == left)
		{
			/* Draw forward slashes / */
			if (lx < (TK_WINDOW_HEIGHT *strength))
			{
				setDrawColor(canvas, color);
				SDL_RenderDrawLine(canvas->getRenderer(), lx, 0, 0, lx);
				if (symmetry == Pattern::horizontal)
				{
					SDL_RenderDrawLine(canvas->getRenderer(), TK_WINDOW_WIDTH - lx, TK_WINDOW_HEIGHT, TK_WINDOW_WIDTH, TK_WINDOW_HEIGHT - lx);
				}
			}
		}

		if (firstPosition == bottomLeft || firstPosition == topRight || firstPosition == bottom || firstPosition == right)
		{
			/* Draw backward slashes \ */
			if (lx < (TK_WINDOW_WIDTH *strength))
			{
				setDrawColor(canvas, color);
				SDL_RenderDrawLine(canvas->getRenderer(), lx, TK_WINDOW_HEIGHT, 0, TK_WINDOW_HEIGHT-lx);
				if (symmetry == Pattern::horizontal)
				{
					SDL_RenderDrawLine(canvas->getRenderer(), TK_WINDOW_WIDTH-lx, 0, TK_WINDOW_WIDTH, lx);
				}
			}
		}
	}
}

void Vexil::Pattern::renderCross(Canvas* canvas)
{
	setDrawColor(canvas, color);
	switch (firstPosition)
	{
	case Position::left:
		for (int lx = 0; lx < strength*(TK_WINDOW_HEIGHT / 6); lx++)
		{
			SDL_RenderDrawLine(canvas->getRenderer(), (TK_WINDOW_WIDTH / 3)+lx, 0, (TK_WINDOW_WIDTH / 3)+lx, TK_WINDOW_HEIGHT);
			SDL_RenderDrawLine(canvas->getRenderer(), (TK_WINDOW_WIDTH / 3)-lx, 0, (TK_WINDOW_WIDTH / 3)-lx, TK_WINDOW_HEIGHT);
		}
		for (int ly = 0; ly < strength*(TK_WINDOW_HEIGHT / 6); ly++)
		{
			SDL_RenderDrawLine(canvas->getRenderer(), 0, (TK_WINDOW_HEIGHT / 2) + ly, TK_WINDOW_WIDTH, (TK_WINDOW_HEIGHT / 2) + ly);
			SDL_RenderDrawLine(canvas->getRenderer(), 0, (TK_WINDOW_HEIGHT / 2) - ly, TK_WINDOW_WIDTH, (TK_WINDOW_HEIGHT / 2) - ly);
		}
		break;
	case Position::right:
		for (int lx = 0; lx < strength*(TK_WINDOW_HEIGHT / 6); lx++)
		{
			SDL_RenderDrawLine(canvas->getRenderer(), (TK_WINDOW_WIDTH / 3) + lx, 0, (TK_WINDOW_WIDTH / 3) + lx, TK_WINDOW_HEIGHT);
			SDL_RenderDrawLine(canvas->getRenderer(), (TK_WINDOW_WIDTH / 3) - lx, 0, (TK_WINDOW_WIDTH / 3) - lx, TK_WINDOW_HEIGHT);
		}
		for (int ly = 0; ly < strength*(TK_WINDOW_HEIGHT / 6); ly++)
		{
			SDL_RenderDrawLine(canvas->getRenderer(), 0, (TK_WINDOW_HEIGHT / 2) + ly, TK_WINDOW_WIDTH, (TK_WINDOW_HEIGHT / 2) + ly);
			SDL_RenderDrawLine(canvas->getRenderer(), 0, (TK_WINDOW_HEIGHT / 2) - ly, TK_WINDOW_WIDTH, (TK_WINDOW_HEIGHT / 2) - ly);
		}
		break;
	case Position::bottom: // centered cross that doesn't reach the edges
		strength = (strength > .45f) ? .75f : strength;
		strength = (strength < .25f) ? .25f : strength;
		for (int lx = 0; lx < (strength)*(TK_WINDOW_HEIGHT / 6); lx++)
		{
			SDL_RenderDrawLine(canvas->getRenderer(), (TK_WINDOW_WIDTH / 2) + lx, (TK_WINDOW_HEIGHT / 2) - (TK_WINDOW_HEIGHT / 3), (TK_WINDOW_WIDTH / 2) + lx, (TK_WINDOW_HEIGHT / 2) + (TK_WINDOW_HEIGHT / 3));
			SDL_RenderDrawLine(canvas->getRenderer(), (TK_WINDOW_WIDTH / 2) - lx, (TK_WINDOW_HEIGHT / 2) - (TK_WINDOW_HEIGHT / 3), (TK_WINDOW_WIDTH / 2) - lx, (TK_WINDOW_HEIGHT / 2) + (TK_WINDOW_HEIGHT / 3));
		}
		for (int ly = 0; ly < (strength)*(TK_WINDOW_HEIGHT / 6); ly++)
		{
			SDL_RenderDrawLine(canvas->getRenderer(), (TK_WINDOW_WIDTH / 2) - (TK_WINDOW_HEIGHT / 3), (TK_WINDOW_HEIGHT / 2) + ly, (TK_WINDOW_WIDTH / 2) + (TK_WINDOW_HEIGHT / 3), (TK_WINDOW_HEIGHT / 2) + ly);
			SDL_RenderDrawLine(canvas->getRenderer(), (TK_WINDOW_WIDTH / 2) - (TK_WINDOW_HEIGHT / 3), (TK_WINDOW_HEIGHT / 2) - ly, (TK_WINDOW_WIDTH / 2) + (TK_WINDOW_HEIGHT / 3), (TK_WINDOW_HEIGHT / 2) - ly);
		}
		break;
	case Position::top: // centered cross that reaches the edges, dividing the flag into 4 quadrants
		for (int lx = 0; lx < (strength / 2)*(TK_WINDOW_HEIGHT / 6); lx++)
		{
			SDL_RenderDrawLine(canvas->getRenderer(), (TK_WINDOW_WIDTH / 2) + lx, 0, (TK_WINDOW_WIDTH / 2) + lx, TK_WINDOW_HEIGHT);
			SDL_RenderDrawLine(canvas->getRenderer(), (TK_WINDOW_WIDTH / 2) - lx, 0, (TK_WINDOW_WIDTH / 2) - lx, TK_WINDOW_HEIGHT);
		}
		for (int ly = 0; ly < (strength / 2)*(TK_WINDOW_HEIGHT / 6); ly++)
		{
			SDL_RenderDrawLine(canvas->getRenderer(), 0, (TK_WINDOW_HEIGHT / 2) + ly, TK_WINDOW_WIDTH, (TK_WINDOW_HEIGHT / 2) + ly);
			SDL_RenderDrawLine(canvas->getRenderer(), 0, (TK_WINDOW_HEIGHT / 2) - ly, TK_WINDOW_WIDTH, (TK_WINDOW_HEIGHT / 2) - ly);
		}
		break;
	default:
		break;
	}
}

void Vexil::Pattern::renderTriangle(Canvas* canvas)
{
	bool renderTop = false;
	bool renderBottom = false;
	bool renderLeft = false;
	bool renderRight = false;

	if (firstPosition == top || firstPosition == topLeft || symmetry == quad)
	{
		renderTop = true;
		if (symmetry == horizontal)
		{
			renderBottom = true;
		}
	}
	if (firstPosition == right || firstPosition == topRight || symmetry == quad)
	{
		renderRight = true;
		if (symmetry == vertical)
		{
			renderLeft = true;
		}
	}
	if (firstPosition == bottom || firstPosition == bottomRight || symmetry == quad)
	{
		renderBottom = true;
		if (symmetry == horizontal)
		{
			renderTop = true;
		}
	}
	if (firstPosition == left || firstPosition == bottomLeft || symmetry == quad)
	{
		renderLeft = true;
		if (symmetry == vertical)
		{
			renderRight = true;
		}
	}

	strength = (strength > .45f) ? .75f : strength;
	strength = (strength < .25f) ? .25f : strength;
	setDrawColor(canvas, color);
	if (renderTop)
	{
		for (int lx = 0; lx < (strength*TK_WINDOW_WIDTH); lx++)
		{
			SDL_RenderDrawLine(canvas->getRenderer(), (TK_WINDOW_WIDTH / 2), 
			((TK_WINDOW_HEIGHT / 2)*strength) - lx,
				(TK_WINDOW_WIDTH / 2) + ((TK_WINDOW_HEIGHT / 2)*strength) - lx,
				0);
			SDL_RenderDrawLine(canvas->getRenderer(), (TK_WINDOW_WIDTH / 2),
				((TK_WINDOW_HEIGHT / 2)*strength) - lx,
				(TK_WINDOW_WIDTH / 2) - ((TK_WINDOW_HEIGHT / 2)*strength) + lx,
				0);
			
		}
	}

	if (renderBottom)
	{
		for (int lx = 0; lx < (strength*TK_WINDOW_WIDTH); lx++)
		{
			SDL_RenderDrawLine(canvas->getRenderer(), (TK_WINDOW_WIDTH / 2),
				TK_WINDOW_HEIGHT-((TK_WINDOW_HEIGHT / 2)*strength) + lx,
				(TK_WINDOW_WIDTH / 2) + ((TK_WINDOW_HEIGHT / 2)*strength) - lx,
				TK_WINDOW_HEIGHT);
			SDL_RenderDrawLine(canvas->getRenderer(), (TK_WINDOW_WIDTH / 2),
				TK_WINDOW_HEIGHT - ((TK_WINDOW_HEIGHT / 2)*strength) + lx,
				(TK_WINDOW_WIDTH / 2) - ((TK_WINDOW_HEIGHT / 2)*strength) + lx,
				TK_WINDOW_HEIGHT);

		}
	}

	if (renderLeft)
	{
		for (int lx = 0; lx < (strength*TK_WINDOW_WIDTH); lx++)
		{
			SDL_RenderDrawLine(canvas->getRenderer(), ((TK_WINDOW_HEIGHT / 2)*strength) - lx,
				(TK_WINDOW_HEIGHT / 2),
				0,
				(TK_WINDOW_HEIGHT / 2) + ((TK_WINDOW_HEIGHT / 2)*strength) - lx);
			SDL_RenderDrawLine(canvas->getRenderer(), ((TK_WINDOW_HEIGHT / 2)*strength) - lx,
				(TK_WINDOW_HEIGHT / 2),
				0,
				(TK_WINDOW_HEIGHT / 2) - ((TK_WINDOW_HEIGHT / 2)*strength) + lx);

		}
	}

	if (renderLeft)
	{
		for (int lx = 0; lx < (strength*TK_WINDOW_WIDTH); lx++)
		{
			SDL_RenderDrawLine(canvas->getRenderer(), TK_WINDOW_WIDTH - (((TK_WINDOW_HEIGHT / 2)*strength) - lx),
				(TK_WINDOW_HEIGHT / 2),
				TK_WINDOW_WIDTH,
				(TK_WINDOW_HEIGHT / 2) + ((TK_WINDOW_HEIGHT / 2)*strength) - lx);
			SDL_RenderDrawLine(canvas->getRenderer(), TK_WINDOW_WIDTH - (((TK_WINDOW_HEIGHT / 2)*strength) - lx),
				(TK_WINDOW_HEIGHT / 2),
				TK_WINDOW_WIDTH,
				(TK_WINDOW_HEIGHT / 2) - ((TK_WINDOW_HEIGHT / 2)*strength) + lx);

		}
	}

}

void Vexil::Pattern::renderRectangle(Canvas* canvas)
{

}
void Vexil::Pattern::renderCheckers(Canvas* canvas)
{

}