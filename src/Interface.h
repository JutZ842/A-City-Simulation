#pragma once
#include <vector>
#include <map>

class Interface
{
	public:
		//todo in theory if this is the only function that gets called through the backend this could be the constructor
		Interface(const int& curLivPop, const int& curWorkPop, const int& turn);
		//void getInv(const std::map<products, float>& inv) {
		//	
		//}
		int InterfaceInit();
		void updateCLP(const int& curLivPop);
		void updateCWP(const int& curWorkPop);
		void updateT(const int& turn);
	private:
		int clP;
		int cwP;
		int t;
		
		char i;

		void infoScreen();
		int standardScreen();
		int buildScreen();
		int upgradeScreen();
		int removeScreen();
};

