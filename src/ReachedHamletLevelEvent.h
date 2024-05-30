#pragma once
#include "LevelUpEvent.h"
class ReachedHamletLevelEvent : public LevelUpEvent {

	public:
		static ReachedHamletLevelEvent& get() {
			static ReachedHamletLevelEvent instance;
			return instance;
		}

		void execute() override;
		bool reachedLevel() override;
	private:
		ReachedHamletLevelEvent() : LevelUpEvent("Hamlet") {}
		ReachedHamletLevelEvent(const ReachedHamletLevelEvent&) = delete;
		void operator=(const ReachedHamletLevelEvent&) = delete;
};

