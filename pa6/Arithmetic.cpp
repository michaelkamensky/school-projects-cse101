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
#include"List.h"
#include"BigInteger.h"

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
   
   string str1, str2;
   
   // reading the inputfile to create the Big Integers
   getline(inputFile, str1);

   // reading a line that is empty to move past it
   getline(inputFile, str2);

   // reading a line again to overide str2 with the actual string
   getline(inputFile, str2);

#if DEBUG
   cout <<  "str1 " << str1 << endl;
   cout <<  "str2 " << str2 << endl;
#endif

   BigInteger A = BigInteger(str1);
   BigInteger B = BigInteger(str2);

   outputFile << A << endl;
   outputFile << endl;

   outputFile << B << endl;
   outputFile << endl;

   outputFile << A + B << endl;
   outputFile << endl;

   outputFile << A - B << endl;
   outputFile << endl;

   outputFile << A - A << endl;
   outputFile << endl;

   outputFile << (3 * A) - (2 * B) << endl;
   outputFile << endl;

   outputFile << A * B << endl;
   outputFile << endl;

   outputFile << A * A << endl;
   outputFile << endl;

   outputFile << B * B << endl;
   outputFile << endl;

   outputFile << 9 * (A * A * A * A) + 16 * (B * B * B * B * B)<< endl;
   outputFile << endl;

   
   // closing the files
   inputFile.close();
   outputFile.close();
   
   return 0;
}