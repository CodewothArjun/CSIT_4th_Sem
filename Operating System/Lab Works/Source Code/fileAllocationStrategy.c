#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCKS 100
#define BLOCK_SIZE 10
#define MAX_FILES 5

// Disk space
int disk[MAX_BLOCKS];
int disk_size = MAX_BLOCKS;

// File structure
typedef struct {
    char name[20];
    int size;
    int start_block;  // For Sequential Allocation
    int *index_blocks; // For Indexed Allocation
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

// Sequential Allocation
void allocateSequential(File *file) {
    int start = -1;
    int count = 0;

    for (int i = 0; i < disk_size; i++) {
        if (disk[i] == 0) {
            if (count == 0) start = i;
            count++;
            if (count == file->size) {
                file->start_block = start;
                for (int j = start; j < start + file->size; j++) {
                    disk[j] = 1;
                }
                printf("File '%s' allocated sequentially from block %d.\n", file->name, start);
                return;
            }
        } else {
            count = 0;
        }
    }
    printf("Not enough contiguous space for file '%s'.\n", file->name);
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
                printf("File '%s' allocated with index blocks.\n", file->name);
                return;
            }
        }
    }
    printf("Not enough free blocks for file '%s'.\n", file->name);
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
            if (prev_block != -1 && count > 0) {
                printf("Block %d -> Block %d\n", file->linked_blocks[count - 1], i);
            }
            prev_block = i;
            count++;
            if (count == file->size) {
                printf("File '%s' allocated with linked blocks.\n", file->name);
                return;
            }
        }
    }
    printf("Not enough free blocks for file '%s'.\n", file->name);
}

// Free allocated blocks
void freeBlocks(File *file, int method) {
    if (method == 1) { // Sequential
        for (int i = file->start_block; i < file->start_block + file->size; i++) {
            disk[i] = 0;
        }
    } else if (method == 2) { // Indexed
        for (int i = 0; i < file->size; i++) {
            disk[file->index_blocks[i]] = 0;
        }
        free(file->index_blocks);
    } else if (method == 3) { // Linked
        for (int i = 0; i < file->size; i++) {
            disk[file->linked_blocks[i]] = 0;
        }
        free(file->linked_blocks);
    }
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
    printf("\nSequential Allocation:\n");
    for (int i = 0; i < MAX_FILES; i++) {
        allocateSequential(&files[i]);
    }
    printDiskStatus();

    // Reinitialize disk for the next allocation
    initializeDisk();
    printDiskStatus();

    printf("\nIndexed Allocation:\n");
    for (int i = 0; i < MAX_FILES; i++) {
        allocateIndexed(&files[i]);
    }
    printDiskStatus();

    // Reinitialize disk for the next allocation
    initializeDisk();
    printDiskStatus();

    printf("\nLinked Allocation:\n");
    for (int i = 0; i < MAX_FILES; i++) {
        allocateLinked(&files[i]);
    }
    printDiskStatus();

    // Free allocated blocks
    for (int i = 0; i < MAX_FILES; i++) {
        freeBlocks(&files[i], 1); // Sequential
        freeBlocks(&files[i], 2); // Indexed
        freeBlocks(&files[i], 3); // Linked
    }

    return 0;
}
