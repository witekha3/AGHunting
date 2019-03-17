//
// Created by neko on 13.03.19.
//

#include "connection.h"

void* connection_handler(void* data) {
    Connection* c = (Connection*)data;

    log_info("Received connection from: %s:%d", c->socket.host.addr, c->socket.host.port);

    // echo
    char buff[128];
    tcp_socket_recv(&c->socket, buff, 128, NULL);
    tcp_socket_send(&c->socket, buff ,128, NULL);

    tcp_socket_close(&c->socket);
}
