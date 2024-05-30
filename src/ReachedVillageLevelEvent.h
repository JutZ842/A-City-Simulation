#pragma once
#include "LevelUpEvent.h"
class ReachedVillageLevelEvent : public LevelUpEvent {
	public:
		static ReachedVillageLevelEvent& get() {
			static ReachedVillageLevelEvent instance;
			return instance;
		}

		ReachedVillageLevelEvent(const ReachedVillageLevelEvent&) = delete;
		void operator = (const ReachedVillageLevelEvent&) = delete;

		void execute() override;
		bool reachedLevel() override;
	private:
		ReachedVillageLevelEvent() : LevelUpEvent("Village") {}
};

