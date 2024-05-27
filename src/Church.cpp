#include "Church.h"

Church::Church() {
	consumption[InvManagement::wheat] = 1;

	spaceUsed = 2;
	hp = 100;
	bt = 2; //2 turns
	costs = 10;
	buildMat = InvManagement::wood;

	numPop = 0;
	maxPop = 100;
}