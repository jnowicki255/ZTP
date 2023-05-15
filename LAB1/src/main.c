#include <stdio.h>
#include "m_nums.h"
#include "m_disp.h"

int main (int argc, char *argv[]) 
{ 
    int const maxMatrixSize = 100;
    int const tabSize = 10;

    // Wygenerowanie macierzy
    int tab1[tabSize][maxMatrixSize];
    genMatrix(tab1, tabSize, 0, 50);

    int tab2[tabSize][maxMatrixSize];
    genMatrix(tab2, tabSize, 0, 100);

    printf("====== PIERWSZA MACEIRZ ======\n");
    printMatrix(tab1, tabSize);

    printf("====== DRUGA MACIERZ ======\n");
    printMatrix(tab2, tabSize);

    // Odwrócenie pierwszej macierzy
    printf("====== MNOŻENIE MACIERZY ======\n");
    int mul[tabSize][maxMatrixSize];
    multiplyMatrix(tab1, tab2, mul, tabSize);
    printMatrix(mul, tabSize);

    // Sumowanie dwóch macierzy
    printf("====== SUMA DWÓCH MACIERZY ======\n");
    int sum[tabSize][maxMatrixSize];
    sumMatrix(tab1, tab2, sum, tabSize);
    printMatrix(sum, tabSize);

    return 0;
}