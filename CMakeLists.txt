cmake_minimum_required(VERSION 3.31)
project(lab_6 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SOURCES
  main.cpp)

set(HEADERS
  cars.hpp)

add_executable(lab_6 ${SOURCES} ${HEADERS})
