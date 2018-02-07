CC=g++

CFLAGS=-c -Wall -std=c++11

all: im

im:	main.o interval_map.o
	$(CC) -o im  main.o interval_map.o

main.o: main.cpp interval_map.h
	$(CC) $(CFLAGS) main.cpp

interval_map.o:	interval_map.cpp interval_map.h
		$(CC) $(CFLAGS) interval_map.cpp 

clean:
	rm -rf *o im

