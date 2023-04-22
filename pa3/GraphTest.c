/********************************************************************************* 
* Michael V Kamensky
* 2023 Winter CSE101 PA#3 
* GraphTest.c 
* Test the Graph ADT
*********************************************************************************/ 
#include <stdio.h>
#include <stdio.h>

#include "List.h"
#include "Graph.h"

void test_graph_create(void) {
    Graph G = newGraph(5);
    addArc(G, 1, 4);
    addArc(G, 1, 2);
    addArc(G, 2, 5);
    addArc(G, 2, 3);   
    addArc(G, 3, 5);
    addArc(G, 4, 5);

    printGraph(stdout, G);
}

void test_DFS(void) {
    Graph G = newGraph(5);
    addArc(G, 1, 4);
    addArc(G, 1, 2);
    addArc(G, 2, 5);
    addArc(G, 2, 3);   
    addArc(G, 3, 5);
    addArc(G, 4, 5);

    printGraph(stdout, G);

    List s = newList();

    DFS(G, s);
}

int main(void) {
    //test_graph_create();
    test_DFS();

    return 0;
}