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