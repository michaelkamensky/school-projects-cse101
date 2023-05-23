# Programming Assignment 6

## Description
In this assignment, I created a BigInteger ADT and a main arithmetic class that uses the ADT to preform some basic operations

This is a response to [pa6](https://people.ucsc.edu/~ptantalo/cse101/Spring23/pa6.pdf) in [Cse101 course](https://people.ucsc.edu/~ptantalo/cse101/Spring23/)

## File Descriptions

### Arithmetic.cpp
A main class that uses the BigInteger ADT to preform some opertations

### BigInteger.h
A header file with all the public protypes for the BigInteger ADT

### BigInteger.cpp
A BigInteger ADT that creates a large int through a list of longs that can be added subtracted and mulitplied with other big ints

### BigIntegerTest.cpp
A test for my BigInteger ADT

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
./Arithmetic [input_file] [output_file] 
```

## Support
Please contact mkamensk@ucsc.edu if you need help or provide feedback for this project


## Author
Michael V. Kamensky