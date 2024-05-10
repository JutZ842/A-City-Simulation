#include "Production.h"


Production::Production()
{
}

float Production::createGoods(int curJobs, int maxJobs) {
	return baseProd * (curJobs / maxJobs);
}

int Production::getProduct() {
	return product;
}
//number between 0 and 1;modifies the good production
float Production::getBaseProd() {
	return baseProd;
}

Production::~Production() {
}
