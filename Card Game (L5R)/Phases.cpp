#include "Phases.hpp"
#include <string>
void Phases :: startingPhase(Player *player){
	cout <<"Starting Phase !"<<endl;
	hand = player->giveHand();
	provinces = player->giveProvinces();
	greendeck = player->giveGreenDeck();//replace me sunartisi pou dinei greencard opwsdipote
	army = player->giveArmy();
	holdings= player->giveHoldings();
	
	army.untapEverything();			//
	holdings.untapEverything();		// mporei na ginoun replace me sunartish tou player
	hand.addCard(greendeck.giveCard());
	provinces.revealAll();
	cout <<"Starting Phase ended."<<endl;
}
	
	
///////////////////////////////////////////////////////////////

	
	
void Phases :: equipPhase(Player *player){
	cout <<"Equip Phase !"<<endl;
	hand = player->giveHand();
	army = player->giveArmy();
	holdings = player->giveHoldings();
	if(army.empty()){
		cout << "You army is empty , you can't buy cards from your hand." <<endl;
	}else{
		string done;
		do{	
			string buy;
			cout << "Do you want to buy a card from your hand? Y/N."<<endl;
			cin >> buy;
			while(buy!="Y"&&buy!="y"&&buy!="N"&&buy!="n"){
				cout << "Answer with Y/y for yes or N/n for no."<<endl;
				cin >> buy;
			}
			if(buy=="Y"||buy=="y"){
				army.print();
				int armpos , hpos, i=0 , pos , sum=0 ,End=0 , holpos[10] ;
				string YN , CS;
				bool honor , cost;
				for(int j=0;j<=9;j++) holpos[j]=0;
				cout <<"Give the position of the personality you want to equip."<<endl;
   				cin >>armpos;
    			while(armpos>army.size()||armpos<=0){
    				cout<<"Choose a number according to the size of your army"<<endl;
    				cin>>armpos;
    				while(cin.fail()) {
       					cout<<"Give a numerical position."<<endl;
 	     				cin.clear();
        				cin.ignore(256,'\n');
       		 		cin >> armpos;
    				}
    			}
    			hand.print();
				cout << "Give the position of the card in your hand you want to equip."<<endl;
    			cin >>hpos;
    			while(hpos>hand.size()||hpos<=0){
    				cout<<"Choose a number according to the size of your hand"<<endl;
    				cin>>hpos;
    				while(cin.fail()) {
      					cout<<"Give a numerical position."<<endl;
	     				cin.clear();
						cin.ignore(256,'\n');
        				cin >>hpos;
    				}
    			}	
				if(army.getHonour(armpos)>=hand.getMinimumHonour(hpos)) honor = true;
				else honor = false;	
				if(honor == true){
					cout << "Do you want to upgrade?  Y/N "<<endl;
					cin >> YN; 
					while (!(YN=="Y"||YN=="y"||YN=="N"||YN=="n")){
						cout <<"Answer with Y for yes or N for no"<<endl;
						cin >> YN;
					}

					if(hand.getCost(hpos)!=0 || YN=="Y" || YN=="y"){
					holdings.print();
					cout << "Now , choose your holdings."<<endl;
					
						while(End!=1){
							int failedTr=0;
							cout << "Type C to continue , or S to stop"<<endl;
							cin >> CS;
							if(CS=="C"||CS=="c")	{
								cout << "Which holding you want to tap?" << endl;
								cin >>pos;
    							while(pos>holdings.size()||pos<=0){
    								cout<<"Choose a number according to the size of your holdings"<<endl;
    								cin>>pos;
    								while(cin.fail()) {
       								cout<<"Give a numerical position."<<endl;
 	   	  							cin.clear();
     		   						cin.ignore(256,'\n');
       	 							cin >> pos;
    								}
    							}
								if(holdings.getIsTapped(pos)){
								cout << "This holding is tapped." << endl;
								}else{
									for(int l=0;l<=9;l++) 
									if(pos==holpos[l]){
										cout<< "You've already chosen that holding for the same transaction." <<endl;
										failedTr=1;
									}
									if(failedTr!=1){
										sum+=holdings.getHarvestValue(pos);
										holpos[i]=pos;
										i++;
									}
								}
							}
							else if(CS=="S"||CS=="s") End=1;	
							else cout << "Wrong Answer." << endl;
						}	
						if(YN=="Y"||YN=="y"){
							if(sum>=hand.getEffectCost(hpos)) cost = true;
							else cost = false;
						}else if(YN=="N"||YN=="n"){
							if(sum>=hand.getCost(hpos)) cost = true;
							else cost = false;
						}
					}else if(YN=="N"||YN=="n"){
						cost = true;
					}
					if( cost) {
						for(i=0;i<=9;i++) 
							if(holpos[i]>0)
								holdings.tapCard(holpos[i]);
						if(YN=="Y"||YN=="y"){
							hand.activateBonus(hpos);
						}
						army.addHelpingCard(hand.giveCard(hpos) , armpos);
						cout << "Transaction Complete" <<endl;
 					}else{
 						cout << "Not enough harvestValue to buy the card" << endl;
 					}
 				}else {
 					cout << "Not enough honor to buy the card" << endl;
 				}
			}
			cout << "Are you done with Equip Phase? Y/N"<<endl;
			cin>> done;
			while(done!="Y"&&done!="y"&&done!="N"&&done!="n"){
				cout << "Answer with Y/y for yes or N/n for no."<<endl;
				cin >> done;
			}
		}while(!(done=="Y"||done=="y"));
	}
	cout <<"Equip Phase ended."<<endl;
}



