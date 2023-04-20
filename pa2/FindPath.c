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
    printGraph(output_file, G);

    // reading the file to read the source and dest vertecies
    while (fscanf(input_file, "%d %d", &num1, &num2) != EOF) {
        if (num1 == 0 && num2 == 0) {
            break;
        }
        BFS(G, num1);
        fprintf(output_file, "\n");
        int dist = getDist(G, num2);
        if (dist != INF) {
            fprintf(output_file, "The distance from %d to %d is %d\n", num1, num2, dist);
            List new = newList();
            getPath(new, G, num2);
            fprintf(output_file, "A shortest %d-%d path is: ", num1, num2);
            printList(output_file, new);
            fprintf(output_file, "\n");
            freeList(&new);
        } else {
            fprintf(output_file, "The distance from %d to %d is infinity\n", num1, num2);
            fprintf(output_file, "No %d-%d path exists", num1, num2);
        }
    }

    // close the files
    fclose(input_file);
    fclose(output_file);
    return 0;
}