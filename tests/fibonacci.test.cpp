#include "fibonacci/fibonacci.h"

#include <gtest/gtest.h>

namespace {
const std::vector<int> s_fib_seq = {0, 1, 1, 2, 3, 5, 8};
}

TEST(FibonacciTests, ExponentialTime_ReturnsCorrectValuesForUnsignedInts) {
  std::vector<int> results;
  for (int i = 0; i < s_fib_seq.size(); ++i) {
    results.push_back(fibonacci::exp(i));
  }
  ASSERT_EQ(s_fib_seq, results);
  ASSERT_EQ(832040, fibonacci::exp(30));
}

TEST(FibonacciTests, LinearTime_ReturnsCorrectValuesForUnsignedInts) {
  std::vector<int> results;
  for (int i = 0; i < s_fib_seq.size(); ++i) {
    results.push_back(fibonacci::linear(i));
  }
  ASSERT_EQ(s_fib_seq, results);
  ASSERT_EQ(832040, fibonacci::linear(30));
}
