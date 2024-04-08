#include <stdio.h>
#include "matrix.c"

/*
    Main driver function for testing.
*/
int main()
{
    printf("Initializing empty 5x5 matrix m1...\n");
    Matrix m1 = createEmptyMatrix(5, 5);
    displayMatrix(&m1);
    printf("\n");

    printf("Randomizing matrix m1...\n");
    randomizeMatrix(&m1);
    displayMatrix(&m1);

    return 0;
}