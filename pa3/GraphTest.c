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

void test_make_arc(void) {
    Graph G = newGraph(5);
    addArc(G, 1, 4);
    addArc(G, 1, 2);
    addArc(G, 2, 5);
    addArc(G, 2, 3);   
    addArc(G, 3, 5);
    addArc(G, 4, 5);

    // The number of edges is 
    printf("The num edges is %d should be 6 \n", getSize(G));

    // function that prints out the graph
    printf("The Result is \n");
    printGraph(stdout, G);

    printf("It should be \n");
    printf("1: 2 4\n");
    printf("2: 3 5\n");
    printf("3: 5\n");
    printf("4: 5\n");
    printf("5:\n");

}

void test_makeNull(void) {
    Graph G = newGraph(5);
    addArc(G, 1, 2);
    addArc(G, 1, 4);
    addArc(G, 2, 3);
    addArc(G, 2, 5);
    addArc(G, 3, 5);
    addArc(G, 4, 5);

    // the tested function
    makeNull(G);

    // The number of edges is 
    printf("The num edges is %d should be 0 \n", getSize(G));

    // function that prints out the graph
    printf("The Result is \n");
    printGraph(stdout, G);

    printf("It should be \n");
    printf("1:\n");
    printf("2:\n");
    printf("3:\n");
    printf("4:\n");
    printf("5:\n");

}

void test_BFS(void) {
    Graph G = newGraph(5);
    addArc(G, 1, 2);
    addArc(G, 1, 4);
    addArc(G, 2, 3);
    addArc(G, 2, 5);
    addArc(G, 3, 5);
    addArc(G, 4, 5);

    BFS(G, 1);
    printGraph(stdout, G);

    printf("The num edges is %d should be 6 \n", getSize(G));
    printf("The source is %d should be 1 \n", getSource(G));
    printf("The distance to 4 is %d should be 1 \n", getDist(G, 4));
    printf("The distance to 5 is %d should be 2 \n", getDist(G, 5));
    printf("The distance to 3 is %d should be 2 \n", getDist(G, 3));
    printf("The distance to 2 is %d should be 1 \n", getDist(G, 2));

    List L = newList();
    getPath(L, G, 5);
    printList(stdout, L);
    fprintf(stdout, "\n");
    clear(L);

    getPath(L, G, 3);
    printList(stdout, L);
    fprintf(stdout, "\n");
    clear(L);

    getPath(L, G, 4);
    printList(stdout, L);
    fprintf(stdout, "\n");
    clear(L);



}

void test_BFS_2(void) {
    Graph G = newGraph(7);
    addArc(G, 1, 2);
    addArc(G, 1, 4);
    addArc(G, 1, 7);
    addArc(G, 4, 5);
    addArc(G, 5, 6);
    addArc(G, 6, 7);
    addArc(G, 7, 3);

    BFS(G, 1);
    printGraph(stdout, G);

    printf("The num edges is %d should be 7 \n", getSize(G));
    printf("The source is %d should be 1 \n", getSource(G));
    printf("The distance to 4 is %d should be 1 \n", getDist(G, 4));
    printf("The distance to 5 is %d should be 2 \n", getDist(G, 5));
    printf("The distance to 3 is %d should be 2 \n", getDist(G, 3));
    printf("The distance to 6 is %d should be 3 \n", getDist(G, 6));
    printf("The distance to 7 is %d should be 1 \n", getDist(G, 7));

    List L = newList();
    getPath(L, G, 6);
    printList(stdout, L);
    fprintf(stdout, "\n");
    clear(L);

    getPath(L, G, 7);
    printList(stdout, L);
    fprintf(stdout, "\n");
    clear(L);

    getPath(L, G, 3);
    printList(stdout, L);
    fprintf(stdout, "\n");
    clear(L);



}


int main(void) {
    //test_const();
    //test_free_empty();
    //test_make_edge();
    //test_make_arc();
    //test_makeNull();
    test_BFS();
    //test_BFS_2();


    return 0;
}