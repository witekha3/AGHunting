//
// Created by neko on 12.03.19.
//

#ifndef SERVER_TCP_SOCKET_H
#define SERVER_TCP_SOCKET_H

#ifdef __linux
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define sock_close(s) close(s)
#elif WIN32
#include <winsock2.h>
    #include <ws2tcpip.h>
    #define sock_close(s) closesocket(s)
#else
    #define OS_NOT_SUPPORTED
#endif

#ifndef SOCKET
#define SOCKET int
#endif

#include <stdbool.h>

#include <network/host.h>

// define core structures

typedef enum TCP_Sock_Error {
    ERR_NONE,
    ERR_OS_NOT_SUPPORTED,
    ERR_CANNOT_CREATE_SOCKET,
    ERR_INVALID_ADDR,
    ERR_CANNOT_BIND_SOCKET,
    ERR_CANNOT_LISTEN,
    ERR_CANNOT_BIND_UNINITIALIZED_SOCK,
    ERR_CANNOT_BIND_CLIENT_MODE_SOCK,
    ERR_FAILED_TO_ACCEPT_CONNECTION
} TCP_SOCK_ERROR;

typedef enum TCP_Sock_Type {
    TP_NOT_CHOSEN,
    TP_SERVER,
    TP_CLIENT
} TCP_SOCK_TYPE;

typedef struct TCP_Socket {
    SOCKET         sock;
    HOST           host;

    bool           is_initialized;
    bool           is_listening;
    bool           is_connected;

    TCP_SOCK_TYPE  type;
    TCP_SOCK_ERROR last_error;

    struct sockaddr_in saddr;
} TCP_SOCKET;


// utility functions
extern bool tcp_socket_create(TCP_SOCKET*, HOST, TCP_SOCK_ERROR*);
extern bool tcp_socket_close(TCP_SOCKET*);

// server
extern bool tcp_socket_bind_and_listen(TCP_SOCKET*, int, TCP_SOCK_ERROR*);
extern bool tcp_socket_accept(TCP_SOCKET*, TCP_SOCKET*, TCP_SOCK_ERROR*);

// client

// both
extern int tcp_socket_recv(TCP_SOCKET*, char*, size_t, TCP_SOCK_ERROR*);

#endif //SERVER_TCP_SOCKET_H
