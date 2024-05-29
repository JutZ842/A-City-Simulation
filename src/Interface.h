#pragma once
#include <vector>
#include <map>

class Interface
{
	public:
		//todo in theory if this is the only function that gets called through the backend this could be the constructor
		Interface(const int& curLivPop, const int& curWorkPop, const int& turn, const int& devotion);



		//void getInv(const std::map<products, float>& inv) {
		//	
		//}
		int InterfaceInit();
		void updateCLP(const int& curLivPop);
		void updateCWP(const int& curWorkPop);
		void updateT(const int& turn);
		void updateDev(const int& devotion);
	private:
		int m_clP = 0;
		int m_cwP = 0;
		int m_t = 0;
		int m_dev = 0;
		
		char m_i;

		void infoScreen();
		int standardScreen();
		int buildScreen();
		int upgradeScreen();
		int removeScreen();
};

