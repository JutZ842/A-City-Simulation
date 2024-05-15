#pragma once
#include <map>

#include "Building.h"

class Living : public Building
{
	protected:

		float sol;
		float happiness;
		float health;

		struct Consumption {
			float baseConsum;
			InvManagement::products consumProduct;

			Consumption(const InvManagement::products& p, const float& bC) : consumProduct(p), baseConsum(bC) {}
			Consumption& getConsum(Consumption& cons) {
				return cons;
			}

		};

		std::map<InvManagement::products, int>consumption;

	public:
		Living();

		float calcSol();
		float calcHappy();
		float calcHealth();

		float getSol();
		float getHappiness();
		float getHealth();
		std::map<InvManagement::products, int> getConsumption();

		~Living();
};

