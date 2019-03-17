//
// Created by neko on 12.03.19.
//

#ifndef SERVER_HOST_H
#define SERVER_HOST_H

#include <stdint.h>

typedef struct {
    char     addr[16];
    uint16_t port;
} Host;

#endif //SERVER_HOST_H
