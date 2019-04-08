//
// Created by neko on 08.04.19.
//

#ifndef UDP_SERVER_REQUESTHANDLER_H
#define UDP_SERVER_REQUESTHANDLER_H

#include <functional>

#include <AGHunting/Core.h>
#include <AGHunting/network/UDP.h>
#include <AGHunting/network/SocketUDP.h>
#include <AGHunting/misc/Log.h>

namespace ah {
    struct AH_API ServerAPI {
        std::function<void(char*, size_t)> response;
    };

    class AH_API RequestHandler {
    public:
        static void handle(ServerAPI, UDP_Packet);

    private:
    };
}

#endif //UDP_SERVER_REQUESTHANDLER_H
