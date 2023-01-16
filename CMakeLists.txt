cmake_minimum_required(VERSION 3.25)
project(Fibonacci
  VERSION 0.1.0
  DESCRIPTION "A library of Fibonacci number generators."
  LANGUAGES CXX
)

################################################################################
# Project Settings.

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

################################################################################
# Third Party Dependencies.

include("cmake/FindGoogleTest.cmake")

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

################################################################################
# Project Tests.

enable_testing()

add_executable(unit_tests
  "tests/fibonacci.test.cpp"
)

target_link_libraries(unit_tests
  PRIVATE
    fibonacci
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(unit_tests)

################################################################################