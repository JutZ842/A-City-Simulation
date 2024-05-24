#include "RefugeeEvent.h"

void RefugeeEvent::execute() {
	addToHouse(m_popChange);
}

int RefugeeEvent::addToHouse(const int& amount) {
	int remain = amount;
	int temp = 0;

	for (auto& i : mv_bt) {
		temp = i->getMaxPop() - i->getNumPop();
		if (temp > 0) {
			i->moveIn(temp);
			remain -= temp;
		}
		return 0;
	}
	std::cout << "ERROR: Something went wrong in " << m_evName << "\nRemain: " << remain << "\nTemp: " << temp << "\nEnd of ERROR message\n";
	return -1;
}