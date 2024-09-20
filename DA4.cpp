#include <stdio.h>

int main() {
    int n, i;
    int largest;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int array[n]; 

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    largest = array[0];

    for (i = 1; i < n; i++) {
        if (array[i] > largest) {
            largest = array[i];
        }
    }

    printf("The largest element in the array is: %d\n", largest);

    return 0;
}

