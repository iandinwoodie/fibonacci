#include "fibonacci/fibonacci.h"

namespace fibonacci {
unsigned int exp(unsigned int n) {
  if (n < 2) {
    return n;
  }

  return exp(n - 1) + exp(n - 2);
}

unsigned int linear(unsigned int n) {
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
