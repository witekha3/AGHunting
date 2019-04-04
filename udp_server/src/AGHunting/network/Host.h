//
// Created by neko on 04.04.19.
//

#ifndef UDP_SERVER_HOST_H
#define UDP_SERVER_HOST_H

#include <AGHunting/Core.h>

namespace ah {
    struct AH_API Host {
        PORT port;
        IP   ip;
    };
}

#endif //UDP_SERVER_HOST_H
