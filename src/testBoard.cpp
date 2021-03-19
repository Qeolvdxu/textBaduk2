#include <iostream>

#include "../include/Board.hpp"

using namespace std;

int main(void)
{
	Board* testBoard = new Board(18);

	int row, collum;
	bool running = true;
	bool safe = false;

	while(running)
	{
		testBoard->printBoard();
		do{
			cin >> row;	
			cin >> collum;	
			safe = testBoard->placeStone(row,collum);
		} while(safe == false);
		testBoard->changePlayer();
	}

	return 0;
}
