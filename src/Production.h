#pragma once
#include "Building.h"
#include "UnorderedHeader.h"
class Production : public Building
{
	protected:
		unsigned int curJobs;
		unsigned int maxJobs;
		products product;
		float productivity;
	public:
		Production();
		void hiring(int modifier);
		void firing(int modifier);

		int getCurJobs();
		int getMaxJobs();
		int getProduct();
		float getProductivity();
		~Production();
};

