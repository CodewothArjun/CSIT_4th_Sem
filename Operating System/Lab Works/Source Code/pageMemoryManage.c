#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int pageTable[MAX], pageSize, numPages, logicalAddress, pageNumber, offset, frameNumber, physicalAddress;
    
    // Input page size and number of pages
    printf("Enter the page size (in words): ");
    scanf("%d", &pageSize);
    
    printf("Enter the number of pages: ");
    scanf("%d", &numPages);
    
    // Populate page table with frame numbers for each page
    printf("Enter the frame number for each page:\n");
    for (int i = 0; i < numPages; i++) {
        printf("Page %d: ", i);
        scanf("%d", &pageTable[i]);
    }
    
    // Input the logical address
    printf("\nEnter a logical address (in words): ");
    scanf("%d", &logicalAddress);
    
    // Calculate the page number and offset
    pageNumber = logicalAddress / pageSize;
    offset = logicalAddress % pageSize;
    
    // Check if the page number is valid
    if (pageNumber >= numPages) {
        printf("Error: Invalid logical address!\n");
        return 1;
    }
    
    // Get the frame number from the page table
    frameNumber = pageTable[pageNumber];
    
    // Calculate the physical address
    physicalAddress = frameNumber * pageSize + offset;
    
    // Output the results
    printf("\nLogical Address: %d\n", logicalAddress);
    printf("Page Number: %d\n", pageNumber);
    printf("Offset: %d\n", offset);
    printf("Frame Number: %d\n", frameNumber);
    printf("Physical Address: %d\n", physicalAddress);
    
    return 0;
}
