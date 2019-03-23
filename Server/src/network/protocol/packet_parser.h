//
// Created by neko on 19.03.19.
//

#ifndef SERVER_PACKET_PARSER_H
#define SERVER_PACKET_PARSER_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include <log/log.h>

#include <network/protocol/packet.h>

extern bool parse_packet_header(Packet*, char*, size_t);
extern void print_packet(const Packet* const);

#endif //SERVER_PACKET_PARSER_H
