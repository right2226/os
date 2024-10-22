#include <stdio.h>

#define MAX 25

int main() {
    int b[MAX], f[MAX], bf[MAX], ff[MAX];
    int nb, nf, i, j;

    // Initialize block allocation flags
    for (i = 0; i < MAX; i++) {
        bf[i] = 0;  // Block is free
        ff[i] = 0;  // File is not allocated
    }

    printf("Enter the number of blocks: ");
    scanf("%d", &nb);

    printf("Enter the number of files: ");
    scanf("%d", &nf);

    printf("\nEnter the size of the blocks:\n");
    for (i = 0; i < nb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &b[i]);
    }

    printf("\nEnter the size of the files:\n");
    for (i = 0; i < nf; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &f[i]);
    }

    // First Fit Algorithm
    for (i = 0; i < nf; i++) {
        for (j = 0; j < nb; j++) {
            if (bf[j] == 0 && b[j] >= f[i]) { // Block is free and can accommodate the file
                ff[i] = j; // Allocate file to block
                bf[j] = 1; // Mark block as allocated
                break; // Stop searching for the next file
            }
        }
    }

    // Display results
    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment");
    for (i = 0; i < nf; i++) {
        if (ff[i] != 0) { // If file is allocated
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",
                   i + 1, f[i], ff[i] + 1, b[ff[i]], b[ff[i]] - f[i]);
        } else {
            printf("\n%d\t\t%d\t\tNot Allocated", i + 1, f[i]);
        }
    }

    return 0;
}

