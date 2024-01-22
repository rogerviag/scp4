//
// Created by Roger Villarroya on 17/1/24.
//
#include "Concurrent_Standard_MultMat.h"
#include "Concurrent_Strassens_MultMat.h"
#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Asumiendo que las siguientes funciones están definidas en Matrix.h
float** readMatrixFromFile(const char* filename, int* rows, int* cols);
void writeMatrixToFile(const char* filename, float** matrix, int rows, int cols);
void freeMatrix(float** matrix, int rows);

int main(int argc, char* argv[]) {
    if (argc < 5) {
        printf("Uso: %s <ArchivoMatrizA> <ArchivoMatrizB> <ArchivoResultado> <NumHilos> [<metodo>]\n", argv[0]);
        return 1;
    }

    int rowsA, colsA, rowsB, colsB, numThreads;
    float **matrixA, **matrixB, **resultMatrix;
    struct timespec start, finish;
    double elapsed;

    matrixA = readMatrixFromFile(argv[1], &rowsA, &colsA);
    matrixB = readMatrixFromFile(argv[2], &rowsB, &colsB);
    numThreads = atoi(argv[4]);

    if (colsA != rowsB) {
        printf("Error: Las matrices no se pueden multiplicar debido a sus dimensiones.\n");
        freeMatrix(matrixA, rowsA);
        freeMatrix(matrixB, rowsB);
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

    freeMatrix(matrixA, rowsA);
    freeMatrix(matrixB, rowsB);
    freeMatrix(resultMatrix, rowsA);

    return 0;
}
