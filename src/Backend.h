#pragma once
#include <vector>
#include <map>

#include "Interface.h"
#include "InvManagement.h"

#include "SmallHouse.h"
#include "Lumberjack.h"
#include "Farm.h"

class Backend {
	public:
		Backend();

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
			std::vector<Building*>shv;
			std::vector<Building*>ljv;
			std::vector<Building*>fv;
		} assets;

		bool et = false;
		SmallHouse sh;
		Lumberjack lj;
		Farm f;

		//template <typename T>
		void build(Building* bt, std::vector<Building*>* v_bt);

		void buildFactory();

		//template<typename T>
		int addToBQueue(Building* bt, std::vector<Building*>& v_bt, int turns);

		template<typename T>
		void remove(std::vector<T>& bt);

		int calcPeople(std::vector<Building*>& bt);

		void updatePopInc(std::vector<Building*>& bt);

		template<typename T>
		void updatePopDec(std::vector<T>& bt);


		void generateGoods(std::vector<Building*>& g);

		int generateConsume(const std::vector<Building*>& v);

		void updateGUI(Interface& gui, const int& clP, const int& cwP, const int& t);

		int updateUnemployed();

		void updatePops();

		void save();
		void undo(const int& t);
};
