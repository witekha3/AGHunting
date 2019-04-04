//
// Created by neko on 04.04.19.
//

#ifndef UDP_SERVER_SOCKETUDP_H
#define UDP_SERVER_SOCKETUDP_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <AGHunting/Core.h>
#include <AGHunting/network/Host.h>
#include <AGHunting/misc/Log.h>

namespace ah {
    enum class AH_API SockType : uint8_t {
        SERVER,
        CLIENT
    };

    class AH_API SocketUDP {
    public:
        SocketUDP(Host&, const SockType&&);
        ~SocketUDP();

        bool bind();

    private:
        Host     _host;
        SockType _type;

        SOCKET   _sock;
    };
}

#endif //UDP_SERVER_SOCKETUDP_H
