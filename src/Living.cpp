#include "Living.h"

Living::Living(){}

void Living::moveIn() {
}

void Living::moveOut() {
}

unsigned int Living::getNumPop() {
	return numPop;
}

unsigned int Living::getMaxPop() {
	return maxPop;
}

float Living::getSol() {
	return sol;
}

float Living::getHappiness()
{
	return happiness;
}

float Living::getHealth()
{
	return health;
}

Living::~Living(){}