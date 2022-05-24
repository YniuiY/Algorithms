cmake_minimum_required(VERSION 2.9)

project(SymbolTable)

include_directories(${PROJECT_SOURCE_DIR}/include)

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRCS)

add_executable(run ${SRCS})