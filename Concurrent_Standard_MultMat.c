//
// Created by Roger Villarroya on 17/1/24.
//
#include "Concurrent_Standard_MultMat.h"
#include <pthread.h>
#include <stdlib.h>

typedef struct {
    float **matrixA;
    float **matrixB;
    float **resultMatrix;
    int startRow;
    int endRow;
    int row;
    int colsA;
    int colsB;
} thread_data;

void *standard_mult_thread(void *arg) {
    thread_data *data = (thread_data *)arg;

    // Procesar un rang de files assignades al thread
    for (int row = data->startRow; row < data->endRow; row++) {
        for (int i = 0; i < data->colsB; i++) {
            data->resultMatrix[row][i] = 0;
            for (int j = 0; j < data->colsA; j++) {
                data->resultMatrix[row][i] += data->matrixA[row][j] * data->matrixB[j][i];
            }
        }
    }

    free(data);
    pthread_exit(NULL);
}


void concurrent_standard_multiply(float **matrixA, float **matrixB, float **resultMatrix, int rowsA, int colsA, int colsB, int numThreads) {
    pthread_t threads[numThreads];
    int step = rowsA / numThreads;

    for (int i = 0; i < numThreads; i++) {
        thread_data *data = malloc(sizeof(thread_data));
        data->matrixA = matrixA;
        data->matrixB = matrixB;
        data->resultMatrix = resultMatrix;
        data->startRow = i * step;
        data->endRow = (i + 1) * step;                                  //ajustar si es necessari
        data->colsA = colsA;
        data->colsB = colsB;

        pthread_create(&threads[i], NULL, standard_mult_thread, (void *)data);
    }

    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }
}

