#include <stdio.h>

#define MAX_PROCESSES 100

// Function to calculate turnaround time and waiting time for SJF
void calculateSJF(int arrival[], int burst[], int n) {
    int waiting_time[MAX_PROCESSES], turnaround_time[MAX_PROCESSES];
    int total_waiting_time = 0, total_turnaround_time = 0;
    int remaining_burst[MAX_PROCESSES];
    int completed[MAX_PROCESSES] = {0};
    int current_time = 0, completed_count = 0;
    
    // Initialize remaining burst times
    for (int i = 0; i < n; i++) {
        remaining_burst[i] = burst[i];
    }
    
    // Sort processes based on burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (burst[i] > burst[j]) {
                // Swap burst times
                int temp_burst = burst[i];
                burst[i] = burst[j];
                burst[j] = temp_burst;
                
                // Swap arrival times accordingly
                int temp_arrival = arrival[i];
                arrival[i] = arrival[j];
                arrival[j] = temp_arrival;
            }
        }
    }
    
    // Calculate waiting time and turnaround time
    while (completed_count < n) {
        int min_burst = 9999, index = -1;
        for (int i = 0; i < n; i++) {
            if (arrival[i] <= current_time && !completed[i] && remaining_burst[i] < min_burst) {
                min_burst = remaining_burst[i];
                index = i;
            }
        }
        
        if (index != -1) {
            // Process the selected job
            waiting_time[index] = current_time - arrival[index];
            turnaround_time[index] = waiting_time[index] + burst[index];
            current_time += burst[index];
            completed[index] = 1;
            completed_count++;
        } else {
            current_time++;
        }
    }
    
    // Calculate total waiting time and turnaround time
    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }
    
    // Print results
    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrival[i], burst[i], waiting_time[i], turnaround_time[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

int main() {
    int n;
    
    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    if (n <= 0 || n > MAX_PROCESSES) {
        printf("Invalid number of processes. Exiting...\n");
        return 1;
    }
    
    int arrival[MAX_PROCESSES], burst[MAX_PROCESSES];
    
    // Input arrival and burst times
    printf("Enter arrival times:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &arrival[i]);
    }
    
    printf("Enter burst times:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst[i]);
    }
    
    // Calculate and display SJF results
    calculateSJF(arrival, burst, n);
    
    return 0;
}
