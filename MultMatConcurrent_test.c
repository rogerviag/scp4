//
// Created by Roger Villarroya on 17/1/24.
//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Concurrent_Standard_MultMat.h"
#include "Concurrent_Strassens_MultMat.h"
#include "Matrix.h"
// rutes base i directoris definits
char *input_path = ".";
char *input_folder = "Input";
char *results_path = ".";
char *results_folder = "Results";

void writeMatrixToFile(const char* filename, float** matrix, int rows, int cols);
void openMatrix(char *inputFile, float *** matrix,int *n);
void concurrent_strassen_multiply(float **matrixA, float **matrixB, float **resultMatrix, int n, int numThreads);

void performTest(int size, int numThreads);

int main(int argc, char **argv) {
    int numThreads = argc > 1 ? atoi(argv[1]) : 4; // nombre threads

    performTest(4, numThreads);
    performTest(16, numThreads);
    performTest(64, numThreads);
    performTest(128, numThreads);
    performTest(512, numThreads);
    performTest(1024, numThreads);
    performTest(2048, numThreads);

    return 0;
}

void performTest(int size, int numThreads) {
    char matrixAFile[256], matrixBFile[256], resultFile[256];
    float **matrixA, **matrixB, **resultMatrix;
    int nA, nB;
    struct timespec start, finish;
    double elapsed;

    // Generar noms d'arxius basats en tamany/rutes directoris
    sprintf(matrixAFile, "%s/%s/MatrixA_%dx%d.txt", input_path, input_folder, size, size);
    sprintf(matrixBFile, "%s/%s/MatrixB_%dx%d.txt", input_path, input_folder, size, size);
    sprintf(resultFile, "%s/%s/MatrixResult_%dx%d.txt", results_path, results_folder, size, size);

    openMatrix(matrixAFile, &matrixA, &nA);
    if (matrixA == NULL) {
        perror("Error lectura matrixA");
        exit(EXIT_FAILURE);
    }

    openMatrix(matrixBFile, &matrixB, &nB);
    if (matrixB == NULL) {
        perror("Error lectura matrixB");
        exit(EXIT_FAILURE);
    }

    if (nA != size || nB != size) {
        printf("Error: Les dimencions de les matrius no coincideixen\n");
        exit(EXIT_FAILURE);
    }

    resultMatrix = createZeroMatrix(size);

    clock_gettime(CLOCK_MONOTONIC, &start);
    concurrent_strassen_multiply(matrixA, matrixB, resultMatrix, size, numThreads);
    clock_gettime(CLOCK_MONOTONIC, &finish);

    elapsed = (finish.tv_sec - start.tv_sec) + (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("Tiempo de multiplicación para matriz %dx%d con %d hilos: %f segundos\n", size, size, numThreads, elapsed);

    writeMatrixToFile(resultFile, resultMatrix, size, size);
}
