cmake_minimum_required(VERSION 3.14)
project(BinaryMinHeap)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(BinaryMinHeap
        src/BinaryMinHeap.cpp
        src/BinaryMinHeap.h
        src/Logger.cpp
        src/Logger.h
        src/main.cpp)
