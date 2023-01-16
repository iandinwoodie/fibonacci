#include "fibonacci/fibonacci.h"

#include <iostream>
#include <vector>

namespace fibonacci {
namespace {
unsigned int recursive_memo_impl(unsigned int n,
                                 std::vector<unsigned int> &memo) {
  if (n > 1 && memo[n] == 0) {
    memo[n] =
        recursive_memo_impl(n - 2, memo) + recursive_memo_impl(n - 1, memo);
  }

  return memo[n];
}
} // namespace

unsigned int recursive_naive(unsigned int n) {
  if (n < 2) {
    return n;
  }

  return recursive_naive(n - 1) + recursive_naive(n - 2);
}

unsigned int recursive_memo(unsigned int n) {
  std::vector<unsigned int> memo(n + 1, 0);
  memo[1] = 1;

  return recursive_memo_impl(n, memo);
}

unsigned int iterative(unsigned int n) {
  if (n < 2) {
    return n;
  }

  unsigned int prev = 0;
  unsigned int fib = 1;
  for (unsigned int i = 2; i <= n; ++i) {
    unsigned int tmp = prev + fib;
    prev = fib;
    fib = tmp;
  }

  return fib;
}
} // namespace fibonacci
