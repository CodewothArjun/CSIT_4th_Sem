#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCKS 7
#define BLOCK_SIZE 6
#define MAX_FILES 5

// Disk space
int disk[MAX_BLOCKS];
int disk_size = MAX_BLOCKS;

// File structure
typedef struct {
    char name[20];
    int size;
    int start_block;  // For Sequential Allocation
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

// Free allocated blocks
void freeBlocks(File *file) {
    for (int i = file->start_block; i < file->start_block + file->size; i++) {
        disk[i] = 0;
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

    // Free allocated blocks
    printf("\nFreeing Allocated Blocks:\n");
    for (int i = 0; i < MAX_FILES; i++) {
        freeBlocks(&files[i]);
    }
    printDiskStatus();

    return 0;
}
