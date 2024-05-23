#pragma once
#include <vector>

#include "Events.h"
#include "Building.h"

class StarvingEvent : public Events {
    public:
        StarvingEvent(const int str, const std::vector<Building*>v_bt) : Events("StarvingEvent"), m_strength(str), mv_bt(v_bt) {}

        void execute() override;
    private:
        int m_strength;
        std::vector<Building*>mv_bt;

        int m_randIndex();

};

