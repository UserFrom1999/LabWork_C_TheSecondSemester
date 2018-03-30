cmake_minimum_required(VERSION 3.9)
project(Task5_1_7 C)

set(CMAKE_C_STANDARD 99)

add_executable(Task5_1_7 main.c Input.h)
target_link_libraries(Task5_1_7 m)