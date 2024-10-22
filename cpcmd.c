#include <stdio.h>

int main() {
    int a[10], l = 0, n = 0, i = 0;

    // Get the length of the block
    printf("Enter length: ");
    scanf("%d", &l);

    // Get the starting block number
    printf("Enter starting block: ");
    scanf("%d", &n);

    // Assign values to the array and print the blocks
    for (i = 0; i < l; i++) {
        a[i] = 1;  // Assign a fixed value of 1 to each block
        printf("Block %d: %d\n", i + n, a[i]);  // Display block numbers with values
    }

    return 0;
}
