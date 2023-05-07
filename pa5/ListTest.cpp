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


int main(){
   //test_1();
   test_2();




   return( EXIT_SUCCESS );
}


