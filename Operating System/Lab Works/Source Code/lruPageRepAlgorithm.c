#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 10
#define MAX_PAGES 100

// Function to simulate LRU page replacement algorithm
void lruPageReplacement(int pages[], int numPages, int numFrames) {
    int frame[numFrames];
    int pageFaults = 0;
    int lastUsed[numFrames];
    int currentTime = 0;

    // Initialize frames and last used times
    for (int i = 0; i < numFrames; i++) {
        frame[i] = -1;
        lastUsed[i] = -1;
    }

    printf("Page Reference String: ");
    for (int i = 0; i < numPages; i++) {
        printf("%d ", pages[i]);
    }
    printf("\n");

    printf("Memory Content after each reference:\n");

    for (int i = 0; i < numPages; i++) {
        int page = pages[i];
        bool pageFound = false;
        int oldestPageIndex = 0;

        // Check if page is already in memory
        for (int j = 0; j < numFrames; j++) {
            if (frame[j] == page) {
                pageFound = true;
                lastUsed[j] = currentTime;
                break;
            }
        }

        // Page not found in memory, perform page replacement
        if (!pageFound) {
            int minTime = currentTime;
            for (int j = 0; j < numFrames; j++) {
                if (lastUsed[j] < minTime) {
                    minTime = lastUsed[j];
                    oldestPageIndex = j;
                }
            }

            frame[oldestPageIndex] = page;
            lastUsed[oldestPageIndex] = currentTime;
            pageFaults++;
        }

        // Print memory content
        printf("After page %d: ", page);
        for (int j = 0; j < numFrames; j++) {
            if (frame[j] != -1) {
                printf("%d ", frame[j]);
            }
        }
        printf("\n");

        currentTime++;
    }

    // Print total page faults
    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int numPages, numFrames;
    int pages[MAX_PAGES];
    
    // Input number of pages
    printf("Enter the number of pages: ");
    scanf("%d", &numPages);
    
    // Input page reference string
    printf("Enter the page reference string:\n");
    for (int i = 0; i < numPages; i++) {
        printf("Page %d: ", i + 1);
        scanf("%d", &pages[i]);
    }
    
    // Input number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);
    
    // Simulate LRU page replacement
    lruPageReplacement(pages, numPages, numFrames);

    return 0;
}
