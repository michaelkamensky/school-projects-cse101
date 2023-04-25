# Programming Assignment 3

## Description
In this assignment, I created a graph ADT that uses a depth first seach and transpose to find strongly connected components

This is a response to [pa3](https://people.ucsc.edu/~ptantalo/cse101/Spring23/pa3.pdf) in [Cse101 course](https://people.ucsc.edu/~ptantalo/cse101/Spring23/)

## File Descriptions

### FindComponents.c
The program with the main function that reads a file interprets it creates a graph and finds the strongly related components and outputs the result into an output file

### List.c
This is the program that holds the list adt which can be modified using commands and a cursor

### List.h
This is the public header file for the list; contains all public prototypes for the List.c

### Graph.c
This is the program that holds the graph adt it can build graphs and run a depth first search

### Graph.h
This is the public header file for the Graph; contains all public prototypes for the Graph.c

### GraphTest.c
This file contains the tests that I used to test out the Graph ADT and iron out any bugs

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
./FindComponents [inputfile] [outputfile]
```


## Support
Please contact mkamensk@ucsc.edu if you need help or provide feedback for this project


## Author
Michael V. Kamensky