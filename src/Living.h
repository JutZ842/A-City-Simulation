#pragma once
#include <vector>
#include <map>

#include "Building.h"

class Living : public Building
{
	protected:
		int p_sol;
		float p_happiness;
		float p_health;
		int p_devotion;

	public:
		Living(const int spaceUsed, int hp, int bt, int numPop, const int maxPop, const int costs, const InvManagement::products buildMat, std::map<InvManagement::products, int> consumption);

		float calcSol();
		float calcHappy();
		float calcHealth();

		int getSol();
		int setSol(int am);
		float getHappiness();
		float getHealth();

		int getDevotion();
		int setDevotion(int am);

		~Living();
};

