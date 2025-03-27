cmake_minimum_required(VERSION 3.10)

project(ooplab)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)
if(DEFINED SANITIZE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined -fno-omit-frame-pointer -Wall -Wextra")
endif(DEFINED SANITIZE)

add_library(transform src/lib/transform.cxx)
add_library(progr src/lib/program.cxx)
add_library(excepts src/lib/excepts.cxx)
add_executable(lab src/main.cxx)
target_link_libraries(lab progr transform excepts)