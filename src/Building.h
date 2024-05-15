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

		unsigned int numPop;
		unsigned int maxPop;

		unsigned int costs;
		InvManagement::products buildMat;

		std::string type;

	public:
		Building() {}

		void moveIn(const int& modifier);
		void moveOut(const int& modifier);

		unsigned int getNumPop();
		unsigned int getMaxPop();

		unsigned int getHp();
		unsigned int buildTime();
		unsigned int getCount();
		unsigned int getSpaceUsed();

		unsigned int getCosts();
		InvManagement::products getBuildMat();
		~Building();

};

