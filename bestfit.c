#include <stdio.h>

#define MAX 25

int main() {
    int b[MAX], f[MAX], bf[MAX], ff[MAX];
    int nb, nf, i, j, temp, lowest, lowestIndex;
    
    // Initialize block allocation flags
    for (i = 0; i < MAX; i++) {
        bf[i] = 0;  // Block is free
        ff[i] = 0;  // File is not allocated
    }

    printf("\nEnter the number of blocks: ");
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

    // Best Fit Algorithm
    for (i = 0; i < nf; i++) {
        lowest = 10000; // Arbitrarily large number
        lowestIndex = -1; // No block found yet
        
        for (j = 0; j < nb; j++) {
            if (bf[j] == 0) { // If block is free
                temp = b[j] - f[i];
                if (temp >= 0 && temp < lowest) {
                    lowest = temp; // Update the lowest fragmentation
                    lowestIndex = j; // Track the block index
                }
            }
        }
        
        // If a suitable block was found
        if (lowestIndex != -1) {
            ff[i] = lowestIndex; // Allocate file to block
            bf[lowestIndex] = 1; // Mark block as allocated
        }
    }

    // Display results
    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment");
    for (i = 0; i < nf; i++) {
        if (ff[i] != -1) { // If file is allocated
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",
                   i + 1, f[i], ff[i] + 1, b[ff[i]], b[ff[i]] - f[i]);
        }
    }

    return 0;
}

