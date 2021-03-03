#include <iostream>

#include "../include/Board.hpp"

using namespace std;

int main(void)
{
	Board* testBoard = new Board(18);

// Places preset stones to test caputres
	testBoard->placeStone(10,9);
	testBoard->placeStone(9,9);
	testBoard->placeStone(8,9);
	testBoard->placeStone(7,9);
	testBoard->placeStone(9,13);
	testBoard->placeStone(8,13);
	testBoard->placeStone(7,13);
	testBoard->placeStone(7,12);
	testBoard->placeStone(7,11);
	testBoard->placeStone(7,10);

	testBoard->placeStone(10,10);
	testBoard->placeStone(10,11);
	testBoard->placeStone(10,12);
	testBoard->placeStone(10,13);
	testBoard->placeStone(11,10);
	testBoard->placeStone(11,13);
	testBoard->placeStone(12,10);
	testBoard->placeStone(12,11);
	testBoard->placeStone(12,12);
	testBoard->placeStone(11,8);
	testBoard->placeStone(5,5);

	testBoard->changePlayer();

	testBoard->placeStone(11,11);
	testBoard->placeStone(9,10);
	testBoard->placeStone(9,11);
	testBoard->placeStone(9,12);
	testBoard->placeStone(8,10);
	testBoard->placeStone(8,11);
	testBoard->placeStone(8,12);
//	testBoard->placeStone(11,12);

// Takes user input to play
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
		testBoard->checkAllCaps();

//		testBoard->changePlayer();
	}

	return 0;
}
