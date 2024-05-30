#pragma once
#include <string>
#include <iostream>
#include "Events.h"
class LevelUpEvent : public Events {
	public:
		LevelUpEvent(const std::string levelName) : Events("LevelUpEvent"), p_levelName(levelName) {}
		void execute() override;
		virtual bool reachedLevel() = 0;
	protected:
		std::string p_levelName;
};

