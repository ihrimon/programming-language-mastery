// =============================================================================
// TOPIC 15: Implicit Type Conversion (Integer Promotion, Usual Arithmetic Conversions)
// =============================================================================

/*
 * The compiler AUTOMATICALLY converts operand types in certain situations.
 *
 * INTEGER PROMOTION:
 * - Any type "smaller" than int (char, short) is promoted to int (or unsigned
 *   int) before being used in an arithmetic expression.
 *
 * USUAL ARITHMETIC CONVERSIONS (for binary operators with mixed types):
 * - If one operand is double, the other converts to double.
 * - Else if one is float, the other converts to float.
 *   (int + float -> the int is converted to float, result is float)
 * - Else, integer promotions apply, then the "smaller rank" integer type
 *   converts up to match the "larger rank" type (e.g. int + long -> long).
 * - signed/unsigned of the SAME rank: the signed operand converts to unsigned
 */

#include <stdio.h>

void implicit_conversion_example(void) {
    char c = 'A';         // promoted to int during arithmetic below
    int result = c + 1;   // 'A' (65) promoted to int, + 1 -> 66

    int i = 5;
    double d = 2.0;
    double sum = i + d;   // i converted to double -> 5.0 + 2.0 = 7.0

    int signed_val = -1;
    unsigned int unsigned_val = 1;
    // signed_val is converted to unsigned -> huge positive number!
}

int main(void) {
    printf("\n=== Topic 15: Implicit Type Conversion ===\n");
    implicit_conversion_example();
    return 0;
}
