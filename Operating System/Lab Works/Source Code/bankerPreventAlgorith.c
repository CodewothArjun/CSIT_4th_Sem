#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int allocation[MAX_PROCESSES][MAX_RESOURCES], max[MAX_PROCESSES][MAX_RESOURCES], need[MAX_PROCESSES][MAX_RESOURCES], available[MAX_RESOURCES];
int n, m; // n = number of processes, m = number of resources

void calculateNeed() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

int isSafe() {
    int work[MAX_RESOURCES], finish[MAX_PROCESSES] = {0}, safeSequence[MAX_PROCESSES];
    for (int i = 0; i < m; i++) {
        work[i] = available[i];
    }
    
    int count = 0;
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }

                if (j == m) {
                    for (int k = 0; k < m; k++) {
                        work[k] += allocation[i][k];
                    }
                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        
        if (!found) {
            printf("System is in an unsafe state!\n");
            return 0;
        }
    }
    
    printf("System is in a safe state. Safe sequence is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", safeSequence[i]);
    }
    printf("\n");
    return 1;
}

void requestResources(int processID) {
    int request[MAX_RESOURCES];
    printf("Enter the request for resources by process %d: \n", processID);
    for (int i = 0; i < m; i++) {
        printf("Resource %d: ", i);
        scanf("%d", &request[i]);
    }

    for (int i = 0; i < m; i++) {
        if (request[i] > need[processID][i]) {
            printf("Error: Request exceeds the process's maximum claim.\n");
            return;
        }
    }

    for (int i = 0; i < m; i++) {
        if (request[i] > available[i]) {
            printf("Resources are not available right now. Process %d must wait.\n", processID);
            return;
        }
    }

    for (int i = 0; i < m; i++) {
        available[i] -= request[i];
        allocation[processID][i] += request[i];
        need[processID][i] -= request[i];
    }

    if (!isSafe()) {
        for (int i = 0; i < m; i++) {
            available[i] += request[i];
            allocation[processID][i] -= request[i];
            need[processID][i] += request[i];
        }
        printf("Request cannot be granted as it would lead to an unsafe state. Process %d must wait.\n", processID);
    } else {
        printf("Request granted to process %d.\n", processID);
    }
}

int main() {
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter the number of resource types: ");
    scanf("%d", &m);

    printf("Enter the Allocation Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the Max Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the Available Resources:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }

    calculateNeed();
    
    if (isSafe()) {
        int processID;
        printf("Do you want to request resources for any process? Enter process ID (-1 to exit): ");
        scanf("%d", &processID);

        while (processID != -1) {
            requestResources(processID);
            printf("Enter process ID to request resources (-1 to exit): ");
            scanf("%d", &processID);
        }
    }

    return 0;
}
