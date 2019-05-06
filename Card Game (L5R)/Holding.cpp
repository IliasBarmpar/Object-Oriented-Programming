#include "Holding.hpp"

Plain :: Plain(string n){
	name = n;
	int stats[2];
	readStats("Personalities_and_Holdings.txt", "PLAIN:", 2, stats);
	cost = stats[0];
	harvestValue = stats[1];
}

Mine :: Mine(string n){
	name = n;
	upperHolding = NULL;
	int stats[2];
	readStats("Personalities_and_Holdings.txt", "MINE:", 2, stats);
	cost = stats[0];
	harvestValue = stats[1];
}
int Mine :: getHarvestValue(){
	if(upperHolding)
		return harvestValue+2;
	else
	    return harvestValue;
}

GoldMine :: GoldMine(string n){
	name = n;
	upperHolding = NULL;
	subHolding = NULL;
	int stats[2];
	readStats("Personalities_and_Holdings.txt", "GOLD_MINE:", 2, stats);
	cost = stats[0];
	harvestValue = stats[1];
}
int GoldMine :: getHarvestValue(){
	if(upperHolding && subHolding)
		return harvestValue*3;
	else if(subHolding)
	    return harvestValue+4;
	else if(upperHolding)
	    return harvestValue+5;
	else
	    return harvestValue;
}
bool GoldMine :: chainComplete(){
	if(subHolding && upperHolding)
	    return true;
	else
	    return false;
}

CrystalMine :: CrystalMine(string n){
	name = n;
	subHolding = NULL;
	int stats[2];
	readStats("Personalities_and_Holdings.txt", "CRYSTAL_MINE:", 2, stats);
	cost = stats[0];
	harvestValue = stats[1];
}

int CrystalMine :: getHarvestValue(){
	if(subHolding){
		if(subHolding->chainComplete())
		    return harvestValue*4;
		return harvestValue*2;
	}
	return harvestValue;
}

Farmland :: Farmland(string n){
	name = n;
	int stats[2];
	readStats("Personalities_and_Holdings.txt", "FARMS:", 2, stats);
	cost = stats[0];
	harvestValue = stats[1];
}

GiftsandFavour :: GiftsandFavour(string n){
	name = n;
	int stats[2];
	readStats("Personalities_and_Holdings.txt", "SOLO:", 2, stats);
	cost = stats[0];
	harvestValue = stats[1];
}


StrongHold :: StrongHold(string n){
	name = n;
	isRevealed = true;
	int stats[3];
	readStats("Personalities_and_Holdings.txt", "STRONGHOLD:", 3, stats);
	startingHonour = stats[0];
	harvestValue = stats[1];
	initialDefence = stats[2];
}

/*
int main(){
//	Holding *bcard;
//
//	bcard = new Plain("Footsoldier");
//	bcard->print();
//	bcard = new Mine("Footsoldier");
//	bcard->print();
//	bcard = new GoldMine("Footsoldier");
//	bcard->print();
//	bcard = new CrystalMine("Footsoldier");
//	bcard->print();
//	bcard = new Farmland("Footsoldier");
//	bcard->print();
//	bcard = new GiftsandFavour("Footsoldier");
//	bcard->print();
//	bcard = new StrongHold("StrongHold");
//	bcard->print();
	
	BlackCard *card1, *card2, *card3 ,*card4;
	card1 = new Mine("Mine");
	card2 = new GoldMine("GoldMine");
	card3 = new CrystalMine("CrystalMine");
	card4 = new Farmland("FarmL");
	card1->setUpperHolding(card2);
	card2->setSubHolding(card1);
	Holdings
	card2->setUpperHolding(card3);
	card3->setSubHolding(card2);
	
	card1->print();
	card2->print();
	card3->print();
//	cout << card1->getHarvestValue() << " "<< card2->getHarvestValue() << " "<< card3->getHarvestValue() << endl;
int i;

	
}*/
