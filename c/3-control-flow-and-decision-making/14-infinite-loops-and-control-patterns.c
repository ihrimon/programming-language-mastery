// =============================================================================
// TOPIC 14: Infinite Loops & Loop Control Patterns
// =============================================================================

/*
 * An INFINITE LOOP has a condition that never becomes false — it runs
 * forever unless stopped from inside (via `break`, `return`, `exit()`) or
 * from outside (signal, process kill).
 *
 * COMMON WAYS TO WRITE ONE:
 *   for (;;)       { ... }     // all three for-clauses omitted — idiomatic C
 *   while (1)      { ... }     // condition is always non-zero (true)
 *   do { ... } while (1);      // same idea, checked at the bottom
 * *
 * THE DANGER: writing one BY ACCIDENT (forgetting to update a loop
 * variable, or a condition that can never become false) hangs the program.
 */

#include <stdio.h>

void infinite_loop_patterns_example(void) {
    // `for (;;)` with an internal break — a controlled "infinite" loop
    int count = 0;
    for (;;) {
        if (count >= 3) {
            break;   // the ONLY way this loop ends
        }
        printf("for(;;) iteration %d\n", count);
        count++;
    }

    // `while (1)` — equally idiomatic, same controlled-exit pattern
    int n = 0;
    while (1) {
        if (n >= 3) {
            break;
        }
        printf("while(1) iteration %d\n", n);
        n++;
    }

    // sentinel-driven loop: a common REAL use case for "runs until told to stop"
    int simulated_inputs[] = {10, 20, 30, -1};   // -1 = "quit" sentinel
    int idx = 0;
    for (;;) {
        int input = simulated_inputs[idx++];
        if (input == -1) {
            printf("sentinel reached — stopping\n");
            break;
        }
        printf("processing input: %d\n", input);
    }
}

int main(void) {
    printf("\n=== Topic 14: Infinite Loops & Loop Control Patterns ===\n");
    infinite_loop_patterns_example();
    return 0;
}
