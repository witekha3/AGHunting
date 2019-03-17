//
// Created by neko on 16.03.19.
//

#include "web_interface.h"

static const int QUEUE_SIZE = 5;
static bool init_tcp();
static void* http_thread_worker(void*);

typedef struct {
    TCP_Socket http_socket;
    pthread_t  http_thread;

} WebInterface;

static WebInterface interface;

static char static_http_response[512];

static bool load_http_response(const char*);

bool init_web_interface() {
    Host h = { "127.0.0.1", 1337 };

    if (!init_tcp(&interface, h)) {
        return false;
    }

    memset(static_http_response, 0, 512);
    sprintf(static_http_response, "HTTP/1.1 200 OK\r\nContent-type: text/html\r\n\r\n%s", buff);

    return true;
}

void start_web_interface(AH_Server* server) {
    pthread_create(&interface.http_thread, NULL, http_thread_worker, (void*)server);
}

static void* http_thread_worker(void* data) {
    AH_Server* server = (AH_Server*)data;


    while (server->is_running) {
        TCP_Socket client;

        tcp_socket_accept(&interface.http_socket, &client, NULL);

        // must recv because of http protocol
        char buff1[512];
        tcp_socket_recv(&client, buff1, 128, NULL);

        tcp_socket_send(&client, static_http_response, 512, NULL);
    }
}

static bool load_http_response(const char* p) {
    char buff[512];
    char path[128];

    sprintf(path, "%s%s", STATIC_FILES, p);

    FILE* f = fopen(path, "r");

    if (!f) {
        log_fatal("Failed to open index.html");
        return false;
    }

    fread(buff, 1, 512, f);
    fclose(f);

    return true;
}

static bool init_tcp(WebInterface* interface, Host h) {
    if (!tcp_socket_create(&interface->http_socket, h, NULL)) {
        log_fatal("Cannot create server tcp socket.");
        return false;
    }

    if (!tcp_socket_bind_and_listen(&interface->http_socket, QUEUE_SIZE, NULL)) {
        log_fatal("Failed to bind server, %d\n", errno);
        return false;
    }

    return true;
}