//
// Created by neko on 4/27/19.
//

#ifndef UDP_SERVER_GAMEPACKETPARSER_H
#define UDP_SERVER_GAMEPACKETPARSER_H

#include <memory>
#include <optional>

#include <AGHunting/Core.h>
#include <AGHunting/network/UDP.h>
#include <AGHunting/game/api/GamePacket.h>

namespace ah {

    class AH_API GamePacketParser {
    public:
        static inline std::unique_ptr<GamePacketParser> createInstance() {
            return std::make_unique<GamePacketParser>();
        }

        inline std::optional<GamePacket> parse(UDP_Payload packet) {
            GamePacket p = {};

            if (packet.len < AH_MIN_PACKET_LEN) {
                return NULL_PACKET;
            }

            // validation to do
            p.length    = (unsigned char)packet.data[0];
            p.checksum  = *(AH_USHORT*)&packet.data[1];
            p.id        = (unsigned char)packet.data[3];
            p.method    = static_cast<GameAPI_Method>((unsigned char)packet.data[4]);

            memcpy(p.data, &packet.data[5], packet.len - AH_RAW_PACKET_LEN);

            return p;
        }
    };

    using GamePacketParserPtr = std::unique_ptr<GamePacketParser>;
};

#endif //UDP_SERVER_GAMEPACKETPARSER_H
