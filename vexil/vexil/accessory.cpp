#include "accessory.h"

Vexil::Accessory::Accessory()
{
	double r = VexMath::getDouble(123, 456, 0.0f, 1.0f);
	double g = VexMath::getDouble(789, 987, 0.0f, 1.0f);
	double b = VexMath::getDouble(654, 321, 0.0f, 1.0f);
	double a = 1.0f;

	color = new Color(r, g, b, a);
	count = VexMath::getInt(12, 21, 0, 5);
	type = (AccessoryType)VexMath::getInt(986, 23154, 0, AccessoryType::emblem);
	accessoryPattern = (AccessoryPattern)VexMath::getInt(21, 5322, 0, AccessoryPattern::bow);
	size = VexMath::getDouble(352, 789, 0.0f, 1.0f);
	x = VexMath::getDouble(753, 159, 0.0, (double)809);
	y = VexMath::getDouble(159, 486, 0.0, (double)500);
	
	blockPatterns = (VexMath::getInt(451, 451, 0, 4) > 1) ? false : true;
}

Vexil::Accessory::AccessoryType Vexil::Accessory::getType()
{
	return type;
}
Vexil::Accessory::AccessoryPattern Vexil::Accessory::getPattern()
{
	return accessoryPattern;
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