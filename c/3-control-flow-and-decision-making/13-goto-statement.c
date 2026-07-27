// =============================================================================
// TOPIC 13: `goto` Statement (and why to avoid it)
// =============================================================================

/*
 * `goto` performs an unconditional jump to a labeled statement ELSEWHERE in
 * the same function.
 *
 * SYNTAX:
 *   goto label;
 *   ...
 *   label:
 *       statement;
 */

#include <stdio.h>

void goto_example(void) {
    int i = 0;

    // basic goto — jumps forward, skipping the print
    goto skip_print;
    printf("this line is skipped\n");
skip_print:
    printf("landed after the goto\n");

    // the accepted use case: escaping nested loops in one jump
    for (i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) {
                goto found;   // break only exits the inner loop; goto exits both
            }
            printf("checking i=%d j=%d\n", i, j);
        }
    }
found:
    printf("stopped at i=%d\n", i);
}

int main(void) {
    printf("\n=== Topic 13: goto Statement ===\n");
    goto_example();

    return 0;
}
