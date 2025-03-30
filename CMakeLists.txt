cmake_minimum_required(VERSION 3.31)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(distributed_cache)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG main
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

option(ENABLE_TESTS "Enable testing" ON)
if(ENABLE_TESTS)
  add_subdirectory(test)
endif()


add_executable(distributed_cache main.cpp)

add_subdirectory(src)
add_subdirectory(lib)

target_link_libraries(distributed_cache src_lib lib_lib)

