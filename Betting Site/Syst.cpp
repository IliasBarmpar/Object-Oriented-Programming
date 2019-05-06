#include "Syst.hpp"
#include <string>
#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;
/*
void readFromFile(char *fileName){
	fstream inputfile;
	string line;
	inputfile.open( fileName, ios :: in | ios :: out);
	if( inputfile.is_open() ){
		while( !inputfile.is_open() ){
			
		}
		inputfile.close();
	}else{
		cout << "Error while opening the file"<<endl;
	}
}
*/
void System::printUsersFromFile(char *fileName){
	fstream inputfile;
	string line;
	inputfile.open ( fileName , ios::app );
	if( inputfile.is_open() ){
		while( !inputfile.eof() ){
			getline (inputfile ,line);
			cout << line << endl;
		}
		inputfile.close();
	}else{
		cout <<"error"<<endl;
	}
}

void System::addUserToFile(char *fileName, string usr, string pass,int count){
	fstream inputfile;
	string line;
	inputfile.open ( fileName , ios::app );
	if( inputfile.is_open() ){
		inputfile << count << ";" << usr << ";" << ";" << pass << endl;
		inputfile.close();
	}else{
		cout <<"error"<<endl;
	}
}

void System::writeOnHierarchyFile(char *fileName){
	fstream inputfile;
	string line;
	inputfile.open( fileName );
	if( inputfile.is_open() ){
		while( !inputfile.eof() ){
			// Process of getting the numberCount of each line
			getline(inputfile, line);
			int numberCount=0;
			istringstream ss(line);
			string word;
			ss >> word;
			string :: iterator strit;
			
			for( strit = word.begin(); strit != word.end(); ){
				if( isdigit(*strit) ){
					do{
						strit++;
					}while(isdigit(*strit));
					numberCount++;
				}else{
					strit++;
				}
			}
			// Process of adding the Node based on its numberCount
			numberCount = 0;
		}
		inputfile.close();
	}else{
		cout << "Error while opening the file"<<endl;
	}
}

void System::loadHierarchyFile(char *fileName) {
	ifstream inputfile;
	string line;
	inputfile.open( fileName );
	if( inputfile.is_open() ){
		while( !inputfile.eof() ){
			// Process of getting the numberCount of each line
			getline (inputfile, line);
			int numberCount=0;
			istringstream ss(line);
			string word;
			ss >> word;
			string :: iterator strit;
			
			for( strit = word.begin(); strit != word.end(); ){
				if( isdigit(*strit) ){
					do{
						strit++;
					}while(isdigit(*strit));
					numberCount++;
				}else{
					strit++;
				}
			}
			// Process of adding the Node based on its numberCount
			
			Category* ptrcat;
			SubCategory* ptrsub;
			Event* ptreve;
			Market* ptrmrk;
			Selection* ptrsel;
			if(numberCount == 1){
				string rest;
				getline(ss , rest);
				rest.erase(std::remove(rest.begin(), rest.end(), ' '), rest.end());
				ptrcat = new Category( rest , &hierarchy);
				hierarchy.addChildNode(ptrcat);
			}
			if(numberCount == 2){
				string rest;
				getline(ss , rest);
				rest.erase(std::remove(rest.begin(), rest.end(), ' '), rest.end());
				ptrsub = new SubCategory(rest , ptrcat);
				ptrcat->addChildNode(ptrsub);
			}
			if(numberCount == 3){
				string rest,trash;
				string sy,sm,sd,sh,smi; int y,m,d,h,mi;
				getline(ss , rest, '-');
				rest.erase(std::remove(rest.begin(), rest.end(), ' '), rest.end());
				ss >> y;
				getline(ss, trash, '/'); ss >> m;
				getline(ss, trash, '/'); ss >> d;
				ss >> h;
				getline(ss, trash, ':'); ss >> mi;
				ptreve = new Event(rest , ptrsub, d, m, y, h, mi);
				ptrsub->addChildNode(ptreve);
			}
			if(numberCount == 4){
				string rest;
				getline(ss , rest);
				rest.erase(std::remove(rest.begin(), rest.end(), ' '), rest.end());
				ptrmrk = new Market(rest , ptreve);
				ptreve->addChildNode(ptrmrk);
			}
			if(numberCount == 5){
				string rest,trash; int da,db;
				getline(ss , rest , '#'); ss >> da;
				rest.erase(std::remove(rest.begin(), rest.end(), ' '), rest.end());
				getline(ss , trash , '/'); ss >> db;
				ptrsel = new Selection(rest , ptrmrk, da, db ,4);
				ptrmrk->addChildNode(ptrsel);
			}
			numberCount = 0;
		}
		inputfile.close();
	}else{
		cout << "Error while opening the file"<<endl;
	}
}

