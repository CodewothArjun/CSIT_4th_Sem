#include <stdio.h>

int main() {
    int partitionSize[10], processSize[10], allocated[10], numPartitions, numProcesses;
    int internalFragmentation = 0;

    // Get number of partitions
    printf("Enter the number of memory partitions: ");
    scanf("%d", &numPartitions);

    // Get partition sizes
    printf("Enter the size of each partition:\n");
    for (int i = 0; i < numPartitions; i++) {
        printf("Partition %d size: ", i + 1);
        scanf("%d", &partitionSize[i]);
        allocated[i] = 0;  // No process is allocated initially
    }

    // Get number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    // Get process sizes
    printf("Enter the size of each process:\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("Process %d size: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    // Allocating processes to partitions
    for (int i = 0; i < numProcesses; i++) {
        int allocatedFlag = 0;
        for (int j = 0; j < numPartitions; j++) {
            if (!allocated[j] && partitionSize[j] >= processSize[i]) {
                allocated[j] = 1;
                internalFragmentation += (partitionSize[j] - processSize[i]);
                printf("Process %d of size %d allocated to partition %d of size %d\n", i + 1, processSize[i], j + 1, partitionSize[j]);
                allocatedFlag = 1;
                break;
            }
        }
        if (!allocatedFlag) {
            printf("Process %d of size %d cannot be allocated to any partition.\n", i + 1, processSize[i]);
        }
    }

    printf("Total Internal Fragmentation: %d\n", internalFragmentation);

    return 0;
}
