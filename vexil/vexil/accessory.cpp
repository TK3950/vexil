#include "accessory.h"
#include <iostream>

Vexil::Accessory::Accessory()
{
	double r = VexMath::getDouble(123, 456, 0.0f, 1.0f);
	double g = VexMath::getDouble(789, 987, 0.0f, 1.0f);
	double b = VexMath::getDouble(654, 321, 0.0f, 1.0f);
	double a = 1.0f;

	color = new Color(r, g, b, a);
	count = VexMath::getInt(12, 21, 0, 5);
	type = (AccessoryType)VexMath::getInt(986, 23154, 0, AccessoryType::emblem);
	accessoryPattern = (AccessoryPattern)VexMath::getInt(21, 5322, 0, AccessoryPattern::bow+1);
	size = VexMath::getDouble(352, 789, 0.25f, 0.99999f);
	location = (AccessoryLocation)VexMath::getInt(124, 986, 0, AccessoryLocation::center+1);

	x = VexMath::getDouble(753, 159, 0.0, (double)TK_WINDOW_WIDTH);
	y = VexMath::getDouble(159, 486, 0.0, (double)TK_WINDOW_WIDTH);

	
	blockPatterns = (VexMath::getInt(451, 451, 0, 4) > 1) ? false : true;
	type = circle;
}

Vexil::Accessory::AccessoryType Vexil::Accessory::getType()
{
	return type;
}
Vexil::Accessory::AccessoryPattern Vexil::Accessory::getPattern()
{
	return accessoryPattern;
}
Vexil::Accessory::AccessoryLocation Vexil::Accessory::getLocation()
{
	return location;
}
int Vexil::Accessory::getCount()
{
	return count;
}
double Vexil::Accessory::getSize()
{
	return size;
}
bool Vexil::Accessory::isBlocking()
{
	return blockPatterns;
}
int Vexil::Accessory::getX()
{
	return x;
}
int Vexil::Accessory::getY()
{
	return y;
}
Color* Vexil::Accessory::getColor()
{
	return color;
}

void Vexil::Accessory::setDrawColor(Canvas* canvas, Color* c)
{
	SDL_SetRenderDrawColor(canvas->getRenderer(),
		(int)(c->getRed() * 255),
		(int)(c->getGreen() * 255),
		(int)(c->getBlue() * 255),
		(int)(c->getAlpha() * 255));
}


void Vexil::Accessory::renderSingle(Canvas* canvas)
{
	renderShape(canvas, x, y);
}
void Vexil::Accessory::renderGrid(Canvas* canvas)
{
	std::cout << "grid";
	int yMax = (TK_WINDOW_HEIGHT / 2)*size;
	int xMax = (TK_WINDOW_WIDTH / 2)*size;
	int xIncr = xMax / count;
	int yIncr = yMax / count;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			renderShape(canvas, x+i*xIncr, y+j*yIncr);
		}
	}
}
void Vexil::Accessory::renderCircular(Canvas* canvas)
{
	double radius = (TK_WINDOW_HEIGHT / 4)*size;
	for (int i = 0; i < count; i++)
	{
		int lx = radius * cos(((2 * PI) / (double)count) * i);
		int ly = radius * sin(((2 * PI) / (double)count) * i);
		renderShape(canvas, x+lx, y+ly);
	}
}
void Vexil::Accessory::renderBow(Canvas* canvas)
{
	double radius = (TK_WINDOW_HEIGHT / 2)*size;
	for (int i = 1; i < count-1; i++)
	{
		int lx = radius * cos(((PI) / (double)count) * i);
		int ly = radius * sin(((PI) / (double)count) * i);
		renderShape(canvas, x+lx, y+ly);
	}
}
void Vexil::Accessory::renderStagGrid(Canvas* canvas)
{
	std::cout << "staggered";
	for (int i = 0; i < count; i++)
	{
		int yMax = (TK_WINDOW_HEIGHT / 2)*size;
		int xMax = (TK_WINDOW_WIDTH / 2)*size;
		int xIncr = xMax / count;
		int yIncr = yMax / count;
		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < count; j++)
			{
				if (j%2 == i%2)
				{
					renderShape(canvas, x+i*xIncr, y+j*yIncr);
				}
			}
		}
	}
}

void Vexil::Accessory::renderShape(Canvas* canvas, int lx, int ly)
{
	switch (type)
	{
	case Vexil::Accessory::star:
		//renderStar(canvas, lx, ly);
		break;
	case Vexil::Accessory::accCross:
		//renderCross(canvas, lx, ly);
		break;
	case Vexil::Accessory::moon:
		//renderMoon(canvas, lx, ly);
		break;
	case Vexil::Accessory::circle:
		renderCircle(canvas, lx, ly);
		break;
	case Vexil::Accessory::leaf:
		//renderLeaf(canvas, lx, ly);
		break;
	case Vexil::Accessory::tree:
		//renderTree(canvas, lx, ly);
		break;
	case Vexil::Accessory::diamond:
		//renderDiamond(canvas, lx, ly);
		break;
	case Vexil::Accessory::sun:
		//renderSun(canvas, lx, ly);
		break;
	case Vexil::Accessory::emblem:
		//renderEmblem(canvas, lx, ly);
		break;
	case Vexil::Accessory::accNone:
	default:
		break;
	}
}

void Vexil::Accessory::renderCircle(Canvas* canvas, int ix, int iy)
{
	setDrawColor(canvas, color);
	double radius = (TK_WINDOW_HEIGHT / (5*count))*size;
	for (int lx = 0; lx < TK_WINDOW_WIDTH; lx++)
	{
		for (int ly = 0; ly < TK_WINDOW_HEIGHT; ly++)
		{
			double dx = ix - lx;
			double dy = iy - ly;
			if (sqrt(dx*dx + dy*dy) < radius)
			{
				SDL_RenderDrawPoint(canvas->getRenderer(), lx, ly);
			}
		}
	}
}