#include <stdio.h>

void add(int a[2][2], int b[2][2], int result[2][2]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            result[i][j] = a[i][j] + b[i][j];
}

void subtract(int a[2][2], int b[2][2], int result[2][2]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            result[i][j] = a[i][j] - b[i][j];
}

void strassen(int A[2][2], int B[2][2], int C[2][2]) {
    int M1[2][2], M2[2][2], M3[2][2], M4[2][2], M5[2][2], M6[2][2], M7[2][2];
    int temp1[2][2], temp2[2][2];

    add(A, A + 1, temp1); 
    add(B, B + 1, temp2); 
    strassen(temp1, temp2, M1);

    add(A + 2, A + 3, temp1); 
    strassen(temp1, B, M2);

    subtract(B + 1, B + 3, temp2); 
    strassen(A, temp2, M3);

    subtract(B + 2, B, temp2); 
    strassen(A + 3, temp2, M4);

    add(A, A + 1, temp1); 
    strassen(temp1, B + 3, M5);

    subtract(A + 2, A, temp1); 
    add(B, B + 1, temp2); 
    strassen(temp1, temp2, M6);

    subtract(A + 1, A + 3, temp1); 
    add(B + 2, B + 3, temp2); 
    strassen(temp1, temp2, M7);

    C[0][0] = M1[0][0] + M4[0][0] - M5[0][0] + M7[0][0];
    C[0][1] = M3[0][0] + M5[0][0];
    C[1][0] = M2[0][0] + M4[0][0];
    C[1][1] = M1[0][0] - M2[0][0] + M3[0][0] + M6[0][0];
}

int main() {
    int A[2][2], B[2][2], C[2][2];

    printf("Enter elements of 2x2 Matrix A:\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of 2x2 Matrix B:\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &B[i][j]);

    strassen(A, B, C);

    printf("Resultant Matrix C (A * B):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}
