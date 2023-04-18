#include <stdio.h>

#include "List.h"
#include "Graph.h"

void test_const(void) {
    Graph G = newGraph(5);
    if ((G != NULL)) {
        printf("the constructor seems to create a graph object\n");
    }

}

// use valgrind to check if a memory leack has occurd
void test_free_empty(void) {
    Graph G = newGraph(5);
    freeGraph(&G);
    printf("use valgrind to check for memory leaks\n");
}

void test_make_edge(void) {
    Graph G = newGraph(5);
    addEdge(G, 1, 2);
    addEdge(G, 1, 4);
    addEdge(G, 2, 3);
    addEdge(G, 2, 5);
    addEdge(G, 3, 5);
    addEdge(G, 4, 5);

    // The number of edges is 
    printf("The num edges is %d should be 6 \n", getSize(G));

    // function that prints out the graph
    printf("The Result is \n");
    printGraph(stdout, G);

    printf("It should be \n");
    printf("1: 2 4\n");
    printf("2: 1 3 5\n");
    printf("3: 2 5\n");
    printf("4: 1 5\n");
    printf("5: 2 3 4\n");

}

int main(void) {
    //test_const();
    //test_free_empty();
    test_make_edge();


    return 0;
}