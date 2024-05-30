#pragma once
#include <string>
#include "InvManagement.h"

class Building
{
	protected:
		int p_spaceUsed;
		int p_hp;
		int p_bt;

		int p_numPop = 0;
		int p_maxPop = 0;

		int p_costs;
		InvManagement::products p_buildMat;
		InvManagement::products p_product;

		bool p_isLiving;
		std::map<InvManagement::products, int> p_consumption;
		float p_baseProd;

	public:
		Building(const int spaceUsed, int hp, int bt, int numPop, const int maxPop, const int costs, const InvManagement::products buildMat, const InvManagement::products product, const bool& isLiving, std::map<InvManagement::products, int> consumption, const float baseProd);

		virtual void moveIn(const int& modifier);
		virtual void moveOut(const int& modifier);

		virtual int getNumPop();
		virtual int getMaxPop();

		virtual int getHp();
		virtual void changeHp(int amount);
		
		virtual int getBuildTime();
		virtual int getSpaceUsed();
		virtual int getCosts();

		virtual InvManagement::products getBuildMat();
		virtual bool getIsLiving();
		virtual std::map<InvManagement::products, int> getConsumption();
		virtual InvManagement::products getProduct();
		virtual int createGoods(const float& curJobs, const int& maxJobs);
		virtual float getBaseProd();
		


		~Building();

};

