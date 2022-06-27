cmake_minimum_required(VERSION 3.21)
project(bmp VERSION 1.0.0)
set (CMAKE_CXX_STANDARD 23)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_subdirectory(src)
include_directories(inc)

find_package(wxWidgets COMPONENTS gl core base OPTIONAL_COMPONENTS net)
if(wxWidgets_FOUND)
  include(${wxWidgets_USE_FILE})
  # and for each of your dependent executable/library targets:
endif()

add_executable(${PROJECT_NAME} src/main.cpp)

add_library(
    generic STATIC
    src/generic.cpp
    inc/generic.h
)

target_link_libraries(${PROJECT_NAME} 
    ${wxWidgets_LIBRARIES}
    generic)
