#include "accessory.h"
#include "triangle.h"
#include <iostream>

Vexil::Accessory::Accessory()
{
	double r = VexMath::getDouble(123, 456, 0.0f, 1.0f);
	double g = VexMath::getDouble(789, 987, 0.0f, 1.0f);
	double b = VexMath::getDouble(654, 321, 0.0f, 1.0f);
	double a = 1.0f;

	color = new Color(r, g, b, a);
	count = VexMath::getInt(12, 21, 0, 7);
	type = (AccessoryType)VexMath::getInt(986, 23154, 0, AccessoryType::emblem);
	accessoryPattern = (AccessoryPattern)VexMath::getInt(21, 5322, 0, AccessoryPattern::bow);
	size = VexMath::getDouble(352, 789, 0.25f, 0.99999f);
	location = (AccessoryLocation)VexMath::getInt(124, 986, 0, AccessoryLocation::center);
	blockPatterns = (VexMath::getInt(451, 451, 0, 4) > 1) ? false : true;

	colorSelect = VexMath::getInt(2134, 4543, 0, 3);

	switch (location)
	{
	case center:
		x = TK_WINDOW_WIDTH / 2;
		y = TK_WINDOW_HEIGHT / 2;
		break;
	case topLeft:
		x = TK_WINDOW_WIDTH / 4;
		y = TK_WINDOW_HEIGHT / 4;
		break;
	case topRight:
		x = 3 *(TK_WINDOW_WIDTH / 4);
		y = TK_WINDOW_HEIGHT / 4;
		break;
	case bottomRight:
		x = 3 * (TK_WINDOW_WIDTH / 4);
		y = 3 * (TK_WINDOW_HEIGHT / 4);
		break;
	case bottomLeft:
		x = TK_WINDOW_WIDTH / 4;
		y = 3 * (TK_WINDOW_HEIGHT / 4);
		break;

	case left:
		x = TK_WINDOW_WIDTH / 4;
		y = TK_WINDOW_HEIGHT / 2;
		break;
	case right:
		x = 3 * (TK_WINDOW_WIDTH / 4);
		y = TK_WINDOW_HEIGHT / 2;
		break;
	case top:
		x = TK_WINDOW_WIDTH / 2;
		y = TK_WINDOW_HEIGHT / 4;
		break;
	case bottom:
		x = TK_WINDOW_WIDTH / 2;
		y = 3 * (TK_WINDOW_HEIGHT / 4);
		break;
	}
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


void Vexil::Accessory::renderSingle(Canvas* canvas, Palette* palette)
{
	renderShape(canvas, palette, x, y);
}
void Vexil::Accessory::renderGrid(Canvas* canvas, Palette* palette) // render grid starting at the center and expanding outward
{
	int yMax = (TK_WINDOW_HEIGHT / 2)*size;
	int xMax = (TK_WINDOW_WIDTH / 2)*size;
	int xIncr = xMax / count;
	int yIncr = yMax / count;
	for (int i = 0; i < count/2; i++)
	{
		for (int j = 0; j < count/2; j++)
		{
			renderShape(canvas, palette, x + i*xIncr, y + j*yIncr);
			renderShape(canvas, palette, x - i*xIncr, y - j*yIncr);
			renderShape(canvas, palette, x + i*xIncr, y - j*yIncr);
			renderShape(canvas, palette, x - i*xIncr, y + j*yIncr);
			// some overlap rendering occurs, but this is a small price to keep it centered
		}
	}
}
void Vexil::Accessory::renderCircular(Canvas* canvas, Palette* palette) // circular around the center
{
	double radius = (TK_WINDOW_HEIGHT / 4)*size;
	for (int i = 0; i < count; i++)
	{
		int lx = radius * cos(((2 * PI) / (double)count) * i);
		int ly = radius * sin(((2 * PI) / (double)count) * i);
		renderShape(canvas, palette, x+lx, y+ly);
	}
}
void Vexil::Accessory::renderBow(Canvas* canvas, Palette* palette) // halfish circle around the center
{
	double radius = (TK_WINDOW_HEIGHT / 2)*size;
	for (int i = 1; i < count-1; i++)
	{
		int lx = radius * cos(((PI) / (double)count) * i);
		int ly = radius * sin(((PI) / (double)count) * i);
		renderShape(canvas, palette, x+lx, y+ly);
	}
}
void Vexil::Accessory::renderStagGrid(Canvas* canvas, Palette* palette) // render staggered grid starting at the center and expanding outward
{
	for (int i = 0; i < count; i++)
	{
		int yMax = (TK_WINDOW_HEIGHT / 2)*size;
		int xMax = (TK_WINDOW_WIDTH / 2)*size;
		int xIncr = xMax / (2*count);
		int yIncr = yMax / (2*count);
		for (int i = 0; i < count/2; i++)
		{
			for (int j = 0; j < count/2; j++)
			{
				if (j%2 == i%2)
				{
					renderShape(canvas, palette, x + i*xIncr, y + j*yIncr);
					renderShape(canvas, palette, x - i*xIncr, y - j*yIncr);
					renderShape(canvas, palette, x + i*xIncr, y - j*yIncr);
					renderShape(canvas, palette, x - i*xIncr, y + j*yIncr);
				}
			}
		}
	}
}

void Vexil::Accessory::renderShape(Canvas* canvas, Palette* palette, int lx, int ly)
{
	switch (type)
	{
	case Vexil::Accessory::star:
		renderStar(canvas, palette, lx, ly);
		break;
	case Vexil::Accessory::accCross:
		renderCross(canvas, palette, lx, ly);
		break;
	case Vexil::Accessory::moon:
		renderMoon(canvas, palette, lx, ly);
		break;
	case Vexil::Accessory::circle:
		renderCircle(canvas, palette, lx, ly);
		break;
	case Vexil::Accessory::leaf:
		//renderLeaf(canvas, palette, lx, ly);
		break;
	case Vexil::Accessory::tree:
		//renderTree(canvas, palette, lx, ly);
		break;
	case Vexil::Accessory::diamond:
		renderDiamond(canvas, palette, lx, ly);
		break;
	case Vexil::Accessory::sun:
		//renderSun(canvas, palette, lx, ly);
		break;
	case Vexil::Accessory::emblem:
		//renderEmblem(canvas, palette, lx, ly);
		break;
	case Vexil::Accessory::accNone:
	default:
		break;
	}
}

void Vexil::Accessory::renderCircle(Canvas* canvas, Palette* palette, int ix, int iy)
{
	setDrawColor(canvas, palette->getColorAt(colorSelect));
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

void Vexil::Accessory::renderStar(Canvas* canvas, Palette* palette, int ix, int iy)
{
	setDrawColor(canvas, palette->getColorAt(colorSelect));
	double radius = (TK_WINDOW_HEIGHT / (5 * count))*size;
	int px[5];
	int py[5];
	int sx[5];
	int sy[5];
	// exterior points
	for (int i = 0; i < 5; i++)
	{
		double angle = DEG360 / 5.0f;
		px[i] = radius * cos(angle*+i - DEG90);
		py[i] = radius * sin(angle*i - DEG90);
	}
	// interior points
	for (int i = 0; i < 5; i++)
	{
		double angle = DEG360 / 5.0f;
		double phase = DEG360 / 10.0f - DEG90;
		sx[i] = .4f *radius * cos(angle*i + phase);
		sy[i] = .4f * radius * sin(angle*i + phase);
	}
	Triangle t1 = Triangle(
		Point(ix + px[4], iy + py[4]),
		Point(ix + px[2], iy + py[2]),
		Point(ix + sx[0], iy + sy[0])
	);

	Triangle t2 = Triangle(
		Point(ix + px[3], iy + py[3]),
		Point(ix + px[1], iy + py[1]),
		Point(ix + sx[4], iy + sy[4])
	);

	Triangle t3 = Triangle(
		Point(ix + px[0], iy + py[0]),
		Point(ix + px[3], iy + py[3]),
		Point(ix + sx[1], iy + sy[1])

	);

	for (int i = ix - radius; i < ix + radius; i++)
	{
		for (int j = iy - radius; j < iy + radius; j++)
		{
			if (VexMath::isInsideTriangle(Point(i, j), t1.getA(), t1.getB(), t1.getC()))
			{
				SDL_RenderDrawPoint(canvas->getRenderer(), i, j);
			}
			if (VexMath::isInsideTriangle(Point(i, j), t2.getA(), t2.getB(), t2.getC()))
			{
				SDL_RenderDrawPoint(canvas->getRenderer(), i, j);
			}
			if (VexMath::isInsideTriangle(Point(i, j), t3.getA(), t3.getB(), t3.getC()))
			{
				SDL_RenderDrawPoint(canvas->getRenderer(), i, j);
			}
		}
	}
	
}

void  Vexil::Accessory::renderDiamond(Canvas* canvas, Palette* palette, int ix, int iy)
{
	// diamond consists of four points
	// ix +- scale
	// iy +- scale
	double scale = (TK_WINDOW_HEIGHT / (5 * count))*size;
	double narrowness = .6;
	setDrawColor(canvas, palette->getColorAt(colorSelect));

	Triangle t1 = Triangle(
		Point(ix + narrowness*scale, iy),
		Point(ix - narrowness*scale, iy),
		Point(ix, iy + scale)
	);

	Triangle t2 = Triangle(
		Point(ix + narrowness*scale, iy),
		Point(ix - narrowness*scale, iy),
		Point(ix, iy - scale)
	);

	for (int i = ix - scale; i < ix + scale; i++)
	{
		for (int j = iy - scale; j < iy + scale; j++)
		{
			if (VexMath::isInsideTriangle(Point(i, j), t1.getA(), t1.getB(), t1.getC()))
			{
				SDL_RenderDrawPoint(canvas->getRenderer(), i, j);
			}
			if (VexMath::isInsideTriangle(Point(i, j), t2.getA(), t2.getB(), t2.getC()))
			{
				SDL_RenderDrawPoint(canvas->getRenderer(), i, j);
			}
		}
	}
	SDL_RenderDrawLine(canvas->getRenderer(), ix + narrowness*scale, iy, ix - narrowness*scale+1, iy);
}

void Vexil::Accessory::renderMoon(Canvas* canvas, Palette* palette, int ix, int iy)
{
	setDrawColor(canvas, palette->getColorAt(colorSelect));
	double radius = (TK_WINDOW_HEIGHT / (5 * count))*size;
	double phase = 4*size;
	for (int lx = 0; lx < TK_WINDOW_WIDTH; lx++)
	{
		for (int ly = 0; ly < TK_WINDOW_HEIGHT; ly++)
		{
			double dx = ix - lx;
			double dy = iy - ly;
			double sx = dx - phase * 2;
			double sy = dy - phase;
			if (sqrt(dx*dx + dy*dy) < radius && sqrt(sx*sx + sy*sy) > radius)
			{

				SDL_RenderDrawPoint(canvas->getRenderer(), lx, ly);
			}
		}
	}
}

void  Vexil::Accessory::renderCross(Canvas* canvas, Palette* palette, int ix, int iy)
{
	double scale = (TK_WINDOW_HEIGHT / (5 * count))*size;
	for (int i = 0; i < scale / 4; i++)
	{
		SDL_RenderDrawLine(canvas->getRenderer(), ix + scale, iy + i, ix - scale, iy + i);
		SDL_RenderDrawLine(canvas->getRenderer(), ix + scale, iy - i, ix - scale, iy - i);

		SDL_RenderDrawLine(canvas->getRenderer(), ix + i, iy + scale, ix + i, iy - scale);
		SDL_RenderDrawLine(canvas->getRenderer(), ix - i, iy + scale, ix - i, iy - scale);
	}
}
