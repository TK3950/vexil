#include "flag.h"
#include <math.h>
#include <iostream>
#include <string>

Vexil::Flag::Flag(Vexil::Canvas* c)
{
	canvas = c;
	noise = new OpenSimplexNoise();
	patternCount = VexMath::getInt(800, 400, 0, Pattern::checkers);
	accessoryCount = VexMath::getInt(400, 400, 0, Accessory::emblem);
	
}

void Vexil::Flag::createPatterns(int patternsMax)
{
	patterns = new Pattern[patternsMax];
	for (int count = 0; count < patternsMax; count++)
	{
		patterns[count] = Pattern();
	}
}


void Vexil::Flag::createAccessories(int accessoriesMax)
{
	accessories = new Accessory[accessoriesMax];
	for (int count = 0; count < accessoriesMax; count++)
	{
		accessories[count] = Accessory();
	}
}

void Vexil::Flag::generate()
{
	double r = VexMath::getDouble(50, 100, 0.0f, 1.0f);
	double g = VexMath::getDouble(150, 300, 0.0f, 1.0f);
	double b = VexMath::getDouble(550, 15, 0.0f, 1.0f);
	double a = 1.0f;
	baseColor = new Color(r, g, b, a);
	palette = new Palette();
	patternCount = VexMath::getInt(400, 400, 0,4 );
	accessoryCount = VexMath::getInt(400, 400, 0, 2);

	createPatterns(patternCount);
	createAccessories(accessoryCount);

	renderBase();
	renderPatterns();
	renderAccessories();
}

void Vexil::Flag::setDrawColor(Canvas* canvas, Color* c)
{
	SDL_SetRenderDrawColor(canvas->getRenderer(),
		(int)(c->getRed() * 255),
		(int)(c->getGreen() * 255),
		(int)(c->getBlue() * 255),
		(int)(c->getAlpha() * 255));
}

void Vexil::Flag::renderBase()
{
	setDrawColor(canvas, palette->getColorAt(0));
	SDL_RenderClear(canvas->getRenderer());
}
void Vexil::Flag::renderPatterns()
{
	
	for (int i = 0; i < patternCount; i++)
	{
		switch (patterns[i].getType())
		{
		case Vexil::Pattern::vStripes:
			patterns[i].renderVStripes(canvas, palette);
			break;
		case Vexil::Pattern::hStripes:
			patterns[i].renderHStripes(canvas, palette);
			break;
		case Vexil::Pattern::dStripes:
			patterns[i].renderDStripes(canvas, palette);
			break;
		case Vexil::Pattern::pattCross:
			patterns[i].renderCross(canvas, palette);
			break;
		case Vexil::Pattern::triangle:
			patterns[i].renderTriangle(canvas, palette);
			break;
		case Vexil::Pattern::rectangle:
			patterns[i].renderRectangle(canvas, palette);
			break;
		case Vexil::Pattern::pattNone:
		default:
			break;
		}
	}
}
void Vexil::Flag::renderAccessories()
{
	
	for (int i = 0; i < accessoryCount; i++)
	{
		switch (accessories[i].getPattern())
		{
		case Vexil::Accessory::AccessoryPattern::bow:
			accessories[i].renderBow(canvas, palette);
			break;
		case Vexil::Accessory::AccessoryPattern::circular:
			accessories[i].renderCircular(canvas, palette);
			break;
		case Vexil::Accessory::AccessoryPattern::grid:
			accessories[i].renderGrid(canvas, palette);
			break;
		case Vexil::Accessory::AccessoryPattern::staggeredGrid:
			accessories[i].renderStagGrid(canvas, palette);
			break;
		case Vexil::Accessory::AccessoryPattern::single:
		default:
			accessories[i].renderSingle(canvas, palette);
			break;
		}
	}
}
void Vexil::Flag::renderText()
{

}

void Vexil::Flag::testPalette()
{
	generate();
	setDrawColor(canvas, (palette->getColorAt(0)));
	SDL_RenderClear(canvas->getRenderer());

	for (int i = 1; i <= 3; i++)
	{
		setDrawColor(canvas, (palette->getColorAt(i)));
		for (int xx = i*(TK_WINDOW_WIDTH / 4); xx < TK_WINDOW_WIDTH; xx++)
		{
			SDL_RenderDrawLine(canvas->getRenderer(), xx, 0, xx, TK_WINDOW_HEIGHT);
		}
	}
}

void Vexil::Flag::viewPalette()
{
	setDrawColor(canvas, (palette->getColorAt(0)));
	SDL_RenderClear(canvas->getRenderer());

	for (int i = 1; i <= 3; i++)
	{
		setDrawColor(canvas, (palette->getColorAt(i)));
		for (int xx = i*(TK_WINDOW_WIDTH / 4); xx < TK_WINDOW_WIDTH; xx++)
		{
			SDL_RenderDrawLine(canvas->getRenderer(), xx, 0, xx, TK_WINDOW_HEIGHT);
		}
	}
}