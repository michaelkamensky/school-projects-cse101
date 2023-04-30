//-----------------------------------------------------------------------------
// List.h
// Header file for List ADT
//-----------------------------------------------------------------------------
#ifndef List_H_INCLUDE_
#define List_H_INCLUDE_
#include<stdbool.h>


#define FORMAT "%p"  // format string for ListElement


// Exported types -------------------------------------------------------------
typedef void* ListElement;
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

ListElement front(List L); // Returns front element of L. Pre: length()>0

ListElement back(List L); // Returns back element of L. Pre: length()>0

ListElement get(List L); // Returns cursor element of L. Pre: length()>0, index()>=0



// Manipulation procedures ----------------------------------------------------

// Resets L to its original empty state.
void clear(List L);


// Overwrites the cursor element’s data with x.
// Pre: length()>0, index()>=0
void set(List L, ListElement x); 

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

void prepend(List L, ListElement x);

void append(List L, ListElement x);

// Insert new element before cursor.
// Pre: length()>0, index()>=0
void insertBefore(List L, ListElement x); 

// Insert new element after cursor.
// Pre: length()>0, index()>=0
void insertAfter(List L, ListElement x); 

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
// of pointers to stdout.
void printList(FILE* out, List L); 



#endif