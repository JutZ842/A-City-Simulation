#include "SmallHouse.h"

SmallHouse::SmallHouse() {
		
	Consum consum1;
	
	consum1.baseConsum = .1f;
	consum1.consumProduct = InvManagement::wheat;
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
