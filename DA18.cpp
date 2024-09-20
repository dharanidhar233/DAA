#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num, int divisor) {
    if (num < 2) return false;  
    if (divisor * divisor > num) return true;  

    if (num % divisor == 0) return false;  

    return isPrime(num, divisor + 1);  
}

void generatePrimes(int limit, int current) {
    if (current > limit) return;  

    if (isPrime(current, 2)) {
        printf("%d ", current);  
    }

    generatePrimes(limit, current + 1);  
}

int main() {
    int limit;

    printf("Enter the upper limit to generate prime numbers: ");
    scanf("%d", &limit);

    printf("Prime numbers up to %d: ", limit);
    generatePrimes(limit, 2);  
    printf("\n");

    return 0;
}
