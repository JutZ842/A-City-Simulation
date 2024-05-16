#include <iostream>

#include "Production.h"

Production::Production() { isLiving = false; }

int Production::createGoods(const float& curJobs, const int& maxJobs) {
	return int(baseProd * (curJobs / maxJobs));
}

InvManagement::products Production::getProduct() {
	return product;
}
//number between 0 and 1;modifies the good production
float Production::getBaseProd() {
	return baseProd;
}

Production::~Production() {}
