#include <stdio.h>
#include <stdlib.h>
#include "sparse.h"
// #include "struct.c"

int main()
{
    matrixNode s1, t, s2, mult;
    int row, column;
    printf("\nMatrix 1 Row,Column:");
    scanf("%d%d", &row, &column);
    init(&s1, row, column);
    printf("\nMatrix 2 Row,Column:");
    scanf("%d%d", &row, &column);
    init(&s2, row, column);


    printf("\n\nInformation to be stored in linked list Sparse 1 : \n");
    makeSparse(&s1);
    printf("\n\nInformation stored in linked list Sparse 1 : \n");
    showSparse(&s1);

    printf("\n\nInformation to be stored in linked list Sparse 2 : \n");
    makeSparse(&s2);
    printf("\n\nInformation stored in linked list Sparse 2 : \n");
    showSparse(&s2);

    if (multi(&s1, &s2, &mult))
    {
        printf("\n------------------------\n");
        printf("\n\nMultiplication :\n");
        showSparse(&mult);
    }

    printf("\n------------------------\n");
    if (islowert(&s1))
        printf("\n1 is a lower triangle matrix");
    else
        printf("\nNOT LOWER");

    printf("\n------------------------\n");
    transpose(&t, s1);
    printf("\n\nTranspose of matrix 1: \n");
    showSparse(&t);
    printf("\n------------------------\n");
    dest(&s1);
    dest(&t);
    dest(&s2);
    dest(&mult);
}