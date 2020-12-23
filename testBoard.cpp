#include <iostream>

#include "Board.hpp"

int main(void)
{
	Board* testBoard = new Board(9);

	bool running = true;
	while(running)
	{
		testBoard->printBoard();
		testBoard->placeStone();
		testBoard->changePlayer();
	}

	return 0;
}
