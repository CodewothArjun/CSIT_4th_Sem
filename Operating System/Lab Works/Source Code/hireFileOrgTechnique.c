#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_CONTENT_LENGTH 100
#define MAX_FILES 10
#define MAX_SUBDIRS 10

// Define a file structure
typedef struct {
    char name[MAX_NAME_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} File;

// Define a directory structure
typedef struct Directory Directory; // Forward declaration

struct Directory {
    char name[MAX_NAME_LENGTH];
    File files[MAX_FILES];
    int fileCount;
    Directory* subdirs[MAX_SUBDIRS];
    int subdirCount;
};

// Initialize a directory
void initDirectory(Directory* dir, const char* name) {
    strncpy(dir->name, name, MAX_NAME_LENGTH);
    dir->fileCount = 0;
    dir->subdirCount = 0;
}

// Add a file to a directory
void addFileToDirectory(Directory* dir, const char* fileName, const char* content) {
    if (dir->fileCount < MAX_FILES) {
        strncpy(dir->files[dir->fileCount].name, fileName, MAX_NAME_LENGTH);
        strncpy(dir->files[dir->fileCount].content, content, MAX_CONTENT_LENGTH);
        dir->fileCount++;
        printf("File '%s' added to directory '%s'.\n", fileName, dir->name);
    } else {
        printf("Directory '%s' is full! Cannot add more files.\n", dir->name);
    }
}

// Add a subdirectory to a directory
void addSubdirectoryToDirectory(Directory* dir, Directory* subdir) {
    if (dir->subdirCount < MAX_SUBDIRS) {
        dir->subdirs[dir->subdirCount] = subdir;
        dir->subdirCount++;
        printf("Subdirectory '%s' added to directory '%s'.\n", subdir->name, dir->name);
    } else {
        printf("Directory '%s' is full! Cannot add more subdirectories.\n", dir->name);
    }
}

// List all files in a directory
void listFilesInDirectory(Directory* dir) {
    if (dir->fileCount == 0) {
        printf("Directory '%s' is empty.\n", dir->name);
        return;
    }

    printf("Files in directory '%s':\n", dir->name);
    for (int i = 0; i < dir->fileCount; i++) {
        printf("File Name: %s\n", dir->files[i].name);
        printf("Content: %s\n", dir->files[i].content);
        printf("------------------------------\n");
    }
}

// Recursively list all files and directories in a directory
void listAllInDirectory(Directory* dir, int level) {
    for (int i = 0; i < level; i++) printf("  ");
    printf("Directory '%s':\n", dir->name);
    listFilesInDirectory(dir);
    for (int i = 0; i < dir->subdirCount; i++) {
        listAllInDirectory(dir->subdirs[i], level + 1);
    }
}

int main() {
    // Create root directory
    Directory root;
    initDirectory(&root, "root");

    // Create and initialize subdirectories
    Directory subdir1;
    initDirectory(&subdir1, "subdir1");
    Directory subdir2;
    initDirectory(&subdir2, "subdir2");

    // Add files to root and subdirectories
    addFileToDirectory(&root, "file1.txt", "Content of root file1");
    addFileToDirectory(&root, "file2.txt", "Content of root file2");

    addFileToDirectory(&subdir1, "subfile1.txt", "Content of subdir1 file1");
    addFileToDirectory(&subdir2, "subfile2.txt", "Content of subdir2 file1");

    // Add subdirectories to root
    addSubdirectoryToDirectory(&root, &subdir1);
    addSubdirectoryToDirectory(&root, &subdir2);

    // List all files and directories
    printf("Hierarchical Directory Structure:\n");
    listAllInDirectory(&root, 0);

    return 0;
}
