# Programming Assignment 8

## Description
In this assignment, I created a Dictionary ADT that uses a REB-BLACK Binary Tree to simulate a dictionary
This is a response to [pa8](https://people.ucsc.edu/~ptantalo/cse101/Spring23/pa8.pdf) in [Cse101 course](https://people.ucsc.edu/~ptantalo/cse101/Spring23/)

## File Descriptions

### Order.cpp
A main class that uses the dictionary ADT to construct and dictionary and return an inorder and preorder string representation

### WordFrequency.cpp
A main class that uses the dictionary ADT to construct and dictionary of the frequencies of words in a file

### Dictionary.h
A header file with all the public protypes for the Dictionary ADT

### Dictionary.cpp
The defintions for the Dictionary ADT uses RED-BLACK Binary Trees to simulate the dictionary construct

### DictionaryTest.cpp 
A test for the dictionary ADT functions

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
./Order [input_file] [output_file] 
```

```
./WordFrequency [input_file] [output_file] 
```

## Support
Please contact mkamensk@ucsc.edu if you need help or provide feedback for this project


## Author
Michael V. Kamensky