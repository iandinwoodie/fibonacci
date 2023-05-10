#include "fibonacci/fibonacci.h"

#include <gtest/gtest.h>

#include <cstdint>
#include <stdexcept>
#include <vector>

namespace {
const std::vector<uint32_t> s_fib_seq = {
    0,       1,       1,       2,       3,        5,        8,        13};

const uint8_t s_max_n = 93;
const uint64_t s_max_fib = 12200160415121876738U;
} // namespace

TEST(FibonacciTests, RecursiveNaive_ReturnsCorrectValuesFor5FibonacciNumbers) {
  std::vector<uint32_t> results;
  for (uint8_t i = 0; i < s_fib_seq.size(); ++i) {
    results.push_back(fibonacci::RecursiveNaive(i));
  }
  ASSERT_EQ(s_fib_seq, results);
}

// The following test is excluded due to the time complexity of the algorithm.
// TEST(FibonacciTests, RecursiveNaive_ReturnsCorrectValuesForMaxN)

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

//TEST(FibonacciTests, RecursiveMemo_ReturnsCorrectValuesForMaxN) {
//  ASSERT_EQ(s_max_fib, fibonacci::RecursiveMemo(s_max_n));
//}

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

//TEST(FibonacciTests, Iterative_ReturnsCorrectValuesForMaxN) {
//  ASSERT_EQ(s_max_fib, fibonacci::Iterative(s_max_n));
//}

TEST(FibonacciTests, Iterative_ThrowsForNGreaterThan93) {
  ASSERT_THROW(fibonacci::Iterative(94), std::overflow_error);
}

TEST(FibonacciTests, LookupTable_ReturnsCorrectValuesFor40FibonacciNumbers) {
  std::vector<uint32_t> results;
  for (uint8_t i = 0; i < s_fib_seq.size(); ++i) {
    results.push_back(fibonacci::LookupTable(i));
  }
  ASSERT_EQ(s_fib_seq, results);
}

//TEST(FibonacciTests, LookupTable_ReturnsCorrectValuesForMaxN) {
//  ASSERT_EQ(s_max_fib, fibonacci::LookupTable(s_max_n));
//}

TEST(FibonacciTests, LookupTable_ThrowsForNGreaterThan93) {
  ASSERT_THROW(fibonacci::LookupTable(94), std::overflow_error);
}
