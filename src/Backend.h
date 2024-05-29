#pragma once
#include <stdlib.h>

#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

#include "Interface.h"
#include "InvManagement.h"

#include "SmallHouse.h"
#include "Lumberjack.h"
#include "Farm.h"
#include "Church.h"

#include "StarvingEvent.h"
#include "FireEvent.h"

class Backend {
	public:
		Backend();
		~Backend();

	private:

		//template<typename T>
		struct BuildQueue {
			Building* type;
			std::vector<Building*>* v_type;

			int time;

			void decTurn() { time--; }

			BuildQueue(Building* tp, std::vector<Building*>* tv, int t) : type(tp), v_type(tv), time(t) {}
		};

		std::vector<BuildQueue>bQueue;

		struct Save {
			int turn;

			std::vector<Building*>hisShv;
			std::vector<Building*>hisLjv;
			std::vector<Building*>hisFv;

			int liv;
			int work;
			int unemployed;

			int wood;
			int wheat;
		};

		struct {
			//todo maybe store moves in a vector to make undo possible
			int turn = 0;
			std::vector<Save>history;

		} game;

		struct {
			int liv = 0;
			int work = 0;
			int unemployed = 0;
		} pops;

		//todo maybe a template class or something that makes adding assests easier
		struct {
			SmallHouse sh;
			Lumberjack lj;
			Farm f;
			Church c;

			std::vector<Building*>shv;
			std::vector<Building*>ljv;
			std::vector<Building*>fv;
			std::vector<Building*>cv;
		} assets;

		bool et = false;
		int m_starvCount = 0;



		void build(Building* bt, std::vector<Building*>* v_bt);

		void buildFactory();

		int addToBQueue(Building* bt, std::vector<Building*>& v_bt, int turns);

		void remove(std::vector<Building*>& bt);

		void updateLivPopInc(std::vector<Building*>& btv);

		int calcPeople(std::vector<Building*>& bt);

		void updatePopInc(std::vector<Building*>& bt);

		void updateWorkPopInc(std::vector<Building*>& btv);

		void updatePopDec(std::vector<Building*>& bt, int amount);

		void generateGoods(std::vector<Building*>& g);

		void updateDevotion(std::vector<Building*>& v_house, std::vector<Building*>& v_church);

		float calcDevotion(const std::vector<Building*>& v_bt);

		void updateSol(std::vector<Building*> v_bt);

		int generateConsume(const std::vector<Building*>& v);

		void updateGUI(Interface& gui, const int& clP, const int& cwP, const int& t, const float& dev);

		int updateUnemployed();

		void updatePops();

		void save();
		void undo(const int& t);
};
