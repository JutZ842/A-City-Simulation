#pragma once

#include <iostream>
#include <vector>

#include "Events.h"
#include "Building.h"

class FireEvent : public Events {
	public:
		FireEvent(int strength, std::vector<Building*>v_bt) : Events("FireEvent"), m_strength(strength), mv_bt(v_bt) {}

		void execute() override;
	private:
		int m_strength;
		std::vector<Building*>mv_bt;

		int burnHouse();
		int m_randIndex();
};

