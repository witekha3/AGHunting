//
// Created by neko on 4/23/19.
//

#ifndef UDP_SERVER_ASYNCREQUESTHANDLER_H
#define UDP_SERVER_ASYNCREQUESTHANDLER_H

#include <memory>

#include <AGHunting/Core.h>
#include <AGHunting/misc/Log.h>
#include <AGHunting/network/RequestHandler.h>

namespace ah {

    template<class T>
    class AH_API AsyncRequestHandler : public RequestHandler {
    public:
        static RequestHandlerPtr createInstance() {
            return std::make_unique<AsyncRequestHandler>();
        }

        void handle(UDP_Packet packet, ServerAPI api) override {
            auto res = RUN_ASYNC(&T::handle, packet, api);
        }
    };
}

#endif //UDP_SERVER_ASYNCREQUESTHANDLER_H
