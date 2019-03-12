//
// Created by neko on 12.03.19.
//

#ifndef SERVER_HOST_H
#define SERVER_HOST_H

#include <stdint.h>

typedef struct Host {
    const char* addr;
    uint16_t    port;
} HOST;

#endif //SERVER_HOST_H
