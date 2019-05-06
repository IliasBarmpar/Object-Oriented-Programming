
#include "Phases.hpp"
#include <string>
/*
void EquipPhase :: buyCard(Army army , Hand hand ,Holdings holdings ) {
	string buy;
	cout << "Do you want to buy a card from your hand? Y/N."<<endl;
	cin >> buy;
	while(buy!="Y"&&buy!="y"&&buy!="N"&&buy!="n"){
		cout << "Answer with Y/y for yes or N/n for no."<<endl;
		cin >> buy;
	}
	if(buy=="Y"||buy=="y"){
		int armpos , hpos, i=0 , pos , Sum=0 ,End=0 , holpos[10] ;
		string YN , CS;
		bool honor , cost;
		for(int j=0;j<=9;j++) holpos[j]=0;
		cout <<"Give the position of the personality you want to equip."<<endl;
		cin >>armpos;
    	while(cin.fail()) {
       		cout<<"Give a numerical position."<<endl;
 	        cin.clear();
        	cin.ignore(256,'\n');
        	cin >> armpos;
    	}
		cout << "Give the position of the card in your hand you want to equip."<<endl;
		cin >> hpos;
		while(cin.fail()) {
       		cout<<"Give a numerical position."<<endl;
 	        cin.clear();
        	cin.ignore(256,'\n');
        	cin >> hpos;
    	}
		if(army.getHonour(armpos)>=hand.getMinimumHonour(hpos)) honor = true;
		else honor = false;	
		cout << "Do you want to upgrade?  Y/N "<<endl;
		cin >> YN; 
		while (!(YN=="Y"||YN=="y"||YN=="N"||YN=="n")){
			cout <<"Answer with Y for yes or N for no"<<endl;
			cin >> YN;
		}
		cout << "Now , choose your holdings."<<endl;
		while(End!=1){
			int failedTr=0;
			cout << "Type C to continue , or S to stop"<<endl;
			cin >> CS;
			if(CS=="C"||CS=="c")	{
				cout << "Which holding you want to tap?" << endl; 
				cin >>pos;
				while(cin.fail()) {
       				cout<<"Give a numerical position."<<endl;
 	     			cin.clear();
        			cin.ignore(256,'\n');
        			cin >> pos;
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
							Sum+=holdings.getHarvestValue(pos);
							holpos[i]=pos;
							i++;
						}
				}
			}else if(CS=="S"||CS=="s") End=1;	
			else cout << "Wrong Answer." << endl;
		}
		if(YN=="Y"){
			if(Sum>=hand.getEffectCost(hpos)) cost = true;
			else cost = false;
		}else if(YN=="N"){
			if(Sum>=hand.getCost(hpos)) cost = true;
			else cost = false;
		}
		if( cost &&	honor ) {
			for(i=0;i<=9;i++) 
				if(holpos[i]>0)
					holdings.tapCard(holpos[i]);
			if(YN=="Y"||YN=="y"){
				hand.activateBonus(hpos);
			}
			army.addHelpingCard(hand.giveCard(hpos) , armpos);
 		}else if(cost == false && honor == false)
 			cout << "Not enough honor and harvestValue to buy the card" << endl;
 		else if(cost == false)
 			cout << "Not enough harvestValue to buy the card" << endl;
 		else if(honor == false)
 			cout << "Not enough honor to buy the card" <<endl;
	}
}	 */
