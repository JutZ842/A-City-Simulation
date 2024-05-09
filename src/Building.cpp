#include "Building.h"

Building::Building() {

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