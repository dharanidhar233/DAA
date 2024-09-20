#include <stdio.h>

int isPrime(int num, int divisor) {
    if (num < 2) {
        return 0;
    }
    if (divisor == 1) {
        return 1;
    }
    if (num % divisor == 0) {
        return 0;
    }
    return isPrime(num, divisor - 1);
}

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (isPrime(number, number / 2)) {
        printf("%d is a prime number.\n", number);
    } else {
        printf("%d is not a prime number.\n", number);
    }

    return 0;
}

