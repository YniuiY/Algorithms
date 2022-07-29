cmake_minimum_required(VERSION 2.9)

project(DigraphAlgo)

set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

include_directories(include)

aux_source_directory(src SRCS)

add_executable(run ${SRCS} src/Digraph.cpp include/Digraph.h src/SymbolDigraph.cpp include/SymbolDigraph.h src/BFS.cpp include/BFS.h src/DFS.cpp include/DFS.h)