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

void test_2() {
    // test for iteration functions
    Dictionary test;
    test.setValue("a", 6);
    test.setValue("b", 7);
    test.setValue("e", 25);
    test.setValue("c", 7);
    test.setValue("d", 10);
    test.setValue("d", 5);

    test.begin();

    std::cout << "test.currentKey() = " << test.currentKey() << std::endl;
    std::cout << "test.currentVal() = " << test.currentVal() << std::endl;

    test.next();

    std::cout << "after 1 move next" << std::endl;
    std::cout << "test.currentKey() = " << test.currentKey() << std::endl;
    std::cout << "test.currentVal() = " << test.currentVal() << std::endl;

    test.next();

    std::cout << "after 2 move next" << std::endl;
    std::cout << "test.currentKey() = " << test.currentKey() << std::endl;
    std::cout << "test.currentVal() = " << test.currentVal() << std::endl;

    test.next();

    std::cout << "after 3 move next" << std::endl;
    std::cout << "test.currentKey() = " << test.currentKey() << std::endl;
    std::cout << "test.currentVal() = " << test.currentVal() << std::endl;

    test.next();

    std::cout << "after 4 move next" << std::endl;
    std::cout << "test.currentKey() = " << test.currentKey() << std::endl;
    std::cout << "test.currentVal() = " << test.currentVal() << std::endl;

    test.end();

    std::cout << "test.currentKey() = " << test.currentKey() << std::endl;
    std::cout << "test.currentVal() = " << test.currentVal() << std::endl;

    test.prev();

    std::cout << "after 1 move prev" << std::endl;
    std::cout << "test.currentKey() = " << test.currentKey() << std::endl;
    std::cout << "test.currentVal() = " << test.currentVal() << std::endl;

    test.prev();

    std::cout << "after 2 move prev" << std::endl;
    std::cout << "test.currentKey() = " << test.currentKey() << std::endl;
    std::cout << "test.currentVal() = " << test.currentVal() << std::endl;

    test.prev();

    std::cout << "after 3 move prev" << std::endl;
    std::cout << "test.currentKey() = " << test.currentKey() << std::endl;
    std::cout << "test.currentVal() = " << test.currentVal() << std::endl;

    test.prev();

    std::cout << "after 4 move prev" << std::endl;
    std::cout << "test.currentKey() = " << test.currentKey() << std::endl;
    std::cout << "test.currentVal() = " << test.currentVal() << std::endl;
    
    
}

void test_3() {
    // constructor test and set value test
    Dictionary test;
    test.setValue("a", 6);
    test.setValue("b", 7);
    test.setValue("e", 25);
    test.setValue("c", 7);
    test.setValue("d", 5);
    

    std::cout << test;

    std::string res = test.pre_string();
    std::cout << "preorder_toString\n" << res;
    
}

void test_4() {
    // test for the compare funcs
    Dictionary test;
    test.setValue("a", 6);
    test.setValue("b", 7);
    test.setValue("e", 25);
    test.setValue("c", 7);
    test.setValue("d", 10);
    test.setValue("d", 5);
    

    std::cout << test;

    Dictionary test2;
    test2.setValue("a", 6);
    test2.setValue("b", 7);
    test2.setValue("e", 25);
    test2.setValue("c", 7);
    test2.setValue("d", 5);

    std::cout << test2 << std::endl;
#if 1
    if(test == test2) {
        std::cout << "They are the same dictionaries" << std::endl;
    } else {
        std::cout << "They are different dictionaries" << std::endl;
    }
#endif

    test.setValue("a", 6);
    test.setValue("b", 7);
    test.setValue("e", 25);
    test.setValue("c", 7);
    test.setValue("d", 10); 

    std::cout << test;

    test2.setValue("a", 6);
    test2.setValue("b", 7);
    test2.setValue("e", 25);
    test2.setValue("c", 7);
    test2.setValue("d", 5);

    std::cout << test2 << std::endl;
#if 1
    if(test == test2) {
        std::cout << "They are the same dictionaries" << std::endl;
    } else {
        std::cout << "They are different dictionaries" << std::endl;
    }
#endif

    test.setValue("a", 6);
    test.setValue("b", 7);
    test.setValue("e", 25);
    test.setValue("c", 7);
    test.setValue("d", 5);
    test.remove("e");

    std::cout << test;

    test2.setValue("a", 6);
    test2.setValue("b", 7);
    test2.setValue("e", 25);
    test2.setValue("c", 7);
    test2.setValue("d", 5);

    std::cout << test2 << std::endl;
#if 1
    if(test == test2) {
        std::cout << "They are the same dictionaries" << std::endl;
    } else {
        std::cout << "They are different dictionaries" << std::endl;
    }
#endif   
    
}

void test_5() {
    // test for the compare funcs
    Dictionary test;
    test.setValue("a", 6);
    test.setValue("b", 7);
    test.setValue("e", 25);
    test.setValue("c", 7);
    test.setValue("d", 5);
    

    std::cout << test;

    Dictionary test2;
    test2.setValue("a", 6);
    test2.setValue("b", 7);
    test2.setValue("c", 7);
    test2.setValue("d", 5);

    test2 = test;

    std::cout << test2 << std::endl;
#if 1
    if(test == test2) {
        std::cout << "They are the same dictionaries" << std::endl;
    } else {
        std::cout << "They are different dictionaries" << std::endl;
    }
#endif

    test2.remove("a");
#if 1
    if(test == test2) {
        std::cout << "They are the same dictionaries" << std::endl;
    } else {
        std::cout << "They are different dictionaries" << std::endl;
    }
#endif
}

int main(){
    //test_1();
    //test_2();
    //test_3();
    //test_4();
    test_5();

    return( EXIT_SUCCESS );
}