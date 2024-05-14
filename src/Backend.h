#pragma once
#include <vector>
#include <map>

#include "Interface.h"
#include "InvManagement.h"

#include "SmallHouse.h"
#include "Lumberjack.h"

class Backend
	{
	public:
		Backend();


	
	private:		
		struct Save {

		};

		struct {
			//todo maybe store moves in a vector to make undo possible
			int move = 0;
			std::vector<Save>history;

		} game;

		struct {
			int liv;
			int work;
			int unemployed;
		} pops;

		struct {
			std::vector<SmallHouse>sh;
			std::vector<Lumberjack>lj;
		} assets;

		bool et = false;
		Interface gui;
		SmallHouse sh;
		Lumberjack lj;

		template <typename T>
		void build(T &bt, std::vector<T> &v);

		template<typename T>
		void remove(std::vector<T>& bt);

		template <typename T>
		int calcPeople(const std::vector<T> sh, int curPop);

		template<typename T>
		void updatePopInc(std::vector<T>& bt);

		template<typename T>
		void generateGoods(std::vector<T>& g);

		void generateConsume(SmallHouse& bt);
};
