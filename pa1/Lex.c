#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "List.h"

#define CHARLIMIT 4096
//#define DEBUG 1


char *mystrdup(char *s) {
    size_t size = strlen(s);
    if (s[size - 1] == '\n') {
        s[size - 1] = 0;
    }
    char* ret = malloc(size + 1);
    strcpy(ret, s);
    return ret;
}

// func gets an array and strcmp all the words and then inserts them in the right order in the list
void sort_list(List L, char** myarray, int count) {
    // gets all the words into an array
    
    // logic to organize the list similar to insertion sort
    // if statment to get the loop started
    if (count > 0) {
        append(L, 0);
    }
    // loop to go through all the words in the line
    for (int i = 1; i < (count); i++) {
        char* new = myarray[i];
        // set curos to front to start the search
        moveFront(L);

        while (true) {
            char* current = myarray[get(L)];
            // is true if and only if s1 comes before s2
            if(strcmp(new, current) < 0) {
                insertBefore(L, i);
                break;
            } else {
                if ((index(L) + 1) == length(L)) {
                    insertAfter(L, i);
                    break;
                } else {
                    moveNext(L);
                }
            }
        }
    }
}

void do_output(FILE *fout, List L, char** myarray) {
    moveFront(L);
    for(int i = 0; i < length(L); i++){
        fprintf(fout, "%s\n", myarray[get(L)]);
        moveNext(L);
    }
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


    // counts the number of lines that the file has
    bool last_is_newline = false;
    for (c = getc(input_file); c != EOF; c = getc(input_file)) {
        if (c == '\n') {
            count += 1;
            last_is_newline = true;
        } else {
           last_is_newline = false; 
        }

    }
    // there is no terminating new line
    if (last_is_newline == false) {
        count += 1;
    }

    // print out the number of lines
    // printf("The input_file has %d lines\n ", count);

    // using fseek to go to the front of the file
    fseek(input_file, 0, SEEK_SET);

    // crteating an array of correct size to help sort the file
    char **myarray = calloc(count, sizeof(char*));

    // limit of the number of characters in the file
    char line[CHARLIMIT];

    // looping through the file to get the lines to sort
    int i = 0;
    while (fgets(line, sizeof(line), input_file)) {
#ifdef DEBUG
        printf("%s\n", line);
#endif
        myarray[i] = mystrdup(line);
        i += 1;    
    }
    List sort = newList();
    sort_list(sort, myarray, count);
#ifdef DEBUG
    printList(NULL, sort);
#endif
    do_output(output_file, sort, myarray);

    // free memory
    freeList(&sort);
    for (int j = 0; j < count; j++) {
        free(myarray[j]);
    }
    free(myarray);


    // close the files
    fclose(input_file);
    fclose(output_file);

    return 0;
}