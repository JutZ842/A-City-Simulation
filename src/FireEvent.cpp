#include "FireEvent.h"

void FireEvent::execute() {
	burnHouse();
}

int FireEvent::burnHouse() {
	if (!mv_bt.empty()) {
		for (size_t i = 0; i < m_strength; i++) {
			int rdmn = m_randIndex();
			if(rdmn >= 0 && rdmn < mv_bt.size()) {
				mv_bt.erase(mv_bt.begin() + rdmn);
				std::cout << "A building on index " << rdmn << " has been destroyed\n";
			}
		}
		mv_bt.shrink_to_fit();
	}
	return 0;
}

int FireEvent::m_randIndex() { 
	if (mv_bt.size() > 0) {
		return rand() % mv_bt.size();
	}
	return 0;
}
