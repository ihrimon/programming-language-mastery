// =============================================================================
// TOPIC 10: Nested Loops
// =============================================================================

/*
 * A "nested loop" is a loop placed inside the body of another loop.
 * For each single iteration of the OUTER loop, the INNER loop runs to
 * completion. Total iterations = outer_count * inner_count.
 *
 * Any combination of for/while/do-while can be nested inside each other.
 * Common uses: 2D grids/matrices, multiplication tables, pattern printing.
 */

#include <stdio.h>

void nested_loops_example(void) {
    // basic outer/inner iteration count demo
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 2; j++) {
            printf("i=%d j=%d\n", i, j);
        }
    }

    // multiplication table (2D grid)
    printf("\nMultiplication table (1-5):\n");
    for (int row = 1; row <= 5; row++) {
        for (int col = 1; col <= 5; col++) {
            printf("%4d", row * col);
        }
        printf("\n");
    }

    // simple triangle pattern
    printf("\nTriangle pattern:\n");
    int rows = 5;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main(void) {
    printf("\n=== Topic 10: Nested Loops ===\n");
    nested_loops_example();
    return 0;
}