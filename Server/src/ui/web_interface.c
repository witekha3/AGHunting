//
// Created by neko on 16.03.19.
//

#include "web_interface.h"

typedef struct {
    TCP_Socket http_socket;
    pthread_t  http_thread;

    TCP_Socket web_socket;
    pthread_t  web_thread;

} WebInterface;

static const int QUEUE_SIZE = 5;

static bool init_tcp();
static bool load_http_response(const char*);

static void* http_thread_worker(void*);
static void* web_thread_worker(void*);

#define HTTP_BUFF_SIZE 512 * 64

static WebInterface interface;

static char static_http_response[HTTP_BUFF_SIZE];

bool init_web_interface() {
    Host http_h = { "127.0.0.1", 1337 };
    Host web_h  = { "127.0.0.1", 5001 };

    if (!init_tcp(&interface, http_h, web_h)) {
        return false;
    }

    return true;
}

void start_web_interface(AH_Server* server) {
    pthread_create(&interface.http_thread, NULL, http_thread_worker, (void*)server);
    pthread_create(&interface.web_thread, NULL, web_thread_worker, (void*)server);
}

static void* http_thread_worker(void* data) {
    AH_Server* server = (AH_Server*)data;

    while (server->is_running) {
        TCP_Socket client;

        tcp_socket_accept(&interface.http_socket, &client, NULL);

        // must recv because of http protocol
        char buff1[512];
        tcp_socket_recv(&client, buff1, 128, NULL);

        if (!load_http_response("/index.html")) {
            continue;
        }

        tcp_socket_send(&client, static_http_response, HTTP_BUFF_SIZE, NULL);
    }

    tcp_socket_close(&interface.http_socket);
}

static void* web_thread_worker(void* data) {
    AH_Server* server = (AH_Server*)data;
    char buff[512];

    while (server->is_running) {
        TCP_Socket client;
        tcp_socket_accept(&interface.web_socket, &client, NULL);

        while (true) {
            memset(buff, 0, 512);
            size_t recv = tcp_socket_recv(&client, buff, 128, NULL);

            // websockify src dest must be on
            // user probably refreshed page, websocket need to be reconnected
            if (recv == 0) {
                break;
            }

            // do something with received information

        }
    }
}

static bool load_http_response(const char* p) {
    char buff[HTTP_BUFF_SIZE];
    char path[64];

    sprintf(path, "%s%s", STATIC_FILES, p);

    FILE* f = fopen(path, "r");

    if (!f) {
        log_fatal("Failed to open index.html");
        return false;
    }

    memset(buff, 0, HTTP_BUFF_SIZE);
    memset(static_http_response, 0, HTTP_BUFF_SIZE);

    fread(buff, 1, HTTP_BUFF_SIZE, f);
    fclose(f);

    sprintf(static_http_response, "HTTP/1.1 200 OK\r\nContent-type: text/html\r\nContent-length: %ld\r\n\r\n%s", strlen(buff), buff);

    return true;
}

static bool init_tcp(WebInterface* interface, Host http_h, Host web_h) {
    if (!tcp_socket_create(&interface->http_socket, http_h, NULL)) {
        log_fatal("Cannot create server tcp socket.");
        return false;
    }

    if (!tcp_socket_bind_and_listen(&interface->http_socket, QUEUE_SIZE, NULL)) {
        log_fatal("Failed to bind server, %d\n", errno);
        return false;
    }

    if (!tcp_socket_create(&interface->web_socket, web_h, NULL)) {
        log_fatal("Cannot create server tcp socket.");
        return false;
    }

    if (!tcp_socket_bind_and_listen(&interface->web_socket, QUEUE_SIZE, NULL)) {
        log_fatal("Failed to bind server, %d\n", errno);
        return false;
    }

    return true;
}