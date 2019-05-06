#include "Personality.hpp"
#include "Follower.hpp" //Must be included when debugging with the main in this file

Personality :: Personality(){
	isDead = false;
	helpingCards = new vector<GreenCard*>();
}

Personality :: ~Personality(){
	vector<GreenCard*> ::const_iterator it;
	for(it = helpingCards->begin();it!=helpingCards->end();++it)
		delete (*it);
}

void Personality :: print(){
	if(isRevealed){
		cout << "***************************" << endl;
		cout << "Card Name:      " << name << endl;
		cout << "Cost:           " << cost << endl;
		cout << "Attack:         " << attack << endl;
		cout << "Defense         " << defense << endl;
		cout << "Honour:         " << honour << endl;
		cout << "Is Tapped:      " << isTapped << endl;
		cout << "Is Revealed:    " << isRevealed << endl;
		cout << "Is Dead:        " << isDead << endl;
		cout << "***************************" << endl << endl;
		
		//Printing the cards attached to the personality
		vector<GreenCard*> :: const_iterator it;
		if(!helpingCards->empty()){
			cout << "This Personality has the following cards added to him:" << endl;
			for(it = helpingCards->begin();it!=helpingCards->end();++it){
				(*it)->print();
			}
			cout << "End of Added Cards" << endl;
		}

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

int Personality :: getAttack(){
	int a = attack;
	//AttackBonus must be added
	vector<GreenCard*> :: const_iterator it;
	for(it=helpingCards->begin();it!=helpingCards->end();++it){
		if((*it)->getBonusActivated())
			a += (*it)->getAttackBonus() + (*it)->getEffectBonus();
		else
		    a += (*it)->getAttackBonus();
	}
	return a;
}

int Personality :: getDefense(){
	int d = defense;
	//DefenseBonus must be added
	vector<GreenCard*> :: const_iterator it;
	for(it=helpingCards->begin();it!=helpingCards->end();++it)
	    if((*it)->getBonusActivated())
			d += (*it)->getDefenseBonus()+ (*it)->getEffectBonus();
		else
		    d += (*it)->getDefenseBonus();

	return d;
}

void Personality :: addHelpingCard(GreenCard *gc){
	helpingCards->push_back(gc);
}

int Personality :: followerSize(){
	return helpingCards->size();
}
int Personality :: getHelpingCardsAttack(int pos){
	int a=0;
	vector<GreenCard*> :: iterator it = helpingCards->begin();
	for(int i; i<pos; i++)
		it++;
	if((*it)->getBonusActivated())
		a =(*it)->getAttackBonus() + (*it)->getEffectBonus();
	else
	    a =(*it)->getAttackBonus();
	return a;
}

GreenCard* Personality :: removeHelpingCard(int pos){
	GreenCard *card;
	vector<GreenCard*> :: iterator it = helpingCards->begin();

    for(int i; i<pos; i++)
		it++;
	card = *it;
	helpingCards->erase(it);
 	return card;
}

bool Personality :: reduceHonour(){
	honour--;
	if(honour)
		return false;
	else
	    return (isDead=true);
}



Attacker :: Attacker(string n){
	name = n;
	int stats[4];
	readStats("Personalities_and_Holdings.txt", "ATTACKER:", 4, stats);
	cost = stats[0];
	attack = stats[1];
	defense = stats[2];
	honour = stats[3];
}

Defender :: Defender(string n){
	name = n;
	int stats[4];
	readStats("Personalities_and_Holdings.txt", "DEFENDER:", 4, stats);
	cost = stats[0];
	attack = stats[1];
	defense = stats[2];
	honour = stats[3];
}

Shogun :: Shogun(string n){
	name = n;
	int stats[4];
	readStats("Personalities_and_Holdings.txt", "SHOGUN:", 4, stats);
	cost = stats[0];
	attack = stats[1];
	defense = stats[2];
	honour = stats[3];
}

Chancellor :: Chancellor(string n){
	name = n;
	int stats[4];
	readStats("Personalities_and_Holdings.txt", "CHANCELLOR:", 4, stats);
	cost = stats[0];
	attack = stats[1];
	defense = stats[2];
	honour = stats[3];
}

Champion :: Champion(string n){
	name = n;
	int stats[4];
	readStats("Personalities_and_Holdings.txt", "CHAMPION:", 4, stats);
	cost = stats[0];
	attack = stats[1];
	defense = stats[2];
	honour = stats[3];
}


/*int main(){

	Personality *bcard;

	bcard = new Attacker("Footsoldier");
	bcard->print();
	bcard = new Defender("Footsoldier");
	bcard->print();
	bcard = new Champion("Footsoldier");
	bcard->print();
	bcard = new Chancellor("Footsoldier");
	bcard->print();
	bcard = new Shogun("Shogun");
	bcard->print();
	
	GreenCard *card = new Footsoldier("Additional");

	bcard->addHelpingCard(card);
	bcard-> print();
		
	cout << bcard->getAttack();


	bcard->removeHelpingCard(1);
			bcard->print();
			
	bcard -> print();
	
int i;
cin >> i;
}*/
