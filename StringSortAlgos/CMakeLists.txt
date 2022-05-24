cmake_minimum_required(VERSION 2.9.0)

project(StringSortAlgos)

include_directories(./include)

aux_source_directory(./src SRCS)

add_executable(run ${SRCS})