void System::loadAuditFile(char *fileName){
	ifstream inputfile;
	string line;
	inputfile.open( fileName );
	if( inputfile.is_open() ){
		while( !inputfile.eof() ){
			// Process of getting the numberCount of each line
			getline (inputfile, line);
			int numberCount=0;
			istringstream ss(line);
			string word;
			ss >> word;
		}
		inputfile.close();
	}else{
		cout << "Error while opening the file"<<endl;
	}
}

void System::loadBetFile(char *fileName){
	ifstream inputfile;
	string line;
	inputfile.open( fileName );
	if( inputfile.is_open() ){
		while( !inputfile.eof() ){
			// Process of getting the numberCount of each line
			getline (inputfile, line);
			cout<< line << endl;
			int numberCount=0;
			
		}
		inputfile.close();
	}else{
		cout << "Error while opening the file"<<endl;
	}
}
void System::loadUserFile(char *fileName ){
	ifstream inputfile;
	string line;
	inputfile.open( fileName );
	if( inputfile.is_open() ){
		
		int count = 0;
		getline(inputfile, line); // Skip the first row
		getline(inputfile, line); // Start with the second
		while( !inputfile.eof() ){
			count++;
			string username, password;
			istringstream ss(line);
			getline(ss, username , ';');  
			getline(ss, username , ';');
			getline(ss, password , ';');
			
			
			getline(inputfile, line);
		}
		inputfile.close();
	}else{
		cout << "Error while opening the file"<<endl;
	}
}

/*	string :: iterator strit = line.begin();
			while ( (*strit) != ';')
				strit++;
			int i = 0;
			while ( (*strit) != ';'){
				strit++;
				username[i] = *strit;
				i++;
			}
			i = 0;
			while ( (*strit) != ';'){
				strit++;
				password[i] = *strit;
				i++;
			}
*/

/*
void System::changeHierarchyFile() {
	
}
*/

/*         Node         */



void System::printUsers(){
	list <Punter *>:: iterator it;
	for(it = users->begin(); it != users->end(); it++){
		cout << "Name = "<< (*it)->getName() <<endl;
	}
}

void System::navigate_OnTheSystem(Guest *guest){
//	loadHierarchyFile("hierarchy.dat");
//	signUp();
//	printUsersFromFile("users.csv");
//	logIn();
//	printUsers();
//	loadAuditFile("audit.log");
//	loadBetFile("bets.csv");
	loadUserFile("users.csv");

	/*
//Printer repeated action
	char c;
	bool endNavigation = 0;
	string error;
	string word;
	string option;
//	stringstream ssOption;
	do{
		print_Options(guest);
		cout << "Give an option" << endl;
	    getline(cin,option);
	
	    istringstream iss(option);
	    iss >> word;
	    iss >> error;
	 	if( ( !word.compare("Exit") ) || ( !word.compare("X") ) ){
			endNavigation = 1;
		}else{
			checkOption(word , guest); 
		}
		word.clear();
		error.clear();
	}while(!endNavigation);
}

void System::print_Options(Guest *guest){
	// 1 Location
	cout << "Location:"; // px /Football/EnglandLeague/AstonVsVilla/MatchResult/Win
	currentHierarchyLevel->print_Location(); cout << endl;

	// 2 Tupos Apodoshs
	cout << "Bet Odd View : " << endl; //TODO getbetoddView(decimal/fractional)

	// 3 Choose operation
	guest->print_Options();
	if(dynamic_cast<Market *>(currentHierarchyLevel) != 0)
		guest->printExtraOptions();
		
	// 4 Current hierarchy level
	currentHierarchyLevel->print_Options();
	*/
}

