//
// Created by neko on 12.03.19.
//

#include <network/tcp_socket.h>

// ONLY FOR USE INSIDE TCP_SOCKET_... FUNCTIONS!
#define SET_ERR(err_code) if (err != NULL) *err = err_code;
#define SOCK_ERR(err_code) SET_ERR(err_code);\
                           return false;
#define SET_INTERNAL_ERR(err_code) sock->is_initialized=false; \
                                   sock->last_error = err_code;


bool tcp_socket_create(TCP_Socket* sock, Host host, TCP_SOCK_ERROR* err) {
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
    sock->saddr.sin_family = AF_INET;
    sock->saddr.sin_port   = htons(host.port);

    int res;
    if ((res = inet_pton(AF_INET, host.addr, &sock->saddr.sin_addr)) == 0) {
        SET_INTERNAL_ERR(ERR_INVALID_ADDR);
        SOCK_ERR(ERR_INVALID_ADDR);
    } else if (res == -1) {
        SET_INTERNAL_ERR(ERR_INET_PTON_INVALID_FAMILY);
        SOCK_ERR(ERR_INET_PTON_INVALID_FAMILY);
    }

    return true;
}

bool tcp_socket_close(TCP_Socket* sock) {
    sock->is_initialized = false;
    shutdown(sock->sock, SHUT_RD);
    return !sock_close(sock->sock);
}


// server
bool tcp_socket_bind_and_listen(TCP_Socket* sock, int queue, TCP_SOCK_ERROR* err) {
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

bool tcp_socket_accept(TCP_Socket* server, TCP_Socket* client, TCP_SOCK_ERROR* err) {
    // --> to do error checking

    struct sockaddr_in desc;
    int remote;
    #if defined(WIN32)
        int size;
    #elif defined(__unix__)
        socklen_t size;
    #endif

    client->sock           = accept(server->sock, (struct sockaddr*)&desc, &size);
    client->is_initialized = false;

    if (client->sock == -1) {
        client->last_error = ERR_INVALID_CONNECTION;
        SOCK_ERR(ERR_FAILED_TO_ACCEPT_CONNECTION);
    }

    // fill client structure
    client->is_connected = true;
    client->is_listening = true;
    client->type         = TP_CLIENT;
    client->host.port    = htons(desc.sin_port);

    char buff[16];
    memset(buff, 0, 16);


    if (inet_ntop(AF_INET, &desc.sin_addr, buff, 16) == NULL) {
        SET_ERR(ERR_CANNOT_GET_CLIENT_IP_ADDR);
    }

    buff[15] = '\0';
    memcpy(client->host.addr, buff, 16);

    return true;
}

// both
size_t tcp_socket_recv(TCP_Socket* sock, char* buffer, size_t len, TCP_SOCK_ERROR* err) {
    if (!sock->is_connected) {
        SET_ERR(ERR_SOCKET_IS_NOT_CONNECTED);
        return 0;
    }

    if (buffer == NULL) {
        SET_ERR(ERR_CANNOT_READ_TO_NULL_BUFFER);
        return 0;
    }

    memset(buffer, 0, len);

    return (size_t)recv(sock->sock, buffer, len, 0);
}

size_t tcp_socket_send(TCP_Socket* sock, char* buffer, size_t len, TCP_SOCK_ERROR* err) {
    if (!sock->is_connected) {
        SET_ERR(ERR_SOCKET_IS_NOT_CONNECTED);
        return 0;
    }

    if (buffer == NULL) {
        SET_ERR(ERR_CANNOT_SEND_NULL_BUFFER);
        return 0;
    }

    return (size_t)send(sock->sock, buffer, len, 0);
}

size_t tcp_socket_recv_until(TCP_Socket* sock, char* buffer, size_t len, char terminator, TCP_SOCK_ERROR* err) {
    if (!sock->is_connected) {
        SET_ERR(ERR_SOCKET_IS_NOT_CONNECTED);
        return 0;
    }

    if (buffer == NULL) {
        SET_ERR(ERR_CANNOT_SEND_NULL_BUFFER);
        return 0;
    }

    memset(buffer, 0, len);
    ssize_t received = 0;
    ssize_t tmp_recv = 0;
    char    tmp;

    do {
        tmp_recv = recv(sock->sock, &tmp, 1, 0);

        if (tmp_recv == 0) {
            *err = ERR_DIDNT_FOUND_TERMINATOR_IN_RECEIVED_STREAM;
            break;
        }

        buffer[received] = tmp;
        received += tmp_recv;
    } while (tmp != terminator);

    return (size_t)received;
}
