#include <stdio.h>

void print_subset(int subset[], int subset_size) {
    printf("{ ");
    for (int i = 0; i < subset_size; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

void find_subsets(int arr[], int n, int target, int subset[], int subset_size, int current_sum, int index) {
    if (current_sum == target) {
        print_subset(subset, subset_size);
        return;
    }

    if (current_sum > target || index >= n) {
        return;
    }

    subset[subset_size] = arr[index];
    find_subsets(arr, n, target, subset, subset_size + 1, current_sum + arr[index], index + 1);

    find_subsets(arr, n, target, subset, subset_size, current_sum, index + 1);
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2}; 
    int target = 9; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int subset[n]; 

    printf("Subsets with sum %d:\n", target);
    find_subsets(arr, n, target, subset, 0, 0, 0);

    return 0;
}
