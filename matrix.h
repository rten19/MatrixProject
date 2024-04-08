#ifndef matrix_h
#define matrix_h

/*
    A simple struct implementation of a Matrix.
    A Matrix simply includes a two-dimensional
    integer array and the numbers of rows and
    columns.
*/
typedef struct Matrix
{
    int** array;
    int numRows;
    int numColumns;
} Matrix;

Matrix createEmptyMatrix(int numRows, int numColumns);
void randomizeMatrix(Matrix* m);
void displayMatrix(Matrix* m);
void freeMatrix(Matrix* m);

#endif /* matrix_h */