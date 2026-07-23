// =============================================================================
// TOPIC 2: History of C Language
// =============================================================================

#include <stdio.h>
#include <stdbool.h>    // gives us: bool, true, false (C99)
#include <stdint.h>     // gives us: int8_t, uint32_t, int64_t, etc.

/*
 * TIMELINE:
 *
 * 1967 — Basic Combined Programming Language (BCPL) (Martin Richards, Bell Labs)
 *         Typeless language. Inspired B.
 *
 * 1969 — B Language (Ken Thompson, Bell Labs)
 *         Simplified BCPL. Used for early Unix utilities.
 *         Still typeless — no int, char, float distinction.
 *
 * 1972 — C Language (Dennis Ritchie, Bell Labs)
 *         Added data types, structs, improved syntax.
 *         Unix OS was rewritten in C — proving C's power.
 *
 * 1978 — K&R C
 *         Kernighan & Ritchie published "The C Programming Language".
 *         This book became the informal standard for years.
 *
 * 1989 — C89 / American National Standards Institute (ANSI) C (also called C90)
 *         First official standardized version by ANSI.
 *         Baseline that all compilers still support.
 *
 * 1999 — C99
 *         Added: // comments, <stdint.h>, <stdbool.h>,
 *                Variable-Length Arrays (VLAs), designated initializers, inline, long long
 *
 * 2011 — C11
 *         Added: _Generic, _Static_assert, anonymous structs/unions,
 *                atomics (<stdatomic.h>), threads (<threads.h>)
 *
 * 2017 — C17 (C18)
 *         Bug-fix release only. No new features.
 *
 * 2023 — C23
 *         Added: nullptr, #embed, typeof, bool/true/false as keywords,
 *                [[nodiscard]] attribute, 0b binary literals
 */

// --- C89 style: old-school declarations at top of block ---
int c89_example(void) {
    int x;          /* C89: must declare variables at the TOP of a block */
    int y;
    x = 10;
    y = 20;
    return x + y;
}

// --- C99 feature: declare variable anywhere, // comments, long long ---
// compile with: gcc -std=c99 02-history-of-c.c
long long c99_example(void) {
    int x = 10;             // C99: declare anywhere, not just top of block
    long long big = 9000000000LL;   // long long: 64-bit integer (C99+)

    for (int i = 0; i < 5; i++) {  // C99: loop variable declared inside for
        x += i;
    }

    return big + x;
}

// --- C99 feature: stdbool.h ---
bool c99_bool_example(int x) {
    bool is_positive = (x > 0);    // bool type (C99)
    return is_positive;
}

// --- C99 feature: stdint.h — fixed-width integer types ---
void c99_stdint_example(void) {
    int8_t   a = 127;           // exactly 8-bit signed
    uint8_t  b = 255;           // exactly 8-bit unsigned
    int32_t  c = 2147483647;    // exactly 32-bit signed
    uint64_t d = 18446744073709551615ULL; // exactly 64-bit unsigned

    printf("int8: %d, uint8: %u, int32: %d\n", a, b, c);
    printf("uint64: %llu\n", d);
}

// --- C11 feature: _Static_assert (compile-time check) ---
_Static_assert(sizeof(int) >= 2, "int must be at least 2 bytes");

// --- C11 feature: anonymous struct inside union ---
typedef struct {
    union {
        struct { int x; int y; };   // anonymous struct (C11) — access as .x .y directly
        int coords[2];
    };
} Point;

void c11_anon_struct_example(void) {
    Point p;
    p.x = 10;           // access directly — no inner struct name needed
    p.y = 20;
    printf("Point: %d, %d\n", p.coords[0], p.coords[1]);
}

int main(void) {
    printf("\n=== Topic 2: History Examples ===\n");
    printf("c89_example   : %d\n",   c89_example());
    printf("c99_example   : %lld\n", c99_example());
    printf("bool example  : %d\n",   c99_bool_example(5));
    c99_stdint_example();
    c11_anon_struct_example();
    return 0;
}

// ─────────────────────────────────────────────────────────────────────────────
// gcc -std=c11 -Wall -Wextra -pedantic -g 02-history-of-c.c -o 02-history-of-c
// ─────────────────────────────────────────────────────────────────────────────
