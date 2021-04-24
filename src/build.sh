#!/bin/bash
g++ -fPIC -c Stone.cpp Board.cpp
sudo gcc -shared *.o -o /usr/local/lib/libtb2.so
sudo chmod 755 /usr/local/lib/libtb2.so
