//
// Created by neko on 12.03.19.
//

#include <network/tcp_socket.h>

// ONLY FOR USE INSIDE TCP_SOCKET_... FUNCTIONS!
#define SOCK_ERR(err_code) sock->is_initialized=false; \
                           sock->last_error = err_code;\
                           *err = err_code; \
                           return false;

bool tcp_socket_create(TCP_SOCKET* sock, HOST host, TCP_SOCK_ERROR* err) {
    #ifdef OS_NOT_SUPPORTED
        SOCK_ERR(ERR_OS_NOT_SUPPORTED);
    #endif

    #ifdef WIN32
        WSAData wsa;
        WSAInit(MAKEWORD(2, 2), &wsa);
    #endif


    // windows requires call of WSAInit
    // tcp
    sock->sock           = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    sock->is_initialized = true;

    if (sock->sock == -1) {
        SOCK_ERR(ERR_CANNOT_CREATE_SOCKET);
    }

    // reuse host
    int reuse = 1;
    setsockopt(sock->sock, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int));

    // fill sockaddr structure
    sock->saddr.sin_family      = AF_INET;
    sock->saddr.sin_port        = htons(host.port);

    if (!inet_aton(host.addr, &sock->saddr.sin_addr)) {
        SOCK_ERR(ERR_INVALID_ADDR);
    }

    return true;
}

bool tcp_socket_close(TCP_SOCKET* sock) {
    sock->is_initialized = false;
    return !sock_close(sock->sock);
}

bool tcp_socket_bind_and_listen(TCP_SOCKET* sock, int queue) {



    return true;
}
