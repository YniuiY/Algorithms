cmake_minimum_required(VERSION 3.9)

project(StringSearchTree)

include_directories(./include)

aux_source_directory(./src SRCS)

add_executable(run ${SRCS})