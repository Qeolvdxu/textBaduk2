#ifndef STONE_CPP
#define STONE_CPP

#include "../include/Stone.hpp"

Stone::Stone()
{
	owner = 0;
	placed = false;
	territory = false;	
	character = '+';
	checked = false;
	
	childUp = 0;
	childDown = 0;
	childLeft = 0;
	childRight = 0;
}

Stone::~Stone()
{
	owner = -1;
	placed = false;
	territory = false;
}

void Stone::setUpChild(Stone* newChild)
{
	childUp = newChild;
}
void Stone::setDownChild(Stone* newChild)
{
	childDown = newChild;
}
void Stone::setLeftChild(Stone* newChild)
{
	childLeft = newChild;
}
void Stone::setRightChild(Stone* newChild)
{
	childRight = newChild;
}
void Stone::setChar(char newChar)
{
	character = newChar;
}

char Stone::getChar()
{
	return character;
}
Stone* Stone::getUpChild()
{
	return childUp;
}
Stone* Stone::getDownChild()
{
	return childDown;
}
Stone* Stone::getLeftChild()
{
	return childLeft;
}
Stone* Stone::getRightChild()
{
	return childRight;
}
void Stone::setChecked(bool newValue)
{
	checked = newValue;
}
bool Stone::getChecked()
{
	return checked;
}

#endif
