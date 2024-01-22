//
// Created by Roger Villarroya on 17/1/24.
//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Concurrent_Standard_MultMat.h"
#include "Concurrent_Strassens_MultMat.h"
#include "Matrix.h"


// Definir las rutas base y carpetas para los archivos de entrada y salida
char *input_path = ".";
char *input_folder = "Input";
char *results_path = ".";
char *results_folder = "Results";

// Asumiendo que las siguientes funciones están definidas
float** readMatrixFromFile(const char* filename, int* rows, int* cols);
void writeMatrixToFile(const char* filename, float** matrix, int rows, int cols);
void freeMatrix(float** matrix, int rows);
void openMatrix(char *inputFile, float *** matrix,int *n);

// Prototipo de la función de prueba
void performTest(int size, int numThreads);

int main(int argc, char **argv) {
    int numThreads = argc > 1 ? atoi(argv[1]) : 4; // Número predeterminado de hilos

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
    int rows, cols;
    struct timespec start, finish;
    double elapsed;

    // Generar nombres de archivo basados en tamaño y rutas/carpetas
    sprintf(matrixAFile, "%s/%s/MatrixA_%dx%d.txt", input_path, input_folder, size, size);
    sprintf(matrixBFile, "%s/%s/MatrixB_%dx%d.txt", input_path, input_folder, size, size);
    sprintf(resultFile, "%s/%s/MatrixResult_%dx%d.txt", results_path, results_folder, size, size);

    matrixA = readMatrixFromFile(matrixAFile, &rows, &cols);
    if (matrixA == NULL) {
        perror("Error al leer matrixA");
        exit(EXIT_FAILURE);
    }

    matrixB = readMatrixFromFile(matrixBFile, &rows, &cols);
    if (matrixB == NULL) {
        perror("Error al leer matrixB");
        freeMatrix(matrixA, size);
        exit(EXIT_FAILURE);
    }

    resultMatrix = createZeroMatrix(size);

    clock_gettime(CLOCK_MONOTONIC, &start);
    // Reemplaza con la función de multiplicación concurrente adecuada
    concurrent_strassen_multiply(matrixA, matrixB, resultMatrix,size, numThreads);
    clock_gettime(CLOCK_MONOTONIC, &finish);

    elapsed = (finish.tv_sec - start.tv_sec) + (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("Tiempo de multiplicación para matriz %dx%d con %d hilos: %f segundos\n", size, size, numThreads, elapsed);

    writeMatrixToFile(resultFile, resultMatrix, size, size);

    freeMatrix(matrixA, size);
    freeMatrix(matrixB, size);
    freeMatrix(resultMatrix, size);
}
