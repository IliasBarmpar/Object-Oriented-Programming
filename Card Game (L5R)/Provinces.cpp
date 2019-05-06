#include "APlayer.hpp"


Provinces :: Provinces () {
	provinces = new list<BlackCard*>();
	remainingProvinces=4;
	void fillProvinces(BlackDeck blackdeck);
}

void Provinces :: print () {
	cout << "Your provinces hold:"<<endl;
	list<BlackCard*> ::iterator it;
	for(it = provinces->begin();it!=provinces->end();it++)
		(*it)->print();
	cout <<"End of cards in provinces."<<endl<<endl;
}

void Provinces :: revealAll() {
	list<BlackCard*> :: iterator it;
	for(it = provinces->begin();it!=provinces->end();it++)
		(*it)->reveal();
}

void Provinces :: reveal (int pos) {			
	list<BlackCard*> ::iterator it = provinces->begin() ;
	for(int i = 1 ; i < pos ; i ++)
		it++;
	(*it)->reveal();
}

void Provinces :: addCard (int pos , BlackCard *card) {
	list<BlackCard*> ::iterator it = provinces->begin();;
	it = provinces->begin();;
	for(int i=1; i<pos ; i ++)
		it++;
	provinces->insert (it , card);
}
const string Provinces :: getType (int pos) {
	list<BlackCard*> ::iterator it=provinces->begin();
	for(int i=1; i<pos ; i++)
		it++;
	return (*it)->Type();
}

int Provinces :: getCost (int pos) {
	list<BlackCard*> ::iterator it=provinces->begin();
	for(int i=1; i<pos ; i++)
		it++;
	return (*it)->getCost();
}
BlackCard * Provinces :: giveCard(int pos) { // Player gives position from 1 to x
	BlackCard *card;
	list<BlackCard*> ::iterator it = provinces->begin();
	for(int i=1; i < pos ; i ++)
		it++;
	card = *it;
	provinces->erase (it);
	return card;
}

bool Provinces :: empty(){
	if(provinces->empty()) return true;
	else return false;
}

int Provinces :: size(){
	return provinces->size();
}
