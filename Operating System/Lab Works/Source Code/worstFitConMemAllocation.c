#include <stdio.h>

#define MAX 100

// Function to allocate memory using Worst-Fit algorithm
void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    int i, j;

    // Initialize all allocations as -1 (indicating no allocation)
    for (i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Traverse each process
    for (i = 0; i < n; i++) {
        // Find the worst fit block for this process
        int worstIdx = -1;
        for (j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx]) {
                    worstIdx = j;
                }
            }
        }

        // If a suitable block is found
        if (worstIdx != -1) {
            // Allocate the block to the process
            allocation[i] = worstIdx;
            // Reduce the size of the available block
            blockSize[worstIdx] -= processSize[i];
        }
    }

    // Print the allocation results
    printf("\nProcess No.\tProcess Size\tBlock No.\tBlock Size\n");
    for (i = 0; i < n; i++) {
        if (allocation[i] != -1) {
            printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, processSize[i], allocation[i] + 1, blockSize[allocation[i]]);
        } else {
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, processSize[i]);
        }
    }
}

int main() {
    int m, n;

    // Input number of memory blocks
    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    int blockSize[m];
    printf("Enter the size of each memory block:\n");
    for (int i = 0; i < m; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int processSize[n];
    printf("Enter the size of each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    // Perform Worst-Fit memory allocation
    worstFit(blockSize, m, processSize, n);

    return 0;
}
