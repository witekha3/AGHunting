/*
 *
 * AGHunting UDP SERVE
 * Kacper Czyż & Witold Haza
 *
 */

#include <AGHunting/GameServer.h>
#include <AGHunting/misc/Log.h>

int main() {
    ah::Log::init();

    ah::GameServer s({
        DEFAULT_IP,
        DEFAULT_PORT
    });

    if (!s.init()) {
        AH_FATAL("Failed to init game server.");
        return -1;
    }

    s.start();
    return 0;
}