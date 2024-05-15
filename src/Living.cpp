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

std::map<InvManagement::products, int> Living::getConsumption() {
	return consumption;
}

Living::~Living(){}