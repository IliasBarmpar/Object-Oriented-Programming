#ifndef _PERSONALITY_HPP_
#define _PERSONALITY_HPP_

#include "Card.hpp"

#include <vector>

class Personality : public BlackCard{
	protected:
		int attack;
		int defense;
		int honour;
		bool isDead;
		vector <GreenCard*> *helpingCards;
	public:
		Personality();
		virtual ~Personality();

		void print(); //The printer of Personality prints everything attached to it too
		int getAttack(); //It calculates attackbonuses too
		int getDefense(); //Same
		int getHonour(){return honour;}
		bool getIsDead(){return isDead;}
		
		bool reduceHonour();    //If Honour==0 then it returns true
		
		void addHelpingCard(GreenCard * gc);
		GreenCard* removeHelpingCard(int pos);  //pos starts from 1
		int getHelpingCardsAttack(int pos);
		int followerSize();
		const string Type() {return "Personality";}
};

class Attacker : public Personality{
	public:
		Attacker(string n);
		~Attacker(){}
};

class Defender : public Personality{
	public:
		Defender(string n);
		~Defender(){}
};

class Champion : public Personality{
	public:
		Champion(string n);
		~Champion(){}
};

class Chancellor : public Personality{
	public:
		Chancellor(string n);
		~Chancellor(){}
};

class Shogun : public Personality{
	public:
		Shogun(string n);
		~Shogun(){}
};

#endif
