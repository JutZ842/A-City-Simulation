#include "InvManagement.h"

int InvManagement::getStock(const products& product) {
	return inv[product];
}

void InvManagement::addToStock(const products& product, const int& amount) {
	inv[product] += amount;
}

//checks if stock is > 0 after calculation; if true subtraction is made else stock=0
void InvManagement::removeFromStock(const products& product, const int& amount) {
	(getStock(product) - amount) > 0 ? inv[product] -= amount : inv[product] = 0;
}
