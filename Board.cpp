#ifndef BOARD_CPP
#define BOARD_CPP

#include <iostream> 

#include "Board.hpp"

using namespace std;

Board::Board(int newSize)
{
	size = newSize;
	player = '0'; //set to E for error checking	

	//Create 2d Array for board
	array = new Stone*[size];	
	for(int i=0; i<size; i++)
		array[i] = new Stone[size];

	//Set Stone Children
}

Board::~Board()
{
	size = 0;
}

void Board::printBoard()
{
	cout << "\u001b[2J" //clears screen on both windows and unix-likes
	//<< "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n"
    << "The turn belngs to player " << player << "\n\n"
    << "   ";
	
	// print first row
	for (int i = 0; i < size; i++)
		cout << i << "  ";
	cout << "\n\n";

	// print remaining rows
    for(int i = 0; i < size; i++)
    {
         cout << i << "  ";
         for (int j = 0; j < size; j++)
         {
	         cout << array[i][j].getChar();
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

void Board::placeStone()
{
	int row;
	int collum;
	bool valid = false;
	do
	{
		cin >> row;
		cin >> collum;
		if (row >= size || collum >= size)
			cout << "\nOut Of Bounds!\n";
		else
		{
			if (array[row][collum].getChar() == '+')
			{
				array[row][collum].setChar(player);
				valid = true;
			}
			else
				cout << "\nInvalid Placement!\n";
		}
	}while(valid == false);
	//}while(row < size || collum < size || array[row][collum].getChar() == '+');
}

void Board::changePlayer()
{
	if(player == '0')
		player == 'O';
	if(player == 'O')
		player == '0';
}

#endif
