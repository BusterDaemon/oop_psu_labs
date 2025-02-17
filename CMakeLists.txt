cmake_minimum_required(VERSION 3.10)

project(ooplab)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

add_library(lab1 lab1.cxx)
add_executable(lab main.cxx)
target_link_libraries(lab lab1)