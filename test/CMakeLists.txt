cmake_minimum_required(VERSION 3.31)

enable_testing()

add_executable(test_lib hello.cpp)

target_link_libraries(
  test_lib
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_lib)
