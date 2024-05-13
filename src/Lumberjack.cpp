#include "InvManagement.h"
#include "Lumberjack.h"

Lumberjack::Lumberjack() {	
	spaceUsed = 1;
	hp = 120;
	costs = 1;
	
	numPop = 0;
	maxPop = 10;
	baseProd = 1;

	product = InvManagement::wood;


	createGoods(getNumPop(), getMaxPop());

}
