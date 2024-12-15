#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_PAGES 100

// Function to simulate FIFO page replacement algorithm
void fifoPageReplacement(int pages[], int numPages, int numFrames) {
    int frame[numFrames];
    int pageFaults = 0;
    int pageIndex = 0;
    
    // Initialize frames to -1 (indicating empty frames)
    for (int i = 0; i < numFrames; i++) {
        frame[i] = -1;
    }
    
    // FIFO queue initialization
    int queue[MAX_FRAMES];
    int front = 0, rear = 0;
    
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
                break;
            }
        }

        // Page not found in memory, perform page replacement
        if (!pageFound) {
            // If memory is full, remove the oldest page
            if (rear == numFrames) {
                frame[front] = page;
                front = (front + 1) % numFrames;
            } else {
                frame[rear] = page;
                rear++;
            }
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
    
    // Simulate FIFO page replacement
    fifoPageReplacement(pages, numPages, numFrames);

    return 0;
}
