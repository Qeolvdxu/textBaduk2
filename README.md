See"https://github.com/Qeolvdxu/termGo" for a example on how to use this for a basic go board
(You must install this library where your compiler can see it (there is a script included to install locally))

textbaduk2 is an collection of header and source files meant for simulating a game of Go/Baduk in c++
The goal of this program is to allow a game of go for the simply run in the terminal with or without a user interface quickly and let humans and/or other programs to play.
There are also TUI elements with the Board class for viewing the game in a terminal found in BoardGUI.cpp (this function is seperate because it is optional and can be deleted)
The game is made up of these 2 classes

Stones: This class is used to store variables about an exact location on the game board
  the class is initalized with no input variables
  it contains 4 children which are pointers to the stones which location puts them above, below, left, and right relative to the main stone
  it contains a character which the spot on the board is represented by (these should be either a players character or a '+')
  it contains a boolean for being marked by the capture process to see if the stone has already been checked
  There are functions for setting and returning all of these variables
  
Boards: This class is the main component and includes the graphical aspects, all of the stones, and manages the game itself
  it contains one 2d array of pointers to all of the stones in the game which is equal to the size of the game squared
  the class is initalized with a size variable in the form of an integer so specify the length and height of the board
  printBoard() prints everything the user will see except for errors and other system messages
  placeStone() lets a player place a stone on the specifed coordinates int he form of two integers (row, column)
    this function returns a boolean which specifies if the placement is safe or it is an illegal move
  changePlayer() will rotate the current player out of the next player in line
  checkCap() will check the group of the specified stone if it is captured or not and deals with that capture
