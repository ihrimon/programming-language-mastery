// =============================================================================
// TOPIC 11: `break` Statement
// =============================================================================

/*
 * `break` immediately exits the INNERMOST enclosing loop (for/while/do-while)
 * or `switch` statement — execution resumes at the first line AFTER it.
 *
 * IMPORTANT: in nested loops, `break` only exits ONE level (the innermost
 * loop it is directly inside) — NOT all enclosing loops.
 */

#include <stdio.h>

void break_example(void) {
    // stop a loop early once a condition is met
    for (int i = 0; i < 10; i++) {
        if (i == 5) {
            break;   // exits the loop entirely — i never reaches 6..9
        }
        printf("i = %d\n", i);
    }

    // linear search: stop as soon as the target is found
    int arr[] = {4, 8, 15, 16, 23, 42};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 16, found_index = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            found_index = i;
            break;   // no need to keep scanning once found
        }
    }
    printf("target %d found at index %d\n", target, found_index);

    // break only exits the INNERMOST loop, not both
    printf("nested break demo:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 1) {
                break;   // only breaks the inner (j) loop
            }
            printf("i=%d j=%d\n", i, j);
        }
    }
}

int main(void) {
    printf("\n=== Topic 11: break Statement ===\n");
    break_example();
    return 0;
}