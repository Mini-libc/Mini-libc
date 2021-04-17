#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <err.h>
#include <assert.h>


typedef struct Matrix{
    size_t rows;
    size_t cols;
    double **m; // access cell with myMatrix->m[i][j]
}Matrix;

Matrix *createMatrix(size_t rows, size_t cols); // forall i,j , A[i][j] = 0
Matrix *createMatrixId(size_t size); // return the identity matrix
void freeMatrix(Matrix *m);

void matAdd(Matrix *mSource, Matrix *mDest); // A+B -> B
void matAddScalar(Matrix *m, double lambda); // A[i][j] += lambda
void matScale(Matrix *m, double lambda); // lambda*A -> A
void matMultiply(Matrix *mA, Matrix *mB, Matrix *mC); // AB -> C
void matTranspose(Matrix *m); // transpose A in place
void matTransform(Matrix *m, double (*f)(double)); // apply f(n) to each A[i][j]

int matIsDiagonal(Matrix *m);

void matPrint(Matrix *m);

#endif
