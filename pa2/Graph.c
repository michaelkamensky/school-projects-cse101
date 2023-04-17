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
   // int for the most recently used source
   int source;
   // number of vertecies
   int vertecies;
   // number of edges
   int edges;
   // neighbors list
   List *neighbors;
   // the array for the color
   int *color; 
   // the array for parents
   int *parents;
   // the array for distance
   int *distances;
} GraphObj;



// Constructors-Destructors ---------------------------------------------------

// creates a new Graph 
Graph newGraph(int n) {
   Graph G = malloc(sizeof(GraphObj));
   G->vertecies = n;
   G->edges = 0;
   G->source = NIL;

   G->neighbors = calloc(n+1, sizeof(List));
   G->color = calloc(n+1, sizeof(int));
   G->parents = calloc(n+1, sizeof(int));
   G->distances = calloc(n+1, sizeof(int));

}


// Access functions -----------------------------------------------------------

// returns the number of verticies 
int getOrder(Graph G) {
   if (G != NULL) {
      return G->vertecies;
   } 
}

// retruns the number of edges
int getSize(Graph G) {
   if (G != NULL) {
      return G->edges;
   }
}

// returns the source vertex
int getSource(Graph G) {
   if (G != NULL) {
      return G->source;
   }
}

// return the parents of the vertex number u
int getParent(Graph G, int u) {
   if (G != NULL && u > NIL) {
      return G->parents[u];
   }
}

// returns the dist from the source node to the node u
int getDist(Graph G, int u) {
   if (G != NULL && u > NIL) {
      return G->distances[u];
   }
}

// this func returns the path 
void getPath(List L, Graph G, int u) {
   // logic from print path should be the same but we simply write to the list
   if (G->source == u) {
        append(L, G->source);
   } 
   else if (G->parents[u] == NIL) {
      printf("%d is not reachable from %d")
   }
   else {
      PrintPath(G, G->source, G->parents[u]);
      append(L, u);
   }
   
}


// Manipulation procedures ----------------------------------------------------


// Other Functions ------------------------------------------------------------

