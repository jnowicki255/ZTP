#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "m_nums.h"

#define nullptr ((void*)0)

void genMatrix(int matrix[][100], int matrixSize, int min, int max)
{
    srand(time(nullptr));

    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            int random_num = min + (rand() % (max - min + 1));
            matrix[i][j] = (int)random_num;
        }
    }
}

void multiplyMatrix(int matrix1[][100], int matrix2[][100], int result[][100], int matrixSize) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            result[i][j] = 0;
            for (int k = 0; k < matrixSize; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void sumMatrix(int matrix1[][100], int matrix2[][100], int result[][100], int matrixSize)
{
    int i, j;

    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < matrixSize; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}