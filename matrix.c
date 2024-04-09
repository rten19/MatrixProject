#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

#define RNUM_BEGIN 1
#define RNUM_END 50

/*
    Creates and returns an empty Matrix. The two-
    dimensional array is dynamically allocated and
    must be freed later.
*/
Matrix* createEmptyMatrix(int numRows, int numColumns)
{
    Matrix* m = (Matrix*) malloc(sizeof(Matrix*));

    m->array = (int**) malloc(numRows * sizeof(int*));
    for (int i = 0; i < numRows; i++)
    {
        m->array[i] = (int*) malloc(numColumns * sizeof(int));
    }

    m->numRows = numRows;
    m->numColumns = numColumns;

    return m;
}

/*
    Insert a random number between RAND_BEGIN and
    RAND_END into each index of a Matrix.

    srand() must be called at the start of the
    program.
*/
void randomizeMatrix(Matrix* m)
{
    for (int i = 0; i < m->numRows; i++)
    {
        for (int j = 0; j < m->numColumns; j++)
        {
            m->array[i][j] = RNUM_BEGIN + (rand() % (RNUM_END - RNUM_BEGIN));
        }
    }
}

/*
    Creates and returns a random Matrix.
*/
Matrix* createRandomMatrix(int numRows, int numColumns)
{
    Matrix* m = createEmptyMatrix(numRows, numColumns);
    randomizeMatrix(m);
    return m;
}

/*
    Adds two matrices together and returns the
    resulting matrix.

    The rows and columns of both matrices must be
    equal.
*/
Matrix* addMatrices(Matrix* a, Matrix* b)
{
    if (a->numRows != b->numRows || a->numColumns != b->numColumns)
        return NULL;

    Matrix* result = createEmptyMatrix(a->numRows, a->numColumns);

    for (int i = 0; i < a->numRows; i++)
    {
        for (int j = 0; j < a->numColumns; j++)
        {
            result->array[i][j] = a->array[i][j] + b->array[i][j];
        }
    }
    return result;
}

/*
    Subtracts matrix b from matrix a and returns the
    resulting matrix.

    The rows and columns of both matrices must be
    equal.
*/
Matrix* subMatrices(Matrix* a, Matrix* b)
{
    if (a->numRows != b->numRows || a->numColumns != b->numColumns)
        return NULL;

    Matrix* result = createEmptyMatrix(a->numRows, a->numColumns);

    for (int i = 0; i < a->numRows; i++)
    {
        for (int j = 0; j < a->numColumns; j++)
        {
            result->array[i][j] = a->array[i][j] - b->array[i][j];
        }
    }
    return result;
}

/*
    Simple (but perhaps slow) implementation of
    matrix multiplication. Returns the product
    of two matrices if the operation is successful,
    NULL otherwise.

    The first matrix's number of columns must
    be equal to the second matrix's number of
    rows.
*/
Matrix* multiplyMatrices(Matrix* a, Matrix* b)
{
    if (a->numColumns != b->numRows)
        return NULL;

    Matrix* result = createEmptyMatrix(a->numRows, b->numColumns);
    
    for (int i = 0; i < a->numRows; i++)
    {
        for (int j = 0; j < b->numColumns; j++)
        {
            for (int k = 0; k < b->numRows; k++)
            {
                result->array[i][j] += a->array[i][k] * b->array[k][j];
            }
        }
    }
    return result;
}

/*
    Displays all the elements of a Matrix.
*/
void displayMatrix(Matrix* m)
{
    for (int i = 0; i < m->numRows; i++)
    {
        for (int j = 0; j < m->numColumns - 1; j++)
        {
            printf("%i\t", m->array[i][j]);
        }
        printf("%i\n", m->array[i][m->numColumns - 1]);
    }
}

/*
    Frees the two-dimensional array of the Matrix
    which is dynamically allocated.
*/
void freeMatrix(Matrix* m)
{
    free(m->array);
    free(m);
}