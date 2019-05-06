#ifndef _FOLLOWER_HPP_
#define _FOLLOWER_HPP_

#include "Card.hpp"

class Follower : public GreenCard{
	public:
		Follower(){}
		virtual ~Follower(){}
		
		virtual void print(){
			cout << "***************************" << endl;
			cout << "Card Name:      " << name << endl;
			cout << "Cost:           " << cost << endl;
			cout << "Attack Bonus:   " << attackBonus << endl;
			cout << "Defense Bonus:  " << defenseBonus << endl;
			cout << "Minimum Honour: " << minimumHonour << endl;
			cout << "Effect Bonus:   " << effectBonus << endl;
			cout << "Effect Cost:    " << effectCost << endl;
			cout << "Is Tapped:      " << isTapped << endl;
			cout << "***************************" << endl << endl;
		}
};

class Footsoldier : public Follower{
	public:
		Footsoldier(string n);
		~Footsoldier(){}
};

class Archer : public Follower{
	public:
		Archer(string n);
		~Archer(){}
};

class Cavalry : public Follower{
	public:
		Cavalry(string n);
		~Cavalry(){}
};

class Bushido : public Follower{
	public:
		Bushido(string n);
		~Bushido(){}
};

class Sieger : public Follower{
	public:
		Sieger(string n);
		~Sieger(){}
};

class Atakebune : public Follower{
	public:
		Atakebune(string n);
		~Atakebune(){}
};

#endif
