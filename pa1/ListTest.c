#include <stdio.h>

#include "List.h"

void test_copy_list(List myList) {

    // tests the copy function
    append(myList, 50);
    prepend(myList, 30);
    append(myList, 20);
    append(myList, 10);
    prepend(myList, 5);

    printList(NULL, myList);
    fprintf(stdout, "\n");

    List copy = copyList(myList);

    printList(NULL, copy);
    fprintf(stdout, "\n");

    clear(myList);
    printList(NULL, myList);
    fprintf(stdout, "\n");

    List copy2 = copyList(myList);
    printList(NULL, copy2);
    fprintf(stdout, "\n");


}

void test_cursor_movment(List myList) {
    // tests move front; move bach, next, previos, and Index
    clear(myList);
    append(myList, 50);
    prepend(myList, 30);
    append(myList, 20);
    append(myList, 10);
    prepend(myList, 5);

    printList(NULL, myList);
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
    append(A, 1);
    append(A, 2);
    append(A, 3);
    append(A, 5);
    moveFront(A);
    insertAfter(A, 12);
    printList(NULL, A);
    if (length(A) != 5)
      return 1;
    return 0;
}

int InsertBefore_length_m(void) {
    List A  = newList();
    append(A, 1);
    append(A, 2);
    append(A, 3);
    append(A, 5);
    moveBack(A);
    insertBefore(A, 12);
    printList(NULL, A);
    if (length(A) != 5)
      return 1;
    return 0;
}

int InsertBefore_length(void){
    List A  = newList();
    prepend(A, 76);
    prepend(A, 4);
    prepend(A, 3);
    prepend(A, 1);
    moveFront(A);
    insertBefore(A, 115);
    if (length(A) != 5)
      return 1;
    return 0;
}

int Delete_length(void) {
    List A  = newList();
    append(A, 1);
    append(A, 2);
    moveFront(A);
    delete (A);
    append(A, 3);
    append(A, 5);
    moveFront(A);
    insertAfter(A, 12);
    delete (A);
    if (length(A) != 3)
      return 1;
    return 0;
}

int InsertAfter_index(void) {
    List A  = newList();
    append(A, 5);
    append(A, 6);
    append(A, 4);
    append(A, 33);
    append(A, 2);
    append(A, 1);
    printList(NULL, A);
    fprintf(stdout, "\n");
    moveBack(A);
    insertAfter(A, 75);
    printList(NULL, A);
    fprintf(stdout, "\n");
    moveNext(A);
    if (index(A) != 6)
      return 1;
    insertAfter(A, 345);
    printList(NULL, A);
    fprintf(stdout, "\n");
    moveBack(A);
    if (index(A) != 7)
      return 2;
    return 0;
}


int DeleteFront_index(void) {
    List A  = newList();
    prepend(A, 5);
    prepend(A, 65);
    prepend(A, 43);
    prepend(A, 2);
    prepend(A, 8);
    prepend(A, 1);
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
    prepend(A, 5);
    append(A, 7);
    prepend(A, 2);
    moveFront(A);
    insertBefore(A, 43);
    fprintf(stdout, "the original list \n");
    printList(NULL, A);
    fprintf(stdout, "\n");
    deleteFront(A);
    fprintf(stdout, "after delete front \n");
    printList(NULL, A);
    fprintf(stdout, "\n");
    printf("index is %d \n", get(A));
    printf("front is %d \n", front(A));
    delete (A);
    printf("front is %d \n", front(A));
    //fprintf(stdout, "after delete \n");
    //printList(NULL, A);
    //fprintf(stdout, "\n");
    if (front(A) != 5)
      return 1;
    return 0;
  }

int main(void) {

#if 0
    List myList  = newList();
    List myList2  = newList();
#endif
#if 0
    prepend(myList, 50);
    prepend(myList, 30);
    prepend(myList, 15);
    moveFront(myList);
    prepend(myList, 55);
    prepend(myList, 45);
    append(myList, 1);
    append(myList, 136);
    printf("the value of the cursor is, %d\n", get(myList));    
    printf("the index of the list is, %d\n", index(myList));

    //insertBefore(myList, 3);
    //movePrev(myList);   
    //printf("the index of the list is, %d\n", get(myList));

    insertAfter(myList, 100);
    moveNext(myList);
    printf("the value of the cursor is, %d\n", get(myList));

    printf("the front of the list is, %d\n", front(myList));
    printf("the back of the list is, %d\n", back(myList));

    printList(NULL, myList);
#endif

#if 0
    prepend(myList, 50);
    prepend(myList, 30);
    prepend(myList, 20);
    deleteFront(myList);
    printf("the front of the list is, %d\n", front(myList));
    moveFront(myList);
    moveNext(myList);
    // should be 50
    printf("the value of the cursor is, %d\n", get(myList));
    append(myList, 0);
    moveBack(myList);
    // should be 0
    printf("the value of the cursor is, %d\n", get(myList));
#endif

#if 0
    append(myList, 0);
    prepend(myList, 50);
    prepend(myList, 15);
    prepend(myList, 25);
    prepend(myList, 75);

    moveFront(myList);
    moveNext(myList);
    printf("the value of the cursor is, %d\n", get(myList));
    moveBack(myList);
    printf("the value of the cursor is, %d\n", get(myList));
    movePrev(myList);
    movePrev(myList);
    movePrev(myList);
    movePrev(myList);
    printf("the value of the cursor is, %d\n", get(myList));
#endif

#if 0
    append(myList, 0);    
    append(myList, 10); 
    append(myList, 20); 
    append(myList, 30);
    append(myList, 40);

    append(myList2, 0);    
    append(myList2, 10); 
    append(myList2, 20); 
    append(myList2, 30);
    append(myList2, 40);

    printf ("the result is %d\n", equals(myList, myList2));

    moveFront(myList2);
    moveNext(myList2);

    set(myList2, 11);

    printf ("the result is %d\n", equals(myList, myList2));
#endif

#if 0
    printList(NULL, myList);
    fprintf(stdout, "\n");
    prepend(myList, 50);
    printList(NULL, myList);
    fprintf(stdout, "\n");
    prepend(myList, 30);
    prepend(myList, 20);
    prepend(myList, 10);
    prepend(myList, 5);

    printList(NULL, myList);
#endif

#if 0
    append(myList, 50);
    printList(NULL, myList);
    fprintf(stdout, "\n");
    append(myList, 30);
    append(myList, 20);
    append(myList, 10);
    append(myList, 5);

    printList(NULL, myList);
#endif

#if 0
    append(myList, 50);
    prepend(myList, 30);
    append(myList, 20);
    append(myList, 10);
    prepend(myList, 5);

    printList(NULL, myList);
    fprintf(stdout, "\n");
    clear(myList);

    printList(NULL, myList);
#endif


    //test_copy_list(myList);
    //test_cursor_movment(myList);
    //printf("The result should be 0, %d \n", InsertAfter_length());
    //printf("The result should be 0, %d \n", InsertBefore_length());
    //printf("The result should be 0, %d \n", Delete_length());
    //printf("The result should be 0, %d \n", InsertAfter_index());
    //printf("The result should be 0, %d \n", DeleteFront_index());
    printf("The result should be 0, %d \n", NonEmpty_front());


    return 0;
}