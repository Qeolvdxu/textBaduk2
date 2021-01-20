SOURCE_PATH = ./src
HEADER_PATH = ./include

SOURCE_FILES = ${SOURCE_PATH}/testBoard.cpp ${SOURCE_PATH}/Stone.cpp ${SOURCE_PATH}/Board.cpp

HEADER_FILES = 	${HEADER_PATH}/Stone.hpp ${HEADER_PATH}/Board.hpp

OUT	= test
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(HEADER_FILES) $(SOURCE_FILES) $(LFLAGS)

testBoard.o: testBoard.cpp
	$(CC) $(FLAGS) testBoard.cpp 

Stone.o: Stone.cpp
	$(CC) $(FLAGS) Stone.cpp 

Board.o: Board.cpp
	$(CC) $(FLAGS) Board.cpp 


clean:
	rm -f $(OBJS) $(OUT)
