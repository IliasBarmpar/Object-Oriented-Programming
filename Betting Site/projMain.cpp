#include "Syst.hpp"
#include <iostream>

using namespace std;

int main(int argc, char **argv){
	string parameter = "";
	if (argc>2){
		cout << "Error, too many command line arguments." << endl;
		return 1;
	}else if(argc == 2){
		parameter = argv[1];
	}
	System *syst;
	syst = new System(5);
	Guest *guest;
//	guest = new Punter("name" , "password");
	syst->navigate_OnTheSystem(parameter);
	return 0;
}

/*
	Selection* ptrsel;
	Market* ptrmrk;
	Event* ptreve;
	SubCategory* ptrsub;
	Category* ptrcat;
	
	ptrcat = new Category("cat1" , &hs);
	hs.addChildNode(ptrcat);
	ptrsub = new SubCategory("sub1" , ptrcat);
	ptrcat->addChildNode(ptrsub);
	ptreve = new Event("eve1" , ptrsub, 4 ,4 ,4 ,4,4);
	ptrsub->addChildNode(ptreve);
	ptrmrk = new Market("mrk1" , ptreve);
	ptreve->addChildNode(ptrmrk);
	ptrsel = new Selection("sel1" , ptrmrk , 16 , 4 , 4);
	ptrmrk->addChildNode(ptrsel);

	ptrsel = new Selection("sel2" , ptrmrk, 16 , 4 , 4);
	ptrmrk->addChildNode(ptrsel);

	ptrmrk = new Market("mrk2" , ptreve);
	ptreve->addChildNode(ptrmrk);
	ptrsel = new Selection("sel3" , ptrmrk, 16 , 4 , 4);
	ptrmrk->addChildNode(ptrsel);
	ptrsel = new Selection("sel4" , ptrmrk, 16 , 4 , 4);
	ptrmrk->addChildNode(ptrsel);

	ptreve = new Event("eve2" , ptrsub, 4 ,4 ,4 ,4,4);
		ptrsub->addChildNode(ptreve);
		ptrmrk = new Market("mrk3" , ptreve);
			ptreve->addChildNode(ptrmrk);
			ptrsel = new Selection("sel5" , ptrmrk, 16 , 4 , 4);
			ptrmrk->addChildNode(ptrsel);
			ptrsel = new Selection("sel6" , ptrmrk, 16 , 4 , 4);
			ptrmrk->addChildNode(ptrsel);

	ptrmrk = new Market("mrk4" , ptreve);
		ptreve->addChildNode(ptrmrk);
		ptrsel = new Selection("sel7" , ptrmrk, 16 , 4 , 4);
		ptrmrk->addChildNode(ptrsel);
		ptrsel = new Selection("sel8" , ptrmrk, 16 , 4 , 4);
		ptrmrk->addChildNode(ptrsel);

	ptrsub = new SubCategory("sub2" , ptrcat);
		ptrcat->addChildNode(ptrsub);
		ptreve = new Event("eve3" , ptrsub, 4 ,4 ,4 ,4,4);
		ptrsub->addChildNode(ptreve);
		ptrmrk = new Market("mrk5" , ptreve);
		ptreve->addChildNode(ptrmrk);
		ptrsel = new Selection("sel9" , ptrmrk, 16 , 4 , 4);
		ptrmrk->addChildNode(ptrsel);
		ptrsel = new Selection("sel10" , ptrmrk, 16 , 4 , 4);
		ptrmrk->addChildNode(ptrsel);

	ptrmrk = new Market("mrk6" , ptreve);
		ptreve->addChildNode(ptrmrk);
		ptrsel = new Selection("sel11" , ptrmrk, 16 , 4 , 4);
		ptrmrk->addChildNode(ptrsel);
		ptrsel = new Selection("sel12" , ptrmrk, 16 , 4 , 4);
		ptrmrk->addChildNode(ptrsel);

	ptreve = new Event("eve4" , ptrsub , 4 ,4 ,4 ,4,4);
		ptrsub->addChildNode(ptreve);
		ptrmrk = new Market("mrk7" , ptreve);
			ptreve->addChildNode(ptrmrk);
			ptrsel = new Selection("sel13" , ptrmrk, 16 , 4 , 4);
			ptrmrk->addChildNode(ptrsel);
			ptrsel = new Selection("sel14" , ptrmrk, 16 , 4 , 4);
			ptrmrk->addChildNode(ptrsel);

		ptrmrk = new Market("mrk8" , ptreve);
			ptreve->addChildNode(ptrmrk);
			ptrsel = new Selection("sel15" , ptrmrk, 16 , 4 , 4);
			ptrmrk->addChildNode(ptrsel);
			ptrsel = new Selection("sel16" , ptrmrk, 16 , 4 , 4);
			ptrmrk->addChildNode(ptrsel);
*/
