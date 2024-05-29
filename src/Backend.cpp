#include "Backend.h"

Backend::Backend() {
	pops.liv = 0;
	pops.work = 0;

	Interface gui(pops.liv, pops.work, game.turn, calcDevotion(assets.v_liv));

	InvManagement::get().addToStock(InvManagement::wheat, 1000);
	assets.v_liv.push_back(new SmallHouse);
	assets.v_liv.push_back(new SmallHouse);
	assets.v_work.push_back(new Lumberjack);
	assets.v_work.push_back(new Farm);
	
	//game loop
	while (true) {
		et = false;
		//turn loop
		//user input
		InvManagement::get().addToStock(InvManagement::wood, 100);
		pops.liv = calcPeople(assets.v_liv);
		pops.work = calcPeople(assets.v_work);

		updateGUI(gui, pops.liv, pops.work, game.turn, calcDevotion(assets.v_liv));
		while (et == false) {
			int action = gui.InterfaceInit();

			if (action == 1) {
				addToBQueue(new SmallHouse, assets.v_liv, assets.sh.getBuildTime());
			}
			if (action == 2) {
				addToBQueue(new Lumberjack, assets.v_work, assets.lj.getBuildTime());
			}
			if (action == 3) {
				addToBQueue(new Farm, assets.v_work, assets.f.getBuildTime());
			}
			if (action == 4) {
				addToBQueue(new Church, assets.v_spec, assets.c.getBuildTime());
			}
			if (action == 10) {
				et = true;
			}
		}
		save();
		//todo a class might be beneficial to avoid blank repition
		///*Living update First*///
		updateLivPopInc(assets.v_liv);

		///*Production generation*///
		updateWorkPopInc(assets.v_work);
		//updatePopInc(assets.fv);

		generateGoods(assets.v_work);
		//generateGoods(assets.fv);

		updateDevotion(assets.v_liv, assets.v_spec);

		if (generateConsume(assets.v_liv) < 0) {		
			auto e_starv = std::make_unique<StarvingEvent>(2 + m_starvCount, assets.v_liv);
			e_starv->execute();
			m_starvCount++;
		}
		if (rand() % 100 < 100) {
			auto e_fire = std::make_unique<FireEvent>(20, assets.v_liv);
			e_fire->execute();
		}
		
		///*building generation*///
		buildFactory();
		std::cout << "Number of Small Houses: " << assets.v_liv.size() << "\n";

		if (assets.v_liv.size() > 0) {
			std::cout << "A Small House has been build. There are now: " << assets.v_liv.size() << "\n";
		}
		

		auto pos = std::find_if(assets.v_work.begin(), assets.v_work.end(), [](Building* b) {return dynamic_cast<Lumberjack*>(b) != nullptr; });
		if (assets.v_work.size() > 0) {
			std::cout << "A Working Building has been build. There are now: " << assets.v_work.size() << "\n";
		}
		system("CLS");
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

void Backend::updateGUI(Interface& gui, const int& clP, const int& cwP, const int& t, const float& dev) {
	gui.updateCLP(clP);
	gui.updateCWP(cwP);
	gui.updateT(t);
	gui.updateDev(dev);
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
		std::cout << "CurPop: " << curPop << "\n";
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

void Backend::remove(std::vector<Building*> &v_bt) {
	v_bt.erase(v_bt.end());
	std::cout << "You have now " << v_bt.size() << " of Type " << "\n";
}

void Backend::updateLivPopInc(std::vector<Building*>& btv) {
	
	std::cout << "Btv Size: " << btv.size() << "\n";
	for (int i = 0; i < btv.size();++i) {
		int modifier = 2;

		//todo const value(2) for now will be calculated with a stupid calc
		int curPop = btv[i]->getNumPop();
		int maxPop = btv[i]->getMaxPop();

		std::cout << "Before on Index " << i << ": NumPops: " << curPop << " MaxPop : " << maxPop << "\n";
		std::cout << "Before on Index " << btv.size()-1 << ": NumPops: " << btv[btv.size() - 1]->getNumPop() << " MaxPop : " << btv[btv.size() - 1]->getMaxPop() << "\n";
		int newPop = std::min(curPop + modifier, maxPop);

		btv[i]->moveIn(newPop - curPop);
		pops.liv += newPop - curPop;



		std::cout << "After on Index " << i << ": NumPops: " << btv[i]->getNumPop() << " MaxPop : " << btv[i]->getMaxPop() << "\n";
		std::cout << "After on Index " << btv.size() - 1 << ": NumPops: " << btv[btv.size() - 1]->getNumPop() << " MaxPop : " << btv[btv.size() - 1]->getMaxPop() << "\n";
		
		std::cout << "on index: " << i << "\n";
		std::cout << "numpops: " << btv[i]->getNumPop() << "\n";

	}
}

void Backend::updateWorkPopInc(std::vector<Building*>& btv) {
	std::cout << "Btv Size: " << btv.size() << "\n";
	for (int i = 0; i < btv.size(); ++i) {
		if (pops.liv > pops.work) {
			int modifier = 2;
			int unemployed = updateUnemployed();


			if (unemployed < 2) {
				modifier = pops.unemployed;
			}
			int curPop = btv[i]->getNumPop();
			int maxPop = btv[i]->getMaxPop();

			int newPop = std::min(curPop + modifier, maxPop);

			btv[i]->moveIn(newPop - curPop);
			pops.work += newPop - curPop;
			pops.unemployed -= newPop - curPop;
		}else{
			btv[i]->moveOut(pops.work - pops.liv);
			pops.work -= pops.liv;
		}
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

void Backend::updateDevotion(std::vector<Building*>& v_house, std::vector<Building*>& v_church) {
	//if church max pops > num pops
	for (Building* b : v_house) {
		Living* i = dynamic_cast<Living*>(b);
		int remDev = i->getNumPop() - i->getDevotion();
		if (remDev > 0) {
			for (int j = 0; j < v_church.size() && remDev > 0;++j) {
				int avSpace = v_church[j]->getMaxPop() - v_church[j]->getNumPop();
				if (avSpace > 0) {
					int mvInPops = std::min(remDev, avSpace);
					i->setDevotion(mvInPops);
					v_church[j]->moveIn(mvInPops);
					remDev -= mvInPops;
				}
			}
		}
	}
}

int Backend::calcDevotion(const std::vector<Building*>& v_bt) {
	int devoted = 0;
	int total = 0;
	for (Building* b : v_bt) {
		Living* i = dynamic_cast<Living*>(b);
		devoted += i->getDevotion();
		total+= i->getNumPop();
	}
	if (total == 0) { return 0; }
	return (devoted * 100) / total;
}

void Backend::updateSol(std::vector<Building*>v_bt) {
	for (Building* btemp : v_bt) {
		Living* i = dynamic_cast<Living*>(btemp);
		//todo some other things have to be included
		i->setSol(i->getDevotion());
	}
}

void Backend::save() {
	Save his;

	his.turn = game.turn;

	his.v_hisLiv = assets.v_liv;
	his.v_hisWork = assets.v_work;
	his.v_hisSpec = assets.v_spec;

	his.liv = pops.liv;
	his.work = pops.work;
	his.unemployed = pops.unemployed;

	his.wood = InvManagement::get().getStock(InvManagement::wood);
	his.wheat = InvManagement::get().getStock(InvManagement::wheat);

	game.history.push_back(his);
}



void Backend::undo(const int& t) {
	game.turn = game.history[t].turn;

	assets.v_liv = game.history[t].v_hisLiv;
	assets.v_work = game.history[t].v_hisWork;
	assets.v_spec = game.history[t].v_hisSpec;

	pops.liv = game.history[t].liv;
	pops.work = game.history[t].work;
	pops.unemployed = game.history[t].unemployed;

	InvManagement::get().setStock(InvManagement::wood, game.history[t].wood);
	InvManagement::get().setStock(InvManagement::wheat, game.history[t].wheat);

	game.history.erase(game.history.begin() + (t + 1), game.history.end());
}

Backend::~Backend() {
	for (auto& i : assets.v_liv) {
		delete &i;
	}
}