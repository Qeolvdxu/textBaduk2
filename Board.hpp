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
		~Board();
		void printBoard(); //optional tui
		void placeStone();
		void changePlayer();
		void checkCap();
		void checkAllCaps();
};

#endif
