//
// Created by Roger Villarroya on 20/1/24.
//
#include "Concurrent_Standard_MultMat.h"
#include <pthread.h>
#include <stdlib.h>

typedef struct {
    int **matrixA;
    int **matrixB;
    int **resultMatrix;
    int row;
    int colsA;
    int colsB;
} thread_data;

void *standard_mult_thread(void *arg) {
    thread_data *data = (thread_data *)arg;

    for (int i = 0; i < data->colsB; i++) {
        data->resultMatrix[data->row][i] = 0;
        for (int j = 0; j < data->colsA; j++) {
            data->resultMatrix[data->row][i] += data->matrixA[data->row][j] * data->matrixB[j][i];
        }
    }
    free(data);
    pthread_exit(NULL);
}

void concurrent_standard_multiply(int **matrixA, int **matrixB, int **resultMatrix, int rowsA, int colsA, int colsB, int numThreads) {
    pthread_t threads[numThreads];
    int step = rowsA / numThreads;

    for (int i = 0; i < numThreads; i++) {
        for (int j = 0; j < step; j++) {
            if (i*step + j < rowsA) {
                thread_data *data = malloc(sizeof(thread_data));
                data->matrixA = matrixA;
                data->matrixB = matrixB;
                data->resultMatrix = resultMatrix;
                data->row = i*step + j;
                data->colsA = colsA;
                data->colsB = colsB;

                pthread_create(&threads[i], NULL, standard_mult_thread, (void *)data);
            }
        }
    }

    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }
}
