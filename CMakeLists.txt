cmake_minimum_required(VERSION 3.19)
project(NapBase)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)

add_executable(NapBase scratch.cpp)