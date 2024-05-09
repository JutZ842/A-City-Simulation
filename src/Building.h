#pragma once
class Building
{
	protected:
		unsigned int spaceUsed;
		unsigned int hp;
		unsigned int costs;
		unsigned int buildingCount;

	public:
		Building();
		~Building();
		unsigned int getHp();
		unsigned int getCost();
		unsigned int getCount();
		unsigned int getSpaceUsed();
};

