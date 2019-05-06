#include "APlayer.hpp"
using namespace std;

class StartingPhase {
	public:
		StartingPhase(){};
		void untapEverything(Army army , Holdings holdings);
		void drawFateCard(Hand hand, GreenDeck greendeck);
		void revealProvinces(Provinces provinces);
		void printHand(Hand hand){ hand.print() ;}
		void printProvinces(Provinces provinces){ provinces.print(); }
};

	
