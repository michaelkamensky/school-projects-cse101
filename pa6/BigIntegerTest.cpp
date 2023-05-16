#include<iostream>
#include<string>
#include<stdexcept>
#include"List.h"
#include"BigInteger.h"

using namespace std;

int base2 = 100;

// Helper functions -------------------------------------------------------

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
    // since the least sginiofcant values are in the front we must start in the front and carry over 
    // into the larger placeholder values
    L.moveFront();
    int carry_over = 0;
    long digit_L = 0;

    while (true) {
        // check if we should read the lists
        if (L.position() != L.length()) {
            digit_L = L.peekNext();
            // logic for dealing with the carry over
            L.setAfter(digit_L + carry_over);
            carry_over = 0;
            digit_L = L.peekNext();
        } else {
            if (carry_over != 0) {
                L.insertAfter(carry_over);
                break;
            }
        }

        // replace base2 with base
        while (digit_L > base2) {
            digit_L -= base2;
            carry_over += 1;
        }
        if (L.position() != L.length()) {
            L.setAfter(digit_L);
        }

        if (L.position() != L.length()) {
            L.moveNext();
        } else {
            break;
        }
    }

    // TODO return the sign of the result
    return 0;
}

// Tests -------------------------------------------------------

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

    A.insertAfter(12);
    A.insertAfter(34);
    A.insertAfter(56);

    B.insertAfter(78);
    B.insertAfter(90);


    sumList(S, A, B, 2);

    cout << S << endl;

    normalizeList(S);

    cout << S << endl;


}

int main(){
    //test_1();
    //test_2();
    //test_3();
    test_4();

    return( EXIT_SUCCESS );
}