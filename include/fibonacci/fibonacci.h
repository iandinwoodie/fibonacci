#ifndef FIBONACCI_FIBONACCI_H
#define FIBONACCI_FIBONACCI_H

namespace fibonacci {
// Returns the Nth Fibonacci number using a naive recursive implementation.
// Time: O(n^2)
unsigned int recursive_naive(unsigned int n);

// Returns the Nth Fibonacci number using an iterative implementation.
// Time: O(n)
unsigned int iterative(unsigned int n);
} // namespace fibonacci

#endif // FIBONACCI_FIBONACCI_H
