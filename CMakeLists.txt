cmake_minimum_required(VERSION 3.0...3.31.6 FATAL_ERROR)

project(CppTools)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wpedantic -pipe -O2")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(ErrorHandler ${CMAKE_SOURCE_DIR}/src/ErrorHandler.cpp)
add_library(StrTools ${CMAKE_SOURCE_DIR}/src/StrTools.cpp)
add_library(Time ${CMAKE_SOURCE_DIR}/src/Time.cpp)
add_library(IOTools ${CMAKE_SOURCE_DIR}/src/IOTools.cpp)
add_library(Box ${CMAKE_SOURCE_DIR}/src/Box.cpp)
add_library(Table ${CMAKE_SOURCE_DIR}/src/Table.cpp)

target_link_libraries(IOTools ErrorHandler StrTools)
target_link_libraries(Box ErrorHandler StrTools IOTools)
target_link_libraries(Table ErrorHandler IOTools)
