#ifndef __MSP430_LAUNCHPAD_CORE
#define __MSP430_LAUNCHPAD_CORE

// Syntax sugar for interrupt definitions.
#define interrupt(x) void __attribute__((interrupt (x)))

// Force inline macro.
#define ALWAYS_INLINE inline __attribute__((always_inline))

#endif  // __MSP430_LAUNCHPAD_CORE
