CC = g++
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/segmentTree.o $(OBJ)/matrix.o
HDRS = $(INC)/segmentTree.hpp $(INC)/matrix.hpp
CFLAGS = -Wall -c -g -I$(INC) -std=c++11

EXE = $(BIN)/tp3.out

.PHONY: all clean

run: all
	$(EXE)

all: $(EXE)

$(BIN)/tp3.out: $(OBJS)
	$(CC) -std=c++11 -g -o $(BIN)/tp3.out $(OBJS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/matrix.o: $(HDRS) $(SRC)/matrix.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/matrix.o $(SRC)/matrix.cpp

$(OBJ)/segmentTree.o: $(HDRS) $(SRC)/segmentTree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/segmentTree.o $(SRC)/segmentTree.cpp


clean:
	rm -f $(EXE) $(OBJS) gmon.out