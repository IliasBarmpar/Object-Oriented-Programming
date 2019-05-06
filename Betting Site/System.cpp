#include "System.hpp"
#include <string.h>

#include <iostream>

using namespace std;

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
	int y=1;
	list <Node *>::iterator nodeit;
	for(nodeit = childlist->begin(); (nodeit != childlist->end())&&(y!=pos) ; nodeit++,y++);
	return (*nodeit);
}

void Node::addChildNode(Node* ptr ){
	childlist->push_back(ptr);
}


Price::Price(){

}

void Price::print_Name(){

}

////////////////////////////////////

Selection::Selection(string nm, Node* prt) : Node(nm , prt){
//	name = nm;
//	prices = new list <Price *>;
}

void Selection::print_Name(){
	cout << name;
}

void Selection::print_Options(){

}

void Selection::print_Location(){
	parentNode->print_Location();
	cout << "/" << name;
}

////////////////////////////////////

Market::Market(string nm, Node* prt) : Node(nm , prt){
//	name = nm;
}

void Market::print_Name(){
	cout << name;
}



void Market::print_Location(){
	parentNode->print_Location();
	cout << "/" << name;
}

////////////////////////////////////

Event::Event(string nm, Node* prt) : Node(nm , prt){
//	name = nm;
}

void Event::print_Name(){
	cout << name;
}

void Event::print_Location(){
	parentNode->print_Location();
	cout << "/" << name;
}

////////////////////////////////////

SubCategory::SubCategory(string nm, Node* prt) : Node(nm , prt){

}

void SubCategory::print_Name(){
	cout << name;
}


void SubCategory::print_Location(){
	parentNode->print_Location();
	cout << "/" << name;
}



////////////////////////////////////

Category::Category(string nm, Node* prt) : Node(nm , prt){

}

void Category::print_Name(){
	cout << name;
}


void Category::print_Location(){
	parentNode->print_Location();
	cout << "/" << name;
}

////////////////////////////////////

Hierarchy::Hierarchy(string nm, Node* prt) : Node(nm , prt) {

}

void Hierarchy::print_Location(){
	cout << "/" << name;
}
////////////////////////////////////




//TODO Ektelontas me parametro -R
void System::navigate_OnTheSystem(Guest *guest){
	string usrname,psword;
	int par = 0;
	if(par == 1){
		cout << "Sign Up"<<endl;
		cout << "Username: "<<endl;
		cin >> usrname;
		//TODO check if username is available
		//if yes
		{
		cout << "Password:"<<endl;
		cin >> psword;
		}
		//else
		// { Sorry, the username you chose is unavailable }

	}else{
		cout << "Welcome to BetHoven" <<endl;
		cout << "Please type in your username and password to enter. "<<
				"In case you do not have an account, press (enter) or"<<
				" guest:guest to enter as a guest"<<endl;
		cout << "Username" <<endl;
		cin >> usrname;
		cout << "Password" <<endl;
		cin >> psword;
		//TODO while kai elegxos stoixeiwn
	}

//Printer repeated action
	print_Options(guest);

	int option;
	cout << "Give an option" << endl;
	cin >> option ;
	cout << "Your option was " << option <<endl;
	Node* tempNode;
	tempNode = current_HierarchyNode->give_ChildLocation(option);
	current_HierarchyNode = tempNode;






	this->print_Options(guest);

	cout << "Give an option" << endl;
	cin >> option ;
	cout << "Your option was " << option <<endl;

	tempNode = current_HierarchyNode->give_ChildLocation(option);
	current_HierarchyNode = tempNode;

	this->print_Options(guest);

	cout << "Give an option" << endl;
	cin >> option ;
	cout << "Your option was " << option <<endl;

	tempNode = current_HierarchyNode->give_ChildLocation(option);
	current_HierarchyNode = tempNode;

	this->print_Options(guest);
}

void System::print_Options(Guest *guest){
	// 1 Location
	cout << "Location:"; // px /Football/EnglandLeague/AstonVsVilla/MatchResult/Win
	current_HierarchyNode->print_Location(); cout << endl;

	// 2 Tupos Apodoshs
	cout << "Bet Odd View : " << endl; //TODO getbetoddView(decimal/fractional)

	// 3 Choose operation
	guest->print_Options();

	// 4 Current hierarchy level
	current_HierarchyNode->print_Options();
}




