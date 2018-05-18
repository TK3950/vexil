#include "flag.h"
#include <math.h>


Vexil::Flag::Flag(Vexil::Canvas* c)
{
	canvas = c;
	noise = new OpenSimplexNoise();
	patternCount = VexMath::getInt(800, 400, 0, Pattern::checkers);
	accessoryCount = VexMath::getInt(400, 400, 0, Accessory::emblem);
	
}

void Vexil::Flag::createPatterns(int patternsMax)
{
	for (int count = 0; count < patternsMax; count++)
	{
		patterns[count] = Pattern();
	}
}

void Vexil::Flag::createAccessories(int accessoriesMax)
{
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

	patternCount = VexMath::getInt(400, 400, 0, Pattern::checkers);
	accessoryCount = VexMath::getInt(400, 400, 0, Accessory::emblem);

	createPatterns(patternCount);
	createAccessories(accessoryCount);

}

void Vexil::Flag::setDrawColor(Color* c)
{
	SDL_SetRenderDrawColor(canvas->getRenderer(), c->getRed(), c->getGreen(), c->getBlue(), c->getAlpha());
}

void Vexil::Flag::renderBase()
{
	setDrawColor(baseColor);
	SDL_RenderClear(canvas->getRenderer);
}
void Vexil::Flag::renderPatterns()
{
	for (int i = 0; i < patternCount; i++)
	{
		switch (patterns[i].getType())
		{
			// now what do we do to render

		default:
			break;
		}
	}
}
void Vexil::Flag::renderAccessories()
{
	for (int i = 0; i < patternCount; i++)
	{
		switch (accessories[i].getType())
		{
			// now what do we do to render

		default:
			break;
		}
	}
}
void Vexil::Flag::renderText()
{

}