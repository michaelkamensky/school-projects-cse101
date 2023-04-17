SHELL := /bin/sh
CC = gcc 
CFLAGS = -std=c17
CFLAGS += -Wall -Wpedantic -Werror -Wextra 
CFLAGS += -g
#LFLAGS = $(shell pkg-config --libs gmp)
FindPath_objects = FindPath.o Graph.o 


all: FindPath GraphTest

FindPath: $(FindPath_objects)
	$(CC) $(CFLAGS) -o $@ $^

GraphTest: GraphTest.o Graph.o
	$(CC) $(CFLAGS) -o $@ $^

FindPath.o: FindPath.c
	$(CC) $(CFLAGS)  -c $<

Graph.o: Graph.c
	$(CC) $(CFLAGS)  -c $<

GraphTest.o: GraphTest.c
	$(CC) $(CFLAGS)  -c $<



clean:
	rm -f Lex ListTest *.o