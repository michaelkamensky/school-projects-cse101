SHELL := /bin/sh
CC = gcc 
CFLAGS = -std=c17
#CFLAGS = -Wall -Wpedantic -Werror -Wextra -g $(shell pkg-config --cflags gmp)
CFLAGS += -g
#LFLAGS = $(shell pkg-config --libs gmp)
Lex_objects = Lex.o List.o 


all: Lex ListTest

Lex: $(Lex_objects)
	$(CC) $(CFLAGS) -o $@ $?

ListTest: ListTest.o List.o
	$(CC) $(CFLAGS) -o $@ $?

Lex.o: Lex.c
	$(CC) $(CFLAGS)  -c $<

List.o: List.c
	$(CC) $(CFLAGS)  -c $<

ListTest.o: ListTest.c
	$(CC) $(CFLAGS)  -c $<

clean:
	rm -f Lex *.o

