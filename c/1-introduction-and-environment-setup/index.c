// =============================================================================
// 01. Introduction & Environment Setup
// =============================================================================

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


// =============================================================================
// TOPIC 2: History of C Language
// =============================================================================

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
// compile with: gcc -std=c99 index.c
long long c99_example(void) {
    int x = 10;             // C99: declare anywhere, not just top of block
    long long big = 9000000000LL;   // long long: 64-bit integer (C99+)

    for (int i = 0; i < 5; i++) {  // C99: loop variable declared inside for
        x += i;
    }

    return big + x;
}

// --- C99 feature: stdbool.h ---
#include <stdbool.h>    // gives us: bool, true, false (C99)

bool c99_bool_example(int x) {
    bool is_positive = (x > 0);    // bool type (C99)
    return is_positive;
}

// --- C99 feature: stdint.h — fixed-width integer types ---
#include <stdint.h>     // gives us: int8_t, uint32_t, int64_t, etc.

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


// =============================================================================
// TOPIC 3: Why Learn C?
// =============================================================================

/*
 * 1. FOUNDATION OF MODERN COMPUTING
 *    - Linux kernel, Windows NT core, macOS core → all written in C
 *    - Python (CPython), Ruby (Matz's Ruby Interpreter - MRI/CRuby), PHP → interpreters written in C
 *    - Understanding C = understanding what all these languages do under the hood
 *
 * 2. LOW-LEVEL MEMORY CONTROL
 *    - Direct access to memory addresses via pointers
 *    - You decide when to allocate and free memory (malloc/free)
 *    - No hidden garbage collector pausing your program
 *    - Teaches you: stack vs heap, memory leaks, buffer overflows
 *
 * 3. PERFORMANCE
 *    - C compiles directly to machine code — no VM, no interpreter overhead
 *    - Closest to hardware speed without writing assembly
 *    - Used in: databases (SQLite, PostgreSQL), video codecs (FFmpeg),
 *               game engines (Quake), web servers (Nginx)
 *
 * 4. EMBEDDED SYSTEMS & HARDWARE
 *    - Runs on microcontrollers with just a few KB of RAM
 *    - Arduino, STM32, ESP32 — all programmed in C
 *    - Access hardware registers directly via pointers
 *
 * 5. PORTABILITY
 *    - C compilers exist for virtually every CPU architecture
 *    - Same code runs on 8-bit microcontrollers to supercomputers
 *
 * 6. LEARNING PATH
 *    - After C → C++, Rust, Go, and even Python make much more sense
 *    - You stop treating memory as magic
 *
 * REAL-WORLD USE CASES:
 * ┌─────────────────────┬────────────────────────────────────┐
 * │ Domain              │ Examples                           │
 * ├─────────────────────┼────────────────────────────────────┤
 * │ Operating Systems   │ Linux kernel, Windows NT           │
 * │ Embedded / IoT      │ Arduino, STM32, ESP32 firmware     │
 * │ Databases           │ SQLite, PostgreSQL, MySQL          │
 * │ Compilers           │ GCC, Clang, CPython interpreter    │
 * │ Networking          │ OpenSSL, cURL, network drivers     │
 * │ Game Engines        │ Quake engine, id Tech              │
 * │ Audio / Video       │ FFmpeg, VLC                        │
 * │ Version Control     │ Git                                │
 * │ Web Servers         │ Nginx, Apache                      │
 * └─────────────────────┴────────────────────────────────────┘
 */

// --- Example: manual memory management (why C is powerful AND dangerous) ---
#include <stdlib.h>     // malloc, free

void memory_example(void) {
    // allocate memory for 5 integers on the HEAP
    int *arr = (int *)malloc(5 * sizeof(int));

    if (arr == NULL) {          // ALWAYS check — malloc can fail
        printf("Memory allocation failed!\n");
        return;
    }

    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;        // fill the array
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);  // prints: 0 10 20 30 40
    }
    printf("\n");

    free(arr);   // YOU must free it — C will not do this automatically
    arr = NULL;  // good practice: set to NULL after free
}

// --- Example: pointer gives direct memory access (low-level power) ---
void pointer_example(void) {
    int x = 42;
    int *p = &x;    // p holds the ADDRESS of x

    printf("Value of x   : %d\n",  x);      // 42
    printf("Address of x : %p\n",  (void*)p); // e.g. 0x7ffee4b2c
    printf("Via pointer  : %d\n",  *p);      // 42 — dereference

    *p = 100;   // change x through the pointer
    printf("x is now     : %d\n",  x);       // 100
}

// =============================================================================
// TOPIC 4: C vs C++ 
// =============================================================================
 
