#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 500 

void multiply_matrices(int a[N][N], int b[N][N], int result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0; 
            for (int k = 0; k < N; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int a[N][N], b[N][N], result[N][N];
    
    
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = rand() % 10; 
            b[i][j] = rand() % 10; 
        }
    }

    clock_t start = clock();
    multiply_matrices(a, b, result);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken to multiply two %dx%d matrices: %f seconds\n", N, N, time_taken);
    
    return 0;
}

