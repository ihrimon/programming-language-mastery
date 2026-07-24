// =============================================================================
// TOPIC 10: Escape Sequences (`\n`, `\t`, `\\`, `\"`, `\0`, `\xNN`, `\oNNN`)
// =============================================================================

/*
 * Escape sequences let you represent special/non-printable characters
 * inside a char or string literal, using a backslash (\) prefix.
 *
 *   \n    → newline
 *   \t    → horizontal tab
 *   \\    → literal backslash
 *   \'    → literal single quote
 *   \"    → literal double quote
 *   \0    → null character (value 0) — terminates C strings
 *   \a    → alert / bell sound
 *   \b    → backspace
 *   \r    → carriage return
 *   \v    → vertical tab
 *   \xNN  → character by HEX value  (e.g. \x41 = 'A')
 *   \NNN  → character by OCTAL value (e.g. \101 = 'A')
 */

#include <stdio.h>

void escape_sequences_example(void) {
    printf("Line1\nLine2\n");                 // \n newline
    printf("Col1\tCol2\tCol3\n");              // \t tab
    printf("Backslash: \\\n");                 // \\ literal backslash
    printf("Quote: \"quoted text\"\n");         // \" literal double quote
    printf("Hex A  = \x41\n");                  // \x41 → 'A' (hex 0x41 = 65)
    printf("Octal A= \101\n");                  // \101 → 'A' (octal 101 = 65)

    char str[] = "abc";     // stored in memory as: 'a' 'b' 'c' '\0'
    printf("String length via \\0 terminator: %d characters + null\n",
           (int)(sizeof(str) - 1));
}

int main(void) {
    printf("\n=== Topic 10: Escape Sequences ===\n");
    escape_sequences_example();
    return 0;
}
