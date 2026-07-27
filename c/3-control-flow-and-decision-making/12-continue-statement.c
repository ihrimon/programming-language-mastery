// =============================================================================
// TOPIC 12: `continue` Statement
// =============================================================================

#include <stdio.h>

/*
 * `continue` skips the REST of the current loop iteration's body and jumps
 * straight to the next iteration — for `for` loops, this means the update
 * expression still runs; the loop does NOT exit (unlike `break`).
 */

void continue_example(void) {
    // skip even numbers, print only odd ones
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue;   // skip printf below, go straight to i++ and re-check
        }
        printf("odd: %d\n", i);
    }

    // continue in a while loop — must still update manually before continuing
    int i = 0;
    while (i < 10) {
        i++;
        if (i % 3 != 0) {
            continue;   // skip non-multiples of 3
        }
        printf("multiple of 3: %d\n", i);
    }

    // skip invalid/negative values while summing an array
    int values[] = {5, -2, 8, -1, 3};
    int n = sizeof(values) / sizeof(values[0]);
    int sum = 0;
    for (int j = 0; j < n; j++) {
        if (values[j] < 0) {
            continue;   // ignore negative values entirely
        }
        sum += values[j];
    }
    printf("sum of non-negative values = %d\n", sum);
}

int main(void) {
    printf("\n=== Topic 12: continue Statement ===\n");
    continue_example();
    return 0;
}

// ─────────────────────────────────────────────────────────────────────────────
// gcc -std=c11 -Wall -Wextra -pedantic -g 12-continue-statement.c -o 12-continue-statement
// ─────────────────────────────────────────────────────────────────────────────
