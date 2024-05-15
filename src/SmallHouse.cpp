#include "SmallHouse.h"

SmallHouse::SmallHouse() {
	
	consumption[InvManagement::wheat] = 1;
	consumption[InvManagement::wood] = 0;

	spaceUsed = 1;
	hp = 100;
	bt = 2; //2 turns
	costs = 1;
	buildMat = InvManagement::wood;

	numPop = 0;
	maxPop = 10;
	sol = 0.0f;
	happiness = 0.0f;
	health = 0.0f;
}



