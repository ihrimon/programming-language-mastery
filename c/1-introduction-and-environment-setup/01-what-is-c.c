// =============================================================================
// TOPIC 1: What is C?
// =============================================================================

/*
 * C is a general-purpose, procedural programming language.
 * Created by Dennis Ritchie at Bell Labs around 1972.
 *
 * KEY CHARACTERISTICS:
 * - Compiled language: source code → machine code (via compiler like GCC/Clang)
 * - Statically typed: every variable must have a declared type
 * - Procedural: programs are structured as functions called in sequence
 * - Low-level access: direct memory control via pointers
 * - Portable: same code compiles on different OS and hardware
 * - No garbage collector: you manage memory manually (malloc/free)
 * - Not object-oriented: no classes/objects — uses structs + functions instead
 *
 * EVERY C PROGRAM MUST HAVE:
 * - At least one function: main() — this is the entry point
 * - #include directives to use standard library functions
 *
 * FILE EXTENSIONS:
 * - Source files : .c
 * - Header files : .h
 */

// Simplest possible C program — demonstrates the basic structure
#include <stdio.h>   // standard I/O library (gives us printf, scanf, etc.)

int main(void) {
    // printf is defined in <stdio.h>
    printf("Hello, World!\n");

    return 0;   // 0 means the program ran successfully
}

/*
 * BREAKDOWN OF THE ABOVE PROGRAM:
 *
 * #include <stdio.h>  → tells the preprocessor to include the standard I/O header
 * int main(void)      → entry point; int = return type, void = no parameters
 * { ... }             → a block — groups statements together
 * printf(...)         → function call — prints text to the terminal
 * return 0;           → exit code sent back to the OS (0 = success)
 */

// ─────────────────────────────────────────────────────────────────────────────
// gcc -std=c11 -Wall -Wextra -pedantic -g 01-what-is-c.c -o 01-what-is-c
// ─────────────────────────────────────────────────────────────────────────────
