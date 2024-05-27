#include "FireEvent.h"

void FireEvent::execute() {
	burnHouse();
}

int FireEvent::burnHouse() {
	if (mv_bt.size() > 0) {
		for (size_t i = 0; i < m_strength; i++) {
			int rdmn = m_randIndex();
			mv_bt.erase(mv_bt.begin() + rdmn);
			std::cout << "A building on index " << rdmn << " has been destroyed\n";
		}
	}
	return 0;
}

int FireEvent::m_randIndex() { return rand() % mv_bt.size(); }
