// =============================================================================
// TOPIC 6: Compilation Pipeline
// =============================================================================

#include <stdio.h>

/*
 * When you run:  gcc hello.c -o hello
 * GCC internally runs 4 stages in sequence:
 *
 * ┌──────────┐    ┌──────────┐    ┌──────────────┐    ┌──────────┐
 * │  Source  │    │Preprocessed│  │  Assembly    │    │  Object  │
 * │  hello.c │ →  │  hello.i  │ → │  hello.s     │ →  │  hello.o │ → hello (exe)
 * └──────────┘    └──────────┘    └──────────────┘    └──────────┘
 *  (your code)   (macros        (human-readable      (machine code,
 *                 expanded)      assembly text)       not yet linked)
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * STAGE 1: PREPROCESSING  (gcc -E)
 * ─────────────────────────────────────────────────────────────────────────────
 * Tool    : cpp (C PreProcessor) — runs automatically inside gcc
 * Input   : hello.c
 * Output  : hello.i  (preprocessed C source)
 *
 * What it does:
 * - Expands all #include directives (copies the header file content in)
 * - Expands all #define macros
 * - Handles #ifdef / #ifndef conditional blocks
 * - Strips out all comments
 * - Result is pure C code — no macros, no #include, no comments
 *
 * Command to see preprocessor output:
 *   gcc -E hello.c -o hello.i
 *
 * Example:
 *   #define MAX 100       →  the preprocessor replaces MAX with 100 everywhere
 *   #include <stdio.h>    →  the entire stdio.h file is pasted in here
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * STAGE 2: COMPILATION  (gcc -S)
 * ─────────────────────────────────────────────────────────────────────────────
 * Tool    : cc1 (internal GCC compiler)
 * Input   : hello.i
 * Output  : hello.s  (assembly code)
 *
 * What it does:
 * - Parses the C code (syntax analysis)
 * - Checks types, scopes, and semantics (semantic analysis)
 * - Optimizes the code (if -O flags are used)
 * - Translates C into assembly language for the target CPU (x86, ARM, etc.)
 *
 * Command to see assembly output:
 *   gcc -S hello.c -o hello.s
 *
 * The .s file is human-readable assembly text like:
 *   movl  $42, %eax
 *   call  printf
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * STAGE 3: ASSEMBLING  (gcc -c)
 * ─────────────────────────────────────────────────────────────────────────────
 * Tool    : as (GNU Assembler)
 * Input   : hello.s
 * Output  : hello.o  (object file — binary machine code)
 *
 * What it does:
 * - Converts assembly text instructions into binary machine code (1s and 0s)
 * - The .o file is NOT yet a runnable program
 * - Function calls to external libraries (like printf) are left as
 *   "unresolved references" — the linker will fix them
 *
 * Command:
 *   gcc -c hello.c -o hello.o
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * STAGE 4: LINKING
 * ─────────────────────────────────────────────────────────────────────────────
 * Tool    : ld (GNU Linker)
 * Input   : hello.o + library object files (libc.a, libm.a, etc.)
 * Output  : hello  (final executable)
 *
 * What it does:
 * - Combines your .o file(s) with library code
 * - Resolves all "unresolved references"
 *   (e.g. your call to printf → linked to printf in libc)
 * - Sets up the program's memory layout
 * - Produces the final runnable executable
 *
 * Command (full compile + link in one step):
 *   gcc hello.o -o hello
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * SEEING ALL 4 STAGES MANUALLY
 * ─────────────────────────────────────────────────────────────────────────────
 *
 *   gcc -E  hello.c -o hello.i     # Stage 1: preprocess only
 *   gcc -S  hello.i -o hello.s     # Stage 2: compile to assembly
 *   gcc -c  hello.s -o hello.o     # Stage 3: assemble to object file
 *   gcc     hello.o -o hello       # Stage 4: link to executable
 *
 * Or all at once (most common):
 *   gcc hello.c -o hello
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * STATIC vs DYNAMIC LINKING
 * ─────────────────────────────────────────────────────────────────────────────
 *
 * Dynamic linking (default):
 *   - Library code (.so / .dll) is loaded at runtime
 *   - Executable is smaller
 *   - Requires the library to be installed on the target machine
 *
 * Static linking:
 *   - Library code is copied INTO your executable at link time
 *   - Executable is larger but self-contained
 *   - gcc hello.c -static -o hello
 */

// Demonstrating preprocessor macro expansion (Stage 1)
#define SQUARE(x)   ((x) * (x))     // function-like macro
#define PI          3.14159265       // object-like macro

void pipeline_example(void) {
    int side = 5;
    // At compile time, SQUARE(side) becomes ((side) * (side))
    // PI becomes 3.14159265
    printf("Square of %d = %d\n",  side, SQUARE(side));   // 25
    printf("PI = %.5f\n", PI);                             // 3.14159
    printf("Circle area (r=3) = %.2f\n", PI * SQUARE(3)); // 28.27
}

int main(void) {
    printf("\n=== Topic 6: Pipeline (Macros) ===\n");
    pipeline_example();
    return 0;
}

// ─────────────────────────────────────────────────────────────────────────────
// gcc -std=c11 -Wall -Wextra -pedantic -g 06-compilation-pipeline.c -o 06-compilation-pipeline
//
// See preprocessor output only:
//   gcc -E 06-compilation-pipeline.c -o 06-compilation-pipeline.i
//
// See assembly output only:
//   gcc -S 06-compilation-pipeline.c -o 06-compilation-pipeline.s
// ─────────────────────────────────────────────────────────────────────────────
