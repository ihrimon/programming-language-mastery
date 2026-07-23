// =============================================================================
// TOPIC 7: Size of Types (`sizeof` operator, platform differences)
// =============================================================================

#include <stdio.h>

/*
 * sizeof is a COMPILE-TIME operator (not a function) that returns the size,
 * in bytes, of a type or variable. Its result type is `size_t` (unsigned).
 *
 * SYNTAX:
 *   sizeof(type)        e.g. sizeof(int)
 *   sizeof expression    e.g. sizeof x        (parentheses optional for variables)
 *
 * WHY SIZES VARY BY PLATFORM:
 * - The C standard only guarantees MINIMUM sizes/ranges, not exact ones.
 * - Data models differ by OS/compiler:
 *     ILP32 (32-bit systems)      : int=4, long=4,  pointer=4
 *     LP64  (Linux/Mac 64-bit)    : int=4, long=8,  pointer=8
 *     LLP64 (Windows 64-bit)      : int=4, long=4,  pointer=8  <-- long differs!
 * - This is why portable code should prefer <stdint.h> fixed-width types
 *   (see 08-fixed-width-integers.c) when an EXACT size matters (e.g. binary
 *   file formats, networking).
 */

void sizeof_example(void) {
    printf("sizeof(char)        = %zu byte\n",  sizeof(char));
    printf("sizeof(short)       = %zu bytes\n", sizeof(short));
    printf("sizeof(int)         = %zu bytes\n", sizeof(int));
    printf("sizeof(long)        = %zu bytes\n", sizeof(long));
    printf("sizeof(long long)   = %zu bytes\n", sizeof(long long));
    printf("sizeof(float)       = %zu bytes\n", sizeof(float));
    printf("sizeof(double)      = %zu bytes\n", sizeof(double));
    printf("sizeof(long double) = %zu bytes\n", sizeof(long double));
    printf("sizeof(void*)       = %zu bytes\n", sizeof(void *));

    int arr[10];
    printf("sizeof(arr) (10 ints) = %zu bytes\n", sizeof(arr));       // whole array
    printf("sizeof(arr)/sizeof(arr[0]) = %zu elements\n",
           sizeof(arr) / sizeof(arr[0]));   // common "array length" idiom
}

int main(void) {
    printf("\n=== Topic 7: sizeof Operator ===\n");
    sizeof_example();
    return 0;
}

// ─────────────────────────────────────────────────────────────────────────────
// gcc -std=c11 -Wall -Wextra -pedantic -g 07-sizeof-operator.c -o 07-sizeof-operator
// ─────────────────────────────────────────────────────────────────────────────
