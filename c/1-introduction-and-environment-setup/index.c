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

