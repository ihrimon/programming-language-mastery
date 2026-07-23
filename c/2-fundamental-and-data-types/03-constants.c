// =============================================================================
// TOPIC 3: Constants (`const`, `#define` literals)
// =============================================================================

/*
 * TWO WAYS TO DEFINE CONSTANTS IN C:
 *
 * 1) #define (preprocessor macro)
 *    - Simple text substitution done BEFORE compilation (Stage 1: Preprocessing)
 *    - No type, no memory address, no scope (visible everywhere after definition)
 *    - Cannot be debugged as a "variable" in GDB (it doesn't exist at runtime)
 *
 *      #define PI 3.14159
 *      #define MAX_USERS 100
 *
 * 2) const keyword
 *    - A real, typed variable whose value cannot be changed after initialization
 *    - Has a memory address, respects scope, is type-checked by the compiler
 *    - Preferred in modern C for most cases (safer, debuggable)
 *
 *      const double PI = 3.14159;
 *      const int MAX_USERS = 100;
 *
 * WHEN TO USE WHICH:
 * - #define  → simple numeric/text constants, conditional compilation, header guards
 * - const    → typed constants, especially inside functions or for array sizes
 *
 * NOTE: A const variable is NOT a compile-time constant expression in standard C
 *       (unlike C++). You cannot always use it for array sizes in strict C89/C99
 *       without VLA (Variable Length Array) support, though most compilers allow it as an extension.
 */

#include <stdio.h>
#define MAX_STUDENTS 50          // object-like macro — pure text substitution
#define GREETING "Hello, C!"     // string literal macro

void constants_example(void) {
    const double PI = 3.14159;   // typed constant — cannot be reassigned
    const int MAX_ATTEMPTS = 3;

    printf("MAX_STUDENTS = %d\n", MAX_STUDENTS);   // expands to: 50
    printf("%s\n", GREETING);                       // expands to the string
    printf("PI = %.5f, MAX_ATTEMPTS = %d\n", PI, MAX_ATTEMPTS);
}

int main(void) {
    printf("\n=== Topic 3: Constants ===\n");
    constants_example();
    return 0;
}
