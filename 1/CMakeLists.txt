cmake_minimum_required(VERSION 3.10)

project(main)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -fsanitize=address")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(main main.cpp src/array.cpp src/menu.cpp)

target_include_directories(main PRIVATE include src)

