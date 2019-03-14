#include <stdio.h>

#include <network/tcp_socket.h>

int main(int argc, char** argv) {

    TCP_SOCKET     s;
    TCP_SOCK_ERROR err;
    HOST           h = { "127.0.0.1", 8080 };

    if (!tcp_socket_create(&s, h, &err)) {
        fprintf(stderr, "Cannot create socket! %d", err);
        return -1;
    }

    if (!tcp_socket_bind_and_listen(&s, 5, &err)) {
        fprintf(stderr, "Cannot bind socket! %d\n", err);
        return -2;
    }

    fprintf(stdout, "$ server is listening on %s:%d\n", h.addr, h.port);

    TCP_SOCKET client;

    if (!tcp_socket_accept(&s, &client, &err)) {
        fprintf(stderr, "Cannot to accept connection %d\n", err);
    }

    fprintf(stdout, "$ received a connection\n\n");

    tcp_socket_close(&s);
    return 0;
}