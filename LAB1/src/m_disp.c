#include <stdio.h>
#include "m_disp.h"

void printMatrix(int matrix[][100], int matrixSize) 
{
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            printf("%i ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}