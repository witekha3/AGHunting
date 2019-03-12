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

    tcp_socket_close(&s);
    return 0;
}