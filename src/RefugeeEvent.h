#pragma once
#include <vector>
#include <iostream>

#include "Events.h"
#include "Building.h"

class RefugeeEvent : public Events {
	public:
		RefugeeEvent(int popChange, std::vector<Building*>v_bt) : Events("RefugeeEvent"), m_popChange(popChange), mv_bt(v_bt) {}

		void execute() override;
	private:
		int m_popChange;
		std::vector<Building*>mv_bt;

		int addToHouse(const int& amount);
};
