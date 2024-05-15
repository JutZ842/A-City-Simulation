#pragma once
#include <map>

#include "Building.h"

class Living : public Building
{
	protected:

		float sol;
		float happiness;
		float health;

		std::map<InvManagement::products, int> consumption;

	public:
		std::map<InvManagement::products, int> getConsumption();

		Living();

		float calcSol();
		float calcHappy();
		float calcHealth();

		float getSol();
		float getHappiness();
		float getHealth();

		~Living();
};

