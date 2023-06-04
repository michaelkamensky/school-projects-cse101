/********************************************************************************* 
* Michael V Kamensky
* 2023 Winter CSE101 PA#7
* DictionaryTest.cpp 
* A test for the dictionary ADT functions
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
    test.setValue("e", 20);
    
    std::cout << test << std::endl;
    
}

void test_2() {
    // constructor test and set value test
    Dictionary test;
    test.setValue("a", 6);
    test.setValue("b", 7);
    test.setValue("e", 25);
    test.setValue("c", 7);
    test.setValue("d", 10);

    std::cout << test << std::endl;

    test.remove("d");
    
    std::cout << test << std::endl;
    
}

void test_3() {
Dictionary A;

std::string S[] =   { // words to insert
                "plaices",
                "ambusher",
                "crosby",
                "wattles",
                "pardoner",
                "pythons",
                "second",
                "forms",
                "impales",
                "pic",
                "verticals",
                "recriminator",
                "depressants",
                "cul",
                "potables",
                "norm",
                "reinsurer",
                "deschooler",
                "recoining",
                "dissocialised",
                "cohabit",
                "hemiolia",
                "cantling",
                "glamorized",
                "millesimal",
                "glagolitic"
            };

    // insert some pairs into A
    for(int i=0; i<26; i++){
        A.setValue(S[i], i+1);
    }

    std::cout << A << std::endl;

    // A.remove("second");

    // std::cout << A << std::endl;

    A.remove("forms");

    std::cout << A << std::endl;
}


int main(){
    // test_1();
    // test_2();
    test_3();


    return( EXIT_SUCCESS );
}