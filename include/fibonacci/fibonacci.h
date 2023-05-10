#ifndef FIBONACCI_FIBONACCI_H
#define FIBONACCI_FIBONACCI_H

#include <cstdint>

namespace fibonacci {
// Returns the Nth Fibonacci number using a naive recursive implementation.
// Time: O(2^n)
// Space: O(n)
unsigned long long RecursiveNaive(unsigned short n);

// Returns the Nth Fibonacci number using a memoized recursive implementation.
// Time: O(n)
// Space: O(n)
unsigned long long RecursiveMemo(unsigned short n);

// Returns the Nth Fibonacci number using an iterative implementation.
// Time: O(n)
// Space: O(1)
unsigned long long Iterative(unsigned short n);

// Returns the Nth Fibonacci number using a lookup table implementation.
// Time: O(1)
// Space: O(1)
unsigned long long LookupTable(unsigned short n);
} // namespace fibonacci

#endif // FIBONACCI_FIBONACCI_H
