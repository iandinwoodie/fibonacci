#include "fibonacci/fibonacci.h"

namespace fibonacci {
unsigned int recursive_naive(unsigned int n) {
  if (n < 2) {
    return n;
  }

  return recursive_naive(n - 1) + recursive_naive(n - 2);
}

unsigned int iterative(unsigned int n) {
  if (n < 2) {
    return n;
  }

  int prev = 0;
  int fib = 1;
  for (int i = 2; i <= n; ++i) {
    int tmp = prev + fib;
    prev = fib;
    fib = tmp;
  }

  return fib;
}
} // namespace fibonacci
