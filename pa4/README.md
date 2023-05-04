# Programming Assignment 3

## Description
In this assignment, I created a graph ADT that uses a depth first seach and transpose to find strongly connected components

This is a response to [pa4](https://people.ucsc.edu/~ptantalo/cse101/Spring23/pa4.pdf) in [Cse101 course](https://people.ucsc.edu/~ptantalo/cse101/Spring23/)

## File Descriptions

### Sparse.c
The program with the main function that scans file creates two matracies and runs operations on them to print out certain results

### List.c
This is the program that holds the list adt which can be modified using commands and a cursor

### List.h
This is the public header file for the list; contains all public prototypes for the List.c

### Matrix.c
Matrix ADT for sparse matrixes back end functions, uses an array list to simulate a sparse matrix

### Matrix.h
This is the public header file for the Graph; contains all public prototypes for the Graph.c

### MatrixTest.c
A program with a main function that tests all the function of the matrix to see if they work

### Makefile
This file builds the FindComponents and GraphTest executables and also can clean all executables

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
./Sparse [inputfile] [outputfile]
```

## Support
Please contact mkamensk@ucsc.edu if you need help or provide feedback for this project


## Author
Michael V. Kamensky