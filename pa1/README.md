# Programming Assignment 1 

## Description
In this assignment, I created a List ADT to sort the lines of a file alphabetically and then writting the result into another file. The List is made using a doubly linked list, and has a cursor that can move around. Using commands you can maniplute the list adding elements, removing them, and reading them.

This is a response to [pa1](https://people.ucsc.edu/~ptantalo/cse101/Spring23/pa1.pdf) in [Cse101 course](https://people.ucsc.edu/~ptantalo/cse101/Spring23/)

## File Descriptions

### Lex.c
The program with the main function that sorts the inputfile lines alphabetically and writes the output to the outputfile

### List.c
This is the program that holds the list adt which can be modified using commands and a cursor

### ListTest.c
This file contains the tests that I used to test out the List ADT and iron out any bugs

### List.h
This is the front end header file for the list; contains all public prototypes for the List.c

### Makefile
This file builds the Lex executable and ListTest executables, and clean all executables

### README
Contains the documentation for this project gives instructions on how to use the project

## Installation
First you need to compile all appropirate c files to create sorting: run make as follows
```
make clean && make
```

## Usage
To run this program run encode as follows
```
./Lex.c [inputfile] [outputfile]
```


## Support
Please contact mkamensk@ucsc.edu if you need help or provide feedback for this project


## Author
Michael V. Kamensky