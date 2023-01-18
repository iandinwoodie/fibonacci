#include "fibonacci/fibonacci.h"

#include <cmath>
#include <cstdint>
#include <vector>

namespace fibonacci {
namespace {
uint64_t RecursiveMemoImpl(uint8_t n, std::vector<uint64_t> &memo) {
  if (n > 1 && memo[n] == 0) {
    memo[n] = RecursiveMemoImpl(n - 2, memo) + RecursiveMemoImpl(n - 1, memo);
  }

  return memo[n];
}
} // namespace

uint64_t RecursiveNaive(uint8_t n) {
  if (n < 2) {
    return n;
  }

  return RecursiveNaive(n - 1) + RecursiveNaive(n - 2);
}

uint64_t RecursiveMemo(uint8_t n) {
  std::vector<uint64_t> memo(n + 1, 0);
  memo[1] = 1;

  return RecursiveMemoImpl(n, memo);
}

uint64_t Iterative(uint8_t n) {
  if (n < 2) {
    return n;
  }

  uint64_t prev = 0;
  uint64_t fib = 1;
  uint64_t tmp;
  for (uint8_t i = 2; i <= n; ++i) {
    tmp = prev + fib;
    prev = fib;
    fib = tmp;
  }

  return fib;
}

uint64_t Binet(uint8_t n) {
  static const double phi = (1 + std::sqrt(5)) / 2;
  return (std::pow(phi, n) - std::pow(1 - phi, n)) / std::sqrt(5);
}
} // namespace fibonacci
