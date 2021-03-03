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
		bool placeStone(int row, int collum);
		void changePlayer();
		void checkCap(Stone* stone);
		void checkAllCaps();
};

#endif
