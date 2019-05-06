#include <list>
#include <string>
#include "Us.hpp"
#include <fstream>

using namespace std;

class Date {
		int day;
		int month;
		int year;
	public:
		Date(int d = 0, int m = 0, int y = 0)
	        : day(d), month(m), year(y) {}
	    ~Date();
};

class Time {
		int hours;
		int mins;
	public:
		Time(int h = 0, int m = 0 )
	    	: hours(h), mins(m){}
};

class Node {
	protected:
		Node* parentNode;
		string name;
		list <Node *> *childlist;
	public: 
		Node(string , Node*);
		void print_Name();
		virtual void get_BettingOdd(){};
		void print_Location();
		Node* give_ChildLocation(int pos);
		void print_Options();
		void addChildNode(Node* ptr );
		virtual bool getToggle(){};
		void setToggle(){};
};

class Price {
		string name;
		int divident_BetOdd;
		int divisor_BetOdd;
		double division_BetOdd;
	public: 
		Price(int , int , double );
};

class Selection : public Node{
		bool toggle;
		Price* price;
	public: 
		Selection(string , Node* , int , int , double);
		bool getToggle(){};
		void get_BettingOdd(){};
};

class Market : public Node {
	public: 
		Market(string , Node* );
		void print_Location();
};

class Event : public Node {
	Date* date;
	Time* time;
	
	public:
		Event(string , Node* , int  , int  , int  , int  , int );
		void print_Location();
};

class SubCategory : public Node {
	public: 
		SubCategory(string , Node* );
		void print_Location();
};

class Category : public Node {
	public: 
		Category(string, Node* );
		void print_Location();
};

class Hierarchy : public Node{
	public:
		Hierarchy(string);
		void print_Location();
};
/*
class Node {
	protected:
		Node* parentNode;
		string name;
		list <Node *> *childlist;
	public: 
	Node(string , Node*);
};
*/

class System {
		string name;
		double sum;
		double supply;
		int last_user_id;
		list <User *> *users;
		Node* hierarchy;
		Node* currentHierarchyLevel;
	public: 
		System(double p = 5.0) {
			name = "BetKTCN";
			hierarchy = new Hierarchy(name);
			currentHierarchyLevel = hierarchy;
			last_user_id = 0;
			supply = p;
			sum = 0;
			users = new list <User *>;
		}
		void printFromBetFile();
		void printUsersFromFile(char *);
		void addUserToFile(char *, string, string );
		void navigate_OnTheSystem(string);
		void printOptions(Guest* );
		void systemHome();
		bool checkOption(string , Guest* );
		void userAccountInterface(Punter* );
		// Utilities
		void systemUtilitiesHome();
		void systemUtilitiesToggle();
		void placeBet(int );
		// file functions
		void writeOnHierarchyFile(char *);
		void loadFiles();
		bool checkpasswordAvailability(string );
		bool checkUsernameAvailability(string );
		bool checkNameAvailability(string );
		bool checkForInvalidCharacters(string );
		void signUp(Guest*);
		Guest* logIn();
		void printUsers();
};
