#ifndef STONE_HPP
#define STONE_HPP

class Stone
{
	private:
		int owner;		// which player owns
		bool placed; 	// true if someone has placed this stone
		bool territory; // true if this space counts towards territory
	public:
		char character;

		Stone(); 
		virtual ~Stone();
//		place(int player); // called when a player places a stone
};

#include "Stone.cpp"

#endif
