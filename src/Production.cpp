#include "Production.h"

Production::Production()
{
}

void Production::hiring(int modifier) {
	curJobs += modifier;
}

void Production::firing(int modifier) {
	curJobs -= modifier;
}

int Production::getCurJobs() {
	return curJobs;
}

int Production::getMaxJobs() {
	return maxJobs;
}

int Production::getProduct() {
	return product;
}

float Production::getProductivity() {
	return productivity;
}

Production::~Production() {
}
