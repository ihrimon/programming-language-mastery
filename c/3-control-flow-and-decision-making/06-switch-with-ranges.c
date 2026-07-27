// =============================================================================
// TOPIC 6: `switch` with Ranges (GCC extension)
// =============================================================================

/*
 * Standard C `switch` only matches a case against a SINGLE constant value.
 * GCC (and Clang) provide a NON-STANDARD extension: case RANGES, using `...`
 * between two constants.
 */

#include <stdio.h>

void switch_ranges_example(void) {
    char grade = 'B';

    switch (grade) {
        case 'A' ... 'B':          // GCC range extension: matches 'A' or 'B'
            printf("grade %c: Excellent\n", grade);
            break;
        case 'C' ... 'D':
            printf("grade %c: Average\n", grade);
            break;
        case 'F':
            printf("grade %c: Fail\n", grade);
            break;
        default:
            printf("Invalid grade\n");
    }

    int score = 73;
    switch (score) {
        case 90 ... 100:
            printf("score %d -> A\n", score);
            break;
        case 80 ... 89:
            printf("score %d -> B\n", score);
            break;
        case 70 ... 79:
            printf("score %d -> C\n", score);
            break;
        default:
            printf("score %d -> F\n", score);
    }
}

int main(void) {
    printf("\n=== Topic 6: switch with Ranges (GCC extension) ===\n");
    switch_ranges_example();
    return 0;
}
