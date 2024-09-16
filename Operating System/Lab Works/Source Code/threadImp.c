/* To run this program open terminal and run this command:
    1) gcc -g -pthread threadImp.c -o threadImp
    2) .\threadImp.exe
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* threadFunction(void* arg) {
    int *id = (int *)arg;
    printf("Thread %d is running...\n", *id);
    free(id);  // Free the allocated memory for thread ID
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int *id1 = malloc(sizeof(int));
    int *id2 = malloc(sizeof(int));
    
    if (id1 == NULL || id2 == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    *id1 = 1;
    *id2 = 2;
  
    // Create threads and check for errors
    if (pthread_create(&thread1, NULL, threadFunction, id1) != 0) {
        fprintf(stderr, "Error creating thread 1\n");
        free(id1);
        return 1;
    }
    
    if (pthread_create(&thread2, NULL, threadFunction, id2) != 0) {
        fprintf(stderr, "Error creating thread 2\n");
        free(id2);
        return 1;
    }
    
    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Both threads are completed.\n");
    return 0;
}
