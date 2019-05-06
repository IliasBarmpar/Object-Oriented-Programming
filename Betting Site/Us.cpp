#include "Us.hpp"
Guest::Guest(){}

User::User(string usr, string nm, string pass){
	name = nm;
	username = usr;
	password = pass;
}
Punter::Punter(string usr, string name, string pass): User(usr,name,pass){
	wallet = new Wallet();
}

Trader::Trader(string usr, string name, string pass): User(usr,name,pass){}

Director::Director(string usr, string name, string pass) : Trader(usr,name,pass){}
