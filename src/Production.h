#pragma once
#include "Building.h"
#include "Ressources.h"

class Production : public Building
{
	protected:
		float baseProd;

		products product;

		float createGoods(int curJobs, int maxJobs);

	public:
		Production();

		int getProduct();
		float getBaseProd();
		~Production();
};

