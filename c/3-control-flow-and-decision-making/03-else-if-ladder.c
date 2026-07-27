// =============================================================================
// TOPIC 3: `else if` Ladder
// =============================================================================

/*
 * An `else if` ladder chains multiple conditions in sequence. Conditions are
 * tested TOP TO BOTTOM, and the FIRST one that is true runs — the rest are
 * skipped entirely, even if they would also be true.
 *
 * SYNTAX:
 *   if (condition1) {
 *       ...
 *   } else if (condition2) {
 *       ...
 *   } else if (condition3) {
 *       ...
 *   } else {
 *       // runs only if NONE of the above conditions were true
 *   }
 *
 * ORDER MATTERS: put the most specific / most likely conditions first.
 */

#include <stdio.h>

void else_if_ladder_example(void) {
    int marks = 82;
    char grade;

    if (marks >= 90) {
        grade = 'A';
    } else if (marks >= 80) {
        grade = 'B';
    } else if (marks >= 70) {
        grade = 'C';
    } else if (marks >= 60) {
        grade = 'D';
    } else {
        grade = 'F';
    }

    printf("marks = %d -> grade %c\n", marks, grade);
}

int main(void) {
    printf("\n=== Topic 3: else if Ladder ===\n");
    else_if_ladder_example();
    return 0;
}