/*



Price::Price(){

}

void Price::print_Name(){

}

////////////////////////////////////

Selection::Selection(string nm, Node* prt) : Node(nm , prt){
//	name = nm;
//	prices = new list <Price *>;
}

void Selection::print_Name(){
	cout << name;
}

void Selection::print_Options(){

}

void Selection::print_Location(){
	parentNode->print_Location();
	cout << "/" << name;
}

////////////////////////////////////

Market::Market(string nm, Node* prt) : Node(nm , prt){
//	name = nm;
	selections = new list <Selection *>;
}

void Market::print_Name(){
	cout << name;
}

void Market::print_Options(){
	int i=1;
	list <Selection *>::iterator selectionit;
	for(selectionit = selections->begin(); selectionit != selections->end(); selectionit++){
		cout<< i <<". "; (*selectionit)->print_Name();
		//cout << " - "; (*selectionit)->get_BettingOdd();
		i++;
	}
}

void Market::print_Location(){
	parentNode->print_Location();
	cout << "/" << name;
}

void Market::add_Selection(Selection* ptr ){
	selections->push_back(ptr);
}
////////////////////////////////////

Event::Event(string nm, Node* prt) : Node(nm , prt){
//	name = nm;
	markets = new list <Market *>;
}

void Event::print_Name(){
	cout << name;
}

void Event::print_Options(){
	int i=1;
	list <Market *>::iterator marketit;
	for(marketit = markets->begin(); marketit != markets->end(); marketit++){
		cout<< i <<". "; (*marketit)->print_Name(); cout <<endl;
		i++;
	}
}

void Event::print_Location(){
	parentNode->print_Location();
	cout << "/" << name;
}

void Event::add_Market(Market* ptr ){
	markets->push_back(ptr);
}

////////////////////////////////////

SubCategory::SubCategory(string nm, Node* prt) : Node(nm , prt){
	events = new list <Event *>;
}

void SubCategory::print_Name(){
	cout << name;
}

void SubCategory::print_Options(){
	int i=1;
	list <Event *>::iterator eventit;
	for(eventit = events->begin(); eventit != events->end(); eventit++){
		cout<< i <<". "; (*eventit)->print_Name(); cout <<endl;
		i++;
	}
}

void SubCategory::print_Location(){
	parentNode->print_Location();
	cout << "/" << name;
}

Node* SubCategory::give_ChildLocation(int pos){
	int y=1;
	list <Event *>::iterator eventit;
	for(eventit = events->begin(); eventit != events->end()&&y!=pos; eventit++,y++);
	return (*eventit);
}

void SubCategory::add_Event(Event* ptr ){
	events->push_back(ptr);
}

////////////////////////////////////

Category::Category(string nm, Node* prt) : Node(nm , prt){
	subcategories = new list <SubCategory *>;
}

void Category::print_Name(){
	cout << name;
}

void Category::print_Options(){
	int i=1;
	list <SubCategory *>::iterator subcategoryit;
	for(subcategoryit = subcategories->begin(); subcategoryit != subcategories->end(); subcategoryit++){
		cout<< i <<". "; (*subcategoryit)->print_Name(); cout <<endl;
		i++;
	}
}

void Category::add_SubCategory(SubCategory* ptr){
	subcategories->push_back(ptr);
}

Node* Category::give_ChildLocation(int pos){
	int y=1;
	list <SubCategory *>::iterator subcategoryit;
	for(subcategoryit = subcategories->begin(); subcategoryit != subcategories->end()&&y!=pos; subcategoryit++,y++);
	return (*subcategoryit);
}

void Category::print_Location(){
	parentNode->print_Location();
	cout << "/" << name;
}

////////////////////////////////////

Hierarchy::Hierarchy(string nm, Node* prt) : Node(nm , prt) {
	categories = new list <Category *>;
}

void Hierarchy::add_Category(Category *categ){
	categories->push_back(categ);
}

void Hierarchy::print_Options(){
	int i=1;
	list <Category *>::iterator categoryit;
	for(categoryit = categories->begin(); categoryit != categories->end(); categoryit++){
		cout<< i <<". "; (*categoryit)->print_Name(); cout <<endl;
		i++;
	}
}

Node* Hierarchy::give_ChildLocation(int pos){
	int y=1;
	list <Category *>::iterator categoryit;
	for(categoryit = categories->begin(); categoryit != categories->end()&&y!=pos; categoryit++,y++);
	return (*categoryit);
}

void Hierarchy::print_Location(){
	cout << "/" << name;
}
////////////////////////////////////




//TODO Ektelontas me parametro -R
void System::navigate_OnTheSystem(Guest *guest){
	string usrname,psword;
	int par = 0;
	if(par == 1){
		cout << "Sign Up"<<endl;
		cout << "Username: "<<endl;
		cin >> usrname;
		//TODO check if username is available
		//if yes
		{
		cout << "Password:"<<endl;
		cin >> psword;
		}
		//else
		// { Sorry, the username you chose is unavailable }

	}else{
		cout << "Welcome to BetHoven" <<endl;
		cout << "Please type in your username and password to enter. "<<
				"In case you do not have an account, press (enter) or"<<
				" guest:guest to enter as a guest"<<endl;
		cout << "Username" <<endl;
		cin >> usrname;
		cout << "Password" <<endl;
		cin >> psword;
		//TODO while kai elegxos stoixeiwn
	}

//Printer repeated action
	print_Options(guest);

	int option;
	cout << "Give an option" << endl;
	cin >> option ;
	cout << "Your option was " << option <<endl;
	Node* tempNode;
	tempNode = current_HierarchyNode->give_ChildLocation(option);
	current_HierarchyNode = tempNode;






	this->print_Options(guest);

	cout << "Give an option" << endl;
	cin >> option ;
	cout << "Your option was " << option <<endl;

	tempNode = current_HierarchyNode->give_ChildLocation(option);
	current_HierarchyNode = tempNode;

	this->print_Options(guest);

	cout << "Give an option" << endl;
	cin >> option ;
	cout << "Your option was " << option <<endl;

	tempNode = current_HierarchyNode->give_ChildLocation(option);
	current_HierarchyNode = tempNode;

	this->print_Options(guest);
}

void System::print_Options(Guest *guest){
	// 1 Location
	cout << "Location:"; // px /Football/EnglandLeague/AstonVsVilla/MatchResult/Win
	current_HierarchyNode->print_Location(); cout << endl;

	// 2 Tupos Apodoshs
	cout << "Bet Odd View : " << endl; //TODO getbetoddView(decimal/fractional)

	// 3 Choose operation
	guest->print_Options();

	// 4 Current hierarchy level
	current_HierarchyNode->print_Options();
}



*/
////////////////////////////////////
/*
list<Particle *>::iterator particlesit;
double mass_SavedSum=0;
for(particlesit=particles->begin(); particlesit!=particles->end();particlesit++){
	mass_SavedSum += (*particlesit)->get_MassInMeV();
}
double spin_SavedSum=0;
for(particlesit=particles->begin(); particlesit!=particles->end();particlesit++){
	spin_SavedSum += (*particlesit)->get_Spin();
}*/
