#include <stdio.h>

void reverseString(char *str, int index) {#include <stdio.h>

void reverseString(char *str, int index) {
    // Base case: if the index is at the end of the string
    if (str[index] == '\0') {
        return;
    }

    // Recursive call to the next character
    reverseString(str, index + 1);

    // Print the current character after the recursive call
    printf("%c", str[index]);
}

int main() {
    char str[100];

    // Input the string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Print the reverse of the string
    printf("Reversed string: ");
    reverseString(str, 0);
    printf("\n");

    return 0;
}
    if (str[index] == '\0') {
        return;
    }

    reverseString(str, index + 1);

    printf("%c", str[index]);
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Reversed string: ");
    reverseString(str, 0);
    printf("\n");

    return 0;
}
