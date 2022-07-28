cmake_minimum_required(VERSION 2.9)

project(SymbolTable)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

include_directories(${PROJECT_SOURCE_DIR}/include)

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRCS)

add_executable(run ${SRCS} "../Digraph Algos/src/main.cpp")