#include "Syst.hpp"
#include <string>
#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

//TODO should it be punter* or user*?
void System::userAccountInterface(Punter* punter){
	cout << "Player: " << punter->getName() <<endl;
	cout << "Available Balance: " << punter->getMoney() <<endl;
	cout << "Available Coupons: " <<  endl; //TODO coupon system
	cout << "R(Rename), to change your name" <<endl;
	cout << "P(Password), to change password" <<endl;
	cout << "B(Bets), to view bet history" <<endl;
	cout << "D(Deposit), to deposit to your wallet" <<endl;
	cout << "X(Exit), to exit account settings" <<endl;
	bool optionCheck = 1;
	while(optionCheck){
		cout << "Give your option:"<<endl;
		string line,input,error;
		getline(cin,line);
		istringstream ss(line);
		ss >> input;
		getline(ss,error);
		if(error.empty()){
			if( ( !input.compare("Exit") ) || ( !input.compare("X") ) ){
				optionCheck = 0;
			}else{
				if( ( !input.compare("Rename") ) || ( !input.compare("R") ) ){
					line.clear(); 
					cout << "Type your new fullname" <<endl;
					getline(cin,line);
					if(checkNameAvailability(line) == 0 || input.compare("guest")){
						cout << "Invalid username." <<endl;
					}else{
						punter->rename(line); //TODO should this change the userfile ?
					}
					
				}else if( ( !input.compare("Password") ) || ( !input.compare("P") ) ){
					cout << "Type your new password" <<endl;
					line.clear();
					string input, input2, error;
					getline(cin,line);
					istringstream ss(line);
					ss >> input;
					getline(ss,error);
					if(error.empty()){
						cout << "Retype your password" <<endl;
						line.clear(); error.empty(); ss.clear();
						getline(cin,line);
						istringstream ss(line);
						ss >> input2;
						getline(ss,error);
						if(error.empty()){
							if(!input.compare(input2)){
								punter->changePassword(input);
							}else{
								cout << "Your password inputs don't match" <<endl;
							}
						}else{
							cout << "Invalid characters in your password" << endl;
						}
					}else{
						cout << "Invalid characters in your password" << endl;
					}
				}else if( ( !input.compare("Bets") ) || ( !input.compare("B") ) ){
				}else if( ( !input.compare("Deposit") ) || ( !input.compare("D") ) ){
					//toposo me to opio tha auksithei to upoloipo tou
					cout << "Please give the ammount that you would like to deposit" <<endl;
					string input, error;
					getline(cin,line);
					istringstream ss(line);
					ss >> input;
					getline(ss,error);
					if(error.empty()){
						char* p;
						double ammount = strtod( input.c_str(), &p);
						if(!(*p)){
							punter->deposit(ammount);
						}else
							cout << "Your input was not numerical." << endl;
					}else{
						
					}
				}else
					cout << "The option you gave is unavailable" <<endl;
			}
		}else{
			cout << "Please give only one input or number as an option."<<endl;
		}
		input.clear();
		error.clear();
	}
}

//void System::printUsersFromFile(char *fileName)
void System::printFromBetFile(){
	//TODO add characters till end of line , then reverse, then do what you were doing
	int count = 0;
	char c;
	ifstream myFile("bets.csv", ios::ate);
	streampos size = myFile.tellg();
	int i = 1;
	while(size>0&&count<42){
		myFile.seekg(-i,ios::end);
		size = myFile.tellg();
		myFile.get(c);
		if(c=='\n')
			count++;
		i++;
	}
	
	string line;
	if(size<=0)
		getline(myFile,line);
//	cout << line <<endl;
//	istringstream ss(line);
//	getline(ss,line,';');
//	cout << line;
	bool endBetPrint = 0;
//	while( endBetPrint ){
getline (myFile,line);
	do{
		istringstream ss(line);
		getline(ss,line,';');
		cout << "Bet number " << line;
		getline(ss,line,';');
		cout << " made by user with id " << line;
		getline(ss,line,';');
		cout << " on node " << line;
		getline(ss,line,';');
		cout <<", bet ammount is " << line;
		getline(ss,line,';');
		if(!line.compare("W")){
			cout << " and he won!" <<endl;
		}else if(!line.compare("L")){
			cout << " and he lost..."<<endl;
		}else{
			cout<<" and is still pending."<<endl;
		}
		getline (myFile,line);
	} while( !myFile.eof() );
	myFile.close();
}

