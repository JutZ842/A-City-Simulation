#include "ReachedHamletLevelEvent.h"

void ReachedHamletLevelEvent::execute() {
	LevelUpEvent::execute();
}

bool ReachedHamletLevelEvent::reachedLevel() {
	return true;
}