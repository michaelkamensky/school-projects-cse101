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

    int vert;

    // reading the number of verticies
    fscanf(input_file, "%d", &vert);

    // printing the number of verticies
    printf("the number of verticies %d \n", vert);

    // creating new graph with the correct number of verticies
    Graph G = newGraph(vert);


    // reading the file to create graph
    while (fscanf(input_file, "%d %d", &num1, &num2) != EOF) {
        if (num1 == 0 && num2 == 0) {
            break;
        }
        // adding the edges to the graph
        addEdge(G, num1, num2);
    }

    // printing out the graph
    printGraph(stdout, G);

    // reading the file to read the source and dest vertecies
    while (fscanf(input_file, "%d %d", &num1, &num2) != EOF) {
        if (num1 == 0 && num2 == 0) {
            break;
        }
        printf("Source and Dest: %d %d\n", num1, num2);
    }




    // close the files
    fclose(input_file);
    fclose(output_file);

    return 0;
}