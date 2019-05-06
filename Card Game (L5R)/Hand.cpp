#include "APlayer.hpp"
#include <ctime>


Hand :: Hand() {
	hand = new list<GreenCard*>;
}

void Hand :: print() {
	cout << "Your hand has the following cards in it:"<<endl;
	list<GreenCard*> ::iterator it;
	for(it = hand->begin();it!=hand->end();it++)
		(*it)->print();
	cout << "End of cards in your hand."<<endl<<endl;
}

void Hand :: addCard(GreenCard *card) {
	hand->push_back(card);
}

int Hand :: getCost(int pos){
	list<GreenCard*> ::iterator it=hand->begin();
	for(int i = 1 ; i < pos ; i++)
		it++;
	return (*it)->getCost();
}

int Hand :: getMinimumHonour(int pos){
	list<GreenCard*> ::iterator it=hand->begin();
	for(int i = 1 ; i < pos ; i++)
		it++;
	return (*it)->getMinimumHonour();
}

int Hand :: getEffectCost(int pos){
	list<GreenCard*> ::iterator it=hand->begin();
	for(int i = 1 ; i < pos ; i++)
		it++;
	return (*it)->getEffectCost();
}

bool Hand :: getBonusActivated(int pos){
	list<GreenCard*> ::iterator it=hand->begin();
	for(int i = 1 ; i < pos ; i++)
		it++;
	return (*it)->getBonusActivated();
}

void Hand :: activateBonus(int pos){
	list<GreenCard*> ::iterator it=hand->begin();
	for(int i = 1 ; i < pos ; i++)
		it++;
	(*it)->activateBonus();
}

GreenCard * Hand :: giveCard(int pos) { // Player gives position from 1 to x
	int i;
	GreenCard *card;
	list<GreenCard*> ::iterator it = hand->begin();;
	for(i=1; i < pos ; i ++)
		it++;
	card = *it;
	hand->erase (it);
	return card;
}

void Hand :: removeCard(int pos) {
	list<GreenCard*> ::iterator it = hand->begin();;
	for(int i=1; i < pos ; i ++)
		it++;
	hand->erase (it);
}

int Hand :: size() {
	return hand->size();
}

bool Hand :: empty(){
	if(hand->empty()) return true;
	else return false;
}
