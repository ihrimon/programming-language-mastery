// =============================================================================
// TOPIC 5: `switch` Statement (fall-through, `break`, `default`)
// =============================================================================

/*
 * `switch` compares one expression against several constant `case` values —
 * a cleaner alternative to a long `else if` ladder when checking one
 * variable against many exact values.
 *
 * SYNTAX:
 *   switch (expression) {
 *       case value1:
 *           ...
 *           break;
 *       case value2:
 *           ...
 *           break;
 *       default:
 *           ...
 *   }
 *
 * RULES:
 * - `expression` must evaluate to an INTEGER type (int, char, enum)
 * - `case` labels must be compile-time CONSTANTS, and all distinct.
 * - `break` exits the switch. WITHOUT it, execution "falls through" into the NEXT case
 * - `default` is optional; runs when no case matches. 
 */

#include <stdio.h>

void switch_statement_example(void) {
    int day = 3;

    switch (day) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        default:
            printf("Some other day\n");
            break;
    }
}

int main(void) {
    printf("\n=== Topic 5: switch Statement ===\n");
    switch_statement_example();
    return 0;
}
