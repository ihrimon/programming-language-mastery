// =============================================================================
// TOPIC 1: Keywords & Identifiers
// =============================================================================

#include <stdio.h>

/*
 * KEYWORDS:
 * - Reserved words that have special meaning to the compiler.
 * - Cannot be used as variable/function/identifier names.
 * - C89 has 32 keywords. C99 added: inline, restrict, _Bool, _Complex, _Imaginary
 * - C11 added: _Alignas, _Alignof, _Atomic, _Generic, _Noreturn, _Static_assert, _Thread_local
 *
 * COMMON KEYWORDS:
 *   auto     break    case     char     const    continue  default   do
 *   double   else     enum     extern   float    for       goto      if
 *   int      long     register return   short    signed    sizeof    static
 *   struct   switch   typedef  union    unsigned void       volatile  while
 *
 * IDENTIFIERS (naming rules):
 * - Can contain letters, digits, underscore ( _ )
 * - MUST start with a letter or underscore — (never a digit)
 * - Case-sensitive: "value" and "Value" are different identifiers
 * - Cannot be a keyword (e.g. "int" is illegal as a variable name)
 * - No spaces or special characters (@, #, $, %, etc.)
 *
 * NAMING CONVENTIONS (style, not enforced by compiler):
 * - snake_case      → variables/functions in C (most common: total_count)
 * - UPPER_CASE      → macros and constants (MAX_SIZE)
 * - PascalCase      → sometimes used for typedef'd struct/type names (Point)
 */

// --- valid identifiers ---
int total_count = 0;      // snake_case — conventional for C variables
int _hiddenValue = 5;     // starts with underscore — valid but unconventional
int counter2 = 10;        // digit allowed, just not as the first character

// --- invalid identifiers ---
// int 2counter;     // ERROR: cannot start with a digit
// int int;          // ERROR: "int" is a reserved keyword
// int my-value;     // ERROR: hyphen is not allowed in identifiers
// int my value;     // ERROR: spaces are not allowed

void keywords_identifiers_example(void) {
    int student_age = 20;   // good identifier: descriptive, snake_case
    const int MAX_MARKS = 100; // constant-style naming in UPPER_CASE
    printf("student_age = %d, MAX_MARKS = %d\n", student_age, MAX_MARKS);
}

int main(void) {
    printf("\n=== Topic 1: Keywords & Identifiers ===\n");
    keywords_identifiers_example();
    return 0;
}
