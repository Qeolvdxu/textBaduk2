#ifndef BOARD_CPP
#define BOARD_CPP

#include "Board.hpp"

Board::Board(int newSize)
{
	size = newSize;
	
	//Create 2d Array for board
	array = new Stone*(size);	
	for(i=0; i<row; i++)
		array[i] = new Stone[size];
}

Board::~Board()
{
	size = 0;
}

void Board::printBoard()
{
	int collum = 0;
	cout << "\u001b[2J"
	<< "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n"
    << "The turn belongs to player " << player << "\n\n"
    << "   0  1  2  3  4  5  6  7  8  9\n\n";

    for(int row = 0; row < 10; row++)
    {
         line = row * 10;
         cout << row << "  ";
         for (int j = 0; j < 10; j++)
         {
	         cout << array[row][collum].character;
             if (j < 9)
   	         	cout << "--";
             else
                cout << '\n'; 
          }
          if (row < 9)
          	 cout << "   |  |  |  |  |  |  |  |  |  |\n";
	}
}

#endif
