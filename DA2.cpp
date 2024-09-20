#include <stdio.h>
#include <math.h>

int countDigits(int num) {
    if (num == 0) {
        return 0;
    }
    return 1 + countDigits(num / 10);
}

int isArmstrong(int num, int power) {
    if (num == 0) {
        return 0;
    }
    int digit = num % 10;
    return (int)pow(digit, power) + isArmstrong(num / 10, power);
}

int main() {
    int number, digits, sum;

    printf("Enter a number: ");
    scanf("%d", &number);

    digits = countDigits(number);

    sum = isArmstrong(number, digits);

    if (sum == number) {
        printf("%d is an Armstrong number.\n", number);
    } else {
        printf("%d is not an Armstrong number.\n", number);
    }

    return 0;
}

