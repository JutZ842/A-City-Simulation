#include "Building.h"

void Building::moveIn(const int& modifier) {
    numPop + modifier <= maxPop ? numPop += modifier : numPop = maxPop;
}

void Building::moveOut(const int& modifier) {
    numPop > 0 ? numPop -= modifier : numPop = 0;
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

Building::~Building(){}