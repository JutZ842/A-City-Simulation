#include "ReachedVillageLevelEvent.h"

void ReachedVillageLevelEvent::execute() {
	LevelUpEvent::execute();
}

bool ReachedVillageLevelEvent::reachedLevel() {
	return true;
}