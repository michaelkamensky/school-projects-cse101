#include <stdio.h>
#include <stdlib.h>

#include "Matrix.h"

void test_create_matrix(void) {
    Matrix m = newMatrix(3);
    changeEntry(m, 1, 1, 1.01);
    changeEntry(m, 1, 2, 2.06);
    changeEntry(m, 1, 3, 3.00);
    changeEntry(m, 2, 1, 4.0);
    changeEntry(m, 2, 2, 5.0);
    changeEntry(m, 2, 3, 6.0);
    changeEntry(m, 3, 1, 7.0);
    changeEntry(m, 3, 2, 8.0);
    changeEntry(m, 3, 3, 9.0);
    printMatrix(stdout, m);
}

void test_cpy_matrix(void) {
    Matrix m = newMatrix(3);
    changeEntry(m, 1, 1, 1.01);
    changeEntry(m, 1, 2, 2.06);
    changeEntry(m, 1, 3, 3.00);
    changeEntry(m, 2, 1, 4.0);
    changeEntry(m, 2, 2, 5.0);
    changeEntry(m, 2, 3, 6.0);
    changeEntry(m, 3, 1, 7.0);
    changeEntry(m, 3, 2, 8.0);
    changeEntry(m, 3, 3, 9.0);
    printf("The original matrix is:\n");
    printMatrix(stdout, m);

    Matrix copied = copy(m);
    printf("The copied matrix is:\n");
    printMatrix(stdout, copied);
}

void test_scalar_mult(void) {
    Matrix m = newMatrix(3);
    changeEntry(m, 1, 1, 1.01);
    changeEntry(m, 1, 2, 2.06);
    changeEntry(m, 1, 3, 3.00);
    changeEntry(m, 2, 1, 4.0);
    changeEntry(m, 2, 2, 5.0);
    changeEntry(m, 2, 3, 6.0);
    changeEntry(m, 3, 1, 7.0);
    changeEntry(m, 3, 2, 8.0);
    changeEntry(m, 3, 3, 9.0);
    printf("The original matrix is:\n");
    printMatrix(stdout, m);

    Matrix result = scalarMult(2.0, m);
    printf("The *2 matrix is:\n");
    printMatrix(stdout, result);
}

void test_trp_matrix(void) {
    Matrix m = newMatrix(3);
    changeEntry(m, 1, 1, 1.0);
    changeEntry(m, 1, 2, 2.0);
    changeEntry(m, 1, 3, 3.0);
    changeEntry(m, 2, 1, 4.0);
    changeEntry(m, 2, 2, 5.0);
    changeEntry(m, 2, 3, 6.0);
    changeEntry(m, 3, 1, 7.0);
    changeEntry(m, 3, 2, 8.0);
    changeEntry(m, 3, 3, 9.0);

    printf("The original matrix is:\n");
    printMatrix(stdout, m);
    printf("\n");

    Matrix result = transpose(m);
    printf("The transpose matrix is:\n");
    printMatrix(stdout, result);
    printf("\n");
}

int main(void) {

    //test_create_matrix();
    //test_cpy_matrix();
    //test_scalar_mult();
    test_trp_matrix();
    return 0;
}