cmake_minimum_required(VERSION 3.13)
project(udp_server)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/AGHunting")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs")

file(GLOB SRC "${SRC_DIR}/*.cpp"
              "${SRC_DIR}/*/*.cpp")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src
                    ${LIB_DIR}/spdlog/include)

set(CMAKE_CXX_STANDARD 20)

add_executable(udp_server main.cpp ${SRC})