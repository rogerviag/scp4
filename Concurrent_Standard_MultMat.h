//
// Created by Roger Villarroya on 17/1/24.
//

#ifndef CONCURRENT_STANDARD_MULTMAT_H
#define CONCURRENT_STANDARD_MULTMAT_H

void *standard_mult_thread(void *arg);

void concurrent_standard_multiply(int **matrixA, int **matrixB, int **resultMatrix, int rowsA, int colsA, int colsB, int numThreads);

#endif /* CONCURRENT_STANDARD_MULTMAT_H */
