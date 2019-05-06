#ifndef _ITEM_HPP_
#define _ITEM_HPP_

#include "Card.hpp"

class Item : public GreenCard{
	protected:
		int durability;
	public:
		Item(){}
		virtual ~Item(){}
		
		virtual void print(){
			cout << "***************************" << endl;
			cout << "Card Name:      " << name << endl;
			cout << "Cost:           " << cost << endl;
			cout << "Attack Bonus:   " << attackBonus << endl;
			cout << "Defense Bonus:  " << defenseBonus << endl;
			cout << "Minimum Honour: " << minimumHonour << endl;
			cout << "Effect Bonus:   " << effectBonus << endl;
			cout << "Effect Cost:    " << effectCost << endl;
			cout << "Durability:     " << durability << endl;
			cout << "Is Tapped:      " << isTapped << endl;
			cout << "***************************" << endl << endl;
		}
		int getDurability(){return durability;}
		
		bool reduceDurability();    //If the item is broken (durability==0) it return true
};

class Katana : public Item{
	public:
		Katana(string n);
		~Katana(){}
};

class Spear : public Item{
	public:
		Spear(string n);
		~Spear(){}
};

class Bow : public Item{
	public:
		Bow(string n);
		~Bow(){}
};

class Ninjato : public Item{
	public:
		Ninjato(string n);
		~Ninjato(){}
};

class Wakizashi : public Item{
	public:
		Wakizashi(string n);
		~Wakizashi(){}
};

#endif
