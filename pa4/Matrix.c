#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>

#include "List.h"
#include "Matrix.h"

// structs 
// private Node type
typedef struct EntryObj* Entry;

typedef struct EntryObj {
    int column;
    double value;
} EntryObj;

typedef struct MatrixObj {
    int size;
    List *rows;
} MatrixObj;


// newMatrix()
// Returns a reference to a new nXn Matrix object in the zero state.
Matrix newMatrix(int n) {
    Matrix ret = malloc(sizeof(MatrixObj));
    ret->size = n;
    // adding one since we want the index to start at one and not zero
    ret->rows = calloc(ret->size + 1 , sizeof(List));
    for (int i = 1; i <= ret->size; i++) {
        ret->rows[i] = newList();
    }
    return ret;
}

// freeMatrix()
// Frees heap memory associated with *pM, sets *pM to NULL.
void freeMatrix(Matrix* pM) {
    Matrix m = *pM;
    for (int i = 1; i <= m->size; i++) {
        freeList(&m->rows[i]);
    }
    free(m->rows);
    free(m);
    *pM = NULL; 
}

// Access functions
// size()
// Return the size of square Matrix M.
int size(Matrix M) {
    return M->size;
}

// NNZ()
// Return the number of non-zero elements in M.
int NNZ(Matrix M) {
    int ret = 0;
    for (int i = 1; i <= M->size; i++) {
        ret += length(M->rows[i]);
    }
    return ret;
}

// equals()
// Return true (1) if matrices A and B are equal, false (0) otherwise.
int equals(Matrix A, Matrix B) {
    if (size(A) != size(B)) {
        return 0;
    }
    int n = size(A);
    for (int i = 1; i <= n; i++) { 
        List rowsA = A->rows[i];
        List rowsB = B->rows[i];
        if (length(rowsA) != length(rowsB)) {
            return 0;
        }
        moveFront(rowsA);
        moveFront(rowsB);
        Entry eA;
        Entry eB;
        while (index(rowsA)>=0) {
            eA = get(rowsA);
            eB = get(rowsB);
            if (eA->column != eB->column || eA->value != eB->value) {
                return 0;
            }
        }
    }
    return 1;
}

// Manipulation procedures
// makeZero()
// Re-sets M to the zero Matrix state.
void makeZero(Matrix M) {
    for (int i = 1; i <= M->size; i++) {
        clear(M->rows[i]);
    }
}

// helper function to insert Entries in correct column order
static void rowInsertEntry(List L, int j, double x) {
    moveFront(L);
    Entry val;
    Entry added;
    while (index(L)>=0) {
        val = get(L);
        // if there is an existing entry
        if (val->column == j) {
            val->value = x;
            return;
        }
        if (val->column > j) {
            added = malloc(sizeof(EntryObj));
            added->column = j;
            added->value = x;
            insertBefore(L, added);
            return;
        }
        moveNext(L);
    }
    // if this condition is reached that means we reached the end of the list and the new j is the biggest column value yet
    // this means we have to append it to the list
    added = malloc(sizeof(EntryObj));
    added->column = j;
    added->value = x;
    append(L, added);
}

// changeEntry()
// Changes the ith row, jth column of M to the value x.
// Pre: 1<=i<=size(M), 1<=j<=size(M)
void changeEntry(Matrix M, int i, int j, double x) {
    if (1 > i || i > size(M) || 1 > j || j > size(M)) {
        fprintf(stderr,"Matrix Error: calling change Entry %d, %d does not fit in matrix\n", i, j);
        return;
    }
    List row = M->rows[i];
    rowInsertEntry(row, j, x);
    
}

// Matrix Arithmetic operations
// copy()
// Returns a reference to a new Matrix object having the same entries as A.
Matrix copy(Matrix A) {
    Matrix cpy = newMatrix(A->size);
    List row;
    Entry added;
    Entry data;
    for (int i = 1; i <= A->size; i++) {
        row = A->rows[i];
        moveFront(row);
        while (index(row)>=0) {
            data = get(row);
            added = malloc(sizeof(EntryObj));
            added->column = data->column;
            added->value = data->value;
            append(cpy->rows[i], added);
            moveNext(row);
        }
    }
    return cpy;
}

// transpose()
// Returns a reference to a new Matrix object representing the transpose
// of A.
Matrix transpose(Matrix A) {
    Matrix trp = newMatrix(A->size);
    Entry data;
    //Entry added;
    List row;
    for (int i = 1; i <= A->size; i++) {
        row = A->rows[i];
        moveFront(row);
        while (index(row)>=0) {
            data = get(row);
            //added = malloc(sizeof(EntryObj));
            //added->column = i;
            //added->value = data->value;
            rowInsertEntry(trp->rows[data->column], i, data->value);
            //append(trp->rows[data->column], added);
            moveNext(row);
        }
    }
    return trp;
}

// scalarMult()
// Returns a reference to a new Matrix object representing xA.
Matrix scalarMult(double x, Matrix A) {
    Matrix ret = newMatrix(A->size);
    Entry data;
    Entry added;
    List row;
    for (int i = 1; i <= A->size; i++) {
        row = A->rows[i];
        moveFront(row);
        while (index(row)>=0) {
            data = get(row);
            added = malloc(sizeof(EntryObj));
            added->column = data->column;
            added->value = (data->value) * x;
            append(ret->rows[i], added);
            moveNext(row);
        }
    }
    return ret;
}

// sum()
// Returns a reference to a new Matrix object representing A+B.
// pre: size(A)==size(B)
Matrix sum(Matrix A, Matrix B) {
    if (size(A) == size(B)) {
        Matrix sum = newMatrix(A->size);
        Entry data_A;
        Entry data_B;
        Entry added;
        List row_A;
        List row_B;
        for (int i = 1; i <= A->size; i++) {
            row_A = A->rows[i];
            row_B = B->rows[i];
            moveFront(row_A);
            moveFront(row_B);
            while (index(row_A)>=0) {
                data_A = get(row_A);
                data_B = get(row_B);
                added = malloc(sizeof(EntryObj));
                added->column = data_A->column;
                added->value = data_A->value + data_B->value;
                append(sum->rows[i], added);
                moveNext(row_A);
            }
        }
        return sum;
    } else {
        fprintf(stderr,"error has matrix size of A does not match matrix size of B");
        Matrix sum = newMatrix(A->size);
        return sum;
    }
    
}

// diff()
// Returns a reference to a new Matrix object representing A-B.
// pre: size(A)==size(B)
Matrix diff(Matrix A, Matrix B);

// product()
// Returns a reference to a new Matrix object representing AB
// pre: size(A)==size(B)
Matrix product(Matrix A, Matrix B);

static double round_one_decimal(double val) {
    double rounded_down = floorl(val * 100) / 100;
    return rounded_down;
}

// printMatrix()
// Prints a string representation of Matrix M to filestream out. Zero rows
// are not printed. Each non-zero row is represented as one line consisting
// of the row number, followed by a colon, a space, then a space separated
// list of pairs "(col, val)" giving the column numbers and non-zero values
// in that row. The double val will be rounded to 1 decimal point.
void printMatrix(FILE* out, Matrix M) {
    if(out == NULL) {
      out = stdout;
    }
    for (int i = 1; i <= M->size; i++) {
        List row = M->rows[i];
        if (length(row) != 0) {
            fprintf(out, "%d:", i);
            moveFront(row);
            Entry val;
            while (index(row)>=0) {
                val = get(row);
                fprintf(out, " (%d, %.1f)", val->column, round_one_decimal(val->value));
                moveNext(row);
            }
            fprintf(out, "\n");
        }
    }
}