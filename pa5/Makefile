#------------------------------------------------------------------------------
#  Makefile for List ADT
#
#  make                makes Shuffle
#  make ListClient     make ListClient
#  make clean          removes binary files
#  make check1         runs valgrind on ListClient
#  make check2         runs valgrind on Shuffle with CLA 35
#------------------------------------------------------------------------------

Shuffle : Shuffle.o List.o
	g++ -std=c++17 -Wall -g -o Shuffle Shuffle.o List.o 

Shuffle.o : List.h Shuffle.cpp
	g++ -std=c++17 -Wall -g -c Shuffle.cpp

ListClient : ListClient.o List.o
	g++ -std=c++17 -Wall -g -o ListClient ListClient.o List.o 

ListClient.o : List.h ListClient.cpp
	g++ -std=c++17 -Wall -g -c ListClient.cpp

ListTest : ListTest.o List.o
	g++ -std=c++17 -Wall -g -o ListTest ListTest.o List.o 

ListTest.o : List.h ListTest.cpp
	g++ -std=c++17 -Wall -g -c ListTest.cpp

List.o : List.h List.cpp
	g++ -std=c++17 -Wall -g -c List.cpp

clean :
	rm -f Shuffle Shuffle.o ListClient ListTest  ListClient.o List.o ListTest.o 

check1 : ListClient
	valgrind --leak-check=full ListClient

check2 : Shuffle
	valgrind --leak-check=full Shuffle 35
