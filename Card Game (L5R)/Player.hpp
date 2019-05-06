#include "APlayer.hpp"

#include <list> 
#include <iostream>
#include <ctime>
using namespace std;

class Player{
	private:
		GreenDeck greendeck;
		BlackDeck blackdeck;
		Hand hand;
		Provinces provinces;
		Holdings holdings;
		Army army;
		int pos;
	public:
		Player(int p);
		GreenDeck giveGreenDeck();
		BlackDeck giveBlackDeck();
		Hand giveHand();
		Provinces giveProvinces();
		Holdings giveHoldings();
		Army giveArmy();
		void fillProvinces();
		void printProvinces();
		void shuffle();
		void printPlayerStatistics();
		void printArmy();
		int getProvincesDef();
		int givePos();
		
		int getInitialDefence();
};
