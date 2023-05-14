# Programming Assignment 5

## Description
In this assignment, I created a List ADT and a shuffle program. The Shuffle program takes list of different sizes and preforms the perfect shuffle on them until the list returns to its orignal state

This is a response to [pa5](https://people.ucsc.edu/~ptantalo/cse101/Spring23/pa5.pdf) in [Cse101 course](https://people.ucsc.edu/~ptantalo/cse101/Spring23/)

## File Descriptions

### Shuffle.cpp
Build lists of a certain size based of a commandline argumnet and then does a card shuffle until the decks are back to their original states the program also tracks how many times it does it 

### List.cpp
This is the code for doubly linked list in C++ 

### List.h
This is the public header file for the list; contains all public prototypes for the List.cpp

### ListTest.cpp
This is the code that tests the list ADT

### Makefile
This file builds the shuffle executable and also can clean all executables

### README/README.md
Contains the documentation for this project gives instructions on how to use the project

## Installation
First you need to compile all appropirate c files to create sorting: run make as follows
```
make clean && make
```

## Usage
To run this program run encode as follows
```
./Shuffle [input_int_] 
```

## Support
Please contact mkamensk@ucsc.edu if you need help or provide feedback for this project


## Author
Michael V. Kamensky