#ifndef BOARD_CPP
#define BOARD_CPP

#include <iostream> 

#include "../include/Board.hpp"

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
//	cout << "\u001b[2J" //clears screen on both windows and unix-likes
	//<< "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n"
    cout << "The turn belngs to player " << player << "\n\n"
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

void Board::placeStone(int row, int collum) //simply gets user input and changes the respective stones character
{
	bool valid = false;
	do
	{
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
	this->checkCap(array[row][collum]);
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
	Stone* current = stone;
	Stone* group[size*size];
	Stone* liberts[4];
	int groupCounter = 0;

	// Form group of most recent placement
	//current->setChecked(true);	
	for(int i = 0; i < groupCounter + 1; i++)
	{
		if (current->getUpChild() != 0)
			liberts[0] = current->getUpChild();
		if (current->getDownChild() != 0)
			liberts[1] = current->getDownChild();
		if (current->getLeftChild() != 0)
			liberts[2] = current->getLeftChild();
		if (current->getRightChild() != 0)
			liberts[3] = current->getRightChild();
		for (int j = 0; j < 4; j++)
		{
				if ( liberts[j]->getChecked() == false) 
				{
					cout << j << ": \n" << groupCounter << '\n';
					// Friendly Stone
					if (liberts[j]->getChar() == player)
					{
						cout << "Friendly Player!";
						group[groupCounter] = liberts[j];//current;
						groupCounter++;
						current = liberts[j];
					}
					// Enenmy Stone
					else if (liberts[j]->getChar() == '+')
					{
						cout << "SAFE!" << liberts[j]->getChar();
					}
					// Empty Space
					else
					{
						cout << "Enemy!";
					}
					cout << "\n";
					liberts[j]->setChecked(true);
				}
		}
	}

	//Check if group is captured
	bool safe = false; //assume group is dead until proven otherwise
	for (int i = 0; i < groupCounter; i++)
	{
		if (group[i]->getUpChild()->getChar()    == '+')
			safe = true;
		if (group[i]->getDownChild()->getChar()  == '+')
			safe = true;
		if (group[i]->getLeftChild()->getChar()  == '+')
			safe = true;
		if (group[i]->getRightChild()->getChar() == '+')
			safe = true;
	}	

	//Deal with captured group
	if (safe == false)
	{
		for (int i = 0; i < groupCounter; i++)
		{
			group[i]->setChar('+');
		}
	}


	//Reset for next Check
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			array[i][j]->setChecked(false);
		}
	}
}

/*
void Board::checkCap(Stone* stone) //checks and deals with one singular stone 
{
	Stone* current = stone;
	bool safe = false; // Assume the string of stones is not safe from being captured until proven otherwise
	Stone* liberts[4];
	int checkedCounter = 0;
	int checkedGoal = 0;
	
	current->setChecked(true);

	while(safe == false)
	{
		liberts[0] = current->getUpChild();
		liberts[1] = current->getDownChild();
		liberts[2] = current->getLeftChild();
		liberts[3] = current->getRightChild();
		for (int i = 0; i < 4; i++)
		{
			if (liberts[i]->getChecked() == false)
			{
				// If Lib is Friendly Stone
				if(liberts[i]->getChar() == player)
				{
					current = liberts[i];
				}
	
				// If Lib is Empty Space
				if(liberts[i]->getChar() == '+');
				{
					safe = true;
				}

				// If Lib is Enemy Stone
				if(liberts[i]->getChar() != player && liberts[i]->getChar() != '+')	
				{
					checkedCounter++;
				}

				if (liberts[i]->getChecked() == false)
					checkedGoal++;
				liberts[i]->setChecked(true);
			}
		}
		cout << checkedCounter << "\nsafe:" << safe << "\nChecked Goal:" << checkedGoal << '\n';
		if (checkedCounter >= checkedGoal)
		{
			safe = false;
			stone->setChar('X');
			break;
		}	
	}

	//Reset for next Check
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			array[i][j]->setChecked(false);
		}
	}
	
}
*/
void Board::checkAllCaps() //checks and deals with any captured stone
{
			
}

#endif
