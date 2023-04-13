#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "List.h"

#define CHARLIMIT 100
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

// func gets an array and strcmp all the words and then inserts them in the right order in the list
void sort_list(List L, char* str) {
    // gets all the words into an array
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int word_count = 0;

    char* token = strtok(str, " ");
    while (token != NULL && word_count < MAX_WORDS) {
        strcpy(words[word_count], token);
        word_count++;
        token = strtok(NULL, " ");
    }
    
    // logic to organize the list similar to insertion sort
    // if statment to get the loop started
    if (word_count > 0) {
        append(L, 1);
    }
    // loop to go through all the words in the line
    for (int i = 1; i < (word_count-1); i++) {
        // set curos to front to start the search
        front(L);

        // loop that goes through all the values of the list
        for (int j = 0; i < length(L); j++) {
            // switch for the the three case statments
            switch(strcmp(words[i], get(L))) {
            case 1:
                printf("One\n");
                break;
            case 2:
                printf("Two\n");
                break;
            case 3:
                printf("Three\n");
                break;
            default:
                printf("an error has occurd\n");
            }
        }
    }
    printf("\n");

} 

/* the main function of this program will use the list.c ADT
to organize it
the main function needs to be able 
*/
int main(int argc, char *argv[]) {
    int count = 0;
    char c;

    // Check that we have two file arguments
    if (argc != 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    // open the files
    FILE *input_file = fopen(argv[1], "r");
    FILE *output_file = fopen(argv[2], "w");

    // check if the files are empty if not continues
    if (input_file == NULL || output_file == NULL) {
        printf("Error: could not open files\n");
        return 1;
    }

    // checks that there is at least one character and therefore at least one line
    if(getc(input_file) != EOF) {
        count += 1;
    }

    // counts the number of lines that the file has
    for (c = getc(input_file); c != EOF; c = getc(input_file)) {
        if (c == '\n') {
            count += 1;
        }

    }

    // print out the number of lines
    // printf("The input_file has %d lines\n ", count);

    // using fseek to go to the front of the file
    fseek(input_file, 0, SEEK_SET);

    // crteating an array of correct size to help sort the file
    char **array = calloc(count, sizeof(char*));

    // limit of the number of characters in the file
    char line[CHARLIMIT];

    // looping through the file to get the lines to sort
    while (fgets(line, sizeof(line), input_file)) {
        // creating a list that will be sorted when filled
        List sort = newList();
        // function that takes a string and list and returns a list with the correct ordering
        sort_list(sort, line);

    }

    // close the files
    fclose(input_file);
    fclose(output_file);

/*
    // creates variables that will be used for reading and writting to the files
    char copied_text[30];

    // loop that copies the contents of the inputfile into the outputfile
    while (fscanf(input_file, "%s", copied_text) != EOF) { 

        //prints the input file into the out put file
        fprintf(output_file, "%s ", copied_text);
    }
*/
    return 0;
}