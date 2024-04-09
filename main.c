#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "matrix.c"

/*
    Main driver function for testing.
*/
int main()
{
    srand(time(NULL));
    
    Matrix* a = createRandomMatrix(4, 4);
    Matrix* b = createRandomMatrix(4, 4);
    Matrix* c = createRandomMatrix(3, 5);
    Matrix* d = createRandomMatrix(5, 3);

    printf("Matrix A:\n");
    displayMatrix(a);
    printf("\n");

    printf("Matrix B:\n");
    displayMatrix(b);
    printf("\n");

    Matrix* sum = addMatrices(a, b);
    printf("Result of A + B:\n");
    displayMatrix(sum);
    printf("\n");

    Matrix* diff = subMatrices(a, b);
    printf("Result of A - B:\n");
    displayMatrix(diff);
    printf("\n");

    printf("Matrix C:\n");
    displayMatrix(c);
    printf("\n");

    printf("Matrix D:\n");
    displayMatrix(d);
    printf("\n");

    Matrix* product = multiplyMatrices(c, d);
    printf("Result of C x D:\n");
    displayMatrix(product);
    printf("\n");

    return 0;
}