////////////////////////////////////////////////////////////////////////////////////////////
int Phases :: battlePhase(Player *player , int * armpos){
	cout <<"Battle Phase !"<<endl;
	army = player->giveArmy();
	if(army.empty()){
		cout << "You don't have an army to go to battle."<<endl;
	}else{
		string battle;
		cout << "Do you want to go to battle? Y/N."<<endl;
		cin >> battle;
		while(battle!="Y"&&battle!="y"&&battle!="N"&&battle!="n"){
			cout << "Answer with Y/y for yes or N/n for no."<<endl;
			cin >> battle;
		}
		if(battle=="Y"||battle=="y"){
			int i=0 ,pos ,End=0 , sum=0;//armpos[25]
			string CS;
//			for(int j=0;j<=25;j++) armpos[j]=0;
			army.print();
			cout <<"Now choose the personalities you want to battle with."<<endl;
			while(End!=1){
				int failedPr=0;
				cout << "Type C to continue , or S to stop."<<endl;
				cin >> CS;
				if(CS=="C"||CS=="c"){
					cout << "Which personality you want?"<<endl;
    				cin >>pos;
    				while(pos>army.size()||pos<=0){
    					cout<<"Choose a number according to your army size."<<endl;
    					cin>>pos;
    					while(cin.fail()) {
     			 			cout<<"Give a numerical position."<<endl;
				     		cin.clear();
							cin.ignore(256,'\n');
 				       		cin >>pos;
    					}
    				}
					if(army.getIsTapped(pos)){
						cout << "This personality is tapped." << endl;
					}else{
						for(int l=0;l<=25;l++) 
							if(pos==armpos[l]){
								cout<< "This personality already agreed to battle." <<endl;
								failedPr=1;
							}
						if(failedPr!=1){
							sum=sum + army.getAttack(pos);
							armpos[i]=pos;
							i++;
						}
					}
				}
				else if(CS=="S"||CS=="s") End=1;	
				else cout << "Wrong Answer." << endl;
			}
			return sum;
		}
	}
	return 0;
}

int Phases :: chooseOpponent(int plpos,int oppsize){
	int pos;
	cout << "Choose which opponent you want to battle with."<<endl;
	cin >>pos;
	while(pos>oppsize||pos<=0||pos==plpos){
   		if(pos==plpos){
   		  	cout<< "You can't choose yourself as an opponent."<<endl;
   		}else{
   			cout<<"Choose a number according to your existing opponents."<<endl;
   		}
   		cin>>pos;
    	while(cin.fail()) {
     		cout<<"Give a numerical position."<<endl;
 			cin.clear();
			cin.ignore(256,'\n');
		  	cin >>pos;
   		}
	}
}

