// =============================================================================
// TOPIC 6: `_Bool` / `<stdbool.h>` (`true`, `false`)
// =============================================================================

#include <stdio.h>
#include <stdbool.h>   // gives us: bool, true, false (C99+)

/*
 * C did NOT have a native boolean type until C99.
 *
 * _Bool (C99 keyword):
 * - Built-in boolean type; can only store 0 or 1.
 * - Any non-zero value assigned to it is converted to 1.
 *
 * <stdbool.h> (C99 convenience header):
 * - Defines the macros: bool → _Bool, true → 1, false → 0
 * - Makes boolean code read naturally, like other languages.
 *
 * PRE-C99 CONVENTION:
 * - Programmers used plain `int`, where 0 = false, non-zero = true.
 *   (This still works and is common in older/portable C code.)
 *
 * C23 UPDATE:
 * - bool/true/false become actual KEYWORDS (no #include needed).
 */

void bool_example(void) {
    _Bool raw_flag = 1;              // native _Bool type
    bool is_even = (10 % 2 == 0);    // stdbool.h macro — reads naturally
    bool is_odd = false;

    printf("raw_flag = %d\n", raw_flag);
    printf("is_even  = %d (%s)\n", is_even, is_even ? "true" : "false");
    printf("is_odd   = %d (%s)\n", is_odd,  is_odd  ? "true" : "false");

    // pre-C99 style, still valid and common:
    int old_style_flag = 0;   // 0 = false
    if (!old_style_flag) {
        printf("old_style_flag is false (0)\n");
    }
}

int main(void) {
    printf("\n=== Topic 6: _Bool / stdbool.h ===\n");
    bool_example();
    return 0;
}

// ─────────────────────────────────────────────────────────────────────────────
// gcc -std=c11 -Wall -Wextra -pedantic -g 06-bool-type.c -o 06-bool-type
// ─────────────────────────────────────────────────────────────────────────────
