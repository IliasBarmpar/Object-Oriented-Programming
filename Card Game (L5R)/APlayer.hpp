#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <list>
#include <iostream>
#include "Card.hpp"
#include "Personality.hpp"
#include "Holding.hpp"
#include <ctime>
using namespace std;

class GreenDeck{
	private:
		list<GreenCard*> *greendeck;        // Edo eixes 2 parentheseis
	public:
		GreenDeck(); // createFateDeck								
		void createFateDeck(); //!	
		void shuffle();												
		GreenCard * giveCard();											
		void print();												
};

class BlackDeck{
	private:
		list<BlackCard*> *blackdeck;
	public:
		BlackDeck(); // creteDynastyDeck
		void createDynastyDeck(); //!
		void shuffle();	
		BlackCard * giveCard();
		void print();
};



class Hand{ // done
	private:
		list<GreenCard*> *hand;
	public:
		Hand();
		void print();
		void addCard(GreenCard *card);	
		int getCost(int pos);
		int getMinimumHonour(int pos);
		int getEffectCost(int pos);
		void activateBonus(int pos);
		bool getBonusActivated(int pos);
		int size();
		bool empty();
		void removeCard(int pos);

		GreenCard * giveCard(int pos);
};

class Provinces{ //done
	private:
		list<BlackCard*> *provinces;
		int remainingProvinces; //!
		int initialDef;
	public:
		Provinces();
		void print();
		void revealAll();
		void reveal(int pos);
		void addCard(int pos , BlackCard *);
		const string getType(int pos);
		int getCost(int pos) ;
		int getDef();
		bool empty();
		int size();
		int getRemainingProvinces(){ return remainingProvinces;	}
		void decreaseProvinces() { 
			if(remainingProvinces>0) remainingProvinces--;
			provinces->pop_back();
		}
		BlackCard * giveCard(int pos);
};




class Holdings{ 	//done
	private:
		list<BlackCard *> *holdings;
	public:
		Holdings();
		void print();
		void untapEverything();
		void addCard(BlackCard *);
		void tapCard(int pos);
		void untapCard(int pos);
		int getHarvestValue(int pos);
		int getIsTapped(int pos); 
		int getInitialDefence();
		void checkUpperGoldMines(BlackCard *mine);
		void checkMines(BlackCard *goldmine) ; 
		void checkCrystalMines(BlackCard *goldmine);
		void checkSubGoldMines(BlackCard *crystalmine);
		int size();
//		void giveCard(Holding *); den xreiazete logika
};

class Army{ 	//done expect remove
	private:
		list<BlackCard *> *army;
	public:
		Army(){ army = new list<BlackCard *>; }
		void print();
		void untapEverything();
		void addCard(BlackCard *);
		BlackCard * giveCard(int pos);
		void reveal(int pos );
		
		int getAttack(int pos);
		int getDef(int pos);
		int getHonour(int pos);
		int getIsTapped(int pos);
		int getIsDead(int pos);
		void reduceHonour(int pos);
		void tapCard(int pos);
		void untapCard(int pos);
		void addHelpingCard(GreenCard *card , int pos);	
		bool empty();
		int size();
		int getHelpingCardsAttack(int pos ,int gcpos);
		int followerSize(int pos);
		void removeCard(int pos); // added cards ? 
		void printPersonality(int pos);
		int allFollowerSize();
		int findPrevFollowerSize(int pos);
		int findMySize(int pos);
		void removeHelpingCard(int pos , int gcpos);
};

#endif
