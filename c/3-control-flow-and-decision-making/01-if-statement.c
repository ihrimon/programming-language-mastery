// =============================================================================
// TOPIC 1: `if` Statement
// =============================================================================

/*
 * The `if` statement executes a block of code ONLY when its condition
 * evaluates to a non-zero (TRUE) value.
 *
 * SYNTAX:
 *   if (condition) {
 *       // executed only when condition is non-zero (true)
 *   }
 *
 * - condition is any expression that produces an int (0 = false, non-zero = true)
 */

#include <stdio.h>

void if_statement_example(void) {
    int age = 20;

    if (age >= 18) {
        printf("age %d: eligible to vote\n", age);
    }

    // single-statement if WITHOUT braces — works, but risky style:
    int score = 100;
    if (score == 100)
        printf("Perfect score!\n");   // only this line belongs to the if
}

int main(void) {
    printf("\n=== Topic 1: if Statement ===\n");
    if_statement_example();
    return 0;
}
