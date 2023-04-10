//-----------------------------------------------------------------------------
// List.h
// Header file for List ADT
//-----------------------------------------------------------------------------
#ifndef List_H_INCLUDE_
#define List_H_INCLUDE_
#include<stdbool.h>


#define FORMAT "%d"  // format string for ListElement


// Exported types -------------------------------------------------------------
typedef int ListElement;
typedef struct ListObj* List;


// Constructors-Destructors ---------------------------------------------------

// newList()
// Returns reference to new empty List object. 
List newList();

// freeList()
// Frees all heap memory associated with List *pQ, and sets *pQ to NULL.
void freeList(List* pQ);


// Access functions -----------------------------------------------------------

int length(List L); // Returns the number of elements in L.

int index(List L); // Returns index of cursor element if defined, -1 otherwise.

int front(List L); // Returns front element of L. Pre: length()>0

int back(List L); // Returns back element of L. Pre: length()>0

int get(List L); // Returns cursor element of L. Pre: length()>0, index()>=0

bool equals(List A, List B); // Returns true iff Lists A and B are in same
// state, and returns false otherwise.

/*
// getFront()
// Returns the value at the front of Q.
// Pre: !isEmpty(Q)
ListElement getFront(List Q);

// getLength()
// Returns the length of Q.
int getLength(List Q);

// isEmpty()
// Returns true if Q is empty, otherwise returns false.
bool isEmpty(List Q);
*/


// Manipulation procedures ----------------------------------------------------

// If L is non-empty, sets cursor under the front element,
// otherwise does nothing.
void moveFront(List L); 

// temp func that prints the value of the cursor
// for testing purposes
void pcursor(List L);

// If cursor is defined and not at front, move cursor one
// step toward the front of L; if cursor is defined and at
// front, cursor becomes undefined; if cursor is undefined
// do nothing
void movePrev(List L); 

void prepend(List L, int x);

void append(List L, int x);

// Insert new element before cursor.
// Pre: length()>0, index()>=0
void insertBefore(List L, int x); 

// EnList()
// Places new data at the back of Q.
void EnList(List Q, ListElement data);

// DeList()
// Deletes data at front of Q.
// Pre: !isEmpty(Q)
void DeList(List Q);


// Other Functions ------------------------------------------------------------

// printList()
// Prints a string representation of Q consisting of a space separated list 
// of ints to stdout.
void printList(List Q);

// equals()
// Returns true if A is same int sequence as B, false otherwise.
bool equals(List A, List B);

#endif