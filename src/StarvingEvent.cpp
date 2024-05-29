#include "StarvingEvent.h"

void StarvingEvent::execute() {
	std::cout << "Starving Event was triggered\n"; 
	//first failsave layer
	if (mv_bt.size() > 0) {
		for (size_t i = 0; i < m_strength; i++) {
			mv_bt[m_randIndex()]->moveOut(m_strength);
		}
	}
}

int StarvingEvent::m_randIndex() { return rand() % mv_bt.size(); }
