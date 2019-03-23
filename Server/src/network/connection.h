//
// Created by neko on 13.03.19.
//

#ifndef SERVER_CONNECTION_H
#define SERVER_CONNECTION_H

#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#include <log/log.h>

#include <network/tcp_socket.h>
#include <network/protocol/packet_parser.h>

#include <pthread.h>

typedef struct {
    TCP_Socket socket;
    bool       is_active;
    bool       is_free;
} Connection;

extern void* connection_handler(void*);

#endif //SERVER_CONNECTION_H
