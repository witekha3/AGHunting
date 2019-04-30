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
#include <AGHunting/game/api/GameAPI_Method_Dispatcher.h>
#include <AGHunting/game/Player.h>

namespace ah {

    #define BIND_GAME_API_CALLBACK(func) std::bind(PayloadHandler::func, packet.addr, api, *p)

    class AH_API PayloadHandler {
    public:
        inline static void handle(UDP_Packet packet, ServerAPI api) {
            AH_INFO("Received connection: {0}:{1}", packet.addr.host.ip, packet.addr.host.port);

            auto p = _game_packet_parser->parse(packet.payload);

            if (!p) {
                AH_INFO("Received invalid packet.");
                return;
            }

            GameAPI_Method_Dispatcher d;

            d.dispatch<GameAPI_Method::AH_SEND_PLAYER_POSITION>(p->method, BIND_GAME_API_CALLBACK(api_on_SendPlayerPosition));
            d.dispatch<GameAPI_Method::AH_GET_PLAYERS_POSITIONS>(p->method, BIND_GAME_API_CALLBACK(api_on_GetPlayersPositions));
            d.dispatch<GameAPI_Method::AH_UNKNOWN_METHOD>(p->method, BIND_GAME_API_CALLBACK(api_on_UnknownMethod));
            d.dispatch<GameAPI_Method::AH_CONNECTION_REQUEST>(p->method, BIND_GAME_API_CALLBACK(api_on_ConnectionRequest));
        }

    private:
        static GamePacketParserPtr _game_packet_parser;

        /*
         *  --- callbacks ---
         */
        inline static bool api_on_SendPlayerPosition(UDP_Addr addr, ServerAPI api, GamePacket packet) {


            return true;
        }

        inline static bool api_on_GetPlayersPositions(UDP_Addr addr, ServerAPI api, GamePacket packet) {


            return true;
        }

        inline static bool api_on_UnknownMethod(UDP_Addr addr, ServerAPI api, GamePacket packet) {


            return true;
        }

        inline static bool api_on_ConnectionRequest(UDP_Addr addr, ServerAPI api, GamePacket packet) {


            return true;
        }
    };
}

#endif //UDP_SERVER_PAYLOADHANDLER_H
