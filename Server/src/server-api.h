//
// Created by neko on 12.03.19.
//

#ifndef SERVER_SERVER_API_H
#define SERVER_SERVER_API_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <vector/vector.h>
#include <log/log.h>

#include <network/tcp_socket.h>
#include <network/host.h>
#include <network/connection.h>

#include <ui/web_interface.h>

#include <server.h>

extern bool init_server(Host);
extern void start_server();
extern void shutdown_server();

#endif //SERVER_SERVER_API_H
