#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
    float ratio; 
} Item;

int compare(const void *a, const void *b) {
    return ((Item *)b)->ratio - ((Item *)a)->ratio; 
}

int knapsack(Item items[], int n, int capacity) {
    qsort(items, n, sizeof(Item), compare); 

    int totalValue = 0;

    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        }
    }
    
    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    Item items[n];

    for (int i = 0; i < n; i++) {
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (float)items[i].value / items[i].weight; 
    }

    int maxValue = knapsack(items, n, capacity);
    printf("Maximum value in the knapsack: %d\n", maxValue);

    return 0;
}
