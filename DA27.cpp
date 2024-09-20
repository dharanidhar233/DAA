#include <stdio.h>

int knapsack(int weig+
hts[], int values[], int capacity, int n) {
    int i, w;
    int K[n + 1][capacity + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0; 
            } else if (weights[i - 1] <= w) {
                K[i][w] = (values[i - 1] + K[i - 1][w - weights[i - 1]] > K[i - 1][w]) 
                          ? (values[i - 1] + K[i - 1][w - weights[i - 1]]) 
                          : K[i - 1][w];
            } else {
                K[i][w] = K[i - 1][w]; 
            }
        }
    }

    return K[n][capacity]; 
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    printf("Enter the capacity of the container: ");
    scanf("%d", &capacity);

    int max_value = knapsack(weights, values, capacity, n);
    printf("The maximum value that can be obtained: %d\n", max_value);

    return 0;
}
