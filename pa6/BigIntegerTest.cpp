#include<iostream>
#include<string>
#include<stdexcept>
#include"List.h"
#include"BigInteger.h"

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


int main(){
    //test_1();
    test_2();

    return( EXIT_SUCCESS );
}