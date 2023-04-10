//-----------------------------------------------------------------------------
// List.c
// Implementation file for List ADT
//-----------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include "List.h"


// structs --------------------------------------------------------------------

// private Node type
typedef struct NodeObj* Node;

// private NodeObj type
typedef struct NodeObj{
   ListElement data;
   Node next;
   Node previous;
} NodeObj;

// private ListObj type
typedef struct ListObj{
   Node front;
   Node back;
   //int index;
   Node pointer;
   int length;
} ListObj;

// isEmpty()
// Returns true if Q is empty, otherwise returns false.
static bool isEmpty(List Q){
   if( Q==NULL ){
      printf("Queue Error: calling isEmpty() on NULL Queue reference\n");
      exit(EXIT_FAILURE);
   }
   return(Q->length==0);
}

// Constructors-Destructors ---------------------------------------------------

// newNode()
// Returns reference to new Node object. Initializes next and data fields.
Node newNode(ListElement data){
   Node N = malloc(sizeof(NodeObj));
   assert( N!=NULL );
   N->data = data;
   N->next = NULL;
   N->previous = NULL;
   return(N);
}

// freeNode()
// Frees heap memory pointed to by *pN, sets *pN to NULL.
void freeNode(Node* pN){
   if( pN!=NULL && *pN!=NULL ){
      free(*pN);
      *pN = NULL;
   }
}

// newList()
// Returns reference to new empty List object.
List newList(){
   List Q;
   Q = malloc(sizeof(ListObj));
   assert( Q!=NULL );
   Q->front = Q->back = NULL;
   Q->length = 0;
   return(Q);
}

// freeList()
// Frees all heap memory associated with List *pQ, and sets *pQ to NULL.
void freeList(List* pQ){
   if(pQ!=NULL && *pQ!=NULL) { 
      while( !isEmpty(*pQ) ) { 
         DeList(*pQ); 
      }
      free(*pQ);
      *pQ = NULL;
   }
}

// Access functions -----------------------------------------------------------




// getLength()
// Returns the length of Q.
int length(List Q){
   if( Q==NULL ){
      printf("Queue Error: calling getLength() on NULL Queue reference\n");
      exit(EXIT_FAILURE);
   }
   return(Q->length);
}

// getFront()
// Returns the value at the front of Q.
// Pre: !isEmpty(Q)
ListElement front(List Q){
   if( Q==NULL ){
      printf("Queue Error: calling getFront() on NULL Queue reference\n");
      exit(EXIT_FAILURE);
   }
   if( isEmpty(Q) ){
      printf("Queue Error: calling getFront() on an empty Queue\n");
      exit(EXIT_FAILURE);
   }
   return(Q->front->data);
}

// getBack()
// Returns the value at the back of Q.
// Pre: !isEmpty(Q)
ListElement back(List Q){
   if( Q==NULL ){
      printf("Queue Error: calling getFront() on NULL Queue reference\n");
      exit(EXIT_FAILURE);
   }
   if( isEmpty(Q) ){
      printf("Queue Error: calling getFront() on an empty Queue\n");
      exit(EXIT_FAILURE);
   }
   return(Q->back->data);
}

#if 0
// index()
// Returns the value of the index.
// Pre: !isEmpty(Q)
int index(List Q) {
   if( Q==NULL ){
      printf("Queue Error: calling getFront() on NULL Queue reference\n");
      exit(EXIT_FAILURE);
   }
   if( isEmpty(Q) ){
      printf("Queue Error: calling getFront() on an empty Queue\n");
      exit(EXIT_FAILURE);
   }
   return(Q->index);
}
#endif










