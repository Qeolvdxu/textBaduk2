#ifndef STONE_CPP
#define STONE_CPP

#include "Stone.hpp"

Group::Group(int newSize)
{
	size = newSize;
	stones = new Stone(size);	
}

Group::~Group()
{
	size = 0;
}

#endif
