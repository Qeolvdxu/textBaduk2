#!/bin/bash
sudo cp include/textbaduk2.h /usr/local/include/textbaduk2.h
g++ -fPIC -c src/Stone.cpp src/Board.cpp
sudo gcc -shared *.o -o /usr/local/lib/libtextbaduk2.so
sudo chmod 755 /usr/local/lib/libtextbaduk2.so
rm *.o
echo Done
