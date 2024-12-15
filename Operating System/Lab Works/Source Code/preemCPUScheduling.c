#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;        // Process ID
    int burstTime;  // Burst Time
    int arrivalTime;// Arrival Time
    int priority;   // Priority (for Priority Scheduling)
    int remainingTime; // Remaining Time (for preemptive scheduling)
    int waitingTime;
    int turnaroundTime;
    int completed;  // Completion flag (used in Priority Scheduling)
} Process;

// Function to calculate Turnaround Time and Waiting Time for Round Robin
void calculateRR(Process p[], int n, int timeQuantum) {
    int currentTime = 0;
    int remainingProcesses = n;
    
    while (remainingProcesses > 0) {
        for (int i = 0; i < n; i++) {
            if (p[i].remainingTime > 0) {
                if (p[i].remainingTime <= timeQuantum) {
                    currentTime += p[i].remainingTime;
                    p[i].remainingTime = 0;
                    p[i].turnaroundTime = currentTime - p[i].arrivalTime;
                    p[i].waitingTime = p[i].turnaroundTime - p[i].burstTime;
                    remainingProcesses--;
                } else {
                    currentTime += timeQuantum;
                    p[i].remainingTime -= timeQuantum;
                }
            }
        }
    }
}

// Function to calculate Turnaround Time and Waiting Time for Preemptive Priority
void calculatePriority(Process p[], int n) {
    int currentTime = 0;
    int completedProcesses = 0;
    
    while (completedProcesses < n) {
        int idx = -1;
        int highestPriority = 9999;
        
        for (int i = 0; i < n; i++) {
            if (p[i].arrivalTime <= currentTime && p[i].remainingTime > 0 && p[i].priority < highestPriority) {
                highestPriority = p[i].priority;
                idx = i;
            }
        }

        if (idx != -1) {
            p[idx].remainingTime--;
            currentTime++;
            
            if (p[idx].remainingTime == 0) {
                completedProcesses++;
                p[idx].turnaroundTime = currentTime - p[idx].arrivalTime;
                p[idx].waitingTime = p[idx].turnaroundTime - p[idx].burstTime;
            }
        } else {
            currentTime++;
        }
    }
}

// Display the results
void displayResults(Process p[], int n) {
    printf("\nProcess\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               p[i].pid, p[i].burstTime, p[i].arrivalTime, p[i].priority, p[i].waitingTime, p[i].turnaroundTime);
    }
}

int main() {
    int n, choice, timeQuantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        printf("Enter arrival time for Process %d: ", i + 1);
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter priority for Process %d (higher number = lower priority): ", i + 1);
        scanf("%d", &processes[i].priority);
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].completed = 0;
    }

    printf("\nSelect the scheduling algorithm:\n1. Round Robin\n2. Preemptive Priority Scheduling\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter time quantum for Round Robin: ");
        scanf("%d", &timeQuantum);
        calculateRR(processes, n, timeQuantum);
    } else if (choice == 2) {
        calculatePriority(processes, n);
    } else {
        printf("Invalid choice!\n");
        return 1;
    }

    displayResults(processes, n);
    
    return 0;
}
