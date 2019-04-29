cmake_minimum_required(VERSION 3.13)
project(udp_server)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/AGHunting")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs")

file(GLOB SRC "${SRC_DIR}/*.cpp"
              "${SRC_DIR}/*/*.cpp")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src
                    ${LIB_DIR}/spdlog/include
                    ${LIB_DIR}/)

set(CMAKE_CXX_STANDARD 17)

add_definitions(-lbcrypt)

add_executable(udp_server main.cpp ${SRC} src/AGHunting/network/RequestHandler.h src/AGHunting/network/AsyncRequestHandler.h src/AGHunting/game/PayloadHandler.cpp src/AGHunting/game/PayloadHandler.h src/AGHunting/ServerAPI.h src/AGHunting/game/Player.h src/AGHunting/game/api/GamePacket.h src/AGHunting/game/api/GamePacketParser.h)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(udp_server Threads::Threads)