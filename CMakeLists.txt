cmake_minimum_required(VERSION 3.20)
project(MonIDConverter)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(MonIDConverter main.cpp)
