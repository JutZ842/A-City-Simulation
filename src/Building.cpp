#include "Building.h"

Building::Building() {

}

void Building::moveIn(int modifier) {
    numPop += modifier;
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

unsigned int Building::getCost() {
    return costs;
}

unsigned int Building::getCount(){
    return buildingCount;
}

unsigned int Building::getSpaceUsed(){
    return spaceUsed;
}

Building::~Building(){}