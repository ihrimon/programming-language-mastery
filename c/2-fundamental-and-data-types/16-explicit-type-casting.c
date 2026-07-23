// =============================================================================
// TOPIC 16: Explicit Type Casting (`(type)expression`)
// =============================================================================

#include <stdio.h>

/*
 * A CAST forces a conversion the programmer wants, overriding the compiler's
 * default (implicit) behavior. Syntax:  (target_type) expression
 *
 * COMMON USES:
 * - Forcing float division between two ints:      (double)a / b
 * - Truncating a float to an int (drops decimals): (int)3.99  -> 3
 * - Converting a generic void* to a specific type: (int *)ptr
 * - Silencing "implicit conversion" compiler warnings intentionally.
 *
 * CASTING NEVER "ROUNDS" — float-to-int casts TRUNCATE toward zero.
 */

void explicit_casting_example(void) {
    int a = 7, b = 2;
    printf("a / b           = %d  (integer division)\n", a / b);           // 3
    printf("(double)a / b   = %f  (cast forces float division)\n",
           (double)a / b);                                                  // 3.5

    double pi = 3.99;
    printf("(int)pi = %d  (truncates, does NOT round)\n", (int)pi);        // 3

    double negative = -3.99;
    printf("(int)-3.99 = %d  (truncates toward zero)\n", (int)negative);   // -3

    void *generic_ptr = &a;
    int *typed_ptr = (int *)generic_ptr;   // explicit cast from void* to int*
    printf("*(int*)generic_ptr = %d\n", *typed_ptr);
}

int main(void) {
    printf("\n=== Topic 16: Explicit Type Casting ===\n");
    explicit_casting_example();
    return 0;
}

// ─────────────────────────────────────────────────────────────────────────────
// gcc -std=c11 -Wall -Wextra -pedantic -g 16-explicit-type-casting.c -o 16-explicit-type-casting
// ─────────────────────────────────────────────────────────────────────────────
