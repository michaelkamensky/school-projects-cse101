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

void test_10() {
   List L = List();
   cout << "list after creation" << endl;
   print_list(L);
   L.insertBefore(3);
   L.insertBefore(2);
   L.insertBefore(1);
   L.insertBefore(5);
   L.insertBefore(7);
   cout << L << endl;
   L.moveFront();
   L.moveNext();
   cout << "List peekPrev is " << L.peekPrev() << endl;
   cout << "List position is " << L.position() << endl;
   cout << "List position after find next 5 is " << L.findNext(5) << endl;
   cout << "List position after find next 100 is " << L.findNext(100) << endl;
}

void test_11() {
   List L = List();
   cout << "list after creation" << endl;
   print_list(L);
   L.insertBefore(3);
   L.insertBefore(2);
   L.insertBefore(1);
   L.insertBefore(5);
   L.insertBefore(7);
   cout << L << endl;
   L.moveBack();
   L.movePrev();
   cout << "List peekPrev is " << L.peekPrev() << endl;
   cout << "List position is " << L.position() << endl;
   cout << "List position after find prev 2 is " << L.findPrev(2) << endl;
   cout << "List position after find prev 100 is " << L.findPrev(100) << endl;
}

void test_12() {
   List L = List();
   cout << "list after creation" << endl;
   print_list(L);
   L.insertBefore(3);
   L.insertBefore(2);
   L.insertBefore(1);
   L.insertBefore(5);
   L.insertBefore(7);
   cout << L << endl;
   L.moveFront();
   while (L.position() < L.length()) {
      cout << L.peekNext() << endl;
      L.moveNext();
   }  
}

void test_13() {
   List L = List();
   cout << "list after creation" << endl;
   print_list(L);
   L.insertBefore(3);
   L.insertBefore(2);
   L.insertBefore(1);
   L.insertBefore(5);
   L.insertBefore(7);
   cout << L << endl;
   List cpy = L;
   cout << cpy << endl;
   cout << "peekNext is " << cpy.peekNext() << endl; 
}

void test_14() {
   List L = List();
   cout << "list after creation" << endl;
   print_list(L);
   cout << "Position is " << L.position() << endl; 
   L.insertBefore(3);
   cout << "Position is " << L.position() << endl; 
   cout << L << endl;
   L.insertBefore(2);
   cout << "Position is " << L.position() << endl; 
   cout << L << endl;
   L.insertBefore(1);
   cout << "Position is " << L.position() << endl; 
   cout << L << endl;
   L.insertBefore(5);
   cout << "Position is " << L.position() << endl; 
   cout << L << endl;
   L.insertBefore(7);
   cout << "Position is " << L.position() << endl; 
   cout << L << endl;   
}

void test_15() {
   List L = List();
   cout << "list after creation" << endl;
   print_list(L);
   L.insertBefore(3);
   L.insertBefore(2);
   L.insertBefore(1);
   L.insertBefore(5);
   L.insertBefore(7);
   cout << L << endl;

   List M = List();
   M.insertBefore(30);
   M.insertBefore(20);
   M.insertBefore(10);
   M.insertBefore(50);
   M.insertBefore(70);
   cout << M << endl;

   List N = L.concat(M);
   cout << N << endl;

}

void test_16() {
   List L = List();
   L.insertBefore(3);
   L.insertBefore(2);
   L.insertBefore(1);
   L.insertBefore(5);
   L.insertBefore(7);
   cout << L << endl;
   print_list(L);

   L.clear();
   cout << L << endl;
   print_list(L);

}

void test_17() {
   List L = List();
   L.insertBefore(3);
   L.insertBefore(2);
   L.insertBefore(1);
   L.insertBefore(5);
   L.insertBefore(7);
   cout << L << endl;

   List M = List();
   M.insertBefore(3);
   M.insertBefore(2);
   M.insertBefore(10);
   M.insertBefore(50);
   M.insertBefore(70);
   cout << M << endl;

   if (L.equals(M)) {
      cout << "L and M are equal lists" << endl;
   } else {
      cout << "L and M are NOT equal lists" << endl;
   }

   List N = List();
   N.insertBefore(3);
   N.insertBefore(2);
   N.insertBefore(1);
   N.insertBefore(5);
   N.insertBefore(7);
   cout << N << endl;

   if (L.equals(N)) {
      cout << "L and N are equal lists" << endl;
   } else {
      cout << "L and N are NOT equal lists" << endl;
   }

   List O = List();
   O.insertBefore(3);
   O.insertBefore(2);
   O.insertBefore(1);
   cout << O << endl;

   if (L.equals(O)) {
      cout << "L and O are equal lists" << endl;
   } else {
      cout << "L and O are NOT equal lists" << endl;
   }


}

