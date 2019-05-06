#ifndef _CARD_HPP_
#define _CARD_HPP_

#include <string>
#include <iostream>

using namespace std;

void readStats(char *fileName, char *findText, int no_stats, int stats[]);

class Card{
	protected:
		string name;
		int cost;
		bool isTapped;
	public:
		Card(){isTapped = true;}
		~Card(){}

		int getCost(){return cost;}
		bool getIsTapped(){return isTapped;}
		
		void tap(){isTapped = true;}
		void untap(){isTapped = false;}
};

class GreenCard : public Card{
	protected:
		int attackBonus;
		int defenseBonus;
		int minimumHonour;
		int effectBonus;
		int effectCost;
		bool bonusActivated;
		string cardText;
	public:
		GreenCard(){bonusActivated = false;}
		virtual ~GreenCard(){}
		
        virtual void print() = 0;
		int getAttackBonus(){return attackBonus;}
		int getDefenseBonus(){return defenseBonus;}
		int getMinimumHonour(){return minimumHonour;}
		int getEffectBonus(){return effectBonus;}
		int getEffectCost(){return effectCost;}
		bool getBonusActivated(){return bonusActivated;} //htan int KTC 
		
		void activateBonus(){bonusActivated = true;}
		
		// Functions for Items only!
		virtual int getDurability(){return -1;}  // If it is not an item it returns -1
		virtual bool reduceDurability(){return false;} // !!!No error handling!!!
};

class BlackCard : public Card{
 protected:
		bool isRevealed;
	public:
		BlackCard(){isRevealed = false;}
		virtual ~BlackCard(){}

  		virtual void print() = 0;
		bool getIsRevealed(){return isRevealed;}
		void reveal(){isRevealed = true;}
		virtual const string Type() = 0;
		
		//Functions for Personalities
		virtual int getAttack(){return -1;}       // If it is not a Personality it returns -1
		virtual int getDefense(){return -1;}      // If it is not a Personality it returns -1
		virtual int getHonour(){return -1;}       // If it is not a Personality it returns -1
		virtual bool getIsDead(){return false;} 		// !!!No error handling!!!
		virtual int getHelpingCardsAttack(int pos){}

		virtual bool reduceHonour(){return false;}    	// !!!No error handling!!!
		virtual int followerSize(){}
		virtual void addHelpingCard(GreenCard *greenCard){} // !!!No error handling!!!
		virtual GreenCard* removeHelpingCard(int pos){return NULL;} // If it is not a Personality it returns NULL
		
		//Functions for Holdings
		virtual int getHarvestValue(){return -1;} // If it is not a Holding it returns -1
		virtual bool chainComplete(){return false;} // !!!No error handling!!!
		virtual void setUpperHolding(BlackCard *card){} // !!!No error handling!!!
		virtual void setSubHolding(BlackCard *card){} // !!!No error handling!!!
		virtual BlackCard * getUpperHolding(){}
		virtual BlackCard * getSubHolding(){}
		virtual int getInitialDefence(){}
		
};

#endif
