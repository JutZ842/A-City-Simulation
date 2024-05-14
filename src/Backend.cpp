#include <iostream>

#include "Backend.h"

Backend::Backend() {
	pops.liv = 0;
	pops.work = 0;
	
	//game loop
	while (true) {
		et = false;
		//turn loop
		//user input
		InvManagement::get().addToStock(InvManagement::wood, 10);

		while (et == false) {
			int action = gui.interfaceHandler(calcPeople(assets.sh, pops.liv), calcPeople(assets.lj, pops.work), game.move);

			if (action == 1) {
				build(sh, assets.sh);
			}
			if (action == 2) {
				//build(lj);
			}
			if (action == 3) {
				et = true;
			}
		}
		//all the generation stuff
		//todo !
		updatePopInc(assets.sh);
		updatePopInc(assets.lj);

		generateGoods(assets.lj);

		game.move++;
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
void Backend::build(T &bt, std::vector<T> &v) {
	if (InvManagement::get().getStock(bt.getBuildMat()) >= bt.getCosts()) {
		v.push_back(bt);
		InvManagement::get().removeFromStock(bt.getBuildMat(), bt.getCosts());
	}
	std::cout << "You have now " << assets.sh.size() << " of Type " << "\n";
}

template<typename T>
void Backend::remove(std::vector<T> &bt) {
	bt.pop_back();
	std::cout << "You have now " << bt.size() << " of Type " << "\n";
}

template<typename T>
void Backend::updatePopInc(std::vector<T> &bt) {
	for (auto& i : bt) {
		//todo const value(2) for now will be calculated with a stupid calc
		i.moveIn(2);
	}
}

template <typename T>
void Backend::generateGoods(std::vector<T>& g) {

	for (auto& i : g) {
		InvManagement::get().addToStock(i.getProduct(), i.createGoods(i.getNumPop(), i.getMaxPop()));
	}
}