#include "Interface.h"

/*Public Functions*/
Interface::Interface(const int& curLivPop, const int& curWorkPop, const int& turn, const int& devotion, const int& score, const int& level) : m_clP(curLivPop), m_cwP(curWorkPop), m_t(turn), m_dev(devotion), m_score(score), m_level(level) {
	welcomeScreen();
}

int Interface::InterfaceInit() {
	return standardScreen();
}

void Interface::updateCLP(const int& curLivPop) {
	m_clP = curLivPop;
}

void Interface::updateCWP(const int& curWorkPop) {
	m_cwP = curWorkPop;
}

void Interface::updateT(const int& turn) {
	m_t = turn;
}

void Interface::updateDev(const int& devotion) {
	m_dev = devotion;
}

void Interface::updateScore(const int& score) {
	m_score = score;
}

void Interface::updateCityLevel(const int& level) {
	m_level = level;
}

int Interface::getGamemode() {
	return m_gm;
}

void Interface::victoryScreen() {
	std::cout << "Congratulations, you reached your goal in " << m_t << " Turns. Thats very fast!\nHere a cookie\n";
}

/*Private Functions*/
void Interface::infoScreen() {
	std::cout << "Score: " << m_score << std::endl;
	std::cout << "Current Turn: " << m_t << std::endl;
	for (size_t i = 0; i < m_t; i++) {
		std::cout << "-";
	}
	std::cout << "\nRessources\n";
	std::cout << "Wood: " << InvManagement::get().getStock(InvManagement::wood) << "\n";
	std::cout << "Wheat: " << InvManagement::get().getStock(InvManagement::wheat) << "\n";
	std::cout << "\nPops\n";
	std::cout << "You currently have " << m_clP << " Pops\n";
	std::cout << "You currently have " << m_cwP << " employed Pops\n";
	std::cout << "The Devotion of your Pops is:  " << m_dev << "%\n";
	for (size_t i = 0; i < 64; i++) {
		std::cout << "-";
	}
}

void Interface::welcomeScreen() {
	std::cout << "Welcome to ACiSi!\n";
	//for (size_t i = 0; i < 64; i++) {
	//	std::cout << "-";
	//}
	std::cout << "\nPlease choose a Gamemode:\n";
	std::cout << "\tFreeplay: [1]\n";
	std::cout << "\tScoreplay: [2]\n";
	std::cout << "\tReach City: [3]\n";

	std::cin >> m_i;
	
	switch (m_i) {
	case '1':
		m_gm = fp;
		break;
	case '2':
		m_gm = sp;
		break;
	case '3':
		m_gm = rc;
		break;
	default:
		welcomeScreen();
		break;
	}
}

int Interface::standardScreen() {
	//info page
	infoScreen();
	
	//standard page
	std::cout << "\n\tPlease enter the number to the corresponding option\n";

	std::cout << "\n\tBuild - [1]\n";
	std::cout << "\tRemove - [2]\n";
	std::cout << "\tUpgrade - [3]\n";
	std::cout << "\tNext Turn - [E]\n";

	std::cin >> m_i;

	switch (tolower(m_i)) {
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
	std::cout << "\n\tPlease enter the number to the corresponding option\n\n";


	std::cout << "\tBuild a Small House - [1]\n";
	std::cout << "\tBuild a Lumber Jack - [2]\n";
	std::cout << "\tBuild a Farm - [3]\n";
	std::cout << "\tBuild a Church - [4]\n";
	if (m_level > 1) {
		std::cout << "\tBuild a Medium House - [5]\n";
	}
	
	std::cout << "\tNext Page - [N]\n";
	std::cout << "\tGo Back - [B]\n";
	std::cout << "\tNext Turn - [E]\n";
	
	std::cin >> m_i;

	switch (tolower(m_i)) {
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
	case '5':
		return 5;
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
	std::cin >> m_i;
	
	switch (m_i) {
	case 'b':
		standardScreen();
	default:
		break;
	}
	return 0;
}

int Interface::removeScreen() {
	//TODO Removal Screen
	std::cout << "\n\tPlease enter the number to the corresponding option\n\n";


	std::cout << "\tRemove a Small House - [1]\n";
	std::cout << "\tRemove a Lumber Jack - [2]\n";
	std::cout << "\tRemove a Farm - [3]\n";
	std::cout << "\tRemove a Church - [4]\n";
	if (m_level > 1) {
		std::cout << "\tRemove a Medium House - [5]\n";
	}

	std::cout << "\tNext Page - [N]\n";
	std::cout << "\tGo Back - [B]\n";
	std::cout << "\tNext Turn - [E]\n";

	std::cin >> m_i;

	switch (m_i) {
	case '1':
		return -1;
		break;
	case '2':
		return -2;
		break;
	case '3':
		return -3;
	case '4':
		return -4;
	case '5':
		return -5;
	case 'b':
		standardScreen();
	case 'e':
		return 10;
		break;
	}

	return 0;
}
