#ifndef GROUP_HPP
#define GROUP_HPP

#include "Stone.hpp"

class Board 
{
	private:
		Stone*** array;
		int size;
		char player;
	public:
		Board(int newSize); 
		~Board(void);
		void printBoard(void); //optional tui
		bool placeStone(int row, int column);
		void changePlayer(void);
		void checkAllCaps(void);
		void checkCap(int row, int column, char type);
};

#endif
