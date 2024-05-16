#pragma once

#include "InvManagement.h"
#include "Building.h"


class Production : public Building
{
	protected:
		float baseProd;
		InvManagement::products product;

	public:
		Production();

		InvManagement::products getProduct();
		int createGoods(const float& curJobs, const int& maxJobs);
		float getBaseProd();
		~Production();
};

