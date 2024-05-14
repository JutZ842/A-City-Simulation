#pragma once
#include "Building.h"

class Living : public Building
{
	protected:
		struct Consum {
			float baseConsum;
			InvManagement::products consumProduct;
		};

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
		float getConsum();

		~Living();
};

