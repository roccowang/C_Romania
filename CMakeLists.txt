cmake_minimum_required(VERSION 3.5)
project(C_Romania)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Graph.cpp Graph.h DFS.cpp DFS.h uniform_cost.cpp uniform_cost.h)
add_executable(C_Romania ${SOURCE_FILES})