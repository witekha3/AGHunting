/*
 *
 * AGHunting UDP SERVE
 * Kacper Czyż & Witold Haza
 *
 */

#include <AGHunting/GameServer.h>
#include <AGHunting/ui/ServerController.h>
#include <AGHunting/misc/Log.h>

int main() {
    ah::Log::init();

    ah::GameServer s({
        DEFAULT_IP,
        DEFAULT_PORT
    });

    ah::ServerController controller(s, { "127.0.0.1", 1337 });

    if (!controller.start()) {
        AH_FATAL("Failed to setup server controller.");
        return -2;
    }

    if (!s.init()) {
        AH_FATAL("Failed to init game server.");
        return -1;
    }

    s.start();
    return 0;
}