//
// Created by neko on 4/23/19.
//

#ifndef UDP_SERVER_SERVERAPI_H
#define UDP_SERVER_SERVERAPI_H

#include <functional>

#include <AGHunting/Core.h>

namespace ah {

    struct AH_API ServerAPI {
        std::function<void(char*, size_t)> response;
    };
}

#endif //UDP_SERVER_SERVERAPI_H
