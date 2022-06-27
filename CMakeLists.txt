cmake_minimum_required(VERSION 3.21)
project(bmp VERSION 1.0.0)
set (CMAKE_CXX_STANDARD 23)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_subdirectory(src)
include_directories(inc)

add_executable(${PROJECT_NAME} src/main.cpp)

add_library(
    generic STATIC
    src/generic.cpp
    inc/generic.h
)

target_link_libraries(${PROJECT_NAME} 
    generic)
