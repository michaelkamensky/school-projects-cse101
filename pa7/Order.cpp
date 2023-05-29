/********************************************************************************* 
* Michael V Kamensky
* 2023 Winter CSE101 PA#6
* Arithmetic.cpp 
* A main class that uses the BigInteger ADT to preform some opertations
*********************************************************************************/ 
#include<iostream>
#include<string>
#include<stdexcept>
#include <fstream>
#include"Dictionary.h"

#define DEBUG 0

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: ./program input_file output_file" << endl;
        return 1;
    }
   
    const string inputFilename = argv[1];
    const string outputFilename = argv[2];
   
    ifstream inputFile(inputFilename);
    ofstream outputFile(outputFilename);
   
    if (!inputFile.is_open()) {
        cout << "Failed to open the input file." << endl;
        return 1;
    }
   
    if (!outputFile.is_open()) {
        cout << "Failed to open the output file." << endl;
        return 1;
    }

    // creating dictionary
    Dictionary ret = Dictionary();
   
    // reading the file and then adding it to the dictionary 
    std::string line;
    int count = 1;
    while (std::getline(inputFile, line)) {
        //std::cout << line << std::endl;
        ret.setValue(line, count);
        count += 1;
    }

    // now printing in order representation
    outputFile << ret << endl;

    // now printing out pre order representation
    outputFile << ret.pre_string() << endl;

#if DEBUG
    cout <<  "str1 " << str1 << endl;
    cout <<  "str2 " << str2 << endl;
#endif


   
    // closing the files
    inputFile.close();
    outputFile.close();

    return 0;
}