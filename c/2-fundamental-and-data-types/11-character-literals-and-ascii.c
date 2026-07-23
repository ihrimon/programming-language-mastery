// =============================================================================
// TOPIC 11: Character Literals and ASCII Table
// =============================================================================

#include <stdio.h>

/*
 * A character literal is a single character in single quotes: 'A', '7', '\n'
 * Internally, a char is just a small INTEGER — its value is the character's
 * position in the ASCII table (0-127 standard, up to 255 for extended ASCII).
 *
 * KEY ASCII RANGES:
 *   0 - 31    → control characters (non-printable: newline, tab, escape, etc.)
 *   32        → space
 *   48 - 57   → '0' to '9'   (digits)
 *   65 - 90   → 'A' to 'Z'   (uppercase letters)
 *   97 - 122  → 'a' to 'z'   (lowercase letters)
 *
 * USEFUL TRICKS (because char is really an int):
 *   'a' - 'A' == 32          → the case-difference offset
 *   digit_char - '0'         → converts a digit character to its numeric value
 *   toupper(c) == c - 32     → manual uppercase (for 'a'-'z' only; prefer <ctype.h>)
 */

void ascii_example(void) {
    char letter = 'A';
    printf("'A' as character = %c, as ASCII value = %d\n", letter, letter);

    char digit = '7';
    int numeric_value = digit - '0';    // classic char-to-int trick
    printf("'7' - '0' = %d (converts char digit to int)\n", numeric_value);

    char lower = 'a' + ('Z' - 'A');     // arithmetic on chars works like ints
    printf("'a' + ('Z'-'A') = %c\n", lower);

    // print a small ASCII table
    for (char c = 'A'; c <= 'E'; c++) {
        printf("char '%c' -> ASCII %d\n", c, c);
    }
}

int main(void) {
    printf("\n=== Topic 11: Character Literals & ASCII ===\n");
    ascii_example();
    return 0;
}

// ─────────────────────────────────────────────────────────────────────────────
// gcc -std=c11 -Wall -Wextra -pedantic -g 11-character-literals-and-ascii.c -o 11-character-literals-and-ascii
// ─────────────────────────────────────────────────────────────────────────────
