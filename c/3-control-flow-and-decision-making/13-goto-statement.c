// =============================================================================
// TOPIC 13: `goto` Statement (and why to avoid it)
// =============================================================================

#include <stdio.h>

/*
 * `goto` performs an unconditional jump to a labeled statement ELSEWHERE in
 * the same function.
 *
 * SYNTAX:
 *   goto label;
 *   ...
 *   label:
 *       statement;
 *
 * WHY IT'S GENERALLY AVOIDED:
 * - Makes control flow hard to follow ("spaghetti code") — the reader must
 *   scan the whole function to find where a label jumps from/to.
 * - Almost every use case is better served by structured control flow
 *   (loops, functions, break/continue with labeled logic).
 * - Can jump OVER variable initializations, leading to use of
 *   uninitialized variables — a common source of bugs.
 *
 * THE ONE WIDELY-ACCEPTED USE CASE:
 * - Breaking out of DEEPLY NESTED loops in one step (since `break` only
 *   exits one level). This is the classic, still-debated exception where
 *   many C codebases (including the Linux kernel) permit `goto` for
 *   centralized cleanup/error handling.
 */

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

// ─────────────────────────────────────────────────────────────────────────────
// gcc -std=c11 -Wall -Wextra -pedantic -g 13-goto-statement.c -o 13-goto-statement
// ─────────────────────────────────────────────────────────────────────────────
