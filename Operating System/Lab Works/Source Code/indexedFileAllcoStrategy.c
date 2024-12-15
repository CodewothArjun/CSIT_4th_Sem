#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCKS 6
#define MAX_FILES 5

// Disk space
int disk[MAX_BLOCKS];
int disk_size = MAX_BLOCKS;

// File structure
typedef struct {
    char name[20];
    int size;
    int *index_blocks; // For Indexed Allocation
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

// Indexed Allocation
void allocateIndexed(File *file) {
    file->index_blocks = (int *)malloc(file->size * sizeof(int));
    if (!file->index_blocks) {
        printf("Memory allocation failed for index blocks.\n");
        return;
    }

    int count = 0;
    for (int i = 0; i < disk_size; i++) {
        if (disk[i] == 0) {
            file->index_blocks[count] = i;
            disk[i] = 1;
            count++;
            if (count == file->size) {
                printf("File '%s' allocated with index blocks: ", file->name);
                for (int j = 0; j < file->size; j++) {
                    printf("%d ", file->index_blocks[j]);
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
        disk[file->index_blocks[i]] = 0;
    }
    free(file->index_blocks);
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
    printf("\nIndexed Allocation:\n");
    for (int i = 0; i < MAX_FILES; i++) {
        allocateIndexed(&files[i]);
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
