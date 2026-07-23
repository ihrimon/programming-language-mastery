// =============================================================================
// TOPIC 9: Limits of Types (`<limits.h>`, `<float.h>`)
// =============================================================================

#include <stdio.h>
#include <limits.h>
#include <float.h>

/*
 * <limits.h>  → defines MIN/MAX constants for INTEGER types
 * <float.h>   → defines MIN/MAX/precision constants for FLOATING-POINT types
 *
 * COMMON <limits.h> MACROS:
 *   CHAR_BIT    → number of bits in a char (almost always 8)
 *   CHAR_MIN/MAX, SCHAR_MIN/MAX, UCHAR_MAX
 *   INT_MIN, INT_MAX
 *   UINT_MAX
 *   LONG_MIN, LONG_MAX, ULONG_MAX
 *   LLONG_MIN, LLONG_MAX, ULLONG_MAX
 *
 * COMMON <float.h> MACROS:
 *   FLT_MIN, FLT_MAX, FLT_DIG   (float: min, max, decimal digits of precision)
 *   DBL_MIN, DBL_MAX, DBL_DIG   (double: same, more precision)
 */

void limits_example(void) {
    printf("CHAR_BIT  = %d\n", CHAR_BIT);
    printf("INT_MIN   = %d\n", INT_MIN);
    printf("INT_MAX   = %d\n", INT_MAX);
    printf("UINT_MAX  = %u\n", UINT_MAX);
    printf("LONG_MAX  = %ld\n", LONG_MAX);
    printf("LLONG_MAX = %lld\n", LLONG_MAX);

    printf("FLT_MIN   = %e\n", FLT_MIN);
    printf("FLT_MAX   = %e\n", FLT_MAX);
    printf("FLT_DIG   = %d (decimal digits of precision)\n", FLT_DIG);
    printf("DBL_MAX   = %e\n", DBL_MAX);
    printf("DBL_DIG   = %d (decimal digits of precision)\n", DBL_DIG);
}

int main(void) {
    printf("\n=== Topic 9: Limits of Types ===\n");
    limits_example();
    return 0;
}

// ─────────────────────────────────────────────────────────────────────────────
// gcc -std=c11 -Wall -Wextra -pedantic -g 09-limits-of-types.c -o 09-limits-of-types
// ─────────────────────────────────────────────────────────────────────────────
