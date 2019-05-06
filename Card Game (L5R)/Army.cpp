#include "APlayer.hpp"


void Army :: print() {
	cout << "Your army consists of:"<<endl;
	list<BlackCard *> ::iterator it;
	for(it = army->begin();it!=army->end();it++)
		(*it)->print();
	cout << "End of cards in your army."<<endl<<endl;
}

void Army :: untapEverything(){
	list<BlackCard *> ::iterator it;
	for(it = army->begin();it!=army->end();it++)
		(*it)->untap();
	
}

void Army :: addCard(BlackCard *card) {
	army->push_back(card);
}

void Army :: addHelpingCard(GreenCard *card , int pos) {
	list<BlackCard *> ::iterator it = army->begin();
	for(int i=1 ;i < pos ; i++)
		it++;				
	(*it)->addHelpingCard(card);
}

BlackCard * Army :: giveCard(int pos){
	BlackCard *card;
	list<BlackCard *> ::iterator it = army->begin();
	for(int i=1 ;i <pos ; i++)
		it++;
	card= (*it);
	army->erase (it);
	return card; 
}

int Army :: getAttack(int pos) {
	list<BlackCard*> ::iterator it=army->begin();
	for(int i=1; i<pos ; i++)
		it++;
	return (*it)->getAttack();
}

int Army :: getDef(int pos) {
	list<BlackCard*> ::iterator it=army->begin();
	for(int i=1; i<pos ; i++)
		it++;
	return (*it)->getDefense();
}

int Army :: getHonour(int pos) {
	list<BlackCard*> ::iterator it=army->begin();
	for(int i=1; i<pos ; i++)
		it++;
	return (*it)->getHonour();
}

int Army :: getIsTapped(int pos) {
	list<BlackCard*> ::iterator it=army->begin();
	for(int i=1; i<pos ; i++)
		it++;
	return (*it)->getIsTapped();
}

int Army :: getIsDead(int pos) {
	list<BlackCard*> ::iterator it=army->begin();
	for(int i=1; i<pos ; i++)
		it++;
	return (*it)->getIsDead();
}

void Army :: reduceHonour(int pos) {
	list<BlackCard*> ::iterator it=army->begin();
	for(int i=1; i<pos ; i++)
		it++;
	(*it)->reduceHonour();
}

void Army :: tapCard(int pos){
	list<BlackCard *> ::iterator it = army->begin();
	for(int i=1 ;i < pos ; i++)
		it++;
	(*it)->tap();
}

void Army :: untapCard(int pos){
	list<BlackCard *> ::iterator it = army->begin();
	for(int i=1 ;i < pos ; i++)
		it++;
	(*it)->untap();
}

void Army::reveal(int pos ){
	list<BlackCard *> ::iterator it = army->begin();
	for(int i=1 ;i < pos ; i++)
		it++;
	(*it)->reveal();
} 
void Army :: removeCard(int pos){
	list<BlackCard *> ::iterator it = army->begin();
	for(int i=1 ;i < pos ; i++)
		it++;
	army->erase (it);
}

bool Army :: empty(){
	if(army->empty()) return true;
	else return false;
}

int Army :: size(){
	return army->size();
}
void Army :: printPersonality(int pos){
	list<BlackCard *> ::iterator it = army->begin();
	for(int i=1 ;i < pos ; i++)
		it++;
	(*it)->print();
}
int Army :: followerSize(int pos){
	list<BlackCard *> ::iterator it = army->begin();
	for(int i=1 ;i < pos ; i++)
		it++;
	return (*it)->followerSize();
}
int Army ::allFollowerSize(){
	int afs=0;
	list<BlackCard *> ::iterator it;
	for(it = army->begin();it!=army->end();it++)
		afs += (*it)->followerSize();
	return afs;
}
int Army :: getHelpingCardsAttack(int pos ,int gcpos){
	list<BlackCard *> ::iterator it = army->begin();
	for(int i=1 ;i < pos ; i++)
		it++;
	return (*it)->getHelpingCardsAttack(gcpos);
}

int Army :: findPrevFollowerSize(int pos){
	int fpfs=0;
	list<BlackCard *> ::iterator it = army->begin();
	for(int i=1 ;i <= pos ; i++){
		it++;
		fpfs += (*it)->followerSize();
	}
	return fpfs;
}
void Army :: removeHelpingCard(int pos , int gcpos){
	list<BlackCard *> ::iterator it = army->begin();
	for(int i=1 ;i < pos ; i++)
		it++;
	(*it)->removeHelpingCard(gcpos);
}
int Army :: findMySize(int pos){
	int fMS=0 , wantedpos=0;
	list<BlackCard *> ::iterator it ;
	for(it = army->begin();it!=army->end();it++){
		wantedpos++;
		fMS += (*it)->followerSize();
		if(fMS>=pos)
			return wantedpos;
	}
	return -1;
}
