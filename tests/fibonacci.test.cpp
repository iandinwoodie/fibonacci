#include "fibonacci/fibonacci.h"

#include <gtest/gtest.h>

#include <cstdint>
#include <vector>
#include <exception>

namespace {
const std::vector<uint32_t> s_fib_seq = {
    0,       1,       1,       2,       3,        5,        8,        13,
    21,      34,      55,      89,      144,      233,      377,      610,
    987,     1597,    2584,    4181,    6765,     10946,    17711,    28657,
    46368,   75025,   121393,  196418,  317811,   514229,   832040,   1346269,
    2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986};
const uint8_t s_stress_n = UCHAR_MAX;
const uint64_t s_stress_fib = 102334155;
} // namespace

TEST(FibonacciTests, RecursiveNaive_ReturnsCorrectValuesFor40FibonacciNumbers) {
  std::vector<uint32_t> results;
  for (uint8_t i = 0; i < s_fib_seq.size(); ++i) {
    results.push_back(fibonacci::RecursiveNaive(i));
  }
  ASSERT_EQ(s_fib_seq, results);
}

TEST(FibonacciTests, RecursiveNaive_ThrowsForNGreaterThan93) {
  ASSERT_THROW(fibonacci::RecursiveNaive(94), std::overflow_error);
}

TEST(FibonacciTests, RecursiveMemo_ReturnsCorrectValuesFor40FibonacciNumbers) {
  std::vector<uint32_t> results;
  for (uint8_t i = 0; i < s_fib_seq.size(); ++i) {
    results.push_back(fibonacci::RecursiveMemo(i));
  }
  ASSERT_EQ(s_fib_seq, results);
}

TEST(FibonacciTests, RecursiveMemo_ThrowsForNGreaterThan93) {
  ASSERT_THROW(fibonacci::RecursiveMemo(94), std::overflow_error);
}

TEST(FibonacciTests, Iterative_ReturnsCorrectValuesFor40FibonacciNumbers) {
  std::vector<uint32_t> results;
  for (uint8_t i = 0; i < s_fib_seq.size(); ++i) {
    results.push_back(fibonacci::Iterative(i));
  }
  ASSERT_EQ(s_fib_seq, results);
}

TEST(FibonacciTests, Iterative_ThrowsForNGreaterThan93) {
  ASSERT_THROW(fibonacci::Iterative(94), std::overflow_error);
}

TEST(FibonacciTests, Binet_ReturnsCorrectValuesFor40FibonacciNumbers) {
  std::vector<uint32_t> results;
  for (uint8_t i = 0; i < s_fib_seq.size(); ++i) {
    results.push_back(fibonacci::Binet(i));
  }
  ASSERT_EQ(s_fib_seq, results);
}

TEST(FibonacciTests, Binet_ThrowsForNGreaterThan93) {
  ASSERT_THROW(fibonacci::Binet(94), std::overflow_error);
}
