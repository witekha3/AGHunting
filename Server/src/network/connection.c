//
// Created by neko on 13.03.19.
//

#include "connection.h"

void* connection_handler(void* data) {
    Connection* c = (Connection*)data;

    // auth to do

    while (c->is_active) {
        char buff[RAW_PACKET_LEN];
        memset(buff, 0, RAW_PACKET_LEN);

        Packet p;

        size_t len = tcp_socket_recv(&c->socket, buff, RAW_PACKET_LEN, NULL);

        if (len == 0) {
            c->is_active = false;

            log_error("Connection lost.");
            // --active_connections
            break;
        }

        if (!parse_packet_header(&p, buff, len)) {
            log_error("Received invalid packet");
            continue;
        }

        print_packet(&p);
        // handle packet
    }

    c->is_active = false;
    return (void*)0;
}
