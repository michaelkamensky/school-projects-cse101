#include<iostream>
#include<string>
#include<stdexcept>
#include"List.h"
#include"BigInteger.h"

using namespace std;

int base2 = 100;

// Helper functions -------------------------------------------------------

// negateList()
// Changes the sign of each integer in List L. Used by sub().
void negateList(List& L) {
    L.moveBack();

    while (true) {
        long digit_mine = L.peekPrev();

        L.setBefore(digit_mine * -1);

        if (L.position() == 1) {
            break;
        }

        L.movePrev();
    }
}

// sumList()
// Overwrites the state of S with A + sgn*B (considered as vectors).
// Used by both sum() and sub().
void static sumList(List& S, List A, List B, int sgn) {
    A.moveFront();
    B.moveFront();

    while (true) {
        long digit_A = 0;
        long digit_B = 0;

        // check if we should read the lists
        if (A.position() != A.length()) {
            digit_A = A.peekNext();
        }
        if (B.position() != B.length()) {
            digit_B = B.peekNext();
        }

        // logic of the function
        S.insertAfter(digit_A + digit_B*sgn);

        // check if we should move through the lists
        if (A.position() != A.length()) {
            A.moveNext();
        }
        if (B.position() != B.length()) {
            B.moveNext();
        }

        // break condition
        if (A.position() == A.length() && B.position() == B.length()) {
            break;
        }
    }
}


// normalizeList()
// Performs carries from right to left (least to most significant
// digits), then returns the sign of the resulting integer. Used
// by add(), sub() and mult().
int static normalizeList(List& L) {
    L.moveFront();
    List R = List();
    long high = 0;
    long low;
    int ret = 1;
    long digit = 0;

    while (L.position() != L.length()) {
        digit = L.peekNext();

        digit += high;
        high = 0;
        if (L.position() != (L.length() -1)) {
            while (digit < 0) {
                digit += base2;
                high -= 1;
            }
        }
        high = high + digit/base2;
        low = digit % base2;
        R.insertBefore(low);

        L.moveNext();
    }
    while (high != 0) {
        low = high % base2;
        high = high / base2;
        R.insertBefore(low);  ; 
    }
    R.moveBack();
    digit = R.peekPrev();
    if (digit < 0) {
        negateList(R);
        normalizeList(R);
        ret = -1;

    }
    while (R.position() > 0) {
        digit = R.peekPrev();
        if (digit == 0) {
            R.eraseBefore();
        } else {
            break;
        }
    }
    if (R.length() == 0) {
        ret = 0;
    }
    // cout << "L = " << L << endl;
    // cout << "R = " << R << endl;
    L = R;

    return ret;
}

// shiftList()
// Prepends p zero digits to L, multiplying L by base^p. Used by mult().
void static shiftList(List& L, int p) {
    L.moveFront();
    for (int i = 0; i < p; i++) {
        L.insertAfter(0);
    }
}

// scalarMultList()
// Multiplies L (considered as a vector) by m. Used by mult().
void static scalarMultList(List& L, ListElement m) {
    L.moveFront();
    long digit;
    while (L.position() != L.length()) {
        digit = L.peekNext();
        digit = digit * m;
        L.setAfter(digit);
        L.moveNext();
    }
}

// Tests -------------------------------------------------------
using namespace std;

void test_1() {
    // tests contructor
    BigInteger bigint = BigInteger();
    BigInteger bigint2 = BigInteger(123456);
    BigInteger bigint3 = BigInteger(-123456);
    BigInteger bigint4 = BigInteger("+123456");
    BigInteger bigint5 = BigInteger("-123456");
    BigInteger bigint6 = BigInteger("+1234567");
    BigInteger bigint_00 = BigInteger("1234567");
    BigInteger bigint_01 = BigInteger("00000100");
    BigInteger bigint_02 = BigInteger("1");
    BigInteger bigint_05 = BigInteger("0");
    BigInteger bigint_06 = BigInteger("00000");
    try {
        BigInteger bigint_03 = BigInteger("");
    }
    catch (std::invalid_argument const& e) {
        cout << "Integer string is empty threw exception: " << e.what() << endl;
    }
    try {
        BigInteger bigint_04 = BigInteger("asdf");
    }
    catch (std::invalid_argument const& e) {
        cout << "Bigint_04 threw exception: " << e.what() << endl;
    }
    BigInteger bigint7 = BigInteger(bigint2);
}

void test_2() {
    // tests compare
    cout << BigInteger("123").compare(BigInteger("321")) << endl; // -1
    cout << BigInteger("123").compare(BigInteger("21")) << endl; // 1
    cout << BigInteger("123").compare(BigInteger("-321")) << endl; // 1
    cout << BigInteger("005").compare(BigInteger("321")) << endl; // -1
    cout << BigInteger("321").compare(BigInteger("321")) << endl; // 0
    cout << BigInteger("-321").compare(BigInteger("-322")) << endl; // 1
    cout << BigInteger("-321").compare(BigInteger("-321")) << endl; // 0
}

