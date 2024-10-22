#include <stdio.h>

int main() {
    int a[10], n = 0, l = 0, i = 0;

    // Prompt user for the length of the blocks
    printf("Enter length (up to 10): ");
    scanf("%d", &l);

    // Validate length input
    if (l > 10) {
        printf("Length cannot exceed 10.\n");
        return 1;
    }

    // Prompt user for the starting block
    printf("Enter starting block: ");
    scanf("%d", &n);

    // Initialize the blocks
    for (i = 0; i < l; i++) {
        a[i] = 1; // Initialize each block to 1
        printf("Block %d: %d\n", i + n, a[i]); // Display block number and value
    }

    return 0;
}

