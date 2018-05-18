#include "vexmath.h"

double Vexil::VexMath::getDouble(double x, double y, double min, double max)
{
	(max > min) ? max*abs(noise.Evaluate(x, y) + 0.5f) : 0;
}

int Vexil::VexMath::getInt(double x, double y, int min, int max)
{
	(max > min) ? (int)round(max*abs(noise.Evaluate(x, y) + 0.5f)) : 0;

}

double Vexil::VexMath::getRawNoise(int x, int y)
{
	return noise.Evaluate(x, y);
}