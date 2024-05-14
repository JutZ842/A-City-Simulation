#include "Building.h"

void Building::moveIn(int modifier) {
    if (numPop + modifier <= maxPop) {
        numPop += modifier;
    }else {
        numPop = maxPop;
    }
}

void Building::moveOut(int modifier) {
    numPop -= modifier;
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

unsigned int Building::buildTime() {
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

Building::~Building(){}