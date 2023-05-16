#include<iostream>
#include<string>
#include<stdexcept>
#include"List.h"
#include"BigInteger.h"


int power = 2;
long base = 100;

// Class Constructors & Destructors ----------------------------------------

// BigInteger()
// Constructor that creates a new BigInteger in the zero state: 
// signum=0, digits=().
BigInteger::BigInteger() {
    signum = 0;
    digits = List();
}

// BigInteger()
// Constructor that creates a new BigInteger from the long value x.
BigInteger::BigInteger(long x) {
    if (x > 0) {
        signum = 1;
    } else if (x == 0) {
        signum = 0;
    } else {
        signum = -1;
        x = -x;
    }

    digits = List();
    long high;
    long low;
    while (true) {
        if (x == 0) {
            break;
        }
        low = x % base;
        high  = x / base;

        digits.insertBefore(low);

        x = high;
    }

}


// BigInteger()
// Constructor that creates a new BigInteger from the string s.
// Pre: s is a non-empty string consisting of (at least one) base 10 digit
// {0,1,2,3,4,5,6,7,8,9}, and an optional sign {+,-} prefix.
BigInteger::BigInteger(std::string s) {
    if (s.size() == 0) {
        throw std::invalid_argument("BigInteger: Constructor: empty string");
    }

    char first_char = s.front();
    if (first_char == '+') {
        signum = 1;
        s.erase(0, 1);
    } else if (first_char == '-') {
        signum = -1;
        s.erase(0, 1);
    } else {
        signum = 1;
    }

    for (unsigned int i = 0; i < s.size(); i++) {
        if (s[i] < '0' || s[i] > '9') {
            throw std::invalid_argument("BigInteger: Constructor: non-numeric string");
        }
    }

    while(true) {
        if (s[0] == '0') {
            s.erase(0, 1);
        } else {
            break;
        }
    }

    if (s.size() == 0) {
        signum = 0;
    } else {
        for (int i = s.size(); i > 0; i = i - power) {
            if (i - power > 0) {
                std::string sub = s.substr(s.length() - power, power);
                s.erase(s.length() - power, power);
                long value = stol(sub);
                // std::cout << value << std::endl;
                digits.insertBefore(value);
            } else {
                long value = stol(s);
                // std::cout << value << std::endl;
                digits.insertBefore(value);
            }       
        }
    }
}

// BigInteger()
// Constructor that creates a copy of N.
BigInteger::BigInteger(const BigInteger& N) {
    signum = N.signum;
    digits = N.digits;
}

// Access functions --------------------------------------------------------

// sign()
// Returns -1, 1 or 0 according to whether this BigInteger is positive, 
// negative or 0, respectively.
int BigInteger::sign() const {
    return signum;
}


// compare()
// Returns -1, 1 or 0 according to whether this BigInteger is less than N,
// greater than N or equal to N, respectively.
int BigInteger::compare(const BigInteger& N) const {
    if (signum > N.signum) {
        return 1;
    } else if (signum < N.signum) {
        return -1;
    } else if (signum == 0 && N.signum == 0) {
        return 0;
    }

    if (N.digits.length() > digits.length()) {
        return -1 * signum;
    } else if (N.digits.length() < digits.length()) {
        return 1 * signum;
    }

    // creating a copy to iterate over the list can't do it otherwise
    List other = N.digits;
    List mine = digits;

    other.moveBack();
    mine.moveBack();

    while (true) {
        long digit_other = other.peekPrev();
        long digit_mine = mine.peekPrev();

        if (digit_mine > digit_other) {
            return 1 * signum;
        } else if (digit_mine < digit_other) {
            return -1 * signum;
        }

        if (mine.position() == 1) {
            break;
        }

        other.movePrev();
        mine.movePrev();
    }
    return 0;
}

// Manipulation procedures -------------------------------------------------

// makeZero()
// Re-sets this BigInteger to the zero state.
void BigInteger::makeZero() {
    signum = 0;
    digits.clear();
}

// negate()
// If this BigInteger is zero, does nothing, otherwise reverses the sign of 
// this BigInteger positive <--> negative. 
void BigInteger::negate() {
    if (signum != 0) {
        signum = signum * -1;
    }
}

// Helper functions -------------------------------------------------------


// negateList()
// Changes the sign of each integer in List L. Used by sub().
void static negateList(List& L) {
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
                digit += base;
                high -= 1;
            }
        }
        high = high + digit/base;
        low = digit % base;
        R.insertBefore(low);

        L.moveNext();
    }
    while (high != 0) {
        low = high % base;
        high = high / base;
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

// BigInteger Arithmetic operations ----------------------------------------

// add()
// Returns a BigInteger representing the sum of this and N.
BigInteger BigInteger::add(const BigInteger& N) const {
}

// sub()
// Returns a BigInteger representing the difference of this and N.
BigInteger BigInteger::sub(const BigInteger& N) const {
}

// mult()
// Returns a BigInteger representing the product of this and N. 
BigInteger BigInteger::mult(const BigInteger& N) const {}