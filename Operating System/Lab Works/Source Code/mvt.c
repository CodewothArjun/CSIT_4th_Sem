#include <stdio.h>

int main() {
    int totalMemory, processSize[10], numProcesses, memoryAllocated = 0;

    // Get total memory available
    printf("Enter the total available memory: ");
    scanf("%d", &totalMemory);

    // Get number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    // Get process sizes
    printf("Enter the size of each process:\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("Process %d size: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    // Allocating processes to memory
    for (int i = 0; i < numProcesses; i++) {
        if (memoryAllocated + processSize[i] <= totalMemory) {
            memoryAllocated += processSize[i];
            printf("Process %d of size %d allocated. Memory used: %d/%d\n", i + 1, processSize[i], memoryAllocated, totalMemory);
        } else {
            printf("Process %d of size %d cannot be allocated due to insufficient memory.\n", i + 1, processSize[i]);
        }
    }

    printf("Total memory allocated: %d\n", memoryAllocated);
    printf("Total external fragmentation (remaining memory): %d\n", totalMemory - memoryAllocated);

    return 0;
}
