#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 10

// Structure to represent a file
typedef struct {
    int id;          // File ID
    int size;       // Size of the file
    int startBlock; // Starting block of the file
} File;

// Function to allocate files in a sequential manner
int allocateFiles(File files[], int numFiles, int blocks[], int numBlocks) {
    int blockIndex = 0; // Start from the first block

    for (int i = 0; i < numFiles; i++) {
        // Check if there are enough blocks available
        if (blockIndex + files[i].size > numBlocks) {
            printf("Not enough space to allocate File %d\n", files[i].id);
            return -1; // Not enough space
        }
        
        // Allocate the file
        files[i].startBlock = blockIndex;
        printf("Allocating File %d of size %d starting at block %d\n", files[i].id, files[i].size, blockIndex);
        
        // Mark blocks as allocated
        for (int j = 0; j < files[i].size; j++) {
            blocks[blockIndex + j] = 1; // 1 indicates the block is allocated
        }

        // Move to the next available block
        blockIndex += files[i].size;
    }
    
    return 0; // Successful allocation
}

int main() {
    int blocks[MAX_BLOCKS] = {0}; // Initialize blocks (0 means free)
    File files[5]; // Array to hold files
    int numFiles;

    // Input the number of files and their sizes
    printf("Enter the number of files to allocate (max 5): ");
    scanf("%d", &numFiles);
    
    if (numFiles > 5) {
        printf("Maximum number of files is 5.\n");
        return 1;
    }

    for (int i = 0; i < numFiles; i++) {
        files[i].id = i + 1; // File ID
        printf("Enter the size of File %d: ", files[i].id);
        scanf("%d", &files[i].size);
    }

    // Allocate files
    if (allocateFiles(files, numFiles, blocks, MAX_BLOCKS) == 0) {
        printf("\nFinal allocation of blocks:\n");
        for (int i = 0; i < MAX_BLOCKS; i++) {
            printf("Block %d: %s\n", i, blocks[i] ? "Allocated" : "Free");
        }
    }

    return 0;
}

