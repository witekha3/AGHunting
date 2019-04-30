
/*
 *
 * AGHunting UDP SERVER
 * Kacper Czyż & Witold Haza
 *
 */

#include <AGHunting/GameServer.h>
#include <AGHunting/ui/ServerController.h>
#include <AGHunting/misc/Log.h>

#define LOCAL_IP "192.168.1.7"

const IP c_IP = LOCAL_IP;

int main(int argc, char** argv) {
    ah::Log::init();

    ah::GameServer s({
        c_IP,
        DEFAULT_PORT
    });

    ah::ServerController controller(s, { c_IP, 1337 });

    /*if (!controller.start()) {
        AH_FATAL("Failed to setup server controller.");
        return -2;
    }*/

    if (!s.init()) {
        AH_FATAL("Failed to init game server.");
        return -1;
    }

    s.start();
    return 0;
}
