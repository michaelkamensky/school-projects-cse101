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
   int index;
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
   Q->cursor = NULL;
   Q->length = 0;
   Q->index = -1;
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
   return L->index;
}

// Returns cursor element of L. Pre: length()>0, index()>=0
int get(List L) {
   if (L->length > 0 && index(L) >= 0) {
      return L->cursor->data;
   } else {
      printf("List Error: calling get() on empty List reference or undefiend cursor\n");
      return -1;
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

// Returns true if Lists A and B are in same
// state, and returns false otherwise.
bool equals(List A, List B) {
   if( A==NULL || B==NULL ){
      printf("Queue Error: calling equals() on NULL Queue reference\n");
      exit(EXIT_FAILURE);
   }

   // simple check for speed 
   if ((A->length != B->length) && (A->front != B->front) && (A->back != B->back)) {
      return false;
   }

   bool eq;
   Node N, M;

   eq = ( A->length == B->length );
   N = A->front;
   M = B->front;
   while( eq && N!=NULL){
      eq = ( N->data==M->data );
      N = N->next;
      M = M->next;
   }
   return eq;

} 


// Manipulation procedures ----------------------------------------------------

// Resets L to its original empty state.
void clear(List L) {
   Node N = L->front;
   Node del;
   while (N != NULL) {
      del = N;
      N = N->next;
      freeNode(&del);
   }
   L->front = NULL;
   L->back = NULL;
   L->cursor = NULL;
   L->index = -1;
   L->length = 0;
}

// Overwrites the cursor element’s data with x.
// Pre: length()>0, index()>=0
void set(List L, int x) {
   if (L->length > 0 && index(L) >= 0) {
      L->cursor->data = x;
   }
}

// If L is non-empty, sets cursor under the front element,
// otherwise does nothing.
void moveFront(List L) {
   if (L->front != NULL && L->length > 0) {
      L->cursor = L->front;
      L->index = 0;
   }
} 

// If L is non-empty, sets cursor under the back element,
// otherwise does nothing.
void moveBack(List L) {
   if (L->front != NULL && L->length > 0) {
      L->cursor = L->back;
      L->index = L->length - 1;
   }
}

// If cursor is defined and not at front, move cursor one
// step toward the front of L; if cursor is defined and at
// front, cursor becomes undefined; if cursor is undefined
// do nothing
void movePrev(List L) {
   if (L->cursor != L->front) {
      L->cursor = L->cursor->previous;
      L->index -= 1;
   } else {
      L->cursor = NULL;
      L->index = -1;
   }
}

// If cursor is defined and not at back, move cursor one
// step toward the back of L; if cursor is defined and at
// back, cursor becomes undefined; if cursor is undefined
// do nothing
void moveNext(List L) {
   if (L->cursor != L->back) {
      L->cursor = L->cursor->next;
      L->index += 1;
   } else {
      L->cursor = NULL;
      L->index = -1;
   }
}

// Insert new element into L. If L is non-empty,
// insertion takes place before front element.
void prepend(List L, int x) {
   Node N = newNode(x);
   if (L->front != NULL && L->length > 0) {
      L->front->previous = N;
   } 
   N->next = L->front;
   L->front = N;
   if (L->length == 0) {
      L->back = N;
   }
   L->length += 1;
   if (L->cursor != NULL) {
      L->index += 1;
   }
}

// Insert new element into L. If L is non-empty,
// insertion takes place after back element.
void append(List L, int x) {
   Node N = newNode(x);
   if (L->back != NULL && L->length > 0) {
      L->back->next = N;
   } 
   N->previous = L->back;
   L->back = N;
   if (L->length == 0) {
      L->front = N;
   }
   L->length += 1;
}

// Insert new element before cursor.
// Pre: length()>0, index()>=0
void insertBefore(List L, int x) {
   if (L->length > 0 && index(L) >= 0) {
      Node N = newNode(x);
      N->previous = L->cursor->previous;
      N->next = L->cursor;
      if (L->cursor->previous != NULL) {
         L->cursor->previous->next = N;
      } else {
         L->front = N;
      }
      L->cursor->previous = N;
      L->length += 1;
      if (L->cursor != NULL) {
         L->index += 1;
      }
   }

}

// Insert new element after cursor.
// Pre: length()>0, index()>=0
void insertAfter(List L, int x) {
   if (L->length > 0 && index(L) >= 0) {
      Node N = newNode(x);
      N->next = L->cursor->next;
      N->previous = L->cursor;
      if (L->cursor->next != NULL) {
         L->cursor->next->previous = N;
      } else {
         L->back = N;
      }
      L->cursor->next = N;
      //printf("the length was %d \n", L->length);
      L->length += 1;
      //printf("the length is now %d \n", L->length);
   }
}

// Delete the front element. Pre: length()>0
void deleteFront(List L){
   if (L->length > 0) {
      Node del = L->front;
      L->front = L->front->next;
      if (L->front != NULL) {
         L->front->previous = NULL;
      }
      if (del == L->cursor) {
         L->cursor = NULL;
         L->index = -1;
      }
      freeNode(&del);
      L->length -= 1;
      if (L->cursor != NULL) {
         L->index -= 1;
      }

   }
} 

// Delete the back element. Pre: length()>0
void deleteBack(List L) {
   if (L->length > 0) {
      Node del = L->back;
      L->back = L->back->previous;
      if (L->back != NULL) {
         L->back->next = NULL;
      }
      if (del == L->cursor) {
         L->cursor = NULL;
         L->index = -1;
      } 
      freeNode(&del);
      L->length -= 1;

   }
}

// Delete cursor element, making cursor undefined.
// Pre: length()>0, index()>=0
void delete(List L) {
   if (L->length > 0 && index(L) >= 0) {
      if (L->cursor->previous != NULL) {
         L->cursor->previous->next = L->cursor->next;
      } else {
         L->front = L->cursor->next;
      }
      if (L->cursor->next != NULL) {
         L->cursor->next->previous = L->cursor->previous;
      } else {
         L->back = L->cursor->previous;
      }
      freeNode(&(L->cursor));
      L->cursor = NULL;
      L->index = -1;
      L->length -= 1;
   }
} 

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

// Other Functions ------------------------------------------------------------

// Prints to the file pointed to by out, a
// string representation of L consisting
// of a space separated sequence of integers,
// with front on left.
void printList(FILE* out, List L) {
   if(out == NULL) {
      out = stdout;
   }
   Node N = L->front;
   while (N != NULL) {
      fprintf(out, FORMAT " ", N->data);
      N = N->next;
   }
}

// Returns a new List representing the same integer
// sequence as L. The cursor in the new list is undefined,
// regardless of the state of the cursor in L. The state
// of L is unchanged.
List copyList(List L) {
   List copy = newList();
   if (L->length > 0){
      append(copy, L->front->data);
      Node N = L->front;
      N = N->next;
      while (N != NULL) {
         append(copy, N->data);
         N = N->next;
      }
      return copy;
   } else {
      return copy;
   }

}
