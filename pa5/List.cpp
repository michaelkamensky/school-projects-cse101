#include<iostream>
#include<string>
#include<stdexcept>
#include"List.h"

#define DUMMYVAL -1

#define DEBUG 1

// Private Constructor --------------------------------------------------------

// Node constructor
List::Node::Node(ListElement x){
   data = x;
   next = nullptr;
   prev = nullptr;
}

// Class Constructors & Destructors -------------------------------------------

// Creates a new Queue in the empty state.
List::List(){
#if DEBUG
   std::cout << "contructor called" << std::endl;
#endif
   frontDummy = new Node(DUMMYVAL);
   backDummy = new Node(DUMMYVAL);
   frontDummy->next = backDummy;
   backDummy->prev = frontDummy;
   beforeCursor = frontDummy;
   afterCursor = backDummy;
   num_elements = 0;
   pos_cursor = 0;
   
}

#if 0
// Copy Constructor.
Queue::Queue(const Queue& Q){
   std::cout << "copy contructor called" << std::endl;
   // make this an empty Queue
   front = nullptr;
   back = nullptr;
   length = 0;

   // load elements of Q into this Queue
   Node* N = Q.front;
   while( N!=nullptr ){
      this->Enqueue(N->data);
      N = N->next;
   }
}
#endif

// Destructor
List::~List(){
#if DEBUG
   std::cout << "destructor called" << std::endl;
#endif

}


// Access functions --------------------------------------------------------

// length()
// Returns the length of this List.
int List::length() const {
    return num_elements;
}

// front()
// Returns the front element in this List.
// pre: length()>0
ListElement List::front() const {
    return frontDummy->next->data;
}

// back()
// Returns the back element in this List.
// pre: length()>0
ListElement List::back() const {
    return backDummy->prev->data;
}

// position()
// Returns the position of cursor in this List: 0 <= position() <= length().
int List::position() const{
    return pos_cursor;
}

// peekNext()
// Returns the element after the cursor.
// pre: position()<length()
ListElement List::peekNext() const{
    if (pos_cursor < num_elements) {
        return afterCursor->data;
    } else {
        throw std::length_error("List: peekNext(): no more elements to find");
    }
}

// peekPrev()
// Returns the element before the cursor.
// pre: position()>0
ListElement List::peekPrev() const{
    if (pos_cursor > 0) {
        return beforeCursor->data;
    } else {
        throw std::length_error("List: peekPrev(): no more elements to find");
    }
}

// Manipulation procedures -------------------------------------------------

// clear()
// Deletes all elements in this List, setting it to the empty state.
void List::clear() {
    // TODO
}

// moveFront()
// Moves cursor to position 0 in this List.
void List::moveFront() {
    pos_cursor = 0;
    beforeCursor = frontDummy;
    afterCursor = beforeCursor->next;
}

// moveBack()
// Moves cursor to position length() in this List.
void List::moveBack() {
    pos_cursor = num_elements;
    afterCursor = backDummy;
    beforeCursor = afterCursor->prev;

}

// moveNext()
// Advances cursor to next higher position. Returns the List element that
// was passed over. 
// pre: position()<length() 
ListElement List::moveNext() {
    if (pos_cursor < num_elements) {
        beforeCursor = afterCursor;
        afterCursor = afterCursor->next;
        pos_cursor += 1;
        return beforeCursor->data;
    } else {
        throw std::length_error("List: moveNext(): no more elements to move to");
    }
}

// movePrev()
// Advances cursor to next lower position. Returns the List element that
// was passed over. 
// pre: position()>0
ListElement List::movePrev() {
    if (pos_cursor > 0) {
        afterCursor = beforeCursor;
        beforeCursor = beforeCursor->prev;
        pos_cursor -= 1;
        return afterCursor->data;
    } else {
        throw std::length_error("List: movePrev(): no more elements to move to");
    }
}


// insertAfter()
// Inserts x after cursor.
void List::insertAfter(ListElement x) {
    Node *node = new Node(x);
    num_elements += 1;
    node->next = afterCursor;
    afterCursor->prev = node;
    afterCursor = node;
    node->prev = beforeCursor;
    beforeCursor->next = node;
}

// insertBefore()
// Inserts x before cursor.
void List::insertBefore(ListElement x) {}



// to_string()
// Returns a string representation of this List consisting of a comma 
// separated sequence of elements, surrounded by parentheses.
std::string List::to_string() const {
    Node* N = nullptr;
    std::string s = "";

    for(N=frontDummy->next; N!=backDummy; N=N->next){
        s += std::to_string(N->data)+" ";
    }
    
    return s;
}

// Overriden Operators -----------------------------------------------------

// operator<<()
// Inserts string representation of L into stream.
std::ostream& operator<<( std::ostream& stream, const List& L ) {
    std::cout << "operator<< called" << std::endl;
    return stream << L.List::to_string();
}