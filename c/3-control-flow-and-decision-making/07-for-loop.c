// =============================================================================
// TOPIC 7: `for` Loop (initialization, condition, update)
// =============================================================================

/*
 * `for` is the standard loop for a KNOWN or COUNTABLE number of iterations.
 * It packs three parts into one line:
 *
 * SYNTAX:
 *   for (initialization; condition; update) {
 *       // loop body
 *   }
 *
 *   - initialization → runs ONCE, before the loop starts
 *   - condition      → checked BEFORE each iteration; loop runs while true
 *   - update         → runs AFTER each iteration's body 
 */

#include <stdio.h>

void for_loop_example(void) {
    // basic counting loop
    for (int i = 0; i < 5; i++) {
        printf("i = %d\n", i);
    }

    // counting DOWN
    for (int i = 5; i > 0; i--) {
        printf("countdown: %d\n", i);
    }

    // stepping by more than 1
    for (int i = 0; i <= 20; i += 5) {
        printf("step: %d\n", i);
    }

    // multiple variables using the comma operator 
    for (int i = 0, j = 10; i < j; i++, j--) {
        printf("i=%d j=%d\n", i, j);
    }

    // sum of first N numbers
    int n = 10, sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    printf("sum 1..%d = %d\n", n, sum);
}

int main(void) {
    printf("\n=== Topic 7: for Loop ===\n");
    for_loop_example();
    return 0;
}