void test_3() {
    // tests my mutator functions
    BigInteger bigint_01 = BigInteger("00000");
    BigInteger bigint_02 = BigInteger("+123456");
    bigint_02.makeZero();
    cout << bigint_02.compare(bigint_01) << endl; // 0

    BigInteger bigint_03 = BigInteger("-123456");
    BigInteger bigint_04 = BigInteger("+123456");
    bigint_04.negate();
    cout << bigint_04.compare(bigint_03) << endl; // 0

}

void test_4() {
    // tests my helper functions
    // had to add sub and mult to test them out since otherwise don't have access to them
    // this test will become invalid once the add sub and mult logic has been implamented
    // these are tests for code development

    // for comparison
    BigInteger bigint_01 = BigInteger("+123456");

    List S = List();
    List A = List();
    List B = List();
    List D = List();
    List E = List();
    List F = List();

    A.insertAfter(12);
    A.insertAfter(34);
    A.insertAfter(56);

    B.insertAfter(78);
    B.insertAfter(90);

    D.insertAfter(-450);
    D.insertAfter(-30);
    D.insertAfter(-55);

    E.insertAfter(-450);
    E.insertAfter(321);
    E.insertAfter(25);

    F.insertAfter(100);
    F.insertAfter(00);
    F.insertAfter(00);


    sumList(S, A, B, 2);

    cout << S << endl;
    cout << normalizeList(S) << endl;
    cout << S << endl;

    cout << D << endl;
    cout << normalizeList(D) << endl;
    cout << D << endl;

    cout << E << endl;
    cout << normalizeList(E) << endl;
    cout << E << endl;

    cout << F << endl;
    cout << normalizeList(F) << endl;
    cout << F << endl;


}

void test_5() {
    // tests my helper functions
    // had to add sub and mult to test them out since otherwise don't have access to them
    // this test will become invalid once the add sub and mult logic has been implamented
    // these are tests for code development
    List S = List();
    List D = List();
    List E = List();
    List A = List();
    List B = List();


    D.insertAfter(97);
    D.insertAfter(57);
    D.insertAfter(35);

    E.insertAfter(82);
    E.insertAfter(90);
    E.insertAfter(14);

    sumList(S, D, E, -1);

    cout << S << endl;
    normalizeList(S);

    cout << S << endl;

    A.insertAfter(1);
    A.insertAfter(-233);
    A.insertAfter(15);

    cout << A << endl;
    cout << normalizeList(A) << endl;
    cout << A << endl;

    B.insertAfter(0);
    B.insertAfter(0);
    B.insertAfter(0);

    cout << B << endl;
    cout << normalizeList(B) << endl;
    cout << B << endl;

    B.clear();
    B.insertAfter(1);
    B.insertAfter(-100);
    B.insertAfter(0);

    cout << B << endl;
    cout << normalizeList(B) << endl;
    cout << B << endl;

    B.clear();
    B.insertAfter(1000000);
    B.insertAfter(0);

    cout << B << endl;
    cout << normalizeList(B) << endl;
    cout << B << endl;

    B.clear();
    B.insertAfter(111111);
    B.insertAfter(0);

    cout << B << endl;
    cout << normalizeList(B) << endl;
    cout << B << endl;
    
#if 0
    cout << D << endl;
    cout << normalizeList(D) << endl;
    cout << D << endl;

    cout << E << endl;
    cout << normalizeList(E) << endl;
    cout << E << endl;
#endif 
}

void test_6() {
    // these tests are built of the multiplication helper fucntions

    List A = List();

    A.insertAfter(1);
    A.insertAfter(233);
    A.insertAfter(15);

    normalizeList(A);
    cout << A << endl;

    shiftList(A, 2);
    cout << A << endl;

    scalarMultList(A, 2);
    cout << A << endl;

}

void test_7() {
    // these tests are for BigInteger.add
    BigInteger bigint_00 = BigInteger("1234567");
    BigInteger bigint_01 = BigInteger("00000100");

    BigInteger bigint_02 = BigInteger("41537089");
    BigInteger bigint_03 = BigInteger("143578");

    BigInteger bigint_04 = BigInteger("-980260");
    BigInteger bigint_05 = BigInteger("12356");

    BigInteger bigint_06 = BigInteger("980260");
    BigInteger bigint_07 = BigInteger("-12356");

    BigInteger bigint_08 = BigInteger("+780260");
    BigInteger bigint_09 = BigInteger("-982356");

    BigInteger bigint_10 = BigInteger("45317891012");
    BigInteger bigint_11 = BigInteger("23479865");


    BigInteger bigint_res =  bigint_00.add(bigint_01);
    cout << "Res1 " << bigint_res << endl;

    BigInteger bigint_res2 =  bigint_02.add(bigint_03);
    cout << "Res2 " << bigint_res2 << endl;

    BigInteger bigint_res3 =  bigint_04.add(bigint_05);
    cout << "Res3 " << bigint_res3 << endl;

    BigInteger bigint_res4 =  bigint_06.add(bigint_07);
    cout << "Res4 " << bigint_res4 << endl;

    BigInteger bigint_res5 =  bigint_08.add(bigint_09);
    cout << "Res5 " << bigint_res5 << endl;

    BigInteger bigint_res6 =  bigint_10.add(bigint_11);
    cout << "Res6 " << bigint_res6 << endl;

}

