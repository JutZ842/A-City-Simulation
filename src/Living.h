#pragma once
#include "Building.h"

class Living : public Building
{
	protected:
		float sol;
		float happiness;
		float health;

	public:
		Living();

		float calcSol();
		float calcHappy();
		float calcHealth();

		float getSol();
		float getHappiness();
		float getHealth();
		~Living();
};

