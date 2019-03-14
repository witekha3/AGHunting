//
// Created by neko on 12.03.19.
//

#include <network/tcp_socket.h>

// ONLY FOR USE INSIDE TCP_SOCKET_... FUNCTIONS!
#define SOCK_ERR(err_code) if (err != NULL) *err = err_code; \
                           return false;
#define SET_INTERNAL_ERR(err_code) sock->is_initialized=false; \
                                   sock->last_error = err_code;


bool tcp_socket_create(TCP_SOCKET* sock, HOST host, TCP_SOCK_ERROR* err) {
    #ifdef OS_NOT_SUPPORTED
        SET_INTERNAL_ERR(ERR_OS_NOT_SUPPORTED);
        SOCK_ERR(ERR_OS_NOT_SUPPORTED);
    #endif

    #ifdef WIN32
        WSAData wsa;
        WSAInit(MAKEWORD(2, 2), &wsa);
    #endif


    // windows requires call of WSAInit
    // tcp
    sock->type           = TP_NOT_CHOSEN;
    sock->sock           = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    sock->is_initialized = true;
    sock->is_connected   = false;
    sock->is_listening   = false;

    if (sock->sock == -1) {
        SET_INTERNAL_ERR(ERR_CANNOT_CREATE_SOCKET);
        SOCK_ERR(ERR_CANNOT_CREATE_SOCKET);
    }

    // reuse host
    int reuse = 1;
    setsockopt(sock->sock, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int));

    // fill sockaddr structure
    sock->saddr.sin_family      = AF_INET;
    sock->saddr.sin_port        = htons(host.port);

    if (!inet_aton(host.addr, &sock->saddr.sin_addr)) {
        SET_INTERNAL_ERR(ERR_INVALID_ADDR);
        SOCK_ERR(ERR_INVALID_ADDR);
    }

    return true;
}

bool tcp_socket_close(TCP_SOCKET* sock) {
    sock->is_initialized = false;
    return !sock_close(sock->sock);
}


// server
bool tcp_socket_bind_and_listen(TCP_SOCKET* sock, int queue, TCP_SOCK_ERROR* err) {
    if (!sock->is_initialized) {
        SET_INTERNAL_ERR(ERR_CANNOT_BIND_UNINITIALIZED_SOCK);
        SOCK_ERR(ERR_CANNOT_BIND_UNINITIALIZED_SOCK);
    }

    if (sock->is_connected || sock->type == TP_CLIENT) {
        SET_INTERNAL_ERR(ERR_CANNOT_BIND_CLIENT_MODE_SOCK);
        SOCK_ERR(ERR_CANNOT_BIND_CLIENT_MODE_SOCK);
    }

    if (bind(sock->sock, (const struct sockaddr*)&sock->saddr, sizeof(sock->saddr)) != 0) {
        SET_INTERNAL_ERR(ERR_CANNOT_BIND_SOCKET);
        SOCK_ERR(ERR_CANNOT_BIND_SOCKET);
    }

    if (listen(sock->sock, queue) != 0) {
        SET_INTERNAL_ERR(ERR_CANNOT_LISTEN);
        SOCK_ERR(ERR_CANNOT_LISTEN);
    }

    sock->type         = TP_SERVER;
    sock->is_listening = true;

    return true;
}

bool tcp_socket_accept(TCP_SOCKET* server, TCP_SOCKET* client, TCP_SOCK_ERROR* err) {
    // --> to do error checking

    client->sock = accept(server->sock, NULL, NULL);

    if (client->sock == -1) {
        SOCK_ERR(ERR_FAILED_TO_ACCEPT_CONNECTION);
    }

    return true;
}


// both
int tcp_socket_recv(TCP_SOCKET* sock, char* buffer, size_t len, TCP_SOCK_ERROR* err) {
    // --> to do error checking

    memset(buffer, 0, len);

    return recv(sock->sock, buffer, len, 0);
}
