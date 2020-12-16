#include "Board.cpp"

int main(void)
{
	int size = 9;
	Board* testBoard = new Board(size);
	testBoard->printBoard('T'); //T for test
	return 0;
}
