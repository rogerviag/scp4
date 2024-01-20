//
// Created by Roger Villarroya on 20/1/24.
//

#ifndef CONCURRENT_STRASSENS_MULTMAT_H
#define CONCURRENT_STRASSENS_MULTMAT_H

void concurrent_strassen_multiply(float **matrixA, float **matrixB, float **resultMatrix, int size, int numThreads);
float** strassensMultRec(float **a, float **b, int size); // Declaración de la función

#endif /* CONCURRENT_STRASSENS_MULTMAT_H */
