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

void test_sum_matrix(void) {
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

    printf("The m matrix is:\n");
    printMatrix(stdout, m);
    printf("\n");

    Matrix n = newMatrix(3);
    changeEntry(n, 1, 1, 1.5);
    changeEntry(n, 1, 2, 1.5);
    changeEntry(n, 1, 3, 1.5);
    changeEntry(n, 2, 1, 1.5);
    changeEntry(n, 2, 2, 1.5);
    changeEntry(n, 2, 3, 1.5);
    changeEntry(n, 3, 1, 1.5);
    changeEntry(n, 3, 2, 1.5);
    changeEntry(n, 3, 3, 1.5);

    printf("The n matrix is:\n");
    printMatrix(stdout, n);
    printf("\n");

    Matrix result = sum(m,n);

    printf("The sum matrix is:\n");
    printMatrix(stdout, result);
    printf("\n");
}

void test_diff_matrix(void) {
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

    printf("The m matrix is:\n");
    printMatrix(stdout, m);
    printf("\n");

    Matrix n = newMatrix(3);
    changeEntry(n, 1, 1, 1.5);
    changeEntry(n, 1, 2, 1.5);
    changeEntry(n, 1, 3, 1.5);
    changeEntry(n, 2, 1, 1.5);
    changeEntry(n, 2, 2, 1.5);
    changeEntry(n, 2, 3, 1.5);
    changeEntry(n, 3, 1, 1.5);
    changeEntry(n, 3, 2, 1.5);
    changeEntry(n, 3, 3, 1.5);

    printf("The n matrix is:\n");
    printMatrix(stdout, n);
    printf("\n");

    Matrix result = diff(m,n);

    printf("The sum matrix is:\n");
    printMatrix(stdout, result);
    printf("\n");
}

void test_product_matrix(void) {
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

    printf("The m matrix is:\n");
    printMatrix(stdout, m);
    printf("\n");

    Matrix n = newMatrix(3);
    changeEntry(n, 1, 1, 9.0);
    changeEntry(n, 1, 2, 8.0);
    changeEntry(n, 1, 3, 7.0);
    changeEntry(n, 2, 1, 6.0);
    changeEntry(n, 2, 2, 5.0);
    changeEntry(n, 2, 3, 4.0);
    changeEntry(n, 3, 1, 3.0);
    changeEntry(n, 3, 2, 2.0);
    changeEntry(n, 3, 3, 1.0);

    printf("The n matrix is:\n");
    printMatrix(stdout, n);
    printf("\n");

    Matrix result = product(m,n);

    printf("The product matrix is:\n");
    printMatrix(stdout, result);
    printf("\n");
}

void test_product_matrix_2(void) {
    Matrix m = newMatrix(1000);
    changeEntry(m, 2, 5, 1.0);
    changeEntry(m, 2, 25, 2.0);
    changeEntry(m, 2, 120, 3.0);

    printf("The m matrix is:\n");
    printMatrix(stdout, m);
    printf("\n");

    Matrix n = newMatrix(1000);
    changeEntry(n, 1, 2, 1.0);
    changeEntry(n, 3, 2, 6.0);
    changeEntry(n, 5, 2, 1.0);
    changeEntry(n, 15, 2, 6.0);
    changeEntry(n, 35, 2, 5.0);
    changeEntry(n, 120, 2, 4.0);


    printf("The n matrix is:\n");
    printMatrix(stdout, n);
    printf("\n");

    Matrix result = product(m,n);

    printf("The product matrix is:\n");
    printMatrix(stdout, result);
    printf("\n");

    freeMatrix(&m);
    freeMatrix(&n);
    freeMatrix(&result);
}

int main(void) {

    //test_create_matrix();
    //test_cpy_matrix();
    //test_scalar_mult();
    //test_trp_matrix();
    //test_sum_matrix();
    //test_diff_matrix();
    //test_product_matrix();
    test_product_matrix_2();
    return 0;
}