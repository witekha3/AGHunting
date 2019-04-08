//
// Created by neko on 04.04.19.
//

#ifndef UDP_SERVER_SOCKETUDP_H
#define UDP_SERVER_SOCKETUDP_H

#include <cstring>
#include <cstdlib>
#include <optional>

#include <AGHunting/Core.h>
#include <AGHunting/network/Host.h>
#include <AGHunting/network/UDP.h>

#include <AGHunting/misc/Log.h>

namespace ah {

    class AH_API SocketUDP {
    public:
        SocketUDP(const Host&);
        ~SocketUDP();

        bool bind();

        std::optional<UDP_Packet> recv_from();
        size_t send_to(UDP_Addr, char*, size_t);

        // getters / setters
        inline Host getHost() const {
            return _host;
        }

        inline void close() {
            ::shutdown(_sock, SHUT_RDWR);
            ::close(_sock);
        }

    private:
        Host     _host;
        SOCKET   _sock;

        sockaddr_in _addr;
    };
}

#endif //UDP_SERVER_SOCKETUDP_H
