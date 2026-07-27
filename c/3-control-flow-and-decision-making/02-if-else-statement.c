// =============================================================================
// TOPIC 2: `if...else` Statement
// =============================================================================

/*
 * `if...else` provides an alternate branch that runs when the condition is FALSE.
 *
 * SYNTAX:
 *   if (condition) {
 *       // runs when condition is true
 *   } else {
 *       // runs when condition is false
 *   }
*/

#include <stdio.h>

void if_else_example(void) {
    int number = -7;

    if (number >= 0) {
        printf("%d is non-negative\n", number);
    } else {
        printf("%d is negative\n", number);
    }

    // if/else as a replacement for the ternary operator 
    int a = 10, b = 20, max;
    if (a > b) {
        max = a;
    } else {
        max = b;
    }
    printf("max(a, b) = %d\n", max);
}

int main(void) {
    printf("\n=== Topic 2: if...else Statement ===\n");
    if_else_example();
    return 0;
}
