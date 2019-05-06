#ifndef _HOLDING_HPP_
#define _HOLDING_HPP_

#include "Card.hpp"

#include <list>

class Holding : public BlackCard{
	protected:
		int harvestValue;
	public:
		Holding(){}
		virtual ~Holding(){}

		virtual void print(){
			if(isRevealed){
				cout << "***************************" << endl;
				cout << "Card Name:      " << name << endl;
				cout << "Cost:           " << cost << endl;
				cout << "Harvest Value:  " << harvestValue << endl;
				cout << "Is Tapped:      " << isTapped << endl;
				cout << "Is Revealed:    " << isRevealed << endl;
				cout << "***************************" << endl << endl;
			}else{
				cout << "***************************" << endl;
				cout << "***************************" << endl;
				cout << "***************************" << endl;
				cout << "***************************" << endl;
				cout << "**********HIDDEN***********" << endl;
				cout << "***************************" << endl;
				cout << "***************************" << endl;
				cout << "***************************" << endl;
				cout << "***************************" << endl;
				cout << "***************************" << endl << endl;
			}
		}
		virtual int getHarvestValue(){return harvestValue;} //HarvestValue bonusses
		virtual bool chainComplete(){return false;} //Only used by GoldMine
		virtual void setUpperHolding(BlackCard *card){} //Only used by Mines
		virtual void setSubHolding(BlackCard *card){} //Only used by Mines
		virtual BlackCard * getUpperHolding(){}
		virtual BlackCard * getSubHolding(){}
		virtual const string Type(){return "Holding";}
		virtual int getInitialDefence(){}
};

class Plain : public Holding{
	public:
		Plain(string n);
		~Plain(){}
};

class Mine : public Holding{
	private:
		BlackCard *upperHolding; 	//Mines hold pointer to the card that they are connected to only
								//for the chainComplete function and other future additions
	public:
		Mine(string n);
		~Mine(){}
		
        void print(){
			if(isRevealed){
				cout << "***************************" << endl;
				cout << "Card Name:      " << name << endl;
				cout << "Cost:           " << cost << endl;
				cout << "Harvest Value:  " << harvestValue << endl;
				if(upperHolding)
					cout << "Upper Holding:  Connected" << endl;
				else
				    cout << "Upper Holding:  Not Connected" << endl;
				cout << "Is Tapped:      " << isTapped << endl;
				cout << "Is Revealed:    " << isRevealed << endl;
				cout << "***************************" << endl << endl;
			}else{
				cout << "***************************" << endl;
				cout << "***************************" << endl;
				cout << "***************************" << endl;
				cout << "***************************" << endl;
				cout << "**********HIDDEN***********" << endl;
				cout << "***************************" << endl;
				cout << "***************************" << endl;
				cout << "***************************" << endl;
				cout << "***************************" << endl;
				cout << "***************************" << endl << endl;
			}
		}
		int getHarvestValue();
		
		void setUpperHolding(BlackCard *card){upperHolding = card;}
		BlackCard * getUpperHolding(){return upperHolding;}
		
		const string Type(){return "Mine";}
};

class GoldMine : public Holding{
	private:
		BlackCard *upperHolding;
		BlackCard *subHolding;
	public:
		GoldMine(string n);
		~GoldMine(){}

        void print(){
			if(isRevealed){
				cout << "***************************" << endl;
				cout << "Card Name:      " << name << endl;
				cout << "Cost:           " << cost << endl;
				cout << "Harvest Value:  " << harvestValue << endl;
				if(upperHolding)
					cout << "Upper Holding:  Connected" << endl;
				else
				    cout << "Upper Holding:  Not Connected" << endl;
				if(subHolding)
					cout << "Sub Holding:    Connected" << endl;
				else
					cout << "Sub Holding:    Not Connected" << endl;
				cout << "Is Tapped:      " << isTapped << endl;
				cout << "Is Revealed:    " << isRevealed << endl;
				cout << "***************************" << endl << endl;
			}else{
				cout << "***************************" << endl;
				cout << "***************************" << endl;
				cout << "***************************" << endl;
				cout << "***************************" << endl;
				cout << "**********HIDDEN***********" << endl;
				cout << "***************************" << endl;
				cout << "***************************" << endl;
				cout << "***************************" << endl;
				cout << "***************************" << endl;
				cout << "***************************" << endl << endl;
			}
		}
		int getHarvestValue();
		bool chainComplete();
		const string Type(){return "Gold Mine";}

		void setSubHolding(BlackCard *card){subHolding = card;}
		void setUpperHolding(BlackCard *card){upperHolding = card;}
		BlackCard * getUpperHolding(){return upperHolding;}
		BlackCard * getSubHolding(){return subHolding;}
//		BlackCard * getSubHolding(){return subHolding;9}
};

class CrystalMine : public Holding{
	private:
		BlackCard *subHolding;
	public:
		CrystalMine(string n);
		~CrystalMine(){}
		
        void print(){
			if(isRevealed){
				cout << "***************************" << endl;
				cout << "Card Name:      " << name << endl;
				cout << "Cost:           " << cost << endl;
				cout << "Harvest Value:  " << harvestValue << endl;
				if(subHolding)
					cout << "Sub Holding:    Connected" << endl;
				else
				    cout << "Sub Holding:    Not Connected" << endl;
				cout << "Is Tapped:      " << isTapped << endl;
				cout << "Is Revealed:    " << isRevealed << endl;
				cout << "***************************" << endl << endl;
			}else{
				cout << "***************************" << endl;
				cout << "***************************" << endl;
				cout << "***************************" << endl;
				cout << "***************************" << endl;
				cout << "**********HIDDEN***********" << endl;
				cout << "***************************" << endl;
				cout << "***************************" << endl;
				cout << "***************************" << endl;
				cout << "***************************" << endl;
				cout << "***************************" << endl << endl;
			}
		}
		int getHarvestValue();
		const string Type(){return "Crystal Mine";}
		void setSubHolding(BlackCard *card){subHolding = card;}
		BlackCard * getSubHolding(){return subHolding;}
};

class Farmland : public Holding{
	public:
		Farmland(string n);
		~Farmland(){}
};

class GiftsandFavour : public Holding{
	public:
		GiftsandFavour(string n);
		~GiftsandFavour(){}
};

class StrongHold : public Holding{
	int startingHonour;
	int initialDefence;
	public:
		StrongHold(string n);
		~StrongHold(){}
	void print(){
		cout << "***************************" << endl;
		cout << "Card Name:      " << name << endl;
		cout << "Harvest Value:  " << harvestValue << endl;
		cout << "Staring Honour: " << startingHonour << endl;
		cout << "Initial Defense:" << initialDefence << endl;
		cout << "Is Tapped:      " << isTapped << endl;
		cout << "***************************" << endl << endl;
	}
	int getInitialDefence(){ return initialDefence ;}
};

#endif
