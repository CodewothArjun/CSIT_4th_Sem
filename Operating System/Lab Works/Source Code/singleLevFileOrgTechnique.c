#include <stdio.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_NAME_LENGTH 100
#define MAX_CONTENT_LENGTH 100

// Define a file structure
typedef struct {
    char name[MAX_NAME_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} File;

// Define a single-level directory structure
typedef struct {
    File files[MAX_FILES];
    int count; // Number of files currently in the directory
} SingleLevelDirectory;

// Initialize the directory
void initSingleLevelDirectory(SingleLevelDirectory *dir) {
    dir->count = 0;
}

// Add a file to the directory
void addFileToSingleLevelDirectory(SingleLevelDirectory *dir, const char *name, const char *content) {
    if (dir->count < MAX_FILES) {
        strcpy(dir->files[dir->count].name, name);
        strcpy(dir->files[dir->count].content, content);
        dir->count++;
        printf("File '%s' added successfully.\n", name);
    } else {
        printf("Directory is full! Cannot add more files.\n");
    }
}

// Delete a file from the directory
void deleteFileFromSingleLevelDirectory(SingleLevelDirectory *dir, const char *name) {
    int index = -1;
    for (int i = 0; i < dir->count; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("File '%s' not found.\n", name);
        return;
    }

    // Shift files to remove the deleted file
    for (int i = index; i < dir->count - 1; i++) {
        dir->files[i] = dir->files[i + 1];
    }
    dir->count--;
    printf("File '%s' deleted successfully.\n", name);
}

// List all files in the directory
void listFilesInSingleLevelDirectory(SingleLevelDirectory *dir) {
    if (dir->count == 0) {
        printf("Directory is empty.\n");
        return;
    }

    printf("Files in Single-Level Directory:\n");
    for (int i = 0; i < dir->count; i++) {
        printf("File Name: %s\n", dir->files[i].name);
        printf("Content: %s\n", dir->files[i].content);
        printf("------------------------------\n");
    }
}

int main() {
    SingleLevelDirectory directory;
    initSingleLevelDirectory(&directory);

    // Adding files to the directory
    addFileToSingleLevelDirectory(&directory, "file1.txt", "Content of file1");
    addFileToSingleLevelDirectory(&directory, "file2.txt", "Content of file2");

    // Listing files
    listFilesInSingleLevelDirectory(&directory);

    // Deleting a file
    deleteFileFromSingleLevelDirectory(&directory, "file1.txt");

    // Listing files again
    listFilesInSingleLevelDirectory(&directory);

    return 0;
}
