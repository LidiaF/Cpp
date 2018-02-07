CC=g++

CFLAGS=-c -Wall -std=c++11

all: cr

cr:	main.o  
	$(CC) -o cr main.o 

main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp 

clean:
	rm -rf *o cr

