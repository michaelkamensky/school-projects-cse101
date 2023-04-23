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

    printList(stdout, s);
    printf("\n");
}

void test_copy_graph(void) {
    Graph G = newGraph(5);
    addArc(G, 1, 4);
    addArc(G, 1, 2);
    addArc(G, 2, 5);
    addArc(G, 2, 3);   
    addArc(G, 3, 5);
    addArc(G, 4, 5);

    printGraph(stdout, G);
    Graph copy = copyGraph(G);

    printf("The copy of the graph is \n");
    printGraph(stdout,copy);
}

void test_transpose(void) {
    Graph G = newGraph(5);
    addArc(G, 1, 4);
    addArc(G, 1, 2);
    addArc(G, 2, 5);
    addArc(G, 2, 3);   
    addArc(G, 3, 5);
    addArc(G, 4, 5);

    printGraph(stdout, G);
    Graph copy = transpose(G);

    printf("The trp of the graph is \n");
    printGraph(stdout,copy);
}

void test_DFS_2(void) {
    Graph G = newGraph(8);
    addArc(G, 1, 2);
    addArc(G, 2, 3);
    addArc(G, 2, 5);
    addArc(G, 2, 6);
    addArc(G, 3, 4);
    addArc(G, 3, 7);
    addArc(G, 4, 3);
    addArc(G, 4, 8);
    addArc(G, 5, 1);
    addArc(G, 5, 6);
    addArc(G, 6, 7);
    addArc(G, 7, 6);
    addArc(G, 7, 8);
    addArc(G, 8, 8);

    printGraph(stdout, G);

    List s = newList();

    DFS(G, s);

    printList(stdout, s);
    printf("\n");

    Graph tr = transpose(G);

    printf("The new graph is \n");
    printGraph(stdout, tr);

    DFS(tr, s);

    printList(stdout, s);
    printf("\n");





}

int main(void) {
    //test_graph_create();
    //test_DFS();
    //test_copy_graph();
    //test_transpose();
    test_DFS_2();

    return 0;
}