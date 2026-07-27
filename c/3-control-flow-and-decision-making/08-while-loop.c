// =============================================================================
// TOPIC 8: `while` Loop
// =============================================================================

/*
 * `while` repeats a block as long as its condition stays true. 
 *
 * SYNTAX:
 *   while (condition) {
 *       // runs repeatedly WHILE condition is true
 *   }
 *
 * KEY DIFFERENCE FROM `for`:
 * - `while` is condition-only; initialization/update must be written manually.
 * - The condition is checked BEFORE the first iteration — if it's false
 *   immediately, the body never runs at all.
 */

#include <stdio.h>

void while_loop_example(void) {
    int i = 0;
    while (i < 5) {
        printf("i = %d\n", i);
        i++;   // update must be done manually
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
