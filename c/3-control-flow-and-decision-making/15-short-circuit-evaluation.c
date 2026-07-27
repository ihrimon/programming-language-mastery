// =============================================================================
// TOPIC 15: Short-Circuit Evaluation (`&&`, `||`)
// =============================================================================

#include <stdio.h>

/*
 * `&&` and `||` do NOT always evaluate both operands — they "short-circuit":
 * evaluation stops as soon as the overall result is already determined.
 *
 *   expr1 && expr2   → if expr1 is FALSE (0), the result is already false —
 *                      expr2 is NEVER evaluated.
 *   expr1 || expr2   → if expr1 is TRUE (non-zero), the result is already
 *                      true — expr2 is NEVER evaluated.
 *
 * THIS IS PART OF THE C STANDARD (not an optimization detail) — code can
 * rely on it. The most common practical use is GUARDING an unsafe operation:
 *
 *   if (ptr != NULL && ptr->value > 0) { ... }
 *   //     ^ if ptr IS NULL, ptr->value is never touched — no crash.
 *
 * ORDER MATTERS: put the "safety check" condition FIRST.
 */

// helper that reports whether it was called, to prove short-circuiting happens
int side_effect(const char *label, int return_value) {
    printf("  side_effect(%s) was CALLED\n", label);
    return return_value;
}

void short_circuit_example(void) {
    printf("false && side_effect(...):\n");
    if (0 && side_effect("B", 1)) {   // side_effect("B", ...) is never called
        printf("unreachable\n");
    }

    printf("true || side_effect(...):\n");
    if (1 || side_effect("D", 1)) {   // side_effect("D", ...) is never called
        printf("short-circuited to true\n");
    }

    // the classic NULL-guard pattern — safe because of short-circuiting
    int *ptr = NULL;
    if (ptr != NULL && *ptr > 0) {
        printf("unreachable — ptr is NULL, so *ptr is never dereferenced\n");
    } else {
        printf("guarded safely: ptr was NULL, *ptr never evaluated\n");
    }

    // guarding array access with a bounds check first
    int arr[] = {10, 20, 30};
    int size = 3, index = 5;
    if (index < size && arr[index] > 0) {
        printf("unreachable — index out of bounds\n");
    } else {
        printf("guarded safely: index %d was out of bounds, arr[%d] never read\n",
               index, index);
    }
}

int main(void) {
    printf("\n=== Topic 15: Short-Circuit Evaluation ===\n");
    short_circuit_example();
    return 0;
}

// ─────────────────────────────────────────────────────────────────────────────
// gcc -std=c11 -Wall -Wextra -pedantic -g 15-short-circuit-evaluation.c -o 15-short-circuit-evaluation
// ─────────────────────────────────────────────────────────────────────────────
