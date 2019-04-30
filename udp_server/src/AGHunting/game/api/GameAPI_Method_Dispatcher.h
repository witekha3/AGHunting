//
// Created by neko on 4/30/19.
//

#ifndef UDP_SERVER_GAMEAPI_METHOD_DISPATCHER_H
#define UDP_SERVER_GAMEAPI_METHOD_DISPATCHER_H

#include <functional>

#include <AGHunting/Core.h>
#include <AGHunting/game/api/GamePacket.h>

namespace ah {

    using GameAPI_Method_Callback = std::function<bool(void)>;

    class AH_API GameAPI_Method_Dispatcher {
    public:
        template<GameAPI_Method tp>
        bool dispatch(GameAPI_Method type, GameAPI_Method_Callback callback) {
            if (type == tp) {
                return callback();
            }
        }
    };
}

#endif //UDP_SERVER_GAMEAPI_METHOD_DISPATCHER_H
