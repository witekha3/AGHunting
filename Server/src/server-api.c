//
// Created by neko on 12.03.19.
//

#include <server-api.h>

// server structure
static AH_Server SERVER;

static const int QUEUE_SIZE = 5;


// internal methods headers
static bool init_tcp();
static void* server_controller(void*);


// internal methods
// update, called every frame
static void update() {
    // wait for new connection
    TCP_Socket     client;
    TCP_SOCK_ERROR err;

    if (!tcp_socket_accept(&SERVER.server_socket, &client, &err)) {
        log_error("Failed to accept connection, error %d", err);
        return;
    }

    log_info("received connection request from %s:%d", client.host.addr, client.host.port);

    Connection c = { client, true, false };
    pthread_t tmp;

    if (SERVER.free_slots > 0) {
        // find first free connection
        for (int i = 0; i < vector_size(SERVER.connections); ++i) {
            if (SERVER.connections[i].is_free) {
                SERVER.connections[i] = c;
                pthread_create(&SERVER.threads[i], NULL, connection_handler,
                               (void*)&SERVER.connections[i]);
                break;
            }
        }
    } else {
        vector_push_back(SERVER.connections, c);
        vector_push_back(SERVER.threads, tmp);

        pthread_create(&SERVER.threads[SERVER.last_free_connection], NULL, connection_handler,
                       (void*)&SERVER.connections[SERVER.last_free_connection]);
        ++SERVER.last_free_connection;
    }

    ++SERVER.active_connections;
}

// external methods
// server loop
void start_server() {
    start_web_interface(&SERVER);

    log_info("Server is running on %s:%d", SERVER.host.addr, SERVER.host.port);

    while (SERVER.is_running) {
        update();
    }
}

bool init_server(Host host) {
    SERVER.host = host;

    if (!init_tcp()) {
        log_fatal("Failed to init TCP");
        return false;
    }

    if (!init_web_interface()) {
        log_fatal("Failed to init web interface");
        return false;
    }

    log_info("Successfully initialized web interface on 127.0.0.1:1337");

    SERVER.active_connections   = 0;
    SERVER.free_slots           = 0;
    SERVER.last_free_connection = 0;

    log_info("Server initialized successfully");
    SERVER.is_running = true;
    return true;
}

void shutdown_server() {
    log_info("Shutting down server");
    // firstly close all connections

    tcp_socket_close(&SERVER.server_socket);
}

// static implementation
static bool init_tcp() {
    if (!tcp_socket_create(&SERVER.server_socket, SERVER.host, &SERVER.last_tcp_err)) {
        log_fatal("Cannot create server tcp socket. %d", SERVER.last_tcp_err);
        return false;
    }

    if (!tcp_socket_bind_and_listen(&SERVER.server_socket, QUEUE_SIZE, &SERVER.last_tcp_err)) {
        log_fatal("Failed to bind server, %d\n", errno);
        return false;
    }

    return true;
}
