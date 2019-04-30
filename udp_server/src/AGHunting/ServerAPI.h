//
// Created by neko on 4/23/19.
//

#ifndef UDP_SERVER_SERVERAPI_H
#define UDP_SERVER_SERVERAPI_H

#include <functional>

#include <AGHunting/Core.h>
#include <AGHunting/game/Player.h>

namespace ah {

    struct AH_API ServerAPI {
        std::function<void(char*, size_t)> response;
        std::function<void(char*, size_t)> sendAll;
        std::function<void(Player)>        addNewPlayer;
        std::function<Player*(AH_USHORT)>  getPlayerPtr;
    };
}

#endif //UDP_SERVER_SERVERAPI_H
