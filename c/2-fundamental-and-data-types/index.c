// =============================================================================
// 02. Fundamentals & Data Types
// =============================================================================

#include <stdio.h>
#include <stdlib.h>    // malloc, free
#include <string.h>    // strlen

// =============================================================================
// TOPIC 1: Variables & Constants
// =============================================================================

/*
 * VARIABLES
 * ─────────────────────────────────────────────────────────────────────────────
 * A variable is a named location in memory that stores a value.
 *
 * Declaration syntax:
 *   type name;            → declares without a value
 *   type name = value;    → declares AND initializes
 *
 * RULES FOR NAMING VARIABLES:
 * - Must start with a letter or underscore (_), not a digit
 * - Can contain letters, digits, underscores after the first character
 * - Case-sensitive: "age" and "Age" are different variables
 * - Cannot be a reserved keyword (int, return, while, etc.)
 * - No spaces or special characters (@, #, -, etc.)
 *
 * Valid:   age, _count, total_score, x1, playerHealth
 * Invalid: 1name, total-score, int, my var
 *
 * VARIABLE LIFETIME / SCOPE PREVIEW:
 * - Local variable  → exists only inside the block { } where declared
 * - Global variable → exists for the entire program's lifetime
 *
 * CONSTANTS
 * ─────────────────────────────────────────────────────────────────────────────
 * A constant is a value that CANNOT change after initialization.
 *
 * TWO WAYS TO CREATE CONSTANTS IN C:
 *
 * 1. const keyword (preferred — type-checked by compiler)
 *      const int MAX_USERS = 100;
 *      MAX_USERS = 200;   // ERROR: assignment of read-only variable
 *
 * 2. #define preprocessor macro (text substitution, no type checking)
 *      #define MAX_USERS 100
 *      // Preprocessor replaces MAX_USERS with 100 everywhere, before compiling
 *
 * DIFFERENCE BETWEEN const AND #define:
 *
 * FEATURE          const                    #define
 * ─────────────    ──────────────────────   ───────────────────────
 * Type checking    Yes (has a real type)    No (pure text substitution)
 * Memory           Takes memory (usually)   No memory — replaced before compile
 * Debugger         Visible (has a name)     Invisible (already replaced)
 * Scope            Follows normal C scope   Global from definition point onward
 * Can take address Yes (&MAX_USERS works)   No
 *
 * BEST PRACTICE: prefer `const` over `#define` for typed constants in modern C.
 */

void variables_constants_example(void) {
    // Variable declaration and initialization
    int age = 25;
    float price = 19.99f;
    char grade = 'A';

    // Variable can be reassigned
    age = 26;
    printf("Age is now: %d\n", age);

    // const variable — cannot be reassigned after this point
    const int MAX_USERS = 100;
    printf("MAX_USERS = %d\n", MAX_USERS);
    // MAX_USERS = 200;   // would cause a compile error
}

#define PI_VALUE 3.14159   // #define constant — pure text substitution

void define_constant_example(void) {
    double area = PI_VALUE * 5 * 5;   // PI_VALUE is replaced with 3.14159 here
    printf("Circle area: %.2f\n", area);
}


// =============================================================================
// TOPIC 2: Keywords & Identifiers
// =============================================================================

/*
 * KEYWORDS
 * ─────────────────────────────────────────────────────────────────────────────
 * Keywords are RESERVED WORDS with special meaning to the compiler.
 * You CANNOT use them as variable/function names.
 *
 * C89/C90 had 32 keywords. Later standards added more.
 *
 * C89 KEYWORDS (32 total):
 *   auto      break     case      char      const     continue
 *   default   do        double    else      enum      extern
 *   float     for       goto      if        int       long
 *   register  return    short     signed    sizeof    static
 *   struct    switch    typedef   union     unsigned  void
 *   volatile  while
 *
 * C99 ADDED:
 *   inline    restrict  _Bool     _Complex  _Imaginary
 *
 * C11 ADDED:
 *   _Alignas      _Alignof     _Atomic    _Generic
 *   _Noreturn     _Static_assert   _Thread_local
 *
 * C23 ADDED (now real keywords, not macros):
 *   bool   true   false   nullptr   typeof   constexpr
 *
 * IDENTIFIERS
 * ─────────────────────────────────────────────────────────────────────────────
 * An identifier is a NAME you choose for a variable, function, struct, etc.
 *
 * RULES (same as variable naming rules):
 * - First character: letter (a-z, A-Z) or underscore (_)
 * - Remaining characters: letters, digits, underscores
 * - Cannot be a keyword
 * - Case-sensitive
 * - No length limit by standard, but C99 guarantees at least 63 chars significant
 *
 * NAMING CONVENTIONS (style, not enforced by compiler):
 *   snake_case     → most common in C:      total_score, is_valid
 *   camelCase      → sometimes used:        totalScore, isValid
 *   UPPER_SNAKE    → constants and macros:  MAX_SIZE, PI_VALUE
 *   prefix_        → struct/module names:   sdl_init(), str_compare()
 *
 * RESERVED IDENTIFIER PATTERNS TO AVOID:
 * - Don't start your own identifiers with underscore + uppercase (_Foo)
 *   or double underscore (__foo) — these are reserved for the compiler/library.
 */

