// =============================================================================
// TOPIC 12: Format Specifiers (`%d`, `%f`, `%c`, `%s`, `%p`, `%x`, `%u`, `%ld`, etc.)
// =============================================================================

#include <stdio.h>

/*
 * Format specifiers tell printf/scanf HOW to interpret arguments.
 *
 *   %d / %i   → signed int
 *   %u        → unsigned int
 *   %f        → float / double (printf always promotes float to double)
 *   %lf       → double            (required by scanf; printf accepts %f for both)
 *   %c        → single character
 *   %s        → string (char*)
 *   %p        → pointer address
 *   %x  / %X  → unsigned int in hexadecimal (lower/upper case letters)
 *   %o        → unsigned int in octal
 *   %e  / %E  → scientific notation
 *   %%        → literal percent sign
 *
 * LENGTH MODIFIERS (combine with the above, e.g. %ld, %lld, %hu):
 *   h   → short           (e.g. %hd = short int)
 *   l   → long             (e.g. %ld = long int, %lu = unsigned long)
 *   ll  → long long        (e.g. %lld = long long int)
 *   z   → size_t            (e.g. %zu = size_t, from sizeof)
 *
 * WIDTH & PRECISION:
 *   %5d      → pad to at least 5 characters wide
 *   %-5d     → left-align within 5 characters
 *   %05d     → zero-pad to 5 characters
 *   %.2f     → 2 digits after the decimal point
 *   %8.2f    → 8 wide total, 2 after decimal
 */

void format_specifiers_example(void) {
    int i = -42;
    unsigned int u = 42;
    double d = 3.14159;
    char c = 'X';
    char *s = "hello";
    int *ptr = &i;

    printf("%%d  -> %d\n", i);
    printf("%%u  -> %u\n", u);
    printf("%%f  -> %f\n", d);
    printf("%%.2f-> %.2f\n", d);
    printf("%%c  -> %c\n", c);
    printf("%%s  -> %s\n", s);
    printf("%%p  -> %p\n", (void *)ptr);
    printf("%%x  -> %x  (hex)\n", 255);
    printf("%%o  -> %o  (octal)\n", 8);
    printf("%%5d -> [%5d]  (width padding)\n", 7);
    printf("%%-5d-> [%-5d]  (left-aligned)\n", 7);
    printf("%%05d-> [%05d]  (zero-padded)\n", 7);
    printf("%%%%  -> %%\n");   // literal percent sign
}

int main(void) {
    printf("\n=== Topic 12: Format Specifiers ===\n");
    format_specifiers_example();
    return 0;
}

// ─────────────────────────────────────────────────────────────────────────────
// gcc -std=c11 -Wall -Wextra -pedantic -g 12-format-specifiers.c -o 12-format-specifiers
// ─────────────────────────────────────────────────────────────────────────────
