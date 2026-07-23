// =============================================================================
// TOPIC 4: C vs C++
// =============================================================================

#include <stdio.h>

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

void c_vs_cpp_example(void) {
    printf("See the comment table above for the full C vs C++ comparison.\n");
}

int main(void) {
    printf("\n=== Topic 4: C vs C++ ===\n");
    c_vs_cpp_example();
    return 0;
}

// ─────────────────────────────────────────────────────────────────────────────
// gcc -std=c11 -Wall -Wextra -pedantic -g 04-c-vs-cpp.c -o 04-c-vs-cpp
// ─────────────────────────────────────────────────────────────────────────────
