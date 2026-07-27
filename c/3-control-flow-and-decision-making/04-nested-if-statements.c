// =============================================================================
// TOPIC 4: Nested `if` Statements
// =============================================================================

/*
 * A "nested if" is an if/else statement placed INSIDE the body of another
 * if/else statement. Used when a decision depends on more than one condition
 * that must be checked in stages (rather than combined with && / ||).
 *
 * SYNTAX:
 *   if (outer_condition) {
 *       if (inner_condition) {
 *           ...
 *       }
 *   }
 *
 * READABILITY NOTE: deeply nested ifs are hard to read. When possible,
 * prefer combining conditions with logical operators (&&, ||) or using
 * early returns to reduce nesting depth.
 */

#include <stdio.h>

void nested_if_example(void) {
    int age = 25;
    int has_license = 1;

    if (age >= 18) {
        if (has_license) {
            printf("Can drive: age %d, has license\n", age);
        } else {
            printf("Cannot drive: no license\n");
        }
    } else {
        printf("Cannot drive: underage (%d)\n", age);
    }

    // same logic, flattened with && — usually preferred over nesting
    if (age >= 18 && has_license) {
        printf("(flattened check) Can drive\n");
    }
}

int main(void) {
    printf("\n=== Topic 4: Nested if Statements ===\n");
    nested_if_example();
    return 0;
}
