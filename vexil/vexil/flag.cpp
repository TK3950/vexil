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

	patternCount = VexMath::getInt(400, 400, 0,4 );
	accessoryCount = VexMath::getInt(400, 400, 0, 2);

	std::cout << "Color: " << baseColor->getRed() << baseColor->getGreen() << baseColor->getBlue() << std::endl;
	std::cout << patternCount << " patterns and " << accessoryCount << " accessories.\nPress G on main window to generate.\n";

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
	setDrawColor(canvas, baseColor);
	SDL_RenderClear(canvas->getRenderer());
}
void Vexil::Flag::renderPatterns()
{
	for (int i = 0; i < patternCount; i++)
	{
		switch (patterns[i].getType())
		{
		case Vexil::Pattern::vStripes:
			patterns[i].renderVStripes(canvas);
			break;
		case Vexil::Pattern::hStripes:
			patterns[i].renderHStripes(canvas);
			break;
		case Vexil::Pattern::dStripes:
			patterns[i].renderDStripes(canvas);
			break;
		case Vexil::Pattern::pattCross:
			patterns[i].renderCross(canvas);
			break;
		case Vexil::Pattern::triangle:
			patterns[i].renderTriangle(canvas);
			break;
		case Vexil::Pattern::rectangle:
			patterns[i].renderRectangle(canvas);
			break;
		case Vexil::Pattern::checkers:
			patterns[i].renderCheckers(canvas);
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
			accessories[i].renderBow(canvas);
			break;
		case Vexil::Accessory::AccessoryPattern::circular:
			accessories[i].renderCircular(canvas);
			break;
		case Vexil::Accessory::AccessoryPattern::grid:
			accessories[i].renderGrid(canvas);
			break;
		case Vexil::Accessory::AccessoryPattern::staggeredGrid:
			accessories[i].renderStagGrid(canvas);
			break;
		case Vexil::Accessory::AccessoryPattern::single:
		default:
			accessories[i].renderSingle(canvas);
			break;
		}
	}
}
void Vexil::Flag::renderText()
{

}