/*
void System::printFromBetFile(){
	ifstream inputfile("bets.csv", ios::ate);
	streampos size = inputfile.tellg();
	string line;
//	inputfile.open ( "bets.csv" );
	bool endBetPrint = 0;
//	if( inputfile.is_open() ){
		
/*		while( endBetPrint ){
			getline (inputfile ,line);
			istringstream ss;
			getline(ss,line,';');
			cout << "Bet number " << line;
			getline(ss,line,';');
			cout << " made by user with id " << line;
			getline(ss,line,';');
			cout << " on node " << line;
			getline(ss,line,';');
			cout <<". Bet ammount is " << line;
			getline(ss,line,';');
			if(line.compare("W")){
				cout << " and he won!" <<endl;
			}else if(line.compare("L")){
				cout << " and he lost..."<<endl;
			}else if(line.compare("-")){
				cout << ". The bet is still pending."<<endl;
			}
			
			
			getline (inputfile, line);  // Get line 
			istringstream ss(line);     // Place it on a stringstream 
			getline(ss , rest, '-');
			
			
			cout << line << endl;
		} */
//		inputfile.close();
//	}else{
//		cout <<"error"<<endl;
//	}
//}

void System::loadFiles() {
	ifstream inputfile;
	inputfile.open( "hierarchy.dat" );
	if( inputfile.is_open() ){
		while( !inputfile.eof() ){
			// Process of getting the numberCount of each line
			string input, line;
			int numberCount=0;
			Category* ptrcat;
			SubCategory* ptrsub;
			Event* ptreve;
			Market* ptrmrk;
			Selection* ptrsel;
			//1st Step
			getline (inputfile, line);  /* Get line */
			istringstream ss(line);     /* Place it on a stringstream */ 
			ss >> input; 				/* Get the first input in this line (contains its hierarchy level in numeric form)*/
			string :: iterator strit;
			for( strit = input.begin(); strit != input.end(); ){ /* Check how many numbers this input has and decide */
				if( isdigit(*strit) ){						   /* in which hierarchy level it belongs */
					do{										   /* for example 1 = Category, 4 = Market */
						strit++;
					}while(isdigit(*strit));
					numberCount++;
				}else{
					strit++;
				}
			}
			
			if(numberCount == 1){
				string rest;
				getline(ss , rest);
				rest.erase(std::remove(rest.begin(), rest.end(), ' '), rest.end());
				ptrcat = new Category(rest,hierarchy);
				hierarchy->addChildNode(ptrcat);
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
	}else{	cout << "Error while opening the file"<<endl;	}
	string l_user_id;
	inputfile.open( "users.csv" );
	if( inputfile.is_open() ){
		
		string line;
		int count = 0;
		getline(inputfile, line); // Skip the first row
		getline(inputfile, line); // Start with the second
		while( !inputfile.eof() ){
			count++;
			//TODO isws me getchar ?
			string username, password,name,count,type;
			istringstream ss(line);
			getline(ss, l_user_id , ';');  // id and we use username as a temp in order to skip it
			getline(ss, username , ';');
			getline(ss, name , ';');
			getline(ss, password , ';');
			getline(ss, type , ';');
			
			char* p;	
			int x = strtol(type.c_str() , &p, 10);
			if(!(*p)){
				User *user;
				if(x==1){
					user = new Punter(username, name, password);
				}else if(x==2){
					user = new Trader(username, name, password);
				}else if(x==3){
					user = new Director(username, name, password);
				}else{
					cout << "There is an error on a user type that is causing the load process to fail please fix it manually." << endl;
					return ;
				}
				users->push_back(user);
			}
			getline(inputfile, line);
		}
		char* p;
		last_user_id = strtol(l_user_id.c_str() , &p, 10);
		inputfile.close();
	}else{
		cout << "Error while opening the file"<<endl;
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
			string input;
			ss >> input;
			string :: iterator strit;
			
			for( strit = input.begin(); strit != input.end(); ){
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


/*         Node         */
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

void System::printUsers(){
	list <User *>:: iterator it;
	for(it = users->begin(); it != users->end(); it++){
		cout << "Name = "<< (*it)->getUsername() <<endl;
	}
}

void System::navigate_OnTheSystem(string parameter){
	Guest* guest;
	//1st step -> Load files
	loadFiles();
	printUsers();
	//2nd step ->Sign up or login
	//TODO navigate as a guest
	if( !parameter.compare("-R")){
		signUp(guest);
	}else{
		guest = logIn();
		if(guest == NULL){
			return ;
		}
	}
	//3rd step Navigation
	//--Location
	//--Odd View
	//--Operations
	//--Current Hierarchy Level	
//Printer repeated action

	char c;
	bool endNavigation = 0;
	string error;
	string input;
	string option;
	do{
		printOptions(guest);
		cout << "Give an option" << endl;
		
		bool optionCheck=1;
		while(optionCheck){ // Checking if user is giving a correct option without re-printing the option list
		    getline(cin,option);
		    istringstream iss(option);
		    iss >> input;
		    getline(iss,error);  
		    if(error.empty()){ //if error is empty then the user has given a single input answer, which we want.
			    	if( ( !input.compare("Exit") ) || ( !input.compare("X") ) ){
			    	optionCheck = 0;
					endNavigation = 1;
				}else{
					if(checkOption(input , guest))
						optionCheck = 0;
					else
						cout <<"The option you gave is unavailable"<<endl;
				}
			}else{
				cout << "Please give only one input or number as an option."<<endl;
			}
			input.clear();
			error.clear();
	 	}
	}while(!endNavigation);
}

void System::printOptions(Guest* guest){
	// 1 Location
	cout << "Location:"; // px /Football/EnglandLeague/AstonVsVilla/MatchResult/Win
	currentHierarchyLevel->print_Location(); cout<<endl;
	// 2 Tupos Apodoshs
	cout << "Bet Odd View : " << endl; //TODO getbetoddView(decimal/fractional)

	// 3 Choose operation
	guest->print_Options();
	if(dynamic_cast<Market *>(currentHierarchyLevel) != 0)
		guest->printExtraOptions();
		
	// 4 Current hierarchy level
	currentHierarchyLevel->print_Options();
}

bool System::checkOption(string input, Guest* guest){
	bool successfullyTerminated = 1;
	char* p;	
	int x = strtol(input.c_str() , &p, 10);
	if(!(*p)){
		Node* tempNode;
		tempNode = currentHierarchyLevel->give_ChildLocation(x);
		if(tempNode == NULL ){
			cout << "You've excided list size or w.e"<<endl;
			successfullyTerminated = 0;
		}else{ 
			currentHierarchyLevel = tempNode;
			
		}
	}else{
		if( ( !input.compare("Home") ) || ( !input.compare("H") )  || ( !input.compare("h") ) ){
			currentHierarchyLevel = hierarchy;
		}else if( ( !input.compare("Toggle") ) || ( !input.compare("T") ) ){
			cout << "input == Toggle" << endl;
		}
		if(dynamic_cast<Punter *>(guest) != 0){
			int betPos;
			if( ( !input.compare("Account") ) || ( !input.compare("A") )  || ( !input.compare("a") ) ){
				userAccountInterface(dynamic_cast<Punter *>(guest));
			}
		/*	if(dynamic_cast<Market *>(currentHierarchyLevel) != 0)
				if( ( !input.compare("Place") ) || ( !input.compare("P") )  || ( !input.compare("p") ) )
//TODO Place					 //guest->placeBet(3);
			if(betPos!=0)
				placeBet(betPos); */
		}
					
		if( (dynamic_cast<Trader *>(guest) != 0) || (dynamic_cast<Director *>(guest) !=0) ){
			if( ( !input.compare("Bets") ) || ( !input.compare("B") ) ){
				cout << "input == Bets" << endl; 
				printFromBetFile();
			}else if( ( !input.compare("Freebets") ) || ( !input.compare("F") ) ){
				cout << "input == Freebets" << endl;
			}
		}
		if(dynamic_cast<Director *>(guest) != 0){
			if( ( !input.compare("Save") ) || ( !input.compare("S") ) ){
				cout << "input == Save" << endl;
			}else if( ( !input.compare("Logs") ) || ( !input.compare("L") ) ){
				cout << "input == Logs" << endl;
			}else if( ( !input.compare("Users") ) || ( !input.compare("U") ) ){
				cout << "input == Users" << endl;
			}else if( ( !input.compare("Visibility") ) || ( !input.compare("V") ) ){
				cout << "input == Visibility" << endl;
			}else if( ( !input.compare("Rename") ) || ( !input.compare("R") ) ){
				cout << "input == Rename" << endl;
			}else if( ( !input.compare("New") ) || ( !input.compare("N") ) ){
				cout << "input == New" << endl;
			}else if( ( !input.compare("Copy") ) || ( !input.compare("C") ) ){
				cout << "input == Copy" << endl;
			}else if( ( !input.compare("Delete") ) || ( !input.compare("D") ) ){
				cout << "input == Delete" << endl;
			}
		}
	}
	return successfullyTerminated;
}

void System::addUserToFile(char *fileName, string usr, string pass){
	fstream inputfile;
	string line;
	inputfile.open ( fileName , ios::app );
	if( inputfile.is_open() ){
		last_user_id++;
		inputfile << last_user_id << ";" << usr << ";"<< pass << ";" << 1 << ";"<< "A" << endl;
		inputfile.close();
	}else{
		cout <<"error"<<endl;
	}
}
bool System::checkNameAvailability(string name){
	bool isAvailable = 1;
	list <User *>:: iterator it;
	for(it = users->begin(); it != users->end(); it++){
		if( !name.compare( (*it)->getName() ) )
			isAvailable = 0;
	}
	return isAvailable;
}
bool System::checkUsernameAvailability(string usr){
	bool isAvailable = 1;
	list <User *>:: iterator it;
	for(it = users->begin(); it != users->end(); it++){
		if( !usr.compare( (*it)->getUsername() ) )
			isAvailable = 0;
	}
	return isAvailable;
}

bool System::checkpasswordAvailability(string usr){
	bool isAvailable = 1;
	list <User *>:: iterator it;
	for(it = users->begin(); it != users->end(); it++){
		if( !usr.compare( (*it)->getpassword() ) )
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

void System::signUp(Guest* guest){
	string username,password;
	cout << "Sign Up" << endl;
	cout << "You may only use characters a-z, A-Z, 0-9 for both your username and password!" << endl;
	/* Username check */
	bool continueLoop = 1;
	while(continueLoop){
		cout << "Give your username please. Type s or stop to exit."<<endl;
		getline(cin, username);
		if( checkForInvalidCharacters(username) == 0 ){
			cout << "Your username has invalid characters." << endl;
		}else if( checkUsernameAvailability(username) == 0 ){
			cout << "Your username is being used." << endl;
		}else if( username.length() >= 15 ){
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
	/* password check */
	continueLoop = 1;
	while(continueLoop){
		//TODO kapia periptwsh pou to continueLoop = 0
		cout << "Give your password please. Type s or stop to exit.:"<<endl;
		getline(cin, password);
		if( checkForInvalidCharacters(password) == 0 ){
			cout << "Your password has invalid characters. Type s or stop too exit." << endl;
		}else if( password.length() >= 15 ){
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
	// This SignUp is only used for Punters
	User *user = new Punter(username,"", password);
	addUserToFile("users.csv",username,password);
	users->push_back (user);
	guest = user;
}

Guest* System::logIn(){
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
			return NULL;
		}else if( checkUsernameAvailability(username) == 1 ){
			cout << "Invalid username." << endl;
		}else{
			continueLoop = 0;
		}
	}
	continueLoop = 1;
	cout << "password. Type 'stop' or 's' to exit." <<endl;
	while(continueLoop){
		getline(cin, password);
		if( !(password.compare("stop")) || !(password.compare("s")) ){
			cout << "Login was unsuccessful" << endl;
			return NULL;
		}else if( checkpasswordAvailability(password) == 1 ){
			cout << "Invalid password." << endl;
		}else{
			continueLoop = 0;
		}
	}
	list <User *>:: iterator it;
	for(it = users->begin(); it != users->end(); it++){
		if( !username.compare( (*it)->getUsername() ) ){
			return (*it);
		}
	}
	
}

void System::placeBet(int pos){
	
}

void System::systemUtilitiesHome(){
//	currentHierarchyLevel = &hierarchy;
}

void System::systemUtilitiesToggle(){
	
}

Node::Node(string nm, Node* ptr){
	parentNode = ptr;
	childlist = new list <Node *>;
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

Selection::Selection(string nm, Node* ptr, int da, int db, double pr) : 
	Node(nm,ptr), price( new Price(da, db, pr) ){ toggle = 1; }
	
Market::Market(string nm, Node* ptr) : Node(nm, ptr){}

Event::Event(string nm, Node* ptr , int d , int m , int y , int h , int mi) : 
	Node(nm, ptr) , date( new Date(d,m,y) ), time( new Time(h,mi) ) {}
	
SubCategory::SubCategory(string nm, Node* ptr) : Node(nm, ptr){}

Category::Category(string nm, Node* ptr) : Node(nm ,  ptr) {}

Hierarchy::Hierarchy(string nm) : Node(nm, NULL){}

////////////////////////////////////

/*
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
			string input;
			ss >> input;
			string :: iterator strit;
			
			for( strit = input.begin(); strit != input.end(); ){
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
			string input;
			ss >> input;
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
*/
/*
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
			//TODO isws me getchar ?
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
*/
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
