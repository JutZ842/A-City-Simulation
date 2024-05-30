#include "Church.h"
//const int& spaceUsed, int& hp, int& bt, int& numPop, const int& maxPop, const int& costs, const InvManagement::products& buildMat, const InvManagement::products& product, const bool& isLiving, std::map<InvManagement::products, int>& consumption, const float& baseProd
Church::Church() : Building(4, 200, 8, 0, 100, 10, InvManagement::wood, InvManagement::none, false, { {InvManagement::none, 0} }, 0) {}
