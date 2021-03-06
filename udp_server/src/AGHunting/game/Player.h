//
// Created by neko on 4/25/19.
//

#ifndef UDP_SERVER_PLAYER_H
#define UDP_SERVER_PLAYER_H

#include <AGHunting/Core.h>
#include <AGHunting/network/UDP.h>

namespace ah {

    struct AH_API Player {
        UDP_Addr  addr;
        AH_USHORT id;
    };
}

#endif //UDP_SERVER_PLAYER_H
