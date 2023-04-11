#include <stdio.h>

#include "List.h"

int main(void) {

    List myList  = newList();
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

    append(myList, 0);    
    append(myList, 10); 
    append(myList, 20); 
    append(myList, 30);
    append(myList, 40);
    moveBack(myList);
    movePrev(myList);
    movePrev(myList);
    printf("the value of the cursor is, %d\n", get(myList));
    delete(myList);
    moveFront(myList);
    moveNext(myList);
    printf("the value of the cursor is, %d\n", get(myList));
    moveNext(myList);
    printf("the value of the cursor is, %d\n", get(myList));

    return 0;
}