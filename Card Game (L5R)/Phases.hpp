#include "Player.hpp"
using namespace std;


class Phases{
	private:
		Provinces provinces;
		Hand hand;
		BlackDeck blackdeck;
		GreenDeck greendeck;
		Army army;
		Holdings holdings;
		int maxhandsize;
	public:
		Phases(){ maxhandsize = 6;}
		void startingPhase(Player *player);
		void equipPhase(Player *player);
		void economyPhase(Player *player);
		
		
		int battlePhase(Player *player ,int *armpos);
		int chooseOpponent(int plpos , int oppsize);
		int opponentDefences(Player *player, int att , int *armpos);
		void clearVictory(Player * player ,int *armpos);
		void semiWin(Player * player , int *armpos ,int ad);
		void clearDefeat(Player * player);
		void defeat(Player *player);
		
		void endingPhase(Player *player);
		void discardSurplusFateCards(Hand hand);
		void testPhase(Player *player);
};























/*
class StartingPhase {
	public:
		StartingPhase(){};
		void untapEverything(Army army , Holdings holdings);
		void drawFateCard(Hand hand, GreenDeck greendeck)		{hand.addCard(greendeck.giveCard()); }
		void revealProvinces(Provinces provinces)		{provinces.revealAll();}
		void printHand(Hand hand)		{ hand.print() ;}
		void printProvinces(Provinces provinces)		{ provinces.print(); }
};

class EquipPhase {
	public:
		EquipPhase(){};
		void printHand(Hand hand){ hand.print() ;}
		void printArmy(Army army){ army.print() ;}
		void buyCard(Army army , Hand hand , Holdings holdings);
};

class EconomyPhase{
	public:
		EconomyPhase(){};
		void revealProvinces(Provinces provinces) {provinces.revealAll();}
		void printProvinces(Provinces provinces){ provinces.print(); }
		void buyCard(Army army , Provinces provinces , Holdings holdings);
};

class BattlePhase{
	public:
		BattlePhase(){};
		int gatherForces(Army army);
		void opponentDefences(Army army);
		
};*/
