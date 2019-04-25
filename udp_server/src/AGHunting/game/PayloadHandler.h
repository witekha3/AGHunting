//
// Created by neko on 4/23/19.
//

#ifndef UDP_SERVER_PAYLOADHANDLER_H
#define UDP_SERVER_PAYLOADHANDLER_H

#include <AGHunting/Core.h>
#include <AGHunting/ServerAPI.h>
#include <AGHunting/network/UDP.h>

#include <AGHunting/misc/Log.h>

namespace ah {

    class AH_API PayloadHandler {
    public:
        inline static void handle(UDP_Packet packet, ServerAPI api) {
            AH_INFO("Received connection: {0}:{1}", packet.addr.host.ip, packet.addr.host.port);



        }
    };
}

#endif //UDP_SERVER_PAYLOADHANDLER_H
