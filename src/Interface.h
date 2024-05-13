#pragma once
#include <vector>
#include <map>

#include "SmallHouse.h"
#include "Lumberjack.h"

class Interface
{
	public:
		//todo in theory if this is the only function that gets called through the backend this could be the constructor
		int interfaceHandler(int livPop, int workPop, int turn);
		//void getInv(const std::map<products, float>& inv) {
		//	
		//}
	private:
		char userIn;
		void buildScreen(const char userIn);
		void upgradeScreen(const char userIn);
		void removeScreen(const char userIn);

		std::vector<SmallHouse>sh;
		std::vector<Lumberjack>lj;

		


		//template <typename T>
		//int calcPeople(std::vector<T>sh, int curPop);

		//template<typename T>
		//int generateGoods(std::vector<Lumberjack> g);

};

