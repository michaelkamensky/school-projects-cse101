#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "List.h"

/* the main function of this program will use the list.c ADT
to organize it
the main function needs to be able 
1) check the number of arguments given
2) Count the number of lines the inoput file has
3)Create a List whose elements are the indices of the above string array
*/
int main(int argc, char *argv[]) {
    int count = 0;
    char c;

    // Check that we have two file arguments
    if (argc != 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    // open the files
    FILE *input_file = fopen(argv[1], "r");
    FILE *output_file = fopen(argv[2], "w");

    // check if the files are empty if not continues
    if (input_file == NULL || output_file == NULL) {
        printf("Error: could not open files\n");
        return 1;
    }

    // checks that there is at least one character and therefore at least one line
    if(getc(input_file) != EOF) {
        count += 1;
    }

    // counts the number of lines that the file has
    for (c = getc(input_file); c != EOF; c = getc(input_file)) {
        if (c == '\n') {
            count += 1;
        }

    }

    // print out the number of lines
    printf("The input_file has %d lines\n ", count);

    // close the files
    fclose(input_file);
    fclose(output_file);

/*
    // creates variables that will be used for reading and writting to the files
    char copied_text[30];

    // loop that copies the contents of the inputfile into the outputfile
    while (fscanf(input_file, "%s", copied_text) != EOF) { 

        //prints the input file into the out put file
        fprintf(output_file, "%s ", copied_text);
    }
*/
    return 0;
}