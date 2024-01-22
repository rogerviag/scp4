//
// Created by Roger Villarroya on 17/1/24.
//
#include "Concurrent_Standard_MultMat.h"
#include "Concurrent_Strassens_MultMat.h"
#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
    if (argc < 5) {
        printf("Uso: %s <MatrixA_File> <MatrixB_File> <ResultMatrix_File> <#Threads> [<method>]\n", argv[0]);
        return 1;
    }

    int rowsA, colsA, rowsB, colsB, numThreads;
    float **matrixA, **matrixB, **resultMatrix;
    struct timespec start, finish;
    double elapsed;

    openMatrix(argv[1], &matrixA, &rowsA);
    openMatrix(argv[2], &matrixB, &rowsB);

    // Asumir matrius quadrades com els exemples
    colsA = rowsA;
    colsB = rowsB;

    numThreads = atoi(argv[4]);

    if (colsA != rowsB) {
        printf("Error: les matrix no es poden multiplicar degut a les dimensions.\n");
        return 1;
    }

    resultMatrix = createZeroMatrix(rowsA);
    int method = (argc > 5) ? atoi(argv[5]) : 0;

    clock_gettime(CLOCK_MONOTONIC, &start);

    if (method == 0) {
        concurrent_standard_multiply(matrixA, matrixB, resultMatrix, rowsA, colsA, colsB, numThreads);
    } else {
        concurrent_strassen_multiply(matrixA, matrixB, resultMatrix, rowsA, numThreads);
    }

    clock_gettime(CLOCK_MONOTONIC, &finish);
    elapsed = (finish.tv_sec - start.tv_sec) + (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

    printf("Tiempo de ejecución: %f segundos\n", elapsed);
    writeMatrixToFile(argv[3], resultMatrix, rowsA, colsB);


    return 0;
}
