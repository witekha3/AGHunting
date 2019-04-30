//
// Created by neko on 4/27/19.
//

#ifndef UDP_SERVER_GAMEPACKET_H
#define UDP_SERVER_GAMEPACKET_H

#include <cstring>

#include <AGHunting/Core.h>

constexpr int AH_GAME_PACKET_DATA_LEN = 59;
constexpr int AH_RAW_PACKET_LEN       = 5;
constexpr int AH_MIN_PACKET_LEN       = 6;

#define NULL_PACKET {}

namespace ah {

    enum class GameAPI_Method : AH_USHORT {
        AH_UNKNOWN_METHOD         = 0,
        AH_SEND_PLAYER_POSITION   = 1,
        AH_GET_PLAYERS_POSITIONS  = 2,
        AH_CONNECTION_REQUEST     = 3,
    };

    struct AH_API GamePacket {
        inline GamePacket() {
            std::memset(data, 0, AH_GAME_PACKET_DATA_LEN);
        }

        AH_USHORT length;
        AH_USHORT checksum;
        AH_USHORT id;

        GameAPI_Method method;
        char           data[AH_GAME_PACKET_DATA_LEN];
    };
}

#endif //UDP_SERVER_GAMEPACKET_H
