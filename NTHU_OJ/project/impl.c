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
    // i: row index for block
    // j: col index for block
    // k: iteration index

    int bi, bj, bk;
    // bi: block row index for C
    // bj: block col index for C
    // bk: block index

    for (bi=0; bi<SIZE; bi+=bSize){
        for (bj=0; bj<SIZE; bj+=bSize){
            // clean C's value
            for (i=bi; i<bi+bSize; i++){
                for (j=bj; j<bj+bSize; j++){
                    C[i][j] = 0.0;
                }
            }
            // compute the block submatrix C[bi][bj]
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
