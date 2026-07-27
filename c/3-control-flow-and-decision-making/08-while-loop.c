// =============================================================================
// TOPIC 8: `while` Loop
// =============================================================================

#include <stdio.h>

/*
 * `while` repeats a block as long as its condition stays true. Best suited
 * for loops where the number of iterations is NOT known in advance (e.g.
 * reading input until a sentinel value, or waiting for a condition to change).
 *
 * SYNTAX:
 *   while (condition) {
 *       // runs repeatedly WHILE condition is true
 *   }
 *
 * KEY DIFFERENCE FROM `for`:
 * - `while` is condition-only; initialization/update must be written manually.
 * - The condition is checked BEFORE the first iteration — if it's false
 *   immediately, the body never runs at all (0 iterations possible).
 */

void while_loop_example(void) {
    int i = 0;
    while (i < 5) {
        printf("i = %d\n", i);
        i++;   // update must be done manually — forgetting this causes an infinite loop
    }

    // condition false from the start -> body never executes
    int x = 10;
    while (x < 5) {
        printf("this never prints\n");
    }

    // classic use case: process a value until a sentinel is reached
    int values[] = {4, 8, 15, 16, 23, 42, -1};   // -1 marks the end
    int idx = 0;
    while (values[idx] != -1) {
        printf("value[%d] = %d\n", idx, values[idx]);
        idx++;
    }

    // digit-counting with while (number of iterations unknown ahead of time)
    int number = 12345, digit_count = 0;
    while (number != 0) {
        number /= 10;
        digit_count++;
    }
    printf("digit_count = %d\n", digit_count);
}

int main(void) {
    printf("\n=== Topic 8: while Loop ===\n");
    while_loop_example();
    return 0;
}

// ─────────────────────────────────────────────────────────────────────────────
// gcc -std=c11 -Wall -Wextra -pedantic -g 08-while-loop.c -o 08-while-loop
// ─────────────────────────────────────────────────────────────────────────────
