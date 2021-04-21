#ifndef BOARDGUI_CPP
#define BOARDGUI_CPP

#include <iostream> 

#include "../include/Board.hpp"

using namespace std;

void Board::printBoard()
{
	cout << "\u001b[2J" //clears screen on both windows and unix-likes
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

#endif
