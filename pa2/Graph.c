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

   // for loop to initialize all values
   for (int i = 1; i < (n+1); i++) {
      G->neighbors[i] = newList();
      G->color[i] = WHITE;
      G->parents[i] = NIL;
      G->distances[i] = INF;
   }

   return G;

}

// frees the graph and sets the original pointer to NULL
void freeGraph(Graph* pG) {
   Graph G = *pG;  
   int vert = getOrder(G);
   for (int i = 1; i < vert; i++) {
      freeList(&(G->neighbors[i]));
   }

   free(G->neighbors);
   free(G->color);
   free(G->parents);
   free(G->distances);
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

// returns the source vertex
int getSource(Graph G) {
   if (G == NULL) {
      fprintf(stderr, "Error Graph does not exist\n");
      return -1;
   }
   return G->source;
}

// return the parents of the vertex number u
int getParent(Graph G, int u) {
   if (G == NULL) {
      fprintf(stderr, "Error Graph does not exist\n");
      return -1;
   }
   return G->parents[u];
}

// returns the list from the source node to the node u
int getDist(Graph G, int u) {
   if (G == NULL) {
      fprintf(stderr, "Error Graph does not exist\n");
      return -1;
   }
   else if (G->distances[u] < 1 || G->distances[u] > getOrder(G)) {
      fprintf(stderr, "Error the point %d is not in range\n", G->distances[u]);
      return -1;
   }
   else if (G->source == NIL) {
      return INF;
   }
   else if (G->distances[u] == NIL) {
      return INF;
   } else {
      return G->distances[u];
   }
}

// this func returns the path 
void getPath(List L, Graph G, int u) {
   // logic from print path should be the same but we simply write to the list
   if (G->source == u) {
        append(L, u);
   } 
   else if (getParent(G, u) == NIL) {
      append(L, NIL);
   } else {
      getPath(L, G, getParent(G, u));
      append(L, u);
   }
   
}


// Manipulation procedures ----------------------------------------------------

// this function clears out all the of the neighbors list sets color to white disntance to INF and parents to NULL
void makeNull(Graph G) {
   // clears out all the lists in neighbors
   for(int i = 1; i < (G->vertecies + 1); i++) {
      clear(G->neighbors[i]);
   }

   // sets all the values of the color graph to one
   for(int i = 1; i < (G->vertecies + 1); i++) {
      // the value of white is one
      G->color[i] = WHITE;
   }

   // sets distances to INF 
   for(int i = 1; i < (G->vertecies + 1); i++) {
      // the value of white is one
      G->distances[i] = INF;
   }

   // set the parents of the graph to NIL
   for(int i = 1; i < (G->vertecies + 1); i++) {
      // the value of white is one
      G->parents[i] = NIL;
   }

   // reset the non arry values back to their defults
   G->edges = 0;
   G->source = NIL;


}

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

   // 
}

void addArc(Graph G, int u, int v) {
   insert_in_order(G->neighbors[u], v);
   G->edges += 1;
}

void enqueue(List L, int i) {
   append(L, i);
}

int dequeue(List L) {
   int x = front(L);
   deleteFront(L);
   return x;
}


// does the breath first search of a graph
void BFS(Graph G, int s) {
   G->source = s;
   int vert = getOrder(G);
   for (int i = 1; i < vert; i++) {
      if (i != s){
         G->color[i] = WHITE;
         G->distances[i] = INF;
         G->parents[i] = NIL;
      }
   }
   G->color[s] = GRAY;
   G->distances[s] = 0;
   G->parents[s] = NIL;
   List Q = newList();
   enqueue(Q, s);
   // while loop that works until the List is empty
   int x;
   while (length(Q) > 0) {
      x = dequeue(Q);
      // loop to get the values at all indexes
      List N = G->neighbors[x];
      moveFront(N);
      while (true) {
         int y = get(N);
         if (G->color[y] == WHITE) {
            G->color[y] = GRAY;
            G->distances[y] = G->distances[x] + 1;
            G->parents[y] = x;
            enqueue(Q, y);
         }
         if (index(N) < (length(N) - 1)) {
            moveNext(N);
         } else {
            break;
         }
      }
      G->color[x] = BLACK;
   }

}

// Psudo Code Version
#if 0
BFS(G,s)
   for x in V(G)-{s}
        color[x] = white
        d[x] = inf
        p[x] = nil 
   color[s] = gray       // discover the source s
   d[s] = 0
   p[s] = nil 
   Q = { }               // construct a new empty queue
   Enqueue(Q,s)
   while Q ≠ { }
        x = Dequeue(Q) 
        for y in adj[x]
             if color[y] == white         // y is undiscovered
                  color[y] = gray         // discover y
                  d[y] = d[x]+1
                  p[y] = x
                  Enqueue(Q,y)
        color[x] = black                  // finish x
#endif



// Other Functions ------------------------------------------------------------

void printGraph(FILE* out, Graph G){
   // for loop to loop through all the lists and print them out
   for (int i = 1; i < (getOrder(G) + 1); i++) {
      fprintf(out, "%d: ", i);
      printList(out, G->neighbors[i]);
      fprintf(out, "\n");
   }
}