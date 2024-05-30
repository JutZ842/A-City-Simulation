#include "Building.h"

Building::Building(const int spaceUsed, int hp, int bt, int numPop, const int maxPop, const int costs, const InvManagement::products buildMat, const InvManagement::products product, const bool& isLiving, std::map<InvManagement::products, int> consumption, const float baseProd) : p_spaceUsed(spaceUsed), p_hp(hp), p_bt(bt), p_numPop(numPop), p_maxPop(maxPop), p_costs(costs), p_buildMat(buildMat), p_product(product), p_isLiving(isLiving), p_consumption(consumption), p_baseProd(baseProd) {}

void Building::moveIn(const int& modifier) {
    p_numPop + modifier <= p_maxPop ? p_numPop += modifier : p_numPop = p_maxPop;
}

void Building::moveOut(const int& modifier) {
    p_numPop - modifier > 0 ? p_numPop -= modifier : p_numPop = 0;
}

int Building::getNumPop() {
    return p_numPop;
}

int Building::getMaxPop() {
    return p_maxPop;
}

int Building::getHp() {
    return p_hp;
}

void Building::changeHp(int amount) {
    p_hp += amount;
}

int Building::getBuildTime() {
    return p_bt;
}

int Building::getSpaceUsed(){
    return p_spaceUsed;
}

int Building::getCosts() {
    return p_costs;
}
InvManagement::products Building::getBuildMat() {
    return p_buildMat;
}

bool Building::getIsLiving() {
    return p_isLiving;
}

std::map<InvManagement::products, int> Building::getConsumption() {
    return p_consumption;
}

int Building::createGoods(const float& curJobs, const int& maxJobs) {
    return int(p_baseProd * (curJobs / maxJobs));
}

InvManagement::products Building::getProduct() {
    return p_product;
}
//number between 0 and 1;modifies the good production
float Building::getBaseProd() {
    return p_baseProd;
}

Building::~Building(){}