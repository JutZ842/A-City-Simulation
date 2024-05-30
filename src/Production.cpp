
#include "Production.h"

Production::Production(const int spaceUsed, int hp, int bt, int numPop, const int maxPop, const int costs, const InvManagement::products buildMat, const InvManagement::products product, std::map<InvManagement::products, int> consumption, const float baseProd) : Building(spaceUsed, hp, bt, numPop, maxPop, costs, buildMat, product, false, consumption, baseProd) {}
