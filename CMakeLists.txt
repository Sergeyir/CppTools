cmake_minimum_required(VERSION 3.10)

project(CppTools)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wpedantic -pipe -O2")

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

include_directories("./include")

add_library(ErrorHandler src/ErrorHandler.cpp)
add_library(StrTools src/StrTools.cpp)
add_library(Time src/Time.cpp)
add_library(IOTools src/IOTools.cpp)
add_library(Box src/Box.cpp)
add_library(Table src/Table.cpp)

target_link_libraries(IOTools ErrorHandler StrTools)
target_link_libraries(Box ErrorHandler StrTools IOTools)
target_link_libraries(Table ErrorHandler IOTools)
