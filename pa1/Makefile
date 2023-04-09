SHELL := /bin/sh
CC = gcc
#CFLAGS = -Wall -Wpedantic -Werror -Wextra -g $(shell pkg-config --cflags gmp)
#CFLAGS = -g
#LFLAGS = $(shell pkg-config --libs gmp)
Lex_objects = Lex.o List.o ListTest.o


all: Lex

Lex: $(Lex_objects)
	$(CC) -o $@ $(Lex_objects)

Lex.o: Lex.c
	$(CC) -c $<

List.o: List.c
	$(CC) -c $<

ListTest.o: ListTest.c
	$(CC) -c $<

clean:
	rm -f Lex *.o

