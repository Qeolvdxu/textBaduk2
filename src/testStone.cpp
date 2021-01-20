#ifndef STONE_CPP
#define STONE_CPP

#include "../include/Stone.hpp"

int main(void)
{
	Stone* testStone1 = new Stone();	
	Stone* testStone2 = new Stone();	
	Stone* testStone3 = new Stone();	

	testStone1->setUpChild(0);
	testStone1->setDownChild(testStone2);
	testStone1->setLeftChild(testStone3);
	testStone1->setRightChild(0);

	delete testStone1;
	delete testStone2;
	delete testStone3;
	return 0;
}

#endif
