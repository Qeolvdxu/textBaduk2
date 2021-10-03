# Textbaduk2 

Textbaduk2 is a collection of header and source files meant for simulating a game of [Go/Baduk](https://en.wikipedia.org/wiki/Go_(game)) in C++
The goal of this program is to allow a game of go for the simply run in the terminal with or without an user interface quickly and let humans and/or other programs to play.

See [Qeolvdxu/termGo](https://github.com/Qeolvdxu/termGo) for an example on how to use this for a basic go board
(You must install this library where your compiler can see it (there is a script included to install locally))

There are also TUI elements with the Board class for viewing the game in a terminal found in [BoardGUI.cpp](https://github.com/Qeolvdxu/termGo/blob/main/BoardGUI.cpp) (this function is separate because it is optional and can be deleted)

## Structure

The game is made up of these 2 classes

- [**Stones:**](src/Stone.cpp) This class is used to store variables about an exact location on the game board
    - The class is initialized with **no input variables**
    - It contains **4 children** which are pointers to the stones which location puts them above, below, left, and right relative to the main stone
    - It contains a character which the spot on the board is represented by (these should be either a players character or a '+')
    - It contains a boolean for being marked by the capture process to see if the stone has already been checked
    - There are functions for setting and returning all of these variables
  
- [**Boards:**](src/Board.cpp) This class is the main component and includes the graphical aspects, all of the stones, and manages the game itself
    - It contains one 2D-array of pointers to all of the stones in the game which is equal to the size of the game squared
    - The class is initialized with a size variable in the form of an integer so specify the length and height of the board
    - `printBoard()` prints everything the user will see except for errors and other system messages
    - `placeStone()` lets a player place a stone on the specified coordinates in the form `(row, column)` and returns a boolean which specifies if the placement is safe or it is an illegal move
    - `changePlayer()` will rotate the current player out of the next player in line
    - `checkCap()` will check the group of the specified stone if it is captured or not and deals with that capture

