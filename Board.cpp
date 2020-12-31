#ifndef BOARD_CPP
#define BOARD_CPP

#include <iostream> 

#include "Board.hpp"

using namespace std;

Board::Board(int newSize)
{
	size = newSize;
	player = '0';

	//Create and fill 2d array for board
	array = new Stone** [size];
	for (int i = 0; i < size; i++) 
	{
	    array[i] = new Stone*[size];

        for (int j = 0; j < size; ++j)
            array[i][j] = new Stone;
    }

	//Set Stone Children
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			if (i > 0)
				array[i][j]->setUpChild    (array[i-1][j]);
			if (i < size-1)
				array[i][j]->setDownChild  (array[i+1][j]);
			if (j > 0)
				array[i][j]->setLeftChild  (array[i][j-1]);
			if (j < size-1)
				array[i][j]->setRightChild (array[i][j+1]);
		}
	}
	
}

Board::~Board()
{
	for (int i = 0; i < size; i++) 
	{
   		for (int j = 0; j < size; j++)
		{
       		//delete array[i][j]; // delete pointer for each
   		}
	}
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
	{
		cout << i << ' ';
		if (i < 10)
			cout << ' ';
	}
	cout << "\n\n";

	// print remaining rows
    for(int i = 0; i < size; i++)
    {
         cout << i << ' ';
		 if (i < 10)
			cout << ' ';
         for (int j = 0; j < size; j++)
         {
	         cout << array[i][j]->getChar();
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

void Board::placeStone() //simply gets user input and changes the respective stones character
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
			if (array[row][collum]->getChar() == '+')
			{
				array[row][collum]->setChar(player);
				valid = true;
			}
			else
				cout << "\nInvalid Placement!\n";
		}
	}while(!valid);
}

void Board::changePlayer() //flip players on turn change
{
	if(player == '0')
		player = 'O';
	else if(player == 'O')
		player = '0';
}

void Board::checkCap(Stone* stone) //checks and deals with one singular stone 
{
	Stone* up = stone->getUpChild();
	Stone* down = stone->getDownChild();
	Stone* left = stone->getLeftChild();
	Stone* right = stone->getRightChild();
}

void Board::checkAllCaps() //checks and deals with any captured stone
{
		
}

#endif
