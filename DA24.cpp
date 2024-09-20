#include <stdio.h>

#define MAX_SIZE 100

void insertNumber(int list[], int *size, int number, int position) {
    if (position < 0 || position > *size) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = *size; i > position; i--) {
        list[i] = list[i - 1];
    }

    list[position] = number;
    (*size)++; 
}

void displayList(int list[], int size) {
    printf("Current List: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main() {
    int list[MAX_SIZE];
    int size = 0; 
    int number, position;

    while (1) {
        printf("Enter a number to insert (or -1 to exit): ");
        scanf("%d", &number);
        
        if (number == -1) {
            break; 
        }

        printf("Enter the position to insert the number (0 to %d): ", size);
        scanf("%d", &position);

        insertNumber(list, &size, number, position);
        displayList(list, size);
    }

    return 0;
}
