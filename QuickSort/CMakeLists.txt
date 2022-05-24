cmake_minimum_required(VERSION 2.9.0)

project(QUICK_SORT)

set(CMAKE_CXX_COMPILE_FEATURES "g++")

include_directories(${PROJECT_SOURCE_DIR}/include)

# add_dependencies(-g)

aux_source_directory(./src SRCS)

set(RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

add_executable(run ${SRCS})