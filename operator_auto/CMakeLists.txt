cmake_minimum_required(VERSION 3.8)

project(operator_auto)
add_executable(${PROJECT_NAME} "main.cpp")
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF
    CXX_STANDARD_REQUIRED ON
)
