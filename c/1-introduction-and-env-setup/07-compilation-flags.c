// =============================================================================
// TOPIC 7: Compilation Flags
// =============================================================================

#include <stdio.h>

/*
 * Flags are passed to gcc/clang on the command line to control behavior.
 * Format:  gcc [flags] source.c -o output
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * OUTPUT FLAG
 * ─────────────────────────────────────────────────────────────────────────────
 *
 * -o <filename>
 *   Names the output file.
 *   Without -o, output defaults to a.out (Linux/Mac) or a.exe (Windows).
 *
 *   gcc hello.c -o hello          → output named "hello"
 *   gcc hello.c -o build/hello    → output inside build/ directory
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * WARNING FLAGS
 * ─────────────────────────────────────────────────────────────────────────────
 *
 * -Wall
 *   Enables "all" common warnings. (Not literally all — just the most useful.)
 *   Catches: unused variables, missing return, implicit function declarations, etc.
 *
 * -Wextra
 *   Enables extra warnings not covered by -Wall.
 *   Catches: unused function parameters, missing field initializers, etc.
 *
 * -pedantic  (or -Wpedantic)
 *   Enforces strict compliance with the C standard.
 *   Rejects any code that uses GCC extensions or non-standard behavior.
 *
 * -Werror
 *   Treats ALL warnings as errors — code won't compile if there are warnings.
 *   Great for maintaining clean code in production/CI environments.
 *
 * -Wshadow
 *   Warns when a local variable shadows (hides) an outer variable.
 *
 * -Wconversion
 *   Warns about implicit type conversions that may change a value.
 *
 * RECOMMENDED combination for learning:
 *   gcc -Wall -Wextra -pedantic source.c -o output
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * STANDARD FLAGS
 * ─────────────────────────────────────────────────────────────────────────────
 *
 * -std=c89   → compile as C89/ANSI C (oldest)
 * -std=c99   → compile as C99 (adds bool, stdint.h, VLAs, // comments)
 * -std=c11   → compile as C11 (adds atomics, threads, _Generic)
 * -std=c17   → compile as C17 (bug fixes over C11, no new features)
 * -std=c23   → compile as C23 (latest: nullptr, #embed, typeof)
 * -std=gnu11 → C11 + GCC extensions (default on most Linux systems)
 *
 * BEST PRACTICE: always specify the standard explicitly:
 *   gcc -std=c11 -Wall -Wextra source.c -o output
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * DEBUG FLAG
 * ─────────────────────────────────────────────────────────────────────────────
 *
 * -g
 *   Embeds debug symbols into the executable.
 *   Required for using GDB (GNU Debugger) or LLDB.
 *   Without -g, you cannot see variable names or line numbers in the debugger.
 *   The output file is larger but behavior is identical.
 *
 *   gcc -g -Wall source.c -o output   → compile with debug info
 *   gdb ./output                      → then debug it with GDB
 *
 * -g3
 *   Maximum debug info — includes macro definitions too.
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * OPTIMIZATION FLAGS
 * ─────────────────────────────────────────────────────────────────────────────
 *
 * -O0   No optimization (default). Easiest to debug. Slowest runtime.
 * -O1   Basic optimizations. Small speed gain.
 * -O2   Recommended for production. Good speed without risky optimizations.
 * -O3   Aggressive optimization. Faster but larger binary; can hide bugs.
 * -Os   Optimize for size (smallest binary). Useful for embedded systems.
 * -Og   Optimize while keeping debug info readable. Best for debugging.
 *
 * NOTE: Never use -O2/-O3 with -g at the same time for debugging —
 *       optimizations reorder/remove code, making debugger output confusing.
 *       Use -Og -g instead.
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * OTHER USEFUL FLAGS
 * ─────────────────────────────────────────────────────────────────────────────
 *
 * -I<dir>          → add directory to #include search path
 *                    gcc -I./include source.c -o output
 *
 * -L<dir>          → add directory to library search path
 * -l<name>         → link with lib<name> (e.g. -lm links math library)
 *
 * -D<MACRO>        → define a macro from the command line
 *                    gcc -DDEBUG source.c -o output
 *                    (same as writing #define DEBUG at the top of source)
 *
 * -E               → run preprocessor only, output to stdout
 * -S               → compile to assembly only (.s file)
 * -c               → compile to object file only (.o), do not link
 *
 * -v               → verbose: show all internal commands GCC runs
 * -save-temps      → keep intermediate files (.i, .s, .o)
 *
 * -fsanitize=address       → enable AddressSanitizer (detect memory errors at runtime)
 * -fsanitize=undefined     → enable UndefinedBehaviorSanitizer
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * FLAG COMBINATIONS FOR COMMON SCENARIOS
 * ─────────────────────────────────────────────────────────────────────────────
 *
 * Learning / Development:
 *   gcc -std=c11 -Wall -Wextra -pedantic -g source.c -o output
 *
 * Debugging a crash:
 *   gcc -std=c11 -Wall -Wextra -g -Og -fsanitize=address source.c -o output
 *
 * Production release:
 *   gcc -std=c11 -Wall -Wextra -O2 source.c -o output
 *
 * Embedded / size-constrained:
 *   gcc -std=c11 -Os -Wall source.c -o output
 */

// Demonstrating -D flag: conditional compilation using a macro defined at build time
void flags_example(void) {
#ifdef DEBUG
    // This block is only compiled when you pass -DDEBUG to gcc
    printf("[DEBUG] flags_example() called\n");
#endif

    int x = 10;
    int y = 20;
    printf("Sum = %d\n", x + y);
}

// Demonstrating -Wall catching an issue: unused variable warning
// (comment out to avoid the warning when compiling)
/*
void unused_var_example(void) {
    int forgotten = 42;   // -Wall will warn: 'forgotten' set but not used
    printf("Hello\n");
}
*/

int main(void) {
    printf("\n=== Topic 7: Flags ===\n");
    flags_example();
    return 0;
}

// ─────────────────────────────────────────────────────────────────────────────
// Basic:
//   gcc 07-compilation-flags.c -o 07-compilation-flags
//
// Recommended (development):
//   gcc -std=c11 -Wall -Wextra -pedantic -g 07-compilation-flags.c -o 07-compilation-flags
//
// With DEBUG macro defined:
//   gcc -std=c11 -Wall -Wextra -g -DDEBUG 07-compilation-flags.c -o 07-compilation-flags
//
// With AddressSanitizer (memory error detection):
//   gcc -std=c11 -Wall -Wextra -g -fsanitize=address 07-compilation-flags.c -o 07-compilation-flags
// ─────────────────────────────────────────────────────────────────────────────
