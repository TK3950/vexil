#include "vexmath.h"


double Vexil::VexMath::getDouble(double x, double y, double min, double max)
{
	if (max > min)
	{
		time_t t = time(NULL);
		int64_t timer = static_cast<int64_t>(t);
		int64_t clk = static_cast<int64_t>(clock());
		int64_t seed = clk + timer + timer / 3 + clk / 3 + clk / 6 + clk*clk;
		OpenSimplexNoise noise(seed); // NOTE: I hate generating new noise for every call
		// but we can't seem to make the noise static
		double val = min + max*abs(noise.Evaluate(x, y) + 0.5f);
		if (val > max)
			return max;
		else if (val < min)
			return min;
		else
			return val;

	}
	return 0;
}

bool Vexil::VexMath::sameSideOfLine(Point p1, Point p2, Point a, Point b)
{
	Vec2d ba = Vec2d(a, b);
	Vec2d p1a = Vec2d(a,p1);
	Vec2d p2a = Vec2d(a,p2);
	double cp1 = crossProduct(ba, p1a);
	double cp2 = crossProduct(ba, p2a);
	if (cp1*cp2 > 0)
	{
		return true;
	}
	return false;
}
bool Vexil::VexMath::isInsideTriangle(Point tp, Point a, Point b, Point c)
{
	if (sameSideOfLine(tp, a, c, b) &&
		sameSideOfLine(tp, b, a, c) &&
		sameSideOfLine(tp, c, a, b) )
	{
		return true;
	}
	return false;
}

double Vexil::VexMath::crossProduct(Vec2d u, Vec2d v)
{
	return (u.getX()*v.getY()) - (u.getY()*v.getX());
}

int Vexil::VexMath::getInt(double x, double y, int min, int max)
{
	if (max > min)
	{
		time_t t = time(NULL);
		int64_t timer = static_cast<int64_t>(t);
		int64_t clk = static_cast<int64_t>(clock());
		int64_t seed = clk + timer + timer / 3 + clk / 3 + clk / 6 + clk*clk;
		OpenSimplexNoise noise(seed); // NOTE: I hate generating new noise for every call
									  // but we can't seem to make the noise static
		int val = (int)round(min + max*abs(noise.Evaluate(x, y) + 0.5f));
		if (val > max)
			return max;
		else if (val < min)
			return min;
		else
			return val;

	}
	return 0;
}

double Vexil::VexMath::getRawNoise(int x, int y)
{
	time_t t = time(NULL);
	int64_t timer = static_cast<int64_t>(t);
	int64_t clk = static_cast<int64_t>(clock());
	int64_t seed = clk + timer + timer / 3 + clk / 3 + clk / 6 + clk*clk;
	OpenSimplexNoise noise(seed); // NOTE: I hate generating new noise for every call
								  // but we can't seem to make the noise static
	return noise.Evaluate(x, y);
}