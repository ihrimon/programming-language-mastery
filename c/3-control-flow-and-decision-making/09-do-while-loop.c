// =============================================================================
// TOPIC 9: `do...while` Loop
// =============================================================================

/*
 * `do...while` is like `while`, but the condition is checked AFTER the body
 * runs — guaranteeing the body executes AT LEAST ONCE, even if the condition
 * is false from the start.
 *
 * SYNTAX:
 *   do {
 *       // runs at least once
 *   } while (condition);      
 *
 * WHEN TO USE:
 * - Menu loops (show the menu once, then repeat while the user wants more)
 * - Input validation (ask for input at least once, re-ask while invalid)
 */

#include <stdio.h>

void do_while_example(void) {
    // body runs once even though the condition is immediately false
    int x = 10;
    do {
        printf("this prints exactly once, x = %d\n", x);
    } while (x < 5);

    // typical counting example
    int i = 0;
    do {
        printf("i = %d\n", i);
        i++;
    } while (i < 5);

    // simulated input validation loop (using a preset array instead of real stdin)
    int fake_inputs[] = {-1, -5, 42};   // first two are "invalid", third is valid
    int idx = 0, value;
    do {
        value = fake_inputs[idx++];
        if (value < 0) {
            printf("invalid input %d, retrying...\n", value);
        }
    } while (value < 0);
    printf("accepted value = %d\n", value);
}

int main(void) {
    printf("\n=== Topic 9: do...while Loop ===\n");
    do_while_example();
    return 0;
}
