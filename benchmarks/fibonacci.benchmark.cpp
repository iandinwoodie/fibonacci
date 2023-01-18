#include "fibonacci/fibonacci.h"

#include <benchmark/benchmark.h>

namespace benchmarks {
void RecursiveNaive(benchmark::State &state) {
  for (auto _ : state) {
    fibonacci::RecursiveNaive(state.range(0));
  }
}

void RecursiveMemo(benchmark::State &state) {
  for (auto _ : state) {
    fibonacci::RecursiveMemo(state.range(0));
  }
}

void Iterative(benchmark::State &state) {
  for (auto _ : state) {
    fibonacci::Iterative(state.range(0));
  }
}

void LookupTable(benchmark::State &state) {
  for (auto _ : state) {
    fibonacci::LookupTable(state.range(0));
  }
}
} // namespace benchmarks

BENCHMARK(benchmarks::RecursiveNaive)->DenseRange(0, 40, 8);
BENCHMARK(benchmarks::RecursiveMemo)->DenseRange(0, 92, 8);
BENCHMARK(benchmarks::Iterative)->DenseRange(0, 92, 8);
BENCHMARK(benchmarks::LookupTable)->DenseRange(0, 92, 8);
