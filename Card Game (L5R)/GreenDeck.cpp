#include "APlayer.hpp"
#include "Card.hpp"

#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <ctime>
#include <cstdlib>

#include "Follower.hpp"
#include "Item.hpp"

#define DECKSIZE      40
#define MAXDECKSIZE   60


#define NO_FOLLOWERS	  28
#define NO_FOOTSOLDIER	   6
#define NO_ARCHER	   6
#define NO_SIEGER	   4
#define NO_CAVALRY	   5
#define NO_NAVAL	   5
#define NO_BUSHIDO	   2

#define NO_ITEMS          12
#define NO_KATANA	   4
#define NO_SPEAR    	   3
#define NO_BOW		   2
#define NO_NINJATO         2
#define NO_WAKIZASHI       1




GreenDeck :: GreenDeck() {
	srand (time(NULL));
	greendeck = new list<GreenCard*>(); //2 parentheseis
	createFateDeck();
}

void GreenDeck :: createFateDeck()
{
	int i; 
	// Followers
	for(i=0;i<NO_FOOTSOLDIER;i++)
		greendeck->push_back(new Footsoldier("Peasants"));
	for(i=0;i<NO_ARCHER;i++)
		greendeck->push_back(new Archer("Elite Troops"));
	for(i=0;i<NO_SIEGER;i++)
		greendeck->push_back(new Sieger("Immortal Bushi"));
	for(i=0;i<NO_CAVALRY;i++)
		greendeck->push_back(new Cavalry("Unicorn Horses"));
	for(i=0;i<NO_NAVAL;i++)
		greendeck->push_back(new Atakebune("Yomi Ships"));
	for(i=0;i<NO_BUSHIDO;i++)
		greendeck->push_back(new Bushido("7 Samurai"));
	// Items
	for(i=0;i<NO_KATANA;i++)
		greendeck->push_back(new Katana("Daijtso"));
	for(i=0;i<NO_BOW;i++)
		greendeck->push_back(new Bow("Yumi"));
    for(i=0;i<NO_SPEAR;i++)
		greendeck->push_back(new Spear("Kama"));
	for(i=0;i<NO_NINJATO;i++)
		greendeck->push_back(new Ninjato("Butterfly Dagger"));
	for(i=0;i<NO_WAKIZASHI;i++)
		greendeck->push_back(new Wakizashi("Kusanagi"));
}

void GreenDeck :: print(){
	list<GreenCard*> ::iterator it;
	for(it = greendeck->begin();it!=greendeck->end();it++)
		(*it)->print();
}


void GreenDeck :: shuffle() {
	vector<GreenCard *> vect;
	list<GreenCard*> ::iterator it;
	for(it = greendeck->begin();it!=greendeck->end();it++)
		vect.push_back((*it));
	random_shuffle ( vect.begin(), vect.end() );
	greendeck->clear();
	vector<GreenCard*>:: iterator it2;
	for(it2 = vect.begin();it2!=vect.end();it2++)
		greendeck->push_back((*it2));
}

GreenCard * GreenDeck :: giveCard() {
	GreenCard * card;
	card=greendeck->back();
	greendeck->pop_back();
	return card;
}
