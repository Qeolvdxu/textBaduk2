#include <iostream>

#include "../include/Board.hpp"

using namespace std;

int main(void)
{
	Board* testBoard = new Board(18);

// Places preset stones to test caputres
	testBoard->placeStone(10,9);
	testBoard->placeStone(12,9);

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
//	testBoard->placeStone(11,12);

// Takes user input to play
	int row, collum;
	bool running = true;
	while(running)
	{
		testBoard->printBoard();
		cin >> row;	
		cin >> collum;	
		testBoard->placeStone(row,collum);
		testBoard->checkAllCaps();

//		testBoard->changePlayer();
	}

	return 0;
}
