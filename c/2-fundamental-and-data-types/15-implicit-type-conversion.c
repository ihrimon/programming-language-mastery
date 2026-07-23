// =============================================================================
// TOPIC 15: Implicit Type Conversion (Integer Promotion, Usual Arithmetic Conversions)
// =============================================================================

#include <stdio.h>

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
 *   (this is a common source of subtle bugs — see 05-type-modifiers.c's
 *   wrap-around demo).
 */

void implicit_conversion_example(void) {
    char c = 'A';         // promoted to int during arithmetic below
    int result = c + 1;   // 'A' (65) promoted to int, + 1 -> 66
    printf("'A' + 1 = %d (implicit char -> int promotion)\n", result);

    int i = 5;
    double d = 2.0;
    double sum = i + d;   // i converted to double -> 5.0 + 2.0 = 7.0
    printf("int(5) + double(2.0) = %f (int promoted to double)\n", sum);

    int signed_val = -1;
    unsigned int unsigned_val = 1;
    // signed_val is converted to unsigned -> huge positive number!
    printf("-1 + 1u comparison: (-1 > 1u) is %d (surprising but correct)\n",
           signed_val > unsigned_val);
}

int main(void) {
    printf("\n=== Topic 15: Implicit Type Conversion ===\n");
    implicit_conversion_example();
    return 0;
}

// ─────────────────────────────────────────────────────────────────────────────
// gcc -std=c11 -Wall -Wextra -pedantic -g 15-implicit-type-conversion.c -o 15-implicit-type-conversion
// ─────────────────────────────────────────────────────────────────────────────
