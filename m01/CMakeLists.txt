cmake_minimum_required(VERSION 3.6)
project(maven_test01)

set(CMAKE_CXX_STANDARD 11)
include_directories(../inc)
add_definitions(-DCATCH_CONFIG_MAIN)

set(SOURCE_FILES main.cpp)
add_executable(maven_test01 ${SOURCE_FILES})
