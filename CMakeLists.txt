cmake_minimum_required(VERSION 3.3)
project(Containers)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

set(SOURCE_FILES
        main.c
        List.h List.c
        DoubleList.c DoubleList.h
        Stack.h Stack.c
        RPN.c RPN.h
        Queue.c Queue.h
        BinaryTree.c BinaryTree.h)
add_executable(Containers ${SOURCE_FILES})
