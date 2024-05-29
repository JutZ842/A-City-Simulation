#pragma once
#include <vector>
#include <map>

#include "Building.h"

class Living : public Building
{
	protected:

		int sol;
		float happiness;
		float health;
		int devotion;


	public:
		Living();

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

