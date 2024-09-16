#include <stdio.h>
#include <limits.h>

#define MAX_FRAMES 10
#define MAX_PAGES 100

// Function to find the index of the page to replace
int findOptimalPageToReplace(int frame[], int pageIndex[], int numFrames, int currentPage) {
    int farthest = currentPage;
    int replaceIndex = -1;

    for (int i = 0; i < numFrames; i++) {
        int j;
        for (j = currentPage; j < MAX_PAGES; j++) {
            if (frame[i] == pageIndex[j]) {
                if (j > farthest) {
                    farthest = j;
                    replaceIndex = i;
                }
                break;
            }
        }
        if (j == MAX_PAGES) {
            return i;
        }
    }
    return replaceIndex;
}

// Function to simulate Optimal page replacement algorithm
void optimalPageReplacement(int pages[], int numPages, int numFrames) {
    int frame[numFrames];
    int pageIndex[MAX_PAGES];
    int pageFaults = 0;
    int pageHits = 0;

    // Initialize frames and page index
    for (int i = 0; i < numFrames; i++) {
        frame[i] = -1;
    }
    for (int i = 0; i < numPages; i++) {
        pageIndex[i] = pages[i];
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

        // Check if page is already in memory
        for (int j = 0; j < numFrames; j++) {
            if (frame[j] == page) {
                pageFound = 1;
                pageHits++;
                break;
            }
        }

        // Page not found in memory, perform page replacement
        if (!pageFound) {
            int replaceIndex = findOptimalPageToReplace(frame, pageIndex, numFrames, i);
            frame[replaceIndex] = page;
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
    printf("Total Page Hits: %d\n", pageHits);
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
    
    // Simulate Optimal page replacement
    optimalPageReplacement(pages, numPages, numFrames);

    return 0;
}
