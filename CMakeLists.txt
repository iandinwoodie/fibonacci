cmake_minimum_required(VERSION 3.25)
project(Fibonacci
  VERSION 0.1.0
  DESCRIPTION "A library of Fibonacci number generators."
  LANGUAGES CXX
)

################################################################################
# Project Settings.

set(CMAKE_CXX_STANDARD 17)
include(GNUInstallDirs)

# Enable the generation of compile_commands.json.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

################################################################################
# Third Party Dependencies.

find_package(paptools REQUIRED
  PATHS "${CMAKE_CURRENT_SOURCE_DIR}/../paptools/install"
)
#include("cmake/FindGoogleTest.cmake")
include("cmake/FindBenchmark.cmake")

################################################################################
# Fibonacci Library.

add_library(fibonacci
  "src/fibonacci.cpp"
)

target_include_directories(fibonacci
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

paptrace_trace_target(fibonacci)

################################################################################
# Project Tests.

enable_testing()

add_executable(fibonacci_unit_tests
  "tests/fibonacci.test.cpp"
)

target_link_libraries(fibonacci_unit_tests
  PRIVATE
    fibonacci
    GTest::gtest
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(fibonacci_unit_tests)

################################################################################
# Project Benchmarks.

add_executable(fibonacci_benchmarks
  "benchmarks/fibonacci.benchmark.cpp"
)

target_link_libraries(fibonacci_benchmarks
  PRIVATE
    fibonacci
    benchmark::benchmark_main
)

################################################################################
