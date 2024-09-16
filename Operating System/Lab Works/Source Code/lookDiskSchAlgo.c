#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100
#define DISK_SIZE 200 // Define the size of the disk

// Function to compare two integers used for sorting requests
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to simulate LOOK Disk Scheduling
void lookDiskScheduling(int requests[], int n, int initial_position, int direction) {
    int total_seek_time = 0;
    int current_position = initial_position;
    int seek_sequence[MAX_REQUESTS];
    int count = 0;

    // Sort the requests in ascending order
    qsort(requests, n, sizeof(int), compare);

    // Add the initial position to the sequence
    seek_sequence[count++] = initial_position;

    // Handle direction
    if (direction == 1) { // Move right
        // Move right to the highest request in the right direction
        for (int i = 0; i < n; i++) {
            if (requests[i] >= current_position) {
                seek_sequence[count++] = requests[i];
            }
        }
        // Move left after reaching the highest request
        for (int i = n - 1; i >= 0; i--) {
            if (requests[i] < current_position) {
                seek_sequence[count++] = requests[i];
            }
        }
    } else { // Move left
        // Move left to the lowest request in the left direction
        for (int i = n - 1; i >= 0; i--) {
            if (requests[i] <= current_position) {
                seek_sequence[count++] = requests[i];
            }
        }
        // Move right after reaching the lowest request
        for (int i = 0; i < n; i++) {
            if (requests[i] > current_position) {
                seek_sequence[count++] = requests[i];
            }
        }
    }

    // Calculate the total seek time
    printf("LOOK Disk Scheduling:\n");
    printf("Seek Sequence: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", seek_sequence[i]);
        if (i > 0) {
            total_seek_time += abs(seek_sequence[i] - seek_sequence[i - 1]);
        }
    }
    printf("\nTotal Seek Time: %d\n", total_seek_time);
}

int main() {
    int n, initial_position, direction;

    // Input number of requests and initial disk head position
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_REQUESTS) {
        printf("Invalid number of requests. Exiting...\n");
        return 1;
    }

    int requests[n];

    printf("Enter the disk requests:\n");
    for (int i = 0; i < n; i++) {
        printf("Request %d: ", i + 1);
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial disk head position: ");
    scanf("%d", &initial_position);

    printf("Enter the direction of head movement (1 for right, 0 for left): ");
    scanf("%d", &direction);

    if (direction != 0 && direction != 1) {
        printf("Invalid direction. Use 1 for right or 0 for left.\n");
        return 1;
    }

    // Simulate LOOK Disk Scheduling
    lookDiskScheduling(requests, n, initial_position, direction);

    return 0;
}
