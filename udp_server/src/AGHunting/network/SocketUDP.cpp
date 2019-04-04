//
// Created by neko on 04.04.19.
//

#include "SocketUDP.h"

namespace ah {
    SocketUDP::SocketUDP(Host& host, const SockType&& type)
        :   _host(host),
            _type(type)
    {
    }

    SocketUDP::~SocketUDP() {

    }

    bool SocketUDP::bind() {



        return true;
    }
}
