cmake_minimum_required(VERSION 3.1)	 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(sort)

set(SOURCE_EXE test.cpp)
set(SOURCE_LIB bubble_sort.cpp)

add_library(bubble STATIC ${SOURCE_LIB})
add_executable(test ${SOURCE_EXE})

target_link_libraries(test bubble)