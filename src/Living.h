#pragma once
#include "Building.h"

class Living : protected Building
{
	protected:
		unsigned int numPop;
		unsigned int maxPop;
		float sol;
		float happiness;
		float health;

	public:
		Living();
		void moveIn();
		void moveOut();

		unsigned int getNumPop();
		unsigned int getMaxPop();
		float getSol();
		float getHappiness();
		float getHealth();
		~Living();
};

