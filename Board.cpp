#ifndef BOARD_CPP
#define BOARD_CPP

#include <iostream> 

#include "Board.hpp"

using namespace std;

Board::Board(int newSize)
{
	size = newSize;
	
	//Create 2d Array for board
	array = new Stone*[size];	
	for(int i=0; i<size; i++)
		array[i] = new Stone[size];
}

Board::~Board()
{
	size = 0;
}

void Board::printBoard(char player)
{
	cout << "\u001b[2J" //clears screen on both windows and unix-likes
	<< "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n"
    << "The turn belongs to player " << player << "\n\n"
    << "   ";
	for (int i = 0; i < size; i++)
		cout << i << "  ";
	cout << "\n\n";

    for(int i = 0; i < size; i++)
    {
         cout << i << "  ";
         for (int j = 0; j < size; j++)
         {
	         cout << array[i][j].character;
             if (j < size-1)
   	         	cout << "--";
             else
                cout << '\n'; 
          }
          if (i < size-1)
		  {
    		cout << "   ";
			for (int i = 0; i < size; i++)
				cout << '|' << "  ";
			cout << "\n";
		  }
	}
}

#endif
