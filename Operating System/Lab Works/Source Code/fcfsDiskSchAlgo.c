#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

// Function to calculate total seek time and print the sequence
void fcfsDiskScheduling(int requests[], int n, int initial_position) {
    int total_seek_time = 0;
    int current_position = initial_position;

    printf("FCFS Disk Scheduling:\n");
    printf("Initial Disk Head Position: %d\n", initial_position);

    // Print the sequence of requests
    printf("Request Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", requests[i]);
    }
    printf("\n");

    // Calculate the total seek time
    for (int i = 0; i < n; i++) {
        int seek_time = abs(requests[i] - current_position);
        total_seek_time += seek_time;
        printf("Move from %d to %d: Seek Time = %d\n", current_position, requests[i], seek_time);
        current_position = requests[i];
    }

    printf("Total Seek Time: %d\n", total_seek_time);
}

int main() {
    int n, initial_position;

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

    // Simulate FCFS Disk Scheduling
    fcfsDiskScheduling(requests, n, initial_position);

    return 0;
}
