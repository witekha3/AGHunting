//
// Created by neko on 16.03.19.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include <vector/vector.h>

#include <network/host.h>
#include <network/tcp_socket.h>
#include <network/connection.h>

#include <ui/web_interface.h>

typedef struct {
    Host           host;
    TCP_Socket     server_socket;
    TCP_SOCK_ERROR last_tcp_err;

    bool is_initialized;
    bool is_running;

    short active_connections;
    short free_slots;
    short last_free_connection;

    VECTOR(Connection) connections;
    VECTOR(pthread_t)  threads;
} AH_Server;


#endif //SERVER_SERVER_H
