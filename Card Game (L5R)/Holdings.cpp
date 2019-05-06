#include "APlayer.hpp"

Holdings :: Holdings() {
	holdings = new list<BlackCard*>;
	BlackCard *card;
	card = new StrongHold("Stronghold");
	holdings->push_back(card);
}
int Holdings :: getInitialDefence(){
	list<BlackCard*> ::iterator it=holdings->begin();
	return (*it)->getInitialDefence();
}
void Holdings :: print() {
	cout <<"Your holdings are:"<<endl;
	list<BlackCard*> ::iterator it;
	for(it = holdings->begin();it!=holdings->end();it++)
		(*it)->print();
	cout <<"End of cards in your holdings."<<endl<<endl;
}

void Holdings :: untapEverything(){
	list<BlackCard *> ::iterator it;
	for(it = holdings->begin();it!=holdings->end();it++)
		(*it)->untap();
}

void Holdings :: addCard(BlackCard *card) {
	holdings->push_back(card);
	if(card->Type()=="Mine") checkUpperGoldMines(card);
	else if(card->Type()=="Gold Mine") {
		checkMines(card) ; 
		checkCrystalMines(card);}
	else if(card->Type()=="Crystal Mine") checkSubGoldMines(card);
	
}

void Holdings :: checkUpperGoldMines(BlackCard *mine) {
	list<BlackCard *> ::iterator it;
	for(it = holdings->begin();it!=holdings->end();it++){
		if((*it)->Type()=="Gold Mine"){
			if(!(*it)->getSubHolding()){
				(*it)->setSubHolding(mine);
				mine->setUpperHolding(*it);
			}
		}
	}
}
void Holdings :: checkMines(BlackCard *goldmine) {
	list<BlackCard *> ::iterator it;
	for(it = holdings->begin();it!=holdings->end();it++){
		if((*it)->Type()=="Mine"){
			if(!(*it)->getUpperHolding()){
				(*it)->setUpperHolding(goldmine);
				goldmine->setSubHolding(*it);
			}
		}
	}
}

void Holdings :: checkCrystalMines(BlackCard *goldmine) {
	list<BlackCard *> ::iterator it;
	for(it = holdings->begin();it!=holdings->end();it++){
		if((*it)->Type()=="Crystal Mine"){
			if(!(*it)->getSubHolding()){
				(*it)->setSubHolding(goldmine);
				goldmine->setUpperHolding(*it);
			}
		}
	}
}

void Holdings :: checkSubGoldMines(BlackCard *crystalmine) {
	list<BlackCard *> ::iterator it;
	for(it = holdings->begin();it!=holdings->end();it++){
		if((*it)->Type()=="Gold Mine"){
			if(!(*it)->getUpperHolding()){
				(*it)->setUpperHolding(crystalmine);
				crystalmine->setSubHolding(*it);
			}
		}
	}
}

void Holdings :: tapCard(int pos) {
	list<BlackCard*> ::iterator it=holdings->begin();
	for(int i=1; i<pos ; i++)
		it++;
	(*it)->tap();
}

void Holdings :: untapCard(int pos) {
	list<BlackCard*> ::iterator it=holdings->begin();
	for(int i=1; i<pos ; i++)
		it++;
	(*it)->untap();
}
int Holdings :: getHarvestValue(int pos) {
	list<BlackCard*> ::iterator it=holdings->begin();
	for(int i=1; i<pos ; i++)
		it++;
	return (*it)->getHarvestValue();
}

int Holdings :: getIsTapped(int pos) {
	list<BlackCard*> ::iterator it=holdings->begin();
	for(int i=1; i<pos ; i++)
		it++;
	return (*it)->getIsTapped();
}

int Holdings :: size() {
	return holdings->size();
}
