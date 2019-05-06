/*
#include <iostream> 
#include <string> 
#include <sstream> 

using namespace std; 

int main () 
{ 
	string text = "CAPASITY : 100";
  	std::string tmp;
	int value;
	char c;
	std::stringstream ss(text);
	ss >> c >> tmp >> value;
	cout << "tmp = " << tmp << " | c = "<<c << " | value = "<<value <<endl;COUT 
}
*/
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string t;
    getline(cin,t);

    istringstream iss(t);
    string word;
    while(iss >> word) {
    	cout <<"| " << word <<" |"<<endl; 
    }
}

