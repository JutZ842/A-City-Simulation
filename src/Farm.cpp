#include "Farm.h"

Farm::Farm() {
	spaceUsed = 2;
	hp = 100;
	bt = 2;

	numPop = 0;
	maxPop = 10;

	costs = 2;
	buildMat = InvManagement::wood;

	baseProd = 4;
	product = InvManagement::wheat;
}
