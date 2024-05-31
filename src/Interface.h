#pragma once
#include <vector>
#include <map>
#include <iostream>

#include "InvManagement.h"
#include "ReachedHamletLevelEvent.h"
#include "ReachedVillageLevelEvent.h"

class Interface {
	public:
		//todo in theory if this is the only function that gets called through the backend this could be the constructor
		Interface(const int& curLivPop, const int& curWorkPop, const int& turn, const int& devotion, const int& score, const int& level);

		int InterfaceInit();
		void updateCLP(const int& curLivPop);
		void updateCWP(const int& curWorkPop);
		void updateT(const int& turn);
		void updateDev(const int& devotion);
		void updateScore(const int& score);
		void updateCityLevel(const int& level);
		int getGamemode();
		void victoryScreen();

	private:
		int m_clP = 0;
		int m_cwP = 0;
		int m_t = 0;
		int m_dev = 0;
		int m_score = 0;
		int m_level = 1;


		int m_gm;
		bool m_reachedVillage = ReachedVillageLevelEvent::get().reachedLevel();
		
		char m_i;

		const enum Gamemodes {
			fp,
			sp,
			rc
		};

		void welcomeScreen();
		void infoScreen();
		int standardScreen();
		int buildScreen();
		int upgradeScreen();
		int removeScreen();
};