void keywords_identifiers_example(void) {
    // These are all valid identifiers following different conventions
    int total_score = 100;      // snake_case
    int totalScore   = 100;     // camelCase
    const int MAX_SIZE = 50;    // UPPER_SNAKE for constants

    // 'int', 'const', 'return' below are KEYWORDS — cannot be renamed/reused
    printf("%d %d %d\n", total_score, totalScore, MAX_SIZE);
}


// =============================================================================
// TOPIC 3: Data Types
// =============================================================================

#include <stdbool.h>   // bool, true, false (C99+)
#include <stdint.h>    // fixed-width integer types (C99+)

/*
 * C's data types fall into categories:
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * 1. BASIC / PRIMITIVE TYPES
 * ─────────────────────────────────────────────────────────────────────────────
 *
 * int      → whole numbers           e.g. 10, -5, 0       (commonly 4 bytes)
 * char     → single character        e.g. 'A', '5', '\n'  (1 byte)
 * float    → single-precision real   e.g. 3.14f           (4 bytes)
 * double   → double-precision real   e.g. 3.14159265358   (8 bytes)
 * void     → "no type" / no value    used for functions returning nothing,
 *            and generic pointers (void*)
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * 2. DERIVED TYPES
 * ─────────────────────────────────────────────────────────────────────────────
 * Built from basic types:
 *   Arrays      → int arr[10];
 *   Pointers    → int *p;
 *   Functions   → int add(int a, int b);
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * 3. USER-DEFINED TYPES
 * ─────────────────────────────────────────────────────────────────────────────
 * Created by the programmer:
 *   struct, union, enum, typedef
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * TYPICAL SIZES (platform-dependent! always verify with sizeof)
 * ─────────────────────────────────────────────────────────────────────────────
 *
 * Type              Typical Size (64-bit system)   Range (signed)
 * ───────────────   ────────────────────────────   ─────────────────────────
 * char              1 byte                          -128 to 127
 * short             2 bytes                         -32,768 to 32,767
 * int               4 bytes                         -2,147,483,648 to 2,147,483,647
 * long              8 bytes (Linux) / 4 (Windows)   platform-dependent
 * long long         8 bytes                         very large range
 * float             4 bytes                         ~7 decimal digits precision
 * double            8 bytes                         ~15 decimal digits precision
 * long double       8, 12, or 16 bytes               extended precision
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * bool TYPE (C99+, real keyword in C23)
 * ─────────────────────────────────────────────────────────────────────────────
 * Before C99, C had no real boolean type — people used int (0 = false, nonzero = true).
 * C99 added <stdbool.h>: bool, true (1), false (0)
 * C23: bool/true/false became real keywords — no header needed.
 */

void data_types_example(void) {
    // Basic types
    int    age      = 25;
    char   grade    = 'A';
    float  price    = 19.99f;
    double pi       = 3.14159265358979;
    void  *generic  = NULL;   // void* — can point to any type

    // Checking actual sizes on THIS system
    printf("sizeof(char)      = %zu byte(s)\n",  sizeof(char));
    printf("sizeof(int)       = %zu byte(s)\n",  sizeof(int));
    printf("sizeof(short)     = %zu byte(s)\n",  sizeof(short));
    printf("sizeof(long)      = %zu byte(s)\n",  sizeof(long));
    printf("sizeof(long long) = %zu byte(s)\n",  sizeof(long long));
    printf("sizeof(float)     = %zu byte(s)\n",  sizeof(float));
    printf("sizeof(double)    = %zu byte(s)\n",  sizeof(double));

    // bool type (C99+)
    bool is_logged_in = true;
    printf("is_logged_in = %d\n", is_logged_in);   // prints 1

    printf("age=%d grade=%c price=%.2f pi=%.5f generic=%p\n",
           age, grade, price, pi, generic);
}
