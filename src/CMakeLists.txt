cmake_minimum_required(VERSION 3.31)

add_library(src_lib ./cache/CacheFacade.cpp)

# target_link_libraries(src_lib lib_lib)

target_include_directories(src_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)
