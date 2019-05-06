#include "Item.hpp"

bool Item :: reduceDurability(){
	durability--;
	if(durability)
	    return false;
	else
	    return true;
}

Katana :: Katana(string n){
	name = n;
	int stats[7];
	readStats("Followers_and_Weapons.txt", "KATANA:", 7, stats);
	cost = stats[0];
	attackBonus = stats[1];
	defenseBonus = stats[2];
	minimumHonour = stats[3];
	effectBonus = stats[4];
	effectCost = stats[5];
	durability = stats[6];
}

Spear :: Spear(string n){
	name = n;
	int stats[7];
	readStats("Followers_and_Weapons.txt", "SPEAR:", 7, stats);
	cost = stats[0];
	attackBonus = stats[1];
	defenseBonus = stats[2];
	minimumHonour = stats[3];
	effectBonus = stats[4];
	effectCost = stats[5];
	durability = stats[6];
}

Bow :: Bow(string n){
	name = n;
	int stats[7];
	readStats("Followers_and_Weapons.txt", "BOW:", 7, stats);
	cost = stats[0];
	attackBonus = stats[1];
	defenseBonus = stats[2];
	minimumHonour = stats[3];
	effectBonus = stats[4];
	effectCost = stats[5];
	durability = stats[6];
}

Ninjato :: Ninjato(string n){
	name = n;
	int stats[7];
	readStats("Followers_and_Weapons.txt", "NINJATO:", 7, stats);
	cost = stats[0];
	attackBonus = stats[1];
	defenseBonus = stats[2];
	minimumHonour = stats[3];
	effectBonus = stats[4];
	effectCost = stats[5];
	durability = stats[6];
}

Wakizashi :: Wakizashi(string n){
	name = n;
	int stats[7];
	readStats("Followers_and_Weapons.txt", "WAKIZASHI:", 7, stats);
	cost = stats[0];
	attackBonus = stats[1];
	defenseBonus = stats[2];
	minimumHonour = stats[3];
	effectBonus = stats[4];
	effectCost = stats[5];
	durability = stats[6];
}

/*
int main(){
	Item *gcard;

	gcard = new Katana("Footsoldier");
	gcard->print();
	gcard = new Spear("Footsoldier");
	gcard->print();
	gcard = new Bow("Footsoldier");
	gcard->print();
	gcard = new Ninjato("Footsoldier");
	gcard->print();
	gcard = new Wakizashi("Footsoldier");
	gcard->print();
}*/
