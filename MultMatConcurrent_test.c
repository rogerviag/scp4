//
// Created by Roger Villarroya on 17/1/24.
//


#include "Concurrent_Standard_MultMat.h"
#include "Concurrent_Strassens_MultMat.h"
#include "Matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Asumiendo que las siguientes funciones están definidas
float** readMatrixFromFile(const char* filename, int* rows, int* cols);
void writeMatrixToFile(const char* filename, float** matrix, int rows, int cols);
void freeMatrix(float** matrix, int rows);

// Prototipos de funciones
void performTest(int size, int numThreads, const char* testFolderPath);

int main(int argc, char **argv) {
    const char* testFolderPath = argc > 1 ? argv[1] : ".";
    int numThreads = argc > 2 ? atoi(argv[2]) : 4; // Número predeterminado de hilos

    performTest(4, numThreads, testFolderPath);
    performTest(16, numThreads, testFolderPath);
    performTest(64, numThreads, testFolderPath);
    performTest(128, numThreads, testFolderPath);
    performTest(512, numThreads, testFolderPath);
    performTest(1024, numThreads, testFolderPath);
    performTest(2048, numThreads, testFolderPath);

    return 0;
}

void performTest(int size, int numThreads, const char* testFolderPath) {
    char matrixAFile[256], matrixBFile[256], resultFile[256];
    float **matrixA, **matrixB, **resultMatrix;
    int rows, cols;
    struct timespec start, finish;
    double elapsed;

    // Generar nombres de archivo basados en tamaño y testFolderPath
    sprintf(matrixAFile, "%s/MatrixA_%dx%d.txt", testFolderPath, size, size);
    sprintf(matrixBFile, "%s/MatrixB_%dx%d.txt", testFolderPath, size, size);
    sprintf(resultFile, "%s/MatrixResult_%dx%d.txt", testFolderPath, size, size);

    matrixA = readMatrixFromFile(matrixAFile, &rows, &cols);
    matrixB = readMatrixFromFile(matrixBFile, &rows, &cols);
    resultMatrix = createZeroMatrix(size);

    // Medir el tiempo de la multiplicación concurrente
    clock_gettime(CLOCK_MONOTONIC, &start);
    concurrent_strassen_multiply(matrixA, matrixB, resultMatrix, size, numThreads); // o concurrent_standard_multiply
    clock_gettime(CLOCK_MONOTONIC, &finish);

    elapsed = (finish.tv_sec - start.tv_sec) + (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("Tiempo de multiplicación para matriz %dx%d con %d hilos: %f segundos\n", size, size, numThreads, elapsed);

    writeMatrixToFile(resultFile, resultMatrix, size, size);

    freeMatrix(matrixA, size);
    freeMatrix(matrixB, size);
    freeMatrix(resultMatrix, size);
}