/*
 * ─────────────────────────────────────────────────────────────────────────────
 * C vs C++
 * ─────────────────────────────────────────────────────────────────────────────
 *
 * FEATURE              C                        C++
 * ─────────────────    ──────────────────────   ──────────────────────────────
 * Paradigm             Procedural only          Procedural + OOP + Generic
 * Classes/Objects      No                       Yes (class, struct with methods)
 * Templates            No                       Yes (generic programming)
 * Namespaces           No                       Yes
 * Exception Handling   No (use errno/setjmp)    Yes (try/catch/throw)
 * STL                  No                       Yes (vector, map, sort, etc.)
 * RAII                 No (manual free, malloc) Yes (destructors) (Rsc Acquisition Is Init)
 * Compile Speed        Faster                   Slower (more complex)
 * Runtime Overhead     Very low                 Slightly higher (virtualTables, RTTI= Runtime type info)
 * Use Case             OS, embedded, drivers    Apps, games, systems with OOP
 * File Extension       .c / .h                  .cpp / .hpp / .h
 *
 * KEY POINT:
 * - C++ is a superset of C in many ways, but not 100% compatible.
 * - C++ adds complexity; C stays minimal and predictable.
 * - For embedded/kernel work, C is preferred. 
 * - For application development, C++ offers powerful abstractions.
 */
 
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
 
// Demonstrating that math.h requires -lm flag at compile time
#include <math.h>   // sqrt, pow, sin, etc.
 
void gcc_math_example(void) {
    double result = sqrt(144.0);        // square root
    double power  = pow(2.0, 10.0);    // 2^10
 
    printf("sqrt(144) = %.1f\n", result);   // 12.0
    printf("2^10      = %.0f\n", power);    // 1024
    // compile with: gcc index.c -lm -o index
}
 
 
// =============================================================================
// TOPIC 6: Compilation Pipeline
// =============================================================================
 
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
 
 
// =============================================================================
// TOPIC 7: Compilation Flags
// =============================================================================
 
/*
 * Flags are passed to gcc/clang on the command line to control behavior.
 * Format:  gcc [flags] source.c -o output
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * OUTPUT FLAG
 * ─────────────────────────────────────────────────────────────────────────────
 *
 * -o <filename>
 *   Names the output file.
 *   Without -o, output defaults to a.out (Linux/Mac) or a.exe (Windows).
 *
 *   gcc hello.c -o hello          → output named "hello"
 *   gcc hello.c -o build/hello    → output inside build/ directory
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * WARNING FLAGS
 * ─────────────────────────────────────────────────────────────────────────────
 *
 * -Wall
 *   Enables "all" common warnings. (Not literally all — just the most useful.)
 *   Catches: unused variables, missing return, implicit function declarations, etc.
 *
 * -Wextra
 *   Enables extra warnings not covered by -Wall.
 *   Catches: unused function parameters, missing field initializers, etc.
 *
 * -pedantic  (or -Wpedantic)
 *   Enforces strict compliance with the C standard.
 *   Rejects any code that uses GCC extensions or non-standard behavior.
 *
 * -Werror
 *   Treats ALL warnings as errors — code won't compile if there are warnings.
 *   Great for maintaining clean code in production/CI environments.
 *
 * -Wshadow
 *   Warns when a local variable shadows (hides) an outer variable.
 *
 * -Wconversion
 *   Warns about implicit type conversions that may change a value.
 *
 * RECOMMENDED combination for learning:
 *   gcc -Wall -Wextra -pedantic source.c -o output
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * STANDARD FLAGS
 * ─────────────────────────────────────────────────────────────────────────────
 *
 * -std=c89   → compile as C89/ANSI C (oldest)
 * -std=c99   → compile as C99 (adds bool, stdint.h, VLAs, // comments)
 * -std=c11   → compile as C11 (adds atomics, threads, _Generic)
 * -std=c17   → compile as C17 (bug fixes over C11, no new features)
 * -std=c23   → compile as C23 (latest: nullptr, #embed, typeof)
 * -std=gnu11 → C11 + GCC extensions (default on most Linux systems)
 *
 * BEST PRACTICE: always specify the standard explicitly:
 *   gcc -std=c11 -Wall -Wextra source.c -o output
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * DEBUG FLAG
 * ─────────────────────────────────────────────────────────────────────────────
 *
 * -g
 *   Embeds debug symbols into the executable.
 *   Required for using GDB (GNU Debugger) or LLDB.
 *   Without -g, you cannot see variable names or line numbers in the debugger.
 *   The output file is larger but behavior is identical.
 *
 *   gcc -g -Wall source.c -o output   → compile with debug info
 *   gdb ./output                      → then debug it with GDB
 *
 * -g3
 *   Maximum debug info — includes macro definitions too.
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * OPTIMIZATION FLAGS
 * ─────────────────────────────────────────────────────────────────────────────
 *
 * -O0   No optimization (default). Easiest to debug. Slowest runtime.
 * -O1   Basic optimizations. Small speed gain.
 * -O2   Recommended for production. Good speed without risky optimizations.
 * -O3   Aggressive optimization. Faster but larger binary; can hide bugs.
 * -Os   Optimize for size (smallest binary). Useful for embedded systems.
 * -Og   Optimize while keeping debug info readable. Best for debugging.
 *
 * NOTE: Never use -O2/-O3 with -g at the same time for debugging —
 *       optimizations reorder/remove code, making debugger output confusing.
 *       Use -Og -g instead.
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * OTHER USEFUL FLAGS
 * ─────────────────────────────────────────────────────────────────────────────
 *
 * -I<dir>          → add directory to #include search path
 *                    gcc -I./include source.c -o output
 *
 * -L<dir>          → add directory to library search path
 * -l<name>         → link with lib<name> (e.g. -lm links math library)
 *
 * -D<MACRO>        → define a macro from the command line
 *                    gcc -DDEBUG source.c -o output
 *                    (same as writing #define DEBUG at the top of source)
 *
 * -E               → run preprocessor only, output to stdout
 * -S               → compile to assembly only (.s file)
 * -c               → compile to object file only (.o), do not link
 *
 * -v               → verbose: show all internal commands GCC runs
 * -save-temps      → keep intermediate files (.i, .s, .o)
 *
 * -fsanitize=address       → enable AddressSanitizer (detect memory errors at runtime)
 * -fsanitize=undefined     → enable UndefinedBehaviorSanitizer
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * FLAG COMBINATIONS FOR COMMON SCENARIOS
 * ─────────────────────────────────────────────────────────────────────────────
 *
 * Learning / Development:
 *   gcc -std=c11 -Wall -Wextra -pedantic -g source.c -o output
 *
 * Debugging a crash:
 *   gcc -std=c11 -Wall -Wextra -g -Og -fsanitize=address source.c -o output
 *
 * Production release:
 *   gcc -std=c11 -Wall -Wextra -O2 source.c -o output
 *
 * Embedded / size-constrained:
 *   gcc -std=c11 -Os -Wall source.c -o output
 */
 
