/********************************************************************************* 
* Michael V Kamensky
* 2023 Winter CSE101 PA#4 
* Matrix.c
* Matrix ADT for sparse matrixes back end functions, uses an array list to simulate a sparse matrix
*********************************************************************************/ 

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
        //free all entries in the list 
        List row = m->rows[i];
        moveFront(row);
        while(index(row)>=0) {
            free(get(row));
            moveNext(row);
        }
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
            moveNext(rowsA);
            moveNext(rowsB);
        }
    }
    return 1;
}

// Manipulation procedures
// makeZero()
// Re-sets M to the zero Matrix state.
void makeZero(Matrix M) {
    for (int i = 1; i <= M->size; i++) {
        List row = M->rows[i];
        moveFront(row);
        while(index(row)>=0) {
            free(get(row));
            moveNext(row);
        }
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
            if (x == 0.0) {
                free(val);
                delete(L);
            } else {
                val->value = x;
            }
            return;
        }
        if (val->column > j) {
            if (x != 0.0) {
                added = malloc(sizeof(EntryObj));
                added->column = j;
                added->value = x;
                insertBefore(L, added);
            }
            return;
        }
        moveNext(L);
    }
    // if this condition is reached that means we reached the end of the list and the new j is the biggest column value yet
    // this means we have to append it to the list
    if (x != 0.0 ) {
        added = malloc(sizeof(EntryObj));
        added->column = j;
        added->value = x;
        append(L, added);
    }
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

static void moveNextIfAny(List row) {
    if (index(row) >= 0) {
        moveNext(row);
    }
}

static void *getIfAny(List row) {
    void *ret = NULL;
    if (index(row) >= 0) {
        ret = get(row);
    }
    return ret;
}

// sum()
// Returns a reference to a new Matrix object representing A+B.
// pre: size(A)==size(B)
Matrix sum(Matrix A, Matrix B) {
    if (size(A) == size(B)) {
        Matrix Acopy = NULL;
        if (A == B) {
            // if A == B you need to have a copy to properly iterate through the matricies lists
            Acopy = copy(A);
            B = Acopy;
        }
        Matrix sum = newMatrix(A->size);
        List row_A;
        List row_B;
        for (int i = 1; i <= A->size; i++) {
            row_A = A->rows[i];
            row_B = B->rows[i];
            moveFront(row_A);
            moveFront(row_B);
            while (1) {
                if (index(row_A) < 0 && index(row_B) < 0) {
                    break;
                }
                Entry entry_A = getIfAny(row_A);
                Entry entry_B = getIfAny(row_B);
                if (entry_A && entry_B) {
                    if (entry_A->column == entry_B->column) {
                        double value = (entry_A->value + entry_B->value);
                        changeEntry(sum, i, entry_A->column, value);
                        moveNextIfAny(row_A);
                        moveNextIfAny(row_B);
                    }
                    else if (entry_A->column > entry_B->column) {
                        changeEntry(sum, i, entry_B->column, entry_B->value);
                        moveNextIfAny(row_B);
                    }
                    else if (entry_A->column < entry_B->column) {
                        changeEntry(sum, i, entry_A->column, entry_A->value);
                        moveNextIfAny(row_A);
                    }
                } 
                else if (entry_A) {
                    changeEntry(sum, i, entry_A->column, entry_A->value);
                    moveNextIfAny(row_A);
                } 
                else if (entry_B) {
                    changeEntry(sum, i, entry_B->column, entry_B->value);
                    moveNextIfAny(row_B);
                }
            }
        }
        if (Acopy != NULL) {
            freeMatrix(&Acopy);
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
Matrix diff(Matrix A, Matrix B) {
    if (size(A) == size(B)) {
        Matrix Acopy = NULL;
        if (A == B) {
            // if A == B you need to have a copy to properly iterate through the matricies lists
            Acopy = copy(A);
            B = Acopy;
        }
        Matrix sum = newMatrix(A->size);
        List row_A;
        List row_B;
        for (int i = 1; i <= A->size; i++) {
            row_A = A->rows[i];
            row_B = B->rows[i];
            moveFront(row_A);
            moveFront(row_B);
            while (1) {
                if (index(row_A) < 0 && index(row_B) < 0) {
                    break;
                }
                Entry entry_A = getIfAny(row_A);
                Entry entry_B = getIfAny(row_B);
                if (entry_A && entry_B) {
                    if (entry_A->column == entry_B->column) {
                        double value = (entry_A->value - entry_B->value);
                        if (value != 0.0) {
                            changeEntry(sum, i, entry_A->column, value);
                        }
                        moveNextIfAny(row_A);
                        moveNextIfAny(row_B);
                    }
                    else if (entry_A->column > entry_B->column) {
                        changeEntry(sum, i, entry_B->column, - entry_B->value);
                        moveNextIfAny(row_B);
                    }
                    else if (entry_A->column < entry_B->column) {
                        changeEntry(sum, i, entry_A->column, entry_A->value);
                        moveNextIfAny(row_A);
                    }
                } 
                else if (entry_A) {
                    changeEntry(sum, i, entry_A->column, entry_A->value);
                    moveNextIfAny(row_A);
                } 
                else if (entry_B) {
                    changeEntry(sum, i, entry_B->column, -entry_B->value);
                    moveNextIfAny(row_B);
                }
            }
        }
        if (Acopy != NULL) {
            freeMatrix(&Acopy);
        }
        return sum;
    } else {
        fprintf(stderr,"error has matrix size of A does not match matrix size of B");
        Matrix sum = newMatrix(A->size);
        return sum;
    }  
}

// vector product of two lists helper function
static double vector_product(List A, List B, int *is_zero) {
    double ret = 0.0;
    *is_zero = 1;
    moveFront(A);
    moveFront(B);
    while (1) {
        if (index(A) < 0 ||  index(B) < 0) {
            break;
        }
        Entry entry_A = get(A);
        Entry entry_B = get(B);
        if (entry_A->column == entry_B->column) {
            ret += (entry_A->value * entry_B->value);
            *is_zero = 0;
            moveNext(A);
            moveNext(B);
        }
        else if (entry_A->column > entry_B->column) {
            moveNext(B);
        }
        else if (entry_A->column < entry_B->column) {
            moveNext(A);
        }
    }
    return ret;
}

// product()
// Returns a reference to a new Matrix object representing AB
// pre: size(A)==size(B)
Matrix product(Matrix A, Matrix B) {
    Matrix AB = newMatrix(size(A));
    if (size(A) == size(B)) {     
        Matrix Acopy = NULL;
        if (A == B) {
            // if A == B you need to have a copy to properly iterate through the matricies lists
            Acopy = copy(A);
            B = Acopy;
        } 
        Matrix Bt = transpose(B);
        double value;
        int is_zero;
        for (int i = 1; i <= A->size; i++) {
            List row_i = A->rows[i];
            if (row_i == 0 ) {
                break;
            }
            for (int j = 1; j <= B->size; j++) {
                // rows in transpose Matrix are the columns of original
                List column_j = Bt->rows[j];
                if (column_j == 0 ) {
                    break;
                }
                value = vector_product(row_i, column_j, &is_zero);
                if (!is_zero) {
                    changeEntry(AB, i, j, value);
                }
            }
        }
        freeMatrix(&Bt);
        if (Acopy != NULL) {
            freeMatrix(&Acopy);
        }
    } else {
        fprintf(stderr,"error has matrix size of A does not match matrix size of B"); 
    }
    return AB; 
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
                fprintf(out, " (%d, %.1f)", val->column, val->value);
                moveNext(row);
            }
            fprintf(out, "\n");
        }
    }
}