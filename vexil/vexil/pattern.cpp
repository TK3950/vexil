#include "pattern.h"

Vexil::Pattern::Pattern()
{
	double r = VexMath::getDouble(456, 123, 0.0f, 1.0f);
	double g = VexMath::getDouble(789, 789, 0.0f, 1.0f);
	double b = VexMath::getDouble(123, 456, 0.0f, 1.0f);
	double a = 1.0f;

	color = new Color(r, g, b, a);
	type = (PatternType)VexMath::getInt(986, 23154, 0, PatternType::checkers);
	symmetry = (Symmetry)VexMath::getInt(21, 5322, 0, Symmetry::diagonalQuad);
	strength = VexMath::getDouble(352, 4112, 0.0f, 1.0f);
	firstPosition = (Position)VexMath::getInt(782, 4561, 0, Position::topLeft);
}

Vexil::Pattern::PatternType Vexil::Pattern::getType()
{
	return type;
}
Vexil::Pattern::Symmetry Vexil::Pattern::getSymmetry()
{
	return symmetry;
}
double Vexil::Pattern::getStrength()
{
	return strength;
}
Color* Vexil::Pattern::getColor()
{
	return color;
}