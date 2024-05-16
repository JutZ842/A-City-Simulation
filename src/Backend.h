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
		struct Save {
			int turn;

			std::vector<SmallHouse>hisShv;
			std::vector<Lumberjack>hisLjv;
			std::vector<Farm>hisFv;

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
			std::vector<SmallHouse>shv;
			std::vector<Lumberjack>ljv;
			std::vector<Farm>fv;
		} assets;

		bool et = false;
		SmallHouse sh;
		Lumberjack lj;
		Farm f;

		template <typename T>
		void build(T& bt, std::vector<T>& v);

		template<typename T>
		void remove(std::vector<T>& bt);

		template <typename T>
		int calcPeople(std::vector<T>& bt);

		template<typename T>
		void updatePopInc(std::vector<T>& bt);

		template<typename T>
		void generateGoods(std::vector<T>& g);

		template<typename T>
		int generateConsume(T& bt, const std::vector<T>& v);

		void updateGUI(Interface& gui, const int& clP, const int& cwP, const int& t);

		int updateUnemployed();

		void save();
		void undo(const int& t);
};
