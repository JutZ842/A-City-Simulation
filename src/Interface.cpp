#include <iostream>

#include "InvManagement.h"
#include "Interface.h"


int Interface::interfaceHandler(int curLivPop, int curWorkPop, int turn) {
		
	std::cout << "\n\tPlease enter the number to the corresponding option\n\n";

	std::cout << "Current Turn: " << turn << std::endl;
	std::cout << "Ressources\n";
	std::cout << "Wood: " << InvManagement::get().getStock(InvManagement::wood) << "\n";
	std::cout << "\nPops\n";
	std::cout << "You currently have " << curLivPop << " Pops\n";
	std::cout << "You currently have " << curWorkPop << " employed Pops\n";
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
		return 1;
		break;
	case '2':
		return 2;
		break;
	case '3':
		//sh.pop_back();
		//std::cout << "You have now " << sh.size() << " SmallHouses\n";
		return 0;
		//case 'r':
			//todo fix -> userIn will always be r if this is called; new userIn required
			//removeScreen(userIn);
	case 'e':
		return 3;
		break;
	}
	for (size_t i = 0; i < 64; i++) {
		std::cout << "-";
	}
	return 0;
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


