#include <stdio.h>

#include "List.h"

int main(void) {

    List myList  = newList();

    prepend(myList, 50);
    prepend(myList, 30);
    prepend(myList, 15);
    moveFront(myList);
    prepend(myList, 55);
    prepend(myList, 45);
    append(myList, 1);
    append(myList, 136);
    pcursor(myList);
    printf("the index of the list is, %d\n", index(myList));
    printf("the front of the list is, %d\n", front(myList));
    printf("the back of the list is, %d\n", back(myList));

    return 0;
}