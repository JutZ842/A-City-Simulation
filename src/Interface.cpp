#include <iostream>

#include "InvManagement.h"
#include "Interface.h"


Interface::Interface(const int& curLivPop, const int& curWorkPop, const int& turn) : clP(curLivPop), cwP(curWorkPop), t(turn){}

int Interface::InterfaceInit() {
	return standardScreen();
}

void Interface::updateCLP(const int& curLivPop) {
	clP = curLivPop;
}

void Interface::updateCWP(const int& curWorkPop) {
	cwP = curWorkPop;
}

void Interface::updateT(const int& turn) {
	t = turn;
}

void Interface::infoScreen() {
	std::cout << "\n\tPlease enter the number to the corresponding option\n\n";

	std::cout << "Current Turn: " << t << std::endl;
	std::cout << "Ressources\n";
	std::cout << "Wood: " << InvManagement::get().getStock(InvManagement::wood) << "\n";
	std::cout << "Wheat: " << InvManagement::get().getStock(InvManagement::wheat) << "\n";
	std::cout << "\nPops\n";
	std::cout << "You currently have " << clP << " Pops\n";
	std::cout << "You currently have " << cwP << " employed Pops\n";
	for (size_t i = 0; i < 64; i++) {
		std::cout << "-";
	}
}

int Interface::standardScreen() {
	//info page
	infoScreen();
	
	//standard page
	std::cout << "\n\n\tBuild - [1]\n";
	std::cout << "\tRemove - [2]\n";
	std::cout << "\tUpgrade - [3]\n";
	std::cout << "\tNext Turn - [E]\n";

	std::cin >> i;

	switch (tolower(i)) {
	case '1':
		return buildScreen();
		break;
	case '2':
		return removeScreen();
		break;
	case '3':
		return upgradeScreen();
		break;
	case 'e':
		return 10;
	default:
		break;
	}
}

int Interface::buildScreen() {
	//TODO Build Screen
	std::cout << "\n\n\tBuild a Small House - [1]\n";
	std::cout << "\tBuild a Lumber Jack - [2]\n";
	std::cout << "\tBuild a Farm - [3]\n";
	std::cout << "\tBuild something different - [4]\n";
	std::cout << "\tNext Page - [N]\n";
	std::cout << "\tGo Back - [B]\n";
	std::cout << "\tNext Turn - [E]\n";
	
	std::cin >> i;

	switch (tolower(i)) {
	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break;
	case '3':
		return 3;
	case '4':
		return 4;
	case 'b':
		break;
	case 'e':
		return 10;
		break;
	}
	for (size_t i = 0; i < 64; i++) {
		std::cout << "-";
	}
	return 0;
}

int Interface::upgradeScreen() {
	//TODO Upgrade Screen
	std::cin >> i;
	
	switch (i) {
	case 'b':
		standardScreen();
	default:
		break;
	}
	return 0;
}

int Interface::removeScreen() {
	//TODO Removal Screen
	std::cin >> i;

	switch (i) {
	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break;
	case 'b':
		standardScreen();
	}
	return 0;

}


