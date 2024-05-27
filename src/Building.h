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

		virtual void moveIn(const int& modifier);
		virtual void moveOut(const int& modifier);

		virtual unsigned int getNumPop();
		virtual unsigned int getMaxPop();

		virtual unsigned int getHp();
		virtual void changeHp(int amount);
		virtual unsigned int getBuildTime();
		virtual unsigned int getCount();
		virtual unsigned int getSpaceUsed();

		virtual unsigned int getCosts();
		virtual InvManagement::products getBuildMat();
		virtual bool getIsLiving();
		virtual std::map<InvManagement::products, int> getConsumption();
		virtual InvManagement::products getProduct();
		virtual int createGoods(const float& curJobs, const int& maxJobs);
		virtual float getBaseProd();
		


		~Building();

};

