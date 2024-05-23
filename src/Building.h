#pragma once
#include <string>
#include "InvManagement.h"

class Building
{
	protected:
		unsigned int spaceUsed;
		unsigned int hp;
		unsigned int bt;
		unsigned int buildingCount;

		unsigned int numPop = 0;
		unsigned int maxPop = 0;

		unsigned int costs;
		InvManagement::products buildMat;
		InvManagement::products product;

		bool isLiving;
		std::map<InvManagement::products, int> consumption;
		float baseProd;

	public:
		Building() {}

		void moveIn(const int& modifier);
		void moveOut(const int& modifier);

		unsigned int getNumPop();
		unsigned int getMaxPop();

		unsigned int getHp();
		unsigned int getBuildTime();
		unsigned int getCount();
		unsigned int getSpaceUsed();

		unsigned int getCosts();
		InvManagement::products getBuildMat();
		bool getIsLiving();
		std::map<InvManagement::products, int> getConsumption();
		InvManagement::products getProduct();
		int createGoods(const float& curJobs, const int& maxJobs);
		float getBaseProd();
		


		~Building();

};

