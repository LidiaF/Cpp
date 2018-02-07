CC=g++

CFLAGS=-c -Wall -std=c++11

all: DFS

DFS:	main.o  
	$(CC) -o DFS main.o 

main.o: main.cpp vertex.h
	$(CC) $(CFLAGS) main.cpp 

clean:
	rm -rf *o DFS

