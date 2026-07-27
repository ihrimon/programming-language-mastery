// =============================================================================
// TOPIC 6: `switch` with Ranges (GCC extension)
// =============================================================================

#include <stdio.h>

/*
 * Standard C `switch` only matches a case against a SINGLE constant value.
 * GCC (and Clang) provide a NON-STANDARD extension: case RANGES, using `...`
 * between two constants.
 *
 * SYNTAX (GCC extension — NOT portable, NOT valid in strict/-pedantic mode):
 *   case low ... high:
 *       ...
 *
 * IMPORTANT SYNTAX DETAIL:
 * - Spaces are REQUIRED around `...` — `case 1...5:` can be misparsed by the
 *   preprocessor as `1.` followed by `..5`. Always write `case 1 ... 5:`.
 *
 * PORTABILITY WARNING:
 * - This is a GCC/Clang extension, not part of any C standard (C89-C23).
 * - Compiling with `-pedantic` or `-std=c11` (without `-std=gnu11`) will
 *   produce a warning/error for this syntax on strict-conformance builds.
 * - For portable code, use an `if/else` chain or explicit case-per-value instead.
 */

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

// ─────────────────────────────────────────────────────────────────────────────
// Requires GNU extensions — will NOT compile with strict -std=c11 -pedantic:
//   gcc -std=gnu11 -Wall -Wextra -g 06-switch-with-ranges.c -o 06-switch-with-ranges
// ─────────────────────────────────────────────────────────────────────────────
