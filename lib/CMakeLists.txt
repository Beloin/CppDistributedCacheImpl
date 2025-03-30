cmake_minimum_required(VERSION 3.31)

add_library(lib_lib ./DataStructures/RedBlackTree.cpp)

target_include_directories(lib_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

