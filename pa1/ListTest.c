#include <stdio.h>

#include "List.h"

int main(void) {

    List myList  = newList();
    List myList2  = newList();
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


    append(myList, 50);
    prepend(myList, 30);
    append(myList, 20);
    append(myList, 10);
    prepend(myList, 5);

    printList(NULL, myList);

    moveFront(myList);
    moveNext(myList);



    return 0;
}