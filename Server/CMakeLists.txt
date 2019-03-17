cmake_minimum_required(VERSION 3.13)
project(Server C)

set(CMAKE_C_STANDARD 11)

file(GLOB SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
              "${CMAKE_CURRENT_SOURCE_DIR}/src/*/*.c"
              "${CMAKE_CURRENT_SOURCE_DIR}/src/game/*/*.c"
              "${CMAKE_CURRENT_SOURCE_DIR}/libs/log/src/*.c")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src
                    ${CMAKE_CURRENT_SOURCE_DIR}/libs/includes)

add_definitions(-DSTATIC_FILES="${CMAKE_CURRENT_SOURCE_DIR}/src/ui")

add_executable(Server src/main.c ${SRC})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(Server Threads::Threads)