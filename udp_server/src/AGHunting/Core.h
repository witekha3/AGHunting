//
// Created by neko on 04.04.19.
//

#ifndef UDP_SERVER_CORE_H
#define UDP_SERVER_CORE_H

#include <future>
#include <string>
#include <cstdint>

// macros/defines

#define AH_API
#define RUN_ASYNC(func, ...) std::async(std::launch::async, func, __VA_ARGS__);

#define PORT   uint16_t
#define IP     std::string
#define SOCKET int

// constants

constexpr PORT DEFAULT_PORT = 15001;
const IP       DEFAULT_IP   = "127.0.0.1";


#endif //UDP_SERVER_CORE_H