int Phases :: opponentDefences(Player *player , int att , int *armpos){
	army = player->giveArmy(); 
	cout <<"You are getting attacked !"<<endl;
	cout <<"Your opponent has strenght equal to " << att << " points." <<endl;
	if(army.empty()){
					cout << "You don't have an army to defend with."<<endl;
				}else{
					string battle;
					cout << "Do you want to go to defend this battle? Y/N."<<endl;
					cin >> battle;
					while(battle!="Y"&&battle!="y"&&battle!="N"&&battle!="n"){
						cout << "Answer with Y/y for yes or N/n for no."<<endl;
						cin >> battle;
					}
					if(battle=="Y"||battle=="y"){
						int i=0 ,pos ,End=0 , sum2=0 ;
						string CS;
						army.print();
						cout <<"Now choose the personalities you want to defend with."<<endl;
						while(End!=1){
							int failedPr=0;
							cout << "Type C to continue , or S to stop."<<endl;
							cin >> CS;
							if(CS=="C"||CS=="c"){
								cout <<"Choose the personality you want"<<endl;
    							cin >>pos;
    							while(pos>army.size()||pos<=0){
    								cout<<"Choose a number according to your army size."<<endl;
    								cin>>pos;
    								while(cin.fail()) {
     			 						cout<<"Give a numerical position."<<endl;
				     					cin.clear();
										cin.ignore(256,'\n');
 				  			     		cin >>pos;
    								}
    							}
								if(army.getIsTapped(pos)){
									cout << "This personality is tapped." << endl;
								}else{
									for(int l=0;l<=25;l++) 
										if(pos==armpos[l]){
											cout<< "This personality already agreed to defend." <<endl;
											failedPr=1;
										}
									if(failedPr!=1){
										sum2+=army.getAttack(pos);
										armpos[i]=pos;
										i++;
									}
								}
							}
							else if(CS=="S"||CS=="s") End=1;	
							else cout << "Wrong Answer." << endl;
						}
						return sum2;
}
}return 0;
}

void Phases :: clearVictory(Player *player ,int *armpos ){
	army = player->giveArmy();
	for(int i=0;i<=24;i++)
		if(armpos[i]>0)
			army.tapCard(armpos[i]);
}

