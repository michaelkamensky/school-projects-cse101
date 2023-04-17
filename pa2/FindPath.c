#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "List.h"
#include "Graph.h"


/* the main function of this program will use the List.c and Graph.c ADT
to organize it
the main function needs to be able 
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

    // creating arrays to store the data from file into
    int num1;
    int num2;

    // reading the file to create graph and tests for said graph

    while (fscanf(input_file, "%d %d", &num1, &num2) != "0 0") {
        printf("Read from file: %d %d\n", num1, num2);
    }




    // close the files
    fclose(input_file);
    fclose(output_file);

    return 0;
}