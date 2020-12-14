#ifndef STONE_CPP
#define STONE_CPP

#include "Stone.hpp"

Stone::Stone()
{
	owner = 0;
	placed = false;
	territory = false;	
	character = '+';
}

Stone::~Stone()
{
	owner = -1;
	placed = false;
	territory = false;
}

#endif
