//
// Created by neko on 08.04.19.
//

#include "RequestHandler.h"

namespace ah {

    void RequestHandler::handle(ServerAPI api, UDP_Packet packet) {
        AH_INFO("Received request from {0}:{1}", packet.addr.host.ip, packet.addr.host.port);
    }
}
