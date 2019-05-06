#include "Follower.hpp"

Footsoldier :: Footsoldier(string n){
	name = n;
	int stats[6];
	readStats("Followers_and_Weapons.txt", "FOOTSOLDIER:", 6, stats);
	cost = stats[0];
	attackBonus = stats[1];
	defenseBonus = stats[2];
	minimumHonour = stats[3];
	effectBonus = stats[4];
	effectCost = stats[5];
}

Archer :: Archer(string n){
	name = n;
	int stats[6];
	readStats("Followers_and_Weapons.txt", "ARCHER:", 6, stats);
	cost = stats[0];
	attackBonus = stats[1];
	defenseBonus = stats[2];
	minimumHonour = stats[3];
	effectBonus = stats[4];
	effectCost = stats[5];
}

Cavalry :: Cavalry(string n){
	name = n;
	int stats[6];
	readStats("Followers_and_Weapons.txt", "CAVALRY:", 6, stats);
	cost = stats[0];
	attackBonus = stats[1];
	defenseBonus = stats[2];
	minimumHonour = stats[3];
	effectBonus = stats[4];
	effectCost = stats[5];
}

Bushido :: Bushido(string n){
	name = n;
	int stats[6];
	readStats("Followers_and_Weapons.txt", "BUSHIDO:", 6, stats);
	cost = stats[0];
	attackBonus = stats[1];
	defenseBonus = stats[2];
	minimumHonour = stats[3];
	effectBonus = stats[4];
	effectCost = stats[5];
}

Sieger :: Sieger(string n){
	name = n;
	int stats[6];
	readStats("Followers_and_Weapons.txt", "SIEGER:", 6, stats);
	cost = stats[0];
	attackBonus = stats[1];
	defenseBonus = stats[2];
	minimumHonour = stats[3];
	effectBonus = stats[4];
	effectCost = stats[5];
}

Atakebune :: Atakebune(string n){
	name = n;
	int stats[6];
	readStats("Followers_and_Weapons.txt", "NAVAL:", 6, stats);
	cost = stats[0];
	attackBonus = stats[1];
	defenseBonus = stats[2];
	minimumHonour = stats[3];
	effectBonus = stats[4];
	effectCost = stats[5];
}

/*
int main(){
	Follower *gcard;

	gcard = new Footsoldier("Footsoldier");
	gcard->print();
	gcard = new Archer("Footsoldier");
	gcard->print();
	gcard = new Cavalry("Footsoldier");
	gcard->print();
	gcard = new Bushido("Footsoldier");
	gcard->print();
	gcard = new Sieger("Footsoldier");
	gcard->print();
	gcard = new Atakebune("Footsoldier");
	gcard->print();
}*/

