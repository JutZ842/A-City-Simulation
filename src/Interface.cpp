#include "Interface.h"
#include "Ressources.h"
#include <iostream>

void Interface::InterfaceHandler() {
	bool stop = false;

	while (stop == false) {
		std::cout << "\n\tPlease enter the number to the corresponding option\n\n";

		std::cout << "Ressources\n";
		std::cout << "Wood: " << inv[wood] << "\n";
		std::cout << "Pops\n";
		std::cout << "You currently have " << calcPeople(sh) << " Pops\n";
		for (size_t i = 0; i < 64; i++) {
			std::cout << "-";
		}
		//page 1
		std::cout << "\n\n\tBuild a Small House - [1]\n";
		std::cout << "\tBuild a Lumber Jack - [2]\n";
		std::cout << "\tBuild something different - [3]\n";
		std::cout << "\tNext Page - [N]\n";
		std::cout << "\tBuilding Removal Page - [R]\n";
		std::cout << "\tNext Turn - [E]\n";

		std::cin >> userIn;
		
		
		switch (tolower(userIn)) {
		case '1':
			sh.push_back(SmallHouse());
			std::cout << "You have now " << sh.size() << " SmallHouses\n";
			break;
		case '2':
			lj.push_back(Lumberjack());
			std::cout << "You have now " << lj.size() << " Lumberjacks\n";
			break;
		case '3':
			sh.pop_back();
			std::cout << "You have now " << sh.size() << " SmallHouses\n";
			break;
			//case 'r' | 'R':
				//todo fix -> userIn will always be r or R if this is called; new userIn required
				//removeScreen(userIn);
		case 'e':
			stop = true;
			break;
		}
		for (size_t i = 0; i < 64; i++) {
			std::cout << "-";
		}
	}

}

void Interface::buildScreen(char userIn) {
	//TODO Build Screen
}

void Interface::upgradeScreen(char userIn) {
	//TODO Upgrade Screen
}

void Interface::removeScreen(char userIn) {
	//TODO Removal Screen
	switch (userIn)
	{
	case 1:
		sh.pop_back();
		std::cout << "You have now " << sh.size() << " SmallHouses\n";
	case 2:
		lj.pop_back();
		std::cout << "You have now " << lj.size() << " SmallHouses\n";
	}
}

int Interface::calcPeople(std::vector<SmallHouse>sh) {
	int curPop = 0;
	for (auto& i : sh) {
		curPop += i.getNumPop();
	}return curPop;
}
