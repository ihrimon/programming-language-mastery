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

#include <stdio.h>
#include <stdlib.h>     // malloc, free

// --- Example: manual memory management (why C is powerful AND dangerous) ---
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

int main(void) {
    printf("\n=== Topic 3: Why Learn C ===\n");
    memory_example();
    pointer_example();
    return 0;
}
