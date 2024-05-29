#include "Building.h"

void Building::moveIn(const int& modifier) {
    numPop + modifier <= maxPop ? numPop += modifier : numPop = maxPop;
}

void Building::moveOut(const int& modifier) {
    numPop - modifier > 0 ? numPop -= modifier : numPop = 0;
}

unsigned int Building::getNumPop() {
    return numPop;
}

unsigned int Building::getMaxPop() {
    return maxPop;
}

unsigned int Building::getHp() {
    return hp;
}

void Building::changeHp(int amount) {
    hp += amount;
}

unsigned int Building::getBuildTime() {
    return bt;
}

unsigned int Building::getCount(){
    return buildingCount;
}

unsigned int Building::getSpaceUsed(){
    return spaceUsed;
}

unsigned int Building::getCosts() {
    return costs;
}
InvManagement::products Building::getBuildMat() {
    return buildMat;
}

bool Building::getIsLiving() {
    return isLiving;
}

std::map<InvManagement::products, int> Building::getConsumption() {
    return consumption;
}

int Building::createGoods(const float& curJobs, const int& maxJobs) {
    return int(baseProd * (curJobs / maxJobs));
}

InvManagement::products Building::getProduct() {
    return product;
}
//number between 0 and 1;modifies the good production
float Building::getBaseProd() {
    return baseProd;
}

Building::~Building(){}