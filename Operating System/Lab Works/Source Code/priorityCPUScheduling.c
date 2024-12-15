#include <stdio.h>

#define MAX_PROCESSES 100

// Function to calculate turnaround time and waiting time for Priority Scheduling
void calculatePriorityScheduling(int arrival[], int burst[], int priority[], int n) {
    int waiting_time[MAX_PROCESSES], turnaround_time[MAX_PROCESSES];
    int total_waiting_time = 0, total_turnaround_time = 0;
    int completed[MAX_PROCESSES] = {0};
    int current_time = 0, completed_count = 0;
    
    // Array to store process indices sorted by priority
    int sorted_indices[MAX_PROCESSES];
    
    // Initialize indices
    for (int i = 0; i < n; i++) {
        sorted_indices[i] = i;
    }
    
    // Sort processes based on priority (higher priority first)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (priority[sorted_indices[i]] < priority[sorted_indices[j]]) {
                // Swap indices
                int temp = sorted_indices[i];
                sorted_indices[i] = sorted_indices[j];
                sorted_indices[j] = temp;
            }
        }
    }
    
    // Calculate waiting time and turnaround time
    while (completed_count < n) {
        int index = -1;
        
        // Find the highest priority process that is not completed and has arrived
        for (int i = 0; i < n; i++) {
            int current_index = sorted_indices[i];
            if (arrival[current_index] <= current_time && !completed[current_index]) {
                index = current_index;
                break;
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
    printf("Process\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrival[i], burst[i], priority[i], waiting_time[i], turnaround_time[i]);
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
    
    int arrival[MAX_PROCESSES], burst[MAX_PROCESSES], priority[MAX_PROCESSES];
    
    // Input arrival, burst, and priority times
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
    
    printf("Enter priorities (higher number means higher priority):\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &priority[i]);
    }
    
    // Calculate and display Priority Scheduling results
    calculatePriorityScheduling(arrival, burst, priority, n);
    
    return 0;
}
