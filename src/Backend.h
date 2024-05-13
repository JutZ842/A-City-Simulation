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

		template <typename T>
		int calcPeople(std::vector<T> sh, int curPop);
	
	private:		
		struct Save {

		};

		struct {
			//todo maybe store moves in a vector to make undo possible
			int move = 0;
			std::vector<Save>history;

		} Game;

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

		template <typename T>
		void build(std::vector<T>& bt);

		template<typename T>
		void remove(std::vector<T>& bt);

		template<typename T>
		void updatePopInc(std::vector<T>& bt);

		template<typename T>
		void generateGoods(std::vector<T>& g);

		//todo make all of that private and pass by value or reference



		/*static void test() {
			inv[wood] = 10.0f;

			for (auto& [pk, am] : inv) {
				std::cout << pk << "\n" << am << std::endl;
			}
		}*/

};
