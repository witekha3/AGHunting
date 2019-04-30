//
// Created by neko on 4/23/19.
//

#ifndef UDP_SERVER_REQUESTHANDLER_H
#define UDP_SERVER_REQUESTHANDLER_H

#include <memory>

#include <AGHunting/Core.h>
#include <AGHunting/ServerAPI.h>
#include <AGHunting/network/UDP.h>

namespace ah {

    class AH_API RequestHandler {
    public:
        virtual void handle(UDP_Packet, ServerAPI) = 0;
    };

    using RequestHandlerPtr = std::unique_ptr<RequestHandler>;
}

#endif //UDP_SERVER_REQUESTHANDLER_H
