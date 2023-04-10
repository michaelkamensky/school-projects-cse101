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
   Node cursor;
   int length;
} ListObj;

// isEmpty()
// Returns true if Q is empty, otherwise returns false.
static bool isEmpty(List Q){
   if( Q==NULL ){
      printf("Llist Error: calling isEmpty() on NULL List reference\n");
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

// Returns index of cursor element if defined, -1 otherwise.
int index(List L) {
   if (L->cursor != NULL && L->front != NULL) {
      Node N = L->front;
      int index = 0;
      while (N != L->cursor) {
         index += 1;
         N = N->next;

      }
      return index;
   } 
   return -1;
}

// Returns cursor element of L. Pre: length()>0, index()>=0
int get(List L) {
   if (L->length > 0 && index(L) >= 0) {
      return L->cursor->data;
   }
}


// getLength()
// Returns the length of Q.
int length(List Q){
   if( Q==NULL ){
      printf("Llist Error: calling getLength() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   return(Q->length);
}

// getFront()
// Returns the value at the front of Q.
// Pre: !isEmpty(Q)
ListElement front(List Q){
   if( Q==NULL ){
      printf("Llist Error: calling getFront() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   if( isEmpty(Q) ){
      printf("Llist Error: calling getFront() on an empty List\n");
      exit(EXIT_FAILURE);
   }
   return(Q->front->data);
}

// getBack()
// Returns the value at the back of Q.
// Pre: !isEmpty(Q)
ListElement back(List Q){
   if( Q==NULL ){
      printf("Llist Error: calling getFront() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   if( isEmpty(Q) ){
      printf("Llist Error: calling getFront() on an empty List\n");
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
      printf("Llist Error: calling getFront() on NULL Llist reference\n");
      exit(EXIT_FAILURE);
   }
   if( isEmpty(Q) ){
      printf("Llist Error: calling getFront() on an empty Llist\n");
      exit(EXIT_FAILURE);
   }
   return(Q->index);
}
#endif

// Manipulation procedures ----------------------------------------------------

// If L is non-empty, sets cursor under the front element,
// otherwise does nothing.
void moveFront(List L) {
   if (L->front != NULL && L->length > 0) {
      L->cursor = L->front;
   }
} 

// If L is non-empty, sets cursor under the back element,
// otherwise does nothing.
void moveBack(List L) {
   if (L->front != NULL && L->length > 0) {
      L->cursor = L->back;
   }
}

// If cursor is defined and not at front, move cursor one
// step toward the front of L; if cursor is defined and at
// front, cursor becomes undefined; if cursor is undefined
// do nothing
void movePrev(List L) {
   if (L->cursor != L->front) {
      L->cursor = L->cursor->previous;
   } else {
      L->cursor = NULL;
   }
}

// If cursor is defined and not at back, move cursor one
// step toward the back of L; if cursor is defined and at
// back, cursor becomes undefined; if cursor is undefined
// do nothing
void moveNext(List L) {
   if (L->cursor != L->back) {
      L->cursor = L->cursor->next;
   } else {
      L->cursor = NULL;
   }
}

// Insert new element into L. If L is non-empty,
// insertion takes place before front element.
void prepend(List L, int x) {
   Node N = newNode(x);
   if (L->length == 1 && L->back != NULL) {
      L->back->previous = N;
      N->next = L->back;
      L->front = N;
      L->length += 1;

   } else {
      if (L->front != NULL && L->length > 0) {
         L->front->previous = N;
      } 
      N->next = L->front;
      L->front = N;
      L->length += 1;
   }
}

// Insert new element into L. If L is non-empty,
// insertion takes place after back element.
void append(List L, int x) {
   Node N = newNode(x);
   if (L->length == 1 && L->front != NULL) {
      L->front->next = N;
      N->previous = L->front;
      L->back = N;
      L->length += 1;

   }
   else{
      if (L->back != NULL && L->length > 0) {
         L->back->next = N;
      } 
      N->previous = L->back;
      L->back = N;
      L->length += 1;
   }
}

// Insert new element before cursor.
// Pre: length()>0, index()>=0
void insertBefore(List L, int x) {
   if (L->length > 0 && index(L) >= 0) {
      Node N = newNode(x);
      L->cursor->previous->next = N;
      L->cursor->previous = N;
      L->length += 1;
   }

}

// Insert new element after cursor.
// Pre: length()>0, index()>=0
void insertAfter(List L, int x) {
   if (L->length > 0 && index(L) >= 0) {
      Node N = newNode(x);
      L->cursor->next->previous = N;
      L->cursor->next = N;
      L->length += 1;
   }
}

// Delete the front element. Pre: length()>0
void deleteFront(List L){
   if (L->length > 0) {
      Node del = L->front;
      L->front = L->front->next;
      freeNode(&del);
      L->length -= 1;

   }
} 

// Delete the back element. Pre: length()>0
void deleteBack(List L) {
   if (L->length > 0) {
      Node del = L->back;
      L->back = L->back->next;
      freeNode(&del);
      L->length -= 1;

   }
}

// Delete cursor element, making cursor undefined.
// Pre: length()>0, index()>=0
void delete(List L); 

// DeLlist()
// Deletes data at front of Q.
// Pre: !isEmpty(Q)
void DeList(List Q){
   Node N = NULL;

   if( Q==NULL ){
      printf("Llist Error: calling DeLlist() on NULL Llist reference\n");
      exit(EXIT_FAILURE);
   }
   if( isEmpty(Q) ){
      printf("Llist Error: calling DeLlist on an empty Llist\n");
      exit(EXIT_FAILURE);
   }
   N = Q->front;
   if( length(Q)>1 ) { 
      Q->front = Q->front->next; 
   }else{ 
      Q->front = Q->back = NULL; 
   }
   Q->length--;
   freeNode(&N);
}