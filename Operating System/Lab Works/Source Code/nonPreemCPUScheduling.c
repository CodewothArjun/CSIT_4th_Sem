#include <stdio.h>

typedef struct {
    int pid;        // Process ID
    int burstTime;  // Burst Time
    int arrivalTime;// Arrival Time
    int priority;   // Priority (for Priority Scheduling)
    int waitingTime;
    int turnaroundTime;
} Process;

// Function to calculate waiting time and turnaround time
void calculateTimes(Process p[], int n) {
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        p[i].waitingTime = currentTime - p[i].arrivalTime;
        currentTime += p[i].burstTime;
        p[i].turnaroundTime = currentTime - p[i].arrivalTime;
    }
}

// FCFS Scheduling Algorithm
void fcfsScheduling(Process p[], int n) {
    printf("\n--- FCFS Scheduling ---\n");
    calculateTimes(p, n);
    for (int i = 0; i < n; i++) {
        printf("Process %d: Waiting Time = %d, Turnaround Time = %d\n", p[i].pid, p[i].waitingTime, p[i].turnaroundTime);
    }
}

// SJF Scheduling Algorithm (non-preemptive)
void sjfScheduling(Process p[], int n) {
    printf("\n--- SJF Scheduling ---\n");
    // Sort by burst time
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (p[i].burstTime > p[j].burstTime) {
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    calculateTimes(p, n);
    for (int i = 0; i < n; i++) {
        printf("Process %d: Waiting Time = %d, Turnaround Time = %d\n", p[i].pid, p[i].waitingTime, p[i].turnaroundTime);
    }
}

// Priority Scheduling Algorithm (non-preemptive)
void priorityScheduling(Process p[], int n) {
    printf("\n--- Priority Scheduling ---\n");
    // Sort by priority (higher number = lower priority)
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (p[i].priority > p[j].priority) {
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    calculateTimes(p, n);
    for (int i = 0; i < n; i++) {
        printf("Process %d: Waiting Time = %d, Turnaround Time = %d\n", p[i].pid, p[i].waitingTime, p[i].turnaroundTime);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    Process processes[n];
    
    for (int i = 0; i < n; i++) {
        processes[i].pid = i+1;
        printf("Enter burst time for Process %d: ", i+1);
        scanf("%d", &processes[i].burstTime);
        printf("Enter arrival time for Process %d: ", i+1);
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter priority for Process %d: ", i+1);
        scanf("%d", &processes[i].priority);
    }
    
    // FCFS Scheduling
    fcfsScheduling(processes, n);
    
    // SJF Scheduling
    sjfScheduling(processes, n);
    
    // Priority Scheduling
    priorityScheduling(processes, n);

    return 0;
}
