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
		pops.work = calcPeople(assets.ljv) + calcPeople(assets.fv);

		updateGUI(gui, pops.liv, pops.work, game.turn);
		while (et == false) {
			int action = gui.InterfaceInit();

			if (action == 1) {
				addToBQueue(&sh, assets.shv, sh.getBuildTime());
			}
			if (action == 2) {
				addToBQueue(&lj, assets.ljv, lj.getBuildTime());
			}
			if (action == 3) {
				addToBQueue(&f, assets.fv, f.getBuildTime());
			}
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

		if (generateConsume(assets.shv) < 0) {
			StarvingEvent starv(2 + m_starvCount, assets.shv);
			starv.execute();
			m_starvCount++;
		}
		
		///*building generation*///
		buildFactory();
		std::cout << "Number of Small Houses: " << assets.shv.size() << "\n";

		if (assets.shv.size() > 0) {
			std::cout << "A Small House has been build. There are now: " << assets.shv.size() << "\n";
		}
		if (assets.ljv.size() > 0) {
			std::cout << "A Lumber Jack has been build. There are now: " << assets.ljv.size() << "\n";
		}
		if (assets.fv.size() > 0) {
			std::cout << "A Farm has been build. There are now: " << assets.fv.size() << "\n";
		}
		game.turn++;
	}	
}

int Backend::generateConsume(const std::vector<Building*>& btv) {
	for (auto& i : btv) {
		for (auto const& [good, quantity] : i->getConsumption()) {
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
	if (pops.liv - pops.work > 0) {
		return pops.unemployed = pops.liv - pops.work;
	}else{
		return pops.unemployed = 0;
	}	
}

//calculates the current number of pops living/working in whole city
int Backend::calcPeople(std::vector<Building*>& bt) {	
	int curPop = 0;
	for (auto& i : bt) {
		curPop += i->getNumPop();
		//i.getIsLiving() ? pops.liv = curPop : pops.work = curPop;
	}
	return curPop;
}

void Backend::build(Building* bt, std::vector<Building*>* v_bt) {
	std::cout << "Reached build! pre: " << v_bt->size() << "\n";
	v_bt->push_back(bt);
	std::cout << "aft: " << v_bt->size() << "\n";
}

int Backend::addToBQueue(Building* bt, std::vector<Building*>& v_bt, int turns) {
	if (InvManagement::get().getStock(bt->getBuildMat()) >= bt->getCosts()) {
		bQueue.emplace_back(bt, &v_bt, turns);
		std::cout << "A Building has been added to the queue " << bQueue.size() << "\n";

		InvManagement::get().removeFromStock(bt->getBuildMat(), bt->getCosts());
		return 0;
	}else {
		std::cout << "Theres not enough material to build this builing\n";
		return -1;
	}
}

void Backend::buildFactory() {
	for (auto i = bQueue.begin(); i != bQueue.end();) {
		std::cout << "Reached build factory\n";
		if (i->time == 0) {
			std::cout << "Reached build turn\n";
			i->v_type->push_back(i->type);
			i = bQueue.erase(i);
		}
		else {
			i->decTurn();
			++i;
		}
	}
}

template<typename T>
void Backend::remove(std::vector<T> &bt) {
	bt.pop_back();
	std::cout << "You have now " << bt.size() << " of Type " << "\n";
}

void Backend::updatePopInc(std::vector<Building*>& btv) {
	int modifier;

	std::cout << "Btv Size: " << btv.size() << "\n";
	for (auto i = btv.begin(); i != btv.end();++i) {
		modifier = 2;
		//todo const value(2) for now will be calculated with a stupid calc
		if (!(*i)->getIsLiving()) {
			if (updateUnemployed() < 2) {
				modifier = pops.unemployed;
			}
		}
		(*i)->moveIn(modifier);
		std::cout << "numpops: " << (*i)->getNumPop() << "\n";
	}
}

void Backend::updatePopDec(std::vector<Building*>& bt, int amount) {
	for (auto i = bt.begin(); i != bt.end();++i) {
		(*i)->moveOut(amount);
		updateUnemployed();
	}
}

void Backend::updatePops() {
	//todo there has to be smarter solution for the calculation than calling these functions back to back
}

void Backend::generateGoods(std::vector<Building*>& g) {
	for (auto& i : g) {
		InvManagement::get().addToStock(i->getProduct(), i->createGoods(i->getNumPop(), i->getMaxPop()));
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
