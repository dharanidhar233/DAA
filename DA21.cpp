#include <stdio.h>

int sum_of_digits(int number) {
    int sum = 0;

    if (number < 0) {
        number = -number;
    }

    while (number > 0) {
        sum += number % 10; 
        number /= 10;       
    }

    return sum;
}

int main() {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    int result = sum_of_digits(number);
    printf("The sum of the digits in %d is: %d\n", number, result);

    return 0;
}
