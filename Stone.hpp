#ifndef STONE_HPP
#define STONE_HPP

class Stone
{
	private:
		int owner;		// which player owns
		bool placed; 	// true if someone has placed this stone
		bool territory; // true if this space counts towards territory
		char character;

		// children based on boared position
		Stone* childUp;
		Stone* childDown;
		Stone* childLeft;
		Stone* childRight;
	public:

		Stone(); 
		virtual ~Stone();

		void setUpChild(Stone* newChild);
		void setDownChild(Stone* newChild);
		void setLeftChild(Stone* newChild);
		void setRightChild(Stone* newChild);
		void setChar(char newChar);

		char getChar();
		Stone* getUpChild();
		Stone* getDownChild();
		Stone* getLeftChild();
		Stone* getRightChild();

//		place(int player); // called when a player places a stone
};

#endif
