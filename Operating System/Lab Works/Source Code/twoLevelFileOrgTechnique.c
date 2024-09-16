#include <stdio.h>
#include <string.h>

#define MAX_USERS 5
#define MAX_FILES 10
#define MAX_NAME_LENGTH 100
#define MAX_CONTENT_LENGTH 100

// Define a file structure
typedef struct {
    char name[MAX_NAME_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} File;

// Define a user directory structure
typedef struct {
    File files[MAX_FILES];
    int count; // Number of files currently in the user directory
} UserDirectory;

// Define a two-level directory structure
typedef struct {
    UserDirectory userDirs[MAX_USERS];
    int userCount; // Number of user directories
} TwoLevelDirectory;

// Initialize the two-level directory
void initTwoLevelDirectory(TwoLevelDirectory *dir) {
    dir->userCount = 0;
}

// Initialize a user directory
void initUserDirectory(UserDirectory *userDir) {
    userDir->count = 0;
}

// Add a file to a user directory
void addFileToUserDirectory(UserDirectory *userDir, const char *name, const char *content) {
    if (userDir->count < MAX_FILES) {
        strcpy(userDir->files[userDir->count].name, name);
        strcpy(userDir->files[userDir->count].content, content);
        userDir->count++;
        printf("File '%s' added successfully.\n", name);
    } else {
        printf("User directory is full! Cannot add more files.\n");
    }
}

// Delete a file from a user directory
void deleteFileFromUserDirectory(UserDirectory *userDir, const char *name) {
    int index = -1;
    for (int i = 0; i < userDir->count; i++) {
        if (strcmp(userDir->files[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("File '%s' not found.\n", name);
        return;
    }

    // Shift files to remove the deleted file
    for (int i = index; i < userDir->count - 1; i++) {
        userDir->files[i] = userDir->files[i + 1];
    }
    userDir->count--;
    printf("File '%s' deleted successfully.\n", name);
}

// List all files in a user directory
void listFilesInUserDirectory(UserDirectory *userDir) {
    if (userDir->count == 0) {
        printf("User directory is empty.\n");
        return;
    }

    printf("Files in User Directory:\n");
    for (int i = 0; i < userDir->count; i++) {
        printf("File Name: %s\n", userDir->files[i].name);
        printf("Content: %s\n", userDir->files[i].content);
        printf("------------------------------\n");
    }
}

// Add a user directory to the two-level directory
void addUserDirectory(TwoLevelDirectory *dir) {
    if (dir->userCount < MAX_USERS) {
        initUserDirectory(&dir->userDirs[dir->userCount]);
        dir->userCount++;
        printf("User directory added successfully.\n");
    } else {
        printf("Two-level directory is full! Cannot add more user directories.\n");
    }
}

// List all user directories in the two-level directory
void listUserDirectories(TwoLevelDirectory *dir) {
    if (dir->userCount == 0) {
        printf("No user directories available.\n");
        return;
    }

    for (int i = 0; i < dir->userCount; i++) {
        printf("User Directory %d:\n", i);
        listFilesInUserDirectory(&dir->userDirs[i]);
    }
}

int main() {
    TwoLevelDirectory directory;
    initTwoLevelDirectory(&directory);

    // Adding user directories
    addUserDirectory(&directory);
    addUserDirectory(&directory);

    // Adding files to user directories
    addFileToUserDirectory(&directory.userDirs[0], "user1file1.txt", "Content of user1 file1");
    addFileToUserDirectory(&directory.userDirs[0], "user1file2.txt", "Content of user1 file2");
    addFileToUserDirectory(&directory.userDirs[1], "user2file1.txt", "Content of user2 file1");

    // Listing files in user directories
    printf("\nListing files in all user directories:\n");
    listUserDirectories(&directory);

    // Deleting a file
    deleteFileFromUserDirectory(&directory.userDirs[0], "user1file1.txt");

    // Listing files again
    printf("\nListing files in all user directories after deletion:\n");
    listUserDirectories(&directory);

    return 0;
}
