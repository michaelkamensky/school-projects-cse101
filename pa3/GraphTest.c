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
    printf("\n");

#if 0
    int num_comp = getNumComponents(tr);
    int num_verts = getOrder(tr);
    for (int comp = 1; comp <= num_comp; comp++) {
        printf("Component %d: ", comp);
        for (int vert = 1; vert <= num_verts; vert++) {
            if (getCompnent(tr, vert) == comp) {
                printf("%d ", vert);
            }
        }
        printf("\n");
    }
#endif
    
    int total_compt = 0;
    moveBack(s);
    for (int i = 0; i < length(s); i++) {
        int value = get(s);
        if (getParent(tr, value) == NIL) {
            total_compt += 1;
        }
        movePrev(s);
    }

    printf("G contains %d strongly connected components:\n", total_compt);
    moveBack(s);
    int comp = 0;
    List print = newList();
    for (int i = 1; i <= length(s); i++) { 
        int value = get(s);
        // printf("%d", value);
        prepend(print, value);
        if (getParent(tr, value) == NIL) {
            comp += 1;
            printf("Component %d: ", comp);
            printList(stdout, print);
            printf("\n");
            clear(print);
        }
        movePrev(s);
    }
    freeList(&print);


}

bool test_DG_getSize (void) {
    Graph A = newGraph(55);
    addArc(A, 54, 1);
    addArc(A, 54, 2);
    addArc(A, 54, 2);
    addArc(A, 54, 3);
    addArc(A, 1, 54);
    addArc(A, 1, 54);
    addArc(A, 1, 55);
    addArc(A, 1, 55);
    if (getSize(A) != 5) {
      return false;
    }
    return true;
}

int main(void) {
    //test_graph_create();
    //test_DFS();
    //test_copy_graph();
    //test_transpose();
    //test_DFS_2();
    printf("the result for test_DG_getSize %d should be 1\n", test_DG_getSize());

    return 0;
}