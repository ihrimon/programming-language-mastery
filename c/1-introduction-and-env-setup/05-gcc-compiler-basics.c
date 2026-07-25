// =============================================================================
// TOPIC 5: GCC Compiler Basics
// =============================================================================

/*
 * GCC = GNU Compiler Collection
 * Clang = LLVM-based compiler (alternative to GCC, same flags mostly)
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * BASIC USAGE
 * ─────────────────────────────────────────────────────────────────────────────
 *
 * gcc source.c                    → compile, output file named "a.out" (Linux/Mac)
 *                                   or "a.exe" (Windows)
 *
 * gcc source.c -o output          → compile, name the output "output"
 *
 * gcc file1.c file2.c -o program  → compile multiple source files together
 *
 * clang source.c -o output        → same as gcc, using Clang compiler
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * CHECKING COMPILER VERSION
 * ─────────────────────────────────────────────────────────────────────────────
 *
 * gcc --version                   → shows GCC version installed
 * clang --version                 → shows Clang version installed
 * gcc -v source.c                 → verbose output — shows every internal step
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * COMMON WORKFLOW
 * ─────────────────────────────────────────────────────────────────────────────
 *
 * Step 1 — Write code:     nano hello.c   (or VS Code)
 * Step 2 — Compile:        gcc hello.c -o hello
 * Step 3 — Run:            ./hello         (Linux/Mac)
 *                          hello.exe       (Windows)
 * Step 4 — Check errors:   read the terminal output carefully
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * COMPILING TO OBJECT FILE ONLY (no linking yet)
 * ─────────────────────────────────────────────────────────────────────────────
 *
 * gcc -c source.c             → produces source.o (object file)
 * gcc source.o -o program     → link the object file into an executable
 *
 * This is useful in large projects where you compile files separately.
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * LINKING EXTERNAL LIBRARIES
 * ─────────────────────────────────────────────────────────────────────────────
 *
 * gcc source.c -lm -o program     → link with math library (libm)
 *                                   needed for sin(), cos(), sqrt(), etc.
 *
 * gcc source.c -lpthread -o prog  → link with POSIX threads library
 *
 * -l<name> tells the linker to include lib<name>.a or lib<name>.so
 */
 
#include <stdio.h>
#include <math.h>   // sqrt, pow, sin, etc.

// Demonstrating that math.h requires -lm flag at compile time
void gcc_math_example(void) {
    double result = sqrt(144.0);        // square root
    double power  = pow(2.0, 10.0);    // 2^10

    printf("sqrt(144) = %.1f\n", result);   // 12.0
    printf("2^10      = %.0f\n", power);    // 1024
    // compile with: gcc 05-gcc-compiler-basics.c -lm -o 05-gcc-compiler-basics
}

int main(void) {
    printf("\n=== Topic 5: GCC Basics ===\n");
    gcc_math_example();
    return 0;
}

// ─────────────────────────────────────────────────────────────────────────────
// gcc -std=c11 -Wall -Wextra -pedantic -g 05-gcc-compiler-basics.c -lm -o 05-gcc-compiler-basics
// ─────────────────────────────────────────────────────────────────────────────
