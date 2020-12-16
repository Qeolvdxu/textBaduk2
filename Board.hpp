#ifndef GROUP_HPP
#define GROUP_HPP

#include "Stone.hpp"
#include "Group.hpp"

class Board 
{
	private:
		Stone** array;
		int size;
	public:
		Board(int newSize); 
		virtual ~Board();
		void printBoard(char player);
};

#include "Board.cpp"

#endif
