#include <iostream>
#include "SmallHouse.h"
#include <vector>

void importantDestructor(std::vector<SmallHouse*>& sh);

void construct() {
	char i;
	std::vector<SmallHouse*>sh;
	int bla = 100;
	bool stop = false;

	while (!stop) {
		std::cout << "Build new small house?\n";

		std::cin >> i;
		if (i == 'y') {
			std::cout << "New SmallHouse built\n";
			for (size_t i = 0; i < 100; i++) {
				sh.push_back(new SmallHouse);
				std::cout << "You have now " << sh.size() << " SmallHouses\n";
			}
		}
		else if (i == 'n') {
			stop = true;
		}
		else if (i == 'd') {
			stop = true;
			importantDestructor(sh);
			std::cout << "Everything destroyed!" << std::endl;
		}
		else {
			std::cout << "invalid input" << std::endl;
		}
	}
}

//derefferencing pointers in vector and deleting them afterwards;clearing vector at the end
void importantDestructor(std::vector<SmallHouse*> &sh) {
	int c = 0;
	for (const auto& i : sh) {
		std::cout << "Deleted " << &i << "\n";
		delete i;
		c++;
	}
	std::cout << c << "\n";
	sh.clear();
}

int main() {
	construct();
	char c;
	std::cin >> c;
}
