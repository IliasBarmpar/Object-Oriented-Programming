#include <iostream>
#include <list>
#include <string>

using namespace std;

class Guest{
	public:
	void check_AvailableOpportunities();
	void user_SignUp();
	void user_Login();

	void home();
	void toggle();
	virtual void print_Options(){
		cout<<"Choose:"<<endl;
		cout<<"the ID of the node you'd like to visit."<<endl;
		cout<<"H (Home), to return to the home page"<<endl;
		cout<<"T (Toggle), to switch between decimal and fractional view"<<endl;

	}
};

class Punter: public Guest{

	public:
	void check_Wallet();
	void place_Bet();

	void account();
	void print_Options(){
		cout<<"A (Account), to manage account information"<<endl;
	}
};

class Wallet{
	public:
	void add_ToWallet();
};

class Employ{

};
class Trader : public Employ{
	public:
	void change_BettingOdds();
	void set_MatchResult();

	void bets();
	void freebets();
	void print_Options(){
		cout<<"B (Bets), to view the last 20 placed bets"<<endl;
		cout<<"F (Freebets), to give a coupon to a user"<<endl;
	}
};
class Director: public Trader{

	public:
	void add_ToHierarchy();
	void delete_FromHierarchy();
	void move_Entry();
	void load_HierarchyFiles();
	void synchronize_HierarchyFiles();

	void save();
	void logs();
	void users();
	void visibility();
	void rename();
	void snew();
	void copy();
	void sdelete();
	void print_Options(){
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


