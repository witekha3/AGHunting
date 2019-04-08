//
// Created by neko on 06.04.19.
//

#ifndef UDP_SERVER_SERVERCONTROLLER_H
#define UDP_SERVER_SERVERCONTROLLER_H

#include <thread>
#include <memory>

#include <string>
#include <cstdio>
#include <cstdlib>

#include <AGHunting/Core.h>
#include <AGHunting/GameServer.h>
#include <AGHunting/network/Host.h>
#include <AGHunting/misc/Log.h>
#include <AGHunting/ui/Auth.h>

namespace ah {

    constexpr int CONTROLLER_BUF_SIZE = 128;

    class AH_API ServerController {
        enum class Request : unsigned {
            UNKNOWN,
            SHUTDOWN
        };

    public:
        ServerController(GameServer&, Host&&);
        ~ServerController();

        bool start();

    private:
        GameServer& _server;
        Host        _host;

        SOCKET      _sock;

        std::unique_ptr<std::thread> _thread;


        void _threadWorker();
        Request parseRequest(char*, size_t);
    };
}

#endif //UDP_SERVER_SERVERCONTROLLER_H
