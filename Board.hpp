#ifndef GROUP_HPP
#define GROUP_HPP

#include "Stone.hpp"
#include "Group.hpp"

class Board 
{
	private:
		Stone** array;
		int size;
		char player;
	public:
		Board(int newSize); 
		virtual ~Board();
		void printBoard();
		void placeStone();
		void changePlayer();
};

#include "Board.cpp"

#endif
