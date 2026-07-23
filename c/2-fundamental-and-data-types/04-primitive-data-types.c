// =============================================================================
// TOPIC 4: Primitive Data Types (int, char, float, double, void)
// =============================================================================

#include <stdio.h>

/*
 * C's BASIC (PRIMITIVE) TYPES:
 *
 * TYPE     TYPICAL SIZE   PURPOSE                          FORMAT SPECIFIER
 * ──────   ────────────   ──────────────────────────────   ─────────────────
 * char     1 byte         single character / small integer  %c (char) / %d (int)
 * int      4 bytes        whole numbers                     %d
 * float    4 bytes        single-precision decimal number   %f
 * double   8 bytes        double-precision decimal number   %f (or %lf in scanf)
 * void     0 bytes        "no type" — used for functions
 *                          that return nothing, or generic
 *                          pointers (void*)
 */

void primitive_types_example(void) {
    char grade = 'A';            // single character, stored as its ASCII code
    int age = 25;                // whole number
    float pi_f = 3.14f;          // 'f' suffix marks it as a float literal
    double pi_d = 3.14159265358979; // more precision than float

    printf("grade  = %c\n", grade);
    printf("age    = %d\n", age);
    printf("pi_f   = %f\n", pi_f);
    printf("pi_d   = %lf\n", pi_d);
}

void do_nothing(void) {
    // 'void' return type: this function returns no value
    return;
}

int main(void) {
    printf("\n=== Topic 4: Primitive Data Types ===\n");
    primitive_types_example();
    do_nothing();
    return 0;
}