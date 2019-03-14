cmake_minimum_required(VERSION 3.13)
project(Server C)

set(CMAKE_C_STANDARD 11)

file(GLOB SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
              "${CMAKE_CURRENT_SOURCE_DIR}/src/*/*.c")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(Server src/main.c ${SRC})