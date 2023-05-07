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

// Copy Constructor.
List::List(const List& L){
#if DEBUG
    std::cout << "copy contructor called" << std::endl;
#endif
    frontDummy = new Node(DUMMYVAL);
    backDummy = new Node(DUMMYVAL);
    frontDummy->next = backDummy;
    backDummy->prev = frontDummy;
    beforeCursor = frontDummy;
    afterCursor = backDummy;
    num_elements = 0;
    pos_cursor = 0;
    Node *iter = L.frontDummy;
    iter = iter->next;
    while (iter != L.backDummy) {
        std::cout << iter->data << std::endl;
        Node *node = new Node(iter->data);
        node->prev = beforeCursor;
        beforeCursor->next = node;
        beforeCursor = node;
        node->next = afterCursor;
        afterCursor->prev = node;
        num_elements += 1;
        // move to the next node
        iter = iter->next;
    }
    // reset cursor
    beforeCursor = frontDummy;
    afterCursor = beforeCursor->next;
}


// Destructor
List::~List(){
#if DEBUG
    std::cout << "destructor called" << std::endl;
#endif
    // TODO
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
void List::insertBefore(ListElement x) {
    Node *node = new Node(x);
    num_elements += 1;
    pos_cursor += 1;
    node->prev = beforeCursor;
    beforeCursor->next = node;
    beforeCursor = node;
    node->next = afterCursor;
    afterCursor->prev = node;
}

// setAfter()
// Overwrites the List element after the cursor with x.
// pre: position()<length()
void List::setAfter(ListElement x) {
    if (pos_cursor < num_elements) {
        afterCursor->data = x;
    } else {
        throw std::length_error("List: setAfter(): no element to overide");
    }
}

// setBefore()
// Overwrites the List element before the cursor with x.
// pre: position()>0
void List::setBefore(ListElement x) {
    if (pos_cursor > 0) {
        beforeCursor->data = x;
    } else {
        throw std::length_error("List: setBefore(): no element to overide");
    }
}

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

// eraseAfter()
// Deletes element after cursor.
// pre: position()<length()
void List::eraseAfter() {
    if (pos_cursor < num_elements) {
        Node *node = afterCursor;
        afterCursor = afterCursor->next;
        afterCursor->prev = beforeCursor;
        beforeCursor->next = afterCursor;
        delete node;
        num_elements -= 1;
    } else {
        throw std::length_error("List: setAfter(): no element to overide");
    }
}

// eraseBefore()
// Deletes element before cursor.
// pre: position()>0
void List::eraseBefore() {
    if (pos_cursor > 0) {
        Node *node = beforeCursor;
        beforeCursor = beforeCursor->prev;
        beforeCursor->next = afterCursor;
        afterCursor->prev = beforeCursor;
        delete node;
        num_elements -= 1;
    } else {
        throw std::length_error("List: setAfter(): no element to overide");
    }
}

// Other Functions ---------------------------------------------------------

// findNext()
// Starting from the current cursor position, performs a linear search (in 
// the direction front-to-back) for the first occurrence of element x. If x
// is found, places the cursor immediately after the found element, then 
// returns the final cursor position. If x is not found, places the cursor 
// at position length(), and returns -1. 
int List::findNext(ListElement x) {
    while(pos_cursor < num_elements) {
        if(peekNext() == x) {
            return pos_cursor;
        }
        moveNext();
    }
    return -1;
}

// findPrev()
// Starting from the current cursor position, performs a linear search (in 
// the direction back-to-front) for the first occurrence of element x. If x
// is found, places the cursor immediately before the found element, then
// returns the final cursor position. If x is not found, places the cursor 
// at position 0, and returns -1. 
int List::findPrev(ListElement x) {
    while(pos_cursor > 0) {
        if(peekPrev() == x) {
            movePrev();
            return pos_cursor;
        }
        movePrev();
    }
    return -1;
}

// cleanup()
// Removes any repeated elements in this List, leaving only unique elements.
// The order of the remaining elements is obtained by retaining the frontmost 
// occurrance of each element, and removing all other occurances. The cursor 
// is not moved with respect to the retained elements, i.e. it lies between 
// the same two retained elements that it did before cleanup() was called.
void List::cleanup() {
    // TODO
}

#if 0
// concat()
// Returns a new List consisting of the elements of this List, followed by
// the elements of L. The cursor in the returned List will be at postion 0.
List List::concat(const List& L) const {
    List ret = List();
    L.moveFront();
    while (L.position() < L.length()) {
        ret.insertAfter(L.peekNext());
        L.moveNext();
    }
}
#endif

// Overriden Operators -----------------------------------------------------

// operator<<()
// Inserts string representation of L into stream.
std::ostream& operator<<( std::ostream& stream, const List& L ) {
    std::cout << "operator<< called" << std::endl;
    return stream << L.List::to_string();
}