void System::checkOption( string word , Guest *guest ){
	char* p;	
	int x = strtol(word.c_str() , &p, 10);
	if(!(*p)){
		Node* tempNode;
		tempNode = currentHierarchyLevel->give_ChildLocation(x);
		if(tempNode == NULL ){ cout << "You've excided list size or w.e"<<endl;}
		else{ currentHierarchyLevel = tempNode;}
	}else{
		if( ( !word.compare("Home") ) || ( !word.compare("H") )  || ( !word.compare("h") ) ){
			currentHierarchyLevel = &hierarchy;
		}else if( ( !word.compare("Toggle") ) || ( !word.compare("T") ) ){
			cout << "Word == Toggle" << endl;
		}
		if(dynamic_cast<Punter *>(guest) != 0){
			int betPos;
			
			if( ( !word.compare("Account") ) || ( !word.compare("A") )  || ( !word.compare("h") ) ){
				guest->accountSettings();
			}
			if(dynamic_cast<Market *>(currentHierarchyLevel) != 0)
				if( ( !word.compare("Place") ) || ( !word.compare("P") )  || ( !word.compare("p") ) )
					betPos = guest->placeBet();
			if(betPos!=0)
				placeBet(betPos);
		}
		if(dynamic_cast<Director *>(guest) != 0){
		}			
		if(dynamic_cast<Trader *>(guest) != 0){
			if( ( !word.compare("Bets") ) || ( !word.compare("B") )  || ( !word.compare("h") ) ){
				cout << "Word == Bets" << endl;
			}else if( ( !word.compare("Freebets") ) || ( !word.compare("F") ) ){
				cout << "Word == Freebets" << endl;
			}
		}
		if(dynamic_cast<Director *>(guest) != 0){
			if( ( !word.compare("Bets") ) || ( !word.compare("B") )  || ( !word.compare("h") ) ){
				cout << "Word == Bets" << endl;
			}else if( ( !word.compare("Freebets") ) || ( !word.compare("F") ) ){
				cout << "Word == Freebets" << endl;
			}else if( ( !word.compare("Save") ) || ( !word.compare("S") ) ){
				cout << "Word == Save" << endl;
			}else if( ( !word.compare("Logs") ) || ( !word.compare("L") ) ){
				cout << "Word == Logs" << endl;
			}else if( ( !word.compare("Users") ) || ( !word.compare("U") ) ){
				cout << "Word == Users" << endl;
			}else if( ( !word.compare("Visibility") ) || ( !word.compare("V") ) ){
				cout << "Word == Visibility" << endl;
			}else if( ( !word.compare("Rename") ) || ( !word.compare("R") ) ){
				cout << "Word == Rename" << endl;
			}else if( ( !word.compare("New") ) || ( !word.compare("N") ) ){
				cout << "Word == New" << endl;
			}else if( ( !word.compare("Copy") ) || ( !word.compare("C") ) ){
				cout << "Word == Copy" << endl;
			}else if( ( !word.compare("Delete") ) || ( !word.compare("D") ) ){
				cout << "Word == Delete" << endl;
			}
		}
	}
}

bool System::checkUsernameAvailability(string usr){
	bool isAvailable = 1;
	list <Punter *>:: iterator it;
	for(it = users->begin(); it != users->end(); it++){
		if( !usr.compare( (*it)->getName() ) )
			isAvailable = 0;
	}
	return isAvailable;
}
bool System::checkPasswordAvailability(string usr){
	bool isAvailable = 1;
	list <Punter *>:: iterator it;
	for(it = users->begin(); it != users->end(); it++){
		if( !usr.compare( (*it)->getPassword() ) )
			isAvailable = 0;
	}
	return isAvailable;
}

bool System::checkForInvalidCharacters(string str){
	bool isValid = 1;
	for ( string::iterator it=str.begin(); it!=str.end(); ++it)
		if( (*it) > 'z' || ( (*it) < 'a' )&&( (*it) > 'Z') || ( (*it) < 'A')&&( (*it) > '9') || ( (*it) < '0') )
			isValid = 0;
	return isValid;
}

