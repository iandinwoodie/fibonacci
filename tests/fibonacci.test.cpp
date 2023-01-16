#include "fibonacci/fibonacci.h"

#include <gtest/gtest.h>

namespace {
const std::vector<unsigned int> s_fib_seq = {0, 1, 1, 2, 3, 5, 8};
const unsigned int s_stress_n = 40;
const unsigned int s_stress_result = 102334155;
} // namespace

TEST(FibonacciTests, RecursiveNaive_ReturnsCorrectValuesForUnsignedInts) {
  std::vector<unsigned int> results;
  for (unsigned int i = 0; i < s_fib_seq.size(); ++i) {
    results.push_back(fibonacci::recursive_naive(i));
  }
  ASSERT_EQ(s_fib_seq, results);
  ASSERT_EQ(s_stress_result, fibonacci::recursive_naive(s_stress_n));
}

TEST(FibonacciTests, RecursiveMemo_ReturnsCorrectValuesForUnsignedInts) {
  std::vector<unsigned int> results;
  for (unsigned int i = 0; i < s_fib_seq.size(); ++i) {
    results.push_back(fibonacci::recursive_memo(i));
  }
  ASSERT_EQ(s_fib_seq, results);
  ASSERT_EQ(s_stress_result, fibonacci::recursive_memo(s_stress_n));
}

TEST(FibonacciTests, Iterative_ReturnsCorrectValuesForUnsignedInts) {
  std::vector<unsigned int> results;
  for (unsigned int i = 0; i < s_fib_seq.size(); ++i) {
    results.push_back(fibonacci::iterative(i));
  }
  ASSERT_EQ(s_fib_seq, results);
  ASSERT_EQ(s_stress_result, fibonacci::iterative(s_stress_n));
}
