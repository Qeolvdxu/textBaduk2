#ifndef BOARD_CPP
#define BOARD_CPP

#include "textbaduk2.h"

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
	  delete array[i][j]; // delete pointer for each
	}
    }
  size = 0;
}

bool Board::placeStone(int row, int column) //simply gets user input and changes the respective stones character
{
	bool valid = false;
	if (row >= size || column >= size)
	  valid = false;
	else
	  {
	    if (array[row][column]->getChar() == '+')
	      {
		array[row][column]->setChar(player);
		valid = true;
	      }
	    else
			valid = false;
	}
	return valid;
}

void Board::changePlayer() //flip players on turn change
{
  if(player == '0')
    player = 'O';
  else if(player == 'O')
    player = '0';
}

void Board::checkCap(int row, int column, char type) //checks and deals with one singular stone 
{
  Stone* stone = array[row][column];
  Stone* current = stone;
  Stone* group[size*size];
  Stone* liberts[4] = {0};
  int groupCounter = 0;

  group[groupCounter] = stone;
  groupCounter++;
  
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
      
      // Check each liberty of the current stone and if that liberty is a friend then add it to the group and check that stones liberties
      for (int j = 0; j < 4; j++)
	{
	  if (liberts[j] != 0 && liberts[j]->getChecked() == false) 
	    {
	      if (liberts[j]->getChar() == type)
		{
		  group[groupCounter] = liberts[j];
		  groupCounter++;
		  current = liberts[j];
		}
	      liberts[j]->setChecked(true);
	    }
	}
    }
  for (int i = 0; i < groupCounter; i++)
    {
      
      if (group[i]->getUpChild() != 0 && group[i]->getUpChild()->getChar() == type)
	group[groupCounter++] = group[i]->getUpChild();
      if (group[i]->getDownChild() != 0 && group[i]->getDownChild()->getChar() == type)
	group[groupCounter++] = group[i]->getDownChild();
      if (group[i]->getLeftChild() != 0 && group[i]->getLeftChild()->getChar() == type)
	group[groupCounter++] = group[i]->getLeftChild();
      if (group[i]->getRightChild() != 0 && group[i]->getRightChild()->getChar() == type)
	group[groupCounter++] = group[i]->getRightChild();
    }
  
  
  //Check if group is captured
  bool safe = false; //assume group is dead until proven otherwise
  for (int i = 0; i < groupCounter; i++)
	{
	  if (group[i]->getUpChild() != 0 && group[i]->getUpChild()->getChar()    == '+')
	    safe = true;
	  if (group[i]->getDownChild() != 0 && group[i]->getDownChild()->getChar()    == '+')
	    safe = true;
	  if (group[i]->getLeftChild() != 0 && group[i]->getLeftChild()->getChar()    == '+')
	    safe = true;
	  if (group[i]->getRightChild() != 0 && group[i]->getRightChild()->getChar()    == '+')
	    safe = true;
	}	
  
  //Deal with captured group
  if (safe == false)
    {
      for (int i = 0; i < groupCounter; i++)
	{
			if (group[i] != 0)
			  group[i]->setChar('+');
	}
    }
  
}

void Board::checkAllCaps(void) // calls checkcap for each unchecked stone
{
  for(int i = 0; i < size; i++)
    {
      for(int j = 0; j < size; j++)
	{
	  if (array[i][j]->getChecked() == false)
	    this->checkCap(i,j, '0');		
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
  
  for(int i = 0; i < size; i++)
    {
		for(int j = 0; j < size; j++)
		  {
		    if (array[i][j]->getChecked() == false)
		      this->checkCap(i,j, 'O');		
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

#endif
