#!/bin/bash
g++ -fPIC -c src/Stone.cpp src/Board.cpp
sudo gcc -shared *.o -o /usr/lib/libtextbaduk2.so
sudo chmod 755 /usr/lib/libtextbaduk2.so
sudo cp include/textbaduk2.h /usr/include/textbaduk2.h
rm *.o
echo Done
