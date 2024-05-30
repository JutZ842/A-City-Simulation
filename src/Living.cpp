#include "Living.h"

Living::Living(const int spaceUsed, int hp, int bt, int numPop, const int maxPop, const int costs, const InvManagement::products buildMat, std::map<InvManagement::products, int> consumption) : Building(spaceUsed, hp, bt, numPop, maxPop, costs, buildMat, InvManagement::none, true, consumption, 0) {}

float Living::calcSol() {
	return 0.0f;
}

float Living::calcHappy() {
	//some unimportant calculations
	return ( p_sol + p_health ) / p_numPop;
}

float Living::calcHealth() {
	return 0.0f;
}

int Living::getSol() {
	return p_sol;
}

int Living::setSol(int am) {
	return p_sol += am;
}

float Living::getHappiness() {
	return p_happiness;
}

float Living::getHealth() {
	return p_health;
}

int Living::getDevotion() {
	return p_devotion;
}

int Living::setDevotion(int am) {
	if (p_devotion + am >= p_numPop) {
		return p_devotion = p_numPop;
	}
	return p_devotion += am;
}

Living::~Living(){}