// Demonstrating -D flag: conditional compilation using a macro defined at build time
void flags_example(void) {
#ifdef DEBUG
    // This block is only compiled when you pass -DDEBUG to gcc
    printf("[DEBUG] flags_example() called\n");
#endif
 
    int x = 10;
    int y = 20;
    printf("Sum = %d\n", x + y);
}
 
// Demonstrating -Wall catching an issue: unused variable warning
// (comment out to avoid the warning when compiling)
/*
void unused_var_example(void) {
    int forgotten = 42;   // -Wall will warn: 'forgotten' set but not used
    printf("Hello\n");
}
*/
 
 
// =============================================================================
// MAIN — run all examples
// =============================================================================
 
// NOTE: The main() at the top of this file is the real entry point.
// Replace the top main() with this one to run all topic examples:
 
/*
int main(void) {
    printf("\n=== Topic 1: What is C ===\n");
    // (no separate function — structure shown at top of file)
 
    printf("\n=== Topic 2: History Examples ===\n");
    printf("c89_example   : %d\n",   c89_example());
    printf("c99_example   : %lld\n", c99_example());
    printf("bool example  : %d\n",   c99_bool_example(5));
    c99_stdint_example();
    c11_anon_struct_example();
 
    printf("\n=== Topic 3: Why Learn C ===\n");
    memory_example();
    pointer_example();
 
    printf("\n=== Topic 4: C vs Other Languages ===\n");
    c_vs_cpp_example();
 
    printf("\n=== Topic 5: GCC Basics ===\n");
    gcc_math_example();
 
    printf("\n=== Topic 6: Pipeline (Macros) ===\n");
    pipeline_example();
 
    printf("\n=== Topic 7: Flags ===\n");
    flags_example();
 
    return 0;
}
*/
 
// ─────────────────────────────────────────────────────────────────────────────
// COMPILE COMMANDS SUMMARY
// ─────────────────────────────────────────────────────────────────────────────
//
// Basic:
//   gcc index.c -o index
//
// Recommended (development):
//   gcc -std=c11 -Wall -Wextra -pedantic -g index.c -o index
//
// With math library:
//   gcc -std=c11 -Wall -Wextra -pedantic -g index.c -lm -o index
//
// With DEBUG macro defined:
//   gcc -std=c11 -Wall -Wextra -g -DDEBUG index.c -lm -o index
//
// With AddressSanitizer (memory error detection):
//   gcc -std=c11 -Wall -Wextra -g -fsanitize=address index.c -lm -o index
//
// See preprocessor output only:
//   gcc -E index.c -o index.i
//
// See assembly output only:
//   gcc -S index.c -o index.s
//
// ─────────────────────────────────────────────────────────────────────────────