//
// Created by neko on 4/27/19.
//

#ifndef UDP_SERVER_GAMEPACKET_H
#define UDP_SERVER_GAMEPACKET_H

#include <cstring>

#include <AGHunting/Core.h>

using AH_USHORT = unsigned short;

constexpr int AH_GAME_PACKET_DATA_LEN = 59;
constexpr int AH_RAW_PACKET_LEN       = 5;
constexpr int AH_MIN_PACKET_LEN       = 6;

#define NULL_PACKET {}

namespace ah {

    enum class GameAPI_Method : AH_USHORT {
        AH_UNKNOWN_METHOD,
        AH_GET_PLAYERS_POSITIONS,
        AH_SEND_PLAYER_POSITION,
    };

    struct AH_API GamePacket {
        inline GamePacket() {
            std::memset(data, 0, AH_GAME_PACKET_DATA_LEN);
        }

        AH_USHORT length;
        AH_USHORT checksum;
        AH_USHORT id;

        GameAPI_Method method;
        unsigned char  data[AH_GAME_PACKET_DATA_LEN];
    };
}

#endif //UDP_SERVER_GAMEPACKET_H
