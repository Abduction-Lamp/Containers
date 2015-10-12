cmake_minimum_required(VERSION 3.3)
project(Containers)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

set(SOURCE_FILES main.c List.h List.c)
add_executable(Containers ${SOURCE_FILES})
