#include <stdio.h>

void find_factors(int n, int i) {
    if (i > n) {
        return;
    }

    if (n % i == 0) {
        printf("%d ", i); 
    }

    find_factors(n, i + 1);
}

int main() {
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer greater than 0.\n");
        return 1;
    }

    printf("Factors of %d are: ", n);
    find_factors(n, 1); 
    printf("\n");

    return 0;
}
