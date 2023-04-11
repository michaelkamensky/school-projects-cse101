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

// Resets L to its original empty state.
void clear(List L);


// Overwrites the cursor element’s data with x.
// Pre: length()>0, index()>=0
void set(List L, int x); 

// If L is non-empty, sets cursor under the front element,
// otherwise does nothing.
void moveFront(List L); 

// If L is non-empty, sets cursor under the back element,
// otherwise does nothing.
void moveBack(List L); 

// temp func that prints the value of the cursor
// for testing purposes
void pcursor(List L);

// If cursor is defined and not at front, move cursor one
// step toward the front of L; if cursor is defined and at
// front, cursor becomes undefined; if cursor is undefined
// do nothing
void movePrev(List L); 

// If cursor is defined and not at back, move cursor one
// step toward the back of L; if cursor is defined and at
// back, cursor becomes undefined; if cursor is undefined
// do nothing
void moveNext(List L); 

void prepend(List L, int x);

void append(List L, int x);

// Insert new element before cursor.
// Pre: length()>0, index()>=0
void insertBefore(List L, int x); 

// Insert new element after cursor.
// Pre: length()>0, index()>=0
void insertAfter(List L, int x); 

// EnList()
// Places new data at the back of Q.
void EnList(List Q, ListElement data);

// DeList()
// Deletes data at front of Q.
// Pre: !isEmpty(Q)
void DeList(List Q);

// Delete the front element. Pre: length()>0
void deleteFront(List L); 

// Delete the back element. Pre: length()>0
void deleteBack(List L); 

// Delete cursor element, making cursor undefined.
// Pre: length()>0, index()>=0
void delete(List L); 



// Other Functions ------------------------------------------------------------

// printList()
// Prints a string representation of Q consisting of a space separated list 
// of ints to stdout.
void printList(FILE* out, List L); 

// Returns a new List representing the same integer
// sequence as L. The cursor in the new list is undefined,
// regardless of the state of the cursor in L. The state
// of L is unchanged.
List copyList(List L); 

// Returns a new List which is the concatenation of
// A and B. The cursor in the new List is undefined,
// regardless of the states of the cursors in A and B.
// The states of A and B are unchanged.
List concatList(List A, List B); 



#endif