// =============================================================================
// TOPIC 17: Integer Overflow & Undefined Behavior
// =============================================================================

#include <stdio.h>
#include <limits.h>

/*
 * INTEGER OVERFLOW happens when an arithmetic result exceeds the range that
 * a type can represent.
 *
 * UNSIGNED overflow:
 * - Well-defined by the C standard: it WRAPS AROUND (modulo 2^n).
 * - UINT_MAX + 1 == 0.  This is NOT undefined behavior.
 *
 * SIGNED overflow:
 * - UNDEFINED BEHAVIOR (UB) per the C standard!
 * - The compiler is allowed to do ANYTHING: wrap around, trap/crash,
 *   or "optimize away" code that depends on the overflow — it is NOT
 *   guaranteed to simply wrap like unsigned does, even though it often
 *   appears to on common platforms.
 * - Never rely on signed overflow behavior. Check bounds BEFORE the
 *   operation if overflow is possible.
 *
 * SAFE OVERFLOW CHECK EXAMPLE (before adding two ints):
 *   if (a > 0 && b > INT_MAX - a) { // would overflow  }
 */

void overflow_example(void) {
    unsigned int u = UINT_MAX;
    printf("UINT_MAX       = %u\n", u);
    printf("UINT_MAX + 1   = %u  (well-defined wrap-around to 0)\n", u + 1);

    int s = INT_MAX;
    printf("INT_MAX        = %d\n", s);
    printf("INT_MAX + 1    = %d  (UNDEFINED BEHAVIOR — result not guaranteed!)\n",
           s + 1);   // in practice often wraps to INT_MIN, but NOT guaranteed

    // Safe pattern: check BEFORE the operation
    int a = INT_MAX, b = 1;
    if (a > 0 && b > INT_MAX - a) {
        printf("Addition would overflow — skipping unsafe operation.\n");
    }
}

int main(void) {
    printf("\n=== Topic 17: Integer Overflow & UB ===\n");
    overflow_example();
    return 0;
}

// ─────────────────────────────────────────────────────────────────────────────
// gcc -std=c11 -Wall -Wextra -pedantic -g 17-integer-overflow-and-ub.c -o 17-integer-overflow-and-ub
// ─────────────────────────────────────────────────────────────────────────────
