#include "GameBoard.hpp"

GameBoard :: GameBoard() {
	players = new list<Player *>;
}

void GameBoard :: initializeGameBoard() {
	int plyrs;
	Player *player;
	cout << "How many players there are."<<endl;
	cin >>plyrs;
    while(plyrs<=0||plyrs>=20){
    	cout<<"Choose a valid number for players in the game."<<endl;
    	cin>>plyrs;
    	while(cin.fail()) {
       		cout<<"Give a numerical position."<<endl;
 	    	cin.clear();
       		cin.ignore(256,'\n');
        	cin >> plyrs;
    	}
   	}
   	plysize = plyrs;
	for(int i=1;i<=plyrs;i++){
		player = new Player(i);
		players->push_back(player);
	}
}

void GameBoard :: printGameStatistics() {
	list<Player *> ::iterator it;
	for(it = players->begin();it!=players->end();it++)
		(*it)->printPlayerStatistics();		
}

void GameBoard :: printArena() {
	list<Player *> ::iterator it;
	for(it = players->begin();it!=players->end();it++)
		(*it)->printArmy();		
}

void GameBoard :: gameplay() {
	int End=0 , i=1;
	initializeGameBoard();
	Phases phases;
	Player *player , *secondplayer;
	//dialegw according to honor bla bla bla
	list<Player *> ::iterator it = players->begin();
	player=(*it);
	cout <<"You are player number "<<player->givePos()<<endl;
while(End!=1){
		int armpos[25] , armpos2[25] ,att=0 ,def=0;
		for(int k=0;k<=24;k++) {
			armpos[i]=0;
			armpos2[i]=0;
		}
		phases.startingPhase(player);
		phases.equipPhase(player);
		att =phases.battlePhase(player ,&armpos[0] );
		if(att >0){
			int x =phases.chooseOpponent(player->givePos() , size());
			secondplayer=givePlayer(x);
			int def = phases.opponentDefences(secondplayer,att,&armpos2[0]);
			if(att>def+getInitialDefence(secondplayer)){ //+getInitialDefence(secondplayer)
				phases.clearVictory(player,&armpos[0]);
				phases.clearDefeat(secondplayer);
			}else if(att>def){
				phases.semiWin(player, &armpos[0] , def);
				phases.defeat(secondplayer);
			}else if(att == def){
				phases.defeat(player);
				phases.defeat(player);
			}else if(att < def){
				phases.defeat(player);
				phases.semiWin(secondplayer , &armpos2[0] ,att);
			}
			player->printArmy();
		}
		phases.economyPhase(player);
		phases.endingPhase(player);
	if(i==plysize){
		it = players->begin();
		i=1;
	}else{
		it++;
		i++;
	}
	player=(*it);
	cout<< "You are player number " << player->givePos() <<endl;
}
}

int GameBoard :: size() {
	return players->size();
}
int GameBoard :: getInitialDefence(Player *player){
	return player->getInitialDefence();
}
Player * GameBoard :: givePlayer(int x){
	Player *pl;
	list<Player *> ::iterator it = players->begin();
	for(int i=1; i < x; i++)
		it++;
	pl=(*it);
	return pl;
}
