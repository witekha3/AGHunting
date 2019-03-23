//
// Created by neko on 16.03.19.
//

#ifndef SERVER_WEBINTERFACE_H
#define SERVER_WEBINTERFACE_H

#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#include <log/log.h>

#include <network/tcp_socket.h>
#include <network/host.h>
#include <ui/web_methods.h>

#include <server.h>

extern bool init_web_interface();
extern void start_web_interface(AH_Server*);

#endif //SERVER_WEBINTERFACE_H