void test_8() {
    // tests to string method
    BigInteger bigint_00 = BigInteger("1234567");
    BigInteger bigint_01 = BigInteger("00000100");
    

    BigInteger bigint_02 = BigInteger("41537089");
    BigInteger bigint_03 = BigInteger("143578");

    BigInteger bigint_04 = BigInteger("-980260");
    BigInteger bigint_05 = BigInteger("12356");

    BigInteger bigint_06 = BigInteger("980260");
    BigInteger bigint_07 = BigInteger("-12356");

    BigInteger bigint_08 = BigInteger("+780260");
    BigInteger bigint_09 = BigInteger("-982356");

    cout << "Big int_00 " << bigint_00 << endl;
    cout << "Big int_01 " << bigint_01 << endl;
    cout << "Big int_02 " << bigint_02 << endl;
    cout << "Big int_03 " << bigint_03 << endl;
    cout << "Big int_04 " << bigint_04 << endl;
    cout << "Big int_05 " << bigint_05 << endl;
    cout << "Big int_06 " << bigint_06 << endl;
    cout << "Big int_07 " << bigint_07 << endl;
    cout << "Big int_08 " << bigint_08 << endl;
    cout << "Big int_09 " << bigint_09 << endl;

}

void test_9() {
    // these tests are for BigInteger.sub
    BigInteger bigint_00 = BigInteger("1234567");
    BigInteger bigint_01 = BigInteger("00000100");

    BigInteger bigint_02 = BigInteger("41537089");
    BigInteger bigint_03 = BigInteger("143578");

    BigInteger bigint_04 = BigInteger("-980260");
    BigInteger bigint_05 = BigInteger("12356");

    BigInteger bigint_06 = BigInteger("980260");
    BigInteger bigint_07 = BigInteger("-12356");

    BigInteger bigint_08 = BigInteger("+780260");
    BigInteger bigint_09 = BigInteger("-982356");


    BigInteger bigint_res =  bigint_00.sub(bigint_01);
    cout << "Res1 " << bigint_res << endl;

    BigInteger bigint_res2 =  bigint_02.sub(bigint_03);
    cout << "Res2 " << bigint_res2 << endl;

    BigInteger bigint_res3 =  bigint_04.sub(bigint_05);
    cout << "Res3 " << bigint_res3 << endl;

    BigInteger bigint_res4 =  bigint_06.sub(bigint_07);
    cout << "Res4 " << bigint_res4 << endl;

    BigInteger bigint_res5 =  bigint_08.sub(bigint_09);
    cout << "Res5 " << bigint_res5 << endl;

}

void test_10() {
    // these tests are for BigInteger.mult
    BigInteger bigint_00 = BigInteger("1234567");
    BigInteger bigint_01 = BigInteger("00000100");

    BigInteger bigint_02 = BigInteger("41537089");
    BigInteger bigint_03 = BigInteger("143578");

    BigInteger bigint_04 = BigInteger("-980260");
    BigInteger bigint_05 = BigInteger("12356");

    BigInteger bigint_06 = BigInteger("980260");
    BigInteger bigint_07 = BigInteger("-12356");

    BigInteger bigint_08 = BigInteger("780260");
    BigInteger bigint_09 = BigInteger("-982356");

    BigInteger bigint_res =  bigint_00.mult(bigint_01);
    cout << "Res1 " << bigint_res << endl;
    BigInteger bigint_res2 =  bigint_02.mult(bigint_03);
    cout << "Res2 " << bigint_res2 << endl;

    BigInteger bigint_res3 =  bigint_04.mult(bigint_05);
    cout << "Res3 " << bigint_res3 << endl;

    BigInteger bigint_res4 =  bigint_06.mult(bigint_07);
    cout << "Res4 " << bigint_res4 << endl;

    BigInteger bigint_res5 =  bigint_08.mult(bigint_09);
    cout << "Res5 " << bigint_res5 << endl;

}

void test_11() {
    // these tests are for BigInteger.mult
    BigInteger bigint_00 = BigInteger("980260");
    BigInteger bigint_01 = BigInteger("-12356");

    BigInteger bigint_res =  bigint_00.mult(bigint_01);
    cout << bigint_00 << " * " << bigint_01 << " = "<< bigint_res << endl;
}

void test_12() {
    // these tests are for BigInteger.mult
    BigInteger bigint_00 = BigInteger("24442");
    BigInteger bigint_01 = BigInteger("2444200");

    BigInteger bigint_res =  bigint_00.add(bigint_01);
    cout << bigint_00 << " + " << bigint_01 << " = "<< bigint_res << endl;
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
    test_10();
    //test_11();
    //test_12();

    return( EXIT_SUCCESS );
}