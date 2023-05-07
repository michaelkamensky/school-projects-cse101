//-----------------------------------------------------------------------------
// ListTest.cpp
// A test client for List ADT
//-----------------------------------------------------------------------------
#include<iostream>
#include<string>
#include<stdexcept>
#include"List.h"

using namespace std;

void print_list(List &L) {
   cout << "List length is " << L.length() << endl;
   cout << "List front is " << L.front() << endl;
   cout << "List back is " << L.back() << endl;
   cout << "List position is " << L.position() << endl;
   try {
      cout << "List peekNext is " << L.peekNext() << endl;
   }
   catch (std::length_error const& e) {
      cout << "List peekNext threw exception: " << e.what() << endl;
   }
   try {
      cout << "List peekPrev is " << L.peekPrev() << endl;
   }
   catch (std::length_error const& e) {
      cout << "List peekPrev threw exception: " << e.what() << endl;
   }
}

void test_1() {
   List L = List();
   cout << "list after creation" << endl;
   print_list(L);
   L.moveFront();
   cout << "list after moveFront" << endl;
   print_list(L);
   L.moveBack();
   cout << "list after moveBack" << endl;
   print_list(L);
   try {
      cout << "List moveNext is " << L.moveNext() << endl;
   }
   catch (std::length_error const& e) {
      cout << "List moveNext threw exception: " << e.what() << endl;
   }
   try {
      cout << "List movePrev is " << L.movePrev() << endl;
   }
   catch (std::length_error const& e) {
      cout << "List movePrev threw exception: " << e.what() << endl;
   }
}

void test_2() {
   List L = List();
   cout << "list after creation" << endl;
   print_list(L);
   L.insertAfter(3);
   L.insertAfter(2);
   L.insertAfter(1);
   cout << "list after insertions" << endl;
   print_list(L);
   cout << L << endl;

}

void test_3() {
   List L = List();
   cout << "list after creation" << endl;
   print_list(L);
   L.insertBefore(3);
   L.insertBefore(2);
   L.insertBefore(1);
   cout << "list after insertions" << endl;
   print_list(L);
   cout << L << endl;

}

void test_4() {
   List L = List();
   cout << "list after creation" << endl;
   print_list(L);
   L.insertAfter(3);
   L.insertAfter(2);
   L.insertAfter(1);
   cout << "list after insertions" << endl;
   print_list(L);
   cout << L << endl;
   try {
      cout << "List moveNext is " << L.moveNext() << endl;
   }
   catch (std::length_error const& e) {
      cout << "List moveNext threw exception: " << e.what() << endl;
   }
   try {
      cout << "List moveNext is " << L.moveNext() << endl;
   }
   catch (std::length_error const& e) {
      cout << "List moveNext threw exception: " << e.what() << endl;
   }
   try {
      cout << "List moveNext is " << L.moveNext() << endl;
   }
   catch (std::length_error const& e) {
      cout << "List moveNext threw exception: " << e.what() << endl;
   }
   try {
      cout << "List moveNext is " << L.moveNext() << endl;
   }
   catch (std::length_error const& e) {
      cout << "List moveNext threw exception: " << e.what() << endl;
   }
}

void test_5() {
   List L = List();
   cout << "list after creation" << endl;
   print_list(L);
   L.insertBefore(3);
   L.insertBefore(2);
   L.insertBefore(1);
   cout << "list after insertions" << endl;
   print_list(L);
   cout << L << endl;
   try {
      cout << "List movePrev is " << L.movePrev() << endl;
   }
   catch (std::length_error const& e) {
      cout << "List movePrev threw exception: " << e.what() << endl;
   }
   try {
      cout << "List movePrev is " << L.movePrev() << endl;
   }
   catch (std::length_error const& e) {
      cout << "List movePrev threw exception: " << e.what() << endl;
   }
   try {
      cout << "List movePrev is " << L.movePrev() << endl;
   }
   catch (std::length_error const& e) {
      cout << "List movePrev threw exception: " << e.what() << endl;
   }
   try {
      cout << "List movePrev is " << L.movePrev() << endl;
   }
   catch (std::length_error const& e) {
      cout << "List movePrev threw exception: " << e.what() << endl;
   }
}

void test_6() {
   List L = List();
   cout << "list after creation" << endl;
   print_list(L);
   L.insertAfter(3);
   L.insertAfter(2);
   L.insertAfter(1);
   cout << L << endl;
   cout << "List peekNext is " << L.peekNext() << endl;
   cout << "List position is " << L.position() << endl;
   L.setAfter(8);
   cout << "list after insertions" << endl;
   cout << L << endl;
}

void test_7() {
   List L = List();
   cout << "list after creation" << endl;
   print_list(L);
   L.insertBefore(3);
   L.insertBefore(2);
   L.insertBefore(1);
   cout << L << endl;
   cout << "List peekPrev is " << L.peekPrev() << endl;
   cout << "List position is " << L.position() << endl;
   L.setBefore(8);
   cout << "list after insertions" << endl;
   cout << L << endl;
}

void test_8() {
   List L = List();
   cout << "list after creation" << endl;
   print_list(L);
   L.insertBefore(3);
   L.insertBefore(2);
   L.insertBefore(1);
   cout << L << endl;
   L.moveFront();
   L.moveNext();
   cout << "List peekNext is " << L.peekNext() << endl;
   cout << "List position is " << L.position() << endl;
   L.eraseAfter();
   cout << "list after eraseAfter" << endl;
   cout << L << endl;
}

void test_9() {
   List L = List();
   cout << "list after creation" << endl;
   print_list(L);
   L.insertBefore(3);
   L.insertBefore(2);
   L.insertBefore(1);
   cout << L << endl;
   L.moveFront();
   L.moveNext();
   cout << "List peekPrev is " << L.peekPrev() << endl;
   cout << "List position is " << L.position() << endl;
   L.eraseBefore();
   cout << "list after eraseBefore" << endl;
   cout << L << endl;
}


int main(){
   //test_1();
   //test_2();
   //test_3();
   //test_4();
   //test_5();
   //test_6();
   //test_7();
   //test_8();
   test_9();




   return( EXIT_SUCCESS );
}


