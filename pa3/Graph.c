/********************************************************************************* 
* Michael V Kamensky
* 2023 Winter CSE101 PA#3 
* Graph.c 
* Graph ADT creates a graph using arc or edges and can use breath first search to find the shortest pathways between nodes
*********************************************************************************/ 
//-----------------------------------------------------------------------------
// Graph.c
// Implementation file for Graph ADT
//-----------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

#include "List.h"
#include "Graph.h"

// structs --------------------------------------------------------------------

// private GraphObj type
typedef struct GraphObj{
   int vertecies;
   // number of edges
   int edges;
   // neighbors list
   List *neighbors;
   // finished stack
   int *finished;
   // discover list
   int *discover;
   // the array for the color
   int *color; 
   // the array for parents
   int *parents;
} GraphObj;

// Constructors-Destructors ---------------------------------------------------

// creates a new Graph 
Graph newGraph(int n) {
   Graph G = malloc(sizeof(GraphObj));
   G->vertecies = n;
   G->edges = 0;

   G->neighbors = calloc(n+1, sizeof(List));
   G->finished = calloc(n+1, sizeof(int));
   G->discover = calloc(n+1, sizeof(int));
   G->color = calloc(n+1, sizeof(int));
   G->parents = calloc(n+1, sizeof(int));

   // for loop to initialize all values
   for (int i = 1; i < (n+1); i++) {
      G->neighbors[i] = newList();
      G->finished[i] = NIL;
      G->discover[i] = 0;
      G->color[i] = WHITE;
      G->parents[i] = NIL;
   }
   return G;
}

// frees the graph and sets the original pointer to NULL
void freeGraph(Graph* pG) {
   Graph G = *pG;  
   int vert = getOrder(G);
   for (int i = 1; i <= vert; i++) {
      freeList(&(G->neighbors[i]));
   }

   free(G->neighbors);
   free(G->finished);
   free(G->discover);
   free(G->color);
   free(G->parents);
   free(G);
   *pG = NULL;
}

// Access functions -----------------------------------------------------------

// returns the number of verticies 
int getOrder(Graph G) {
   if (G == NULL) {
      fprintf(stderr, "Error Graph does not exist\n");
      return -1;
   }
   return G->vertecies;
}

// retruns the number of edges
int getSize(Graph G) {
   if (G == NULL) {
      fprintf(stderr, "Error Graph does not exist\n");
      return -1;
   }
   return G->edges;
}

// return the parents of the vertex number u
/* Pre: 1<=u<=n=getOrder(G) */
int getParent(Graph G, int u) {
   if (G == NULL) {
      fprintf(stderr, "Error Graph does not exist\n");
      return -1;
   }
   if (u >= 1 && u <= getOrder(G)){
      return G->parents[u];
   }
   fprintf(stderr, "Error %d does not statisfy the pre cond for getParent\n", u);
   return -1;

}

// List of what nodes were discovered
/* Pre: 1<=u<=n=getOrder(G) */
int getDiscover(Graph G, int u) {
   if (u >= 1 && u <= getOrder(G)){
      return G->discover[u];
   }
   fprintf(stderr, "Error %d does not statisfy the pre cond for getDiscover\n", u);
   return -1;
}

/* Pre: 1<=u<=n=getOrder(G) */
int getFinish(Graph G, int u) {
   if (u >= 1 && u <= getOrder(G)){
      return G->finished[u];
   }
   fprintf(stderr, "Error %d does not statisfy the pre cond for getFinished\n", u);
   return -1;
}

// Manipulation procedures ----------------------------------------------------

void static insert_in_order(List L, int v){
   if (length(L) > 0 && L != NULL) {
      moveFront(L);
      while (true) {
         int current = get(L);
         // is true if and only if s1 comes before s2
         if (current > v )
         {
            insertBefore(L, v);
            break;
         }
         else
         {
            if ((index(L) + 1) == length(L))
            {
               insertAfter(L, v);
               break;
            }
            else
            {
               moveNext(L);
            }
         }
      }
   } else {
      append(L, v);
   }
}

// adds an edge
void addEdge(Graph G, int u, int v) {
   // need to add neighbors between the two node
   insert_in_order(G->neighbors[u], v);
   insert_in_order(G->neighbors[v], u);
   G->edges += 1;
}

void addArc(Graph G, int u, int v) {
   insert_in_order(G->neighbors[u], v);
   G->edges += 1;
}

void static push_stack(List L, int x) {
   // printf("push %p: %d\n", L, x);
   prepend(L, x);
}

int static pop_stack(List L) {
   int fr = front(L);
   // printf("pop %p: %d\n", L, fr);
   deleteFront(L);
   return fr;
}

// helper function for the depth first search 
static void Visit(Graph G, List S, int x, int *time) {
   *time += 1;
   G->discover[x] = *time;
   G->color[x] = GRAY;
   List adj = G->neighbors[x];
   moveFront(adj);
   for (int j = 1; j <= length(adj); j++) {
      int y = get(adj);
      if (G->color[y] == WHITE) {
         G->parents[y] = x;
         Visit(G, S, y, time);
      }
      moveNext(adj);
   }
   G->color[x] = BLACK;
   push_stack(S, x);
   *time += 1;
   G->finished[x] = *time;
}

// Depth First Search Algorithm
/* Pre: length(S)==getOrder(G) */
void DFS(Graph G, List S) {
   for (int i = 1; i <= getOrder(G); i++) {
      G->color[i] = WHITE;
      G->parents[i] = NIL;
   }
   int time = 0;
   int list_length = length(S);
   // checker for list if it is empty run as normally if it has items copy the list and run DFS based of list
   if (list_length == 0) {
      // main loop of DFS when list is empty
      for (int x = 1; x <= getOrder(G); x++) {
         if (G->color[x] == WHITE) {
            Visit(G, S, x, &time);
         }
      }
   } else {
      // if this condition is reached this means that the list was not empty and now need to do the loop backwards
      // create a copied list that serves as input and the original will serve as out put
      List cp = copyList(S);
      // need to clear the original list
      clear(S);
      for (int x = 1; x <= list_length; x++) {
         //int fr = front(cp);
         //deleteFront(cp);
         int fr = pop_stack(cp);
         if (G->color[fr] == WHITE) {
            Visit(G, S, fr, &time);
         }
      }
      freeList(&cp);
   }
}

// Other Functions ------------------------------------------------------------

void printGraph(FILE* out, Graph G){
   // for loop to loop through all the lists and print them out
   for (int i = 1; i < (getOrder(G) + 1); i++) {
      fprintf(out, "%d: ", i);
      printList(out, G->neighbors[i]);
      fprintf(out, "\n");
   }
}

// returns a graph with the edges reversed but is the same in all other regards
Graph transpose(Graph G) {
   int order = getOrder(G);
   Graph ret = newGraph(order);
   int dst;
   int src;

   for (int i = 1; i <= order; i++) {
      dst = i;
      List adjs = G->neighbors[i];
      moveFront(adjs);
      for (int j = 0; j < length(adjs); j++) {
         src = get(adjs);
         moveNext(adjs);
         addArc(ret, src, dst);
      }
      
   }
   return ret;
}

// copies a graph and returns it
Graph copyGraph(Graph G) {
   int order = getOrder(G);
   Graph ret = newGraph(order);
   for (int i = 1; i <= order; i++) {
      ret->color[i] = G->color[i];
      ret->parents[i] = G->parents[i];
      ret->discover[i] = G->discover[i];
      ret->finished[i] = G->finished[i];
      ret->neighbors[i] = copyList(G->neighbors[i]);
      ret->edges = G->edges;
   }
   return ret;
}