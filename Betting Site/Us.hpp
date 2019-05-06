#include <iostream>
#include <stdlib.h>
#include <list>
#include <string>
#include <sstream>

using namespace std;

class Guest{
	public:
		Guest();
	void check_AvailableOpportunities();
	void home();
	void toggle();
	virtual int placeBet(int ){};
	virtual void accountSettings(){};
	virtual void printExtraOptions(){};
	virtual void print_Options(){
		cout<<"Choose:"<<endl;
		cout<<"the ID of the node you'd like to visit."<<endl;
		cout<<"H (Home), to return to the home page"<<endl;
		cout<<"T (Toggle), to switch between decimal and fractional view"<<endl;
		cout<<"X (Exit), to exit the system"<<endl;
	}
};

class Wallet{
	double moneySum;
	public:
	Wallet(double m = 0) : moneySum(m){}
	
	void addToWallet(double x){
		moneySum += x;
	}
	
	double getMoney(){
		return moneySum;
	}
};

class User : public Guest{
	protected:
		string name;
		string username;
		string password;
		int type;
	public:
		User(string, string, string );
		/*	virtual void print_Options(){
			cout<<"Choose:"<<endl;
			cout<<"the ID of the node you'd like to visit." <<endl;
			cout<<"H (Home), to return to the home page" <<endl;
			cout<<"T (Toggle), to switch between decimal and fractional view"<<endl;
			cout<<"X (Exit), to exit the system"<<endl;
		} */
		string getName(){ return name; }
		string getUsername(){ return username; }
		string getpassword(){ return password; }
		void rename(string line){
			name.clear();
			name = line;
		}
		void changePassword(string input){
			password.clear();
			password = input;
		}
		int getType(){ return type; }
		
};

class Punter: public User{
	Wallet* wallet;
	public:
	Punter(string , string, string);
	double getMoney(){
		return wallet->getMoney();
	}
	void checkWallet(){
		cout << "You currently have " << wallet->getMoney() << " dollars." << endl;
	}
	void deposit(double ammount){
		wallet->addToWallet(ammount);
	}
	
	int placeBet(int optionSum) {
		char* p;
		string error, input, option;
		checkWallet();
		cout << "Where would you like to place your bet?" << endl;
		bool end = 0;
		while(!end){
		    getline(cin,option);
		    istringstream iss(option);
		    iss >> input;
		    iss >> error;
		    int x = strtol(input.c_str() , &p, 10); // conver string to integer
			if( !(*p) ){ // user gave a number
				if( x >= optionSum || x <= 0){
					cout << "Please give a correct respond" << endl;
				}else{
					return x;
				}
			}else if( ( !input.compare("cancel") ) ){ // user gave "cancel"
				end = 1;
			}else{ // user gave an incorrect responce
				cout << "Please give a correct respond" << endl;
			}
		}
		return 0;
	}

	void print_Options(){
		Guest::print_Options();
		cout<<"A (Account), to manage account information"<<endl;
	}
	
	void printExtraOptions(){
		cout<<"P (Place) to place a bet" << endl;
	}
	
	void accountSettings(){
		cout << endl << endl << endl;
		cout << "These are your account options" << endl;
		cout << endl << endl << endl;
	}
};

class Trader : public User{
	public:
		Trader(string , string, string);
	void change_BettingOdds();
	void set_MatchResult();

	void print_Options(){
		Guest::print_Options();
		cout<<"B (Bets), to view the last 20 placed bets"<<endl;
		cout<<"F (Freebets), to give a coupon to a user"<<endl;
	}
};

class Director: public Trader{

	public:
		Director(string, string, string);
	void add_ToHierarchy();
	void delete_FromHierarchy();
	void move_Entry();
	void load_HierarchyFiles();
	void synchronize_HierarchyFiles();

	void print_Options(){
		Trader::print_Options(); // Guest::print_Options(); if we don't want the director to be able to also do what a Trader does.
		cout<<"S (Save), to save the currect state and synchronize the files of the system"<<endl;
		cout<<"L (Logs), to show the last 25 actions that happened to the system"<<endl;
		cout<<"U (Users), to access user management"<<endl;
		cout<<"V (Visibility), to change the visibility of a certain node"<<endl;
		cout<<"R (Rename), to rename node "<<endl;
		cout<<"N (New), to create new node"<<endl;
		cout<<"C (Copy), to copy a node"<<endl;
		cout<<"D (Delete), to delete a node"<<endl;
	}
};

class Utilities{
	public:
};

class Interface{
	public:
};


