#pragma once

#include "InvManagement.h"
#include "Building.h"


class Production : public Building
{
	protected:
		float baseProd;
		InvManagement::products product;
		float createGoods(int curJobs, int maxJobs);

	public:
		Production() {}

		InvManagement::products getProduct();
		float getBaseProd();
		~Production();
};

