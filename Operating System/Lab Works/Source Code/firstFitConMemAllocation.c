#include <stdio.h>

void firstFit(int blockSize[], int m, int processSize[], int n) {
    // Stores block id of the block allocated to a process
    int allocation[n];
    
    // Initially no block is assigned to any process
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }
    
    // Pick each process and find the first block that can fit it
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If block j can accommodate process i
            if (blockSize[j] >= processSize[i]) {
                // Allocate block j to process i
                allocation[i] = j;
                
                // Reduce available memory in this block
                blockSize[j] -= processSize[i];
                
                break; // Move to the next process
            }
        }
    }
    
    // Display allocation details
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf(" %d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);  // Display block number (1-based index)
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int m, n;

    // Input number of blocks
    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    int blockSize[m];

    // Input size of each block
    printf("Enter the size of each memory block:\n");
    for (int i = 0; i < m; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    // Input number of processes
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    int processSize[n];

    // Input size of each process
    printf("Enter the size of each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    // Call first fit allocation function
    firstFit(blockSize, m, processSize, n);

    return 0;
}
