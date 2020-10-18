#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mmm.h"

float A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE], D[SIZE][SIZE];

int main(){
    int i, j;
    clock_t t1, t2, t3;
    double d1, d2;

    for (i=0; i<SIZE; i++) {
        for (j=0; j<SIZE; j++){
            A[i][j] = rand()%10;
            B[i][j] = rand()%10;
        }
    }
    double _list[7][7];
    
    for (int i = 0; i < 7; i++)
        for (int k = 0; k < 7; k++)
        {
            t1 = clock();
            matrixmul_block2(A, B, C, (1<<(i+2)), (1<<(k+2)));
            t2 = clock();
            
            _list[i][k] = 1.0 * (t2-t1) / CLOCKS_PER_SEC;
        }
    
    for (int i = 0; i < 7; i++)
        for (int k = 0; k < 7; k++)
            printf("%f%c", _list[i][k], "\t\n"[k == 6]);

    return 0;
}
