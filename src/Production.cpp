#include <iostream>

#include "Production.h"

float Production::createGoods(int curJobs, int maxJobs) {
	return baseProd * (curJobs / maxJobs);
}

InvManagement::products Production::getProduct() {
	return product;
}
//number between 0 and 1;modifies the good production
float Production::getBaseProd() {
	return baseProd;
}

Production::~Production() {
}
