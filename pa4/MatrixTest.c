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

int main(void) {

    test_create_matrix();
    return 0;
}