void System::signUp(){
	string username,password;
	cout << "Sign Up" << endl;
	cout << "You may only use characters a-z, A-Z, 0-9 for both your username and password!" << endl;
	/* Username check */
	bool continueLoop = 1;
	while(continueLoop){
		cout << "Give your username please. Type s or stop too exit."<<endl;
		getline(cin, username);
		if( checkForInvalidCharacters(username) == 0 ){
			cout << "Your username has invalid characters." << endl;
		}else if( checkUsernameAvailability(username) == 0 ){
			cout << "Your username is being used." << endl;
		}else if( username.length() >= 10 ){
			cout << "You need a smaller username." << endl;	
		}else if( username.length() <= 5 ){
			cout << "You need a bigger username." << endl;	
		}else if( !(username.compare("stop")) || !(username.compare("s")) ){
			cout << "Sign up was unsuccessful" << endl;
			return ;
		}else{
			continueLoop = 0;
		}
	}
	/* Password check */
	continueLoop = 1;
	while(continueLoop){
		//TODO kapia periptwsh pou to continueLoop = 0
		cout << "Give your password please. Type s or stop too exit.:"<<endl;
		getline(cin, password);
		if( checkForInvalidCharacters(password) == 0 ){
			cout << "Your password has invalid characters. Type s or stop too exit." << endl;
		}else if( password.length() >= 10 ){
			cout << "You need a smaller password." << endl;	
		}else if( password.length() <= 5 ){
			cout << "You need a bigger password." << endl;	
		}else if( !(password.compare("stop")) || !(password.compare("s")) ){
			cout << "Sign up was unsuccessful" << endl;
			return ;
		}else{
			continueLoop = 0;
		}
	}
	Punter *user = new Punter(username, password);
	addUserToFile("users.csv",username,password,user->get_Count());
	users->push_back (user);
}

void System::logIn(){
	string username,password;
	cout << "Welcome to BetHoven" <<endl;
	cout << "Please type in your username and password to enter. "<<
			"In case you do not have an account, press (enter) or"<<
			" guest:guest to enter as a guest"<<endl;
	cout << "Give your username. Type 'stop' or 's' to exit." <<endl;
	bool continueLoop = 1;
	while(continueLoop){
		getline(cin, username);
		if( !(username.compare("stop")) || !(username.compare("s")) ){
			cout << "Login was unsuccessful" << endl;
			return ;
		}else if( checkUsernameAvailability(username) == 1 ){
			cout << "Invalid username." << endl;
		}else{
			continueLoop = 0;
		}
	}
	continueLoop = 1;
	cout << "Password. Type 'stop' or 's' to exit." <<endl;
	while(continueLoop){
		getline(cin, password);
		if( !(password.compare("stop")) || !(password.compare("s")) ){
			cout << "Login was unsuccessful" << endl;
			return ;
		}else if( checkPasswordAvailability(password) == 1 ){
			cout << "Invalid password." << endl;
		}else{
			continueLoop = 0;
		}
	}
}

void System::placeBet(int pos){
	
}

void System::systemUtilitiesHome(){
	currentHierarchyLevel = &hierarchy;
}

void System::systemUtilitiesToggle(){
	
}

Node::Node(string nm , Node* ptr){
	childlist = new list <Node *>;
	parentNode = ptr;
	name = nm;
}

void Node::print_Options(){
	int i=1;
	list <Node *>::iterator nodeit;
	for(nodeit = childlist->begin(); nodeit != childlist->end(); nodeit++){
		cout<< i <<". "; (*nodeit)->print_Name(); cout <<endl;
		i++;
	}
}

Node* Node::give_ChildLocation(int pos){
	int y = 1;
	list <Node *>::iterator nodeit;
	for(nodeit = childlist->begin(); (nodeit != childlist->end())&&(y!=pos) ; nodeit++,y++);
	if( nodeit == childlist->end() ){ (*nodeit) = NULL; }
	return (*nodeit);
}

void Node::addChildNode(Node* ptr ){
	childlist->push_back(ptr);
}

void Node::print_Name(){
	cout << name;
}

void Node::print_Location(){
	if(dynamic_cast<Hierarchy *>(this) != 0){
		cout << "/" << name;
	}else{
		parentNode->print_Location();
		cout << "/" << name;
	}
}

////////////////////////////////////

Price::Price(int da, int db, double pr) : divident_BetOdd(da), divisor_BetOdd(db), division_BetOdd(pr){}


////////////////////////////////////

Selection::Selection(string nm, Node* prt, int da, int db, double pr) : 
	Node(nm , prt), price( new Price(da, db, pr) ){toggle = 1; }

////////////////////////////////////

Market::Market(string nm, Node* prt) : Node(nm , prt){}

////////////////////////////////////

Event::Event(string nm, Node* prt , int d , int m , int y , int h , int mi) : 
	Node(nm , prt) , date( new Date(d,m,y) ), time( new Time(h,mi) ) {}

////////////////////////////////////

SubCategory::SubCategory(string nm, Node* prt) : Node(nm , prt){}

////////////////////////////////////

Category::Category(string nm, Node* prt) : Node(nm , prt){}

////////////////////////////////////

Hierarchy::Hierarchy(string nm, Node* prt) : Node(nm , prt) {}

////////////////////////////////////
