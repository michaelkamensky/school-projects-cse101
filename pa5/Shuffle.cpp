/********************************************************************************* 
* Michael V Kamensky
* 2023 Winter CSE101 PA#5 
* Shuffle.cpp 
* Build lists of a certain size based of a commandline argumnet and then does a card shuffle until 
* the decks are back to their original states the program also tracks how many times it does it 
*********************************************************************************/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <iomanip>

#include "List.h"

#define DEBUG 0

using namespace std;

void shuffle(List& D) {
    List first_half = List();
    List second_half = List();
    bool is_odd = false;

    int midlength = 0;
    if (D.length() % 2 != 0) {
        is_odd = true;
        //cout << "Is odd" << endl;
        double doublelength = floor(D.length()/2);
        midlength = static_cast<int>(doublelength);
    } else {
        //cout << "Is even" << endl;
        midlength = D.length()/2;
    }

    D.moveFront();
    while (D.position() != midlength) {
        first_half.insertBefore(D.peekNext());
        D.moveNext();
    }
    while (D.position() < D.length()) {
        second_half.insertBefore(D.peekNext());
        D.moveNext();
    }
    // clearing D so we can put new values in it
    D.clear();

#if DEBUG
    cout << "first_half" << endl;
    cout << first_half << endl;
    cout << "second_half" << endl;
    cout << second_half << endl;
#endif

    // move the cursors to the front
    second_half.moveFront();
    first_half.moveFront();

    for (int i = 0; i < first_half.length(); i++) {
        D.insertBefore(second_half.peekNext());
        D.insertBefore(first_half.peekNext());
        if (i < first_half.length() - 1) {
            first_half.moveNext();
        }
        second_half.moveNext();
    }
    if (is_odd) {
        D.insertBefore(second_half.peekNext());
    }

    D.moveFront();
#if DEBUG
    cout << "new D is" << endl;
    cout << D << endl;
#endif
}

/* the main function of this program will use the List.ccp to preform a shuffle on lists of different sizes
*/
int main(int argc, char** argv) {
    if (argc != 2) {
        cerr << "Usage: ./program <integer>" << endl;
        return 1;
    }
    
    int decksize = stoi(argv[1]);

    //cout << decksize << endl;

    // the print out of the main header
    cout << "deck size       shuffle count" << endl;
    cout << "------------------------------" << endl;

    // main loop that will creat and run the helper functions to execute the functionality
    for (int i = 1; i <= decksize; i++) {
        List original = List();
        // filling up the list with the appropriate number of values
        for (int j = 0; j < i; j++) {
            original.insertBefore(j);
        }
        List copy = original;

#if DEBUG
        cout << "original" << endl;
        cout << original << endl;
        cout << "________" << endl;
#endif
        int count = 0;
        shuffle(original);
        count += 1;
#if DEBUG
        cout << original << endl;
#endif
        while (true) {
            if (original == copy) {
                break;
            }
            shuffle(original);
            count += 1;
        }
        cout << " " << i << std::setfill(' ') << std::setw(15 + to_string(count).length() - to_string(i).length()) << count << endl; 
    }
    
    return 0;
}