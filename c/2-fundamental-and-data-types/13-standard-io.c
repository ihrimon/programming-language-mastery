// =============================================================================
// TOPIC 13: Standard Input / Output & `<stdio.h>` Overview
// =============================================================================

#include <stdio.h>

/*
 * <stdio.h> — the Standard Input/Output header — provides:
 *
 *   printf()    → formatted output to stdout
 *   scanf()     → formatted input from stdin
 *   getchar()   → reads a single character from stdin
 *   putchar()   → writes a single character to stdout
 *   gets()      → REMOVED from the C standard (C11) — NEVER use it!
 *   fgets()     → safe alternative to gets(): reads a line with a size limit
 *   puts()      → writes a string + newline to stdout
 *
 * WHY gets() IS DANGEROUS:
 * - It has NO way to limit how many characters it reads.
 * - If input is longer than the destination buffer, it overflows memory —
 *   a classic BUFFER OVERFLOW security vulnerability.
 * - Always use fgets(buffer, sizeof(buffer), stdin) instead.
 *
 * scanf() GOTCHAS:
 * - scanf("%d", &x) leaves the trailing '\n' in the input buffer, which can
 *   interfere with a following getchar() or fgets() call.
 * - scanf("%s", ...) has the SAME overflow danger as gets() for strings —
 *   always specify a width: scanf("%19s", buffer) for a 20-byte buffer.
 */

void io_example(void) {
    // --- output ---
    printf("This goes to stdout.\n");
    putchar('A');
    putchar('\n');
    puts("puts() automatically appends a newline");

    // --- safe string input (commented out — would block waiting for input) ---
    /*
    char name[50];
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);   // SAFE: bounded read
    printf("Hello, %s", name);
    */

    // --- reading a single character (commented out — needs real stdin) ---
    /*
    printf("Press any key: ");
    int ch = getchar();
    printf("You pressed: %c\n", ch);
    */

    // --- scanf usage pattern (commented out — needs real stdin) ---
    /*
    int age;
    printf("Enter age: ");
    scanf("%d", &age);           // '&' required — scanf needs the ADDRESS
    printf("age = %d\n", age);
    */

    // NEVER do this:
    // char buffer[10];
    // gets(buffer);   // ERROR/removed in C11 — unbounded read, buffer overflow risk
}

int main(void) {
    printf("\n=== Topic 13: Standard I/O ===\n");
    io_example();
    return 0;
}

// ─────────────────────────────────────────────────────────────────────────────
// gcc -std=c11 -Wall -Wextra -pedantic -g 13-standard-io.c -o 13-standard-io
// ─────────────────────────────────────────────────────────────────────────────
