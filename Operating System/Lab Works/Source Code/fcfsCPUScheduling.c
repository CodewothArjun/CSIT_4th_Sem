#include <stdio.h>

#define MAX_PROCESSES 100

// Function to calculate turnaround time and waiting time for FCFS
void calculateFCFS(int arrival[], int burst[], int n) {
    int waiting_time[MAX_PROCESSES], turnaround_time[MAX_PROCESSES];
    int total_waiting_time = 0, total_turnaround_time = 0;
    
    // Calculate waiting time for each process
    waiting_time[0] = 0; // First process has no waiting time
    for (int i = 1; i < n; i++) {
        waiting_time[i] = 0;
        for (int j = 0; j < i; j++) {
            waiting_time[i] += burst[j];
        }
    }
    
    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + burst[i];
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
    
    // Calculate and display FCFS results
    calculateFCFS(arrival, burst, n);
    
    return 0;
}
