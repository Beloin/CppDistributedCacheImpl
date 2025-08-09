cmake_minimum_required(VERSION 3.31)

enable_testing()

add_executable(
  test_lib
  hello.cpp
  ./DataStructures/test_RedBlackTree.cpp
  main.cpp
)

target_link_libraries(
  test_lib
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_lib)

target_link_libraries(test_lib src_lib lib_lib)

target_include_directories(test_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)
