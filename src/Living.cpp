#include "Living.h"

Living::Living(){}

float Living::calcSol()
{
	return 0.0f;
}

float Living::calcHappy()
{
	//some unimportant calculations
	return ( sol + health ) / numPop;
}

float Living::calcHealth()
{
	return 0.0f;
}

float Living::getSol() {
	return sol;
}

float Living::getHappiness() {
	return happiness;
}

float Living::getHealth() {
	return health;
}

float Living::getConsum()
{
	return 0.0f;
}

Living::~Living(){}