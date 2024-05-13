#include <iostream>

#include "Backend.h"

Backend::Backend() {
	pops.liv = 0;
	pops.work = 0;

	while (eg == false) {
		Interface gui;
		int action = gui.interfaceHandler(calcPeople(assets.sh, pops.liv), calcPeople(assets.lj, pops.work));
		if (action == 1) {
			build(assets.sh);
		}
		if (action == 2) {
			build(assets.lj);
		}
		Game.move++;
	}
}

//calculates the current number of pops living/working in whole city
template <typename T>
int Backend::calcPeople(std::vector<T>sh, int curPop) {
	
	for (auto& i : sh) {
		curPop += i.getNumPop();
	}
	return curPop;
}

template<typename T>
void Backend::build(std::vector<T> &bt) {
	bt.push_back(T());
	std::cout << "You have now " << bt.size() << " of Type " <<  "\n";
}

template<typename T>
void Backend::remove(std::vector<T>& bt) {
	bt.pop_back();
	std::cout << "You have now " << bt.size() << " of Type " << "\n";
}
