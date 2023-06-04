/********************************************************************************* 
* Michael V Kamensky
* 2023 Winter CSE101 PA#8
* WordFrequency.cpp
* A main class that uses the dictionary ADT to construct and dictionary of the frequencies of words in a file
*********************************************************************************/ 
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>

#include"Dictionary.h"

using namespace std;

#define MAX_LEN 300

int main(int argc, char * argv[]){

   int line_count;
   size_t begin, end, len;
   ifstream in;
   ofstream out;
   string line;
   string tokenBuffer;
   string token;
   // string delim = " "; 
   string delim = " \t\\\"\',<.>/?;:[{]}|`~!@#$^&*()\%-_=+0123456789";

   // check command line for correct number of arguments
   if( argc != 3 ){
      cerr << "Usage: " << argv[0] << " <input file> <output file>" << endl;
      return(EXIT_FAILURE);
   }

   // open files for reading and writing 
   in.open(argv[1]);
   if( !in.is_open() ){
      cerr << "Unable to open file " << argv[1] << " for reading" << endl;
      return(EXIT_FAILURE);
   }

   out.open(argv[2]);
   if( !out.is_open() ){
      cerr << "Unable to open file " << argv[2] << " for writing" << endl;
      return(EXIT_FAILURE);
   }

   // read each line of input file, then count and print tokens 
   line_count = 0;
   Dictionary dict;
   while( getline(in, line) )  {
      line_count++;
      len = line.length();
      
      // get first token
      begin = min(line.find_first_not_of(delim, 0), len);
      end   = min(line.find_first_of(delim, begin), len);
      token = line.substr(begin, end-begin);
      
      while( token!="" ){  // we have a token
        
        // making token lower case
        for (char& c : token) {
            c = std::tolower(c);
        }
        // logic to add to the dictionary
        if (dict.contains(token)) {
            int num = dict.getValue(token);
            num += 1;
            dict.setValue(token, num);
        } else {
            dict.setValue(token, 1);
        }

         // get next token
         begin = min(line.find_first_not_of(delim, end+1), len);
         end   = min(line.find_first_of(delim, begin), len);
         token = line.substr(begin, end-begin);
      }
#if 0
      // print tokens in this line
      out << "line " << line_count << " contains " << token_count;
      out << " token" << (token_count==1?"":"s") << endl;
      out << tokenBuffer << endl;
#endif
   }

   // logic to print out the dictionary
   out << dict << endl;

   // close files 
   in.close();
   out.close();

   return(EXIT_SUCCESS);
}
