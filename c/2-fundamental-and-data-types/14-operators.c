// =============================================================================
// TOPIC 14: Operators in C
// =============================================================================

#include <stdio.h>

// --- 14a: Arithmetic Operators (+, -, *, /, %) ---
void arithmetic_operators_example(void) {
    int a = 17, b = 5;
    printf("a + b = %d\n", a + b);   // 22
    printf("a - b = %d\n", a - b);   // 12
    printf("a * b = %d\n", a * b);   // 85
    printf("a / b = %d  (integer division truncates)\n", a / b);   // 3
    printf("a %% b = %d  (remainder)\n", a % b);                    // 2

    double x = 17.0, y = 5.0;
    printf("17.0 / 5.0 = %f  (float division keeps decimals)\n", x / y);
}

// --- 14b: Relational Operators (==, !=, <, >, <=, >=) ---
void relational_operators_example(void) {
    int a = 10, b = 20;
    printf("a == b -> %d\n", a == b);   // 0 (false)
    printf("a != b -> %d\n", a != b);   // 1 (true)
    printf("a <  b -> %d\n", a <  b);   // 1
    printf("a >  b -> %d\n", a >  b);   // 0
    printf("a <= b -> %d\n", a <= b);   // 1
    printf("a >= b -> %d\n", a >= b);   // 0
    // Relational expressions evaluate to int: 1 (true) or 0 (false).
}

// --- 14c: Logical Operators (&&, ||, !) ---
void logical_operators_example(void) {
    int has_ticket = 1, has_id = 0;
    printf("has_ticket && has_id -> %d\n", has_ticket && has_id);   // 0
    printf("has_ticket || has_id -> %d\n", has_ticket || has_id);   // 1
    printf("!has_ticket -> %d\n", !has_ticket);                     // 0
    // In C, any non-zero value is "true"; only 0 is "false".
}

// --- 14d: Bitwise Operators (&, |, ^, ~, <<, >>) ---
void bitwise_operators_example(void) {
    unsigned int a = 12;   // 1100 in binary
    unsigned int b = 10;   // 1010 in binary

    printf("a & b  = %u  (AND: 1000 = 8)\n",  a & b);
    printf("a | b  = %u  (OR : 1110 = 14)\n", a | b);
    printf("a ^ b  = %u  (XOR: 0110 = 6)\n",  a ^ b);
    printf("~a     = %u  (NOT: bitwise complement)\n", ~a);
    printf("a << 2 = %u  (left shift: multiply by 4 = 48)\n", a << 2);
    printf("a >> 2 = %u  (right shift: divide by 4 = 3)\n",  a >> 2);
}

// --- 14e: Assignment Operators (=, +=, -=, *=, /=, %=, &=, |=, ^=, <<=, >>=) ---
void assignment_operators_example(void) {
    int x = 10;
    x += 5;   printf("x += 5  -> %d\n", x);   // 15
    x -= 3;   printf("x -= 3  -> %d\n", x);   // 12
    x *= 2;   printf("x *= 2  -> %d\n", x);   // 24
    x /= 4;   printf("x /= 4  -> %d\n", x);   // 6
    x %= 4;   printf("x %%= 4 -> %d\n", x);   // 2
    x <<= 3;  printf("x <<= 3 -> %d\n", x);   // 16
    x >>= 2;  printf("x >>= 2 -> %d\n", x);   // 4
    x &= 6;   printf("x &= 6  -> %d\n", x);   // 4
    x |= 1;   printf("x |= 1  -> %d\n", x);   // 5
    x ^= 3;   printf("x ^= 3  -> %d\n", x);   // 6
}

// --- 14f: Increment & Decrement (++, --, prefix vs postfix) ---
void increment_decrement_example(void) {
    int a = 5;
    int a_postfix_result = a++;    // returns 5 (old value), THEN increments
    printf("a++ (postfix) returned %d, a is now %d\n", a_postfix_result, a);

    int b = 5;
    int b_prefix_result = ++b;     // increments FIRST, then returns 6 (new value)
    printf("++b (prefix)  returned %d, b is now %d\n", b_prefix_result, b);
}

// --- 14g: Ternary / Conditional Operator (?:) ---
void ternary_operator_example(void) {
    int age = 20;
    // condition ? value_if_true : value_if_false
    const char *status = (age >= 18) ? "adult" : "minor";
    printf("status = %s\n", status);

    int a = 10, b = 20;
    int max = (a > b) ? a : b;
    printf("max(a, b) = %d\n", max);
}

// --- 14h: sizeof Operator ---
void sizeof_operator_example(void) {
    printf("sizeof(3 + 4.5) = %zu (result type is double -> 8)\n",
           sizeof(3 + 4.5));
    // sizeof does NOT evaluate its operand — it only determines its TYPE.
}

// --- 14i: Comma Operator ---
void comma_operator_example(void) {
    // The comma operator evaluates left-to-right, result = rightmost value.
    int x = 1, y = 2;
    int a = (x++, y++, x + y);   // evaluates x++ then y++ (side effects kept),
                                  // result is the LAST expression: x + y
    printf("a = (x++, y++, x+y) -> %d  (x=%d, y=%d)\n", a, x, y);

    // Most commonly seen inside a for-loop to update multiple variables:
    for (int i = 0, j = 10; i < 3; i++, j--) {
        printf("i=%d j=%d\n", i, j);
    }
}

// --- 14j: Operator Precedence & Associativity ---
/*
 * PRECEDENCE decides WHICH operator binds tighter in a mixed expression.
 * ASSOCIATIVITY decides the ORDER when operators of the SAME precedence appear.
 *
 * QUICK REFERENCE (highest to lowest precedence, common operators):
 *   ()  []  ->  .                      (left-to-right)
 *   !  ~  ++  --  (type)  *  &  sizeof (right-to-left, unary)
 *   *  /  %                            (left-to-right)
 *   +  -                               (left-to-right)
 *   <<  >>                             (left-to-right)
 *   <  <=  >  >=                       (left-to-right)
 *   ==  !=                             (left-to-right)
 *   &                                  (left-to-right)
 *   ^                                  (left-to-right)
 *   |                                  (left-to-right)
 *   &&                                 (left-to-right)
 *   ||                                 (left-to-right)
 *   ?:                                 (right-to-left)
 *   =  +=  -=  etc.                    (right-to-left)
 *   ,                                  (left-to-right)
 *
 * TIP: when in doubt, use parentheses — clarity beats memorizing the table.
 */
void precedence_example(void) {
    int result = 2 + 3 * 4;         // '*' binds tighter than '+' -> 14, not 20
    printf("2 + 3 * 4 = %d\n", result);

    int a = 10, b = 5, c = 2;
    int r = a - b - c;              // '-' is left-to-right: (a - b) - c = 3
    printf("a - b - c = %d\n", r);

    int x, y;
    x = y = 7;                      // '=' is right-to-left: y=7 first, then x=y
    printf("x = y = 7 -> x = %d, y = %d\n", x, y);
}

int main(void) {
    printf("\n=== Topic 14: Operators ===\n");
    arithmetic_operators_example();
    relational_operators_example();
    logical_operators_example();
    bitwise_operators_example();
    assignment_operators_example();
    increment_decrement_example();
    ternary_operator_example();
    sizeof_operator_example();
    comma_operator_example();
    precedence_example();
    return 0;
}
