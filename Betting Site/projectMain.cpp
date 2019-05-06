#include "Users.hpp"
#include "System.hpp"
#include <iostream>

using namespace std;

int main(void){
	Selection* ptrsel;
	Market* ptrmrk;
	Event* ptreve;
	SubCategory* ptrsub;
	Category* ptrcat;

	Hierarchy hs("hs" , NULL);

	ptrcat = new Category("cat1" , &hs);
	hs.addChildNode(ptrcat);
	ptrsub = new SubCategory("sub1" , ptrcat);
	ptrcat->addChildNode(ptrsub);
	ptreve = new Event("eve1" , ptrsub);
	ptrsub->addChildNode(ptreve);
	ptrmrk = new Market("mrk1" , ptreve);
	ptreve->addChildNode(ptrmrk);
	ptrsel = new Selection("sel1" , ptrmrk);
	ptrmrk->addChildNode(ptrsel);

	ptrsel = new Selection("sel2" , ptrmrk);
	ptrmrk->addChildNode(ptrsel);

	ptrmrk = new Market("mrk2" , ptreve);
	ptreve->addChildNode(ptrmrk);
	ptrsel = new Selection("sel3" , ptrmrk);
	ptrmrk->addChildNode(ptrsel);
	ptrsel = new Selection("sel4" , ptrmrk);
	ptrmrk->addChildNode(ptrsel);

	ptreve = new Event("eve2" , ptrsub);
		ptrsub->addChildNode(ptreve);
		ptrmrk = new Market("mrk3" , ptreve);
			ptreve->addChildNode(ptrmrk);
			ptrsel = new Selection("sel5" , ptrmrk);
			ptrmrk->addChildNode(ptrsel);
			ptrsel = new Selection("sel6" , ptrmrk);
			ptrmrk->addChildNode(ptrsel);

	ptrmrk = new Market("mrk4" , ptreve);
		ptreve->addChildNode(ptrmrk);
		ptrsel = new Selection("sel7" , ptrmrk);
		ptrmrk->addChildNode(ptrsel);
		ptrsel = new Selection("sel8" , ptrmrk);
		ptrmrk->addChildNode(ptrsel);

	ptrsub = new SubCategory("sub2" , ptrcat);
		ptrcat->addChildNode(ptrsub);
		ptreve = new Event("eve3" , ptrsub);
		ptrsub->addChildNode(ptreve);
		ptrmrk = new Market("mrk5" , ptreve);
		ptreve->addChildNode(ptrmrk);
		ptrsel = new Selection("sel9" , ptrmrk);
		ptrmrk->addChildNode(ptrsel);
		ptrsel = new Selection("sel10" , ptrmrk);
		ptrmrk->addChildNode(ptrsel);

	ptrmrk = new Market("mrk6" , ptreve);
		ptreve->addChildNode(ptrmrk);
		ptrsel = new Selection("sel11" , ptrmrk);
		ptrmrk->addChildNode(ptrsel);
		ptrsel = new Selection("sel12" , ptrmrk);
		ptrmrk->addChildNode(ptrsel);

	ptreve = new Event("eve4" , ptrsub);
		ptrsub->addChildNode(ptreve);
		ptrmrk = new Market("mrk7" , ptreve);
			ptreve->addChildNode(ptrmrk);
			ptrsel = new Selection("sel13" , ptrmrk);
			ptrmrk->addChildNode(ptrsel);
			ptrsel = new Selection("sel14" , ptrmrk);
			ptrmrk->addChildNode(ptrsel);

		ptrmrk = new Market("mrk8" , ptreve);
			ptreve->addChildNode(ptrmrk);
			ptrsel = new Selection("sel15" , ptrmrk);
			ptrmrk->addChildNode(ptrsel);
			ptrsel = new Selection("sel16" , ptrmrk);
			ptrmrk->addChildNode(ptrsel);

	string s = "yolo";
	System *syst;
	syst = new System( hs , 5);
	Guest *guest;
	guest = new Guest;
	syst->navigate_OnTheSystem(guest);
	return 0;


}
