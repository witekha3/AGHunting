//
// Created by neko on 06.04.19.
//

#ifndef UDP_SERVER_UDP_H
#define UDP_SERVER_UDP_H

#include <AGHunting/Core.h>
#include <AGHunting/network/Host.h>

namespace ah {
    constexpr int IP_BUFF_LEN      = 64;
    constexpr int PAYLOAD_BUFF_LEN = 128;

    struct AH_API UDP_Addr {
        sockaddr_in saddr;
        socklen_t   len;

        char ip_buff[IP_BUFF_LEN];
        Host host;
    };

    struct AH_API UDP_Payload {
        char   data[PAYLOAD_BUFF_LEN];
        size_t len;
    };

    struct AH_API UDP_Packet {
        UDP_Addr    addr;
        UDP_Payload payload;

        UDP_Packet() {
            std::memset(payload.data, 0, PAYLOAD_BUFF_LEN);
            std::memset(addr.ip_buff, 0, IP_BUFF_LEN);
        }
    };
}

#endif //UDP_SERVER_UDP_H