void Phases :: semiWin(Player *player, int * armpos , int ad ){
	army = player->giveArmy();
	cout <<"You will have to remove followers and or personalities to match the defenders defence."<<endl;
	army.print();
	cout <<"Now choose the followers and or personalities you want to kill."<<endl;
	int End=0;
	while(End!=1){
		int i=0 ,pos , sum=0;
		int folpos[40];
		for(int j=0;j<=39;j++) folpos[j]=0;
		int armypos[25];
		for(int u=0;u<=24;u++) armypos[u]=0;
		string CS;
		int End2=0 ,End3=0;
		cout << "Type C to continue or S to stop , the killings."<<endl;
		cin >> CS;
		if(CS=="C"||CS=="c"){///////////////////
			string fp;
			cout <<"Do you want to kill a follower or a personality? F/P."<<endl;
			cin >> fp;
			while(fp!="F"&&fp!="f"&&fp!="P"&&fp!="p"){
				cout << "Answer with F/f for follower or P/p for personality."<<endl;
				cin >> fp;
			}
			
			// 1
			if(fp=="f"||fp=="F"){
				army.print();
				cout << "Time to choose the follower you want to kill."<<endl;
				while(End2!=1){
					int failedPr2=0 , fail=0;
					cout << "Type C to continue , or S to stop."<<endl;
					cin >> CS;
					if(CS=="C"||CS=="c"){
						cout << "Choose which personality has the follower you want to kill."<<endl;
						cin >>pos;
						
						while(army.getIsTapped(pos)){
							if(army.getIsTapped(pos)){
								cout<<"This personality is already tapped."<<endl;
							}else{
    							while(pos>army.size()||pos<=0){
    								cout<<"Choose a number according to the army  size."<<endl;
    								cin>>pos;
    								while(cin.fail()) {
     									cout<<"Give a numerical position."<<endl;
									   	cin.clear();
										cin.ignore(256,'\n');
 									    cin >>pos;
    								}
    							}	
    						}
						}
						for(int l=1;l<=39;l++)
							if(pos==armypos[l]){
									cout<<"This personality is already dying."<<endl;
									fail=1;
							}
							if(fail!=1){
	    					int fpos;
    						cout <<"Choose the follower you want to kill.(Addup the followers from personality to personality to get the position you want)"<<endl;
    						cin >>fpos;
    						while(fpos>army.allFollowerSize()||fpos<=0){
    							cout<<"Choose a number according to the followers size."<<endl;
    							cin>>fpos;
    							while(cin.fail()){
     								cout<<"Give a numerical position."<<endl;
								   	cin.clear();
									cin.ignore(256,'\n');
 								    cin >>fpos;
    							}
    						}
							for(int l=0;l<=39;l++)
								if(pos==folpos[l]){
									cout<< "This follower was already chosen." <<endl;
									failedPr2=1;
								}
							if(failedPr2!=1){
								sum+=army.getHelpingCardsAttack(pos , fpos);
								folpos[i]=fpos;
								i++;
							}
						}
					}else if(CS=="S"||CS=="s") End2=1;	
					else cout << "Wrong Answer." << endl;
				}
			}else if(fp=="p"||fp=="P"){
				army.print();
				cout <<"Now choose the personalities you want to kill."<<endl;
				while(End3!=1){
					int failedPr3=0 , topbarrier=0 , botbarrier=0;
					cout << "Type C to continue , or S to stop."<<endl;
					cin >> CS;
					if(CS=="C"||CS=="c"){
						cout << "Which personality you want?"<<endl;
    					cin >>pos;
    					while(pos>army.size()||pos<=0){
    						cout<<"Choose a number according to your army size."<<endl;
    						cin>>pos;
    						while(cin.fail()) {
     				 			cout<<"Give a numerical position."<<endl;
				  		   		cin.clear();
								cin.ignore(256,'\n');
 				       			cin >>pos;
    						}
    					}
						if(army.getIsTapped(pos)){
						cout << "This personality is tapped." << endl;
						}else{
							for(int l=0;l<=25;l++) 
								if(pos==armypos[l]){
									cout<< "This personality was already chosen." <<endl;
									failedPr3=1;
								}
							if(failedPr3!=1){
								sum=sum + army.getAttack(pos);
								armypos[i]=pos;
								i++;
								int x = army.findPrevFollowerSize(pos);
    							botbarrier =x+1;
    							topbarrier =x+army.followerSize(pos);
    							for(int m=1;m<=39;m++)
    								if(folpos[m]<=topbarrier&&folpos[m]>=botbarrier){
    									sum=sum-folpos[m];
    									folpos[m]=0;
    								}
							}
						}
					}else if(CS=="S"||CS=="s") End3=1;	
					else cout << "Wrong Answer." << endl;
				}
			}
		}
		else if(CS=="S"||CS=="s")	{}
		else cout << "Wrong Answer." << endl;
		if(sum>=ad){
			End=1;
			for(int b=1;b<=39;b++)
				if(folpos[b]>0){
					int personpos = army.findMySize(b);
					int followpos = folpos[b] - army.findPrevFollowerSize(personpos);
					army.removeHelpingCard(personpos ,followpos );
				}
			for(int o=1;o<=24;o++)
				if(armypos[o]>0){
					army.removeCard(armpos[o]);
				}
		}else{
			End=0;
			cout<<"You failed to gather the correct ammount of damage , try again."<<endl;
		}
	}
}

/*if(army.getIsTapped(pos)){
	cout << "This personality is tapped." << endl;
}else{
	for(int l=0;l<=25;l++) 
		if(pos==armpos[l]){
			cout<< "This personality already agreed to defend." <<endl;
			failedPr=1;
	}
	if(failedPr!=1){
		sum+=army.getAttack(pos);
		armpos[i]=pos;
		i++;
	}
}*/
								
void Phases :: clearDefeat(Player *player){
	army = player->giveArmy();
	for(int i=1;i<=army.size();i++)
		army.removeCard(1);
	provinces = player->giveProvinces();
	provinces.decreaseProvinces();
}

void Phases :: defeat(Player *player){
	army = player->giveArmy();
	for(int i=1;i<=army.size();i++)
		army.removeCard(1);
}

