cmake_minimum_required(VERSION 3.10)

project(ooplab)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

add_library(lab3 STATIC lib/lab3.cxx)
add_library(io STATIC lib/io.cxx)

target_link_libraries(io lab3)

target_include_directories(lab3 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib)
target_include_directories(io PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib)


add_executable(lab main.cxx)
target_link_libraries(lab PRIVATE io)