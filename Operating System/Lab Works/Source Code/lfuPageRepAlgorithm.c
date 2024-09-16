#include <stdio.h>
#include <limits.h>

#define MAX_FRAMES 10
#define MAX_PAGES 100

// Function to simulate LFU page replacement algorithm
void lfuPageReplacement(int pages[], int numPages, int numFrames) {
    int frame[numFrames];
    int frequency[numFrames];
    int pageFaults = 0;
    int pageIndex = 0;

    // Initialize frames and frequency counts
    for (int i = 0; i < numFrames; i++) {
        frame[i] = -1;
        frequency[i] = 0;
    }

    printf("Page Reference String: ");
    for (int i = 0; i < numPages; i++) {
        printf("%d ", pages[i]);
    }
    printf("\n");

    printf("Memory Content after each reference:\n");

    for (int i = 0; i < numPages; i++) {
        int page = pages[i];
        int pageFound = 0;
        int minFrequency = INT_MAX;
        int replaceIndex = 0;

        // Check if page is already in memory
        for (int j = 0; j < numFrames; j++) {
            if (frame[j] == page) {
                pageFound = 1;
                frequency[j]++;
                break;
            }
        }

        // Page not found in memory, perform page replacement
        if (!pageFound) {
            // If memory is full, replace the least frequently used page
            for (int j = 0; j < numFrames; j++) {
                if (frequency[j] < minFrequency) {
                    minFrequency = frequency[j];
                    replaceIndex = j;
                }
            }

            frame[replaceIndex] = page;
            frequency[replaceIndex] = 1;
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
    
    // Simulate LFU page replacement
    lfuPageReplacement(pages, numPages, numFrames);

    return 0;
}
