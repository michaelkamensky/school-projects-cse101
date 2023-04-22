/********************************************************************************* 
* Michael V Kamensky
* 2023 Winter CSE101 PA#3 
* FindComponents.c 
* Scans file and then uses graph adt and uses Depth first search to find the stength on connection between nodes
*********************************************************************************/ 
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
    int src;
    int dst;

    int vert;

    // reading the number of verticies
    fscanf(input_file, "%d", &vert);
  

    // creating new graph with the correct number of verticies
    Graph G = newGraph(vert);

    // reading the file to create graph
    while (fscanf(input_file, "%d %d", &src, &dst) != EOF) {
        if (src == 0 && dst == 0) {
            break;
        }
        // adding the edges to the graph
        addEdge(G, src, dst);
    }

    // printing out the graph
    printGraph(output_file, G);

#if 0
    // reading the file to read the source and dest vertecies
    while (fscanf(input_file, "%d %d", &src, &dst) != EOF) {
        if (src == 0 && dst == 0) {
            break;
        }
        BFS(G, src);
        fprintf(output_file, "\n");
        int dist = getDist(G, dst);
        if (dist != INF) {
            fprintf(output_file, "The distance from %d to %d is %d\n", src, dst, dist);
            List new = newList();
            getPath(new, G, dst);
            fprintf(output_file, "A shortest %d-%d path is: ", src, dst);
            printList(output_file, new);
            fprintf(output_file, "\n");
            freeList(&new);
        } else {
            fprintf(output_file, "The distance from %d to %d is infinity\n", src, dst);
            fprintf(output_file, "No %d-%d path exists", src, dst);
        }
    }
#endif
    // free the graph
    freeGraph(&G);
    // close the files
    fclose(input_file);
    fclose(output_file);
    return 0;
}