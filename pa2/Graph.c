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

// private Graph type
typedef struct GraphObj* Graph;

// private GraphObj type
typedef struct GraphObj{
   ListElement data;
   Graph next;
   Graph previous;
} GraphObj;

// private ListObj type
typedef struct ListObj{
   Graph front;
   Graph back;
   int index;
   Graph cursor;
   int length;
} ListObj;



// Constructors-Destructors ---------------------------------------------------


// Access functions -----------------------------------------------------------


// Manipulation procedures ----------------------------------------------------


// Other Functions ------------------------------------------------------------

