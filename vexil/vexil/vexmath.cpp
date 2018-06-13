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


bool Vexil::VexMath::getBool(int x, int y)
{
	time_t t = time(NULL);
	int64_t timer = static_cast<int64_t>(t);
	int64_t clk = static_cast<int64_t>(clock());
	int64_t seed = clk + timer + timer / 3 + clk / 3 + clk / 6 + clk*clk;
	OpenSimplexNoise noise(seed);

	return (noise.Evaluate(x, y) > 0);


}

bool Vexil::VexMath::sameSideOfLine(Point testPoint, Point reference, Point a, Point b)
{
	Vec2d ba = Vec2d(b, a);
	Vec2d testVector = Vec2d(testPoint, a);
	Vec2d referenceVector = Vec2d(reference,a);
	double cp1 = crossProduct(ba, testVector);
	double cp2 = crossProduct(ba, referenceVector);
	if (cp1*cp2 > 0)
	{
		return true;
	}
	return false;
}
bool Vexil::VexMath::isInsideTriangle(Point testPoint, Point a, Point b, Point c)
{
#ifndef BARYCENTRIC
	if (sameSideOfLine(testPoint, a, b, c) &&
		sameSideOfLine(testPoint, b, a, c) &&
		sameSideOfLine(testPoint, c, a, b) )
	{
		return true;
	}
	return false;
#endif
#ifdef BARYCENTRIC
	Vec2d v0 = Vec2d(c,a);
	Vec2d v1 = Vec2d(b, a);
	Vec2d v2 = Vec2d(testPoint, a);

	double dot00 = dotProduct(v0, v0);
	double dot01 = dotProduct(v0, v1);
	double dot02 = dotProduct(v0, v2);
	double dot11 = dotProduct(v1, v1);
	double dot12 = dotProduct(v1, v2);

	double invDenom = 1 / (dot00 * dot11 - dot01 * dot01);
	double u = (dot11 * dot02 - dot01 * dot12) * invDenom;
	double v = (dot00 * dot12 - dot01 * dot02) * invDenom;

	return ((u >= 0) && (v >= 0) && (u + v < 1));
#endif
}

double Vexil::VexMath::crossProduct(Vec2d u, Vec2d v)
{
	return (u.getX()*v.getY()) - (u.getY()*v.getX());
}

double Vexil::VexMath::dotProduct(Vec2d u, Vec2d v)
{
	return (u.getMagnitude()*v.getMagnitude()*cos(angle(u, v)));
}

double Vexil::VexMath::angle(Vec2d u, Vec2d v)
{
	return atan2(u.getY(), u.getX())- atan2(v.getY(), v.getX());
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