// =============================================================================
// TOPIC 2: Variables — Declaration, Initialization, Assignment
// =============================================================================

#include <stdio.h>

/*
 * DECLARATION   → tells the compiler a variable's name and type (reserves memory)
 *                 int age;
 * INITIALIZATION→ giving a variable its first value at the time of declaration
 *                 int age = 25;
 * ASSIGNMENT    → giving a variable a (new) value AFTER it has been declared
 *                 age = 30;
 *
 * RULES:
 * - A variable must be declared before use.
 * - In C89, declarations must appear at the TOP of a block.
 * - In C99+, variables can be declared anywhere in a block, close to first use.
 * - Uninitialized local variables contain GARBAGE values
 * - Global/static variables are automatically zero-initialized if not given
 *   an explicit initializer.
 */

int global_counter;          // global — automatically initialized to 0

void variables_example(void) {
    int age;                 // declaration only — value is garbage right now
    age = 25;                // assignment — now age holds a defined value

    int score = 90;          // declaration + initialization in one line
    double price = 19.99, tax = 1.5;   // multiple declarations, same type

    score = score + 10;      // re-assignment: reading old value, writing new one

    printf("age=%d score=%d price=%.2f tax=%.2f global_counter=%d\n",
           age, score, price, tax, global_counter);

    {
        int age = 99;         // block-scoped variable SHADOWS the outer 'age'
        printf("inner age = %d\n", age);
    }
    printf("outer age is still = %d\n", age);   // unaffected by inner block
}

int main(void) {
    printf("\n=== Topic 2: Variables ===\n");
    variables_example();
    return 0;
}
