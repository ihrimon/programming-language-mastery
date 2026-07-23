// =============================================================================
// TOPIC 5: Type Modifiers (signed, unsigned, short, long, long long)
// =============================================================================

#include <stdio.h>

/*
 * MODIFIERS change the SIZE and/or RANGE of a base type.
 *
 * SIGNEDNESS:
 * - signed   → can hold negative and positive values (default for int/char*)
 * - unsigned → can hold only 0 and positive values, doubling the positive range
 *
 * SIZE MODIFIERS (applied to int, and sometimes double):
 * - short         → at least 16 bits            (short int)
 * - long          → at least 32 bits            (long int)
 * - long long     → at least 64 bits (C99+)     (long long int)
 * - long double   → extended precision floating point
 *
 * TYPICAL SIZES ON A 64-BIT SYSTEM (LP64 model — Linux/Mac):
 *   short int       → 2 bytes   (-32,768 to 32,767)
 *   int             → 4 bytes   (-2,147,483,648 to 2,147,483,647)
 *   long int        → 8 bytes   (Linux/Mac) or 4 bytes (Windows, LLP64 model!)
 *   long long int   → 8 bytes
 *   unsigned int    → 4 bytes   (0 to 4,294,967,295)
 *
 * *char* IS SPECIAL: whether plain `char` is signed or unsigned by default
 * is IMPLEMENTATION-DEFINED — always use `signed char` / `unsigned char`
 * explicitly if the sign matters.
 */

void type_modifiers_example(void) {
    signed int a = -10;             // explicit signed (same as plain 'int')
    unsigned int b = 10;            // only non-negative values
    short int c = 32000;            // small range, saves memory
    long int d = 2000000000L;       // 'L' suffix marks a long literal
    long long int e = 9000000000LL; // 'LL' suffix marks a long long literal
    unsigned long long f = 18000000000ULL; // 'ULL' = unsigned long long

    printf("signed a   = %d\n", a);
    printf("unsigned b = %u\n", b);
    printf("short c    = %hd\n", c);
    printf("long d     = %ld\n", d);
    printf("long long e= %lld\n", e);
    printf("unsigned long long f = %llu\n", f);

    // DANGER: assigning a negative value to unsigned wraps around!
    unsigned int wrapped = -1;
    printf("unsigned(-1) wraps to = %u  (max unsigned int value)\n", wrapped);
}

int main(void) {
    printf("\n=== Topic 5: Type Modifiers ===\n");
    type_modifiers_example();
    return 0;
}

