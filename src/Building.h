#pragma once
#include <string>

class Building
{
	protected:
		unsigned int spaceUsed;
		unsigned int hp;
		unsigned int costs;
		unsigned int buildingCount;

		unsigned int numPop;
		unsigned int maxPop;

		std::string type;

	public:
		Building();

		void moveIn(int modifier);
		void moveOut(int modifier);

		unsigned int getNumPop();
		unsigned int getMaxPop();

		unsigned int getHp();
		unsigned int getCost();
		unsigned int getCount();
		unsigned int getSpaceUsed();
		~Building();

};

