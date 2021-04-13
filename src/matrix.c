#include "matrix.h"

Matrix *createMatrix(size_t rows, size_t cols)
{
    Matrix *mat = malloc(sizeof(Matrix));
    if(mat == NULL)
        errx(EXIT_FAILURE, "Couldnt create matrix");
    mat->rows = rows;
    mat->cols = cols;
    int memSize = sizeof(double*) * rows + sizeof(double) * cols * rows;
    mat->m = (double **)malloc(memSize);
    if(mat->m == NULL)
        errx(EXIT_FAILURE, "Couldnt create matrix");

    double *ptr = (double *)(mat->m + rows); // ptr points to first element
    for(size_t i = 0; i < rows; i++) // set rows pointer correctly
        mat->m[i] = (ptr + cols * i);

    for(size_t i = 0; i < rows; i++) // clear matrix
        for(size_t j = 0; j < cols; j++)
            mat->m[i][j] = 0;

    return mat;
}

Matrix *createMatrixId(size_t size)
{
    Matrix *mat = createMatrix(size, size);
    for(size_t i = 0; i < size; i++)
        mat->m[i][i] = 1;
    return mat;
}

void freeMatrix(Matrix *m)
{
    free(m->m);
    free(m);
}
void matAdd(Matrix *mSource, Matrix *mDest)
{
    assert(mSource->rows == mDest->rows && mSource->cols == mDest->cols);

    for(size_t i = 0; i < mSource->rows; i++)
        for(size_t j = 0; j < mSource->cols; j++)
            mDest->m[i][j] += mSource->m[i][j];
}

void matAddScalar(Matrix *m, double lambda)
{
    for(size_t i = 0; i < m->rows; i++)
        for(size_t j = 0; j < m->cols; j++)
            m->m[i][j] += lambda;
}

void matScale(Matrix *m, double lambda)
{
    for(size_t i = 0; i < m->rows; i++)
        for(size_t j = 0; j < m->cols; j++)
            m->m[i][j] *= lambda;
}

void matMultiply(Matrix *mA, Matrix *mB, Matrix *mC)
{
    assert(mA->cols == mB->rows);
    assert(mC->rows == mA->rows && mC->cols == mB->cols);

    double cellValue = 0;
    for(size_t i = 0; i < mC->rows; i++) // for each mC cell
    {
        for(size_t j = 0; j < mC->cols; j++)
        {
            for(size_t k = 0; k < mA->cols; k++)
                cellValue += mA->m[i][k] * mB->m[k][j];
            mC->m[i][j] = cellValue;
            cellValue = 0; // reset cellValue
        }
    }
}

void matTranspose(Matrix *m)
{
    Matrix *result = createMatrix(m->cols, m->rows); //create the transpose
    for(size_t i = 0; i < m->rows; i++)
    {
        for(size_t j = 0; j < m->cols; j++)
        {
            result->m[j][i] = m->m[i][j];
        }
    }

    //replace m with its transpose
    freeMatrix(m);
    m = result;
}

void matTransform(Matrix *m, double (*f)(double))
{
    for(size_t i = 0; i < m->rows; i++)
        for(size_t j = 0; j < m->cols; j++)
            m->m[i][j] = (*f)(m->m[i][j]);
}

int matIsDiagonal(Matrix *m)
{
    if(m->rows != m->cols)
        return 0;

    for(size_t i = 0; i < m->rows; i++)
    {
        for(size_t j = 0; j < m->cols; j++)
        {
            if(i != j && fabs(m->m[i][j]) > 10e-5)
                return 0;
        }
    }
    return 1;
}

void matPrint(Matrix *m)
{
    for(size_t i = 0; i < m->rows; i++)
    {
        for(size_t j = 0; j < m->cols; j++)
            printf("%.5lf", m->m[i][j]);
        printf("\n");
    }
}

