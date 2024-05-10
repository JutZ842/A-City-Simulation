#pragma once
#include <vector>
#include "SmallHouse.h"
#include "Lumberjack.h"

class Interface
{
	public:
		Interface() {
			InterfaceHandler();
		}
		std::vector<SmallHouse>sh;
		std::vector<Lumberjack>lj;

	private:
		char userIn;
		void buildScreen(char userIn);
		void upgradeScreen(char userIn);
		void removeScreen(char userIn);

		template <typename T>
		int calcPeople(std::vector<T>sh);

		void InterfaceHandler();
};

