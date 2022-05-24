cmake_minimum_required(VERSION 2.9)#cmake最低版本要求

project(BFS)#生成的工程名

set(CMAKE_CXX_COMPILE_FEATURES "g++")#设置C++编辑器

include_directories(${PROJECT_SOURCE_DIR}/include)#添加头文件的搜索路径

aux_source_directory(./src SRCS)#将目录src下的源文件写入变量SRCS

set(${EXECUTABLE_OUTPUT_PATH} ../)#设置可执行文件的生成路径

add_executable(run ${SRCS})#生成可执行文件

add_definitions(-std=c++11)#添加对C++11的支持