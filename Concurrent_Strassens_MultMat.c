//
// Created by Roger Villarroya on 17/1/24.
//
#include "Concurrent_Strassens_MultMat.h"
#include "Matrix.h"
#include <pthread.h>
#include <stdlib.h>

typedef struct {
    float **matrixA;
    float **matrixB;
    float **resultMatrix;
    int size;
} thread_data;

// Funcions auxiliares
float** addMatrix(float** a, float** b, int size);
float** subMatrix(float** a, float** b, int size);
float** standardMultiplication(float** a, float** b, int size);
float** divide(float **matrix, int size, int row, int col);
void compose(float** c, float** result, int row, int col, int size);
float** createZeroMatrix(int size);

void *strassen_mult_thread(void *arg) {
    thread_data *data = (thread_data *)arg;
    data->resultMatrix = strassensMultRec(data->matrixA, data->matrixB, data->size);
    free(data);
    pthread_exit(NULL);
}

void concurrent_strassen_multiply(float **matrixA, float **matrixB, float **resultMatrix, int size, int numThreads) {
    pthread_t threads[numThreads];
    for (int i = 0; i < numThreads; i++) {
        thread_data *data = malloc(sizeof(thread_data));
        data->matrixA = matrixA;
        data->matrixB = matrixB;
        data->resultMatrix = resultMatrix;
        data->size = size;
        pthread_create(&threads[i], NULL, strassen_mult_thread, (void *)data);
    }
    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }
}

float** strassensMultRec(float **a, float **b, int size) {
    if (size <= 2) {
        // En tamanys petits usar multiplicació standar
        return standardMultiplication(a, b, size);
    } else {
        int newSize = size / 2;


        float **a11 = divide(a, size, 0, 0);
        float **a12 = divide(a, size, 0, newSize);
        float **a21 = divide(a, size, newSize, 0);
        float **a22 = divide(a, size, newSize, newSize);
        float **b11 = divide(b, size, 0, 0);
        float **b12 = divide(b, size, 0, newSize);
        float **b21 = divide(b, size, newSize, 0);
        float **b22 = divide(b, size, newSize, newSize);

        float **m1 = strassensMultRec(addMatrix(a11, a22, newSize), addMatrix(b11, b22, newSize), newSize);
        float **m2 = strassensMultRec(addMatrix(a21, a22, newSize), b11, newSize);
        float **m3 = strassensMultRec(a11, subMatrix(b12, b22, newSize), newSize);
        float **m4 = strassensMultRec(a22, subMatrix(b21, b11, newSize), newSize);
        float **m5 = strassensMultRec(addMatrix(a11, a12, newSize), b22, newSize);
        float **m6 = strassensMultRec(subMatrix(a21, a11, newSize), addMatrix(b11, b12, newSize), newSize);
        float **m7 = strassensMultRec(subMatrix(a12, a22, newSize), addMatrix(b21, b22, newSize), newSize);

        float **c11 = addMatrix(subMatrix(addMatrix(m1, m4, newSize), m5, newSize), m7, newSize);
        float **c12 = addMatrix(m3, m5, newSize);
        float **c21 = addMatrix(m2, m4, newSize);
        float **c22 = addMatrix(subMatrix(addMatrix(m1, m3, newSize), m2, newSize), m6, newSize);

        float **result = createZeroMatrix(size);
        compose(c11, result, 0, 0, newSize);
        compose(c12, result, 0, newSize, newSize);
        compose(c21, result, newSize, 0, newSize);
        compose(c22, result, newSize, newSize, newSize);

        return result;
    }
}


float** addMatrix(float** matrixA, float** matrixB, int n) {
    float** result = createZeroMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    return result;
}


float** subMatrix(float** matrixA, float** matrixB, int n) {
    float** result = createZeroMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    return result;
}


float** standardMultiplication(float** a, float** b, int size) {
    float** result = createZeroMatrix(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}


float** divide(float** matrix, int n, int row, int col) {
    int newSize = n / 2;
    float** subMatrix = createZeroMatrix(newSize);
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            subMatrix[i][j] = matrix[row + i][col + j];
        }
    }
    return subMatrix;
}


void compose(float** subMatrix, float** resultMatrix, int row, int col, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            resultMatrix[row + i][col + j] = subMatrix[i][j];
        }
    }
}

