#include <stdio.h>
#include <stdlib.h>

#include "List.h"

typedef struct Element {
    int value;
} Element;

static void* create_element(int i) {
    Element *e = malloc(sizeof(Element));
    e->value = i;
    return e;
}

static void printListOfElements(FILE* out, List L) {
    if(out == NULL) {
      out = stdout;
    }
    int prev_index = index(L);
    Element *e;
    moveFront(L);
    while (index(L)>=0) {
      e = get(L);
      fprintf(out, "%d\n", e->value);
      moveNext(L);
    }
    moveFront(L);
    while ( index(L) != prev_index) {
      moveNext(L);
    }
}

void test_cursor_movment(List myList) {
    // tests move front; move bach, next, previos, and Index
    clear(myList);
    append(myList, create_element(50));
    prepend(myList, create_element(30));
    append(myList, create_element(20));
    append(myList, create_element(10));
    prepend(myList, create_element(5));

    printListOfElements(NULL, myList);
    fprintf(stdout, "\n");

    moveFront(myList);
    fprintf(stdout, "The expected value is 0 the res is %d \n", index(myList));

    moveNext(myList);
    fprintf(stdout, "The expected value is 1 the res is %d \n", index(myList));

    moveBack(myList);
    fprintf(stdout, "The expected value is 4 the res is %d \n", index(myList));

    movePrev(myList);
    fprintf(stdout, "The expected value is 3 the res is %d \n", index(myList));

    moveFront(myList);
    fprintf(stdout, "Should result in an error \n");
    movePrev(myList);
    fprintf(stdout, "The expected value is -1 the res is %d \n", index(myList));

    moveBack(myList);
    fprintf(stdout, "Should result in an error \n");
    moveNext(myList);
    fprintf(stdout, "The expected value is -1 the res is %d \n", index(myList));

    clear(myList);

    moveFront(myList);
    fprintf(stdout, "Should result in an error \n");
    fprintf(stdout, "The expected value is -1 the res is %d \n", index(myList));

    moveBack(myList);
    fprintf(stdout, "Should result in an error \n");
    fprintf(stdout, "The expected value is -1 the res is %d \n", index(myList));

}

int InsertAfter_length(void) {
    List A  = newList();
    append(A, create_element(1));
    append(A, create_element(2));
    append(A, create_element(3));
    append(A, create_element(5));
    moveFront(A);
    insertAfter(A, create_element(12));
    printListOfElements(NULL, A);
    if (length(A) != 5)
      return 1;
    return 0;
}

int InsertBefore_length_m(void) {
    List A  = newList();
    append(A, create_element(1));
    append(A, create_element(2));
    append(A, create_element(3));
    append(A, create_element(5));
    moveBack(A);
    insertBefore(A, create_element(12));
    printListOfElements(NULL, A);
    if (length(A) != 5)
      return 1;
    return 0;
}

int InsertBefore_length(void){
    List A  = newList();
    prepend(A, create_element(76));
    prepend(A, create_element(4));
    prepend(A, create_element(3));
    prepend(A, create_element(1));
    moveFront(A);
    insertBefore(A, create_element(115));
    if (length(A) != 5)
      return 1;
    return 0;
}

int Delete_length(void) {
    List A  = newList();
    append(A, create_element(1));
    append(A, create_element(2));
    moveFront(A);
    delete (A);
    append(A, create_element(3));
    append(A, create_element(5));
    moveFront(A);
    insertAfter(A, create_element(12));
    delete (A);
    if (length(A) != 3)
      return 1;
    return 0;
}

int InsertAfter_index(void) {
    List A  = newList();
    append(A, create_element(5));
    append(A, create_element(6));
    append(A, create_element(4));
    append(A, create_element(33));
    append(A, create_element(2));
    append(A, create_element(1));
    printListOfElements(NULL, A);
    fprintf(stdout, "\n");
    moveBack(A);
    if (index(A) != 5)
      return 1;
    insertAfter(A, create_element(75));
    if (index(A) != 5)
      return 2;
    printListOfElements(NULL, A);
    fprintf(stdout, "\n");
    moveNext(A);
    if (index(A) != 6)
      return 3;
    insertAfter(A, create_element(345));
    printListOfElements(NULL, A);
    fprintf(stdout, "\n");
    moveBack(A);
    if (index(A) != 7)
      return 4;
    return 0;
}


int DeleteFront_index(void) {
    List A  = newList();
    prepend(A, create_element(5));
    prepend(A, create_element(65));
    prepend(A, create_element(43));
    prepend(A, create_element(2));
    prepend(A, create_element(8));
    prepend(A, create_element(1));
    moveFront(A);
    deleteFront(A);
    if (index(A) != -1)
      return 1;
    moveBack(A);
    deleteFront(A);
    if (index(A) != 3)
      return 2;
    return 0;
}

int NonEmpty_front(void) {
    List A  = newList();
    prepend(A, create_element(5));
    append(A, create_element(7));
    prepend(A, create_element(2));
    moveFront(A);
    insertBefore(A, create_element(43));
    fprintf(stdout, "the original list \n");
    printListOfElements(NULL, A);
    fprintf(stdout, "\n");
    deleteFront(A);
    fprintf(stdout, "after delete front \n");
    printListOfElements(NULL, A);
    fprintf(stdout, "\n");
    printf("index is " FORMAT "\n", get(A));
    printf("front is " FORMAT "\n", front(A));
    delete (A);
    printf("front is " FORMAT "\n", front(A));
    //fprintf(stdout, "after delete \n");
    //printListOfElements(NULL, A);
    //fprintf(stdout, "\n");
    Element *e = front(A);
    if (e->value != 5)
      return 1;
    return 0;
  }

int main(void) {

    printf("The result should be 0, %d \n", InsertAfter_length());
    printf("The result should be 0, %d \n", InsertBefore_length());
    printf("The result should be 0, %d \n", Delete_length());
    printf("The result should be 0, %d \n", InsertAfter_index());
    printf("The result should be 0, %d \n", DeleteFront_index());
    printf("The result should be 0, %d \n", NonEmpty_front());


    return 0;
}