void test_18() {
   List L = List();
   L.insertBefore(3);
   L.insertBefore(2);
   L.insertBefore(1);
   L.insertBefore(5);
   L.insertBefore(7);
   cout << L << endl;

   List M = List();
   M.insertBefore(3);
   M.insertBefore(2);
   M.insertBefore(10);
   M.insertBefore(50);
   M.insertBefore(70);
   cout << M << endl;

   if (L == M) {
      cout << "L and M are equal lists" << endl;
   } else {
      cout << "L and M are NOT equal lists" << endl;
   }

   List N = List();
   N.insertBefore(3);
   N.insertBefore(2);
   N.insertBefore(1);
   N.insertBefore(5);
   N.insertBefore(7);
   cout << N << endl;

   if (L == N) {
      cout << "L and N are equal lists" << endl;
   } else {
      cout << "L and N are NOT equal lists" << endl;
   }

   List O = List();
   O.insertBefore(3);
   O.insertBefore(2);
   O.insertBefore(1);
   cout << O << endl;

   if (L == O) {
      cout << "L and O are equal lists" << endl;
   } else {
      cout << "L and O are NOT equal lists" << endl;
   }


}

void test_19() {
   List L = List();
   cout << "list after creation" << endl;
   print_list(L);
   L.insertBefore(3);
   L.insertBefore(2);
   L.insertBefore(1);
   L.insertBefore(5);
   L.insertBefore(7);
   cout << L << endl;

   List M = List();
   M.insertBefore(30);
   M.insertBefore(20);
   M.insertBefore(10);
   M.insertBefore(50);
   M.insertBefore(70);
   cout << M << endl;

   M = L;
   cout << M << endl;

}

void test_20() {
   List L = List();
   cout << "list after creation" << endl;
   L.insertBefore(3);
   L.insertBefore(3);
   L.insertBefore(20);
   L.insertBefore(25);
   L.insertBefore(2);
   L.insertBefore(2);
   L.insertBefore(1);
   L.insertBefore(5);
   L.insertBefore(7);
   L.insertBefore(7);
   cout << L << endl;
   L.moveFront();
   L.moveNext();
   print_list(L);

   L.cleanup();
   cout << L << endl;
   print_list(L);

}

void test_21() {
   List L = List();
   cout << "list after creation" << endl;
   L.insertBefore(3);
   L.insertBefore(3);
   L.insertBefore(20);
   L.insertBefore(25);
   L.insertBefore(2);
   L.insertBefore(2);
   L.insertBefore(1);
   L.insertBefore(5);
   L.insertBefore(7);
   L.insertBefore(7);
   cout << L << endl;
   L.moveBack();
   L.movePrev();
   print_list(L);

   L.cleanup();
   cout << L << endl;
   print_list(L);

}

void test_22() {
   List L = List();
   cout << "list after creation" << endl;
   L.insertBefore(3);
   L.insertBefore(3);
   L.insertBefore(20);
   L.insertBefore(25);
   L.insertBefore(2);
   L.insertBefore(2);
   L.insertBefore(1);
   L.insertBefore(5);
   L.insertBefore(7);
   L.insertBefore(7);
   cout << L << endl;
   L.moveFront();
   L.moveNext();
   L.moveNext();
   L.moveNext();
   L.moveNext();
   L.moveNext();
   print_list(L);

   L.cleanup();
   cout << L << endl;
   print_list(L);

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
   //test_9();
   //test_10();
   //test_11();
   //test_12();
   //test_13();
   //test_14();
   //test_15();
   //test_16();
   //test_17();
   //test_18();
   //test_19();
   //test_20();
   //test_21();
   test_22();




   return( EXIT_SUCCESS );
}


