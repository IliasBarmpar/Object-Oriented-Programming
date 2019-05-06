#include "Phases.hpp"

class GameBoard {
	private:
		list <Player*> *players;
		int plysize;
	public:
		GameBoard();
		void initializeGameBoard();
		void printGameStatistics();
		void printArena();
		void gameplay();
		int size();
		Player * givePlayer(int x);
		int getInitialDefence(Player *player);
};

