CC=g++

CFLAGS=-c -Wall -std=c++11

all: mm

mm:	main.o 
	$(CC) -o mm main.o 

main.o: main.cpp matrix.h
	$(CC) $(CFLAGS) main.cpp 

clean:
	rm -rf *o mm

