#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 6
#define MAX_FILES 5

// Disk space
int disk[MAX_BLOCKS];
int disk_size = MAX_BLOCKS;

// File structure
typedef struct File {
    char name[20];
    int size;
    int *linked_blocks; // For Linked Allocation
} File;

// Initialize the disk
void initializeDisk() {
    for (int i = 0; i < disk_size; i++) {
        disk[i] = 0; // 0 means free
    }
}

// Print the disk status
void printDiskStatus() {
    printf("Disk Status:\n");
    for (int i = 0; i < disk_size; i++) {
        printf("Block %d: %s\n", i, disk[i] == 0 ? "Free" : "Occupied");
    }
}

// Linked Allocation
void allocateLinked(File *file) {
    file->linked_blocks = (int *)malloc(file->size * sizeof(int));
    if (!file->linked_blocks) {
        printf("Memory allocation failed for linked blocks.\n");
        return;
    }

    int count = 0;
    int prev_block = -1;
    for (int i = 0; i < disk_size; i++) {
        if (disk[i] == 0) {
            file->linked_blocks[count] = i;
            disk[i] = 1;
            if (prev_block != -1) {
                printf("Block %d -> Block %d\n", file->linked_blocks[count - 1], i);
            }
            prev_block = i;
            count++;
            if (count == file->size) {
                printf("File '%s' allocated with linked blocks: ", file->name);
                for (int j = 0; j < file->size; j++) {
                    printf("%d ", file->linked_blocks[j]);
                }
                printf("\n");
                return;
            }
        }
    }
    printf("Not enough free blocks for file '%s'.\n", file->name);
}

// Free allocated blocks
void freeBlocks(File *file) {
    for (int i = 0; i < file->size; i++) {
        disk[file->linked_blocks[i]] = 0;
    }
    free(file->linked_blocks);
}

int main() {
    File files[MAX_FILES] = {
        {"File1", 5},
        {"File2", 3},
        {"File3", 7},
        {"File4", 2},
        {"File5", 4}
    };

    // Initialize disk
    initializeDisk();
    printDiskStatus();

    // Allocate files
    printf("\nLinked Allocation:\n");
    for (int i = 0; i < MAX_FILES; i++) {
        allocateLinked(&files[i]);
    }
    printDiskStatus();

    // Free allocated blocks
    printf("\nFreeing Allocated Blocks:\n");
    for (int i = 0; i < MAX_FILES; i++) {
        freeBlocks(&files[i]);
    }
    printDiskStatus();

    return 0;
}
