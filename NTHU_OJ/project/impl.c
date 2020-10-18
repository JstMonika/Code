#include "mmm.h"

// compute C = A*B
void matrixmul(float A[][SIZE], float B[][SIZE], float C[][SIZE]){
    int i, j, k;
    // i: row index for C
    // j: col index for C
    // k: iteration index


    for (i=0; i<SIZE; i++){
        for (j=0; j<SIZE; j++){
            C[i][j] = 0;
            for (k=0; k<SIZE; k++){
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

// compute C = A*B using blocking
void matrixmul_block(float A[][SIZE], float B[][SIZE], float C[][SIZE], int bSize){
    int i, j, k;

    int bi, bj, bk;

    for (bi=0; bi<SIZE; bi+=bSize){
        for (bj=0; bj<SIZE; bj+=bSize){
            for (i=bi; i<bi+bSize; i++){
                for (j=bj; j<bj+bSize; j++){
                    C[i][j] = 0.0;
                }
            }
            for (bk=0; bk<SIZE; bk+=bSize){
                for (i=bi; i<bi+bSize; i++){
                    for (j=bj; j<bj+bSize; j++){
                        for (k=bk; k<bk+bSize; k++){
                            C[i][j] += A[i][k]*B[k][j];
                        }
                    }
                }
            }
        }
    }
}


// compute C = A*B using blocking
void matrixmul_block2(float A[][SIZE], float B[][SIZE], float C[][SIZE], int p, int q){
    // your implementation here
    int i = 0, j = 0, k = 0;
    
    int bi = 0, bj = 0, bk = 0;
    
    for (int bi = 0; bi < SIZE; bi += p)
        for (int bk = 0; bk < SIZE; bk += q)
        {
            for (int i = bi; i < bi + p; i++)
                for (int k = bk; k < bk + q; k++)
                    C[i][k] = 0.0;
            
            for (int bj = 0; bj < SIZE; bj += q)
                for (int i = bi; i < bi + p; i++)
                    for (int k = bk; k < bk + q; k++)
                        for (int j = bj; j < bj + q; j++)
                            C[i][k] += A[i][j] * B[j][k];
        }
}


// verify the correctness of the result
double verify(float X[][SIZE], float Y[][SIZE]){
    float diff = 0.0;
    double accum = 0.0;
    int i, j;

    for (i=0; i< SIZE; i++){
        for (j=0; j<SIZE; j++){
            diff = X[i][j] - Y[i][j];
            accum += diff<0?-diff:diff;
        }
    }
    return accum;
}
