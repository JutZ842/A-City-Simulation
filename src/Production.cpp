#include <iostream>

#include "Production.h"


int Production::createGoods(float curJobs, int maxJobs) {
	return int(baseProd * (curJobs / maxJobs));
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
