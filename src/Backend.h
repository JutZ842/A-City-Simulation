#pragma once
#include <stdlib.h>

#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <functional>
#include <limits>

#include "Interface.h"
#include "InvManagement.h"

#include "SmallHouse.h"
#include "MediumHouse.h"
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
		struct BuildQueue {
			Building* type;
			std::vector<Building*>* v_type;

			int time;

			void decTurn() { time--; }

			BuildQueue(Building* tp, std::vector<Building*>* tv, int t) : type(tp), v_type(tv), time(t) {}
		};

		struct Save {
			int turn;

			/*Building to live*/
			std::vector<Building*>v_hisLiv;
			/*Building to work*/
			std::vector<Building*>v_hisWork;
			/*Special Building*/
			std::vector<Building*>v_hisSpec;

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
			MediumHouse mh;

			/*Building to live*/
			std::vector<Building*>v_liv;
			/*Building to work*/
			std::vector<Building*>v_work;
			/*Special Building*/
			std::vector<Building*>v_spec;

		} assets;

		bool et = false;
		int m_starvCount = 0;
		int m_cityLevel = 1;
		int m_gm;
		int m_curScore = 0;

		void gameLoop(Interface& gui);

		std::vector<BuildQueue>bQueue;
		std::function<bool(int)> gamemode;

		int addToBQueue(Building* bt, std::vector<Building*>& v_bt, int turns);
		void buildFactory();
		void build(Building* bt, std::vector<Building*>* v_bt);
		void remove(Building* bt, std::vector<Building*>& v_bt);
		
		int calcPeople(std::vector<Building*>& bt);
		void updateLivPopInc(std::vector<Building*>& btv);
		void updateWorkPopInc(std::vector<Building*>& btv);
		void updatePopDec(std::vector<Building*>& bt, int amount);

		int generateConsume(const std::vector<Building*>& v);
		void generateGoods(std::vector<Building*>& g);

		int calcDevotion(const std::vector<Building*>& v_bt);
		void updateDevotion(std::vector<Building*>& v_house, std::vector<Building*>& v_church);
		void updateSol(std::vector<Building*> v_bt);
		
		int calcScore();

		int updateUnemployed();
		void updateGUI(Interface& gui, const int& clP, const int& cwP, const int& t, const float& dev, const int& score, const int& level);
		void updatePops();

		void save();
		void undo(const int& t);

		void setEndCondition();
		
};
