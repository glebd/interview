cmake_minimum_required(VERSION 3.5)
project(is_unique)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(../lib/googletest/googletest/include)
enable_testing()

set(SOURCE_FILES main.cpp)
add_executable(is_unique ${SOURCE_FILES})

add_subdirectory(../lib/googletest ${CMAKE_CURRENT_BINARY_DIR}/googletest)

target_link_libraries(is_unique gtest gtest_main)
