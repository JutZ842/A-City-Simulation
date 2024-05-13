#pragma once
#include <vector>
#include <map>

#include "SmallHouse.h"
#include "Lumberjack.h"

class Interface
{
	public:
		int interfaceHandler(int livPop, int workPop);
		//void getInv(const std::map<products, float>& inv) {
		//	
		//}
	private:
		char userIn;
		void buildScreen(char userIn);
		void upgradeScreen(char userIn);
		void removeScreen(char userIn);

		std::vector<SmallHouse>sh;
		std::vector<Lumberjack>lj;

		


		//template <typename T>
		//int calcPeople(std::vector<T>sh, int curPop);

		//template<typename T>
		//int generateGoods(std::vector<Lumberjack> g);

};

