/********************************************************************************* 
* Michael V Kamensky
* 2023 Winter CSE101 PA#3 
* FindComponents.c 
* Scans file and then uses graph adt and uses Depth first search to find the strongly connected nodes
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
        // adding the arcs to the graph
        addArc(G, src, dst);
    }

    // printing out the graph
    fprintf(output_file, "Adjacency list representation of G:\n");
    printGraph(output_file, G);

    fprintf(output_file, "\n");

    // logic finding the components
    List s = newList();

    DFS(G, s);

    Graph tr = transpose(G);

    DFS(tr, s);

    // now logic to print out the components

    int total_compt = 0;
    moveBack(s);
    for (int i = 0; i < length(s); i++) {
        int value = get(s);
        if (getParent(tr, value) == NIL) {
            total_compt += 1;
        }
        movePrev(s);
    }

    fprintf(output_file, "G contains %d strongly connected components:\n", total_compt);
    moveBack(s);
    int comp = 0;
    List print = newList();
    for (int i = 1; i <= length(s); i++) { 
        int value = get(s);
        // printf("%d", value);
        prepend(print, value);
        if (getParent(tr, value) == NIL) {
            comp += 1;
            fprintf(output_file, "Component %d: ", comp);
            printList(output_file, print);
            fprintf(output_file, "\n");
            clear(print);
        }
        movePrev(s);
    }
    freeList(&print);

    // free the graph
    freeGraph(&G);
    // free the graph
    freeGraph(&tr);
    // free the final list
    freeList(&s);
    // close the files
    fclose(input_file);
    fclose(output_file);
    return 0;
}