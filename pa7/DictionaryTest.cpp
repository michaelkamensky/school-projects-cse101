/********************************************************************************* 
* Michael V Kamensky
* 2023 Winter CSE101 PA#6
* BigInteger.cpp 
* A BigInteger ADT that creates a large int through a list of longs that can be added subtracted and mulitplied with other big ints
*********************************************************************************/ 
#include<iostream>
#include<string>
#include"Dictionary.h"

void test_1() {
    // constructor test and set value test
    Dictionary test;
    test.setValue("a", 6);
    test.setValue("b", 7);
    test.setValue("e", 25);
    test.setValue("c", 7);
    test.setValue("d", 10);
    test.setValue("d", 5);
    

    test.remove("e");
    
}

int main(){
    test_1();



    return( EXIT_SUCCESS );
}