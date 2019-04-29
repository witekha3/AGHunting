//
// Created by neko on 4/23/19.
//

#ifndef UDP_SERVER_PAYLOADHANDLER_H
#define UDP_SERVER_PAYLOADHANDLER_H

#include <AGHunting/Core.h>
#include <AGHunting/ServerAPI.h>
#include <AGHunting/network/UDP.h>

#include <AGHunting/misc/Log.h>

#include <AGHunting/game/api/GamePacket.h>
#include <AGHunting/game/api/GamePacketParser.h>
#include <AGHunting/game/Player.h>

namespace ah {

    class AH_API PayloadHandler {
    public:
        inline static void handle(UDP_Packet packet, ServerAPI api) {
            AH_INFO("Received connection: {0}:{1}", packet.addr.host.ip, packet.addr.host.port);

            auto p = _game_packet_parser->parse(packet.payload);

            if (!p) {
                AH_INFO("Received invalid packet.");
                return;
            }

            char response[128];
            sprintf(response, "%d-%d-%d-%d\n", p->length, p->checksum, p->id, (int)p->method);

            AH_INFO(response);

            api.response(response, strlen(response));
        }

    private:
        static GamePacketParserPtr _game_packet_parser;
    };
}

#endif //UDP_SERVER_PAYLOADHANDLER_H
