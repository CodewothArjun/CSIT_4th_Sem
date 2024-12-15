#include <stdio.h>
#include <string.h>

#define MAX 1000

// Function to check if the input is of the form a^n b^n c^n
int checkTM(char tape[]) {
    int i = 0, n = strlen(tape);
    
    // While there are unmarked 'a's
    while (1) {
        // Move to the leftmost 'a'
        while (tape[i] != 'a' && i < n) i++;
        if (i >= n) break;  // No more 'a's, move to check end

        // Mark 'a' as X
        tape[i] = 'X';

        // Move right to find the first 'b'
        while (tape[i] != 'b' && i < n) i++;
        if (i >= n) return 0;  // Mismatch: no 'b' found, reject

        // Mark 'b' as Y
        tape[i] = 'Y';

        // Move right to find the first 'c'
        while (tape[i] != 'c' && i < n) i++;
        if (i >= n) return 0;  // Mismatch: no 'c' found, reject

        // Mark 'c' as Z
        tape[i] = 'Z';

        // Reset to the beginning of the tape
        i = 0;
    }

    // After marking, check if there are any remaining 'a', 'b', or 'c'
    for (i = 0; i < n; i++) {
        if (tape[i] == 'a' || tape[i] == 'b' || tape[i] == 'c')
            return 0;  // Reject if any unmarked 'a', 'b', or 'c' remains
    }
    return 1;  // Accept if all 'a', 'b', and 'c' are marked
}

int main() {
    char tape[MAX];

    printf("Enter a string over the alphabet {a, b, c}: ");
    scanf("%s", tape);

    if (checkTM(tape))
        printf("The string is accepted by the Turing Machine.\n");
    else
        printf("The string is rejected by the Turing Machine.\n");

    return 0;
}
