#pragma once
#include <iostream>

#include "InvManagement.h"
#include "Building.h"


class Production : public Building {
	protected:	
	public:
		Production(const int spaceUsed, int hp, int bt, int numPop, const int maxPop, const int costs, const InvManagement::products buildMat, const InvManagement::products product, std::map<InvManagement::products, int> consumption, const float baseProd);
};
