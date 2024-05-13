#pragma once
#include <vector>
#include <map>

#include "Interface.h"
#include "SmallHouse.h"
#include "Lumberjack.h"

class Backend
	{
	public:
		Backend();

		struct {
			std::vector<SmallHouse>sh;
			std::vector<Lumberjack>lj;
		} assets;

		struct {
			int liv;
			int work;
		} pops;

		template <typename T>
		int calcPeople(std::vector<T> sh, int curPop);
	
	private:
		bool eg = false;

		template <typename T>
		void build(std::vector<T> &bt);
		
		template<typename T>
		void remove(std::vector<T>& bt);
		
		struct {
			//todo maybe store moves in a vector to make undo possible
			int move = 0;

		} Game;

		//todo make all of that private and pass by value or reference



		/*static void test() {
			inv[wood] = 10.0f;

			for (auto& [pk, am] : inv) {
				std::cout << pk << "\n" << am << std::endl;
			}
		}*/

};
