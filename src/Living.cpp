#include "Living.h"

Living::Living() { isLiving = true; }

float Living::calcSol() {
	return 0.0f;
}

float Living::calcHappy() {
	//some unimportant calculations
	return ( sol + health ) / numPop;
}

float Living::calcHealth() {
	return 0.0f;
}

int Living::getSol() {
	return sol;
}

int Living::setSol(int am) {
	return sol += am;
}

float Living::getHappiness() {
	return happiness;
}

float Living::getHealth() {
	return health;
}

int Living::getDevotion() {
	return devotion;
}

int Living::setDevotion(int am) {
	if (devotion + am >= numPop) {
		return devotion = numPop;
	}
	return devotion += am;
}

Living::~Living(){}