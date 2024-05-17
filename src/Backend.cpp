#include <iostream>

#include "Backend.h"

Backend::Backend() {
	pops.liv = 0;
	pops.work = 0;

	Interface gui(pops.liv, pops.work, game.turn);

	InvManagement::get().addToStock(InvManagement::wheat, 10);
	//game loop
	while (true) {
		et = false;
		//turn loop
		//user input
		InvManagement::get().addToStock(InvManagement::wood, 10);
		pops.liv = calcPeople(assets.shv);
		pops.work = calcPeople(assets.ljv);

		updateGUI(gui, pops.liv, pops.work, game.turn);
		while (et == false) {
			int action = gui.InterfaceInit();

			if (action == 1) {
				addToBQueue(sh, assets.shv);
			}
			/*if (action == 2) {
				build(lj, assets.ljv);
			}
			if (action == 3) {
				build(f, assets.fv);
			}*/
			if (action == 10) {
				et = true;
			}
		}
		save();
		//todo a class might be beneficial to avoid blank repition
		///*Living update First*///
		updatePopInc(assets.shv);

		///*Production generation*///
		updatePopInc(assets.ljv);
		updatePopInc(assets.fv);

		generateGoods(assets.ljv);
		generateGoods(assets.fv);

		generateConsume(sh, assets.shv);
		
		///*building generation*///
		buildFactory();

		if (pops.work > pops.liv) {
			std::cout << "Error! Too many workers: \nWorkers: " << pops.work << "\nResidents: " << pops.work << "\n";
		}
		if (assets.shv.size() > 0) {
			std::cout << "A Small House has been build. There are now: " << assets.shv.size() << "\n";
		}
		game.turn++;
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
				return -1;
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

//template<typename T>
void Backend::build(SmallHouse& bt, std::vector<SmallHouse>& v) {
		v.push_back(bt);
}

//make a vector
//put build element in vector
//iterate through vector in every turn
//reduce time to build by 1
//if 0 build is called

template<typename T>
int Backend::addToBQueue(T& bt, std::vector<T>& v_bt) {
	if (InvManagement::get().getStock(bt.getBuildMat()) >= bt.getCosts()) {
		BuildQueue bq(bt, v_bt, bt.getBuildTime());
		bQueue.push_back(bq);
		std::cout << "A Building has been added to the queue " << bQueue.size() << "\n";

		InvManagement::get().removeFromStock(bt.getBuildMat(), bt.getCosts());
		return 0;
	}else {
		return -1;
	}
}

void Backend::buildFactory() {
	for (size_t i = 0; i < bQueue.size(); i++) {
		if (bQueue[i].time == 0) {
			build(bQueue[i].type, bQueue[i].v_type);
		}
		else {
			bQueue[i].time--;
		}
		std::cout << "Value of i: " << i << "\nValue of t: " << bQueue[i].time << "\n";
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
			}
		}
		i.moveIn(modifier);
	}
}

template<typename T>
void Backend::updatePopDec(std::vector<T>& bt) {
}

void Backend::updatePops() {
	//todo there has to be smarter solution for the calculation than calling these functions back to back
}

template <typename T>
void Backend::generateGoods(std::vector<T>& g) {
	for (auto& i : g) {
		InvManagement::get().addToStock(i.getProduct(), i.createGoods(i.getNumPop(), i.getMaxPop()));
	}
}

void Backend::save() {
	Save his;

	his.turn = game.turn;

	his.hisFv = assets.fv;
	his.hisLjv = assets.ljv;
	his.hisShv = assets.shv;

	his.liv = pops.liv;
	his.work = pops.work;
	his.unemployed = pops.unemployed;

	his.wood = InvManagement::get().getStock(InvManagement::wood);
	his.wheat = InvManagement::get().getStock(InvManagement::wheat);

	game.history.push_back(his);
}

void Backend::undo(const int& t) {
	game.turn = game.history[t].turn;

	assets.fv = game.history[t].hisFv;
	assets.ljv = game.history[t].hisLjv;
	assets.shv = game.history[t].hisShv;

	pops.liv = game.history[t].liv;
	pops.work = game.history[t].work;
	pops.unemployed = game.history[t].unemployed;

	InvManagement::get().setStock(InvManagement::wood, game.history[t].wood);
	InvManagement::get().setStock(InvManagement::wheat, game.history[t].wheat);

	game.history.erase(game.history.begin() + (t + 1), game.history.end());
}
