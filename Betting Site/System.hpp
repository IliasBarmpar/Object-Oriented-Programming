#include <list>
#include <string>
//#include "Users.hpp"
using namespace std;


class Node{
	protected:
	Node* parentNode;
	string name;
	list <Node *> *childlist;

	public: ////
	Node(string , Node* );
	virtual void print_Name(){};
	virtual void get_BettingOdd(){};
	virtual void print_Location(){};
	virtual Node* give_ChildLocation(int pos);
	void print_Options();
	void addChildNode(Node* ptr );
};

class Price{
	string name;
	int divident_BetOdd;
	int divisor_BetOdd;
	double division_BetOdd;

	public: ////
	Price();
	void print_Name();
	void print_Options();
};

class Selection : public Node{
	Price  price;

	public: ////
	Selection(string , Node* ) ;
	void print_Name();
	void print_Options();
	void print_Location();
	void get_BettingOdd(){};
};

class Market : public Node{
//	list <Selection *> *childList;

	public: ////
	Market(string , Node* );
	void print_Name();
	void print_Options();
	void print_Location();
};

class Event : public Node{
//	list <Market *> *childList;

	public: ////
	Event(string , Node* );
	void print_Name();
	void print_Options();
	void print_Location();
};

class SubCategory : public Node{
//	list <Event *> *childList;

	public:  ////
	SubCategory(string , Node* );
	void print_Name();
	void print_Options();
	void print_Location();
};

class Category : public Node{
//	list <SubCategory *> *childList;

	public:  ////
	Category(string , Node* );
	void print_Name();
	void print_Options();
	void print_Location();
};


class Hierarchy : public Node{
//	list <Category *> *childList;

	public:  ////
	Hierarchy(string , Node* );
	void print_Location(Node *node){};
	void print_Options();
	void print_Location();
};

class System{
	string name;
	double sum;
	double supply;
	Hierarchy& hierarchy;
	Node* current_HierarchyNode;
	//list <User *> users;

	public: ////

	System( Hierarchy& hs , double p = 5.0 ) : hierarchy(hs) {
		current_HierarchyNode = &hs;
		supply = p;
		name = "yolo";
		sum = 0;
	}
	void navigate_OnTheSystem( Guest *);
	void print_Options(Guest *);
};

/* 2nd Save
class Node{
	protected:
	Node* parentNode;
	string name;
	list <Node *> *childlist;

	public: ////
	Node(string , Node* );
	virtual void print_Name(){};
	virtual void get_BettingOdd(){};
	virtual void print_Location(){};
	virtual Node* give_ChildLocation(int pos);
	void add_Selection(Node* ptr )
	void print_Options();
};

class Price{
	string name;
	int divident_BetOdd;
	int divisor_BetOdd;
	double division_BetOdd;

	public: ////
	Price();
	void print_Name();
	void print_Options();
};

class Selection : public Node{
	Price  price;

	public: ////
	Selection(string , Node* ) ;
	void print_Name();
	void print_Options();
	void print_Location();
	void get_BettingOdd(){};
};

class Market : public Node{
//	list <Selection *> *childList;

	public: ////
	Market(string , Node* );
	void add_Selection(Selection* );
	void print_Name();
	void print_Options();
	void print_Location();
};

class Event : public Node{
//	list <Market *> *childList;

	public: ////
	Event(string , Node* );
	void add_Market(Market* );
	void print_Name();
	void print_Options();
	void print_Location();
};

class SubCategory : public Node{
//	list <Event *> *childList;

	public:  ////
	SubCategory(string , Node* );
	void add_Event(Event* );
	void print_Name();
	void print_Options();
	void print_Location();
	Node* give_ChildLocation(int pos);
};

class Category : public Node{
//	list <SubCategory *> *childList;

	public:  ////
	Category(string , Node* );
	void add_SubCategory(SubCategory* );
	void print_Name();
	void print_Options();
	void print_Location();
	Node* give_ChildLocation(int pos);
};


class Hierarchy : public Node{
//	list <Category *> *childList;

	public:  ////
	Hierarchy(string , Node* );
	void add_Category(Category* );
	virtual void print_Location(Node *node){};
	void print_Options();
	void print_Location();
	Node* give_ChildLocation(int pos);
};

class System{
	string name;
	double sum;
	double supply;
	Hierarchy& hierarchy;
	Node* current_HierarchyNode;
	//list <User *> users;

	public: ////

	System( Hierarchy& hs , double p = 5.0 ) : hierarchy(hs) {
		current_HierarchyNode = &hs;
		supply = p;
		name = "yolo";
		sum = 0;
	}
	void navigate_OnTheSystem( Guest *);
	void print_Options(Guest *);
};
*/

/* 1st Save
class Node{
	protected:
	Node* parentNode;
	string name;

	public: ////
	Node(string , Node* );
	virtual void print_Options(){};
	virtual void get_BettingOdd(){};
	virtual void print_Location(){};
	virtual Node* give_ChildLocation(int pos){};
};

class Price{
	string name;
	int divident_BetOdd;
	int divisor_BetOdd;
	double division_BetOdd;

	public: ////
	Price();
	void print_Name();
	void print_Options();

};

class Selection : public Node{
//	Node* parentNode;
	Price  price;
//	string name;

	public: ////
	Selection(string , Node* ) ;
	void print_Name();
	void print_Options();
	void print_Location();
	void get_BettingOdd(){};
};

class Market : public Node{
//	Node* parentNode;
	list <Selection *> *selections;
//	string name;

	public: ////
	Market(string , Node* );
	void print_Name();
	void print_Options();
	void print_Location();
};

class Event : public Node{
//	Node* parentNode;
	list <Market *> *markets;
//	string name;

	public: ////
	Event(string , Node* );
	void print_Name();
	void print_Options();
	void print_Location();
};

class SubCategory : public Node{
//	Node* parentNode;
	list <Event *> *events;
//	string name;

	public:  ////
	SubCategory(string , Node* );
	void print_Name();
	void print_Options();
	void print_Location();
	void system_Home
};

class Category : public Node{
//	Node* parentNode;
	list <SubCategory *> *subcategories;
//	string name;

	public:  ////
	Category(string , Node* );
	void print_Name();
	void print_Options();
	void print_Location();
};


class Hierarchy : public Node{
	list <Category *> *categories;

	public:  ////
	Hierarchy(string , Node* );
	void add_Category(Category* );
	virtual void print_Location(Node *node){};
	void print_Options();
	void print_Location();
	Node* give_ChildLocation(int pos);
};

class System{
	string name;
	double sum;
	double supply;
	Hierarchy& hierarchy;
	Node *nodeRunner;
	//list <User *> users;

	public: ////

	System( Hierarchy& hs , double p = 5.0 ) : hierarchy(hs) {
		nodeRunner = &hs;
		supply = p;
		name = "yolo";
		sum = 0;
	}
	void navigate_OnTheSystem( Guest *);
	void print_Options(Guest *);

};
*/
