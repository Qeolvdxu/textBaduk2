#include <iostream>

#include "../include/Board.hpp"

using namespace std;

int main(void)
{
	Board* testBoard = new Board(18);
	testBoard->placeStone(3,2);
	testBoard->placeStone(3,3);
	testBoard->placeStone(3,4);
	testBoard->placeStone(3,5);
	testBoard->placeStone(4,2);
	testBoard->placeStone(5,2);
	testBoard->placeStone(4,5);
	testBoard->placeStone(5,5);
	testBoard->placeStone(6,2);
	testBoard->placeStone(6,3);
	testBoard->placeStone(6,4);
	testBoard->placeStone(6,5);

	int row, column;
	bool running = true;
	bool safe = false;

	while(running)
	{
		testBoard->printBoard();
		do{
			cin >> row;	
			if (row == 'e')
				running = false;
			cin >> column;	
			safe = testBoard->placeStone(row,column);
			testBoard->checkCap(row,column);
		} while(safe == false);
		testBoard->changePlayer();
	}

	return 0;
}
