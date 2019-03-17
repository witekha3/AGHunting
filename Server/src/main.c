// ENTRY POINT

#include <log/log.h>
#include <server-api.h>

#define DEFAULT_ADDR "127.0.0.1"
#define DEFAULT_PORT 8080

int main(int argc, char** argv) {

    Host h = { DEFAULT_ADDR, DEFAULT_PORT };

    if (!init_server(h)) {
        log_fatal("Server failed to initialize, closing");
        return -1;

    }

    start_server();
    shutdown_server();

    return 0;
}