void Phases :: economyPhase(Player *player){
	blackdeck = player->giveBlackDeck();
	cout <<"Economy Phase !"<<endl;
	provinces = player->giveProvinces();
	provinces.revealAll();
	if(provinces.empty()){
		cout << "You provinces are empty , you can't buy cards from them." <<endl;
	}else{
	string buy;
	cout << "Do you want to buy a card from the provinces? Y/N."<<endl;
	cin >> buy;
	while(buy!="Y"&&buy!="y"&&buy!="N"&&buy!="n"){
		cout << "Answer with Y/y for yes or N/n for no."<<endl;
		cin >> buy;
	}
	if(buy=="Y"||buy=="y"){
		provinces.print();
		int prpos ,i=0 ,pos , sum=0 ,End=0 , holpos[18];
		string CS;
		bool honor , cost;
		for(int j=0;j<=17;j++) holpos[j]=0;
		cout <<"Give the position of the card you want to buy."<<endl;
    	cin >>prpos;
    	while(prpos>provinces.size()||prpos<=0){
    		cout<<"Choose a number according to the size of your provinces"<<endl;
    		cin>>prpos;
    		while(cin.fail()) {
      			cout<<"Give a numerical position."<<endl;
	     		cin.clear();
				cin.ignore(256,'\n');
        		cin >>prpos;
    		}
    	}
    	holdings.print();
		cout << "Now , choose your holdings."<<endl;
		while(End!=1){
			int failedTr=0;
			cout << "Type C to continue , or S to stop."<<endl;
			cin >> CS;
			if(CS=="C"||CS=="c"){
				cout << "Which holding you want to tap?" << endl; 
    			cin >>pos;
    			while(pos>holdings.size()||pos<=0){
    				cout<<"Choose a number according to your holdings size."<<endl;
    				cin>>pos;
    				while(cin.fail()) {
     		 			cout<<"Give a numerical position."<<endl;
			     		cin.clear();
						cin.ignore(256,'\n');
 			       		cin >>pos;
    				}
    			}
				if(holdings.getIsTapped(pos)){
					cout << "This holding is already tapped" << endl;
				}else{
					for(int l=0;l<=17;l++) 
						if(pos==holpos[l]){
							cout<< "You've already chosen that holding for the same transaction" <<endl;
							failedTr=1;
						}
					if(failedTr!=1){
							sum+=holdings.getHarvestValue(pos);
							holpos[i]=pos;
							i++;
					}
				}
			}
			else if(CS=="S"||CS=="s") End=1;	
			else cout << "Wrong Answer , Type C if you want to continue or S if you want to stop." << endl;
		}
		if(sum>=provinces.getCost(prpos)) cost = true;
		else cost = false;
		if( cost ) {
			for(i=0;i<=17;i++) 
				if(holpos[i]>0)
					holdings.tapCard(holpos[i]);
			if(provinces.getType(prpos)=="Personality"){
				army.addCard(provinces.giveCard(prpos));
			}else{
				holdings.addCard(provinces.giveCard(prpos));
			}
			provinces.addCard(prpos ,blackdeck.giveCard());
			cout <<"Transaction complete."<<endl;
 		}else if(cost == false){
 			cout << "Not enough harvestValue to buy the card" << endl;
			}
		}
	}
	cout <<"Economy Phase ended."<<endl;
}

//void Phases :: battlePhase(Player player , Player player2){
//	
//		int gatherForces(Army army);
//		void opponentDefences(Army army);
//	}
//
//};

void Phases :: endingPhase(Player *player ){
	cout <<"Ending Phase !"<<endl;
	hand = player->giveHand();
	discardSurplusFateCards(hand);
	cout <<"Ending Phase ended."<<endl;
}

void Phases :: discardSurplusFateCards(Hand hand){
	if(hand.size()>maxhandsize)
		hand.print();
	while(hand.size()>maxhandsize){
		int hpos;
		cout <<"Your hands exceed the allowed limit"<<endl;
		cout <<"Choose which card you want to remove."<<endl;
		cin >>hpos;
    	while(hpos>hand.size()||hpos<=0){
    		cout<<"Choose a number according to your holdings size."<<endl;
    		cin>>hpos;
    		while(cin.fail()) {
    		 	cout<<"Give a numerical position."<<endl;
		    	cin.clear();
				cin.ignore(256,'\n');
 		     	cin >>hpos;
   			}
   		}
		hand.removeCard(hpos);
	}
	cout << "Your hands are in the allowed limit."<<endl;
}
