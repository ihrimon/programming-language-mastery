// =============================================================================
// TOPIC 8: Fixed-Width Integer Types (`<stdint.h>`)
// =============================================================================

/*
 * Since the size of `int`/`long` etc. varies by platform, <stdint.h> (C99+)
 * provides EXACT-WIDTH integer types with guaranteed sizes everywhere.
 * Essential for: binary file formats, network protocols, embedded/hardware code.
 *
 *   int8_t   / uint8_t    → exactly  8-bit  signed / unsigned
 *   int16_t  / uint16_t   → exactly 16-bit  signed / unsigned
 *   int32_t  / uint32_t   → exactly 32-bit  signed / unsigned
 *   int64_t  / uint64_t   → exactly 64-bit  signed / unsigned
 *
 * ALSO PROVIDED:
 *   int_least8_t   → smallest type with AT LEAST 8 bits (portability fallback)
 *   int_fast8_t    → fastest type with AT LEAST 8 bits on this platform
 *   intmax_t       → largest integer type supported
 *   intptr_t       → integer large enough to hold a pointer
 */
#include <stdio.h>
#include <stdint.h>

void fixed_width_example(void) {
    int8_t   small   = -128;
    uint8_t  ubyte   = 255;
    int16_t  medium  = -32000;
    uint32_t big     = 4000000000U;
    int64_t  huge    = -9000000000000000000LL;
    uint64_t uhuge   = 18000000000000000000ULL;

    printf("int8_t   small = %d\n",  small);
    printf("uint8_t  ubyte = %u\n",  ubyte);
    printf("int16_t  medium= %d\n",  medium);
    printf("uint32_t big   = %u\n",  big);
    printf("int64_t  huge  = %lld\n", huge);
    printf("uint64_t uhuge = %llu\n", uhuge);

    printf("sizeof(int32_t) = %zu bytes (always 4, on ANY platform)\n",
           sizeof(int32_t));
}

int main(void) {
    printf("\n=== Topic 8: Fixed-Width Integer Types ===\n");
    fixed_width_example();
    return 0;
}
