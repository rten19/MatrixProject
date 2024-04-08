#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

#define RAND_BEGIN 1
#define RAND_END 50

/*
    Creates and returns an empty Matrix. The two-
    dimensional array is dynamically allocated and
    must be freed later.
*/
Matrix createEmptyMatrix(int numRows, int numColumns)
{
    Matrix m;

    m.array = (int**) malloc(numRows * sizeof(int*));
    for (int i = 0; i < numRows; i++)
    {
        m.array[i] = (int*) malloc(numColumns * sizeof(int));
    }

    m.numRows = numRows;
    m.numColumns = numColumns;

    return m;
}

/*
    Insert a random number between RAND_BEGIN and
    RAND_END into each index of a Matrix.
*/
void randomizeMatrix(Matrix* m)
{
    srand(time(NULL));

    for (int i = 0; i < m->numRows; i++)
    {
        for (int j = 0; j < m->numColumns; j++)
        {
            m->array[i][j] = RAND_BEGIN + (rand() % (RAND_END - RAND_BEGIN));
        }
    }
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
}