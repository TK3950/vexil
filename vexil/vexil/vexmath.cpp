#include "vexmath.h"


double Vexil::VexMath::getDouble(double x, double y, double min, double max)
{
	OpenSimplexNoise noise; // NOTE: I hate generating new noise for every call
	// but we can't seem to make the noise static
	return (max > min) ? min+max*abs(noise.Evaluate(x, y) + 0.5f) : 0;
}

int Vexil::VexMath::getInt(double x, double y, int min, int max)
{
	OpenSimplexNoise noise;
	return (max > min) ? (int)round(min+max*abs(noise.Evaluate(x, y) + 0.5f)) : 0;

}

double Vexil::VexMath::getRawNoise(int x, int y)
{
	OpenSimplexNoise noise;
	return noise.Evaluate(x, y);
}