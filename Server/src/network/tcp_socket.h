//
// Created by neko on 12.03.19.
//

#ifndef SERVER_TCP_SOCKET_H
#define SERVER_TCP_SOCKET_H

#include <errno.h>
#include <log/log.h>

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

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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
    ERR_FAILED_TO_ACCEPT_CONNECTION,
    ERR_CANNOT_READ_TO_NULL_BUFFER,
    ERR_CANNOT_SEND_NULL_BUFFER,
    ERR_SOCKET_IS_NOT_CONNECTED,
    ERR_INVALID_CONNECTION,
    ERR_DIDNT_FOUND_TERMINATOR_IN_RECEIVED_STREAM,
    ERR_CANNOT_GET_CLIENT_IP_ADDR,
    ERR_INET_PTON_INVALID_FAMILY
} TCP_SOCK_ERROR;

typedef enum TCP_Sock_Type {
    TP_NOT_CHOSEN,
    TP_SERVER,
    TP_CLIENT
} TCP_SOCK_TYPE;

typedef struct {
    SOCKET         sock;
    Host           host;

    bool           is_initialized;
    bool           is_listening;
    bool           is_connected;

    TCP_SOCK_TYPE  type;
    TCP_SOCK_ERROR last_error;

    struct sockaddr_in saddr;
} TCP_Socket;


// utility functions
extern bool tcp_socket_create(TCP_Socket*, Host, TCP_SOCK_ERROR*);
extern bool tcp_socket_close(TCP_Socket*);

// server
extern bool tcp_socket_bind_and_listen(TCP_Socket*, int, TCP_SOCK_ERROR*);
extern bool tcp_socket_accept(TCP_Socket*, TCP_Socket*, TCP_SOCK_ERROR*);

// client
extern bool tcp_socket_connect(TCP_Socket*, TCP_SOCK_ERROR*);

// both
extern size_t tcp_socket_recv(TCP_Socket*, char*, size_t, TCP_SOCK_ERROR*);
extern size_t tcp_socket_send(TCP_Socket*, char*, size_t, TCP_SOCK_ERROR*);
extern size_t tcp_socket_recv_until(TCP_Socket*, char*, size_t, char, TCP_SOCK_ERROR*);

#endif //SERVER_TCP_SOCKET_H
