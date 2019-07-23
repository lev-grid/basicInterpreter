cmake_minimum_required(VERSION 3.5.1)

add_compile_options(-std=c++11)

project(interpreter)

add_library(functions STATIC functions.cpp)

add_executable(main main.cpp)

target_link_libraries(main functions)
