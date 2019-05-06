#include "APlayer.hpp"
#include "Card.hpp"

#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <ctime>
#include <cstdlib>

#include "Personality.hpp"
#include "Holding.hpp"

#define DECKSIZE      40
#define MAXDECKSIZE   60

#define NO_PERSONALITIES  25
#define NO_DEFENSIVE	  10
#define NO_ATTACKING	  10
#define NO_SHOGUN 	   2
#define NO_CHANCELLOR	   2
#define NO_CHAMPION	   1

#define NO_HOLDINGS	  17
#define NO_PLAIN	   3
#define NO_MINE		   3
#define NO_GOLD_MINE	   3
#define NO_CRYSTAL_MINE	   3
#define NO_FARMS	   3
#define NO_SOLO		   2

BlackDeck :: BlackDeck() {
	srand (time(NULL));
	blackdeck = new list<BlackCard*>();  
	createDynastyDeck();
}

void BlackDeck :: createDynastyDeck() 
{
	int i;
	//Create Personalities
	//NO_DEFENSIVE 10
	for(i=0;i<NO_DEFENSIVE;i++)
		blackdeck->push_back(new Defender("Footsoldiers"));
	//NO_ATTACKING 10
	for(i=0;i<NO_ATTACKING;i++)
		blackdeck->push_back(new Attacker("Steadfast bushi"));
	//NO_SHOGUN	2
	blackdeck->push_back(new Shogun("Akodo Kaneka"));
	blackdeck->push_back(new Shogun("Isawa Shi en"));
	//NO_CHANCELLOR 2
	blackdeck->push_back(new Chancellor("Hida Shozen"));
	blackdeck->push_back(new Chancellor("Mirimuto Enishi"));
	//NO_CHAMPION 1
	blackdeck->push_back(new Champion("Hida Kisada"));
	//Create holdings
	for(i=0;i<NO_PLAIN;i++)
		blackdeck->push_back(new Plain("Rice Fields"));
	for(i=0;i<NO_FARMS;i++)
		blackdeck->push_back(new Farmland("Fish Farms"));
	for(i=0;i<NO_MINE;i++)
		blackdeck->push_back(new Mine("Ashio Copper Mine"));
	for(i=0;i<NO_GOLD_MINE;i++)
		blackdeck->push_back(new GoldMine("Konomai Gold Mine"));
	for(i=0;i<NO_CRYSTAL_MINE;i++)
		blackdeck->push_back(new CrystalMine("Ichinokawa Crystal Mine"));
	for(i=0;i<NO_SOLO;i++)
		blackdeck->push_back(new GiftsandFavour("Gifts and Favors"));

}

void BlackDeck :: print(){
	list<BlackCard*> ::iterator it;
	for(it = blackdeck->begin();it!=blackdeck->end();it++)
		(*it)->print();
}

void BlackDeck :: shuffle() {
	vector<BlackCard *> vect;
	list<BlackCard*> ::iterator it;
	for(it = blackdeck->begin();it!=blackdeck->end();it++)
		vect.push_back((*it));

	random_shuffle ( vect.begin(), vect.end() );

	blackdeck->clear();

	vector<BlackCard*>:: iterator it2;
	for(it2 = vect.begin();it2!=vect.end();it2++)
		blackdeck->push_back((*it2));
}

BlackCard * BlackDeck :: giveCard() {
	BlackCard * card;
	card=blackdeck->back();
	blackdeck->pop_back();
	return card;
}
