#include <iostream>

#include "Backend.h"

Backend::Backend() {
	pops.liv = 0;
	pops.work = 0;

	Interface gui(pops.liv, pops.work, game.move);

	InvManagement::get().addToStock(InvManagement::wheat, 10);
	//game loop
	while (true) {
		et = false;
		//turn loop
		//user input
		InvManagement::get().addToStock(InvManagement::wood, 10);
		pops.liv = calcPeople(assets.shv);
		pops.work = calcPeople(assets.ljv);

		updateGUI(gui, pops.liv, pops.work, game.move);
		while (et == false) {
			int action = gui.InterfaceInit();

			if (action == 1) {
				build(sh, assets.shv);
			}
			if (action == 2) {
				build(lj, assets.ljv);
			}
			if (action == 3) {
				build(f, assets.fv);
			}
			if (action == 10) {
				et = true;
			}
		}
		//all the generation stuff
		//todo !
		//todo a class might be beneficial to avoid blank repition
		///*Living update First*///
		updatePopInc(assets.shv);

		///*Production generation*///
		updatePopInc(assets.ljv);
		updatePopInc(assets.fv);

		generateGoods(assets.ljv);
		generateGoods(assets.fv);

		generateConsume(sh, assets.shv);

		if (pops.work > pops.liv) {
			std::cout << "Error! Too many workers: \nWorkers: " << pops.work << "\nResidents: " << pops.work << "\n";
		}

		game.move++;
	}	
}

template<typename T>
int Backend::generateConsume(T& bt, const std::vector<T>&v) {
	for (auto& i : v) {
		for (auto const& [good, quantity] : bt.getConsumption()) {
			if (InvManagement::get().getStock(good) - quantity >= 0) {
				InvManagement::get().removeFromStock(good, quantity);
			}
			else{
				//todo can trigger a starving event or whatever
				return 1;
			}
		}
	}
	return 0;
}

void Backend::updateGUI(Interface& gui, const int& clP, const int& cwP, const int& t) {
	gui.updateCLP(clP);
	gui.updateCWP(cwP);
	gui.updateT(t);
}

int Backend::updateUnemployed() {
	return pops.unemployed = pops.liv - pops.work;
}

//calculates the current number of pops living/working in whole city
template <typename T>
int Backend::calcPeople(std::vector<T>&bt) {	
	int curPop = 0;
	for (auto& i : bt) {
		curPop += i.getNumPop();
		//i.getIsLiving() ? pops.liv = curPop : pops.work = curPop;
	}
	return curPop;
}

template<typename T>
void Backend::build(T &bt, std::vector<T> &v) {
	if (InvManagement::get().getStock(bt.getBuildMat()) >= bt.getCosts()) {
		v.push_back(bt);
		InvManagement::get().removeFromStock(bt.getBuildMat(), bt.getCosts());
	}
}

template<typename T>
void Backend::remove(std::vector<T> &bt) {
	bt.pop_back();
	std::cout << "You have now " << bt.size() << " of Type " << "\n";
}

template<typename T>
void Backend::updatePopInc(std::vector<T> &bt) {
	int modifier;

	for (auto& i : bt) {
		modifier = 2;
		//todo const value(2) for now will be calculated with a stupid calc
		if (!i.getIsLiving()) {
			if (updateUnemployed() < 2) {
				modifier = pops.unemployed;
				std::cout << "Modifier: " << modifier << "\n";
			}
		}
		std::cout << "Modifier: " << modifier << "\n";
		i.moveIn(modifier);
	}
}

template <typename T>
void Backend::generateGoods(std::vector<T>& g) {
	for (auto& i : g) {
		InvManagement::get().addToStock(i.getProduct(), i.createGoods(i.getNumPop(), i.getMaxPop()));
	}
}
