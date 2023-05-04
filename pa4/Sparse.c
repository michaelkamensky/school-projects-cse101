/********************************************************************************* 
* Michael V Kamensky
* 2023 Winter CSE101 PA#4 
* FindComponents.c 
* Scans file creates two matracies and runs operations on them to print out certain results
*********************************************************************************/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "List.h"
#include "Matrix.h"

/* the main function of this program will use the List.c and Matrix.c ADT
*/
int main(int argc, char *argv[]) {
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

    int matrix_size;
    int a_entries_n;
    int b_entries_n;
    
    // reading the number entries
    fscanf(input_file, "%d %d %d", &matrix_size, &a_entries_n, &b_entries_n);
  
    // creating new matricies of the right size
    Matrix A = newMatrix(matrix_size);
    Matrix B = newMatrix(matrix_size);

    fscanf(input_file, "\n");

    int i;
    int j;
    double val;

    // reading the file to create matrix
    for (int k = 0; k < a_entries_n; k++) {
        int rc = fscanf(input_file, "%d %d %lf", &i, &j, &val);
        if (rc == EOF) {
            fprintf(stderr, "Unexpected end of the file");
            return -1;
        }
        changeEntry(A, i, j, val);
    }

    fscanf(input_file, "\n");

    for (int k = 0; k < b_entries_n; k++) {
        int rc = fscanf(input_file, "%d %d %lf", &i, &j, &val);
        if (rc == EOF) {
            fprintf(stderr, "Unexpected end of the file");
            return -1;
        }
        changeEntry(B, i, j, val);
    }

    // printing out the matrices
    fprintf(output_file, "A has %d non-zero entries:\n", NNZ(A));
    printMatrix(output_file, A);
    fprintf(output_file, "\n");


    fprintf(output_file, "B has %d non-zero entries:\n", NNZ(B));
    printMatrix(output_file, B);
    fprintf(output_file, "\n");

    fprintf(output_file, "(1.5)*A =\n");
    Matrix A_1_5 = scalarMult(1.5, A);
    printMatrix(output_file, A_1_5);
    fprintf(output_file, "\n");
    freeMatrix(&A_1_5);

    fprintf(output_file, "A+B =\n");
    Matrix A_plus_B = sum(A, B);
    printMatrix(output_file, A_plus_B);
    fprintf(output_file, "\n");
    freeMatrix(&A_plus_B);

    fprintf(output_file, "A+A =\n");
    Matrix copyA = copy(A);
    Matrix A_plus_A = sum(A, copyA);
    printMatrix(output_file, A_plus_A);
    fprintf(output_file, "\n");
    freeMatrix(&A_plus_A);
    freeMatrix(&copyA);

    fprintf(output_file, "B-A =\n");
    Matrix B_diff_A = diff(B, A);
    printMatrix(output_file, B_diff_A);
    fprintf(output_file, "\n");
    freeMatrix(&B_diff_A);

    fprintf(output_file, "A-A =\n");
    copyA = copy(A);
    Matrix A_diff_A = diff(A, copyA);
    printMatrix(output_file, A_diff_A);
    fprintf(output_file, "\n");
    freeMatrix(&A_diff_A);
    freeMatrix(&copyA);

    fprintf(output_file, "Transpose(A) =\n");
    Matrix A_trp = transpose(A);
    printMatrix(output_file, A_trp);
    fprintf(output_file, "\n");
    freeMatrix(&A_trp);

    fprintf(output_file, "A*B =\n");
    Matrix A_mul_B = product(A, B);
    printMatrix(output_file, A_mul_B);
    fprintf(output_file, "\n");
    freeMatrix(&A_mul_B);

    fprintf(output_file, "B*B =\n");
    Matrix copyB = copy(B);
    Matrix B_mul_B = product(copyB, B);
    printMatrix(output_file, B_mul_B);
    fprintf(output_file, "\n");
    freeMatrix(&copyB);
    freeMatrix(&B_mul_B);

    freeMatrix(&A);
    freeMatrix(&B);

    // close the files
    fclose(input_file);
    fclose(output_file);
    return 0;
}