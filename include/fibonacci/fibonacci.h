#ifndef FIBONACCI_FIBONACCI_H
#define FIBONACCI_FIBONACCI_H

#include <cstdint>

namespace fibonacci {
// Returns the Nth Fibonacci number using a naive recursive implementation.
// Time: O(n^2)
// Space: O(n)
uint64_t RecursiveNaive(uint8_t n);

// Returns the Nth Fibonacci number using a memoized recursive implementation.
// Time: O(n)
// Space: O(n)
uint64_t RecursiveMemo(uint8_t n);

// Returns the Nth Fibonacci number using an iterative implementation.
// Time: O(n)
// Space: O(1)
uint64_t Iterative(uint8_t n);

// Returns the Nth Fibonacci number using a Binet's formula implementation.
// Time: O(1.618^n)
// Space: O(1)
uint64_t Binet(uint8_t n);
} // namespace fibonacci

#endif // FIBONACCI_FIBONACCI_H
